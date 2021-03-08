#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void *calloc(size_t num_elements, size_t element_size) {
    register char *array = (void *) malloc(num_elements * element_size);
    if (array != NULL) {
        memset(array, 0, element_size);
        return array;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    int *array = calloc(25, 4);
    printf("%d", *array);
    return 0;
}
