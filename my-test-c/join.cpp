#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char *join(char *a, char *b)
{
    // 局部变量，用malloc申请内存
    char *c = (char *)malloc(strlen(a) + strlen(b) + 1);
    if (c == NULL)
    {
        exit(1);
    }
    // 把首地址存下来
    char *tempc = c;
    while (*a != '\0')
    {
        *c++ = *a++;
    }
    while ((*c++ = *b++) != '\0')
    {
        ;
    }
    // 此时指针c已经指向拼接之后的字符串的结尾'\0'
    // 返回值是局部malloc申请的指针变量，需在函数调用结束后free
    return tempc;
}

int main()
{
    char a[4] = "abc";
    char b[4] = "def";
    char *c = join(a, b);
    printf("contacted String is %s\n", c);
    free(c);
    c = NULL;
    return 0;
}
