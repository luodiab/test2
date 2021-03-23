#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//void arry(int a);
//int main(void)
//{
//	int a=0;
//	scanf("%d", &a);
//	arry(a);
//	return 0;
//}
//void arry(int b)
//{
//	int i = 0;
//	printf("奇数位：\n");
//	for (i = 30; i >= 0; i =i-2)
//	{
//		printf("%d ", (b >> 1) & 1);
//	}
//	printf("\n");
//	printf("偶数位：\n");
//	for (i = 31; i >= 1; i =i- 2)
//	{
//		printf("%d ", (b >> 1) & 1);
//	}
//	printf("\n");
//}


//#include<stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#pragma warning(suppress : 4996)
//void main()
//{
//	FILE* fp;
//	char ch;
//	if ((fp = fopen("string", "wt+")) == NULL)
//	{
//		printf("Cannot open file strike any key exit!bai");
//		getch();
//		exit(1);
//	}
//	printf("input a string:\n");
//	ch = getchar();
//	while (ch != '\n')
//	{
//		fputc(ch, fp);
//		ch = getchar();
//	}
//	rewind(fp);
//	ch = fgetc(fp);
//	while (ch != EOF)
//	{
//		putchar(ch);
//		ch = fgetc(fp);
//	}
//	printf("\n");
//	fclose(fp);
//}


//void arry(int* x);
//int main()
//{
//	int a = 1;
//
//	printf("a=%d\n", a);
//	arry(&a);
//	printf("a=%d\n", a);
//	return 0;
//}
//
//void arry(int* x)
//{
//	*x = 2014;
//	printf("x=%d\n", x);
//}


int main()
{
	int a=1, b=2,e,f;

	scanf("%d", &a);
	if (a > 12)
		goto c;
	goto e;
c: f = 3;
e:f = 6;
	printf("f=%d", f);

	return 0;
}