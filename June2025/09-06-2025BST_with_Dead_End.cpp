/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution
{
public:
    void storeNodes(Node *root, set<int> &allNodes, set<int> &leafNodes)
    {
        if (!root)
            return;

        allNodes.insert(root->data);

        if (!root->left && !root->right)
        {
            leafNodes.insert(root->data);
        }

        storeNodes(root->left, allNodes, leafNodes);
        storeNodes(root->right, allNodes, leafNodes);
    }

    bool isDeadEnd(Node *root)
    {
        set<int> allNodes, leafNodes;
        allNodes.insert(0);

        storeNodes(root, allNodes, leafNodes);

        for (int leaf : leafNodes)
        {
            if (allNodes.find(leaf - 1) != allNodes.end() &&
                allNodes.find(leaf + 1) != allNodes.end())
            {
                return true;
            }
        }
        return false;
    }
};