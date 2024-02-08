#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find the Lowest Common Ancestor (LCA) in a binary tree
struct TreeNode* findLCA(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root)
        return NULL;

    // If either p or q is the root, then root is the LCA
    if (root == p || root == q)
        return root;

    // Recursively find LCA in the left and right subtrees
    struct TreeNode* leftLCA = findLCA(root->left, p, q);
    struct TreeNode* rightLCA = findLCA(root->right, p, q);

    // If both leftLCA and rightLCA are not NULL, then root is the LCA
    if (leftLCA && rightLCA)
        return root;

    // Otherwise, return the non-NULL LCA (either leftLCA or rightLCA)
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Helper function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* constructTree(int arr[], int size, int index) {
    if (index >= size)
        return NULL;

    struct TreeNode* root = createNode(arr[index]);

    // Recursively construct left and right subtrees
    root->left = constructTree(arr, size, 2 * index + 1);
    root->right = constructTree(arr, size, 2 * index + 2);

    return root;
}


int main() {
    // // Example binary tree
    // struct TreeNode* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(int);

    // Construct the binary tree
    struct TreeNode* root = constructTree(arr, size, 0);

    // Nodes for which we want to find the LCA
    struct TreeNode* n1 = root->left->left; // Node 4
    struct TreeNode* n2 = root->left->right; // Node 5

    // Find the LCA
    struct TreeNode* lca = findLCA(root, n1, n2);

    if (lca)
        printf("The Closest Common Ancestor of nodes %d and %d is node %d.\n", n1->data, n2->data, lca->data);
    else
        printf("Nodes %d and %d do not have a common ancestor.\n", n1->data, n2->data);

    // Clean up memory (free tree nodes)
    // ...

    return 0;
}
