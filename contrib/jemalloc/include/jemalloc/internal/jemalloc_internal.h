begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_define
define|#
directive|define
name|ENOENT
value|ERROR_PATH_NOT_FOUND
end_define

begin_define
define|#
directive|define
name|EINVAL
value|ERROR_BAD_ARGUMENTS
end_define

begin_define
define|#
directive|define
name|EAGAIN
value|ERROR_OUTOFMEMORY
end_define

begin_define
define|#
directive|define
name|EPERM
value|ERROR_WRITE_FAULT
end_define

begin_define
define|#
directive|define
name|EFAULT
value|ERROR_INVALID_ADDRESS
end_define

begin_define
define|#
directive|define
name|ENOMEM
value|ERROR_NOT_ENOUGH_MEMORY
end_define

begin_undef
undef|#
directive|undef
name|ERANGE
end_undef

begin_define
define|#
directive|define
name|ERANGE
value|ERROR_INVALID_DATA
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYS_write
argument_list|)
operator|&&
name|defined
argument_list|(
name|__NR_write
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYS_write
value|__NR_write
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_T_MAX
value|SIZE_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)&(((type *)NULL)->member))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_typedef
typedef|typedef
name|intptr_t
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PATH_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_define
define|#
directive|define
name|__func__
value|__FUNCTION__
end_define

begin_comment
comment|/* Disable warnings about deprecated system functions */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4996
name|)
end_pragma

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|"jemalloc_internal_defs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_UTRACE
end_ifdef

begin_include
include|#
directive|include
file|<sys/ktrace.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_VALGRIND
end_ifdef

begin_include
include|#
directive|include
file|<valgrind/valgrind.h>
end_include

begin_include
include|#
directive|include
file|<valgrind/memcheck.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_define
define|#
directive|define
name|JEMALLOC_NO_DEMANGLE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_define
define|#
directive|define
name|JEMALLOC_N
parameter_list|(
name|n
parameter_list|)
value|jet_##n
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/public_namespace.h"
end_include

begin_define
define|#
directive|define
name|JEMALLOC_NO_RENAME
end_define

begin_include
include|#
directive|include
file|"../jemalloc.h"
end_include

begin_undef
undef|#
directive|undef
name|JEMALLOC_NO_RENAME
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JEMALLOC_N
parameter_list|(
name|n
parameter_list|)
value|__je_##n
end_define

begin_include
include|#
directive|include
file|"../jemalloc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"jemalloc/internal/private_namespace.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_debug
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_DEBUG
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_dss
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_DSS
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_fill
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_FILL
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_lazy_lock
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_prof
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_PROF
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_prof_libgcc
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_PROF_LIBGCC
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_prof_libunwind
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_PROF_LIBUNWIND
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_mremap
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_MREMAP
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_munmap
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_MUNMAP
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_stats
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_STATS
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_tcache
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_TCACHE
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_tls
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_TLS
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_utrace
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_UTRACE
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_valgrind
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_VALGRIND
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_xmalloc
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_XMALLOC
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|config_ivsalloc
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_IVSALLOC
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_ATOMIC9
end_ifdef

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

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
name|JEMALLOC_OSATOMIC
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_OSSPIN
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<libkern/OSAtomic.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_ZONE
end_ifdef

begin_include
include|#
directive|include
file|<mach/mach_error.h>
end_include

begin_include
include|#
directive|include
file|<mach/mach_init.h>
end_include

begin_include
include|#
directive|include
file|<mach/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<malloc/malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RB_COMPACT
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/rb.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/qr.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ql.h"
end_include

begin_comment
comment|/*  * jemalloc can conceptually be broken into components (arena, tcache, etc.),  * but there are circular dependencies that cannot be broken without  * substantial performance degradation.  In order to reduce the effect on  * visual code flow, read the header files in multiple passes, with one of the  * following cpp variables defined during each pass:  *  *   JEMALLOC_H_TYPES   : Preprocessor-defined constants and psuedo-opaque data  *                        types.  *   JEMALLOC_H_STRUCTS : Data structures.  *   JEMALLOC_H_EXTERNS : Extern data declarations and function prototypes.  *   JEMALLOC_H_INLINES : Inline functions.  */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_H_TYPES
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_macros.h"
end_include

begin_define
define|#
directive|define
name|MALLOCX_LG_ALIGN_MASK
value|((int)0x3f)
end_define

begin_define
define|#
directive|define
name|ALLOCM_LG_ALIGN_MASK
value|((int)0x3f)
end_define

begin_comment
comment|/* Smallest size class to support. */
end_comment

begin_define
define|#
directive|define
name|LG_TINY_MIN
value|3
end_define

begin_define
define|#
directive|define
name|TINY_MIN
value|(1U<< LG_TINY_MIN)
end_define

begin_comment
comment|/*  * Minimum alignment of allocations is 2^LG_QUANTUM bytes (ignoring tiny size  * classes).  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc64__
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

begin_ifndef
ifndef|#
directive|ifndef
name|LG_QUANTUM
end_ifndef

begin_error
error|#
directive|error
literal|"No LG_QUANTUM definition for architecture; specify via CPPFLAGS"
end_error

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
comment|/* Page size.  STATIC_PAGE_SHIFT is determined by the configure script. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PAGE_MASK
end_ifdef

begin_undef
undef|#
directive|undef
name|PAGE_MASK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LG_PAGE
value|STATIC_PAGE_SHIFT
end_define

begin_define
define|#
directive|define
name|PAGE
value|((size_t)(1U<< STATIC_PAGE_SHIFT))
end_define

begin_define
define|#
directive|define
name|PAGE_MASK
value|((size_t)(PAGE - 1))
end_define

begin_comment
comment|/* Return the smallest pagesize multiple that is>= s. */
end_comment

begin_define
define|#
directive|define
name|PAGE_CEILING
parameter_list|(
name|s
parameter_list|)
define|\
value|(((s) + PAGE_MASK)& ~PAGE_MASK)
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
value|((void *)((uintptr_t)(a)& (-(alignment))))
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
value|(((s) + (alignment - 1))& (-(alignment)))
end_define

begin_comment
comment|/* Declare a variable length array */
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
value|type *name = alloca(sizeof(type) * count)
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
value|type name[count]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_VALGRIND
end_ifdef

begin_comment
comment|/*  * The JEMALLOC_VALGRIND_*() macros must be macros rather than functions  * so that when Valgrind reports errors, there are no extra stack frames  * in the backtraces.  *  * The size that is reported to valgrind must be consistent through a chain of  * malloc..realloc..realloc calls.  Request size isn't recorded anywhere in  * jemalloc, so it is critical that all callers of these macros provide usize  * rather than request size.  As a result, buffer overflow detection is  * technically weakened for the standard API, though it is generally accepted  * practice to consider any extra bytes reported by malloc_usable_size() as  * usable space.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MALLOC
parameter_list|(
name|cond
parameter_list|,
name|ptr
parameter_list|,
name|usize
parameter_list|,
name|zero
parameter_list|)
value|do {		\ 	if (config_valgrind&& opt_valgrind&& cond)			\ 		VALGRIND_MALLOCLIKE_BLOCK(ptr, usize, p2rz(ptr), zero);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_REALLOC
parameter_list|(
name|ptr
parameter_list|,
name|usize
parameter_list|,
name|old_ptr
parameter_list|,
name|old_usize
parameter_list|,	\
name|old_rzsize
parameter_list|,
name|zero
parameter_list|)
value|do {						\ 	if (config_valgrind&& opt_valgrind) {				\ 		size_t rzsize = p2rz(ptr);				\ 									\ 		if (ptr == old_ptr) {					\ 			VALGRIND_RESIZEINPLACE_BLOCK(ptr, old_usize,	\ 			    usize, rzsize);				\ 			if (zero&& old_usize< usize) {		\ 				VALGRIND_MAKE_MEM_DEFINED(		\ 				    (void *)((uintptr_t)ptr +		\ 				    old_usize), usize - old_usize);	\ 			}						\ 		} else {						\ 			if (old_ptr != NULL) {				\ 				VALGRIND_FREELIKE_BLOCK(old_ptr,	\ 				    old_rzsize);			\ 			}						\ 			if (ptr != NULL) {				\ 				size_t copy_size = (old_usize< usize)	\ 				    ?  old_usize : usize;		\ 				size_t tail_size = usize - copy_size;	\ 				VALGRIND_MALLOCLIKE_BLOCK(ptr, usize,	\ 				    rzsize, false);			\ 				if (copy_size> 0) {			\ 					VALGRIND_MAKE_MEM_DEFINED(ptr,	\ 					    copy_size);			\ 				}					\ 				if (zero&& tail_size> 0) {		\ 					VALGRIND_MAKE_MEM_DEFINED(	\ 					    (void *)((uintptr_t)ptr +	\ 					    copy_size), tail_size);	\ 				}					\ 			}						\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_FREE
parameter_list|(
name|ptr
parameter_list|,
name|rzsize
parameter_list|)
value|do {			\ 	if (config_valgrind&& opt_valgrind)				\ 		VALGRIND_FREELIKE_BLOCK(ptr, rzsize);			\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RUNNING_ON_VALGRIND
value|((unsigned)0)
end_define

begin_define
define|#
directive|define
name|VALGRIND_MALLOCLIKE_BLOCK
parameter_list|(
name|addr
parameter_list|,
name|sizeB
parameter_list|,
name|rzB
parameter_list|,
name|is_zeroed
parameter_list|)
define|\
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|VALGRIND_RESIZEINPLACE_BLOCK
parameter_list|(
name|addr
parameter_list|,
name|oldSizeB
parameter_list|,
name|newSizeB
parameter_list|,
name|rzB
parameter_list|)
define|\
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|VALGRIND_FREELIKE_BLOCK
parameter_list|(
name|addr
parameter_list|,
name|rzB
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|VALGRIND_MAKE_MEM_NOACCESS
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|VALGRIND_MAKE_MEM_UNDEFINED
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MALLOC
parameter_list|(
name|cond
parameter_list|,
name|ptr
parameter_list|,
name|usize
parameter_list|,
name|zero
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_REALLOC
parameter_list|(
name|ptr
parameter_list|,
name|usize
parameter_list|,
name|old_ptr
parameter_list|,
name|old_usize
parameter_list|,	\
name|old_rzsize
parameter_list|,
name|zero
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_FREE
parameter_list|(
name|ptr
parameter_list|,
name|rzsize
parameter_list|)
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"jemalloc/internal/util.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prng.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ckh.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/stats.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ctl.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mb.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/extent.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/arena.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/bitmap.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/base.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/chunk.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/huge.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/rtree.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/hash.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/quarantine.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prof.h"
end_include

begin_undef
undef|#
directive|undef
name|JEMALLOC_H_TYPES
end_undef

begin_comment
comment|/******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_H_STRUCTS
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/util.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prng.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ckh.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/stats.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ctl.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mb.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/bitmap.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/extent.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/arena.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/base.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/chunk.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/huge.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/rtree.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/hash.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/quarantine.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prof.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint64_t
name|allocated
decl_stmt|;
name|uint64_t
name|deallocated
decl_stmt|;
block|}
name|thread_allocated_t
typedef|;
end_typedef

begin_comment
comment|/*  * The JEMALLOC_ARG_CONCAT() wrapper is necessary to pass {0, 0} via a cpp macro  * argument.  */
end_comment

begin_define
define|#
directive|define
name|THREAD_ALLOCATED_INITIALIZER
value|JEMALLOC_ARG_CONCAT({0, 0})
end_define

begin_undef
undef|#
directive|undef
name|JEMALLOC_H_STRUCTS
end_undef

begin_comment
comment|/******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_H_EXTERNS
end_define

begin_decl_stmt
specifier|extern
name|bool
name|opt_abort
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_junk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|opt_quarantine
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_redzone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_utrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_valgrind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_xmalloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_zero
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|opt_narenas
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of CPUs. */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|ncpus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Protects arenas initialization (arenas, arenas_total). */
end_comment

begin_decl_stmt
specifier|extern
name|malloc_mutex_t
name|arenas_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Arenas that are used to service external requests.  Not all elements of the  * arenas array are necessarily used; arenas are created lazily as needed.  *  * arenas[0..narenas_auto) are used for automatic multiplexing of threads and  * arenas.  arenas[narenas_auto..narenas_total) are only used if the application  * takes some action to create them and allocate from them.  */
end_comment

begin_decl_stmt
specifier|extern
name|arena_t
modifier|*
modifier|*
name|arenas
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|narenas_total
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|narenas_auto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read-only after initialization. */
end_comment

begin_function_decl
name|arena_t
modifier|*
name|arenas_extend
parameter_list|(
name|unsigned
name|ind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arenas_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|arena_t
modifier|*
name|choose_arena_hard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jemalloc_prefork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jemalloc_postfork_parent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jemalloc_postfork_child
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"jemalloc/internal/util.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prng.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ckh.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/stats.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ctl.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mb.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/bitmap.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/extent.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/arena.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/base.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/chunk.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/huge.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/rtree.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/hash.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/quarantine.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prof.h"
end_include

begin_undef
undef|#
directive|undef
name|JEMALLOC_H_EXTERNS
end_undef

begin_comment
comment|/******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_H_INLINES
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/util.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prng.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ckh.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/stats.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ctl.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mb.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/extent.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/base.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/chunk.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/huge.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_macro
name|malloc_tsd_protos
argument_list|(
argument|JEMALLOC_ATTR(unused)
argument_list|,
argument|arenas
argument_list|,
argument|arena_t *
argument_list|)
end_macro

begin_function_decl
name|size_t
name|s2u
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|sa2u
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|narenas_total_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|arena_t
modifier|*
name|choose_arena
parameter_list|(
name|arena_t
modifier|*
name|arena
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
name|JEMALLOC_C_
argument_list|)
operator|)
end_if

begin_comment
comment|/*  * Map of pthread_self() --> arenas[???], used for selecting an arena to use  * for allocations.  */
end_comment

begin_macro
name|malloc_tsd_externs
argument_list|(
argument|arenas
argument_list|,
argument|arena_t *
argument_list|)
end_macro

begin_macro
name|malloc_tsd_funcs
argument_list|(
argument|JEMALLOC_ALWAYS_INLINE
argument_list|,
argument|arenas
argument_list|,
argument|arena_t *
argument_list|,
argument|NULL
argument_list|,
argument|arenas_cleanup
argument_list|)
end_macro

begin_comment
comment|/*  * Compute usable size that would result from allocating an object with the  * specified size.  */
end_comment

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|size_t
name|s2u
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|<=
name|SMALL_MAXCLASS
condition|)
return|return
operator|(
name|arena_bin_info
index|[
name|SMALL_SIZE2BIN
argument_list|(
name|size
argument_list|)
index|]
operator|.
name|reg_size
operator|)
return|;
if|if
condition|(
name|size
operator|<=
name|arena_maxclass
condition|)
return|return
operator|(
name|PAGE_CEILING
argument_list|(
name|size
argument_list|)
operator|)
return|;
return|return
operator|(
name|CHUNK_CEILING
argument_list|(
name|size
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Compute usable size that would result from allocating an object with the  * specified size and alignment.  */
end_comment

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|size_t
name|sa2u
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|)
block|{
name|size_t
name|usize
decl_stmt|;
name|assert
argument_list|(
name|alignment
operator|!=
literal|0
operator|&&
operator|(
operator|(
name|alignment
operator|-
literal|1
operator|)
operator|&
name|alignment
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * Round size up to the nearest multiple of alignment. 	 * 	 * This done, we can take advantage of the fact that for each small 	 * size class, every object is aligned at the smallest power of two 	 * that is non-zero in the base two representation of the size.  For 	 * example: 	 * 	 *   Size |   Base 2 | Minimum alignment 	 *   -----+----------+------------------ 	 *     96 |  1100000 |  32 	 *    144 | 10100000 |  32 	 *    192 | 11000000 |  64 	 */
name|usize
operator|=
name|ALIGNMENT_CEILING
argument_list|(
name|size
argument_list|,
name|alignment
argument_list|)
expr_stmt|;
comment|/* 	 * (usize< size) protects against the combination of maximal 	 * alignment and size greater than maximal alignment. 	 */
if|if
condition|(
name|usize
operator|<
name|size
condition|)
block|{
comment|/* size_t overflow. */
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|usize
operator|<=
name|arena_maxclass
operator|&&
name|alignment
operator|<=
name|PAGE
condition|)
block|{
if|if
condition|(
name|usize
operator|<=
name|SMALL_MAXCLASS
condition|)
return|return
operator|(
name|arena_bin_info
index|[
name|SMALL_SIZE2BIN
argument_list|(
name|usize
argument_list|)
index|]
operator|.
name|reg_size
operator|)
return|;
return|return
operator|(
name|PAGE_CEILING
argument_list|(
name|usize
argument_list|)
operator|)
return|;
block|}
else|else
block|{
name|size_t
name|run_size
decl_stmt|;
comment|/* 		 * We can't achieve subpage alignment, so round up alignment 		 * permanently; it makes later calculations simpler. 		 */
name|alignment
operator|=
name|PAGE_CEILING
argument_list|(
name|alignment
argument_list|)
expr_stmt|;
name|usize
operator|=
name|PAGE_CEILING
argument_list|(
name|size
argument_list|)
expr_stmt|;
comment|/* 		 * (usize< size) protects against very large sizes within 		 * PAGE of SIZE_T_MAX. 		 * 		 * (usize + alignment< usize) protects against the 		 * combination of maximal alignment and usize large enough 		 * to cause overflow.  This is similar to the first overflow 		 * check above, but it needs to be repeated due to the new 		 * usize value, which may now be *equal* to maximal 		 * alignment, whereas before we only detected overflow if the 		 * original size was *greater* than maximal alignment. 		 */
if|if
condition|(
name|usize
operator|<
name|size
operator|||
name|usize
operator|+
name|alignment
operator|<
name|usize
condition|)
block|{
comment|/* size_t overflow. */
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 		 * Calculate the size of the over-size run that arena_palloc() 		 * would need to allocate in order to guarantee the alignment. 		 * If the run wouldn't fit within a chunk, round up to a huge 		 * allocation size. 		 */
name|run_size
operator|=
name|usize
operator|+
name|alignment
operator|-
name|PAGE
expr_stmt|;
if|if
condition|(
name|run_size
operator|<=
name|arena_maxclass
condition|)
return|return
operator|(
name|PAGE_CEILING
argument_list|(
name|usize
argument_list|)
operator|)
return|;
return|return
operator|(
name|CHUNK_CEILING
argument_list|(
name|usize
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|unsigned
name|narenas_total_get
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|narenas
decl_stmt|;
name|malloc_mutex_lock
argument_list|(
operator|&
name|arenas_lock
argument_list|)
expr_stmt|;
name|narenas
operator|=
name|narenas_total
expr_stmt|;
name|malloc_mutex_unlock
argument_list|(
operator|&
name|arenas_lock
argument_list|)
expr_stmt|;
return|return
operator|(
name|narenas
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Choose an arena based on a per-thread value. */
end_comment

begin_function
name|JEMALLOC_INLINE
name|arena_t
modifier|*
name|choose_arena
parameter_list|(
name|arena_t
modifier|*
name|arena
parameter_list|)
block|{
name|arena_t
modifier|*
name|ret
decl_stmt|;
if|if
condition|(
name|arena
operator|!=
name|NULL
condition|)
return|return
operator|(
name|arena
operator|)
return|;
if|if
condition|(
operator|(
name|ret
operator|=
operator|*
name|arenas_tsd_get
argument_list|()
operator|)
operator|==
name|NULL
condition|)
block|{
name|ret
operator|=
name|choose_arena_hard
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|ret
operator|!=
name|NULL
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"jemalloc/internal/bitmap.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/rtree.h"
end_include

begin_comment
comment|/*  * Include arena.h twice in order to resolve circular dependencies with  * tcache.h.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_ARENA_INLINE_A
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/arena.h"
end_include

begin_undef
undef|#
directive|undef
name|JEMALLOC_ARENA_INLINE_A
end_undef

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache.h"
end_include

begin_define
define|#
directive|define
name|JEMALLOC_ARENA_INLINE_B
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/arena.h"
end_include

begin_undef
undef|#
directive|undef
name|JEMALLOC_ARENA_INLINE_B
end_undef

begin_include
include|#
directive|include
file|"jemalloc/internal/hash.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/quarantine.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_function_decl
name|void
modifier|*
name|imalloct
parameter_list|(
name|size_t
name|size
parameter_list|,
name|bool
name|try_tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|imalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|icalloct
parameter_list|(
name|size_t
name|size
parameter_list|,
name|bool
name|try_tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|icalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ipalloct
parameter_list|(
name|size_t
name|usize
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|bool
name|try_tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ipalloc
parameter_list|(
name|size_t
name|usize
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|isalloc
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|demote
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ivsalloc
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|demote
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|u2rz
parameter_list|(
name|size_t
name|usize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|p2rz
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idalloct
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|try_tcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idalloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iqalloct
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|try_tcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iqalloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|iralloct_realign
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|bool
name|try_tcache_alloc
parameter_list|,
name|bool
name|try_tcache_dalloc
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|iralloct
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|bool
name|try_tcache_alloc
parameter_list|,
name|bool
name|try_tcache_dalloc
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|iralloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ixalloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|malloc_tsd_protos
argument_list|(
argument|JEMALLOC_ATTR(unused)
argument_list|,
argument|thread_allocated
argument_list|,
argument|thread_allocated_t
argument_list|)
end_macro

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
name|JEMALLOC_C_
argument_list|)
operator|)
end_if

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|imalloct
parameter_list|(
name|size_t
name|size
parameter_list|,
name|bool
name|try_tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
block|{
name|assert
argument_list|(
name|size
operator|!=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
operator|<=
name|arena_maxclass
condition|)
return|return
operator|(
name|arena_malloc
argument_list|(
name|arena
argument_list|,
name|size
argument_list|,
name|false
argument_list|,
name|try_tcache
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|huge_malloc
argument_list|(
name|size
argument_list|,
name|false
argument_list|,
name|huge_dss_prec_get
argument_list|(
name|arena
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|imalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
return|return
operator|(
name|imalloct
argument_list|(
name|size
argument_list|,
name|true
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|icalloct
parameter_list|(
name|size_t
name|size
parameter_list|,
name|bool
name|try_tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
block|{
if|if
condition|(
name|size
operator|<=
name|arena_maxclass
condition|)
return|return
operator|(
name|arena_malloc
argument_list|(
name|arena
argument_list|,
name|size
argument_list|,
name|true
argument_list|,
name|try_tcache
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|huge_malloc
argument_list|(
name|size
argument_list|,
name|true
argument_list|,
name|huge_dss_prec_get
argument_list|(
name|arena
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|icalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
return|return
operator|(
name|icalloct
argument_list|(
name|size
argument_list|,
name|true
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|ipalloct
parameter_list|(
name|size_t
name|usize
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|bool
name|try_tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
block|{
name|void
modifier|*
name|ret
decl_stmt|;
name|assert
argument_list|(
name|usize
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|usize
operator|==
name|sa2u
argument_list|(
name|usize
argument_list|,
name|alignment
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|usize
operator|<=
name|arena_maxclass
operator|&&
name|alignment
operator|<=
name|PAGE
condition|)
name|ret
operator|=
name|arena_malloc
argument_list|(
name|arena
argument_list|,
name|usize
argument_list|,
name|zero
argument_list|,
name|try_tcache
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|usize
operator|<=
name|arena_maxclass
condition|)
block|{
name|ret
operator|=
name|arena_palloc
argument_list|(
name|choose_arena
argument_list|(
name|arena
argument_list|)
argument_list|,
name|usize
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|alignment
operator|<=
name|chunksize
condition|)
name|ret
operator|=
name|huge_malloc
argument_list|(
name|usize
argument_list|,
name|zero
argument_list|,
name|huge_dss_prec_get
argument_list|(
name|arena
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|ret
operator|=
name|huge_palloc
argument_list|(
name|usize
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|,
name|huge_dss_prec_get
argument_list|(
name|arena
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|assert
argument_list|(
name|ALIGNMENT_ADDR2BASE
argument_list|(
name|ret
argument_list|,
name|alignment
argument_list|)
operator|==
name|ret
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|ipalloc
parameter_list|(
name|size_t
name|usize
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|)
block|{
return|return
operator|(
name|ipalloct
argument_list|(
name|usize
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|,
name|true
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Typical usage:  *   void *ptr = [...]  *   size_t sz = isalloc(ptr, config_prof);  */
end_comment

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|size_t
name|isalloc
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|demote
parameter_list|)
block|{
name|size_t
name|ret
decl_stmt|;
name|arena_chunk_t
modifier|*
name|chunk
decl_stmt|;
name|assert
argument_list|(
name|ptr
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|/* Demotion only makes sense if config_prof is true. */
name|assert
argument_list|(
name|config_prof
operator|||
name|demote
operator|==
name|false
argument_list|)
expr_stmt|;
name|chunk
operator|=
operator|(
name|arena_chunk_t
operator|*
operator|)
name|CHUNK_ADDR2BASE
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|chunk
operator|!=
name|ptr
condition|)
name|ret
operator|=
name|arena_salloc
argument_list|(
name|ptr
argument_list|,
name|demote
argument_list|)
expr_stmt|;
else|else
name|ret
operator|=
name|huge_salloc
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|size_t
name|ivsalloc
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|demote
parameter_list|)
block|{
comment|/* Return 0 if ptr is not within a chunk managed by jemalloc. */
if|if
condition|(
name|rtree_get
argument_list|(
name|chunks_rtree
argument_list|,
operator|(
name|uintptr_t
operator|)
name|CHUNK_ADDR2BASE
argument_list|(
name|ptr
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|isalloc
argument_list|(
name|ptr
argument_list|,
name|demote
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|size_t
name|u2rz
parameter_list|(
name|size_t
name|usize
parameter_list|)
block|{
name|size_t
name|ret
decl_stmt|;
if|if
condition|(
name|usize
operator|<=
name|SMALL_MAXCLASS
condition|)
block|{
name|size_t
name|binind
init|=
name|SMALL_SIZE2BIN
argument_list|(
name|usize
argument_list|)
decl_stmt|;
name|ret
operator|=
name|arena_bin_info
index|[
name|binind
index|]
operator|.
name|redzone_size
expr_stmt|;
block|}
else|else
name|ret
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|size_t
name|p2rz
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|size_t
name|usize
init|=
name|isalloc
argument_list|(
name|ptr
argument_list|,
name|false
argument_list|)
decl_stmt|;
return|return
operator|(
name|u2rz
argument_list|(
name|usize
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
name|idalloct
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|try_tcache
parameter_list|)
block|{
name|arena_chunk_t
modifier|*
name|chunk
decl_stmt|;
name|assert
argument_list|(
name|ptr
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|chunk
operator|=
operator|(
name|arena_chunk_t
operator|*
operator|)
name|CHUNK_ADDR2BASE
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|chunk
operator|!=
name|ptr
condition|)
name|arena_dalloc
argument_list|(
name|chunk
operator|->
name|arena
argument_list|,
name|chunk
argument_list|,
name|ptr
argument_list|,
name|try_tcache
argument_list|)
expr_stmt|;
else|else
name|huge_dalloc
argument_list|(
name|ptr
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
name|idalloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|idalloct
argument_list|(
name|ptr
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
name|iqalloct
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|try_tcache
parameter_list|)
block|{
if|if
condition|(
name|config_fill
operator|&&
name|opt_quarantine
condition|)
name|quarantine
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
else|else
name|idalloct
argument_list|(
name|ptr
argument_list|,
name|try_tcache
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
name|iqalloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|iqalloct
argument_list|(
name|ptr
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|iralloct_realign
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|bool
name|try_tcache_alloc
parameter_list|,
name|bool
name|try_tcache_dalloc
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
block|{
name|void
modifier|*
name|p
decl_stmt|;
name|size_t
name|usize
decl_stmt|,
name|copysize
decl_stmt|;
name|usize
operator|=
name|sa2u
argument_list|(
name|size
operator|+
name|extra
argument_list|,
name|alignment
argument_list|)
expr_stmt|;
if|if
condition|(
name|usize
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|p
operator|=
name|ipalloct
argument_list|(
name|usize
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|,
name|try_tcache_alloc
argument_list|,
name|arena
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|extra
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
comment|/* Try again, without extra this time. */
name|usize
operator|=
name|sa2u
argument_list|(
name|size
argument_list|,
name|alignment
argument_list|)
expr_stmt|;
if|if
condition|(
name|usize
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|p
operator|=
name|ipalloct
argument_list|(
name|usize
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|,
name|try_tcache_alloc
argument_list|,
name|arena
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* 	 * Copy at most size bytes (not size+extra), since the caller has no 	 * expectation that the extra bytes will be reliably preserved. 	 */
name|copysize
operator|=
operator|(
name|size
operator|<
name|oldsize
operator|)
condition|?
name|size
else|:
name|oldsize
expr_stmt|;
name|memcpy
argument_list|(
name|p
argument_list|,
name|ptr
argument_list|,
name|copysize
argument_list|)
expr_stmt|;
name|iqalloct
argument_list|(
name|ptr
argument_list|,
name|try_tcache_dalloc
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|iralloct
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|bool
name|try_tcache_alloc
parameter_list|,
name|bool
name|try_tcache_dalloc
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
block|{
name|size_t
name|oldsize
decl_stmt|;
name|assert
argument_list|(
name|ptr
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|size
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|oldsize
operator|=
name|isalloc
argument_list|(
name|ptr
argument_list|,
name|config_prof
argument_list|)
expr_stmt|;
if|if
condition|(
name|alignment
operator|!=
literal|0
operator|&&
operator|(
operator|(
name|uintptr_t
operator|)
name|ptr
operator|&
operator|(
operator|(
name|uintptr_t
operator|)
name|alignment
operator|-
literal|1
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* 		 * Existing object alignment is inadequate; allocate new space 		 * and copy. 		 */
return|return
operator|(
name|iralloct_realign
argument_list|(
name|ptr
argument_list|,
name|oldsize
argument_list|,
name|size
argument_list|,
name|extra
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|,
name|try_tcache_alloc
argument_list|,
name|try_tcache_dalloc
argument_list|,
name|arena
argument_list|)
operator|)
return|;
block|}
if|if
condition|(
name|size
operator|+
name|extra
operator|<=
name|arena_maxclass
condition|)
block|{
return|return
operator|(
name|arena_ralloc
argument_list|(
name|arena
argument_list|,
name|ptr
argument_list|,
name|oldsize
argument_list|,
name|size
argument_list|,
name|extra
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|,
name|try_tcache_alloc
argument_list|,
name|try_tcache_dalloc
argument_list|)
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
name|huge_ralloc
argument_list|(
name|ptr
argument_list|,
name|oldsize
argument_list|,
name|size
argument_list|,
name|extra
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|,
name|try_tcache_dalloc
argument_list|,
name|huge_dss_prec_get
argument_list|(
name|arena
argument_list|)
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
modifier|*
name|iralloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|)
block|{
return|return
operator|(
name|iralloct
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|,
name|extra
argument_list|,
name|alignment
argument_list|,
name|zero
argument_list|,
name|true
argument_list|,
name|true
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|bool
name|ixalloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|)
block|{
name|size_t
name|oldsize
decl_stmt|;
name|assert
argument_list|(
name|ptr
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|size
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|oldsize
operator|=
name|isalloc
argument_list|(
name|ptr
argument_list|,
name|config_prof
argument_list|)
expr_stmt|;
if|if
condition|(
name|alignment
operator|!=
literal|0
operator|&&
operator|(
operator|(
name|uintptr_t
operator|)
name|ptr
operator|&
operator|(
operator|(
name|uintptr_t
operator|)
name|alignment
operator|-
literal|1
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* Existing object alignment is inadequate. */
return|return
operator|(
name|true
operator|)
return|;
block|}
if|if
condition|(
name|size
operator|<=
name|arena_maxclass
condition|)
return|return
operator|(
name|arena_ralloc_no_move
argument_list|(
name|ptr
argument_list|,
name|oldsize
argument_list|,
name|size
argument_list|,
name|extra
argument_list|,
name|zero
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|huge_ralloc_no_move
argument_list|(
name|ptr
argument_list|,
name|oldsize
argument_list|,
name|size
argument_list|,
name|extra
argument_list|)
operator|)
return|;
block|}
end_function

begin_macro
name|malloc_tsd_externs
argument_list|(
argument|thread_allocated
argument_list|,
argument|thread_allocated_t
argument_list|)
end_macro

begin_macro
name|malloc_tsd_funcs
argument_list|(
argument|JEMALLOC_ALWAYS_INLINE
argument_list|,
argument|thread_allocated
argument_list|,
argument|thread_allocated_t
argument_list|,
argument|THREAD_ALLOCATED_INITIALIZER
argument_list|,
argument|malloc_tsd_no_cleanup
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"jemalloc/internal/prof.h"
end_include

begin_undef
undef|#
directive|undef
name|JEMALLOC_H_INLINES
end_undef

begin_comment
comment|/******************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_H */
end_comment

end_unit

