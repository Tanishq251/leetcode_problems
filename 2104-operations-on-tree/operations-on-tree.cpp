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
            MyTreeNode* parent = node->parent;
            while (parent) {
                parent->lockedDescendantCount++;
                parent = parent->parent;
            }
            return true;
        }
        return false; // Node is already locked
    }

    bool unlock(int num, int user) {
        MyTreeNode* node = nodeMap[num];
        if (node->lockedBy == user) { // If the node is locked by the same user
            node->lockedBy = -1;
            MyTreeNode* parent = node->parent;
            while (parent) {
                parent->lockedDescendantCount--;
                parent = parent->parent;
            }
            return true;
        }
        return false; // Node is either unlocked or locked by a different user
    }

    bool upgrade(int num, int user) {
        MyTreeNode* node = nodeMap[num];
        if (node->lockedBy != -1 || node->lockedDescendantCount == 0) {
            return false; // The node is either locked or has no locked descendants
        }

        MyTreeNode* parent = node->parent;
        while (parent) { // Check if any ancestor is locked
            if (parent->lockedBy != -1) return false;
            parent = parent->parent;
        }

        // Unlock all locked descendants
        unlockDescendants(node);

        // Lock the current node
        node->lockedBy = user;
        parent = node->parent;
        while (parent) { // Update ancestors about the locking
            parent->lockedDescendantCount++;
            parent = parent->parent;
        }
        return true;
    }

    void unlockDescendants(MyTreeNode* node) {
        for (MyTreeNode* child : node->children) {
            if (child->lockedBy != -1) {
                child->lockedBy = -1;
                MyTreeNode* parent = child->parent;
                while (parent) {
                    parent->lockedDescendantCount--;
                    parent = parent->parent;
                }
            }
            unlockDescendants(child); // Recursively unlock all descendants
        }
    }
};