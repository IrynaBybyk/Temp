#include "uls.h"

static void output_flags(char *s, int *fl);
static void hiden_files_and_R(char *s, int *fl);
//static void mx_sort_flags(char *s, int *fl);
//static void sort_flags_2(char *s, int *fl);
static void fill_clonem(int *fl, int *values);
 
void mx_read_flags(char *s, t_App *app) {
        mx_check_eror_flag(&s[1]);
		output_flags(s, app->flags);
		if (app->flags[m] == 1 && app->flags[C] == 1)
			app->flags[C] = 0;
		hiden_files_and_R(&s[1], app->flags);
    mx_sort_flags(&s[1], app);
		//sort_flags_2(&s[1], app->flags);
		mx_filter_flags(&s[1], app->flags);
}

static void fill_clonem(int *fl, int *values) {
    fl[C] = values[0];
    fl[l] = values[1];
    fl[one] = values[2];
    fl[m] = values[3];
}

static void output_flags(char *s, int *fl) {
    for (; *s; s++)
        if (*s == 'm') {
            fill_clonem(fl, (int []){0, 0, 0, 1});
        }
        else if (*s =='1') {
            fill_clonem(fl, (int []){0, 0, 1, 0});
        }
        else if (*s =='l') {
            fill_clonem(fl, (int []){0, 1, 0, 0});
        }
        else if (*s == 'C') {
            fill_clonem(fl, (int []){1, 0, 0, fl[m]});
        }
}

static void hiden_files_and_R(char *s, int *fl)
{
    for (int i = 0; s[i] != '\0'; i++)
        switch (s[i]) {
        case 'A':
            if (fl[a] != 1)
                fl[A] = 1;
            break;
        case 'a':
            fl[a] = 1;
            fl[A] = 0;
            break;
        case '@':
            if (fl[l] == 1)
                fl[dog] = 1;
            break;
        case 'R':
            fl[R] = 1;
            break;
        }
}

//static void mx_sort_flags(char *s, int *fl) {
//    for (; *s; s++)
//        switch (*s) {
//        case 'S':
//            fl[S] = 1;
//            fl[t] = 0;
//            fl[c] = 0;
//            break;
//        case 'c':
//            if (fl[S] != 1) {
//                fl[c] = 1;
//                break;
//            }
//        }
//}
//
//static void sort_flags_2(char *s, int *fl) {
//    for (; *s; s++)
//        switch (*s) {
//        case 'u':
//                fl[u] = 1;
//                fl[U] = 0;
//                break;
//        case 't':
//            if (fl[S] != 1) {
//                fl[t] = 1;
//                break;
//            }
//        }
//}
