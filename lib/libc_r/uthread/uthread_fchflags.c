begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * David Leonard<d@openbsd.org>, 1999. Public Domain.  *  * $OpenBSD: uthread_fchflags.c,v 1.1 1999/01/08 05:42:18 d Exp $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"pthread_private.h"
end_include

begin_function
name|int
name|_fchflags
parameter_list|(
name|int
name|fd
parameter_list|,
name|u_long
name|flags
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
if|if
condition|(
operator|(
name|ret
operator|=
name|_FD_LOCK
argument_list|(
name|fd
argument_list|,
name|FD_WRITE
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|ret
operator|=
name|_thread_sys_fchflags
argument_list|(
name|fd
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|_FD_UNLOCK
argument_list|(
name|fd
argument_list|,
name|FD_WRITE
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

begin_expr_stmt
name|__strong_reference
argument_list|(
name|_fchflags
argument_list|,
name|fchflags
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

