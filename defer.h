#ifndef __DEFER_H__
#define __DEFER_H__


#define _defer_concat(x, y) x ## y
#define defer_concat(x, y) _defer_concat(x, y)
#define defer(block)     \
void defer_concat( defer_func, __LINE__ )(){block;} \
__attribute__((cleanup(defer_concat( defer_func, __LINE__ )))) char defer_concat( defer_var, __LINE__ )


#endif  // __DEFER_H__
