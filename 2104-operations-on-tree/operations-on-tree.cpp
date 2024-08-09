class LockingTree {
private:
    vector<int> parent;
    vector<int> locked;
    vector<vector<int>> children;

public:
    LockingTree(vector<int>& parent) : parent(parent) {
        int n = parent.size();
        locked.resize(n, -1);
        children.resize(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locked[num] != -1) return false;
        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (locked[num] != user) return false;
        locked[num] = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (locked[num] != -1) return false;
        
        // Check if the node has any locked ancestors
        int cur = num;
        while (cur != -1) {
            if (locked[cur] != -1) return false;
            cur = parent[cur];
        }
        
        // Check if the node has any locked descendants
        vector<int> lockedDescendants;
        dfs(num, lockedDescendants);
        
        if (lockedDescendants.empty()) return false;
        
        // Unlock all descendants
        for (int desc : lockedDescendants) {
            locked[desc] = -1;
        }
        
        // Lock the current node
        locked[num] = user;
        
        return true;
    }
    
private:
    void dfs(int node, vector<int>& lockedDescendants) {
        if (locked[node] != -1) {
            lockedDescendants.push_back(node);
        }
        for (int child : children[node]) {
            dfs(child, lockedDescendants);
        }
    }
};