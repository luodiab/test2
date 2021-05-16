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


//Chapter	11 Programming	Exercises

/* Programming Exercise 11-1 */
//
//#include <stdio.h>
//
//#define LEN 10
//
//char* getnchar(char* str, int n);
//
//int main(void)
//{
//    char input[LEN];
//    char* check;
//
//    check = getnchar(input, LEN - 1);
//    if (check == NULL)
//        puts("Input failed.");
//    else
//        puts(input);
//    puts("Done.\n");
//
//    return 0;
//}
//char* getnchar(char* str, int n)
//{
//    int i;
//    int ch;
//    for (i = 0; i < n; i++)
//    {
//        ch = getchar();
//        if (ch != EOF)
//            str[i] = ch;
//        else
//            break;
//    }
//    if (ch == EOF)
//        return NULL;
//    else
//    {
//        str[i] = '\0';
//        return str;
//    }
//}


/* Programming Exercise 11-2 */

//(1)
//#include <stdio.h>
//
//#define SIZE 40
//
//char* read_char(char* st, int n);
//
//int main(int argc, char* argv[]) 
//{
//    char test[SIZE];
//    puts("Start to test function. Enter a string.");
//    read_char(test, SIZE);
//    puts("The string you input is:");
//    puts(test);
//
//    return 0;
//}
//
//char* read_char(char* st, int n) 
//{
//    int i = 0;
//    do 
//    {
//        st[i] = getchar();
//        if (st[i] == '\n' || st[i] == '\t' || st[i] == ' ')
//            break;
//
//    } while (st[i] != EOF && ++i < n);
//    st[i] = '\0';        /* 若没有这个语句，则当数组没有存储满时，输出到屏幕时,当存储的内容输出完时会随意输出内容。*/

//    return st;
//}

//(2)
//#include <stdio.h>
//
//#define LEN 40
//
//char* getnchar(char* str, int n);
//
//int main(void)
//{
//    char input[LEN];
//    char* check;
//
//    check = getnchar(input, LEN - 1);
//    if (check == NULL)
//        puts("Input failed.");
//    else
//        puts(input);
//    puts("Done.\n");
//
//    return 0;
//}
//char* getnchar(char* str, int n)
//{
//    int i;
//    int ch;
//    for (i = 0; i < n; i++)
//    {
//        ch = getchar();
//        if (ch == '\n' || ch == '\t' || ch == ' ')
//            break;
//        else if (ch != EOF)
//            str[i] = ch;
//        else
//            break;
//    }
//    if (ch == EOF)
//        return NULL;
//    else
//    {
//        str[i] = '\0';
//        return str;
//    }
//}


/* Programming Exercise 11-3 */
//
//#include <stdio.h>
//#include <ctype.h>
//
//#define LEN 20
//
//char* getword(char* str);
//
//int main(void)
//{
//    char input[LEN];
//
//    while (getword(input) != NULL)
//        puts(input);
//    puts("Done.\n");
//
//    return 0;
//}
//
//char* getword(char* str)
//{
//    int ch;
//    char* orig = str;
//
//    while ((ch = getchar()) != EOF && !isspace(ch))
//        *str++ = ch;
//         *str = '\0';
//    if (ch == EOF)
//        return NULL;
//    else
//    {
//        while (ch != '\n')
//            ch = getchar();
//        return orig;
//    }
//}


/* Programming Exercise 11-4 */
//
//#include <stdio.h>
//#include <ctype.h>
//
//#define LEN 20
//
//char* getword(char* str ,int n);
//
//int main(void)
//{
//    char input[LEN];
//
//    while (getword(input,9) != NULL)
//        puts(input);
//    puts("Done.\n");
//
//    return 0;
//}
//
//char* getword(char* str ,int n)
//{
//    int ch,k=0;
//    char* orig = str;
//
//    while ((ch = getchar()) != EOF && !isspace(ch))
//    {
//        *str++ = ch;
//        k++;
//        *str = '\0';
//        if (k == 10)
//        {
//            printf("k=%d\n", k);
//            break;
//        }
//    }
//
//    if (ch == EOF)
//        return NULL;
//    else                     
//    {
//        while (ch != '\n')               /* 接下来的while循环是舍弃剩余的字符。*/
//        {
//            ch = getchar();
//        }
//        return orig;
//    }
//}


/* Programming Exercise 11-5 */
//
//#include <stdio.h>
//#define SIZE 80
//char* string_char(char* st, char c);
//
//int main(int argc, char* argv[]) 
//{
//    char source[SIZE];
//    char dest = ' ';
//    char* position;
//    printf("Enter a String: ");
//    fgets(source, SIZE, stdin);
//
//    while (dest != EOF)      /*注意，这里的dest为上一个dest的值，因此当取得新的dest值时，用if (dest == EOF)语句判断。*/
//    {
//
//        printf("Enter a char to find (EOF for Quit):");
//        while ((dest = getchar()) == '\n') 
//            continue;
//        if (dest == EOF)
//            break;
//        if((position = string_char(source, dest))!=NULL)
//           printf("Found the char %c in the %p\n",*position,position);
//        else
//           printf("Char %c not found. Try another?\n",dest);
//
//     }
//    puts("Done!\n");
//      return 0;
//  }
//  char* string_char(char* st, char c)
//  {
//     while(*st != '\0')
//     {
//
//        if(*st == c)
//           return st;
//
//        else
//           st++;
//
//     }
//     return NULL;
//  }


/* Programming Exercise 11-6 */
//
//#include <stdio.h>
//#include <string.h>
//
//#define LEN 80
//
//_Bool is_within(const char* str, char c);
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char input[LEN];
//    char ch;
//    int found;;
//
//    printf("Enter a string: ");
//    while (s_gets(input, LEN) && input[0] != '\0')
//    {
//        printf("Enter a character: ");
//        ch = getchar();
//        while (getchar() != '\n')     /* 舍弃getchar后面的字符。*/
//            continue;
//        found = is_within(input, ch);
//        if (found == 0)
//            printf("%c not found in string.\n", ch);
//        else
//            printf("%c found in string %s\n", ch, input);
//        printf("Next string: ");
//    }
//    puts("Done.\n");
//
//    return 0;
//}
//
//_Bool is_within(const char* str, char ch)
//{
//    while (*str != ch && *str != '\0')
//        str++;
//    return *str; /* = 0 if \0 reached, non-zero otherwise */
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    char* find;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        find = strchr(st, '\n'); // look for newline
//        if (find) // if the address is not NULL,
//            *find = '\0'; // place a null character there
//        else
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* Programming Exercise 11-7 */
//
//#include <stdio.h>
//#include <string.h>
//
//#define SIZE 80
//
//char* mystrncpy(char* dest, char* src, int n);
//
//int main(int argc, char* argv[]) 
//{
//    char destination[SIZE], source[SIZE];
//    int i = 0;
//    printf("Enter a String as s source (blank to quit.): ");
//    fgets(source, SIZE, stdin);
//    printf("Enter number of char you need to copy :");
//    scanf("%d", &i);
//   
//    while (*source != '\n') 
//    {
//        mystrncpy(destination, source, i);
//        printf("Done!\nNow the dest string is:");
//        puts(destination);
//        while (getchar() != '\n') 
//            break;
//
//        printf("Another? Enter a String as s source(blank to quit.): ");
//        fgets(source, SIZE, stdin);
//        if (*source == '\n')
//        {
//            puts("Done!\n");
//            break;
//        }
//        printf("Enter number of char you need to copy:");
//        scanf("%d", &i);
//    };
//    return 0;
//}
//
//char* mystrncpy(char* dest, char* src, int n) 
//{
//    int count = 0;
//    while (*src != '\0' && count < n) 
//    {
//        *(dest + count++) = *src++;
//    }
//
//    if (count < n) 
//    {
//        while (count < n)
//            *(dest + count++) = '\0';
//    }
//    *(dest + count) = '\0';
//    if (*dest == EOF)
//    {
//        return NULL;
//    }
//
//    return dest;
//}


/* Programming Exercise 11-8 */
//
//(1)
//#include <stdio.h>
//#include <string.h>
//
//#define LEN 20
//
//char* string_in(const char* s1, const char* s2);
//
//int main(void)
//{
//    char orig[LEN] = "transportation";
//    char* find;
//
//    printf("The contents of orig array are:");
//    puts(orig);
//    find = string_in(orig, "port");
//    if (find)
//    {
//        printf("Had been found(port):");
//        puts(find);
//    }
//    else
//        puts("Not found");
//    find = string_in(orig, "part");
//    if (find)
//        puts(find);
//    else
//        puts("Not found");
//
//    return 0;
//}
//
//char* string_in(const char* s1, const char* s2)
//{
//    int l2 = strlen(s2);
//    int tries; /* maximum number of comparisons */
//    int nomatch = 1; /* set to 0 if match is found */
//
//    tries = strlen(s1) + 1 - l2;
//    if (tries > 0)
//        while ((nomatch = strncmp(s1, s2, l2)) && tries--)
//            s1++;
//    if (nomatch)
//        return NULL;
//    else
//        return (char*)s1; /* cast const away */
//}


//(2)
//#include <stdio.h>
//#include <string.h>
//
//#define SIZE 80
//
//char* string_in(char* st, char* sub);
//
//int main(int argc, char* argv[]) 
//{
//    char main_string[SIZE], sub[SIZE];
//    char* p = NULL;
//    printf("Enter a String as main string (blank to quit.): ");
//    fgets(main_string, SIZE, stdin);
//    printf("Enter a sub string to find in main :");
//    fgets(sub, SIZE, stdin);
//    while (*main_string != '\n') 
//    {
//
//        p = string_in(main_string, sub);
//
//        printf("Done!\nNow the position of sub string is:");
//        printf("%p\n", p);
//        printf("Another? Enter a String as main string (blank to quit.): ");
//        fgets(main_string, SIZE, stdin);
//        printf("Enter a sub string to find in main :");
//        fgets(sub, SIZE, stdin);
//    };
//    return 0;
//}
//
//char* string_in(char* st, char* sub) 
//{
//    int count = 0;
//    int src_len = strlen(sub);
//    while (*st != '\0' && count < src_len) 
//    {
//
//        if (*(st + count) == *(sub + count)) 
//        {
//            count++;
//        }
//        else 
//        {
//            count = 0;
//            st++;
//        }
//    }
//    if(count == src_len) 
//        return st;
//    else 
//        return NULL;
//}


/* Programming Exercise 11-9 */
//
//#include <stdio.h>
//#include <string.h>
//
//#define SIZE 80
//
//char* invert_str(char* st, int n);
//
//int main(int argc, char* argv[])
//{
//    char test_string[SIZE];
//    char* p = NULL;
//    int k = 0;
//
//    printf("Enter a string (enter to quit.): ");
//    fgets(test_string, SIZE, stdin);
//    while (*test_string != '\n')
//    {
//        k = strlen(test_string)-1;
//        p = invert_str(test_string, k);
//        printf("Done!\nNow the invert string is :");
//        printf("%s\n", test_string);             /*执行完%s后，下一个printf会与其有一行空行，因为test_string
//                                                    本身存储着一个'\n'，再加上%s后的'\n'。*/
//        printf("Another? Enter a string (enter to quit.):");
//        fgets(test_string, SIZE, stdin);
//    };
//}
//
//char* invert_str(char* st, int n)
//{
//
//    int length = n;
//
//    char invert[SIZE] = { 0 };
//
//    for (int i = 0; i < length; i++)
//        *(invert + i) = *(st + length - 1 - i);
//
//    for (int i = 0; i < length; i++)
//        *(st + i) = *(invert + i);
//
//    return st;
//}


/* Programming Exercise 11-10 */
//
//(1) -- drop_space函数返回的是原来的orig函数，只是将其内的空格删除。
//#include <stdio.h>
//#include <string.h> // for strchr();
//#define LEN 81
//int drop_space(char* s);
//char* s_gets(char* st, int n);
//int main(void)
//{
//    char orig[LEN];
//
//    puts("Enter a string of 80 characters or less:");
//    while (s_gets(orig, LEN) && orig[0] != '\0')
//    {
//        drop_space(orig);
//        puts(orig);
//        puts("Enter next string (or just Enter to quit):");
//    }
//    puts("Bye!");
//    return 0;
//}
//int drop_space(char* s)
//{
//    char* pos;
//    while (*s) /* or while (*s != '\0') */
//    {
//        if (*s == ' ')
//        {
//            pos = s;
//            do
//            {
//                *pos = *(pos + 1);
//                pos++;
//            } while (*pos);
//        }
//        else
//            s++;
//    }
//
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    char* find;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        find = strchr(st, '\n'); // look for newline
//        if (find) // if the address is not NULL,
//            *find = '\0'; // place a null character there
//        else
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}

//(2) -- drop_space函数返回的是一个新的pos函数，其为将orig函数的空格删除，再将orig复制给pos.
//#include <stdio.h>
//#include <string.h> // for strchr();
//
//#define LEN 81
//
//char* drop_space(char* s);
//
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    char orig[LEN];
//
//    puts("Enter a string of 80 characters or less:");
//    while (s_gets(orig, LEN) && orig[0] != '\0')
//    {
//        drop_space(orig);
//        puts(orig);
//        puts("Enter next string (or just Enter to quit):");
//    }
//    puts("Bye!");
//    return 0;
//}
//char* drop_space(char* s)
//{
//    char* pos=s;
//   
//    for (; *s != '\0'; s++)
//    {
//        *pos = *s;
//        while (*s == ' ')
//        {
//            *pos = *(++s);
//        }
//        pos++;
//    }
//    *pos = '\0';
//    return pos;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    char* find;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        find = strchr(st, '\n'); // look for newline
//        if (find) // if the address is not NULL,
//            *find = '\0'; // place a null character there
//        else
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}


/* Programming Exercise 11-11 */
//
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define SIZE 80
//#define NUMBER 5
//
//void show_menu(void);
//void input_string(int number, char st[][SIZE]);
//void print_original(int number, char st[][SIZE]);
//void print_ascii(int number, char st[][SIZE]);
//void print_length(int number, char st[][SIZE]);
//void print_words(int number, char st[][SIZE]);
//void sort_order(int number, int order[][2]);
//int get_word_length(char* input);
//
//int main(int argc, char* argv[]) {
//    char test[NUMBER][SIZE];
//    int selected;
//    input_string(NUMBER, test);
//    show_menu();
//    scanf("%d", &selected);
//    while (selected != 5) 
//    {
//        switch (selected) 
//        {
//        case 1: print_original(NUMBER, test); break;
//        case 2: print_ascii(NUMBER, test); break;
//        case 3: print_length(NUMBER, test); break;
//        case 4: print_words(NUMBER, test); break;
//        case 5: break;
//        default:
//            printf("Error select, retry!\n");
//        }
//        show_menu();
//        scanf("%d", &selected);
//    }
//    printf("All done, bye.");
//}
//
//void show_menu() {
//    printf("==============================================================\n");
//    printf("1) print original strings.   2) print string by ascii order\n");
//    printf("3) printf string by length.  4) print string by word length\n");
//    printf("5) quit.\n");
//    printf("===============================================================\n");
//}
//void input_string(int number, char st[][SIZE]) 
//{
//
//    printf("Please input 5 strings serperate by enter.\n");
//    for(int i = 0;i< number ;i++)
//    {
//        fgets(st[i],SIZE,stdin);
//    }
//}
//void print_original(int number, char st[][SIZE])
//{
//
//    printf("print 5 strings in original mode.\n");
//    for(int i = 0;i< number ;i++)
//    {
//        printf("%d. %s",i+1,st[i]);
//    }
//}
//void print_ascii(int number, char st[][SIZE])
//{
//    printf("print 5 strings in ascii mode.\n");
//    int order[NUMBER][2];
//    for(int i = 0;i< number ;i++)
//    {
//
//    order[i][0] = i;
//    order[i][1] = st[i][0];
//    }
//
//sort_order(number, order);
//
//for(int i = 0;i < number ;i++)
//{
//
//    printf("ASCII No.%d. %s",i+1,st[order[i][0]]);
//}
//}
//void print_length(int number, char st[][SIZE])
//{
//    printf("print 5 strings in length mode.\n");
//    int order[NUMBER][2];
//    for(int i = 0;i< number ;i++)
//    {
//        order[i][0] = i;
//        order[i][1] = strlen( st[i]);
//    }
//
//    sort_order(number, order);
//
//    for(int i = 0;i < number ;i++)
//    {
//        printf("LENGTH No.%d. %s",i+1,st[order[i][0]]);
//    }
//}
//void print_words(int number, char st[][SIZE])
//{
//    printf("print 5 strings in words mode.\n");
//    int order[NUMBER][2];
//    for(int i = 0;i< number ;i++)
//    {
//        order[i][0] = i;
//        order[i][1] = get_word_length(st[i]);
//    }
//
//    sort_order(number, order);
//
//    for(int i = 0;i < number ;i++)
//    {
//        printf("WORDS No.%d. %s",i+1,st[order[i][0]]);
//    }
//}
//
//
//void sort_order(int number, int order[][2])
//{
//
//    int temp[2];
//    for(int i = 0;i< number-1 ;i++)
//    {
//        for(int j = 0  ;j < number -1-i ;j++)
//        {
//            if(order[j][1] > order[j+1][1])
//            {
//                temp[0] = order[j][0];
//                temp[1] = order[j][1];
//                order[j][0] = order[j+1][0];
//                order[j][1] = order[j+1][1];
//                order[j+1][0] = temp[0];
//                order[j+1][1] = temp[1];
//            }
//        }
//    }
//}
//
//int get_word_length(char *input)
//{
//
//    char *in = input;
//    int length = 0;
//    while(isalpha(*in) == 0) in++;
//
//while (isalpha(*in) != 0) 
//{
//    in++;
//    length++;
//}
//
//return length;
//}


/* Programming Exercise 11-12 */
//#include <stdio.h>
//#include <ctype.h>
//
//#define SIZE 256
//
//int check_words(char* input);
//int check_upper(char* input);
//int check_lower(char* input);
//int check_punct(char* input);
//int chech_digit(char* input);
//
//int main(int argc, char *argv[]) 
//{
//    char input[SIZE];
//    int i = 0;
//    while((input[i++] = getchar()) != EOF)
//    {
//        if( i >= SIZE )
//        {
//            printf("Over flowed.\n");
//            break;
//        }
//    }
//
//
//    printf("Hello you input complete.\nNow let's counting.\n");
//    printf("Input words %d.\n",check_words(input));
//    printf("Input upper char %d.\n",check_upper(input));
//    printf("Input loewer char %d.\n",check_lower(input));
//    printf("Input punct char %d.\n",check_punct(input));
//    printf("Input digital  %d.\n",chech_digit(input));
//
//
//}
//
//int check_words(char* input)
//{
//
//int count = 0;
//int start = 0;
//while (*input != EOF) 
//{
//    if (isalpha(*input) == 0 && start == 0) 
//    {
//        input++;
//    }
//    else if (isalpha(*input) == 0 && start == 1) 
//    {
//        input++;
//        count++;
//        start = 0;
//    }
//    else if (isalpha(*input) != 0) 
//    {
//        input++;
//        start = 1;
//    }
//}
//if (start == 1) count++;
//return count;
//}
//
//int check_upper(char* input) 
//{
//    int count = 0;
//    while (*input != EOF) 
//    {
//        if (isupper(*input++) != 0)
//            count++;
//    }
//    return count;
//}
//
//int check_lower(char* input) 
//{
//    int count = 0;
//    while (*input != EOF) 
//    {
//        if (islower(*input++) != 0)
//            count++;
//    }
//    return count;
//}
//
//int check_punct(char* input) 
//{
//    int count = 0;
//    while (*input != EOF) 
//    {
//        if (ispunct(*input++) != 0)
//            count++;
//    }
//    return count;
//}
//
//int chech_digit(char* input) 
//{
//    int count = 0;
//    while (*input != EOF) 
//    {
//        if (isdigit(*input++) != 0)
//            count++;
//    }
//    return count;
//}


/* Programming Exercise 11-13 */
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//#define SIZE 80
//
//int check_words(char* input);
//
//int main(int argc, char* argv[])
//{
//    char test_string[SIZE];
//    char* p = NULL;
//    char dy[SIZE] = { 0 };
//    int k = 0;
//
//    printf("Enter a string (enter to quit.): ");
//    fgets(test_string, SIZE, stdin);
//    while (*test_string != '\n')
//    {
//           k=check_words(test_string);
//           // printf("Done!\nNow the invert string is :\n");
//       // printf("Another? Enter a string (enter to quit.):");
//        fgets(test_string, SIZE, stdin);
//    };
//}
//
//int  check_words(char* input)
//{
//
//int count = 0;
//int start = 0;
//int numb = 0;   //记录单词长度
//int i = 0;
//int sd = 0;     //记录非单词长度
//int sh = 0;     //记录打印单词个数
//char arry[SIZE][SIZE] = { 0 };
//char* vc = input;
//char* xc = input;
//
//while (*input != EOF) 
//{
//
//    if (isalpha(*input) == 0 && start == 0) 
//    {
//        input++;
//        sd++;               //记录非单词长度
//        vc = (vc + numb+1);
//    }
//    else if (isalpha(*input) == 0 && start == 1) 
//    {
//        sd++;        //记录非单词长度
//        input++;      //下一个字符
//        count++;      //统计单词个数
//        start = 0;
//        strncpy(arry[i][SIZE], vc, numb);
//        numb = 0;
//        i++;
//
//    }
//    else if (isalpha(*input) != 0) 
//    {
//        input++;      //下一个字符
//        start = 1;
//        numb++;         //记录单词长度
//        sd = 0;
//    }
//}
//if (start == 1)
//{
//    count++;
//    strncpy(arry[i], vc, numb);
//}
//for (sh = 0; sh < count && i >=0; sh++)
//{
//    printf("%s\n",arry[i]);
//    i--;
//}
//return count;
//}


//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//#define SIZE 80
//
//int check_words(char* input);
//
//int main(int argc, char* argv[])
//{
//    char test_string[SIZE];
//    char* p = NULL;
//    char dy[SIZE] = { 0 };
//    int k = 0;
//
//    printf("Enter a string (enter to quit.): ");
//    fgets(test_string, SIZE, stdin);
//    while (*test_string != '\n')
//    {
//           k=check_words(test_string);
//           // printf("Done!\nNow the invert string is :\n");
//       // printf("Another? Enter a string (enter to quit.):");
//        fgets(test_string, SIZE, stdin);
//    };
//}
//
//int  check_words(char input[SIZE])
//{
//
//int count = 0;
//int start = 0;
//int numb = 0;   //记录单词长度
//int i = 0;
//int sh = 0;     //记录打印单词个数
//int we = 1;
//int as = 1;
//char arry[SIZE][SIZE] = { 0 };
//char* xc = input;
//char* vc = input;
//
//while (*input != EOF) 
//{
//
//    if (isalpha(*input) == 0 && start == 0) 
//    {
//        input++;
//        as = 2;
//    }
//    else if (isalpha(*input) == 0 && start == 1) 
//    {
//        if (we == 1)
//        {
//            strncpy(arry[i], xc, numb);
//        }
//        we = 0;
//        strncpy(arry[i], vc, numb);
//        input++;      //下一个字符
//        count++;      //统计单词个数
//        start = 0;
//        arry[i][numb] = '\0';
//        numb = 0;
//        as = 2;
//        i++;
//    }
//    else if (isalpha(*input) != 0) 
//    {
//        if (as == 2)
//        {
//            vc = input;
//        }
//        as = 1;
//        input++;      //下一个字符
//        start = 1;
//        numb++;         //记录单词长度
//        
//    }
//}
//if (start == 1)
//{
//    count++;
//    strncpy(arry[i], vc, numb);
//}
//for (;i >=0; i--)
//{
//    printf("%s\n",arry[i]);
//}
//return count;
//}

/* Programming Exercise 11-13 */
/*通过命令行输入参数*/
//#include <stdio.h>
//#include <stdlib.h>
//int main(int argc, char* argv[])
//{
//    int count;
//
//    for (count = argc - 1; count > 0; count--)
//        printf("%s ", argv[count]);
//    printf("\n");
//    return 0;
//}


/* Programming Exercise 11-14 */
/*命令行输入参数的方法：直接在命令行那里输入想输入的参数，每个参数之间留一个空格，如：2.0 3*/
//
//#include <stdio.h>
//#include <stdlib.h> /* for atof() */
//#include <math.h> /* for pow() */
//
//int main(int argc, char* argv[])
//{
//    double num, exp;
//
//    if (argc != 3)
//        printf("Usage: %s number exponent\n", argv[0]);
//    else
//    {
//        num = atof(argv[1]);
//        exp = atof(argv[2]);
//        printf("%f to the %f power = %g\n", num, exp, pow(num, exp));
//    }
//
//    return 0;
//}


/* Programming Exercise 11-15 */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//int go_atoi(char* ptr);
//
//int main()
//{
//    char a[50];
//    printf("字符串输入：\n");
//    gets(a);
//    printf("数字输出：\n");
//    printf("%d\n", go_atoi(a));
//    return 0;
//}
//
//int go_atoi(char* ptr) 
//{
//    int i = 0;
//    int ten_power = 1;
//    int sum = 0;
//    while (ptr[i] != '\0') 
//    {
//        if (!isdigit(ptr[i]))
//        {
//            return 0;     //检查从头到尾有没有非数字，记得不要用fget，
//                         //fget会录入回车
//        }
//        i++;
//    }
//    i--;         //这里的i--是最后一个数字（个位）的下标
//    sum = ptr[i] - '0';      //把个位加给sum , 数字字符的ASCII码在48-57之间
//    while (--i >= 0)
//    {
//        ten_power *= 10;   // i每次减1都升位
//        sum += (ptr[i] - '0') * ten_power;//百位乘百，千位乘千，加给sum
//    }
//    return sum;
//}


/* Programming Exercise 11-16 */
//
//#include <stdio.h>
//#include <ctype.h>
//
//int main(int argc, char* argv[])
//{
//    char mode = 'p';
//    int ok = 1;
//    int ch;
//
//    if (argc > 2)
//    {
//        printf("Usage: %s [-p | -u | -l]\n", argv[0]);
//        ok = 0; /* skip processing input */
//    }
//    else if (argc == 2)
//    {
//        if (argv[1][0] != '-')
//        {
//            printf("Usage: %s [-p | -u | -l]\n", argv[0]);
//            ok = 0;
//        }
//        else
//            switch (argv[1][1])
//            {
//            case 'p':
//            case 'u':
//            case 'l': mode = argv[1][1];
//                break;
//            default: printf("%s is an invalid flag; ", argv[1]);
//                printf("using default flag (-p).\n");
//            }
//    }
//
//    if (ok)
//        while ((ch = getchar()) != EOF)
//        {
//            switch (mode)
//            {
//            case 'p': putchar(ch);
//                break;
//            case 'u': putchar(toupper(ch));
//                break;
//            case 'l': putchar(tolower(ch));
//            }
//        }
//
//    return 0;
//}





















































