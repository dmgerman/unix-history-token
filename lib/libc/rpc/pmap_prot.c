begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pmap_prot.c,v 1.10 2000/01/22 22:19:18 mycroft Exp $	*/
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
literal|"@(#)pmap_prot.c 1.17 87/08/11 Copyr 1984 Sun Micro"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)pmap_prot.c	2.1 88/07/29 4.0 RPCSRC"
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
comment|/*  * pmap_prot.c  * Protocol for the local binder service, or pmap.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_include
include|#
directive|include
file|<rpc/pmap_prot.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_function
name|bool_t
name|xdr_pmap
parameter_list|(
name|xdrs
parameter_list|,
name|regs
parameter_list|)
name|XDR
modifier|*
name|xdrs
decl_stmt|;
name|struct
name|pmap
modifier|*
name|regs
decl_stmt|;
block|{
name|assert
argument_list|(
name|xdrs
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|regs
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
name|regs
operator|->
name|pm_prog
argument_list|)
operator|&&
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
name|regs
operator|->
name|pm_vers
argument_list|)
operator|&&
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
name|regs
operator|->
name|pm_prot
argument_list|)
condition|)
return|return
operator|(
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
name|regs
operator|->
name|pm_port
argument_list|)
operator|)
return|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

end_unit

