struct MyTreeNode {
    int val;
    int lockedBy; // Stores the user who locked the node, or -1 if unlocked
    MyTreeNode* parent; // Pointer to the parent node
    vector<MyTreeNode*> children; // List of child nodes
    int lockedDescendantCount; // Count of locked descendants

    MyTreeNode(int v, MyTreeNode* p = nullptr) : val(v), lockedBy(-1), parent(p), lockedDescendantCount(0) {}
};

class LockingTree {
private:
    unordered_map<int, MyTreeNode*> nodeMap; // Mapping from node value to MyTreeNode pointer
    unordered_map<int, int> lockedNodes; // Mapping from locked node to the user

public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        for (int i = 0; i < n; ++i) {
            nodeMap[i] = new MyTreeNode(i);
        }

        // Building the tree
        for (int i = 1; i < n; ++i) {
            int p = parent[i];
            nodeMap[i]->parent = nodeMap[p];
            nodeMap[p]->children.push_back(nodeMap[i]);
        }
    }

    bool lock(int num, int user) {
        MyTreeNode* node = nodeMap[num];
        if (node->lockedBy == -1) { // If the node is unlocked
            node->lockedBy = user;
            lockedNodes[num] = user;
            updateLockedDescendantCount(node, 1);
            return true;
        }
        return false; // Node is already locked
    }

    bool unlock(int num, int user) {
        MyTreeNode* node = nodeMap[num];
        if (node->lockedBy == user) { // If the node is locked by the same user
            node->lockedBy = -1;
            lockedNodes.erase(num);
            updateLockedDescendantCount(node, -1);
            return true;
        }
        return false; // Node is either unlocked or locked by a different user
    }

    bool upgrade(int num, int user) {
        MyTreeNode* node = nodeMap[num];
        if (node->lockedBy != -1 || node->lockedDescendantCount == 0) {
            return false; // The node is either locked or has no locked descendants
        }

        if (hasLockedAncestor(node)) {
            return false; // Any ancestor is locked
        }

        // Unlock all locked descendants in O(log n) by iterating over the lockedNodes map
        vector<int> toUnlock;
        for (auto& [lockedNodeNum, _] : lockedNodes) {
            MyTreeNode* lockedNode = nodeMap[lockedNodeNum];
            if (isDescendant(node, lockedNode)) {
                toUnlock.push_back(lockedNodeNum);
            }
        }

        for (int nodeNum : toUnlock) {
            unlock(nodeNum, lockedNodes[nodeNum]);
        }

        // Lock the current node
        return lock(num, user);
    }

private:
    bool isDescendant(MyTreeNode* ancestor, MyTreeNode* node) {
        while (node) {
            if (node == ancestor) return true;
            node = node->parent;
        }
        return false;
    }

    void updateLockedDescendantCount(MyTreeNode* node, int delta) {
        MyTreeNode* parent = node->parent;
        while (parent) {
            parent->lockedDescendantCount += delta;
            parent = parent->parent;
        }
    }

    bool hasLockedAncestor(MyTreeNode* node) {
        MyTreeNode* parent = node->parent;
        while (parent) {
            if (parent->lockedBy != -1) return true;
            parent = parent->parent;
        }
        return false;
    }
};
