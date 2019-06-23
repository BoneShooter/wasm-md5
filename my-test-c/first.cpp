#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char *getMD5(char *out)
{
    char *md5 = (char *)"zxcvbnm";
    out = md5;
    return out;
}

int main()
{
    char *a = (char *)"abc";
    char *b = (char *)"defghi";

    cout << "b init" << endl;
    cout << "b 串: " << b << endl;

    b = a;
    cout << "b=a" << endl;
    cout << "b 串: " << b << endl;

    getMD5(b);
    cout << "b=md5" << endl;
    cout << "b 串: " << b << endl;
    return 0;
}
