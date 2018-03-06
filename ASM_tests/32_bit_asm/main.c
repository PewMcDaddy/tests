#include <stdlib.h>
#include <stdio.h>

// Function implemented in sum_s.s
int sum_s(int n);

/*******************************************************************************
 *
*******************************************************************************/
int sum_c(int n)
{
	int sum = 0;
	for(int i = 0; i < n; ++i){
		sum = i + sum;
	}
	return sum;
}

/*******************************************************************************
 *
*******************************************************************************/
int main()
{
	printf("sum_c(40) is %d\n", sum_c(40));
	printf("sum_s(40) is %d\n", sum_s(40));
	return 0;
}
