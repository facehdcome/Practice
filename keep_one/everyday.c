//3.�ж�1000��---2000��֮������꣨���겻������һ���İ���һ��
//#include<stdio.h>
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		{
//			printf(" %d ", year);
//			count++;
//		}
//	}
//	printf("\nһ���� %d ����������",count);
//
//	return 0;
//}




//2.����žų˷��ھ���(����λ��)
//��������
//#include<stdio.h>
//int main()
//{
//	int row = 0;
//	int col = 0;
//
//	for (row = 1; row <= 9; row++)
//	{
//		for (col = row; col <= 9; col++)
//		{
//			printf("%d*%d=%2d\t", row, col, row * col);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//��������*
//#include <stdio.h>
//int main()
//{
//	int row = 0;
//	int col = 0;
//	int space = 0;							//��ӡ�ո�
//
//	for (row = 1; row <= 9; row++)
//	{
//		for (space = 2; space <= row; space++)							//space����2������ӡ��һ��
//		{
//			printf("\t");
//		}
//		for (col = row; col <= 9; col++)
//		{
//			printf("%d*%d=%2d\t", row, col, row * col);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//��������*
//#include<stdio.h>
//int main()
//{
//	int row = 0;
//	int col = 0;
//	int space = 0;							//��ӡ�ո�

//	for (row = 1; row <= 9; row++)
//	{
//		for (space = row; space <= 8; space++)
//		{
//			printf("\t");
//		}
//		for (col = 1; col <= row; col++)
//		{
//			printf("%d*%d=%2d\t", row, col, row * col);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//��������
//#include <stdio.h>
//int main()
//{
//	int row = 0;
//	int col = 0;

//	for (row = 1; row <= 9; row++)
//	{
//		for (col = 1; col <= row; col++)
//		{
//			printf("%d*%d=%2d\t", row, col, row * col);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//�����ľ���
//#include <stdio.h>
//int main()
//{
//	int row = 0;								//������
//	int col= 0;								//������

//	for (row = 1; row <= 9; row++)
//	{
//		for (col = 1; col <= 9; col++)
//		{
//			printf("%d*%d=%2d\t", row, col, row * col);  //  \t �˸��ո�
//		}
//		printf("\n");
//	}
//
//	return 0;
//}





//1.��ӡ100-200֮������� �ж��ٸ�
//����������ֻ�б����1����1����������
//#include <math.h>
//#include <stdio.h>
//int main()
//{
//	int i = 0;										//��Ҫ�жϵ�����
//	int count = 0;								//������

//	for (i = 100; i <= 200; i++)
//	{
//		int k = 0;									//����
//		for (k = 2; k < sqrt(i); k++)		//����
//		{
//			if (i % k == 0)
//				break;
//		}
//		if (k > sqrt(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	
//	}
//	printf("\nһ���� %d ������", count);
//
//	return 0;
//}