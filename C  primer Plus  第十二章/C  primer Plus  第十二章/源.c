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
/* compile with s_and_r.c                  */
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