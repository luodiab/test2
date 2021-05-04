#define _CRT_SECURE_NO_WARNINGS 1

/* �����嵥11.1 --  strings1.c */
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


/* �����嵥11.2 -- strptr.c -- strings as pointers -- ע�⣺��"space farers"ǰ���ϡ�*���ţ��൱�ڡ�*arry[]'
                                                            "space farers"�൱����������*/
//
//#include <stdio.h>
//
//int main(void)
//{
//    printf("%s, %p, %c\n", "We", "are", *"space farers");
//    printf("%c", *"apace farers" + 2);    //�൱��a��ֵ����2��
//    printf("%c", *("apace farers" + 2));  //�൱�ڵ�����Ԫ�ص�ֵ��("apace farers" + 2)Ϊ������Ԫ�صĵ�ַ��
//
//    return 0;
//


/* �����嵥11.3 -- addresses.c  -- addresses of strings */
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


/* �����嵥11.4 -- arrchar.c -- array of pointers, array of strings */
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


/* �����嵥11.5 -- p_and_s.c -- pointers and strings */
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
//        mesg, &mesg, mesg);                       /*ע�⣺const char* mesg = "Don't be a fool!"��
//                                                          printf("%c", *"apace farers" + 2)��ͬ��
//                                                          ǰһ������ǡ�%s������һ������ǡ�%c'��*/
//
//    printf("copy = %s; &copy = %p; value = %p\n",
//        copy, &copy, copy);
// 
//    return 0;
//}


/* �����嵥11.6 -- getsputs.c  -- using gets() and puts() */
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


/* �����嵥11.7 -- fgets1.c  -- using fgets() and fputs() */
/*ע�⣺puts���ں��油��һ����\n����fputs�򲻻�*/
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