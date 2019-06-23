### 格式

int* a;
与
int *a

### char 指针

char *out
char *md5
// out = md5;
// 有啥区别？？为什么=不行
strncpy(out, md5, 128);


### emcc 最大分配内存

Uncaught abort("Stack overflow! Attempted to allocate 40000001 bytes on the stack, but stack has only 5242865 bytes available!") at Error
