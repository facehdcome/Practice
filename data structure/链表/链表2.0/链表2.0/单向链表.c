#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//�����ڵ�
struct LinkNode
{
	void* data;
	struct LinkNode* next;
};

//��������
struct LList
{
	struct LinkNode pHeader;
	int m_size;
};

//���û�һ���ӿ�
typedef  void* LinkList;

//��ʼ������
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

//��������
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

	//�ж��û���������λ���Ƿ���Ч(��Чβ��)
	struct LList* myList = List;
	if (pos < 0 && pos > myList->m_size)
	{
		pos = myList->m_size;
	}

	//����ǰ���ڵ�
	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����µ�����
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	//��ʼ���µ�����
	newNode->data = data;
	newNode->next = NULL;

	//������ϵ����������
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	myList->m_size++;
}

//��������
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

//��λ��ɾ��ֵ
/*
* 	//�ҵ���ɾ���ڵ��ǰ���ڵ�
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	//��¼��ɾ���Ľڵ�
	struct LinkNode * pDel = pCurrent->next;

	//���½����ڵ��ϵ
	pCurrent->next = pDel->next;

	free(pDel);
	pDel = NULL;

	//����������
	mylist->m_size--;
}
*/
void removeByPos_LinkList(LinkList List, int pos)
{
	if (List == NULL)
	{
		printf("��Ч��ַ��\n");
		return;
	}

	struct LList* myList = List;

	struct LinkNode* pCurrent = myList->pHeader.next;
	struct LinkNode* pPrve = &myList->pHeader;
	if (pos < 1 || pos > myList->m_size)
	{
		printf("\nѡ�����û�д�λ�ã�\n");
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

//��ֵɾ������
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

//�������
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

//��ӡ���ݶ���
int size_LinkList(LinkList List)
{
	if (List == NULL)
	{
		return -1;
	}

	struct LList* myList = List;
	return myList->m_size;
}

//��������
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
	printf("������%s,���䣺%d\n", p->name, p->age);
}

int myCompare(void* e1, void* e2)
{
	struct Person* p1 = e1;
	struct Person* p2 = e2;

	return strcmp(p1->name,p2->name)== 0 && p1->age == p2->age;
}


void test()
{
	struct Person p1 = { "��ɪ",10 };
	struct Person p2 = { "���ʽ�",11 };
	struct Person p3 = { "����",12 };
	struct Person p4 = { "������",13 };
	struct Person p5 = { "���",14 };
	struct Person p6 = { "����",15 };

	//��ʼ������
	LinkList myList = init_LinkList();
	//�Լ�ʵ���е�����

	insert_LinkList(myList, 0, &p1);
	insert_LinkList(myList, 0, &p2);
	insert_LinkList(myList, -1, &p3);
	insert_LinkList(myList, 2, &p4);
	insert_LinkList(myList, 3, &p5);
	insert_LinkList(myList, 3, &p6);

	printf("��������ǰ\n");
	foreach_LinkList(myList, myPrintPerson);


	/*removeByPos_LinkList(myList, 6);*/
	removeByValue_LinkList(myList, &p1, myCompare);
	printf("\nɾ�����ݺ�\n");
	foreach_LinkList(myList, myPrintPerson);
}

//����
int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

