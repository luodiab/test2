#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


//第六章 -- 编程练习
//(1)

//#define SUM 26
//
//int main()
//{
//	char arry[SUM];
//	int a;
//
//	printf("please input letter:\n");
//		scanf("%s", arry);
//	printf("This is the word you typed:");
//	for (a = 0; a < SUM; a++)
//	{
//		printf("%c",arry[a]);
//	}
//	printf("\n");
//	return 0;
//}


//(2)
//
//#define SUY 5
//int main()
//{
//	int a,b;
//
//	for (a = 0; a < SUY; a++)
//	{
//		for (b = 0; b <= a; b++)
//		{
//			printf("$");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//(3)
//
//#define SUY 6
//int main()
//{
//	char arry[SUY] = { 'F','E','D','C','B','A' };
//	int a,b;
//	for (a = 0; a < SUY; a++)
//	{
//		for (b = 0; b <= a; b++)
//		{
//			printf("%c ", arry[b]);
//		}
//		printf("\n");
//	}
//		
//	return 0;
//}

//(4)
//
//#define SUY 6
//int main()
//{
//	char c = 'A';
//	int a,b;
//
//		for (a = 0; a < SUY; a++)
//		{
//			for (b = 0; b <= a; b++,c++)
//			{
//				printf("%c ",c );
//			}
//			printf("\n");
//		}
//			
//		return 0;
//}

//(5)
//int main()
//{
//	int i, j, num;
//	char c;
//	printf("Enter the core char you want to print(A...Z):");
//	scanf("%c", &c);
//	char ch = 'A';
//	num = c - 'A' + 1;
//	for (i = 1; i <= num; i++)
//	{
//		for (j = 0; j < num - i; j++)
//		{
//			printf(" ");
//		}
//		for (ch = 'A'; j < num; j++)
//		{
//			printf("%c", ch++);
//		}
//		for (j = 1, ch -= 2; j < i; j++, ch--)
//		{
//			printf("%c", ch);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	char a,k;
//	int b, c, d,j,w;
//
//	printf("Enter the core char you want to print(A...Z):");
//	scanf("%c", &a);
//	b = a - 'A'+1;//金字塔的总行数
//	for (c = 1; c <= b; c++)
//	{
//		for (d = 1; d <= b - c; d++)//d:每一行所需要补充的空格
//		{
//			printf(" ");
//		}
//		for (k = 'A',j=1; j <= b - d+1 ; k++,j++)//j:正序所补充的字母数
//		{
//			printf("%c", k);
//		}
//		for (w = 1,k-=2; w <c; w++, k--)//w:反序所补充的字母数
//		{
//			printf("%c", k);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//(6)
//
//int main()
//{
//	int _start, _final,c;
//
//	printf("Please enter the starting number:");
//		scanf("%d", &_start);
//		printf("Please enter the final number:");
//		scanf("%d", &_final);
//	for (c = _start; c <= _final; c++)
//	{
//		printf("number       number^2         number^3\n");
//		printf("  %d              %d                %d\n", c, c * c, c * c * c);
//	}
//	return 0;
//}


//(7)
//
//#define ASD 50
//int main()
//{
//	char arry[ASD];
//	int a, b, c;
//
//	printf("please input a word:");
//	scanf("%s", &arry);
//	printf("\n");
//	a = strlen(arry);
//	printf("The word is pritend in reverse order:");
//	for (; a >= 0; a--)
//	{
//		printf("%c", arry[a]);
//	}
//	return 0;
//}


//(8)
//
//int main()
//{
//	double a, b, c;
//
//	printf("please input two number:");
//	for (; scanf("%lf %lf", &a, &b) == 2;)
//	{
//		c = (a - b) / (a * b);
//		printf("The results for:%lf", c);
//		printf("\n");
//		printf("please input two number:");
//	}
//	return 0;
//}


//(9)
//
//double ser(double x, double y);
//int main()
//{
//		double a, b,c;
//
//		printf("please input two number:");
//		for (; scanf("%lf %lf", &a, &b) == 2;)
//		{
//			c = ser(a, b);
//			printf("The results for:%lf", c);
//			printf("\n");
//			printf("please input two number:");
//		}
//		return 0;
//}
//
//double ser(double x, double y)
//{
//	double c;
//	c = (x-y) / (x * y);
//	return c;
//}


//(10)
//
//int FRT(int x, int y);
//int main()
//{
//	int a, b;
//	int num = 0;
//
//	printf("Enter iower and upper integer limits:");
//	scanf("%d %d", &a, &b);
//	for (;a<b;)
//	{
//		num = FRT(a, b);
//		printf("The sums of the squares from %d to %d is %d\n", a * a, b * b, num);
//		printf("Enter iower and upper integer limits:");
//		scanf("%d %d", &a, &b);
//	}
//	for (; a >= b;)
//	{
//		printf("Done\n");
//		break;
//	}
//	return 0;
//}
//
//int FRT(int x, int y)
//{
//	int sum=0,c;
//
//	for (c = x; c <=y; c++)
//	{
//		sum += c * c;
//	}
//	return sum;
//}


//(11)
//
//#define ZSD 8
//int main()
//{
//	int arry[ZSD],i;
//
//	printf("please input the number:");
//	for (i = 0; i < ZSD; i++)
//	{
//		scanf("%d", &arry[i]);
//	}
//	printf("Now output in reverse order:");
//	for (i-=1; i >= 0; i--)
//	{
//		printf("%d ", arry[i]);
//	}
//	printf("\n");
//	return 0;
//}


//(12)
//
//int main()
//{
//	double b, c;
//	double sum1 = 0.0, sum2 = 0.0;
//	int a, k;
//
//	printf("please input a number:");
//	scanf("%d", &a);
//	b = c = 1.0;
//	while(a > 0)
//{
//
//	for (k = 1; k <= a; c++, k++)
//	{
//		sum1 += b / c;
//
//	}
//	c = 1.0;
//	for (k = 1; k <= a; c++, k++)
//	{
//		if (k % 2 == 1)
//		{
//			sum2 += b / c;
//		}
//		if (k % 2 == 0)
//		{
//			sum2 -= b / c;
//		}
//	}
//	printf("%lf %lf\n", sum1, sum2);
//	printf("please input a number:");
//	scanf("%d", &a);
//}
//	 if (a <= 0)
//	{
//		printf("done\n");
//	}
//	return 0;
//}


//(13)
//
//#define AWE 8
//int main()
//{
//	int arry[AWE];
//	int a, b, c, d;
//
//	for (a = 0,b=2; a < AWE;a++)
//	{
//		arry[a] = b;
//		b = b * 2;
//	}
//	a = 0;
//	printf("The arry output element is:");
//	do
//	{
//		printf("%d ", arry[a]);
//			a++;
//	}while(a < AWE);
//	printf("\n");
//	return 0;
//}


//(14)
//
//#define ZXC 8
//int main()
//{
//	double arry1[ZXC] = { 0 }, arry2[ZXC] = { 0 },ass;
//	int a, b, c,d;
//
//	for (a = 0; a < ZXC; a++)
//	{
//		printf("please enter %d value:",a+1);
//		scanf("%lf", &arry1[a]);
//	}
//	printf("\n");
//	for (b = 0; b < ZXC; b++)
//	{
//		for (c = 0,ass=0; c <= b; c++)
//		{
//			ass += arry1[c];
//		}
//		arry2[b] = ass;
//	}
//	printf("The first array element is:");
//	for (d = 0; d < ZXC; d++)
//	{
//		printf("%lf ", arry1[d]);
//	}
//	printf("\n");
//	printf("The second array element is:");
//	for (d = 0; d < ZXC; d++)
//	{
//		printf("%lf ", arry2[d]);
//	}
//	printf("\n");
//	return 0;
//}


//(15)
//
//#define SED 255
//int main()
//{
//	char arry[SED];
//	int a=0, b, c;
//
//	printf("Please type what you want to type:");
//		do
//		{
//			scanf("%c", &arry[a]);
//			a++;
//		}while (a != '\n');
//				for(a -= 1; a >= 0; a--)
//				{
//					printf("%c", arry[a]);
//				}
//				printf("\n");
//	return 0;
//}


//(16)
//
//int main()
//{
//	int a=100,year=1;
//	double sum1 =100, sum2 = 100;
//
//	while (1)
//	{
//			sum1 += a * 0.1;
//			sum2 += sum2 * 0.05;
//			year++;
//		if (sum2 > sum1)
//		{
//			printf("After the %d years,Deirdre investment exceeds Daphne\n", year);
//			printf("Mr.Daphne investment is:%lf\n", sum1);
//			printf("Mr.Deirdre investment is:%lf\n", sum2);
//			break;
//		}
//	}
//	return 0;
//}


//(17)
//
//int main()
//{
//	double principal = 100;
//	int years = 1;
//	
//	while (1)
//	{
//		principal += principal * 0.08-10;
//		years++;
//		if (principal < 0)
//		{
//			printf("You withdraw your money after the %d year.\n", years);
//			break;
//		}
//	}
//	return 0;
//}


//(18)
//
//#define ASD 150
//int main()
//{
//	int friends=5;
//	int week=1;
//
//	while (1)
//	{
//		friends = (friends - week) * 2;
//		printf("The number of friends Dr.Rabnud has %d week is %d.\n ", week, friends);
//		week++;
//		if (friends > ASD)
//		{
//			break;
//		}
//	}
//
//	return 0;
//}