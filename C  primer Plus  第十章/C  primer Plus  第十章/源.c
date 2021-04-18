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
//        printf("Month %2d has %2d days.\n", index + 1, days[index]);
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


//程序清单10.5 -- designate.c -- use designated initializers    //在写代码时注意尽量将C的代码写在源文件后缀名为.c的形式下，
//                                                              //因为.c默认为C，而.cpp默认为C++，虽然C++支持大多数的C用法，
//#include <stdio.h>   -- 本题在.cpp下无法编译                  //但俩者的算法仍然是不同的，某些代码在.CPP文件中违反编译过去
//#define MONTHS 12                                             //但在.c文件中却可以编译过去。因此笔者建议最好在写C时用.C，在
//                                                              //写C++时用.cpp,避免错误。
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


//程序清单10.6 --  bounds.c -- exceed the bounds of an array
//
//#include <stdio.h>
//#define SIZE 4
//
//int main(void)
//{
//    int value1 = 44;
//    int arr[SIZE];
//    int value2 = 88;
//    int i;
//
//    printf("value1 = %d, value2 = %d\n", value1, value2);
//    for (i = -1; i <= SIZE; i++)
//        arr[i] = 2 * i + 1;
//
//    for (i = -1; i < 7; i++)
//        printf("%2d  %d\n", i, arr[i]);
//    printf("value1 = %d, value2 = %d\n", value1, value2);
//
//    printf("address of arr[-1]: %p\n", &arr[-1]);
//    printf("address of arr[4]:  %p\n", &arr[4]);
//    printf("address of value1:  %p\n", &value1);
//    printf("address of value2:  %p\n", &value2);
//
//    return 0;
//}


/* 程序清单10.7 -- rain.c  -- finds yearly totals, yearly average, and monthly
                   average for several years of rainfall data */
//
//#include <stdio.h>
//#define MONTHS 12    // number of months in a year
//#define YEARS   5    // number of years of data
//
//int main(void)
//{
//    // initializing rainfall data for 2010 - 2014
//    const float rain[YEARS][MONTHS] =
//    {
//        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
//        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
//        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
//        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
//        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
//    };
//    int year, month;
//    float subtot, total;
//
//    printf(" YEAR    RAINFALL  (inches)\n");
//    for (year = 0, total = 0; year < YEARS; year++)
//    {             // for each year, sum rainfall for each month
//        for (month = 0, subtot = 0; month < MONTHS; month++)
//           {
//              subtot += rain[year][month];
//            }
//        printf("%5d %15.1f\n", 2010 + year, subtot);
//        total += subtot;    // total for all years
//    }
//    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
//    printf("MONTHLY AVERAGES:\n\n");
//    printf("  Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n ");
//
//    for (month = 0; month < MONTHS; month++)
//    {             // for each month, sum rainfall over years
//        for (year = 0, subtot = 0; year < YEARS; year++)
//            {
//               subtot += rain[year][month];
//             }
//        printf("%4.1f ", subtot / YEARS);
//    }
//    printf("\n");
//
//    return 0;
//}


// 程序清单10.8 -- pnt_add.c -- pointer addition
//
//#include <stdio.h>
//#define SIZE 4
//
//int main(void)
//{
//    short dates[SIZE];
//    short* pti;
//    short index;
//    double bills[SIZE];
//    double* ptf;
//
//    pti = dates;    // assign address of array to pointer
//    ptf = bills;
//    printf("%23s %15s\n", "short", "double");
//    for (index = 0; index < SIZE; index++)
//    {
//        printf("pointers + %d: %10p %10p\n",
//               index, pti + index, ptf + index);
//    }
//
//    return 0;
//}


// 程序清单10.9 -- day_mon3.c -- uses pointer notation 
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
//        printf("Month %2d has %d days.\n", index + 1,
//            *(days + index));   // same as days[index]
//    }
//
//    return 0;
//}


// 程序清单10.10 -- sum_arr1.c -- sums the elements of an array
//
// use %u or %lu if %zd doesn't work
//#include <stdio.h>
//#define SIZE 10
//
//int sum(int ar[], int n);
//
//int main(void)
//{
//    int marbles[SIZE] = { 20,10,5,39,4,16,19,26,31,20 };
//    long answer;
//
//    answer = sum(marbles, SIZE);
//    printf("The total number of marbles is %ld.\n", answer);
//    printf("The size of marbles is %zd bytes.\n",
//        sizeof marbles);
//
//    return 0;
//}
//
//int sum(int ar[], int n)     // how big an array?
//{
//    int i;
//    int total = 0;
//
//    for (i = 0; i < n; i++)
//        total += ar[i];
//    printf("The size of ar is %zd bytes.\n", sizeof(ar));
//
//    return total;
//}



// 程序清单10.11 -- sum_arr2.c -- sums the elements of an array 
//
//#include <stdio.h>
//#define SIZE 10
//
//int sump(int* start, int* end);
//
//int main(void)
//{
//    int marbles[SIZE] = { 20,10,5,39,4,16,19,26,31,20 };
//    long answer;
//
//    answer = sump(marbles, marbles + SIZE);
//    printf("The total number of marbles is %ld.\n", answer);
//
//    return 0;
//}
//
///* use pointer arithmetic   */
//int sump(int* start, int* end)
//{
//    int total = 0;
//
//    while (start < end)
//    {
//        total += *start; // add value to total
//        start++;         // advance pointer to next element
//    }
//
//    return total;
//}


//程序清单10.12 -- order.c -- precedence in pointer operations 
//
//#include <stdio.h>
//int data[2] = { 100, 200 };
//int moredata[2] = { 300, 400 };
//
//int main(void)
//{
//    int* p1, * p2, * p3;
//
//    p1 = p2 = data;
//    p3 = moredata;
//    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n",
//        *p1, *p2, *p3);
//    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n",
//        *p1++, *++p2, (*p3)++);
//    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n",
//        *p1, *p2, *p3);
//
//    return 0;
//}