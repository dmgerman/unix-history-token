begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_DECLS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_DECLS_H
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

begin_include
include|#
directive|include
file|"msvc_compat/windows_extra.h"
end_include

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__pnacl__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__native_client__
argument_list|)
end_if

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_open
argument_list|)
operator|&&
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_comment
comment|/* Android headers may define SYS_open to __NR_open even though         * __NR_open may not exist on AArch64 (superseded by __NR_openat). */
end_comment

begin_undef
undef|#
directive|undef
name|SYS_open
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_OS_UNFAIR_LOCK
end_ifdef

begin_include
include|#
directive|include
file|<os/lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_GLIBC_MALLOC_HOOK
end_ifdef

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_HAVE_MACH_ABSOLUTE_TIME
end_ifdef

begin_include
include|#
directive|include
file|<mach/mach_time.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|SSIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SSIZE_MAX
value|((ssize_t)(SIZE_T_MAX>> 1))
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

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_HAS_RESTRICT
end_ifdef

begin_define
define|#
directive|define
name|restrict
value|__restrict
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Disable warnings about deprecated system functions. */
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

begin_if
if|#
directive|if
name|_MSC_VER
operator|<
literal|1800
end_if

begin_function
specifier|static
name|int
name|isblank
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
operator|(
name|c
operator|==
literal|'\t'
operator|||
name|c
operator|==
literal|' '
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_H */
end_comment

end_unit

