begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_comment
comment|/*static char *sccsid = "from: @(#)svc_run.c 1.1 87/10/13 Copyr 1984 Sun Micro";*/
end_comment

begin_comment
comment|/*static char *sccsid = "from: @(#)svc_run.c	2.1 88/07/29 4.0 RPCSRC";*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the rpc server side idle loop  * Wait for input, call server program.  */
end_comment

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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|_rpc_dtablesize
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|my_svc_run
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|FD_SETSIZE
name|fd_set
name|readfds
decl_stmt|;
else|#
directive|else
name|int
name|readfds
decl_stmt|;
endif|#
directive|endif
comment|/* def FD_SETSIZE */
specifier|extern
name|int
name|errno
decl_stmt|;
specifier|extern
name|int
name|forked
decl_stmt|;
name|int
name|pid
decl_stmt|;
comment|/* Establish the identity of the parent ypserv process. */
name|pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
ifdef|#
directive|ifdef
name|FD_SETSIZE
name|readfds
operator|=
name|svc_fdset
expr_stmt|;
else|#
directive|else
name|readfds
operator|=
name|svc_fds
expr_stmt|;
endif|#
directive|endif
comment|/* def FD_SETSIZE */
switch|switch
condition|(
name|select
argument_list|(
name|_rpc_dtablesize
argument_list|()
argument_list|,
operator|&
name|readfds
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|(
expr|struct
name|timeval
operator|*
operator|)
literal|0
argument_list|)
condition|)
block|{
case|case
operator|-
literal|1
case|:
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
block|{
continue|continue;
block|}
name|perror
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
if|if
condition|(
name|forked
operator|&&
name|pid
operator|!=
name|getpid
argument_list|()
condition|)
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

