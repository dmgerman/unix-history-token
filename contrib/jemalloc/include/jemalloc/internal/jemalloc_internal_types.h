begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_TYPES_H
end_define

begin_comment
comment|/* Page size index type. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|pszind_t
typedef|;
end_typedef

begin_comment
comment|/* Size class index type. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|szind_t
typedef|;
end_typedef

begin_comment
comment|/* Processor / core id type. */
end_comment

begin_typedef
typedef|typedef
name|int
name|malloc_cpuid_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags bits:  *  * a: arena  * t: tcache  * 0: unused  * z: zero  * n: alignment  *  * aaaaaaaa aaaatttt tttttttt 0znnnnnn  */
end_comment

begin_define
define|#
directive|define
name|MALLOCX_ARENA_BITS
value|12
end_define

begin_define
define|#
directive|define
name|MALLOCX_TCACHE_BITS
value|12
end_define

begin_define
define|#
directive|define
name|MALLOCX_LG_ALIGN_BITS
value|6
end_define

begin_define
define|#
directive|define
name|MALLOCX_ARENA_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|MALLOCX_TCACHE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MALLOCX_ARENA_MASK
define|\
value|(((1<< MALLOCX_ARENA_BITS) - 1)<< MALLOCX_ARENA_SHIFT)
end_define

begin_comment
comment|/* NB: Arena index bias decreases the maximum number of arenas by 1. */
end_comment

begin_define
define|#
directive|define
name|MALLOCX_ARENA_LIMIT
value|((1<< MALLOCX_ARENA_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|MALLOCX_TCACHE_MASK
define|\
value|(((1<< MALLOCX_TCACHE_BITS) - 1)<< MALLOCX_TCACHE_SHIFT)
end_define

begin_define
define|#
directive|define
name|MALLOCX_TCACHE_MAX
value|((1<< MALLOCX_TCACHE_BITS) - 3)
end_define

begin_define
define|#
directive|define
name|MALLOCX_LG_ALIGN_MASK
value|((1<< MALLOCX_LG_ALIGN_BITS) - 1)
end_define

begin_comment
comment|/* Use MALLOCX_ALIGN_GET() if alignment may not be specified in flags. */
end_comment

begin_define
define|#
directive|define
name|MALLOCX_ALIGN_GET_SPECIFIED
parameter_list|(
name|flags
parameter_list|)
define|\
value|(ZU(1)<< (flags& MALLOCX_LG_ALIGN_MASK))
end_define

begin_define
define|#
directive|define
name|MALLOCX_ALIGN_GET
parameter_list|(
name|flags
parameter_list|)
define|\
value|(MALLOCX_ALIGN_GET_SPECIFIED(flags)& (SIZE_T_MAX-1))
end_define

begin_define
define|#
directive|define
name|MALLOCX_ZERO_GET
parameter_list|(
name|flags
parameter_list|)
define|\
value|((bool)(flags& MALLOCX_ZERO))
end_define

begin_define
define|#
directive|define
name|MALLOCX_TCACHE_GET
parameter_list|(
name|flags
parameter_list|)
define|\
value|(((unsigned)((flags& MALLOCX_TCACHE_MASK)>> MALLOCX_TCACHE_SHIFT)) - 2)
end_define

begin_define
define|#
directive|define
name|MALLOCX_ARENA_GET
parameter_list|(
name|flags
parameter_list|)
define|\
value|(((unsigned)(((unsigned)flags)>> MALLOCX_ARENA_SHIFT)) - 1)
end_define

begin_comment
comment|/* Smallest size class to support. */
end_comment

begin_define
define|#
directive|define
name|TINY_MIN
value|(1U<< LG_TINY_MIN)
end_define

begin_comment
comment|/*  * Minimum allocation alignment is 2^LG_QUANTUM bytes (ignoring tiny size  * classes).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LG_QUANTUM
end_ifndef

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
name|_M_IX86
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

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
name|__sparc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparcv9
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc_v9__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

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
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__arm__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__aarch64__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__hppa__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__mips__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__or1k__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__riscv
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__s390__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__SH4__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__tile__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__le32__
end_ifdef

begin_define
define|#
directive|define
name|LG_QUANTUM
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LG_QUANTUM
end_ifndef

begin_error
error|#
directive|error
literal|"Unknown minimum alignment for architecture; specify via "
end_error

begin_expr_stmt
literal|"--with-lg-quantum"
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|QUANTUM
value|((size_t)(1U<< LG_QUANTUM))
end_define

begin_define
define|#
directive|define
name|QUANTUM_MASK
value|(QUANTUM - 1)
end_define

begin_comment
comment|/* Return the smallest quantum multiple that is>= a. */
end_comment

begin_define
define|#
directive|define
name|QUANTUM_CEILING
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a) + QUANTUM_MASK)& ~QUANTUM_MASK)
end_define

begin_define
define|#
directive|define
name|LONG
value|((size_t)(1U<< LG_SIZEOF_LONG))
end_define

begin_define
define|#
directive|define
name|LONG_MASK
value|(LONG - 1)
end_define

begin_comment
comment|/* Return the smallest long multiple that is>= a. */
end_comment

begin_define
define|#
directive|define
name|LONG_CEILING
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a) + LONG_MASK)& ~LONG_MASK)
end_define

begin_define
define|#
directive|define
name|SIZEOF_PTR
value|(1U<< LG_SIZEOF_PTR)
end_define

begin_define
define|#
directive|define
name|PTR_MASK
value|(SIZEOF_PTR - 1)
end_define

begin_comment
comment|/* Return the smallest (void *) multiple that is>= a. */
end_comment

begin_define
define|#
directive|define
name|PTR_CEILING
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a) + PTR_MASK)& ~PTR_MASK)
end_define

begin_comment
comment|/*  * Maximum size of L1 cache line.  This is used to avoid cache line aliasing.  * In addition, this controls the spacing of cacheline-spaced size classes.  *  * CACHELINE cannot be based on LG_CACHELINE because __declspec(align()) can  * only handle raw constants.  */
end_comment

begin_define
define|#
directive|define
name|LG_CACHELINE
value|6
end_define

begin_define
define|#
directive|define
name|CACHELINE
value|64
end_define

begin_define
define|#
directive|define
name|CACHELINE_MASK
value|(CACHELINE - 1)
end_define

begin_comment
comment|/* Return the smallest cacheline multiple that is>= s. */
end_comment

begin_define
define|#
directive|define
name|CACHELINE_CEILING
parameter_list|(
name|s
parameter_list|)
define|\
value|(((s) + CACHELINE_MASK)& ~CACHELINE_MASK)
end_define

begin_comment
comment|/* Return the nearest aligned address at or below a. */
end_comment

begin_define
define|#
directive|define
name|ALIGNMENT_ADDR2BASE
parameter_list|(
name|a
parameter_list|,
name|alignment
parameter_list|)
define|\
value|((void *)((uintptr_t)(a)& ((~(alignment)) + 1)))
end_define

begin_comment
comment|/* Return the offset between a and the nearest aligned address at or below a. */
end_comment

begin_define
define|#
directive|define
name|ALIGNMENT_ADDR2OFFSET
parameter_list|(
name|a
parameter_list|,
name|alignment
parameter_list|)
define|\
value|((size_t)((uintptr_t)(a)& (alignment - 1)))
end_define

begin_comment
comment|/* Return the smallest alignment multiple that is>= s. */
end_comment

begin_define
define|#
directive|define
name|ALIGNMENT_CEILING
parameter_list|(
name|s
parameter_list|,
name|alignment
parameter_list|)
define|\
value|(((s) + (alignment - 1))& ((~(alignment)) + 1))
end_define

begin_comment
comment|/* Declare a variable-length array. */
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|<
literal|199901L
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_define
define|#
directive|define
name|alloca
value|_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_HAS_ALLOCA_H
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VARIABLE_ARRAY
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|count
parameter_list|)
define|\
value|type *name = alloca(sizeof(type) * (count))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VARIABLE_ARRAY
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|count
parameter_list|)
value|type name[(count)]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_TYPES_H */
end_comment

end_unit

