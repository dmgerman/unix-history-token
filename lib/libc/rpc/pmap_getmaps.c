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
comment|/*static char *sccsid = "from: @(#)pmap_getmaps.c 1.10 87/08/11 Copyr 1984 Sun Micro";*/
end_comment

begin_comment
comment|/*static char *sccsid = "from: @(#)pmap_getmaps.c	2.2 88/08/01 4.0 RPCSRC";*/
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
comment|/*  * pmap_getmap.c  * Client interface to pmap rpc service.  * contains pmap_getmaps, which is only tcp service involved  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

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
file|<sys/socket.h>
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
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
operator|(
expr|struct
name|pmaplist
operator|*
operator|)
name|NULL
decl_stmt|;
name|int
name|socket
init|=
operator|-
literal|1
decl_stmt|;
name|struct
name|timeval
name|minutetimeout
decl_stmt|;
specifier|register
name|CLIENT
modifier|*
name|client
decl_stmt|;
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
name|socket
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
operator|(
name|CLIENT
operator|*
operator|)
name|NULL
condition|)
block|{
if|if
condition|(
name|CLNT_CALL
argument_list|(
name|client
argument_list|,
name|PMAPPROC_DUMP
argument_list|,
name|xdr_void
argument_list|,
name|NULL
argument_list|,
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
if|if
condition|(
name|socket
operator|!=
operator|-
literal|1
condition|)
operator|(
name|void
operator|)
name|_close
argument_list|(
name|socket
argument_list|)
expr_stmt|;
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

