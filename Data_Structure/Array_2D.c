#include <stdio.h>
#define ROWS  2
#define COLS   3

int cal_sum(int list[], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            sum += list[i * cols + j];
    return sum;
    
}

int main(void)
{
	int  num[ROWS][COLS] = { { 2, 3, 5} , {7, 9, 11}  };
	int  sum = cal_sum((int *) num, ROWS, COLS);
	printf("합 = %d \n", sum);
	return 0;
}

