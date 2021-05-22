#define _CRT_SECURE_NO_WARNINGS 1

/* 程序清单13.1 -- count.c -- using standard I/O */
//
//#include <stdio.h>
//#include <stdlib.h> // exit() prototype
//
//int main(int argc, char* argv[])
//{
//    int ch;         // place to store each character as read
//    FILE* fp;       // "file pointer"
//    unsigned long count = 0;
//    if (argc != 2)
//    {
//        printf("Usage: %s filename\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    if ((fp = fopen(argv[1], "r")) == NULL)
//    {
//        printf("Can't open %s\n", argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    while ((ch = getc(fp)) != EOF)
//    {
//        putc(ch, stdout);  // same as putchar(ch);
//        count++;
//    }
//    fclose(fp);
//    printf("File %s has %lu characters\n", argv[1], count);
//
//    return 0;
//}


/* 程序清单13.2 -- reducto.c -- reduces your files by two-thirds! */
//
//#include <stdio.h>
//#include <stdlib.h>    // for exit()
//#include <string.h>    // for strcpy(), strcat()
//
//#define LEN 40
//
//int main(int argc, char* argv[])
//{
//    FILE* in, * out;   // declare two FILE pointers
//    int ch;
//    char name[LEN];    // storage for output filename
//    int count = 0;
//
//    // check for command-line arguments
//    if (argc < 2)
//    {
//        fprintf(stderr, "Usage: %s filename\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    // set up input
//    if ((in = fopen(argv[1], "r")) == NULL)
//    {
//        fprintf(stderr, "I couldn't open the file \"%s\"\n",
//            argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    // set up output
//    strncpy(name, argv[1], LEN - 5); // copy filename
//    name[LEN - 5] = '\0';
//    strcat(name, ".red");            // append .red
//    if ((out = fopen(name, "w")) == NULL)
//    {                       // open file for writing
//        fprintf(stderr, "Can't create output file.\n");
//        exit(3);
//    }
//    // copy data
//    while ((ch = getc(in)) != EOF)
//        if (count++ % 3 == 0)
//            putc(ch, out);  // print every 3rd char
//    // clean up
//    if (fclose(in) != 0 || fclose(out) != 0)
//        fprintf(stderr, "Error in closing files\n");
//
//    return 0;
//}


/* 程序清单13.3 -- addaword.c -- uses fprintf(), fscanf(), and rewind() */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX 41
//
//int main(void)
//{
//    FILE* fp;
//    char words[MAX];
//
//    if ((fp = fopen("wordy", "a+")) == NULL)
//    {
//        fprintf(stdout, "Can't open \"wordy\" file.\n");
//        exit(EXIT_FAILURE);
//    }
//
//    puts("Enter words to add to the file; press the #");
//    puts("key at the beginning of a line to terminate.");
//    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
//        fprintf(fp, "%s\n", words);
//
//    puts("File contents:");
//    rewind(fp);           /* go back to beginning of file */
//    while (fscanf(fp, "%s", words) == 1)
//        puts(words);
//    puts("Done!");
//    if (fclose(fp) != 0)
//        fprintf(stderr, "Error closing file\n");
//
//    return 0;
//}


/* 程序清单13.4 -- reverse.c -- displays a file in reverse order */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define CNTL_Z '\032'   /* eof marker in DOS text files */
//#define SLEN 81
//
//int main(void)
//{
//    char file[SLEN];
//    char ch;
//    FILE* fp;
//    long count, last;
//
//    puts("Enter the name of the file to be processed:");
//    scanf("%80s", file);
//    if ((fp = fopen(file, "rb")) == NULL)
//    {                               /* read-only mode   */
//        printf("reverse can't open %s\n", file);
//        exit(EXIT_FAILURE);
//    }
//
//    fseek(fp, 0L, SEEK_END);        /* go to end of file */
//    last = ftell(fp);
//    for (count = 1L; count <= last; count++)
//    {
//        fseek(fp, -count, SEEK_END); /* go backward      */
//        ch = getc(fp);
//        if (ch != CNTL_Z && ch != '\r')  /* MS-DOS files */
//            putchar(ch);
//    }
//    putchar('\n');
//    fclose(fp);
//
//    return 0;
//}


/* 程序清单13.5 -- append.c -- appends files to a file */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define BUFSIZE 4096
//#define SLEN 81
//
//void append(FILE* source, FILE* dest);
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    FILE* fa, * fs;	// fa for append file, fs for source file
//    int files = 0;  // number of files appended
//    char file_app[SLEN];  // name of append file
//    char file_src[SLEN];  // name of source file
//    int ch;
//
//    puts("Enter name of destination file:");
//    s_gets(file_app, SLEN);
//    if ((fa = fopen(file_app, "a+")) == NULL)
//    {
//        fprintf(stderr, "Can't open %s\n", file_app);
//        exit(EXIT_FAILURE);
//    }
//    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        fputs("Can't create output buffer\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    puts("Enter name of first source file (empty line to quit):");
//    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
//    {
//        if (strcmp(file_src, file_app) == 0)
//            fputs("Can't append file to itself\n", stderr);
//        else if ((fs = fopen(file_src, "r")) == NULL)
//            fprintf(stderr, "Can't open %s\n", file_src);
//        else
//        {
//            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
//            {
//                fputs("Can't create input buffer\n", stderr);
//                continue;
//            }
//            append(fs, fa);
//            if (ferror(fs) != 0)
//                fprintf(stderr, "Error in reading file %s.\n",
//                    file_src);
//            if (ferror(fa) != 0)
//                fprintf(stderr, "Error in writing file %s.\n",
//                    file_app);
//            fclose(fs);
//            files++;
//            printf("File %s appended.\n", file_src);
//            puts("Next file (empty line to quit):");
//        }
//    }
//    printf("Done appending. %d files appended.\n", files);
//    rewind(fa);
//    printf("%s contents:\n", file_app);
//    while ((ch = getc(fa)) != EOF)
//        putchar(ch);
//    puts("Done displaying.");
//    fclose(fa);
//
//    return 0;
//}
//
//void append(FILE* source, FILE* dest)
//{
//    size_t bytes;
//    static char temp[BUFSIZE]; // allocate once
//
//    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
//        fwrite(temp, sizeof(char), bytes, dest);
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
//                continue;
//    }
//    return ret_val;
//}


/* 程序清单13.6 -- randbin.c -- random access, binary i/o */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define ARSIZE 1000
//
//int main()
//{
//    double numbers[ARSIZE];
//    double value;
//    const char* file = "numbers.dat";
//    int i;
//    long pos;
//    FILE* iofile;
//
//    // create a set of double values
//    for (i = 0; i < ARSIZE; i++)
//        numbers[i] = 100.0 * i + 1.0 / (i + 1);
//    // attempt to open file
//    if ((iofile = fopen(file, "wb")) == NULL)
//    {
//        fprintf(stderr, "Could not open %s for output.\n", file);
//        exit(EXIT_FAILURE);
//    }
//    // write array in binary format to file
//    fwrite(numbers, sizeof(double), ARSIZE, iofile);
//    fclose(iofile);
//    if ((iofile = fopen(file, "rb")) == NULL)
//    {
//        fprintf(stderr,
//            "Could not open %s for random access.\n", file);
//        exit(EXIT_FAILURE);
//    }
//    // read selected items from file
//    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
//    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
//    {
//        pos = (long)i * sizeof(double); // calculate offset
//        fseek(iofile, pos, SEEK_SET);    // go there
//        fread(&value, sizeof(double), 1, iofile);
//        printf("The value there is %f.\n", value);
//        printf("Next index (out of range to quit):\n");
//    }
//    // finish up
//    fclose(iofile);
//    puts("Bye!");
//
//    return 0;
//}


/* Chapter	13 Programming	Exercises */

/* Programming Exercise 13-1 */
//
//#include<stdio.h>
//#include<stdlib.h>
//
//#define LEN 100
//
//int main(void)
//{
//    char fileName[LEN];
//    FILE* tarFile;
//    char ch;
//
//    printf("PLease Input File Name:\n");
//    gets(fileName);
//
//    if ((tarFile = fopen(fileName, "r")) == NULL)      /* fopen的第一个参数是待打开文件的名称，
//                                                          更切确地说是一个包含该文件名的字符串
//                                                          地址。*/
//    {
//        printf("Open %s Fail.", fileName);
//        exit(1);
//    }
//
//    while ((ch = getc(tarFile)) != EOF)      /* 函数getc()用于从流中取字符,
//                                                其原型为: int getc(FILE *stream)
//                                                参数*steam为要从中读取字符的文件流。*/
//        printf("%c", ch);
//
//    fclose(tarFile);
//
//    return 0;
//}


/* Programming Exercise 13-2 */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//	int byte;
//	FILE* source;    //原始文件名
//	FILE* target;    //拷贝文件名
//	if (argc != 3)
//	{
//		printf("Usage: %s sourcefile targetfile\n", argv[0]);
//		exit(EXIT_FAILURE);
//	}
//
//	if ((source = fopen(argv[1], "rb")) == NULL)
//	{
//		printf("Could not open file %s for input\n", argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	if ((target = fopen(argv[2], "wb")) == NULL)
//	{
//		printf("Could not open file %s for output\n", argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	while ((byte = getc(source)) != EOF)
//	{
//		putc(byte, target);
//	}
//	if (fclose(source) != 0)
//		printf("Could not close file %s\n", argv[1]);
//	if (fclose(target) != 0)
//		printf("Could not close file %s\n", argv[2]);
//
//	return 0;
//}


/* Programming Exercise 13-3 */
//
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//
//#define LEN 50
//
//int main(int argc, char* argv[])
//{
//    int ch;
//    FILE* fp;
//    char filename[LEN];
//
//    printf("Please enter a filename: ");
//    scanf("%49s", filename);
//
//    if ((fp = fopen(filename, "r+")) == NULL)
//    {
//        fprintf(stderr, "Can't open %s\n", filename);
//        exit(EXIT_FAILURE);
//    }
//    while ((ch = getc(fp)) != EOF)
//    {
//        fseek(fp, -1L, SEEK_CUR); //回退一个字节;
//        putc(toupper(ch), fp);
//        fseek(fp, 0L, SEEK_CUR); //改变文件状态,使得下一个字符可以被正常读取(详情参见C陷阱与缺陷一书);
//    }
//    rewind(fp);
//    printf("File %s:\n", filename);
//    while ((ch = getc(fp)) != EOF)
//    {
//        putchar(ch);
//        /*↑显示到屏幕上检测
//        字符是否成功转换为大写;*/
//    }
//    putchar('\n');
//    if (fclose(fp) != 0)
//    {
//        fprintf(stderr, "Can't close %s\n", filename);
//    }
//
//    return 0;
//}


/* Programming Exercise 13-4 */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    int i, temp;
//    FILE* source;
//
//    if (argc == 1)
//    {
//        fprintf(stderr, "Usage: %s filename[s]\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    for (i = 1; i < argc; i++)
//    {
//        if ((source = fopen(argv[i], "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open file %s\n", argv[i]);
//            continue;
//        }
//        printf("File %s:\n", argv[i]);
//        while ((temp = getc(source)) != EOF)
//        {
//            putchar(temp);
//        }
//        putchar('\n');
//        if (fclose(source) != 0)
//        {
//            fprintf(stderr, "Can't close file %s\n", argv[i]);
//        }
//    }
//
//    return 0;
//}


/* Programming Exercise 13-5 */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define BUFSIZE 4096
//#define SLEN 81
//
//void append(FILE* source, FILE* dest);
//
//int main(int argc, char* argv[])
//{
//    int i, ch;
//    int files = 0;
//    FILE* fa;
//    FILE* fs;
//
//    if (argc < 3)
//    {
//        printf("Usage: %s appendfile sourcefile.\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    if ((fa = fopen(argv[1], "a+")) == NULL)
//    {
//        fprintf(stderr, "Can't open %s\n", argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        //↑设置缓冲区大小为BUFSIZE;
//        //↑_IOFBF表示完全缓冲;
//        //↑NULL表示为fa指向的文件分配缓冲区;
//        fputs("Can't create output buffer\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    for (i = 2; i < argc; i++)
//    {
//        if (strcmp(argv[i], argv[1]) == 0)
//        {
//            fputs("Can't append file to itself\n", stderr);
//            //↑防止文件自身附加在文件末尾;
//        }
//        else if ((fs = fopen(argv[i], "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", argv[i]);
//        }
//        else
//        {
//            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
//            {
//                //↑同上一个setvbuf函数所述;
//                //↑本次调用是为fs指向的文件分配缓冲区;
//                fputs("Can't create input buffer\n", stderr);
//                continue;
//            }
//            append(fs, fa);
//            if (ferror(fs) != 0)
//            {
//                /*↑当读或写出现错误
//                ferror函数返回一个非0值*/
//                fprintf(stderr, "Error in reading file %s.\n", argv[i]);
//            }
//            if (ferror(fa) != 0)
//            {
//                fprintf(stderr, "Error in writing file %s.\n", argv[1]);
//            }
//            fclose(fs);
//            files++;
//            printf("File %s appended.\n", argv[i]);
//        }
//    }
//    printf("Done appending. %d files appended.\n", files);
//    rewind(fa); //返回文件起始处;
//    printf("%s contents:\n", argv[1]);
//    while ((ch = getc(fa)) != EOF)
//    {
//        putchar(ch);
//    }
//    putchar('\n');
//    puts("Done displaying.");
//    fclose(fa);
//
//    return 0;
//}
//
//void append(FILE* source, FILE* dest)
//{
//    size_t bytes;
//    static char temp[BUFSIZE];
//    //↑静态无链接变量只分配一次内存;
//
//    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
//    {
//        /*↑fread函数把source指向的
//        文件中的BUFSIZE块char类型的
//        数据写入temp数组中,返回值是成功
//        读取数据块的数量;*/
//        fwrite(temp, sizeof(char), bytes, dest);
//        /*↑fwrite函数把temp数组中的
//        bytes块char类型的数据写入dest
//        指向的文件中,返回值是成功写入数据
//        块的数量;*/
//    }
//
//    return;
//}


/* Programming Exercise 13-6 */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define LEN 40
//
//int main(int argc, char* argv[])
//{
//    FILE* in, * out;
//    int ch;
//    char name[LEN];
//    int count = 0;
//    char temp[LEN];
//
//    printf("Please enter a filename:\n");
//    scanf("%39s", temp);
//
//    if ((in = fopen(temp, "r")) == NULL)
//    {
//        fprintf(stderr, "I could't open the file \"%s\"\n", temp);
//        exit(EXIT_FAILURE);
//    }
//    //↓拷贝文件名;
//    strncpy(name, temp, LEN - 5);
//    name[LEN - 5] = '\0';
//    strcat(name, ".red");
//    //↑在文件名后面添加.red;
//    if ((out = fopen(name, "w")) == NULL)
//    {
//        fprintf(stderr, "Can't create output file.\n");
//        exit(3);
//    }
//    //↓拷贝数据;
//    while ((ch = getc(in)) != EOF)
//    {
//        if (count++ % 3 == 0)
//        {
//            putc(ch, out);
//        }
//    }
//    if (fclose(in) != 0 || fclose(out) != 0)
//    {
//        fprintf(stderr, "Error in closing files\n");
//    }
//
//    return 0;
//}


/* Programming Exercise 13-7.a */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    FILE* f1;
//    FILE* f2;
//    int ch1, ch2;
//
//    if (argc != 3)
//    {
//        printf("Usage: %s file1 file2\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    if ((f1 = fopen(argv[1], "r")) == NULL)
//    {
//        fprintf(stderr, "Can't open file %s\n", argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    if ((f2 = fopen(argv[2], "r")) == NULL)
//    {
//        fprintf(stderr, "Can't open file %s\n", argv[2]);
//        exit(EXIT_FAILURE);
//    }
//
//    ch1 = getc(f1);
//    ch2 = getc(f2);
//    while (ch1 != EOF || ch2 != EOF)
//    {
//        while (ch1 != EOF && ch1 != '\n')
//        {
//            putchar(ch1);
//            ch1 = getc(f1);
//        }
//        if (ch1 != EOF)
//        {
//            putchar('\n');
//            ch1 = getc(f1); //光标读取至文件1的下一行;
//        }
//        while (ch2 != EOF && ch2 != '\n')
//        {
//            putchar(ch2);
//            ch2 = getc(f2);
//        }
//        if (ch2 != EOF)
//        {
//            putchar('\n');
//            ch2 = getc(f2); //光标读取至文件2的下一行;
//        }
//    }
//    if (fclose(f1) != 0)
//    {
//        fprintf(stderr, "Can't close %s\n", argv[1]);
//    }
//    if (fclose(f2) != 0)
//    {
//        fprintf(stderr, "Can't close %s\n", argv[2]);
//    }
//
//    return 0;
//}


/* Programming Exercise 13-7.b.1 */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    FILE* f1;
//    FILE* f2;
//    int ch1, ch2;
//    int x = 1;
//
//    if (argc != 3)
//    {
//        printf("Usage: %s file1 file2\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    if ((f1 = fopen(argv[1], "r")) == NULL)
//    {
//        fprintf(stderr, "Can't open file %s\n", argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    if ((f2 = fopen(argv[2], "r")) == NULL)
//    {
//        fprintf(stderr, "Can't open file %s\n", argv[2]);
//        exit(EXIT_FAILURE);
//    }
//
//    ch1 = getc(f1);
//    ch2 = getc(f2);
//    while (ch1 != EOF || ch2 != EOF)
//    {
//        while (ch1 != EOF && ch1 != '\n')
//        {
//            putchar(ch1);
//            ch1 = getc(f1);
//        }
//        if (ch1 != EOF)
//        {
//            ch1 = getc(f1); //光标读取至文件1的下一行;
//        }
//        while (ch2 != EOF && ch2 != '\n')
//        {
//            if (x == 1)
//            {
//                putchar(' ');
//                putchar(' ');
//                x = 0;
//            }
//            putchar(ch2);
//            ch2 = getc(f2);
//        }
//        if (ch2 != EOF)
//        {
//            ch2 = getc(f2); //光标读取至文件2的下一行;
//        }
//        putchar('\n');
//        x = 1;
//    }
//    if (fclose(f1) != 0)
//    {
//        fprintf(stderr, "Can't close %s\n", argv[1]);
//    }
//    if (fclose(f2) != 0)
//    {
//        fprintf(stderr, "Can't close %s\n", argv[2]);
//    }
//
//    return 0;
//}


/* Programming Exercise 13-7.b.2 */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    FILE* f1;
//    FILE* f2;
//    int ch1, ch2;
//
//    if (argc != 3)
//    {
//        printf("Usage: %s file1 file2\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    if ((f1 = fopen(argv[1], "r")) == NULL)
//    {
//        fprintf(stderr, "Can't open file %s\n", argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    if ((f2 = fopen(argv[2], "r")) == NULL)
//    {
//        fprintf(stderr, "Can't open file %s\n", argv[2]);
//        exit(EXIT_FAILURE);
//    }
//
//    ch1 = getc(f1);
//    ch2 = getc(f2);
//    while (ch1 != EOF || ch2 != EOF)
//    {
//        while (ch1 != EOF && ch1 != '\n')
//        {
//            putchar(ch1);
//            ch1 = getc(f1);
//        }
//        if (ch1 != EOF)
//        {
//            if (ch2 == EOF) //若是文件2以读取完毕则换行;
//            {
//                putchar('\n');
//            }
//            else //文件2未读取完毕打印空格隔开2个文件内容;
//            {
//                putchar(' ');
//            }
//            ch1 = getc(f1); //光标读取至文件1的下一行;
//        }
//        while (ch2 != EOF && ch2 != '\n')
//        {
//            putchar(ch2);
//            ch2 = getc(f2);
//        }
//        if (ch2 != EOF)
//        {
//            putchar('\n');
//            ch2 = getc(f2); //光标读取至文件2的下一行;
//        }
//    }
//    if (fclose(f1) != 0)
//    {
//        fprintf(stderr, "Can't close %s\n", argv[1]);
//    }
//    if (fclose(f2) != 0)
//    {
//        fprintf(stderr, "Can't close %s\n", argv[2]);
//    }
//
//    return 0;
//}


/* Programming Exercise 13-8 */
//
//(1) -- 为笔者自写，只能执行一个文件，没有处理多个文件的功能，为简化版。
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX 41
//
//int main(int argc, char* argv[])
//{
//    FILE *fp;
//    char words[MAX];
//    int k=0,g=0,ch,ch2,j;
//    int count = 0;
//    int i = 0;
//
//    if (argc==2)    //判断参数是否足够，不够则回应报告。
//    {
//        printf("Usage: %s appendfile sourcefile.\n", argv[0]);
//        j = argv[1][0];
//        printf("Please enter a string of characters:\n");
//        scanf("%s", words);
//        int k = 1;
//        if (k == 1)
//        {
//            g = strlen(words);
//            words[g] = '\n';
//            for (i = 0; i < g; i++)
//            {
//                if (j == words[i])
//                {
//                    ++count;
//                }
//            }
//            printf("\' %c \'occurs %d times in the array words\n", j, count);
//        }
//    }
//    if(argc==3)
//    {
//        if ((fp = fopen(argv[2], "r")) == NULL)     //判断文件是否能打开，不能打开则报告。
//        {
//            fprintf(stderr, "Can't open file %s\n", argv[2]);
//        }
//        printf("File %s:\n", argv[2]);
//        while ((ch = getc(fp)) != EOF)     //打印文件内的内容。
//        {
//            putchar(ch);
//        }
//        rewind(fp);
//        j = argv[1][0];
//        ch = getc(fp);
//        while (ch != EOF)
//        {
//            while (ch != EOF )
//            {
//                if (j == (char)ch)
//                {
//                    ++count;
//                }
//                ch = getc(fp);
//            }
//        }
//        if (ch == EOF)
//        {
//            printf("\' %c \'occurs %d times in the array %s\n", j, count, argv[2]);
//        }
//        if (fclose(fp) != 0)    //判断文件是否关闭，关闭不成功则报告。
//            fprintf(stderr, "Error closing file\n");
//    }
//
//    return 0;
//}



//(2)
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int search(int ch, FILE* fp);
//
//int main(int argc, char* argv[])
//{
//    FILE* fp;
//    int i, ch, ct;
//    int count = 0;
//
//    if (argc < 2)
//    {
//        fprintf(stderr, "Usage: %s character filename[s]\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    if (strlen(argv[1]) != 1)
//    {
//        fprintf(stderr, "The second argument must be a character!\n");
//        exit(EXIT_FAILURE);
//    }
//    if (argc == 2)
//    {
//        fp = stdin;
//        ch = argv[1][0];
//        printf("Please enter a string (EOF to quit): ");
//        count = search(ch, fp);
//        printf("%c appeared %d times.\n", ch, count);
//    }
//    else if (argc > 2)
//    {
//        ch = argv[1][0];
//        for (i = 2; i < argc; i++)
//        {
//            if ((fp = fopen(argv[i], "r")) == NULL)
//            {
//                fprintf(stderr, "Can't open file %s\n", argv[i]);
//                continue;
//            }
//            printf("File %s:\n", argv[i]);
//            while ((ct = getc(fp)) != EOF)
//            {
//                putchar(ct);
//            }
//            rewind(fp);
//            count = search(ch, fp);
//            printf("%c appeared %d times in file %s\n", ch, count, argv[i]);
//            if (fclose(fp) != 0)
//            {
//                fprintf(stderr, "Can't close file %s\n", argv[i]);
//            }
//        }
//    }
//
//    return 0;
//}
//
//int search(int ch, FILE* fp)
//{
//    int find;
//    int n = 0;
//
//    while ((find = getc(fp)) != EOF)
//    {
//        if (ch == find)
//        {
//            ++n;
//        }
//    }
//    return n;
//}


/* Programming Exercise 13-9 */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 41
//
//int main(void)
//{
//    FILE* fp;
//    int ct = 0;
//    char words[MAX];
//
//    if ((fp = fopen("wordy", "a+")) == NULL)
//    {
//        fprintf(stdout, "Can't open \"wordy\" file.\n");
//        exit(EXIT_FAILURE);
//    }
//
//    while (fgets(words, MAX, fp) != NULL)   //从fp读取文件到words.
//    {
//        ct++;
//    }
//    rewind(fp);
//    puts("Enter words to add to the file; press the #");
//    puts("key at the beginning of a line to terminate.");
//    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))   //从stdin读取字符串到words.
//    {
//        fprintf(fp, "%-2d : %s\n", ++ct, words);
//    }
//
//    puts("File contents:");
//    rewind(fp);
//    while (fgets(words, MAX, fp) != NULL)
//    {
//        fputs(words, stdout);
//    }
//    puts("Done!");
//    if (fclose(fp) != 0)
//    {
//        fprintf(stderr, "Error in closing file\n");
//    }
//
//    return 0;
//}


/* Programming Exercise 13-10 */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define LEN 50
//
//int main(int argc, char* argv[])
//{
//    int ch;
//    FILE* fp;
//    long int number;
//    char filename[LEN];
//
//    printf("Please enter a filename: ");
//    scanf("%49s", filename);
//
//    if ((fp = fopen(filename, "r")) == NULL)   //通过交互的方式获得文件名。
//    {
//        fprintf(stderr, "Can't open file %s\n", filename);
//        exit(EXIT_FAILURE);
//    }
//    printf("Please enter a file position (<0 or q to quit): ");
//    while (scanf("%ld", &number) == 1 && number >= 0)
//    {
//        fseek(fp, number, SEEK_SET);
//        while ((ch = getc(fp)) != '\n' && ch != EOF)
//        {
//            /*↓打印从该位置开始到
//            下一个换行符之前的内容;*/
//            putchar(ch);
//        }
//        if (ch == EOF)
//        {
//            printf("The position reaches EOF.\n");
//            break;
//        }
//        printf("\nYou can enter again (<0 or q to quit): ");
//    }
//    printf("Done.\n");
//    if (fclose(fp) != 0)
//    {
//        fprintf(stderr, "Can't close file %s\n", filename);
//    }
//
//    return 0;
//}


/* Programming Exercise 13-11 */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define SLEN 256
//
//int main(int argc, char* argv[])
//{
//    FILE* fp;
//    char line[SLEN];
//
//    if (argc != 3)
//    {
//        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//    if ((fp = fopen(argv[2], "r")) == NULL)
//    {
//        fprintf(stderr, "Can't open file %s", argv[2]);
//        exit(EXIT_FAILURE);
//    }
//    while (fgets(line, SLEN, fp) != NULL)    //从文件流读取一行，送到缓冲区
//    {
//        if (strstr(line, argv[1]) != NULL)
//        {
//            fputs(line, stdout);
//        }
//    }
//    if (fclose(fp) != 0)
//    {
//        fprintf(stderr, "Can't close file %s", argv[2]);
//    }
//
//    return 0;
//}



