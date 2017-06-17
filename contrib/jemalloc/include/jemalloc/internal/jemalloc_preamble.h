begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_PREAMBLE_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_PREAMBLE_H
end_define

begin_include
include|#
directive|include
file|"jemalloc_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_decls.h"
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

begin_undef
undef|#
directive|undef
name|JEMALLOC_IS_MALLOC
end_undef

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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_macros.h"
end_include

begin_comment
comment|/*  * Note that the ordering matters here; the hook itself is name-mangled.  We  * want the inclusion of hooks to happen early, so that we hook as much as  * possible.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_NO_PRIVATE_NAMESPACE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_JET
end_ifndef

begin_include
include|#
directive|include
file|"jemalloc/internal/private_namespace.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"jemalloc/internal/private_namespace_jet.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"jemalloc/internal/hooks.h"
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
name|have_dss
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
name|char
modifier|*
specifier|const
name|config_malloc_conf
init|=
name|JEMALLOC_CONFIG_MALLOC_CONF
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
name|maps_coalesce
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_MAPS_COALESCE
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
name|config_thp
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_THP
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
name|config_cache_oblivious
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_CACHE_OBLIVIOUS
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
name|JEMALLOC_HAVE_SCHED_GETCPU
end_ifdef

begin_comment
comment|/* Currently percpu_arena depends on sched_getcpu. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_PERCPU_ARENA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|have_percpu_arena
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_PERCPU_ARENA
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Undocumented, and not recommended; the application should take full  * responsibility for tracking provenance.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|force_ivsalloc
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_FORCE_IVSALLOC
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
name|have_background_thread
init|=
ifdef|#
directive|ifdef
name|JEMALLOC_BACKGROUND_THREAD
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_PREAMBLE_H */
end_comment

end_unit

