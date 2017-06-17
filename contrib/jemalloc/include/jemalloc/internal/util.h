begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_UTIL_H
end_define

begin_define
define|#
directive|define
name|UTIL_INLINE
value|static inline
end_define

begin_comment
comment|/* Junk fill patterns. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ALLOC_JUNK
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_ALLOC_JUNK
value|((uint8_t)0xa5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_FREE_JUNK
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_FREE_JUNK
value|((uint8_t)0x5a)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* cpp macro definition stringification. */
end_comment

begin_define
define|#
directive|define
name|STRINGIFY_HELPER
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|STRINGIFY
parameter_list|(
name|x
parameter_list|)
value|STRINGIFY_HELPER(x)
end_define

begin_comment
comment|/*  * Silence compiler warnings due to uninitialized values.  This is used  * wherever the compiler fails to recognize that the variable is never used  * uninitialized.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_CC_SILENCE_INIT
parameter_list|(
name|v
parameter_list|)
value|= v
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|!!(x)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|!!(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|JEMALLOC_INTERNAL_UNREACHABLE
argument_list|)
end_if

begin_error
error|#
directive|error
error|JEMALLOC_INTERNAL_UNREACHABLE should have been defined by configure
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|unreachable
parameter_list|()
value|JEMALLOC_INTERNAL_UNREACHABLE()
end_define

begin_comment
comment|/* Set error code. */
end_comment

begin_function
name|UTIL_INLINE
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
comment|/* Get last error code. */
end_comment

begin_function
name|UTIL_INLINE
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
name|GetLastError
argument_list|()
return|;
else|#
directive|else
return|return
name|errno
return|;
endif|#
directive|endif
block|}
end_function

begin_undef
undef|#
directive|undef
name|UTIL_INLINE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_UTIL_H */
end_comment

end_unit

