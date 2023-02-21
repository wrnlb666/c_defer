#ifndef __DEFER_H__
#define __DEFER_H__


#define _concat(x, y) x ## y
#define concat(x, y) _concat(x, y)
#define defer(block)     \
void concat( defer_func, __LINE__ )(){block} \
__attribute__((cleanup(concat( defer_func, __LINE__ )))) char concat( defer_var, __LINE__ )


#endif  // __DEFER_H__
