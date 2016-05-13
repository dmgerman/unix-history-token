begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_define
define|#
directive|define
name|FMT64_PREFIX
value|"ll"
end_define

begin_define
define|#
directive|define
name|FMTPTR_PREFIX
value|"ll"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FMT64_PREFIX
value|"ll"
end_define

begin_define
define|#
directive|define
name|FMTPTR_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FMTd32
value|"d"
end_define

begin_define
define|#
directive|define
name|FMTu32
value|"u"
end_define

begin_define
define|#
directive|define
name|FMTx32
value|"x"
end_define

begin_define
define|#
directive|define
name|FMTd64
value|FMT64_PREFIX "d"
end_define

begin_define
define|#
directive|define
name|FMTu64
value|FMT64_PREFIX "u"
end_define

begin_define
define|#
directive|define
name|FMTx64
value|FMT64_PREFIX "x"
end_define

begin_define
define|#
directive|define
name|FMTdPTR
value|FMTPTR_PREFIX "d"
end_define

begin_define
define|#
directive|define
name|FMTuPTR
value|FMTPTR_PREFIX "u"
end_define

begin_define
define|#
directive|define
name|FMTxPTR
value|FMTPTR_PREFIX "x"
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_define
define|#
directive|define
name|FMTd32
value|PRId32
end_define

begin_define
define|#
directive|define
name|FMTu32
value|PRIu32
end_define

begin_define
define|#
directive|define
name|FMTx32
value|PRIx32
end_define

begin_define
define|#
directive|define
name|FMTd64
value|PRId64
end_define

begin_define
define|#
directive|define
name|FMTu64
value|PRIu64
end_define

begin_define
define|#
directive|define
name|FMTx64
value|PRIx64
end_define

begin_define
define|#
directive|define
name|FMTdPTR
value|PRIdPTR
end_define

begin_define
define|#
directive|define
name|FMTuPTR
value|PRIuPTR
end_define

begin_define
define|#
directive|define
name|FMTxPTR
value|PRIxPTR
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Junk fill patterns. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_ALLOC_JUNK
value|((uint8_t)0xa5)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_FREE_JUNK
value|((uint8_t)0x5a)
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

begin_define
define|#
directive|define
name|JEMALLOC_GNUC_PREREQ
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|(!defined(__clang__)&&						\     (__GNUC__> (major) || (__GNUC__ == (major)&& __GNUC_MINOR__>= (minor))))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__has_builtin
end_ifndef

begin_define
define|#
directive|define
name|__has_builtin
parameter_list|(
name|builtin
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JEMALLOC_CLANG_HAS_BUILTIN
parameter_list|(
name|builtin
parameter_list|)
define|\
value|(defined(__clang__)&& __has_builtin(builtin))
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

begin_if
if|#
directive|if
name|JEMALLOC_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|6
argument_list|)
operator|||
expr|\
name|JEMALLOC_CLANG_HAS_BUILTIN
argument_list|(
name|__builtin_unreachable
argument_list|)
end_if

begin_define
define|#
directive|define
name|unreachable
parameter_list|()
value|__builtin_unreachable()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|unreachable
parameter_list|()
value|abort()
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|unreachable
parameter_list|()
value|abort()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"jemalloc/internal/assert.h"
end_include

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
value|do {							\ 	if (unlikely(!(c)))						\ 		not_reached();						\ } while (0)
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
name|size_t
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
name|size_t
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
function_decl|JEMALLOC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
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
function_decl|JEMALLOC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
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
function_decl|JEMALLOC_FORMAT_PRINTF
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
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
name|unsigned
name|ffs_llu
parameter_list|(
name|unsigned
name|long
name|long
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|ffs_lu
parameter_list|(
name|unsigned
name|long
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|ffs_u
parameter_list|(
name|unsigned
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|ffs_zu
parameter_list|(
name|size_t
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|ffs_u64
parameter_list|(
name|uint64_t
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|ffs_u32
parameter_list|(
name|uint32_t
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|pow2_ceil_u64
parameter_list|(
name|uint64_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|pow2_ceil_u32
parameter_list|(
name|uint32_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|pow2_ceil_zu
parameter_list|(
name|size_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|lg_floor
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
comment|/* Sanity check. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|JEMALLOC_INTERNAL_FFSLL
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|JEMALLOC_INTERNAL_FFSL
argument_list|)
expr|\
operator|||
operator|!
name|defined
argument_list|(
name|JEMALLOC_INTERNAL_FFS
argument_list|)
end_if

begin_error
error|#
directive|error
error|JEMALLOC_INTERNAL_FFS{,L,LL} should have been defined by configure
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|unsigned
name|ffs_llu
parameter_list|(
name|unsigned
name|long
name|long
name|bitmap
parameter_list|)
block|{
return|return
operator|(
name|JEMALLOC_INTERNAL_FFSLL
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|unsigned
name|ffs_lu
parameter_list|(
name|unsigned
name|long
name|bitmap
parameter_list|)
block|{
return|return
operator|(
name|JEMALLOC_INTERNAL_FFSL
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|unsigned
name|ffs_u
parameter_list|(
name|unsigned
name|bitmap
parameter_list|)
block|{
return|return
operator|(
name|JEMALLOC_INTERNAL_FFS
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|unsigned
name|ffs_zu
parameter_list|(
name|size_t
name|bitmap
parameter_list|)
block|{
if|#
directive|if
name|LG_SIZEOF_PTR
operator|==
name|LG_SIZEOF_INT
return|return
operator|(
name|ffs_u
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
elif|#
directive|elif
name|LG_SIZEOF_PTR
operator|==
name|LG_SIZEOF_LONG
return|return
operator|(
name|ffs_lu
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
elif|#
directive|elif
name|LG_SIZEOF_PTR
operator|==
name|LG_SIZEOF_LONG_LONG
return|return
operator|(
name|ffs_llu
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
else|#
directive|else
error|#
directive|error
error|No implementation for size_t ffs()
endif|#
directive|endif
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|unsigned
name|ffs_u64
parameter_list|(
name|uint64_t
name|bitmap
parameter_list|)
block|{
if|#
directive|if
name|LG_SIZEOF_LONG
operator|==
literal|3
return|return
operator|(
name|ffs_lu
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
elif|#
directive|elif
name|LG_SIZEOF_LONG_LONG
operator|==
literal|3
return|return
operator|(
name|ffs_llu
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
else|#
directive|else
error|#
directive|error
error|No implementation for 64-bit ffs()
endif|#
directive|endif
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|unsigned
name|ffs_u32
parameter_list|(
name|uint32_t
name|bitmap
parameter_list|)
block|{
if|#
directive|if
name|LG_SIZEOF_INT
operator|==
literal|2
return|return
operator|(
name|ffs_u
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
else|#
directive|else
error|#
directive|error
error|No implementation for 32-bit ffs()
endif|#
directive|endif
return|return
operator|(
name|ffs_u
argument_list|(
name|bitmap
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|uint64_t
name|pow2_ceil_u64
parameter_list|(
name|uint64_t
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
name|x
operator||=
name|x
operator|>>
literal|32
expr_stmt|;
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

begin_function
name|JEMALLOC_INLINE
name|uint32_t
name|pow2_ceil_u32
parameter_list|(
name|uint32_t
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
comment|/* Compute the smallest power of 2 that is>= x. */
end_comment

begin_function
name|JEMALLOC_INLINE
name|size_t
name|pow2_ceil_zu
parameter_list|(
name|size_t
name|x
parameter_list|)
block|{
if|#
directive|if
operator|(
name|LG_SIZEOF_PTR
operator|==
literal|3
operator|)
return|return
operator|(
name|pow2_ceil_u64
argument_list|(
name|x
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|pow2_ceil_u32
argument_list|(
name|x
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
end_if

begin_function
name|JEMALLOC_INLINE
name|unsigned
name|lg_floor
parameter_list|(
name|size_t
name|x
parameter_list|)
block|{
name|size_t
name|ret
decl_stmt|;
name|assert
argument_list|(
name|x
operator|!=
literal|0
argument_list|)
expr_stmt|;
asm|asm ("bsr %1, %0" 	    : "=r"(ret)
comment|// Outputs.
asm|: "r"(x)
comment|// Inputs.
asm|);
name|assert
argument_list|(
name|ret
operator|<
name|UINT_MAX
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|unsigned
operator|)
name|ret
operator|)
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|)
end_elif

begin_function
name|JEMALLOC_INLINE
name|unsigned
name|lg_floor
parameter_list|(
name|size_t
name|x
parameter_list|)
block|{
name|unsigned
name|long
name|ret
decl_stmt|;
name|assert
argument_list|(
name|x
operator|!=
literal|0
argument_list|)
expr_stmt|;
if|#
directive|if
operator|(
name|LG_SIZEOF_PTR
operator|==
literal|3
operator|)
name|_BitScanReverse64
argument_list|(
operator|&
name|ret
argument_list|,
name|x
argument_list|)
expr_stmt|;
elif|#
directive|elif
operator|(
name|LG_SIZEOF_PTR
operator|==
literal|2
operator|)
name|_BitScanReverse
argument_list|(
operator|&
name|ret
argument_list|,
name|x
argument_list|)
expr_stmt|;
else|#
directive|else
error|#
directive|error
literal|"Unsupported type size for lg_floor()"
endif|#
directive|endif
name|assert
argument_list|(
name|ret
operator|<
name|UINT_MAX
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|unsigned
operator|)
name|ret
operator|)
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_HAVE_BUILTIN_CLZ
argument_list|)
operator|)
end_elif

begin_function
name|JEMALLOC_INLINE
name|unsigned
name|lg_floor
parameter_list|(
name|size_t
name|x
parameter_list|)
block|{
name|assert
argument_list|(
name|x
operator|!=
literal|0
argument_list|)
expr_stmt|;
if|#
directive|if
operator|(
name|LG_SIZEOF_PTR
operator|==
name|LG_SIZEOF_INT
operator|)
return|return
operator|(
operator|(
operator|(
literal|8
operator|<<
name|LG_SIZEOF_PTR
operator|)
operator|-
literal|1
operator|)
operator|-
name|__builtin_clz
argument_list|(
name|x
argument_list|)
operator|)
return|;
elif|#
directive|elif
operator|(
name|LG_SIZEOF_PTR
operator|==
name|LG_SIZEOF_LONG
operator|)
return|return
operator|(
operator|(
operator|(
literal|8
operator|<<
name|LG_SIZEOF_PTR
operator|)
operator|-
literal|1
operator|)
operator|-
name|__builtin_clzl
argument_list|(
name|x
argument_list|)
operator|)
return|;
else|#
directive|else
error|#
directive|error
literal|"Unsupported type size for lg_floor()"
endif|#
directive|endif
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|JEMALLOC_INLINE
name|unsigned
name|lg_floor
parameter_list|(
name|size_t
name|x
parameter_list|)
block|{
name|assert
argument_list|(
name|x
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|x
operator||=
operator|(
name|x
operator|>>
literal|1
operator|)
expr_stmt|;
name|x
operator||=
operator|(
name|x
operator|>>
literal|2
operator|)
expr_stmt|;
name|x
operator||=
operator|(
name|x
operator|>>
literal|4
operator|)
expr_stmt|;
name|x
operator||=
operator|(
name|x
operator|>>
literal|8
operator|)
expr_stmt|;
name|x
operator||=
operator|(
name|x
operator|>>
literal|16
operator|)
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
operator|(
name|x
operator|>>
literal|32
operator|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|x
operator|==
name|SIZE_T_MAX
condition|)
return|return
operator|(
operator|(
literal|8
operator|<<
name|LG_SIZEOF_PTR
operator|)
operator|-
literal|1
operator|)
return|;
name|x
operator|++
expr_stmt|;
return|return
operator|(
name|ffs_zu
argument_list|(
name|x
argument_list|)
operator|-
literal|2
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set error code. */
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
comment|/* Get last error code. */
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

