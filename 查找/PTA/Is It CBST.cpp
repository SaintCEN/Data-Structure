#include <stdio.h>

#define MAXN 10

int IsCBST(int A[], int N);

int main()
{
    int A[MAXN], N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    if (IsCBST(A, N))
        printf("Yes\n");
    else
        printf("No\n");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}

typedef struct Node
{
    int key;
    struct Node *left, *right;
} Node;

Node *Insert(Node *root, int key)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->key = key;
        root->left = root->right = NULL;
    }
    else if (key > root->key)
    {
        root->left = Insert(root->left, key);
    }
    else
    {
        root->right = Insert(root->right, key);
    }
    return root;
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int Complete(Node *root, int idx, int n)
{
    if (root == NULL)
        return 1;
    if (idx >= n)
        return 0;
    return Complete(root->left, 2 * idx + 1, n) &&
           Complete(root->right, 2 * idx + 2, n);
}

int postorder(Node *root, int arr[], int idx)
{
    if (root == NULL)
        return idx;
    idx = postorder(root->left, arr, idx);
    idx = postorder(root->right, arr, idx);
    arr[idx++] = root->key;
    return idx;
}

int IsCBST(int A[], int N)
{
    Node *root = NULL;
    for (int i = 0; i < N; i++)
    {
        root = Insert(root, A[i]);
    }
    int total = countNodes(root);
    int flag = Complete(root, 0, total);
    int *tmp = (int *)malloc(sizeof(int) * N);
    postorder(root, tmp, 0);
    for (int i = 0; i < N; i++)
        A[i] = tmp[i];
    free(tmp);
    return flag;
}