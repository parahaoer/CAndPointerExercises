#include<ctype.h>
#include<stdio.h>
/*
* 1、转换表func是一个函数指针数组，数组元素的类型是函数指针，函数返回值是一个int值。
* 2、从标准输入获得字符，注意后面的换行符'\n'
* 3、ctype.h 中声明的函数非零（不是1）表示true， 0表示false
*/
int main(int argc, char const *argv[])
{
    char ch;
    int (* func[]) (int ch) = {
        iscntrl, isspace, isdigit, islower, isupper, ispunct, isprint
    };
    int res[7] = {0};

    while ((ch = getchar()) != EOF) {
        for (int i = 0; i < 7; i++) {
            if (i == 6)
                if (func[i](ch) != 0)
                    res[i] += 0;
                else
                    res[i] += 1;
            else if (func[i](ch) != 0)
                res[i] += 1;
        }
        float sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += res[i];
        }
        for (int i = 0; i < 7; i++) {
            printf("%.2f ", res[i] / sum);
        }
        printf("\n");
    }      
    return 0;
}
