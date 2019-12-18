#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int l;

    if (!str || !sub) {
        return -1; 
    } // here was mistake
    if (!(*sub)) {
        return 0;
    }    
    l = mx_strlen(sub);
    while (*str) {
        char *p = mx_strstr(str, sub);
        
        if (p) {
            count++;
            str = p + l - 1;
        }
        str++;
    }
    return count;
}

