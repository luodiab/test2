#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//�����嵥7.1 -- colddays.c -- �ҳ�0�����µ�����ռ�������İٷֱ�
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


//�����嵥7.2 -- cypher1.c -- �������룬�ո񲻱�
//
//#define SPACE ' '
//int main()
//{
//	char ch;
//
//	ch = getchar();    //��ȡһ���ַ�
//	while (ch != '\n')    //��һ��δ����ʱ
//	{
//		if (ch == SPACE)   //���¿ո�
//			putchar(ch);       //���ַ�����
//			else
//			putchar(ch + 1);  //�ı������ַ�
//			ch = getchar();   //��ȡ��һ���ַ�
//	}
//	putchar(ch);     //��ӡ���з�
//
//	return 0;
//}


//�����嵥7.3 -- cypher2.c -- �������룬�ո񲻱�
//
//#include<ctype.h>       //����isalpha()�ĺ���ԭ��
//int main()
//{
//	char ch;
//
//	while ((ch =getchar())!='\n ')    //��һ��δ����ʱ
//	{
//		if (isalpha(ch))   //�����һ���ַ�
//			putchar(ch+1);       //��ʾ���ַ�����һ���ַ�
//			else              //����
//			putchar(ch);  //ԭ����ʾ
//	}
//	putchar(ch);     //��ʾ���з�
//	return 0;
//}


//�����嵥7.4 -- electric.c -- ������
//
//#define RATE1 0.13230    //�״�ʹ��360kwh�ķ���
//#define RATE2 0.15040    //������ʹ��108kwh�ķ���
//#define RATE3 0.30025    //������ʹ��252kwh�ķ���
//#define RATE4 0.34025    //ʹ�ó���720kwh�ķ���
//#define BREAK1 360.0     //���ʵĵ�1���ֽ��
//#define BREAK2 468.0     //���ʵĵ�2���ֽ��
//#define BREAK3 720.0     //���ʵĵ�3���ֽ��
//#define BASE1 (RATE1*BREAK1)                           //ʹ��360keh�ķ���
//#define BASE2 (RATE1+(RATE2*(BREAK2-BREAK1)))          //ʹ��468keh�ķ���
//#define BASE3 (RATE2+(RATE3*(BREAK3-BREAK2)))          //ʹ��720keh�ķ���
//int main()
//{
//	double kwh;        //ʹ�õ�ǧ��ʱ
//	double bill;       //���
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
//	else                                 //���� 720 kwh
//		bill = BASE3 + (RATE4 * (kwh - BREAK3));
//	printf("The charge for %.1f kwh is $%1.2f.\n", kwh, bill);
//
//	return 0;
//}


//�����嵥7.5 -- divisors.c -- ʹ��Ƕ��if�����ʾһ������Լ��/�ж�һ�����Ƿ�Ϊ����
//
//int main()
//{
//	unsigned long num;      //�����Ե���
//	unsigned long div;      //���ܵ�Լ��
//	bool isPrime;           //�������
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
//				isPrime = false;    //������������
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


//�����嵥7.6 -- chcount.c -- ʹ���߼��������
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


//�����嵥7.6 -- chcount.c -- ʹ���߼��������(ʹ��<iso646.h>ͷ�ļ���
//
//#include <iso646.h>      //���Խ���&&����Ϊ��and";"||"��Ϊ"or";"!"��Ϊ"not".
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


//�����嵥7.7 -- wordcnt.c -- ͳ���ַ�����������������
//
//#include <ctype.h>      //Ϊ isspace()�����ṩԭ��
//#include <stdbool.h>    //Ϊ bool��true��false �ṩģ��
//#define STOP '|'
//int main()
//{
//	char c;      //�����ַ�
//	char prev;   //�����ǰһ���ַ�
//	long n_chars = 0L;    //�ַ���
//	int n_lines = 0;      //����
//	int n_words = 0;      //������
//	int p_lines = 0;      //������������
//	bool inword = false;   //��� c �ڵ����У�inword ���� true
//
//	printf("Enter text to be analyzed( | to terminate):\n");
//	prev = '\n';        //����ʶ����������
//	while ((c = getchar()) != STOP)
//	{
//		n_chars++;    //ͳ���ַ�
//		if (c == '\n')
//			n_lines++;   //ͳ����
//		if (!isspace(c) && !inword)
//		{
//			inword = true;     //��ʼһ���µĵ���
//			n_words++;         //ͳ�Ƶ���
//		}
//		if (isspace(c) && inword)
//			inword = false;      //�ﵽ���ʵ�ĩβ
//		prev = c;                //�����ַ���ֵ
//	}
//
//	if (prev != '\n')
//		p_lines = 1;
//	printf("characters=%ld,words=%d,lines=%d,",
//		n_chars, n_words, n_lines);
//	printf("partial lines=%d\n", p_lines);
//	return 0;
//}


//�����嵥7.8 -- paint.c -- ʹ�������������������
//
//#define COVERAGE 350       //ÿ�������ˢ�����
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


//�����嵥7.9 -- skippart.c -- ʹ��continue��������ѭ��
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


//�����嵥7.10 -- break.c -- ʹ�� break �˳�ѭ��
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


//�����嵥7.11 -- animals.c -- ʹ�� switch ���
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
//		if (islower(ch))     //ֻ����Сд��ĸ
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


//�����嵥7.12 -- vowels.c -- ʹ�ö��ر�ǩ
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


//�����ϰ--Chapter	7 Programming	Exercises

/* Programming Exercise 7-1 */
//
//int main()
//{
//	int c;     //������ַ�
//	int N_spaces =0, L_spaces =0, A_spaces = 0;
//
//	printf("Please type the character yoy want to type(enter # to quit)\n");
//	while ((c = getchar()) != '#')
//	{
//		if (c == ' ')
//		{
//			N_spaces++;     //ͳ�ƿո���
//		}
//		if (c == '\n')
//		{
//			L_spaces++;     //ͳ�ƻ�����
//		}
//		if (c !=' '&&c!='\n')
//		{
//			A_spaces++;     //ͳ�������ַ���
//		}
//	}
//	printf("N_spaces=%d   L_spaces=%d    A_spaces=%d\n", N_spaces, L_spaces, A_spaces);
//	return 0;
//}


/* Programming Exercise 7-2 */
//
//int main()
//{
//	int c;         //�����ַ�Ԫ��
//	int spaces = 0;      //ͳ�������ַ��ĸ���
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
//	double sumeven = 0.0;    //ż����
//	int ct_even = 0;
//	double sumodd = 0.0;     //������
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
//	int ct1 = 0;      //ͳ�ƾ����
//	int ct2 = 0;      //ͳ�Ƹ�̾����
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
//	printf("'ei'�ܹ�����%d��\n",sum);
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
//	//���㹤���ܶ�
//	if (w_time <= 40)
//	{
//		total_wages = w_time * A_HOUR;
//	}
//	else if (w_time > 40)
//	{
//		total_wages = 40 * A_HOUR + (w_time - 40) * 1.5 * A_HOUR;
//	}
//	//����˰��
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
//	printf("total_wages=%lf\ntax=%lf\nnet_income=%lf\n", total_wages, tax, total_wages - tax);   //net_income--������
//
//	return 0;
//}
