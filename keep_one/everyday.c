//3.判断1000年---2000年之间的闰年（百年不闰，四年一闰，四百年一闰）
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
//	printf("\n一共有 %d 个闰年数字",count);
//
//	return 0;
//}




//2.输出九九乘法口诀表(四种位置)
//左上三角
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



//右上三角*
//#include <stdio.h>
//int main()
//{
//	int row = 0;
//	int col = 0;
//	int space = 0;							//打印空格
//
//	for (row = 1; row <= 9; row++)
//	{
//		for (space = 2; space <= row; space++)							//space等于2，不打印第一行
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



//右下三角*
//#include<stdio.h>
//int main()
//{
//	int row = 0;
//	int col = 0;
//	int space = 0;							//打印空格

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



//左下三角
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



//完整的矩形
//#include <stdio.h>
//int main()
//{
//	int row = 0;								//控制行
//	int col= 0;								//控制列

//	for (row = 1; row <= 9; row++)
//	{
//		for (col = 1; col <= 9; col++)
//		{
//			printf("%d*%d=%2d\t", row, col, row * col);  //  \t 八个空格
//		}
//		printf("\n");
//	}
//
//	return 0;
//}





//1.打印100-200之间的素数 有多少个
//分析（素数只有本身和1，且1不是素数）
//#include <math.h>
//#include <stdio.h>
//int main()
//{
//	int i = 0;										//需要判断的整数
//	int count = 0;								//计数器

//	for (i = 100; i <= 200; i++)
//	{
//		int k = 0;									//除数
//		for (k = 2; k < sqrt(i); k++)		//开方
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
//	printf("\n一共有 %d 个素数", count);
//
//	return 0;
//}