begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: svc_run.c,v 1.17 2000/07/06 03:10:35 christos Exp $	*/
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"from: @(#)svc_run.c 1.1 87/10/13 Copyr 1984 Sun Micro"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"from: @(#)svc_run.c	2.1 88/07/29 4.0 RPCSRC"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This is the rpc server side idle loop  * Wait for input, call server program.  */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|"reentrant.h"
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_function
name|void
name|svc_run
parameter_list|()
block|{
name|fd_set
name|readfds
decl_stmt|;
specifier|extern
name|rwlock_t
name|svc_fd_lock
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|rwlock_rdlock
argument_list|(
operator|&
name|svc_fd_lock
argument_list|)
expr_stmt|;
name|readfds
operator|=
name|svc_fdset
expr_stmt|;
name|rwlock_unlock
argument_list|(
operator|&
name|svc_fd_lock
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|_select
argument_list|(
name|svc_maxfd
operator|+
literal|1
argument_list|,
operator|&
name|readfds
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
condition|)
block|{
case|case
operator|-
literal|1
case|:
name|FD_ZERO
argument_list|(
operator|&
name|readfds
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
block|{
continue|continue;
block|}
name|_warn
argument_list|(
literal|"svc_run: - select failed"
argument_list|)
expr_stmt|;
return|return;
case|case
literal|0
case|:
continue|continue;
default|default:
name|svc_getreqset
argument_list|(
operator|&
name|readfds
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/*  *      This function causes svc_run() to exit by telling it that it has no  *      more work to do.  */
end_comment

begin_function
name|void
name|svc_exit
parameter_list|()
block|{
specifier|extern
name|rwlock_t
name|svc_fd_lock
decl_stmt|;
name|rwlock_wrlock
argument_list|(
operator|&
name|svc_fd_lock
argument_list|)
expr_stmt|;
name|FD_ZERO
argument_list|(
operator|&
name|svc_fdset
argument_list|)
expr_stmt|;
name|rwlock_unlock
argument_list|(
operator|&
name|svc_fd_lock
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

