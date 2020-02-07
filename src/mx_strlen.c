int mx_strlen(const char *s) {
    int i;
    
    if (!s)
        return 0;
    for (i = 0; s[i]; i++);
    return i;
}
