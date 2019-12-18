int mx_strlen(const char *s) {
    int len = 0;
    
    if (!s) {
        return 0;
    }
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}

