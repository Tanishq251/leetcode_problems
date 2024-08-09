

class LockingTree {
private:
    struct MyTreeNode {
        int val;
        int lockedBy;
        int parent;
        int childrenStart;
        int childrenCount;
        int lockedDescendantCount;
        int depth;
        
        MyTreeNode(int v, int p = -1) : val(v), lockedBy(-1), parent(p), 
                                        childrenStart(-1), childrenCount(0),
                                        lockedDescendantCount(0), depth(0) {}
    };
    
    std::vector<MyTreeNode> nodes;
    std::vector<int> allChildren;
    std::unordered_set<int> lockedNodes;

public:
    LockingTree(std::vector<int>& parent) {
        int n = parent.size();
        nodes.reserve(n);
        for (int i = 0; i < n; ++i) {
            nodes.emplace_back(i, parent[i]);
        }
        
        std::vector<int> childrenCounts(n, 0);
        for (int i = 1; i < n; ++i) {
            if (parent[i] >= 0 && parent[i] < n) {
                childrenCounts[parent[i]]++;
            }
        }
        
        int totalChildren = 0;
        for (int i = 0; i < n; ++i) {
            nodes[i].childrenStart = totalChildren;
            totalChildren += childrenCounts[i];
        }
        
        allChildren.resize(totalChildren);
        std::vector<int> nextChildIndex(n);
        for (int i = 0; i < n; ++i) {
            nextChildIndex[i] = nodes[i].childrenStart;
        }
        
        for (int i = 1; i < n; ++i) {
            if (parent[i] >= 0 && parent[i] < n) {
                int p = parent[i];
                allChildren[nextChildIndex[p]++] = i;
                nodes[p].childrenCount++;
            }
        }
        
        calculateDepth(0, 0);
    }

    void calculateDepth(int nodeIndex, int depth) {
        nodes[nodeIndex].depth = depth;
        int childrenEnd = nodes[nodeIndex].childrenStart + nodes[nodeIndex].childrenCount;
        for (int i = nodes[nodeIndex].childrenStart; i < childrenEnd; ++i) {
            calculateDepth(allChildren[i], depth + 1);
        }
    }

    bool lock(int num, int user) {
        if (nodes[num].lockedBy == -1) {
            nodes[num].lockedBy = user;
            lockedNodes.insert(num);
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
            lockedNodes.erase(num);
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
        
        std::vector<int> toUnlock;
        for (int locked : lockedNodes) {
            if (isDescendant(num, locked)) {
                toUnlock.push_back(locked);
            }
        }
        
        for (int locked : toUnlock) {
            nodes[locked].lockedBy = -1;
            lockedNodes.erase(locked);
            parent = nodes[locked].parent;
            while (parent != -1) {
                nodes[parent].lockedDescendantCount--;
                parent = nodes[parent].parent;
            }
        }
        
        nodes[num].lockedBy = user;
        lockedNodes.insert(num);
        parent = nodes[num].parent;
        while (parent != -1) {
            nodes[parent].lockedDescendantCount++;
            parent = nodes[parent].parent;
        }
        return true;
    }

private:
    bool isDescendant(int ancestor, int descendant) {
        return nodes[ancestor].depth < nodes[descendant].depth &&
               isAncestor(ancestor, descendant);
    }
    
    bool isAncestor(int ancestor, int descendant) {
        while (nodes[descendant].depth > nodes[ancestor].depth) {
            descendant = nodes[descendant].parent;
        }
        return ancestor == descendant;
    }
};