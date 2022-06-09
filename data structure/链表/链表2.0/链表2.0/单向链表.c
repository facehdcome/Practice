#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//创建节点
struct LinkNode
{
	void* data;
	struct LinkNode* next;
};

//创建链表
struct LList
{
	struct LinkNode pHeader;
	int m_size;
};

//给用户一个接口
typedef  void* LinkList;

//初始化链表
LinkList  init_LinkList()
{
	struct LList* myList = malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.data = NULL;
	myList->pHeader.next = NULL;
	myList->m_size = 0;

	return myList;
}

//插入数据
void insert_LinkList(LinkList List, int pos, void* data)
{
	if (List == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}

	//判断用户传过来的位置是否有效(无效尾插)
	struct LList* myList = List;
	if (pos < 0 && pos > myList->m_size)
	{
		pos = myList->m_size;
	}

	//创建前驱节点
	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//创建新的数据
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	//初始化新的数据
	newNode->data = data;
	newNode->next = NULL;

	//建立关系，插入数据
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	myList->m_size++;
}

//遍历数据
void foreach_LinkList(LinkList List, void(*myPrint)(void*))
{
	if (List == NULL)
	{
		return List;
	}

	struct LList* myList = List;

	struct LinkNode* pCurrent = myList->pHeader.next;

	for (int i = 0; i < myList->m_size; i++)
	{
		myPrint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//按位置删除值
/*
* 	//找到待删除节点的前驱节点
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	//记录待删除的节点
	struct LinkNode * pDel = pCurrent->next;

	//重新建立节点关系
	pCurrent->next = pDel->next;

	free(pDel);
	pDel = NULL;

	//更新链表长度
	mylist->m_size--;
}
*/
void removeByPos_LinkList(LinkList List, int pos)
{
	if (List == NULL)
	{
		printf("无效地址！\n");
		return;
	}

	struct LList* myList = List;

	struct LinkNode* pCurrent = myList->pHeader.next;
	struct LinkNode* pPrve = &myList->pHeader;
	if (pos < 1 || pos > myList->m_size)
	{
		printf("\n选择错误，没有此位置！\n");
		return NULL;
	}
	else
	{
		for (int i = 1; i < pos; i++)
		{
			pPrve = pCurrent;
			pCurrent = pCurrent->next;
		}
		pPrve->next = pCurrent->next;
		free(pCurrent);
		pCurrent = NULL;
	}

	myList->m_size--;
}

//按值删除数据
void removeByValue_LinkList(LinkList List, void* data,int(*myCompare)(void*, void*))
{
	if (List == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}

	struct LList* myList = List;

	struct LinkNode* pPrve = &myList->pHeader;
	struct LinkNode* pCurrent = myList->pHeader.next;

	for (int i = 0; i < myList->m_size; i++)
	{
		if (myCompare(pCurrent->data, data))
		{
			pPrve->next = pCurrent->next;

			free(pCurrent);
			pCurrent = NULL;

			myList->m_size--;
			break;
		}
		pPrve = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//清空链表
void clear_LinkList(LinkList List)
{
	if (List == NULL)
	{
		return;
	}

	struct LList* myList = List;
	
	struct LinkNode* pCurrent = myList->pHeader.next;
	struct LinkNode* next = pCurrent->next;

	for (int i = 0; i < myList->m_size; i++)
	{
		struct LinkNode* next = pCurrent->next;

		free(pCurrent);
		pCurrent = next;
	}

	myList->pHeader.next = NULL;
	myList->m_size = 0;
}

//打印数据多少
int size_LinkList(LinkList List)
{
	if (List == NULL)
	{
		return -1;
	}

	struct LList* myList = List;
	return myList->m_size;
}

//销毁链表
void destroy_LinkList(LinkList List)
{
	if (List == NULL)
	{
		return;
	}
	clear_LinkList(List);

	free(List);
	List = NULL;
}





struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void* data)
{
	struct Person* p = data;
	printf("姓名：%s,年龄：%d\n", p->name, p->age);
}

int myCompare(void* e1, void* e2)
{
	struct Person* p1 = e1;
	struct Person* p2 = e2;

	return strcmp(p1->name,p2->name)== 0 && p1->age == p2->age;
}


void test()
{
	struct Person p1 = { "亚瑟",10 };
	struct Person p2 = { "狄仁杰",11 };
	struct Person p3 = { "后裔",12 };
	struct Person p4 = { "孙尚香",13 };
	struct Person p5 = { "李白",14 };
	struct Person p6 = { "荆轲",15 };

	//初始化链表
	LinkList myList = init_LinkList();
	//自己实现有点问题

	insert_LinkList(myList, 0, &p1);
	insert_LinkList(myList, 0, &p2);
	insert_LinkList(myList, -1, &p3);
	insert_LinkList(myList, 2, &p4);
	insert_LinkList(myList, 3, &p5);
	insert_LinkList(myList, 3, &p6);

	printf("插入数据前\n");
	foreach_LinkList(myList, myPrintPerson);


	/*removeByPos_LinkList(myList, 6);*/
	removeByValue_LinkList(myList, &p1, myCompare);
	printf("\n删除数据后\n");
	foreach_LinkList(myList, myPrintPerson);
}

//测试
int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

