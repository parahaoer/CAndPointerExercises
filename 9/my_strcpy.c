#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char  *my_strcpy(char *src, size_t n) {
    // dest是局部变量，在栈上分配空间，当函数结束后会回收空间，这样dest返回的内容无效。
    // 解决方法是在堆上申请空间，然后返回，但是这样做需要注意释放空间。
    char *dest = malloc(n + 1);
    char *dest_ptr = dest;
    int i;
    for (i = 0; i < n; i++) {
        *dest_ptr++ = *src++;
    }
    *dest_ptr = '\0';
    return dest;
}

int main(int argc, char const *argv[])
{
    
    char *src = "helloworld";
    char *dest = my_strcpy(src, strlen(src));
    printf("%s", dest);
    free(dest);
    return 0;
}
