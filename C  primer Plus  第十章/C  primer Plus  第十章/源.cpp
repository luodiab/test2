#define _CRT_SECURE_NO_WARNINGS 1

//程序清单10.1 -- day_mon1.c -- prints the days for each month 
//
//#include <stdio.h>
//#define MONTHS 12
//
//int main(void)
//{
//    int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//    int index;
//
//    for (index = 0; index < MONTHS; index++)
//    {
//        printf("Month %-2d has %2d days.\n", index + 1, days[index]);
//    }
//
//    return 0;
//}


//程序清单10.2 -- no_data.c -- uninitialized array 
//
//#include <stdio.h>
//#define SIZE 4
//
//int main(void)
//{
//    int no_data[SIZE];  /* uninitialized array */
//    int i;
//
//    printf("%2s%14s\n", "i", "no_data[i]");
//    for (i = 0; i < SIZE; i++)
//    {
//        printf("%2d%14d\n", i, no_data[i]);
//    }
//       
//    return 0;
//}


//程序清单10.3 -- some_data.c -- partially initialized array 
//
//#include <stdio.h>
//#define SIZE 4
//
//int main(void)
//{
//    int some_data[SIZE] = { 1492, 1066 };
//    int i;
//
//    printf("%2s%14s\n", "i", "some_data[i]");
//    for (i = 0; i < SIZE; i++)
//    {
//        printf("%2d%14d\n", i, some_data[i]);
//    }
//
//    return 0;
//}


//程序清单10.4 -- day_mon2.c -- letting the compiler count elements 
//
//#include <stdio.h>
//
//int main(void)
//{
//    const int days[] = { 31,28,31,30,31,30,31,31,30,31 };
//    int index;
//
//    for (index = 0; index < sizeof days / sizeof days[0]; index++)    //注意:当不是{}包含数组内容，而是“”包含数组内容时
//    {                                                                 //sizeof()函数输出字符串长度时会把结束符'\0'计算在内；
//        printf("Month %2d has %d days.\n", index + 1, days[index]);   //strlen()函数输出字符串长度时不会把结束符计算在内。
//    }
//
//    return 0;
//}


//程序清单10.5 -- designate.c -- use designated initializers
//
//#include <stdio.h>
//#define MONTHS 12
//
//int main(void)
//{
//    int days[MONTHS] = { 31,28,[4] = 31,30,31,[1] = 29 };
//    int i;
//
//    for (i = 0; i < MONTHS; i++)
//        printf("%2d  %d\n", i + 1, days[i]);
//
//    return 0;
//}