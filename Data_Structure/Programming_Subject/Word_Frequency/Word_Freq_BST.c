#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME        100
#define MAX_WORDS       10000
#define MAX_WORD_SIZE   100
#define TRUE            1
#define FALSE           0

/// 데이터 형식
typedef struct
{
	char    word[MAX_WORD_SIZE];		/// 키필드
    int     count;
} element;

/// 노드의 구조
typedef struct TreeNode
{
	element key;
	struct TreeNode *left, *right;
} TreeNode;

/// 만약 e1 > e2 -> -1 반환
/// 만약 e1 == e2 -> 0  반환
/// 만약 e1 < e2 -> 1 반환
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
/// 디스크 파일로부터 한 개 단어를 읽어 배열 word에 저장
/// 성공적으로 읽었으면 TRUE, 그렇지 않으면(파일 끝) FALSE 리턴
int getword(FILE *fd, char *word)
{
    char    ch;
    int    i;

    do {
        ch = getc(fd);
        if (ch == EOF)
            return FALSE;
    } while (!isalpha(ch)); /// 첫번째 알파벳 문자가 나올때까지 읽는다.
    i = 0;
    do {    /// 단어 1개를 읽는다.
        ch = tolower(ch);   /// 소문자로 변환
        word[i++] = ch;
        ch = getc(fd);
    } while (isalpha(ch));  /// 알파벳 문자이면 계속 읽는다.
    word[i] = '\0';
    return TRUE;
    }

/// Binary Search Tree에 새 단어 추가 또는 기존 단어인 경우 빈도 갱신
TreeNode * update_BST(TreeNode **root, element key)
{
	//교재 프로그램 insert_node() 참고
    TreeNode *a,*b;
    TreeNode *newnode;
    a=*root;
    b = NULL;
    while(a !=NULL)
    {
        if(compare(key,a->key)==0)
		{
            a->key.count++;
            return a;
        }
        b = a;
        if(compare(key,a->key)<0)
		{
            a = a->left;
        }
        else
            a = a->right;
    }

    newnode= (TreeNode *)malloc(sizeof(TreeNode));
    if(newnode == NULL)
        return newnode;
    newnode->key = key;
    newnode->left = newnode->right =NULL;
    if(b !=NULL){
        if(compare(key,b->key)<0)
		{
            b->left = newnode;
            newnode->key.count=1;
        }
        else
		{
            b->right = newnode;
            newnode->key.count=1;
        }
    }
    else
	{
        *root =newnode;
        newnode->key.count=1;
    }
}

/// inorder traversal
void inorder(TreeNode *t)
{
    if(t)
    {
        inorder(t->left);
         printf("%s %d ",t->key.word,t->key.count);
        inorder(t->right);
    }
/// 방문한 노드의 단어와 count 출력
}

/// 노드 개수 세기
int get_node_count(TreeNode *node)
{
    int count = 0;
    if ( node != NULL )
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    return count;
}

/// 최대값 return
int max(int a, int b)
{
	if (a > b)
		return (a);
	else //else if 가 아닌 else 를 쓴 이유는 a 와 b가 같을경우 b를 리턴해도 최댓값이기 때문
		return (b);
}

/// 트리 높이 계산
int get_height(TreeNode *node)
{
    int height = 0;
    if(node != NULL)
        height = 1 + max(get_height(node->left),get_height(node->right));
    return height;
}

/// Binary Search Tree를 사용하여 단어 빈도 파악
int main()
{
	FILE        *fd;
 	element     e;
	TreeNode    *root=NULL;
	TreeNode    *tmp;
	char        fname[MAX_NAME];    /// 파일 이름
	char        w[MAX_WORD_SIZE];   /// 읽어들인 단어
	int         flag;               /// 파일 끝이 아닌지 여부
    clock_t     start, finish;
    double      duration;

    printf("파일 이름: ");
    scanf("%s",fname);
    if((fd =fopen(fname,"r"))==NULL){
        fprintf(stderr,"파일을 열수없습니다.\n");
        return 0;
    }

    start =clock();
    do{
		flag = getword(fd,w);
		if(flag ==FALSE)
			break;
        strcpy(e.word,w);
        update_BST(&root,e);

    }while(1);

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    inorder(root);

    printf("\n노드 개수 = %d\n",get_node_count(root));
    printf("트리 높이 = %d\n",get_height(root));
    printf("\n%.6f 초입니다.\n",duration);

}
