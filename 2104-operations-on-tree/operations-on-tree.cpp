class LockingTree {
private:
    vector<int> parent;
    vector<int> locked;
    vector<unordered_set<int>> children;
    vector<int> lockedDescendantsCount;

public:
    LockingTree(vector<int>& parent) : parent(parent) {
        int n = parent.size();
        locked.resize(n, -1);
        children.resize(n);
        lockedDescendantsCount.resize(n, 0);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].insert(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locked[num] != -1) return false;
        locked[num] = user;
        updateAncestors(num, 1);
        return true;
    }
    
    bool unlock(int num, int user) {
        if (locked[num] != user) return false;
        locked[num] = -1;
        updateAncestors(num, -1);
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (locked[num] != -1 || lockedDescendantsCount[num] == 0) return false;
        
        // Check if the node has any locked ancestors
        int cur = parent[num];
        while (cur != -1) {
            if (locked[cur] != -1) return false;
            cur = parent[cur];
        }
        
        // Unlock all descendants
        unlockDescendants(num);
        
        // Lock the current node
        locked[num] = user;
        updateAncestors(num, 1);
        
        return true;
    }
    
private:
    void updateAncestors(int node, int delta) {
        int cur = parent[node];
        while (cur != -1) {
            lockedDescendantsCount[cur] += delta;
            cur = parent[cur];
        }
    }
    
    void unlockDescendants(int node) {
        if (locked[node] != -1) {
            locked[node] = -1;
            updateAncestors(node, -1);
        }
        for (int child : children[node]) {
            unlockDescendants(child);
        }
    }
};