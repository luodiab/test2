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


/* 程序清单14.8 -- names1.c -- uses pointers to a structure */
//
//#include <stdio.h>
//#include <string.h>
//
//#define NLEN 30
//
//struct namect 
//{
//    char fname[NLEN];
//    char lname[NLEN];
//    int letters;
//};
//
//void getinfo(struct namect*);
//void makeinfo(struct namect*);
//void showinfo(const struct namect*);
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    struct namect person;
//
//    getinfo(&person);
//    makeinfo(&person);
//    showinfo(&person);
//    return 0;
//}
//
//void getinfo(struct namect* pst)
//{
//    printf("Please enter your first name.\n");
//    s_gets(pst->fname, NLEN);
//    printf("Please enter your last name.\n");
//    s_gets(pst->lname, NLEN);
//}
//
//void makeinfo(struct namect* pst)
//{
//    pst->letters = strlen(pst->fname) +
//        strlen(pst->lname);
//}
//
//void showinfo(const struct namect* pst)
//{
//    printf("%s %s, your name contains %d letters.\n",
//        pst->fname, pst->lname, pst->letters);
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
//
//    return ret_val;
//}


/* 程序清单14.9 -- names2.c -- passes and returns structures */
//
//#include <stdio.h>
//#include <string.h>
//
//#define NLEN 30
//
//struct namect 
//{
//    char fname[NLEN];
//    char lname[NLEN];
//    int letters;
//};
//
//struct namect getinfo(void);
//struct namect makeinfo(struct namect);
//void showinfo(struct namect);
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    struct namect person;
//
//    person = getinfo();
//    person = makeinfo(person);
//    showinfo(person);
//
//    return 0;
//}
//
//struct namect getinfo(void)
//{
//    struct namect temp;
//    printf("Please enter your first name.\n");
//    s_gets(temp.fname, NLEN);
//    printf("Please enter your last name.\n");
//    s_gets(temp.lname, NLEN);
//
//    return temp;
//}
//
//struct namect makeinfo(struct namect info)
//{
//    info.letters = strlen(info.fname) + strlen(info.lname);
//
//    return info;
//}
//
//void showinfo(struct namect info)
//{
//    printf("%s %s, your name contains %d letters.\n",
//        info.fname, info.lname, info.letters);
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
//
//    return ret_val;
//}


/* 程序清单14.10 -- names3.c -- use pointers and malloc() */
//
//#include <stdio.h>
//#include <string.h>   // for strcpy(), strlen()
//#include <stdlib.h>   // for malloc(), free()
//
//#define SLEN 81
//
//struct namect 
//{
//    char * fname;  // using pointers
//    char * lname;
//    int letters;
//};
//
//void getinfo(struct namect *);        // allocates memory
//void makeinfo(struct namect *);
//void showinfo(const struct namect *);
//void cleanup(struct namect *);        // free memory when done
//char * s_gets(char * st, int n);
//
//int main(void)
//{
//    struct namect person;
//    
//    getinfo(&person);
//    makeinfo(&person);
//    showinfo(&person);
//    cleanup(&person);
//    
//    return 0;
//}
//
//void getinfo (struct namect * pst)
//{
//    char temp[SLEN];
//    printf("Please enter your first name.\n");
//    s_gets(temp, SLEN);
//    // allocate memory to hold name
//    pst->fname = (char *) malloc(strlen(temp) + 1);
//    // copy name to allocated memory
//    strcpy(pst->fname, temp);
//    printf("Please enter your last name.\n");
//    s_gets(temp, SLEN);
//    pst->lname = (char *) malloc(strlen(temp) + 1);
//    strcpy(pst->lname, temp);
//}
//
//void makeinfo (struct namect * pst)
//{
//    pst->letters = strlen(pst->fname) +
//    strlen(pst->lname);
//}
//
//void showinfo (const struct namect * pst)
//{
//    printf("%s %s, your name contains %d letters.\n",
//           pst->fname, pst->lname, pst->letters);
//}
//
//void cleanup(struct namect * pst)
//{
//    free(pst->fname);
//    free(pst->lname);
//}
//
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//    char * find;
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
//
//    return ret_val;
//}


/* 程序清单14.11 -- complit.c -- compound literals */
//
//#include <stdio.h>
//
//#define MAXTITL  41
//#define MAXAUTL  31
//
//struct book    // structure template: tag is book
//{          
//    char title[MAXTITL];
//    char author[MAXAUTL];
//    float value;
//};
//
//int main(void)
//{
//    struct book readfirst;
//    int score;
//
//    printf("Enter test score: ");
//    scanf("%d", &score);
//
//    if (score >= 84)
//        readfirst = (struct book){ "Crime and Punishment",
//            "Fyodor Dostoyevsky",
//            11.25 };
//    else
//        readfirst = (struct book){ "Mr. Bouncy's Nice Hat",
//            "Fred Winsome",
//            5.99 };
//    printf("Your assigned reading:\n");
//    printf("%s by %s: $%.2f\n", readfirst.title,
//        readfirst.author, readfirst.value);
//
//    return 0;
//}


/* 程序清单14.12 -- flexmemb.c -- flexible array member (C99 feature) */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct flex
//{
//    size_t count;
//    double average;
//    double scores[];   // flexible array member
//};
//
//void showFlex(const struct flex* p);
//
//int main(void)
//{
//    struct flex* pf1, * pf2;
//    int n = 5;
//    int i;
//    int tot = 0;
//
//    // allocate space for structure plus array
//    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
//    pf1->count = n;
//    for (i = 0; i < n; i++)
//    {
//        pf1->scores[i] = 20.0 - i;
//        tot += pf1->scores[i];
//    }
//    pf1->average = tot / n;
//    showFlex(pf1);
//
//    n = 9;
//    tot = 0;
//    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
//    pf2->count = n;
//    for (i = 0; i < n; i++)
//    {
//        pf2->scores[i] = 20.0 - i / 2.0;
//        tot += pf2->scores[i];
//    }
//    pf2->average = tot / n;
//    showFlex(pf2);
//    free(pf1);
//    free(pf2);
//
//    return 0;
//}
//
//void showFlex(const struct flex* p)
//{
//    int i;
//    printf("Scores : ");
//    for (i = 0; i < p->count; i++)
//        printf("%g ", p->scores[i]);
//    printf("\nAverage: %g\n", p->average);
//}


/* 程序清单14.13 -- funds4.c -- passing an array of structures to a function */
//
//#include <stdio.h>
//
//#define FUNDLEN 50
//#define N 2
//
//struct funds 
//{
//    char   bank[FUNDLEN];
//    double bankfund;
//    char   save[FUNDLEN];
//    double savefund;
//};
//
//double sum(const struct funds money[], int n);
//
//int main(void)
//{
//    struct funds jones[N] = {
//        {
//            "Garlic-Melon Bank",
//            4032.27,
//            "Lucky's Savings and Loan",
//            8543.94
//
//        },
//        {
//            "Honest Jack's Bank",
//            3620.88,
//            "Party Time Savings",
//            3802.91
//        }
//    };
//
//    printf("The Joneses have a total of $%.2f.\n",
//        sum(jones, N));
//
//    return 0;
//}
//
//double sum(const struct funds money[], int n)
//{
//    double total;
//    int i;
//
//    for (i = 0, total = 0; i < n; i++)
//        total += money[i].bankfund + money[i].savefund;
//
//    return(total);
//}


/* 程序清单14.14 -- booksave.c -- saves structure contents in a file */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAXTITL  40
//#define MAXAUTL  40
//#define MAXBKS   10             /* maximum number of books */
//
//char* s_gets(char* st, int n);
//
//struct book {                   /* set up book template    */
//    char title[MAXTITL];
//    char author[MAXAUTL];
//    float value;
//};
//
//int main(void)
//{
//    struct book library[MAXBKS]; /* array of structures     */
//    int count = 0;
//    int index, filecount;
//    FILE* pbooks;
//    int size = sizeof(struct book);
//
//    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
//    {
//        fputs("Can't open book.dat file\n", stderr);
//        exit(1);
//    }
//
//    rewind(pbooks);            /* go to start of file     */
//    while (count < MAXBKS && fread(&library[count], size,
//        1, pbooks) == 1)
//    {
//        if (count == 0)
//            puts("Current contents of book.dat:");
//        printf("%s by %s: $%.2f\n", library[count].title,
//            library[count].author, library[count].value);
//        count++;
//    }
//    filecount = count;
//    if (count == MAXBKS)
//    {
//        fputs("The book.dat file is full.", stderr);
//        exit(2);
//    }
//
//    puts("Please add new book titles.");
//    puts("Press [enter] at the start of a line to stop.");
//    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
//        && library[count].title[0] != '\0')
//    {
//        puts("Now enter the author.");
//        s_gets(library[count].author, MAXAUTL);
//        puts("Now enter the value.");
//        scanf("%f", &library[count++].value);
//        while (getchar() != '\n')
//            continue;                /* clear input line  */
//        if (count < MAXBKS)
//            puts("Enter the next title.");
//    }
//
//    if (count > 0)
//    {
//        puts("Here is the list of your books:");
//        for (index = 0; index < count; index++)
//            printf("%s by %s: $%.2f\n", library[index].title,
//                library[index].author, library[index].value);
//        fwrite(&library[filecount], size, count - filecount,
//            pbooks);
//    }
//    else
//        puts("No books? Too bad.\n");
//
//    puts("Bye.\n");
//    fclose(pbooks);
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
//
//    return ret_val;
//}
