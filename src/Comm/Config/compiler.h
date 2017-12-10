#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C" {
#endif

#define COMPILER_CONCAT_(a, b) a##b
#define COMPILER_CONCAT(a, b) COMPILER_CONCAT_(a, b)

// Divide by zero if the the expression is false.  This
// causes an error at compile time.
//
// The special value '__COUNTER__' is used to create a unique value to
// append to 'compiler_assert_' to create a unique token.  This prevents
// conflicts resulting from the same enum being declared multiple times.
#define COMPILER_ASSERT(e) enum { COMPILER_CONCAT(compiler_assert_, __COUNTER__) = 1/((e) ? 1 : 0) }

#ifdef __cplusplus
}
#endif

#endif
