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


//程序清单10.13 -- ptr_ops.c -- pointer operations
//
//#include <stdio.h>
//
//int main(void)
//{
//    int urn[5] = { 100,200,300,400,500 };
//    int* ptr1, * ptr2, * ptr3;
//
//    ptr1 = urn;         // assign an address to a pointer
//    ptr2 = &urn[2];     // ditto
//    // dereference a pointer and take
//    // the address of a pointer
//    printf("pointer value, dereferenced pointer, pointer address:\n");
//    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n",
//        ptr1, *ptr1, &ptr1);
//
//    // pointer addition
//    ptr3 = ptr1 + 4;
//    printf("\nadding an int to a pointer:\n");
//    printf("ptr1 + 4 = %p, *(ptr4 + 3) = %d\n",
//        ptr1 + 4, *(ptr1 + 3));
//    ptr1++;            // increment a pointer
//    printf("\nvalues after ptr1++:\n");
//    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n",
//        ptr1, *ptr1, &ptr1);
//    ptr2--;            // decrement a pointer
//    printf("\nvalues after --ptr2:\n");
//    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
//        ptr2, *ptr2, &ptr2);
//    --ptr1;            // restore to original value
//    ++ptr2;            // restore to original value
//    printf("\nPointers reset to original values:\n");
//    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
//    // subtract one pointer from another
//    printf("\nsubtracting one pointer from another:\n");
//    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n",
//        ptr2, ptr1, ptr2 - ptr1);
//    // subtract an integer from a pointer
//    printf("\nsubtracting an int from a pointer:\n");
//    printf("ptr3 = %p, ptr3 - 2 = %p\n",
//        ptr3, ptr3 - 2);
//
//    return 0;
//}


/*程序清单10.14 -- arf.c -- array functions */
//
//#include <stdio.h>
//#define SIZE 5
//
//void show_array(const double ar[], int n);
//
//void mult_array(double ar[], int n, double mult);
//
//int main(void)
//{
//    double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
//
//    printf("The original dip array:\n");
//    show_array(dip, SIZE);
//    mult_array(dip, SIZE, 2.5);
//    printf("The dip array after calling mult_array():\n");
//    show_array(dip, SIZE);
//
//    return 0;
//}
//
///* displays array contents */
//void show_array(const double ar[], int n)
//{
//    int i;
//
//    for (i = 0; i < n; i++)
//        printf("%8.3f ", ar[i]);
//    putchar('\n');
//}
//
///* multiplies each array member by the same multiplier */
//void mult_array(double ar[], int n, double mult)
//{
//    int i;
//
//    for (i = 0; i < n; i++)
//        ar[i] *= mult;
//}


/*程序清单10.15 -- zippo1.c --  zippo info */
//
//#include <stdio.h>
//
//int main(void)
//{
//    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
//
//    printf("   zippo = %p,    zippo + 1 = %p\n",
//        zippo, zippo + 1);
//    printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
//        zippo[0], zippo[0] + 1);
//    printf("  *zippo = %p,   *zippo + 1 = %p\n",
//        *zippo, *zippo + 1);
//    printf("zippo[0][0] = %d\n", zippo[0][0]);
//    printf("  *zippo[0] = %d\n", *zippo[0]);
//    printf("    **zippo = %d\n", **zippo);
//    printf("      zippo[2][1] = %d\n", zippo[2][1]);
//    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));
//
//    return 0;
//}


/*程序清单10.16 -- zippo2.c --  zippo info via a pointer variable */
//
//#include <stdio.h>
//
//int main(void)
//{
//    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
//    int(*pz)[2];
//    pz = zippo;
//
//    printf("   pz = %p,    pz + 1 = %p\n",
//        pz, pz + 1);
//    printf("pz[0] = %p, pz[0] + 1 = %p\n",
//        pz[0], pz[0] + 1);
//    printf("  *pz = %p,   *pz + 1 = %p\n",
//        *pz, *pz + 1);
//    printf("pz[0][0] = %d\n", pz[0][0]);
//    printf("  *pz[0] = %d\n", *pz[0]);
//    printf("    **pz = %d\n", **pz);
//    printf("      pz[2][1] = %d\n", pz[2][1]);
//    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
//
//    return 0;
//}


/*程序清单10.17 -- array2d.c -- functions for 2d arrays*/
//
//#include <stdio.h>
//#define ROWS 3
//#define COLS 4
//
//void sum_rows(int ar[][COLS], int rows);
//
//void sum_cols(int [][COLS], int );    // ok to omit names
//
//int sum2d(int (*ar)[COLS], int rows); // another syntax
//
//int main(void)
//{
//    int junk[ROWS][COLS] = 
//    {
//        {2,4,6,8},
//        {3,5,7,9},
//        {12,10,8,6}
//    };
//    
//    sum_rows(junk, ROWS);
//    sum_cols(junk, ROWS);
//    printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
//    
//    return 0;
//}
//
//void sum_rows(int ar[][COLS], int rows)
//{
//    int r;
//    int c;
//    int tot;
//    
//    for (r = 0; r < rows; r++)
//    {
//        tot = 0;
//        for (c = 0; c < COLS; c++)
//            tot += ar[r][c];
//        printf("row %d: sum = %d\n", r, tot);
//    }
//}
//
//void sum_cols(int ar[][COLS], int rows)
//{
//    int r;
//    int c;
//    int tot;
//    
//    for (c = 0; c < COLS; c++)
//    {
//        tot = 0;
//        for (r = 0; r < rows; r++)
//            tot += ar[r][c];
//        printf("col %d: sum = %d\n", c, tot);
//    }
//}
//
//int sum2d(int ar[][COLS], int rows)
//{
//    int r;
//    int c;
//    int tot = 0;
//    
//    for (r = 0; r < rows; r++)
//        for (c = 0; c < COLS; c++)
//            tot += ar[r][c];
//    
//    return tot;
//}


/*程序清单10.18 -- vararr2d.c -- functions using VLAs -- 注意：vs2019不支持变长数组特性既该代码在vs中不能运行*/
//
//#include <stdio.h>
//#define ROWS 3
//#define COLS 4
//
//int sum2d(int rows, int cols, int ar[rows][cols]);
//
//int main(void)
//{
//    int i, j;
//    int rs = 3;
//    int cs = 10;
//    int junk[ROWS][COLS] = 
//    {
//        {2,4,6,8},
//        {3,5,7,9},
//        {12,10,8,6}
//    };
//
//    int morejunk[ROWS - 1][COLS + 2] = {
//        {20,30,40,50,60,70},
//        {5,6,7,8,9,10}
//    };
//
//    int varr[rs][cs];  // VLA
//
//    for (i = 0; i < rs; i++)
//        for (j = 0; j < cs; j++)
//            varr[i][j] = i * j + j;
//
//    printf("3x5 array\n");
//    printf("Sum of all elements = %d\n",
//        sum2d(ROWS, COLS, junk));
//
//    printf("2x6 array\n");
//    printf("Sum of all elements = %d\n",
//        sum2d(ROWS - 1, COLS + 2, morejunk));
//
//    printf("3x10 VLA\n");
//    printf("Sum of all elements = %d\n",
//        sum2d(rs, cs, varr));
//
//    return 0;
//}
//
//// function with a VLA parameter
//int sum2d(int rows, int cols, int ar[rows][cols])
//{
//    int r;
//    int c;
//    int tot = 0;
//
//    for (r = 0; r < rows; r++)
//        for (c = 0; c < cols; c++)
//            tot += ar[r][c];
//
//    return tot;
//}


//(2) -- (2)版本经过修改可以运行，但其主要问题仍然是数组的维数必须为常量，在函数中定义不行，那为局部变量。
//#include <stdio.h>
//#define ROWS 3
//#define COLS 4
//
//int sum2d(int rows, int cols, int * ar);
//
//int main(void)
//{
//    int i, j;
//    int rs = 3;
//    int cs = 10;
//        int junk[ROWS][COLS] = 
//        {
//            {2,4,6,8},
//            {3,5,7,9},
//            {12,10,8,6}
//        };
//
//    int morejunk[ROWS - 1][COLS + 2] = {
//        {20,30,40,50,60,70},
//        {5,6,7,8,9,10}
//    };
//
//    int varr[3][10];  // VLA
//
//    for (i = 0; i < rs; i++)
//        for (j = 0; j < cs; j++)
//            varr[i][j] = i * j + j;
//
//    printf("3x5 array\n");
//    printf("Sum of all elements = %d\n",
//        sum2d(ROWS, COLS, junk));
//
//    printf("2x6 array\n");
//    printf("Sum of all elements = %d\n",
//        sum2d(ROWS - 1, COLS + 2, morejunk));
//
//    printf("3x10 VLA\n");
//    printf("%d", sum2d(rs, cs, &varr[0][0]));
//
//    return 0;
//}


//程序清单10.18 -- flc.c -- funny-looking constants -- 本代码笔者增加了一行代码以验证某些疑惑
//
//#include <stdio.h>
//#define COLS 4
//
//int sum2d(const int ar[][COLS], int rows);
//
//int sum(const int ar[], int n);
//
//int main(void)
//{
//    int total1, total2, total3;
//    int* pt1;
//    int(*pt2)[COLS];
//
//    pt1 = (int[2]){ 10, 20 };
//    pt2 = (int[2][COLS]){ {1,2,3,-9}, {4,5,6,-8} };
//
//    total1 = sum(pt1, 2);
//    total2 = sum2d(pt2, 2);
//    total3 = sum((int[]) { 4, 4, 4, 5, 5, 5 }, 6);
//    printf("total1 = %d\n", total1);
//    printf("total2 = %d\n", total2);
//    printf("total3 = %d\n", total3);
//    printf("%d  %d  \n", *pt1, *(pt1 + 1));    //使用指针看是否可以表达这种复合字面量数组的值
//
//    return 0;
//}
//
//int sum(const int ar[], int n)
//{
//    int i;
//    int total = 0;
//
//    for (i = 0; i < n; i++)
//        total += ar[i];
//
//    return total;
//}
//
//int sum2d(const int ar[][COLS], int rows)
//{
//    int r;
//    int c;
//    int tot = 0;
//
//    for (r = 0; r < rows; r++)
//        for (c = 0; c < COLS; c++)
//            tot += ar[r][c];
//
//    return tot;
//}


//编程练习 -- Chapter 10 Programming	Exercises
//
/* Programming Exercise 10-1 */
//
//#include <stdio.h>
//#define MONTHS 12 // number of months in a year
//#define YRS 5 // number of years of data
//
//int main(void)
//{
//    // initializing rainfall data for 2010 - 2014
//    const float rain[YRS][MONTHS] = {
//    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
//    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
//    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
//    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
//    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
//    };
//    int year, month;
//    float subtot, total;
//
//    printf(" YEAR RAINFALL (inches)\n");
//    for (year = 0, total = 0; year < YRS; year++)
//    { /* for each year, sum rainfall for each month */
//        for (month = 0, subtot = 0; month < MONTHS; month++)
//            subtot += *(*(rain + year) + month);
//        printf("%5d %15.1f\n", 2010 + year, subtot);
//        total += subtot; /* total for all years */
//    }
//    printf("\nThe yearly average is %.1f inches.\n\n", total / YRS);
//    printf("MONTHLY AVERAGES:\n\n");
//    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
//    printf(" Nov  Dec\n");
//
//    for (month = 0; month < MONTHS; month++)
//    { /* for each month, sum rainfall over years */
//        for (year = 0, subtot = 0; year < YRS; year++)
//            subtot += *(*(rain + year) + month);
//        printf("%4.1f ", subtot / YRS);
//    }
//    printf("\n");
//    return 0;
//}


/* Programming Exercise 10-2 */
//
//#include <stdio.h>
//
//void copy_arr(double t[], double s[], int n);
//
//void copy_ptr(double* t, double* s, int n);
//
//void copy_ptrs(double* t, double* s_first, double* s_last);
//
//int main(void) 
//{
//    double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
//    double target1[5];
//    double target2[5];
//    double target3[5];
//    copy_arr(target1, source, 5);
//    copy_ptr(target2, source, 5);
//    copy_ptrs(target3, source, source + 5);
//    return 0;
//}
//
//void copy_arr(double t[], double s[], int n)
//{
//    for (int i = 0; i < n; i++)
//        t[i] = s[i];
//
//}
//
//void copy_ptr(double * t, double * s, int n) 
//{
//    for (int i = 0; i < n; i++)
//        *(t + i) = *(s + i);
//}
//
//void copy_ptrs(double * t, double * s_first, double * s_last) 
//{
//    for (int i = 0; (s_last - s_first) > i; i++)
//
//        *(t+i) = *(s_first+i);
//
//}


/* Programming Exercise 10-3 */
//
//#include <stdio.h>
//#define LEN 10 
//
//int max_arr(const int ar[], int n);
//
//void show_arr(const int ar[], int n);
//
//int main(void)
//{
//    int orig[LEN] = { 1,2,3,4,12,6,7,8,9,10 };
//    int max;
//    show_arr(orig, LEN);
//    max = max_arr(orig, LEN);
//    printf("%d = largest value\n", max);
//
//    return 0;
//}
//
//int max_arr(const int ar[], int n)
//{
//    int i;
//    int max = ar[0];
//    /* don't use 0 as initial max value -- fails if all array values are neg */
//
//    for (i = 1; i < n; i++)
//        if (max < ar[i])
//            max = ar[i];
//    return max;
//}
//
//void show_arr(const int ar[], int n)
//{
//    int i;
//
//    for (i = 0; i < n; i++)
//        printf("%d ", ar[i]);
//    putchar('\n');
//}


/* Programming Exercise 10-4 */
//
//#include <stdio.h>
//#define LEN 10 
//
//int max_arr(const double ar[], int n);
//
//void show_arr(const double ar[], int n);
//
//int main(void)
//{
//    double orig[LEN] = { 1,2,3,4,12,6,7,8,9,10 };
//    int max;
//    show_arr(orig, LEN);
//    max = max_arr(orig, LEN);
//    printf("%d = largest\n", max);
//
//    return 0;
//}
//
//int max_arr(const double ar[], int n)
//{
//    int i;
//    int max1 = 0;
//    double max = ar[0];
//    /* don't use 0 as initial max value -- fails if all array values are neg */
//
//    for (i = 1; i < n; i++)
//    {
//        if (max < ar[i])
//        {
//            max = ar[i];
//            max1 = i;
//        }
//    }
//
//    if (max == ar[0])
//        max1 = 0;
//    return max1;
//}
//
//void show_arr(const double ar[], int n)
//{
//    int i;
//
//    for (i = 0; i < n; i++)
//        printf("%f ", ar[i]);
//    putchar('\n');
//}


/* Programming Exercise 10-5 */
//
//#include <stdio.h>
//#define LEN 10 
//
//double difference_arr(const double ar[], int n);
//
//void show_arr(const double ar[], int n);
//
//int main(void)
//{
//    double orig[LEN] = { 1,2,3,4,12,6,7,8,9,10 };
//    double difference=0;
//
//    show_arr(orig, LEN);
//    difference = difference_arr(orig, LEN);
//    printf("%f = largest-minimum\n", difference);
//
//    return 0;
//}
//
//double difference_arr(const double ar[], int n)
//{
//    int i;
//    double max = ar[0];
//    double min = ar[0];
//    double difference = 0.0;
//    /* don't use 0 as initial max value -- fails if all array values are neg */
//
//    for (i = 1; i < n; i++)
//    {
//        if (max < ar[i])
//        {
//            max = ar[i];
//        }
//    }
//
//    for (i = 1; i < n; i++)
//    {
//        if (min > ar[i])
//        {
//            min = ar[i];
//        }
//    }
//    difference = (max - min);
//
//    return difference;
//}
//
//void show_arr(const double ar[], int n)
//{
//    int i;
//
//    for (i = 0; i < n; i++)
//        printf("%f ", ar[i]);
//    putchar('\n');
//}


/* Programming Exercise 10-6 */
//
//#include <stdio.h>
//#define LEN 10 
//
//void arr( double ar[], int n);
//
//void show_arr(const double ar[], int n);
//
//int main(void)
//{
//    double orig[LEN] = { 1,2,3,4,12,6,7,8,9,10 };
//
//    printf("The top:\n");
//    show_arr(orig, LEN);
//    arr(orig, LEN);
//    printf("After arrangement:\n");
//    show_arr(orig, LEN);
//
//    return 0;
//}
//
//void arr( double ar[], int n)
//{
//    int i,k;
//    double temp = 0.0;
//    /* don't use 0 as initial max value -- fails if all array values are neg */
//
//    for (i = 0,k=n-1; i < n/2-1; i++,k--)
//    {
//        temp = ar[i];
//        ar[i] = ar[k];
//        ar[k] = temp;
//    }
//
//
//    return 0;
//}
//
//void show_arr(const double ar[], int n)
//{
//    int i;
//
//    for (i = 0; i < n; i++)
//        printf("%f ", ar[i]);
//    putchar('\n');
//}


/* Programming Exercise 10-7 */
//
//#include <stdio.h>
//#define ROWS 12
//#define COLS 5
//
//void copy_arr(double t[], double s[], int n);
//
//void copy_ptr(double* t, double* s, int n);
//
//void copy_ptrs(double* t, double* s_first, double* s_last);
//
//void copy_2d_ptr(double(*t)[ROWS], double(*s)[ROWS], int n);
//
//int main(void) 
//{
//    double target[COLS][ROWS], source[COLS][ROWS] = 
//    {
//            {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
//            {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
//            {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
//            {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
//            {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2},
//    };
//
//    copy_2d_ptr(target, source, COLS);
//
//    for (int i = 0; i < COLS; i++) 
//    {
//        for (int j = 0; j < ROWS; j++)
//            printf("%5.2f", target[i][j]);
//        printf("\n");
//    }
//    return 0;
//}
//
//void copy_arr(double t[], double s[], int n) 
//{
//    for (int i = 0; i < n; i++)
//    {
//        t[i] = s[i];
//    }
//}
//void copy_2d_ptr(double(*t)[ROWS], double(*s)[ROWS], int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        copy_ptr(*(t + i), *(s + i), ROWS);
//    }
//}
//void copy_ptr(double * t, double * s, int n) 
//{
//    for (int i = 0; i < n; i++)
//    {
//        *(t + i) = *(s + i);
//        printf("%lf  ", t[i]);
//        if (i==n-1)
//        {
//            printf("\n");
//        }
//    }
//}
//void copy_ptrs(double* t, double* s_first, double* s_last) 
//{
//    for (int i = 0; (s_last - s_first) > i; i++)
//        //for(int i = 0; (s_last - s_first) > 0 ;i++, s_first++)
//        *(t + i) = *(s_first + i);
//}


/* Programming Exercise 10-8 */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//void copy_ptr(double* t, double* s, int n);
//
//int main(void)
//{
//    double src[] = { 1, 2, 3, 4, 5, 6, 7 };
//    double targ[3];
//    copy_ptr(targ, src + 2, 3);
//
//    printf("Now Show the src array:\n");
//    for (int i = 0 ;i < 7; i++)
//        printf("%.0lf ", src[i]);
//
//    printf("\nNow Show the dest array:\n");
//    for (int i = 0; i < 3; ++i)
//        printf("%.0lf ", targ[i]);
//    return 0;
//}
//void copy_ptr(double *t, double *s, int n)
//{
//    for(int i = 0 ;i < n ;i++)
//        *(t+i) = *(s+i);
//}


/* Programming Exercise 10-9 */    //注意，若编译器不支持变长数组，则该代码不能运行
//#include <stdio.h>

//void copy_array(int n, int m, double target[n][m], const double source[n][m]);

//void show_array(int n, int m, const double array[n][m]);
//
//int main(void) 
//{
//    int n = 3;
//    int m = 5;
//    double target[n][m], source[][5] =
//    {
//            {0.2, 0.4, 2.4, 3.5, 6.6},
//            {8.5, 8.2, 1.2, 1.6, 2.4},
//            {9.1, 8.5, 2.3, 6.1, 8.4},
//    };
//    copy_array(n, m, target, source);
//    show_array(n, m, target);
//    return 0;
//}
//
//void copy_array(int n, int m, double target[n][m], const double source[n][m])
//{
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            target[i][j] = source[i][j];
//}
//
//void show_array(int n, int m, const double array[n][m])
//{
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            printf("%g ", array[i][j]);
//        printf("\n");
//    }
//}


/* Programming Exercise 10-10 */
//
//#include <stdio.h>
//#define INDEX 4
//
//void add_array(int n, int t[INDEX], const int s1[INDEX], const int s2[INDEX]);
//
//int main(void) 
//{
//    int sum[INDEX], s1[INDEX] = { 2,4,5,8 }, s2[INDEX] = { 1,0,4,6 };
//    add_array(INDEX, sum, s1, s2);
//    for (int i = 0; i < INDEX; i++)
//        printf("%d ", sum[i]);
//    return 0;
//}
//
//void add_array(int n, int t[INDEX], const int s1[INDEX], const int s2[INDEX])
//{
//    for (int i = 0; i < n; i++)
//        t[i] = s1[i] + s2[i];
//}


/* Programming Exercise 10-11 */
//
//#include <stdio.h>
//#define ROWS 3
//#define COLS 5 
//
//void times2(int ar[][COLS], int r);
//
//void showarr2(int ar[][COLS], int r);
//
//int main(void)
//{
//    int stuff[ROWS][COLS] = 
//    { 
//        {1,2,3,4,5},
//        {6,7,8,-2,10},
//        {11,12,13,14,15}
//    };
//    showarr2(stuff, ROWS);
//    putchar('\n');
//    times2(stuff, ROWS);
//    showarr2(stuff, ROWS);
//
//    return 0;
//}
//
//void times2(int ar[][COLS], int r)
//{
//    int row, col;
//
//    for (row = 0; row < r; row++)
//        for (col = 0; col < COLS; col++)
//            ar[row][col] *= 2;
//}
//
//void showarr2(int ar[][COLS], int r)
//{
//    int row, col;
//
//    for (row = 0; row < r; row++)
//    {
//        for (col = 0; col < COLS; col++)
//            printf("%3d ", ar[row][col]);
//        putchar('\n');
//    }
//}


/* Programming Exercise 10-13 */
//
//#include <stdio.h>
//#define ROWS 3
//#define COLS 5 
//
//void store(double ar[], int n);
//
//double average2d(int rows, int cols, double ar[ROWS][COLS]);
//
//double max2d(int rows, int cols, double ar[ROWS][COLS]);
//
//void showarr2(int rows, int cols, double ar[ROWS][COLS]);
//
//double average(const double ar[], int n);
//
//int main(void)
//{
//    double stuff[ROWS][COLS];
//    int row;
//
//    for (row = 0; row < ROWS; row++)
//    {
//        printf("Enter %d numbers for row %d\n", COLS, row + 1);
//        store(stuff[row], COLS);
//    }
//
//    printf("array contents:\n");
//    showarr2(ROWS, COLS, stuff);
//
//    for (row = 0; row < ROWS; row++)
//        printf("average value of row %d = %g\n", row + 1, average(stuff[row], COLS));
//    printf("average value of all rows = %g\n", average2d(ROWS, COLS, stuff));
//    printf("largest value = %g\n", max2d(ROWS, COLS, stuff));
//    printf("Bye!\n");
//
//    return 0;
//}
//
//void store(double ar[], int n)
//{
//    int i;
//    for (i = 0; i < n; i++)
//    {
//        printf("Enter value #%d: ", i + 1);
//        scanf("%lf", &ar[i]);
//    }
//}
//
//double average2d(int rows, int cols, double ar[ROWS][COLS])
//{
//    int r, c;
//    double sum = 0.0;
//
//    for (r = 0; r < rows; r++)
//        for (c = 0; c < cols; c++)
//            sum += ar[r][c];
//    if (rows * cols > 0)
//        return sum / (rows * cols);
//    else
//        return 0.0;
//}
//
//double max2d(int rows, int cols, double ar[ROWS][COLS])
//{
//    int r, c;
//    double max = ar[0][0];
//
//    for (r = 0; r < rows; r++)
//        for (c = 0; c < cols; c++)
//            if (max < ar[r][c])
//                max = ar[r][c];
//    return max;
//}
//
//void showarr2(int rows, int cols, double ar[ROWS][COLS])
//{
//    int row, col;
//
//    for (row = 0; row < rows; row++)
//    {
//        for (col = 0; col < cols; col++)
//            printf("%3g ", ar[row][col]);
//        putchar('\n');
//    }
//}
//
//double average(const double ar[], int n)
//{
//    int i;
//    double sum = 0.0;
//
//    for (i = 0; i < n; i++)
//        sum += ar[i];
//    if (n > 0)
//        return sum / n;
//    else
//        return 0.0;
//}
