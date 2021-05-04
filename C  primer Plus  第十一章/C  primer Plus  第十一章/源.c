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