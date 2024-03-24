#include "estr.h"

char* str_poly_concat(int n_args, ...)
{
    va_list arg;
    va_start(arg, n_args);
    char* result = va_arg(arg, char*);
    for (int i = 1; i < n_args; ++i)
        result = str_concat(result, va_arg(arg, char*));
    va_end(arg);
    return result;
}
