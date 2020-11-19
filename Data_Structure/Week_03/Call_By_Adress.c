#include <stdio.h>

void increment(int *x)
{
   *x +=1;
}

int main(void)
{
    int     num;
    scanf("%d", &num);

   increment(&num);
	printf("%d\n", num);
}
