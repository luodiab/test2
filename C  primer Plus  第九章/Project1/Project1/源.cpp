#define _CRT_SECURE_NO_WARNINGS 1

//程序清单9.1 -- lethead1.c 
//
//#include <stdio.h>
//#define NAME "GIGATHINK, INC."
//#define ADDRESS "101 Megabuck Plaza"
//#define PLACE "Megapolis, CA 94904"
//#define WIDTH 40
//
//void starbar(void);  /* prototype the function */
//
//int main(void)
//{
//    starbar();
//    printf("%s\n", NAME);
//    printf("%s\n", ADDRESS);
//    printf("%s\n", PLACE);
//    starbar();       /* use the function       */
//
//    return 0;
//}
//
//void starbar(void)   /* define the function    */
//{
//    int count;
//
//    for (count = 1; count <= WIDTH; count++)
//        putchar('*');
//    putchar('\n');
//}


//程序清单9.2 -- lethead2.c 
//
//#include <stdio.h>
//#include <string.h>            /* for strlen() */
//#define NAME "GIGATHINK, INC."
//#define ADDRESS "101 Megabuck Plaza"
//#define PLACE "Megapolis, CA 94904"
//#define WIDTH 40
//#define SPACE ' '
//
//void show_n_char(char ch, int num);
//
//int main(void)
//{
//    int spaces;
//
//    show_n_char('*', WIDTH);   /* using constants as arguments */
//    putchar('\n');
//    show_n_char(SPACE, 12);    /* using constants as arguments */
//    printf("%s\n", NAME);
//    spaces = (WIDTH - strlen(ADDRESS)) / 2;
//    /* Let the program calculate    */
//    /* how many spaces to skip      */
//    show_n_char(SPACE, spaces);/* use a variable as argument   */
//    printf("%s\n", ADDRESS);
//    show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
//    /* an expression as argument    */
//    printf("%s\n", PLACE);
//    show_n_char('*', WIDTH);
//    putchar('\n');
//
//    return 0;
//}
//
///* show_n_char() definition */
//void show_n_char(char ch, int num)
//{
//    int count;
//
//    for (count = 1; count <= num; count++)
//        putchar(ch);
//}


//程序清单9.3 --  lesser.c -- finds the lesser of two evils 
//
//#include <stdio.h>
//
//int imin(int, int);
//
//int main(void)
//{
//    int evil1, evil2;
//
//    printf("Enter a pair of integers (q to quit):\n");
//    while (scanf("%d %d", &evil1, &evil2) == 2)
//    {
//        printf("The lesser of %d and %d is %d.\n",
//            evil1, evil2, imin(evil1, evil2));
//        printf("Enter a pair of integers (q to quit):\n");
//    }
//    printf("Bye.\n");
//
//    return 0;
//}
//
//int imin(int n, int m)
//{
//    int min;
//
//    if (n < m)
//        min = n;
//    else
//        min = m;
//
//    return min;
//}


//程序清单9.4 -- misuse.c -- uses a function incorrectly -- 注意，该程序无法被执行。
//
//#include <stdio.h>
//
//int imax();      /* old-style declaration */
//
//int main(void)
//{
//    printf("The maximum of %d and %d is %d.\n",
//        3, 5, imax(3));
//    printf("The maximum of %d and %d is %d.\n",
//        3, 5, imax(3.0, 5.0));
//    return 0;
//}
//
//int imax(n, m)
//int n, m;
//{
//    return (n > m ? n : m);
//}


//程序清单9.5 -- proto.c -- uses a function prototype  -- 注意，该程序也无法被执行。
//
//#include <stdio.h>
//int imax(int, int);        /* prototype */
//int main(void)
//{
//    printf("The maximum of %d and %d is %d.\n",
//        3, 5, imax(3));
//    printf("The maximum of %d and %d is %d.\n",
//        3, 5, imax(3.0, 5.0));
//    return 0;
//}
//
//int imax(int n, int m)
//{
//    return (n > m ? n : m);
//}


//程序清单9.6 -- recur.c -- recursion illustration 
//
//#include <stdio.h>
//
//void up_and_down(int);
//
//int main(void)
//{
//    up_and_down(1);
//    return 0;
//}
//
//void up_and_down(int n)
//{
//    printf("Level %d: n location %p\n", n, &n); // 1
//    if (n < 4)
//        up_and_down(n + 1);
//    printf("LEVEL %d: n location %p\n", n, &n); // 2
//
//}


//程序清单9.7 -- factor.c -- uses loops and recursion to calculate factorials
//
//#include <stdio.h>
//
//long fact(int n);
//long rfact(int n);
//
//int main(void)
//{
//    int num;
//
//    printf("This program calculates factorials.\n");
//    printf("Enter a value in the range 0-12 (q to quit):\n");
//    while (scanf("%d", &num) == 1)
//    {
//        if (num < 0)
//            printf("No negative numbers, please.\n");
//        else if (num > 12)
//            printf("Keep input under 13.\n");
//        else
//        {
//            printf("loop: %d factorial = %ld\n",
//                num, fact(num));
//            printf("recursion: %d factorial = %ld\n",
//                num, rfact(num));
//        }
//        printf("Enter a value in the range 0-12 (q to quit):\n");
//    }
//    printf("Bye.\n");
//
//    return 0;
//}
//
//long fact(int n)     // loop-based function
//{
//    long ans;
//
//    for (ans = 1; n > 1; n--)
//        ans *= n;
//
//    return ans;
//}
//
//long rfact(int n)    // recursive version
//{
//    long ans;
//
//    if (n > 0)
//        ans = n * rfact(n - 1);
//    else
//        ans = 1;
//
//    return ans;
//}


//程序清单9.8 -- binary.c -- prints integer in binary form 
//
//#include <stdio.h>
//
//void to_binary(unsigned long n);
//
//int main(void)
//{
//    unsigned long number;
//    printf("Enter an integer (q to quit):\n");
//    while (scanf("%lu", &number) == 1)
//    {
//        printf("Binary equivalent: ");
//        to_binary(number);
//        putchar('\n');
//        printf("Enter an integer (q to quit):\n");
//    }
//    printf("Done.\n");
//
//    return 0;
//}
//
//void to_binary(unsigned long n)   /* recursive function */
//{
//    int r;
//
//    r = n % 2;
//    if (n >= 2)
//        to_binary(n / 2);
//    putchar(r == 0 ? '0' : '1');
//
//    return;
//}


//程序清单9.12 -- loccheck.c -- 查看变量被存储在何处
//
//#include <stdio.h>
//
//void mikado(int);                      /* declare function  */
//
//int main(void)
//{
//    int pooh = 2, bah = 5;             /* local to main()   */
//
//    printf("In main(), pooh = %d and &pooh = %p\n",
//        pooh, &pooh);
//    printf("In main(), bah = %d and &bah = %p\n",
//        bah, &bah);
//    mikado(pooh);
//
//    return 0;
//}
//
//void mikado(int bah)                   /* define function   */
//{
//    int pooh = 10;                     /* local to mikado() */
//
//    printf("In mikado(), pooh = %d and &pooh = %p\n",
//        pooh, &pooh);
//    printf("In mikado(), bah = %d and &bah = %p\n",
//        bah, &bah);
//}


//程序清单9.13 -- swap1.c -- first attempt at a swapping function 
//
//#include <stdio.h>
//
//void interchange(int u, int v); /* declare function */
//
//int main(void)
//{
//    int x = 5, y = 10;
//
//    printf("Originally x = %d and y = %d.\n", x, y);
//    interchange(x, y);
//    printf("Now x = %d and y = %d.\n", x, y);
//
//    return 0;
//}
//
//void interchange(int u, int v)  /* define function  */
//{
//    int temp;
//
//    temp = u;
//    u = v;
//    v = temp;
//}


//程序清单9.14 -- swap2.c -- researching swap1.c 
//
//#include <stdio.h>
//
//void interchange(int u, int v);
//
//int main(void)
//{
//    int x = 5, y = 10;
//
//    printf("Originally x = %d and y = %d.\n", x, y);
//    interchange(x, y);
//    printf("Now x = %d and y = %d.\n", x, y);
//
//    return 0;
//}
//
//void interchange(int u, int v)
//{
//    int temp;
//
//    printf("Originally u = %d and v = %d.\n", u, v);
//    temp = u;
//    u = v;
//    v = temp;
//    printf("Now u = %d and v = %d.\n", u, v);
//}


//程序清单9.15 -- swap3.c -- 使用指针解决交换函数的问题
//
//#include <stdio.h>
//
//void interchange(int * u, int * v);
//
//int main(void)
//{
//    int x = 5, y = 10;
//
//    printf("Originally x = %d and y = %d.\n", x, y);
//    interchange(&x, &y);
//    printf("Now x = %d and y = %d.\n", x, y);
//
//    return 0;
//}
//
//void interchange(int * u, int * v)
//{
//    int temp;
//
//    temp = *u;
//    *u = *v;
//    *v = temp;
//}


//编程练习 -- Chapter 9 Programming	Exercises

/* Programming Exercise 9-1 */
//
//#include <stdio.h>
//
//double min(double, double);
//
//int main(void)
//{
//	double x, y;
//
//	printf("Enter two numbers (q to quit): ");
//	while (scanf("%lf %lf", &x, &y) == 2)
//	{
//		printf("The smaller number is %f.\n", min(x, y));
//		printf("Next two values (q to quit): ");
//	}
//	printf("Bye!\n");
//
//	return 0;
//}
//double min(double a, double b)
//{
//	return a < b ? a : b;
//}


/* Programming Exercise 9-2 */
//
//#include <stdio.h>
//
//void chline(char ch,int x, int y);
//
//int main(void)
//{
//	int i, j;
//    char ch;
//
//	printf("Enter two numbers and character you want('q q q'to quit): ");
//	while (scanf("%c %d %d", &ch, &i, &j) ==3 )
//	{
//	    chline( ch, i, j);
//		printf("Next two numbers and character you want('q q q'to quit): ");
//		scanf("%*c");    //用来忽略'\n'
//	}
//	printf("Bye!\n");
//
//	return 0;
//}
//
//void chline(char ch, int x, int y)
//{
//	int z = 0, k = 0;
//	for (z = 0; z < x; z++)
//	{
//		for (k = 0; k < y; k++)
//		{
//			printf("%c", ch);
//		}
//		printf("\n");
//	}
//}


/* Programming Exercise 9-3 */
//
//(1)
//#include <stdio.h>
//
//void chline(char ch,int x, int y);
//
//int main(void)
//{
//	int i, j;
//    char ch;
//
//	printf("Enter two numbers and character you want('q q q'to quit): ");
//	while (scanf("%c %d %d", &ch, &i, &j) ==3 )
//	{
//	    chline( ch, i, j);
//		printf("Next two numbers and character you want('q q q'to quit): ");
//		scanf("%*c");    //用来忽略'\n'
//	}
//	printf("Bye!\n");
//
//	return 0;
//}
//
//void chline(char ch, int x, int y)
//{
//	int z = 0, k = 0;
//	for (z = 0; z < y; z++)
//	{
//		for (k = 0; k < x; k++)
//		{
//			printf("%c", ch);
//		}
//		printf("\n");
//	}
//}


//(2) --本人对答案做了一些修改，当使用者输入不为俩个数字时，程序会进行提醒使用者重新输入。
//#include <stdio.h>
//
//void chLineRow(char ch, int c, int r);
//
//int main(void)
//{
//	char ch;
//	int col, row,s=0;
//
//	printf("Enter a character (# to quit): ");
//	while ((ch = getchar()) != '#')
//	{
//		if (ch == '\n')
//			continue;              //这里与scanf("%*c")作用相似。
//		printf("Enter number of columns and number of rows: ");
//		//从这里开始修改
//		if (scanf("%d %d", &col, &row) != 2)
//		{
//			s = 1;
//		}
//		while(s==1)
//		{
//			scanf("%*c");
//			printf("Please enter two numbers:");
//			if (scanf("%d %d", &col, &row) != 2)
//			{
//				continue;
//			}
//			s = 0;
//		}
//		//到这里结束
//		chLineRow(ch, col, row);
//		printf("\nEnter next character (# to quit): ");
//	}
//	printf("Bye!\n");
//
//	return 0;
//}
//
//// start rows and cols at 0
//void chLineRow(char ch, int c, int r)
//{
//	int col, row;
//	for (row = 0; row < r; row++)
//	{
//		for (col = 0; col < c; col++)
//			putchar(ch);
//		putchar('\n');
//	}
//	return;
//}


/* Programming Exercise 9-4 */
//
//#include <stdio.h>
//
//double H_mean(double x, double y);
//
//int main(void)
//{
//	double x, y,k;
//
//	printf("Please enter two numbers:");
//	scanf("%lf %lf", &x, &y);
//	k = H_mean(x, y);
//	printf("x&y=%lf", k);     //x&y表示调和平均数
//
//	return 0;
//}
//
//double H_mean(double x, double y)
//{
//	double a, b;
//
//	if (x == 0 || y == 0)
//	{
//		return 0;
//	}
//	a = (1 / x + 1 / y) / 2;
//	b = 1 / a;
//
//	return b;
//}


/* Programming Exercise 9-5 */
//
//#include <stdio.h>
//
//void larger_of(double* p1, double* p2);
//
//int main(void)
//{
//	double x, y;
//
//	printf("Enter two numbers (q to quit): ");
//	while (scanf("%lf %lf", &x, &y) == 2)
//	{
//		larger_of(&x, &y);
//		printf("The modified values are %f and %f.\n", x, y);
//		printf("Next two values (q to quit): ");
//	}
//	printf("Bye!\n");
//
//	return 0;
//}
//
//void larger_of(double* p1, double* p2)
//{
//	if (*p1 > *p2)
//		*p2 = *p1;
//	else
//		*p1 = *p2;
//}


/* Programming Exercise 9-6 */
//#include <stdio.h>
//
//void Row_size(double * p1, double * p2,double * p3);
//
//int main(void)
//{
//	double x, y,z;
//
//	printf("Enter two numbers (q to quit): ");
//	while (scanf("%lf %lf %lf", &x, &y, &z) == 3)
//	{
//		Row_size(&x, &y, &z);
//		printf("The row_size values are %lf %lf %lf.\n", x, y, z);
//		printf("Next three values (q to quit): ");
//	}
//	printf("Bye!\n");
//
//	return 0;
//}
//
//void Row_size(double * p1, double * p2, double * p3)
//{
//	double arry[3] = { 0 };
//	int i, j;
//	double temp = 0;
//
//	arry[0] = *p1;
//	arry[1] = *p2;
//	arry[2] = *p3;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = i + 1; j < 3; j++)
//		{
//			if (arry[i] > arry[j])
//			{
//				temp = arry[i];
//				arry[i] = arry[j];
//				arry[j] = temp;
//			}
//		}
//	}
//	*p1 = arry[0];
//	*p2 = arry[1];
//	*p3 = arry[2];
//}


/* Programming Exercise 9-7 */
//#include <stdio.h>
//
//void get_char_pos(void);
//
//int position(char ch);
//
//int main(void) 
//{
//    get_char_pos();
//
//    return 0;
//}
//
//void get_char_pos(void)
//{
//    char ch;
//
//    printf("Enter the chars(ended by EOF ,not enter):");
//    while((ch = getchar()) != EOF)
//    {
//     
//        if (ch == '\n')
//        {
//            continue;
//        }
//       if(position(ch) != -1)
//        {
//            printf("The char %c position in alphabet is %d.\n",ch,position(ch));
//        }
//       else
//        {
//            printf("%c is not a alphabet.\n", ch);
//        }
//    }
//}
//
//int position(char ch)
//{
//    if(ch >='A' && ch <='Z')
//
//        return (ch -'A' + 1);
//
//    else if(ch >='a' && ch <='z')
//
//        return (ch -'a' + 1);
//    else 
//
//        return -1;
//}


/* Programming Exercise 9-8 */
//
//#include <stdio.h>
//
//double power(double a, int b); /* ANSI prototype */
//
//int main(void)
//{
//	double x, xpow;
//	int n;
//	printf("Enter a number and the integer power to which\n");
//	printf("the number will be raised. Enter q to quit.\n");
//	while (scanf("%lf %d", &x, &n) == 2)
//	{
//		xpow = power(x, n); /* function call */
//		printf("%.3g to the power %d is %.5g\n", x, n, xpow);
//		printf("Enter next pair of numbers or q to quit.\n");
//	}
//	printf("Hope you enjoyed this power trip -- bye!\n");
//	return 0;
//}
//double power(double a, int b) /* function definition */
//{
//	double pow = 1;
//	int i;
//
//	if (b == 0)
//	{
//		if (a == 0)
//			printf("0 to the 0 undefined; using 1 as the value\n");
//		pow = 1.0;
//	}
//	else if (a == 0)
//		pow = 0.0;
//	else if (b > 0)
//	{
//		for (i = 1; i <= b; i++)
//			pow *= a;
//	}
//	else if (b < 0)
//	{
//		pow = 1.0 / power(a, -b);
//	}
//	return pow; /* return the value of pow */
//}


/* Programming Exercise 9-9 */
//
//#include <stdio.h>
//
//double power(double n, int p);
//
//int main(void) 
//{
//    double x, xpow;
//    int exp;
//
//    printf("Enter a number and the integer power to which \n");
//    printf("the number will be raised. Enter q to quit.\n");
//    while(scanf("%lf %d",&x,&exp) == 2)
//    {
//        xpow = power(x,exp);
//        printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
//        printf("Enter the next pair of numbers or q to quit.\n");
//    }
//    printf("Hope you enjoy this power trip -- bye!\b");
//
//    return 0;
//}
//
//double power(double n, int p)
//{
//    double pow = 1;
//    int i;
//    if(n == 0 && p ==0)
//    {
//        printf("The %g to the power %c is not define, return 1!\n",n , p);
//        return 1;
//    }
//    if (n == 0)
//    {
//        return 0;
//    }
//    if (p == 0)
//    {
//        return 1;
//    }
//    if (p > 0) 
//    {
//        return n * power(n, p - 1);
//    }
//    else
//    {
//        return power(n,p+1)/n;
//    }
//}


/* Programming Exercise 9-10 */
//
//(1) -- 第一种方法可以测试任何进制
//#include <stdio.h>
//
//void to_base_n(unsigned long n, unsigned int y);
//
//int main(void)
//{
//    unsigned long number;
//    unsigned int y;
//
//    printf("Enter an integer ('q q' to quit):\n");
//    while (scanf("%lu %d", &number,&y) == 2)
//    {
//        printf("Binary equivalent: ");
//        to_base_n(number,y);
//        putchar('\n');
//        printf("Enter an integer (q to quit):\n");
//    }
//    printf("Done.\n");
//
//    return 0;
//}
//
//void to_base_n(unsigned long n, unsigned int y)   /* recursive function */
//{
//    int r;
//
//    r = n % y;
//    if (n >= y)
//        to_base_n(n / y,y);
//    putchar('0'+r);
//
//    return;
//}


//(2)
//#include <stdio.h>
//
//void to_base_n(int x, int base);
//
//int main(void)
//{
//	int number;
//	int b;
//	int count;
//
//	printf("Enter an integer (q to quit):\n");
//	while (scanf("%d", &number) == 1)
//	{
//		printf("Enter number base (2-10): ");
//		while ((count = scanf("%d", &b)) == 1 && (b < 2 || b > 10))
//		{
//			printf("base should be in the range 2-10: ");
//		}
//	/*	if (count != 1)
//			break;*/
//		printf("Base %d equivalent: ", b);
//		to_base_n(number, b);
//		putchar('\n');
//		printf("Enter an integer (q to quit):\n");
//	}
//	printf("Done.\n");
//	return 0;
//}
//void to_base_n(int x, int base) /* recursive function */
//{
//	int r;
//	r = x % base;
//	if (x >= base)
//		to_base_n(x / base, base);
//	putchar('0' + r);
//	return;
//}


/* Programming Exercise 9-11 */
//
//#include <stdio.h>
//
//void Fibonacci(int n);
//
//int main(void) 
//{
//    int n;
//
//    printf("Enter the number of Fibonacci (q to quit):");
//    while(scanf("%d",&n) == 1)
//    {
//        if(n >= 2)
//        {
//            Fibonacci(n);
//            printf("Enter the number of Fibonacci (q to quit):");
//        }
//    }
//    return 0;
//}
//
//void Fibonacci(int n)
//{
//    unsigned long f1,f2,temp;
//    f1 = 1;
//    f2 = 1;
//    for(int i = 0 ;i < n; i++)
//    {
//        printf("%lu ",f1);
//        temp = f1+f2;
//        f1 = f2;
//        f2 = temp;
//    }
//    printf("\n");
//}