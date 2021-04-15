#define _CRT_SECURE_NO_WARNINGS 1

//程序清单9.12 -- loccheck.c -- 查看变量被存储在何处
//
//#include <stdio.h>
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