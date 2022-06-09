#pragma  once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct LinkNode
{
	int num;
	struct LinkNode* next;
};

//��ʼ������
struct LinkNode* initLinkList();

//��������
void foreach_LinkList(struct LinkNode* pHeader);

//��������
void insert_LinkList(struct LinkNode* pHeader, int oldVal, int newVal);

//��λ�ò�������
void insertByPos_LinkList(struct LinkNode* pHeader, int pos, int newVal);

//ɾ������
void delete_LinkList(struct LinkNode* pHeader, int val);

//��λ��ɾ������
void deleteByPos_LinkList(struct LinkNode* pHeader, int pos);

//�������
void clear_LinkList(struct LinkNode* pHeader);

//��������
void destroy_LinkList(struct LinkNode* pHeader);

//��ת����
void reverse_LinkList(struct LinkNode* pHeader);