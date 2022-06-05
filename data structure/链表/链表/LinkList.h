#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkNode
{
	int num;
	struct LinkNode* next;
};

struct LinkNode* InitLinkNode();
void foreach_LinkList(struct LinkNode *pHeader);