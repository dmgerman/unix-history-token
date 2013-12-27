begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pmap_getmaps.c,v 1.16 2000/07/06 03:10:34 christos Exp $	*/
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
literal|"@(#)pmap_getmaps.c 1.10 87/08/11 Copyr 1984 Sun Micro"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)pmap_getmaps.c	2.2 88/08/01 4.0 RPCSRC"
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
comment|/*  * pmap_getmap.c  * Client interface to pmap rpc service.  * contains pmap_getmaps, which is only tcp service involved  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<rpc/pmap_prot.h>
end_include

begin_include
include|#
directive|include
file|<rpc/pmap_clnt.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_define
define|#
directive|define
name|NAMELEN
value|255
end_define

begin_define
define|#
directive|define
name|MAX_BROADCAST_SIZE
value|1400
end_define

begin_comment
comment|/*  * Get a copy of the current port maps.  * Calls the pmap service remotely to do get the maps.  */
end_comment

begin_function
name|struct
name|pmaplist
modifier|*
name|pmap_getmaps
parameter_list|(
name|address
parameter_list|)
name|struct
name|sockaddr_in
modifier|*
name|address
decl_stmt|;
block|{
name|struct
name|pmaplist
modifier|*
name|head
init|=
name|NULL
decl_stmt|;
name|int
name|sock
init|=
operator|-
literal|1
decl_stmt|;
name|struct
name|timeval
name|minutetimeout
decl_stmt|;
name|CLIENT
modifier|*
name|client
decl_stmt|;
name|assert
argument_list|(
name|address
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|minutetimeout
operator|.
name|tv_sec
operator|=
literal|60
expr_stmt|;
name|minutetimeout
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|address
operator|->
name|sin_port
operator|=
name|htons
argument_list|(
name|PMAPPORT
argument_list|)
expr_stmt|;
name|client
operator|=
name|clnttcp_create
argument_list|(
name|address
argument_list|,
name|PMAPPROG
argument_list|,
name|PMAPVERS
argument_list|,
operator|&
name|sock
argument_list|,
literal|50
argument_list|,
literal|500
argument_list|)
expr_stmt|;
if|if
condition|(
name|client
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|CLNT_CALL
argument_list|(
name|client
argument_list|,
operator|(
name|rpcproc_t
operator|)
name|PMAPPROC_DUMP
argument_list|,
operator|(
name|xdrproc_t
operator|)
name|xdr_void
argument_list|,
name|NULL
argument_list|,
operator|(
name|xdrproc_t
operator|)
name|xdr_pmaplist
argument_list|,
operator|&
name|head
argument_list|,
name|minutetimeout
argument_list|)
operator|!=
name|RPC_SUCCESS
condition|)
block|{
name|clnt_perror
argument_list|(
name|client
argument_list|,
literal|"pmap_getmaps rpc problem"
argument_list|)
expr_stmt|;
block|}
name|CLNT_DESTROY
argument_list|(
name|client
argument_list|)
expr_stmt|;
block|}
name|address
operator|->
name|sin_port
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|head
operator|)
return|;
block|}
end_function

end_unit

