#include <stdio.h>

//===============================
// Calculate the sum of array in recursive way 
//===============================
int GetSum_R(int a[], int n)
{
	
int sum=0,i;
for(i=0;i<n;i++)
{
	sum=sum+a[i];
	}
	return sum;
}

int main(void)
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum;
	
	sum = GetSum_R(A, sizeof(A)/sizeof(int));

	printf("the sum of array A: %d", sum);

}
