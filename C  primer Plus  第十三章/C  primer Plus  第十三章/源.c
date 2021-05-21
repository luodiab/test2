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
