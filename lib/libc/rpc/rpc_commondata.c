begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpc_commondata.c,v 1.7 2000/06/02 23:11:13 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,   *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,   *   this list of conditions and the following disclaimer in the documentation   *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its   *   contributors may be used to endorse or promote products derived   *   from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   * POSSIBILITY OF SUCH DAMAGE.  */
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
literal|"@(#)rpc_commondata.c	2.1 88/07/29 4.0 RPCSRC"
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

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_comment
comment|/*  * This file should only contain common data (global data) that is exported  * by public interfaces   */
end_comment

begin_decl_stmt
name|struct
name|opaque_auth
name|_null_auth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fd_set
name|svc_fdset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svc_maxfd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

end_unit

