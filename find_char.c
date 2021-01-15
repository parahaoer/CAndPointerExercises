#include<stdio.h>

char *find_char(char const *source, char const *chars) {
    char const *p_char = chars;
    char *p_source = source;
    while (*p_char != '\0')
    {
        while (*p_source != '\0' && *p_char != *p_source)
        {
            p_source++;
        }
        if (*p_source != '\0' && *p_char == *p_source) 
            return p_source;
        else {
            p_char++;
            p_source = source;
        }
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    char *source = "ABCDEF";
    char *chars = "CDE";
    char *ch = find_char(source, chars);
    if (ch != NULL)
        printf("%c", *ch);
    else
        printf("not match");
    
    return 0;
}
