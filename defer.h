#ifndef __DEFER_H__
#define __DEFER_H__


#define _defer_concat(x, y) x ## y
#define defer_concat(x, y) _defer_concat(x, y)

#if defined __clang__
#include <Block.h>
typedef void (^defer_clang_type)(void);
static void defer_clang_wrapper(void* fn) {
    defer_clang_type* func = (defer_clang_type*)fn;
    (*func)();
}
#define defer(block)    \
__attribute__((cleanup(defer_clang_wrapper)))   \
defer_clang_type defer_concat(defer_func, __LINE__) = ^{block;};    \
(void) defer_concat(defer_func, __LINE__);
#elif defined __GNUC__  //  __clang__
#define defer(block)    \
void defer_concat(defer_func, __LINE__)(){block;};  \
__attribute__((cleanup(defer_concat(defer_func, __LINE__))))    \
char defer_concat(defer_var, __LINE__);
#else   // __GNUC__
#error This can only be used with gcc or clang
#endif  // other compiler


#endif  // __DEFER_H__
