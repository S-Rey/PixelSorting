
#pragma once

/**
 * @file error.h
 * @brief file system error codes
 *
 * @author Edouard Bugnion
 * @date summer 2016
 */

#ifdef DEBUG
#include <stdio.h> // for fprintf
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief filesytem internal error codes.
 *
 */
enum error_codes {
	ERR_FIRST = -128, // not an actual error but to set the first error number
	ERR_NOT_ENOUGH_ARGUMENT,
	ERR_LAST // not an actual error but to have e.g. the total number of errors
};

/*
 * Helpers (macros)
 */

#ifdef DEBUG
#define debug_print(fmt, ...) \
    fprintf(stderr, fmt, __VA_ARGS__)
#else
#define debug_print(fmt, ...) \
    do {} while(0)
#endif

#define M_REQUIRE_NON_NULL(arg) \
    do { \
        if (arg == NULL) { \
            debug_print("ERROR: parameter %s is NULL when calling  %s() (defined in %s)\n", \
                        #arg, __func__, __FILE__); \
            return ERR_BAD_PARAMETER; \
        } \
    } while(0)

/**
* @brief filesystem internal error messages. defined in error.c
*
*/
extern
const char * const ERR_MESSAGES[];

#ifdef __cplusplus
}
#


