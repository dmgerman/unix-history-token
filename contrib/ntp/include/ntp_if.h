begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sockets are not standard.  * So hide uglyness in include file.  */
end_comment

begin_comment
comment|/* was: defined(SYS_CONVEXOS9) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SYS_SYNC_QUEUE_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE__SYS_SYNC_SEMA_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|"/sys/sync/queue.h"
end_include

begin_include
include|#
directive|include
file|"/sys/sync/sema.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* was: defined(SYS_AIX) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TIME_WITH_SYS_TIME
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* was: (defined(SYS_SOLARIS)&& !defined(bsd)) || defined(SYS_SUNOS4) */
end_comment

begin_comment
comment|/* was: defined(SYS_UNIXWARE1) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* was: #if defined(SYS_PTX) || defined(SYS_SINIXM) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STREAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STROPTS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Was: #if defined(SYS_SVR4) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_STREAMS_DEVICE_FOR_IF_CONFIG
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_undef
undef|#
directive|undef
name|SIOCGIFCONF
end_undef

begin_undef
undef|#
directive|undef
name|SIOCGIFFLAGS
end_undef

begin_undef
undef|#
directive|undef
name|SIOCGIFADDR
end_undef

begin_undef
undef|#
directive|undef
name|SIOCGIFBRDADDR
end_undef

begin_undef
undef|#
directive|undef
name|SIOCGIFNETMASK
end_undef

begin_define
define|#
directive|define
name|SIOCGIFCONF
value|IPIOC_GETIFCONF
end_define

begin_define
define|#
directive|define
name|SIOCGIFFLAGS
value|IPIOC_GETIFFLAGS
end_define

begin_define
define|#
directive|define
name|SIOCGIFADDR
value|IPIOC_GETIFADDR
end_define

begin_define
define|#
directive|define
name|SIOCGIFBRDADDR
value|IPIOC_GETIFBRDADDR
end_define

begin_define
define|#
directive|define
name|SIOCGIFNETMASK
value|IPIOC_GETIFNETMASK
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* We don't need this now that sys/sockio.h is handled above */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_STREAMS_DEVICE_FOR_IF_CONFIG */
end_comment

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_STREAMS_DEVICE_FOR_IF_CONFIG */
end_comment

begin_comment
comment|/* was #endif SYS_SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NET_IF_H */
end_comment

end_unit

