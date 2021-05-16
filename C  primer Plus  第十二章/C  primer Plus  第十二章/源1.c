#define _CRT_SECURE_NO_WARNINGS 1

/* 程序清单12.6 -- partb.c -- rest of the program */ 
// compile with parta.c
//#include <stdio.h>
//
//extern int count;       // reference declaration, external linkage
//static int total = 0;   // static definition, internal linkage
//
//void accumulate(int k); // prototype
//
//void accumulate(int k)  // k has block scope, no linkage
//{
//    static int subtotal = 0;  // static, no linkage
//
//    if (k <= 0)
//    {
//        printf("loop cycle: %d\n", count);
//        printf("subtotal: %d; total: %d\n", subtotal, total);
//        subtotal = 0;
//    }
//    else
//    {
//        subtotal += k;
//        total += k;
//    }
//}


/* 程序清单12.7 -- rand0.c -- produces random numbers */
/* uses ANSI C portable algorithm  */
//static unsigned long int next = 1;  /* the seed  */
//
//unsigned int rand0(void)
//{
//    /* magic formula to generate pseudorandom number */
//    next = next * 1103515245 + 12345;
//    return (unsigned int)(next / 65536) % 32768;
//}


/* 程序清单12.9 -- s_and_r.c -- file for rand1() and srand1() */
/* uses ANSI C portable algorithm */
//static unsigned long int next = 1;  /* the seed  */
//
//int rand1(void)
//{
//    /* magic formula to generate pseudorandom number */
//    next = next * 1103515245 + 12345;
//    return (unsigned int)(next / 65536) % 32768;
//}
//
//void srand1(unsigned int seed)
//{
//    next = seed;
//}