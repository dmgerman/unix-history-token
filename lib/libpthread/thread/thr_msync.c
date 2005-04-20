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

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__msync
argument_list|,
name|msync
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|__msync
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
name|struct
name|pthread
modifier|*
name|curthread
init|=
name|_get_curthread
argument_list|()
decl_stmt|;
name|int
name|ret
decl_stmt|;
comment|/* 	 * XXX This is quite pointless unless we know how to get the 	 * file descriptor associated with the memory, and lock it for 	 * write. The only real use of this wrapper is to guarantee 	 * a cancellation point, as per the standard. sigh. 	 */
name|_thr_cancel_enter
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
name|ret
operator|=
name|__sys_msync
argument_list|(
name|addr
argument_list|,
name|len
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|_thr_cancel_leave
argument_list|(
name|curthread
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

