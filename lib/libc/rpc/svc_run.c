begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: svc_run.c,v 1.17 2000/07/06 03:10:35 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,   *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,   *   this list of conditions and the following disclaimer in the documentation   *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its   *   contributors may be used to endorse or promote products derived   *   from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   * POSSIBILITY OF SUCH DAMAGE.  */
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
name|sccsid2
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

begin_include
include|#
directive|include
file|"rpc_com.h"
end_include

begin_include
include|#
directive|include
file|"mt_misc.h"
end_include

begin_function
name|void
name|svc_run
parameter_list|()
block|{
name|fd_set
name|readfds
decl_stmt|,
name|cleanfds
decl_stmt|;
name|struct
name|timeval
name|timeout
decl_stmt|;
name|timeout
operator|.
name|tv_sec
operator|=
literal|30
expr_stmt|;
name|timeout
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
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
name|cleanfds
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
operator|&
name|timeout
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
name|__svc_clean_idle
argument_list|(
operator|&
name|cleanfds
argument_list|,
literal|30
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
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

