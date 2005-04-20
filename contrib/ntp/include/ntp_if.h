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

