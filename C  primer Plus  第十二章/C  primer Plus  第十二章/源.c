#define _CRT_SECURE_NO_WARNINGS 1

/* 程序清单12.1 -- hiding.c -- variables in blocks */
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
//    while (x++ < 33) // original x       /*注意：当判断完33 !< 33时，x仍然会++，即此时x=34*/
//    {
//        int x = 100; // new x, hides first x 
//        x++;
//        printf("x in while loop: %d at %p\n", x, &x);
//    }
//    printf("x in outer block: %d at %p\n", x, &x);
//
//    return 0;
//}


/* 程序清单12.2 -- forc99.c -- new C99 block rules */
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


/* 程序清单12.3 -- loc_stat.c -- using a local static variable */
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


/* 程序清单12.4 -- global.c  -- uses an external variable */
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


/* 程序清单12.5 -- parta.c --- various storage classes -- 编译时要与(12.6)一起编译 */
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


/* 程序清单12.8 -- r_drive0.c -- test the rand0() function */
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


/* 程序清单12.10 -- r_drive1.c -- test rand1() and srand1() */
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


/* 程序清单12.13 -- manydice.c -- multiple dice rolls   */ 
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


/* 程序清单12.14 -- dyn_arr.c -- dynamically allocated array   */
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


/* 程序清单12.15 -- where.c -- where's the memory? */
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
//(1) -- 通过传变量地址来改变。
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


//(2) -- 通过函数的返回值来改变变量的值。
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
/* C语言中使用auto 关键字声明自动变量，使用static关键字声明静态变量。
   在函数中定义局部变量时，如果没有被声明为其他类型的变量都是自动变量。*/
// pe12-3b.c
// compile with pe12-3a.c
//#include <stdio.h>
//#include "pe12-3a.h"
//
//int main(void)
//{
//	int mode;
//	int prev_mode = METRIC;   //METRIC初值为0
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
//(1)
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


//(2)
//#include <stdio.h>
//#include <stdlib.h>
//void print(const int array[], int limit);
//void sort(int array[], int limit);
//#define SIZE 100
//int main(void)
//{
//	int i;
//	int arr[SIZE];
//
//	for (i = 0; i < SIZE; i++)
//		arr[i] = rand() % 10 + 1;
//	puts("initial array");
//	print(arr, SIZE);
//	sort(arr, SIZE);
//	puts("\nsorted array");
//	print(arr, SIZE);
//
//	return 0;
//}
///* sort.c -- sorts an integer array in decreasing order */
//void sort(int array[], int limit)
//{
//	int top, search, temp;
//	for (top = 0; top < limit - 1; top++)
//		for (search = top + 1; search < limit; search++)
//			if (array[search] > array[top])
//			{
//				temp = array[search];
//				array[search] = array[top];
//				array[top] = temp;
//			}
//}
///* print.c -- prints an array */
//void print(const int array[], int limit)
//{
//	int index;
//	for (index = 0; index < limit; index++)
//	{
//		printf("%2d ", array[index]);
//		if (index % 10 == 9)
//			putchar('\n');
//	}
//	if (index % 10 != 0) // if last line not complete
//		putchar('\n');
//}


/* Programming Exercise 12-6 */
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define SIZE 10
//#define LENGTH 1000
//
//int main(int argc, char* argv[]) 
//{
//    int data_count[SIZE + 1];
//    int datum;
//    for (int seed = 1; seed <= 10; seed++) 
//    {
//        printf("This is %d round to create data.\n", seed);
//        srand(seed);
//
//        for (int i = 0; i <= SIZE; i++)
//        {
//            data_count[i] = 0;
//        }
//        for (int i = 0; i < LENGTH; i++) 
//        {
//            datum = rand() % 10 + 1;
//            data_count[datum]++;
//    
//        }
//        printf("Random data created,let's stata it.\n");
//        for (int i = 1; i <= SIZE; i++) 
//        {
//            printf("The datum %d created %d times.\n", i, data_count[i]);
//        
//        }
//    }
//    return 0;
//}


/* Programming Exercise 12-7 */
/* manydice.c -- multiple dice rolls                    */
/* compile with diceroll.c                              */
//#include <stdio.h>
//#include <stdlib.h>              /* for library srand() */
//#include <time.h>                /* for time()          */
//#include "diceroll.h"            /* for roll_n_dice()   */
///* and for roll_count  */
//#define ASD 100
//
//int main(void)
//{
//    int roll[ASD] = { 0 };
//    int dice;
//    int sides;
//    int status;
//    int set;
//    int k = 0;
//    int j;
//
//    srand((unsigned int)time(0)); /* randomize seed      */
//    printf("Enter the number of set; enter q to stop:");
//    while (scanf("%d", &set) == 1 && set > 0)
//    {
//        printf("How many sides and how many dice? ");
//        if ((status = scanf("%d %d", &sides,&dice)) != 2)
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
//        printf("Here are %d sets of %d %d-sided throws.\n", set, dice, sides);
//        for (k = 0; k < set; k++)
//        {
//            roll[k] = roll_n_dice(dice, sides);
//        }
//        for (k = 0; k < set; k++)
//        {
//            printf("%2d ", roll[k]);
//            j = k + 1;
//            if (j % 15 == 0)
//            {
//                printf("\n");
//            }
//        }
//        printf("\nHow many set; enter q to stop:");
//    }
//    printf("The rollem() function was called %d times.\n",
//        roll_count);           /* use extern variable */
//    printf("GOOD FORTUNE TO YOU!\n");
//
//    return 0;
//}


/* Programming Exercise 12-8 */
//#include <stdio.h>
//#include <stdlib.h>
//
//int* make_array(int elem, int val);
//void show_array(const int ar[], int n);
//
//int main(int argc, char *argv[])
//{
//   int * pa;
//   int size;
//   int value;
//   printf("Enter the number of elements: ");
//   while (scanf("%d", &size) == 1 && size > 0)
//   {
//      printf("Enter the initialization value: ");
//      scanf("%d", &value);
//      pa = make_array(size, value);
//      if (pa)
//      {
//         show_array(pa, size);
//         free(pa);
//      }
//      printf("Enter the number of elements (<1 to quit): ");
//   }
//   printf("Done.\n");
//   return 0;
//}
//
//int* make_array(int elem, int val)
//{
//    int* arry = (int*)malloc(elem * sizeof(int));
//    int k = 0;
//if (arry == NULL) return NULL;
//    for (k = 0; k < elem; ++k)
//    {
//        arry[k] = val;
//    }
//    return arry;
//}
//
//void show_array(const int ar[], int n)
//{
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        printf("%2d ", ar[i]);
//        if ((i+1) % 8 == 0)
//        {
//            printf("\n");
//        }
//    }
//    printf("\n");
//}


/* Programming Exercise 12-9 */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, char* argv[]) 
//{
//    int amount;
//    printf("How many words do you wish to enter: ");
//    scanf("%d", &amount);
//    printf("Enter %d words now:\n ", amount);
//    char** pst = (char**)malloc(amount * sizeof(char*));
//
//    for (int i = 0; i < amount; i++) 
//    {
//        char temp[100];
//        scanf("%s", temp);    //scanf扫描到字符后面的空格时，就认为对temp的赋值结束，并忽略了后面的字符。
//                              //scanf()在读取数字时会跳过空格、制表符和换行符！
//                              /*scanf()函数接收输入数据时，遇以下情况结束一个数据的输入：（不是结束该scanf函数，scanf函数仅在每一个数据域均有数据，并按回车后结束）。 
//                               ① 遇空格、“回车”、“跳格”键。
//                               ② 遇宽度结束。
//                               ③ 遇非法输入。*/
//        int length = strlen(temp);
//
//        char* str = (char*)malloc(length * sizeof(char));
//
//        strcpy(str,temp);
//        *( pst + i) = str;
//
//    }
//    for (int i = 0; i < amount; i++) 
//    {
//        printf("%s\n",*(pst+i));
//    }
//    free(pst);
//    printf("All done!\n");
//    return 0;
//}