
#include "LinkList.h"
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//��̬����
//struct LinkNode
//{
//	int num;
//	struct LinkNode* next;
//};
//
//void test1()
//{
//	struct LinkNode node1 = { 10,NULL };
//	struct LinkNode node2 = { 11,NULL };
//	struct LinkNode node3 = { 12,NULL };
//	struct LinkNode node4 = { 13,NULL };
//	struct LinkNode node5 = { 14,NULL };
//	struct LinkNode node6 = { 15,NULL };
//
//	node1.next = &node2;
//	node2.next = &node3;
//	node3.next = &node4;
//	node4.next = &node5;
//	node5.next = &node6;
//
//	struct LinkNode* pCurrent = &node1;
//
//	while (pCurrent != NULL)
//	{
//		printf("%d\t", pCurrent->num);
//		pCurrent = pCurrent->next;
//	}
//}

//��̬����
//void test2()
//{
//	struct LinkNode
//	{
//		int data;
//		struct LinkNode* next;
//	};
//
//	struct LinkNode* node1 = malloc(sizeof(struct LinkNode));
//	struct LinkNode* node2 = malloc(sizeof(struct LinkNode));
//	struct LinkNode* node3 = malloc(sizeof(struct LinkNode));
//	struct LinkNode* node4 = malloc(sizeof(struct LinkNode));
//	struct LinkNode* node5 = malloc(sizeof(struct LinkNode));
//
//	node1->data = 100;
//	node2->data = 100;
//	node3->data = 100;
//	node4->data = 100;
//	node5->data = 100;
//
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = NULL;
//
//	struct LinkNode* pCurrent = node1;
//	while (pCurrent != NULL)
//	{
//		printf("%d\t", pCurrent->data);
//		pCurrent = pCurrent->next;
//	}
//
//	free(node1);
//	node1 = NULL;
//	free(node2);
//	node2 = NULL;
//	free(node3);
//	node3 = NULL;
//	free(node4);
//	node4 = NULL;
//	free(node5);
//	node5 = NULL;
//}


//��ͷ�벻��ͷ����

//��ͷ����ŵ㣬��Զ�̶���ͷ����λ����
int main()
{
	/*test1();*/
	/*test2();*/
	struct LinkNode* pHeader = InitLinkNode();

	//��������
	printf("��������\n");
	foreach_LinkList(pHeader);

	system("pause");
	return EXIT_SUCCESS;
}

