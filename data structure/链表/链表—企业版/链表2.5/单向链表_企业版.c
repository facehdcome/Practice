#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//创建节点
struct LinkNode
{
	struct LinkNode* next;
};

//创建链表
struct LList
{
	struct LinkNode pHeader;
	int m_size;
};

//给用户一个地址
typedef void* LinkList;

//初始化链表
LinkList init_LinkList()
{
	struct LList* myList = malloc(sizeof(struct LList));
	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.next = NULL;
	myList->m_size = 0;

	return myList;
}

//插入链表
void insert_LinkList(LinkList List, int pos, void * data)
{
	if (List == NULL)
	{
		return NULL;
	}

	if (data == NULL)
	{
		return NULL;
	}

	//无效位置尾插
	struct LList* myList = List;

	if (pos < 0 && pos > myList->m_size-1)
	{
		pos = myList->m_size;
	}

	struct LinkNode* myNode = data;

	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	myNode->next = NULL;

	//建立关系
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	//更新链表的长度
	myList->m_size++;
}

//遍历
void foreach_LinkList(LinkList List, void(*myPrint)(void*))
{
	if (List == NULL)
	{
		return NULL;
	}

	struct LList* myList = List;
	struct LinkNode* myNode = myList->pHeader.next;

	for (int i = 0; i < myList->m_size; i++)
	{
		myPrint(myNode);
		myNode = myNode->next;
	}
}

//按位置删除节点
void removeByPos_LinkList(LinkList List, int pos)
{
	if (List == NULL)
	{
		return NULL;
	}

	//无效位置判断
	struct LList* myList = List;

	if (pos < 0 || pos > myList->m_size - 1)
	{
		printf("位置无效！\n");
		return NULL;
	}

	//找前驱结点
	struct LinkNode* pCurrent = &myList->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	struct LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;

	myList->m_size--;
}

void destroy_LinkList(LinkList List)
{
	if (List == NULL)
	{
		return NULL;
	}

	free(List);
	List = NULL;
}




struct Person
{
	void* data;
	char name[64];
	int age;
};

void myPrint(void* data)
{
	struct Person* p = data;
	printf("姓名： %s,  年龄： %d\n",p->name,p->age);
}

void test()
{
	LinkList myList = init_LinkList();

	struct Person p1 = { NULL,"aaa", 10 };
	struct Person p2 = { NULL,"bbb", 20 };
	struct Person p3 = { NULL,"ccc", 30 };
	struct Person p4 = { NULL,"ddd", 40 };
	struct Person p5 = { NULL,"eee", 50 };

	insert_LinkList(myList, 0, &p1);
	insert_LinkList(myList, 0, &p2);
	insert_LinkList(myList, 1, &p3);
	insert_LinkList(myList, -1, &p4);
	insert_LinkList(myList, 0, &p5);

	foreach_LinkList(myList, myPrint);

	//销毁数组
	destroy_LinkList(myList);
	myList = NULL;


}





int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}