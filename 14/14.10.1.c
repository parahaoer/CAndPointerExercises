#include<stdio.h>
//#define OPTION_LONG 0
#define OPTION_DETAILED 3

void print_ledger_long(int n) {
    printf("%ld", n);
}

void print_ledger_detailed(int n) {
    printf("n = %d", n);
}

void print_ledger_default() {
    printf("n default = 0");
}

void print_ledger(int n) {
    #if defined(OPTION_LONG)
        print_ledger_long(n);
    #elif defined(OPTION_DETAILED)
        print_ledger_detailed(n);
    #else
        print_ledger_default();
    #endif
}

int main(int argc, char const *argv[])
{
    print_ledger(100);
    return 0;
}

/*
预处理后得到的代码：
void print_ledger_long(int n) {
    printf("%ld", n);
}

void print_ledger_detailed(int n) {
    printf("n = %d", n);
}

void print_ledger_default() {
    printf("n default = 0");
}

void print_ledger(int n) {



        print_ledger_detailed(n);



}

int main(int argc, char const *argv[])
{
    print_ledger(100);
    return 0;
}

*/