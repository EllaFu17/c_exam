#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

// definition of node structure of singly linked list
typedef struct L_node
{
	ElemType data;           // data field
	struct L_node *next;     // pointer field
}LNode, *LinkList;

//===========================================
// Create a singly linked list L with head node, and with n elements
//===========================================
Status CreateList_L(LinkList &L, int n)
{
	LinkList p, q;
	int i;

	L = (LinkList)malloc(sizeof(LNode)); //create an empty list
	if (!L) return ERROR;
	L->next = NULL;
	q = L;
	for (i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(LNode));    //make a new node
		if (!p) return ERROR;
		scanf("%d", &p->data);                    //enter element data from keyboard

		p->next = NULL;
		q->next = p;
		q = p;
	}
	return OK;
}

//======================================
//Print all elements of the linked list
//=======================================
void LinkedListPrint(LinkList L)
{
LinkList A=(LinkList)malloc(sizeof(LNode));
    A=L;
	while(NULL!=A->next){
		A=A->next;
		printf("%d\n",A->data);
	}
    printf("\n");
}

//=========================================
// Get the length of the list
//=========================================
int ListLength_L(LinkList L)
{
	LinkList A=(LinkList)malloc(sizeof(LNode));
    A=L;
    int i=0;
	while(NULL!=A->next){
		A=A->next;
		i++;}
    return i;
}

//=========================================
//Find the maximum node and return the value
//the pointer of the Maxnode is returned by p.
//=========================================
int GetMax(LinkList L, LinkList pMax)
{
LinkList A=(LinkList)malloc(sizeof(LNode));
    A=L;
    pMax=L;
    int m=0;
	while(NULL!=A->next){
		A=A->next;
		if(A->data>m){
			m=A->data;
			pMax=A;
		}
	}
return m;
}

//=========================================
//Move the maximum node to the front of the list
// pMax is the pointer to the MaxNode
//=========================================
void MoveMax(LinkList L, LinkList pMax, int m)
{
    LinkList a=(LinkList)malloc(sizeof(LNode));
    a=L;
    while(NULL!=a->next){//aȡpMaxǰһ�� 
		a=a->next;
		if(a->next->data==m){
		break;
		}
	}
	a->next=pMax->next;
	pMax->next=L->next;
	L->next=pMax;
}

int main(void)
{

	LinkList LA;
	int len;

	// Create a singly linked list with elements of 21, 18, 30, 75, 42, 56
	printf("please enter 6 numbers:\n");
	CreateList_L(LA, 6);

	// print out the linked list
	printf("the list is:\n"); 
	LinkedListPrint(LA);

	// get the length
	len = ListLength_L(LA);
	printf("the length of the list is %d\n", len);

	//get the maxmum value
	int maxVal;
	LinkList pMaxNode;
	maxVal = GetMax(LA, pMaxNode);
	printf("the maximum value is %d\n", maxVal);//minimum

	//Move the maximum node to the front of the list
	MoveMax(LA, pMaxNode,maxVal);

	LinkedListPrint(LA);

}
