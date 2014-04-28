begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_comment
comment|/* Size of stack-allocated buffer passed to buferror(). */
end_comment

begin_define
define|#
directive|define
name|BUFERROR_BUF
value|64
end_define

begin_comment
comment|/*  * Size of stack-allocated buffer used by malloc_{,v,vc}printf().  This must be  * large enough for all possible uses within jemalloc.  */
end_comment

begin_define
define|#
directive|define
name|MALLOC_PRINTF_BUFSIZE
value|4096
end_define

begin_comment
comment|/*  * Wrap a cpp argument that contains commas such that it isn't broken up into  * multiple arguments.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_ARG_CONCAT
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
end_define

begin_comment
comment|/*  * Silence compiler warnings due to uninitialized values.  This is used  * wherever the compiler fails to recognize that the variable is never used  * uninitialized.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_CC_SILENCE
end_ifdef

begin_define
define|#
directive|define
name|JEMALLOC_CC_SILENCE_INIT
parameter_list|(
name|v
parameter_list|)
value|= v
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JEMALLOC_CC_SILENCE_INIT
parameter_list|(
name|v
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define a custom assert() in order to reduce the chances of deadlock during  * assertion failure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|assert
end_ifndef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|e
parameter_list|)
value|do {							\ 	if (config_debug&& !(e)) {					\ 		malloc_printf(						\ 		    "<jemalloc>: %s:%d: Failed assertion: \"%s\"\n",	\ 		    __FILE__, __LINE__, #e);				\ 		abort();						\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|not_reached
end_ifndef

begin_define
define|#
directive|define
name|not_reached
parameter_list|()
value|do {						\ 	if (config_debug) {						\ 		malloc_printf(						\ 		    "<jemalloc>: %s:%d: Unreachable code reached\n",	\ 		    __FILE__, __LINE__);				\ 		abort();						\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|not_implemented
end_ifndef

begin_define
define|#
directive|define
name|not_implemented
parameter_list|()
value|do {						\ 	if (config_debug) {						\ 		malloc_printf("<jemalloc>: %s:%d: Not implemented\n",	\ 		    __FILE__, __LINE__);				\ 		abort();						\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|assert_not_implemented
end_ifndef

begin_define
define|#
directive|define
name|assert_not_implemented
parameter_list|(
name|e
parameter_list|)
value|do {					\ 	if (config_debug&& !(e))					\ 		not_implemented();					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use to assert a particular configuration, e.g., cassert(config_debug). */
end_comment

begin_define
define|#
directive|define
name|cassert
parameter_list|(
name|c
parameter_list|)
value|do {							\ 	if ((c) == false)						\ 		not_reached();						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_function_decl
name|int
name|buferror
parameter_list|(
name|int
name|err
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintmax_t
name|malloc_strtoumax
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
specifier|restrict
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_write
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * malloc_vsnprintf() supports a subset of snprintf(3) that avoids floating  * point math.  */
end_comment

begin_function_decl
name|int
name|malloc_vsnprintf
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
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malloc_snprintf
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
function_decl|JEMALLOC_ATTR
parameter_list|(
function_decl|format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|malloc_vcprintf
parameter_list|(
name|void
function_decl|(
modifier|*
name|write_cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbopaque
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_cprintf
parameter_list|(
name|void
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbopaque
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
function_decl|format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|malloc_printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
function_decl|format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_function_decl
name|size_t
name|pow2_ceil
parameter_list|(
name|size_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_errno
parameter_list|(
name|int
name|errnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_errno
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|JEMALLOC_ENABLE_INLINE
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_UTIL_C_
argument_list|)
operator|)
end_if

begin_comment
comment|/* Compute the smallest power of 2 that is>= x. */
end_comment

begin_function
name|JEMALLOC_INLINE
name|size_t
name|pow2_ceil
parameter_list|(
name|size_t
name|x
parameter_list|)
block|{
name|x
operator|--
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|1
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|2
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|4
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|8
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|16
expr_stmt|;
if|#
directive|if
operator|(
name|LG_SIZEOF_PTR
operator|==
literal|3
operator|)
name|x
operator||=
name|x
operator|>>
literal|32
expr_stmt|;
endif|#
directive|endif
name|x
operator|++
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Sets error code */
end_comment

begin_function
name|JEMALLOC_INLINE
name|void
name|set_errno
parameter_list|(
name|int
name|errnum
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_WIN32
name|SetLastError
argument_list|(
name|errnum
argument_list|)
expr_stmt|;
else|#
directive|else
name|errno
operator|=
name|errnum
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Get last error code */
end_comment

begin_function
name|JEMALLOC_INLINE
name|int
name|get_errno
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_WIN32
return|return
operator|(
name|GetLastError
argument_list|()
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|errno
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

