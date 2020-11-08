#include <stdio.h>
#include <stdlib.h>
#define SIZE (10000)

int cal_sum(int  list[ ], int  n)
{
	int  sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += list[i];
	}
	return sum;
}

void readArray(int list[], char *fname)
{
    FILE    *fp;
    int     i = 0;
    int     rc;
    
    fp = fopen(fname, "r");
    
    do {
        rc = fscanf(fp, " %d", &(list[i]));
        i++;
    } while (rc != EOF);
}

int main(void)
{
	int  *num;
	int  sum;
	
	num = (int *)malloc(sizeof(int) * SIZE);
	readArray(num, "primes.txt");
	sum = cal_sum(num, SIZE);
	
	printf("%d", sum);
	
	return 0;
}
