#define _CRT_SECURE_NO_WARNINGS 1

/* 程序清单14.1 -- book.c -- one-book inventory */
//
//#include <stdio.h>
//#include <string.h>
//
//char* s_gets(char* st, int n);
//
//#define MAXTITL  41      /* maximum length of title + 1         */
//#define MAXAUTL  31      /* maximum length of author's name + 1 */
//
//struct book {            /* structure template: tag is book     */
//    char title[MAXTITL];
//    char author[MAXAUTL];
//    float value;
//};                       /* end of structure template           */
//
//int main(void)
//{
//    struct book library; /* declare library as a book variable  */
//
//    printf("Please enter the book title.\n");
//    s_gets(library.title, MAXTITL); /* access to the title portion         */
//    printf("Now enter the author.\n");
//    s_gets(library.author, MAXAUTL);
//    printf("Now enter the value.\n");
//    scanf("%f", &library.value);
//    printf("%s by %s: $%.2f\n", library.title,
//        library.author, library.value);
//    printf("%s: \"%s\" ($%.2f)\n", library.author,
//        library.title, library.value);
//    printf("Done.\n");
//
//    return 0;
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
//        find = strchr(st, '\n');   // look for newline
//        if (find)                  // if the address is not NULL,
//            *find = '\0';          // place a null character there
//        else
//            while (getchar() != '\n')
//                continue;          // dispose of rest of line
//    }
//    return ret_val;
//}


/* 程序清单14.2 -- manybook.c -- multiple book inventory */
//
//#include <stdio.h>
//#include <string.h>
//
//char* s_gets(char* st, int n);
//
//#define MAXTITL   40
//#define MAXAUTL   40
//#define MAXBKS   100              /* maximum number of books  */
//
//struct book 
//{                     /* set up book template     */
//    char title[MAXTITL];
//    char author[MAXAUTL];
//    float value;
//};
//
//int main(void)
//{
//    struct book library[MAXBKS]; /* array of book structures */
//    int count = 0;
//    int index;
//
//    printf("Please enter the book title.\n");
//    printf("Press [enter] at the start of a line to stop.\n");
//    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
//        && library[count].title[0] != '\0')
//    {
//        printf("Now enter the author.\n");
//        s_gets(library[count].author, MAXAUTL);
//        printf("Now enter the value.\n");
//        scanf("%f", &library[count++].value);
//        while (getchar() != '\n')
//            continue;          /* clear input line         */
//        if (count < MAXBKS)
//            printf("Enter the next title.\n");
//    }
//
//    if (count > 0)
//    {
//        printf("Here is the list of your books:\n");
//        for (index = 0; index < count; index++)
//            printf("%s by %s: $%.2f\n", library[index].title,
//                library[index].author, library[index].value);
//    }
//    else
//        printf("No books? Too bad.\n");
//
//    return 0;
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
//        find = strchr(st, '\n');   // look for newline
//        if (find)                  // if the address is not NULL,
//            *find = '\0';          // place a null character there
//        else
//            while (getchar() != '\n')
//                continue;          // dispose of rest of line
//    }
//    return ret_val;
//}


/* 程序清单14.3 -- friend.c -- example of a nested structure */
//
//#include <stdio.h>
//
//#define LEN 20
//
//const char * msgs[5] =
//{
//    "    Thank you for the wonderful evening, ",
//    "You certainly prove that a ",
//    "is a special kind of guy. We must get together",
//    "over a delicious ",
//    " and have a few laughs"
//};
//
//struct names {                     // first structure
//    char first[LEN];
//    char last[LEN];
//};
//
//struct guy {                       // second structure
//    struct names handle;           // nested structure
//    char favfood[LEN];
//    char job[LEN];
//    float income;
//};
//
//int main(void)
//{
//    struct guy fellow = {   // initialize a variable
//        { "Ewen", "Villard" },
//        "grilled salmon",
//        "personality coach",
//        68112.00
//    };
//    
//    printf("Dear %s, \n\n", fellow.handle.first);
//    printf("%s%s.\n", msgs[0], fellow.handle.first);
//    printf("%s%s\n", msgs[1], fellow.job);
//    printf("%s\n", msgs[2]);
//    printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
//    if (fellow.income > 150000.0)
//        puts("!!");
//    else if (fellow.income > 75000.0)
//        puts("!");
//    else
//        puts(".");
//    printf("\n%40s%s\n", " ", "See you soon,");
//    printf("%40s%s\n", " ", "Shalala");
//    
//    return 0;
//}


/* 程序清单14.4 -- friends.c -- uses pointer to a structure */
//
//#include <stdio.h>
//
//#define LEN 20
//
//struct names {
//    char first[LEN];
//    char last[LEN];
//};
//
//struct guy {
//    struct names handle;
//    char favfood[LEN];
//    char job[LEN];
//    float income;
//};
//
//int main(void)
//{
//    struct guy fellow[2] = {
//        {{ "Ewen", "Villard"},
//            "grilled salmon",
//            "personality coach",
//            68112.00
//        },
//        {{"Rodney", "Swillbelly"},
//            "tripe",
//            "tabloid editor",
//            432400.00
//        }
//    };
//    struct guy* him;    /* here is a pointer to a structure */
//
//    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
//    him = &fellow[0];    /* tell the pointer where to point  */
//    printf("pointer #1: %p #2: %p\n", him, him + 1);
//    printf("him->income is $%.2f: (*him).income is $%.2f\n",
//        him->income, (*him).income);
//    him++;               /* point to the next structure      */
//    printf("him->favfood is %s:  him->handle.last is %s\n",
//        him->favfood, him->handle.last);
//
//    return 0;
//}


/* 提醒：当参数是一个结构时，是(3)中的moolah.bankfund;
         当参数是一个指针时，是(2)中的money->bankfund. 
         即在运用结构时，原型用"  . ",指针用" -> ". */

/* 程序14.5 ——14.7为一组，请参考三种不同的方法。*/

/* 程序清单14.5 -- funds1.c -- passing structure members as arguments */
//
//#include <stdio.h>
//
//#define FUNDLEN 50
//
//struct funds 
//{
//    char   bank[FUNDLEN];
//    double bankfund;
//    char   save[FUNDLEN];
//    double savefund;
//};
//
//double sum(double, double);
//
//int main(void)
//{
//    struct funds stan = 
//    {
//        "Garlic-Melon Bank",
//        4032.27,
//        "Lucky's Savings and Loan",
//        8543.94
//    };
//
//    printf("Stan has a total of $%.2f.\n",
//        sum(stan.bankfund, stan.savefund));
//
//    return 0;
//}
//
///* adds two double numbers */
//double sum(double x, double y)
//{
//    return(x + y);
//}


/* 程序清单14.6 -- funds2.c -- passing a pointer to a structure */
//
//#include <stdio.h>
//
//#define FUNDLEN 50
//
//struct funds 
//{
//    char   bank[FUNDLEN];
//    double bankfund;
//    char   save[FUNDLEN];
//    double savefund;
//};
//
//double sum(const struct funds*);  /* argument is a pointer */
//
//int main(void)
//{
//    struct funds stan = 
//    {
//        "Garlic-Melon Bank",
//        4032.27,
//        "Lucky's Savings and Loan",
//        8543.94
//    };
//
//    printf("Stan has a total of $%.2f.\n", sum(&stan));
//
//    return 0;
//}
//
//double sum(const struct funds* money)
//{
//    return(money->bankfund + money->savefund);
//}


/* 程序清单14.7 -- funds3.c -- passing a structure */
//
//#include <stdio.h>
//
//#define FUNDLEN 50
//
//struct funds 
//{
//    char   bank[FUNDLEN];
//    double bankfund;
//    char   save[FUNDLEN];
//    double savefund;
//};
//
//double sum(struct funds moolah);  /* argument is a structure */
//
//int main(void)
//{
//    struct funds stan = 
//    {
//        "Garlic-Melon Bank",
//        4032.27,
//        "Lucky's Savings and Loan",
//        8543.94
//    };
//
//    printf("Stan has a total of $%.2f.\n", sum(stan));
//
//    return 0;
//}
//
//double sum(struct funds moolah)
//{
//    return(moolah.bankfund + moolah.savefund);
//}