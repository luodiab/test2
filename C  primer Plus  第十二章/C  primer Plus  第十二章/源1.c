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


/* 程序清单12.11 -- diceroll.c -- dice role simulation */
/* compile with mandydice.c           */
//#include "diceroll.h"
//#include <stdio.h>
//#include <stdlib.h>           /* for library rand()   */
//
//int roll_count = 0;          /* external linkage     */
//
//static int rollem(int sides)  /* private to this file */
//{
//    int roll;
//
//    roll = rand() % sides + 1;
//    ++roll_count;             /* count function calls */
//
//    return roll;
//}
//
//int roll_n_dice(int dice, int sides)
//{
//    int d;
//    int total = 0;
//    if (sides < 2)
//    {
//        printf("Need at least 2 sides.\n");
//        return -2;
//    }
//    if (dice < 1)
//    {
//        printf("Need at least 1 die.\n");
//        return -1;
//    }
//
//    for (d = 0; d < dice; d++)
//        total += rollem(sides);
//
//    return total;
//}


/* Programming Exercise 12-3 */
// compile with pe12-3b.c
//#include <stdio.h>
//#include "pe12-3a.h"
//
//void check_mode(int* pm)
//{
//	if (*pm != METRIC && *pm != US)
//	{
//		printf("Invalid mode specified. Mode %d\n", *pm);
//		printf("Previous mode will be used.\n");
//		*pm = USE_RECENT;
//	}
//}
//
//void get_info(int mode, double* pd, double* pf)
//{
//	if (mode == METRIC)
//		printf("Enter distance traveled in kilometers: ");
//	else
//		printf("Enter distance traveled in miles: ");
//	scanf("%lf", pd);
//	if (mode == METRIC)
//		printf("Enter fuel consumed in liters: ");
//	else
//		printf("Enter fuel consumed in gallons: ");
//	scanf("%lf", pf);
//}
//
//void show_info(int mode, double distance, double fuel)
//{
//	printf("Fuel consumption is ");
//	if (mode == METRIC)
//		printf("%.2f liters per 100 km.\n", 100 * fuel / distance);
//	else
//		printf("%.1f miles per gallon.\n", distance / fuel);
//}


