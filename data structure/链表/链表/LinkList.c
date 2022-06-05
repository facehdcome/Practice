
#include "LinkList.h"
struct LinkNode* InitLinkNode()
{
	//创建头结点
	struct LinkNode* pHeader = malloc(sizeof(struct LinkNode));
	if (pHeader == NULL)
	{
		return NULL;
	}

	//初始化头结点
	pHeader->next = NULL;
	struct LinkNode* pTell = pHeader;

	int val = -1;
	while (1)
	{
		printf("请初始化数据，如果等于-1退出\n");
		scanf("%d", &val);

		if (val == -1)
		{
			break;
		}
		//如果输入不是-1插入节点到链表中
		else
		{
			struct LinkNode* NewNode = malloc(sizeof(struct LinkNode));
			NewNode->num = val;
			NewNode->next = NULL;

			pTell->next = NewNode;
			//更新新的尾结点的指向
			pTell = NewNode;
	
		}
	}

	return pHeader;
}

//遍历链表
void foreach_LinkList(struct  LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return NULL;
	}

	//第一个有效数据
	struct LinkNode* pCurrent = pHeader->next;
	while (pCurrent != NULL)
	{
		printf("%d\t", pCurrent->num);
		pCurrent = pCurrent->next;
	}
}
