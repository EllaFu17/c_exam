#include <stdio.h>

int FindElement(int a[], int n, int x)
{
   int i,j, num;
   num = 0;
   for(i=n;i>1;i--)
   {
   	a[i]=a[i-1];
   }
   a[0]=n;
   for(j = n;j>1;j--)
   {
   	if(a[j]==x)
   	{
		num = j;
   		break;
	}
   }
   return num;
}

int main(void)
{
	int A[] = { 1, 3, 5, 8, 9, 5, 7, 10, 12};
	int e;
	int RetVal;
    scanf("%d", &e);
	RetVal=FindElement(A, sizeof(A)/sizeof(0), e);

	if(RetVal)
		printf("The position of the element is %d\n", RetVal);
	else
		printf("The element doesn't exist in the array!\n");
}
