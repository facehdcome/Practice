
#include "LinkList.h"
struct LinkNode* InitLinkNode()
{
	//����ͷ���
	struct LinkNode* pHeader = malloc(sizeof(struct LinkNode));
	if (pHeader == NULL)
	{
		return NULL;
	}

	//��ʼ��ͷ���
	pHeader->next = NULL;
	struct LinkNode* pTell = pHeader;

	int val = -1;
	while (1)
	{
		printf("���ʼ�����ݣ��������-1�˳�\n");
		scanf("%d", &val);

		if (val == -1)
		{
			break;
		}
		//������벻��-1����ڵ㵽������
		else
		{
			struct LinkNode* NewNode = malloc(sizeof(struct LinkNode));
			NewNode->num = val;
			NewNode->next = NULL;

			pTell->next = NewNode;
			//�����µ�β����ָ��
			pTell = NewNode;
	
		}
	}

	return pHeader;
}

//��������
void foreach_LinkList(struct  LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return NULL;
	}

	//��һ����Ч����
	struct LinkNode* pCurrent = pHeader->next;
	while (pCurrent != NULL)
	{
		printf("%d\t", pCurrent->num);
		pCurrent = pCurrent->next;
	}
}
