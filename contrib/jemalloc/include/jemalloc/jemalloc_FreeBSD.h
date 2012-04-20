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

begin_comment
comment|/*  * The following are architecture-dependent, so conditionally define them for  * each supported architecture.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPU_SPINWAIT
end_undef

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
name|LG_SIZEOF_PTR
value|2
end_define

begin_define
define|#
directive|define
name|CPU_SPINWAIT
value|__asm__ volatile("pause")
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
name|LG_SIZEOF_PTR
value|3
end_define

begin_define
define|#
directive|define
name|CPU_SPINWAIT
value|__asm__ volatile("pause")
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
name|__mips__
end_ifdef

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
name|__powerpc64__
end_ifdef

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
name|LG_SIZEOF_PTR
value|2
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

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_undef
undef|#
directive|undef
name|JEMALLOC_TLS_MODEL
end_undef

begin_define
define|#
directive|define
name|JEMALLOC_TLS_MODEL
end_define

begin_comment
comment|/* clang does not support tls_model yet. */
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
name|pthread_mutex_lock
value|_pthread_mutex_lock
end_define

begin_define
define|#
directive|define
name|pthread_mutex_unlock
value|_pthread_mutex_unlock
end_define

end_unit

