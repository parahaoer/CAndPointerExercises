#include <stddef.h>
#include <stdio.h>
size_t my_strlen(char *str, int len) {
    int i = 0;
    for (; i < len; i++) {
        if (str[i] == '\0')
            return i;
    }
    return len;
}

int main(int argc, char const *argv[])
{
    char str[5] = {'g', 'e', 't', 'm', 'e'};
    int strlen = my_strlen(str, sizeof(str));
    printf("%d", strlen);
    return 0;
}
