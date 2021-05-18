#define _CRT_SECURE_NO_WARNINGS 1
//pe12-3a.h
#define METRIC 0
#define US 1
#define USE_RECENT 2
void check_mode(int* pm);
void get_info(int mode, double* pd, double* pf);
void show_info(int mode, double distance, double fuel);