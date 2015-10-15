#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define f_N 20
#define strt_ 100
#define end_ 150
#define dffrnt (end_-strt_)

int rndm(int strt, int end);
int comp(void *a, void *b);

int main()
{
	int arr_n[f_N];
	srand(time(NULL));
	for (int i=0; i<f_N; i++)
	 arr_n[i]=rndm(strt_, end_);
	 
	printf("Unsorted: \n\n"); 
	 
	for (int i=0; i<f_N; i++)
		printf("%i\n",arr_n[i]);
		
	printf("\nSorted: \n\n");
		
	qsort(arr_n, f_N, sizeof(int),(__compar_fn_t)comp);
	
	for (int i=0; i<f_N; i++)
		printf("%i\n",arr_n[i]);
}

int rndm(int strt, int end)
{
	return (int)((end-strt)*((float)(rand()&127)/(RAND_MAX&127)))+strt;
}

int comp(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}
