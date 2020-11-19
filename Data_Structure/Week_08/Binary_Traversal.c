#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode TreeNode;

// 노드 생성 함수 (인자: 데이터, 왼쪽 자식 주소, 오른쪽 자식 주소)
// 반환값: 생성된 노드의 주소 

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

TreeNode* makeNode(int data, TreeNode *left, TreeNode *right)
{
    TreeNode *p;
    p = (TreeNode *) malloc(sizeof(TreeNode));
    p->data = data;
    p->left = left;
    p->right = right;
    return p;
}

void preorder(TreeNode *p)
{
    if(p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(TreeNode *p)
{
    if(p != NULL)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

void postorder(TreeNode *p)
{
    if(p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

int main()
{
    TreeNode    *n1, *n2, *n3, *n4, *n5;
    int data;
    // 정수를 하나씩 입력 받을 때마다 노드를 생성하여 트리 구성
    // makeNode() 함수 이용
    scanf("%d", &data);
    n4 = makeNode(data, NULL, NULL);
    scanf("%d", &data);
    n5 = makeNode(data, NULL, NULL);
    scanf("%d", &data);
    n2 = makeNode(data, n4, n5);
    scanf("%d", &data);
    n3 = makeNode(data, NULL, NULL);
    scanf("%d", &data);
    n1 = makeNode(data, n2, n3);
    
    // preorder
    preorder(n1);
    printf("\n");   
    
    // inorder
    inorder(n1);
    printf("\n");
    
    // postorder
    postorder(n1);
    printf("\n");
}

