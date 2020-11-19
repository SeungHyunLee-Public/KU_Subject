#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES    50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;
// GraphType 정의 


// 그래프 초기화
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c]=0;
		}
	}
}

// 간선 삽입
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

//인접 행렬 출력 함수
void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

int main()
{
    GraphType   g;
    int         n;      // 정점 개수
    int         s, e;   // 간선

    // 그래프 초기화
    init(&g);

    // 정점 개수 입력
    scanf("%d", &n);

    // 정점 개수 설정
    g.n = n;


    // 간선 입력
    do {
        scanf("%d %d", &s, &e); // (s, e)
        if (s < 0 || e < 0) break;

        // 간선 (s, e) 입력
        insert_edge(&g, s, e);



    } while (1);

    // 각 정점의 차수(degree) 출력
    int edge_cnt = 0;
    int degree;
    for (int i = 0; i < g.n; i++)
    {
        //정점 i의 차수 출력
        degree = 0;
        for (int j = 0; j < g.n; j++)
            degree +=g.adj_mat[i][j];
        printf("%d : %d", i, degree);
        edge_cnt += degree;
    }



    // 간선(edge)의 총 개수 출력
    printf("%d", edge_cnt/2);



    // 각 간선 출력: 정점 번호 오름차순으로; (s, e) for s < e
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
            if (g.adj_mat[i][j] == 1)
                printf("%d, %d\n", i, j);
    }
    
    
}
