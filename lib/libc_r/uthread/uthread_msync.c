begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * David Leonard<d@openbsd.org>, 1999. Public Domain.  *  * $OpenBSD: uthread_msync.c,v 1.2 1999/06/09 07:16:17 d Exp $  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
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
name|_msync
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
name|_thread_sys_msync
argument_list|(
name|addr
argument_list|,
name|len
argument_list|,
name|flags
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
name|int
name|msync
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
comment|/* 	 * XXX This is quite pointless unless we know how to get the 	 * file descriptor associated with the memory, and lock it for 	 * write. The only real use of this wrapper is to guarantee 	 * a cancellation point, as per the standard. sigh. 	 */
name|_thread_enter_cancellation_point
argument_list|()
expr_stmt|;
name|ret
operator|=
name|_msync
argument_list|(
name|addr
argument_list|,
name|len
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|_thread_leave_cancellation_point
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

