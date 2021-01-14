#include<stdio.h>

int del_substr(char *str, char const *substr) {
    char *p_str = str;
    char const *p_substr = substr;
    char *p_start = p_str;

    while (*str != '\0') {

        while (*p_substr != '\0' && *p_str++ == *p_substr++);
        if (*p_substr == '\0') {
            while(*p_str != '\0') 
                *p_start++ = *p_str++;
            *p_start = '\0';
            return 1;
        }
        p_start++;
        p_substr = substr;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char str[] = "ABCDEFG";
    char sub_str[] = "CDE";
    //如果传入的是字符指针，p_start++会报段错误；如果传入的是字符数组，程序能够正常运行。
    int res = del_substr(str, sub_str);
    printf("%d\n", res);
    printf("%s", str);
    return 0;
}
