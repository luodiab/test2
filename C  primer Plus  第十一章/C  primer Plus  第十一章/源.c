#define _CRT_SECURE_NO_WARNINGS 1

/* 程序清单11.1 --  strings1.c */
//
//#include <stdio.h>
//
//#define MSG "I am a symbolic string constant."
//#define MAXLENGTH 81
//
//int main(void)
//{
//    char words[MAXLENGTH] = "I am a string in an array.";
//    const char* pt1 = "Something is pointing at me.";
//
//    puts("Here are some strings:");
//    puts(MSG);
//    puts(words);
//    puts(pt1);
//    words[8] = 'p';
//    puts(words);
//
//    return 0;


/* 程序清单11.2 -- strptr.c -- strings as pointers -- 注意：在"space farers"前加上‘*’号，相当于‘*arry[]'
                                                            "space farers"相当于数组名。*/
//
//#include <stdio.h>
//
//int main(void)
//{
//    printf("%s, %p, %c\n", "We", "are", *"space farers");
//    printf("%c", *"apace farers" + 2);    //相当于a的值加上2。
//    printf("%c", *("apace farers" + 2));  //相当于第三个元素的值，("apace farers" + 2)为第三个元素的地址。
//
//    return 0;
//


/* 程序清单11.3 -- addresses.c  -- addresses of strings */
//
//#define MSG "I'm special."
//#include <stdio.h>
//
//int main()
//{
//    char ar[] = MSG;
//    const char* pt = MSG;
//    printf("address of \"I'm special\": %p \n", "I'm special");
//    printf("              address ar: %p\n", ar);
//    printf("              address pt: %p\n", pt);
//    printf("          address of MSG: %p\n", MSG);
//    printf("address of \"I'm special\": %p \n", "I'm special");
//
//    return 0;
//}


/* 程序清单11.4 -- arrchar.c -- array of pointers, array of strings */
//
//#include <stdio.h>
//#define SLEN 40
//#define LIM 5
//
//int main(void)
//{
//    const char* mytalents[LIM] = 
//    {
//        "Adding numbers swiftly",
//        "Multiplying accurately", "Stashing data",
//        "Following instructions to the letter",
//        "Understanding the C language"
//    };
//    char yourtalents[LIM][SLEN] = 
//    {
//        "Walking in a straight line",
//        "Sleeping", "Watching television",
//        "Mailing letters", "Reading email"
//    };
//    int i;
//
//    puts("Let's compare talents.");
//    printf("%-36s  %-25s\n", "My Talents", "Your Talents");
//    for (i = 0; i < LIM; i++)
//        printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
//    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
//        sizeof(mytalents), sizeof(yourtalents));
//
//    return 0;
//}


/* 程序清单11.5 -- p_and_s.c -- pointers and strings */
//
//#include <stdio.h>
//
//int main(void)
//{
//    const char* mesg = "Don't be a fool!";
//    const char* copy;
//
//    copy = mesg;
//    printf("%s\n", copy);
//    printf("mesg = %s; &mesg = %p; value = %p\n",                  
//        mesg, &mesg, mesg);                       /*注意：const char* mesg = "Don't be a fool!"与
//                                                          printf("%c", *"apace farers" + 2)不同，
//                                                          前一个输出是‘%s’，后一个输出是‘%c'。*/
//
//    printf("copy = %s; &copy = %p; value = %p\n",
//        copy, &copy, copy);
// 
//    return 0;
//}


/* 程序清单11.6 -- getsputs.c  -- using gets() and puts() */
//
//#include <stdio.h>
//#define STLEN 81
//
//int main(void)
//{
//    char words[STLEN];
//
//    puts("Enter a string, please.");
//    gets(words);  // typical use
//    printf("Your string twice:\n");
//    printf("%s\n", words);
//    puts(words);
//    puts("Done.");
//
//    return 0;
//}


/* 程序清单11.7 -- fgets1.c  -- using fgets() and fputs() */
/*注意：puts会在后面补上一个‘\n’而fputs则不会*/
//
//#include <stdio.h>
//#define STLEN 14
//
//int main(void)
//{
//    char words[STLEN];
//
//    puts("Enter a string, please.");
//    fgets(words, STLEN, stdin);
//    printf("Your string twice (puts(), then fputs()):\n");
//    puts(words);
//    fputs(words, stdout);
//    puts("Enter another string, please.");
//    fgets(words, STLEN, stdin);
//    printf("Your string twice (puts(), then fputs()):\n");
//    puts(words);
//    fputs(words, stdout);
//    puts("Done.");
//
//    return 0;
//}


/* 程序清单11.8 -- fgets2.c  -- using fgets() and fputs() */
//
//#include <stdio.h>
//#define STLEN 10
//
//int main(void)
//{
//    char words[STLEN];
//
//    puts("Enter strings (empty line to quit):");
//    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
//        fputs(words, stdout);
//    puts("Done.");
//
//    return 0;
//}


/* 程序清单11.9 -- fgets3.c  -- using fgets() */
//
//#include <stdio.h>
//#define STLEN 10
//
//int main(void)
//{
//    char words[STLEN];
//    int i;
//
//    puts("Enter strings (empty line to quit):");
//    while (fgets(words, STLEN, stdin) != NULL
//        && words[0] != '\n')
//    {
//        i = 0;
//        while (words[i] != '\n' && words[i] != '\0')
//            i++;
//        if (words[i] == '\n')
//            words[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//        puts(words);
//    }
//    puts("done");
//
//    return 0;
//}


/* 程序清单11.11 -- scan_str.c -- using scanf() */
//
//#include <stdio.h>
//
//int main(void)
//{
//    char name1[11], name2[11];
//    int count;
//
//    printf("Please enter 2 names.\n");
//    count = scanf("%5s %10s", name1, name2);
//    printf("I read the %d names %s and %s.\n",
//        count, name1, name2);
//
//    return 0;
//}


/* 程序清单11.12 -- put_out.c -- using puts() */
//
//#include <stdio.h>
//#define DEF "I am a #defined string."
//
//int main(void)
//{
//    char str1[80] = "An array was initialized to me.";
//    const char* str2 = "A pointer was initialized to me.";
//
//    puts("I'm an argument to puts().");
//    puts(DEF);
//    puts(str1);
//    puts(str2);
//    puts(&str1[5]);
//    puts(str2 + 4);
//
//    return 0;
//}


/* 程序清单11.13 -- nono.c -- no! */
//
//#include <stdio.h>
//
//int main(void)
//{
//    char side_a[] = "Side A";
//    char dont[] = { 'W', 'O', 'W', '!' };
//    char side_b[] = "Side B";
//
//    puts(dont);   /* dont is not a string */
//
//    return 0;
//}


/* 程序清单11.14.15.16 -- put_put.c -- user-defined output functions */
//
//#include <stdio.h>
//
//void put1(const char *);    //(11.14)
//
//int put2(const char *);     //(11.15)
//
//int main(void)
//{
//    put1("If I'd as much money");
//    put1(" as I could spend,\n");
//    printf("I count %d characters.\n",
//           put2("I never would cry old chairs to mend."));
//    
//    return 0;
//}
//
//void put1(const char * string)
//{
//    while (*string)  /* same as *string != '\0' */
//       putchar(*string++);
//}
//
//int put2(const char* string)
//{
//    int count = 0;
//    while (*string)
//    {
//        putchar(*string++);
//        count++;
//    }
//    putchar('\n');
//
//    return(count);
//}


/* 程序清单11.17 -- test_fit.c -- try the string-shrinking function */
//
//#include <stdio.h>
//#include <string.h> /* contains string function prototypes */
//
//void fit(char*, unsigned int);
//
//int main(void)
//{
//    char mesg[] = "Things should be as simple as possible,"
//        " but not simpler.";
//
//    puts(mesg);
//    fit(mesg, 38);
//    puts(mesg);
//    puts("Let's look at some more of the string.");
//    puts(mesg + 39);
//
//    return 0;
//}
//
//void fit(char* string, unsigned int size)
//{
//    if (strlen(string) > size)
//        string[size] = '\0';
//}


/* 程序清单11.18 -- str_cat.c -- joins two strings */
//
//#include <stdio.h>
//#include <string.h>  /* declares the strcat() function */
//#define SIZE 80
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char flower[SIZE];
//    char addon[] = "s smell like old shoes.";
//
//    puts("What is your favorite flower?");
//    if (s_gets(flower, SIZE))
//    {
//        strcat(flower, addon);
//        puts(flower);
//        puts(addon);
//    }
//    else
//        puts("End of file encountered!");
//    puts("bye");
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}

/* 补充（strcat的用法）：
头文件：#include <string.h>

strcat() 函数用来连接字符串，其原型为：char *strcat(char *dest, const char *src);

【参数】dest 为目的字符串指针，src 为源字符串指针。

strcat() 会将参数 src 字符串复制到参数 dest 所指的字符串尾部；dest 最后的结束字符 NULL 会被覆盖掉，并在

连接后的字符串的尾部再增加一个 NULL。

注意：dest 与 src 所指的内存空间不能重叠，且 dest 要有足够的空间来容纳要复制的字符串。

【返回值】返回dest 字符串起始地址 */


/* 程序清单11.19 -- join_chk.c -- joins two strings, check size first */
//
//#include <stdio.h>
//#include <string.h>
//#define SIZE 30
//#define BUGSIZE 13
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char flower[SIZE];
//    char addon[] = "s smell like old shoes.";
//    char bug[BUGSIZE];
//    int available;
//
//    puts("What is your favorite flower?");
//    s_gets(flower, SIZE);
//    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
//        strcat(flower, addon);
//    puts(flower);
//    puts("What is your favorite bug?");
//    s_gets(bug, BUGSIZE);
//    available = BUGSIZE - strlen(bug) - 1;
//    strncat(bug, addon, available);
//    puts(bug);
//
//    return 0;
//}
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}

/*strlen 测量的是字符的实际长度，以'\0' 结束（不包含'\0' ）。

而sizeof 测量的是字符的分配大小，如果未分配大小，则遇到'\0' 结束

（包含'\0' ，也就是strlen测量的长度加1），如果已经分配内存大小，返回的就是分配的内存大小

即通常同一个字符串，strlen得出的结果比sizeof少1。*/


/* 程序清单11.20 -- nogo.c -- will this work? */
//
//#include <stdio.h>
//#define ANSWER "Grant"
//#define SIZE 40
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char try[SIZE];
//
//    puts("Who is buried in Grant's tomb?");
//    s_gets(try, SIZE);
//    while (try != ANSWER)
//    {
//        puts("No, that's wrong. Try again.");
//        s_gets(try, SIZE);
//    }
//    puts("That's right!");
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* 程序清单11.21 -- compare.c -- this will work */
//
//#include <stdio.h>
//#include <string.h>   // declares strcmp()
//
//#define ANSWER "Grant"
//#define SIZE 40
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char try[SIZE];
//
//    puts("Who is buried in Grant's tomb?");
//    s_gets(try, SIZE);
//    while (strcmp(try, ANSWER) != 0)
//    {
//        puts("No, that's wrong. Try again.");
//        s_gets(try, SIZE);
//    }
//    puts("That's right!");
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* 程序清单11.22 -- compback.c -- strcmp returns */
//
//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//
//    printf("strcmp(\"A\", \"A\") is ");
//    printf("%d\n", strcmp("A", "A"));
//
//    printf("strcmp(\"A\", \"B\") is ");
//    printf("%d\n", strcmp("A", "B"));
//
//    printf("strcmp(\"B\", \"A\") is ");
//    printf("%d\n", strcmp("B", "A"));
//
//    printf("strcmp(\"C\", \"A\") is ");
//    printf("%d\n", strcmp("C", "A"));
//
//    printf("strcmp(\"Z\", \"a\") is ");
//    printf("%d\n", strcmp("Z", "a"));
//
//    printf("strcmp(\"apples\", \"apple\") is ");
//    printf("%d\n", strcmp("apples", "apple"));
//
//    return 0;
//}

/*补充：若第一个字符串位于第二个字符串前面，strcmp则返回-1，

        若第一个字符串位于第二个字符串后面，strcmp则返回1。
        
        若第一个字符串与第二个字符串相同，strcmp则返回0。*/


/* 程序清单11.23 -- quit_chk.c -- beginning of some program */
//
//#include <stdio.h>
//#include <string.h>
//#define SIZE 80
//#define LIM 10
//#define STOP "quit"
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char input[LIM][SIZE];
//    int ct = 0;
//
//    printf("Enter up to %d lines (type quit to quit):\n", LIM);
//    while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
//        strcmp(input[ct], STOP) != 0)
//    {
//        ct++;
//    }
//    printf("%d strings entered\n", ct);
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* 程序清单11.24 -- starsrch.c -- use strncmp() */
//
//#include <stdio.h>
//#include <string.h>
//#define LISTSIZE 6
//
//int main()
//{
//    const char* list[LISTSIZE] =
//    {
//        "astronomy", "astounding",
//        "astrophysics", "ostracize",
//        "asterism", "astrophobia"
//    };
//    int count = 0;
//    int i;
//
//    for (i = 0; i < LISTSIZE; i++)
//        if (strncmp(list[i], "astro", 5) == 0)
//        {
//            printf("Found: %s\n", list[i]);
//            count++;
//        }
//    printf("The list contained %d words beginning"
//        " with astro.\n", count);
//
//    return 0;
//}


/* 程序清单11.25 -- copy1.c -- strcpy() demo */
//
//#include <stdio.h>
//#include <string.h>  // declares strcpy()
//
//#define SIZE 40
//#define LIM 5
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char qwords[LIM][SIZE];
//    char temp[SIZE];
//    int i = 0;
//
//    printf("Enter %d words beginning with q:\n", LIM);
//    while (i < LIM && s_gets(temp, SIZE))
//    {
//        if (temp[0] != 'q')
//            printf("%s doesn't begin with q!\n", temp);
//        else
//        {
//            strcpy(qwords[i], temp);
//            i++;
//        }
//    }
//    puts("Here are the words accepted:");
//    for (i = 0; i < LIM; i++)
//        puts(qwords[i]);
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* 程序清单11.26 -- copy2.c -- strcpy() demo */
//
//#include <stdio.h>
//#include <string.h>    // declares strcpy()
//
//#define WORDS  "beast"
//#define SIZE 40
//
//int main(void)
//{
//    const char* orig = WORDS;
//    char copy[SIZE] = "Be the best that you can be.";
//    char* ps;
//
//    puts(orig);
//    puts(copy);
//    ps = strcpy(copy + 7, orig);
//    puts(copy);
//    puts(ps);       //注意：strcpy返回的是第一个参数的地址。
//
//    return 0;
//}


/* 程序清单11.27 -- copy3.c -- strncpy() demo */
//
//#include <stdio.h>
//#include <string.h>  /* declares strncpy() */
//
//#define SIZE 40
//#define TARGSIZE 7
//#define LIM 5
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char qwords[LIM][TARGSIZE];
//    char temp[SIZE];
//    int i = 0;
//
//    printf("Enter %d words beginning with q:\n", LIM);
//    while (i < LIM && s_gets(temp, SIZE))
//    {
//        if (temp[0] != 'q')
//            printf("%s doesn't begin with q!\n", temp);
//        else
//        {
//            strncpy(qwords[i], temp, TARGSIZE - 1);
//            qwords[i][TARGSIZE - 1] = '\0';
//            i++;
//        }
//    }
//    puts("Here are the words accepted:");
//    for (i = 0; i < LIM; i++)
//        puts(qwords[i]);
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* 程序清单11.28 -- format.c -- format a string */
//
//#include <stdio.h>
//
//#define MAX 20
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char first[MAX];
//    char last[MAX];
//    char formal[2 * MAX + 10];
//    double prize;
//
//    puts("Enter your first name:");
//    s_gets(first, MAX);
//    puts("Enter your last name:");
//    s_gets(last, MAX);
//    puts("Enter your prize money:");
//    scanf("%lf", &prize);
//    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
//    puts(formal);
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* 程序清单11.29 -- sort_str.c -- reads in strings and sorts them */
//
//#include <stdio.h>
//#include <string.h>
//
//#define SIZE 81        /* string length limit, including \0  */
//#define LIM 20         /* maximum number of lines to be read */
//#define HALT ""        /* null string to stop input          */
//
//void stsrt(char* strings[], int num);/* string-sort function */
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char input[LIM][SIZE];     /* array to store input       */
//    char* ptstr[LIM];          /* array of pointer variables */
//    int ct = 0;                /* input count                */
//    int k;                     /* output count               */
//
//    printf("Input up to %d lines, and I will sort them.\n", LIM);
//    printf("To stop, press the Enter key at a line's start.\n");
//    while (ct < LIM && s_gets(input[ct], SIZE) != NULL
//        && input[ct][0] != '\0')
//    {
//        ptstr[ct] = input[ct];  /* set ptrs to strings        */
//        ct++;
//    }
//    stsrt(ptstr, ct);          /* string sorter              */
//    puts("\nHere's the sorted list:\n");
//    for (k = 0; k < ct; k++)
//        puts(ptstr[k]);       /* sorted pointers            */
//
//    return 0;
//}
//
///* string-pointer-sorting function */
//void stsrt(char* strings[], int num)
//{
//    char* temp;
//    int top, seek;
//
//    for (top = 0; top < num - 1; top++)
//        for (seek = top + 1; seek < num; seek++)
//            if (strcmp(strings[top], strings[seek]) > 0)
//            {
//                temp = strings[top];
//                strings[top] = strings[seek];
//                strings[seek] = temp;
//            }
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* 程序清单11.30 -- mod_str.c -- modifies a string */
//
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//#define LIMIT 81
//
//void ToUpper(char *);
//
//int PunctCount(const char *);
//
//int main(void)
//{
//    char line[LIMIT];
//    char * find;
//    
//    puts("Please enter a line:");
//    fgets(line, LIMIT, stdin);
//    find = strchr(line, '\n');   // look for newline
//    if (find)                    // if the address is not NULL,
//        *find = '\0';            // place a null character there
//    ToUpper(line);
//    puts(line);
//    printf("That line has %d punctuation characters.\n",
//           PunctCount(line));
//    
//    return 0;
//}
//
//void ToUpper(char * str)
//{
//    while (*str)
//    {
//        *str = toupper(*str);
//        str++;
//    }
//}
//
//int PunctCount(const char * str)
//{
//    int ct = 0;
//    while (*str)
//    {
//        if (ispunct(*str))
//            ct++;
//        str++;
//    }
//    
//    return ct;
//}


/* 程序清单11.31 -- repeat.c -- main() with arguments */
//
//#include <stdio.h>
//
//int main(int argc, char* argv[])
//{
//    int count;
//
//    printf("The command line has %d arguments:\n", argc - 1);
//    for (count = 1; count < argc; count++)
//        printf("%d: %s\n", count, argv[count]);
//    printf("\n");
//
//    return 0;
//}


/* 程序清单11.33 -- strcnvt.c -- try strtol()  */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define LIM 30
//
//char* s_gets(char* st, int n);
//
//int main()
//{
//    char number[LIM];
//    char* end;
//    long value;
//
//    puts("Enter a number (empty line to quit):");
//    while (s_gets(number, LIM) && number[0] != '\0')
//    {
//        value = strtol(number, &end, 10);  /* base 10 */
//        printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n",
//            value, end, *end);
//        value = strtol(number, &end, 16);  /* base 16 */
//        printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n",
//            value, end, *end);
//        puts("Next number:");
//    }
//    puts("Bye!\n");
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else // must have words[i] == '\0'
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}