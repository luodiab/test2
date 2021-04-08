#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//程序清单7.1 -- colddays.c -- 找出0度以下的天数占总天数的百分比
//
//int main()
//{
//	const int FREEZING = 0;
//	float temperature;
//	int cold_days = 0;
//	int all_days = 0;
//
//	printf("Enter the list of daily low temperatures.\n");
//	printf("Use Celsius,and enter q to quit.\n");
//	while (scanf("%f", &temperature) == 1)
//	{
//		all_days++;
//		if (temperature < FREEZING)
//			cold_days++;
//	}
//	if (all_days != 0)
//		printf("%d days total : %.1f%% were below freezing.\n", all_days, 100.0 * (float)cold_days / all_days);
//	if (all_days == 0)
//		printf("No data enter!\n");
//	return 0;
//}


//程序清单7.2 -- cypher1.c -- 更改输入，空格不变
//
//#define SPACE ' '
//int main()
//{
//	char ch;
//
//	ch = getchar();    //读取一个字符
//	while (ch != '\n')    //当一行未结束时
//	{
//		if (ch == SPACE)   //留下空格
//			putchar(ch);       //该字符不变
//			else
//			putchar(ch + 1);  //改变其他字符
//			ch = getchar();   //获取下一个字符
//	}
//	putchar(ch);     //打印换行符
//
//	return 0;
//}


//程序清单7.3 -- cypher2.c -- 更改输入，空格不变
//
//#include<ctype.h>       //包含isalpha()的函数原型
//int main()
//{
//	char ch;
//
//	while ((ch =getchar())!='\n ')    //当一行未结束时
//	{
//		if (isalpha(ch))   //如果是一个字符
//			putchar(ch+1);       //显示该字符的下一个字符
//			else              //否则
//			putchar(ch);  //原样显示
//	}
//	putchar(ch);     //显示换行符
//	return 0;
//}


//程序清单7.4 -- electric.c -- 计算电费
//
//#define RATE1 0.13230    //首次使用360kwh的费率
//#define RATE2 0.15040    //接着再使用108kwh的费率
//#define RATE3 0.30025    //接着再使用252kwh的费率
//#define RATE4 0.34025    //使用超过720kwh的费率
//#define BREAK1 360.0     //费率的第1个分界点
//#define BREAK2 468.0     //费率的第2个分界点
//#define BREAK3 720.0     //费率的第3个分界点
//#define BASE1 (RATE1*BREAK1)                           //使用360keh的费用
//#define BASE2 (RATE1+(RATE2*(BREAK2-BREAK1)))          //使用468keh的费用
//#define BASE3 (RATE2+(RATE3*(BREAK3-BREAK2)))          //使用720keh的费用
//int main()
//{
//	double kwh;        //使用的千瓦时
//	double bill;       //电费
//
//	printf("please enter the kwh used.\n");
//	scanf("%lf", &kwh);             
//	if (kwh <= BREAK1)
//		bill = RATE1 * kwh;
//	else if (kwh <= BREAK2)             //360~~468 kwh
//		bill = BASE1 + (RATE2 * (kwh - BREAK1));
//	else if (kwh <= BREAK3)              //468~~4720 kwh
//	{
//		bill = BASE2 + (RATE3 * (kwh - BREAK2));
//		printf("%1.2f\n", BASE2);
//	}
//	else                                 //超过 720 kwh
//		bill = BASE3 + (RATE4 * (kwh - BREAK3));
//	printf("The charge for %.1f kwh is $%1.2f.\n", kwh, bill);
//
//	return 0;
//}


//程序清单7.5 -- divisors.c -- 使用嵌套if语句显示一个数的约数/判断一个数是否为素数
//
//int main()
//{
//	unsigned long num;      //待测试的数
//	unsigned long div;      //可能的约数
//	bool isPrime;           //素数标记
//
//	printf("Please enter an integer for analysis:\n");
//	printf("Enter q to quit.\n");
//	while (scanf("%lu", &num) == 1)
//	{
//		for (div = 2, isPrime = true; (div * div) <= num; div++)
//		{
//			if (num % div == 0)
//			{
//				if ((div * div) != 0)
//					printf("%lu is divisible by %lu and %1u.\n", num, div, num / div);
//				else
//					printf("%lu is divisible by %lu.\n", num, div);
//				isPrime = false;    //该数不是素数
//			}
//		}
//		if (isPrime)
//			printf("%lu is prime.\n", num);
//		printf("Please enter another integer for analysis:");
//		printf("Enter q to quit.\n");
//	}
//	printf("Bye.\n");
//
//	return 0;
//}


//程序清单7.6 -- chcount.c -- 使用逻辑与运算符
//
//#define PERIOD '.'
//int main()
//{
//	char ch;
//	int charcount = 0;
//
//	while ((ch = getchar()) != PERIOD)
//	{
//		if (ch != '"' && ch != '\'')
//			charcount++;
//	}
//	printf("There are %dnon-quote characters.\n", charcount);
//
//	return 0;
//}


//程序清单7.6 -- chcount.c -- 使用逻辑与运算符(使用<iso646.h>头文件）
//
//#include <iso646.h>      //可以将“&&”改为“and";"||"改为"or";"!"改为"not".
//#define PERIOD '.'
//int main()
//{
//	char ch;
//	int charcount = 0;
//
//	while ((ch = getchar()) != PERIOD)
//	{
//		if (ch != '"' and ch != '\'')
//			charcount++;
//	}
//	printf("There are %dnon-quote characters.\n", charcount);
//
//	return 0;
//}


//程序清单7.7 -- wordcnt.c -- 统计字符数、单词数、行数
//
//#include <ctype.h>      //为 isspace()函数提供原型
//#include <stdbool.h>    //为 bool、true、false 提供模型
//#define STOP '|'
//int main()
//{
//	char c;      //读入字符
//	char prev;   //读入的前一个字符
//	long n_chars = 0L;    //字符数
//	int n_lines = 0;      //行数
//	int n_words = 0;      //单词数
//	int p_lines = 0;      //不完整的行数
//	bool inword = false;   //如果 c 在单词中，inword 等于 true
//
//	printf("Enter text to be analyzed( | to terminate):\n");
//	prev = '\n';        //用于识别完整的行
//	while ((c = getchar()) != STOP)
//	{
//		n_chars++;    //统计字符
//		if (c == '\n')
//			n_lines++;   //统计行
//		if (!isspace(c) && !inword)
//		{
//			inword = true;     //开始一个新的单词
//			n_words++;         //统计单词
//		}
//		if (isspace(c) && inword)
//			inword = false;      //达到单词的末尾
//		prev = c;                //保存字符的值
//	}
//
//	if (prev != '\n')
//		p_lines = 1;
//	printf("characters=%ld,words=%d,lines=%d,",
//		n_chars, n_words, n_lines);
//	printf("partial lines=%d\n", p_lines);
//	return 0;
//}


//程序清单7.8 -- paint.c -- 使用条件运算符（？：）
//
//#define COVERAGE 350       //每罐油漆可刷的面积
//int main()
//{
//	int sq_feet;
//	int cans;
//
//	printf("Enter number of square feet to be painted:\n");
//	while (scanf("%d", &sq_feet) == 1)
//	{
//		cans = sq_feet / COVERAGE;
//		cans += (sq_feet % COVERAGE == 0) ? 0 : 1;
//		printf("You need %d %s of paint.\n", cans,
//			cans == 1 ? "can" : "cans");
//		printf("Enter next value (q to quit):\n");
//	}
//	return 0;
//}


//程序清单7.9 -- skippart.c -- 使用continue跳过部分循环
//
//int main()
//{
//	const float MIN = 0.0f;
//	const float MAX = 100.0f;
//
//	float score;
//	float total = 0.0f;
//	int n = 0;
//	float min = MAX;
//	float max = MIN;
//
//	printf("Enter the first score (q to quit):");
//	while (scanf("%f", &score) == 1)
//	{
//		if (score<MIN || score>MAX)
//		{
//			printf("%0.lf is an invalid value. Try again: ", score);
//			continue;
//		}
//		printf("Accepting %0.lf:\n", score);
//		min = (score < min) ? score : min;
//		max = (score > max) ? score : max;
//		total += score;
//		n++;
//		printf("Enter next score (q to quit):");
//	}
//	if (n > 0)
//	{
//		printf("Average of %d scores is %0.lf.\n", n, total/n);
//		printf("low=%0.1f,high=%0.lf\n", min, max);
//	}
//	else
//		printf("No valid scores were entered.\n");
//	return 0;
//}


//程序清单7.10 -- break.c -- 使用 break 退出循环
//
//int main()
//{
//	float length, width;
//
//	printf("Enter the length of the rectangle:\n");
//	while (scanf("%f", &length) == 1)
//	{
//		printf("length=%0.2f:\n", length);
//		printf("Enter its width:\n");
//		if (scanf("%f", &width) != 1)
//		{
//			break;
//		}
//		printf("Width=%0.2f:\n", width);
//		printf("Area=%0.2f:\n", length*width);
//		printf("Enter the length of the rectangle:\n");
//	}
//	printf("Done.\n");
//	return 0;
//}


//程序清单7.11 -- animals.c -- 使用 switch 语句
//
//#include <ctype.h>
//int main()
//{
//	char ch;
//
//	printf("Give me a letter of the alphabet,and I will qive ");
//	printf("an animal name\nbeginning with that letter.\n ");
//	printf("please type in a letter;type # to end my act.\n");
//	while ((ch = getchar()) != '#')
//	{
//		if ('\n' == ch)
//			continue;
//		if (islower(ch))     //只接受小写字母
//			switch (ch)
//			{
//			case 'a':
//				printf("argali,a wild sheep of Asia\n");
//				break;
//			case 'b':
//				printf("babirusa,a wild pig of Malay\n");
//				break;
//			case 'c':
//				printf("coati,racoonlike mammal\n");
//				break;
//			case 'd':
//				printf("desman,aquatic,molelike critter\n");
//				break;
//			case 'e':
//				printf("echinda,the spiny anteater\n");
//				break;
//			case 'f':
//				printf("fisher,brownish marten\n");
//				break;
//			default:
//				printf("That's a stumper!\n");
//			}
//		else
//			printf("I recognize only lowercase letters.\n");
//		while (getchar() != '\n')
//			continue;
//		printf("Please type another letter or a #.\n");
//	}
//	printf("Bye!\n");
//
//	return 0;
//}


//程序清单7.12 -- vowels.c -- 使用多重标签
//
//int main()
//{
//	char ch;
//	int a_ct, e_ct, i_ct, o_ct, u_ct;
//
//	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
//
//	printf("Enter some text; enter # to quit.\n");
//	while ((ch = getchar()) != '#')
//	{
//		switch (ch)
//		{
//		case 'a':
//		case 'A':
//			a_ct++;
//			break;
//		case 'e':
//		case 'E':
//			e_ct++;
//			break;
//		case 'i':
//		case 'I':
//			i_ct++;
//			break;
//		case 'o':
//		case 'O':
//			o_ct++;
//			break;
//		case 'u':
//		case 'U':
//			u_ct++;
//			break;
//		default:
//			break;
//		}
//	}
//	printf("number of vowels:   A      E      I     O     U\n");
//	printf("                 %4d   %4d   %4d  %4d  %4d\n",
//		a_ct, e_ct, i_ct, o_ct, u_ct);
//	return 0;
//}


//编程练习--Chapter	7 Programming	Exercises

/* Programming Exercise 7-1 */
//
//int main()
//{
//	int c;     //输入的字符
//	int N_spaces =0, L_spaces =0, A_spaces = 0;
//
//	printf("Please type the character yoy want to type(enter # to quit)\n");
//	while ((c = getchar()) != '#')
//	{
//		if (c == ' ')
//		{
//			N_spaces++;     //统计空格数
//		}
//		if (c == '\n')
//		{
//			L_spaces++;     //统计换行数
//		}
//		if (c !=' '&&c!='\n')
//		{
//			A_spaces++;     //统计其它字符数
//		}
//	}
//	printf("N_spaces=%d   L_spaces=%d    A_spaces=%d\n", N_spaces, L_spaces, A_spaces);
//	return 0;
//}


/* Programming Exercise 7-2 */
//
//int main()
//{
//	int c;         //输入字符元素
//	int spaces = 0;      //统计输入字符的个数
//
//	printf("Please type the character yoy want to type(enter # to quit)\n");
//	while ((c = getchar()) != '#')
//	{
//		printf("%c-%d ", c, c);
//		spaces++;
//		if (spaces % 8 == 0)
//		{
//			printf("\n");
//		}
//	}
//	return 0;
//}


/* Programming Exercise 7-3 */
//
//#define ASD 100
//int main()
//{
//	int T_numbers = 0, O_numbers = 0, sum1 = 0, sum2 = 0;
//	int c=0;
//	int arry1[ASD] = { 0 }, arry2[ASD] = { 0 };
//	float average1, average2;
//
//	printf("Please type the character yoy want to type:");
//	while (scanf("%d", &c) != EOF)
//	{
//		if (c == 0)
//		{
//			break;
//		}
//		if (c % 2 == 0)
//		{
//			arry1[T_numbers] = c;
//			T_numbers++;
//			sum1 += c;
//		}
//		if (c % 2 == 1)
//		{
//			arry2[O_numbers] = c;
//			O_numbers++;
//			sum2 += c;
//		}
//		if ((c = getchar()) < 0)
//		{
//			printf("Wroing input,please try again:");
//			c = getchar();
//		}
//	}
//	average1 = (sum1/T_numbers);
//	average2 = (sum2/O_numbers);
//	printf("In total,%d even T_numbers were entered,their average is %f\n",T_numbers,average1);
//	printf("In total,%d even O_numbers were entered,their average is %f\n",O_numbers,average2);
//	return 0;
//}


/* Programming Exercise 7-3 */
//
//int main(void)
//{
//	int n;
//	double sumeven = 0.0;    //偶数和
//	int ct_even = 0;
//	double sumodd = 0.0;     //奇数和
//	int ct_odd = 0;
//
//	while (scanf("%d", &n) == 1 && n != 0)
//	{
//		if (n % 2 == 0)
//		{
//			sumeven += n;
//			++ct_even;
//		}
//		else                  // n % 2 is either 1 or -1
//		{
//			sumodd += n;
//			++ct_odd;
//		}
//	}
//	printf("Number of evens: %d", ct_even);
//	if (ct_even > 0)
//		printf(" average: %g", sumeven / ct_even);
//	putchar('\n');
//
//	printf("Number of odds: %d", ct_odd);
//	if (ct_odd > 0)
//		printf(" average: %g", sumodd / ct_odd);
//	putchar('\n');
//	printf("\ndone\n");
//
//	return 0;
//}


/* Programming Exercise 7-5 */
//
//int main(void)
//{
//	char ch;
//	int ct1 = 0;      //统计句号数
//	int ct2 = 0;      //统计感叹号数
//	while ((ch = getchar()) != '#')
//	{
//		switch (ch)
//		{
//		case '.': 
//			putchar('!');
//			++ct1;
//			break;
//		case '!': 
//			putchar('!');
//			putchar('!');
//			++ct2;
//			break;
//		default: 
//			putchar(ch);
//		}
//	}
//	printf("\n");
//	printf("%d replacement(s) of . with !\n", ct1);
//	printf("%d replacement(s) of ! with !!\n", ct2);
//
//	return 0;
//}


/* Programming Exercise 7-6 */
//
//int main(void)
//{
//	int c;
//	int sum = 0;
//
//	while ((c = getchar()) != EOF)
//	{
//		if (c == 'e' && getchar() == 'i')
//		{
//			sum++;
//		}
//	}
//	printf("\n");
//	printf("'ei'总共出现%d次\n",sum);
//
//	return 0;
//}


/* Programming Exercise 7-7 */
//
//#define A_HOUR 10
//int main(void)
//{
//	double w_time, total_wages, tax=0;
//	
//	printf("Please enter the number of working hours per week:");
//	scanf("%lf", &w_time);
//	//计算工资总额
//	if (w_time <= 40)
//	{
//		total_wages = w_time * A_HOUR;
//	}
//	else if (w_time > 40)
//	{
//		total_wages = 40 * A_HOUR + (w_time - 40) * 1.5 * A_HOUR;
//	}
//	//计算税金
//	if (total_wages <= 300)
//	{
//		tax = total_wages * 0.15;
//	}
//	else if (total_wages > 300 && total_wages <= 450)
//	{
//		tax = 300 * 0.15+(total_wages-300)*0.2;
//	}
//	else if (total_wages > 450)
//	{
//		tax = 300 * 0.15 + 150* 0.2+(total_wages-450)*0.25;
//	}
//
//	printf("total_wages=%lf\ntax=%lf\nnet_income=%lf\n", total_wages, tax, total_wages - tax);   //net_income--净收入
//
//	return 0;
//}
