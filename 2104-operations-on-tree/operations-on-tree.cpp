class LockingTree {
private:
    static const int MAX_NODES = 2000; // Adjust based on the maximum number of nodes

    struct MyTreeNode {
        int lockedBy;
        int parent;
        std::vector<int> children;
        int lockedDescendantCount;
        
        MyTreeNode(int p = -1) : lockedBy(-1), parent(p), lockedDescendantCount(0) {}
    };
    
    std::vector<MyTreeNode> nodes;
    std::bitset<MAX_NODES> lockedNodes;
    std::vector<int> depth;

public:
    LockingTree(std::vector<int>& parent) {
        int n = parent.size();
        nodes.resize(n);
        depth.resize(n);
        
        for (int i = 0; i < n; ++i) {
            nodes[i].parent = parent[i];
            if (parent[i] != -1) {
                nodes[parent[i]].children.push_back(i);
            }
        }
        
        calculateDepth(0, 0);
    }

    void calculateDepth(int nodeIndex, int d) {
        depth[nodeIndex] = d;
        for (int child : nodes[nodeIndex].children) {
            calculateDepth(child, d + 1);
        }
    }

    bool lock(int num, int user) {
        if (nodes[num].lockedBy == -1) {
            nodes[num].lockedBy = user;
            lockedNodes.set(num);
            int parent = nodes[num].parent;
            while (parent != -1) {
                nodes[parent].lockedDescendantCount++;
                parent = nodes[parent].parent;
            }
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (nodes[num].lockedBy == user) {
            nodes[num].lockedBy = -1;
            lockedNodes.reset(num);
            int parent = nodes[num].parent;
            while (parent != -1) {
                nodes[parent].lockedDescendantCount--;
                parent = nodes[parent].parent;
            }
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (nodes[num].lockedBy != -1 || nodes[num].lockedDescendantCount == 0) {
            return false;
        }
        
        int parent = nodes[num].parent;
        while (parent != -1) {
            if (nodes[parent].lockedBy != -1) return false;
            parent = nodes[parent].parent;
        }
        
        unlockDescendants(num);
        
        nodes[num].lockedBy = user;
        lockedNodes.set(num);
        parent = nodes[num].parent;
        while (parent != -1) {
            nodes[parent].lockedDescendantCount++;
            parent = nodes[parent].parent;
        }
        return true;
    }

private:
    void unlockDescendants(int num) {
        for (int child : nodes[num].children) {
            if (lockedNodes[child]) {
                nodes[child].lockedBy = -1;
                lockedNodes.reset(child);
                nodes[num].lockedDescendantCount--;
            }
            unlockDescendants(child);
        }
    }

    bool isAncestor(int ancestor, int descendant) {
        while (depth[descendant] > depth[ancestor]) {
            descendant = nodes[descendant].parent;
        }
        return ancestor == descendant;
    }
};