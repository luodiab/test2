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