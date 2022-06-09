#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1024

struct SStack
{
	void* data[MAX];//ջ������
	int m_Size;
};

typedef void* SeqStack;

//��ʼ��ջ init
SeqStack Init_SeqStack()
{
	struct SStack* myStack = malloc(sizeof(struct SStack));
	
	if (myStack == NULL)
	{
		return NULL;
	}

	memset(myStack->data, 0, sizeof(void*) * MAX);

	myStack->m_Size = 0;

	return myStack;
}

//��ջ  push
void push_SeqStack(SeqStack stack, void * data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct SStack* myStack = stack;
	if (myStack->m_Size == MAX)
	{
		return;
	}

	myStack->data[myStack->m_Size] = data;

	myStack->m_Size++;
}

//��ջ  pop
void pop_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	struct SStack* myStack = stack;

	if (myStack->m_Size == 0)
	{
		return;
	}

	myStack->data[myStack->m_Size - 1] = NULL;

	myStack->m_Size--;
}

//����ջ��  top
void* top_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	struct SStack* myStack = stack;

	if (myStack->m_Size == 0)
	{
		return NULL;
	}

	return myStack->data[myStack->m_Size - 1];
}

//ջ��С  size
int size_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack* myStack = stack;

	return myStack->m_Size;
}

//�Ƿ�Ϊ��  isEmpty
int isEmpty_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;//����-1������  ��ջ
	}

	struct SStack* mystack = stack;

	if (mystack->m_Size == 0)
	{
		return 1;
	}

	return 0; //����0 ���� ���ǿ�ջ

}

//����ջ destroy
void destroy_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
	stack = NULL;
}

struct Person
{
	char name[64];
	int age;
};


void test()
{
	//��ʼ��ջ
	SeqStack myStack = Init_SeqStack();

	struct Person p1 = {"aaa", 10 };
	struct Person p2 = {"bbb", 20 };
	struct Person p3 = {"ccc", 30 };
	struct Person p4 = {"ddd", 40 };
	struct Person p5 = {"eee", 50 };

	//��ջ
	push_SeqStack(myStack, &p1);
	push_SeqStack(myStack, &p2);
	push_SeqStack(myStack, &p3);
	push_SeqStack(myStack, &p4);
	push_SeqStack(myStack, &p5);

	printf("ջ��Ԫ�ظ���Ϊ��%d\n", size_SeqStack(myStack));

	while (isEmpty_SeqStack(myStack) == 0) //ջ��Ϊ�գ��鿴ջ��Ԫ�أ���ջ
	{
		struct Person* p = top_SeqStack(myStack);
		printf("������%s ���䣺%d\n", p->name, p->age);

		//��ջ
		pop_SeqStack(myStack);
	}
	

	printf("ջ��Ԫ�ظ���Ϊ��%d\n", size_SeqStack(myStack));
}

int main() 
{
	test();


	system("pause");
	return EXIT_SUCCESS;
}