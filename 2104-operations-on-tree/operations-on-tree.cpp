struct MyTreeNode {
    int val;
    int lockedBy; 
    MyTreeNode* parent; 
    vector<MyTreeNode*> children; 
    int lockedDescendantCount; 

    MyTreeNode(int v, MyTreeNode* p = nullptr) : val(v), lockedBy(-1), parent(p), lockedDescendantCount(0) {}
};

class LockingTree {
private:
    unordered_map<int, MyTreeNode*> nodeMap; 
    unordered_map<int, int> depth; 
    vector<int> parent; 

public:
    LockingTree(vector<int>& parent) : parent(parent) {
        int n = parent.size();
        for (int i = 0; i < n; ++i) {
            nodeMap[i] = new MyTreeNode(i);
        }

        for (int i = 1; i < n; ++i) {
            int p = parent[i];
            nodeMap[i]->parent = nodeMap[p];
            nodeMap[p]->children.push_back(nodeMap[i]);
        }

        dfs(nodeMap[0], 0);
    }

    bool lock(int num, int user) {
        MyTreeNode* node = nodeMap[num];
        if (node->lockedBy == -1) { 
            node->lockedBy = user;
            update(node, 1);
            return true;
        }
        return false; 
    }

    bool unlock(int num, int user) {
        MyTreeNode* node = nodeMap[num];
        if (node->lockedBy == user) { 
            node->lockedBy = -1;
            update(node, -1);
            return true;
        }
        return false; 
    }

    bool upgrade(int num, int user) {
        MyTreeNode* node = nodeMap[num];
        if (node->lockedBy != -1 || node->lockedDescendantCount == 0) {
            return false; 
        }

        MyTreeNode* parent = node->parent;
        while (parent) { 
            if (parent->lockedBy != -1) return false;
            parent = parent->parent;
        }

        unlockDescendants(node);
        node->lockedBy = user;
        update(node, 1);
        return true;
    }

private:
    void dfs(MyTreeNode* node, int d) {
        depth[node->val] = d;
        for (MyTreeNode* child : node->children) {
            dfs(child, d + 1);
        }
    }

    void update(MyTreeNode* node, int delta) {
        while (node) {
            node->lockedDescendantCount += delta;
            node = node->parent;
        }
    }

    void unlockDescendants(MyTreeNode* node) {
        for (MyTreeNode* child : node->children) {
            if (child->lockedBy != -1) {
                child->lockedBy = -1;
                update(child, -1);
            }
            unlockDescendants(child);
        }
    }
};