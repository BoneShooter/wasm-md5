/**
 * @file main.cpp
 * @The app entry，test for WebAssembly
 * @author Bone Shooter
 * @github https://github.com/BoneShooter
 * @data June 23 2019
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "./md5.h"

using namespace std;

// https://emscripten.org/docs/getting_started/FAQ.html#why-do-functions-in-my-c-c-source-code-vanish-when-i-compile-to-javascript-and-or-i-get-no-functions-to-process
// Exported functions need to be C functions (to avoid C++ name mangling).
// 大概是由于C++的函数可以重载，编译后的名字不可预料，这里保证被编译时按照c语言函数名的规则来编译。
#ifdef __cplusplus
extern "C"
{
#endif

    char *getMD5(char *str)
    {
        string input = str;
        MD5 MD5Instance(str);
        string result = MD5Instance.toStr();
        char *presult = (char *)(result.c_str());
        // 局部变量，需要用malloc申请内存，否则返回时地址会变释放
        char *md5 = (char *)malloc(strlen(presult) + 1);
        if (md5 == NULL)
        {
            exit(1);
        }
        // 把md5首地址存下来
        char *startmd5 = md5;
        // 复制md5字符串到c字符串
        while ((*md5++ = *presult++) != '\0')
        {
            ;
        }
        // 此时指针c已经指向拼接之后的字符串的结尾'\0'，需要返回把md5首地址
        // 返回值是局部malloc申请的指针变量，需在函数调用结束后free之
        return startmd5;
    }

#ifdef __cplusplus
}
#endif

int main()
{
    char var[] = "hello world !";
    char *pvar = var;
    char *result = getMD5(pvar);
    cout << "pvar 串: " << pvar << endl;
    // 如果给cout提供一个指针，它将打印指针所指向的地址单元的地址
    // 但如果指针类型为char *，则cout将打印char *指针所指向的字符串
    cout << "result 串: " << result << endl;
    cout << "result 指针地址: " << (int *)result << endl;
    cout << "result 首字母: " << *result << endl;
    free(result);
    return 0;
}