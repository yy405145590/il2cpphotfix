//
// Created by Administrator on 2019/5/14.
//

#ifndef TEST_UPDATE_IL2CPP_API_H
#define TEST_UPDATE_IL2CPP_API_H
# define IL2CPP_EXPORT __attribute__ ((visibility ("default")))
# define IL2CPP_IMPORT
#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus
#define DO_API(r, n, p)             IL2CPP_EXPORT r n p;
#define DO_API_NO_RETURN(r, n, p)   IL2CPP_EXPORT  r n p;
#include "il2cpp-api-functions.h"
#undef DO_API
#undef DO_API_NORETURN
#if defined(__cplusplus)
}
#endif // __cplusplus

#endif //TEST_UPDATE_IL2CPP_API_H
