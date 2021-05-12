#include <stdio.h>
struct student
{
    int score;
};
int cmp(struct student *s1, struct student *s2);
void swap(char *a, char *b, int size);
void sort(void *a, size_t len, int size, int (*cmp)(void *c1, void *c2));

void sort(void *a, size_t len, int size, int (*cmp)(void *c1, void *c2))
{
    size_t i, j;
    for (i = 0; i < len - 1; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (cmp(a + i * size, a + j * size) > 0)
            {
                swap(a + i * size, a + j * size, size);
            }
        }
    }
}
void swap(char *a, char *b, int size)
{
    char tmp;
    size_t i;
    for (i = 0; i < size; i++)
    {
        tmp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = tmp;
    }
}

int cmp(struct student *s1, struct student *s2)
{
    if (s1->score == s2->score)
        return 0;
    else if (s1->score > s2->score)
        return 1;
    else
        return -1;
}

int main(int argc, char const *argv[])
{

    struct student stu[3];
    stu[0].score = 99;
    stu[1].score = 55;
    stu[2].score = 77;

    sort(stu, 3, sizeof(struct student), cmp);
    size_t i;
    for (i = 0; i < 3; i++)
    {
        printf("%d ", stu[i].score);
    }
    return 0;
}
