class LockingTree {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> locked;
    unordered_map<int, std::unordered_set<int>> children;
    unordered_map<int, int> lockedDescendantsCount;

public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        for (int i = 0; i < n; ++i) {
            this->parent[i] = parent[i];
            if (i > 0) {
                children[parent[i]].insert(i);
            }
        }
    }
    
    bool lock(int num, int user) {
        if (locked.count(num)) return false;
        locked[num] = user;
        updateAncestors(num, 1);
        return true;
    }
    
    bool unlock(int num, int user) {
        if (!locked.count(num) || locked[num] != user) return false;
        locked.erase(num);
        updateAncestors(num, -1);
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (locked.count(num) || lockedDescendantsCount[num] == 0) return false;
        
        // Check if the node has any locked ancestors
        int cur = num;
        while (parent.count(cur)) {
            cur = parent[cur];
            if (locked.count(cur)) return false;
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
        while (parent.count(node)) {
            node = parent[node];
            lockedDescendantsCount[node] += delta;
        }
    }
    
    void unlockDescendants(int node) {
        if (locked.count(node)) {
            locked.erase(node);
            updateAncestors(node, -1);
        }
        for (int child : children[node]) {
            unlockDescendants(child);
        }
    }
};