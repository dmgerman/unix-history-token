begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Override settings that were generated in jemalloc_defs.h as necessary.  */
end_comment

begin_undef
undef|#
directive|undef
name|JEMALLOC_OVERRIDE_VALLOC
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|MALLOC_PRODUCTION
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|JEMALLOC_DSS
end_undef

begin_undef
undef|#
directive|undef
name|JEMALLOC_BACKGROUND_THREAD
end_undef

begin_comment
comment|/*  * The following are architecture-dependent, so conditionally define them for  * each supported architecture.  */
end_comment

begin_undef
undef|#
directive|undef
name|JEMALLOC_TLS_MODEL
end_undef

begin_undef
undef|#
directive|undef
name|STATIC_PAGE_SHIFT
end_undef

begin_undef
undef|#
directive|undef
name|LG_VADDR
end_undef

begin_undef
undef|#
directive|undef
name|LG_SIZEOF_PTR
end_undef

begin_undef
undef|#
directive|undef
name|LG_SIZEOF_INT
end_undef

begin_undef
undef|#
directive|undef
name|LG_SIZEOF_LONG
end_undef

begin_undef
undef|#
directive|undef
name|LG_SIZEOF_INTMAX_T
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|LG_VADDR
value|32
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|2
end_define

begin_define
define|#
directive|define
name|JEMALLOC_TLS_MODEL
value|__attribute__((tls_model("initial-exec")))
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
name|LG_VADDR
value|64
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|3
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
name|LG_VADDR
value|64
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|3
end_define

begin_define
define|#
directive|define
name|JEMALLOC_TLS_MODEL
value|__attribute__((tls_model("initial-exec")))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|LG_VADDR
value|48
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|3
end_define

begin_define
define|#
directive|define
name|JEMALLOC_TLS_MODEL
value|__attribute__((tls_model("initial-exec")))
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
name|LG_VADDR
value|32
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|2
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
name|LG_VADDR
value|48
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|3
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

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|LG_VADDR
value|64
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|3
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LG_VADDR
value|32
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|2
end_define

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
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|LG_VADDR
value|64
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|3
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LG_VADDR
value|32
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__riscv__
end_ifdef

begin_define
define|#
directive|define
name|LG_VADDR
value|64
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_TLS_MODEL
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_TLS_MODEL
end_define

begin_comment
comment|/* Default. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STATIC_PAGE_SHIFT
value|PAGE_SHIFT
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_INT
value|2
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_LONG
value|LG_SIZEOF_PTR
end_define

begin_define
define|#
directive|define
name|LG_SIZEOF_INTMAX_T
value|3
end_define

begin_undef
undef|#
directive|undef
name|CPU_SPINWAIT
end_undef

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_define
define|#
directive|define
name|CPU_SPINWAIT
value|cpu_spinwait()
end_define

begin_comment
comment|/* Disable lazy-lock machinery, mangle isthreaded, and adjust its type. */
end_comment

begin_undef
undef|#
directive|undef
name|JEMALLOC_LAZY_LOCK
end_undef

begin_decl_stmt
specifier|extern
name|int
name|__isthreaded
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isthreaded
value|((bool)__isthreaded)
end_define

begin_comment
comment|/* Mangle. */
end_comment

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
name|je_mallocx
end_undef

begin_undef
undef|#
directive|undef
name|je_rallocx
end_undef

begin_undef
undef|#
directive|undef
name|je_xallocx
end_undef

begin_undef
undef|#
directive|undef
name|je_sallocx
end_undef

begin_undef
undef|#
directive|undef
name|je_dallocx
end_undef

begin_undef
undef|#
directive|undef
name|je_sdallocx
end_undef

begin_undef
undef|#
directive|undef
name|je_nallocx
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
name|je_malloc_stats_print
end_undef

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

begin_define
define|#
directive|define
name|je_malloc
value|__malloc
end_define

begin_define
define|#
directive|define
name|je_calloc
value|__calloc
end_define

begin_define
define|#
directive|define
name|je_posix_memalign
value|__posix_memalign
end_define

begin_define
define|#
directive|define
name|je_aligned_alloc
value|__aligned_alloc
end_define

begin_define
define|#
directive|define
name|je_realloc
value|__realloc
end_define

begin_define
define|#
directive|define
name|je_free
value|__free
end_define

begin_define
define|#
directive|define
name|je_malloc_usable_size
value|__malloc_usable_size
end_define

begin_define
define|#
directive|define
name|je_mallocx
value|__mallocx
end_define

begin_define
define|#
directive|define
name|je_rallocx
value|__rallocx
end_define

begin_define
define|#
directive|define
name|je_xallocx
value|__xallocx
end_define

begin_define
define|#
directive|define
name|je_sallocx
value|__sallocx
end_define

begin_define
define|#
directive|define
name|je_dallocx
value|__dallocx
end_define

begin_define
define|#
directive|define
name|je_sdallocx
value|__sdallocx
end_define

begin_define
define|#
directive|define
name|je_nallocx
value|__nallocx
end_define

begin_define
define|#
directive|define
name|je_mallctl
value|__mallctl
end_define

begin_define
define|#
directive|define
name|je_mallctlnametomib
value|__mallctlnametomib
end_define

begin_define
define|#
directive|define
name|je_mallctlbymib
value|__mallctlbymib
end_define

begin_define
define|#
directive|define
name|je_malloc_stats_print
value|__malloc_stats_print
end_define

begin_define
define|#
directive|define
name|je_allocm
value|__allocm
end_define

begin_define
define|#
directive|define
name|je_rallocm
value|__rallocm
end_define

begin_define
define|#
directive|define
name|je_sallocm
value|__sallocm
end_define

begin_define
define|#
directive|define
name|je_dallocm
value|__dallocm
end_define

begin_define
define|#
directive|define
name|je_nallocm
value|__nallocm
end_define

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_define
define|#
directive|define
name|write
value|_write
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_define
define|#
directive|define
name|pthread_join
value|_pthread_join
end_define

begin_define
define|#
directive|define
name|pthread_once
value|_pthread_once
end_define

begin_define
define|#
directive|define
name|pthread_self
value|_pthread_self
end_define

begin_define
define|#
directive|define
name|pthread_equal
value|_pthread_equal
end_define

begin_define
define|#
directive|define
name|pthread_mutex_lock
value|_pthread_mutex_lock
end_define

begin_define
define|#
directive|define
name|pthread_mutex_trylock
value|_pthread_mutex_trylock
end_define

begin_define
define|#
directive|define
name|pthread_mutex_unlock
value|_pthread_mutex_unlock
end_define

begin_define
define|#
directive|define
name|pthread_cond_init
value|_pthread_cond_init
end_define

begin_define
define|#
directive|define
name|pthread_cond_wait
value|_pthread_cond_wait
end_define

begin_define
define|#
directive|define
name|pthread_cond_timedwait
value|_pthread_cond_timedwait
end_define

begin_define
define|#
directive|define
name|pthread_cond_signal
value|_pthread_cond_signal
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_C_
end_ifdef

begin_comment
comment|/*  * Define 'weak' symbols so that an application can have its own versions  * of malloc, calloc, realloc, free, et al.  */
end_comment

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__malloc
argument_list|,
name|malloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__calloc
argument_list|,
name|calloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__posix_memalign
argument_list|,
name|posix_memalign
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__aligned_alloc
argument_list|,
name|aligned_alloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__realloc
argument_list|,
name|realloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__free
argument_list|,
name|free
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__malloc_usable_size
argument_list|,
name|malloc_usable_size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__mallocx
argument_list|,
name|mallocx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__rallocx
argument_list|,
name|rallocx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__xallocx
argument_list|,
name|xallocx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sallocx
argument_list|,
name|sallocx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__dallocx
argument_list|,
name|dallocx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sdallocx
argument_list|,
name|sdallocx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__nallocx
argument_list|,
name|nallocx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__mallctl
argument_list|,
name|mallctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__mallctlnametomib
argument_list|,
name|mallctlnametomib
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__mallctlbymib
argument_list|,
name|mallctlbymib
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__malloc_stats_print
argument_list|,
name|malloc_stats_print
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__allocm
argument_list|,
name|allocm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__rallocm
argument_list|,
name|rallocm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sallocm
argument_list|,
name|sallocm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__dallocm
argument_list|,
name|dallocm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__nallocm
argument_list|,
name|nallocm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

