#include <stdio.h>
void mySort(int A[],int length)
{
	int i,j,max;
	int temp;
	for(j=length;j>1;j--)
	{
		max=0;
		for(i=0;i<j;i++)
		if(A[i]>A[max])
		max=i;
		if(max!=j-1)
		{
			temp=A[max];
			A[max]=A[j-1];
			A[j-1]=temp;
		}
	}
 } 

int main(void)
{
	int A[] = { 4, 8, 3, 9, 6, 4, 12, 0, 8, 3 };//0 3 3 4 4 6 8 8 9 12

	mySort(A, sizeof(A)/sizeof(A[0]));
	
	printf("after sorting:\n");
	
	for (int i = 0; i<sizeof(A) / sizeof(A[0]); i++)
	{
		printf("%d ", A[i]);
	}
}

