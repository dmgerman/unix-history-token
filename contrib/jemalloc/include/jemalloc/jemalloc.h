begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_H_
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<limits.h>
include|#
directive|include
file|<strings.h>
define|#
directive|define
name|JEMALLOC_VERSION
value|"1.0.0-286-ga8f8d7540d66ddee7337db80c92890916e1063ca"
define|#
directive|define
name|JEMALLOC_VERSION_MAJOR
value|1
define|#
directive|define
name|JEMALLOC_VERSION_MINOR
value|0
define|#
directive|define
name|JEMALLOC_VERSION_BUGFIX
value|0
define|#
directive|define
name|JEMALLOC_VERSION_NREV
value|286
define|#
directive|define
name|JEMALLOC_VERSION_GID
value|"a8f8d7540d66ddee7337db80c92890916e1063ca"
include|#
directive|include
file|"jemalloc_defs.h"
include|#
directive|include
file|"jemalloc_FreeBSD.h"
ifdef|#
directive|ifdef
name|JEMALLOC_EXPERIMENTAL
define|#
directive|define
name|ALLOCM_LG_ALIGN
parameter_list|(
name|la
parameter_list|)
value|(la)
if|#
directive|if
name|LG_SIZEOF_PTR
operator|==
literal|2
define|#
directive|define
name|ALLOCM_ALIGN
parameter_list|(
name|a
parameter_list|)
value|(ffs(a)-1)
else|#
directive|else
define|#
directive|define
name|ALLOCM_ALIGN
parameter_list|(
name|a
parameter_list|)
value|((a< (size_t)INT_MAX) ? ffs(a)-1 : ffs(a>>32)+31)
endif|#
directive|endif
define|#
directive|define
name|ALLOCM_ZERO
value|((int)0x40)
define|#
directive|define
name|ALLOCM_NO_MOVE
value|((int)0x80)
define|#
directive|define
name|ALLOCM_SUCCESS
value|0
define|#
directive|define
name|ALLOCM_ERR_OOM
value|1
define|#
directive|define
name|ALLOCM_ERR_NOT_MOVED
value|2
endif|#
directive|endif
comment|/*  * The je_ prefix on the following public symbol declarations is an artifact of  * namespace management, and should be omitted in application code unless  * JEMALLOC_NO_DEMANGLE is defined (see below).  */
specifier|extern
specifier|const
name|char
modifier|*
name|je_malloc_conf
decl_stmt|;
specifier|extern
name|void
function_decl|(
modifier|*
name|je_malloc_message
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|je_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
name|malloc
parameter_list|)
function_decl|;
name|void
modifier|*
name|je_calloc
parameter_list|(
name|size_t
name|num
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
name|malloc
parameter_list|)
function_decl|;
name|int
name|je_posix_memalign
parameter_list|(
name|void
modifier|*
modifier|*
name|memptr
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
function_decl|nonnull
parameter_list|(
function_decl|1
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
modifier|*
name|je_aligned_alloc
parameter_list|(
name|size_t
name|alignment
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
name|malloc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|je_realloc
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

begin_function_decl
name|void
name|je_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|je_malloc_usable_size
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
name|je_malloc_stats_print
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
name|je_cbopaque
parameter_list|,
specifier|const
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|je_mallctl
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|oldp
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|void
modifier|*
name|newp
parameter_list|,
name|size_t
name|newlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|je_mallctlnametomib
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|mibp
parameter_list|,
name|size_t
modifier|*
name|miblenp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|je_mallctlbymib
parameter_list|(
specifier|const
name|size_t
modifier|*
name|mib
parameter_list|,
name|size_t
name|miblen
parameter_list|,
name|void
modifier|*
name|oldp
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|void
modifier|*
name|newp
parameter_list|,
name|size_t
name|newlen
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_EXPERIMENTAL
end_ifdef

begin_function_decl
name|int
name|je_allocm
parameter_list|(
name|void
modifier|*
modifier|*
name|ptr
parameter_list|,
name|size_t
modifier|*
name|rsize
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
function_decl|nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|je_rallocm
parameter_list|(
name|void
modifier|*
modifier|*
name|ptr
parameter_list|,
name|size_t
modifier|*
name|rsize
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
function_decl|nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|je_sallocm
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
modifier|*
name|rsize
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
function_decl|nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|je_dallocm
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|JEMALLOC_ATTR
parameter_list|(
function_decl|nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|je_nallocm
parameter_list|(
name|size_t
modifier|*
name|rsize
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * By default application code must explicitly refer to mangled symbol names,  * so that it is possible to use jemalloc in conjunction with another allocator  * in the same application.  Define JEMALLOC_MANGLE in order to cause automatic  * name mangling that matches the API prefixing that happened as a result of  * --with-mangling and/or --with-jemalloc-prefix configuration settings.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_MANGLE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_NO_DEMANGLE
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_NO_DEMANGLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|malloc_conf
value|je_malloc_conf
end_define

begin_define
define|#
directive|define
name|malloc_message
value|je_malloc_message
end_define

begin_define
define|#
directive|define
name|malloc
value|je_malloc
end_define

begin_define
define|#
directive|define
name|calloc
value|je_calloc
end_define

begin_define
define|#
directive|define
name|posix_memalign
value|je_posix_memalign
end_define

begin_define
define|#
directive|define
name|aligned_alloc
value|je_aligned_alloc
end_define

begin_define
define|#
directive|define
name|realloc
value|je_realloc
end_define

begin_define
define|#
directive|define
name|free
value|je_free
end_define

begin_define
define|#
directive|define
name|malloc_usable_size
value|je_malloc_usable_size
end_define

begin_define
define|#
directive|define
name|malloc_stats_print
value|je_malloc_stats_print
end_define

begin_define
define|#
directive|define
name|mallctl
value|je_mallctl
end_define

begin_define
define|#
directive|define
name|mallctlnametomib
value|je_mallctlnametomib
end_define

begin_define
define|#
directive|define
name|mallctlbymib
value|je_mallctlbymib
end_define

begin_define
define|#
directive|define
name|memalign
value|je_memalign
end_define

begin_define
define|#
directive|define
name|valloc
value|je_valloc
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_EXPERIMENTAL
end_ifdef

begin_define
define|#
directive|define
name|allocm
value|je_allocm
end_define

begin_define
define|#
directive|define
name|rallocm
value|je_rallocm
end_define

begin_define
define|#
directive|define
name|sallocm
value|je_sallocm
end_define

begin_define
define|#
directive|define
name|dallocm
value|je_dallocm
end_define

begin_define
define|#
directive|define
name|nallocm
value|je_nallocm
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
comment|/*  * The je_* macros can be used as stable alternative names for the public  * jemalloc API if JEMALLOC_NO_DEMANGLE is defined.  This is primarily meant  * for use in jemalloc itself, but it can be used by application code to  * provide isolation from the name mangling specified via --with-mangling  * and/or --with-jemalloc-prefix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_NO_DEMANGLE
end_ifndef

begin_undef
undef|#
directive|undef
name|je_malloc_conf
end_undef

begin_undef
undef|#
directive|undef
name|je_malloc_message
end_undef

begin_undef
undef|#
directive|undef
name|je_malloc
end_undef

begin_undef
undef|#
directive|undef
name|je_calloc
end_undef

begin_undef
undef|#
directive|undef
name|je_posix_memalign
end_undef

begin_undef
undef|#
directive|undef
name|je_aligned_alloc
end_undef

begin_undef
undef|#
directive|undef
name|je_realloc
end_undef

begin_undef
undef|#
directive|undef
name|je_free
end_undef

begin_undef
undef|#
directive|undef
name|je_malloc_usable_size
end_undef

begin_undef
undef|#
directive|undef
name|je_malloc_stats_print
end_undef

begin_undef
undef|#
directive|undef
name|je_mallctl
end_undef

begin_undef
undef|#
directive|undef
name|je_mallctlnametomib
end_undef

begin_undef
undef|#
directive|undef
name|je_mallctlbymib
end_undef

begin_undef
undef|#
directive|undef
name|je_memalign
end_undef

begin_undef
undef|#
directive|undef
name|je_valloc
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_EXPERIMENTAL
end_ifdef

begin_undef
undef|#
directive|undef
name|je_allocm
end_undef

begin_undef
undef|#
directive|undef
name|je_rallocm
end_undef

begin_undef
undef|#
directive|undef
name|je_sallocm
end_undef

begin_undef
undef|#
directive|undef
name|je_dallocm
end_undef

begin_undef
undef|#
directive|undef
name|je_nallocm
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_ */
end_comment

end_unit

