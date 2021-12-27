#include <mm_malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  1
#define FALSE  0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int SElemType;

#define STACK_INIT_SIZE   100        //Initial size for memory allocation
#define STACKINCREMENT  10          //incremental size 

typedef struct SqStack
{
	SElemType  *base;    //base pointer
	SElemType  *top;      //top pointer
	int        stacksize;     //current size
}SqStack;

//==================================================
// Initialize a stack
//====================================================
Status InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base) return ERROR;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//==============================================
//test empty stack
//===============================================
Status StackEmpty(SqStack S)
{
	return (S.top == S.base);   //empty stack
}

//===================================
// Get the length of a stack
//==================================
int  StackLength(SqStack S)
{
	return (S.top - S.base);
}

//=================================
//Get the element at the top end
//==================================
Status GetTop(SqStack S, SElemType &e)
{
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

//==================================
//delete the element at the top end 
//=====================================
Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}
//==================================
//Insert an element
//=================================
Status Push(SqStack &S, SElemType e)
{
	if (S.top - S.base >= S.stacksize) //stack is full, increase the size
	{      
		S.base = (SElemType *)realloc(S.base, (S.stacksize +
			STACKINCREMENT)*sizeof(SElemType));
		if (!S.base) return ERROR;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status myFunc(char str[])
{
    SqStack
    SElemType c;
    ElemType *p = str.elem;
    int state = 0;
    InitStack(s);
    while(p < str.elem + StackLength(str)){
        if(*p == '{' || *p == '[' || *p == '('){
            Push(s,*p);
        }
        else if(*p == '}' || *p == ']' || *p == ')'){
                if(StackEmpty(s))return 0;
                GetTop(s,c);
                switch(c){ 
                    case '(' : {
                                if(*p == ')'){
                                        Pop(s,c);
                                        state = 1;
                                        break;
                                    }                                                                       
                                 else return 0;
                                }
                    case '[' : {
                                if(*p == ']'){
                                        Pop(s,c);
                                        state = 1; 
                                        break;
                                    }                                    
                                  else return 0;
                                }
                    case '{' : {
                                if(*p == '}'){
                                        Pop(s,c);
                                        state = 1; 
                                        break;
                                    }
                                   else return 0;
                                }
                }            
        } 
        p++;
    }
    if(StackEmpty(s))state = 1;
    else state = 0;
    if(state == 1)
	return 1;
    else return 0;

	
}

void main()
{
	char str[1024];
	printf("please input a string inlcuding (  )  [  ]  {  } \n");
	scanf("%s", str);

	printf("the input string is %s", str);

	if (myFunc(str))
	{
		printf("Parentheses appear in pairs");
	}
	else
	{
		printf("Parentheses do not appear in pairs");
	}

}
