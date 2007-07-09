begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd / OS specific functions  * Copyright (c) 2005-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OS_H
end_ifndef

begin_define
define|#
directive|define
name|OS_H
end_define

begin_typedef
typedef|typedef
name|long
name|os_time_t
typedef|;
end_typedef

begin_comment
comment|/**  * os_sleep - Sleep (sec, usec)  * @sec: Number of seconds to sleep  * @usec: Number of microseconds to sleep  */
end_comment

begin_function_decl
name|void
name|os_sleep
parameter_list|(
name|os_time_t
name|sec
parameter_list|,
name|os_time_t
name|usec
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|os_time
block|{
name|os_time_t
name|sec
decl_stmt|;
name|os_time_t
name|usec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * os_get_time - Get current time (sec, usec)  * @t: Pointer to buffer for the time  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|os_get_time
parameter_list|(
name|struct
name|os_time
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper macros for handling struct os_time */
end_comment

begin_define
define|#
directive|define
name|os_time_before
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((a)->sec< (b)->sec || \ 	 ((a)->sec == (b)->sec&& (a)->usec< (b)->usec))
end_define

begin_define
define|#
directive|define
name|os_time_sub
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|res
parameter_list|)
value|do { \ 	(res)->sec = (a)->sec - (b)->sec; \ 	(res)->usec = (a)->usec - (b)->usec; \ 	if ((res)->usec< 0) { \ 		(res)->sec--; \ 		(res)->usec += 1000000; \ 	} \ } while (0)
end_define

begin_comment
comment|/**  * os_mktime - Convert broken-down time into seconds since 1970-01-01  * @year: Four digit year  * @month: Month (1 .. 12)  * @day: Day of month (1 .. 31)  * @hour: Hour (0 .. 23)  * @min: Minute (0 .. 59)  * @sec: Second (0 .. 60)  * @t: Buffer for returning calendar time representation (seconds since  * 1970-01-01 00:00:00)  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|os_mktime
parameter_list|(
name|int
name|year
parameter_list|,
name|int
name|month
parameter_list|,
name|int
name|day
parameter_list|,
name|int
name|hour
parameter_list|,
name|int
name|min
parameter_list|,
name|int
name|sec
parameter_list|,
name|os_time_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_daemonize - Run in the background (detach from the controlling terminal)  * @pid_file: File name to write the process ID to or %NULL to skip this  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|os_daemonize
parameter_list|(
specifier|const
name|char
modifier|*
name|pid_file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_daemonize_terminate - Stop running in the background (remove pid file)  * @pid_file: File name to write the process ID to or %NULL to skip this  */
end_comment

begin_function_decl
name|void
name|os_daemonize_terminate
parameter_list|(
specifier|const
name|char
modifier|*
name|pid_file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_get_random - Get cryptographically strong pseudo random data  * @buf: Buffer for pseudo random data  * @len: Length of the buffer  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|os_get_random
parameter_list|(
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_random - Get pseudo random value (not necessarily very strong)  * Returns: Pseudo random value  */
end_comment

begin_function_decl
name|unsigned
name|long
name|os_random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_rel2abs_path - Get an absolute path for a file  * @rel_path: Relative path to a file  * Returns: Absolute path for the file or %NULL on failure  *  * This function tries to convert a relative path of a file to an absolute path  * in order for the file to be found even if current working directory has  * changed. The returned value is allocated and caller is responsible for  * freeing it. It is acceptable to just return the same path in an allocated  * buffer, e.g., return strdup(rel_path). This function is only used to find  * configuration files when os_daemonize() may have changed the current working  * directory and relative path would be pointing to a different location.  */
end_comment

begin_function_decl
name|char
modifier|*
name|os_rel2abs_path
parameter_list|(
specifier|const
name|char
modifier|*
name|rel_path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_program_init - Program initialization (called at start)  * Returns: 0 on success, -1 on failure  *  * This function is called when a programs starts. If there are any OS specific  * processing that is needed, it can be placed here. It is also acceptable to  * just return 0 if not special processing is needed.  */
end_comment

begin_function_decl
name|int
name|os_program_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_program_deinit - Program deinitialization (called just before exit)  *  * This function is called just before a program exists. If there are any OS  * specific processing, e.g., freeing resourced allocated in os_program_init(),  * it should be done here. It is also acceptable for this function to do  * nothing.  */
end_comment

begin_function_decl
name|void
name|os_program_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_setenv - Set environment variable  * @name: Name of the variable  * @value: Value to set to the variable  * @overwrite: Whether existing variable should be overwritten  * Returns: 0 on success, -1 on error  *  * This function is only used for wpa_cli action scripts. OS wrapper does not  * need to implement this if such functionality is not needed.  */
end_comment

begin_function_decl
name|int
name|os_setenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|int
name|overwrite
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_unsetenv - Delete environent variable  * @name: Name of the variable  * Returns: 0 on success, -1 on error  *  * This function is only used for wpa_cli action scripts. OS wrapper does not  * need to implement this if such functionality is not needed.  */
end_comment

begin_function_decl
name|int
name|os_unsetenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_readfile - Read a file to an allocated memory buffer  * @name: Name of the file to read  * @len: For returning the length of the allocated buffer  * Returns: Pointer to the allocated buffer or %NULL on failure  *  * This function allocates memory and reads the given file to this buffer. Both  * binary and text files can be read with this function. The caller is  * responsible for freeing the returned buffer with os_free().  */
end_comment

begin_function_decl
name|char
modifier|*
name|os_readfile
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_zalloc - Allocate and zero memory  * @size: Number of bytes to allocate  * Returns: Pointer to allocated and zeroed memory or %NULL on failure  *  * Caller is responsible for freeing the returned buffer with os_free().  */
end_comment

begin_function_decl
name|void
modifier|*
name|os_zalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The following functions are wrapper for standard ANSI C or POSIX functions.  * By default, they are just defined to use the standard function name and no  * os_*.c implementation is needed for them. This avoids extra function calls  * by allowing the C pre-processor take care of the function name mapping.  *  * If the target system uses a C library that does not provide these functions,  * build_config.h can be used to define the wrappers to use a different  * function name. This can be done on function-by-function basis since the  * defines here are only used if build_config.h does not define the os_* name.  * If needed, os_*.c file can be used to implement the functions that are not  * included in the C library on the target system. Alternatively,  * OS_NO_C_LIB_DEFINES can be defined to skip all defines here in which case  * these functions need to be implemented in os_*.c file for the target system.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS_NO_C_LIB_DEFINES
end_ifdef

begin_comment
comment|/**  * os_malloc - Allocate dynamic memory  * @size: Size of the buffer to allocate  * Returns: Allocated buffer or %NULL on failure  *  * Caller is responsible for freeing the returned buffer with os_free().  */
end_comment

begin_function_decl
name|void
modifier|*
name|os_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_realloc - Re-allocate dynamic memory  * @ptr: Old buffer from os_malloc() or os_realloc()  * @size: Size of the new buffer  * Returns: Allocated buffer or %NULL on failure  *  * Caller is responsible for freeing the returned buffer with os_free().  * If re-allocation fails, %NULL is returned and the original buffer (ptr) is  * not freed and caller is still responsible for freeing it.  */
end_comment

begin_function_decl
name|void
modifier|*
name|os_realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_free - Free dynamic memory  * @ptr: Old buffer from os_malloc() or os_realloc(); can be %NULL  */
end_comment

begin_function_decl
name|void
name|os_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_memcpy - Copy memory area  * @dest: Destination  * @src: Source  * @n: Number of bytes to copy  * Returns: dest  *  * The memory areas src and dst must not overlap. os_memmove() can be used with  * overlapping memory.  */
end_comment

begin_function_decl
name|void
modifier|*
name|os_memcpy
parameter_list|(
name|void
modifier|*
name|dest
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_memmove - Copy memory area  * @dest: Destination  * @src: Source  * @n: Number of bytes to copy  * Returns: dest  *  * The memory areas src and dst may overlap.  */
end_comment

begin_function_decl
name|void
modifier|*
name|os_memmove
parameter_list|(
name|void
modifier|*
name|dest
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_memset - Fill memory with a constant byte  * @s: Memory area to be filled  * @c: Constant byte  * @n: Number of bytes started from s to fill with c  * Returns: s  */
end_comment

begin_function_decl
name|void
modifier|*
name|os_memset
parameter_list|(
name|void
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_memcmp - Compare memory areas  * @s1: First buffer  * @s2: Second buffer  * @n: Maximum numbers of octets to compare  * Returns: An integer less than, equal to, or greater than zero if s1 is  * found to be less than, to match, or be greater than s2. Only first n  * characters will be compared.  */
end_comment

begin_function_decl
name|int
name|os_memcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strdup - Duplicate a string  * @s: Source string  * Returns: Allocated buffer with the string copied into it or %NULL on failure  *  * Caller is responsible for freeing the returned buffer with os_free().  */
end_comment

begin_function_decl
name|char
modifier|*
name|os_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strlen - Calculate the length of a string  * @s: '\0' terminated string  * Returns: Number of characters in s (not counting the '\0' terminator)  */
end_comment

begin_function_decl
name|size_t
name|os_strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strcasecmp - Compare two strings ignoring case  * @s1: First string  * @s2: Second string  * Returns: An integer less than, equal to, or greater than zero if s1 is  * found to be less than, to match, or be greatred than s2  */
end_comment

begin_function_decl
name|int
name|os_strcasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strncasecmp - Compare two strings ignoring case  * @s1: First string  * @s2: Second string  * @n: Maximum numbers of characters to compare  * Returns: An integer less than, equal to, or greater than zero if s1 is  * found to be less than, to match, or be greater than s2. Only first n  * characters will be compared.  */
end_comment

begin_function_decl
name|int
name|os_strncasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strchr - Locate the first occurrence of a character in string  * @s: String  * @c: Character to search for  * Returns: Pointer to the matched character or %NULL if not found  */
end_comment

begin_function_decl
name|char
modifier|*
name|os_strchr
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strrchr - Locate the last occurrence of a character in string  * @s: String  * @c: Character to search for  * Returns: Pointer to the matched character or %NULL if not found  */
end_comment

begin_function_decl
name|char
modifier|*
name|os_strrchr
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strcmp - Compare two strings  * @s1: First string  * @s2: Second string  * Returns: An integer less than, equal to, or greater than zero if s1 is  * found to be less than, to match, or be greatred than s2  */
end_comment

begin_function_decl
name|int
name|os_strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strncmp - Compare two strings  * @s1: First string  * @s2: Second string  * @n: Maximum numbers of characters to compare  * Returns: An integer less than, equal to, or greater than zero if s1 is  * found to be less than, to match, or be greater than s2. Only first n  * characters will be compared.  */
end_comment

begin_function_decl
name|int
name|os_strncmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strncpy - Copy a string  * @dest: Destination  * @src: Source  * @n: Maximum number of characters to copy  * Returns: dest  */
end_comment

begin_function_decl
name|char
modifier|*
name|os_strncpy
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_strstr - Locate a substring  * @haystack: String (haystack) to search from  * @needle: Needle to search from haystack  * Returns: Pointer to the beginning of the substring or %NULL if not found  */
end_comment

begin_function_decl
name|char
modifier|*
name|os_strstr
parameter_list|(
specifier|const
name|char
modifier|*
name|haystack
parameter_list|,
specifier|const
name|char
modifier|*
name|needle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * os_snprintf - Print to a memory buffer  * @str: Memory buffer to print into  * @size: Maximum length of the str buffer  * @format: printf format  * Returns: Number of characters printed (not including trailing '\0').  *  * If the output buffer is truncated, number of characters which would have  * been written is returned. Since some C libraries return -1 in such a case,  * the caller must be prepared on that value, too, to indicate truncation.  *  * Note: Some C library implementations of snprintf() may not guarantee null  * termination in case the output is truncated. The OS wrapper function of  * os_snprintf() should provide this guarantee, i.e., to null terminate the  * output buffer if a C library version of the function is used and if that  * function does not guarantee null termination.  *  * If the target system does not include snprintf(), see, e.g.,  * http://www.ijs.si/software/snprintf/ for an example of a portable  * implementation of snprintf.  */
end_comment

begin_function_decl
name|int
name|os_snprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OS_NO_C_LIB_DEFINES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|os_malloc
end_ifndef

begin_define
define|#
directive|define
name|os_malloc
parameter_list|(
name|s
parameter_list|)
value|malloc((s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_realloc
end_ifndef

begin_define
define|#
directive|define
name|os_realloc
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|realloc((p), (s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_free
end_ifndef

begin_define
define|#
directive|define
name|os_free
parameter_list|(
name|p
parameter_list|)
value|free((p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_memcpy
end_ifndef

begin_define
define|#
directive|define
name|os_memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|memcpy((d), (s), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_memmove
end_ifndef

begin_define
define|#
directive|define
name|os_memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|memmove((d), (s), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_memset
end_ifndef

begin_define
define|#
directive|define
name|os_memset
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|memset(s, c, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_memcmp
end_ifndef

begin_define
define|#
directive|define
name|os_memcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|memcmp((s1), (s2), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strdup
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|os_strdup
parameter_list|(
name|s
parameter_list|)
value|_strdup(s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|os_strdup
parameter_list|(
name|s
parameter_list|)
value|strdup(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strlen
end_ifndef

begin_define
define|#
directive|define
name|os_strlen
parameter_list|(
name|s
parameter_list|)
value|strlen(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strcasecmp
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|os_strcasecmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|_stricmp((s1), (s2))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|os_strcasecmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcasecmp((s1), (s2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strncasecmp
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|os_strncasecmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|_strnicmp((s1), (s2), (n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|os_strncasecmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|strncasecmp((s1), (s2), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strchr
end_ifndef

begin_define
define|#
directive|define
name|os_strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|strchr((s), (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strcmp
end_ifndef

begin_define
define|#
directive|define
name|os_strcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcmp((s1), (s2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strncmp
end_ifndef

begin_define
define|#
directive|define
name|os_strncmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|strncmp((s1), (s2), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strncpy
end_ifndef

begin_define
define|#
directive|define
name|os_strncpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strncpy((d), (s), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strrchr
end_ifndef

begin_define
define|#
directive|define
name|os_strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|strrchr((s), (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_strstr
end_ifndef

begin_define
define|#
directive|define
name|os_strstr
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
value|strstr((h), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|os_snprintf
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|os_snprintf
value|_snprintf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|os_snprintf
value|snprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS_NO_C_LIB_DEFINES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS_REJECT_C_LIB_FUNCTIONS
end_ifdef

begin_define
define|#
directive|define
name|malloc
value|OS_DO_NOT_USE_malloc
end_define

begin_define
define|#
directive|define
name|realloc
value|OS_DO_NOT_USE_realloc
end_define

begin_define
define|#
directive|define
name|free
value|OS_DO_NOT_USE_free
end_define

begin_define
define|#
directive|define
name|memcpy
value|OS_DO_NOT_USE_memcpy
end_define

begin_define
define|#
directive|define
name|memmove
value|OS_DO_NOT_USE_memmove
end_define

begin_define
define|#
directive|define
name|memset
value|OS_DO_NOT_USE_memset
end_define

begin_define
define|#
directive|define
name|memcmp
value|OS_DO_NOT_USE_memcmp
end_define

begin_undef
undef|#
directive|undef
name|strdup
end_undef

begin_define
define|#
directive|define
name|strdup
value|OS_DO_NOT_USE_strdup
end_define

begin_define
define|#
directive|define
name|strlen
value|OS_DO_NOT_USE_strlen
end_define

begin_define
define|#
directive|define
name|strcasecmp
value|OS_DO_NOT_USE_strcasecmp
end_define

begin_define
define|#
directive|define
name|strncasecmp
value|OS_DO_NOT_USE_strncasecmp
end_define

begin_undef
undef|#
directive|undef
name|strchr
end_undef

begin_define
define|#
directive|define
name|strchr
value|OS_DO_NOT_USE_strchr
end_define

begin_undef
undef|#
directive|undef
name|strcmp
end_undef

begin_define
define|#
directive|define
name|strcmp
value|OS_DO_NOT_USE_strcmp
end_define

begin_undef
undef|#
directive|undef
name|strncmp
end_undef

begin_define
define|#
directive|define
name|strncmp
value|OS_DO_NOT_USE_strncmp
end_define

begin_undef
undef|#
directive|undef
name|strncpy
end_undef

begin_define
define|#
directive|define
name|strncpy
value|OS_DO_NOT_USE_strncpy
end_define

begin_define
define|#
directive|define
name|strrchr
value|OS_DO_NOT_USE_strrchr
end_define

begin_define
define|#
directive|define
name|strstr
value|OS_DO_NOT_USE_strstr
end_define

begin_undef
undef|#
directive|undef
name|snprintf
end_undef

begin_define
define|#
directive|define
name|snprintf
value|OS_DO_NOT_USE_snprintf
end_define

begin_define
define|#
directive|define
name|strcpy
value|OS_DO_NOT_USE_strcpy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS_REJECT_C_LIB_FUNCTIONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS_H */
end_comment

end_unit

