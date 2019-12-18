#include "libmx.h"

static int compare(char *s1, char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;

    if (!s || !arr || !(*arr)) {
        return -1;
    } 
    *count = 0;   
    while (left <= right) {
        int mid = left + (right - left) / 2;

        (*count)++;
        if (compare((char *)s, arr[mid]) < 0)
            right = mid - 1;
        else if (compare((char *)s, arr[mid]) > 0)
            left = mid + 1;
        else
            return mid;
    }
    *count = 0;
    return -1;
}

static int compare(char *s1, char *s2) {
    return mx_strcmp(s1, s2);
}

