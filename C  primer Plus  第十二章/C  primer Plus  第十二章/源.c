#define _CRT_SECURE_NO_WARNINGS 1

/* �����嵥12.1 -- hiding.c -- variables in blocks */
//
//#include <stdio.h>
//
//int main()
//{
//    int x = 30;      // original x
//
//    printf("x in outer block: %d at %p\n", x, &x);
//    {
//        int x = 77;  // new x, hides first x
//        printf("x in inner block: %d at %p\n", x, &x);
//    }
//    printf("x in outer block: %d at %p\n", x, &x);
//    while (x++ < 33) // original x       /*ע�⣺���ж���33 !< 33ʱ��x��Ȼ��++������ʱx=34*/
//    {
//        int x = 100; // new x, hides first x 
//        x++;
//        printf("x in while loop: %d at %p\n", x, &x);
//    }
//    printf("x in outer block: %d at %p\n", x, &x);
//
//    return 0;
//}


/* �����嵥12.2 -- forc99.c -- new C99 block rules */
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 8;
//
//    printf("   Initially, n = %d at %p\n", n, &n);
//    for (int n = 1; n < 3; n++)
//        printf("      loop 1: n = %d at %p\n", n, &n);
//    printf("After loop 1, n = %d at %p\n", n, &n);
//    for (int n = 1; n < 3; n++)
//    {
//        printf(" loop 2 index n = %d at %p\n", n, &n);
//        int n = 6;
//        printf("      loop 2: n = %d at %p\n", n, &n);
//        n++;
//    }
//    printf("After loop 2, n = %d at %p\n", n, &n);
//
//    return 0;
//}


/* �����嵥12.3 -- loc_stat.c -- using a local static variable */
//
//#include <stdio.h>
//
//void trystat(void);
//
//int main(void)
//{
//    int count;
//
//    for (count = 1; count <= 3; count++)
//    {
//        printf("Here comes iteration %d:\n", count);
//        trystat();
//    }
//
//    return 0;
//}
//
//void trystat(void)
//{
//    int fade = 1;
//    static int stay = 1;
//
//    printf("fade = %d and stay = %d\n", fade++, stay++);
//}


/* �����嵥12.4 -- global.c  -- uses an external variable */
//
//#include <stdio.h>
//
//int units = 0;         /* an external variable      */
//
//void critic(void);
//
//int main(void)
//{
//    extern int units;  /* an optional redeclaration */
//
//    printf("How many pounds to a firkin of butter?\n");
//    scanf("%d", &units);
//    while (units != 56)
//        critic();
//    printf("You must have looked it up!\n");
//
//    return 0;
//}
//
//void critic(void)
//{
//    /* optional redeclaration omitted */
//    printf("No luck, my friend. Try again.\n");
//    scanf("%d", &units);
//}


/* �����嵥12.5 -- parta.c --- various storage classes -- ����ʱҪ��(12.6)һ����� */
// compile with partb.c
//
//#include <stdio.h>
//
//void report_count();
//
//void accumulate(int k);
//
//int count = 0;       // file scope, external linkage
//
//int main(void)
//{
//    int value;       // automatic variable
//    register int i;  // register variable
//    
//    printf("Enter a positive integer (0 to quit): ");
//    while (scanf("%d", &value) == 1 && value > 0)
//    {
//        ++count;     // use file scope variable
//        for (i = value; i >= 0; i--)
//            accumulate(i);
//        printf("Enter a positive integer (0 to quit): ");
//    }
//    report_count();
//    
//    return 0;
//}
//
//void report_count()
//{
//    printf("Loop executed %d times\n", count);
//}


/* �����嵥12.8 -- r_drive0.c -- test the rand0() function */
/* compile with rand0.c */
//#include <stdio.h>
//extern unsigned int rand0(void);
//
//int main(void)
//{
//    int count;
//
//    for (count = 0; count < 5; count++)
//        printf("%d\n", rand0());
//
//    return 0;
//}


/* �����嵥12.10 -- r_drive1.c -- test rand1() and srand1() */
/* compile with s_and_r.c */
//#include <stdio.h>
//#include <stdlib.h>
//extern void srand1(unsigned int x);
//extern int rand1(void);
//
//int main(void)
//{
//    int count;
//    unsigned seed;
//
//    printf("Please enter your choice for seed.\n");
//    while (scanf("%u", &seed) == 1)
//    {
//        srand1(seed);    /* reset seed */
//        for (count = 0; count < 5; count++)
//            printf("%d\n", rand1());
//        printf("Please enter next seed (q to quit):\n");
//    }
//    printf("Done\n");
//
//    return 0;
//}


/* �����嵥12.13 -- manydice.c -- multiple dice rolls   */ 
/* manydice.c -- multiple dice rolls                    */
/* compile with diceroll.c                              */
//#include <stdio.h>
//#include <stdlib.h>              /* for library srand() */
//#include <time.h>                /* for time()          */
//#include "diceroll.h"            /* for roll_n_dice()   */
///* and for roll_count  */
//int main(void)
//{
//    int dice, roll;
//    int sides;
//    int status;
//
//    srand((unsigned int)time(0)); /* randomize seed      */
//    printf("Enter the number of sides per die, 0 to stop.\n");
//    while (scanf("%d", &sides) == 1 && sides > 0)
//    {
//        printf("How many dice?\n");
//        if ((status = scanf("%d", &dice)) != 1)
//        {
//            if (status == EOF)
//                break;             /* exit loop           */
//            else
//            {
//                printf("You should have entered an integer.");
//                printf(" Let's begin again.\n");
//                while (getchar() != '\n')
//                    continue;     /* dispose of bad input */
//                printf("How many sides? Enter 0 to stop.\n");
//                continue;         /* new loop cycle       */
//            }
//        }
//        roll = roll_n_dice(dice, sides);
//        printf("You have rolled a %d using %d %d-sided dice.\n",
//            roll, dice, sides);
//        printf("How many sides? Enter 0 to stop.\n");
//    }
//    printf("The rollem() function was called %d times.\n",
//        roll_count);           /* use extern variable */
//
//    printf("GOOD FORTUNE TO YOU!\n");
//
//    return 0;
//}


/* �����嵥12.14 -- dyn_arr.c -- dynamically allocated array   */
//
//#include <stdio.h>
//#include <stdlib.h> /* for malloc(), free() */
//
//int main(void)
//{
//    double* ptd;
//    int max;
//    int number;
//    int i = 0;
//
//    puts("What is the maximum number of type double entries?");
//    if (scanf("%d", &max) != 1)
//    {
//        puts("Number not correctly entered -- bye.");
//        exit(EXIT_FAILURE);
//    }
//    ptd = (double*)malloc(max * sizeof(double));
//    if (ptd == NULL)
//    {
//        puts("Memory allocation failed. Goodbye.");
//        exit(EXIT_FAILURE);
//    }
//    /* ptd now points to an array of max elements */
//    puts("Enter the values (q to quit):");
//    while (i < max && scanf("%lf", &ptd[i]) == 1)
//        ++i;
//    printf("Here are your %d entries:\n", number = i);
//    for (i = 0; i < number; i++)
//    {
//        printf("%7.2f ", ptd[i]);
//        if (i % 7 == 6)
//            putchar('\n');
//    }
//    if (i % 7 != 0)
//        putchar('\n');
//    puts("Done.");
//    free(ptd);
//
//    return 0;
//}


/* �����嵥12.14 -- where.c -- where's the memory? */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int static_store = 30;
//
//const char* pcg = "String Literal";
//
//int main()
//{
//    int auto_store = 40;
//    char auto_string[] = "Auto char Array";
//    int* pi;
//    char* pcl;
//
//    pi = (int*)malloc(sizeof(int));
//    *pi = 35;
//    pcl = (char*)malloc(strlen("Dynamic String") + 1);
//    strcpy(pcl, "Dynamic String");
//
//    printf("static_store: %d at %p\n", static_store, &static_store);
//    printf("  auto_store: %d at %p\n", auto_store, &auto_store);
//    printf("         *pi: %d at %p\n", *pi, pi);
//    printf("  %s at %p\n", pcg, pcg);
//    printf(" %s at %p\n", auto_string, auto_string);
//    printf("  %s at %p\n", pcl, pcl);
//    printf("   %s at %p\n", "Quoted String", "Quoted String");
//    free(pi);
//    free(pcl);
//
//    return 0;
//}


//Chapter 12 Programming Exercises

/* pe12-1.c -- deglobalizing global.c */
/* Programming Exercise 12-1 */
/* one of several approaches */
//(1) -- ͨ����������ַ���ı䡣
//#include <stdio.h>
//
//void critic(int* u);
//
//int main(void)
//{
//	int units; /* units now local */
//	printf("How many pounds to a firkin of butter?\n");
//	scanf("%d", &units);
//	while (units != 56)
//		critic(&units);
//	printf("You must have looked it up!\n");
//	return 0;
//}
//
//void critic(int* u)
//{
//	printf("No luck, my friend. Try again.\n");
//	scanf("%d", u);
//}


//(2) -- ͨ�������ķ���ֵ���ı������ֵ��
// or use a return value:
// units = critic(); 
// and have critic look like this:
//#include <stdio.h>
//int critic(void);
//int main(void)
//{
//	int units; /* units now local */
//	printf("How many pounds to a firkin of butter?\n");
//	scanf("%d", &units);
//	while (units != 56)
//		units=critic();
//	printf("You must have looked it up!\n");
//
//	return 0;
//}
//
//int critic(void)
//{
// int u;
// printf("No luck, my friend. Try again.\n");
// scanf("%d", &u);
//
// return u;
//}


/* Programming Exercise 12-2 */
//#include "pe12-2a.h"
//
//int main(int argc, char* argv[])
//{
//    int n;
//    printf("Enter 0 for metric mode, 1 for US mode: ");
//    scanf("%d", &n);
//    while (n >= 0)
//    {
//        set_mode(n);
//        get_info();
//        show_info();
//        printf("Enter 0 for metric mode, 1 for US mode: ");
//        printf(" (-1 to quit ): ");
//        scanf("%d", &n);
//    }
//    printf("Done.\n");
//    return 0;
//}
//
//void set_mode(int n)
//{
//    if (n > 1)
//    {
//        printf("Invalid mode specified.");
//        if (mode == 0)
//        {
//            printf(" Mode 0(Mrtric) used.\n");
//        }
//        else
//        {
//            printf(" Mode 1(US) used.\n");
//        }
//    }
//    else mode = n;
//}
//
//void get_info(void)
//{
//    if (mode == 0)
//        printf("Enter distance traveled in kilometers:");
//    else
//        printf("Enter distance traveled in miles:");
//    scanf("%lf", &range);
//
//    if (mode == 0)
//        printf("Enter fuel consumed in liters:");
//    else
//        printf("Enter fuel consumed in gallons:");
//    scanf("%lf", &fuel);
//}
//
//void show_info(void)
//{
//    if (mode == 0)
//        printf("Fuel consumption is %.2lf liters per 100 km.\n", (fuel / range) * 100);
//    else
//        printf("Fuel consumption is %.1lf miles per gallon.\n", range / fuel);
//}


/* Programming Exercise 12-3 */
/* C������ʹ��auto �ؼ��������Զ�������ʹ��static�ؼ���������̬������
   �ں����ж���ֲ�����ʱ�����û�б�����Ϊ�������͵ı��������Զ�������*/
// pe12-3b.c
// compile with pe12-3a.c
//#include <stdio.h>
//#include "pe12-3a.h"
//
//int main(void)
//{
//	int mode;
//	int prev_mode = METRIC;   //METRIC��ֵΪ0
//	double distance, fuel;
//
//	printf("Enter 0 for metric mode, 1 for US mode: ");
//	scanf("%d", &mode);
//	while (mode >= 0)
//	{
//		check_mode(&mode);
//		if (mode == USE_RECENT)
//			mode = prev_mode;
//		prev_mode = mode;
//		get_info(mode, &distance, &fuel);
//		show_info(mode, distance, fuel);
//		printf("Enter 0 for metric mode, 1 for US mode");
//		printf(" (-1 to quit): ");
//		scanf("%d", &mode);
//	}
//	printf("Done.\n");
//
//	return 0;
//}


/* Programming Exercise 12-4 */
//#include <stdio.h>
//
//static int count = 0;
//
//int run_counter(void);
//
//int main(int argc, char *argv[]) 
//{
//
//    for(int i = 0;i<100;i++)
//        printf("The function run_time run %d times.\n",run_counter());
//    return 0;
//}
//
//int run_counter(void)
//{
//    return ++count;
//}


/* Programming Exercise 12-5 */
//#include <stdio.h>
//#include <stdlib.h>              /* for library srand() */
//#include <time.h>                /* for time()          */
//
//#define ASD 100
//
//int main(void)
//{
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    int temp = 0;
//    int arry[ASD] = { 0 };
//
//    srand((unsigned int)time(0)); /* randomize seed      */
//
//    for (i = 0; i < ASD; i++)
//    {
//        k = 1 + (int)(10.0 * rand() / (RAND_MAX + 1.0));
//        arry[i] = k;
//    }
//    for (i=0;i<ASD-1;i++)
//    {
//        for (j=i+1;j < ASD;j++)
//        {
//            if (arry[i] < arry[j])
//            {
//                temp = arry[i];
//                arry[i] = arry[j];
//                arry[j] = temp;
//            }
//            if (arry[i] == arry[j])
//                continue;
//        }
//    }
//    for (i = 0; i < ASD; i++)
//    {
//        int s = i + 1;
//        printf("%2d ", arry[i]);
//        if (s % 10 == 0)
//            printf("\n");
//    }
//
//    return 0;
//}