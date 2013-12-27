begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1986, 1993  *	The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)raw_cb.c	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_include
include|#
directive|include
file|<net/raw_cb.h>
end_include

begin_comment
comment|/*  * Routines to manage the raw protocol control blocks.  *  * TODO:  *	hash lookups by protocol family/protocol + address family  *	take care of unique address problems per AF?  *	redo address binding to allow wildcards  */
end_comment

begin_decl_stmt
name|struct
name|mtx
name|rawcb_mtx
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|VNET_DEFINE
argument_list|(
expr|struct
name|rawcb_list_head
argument_list|,
name|rawcb_list
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|SYSCTL_NODE
argument_list|(
name|_net
argument_list|,
name|OID_AUTO
argument_list|,
name|raw
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Raw socket infrastructure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|u_long
name|raw_sendspace
init|=
name|RAWSNDQ
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_net_raw
argument_list|,
name|OID_AUTO
argument_list|,
name|sendspace
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|raw_sendspace
argument_list|,
literal|0
argument_list|,
literal|"Default raw socket send space"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|u_long
name|raw_recvspace
init|=
name|RAWRCVQ
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_net_raw
argument_list|,
name|OID_AUTO
argument_list|,
name|recvspace
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|raw_recvspace
argument_list|,
literal|0
argument_list|,
literal|"Default raw socket receive space"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Allocate a control block and a nominal amount of buffer space for the  * socket.  */
end_comment

begin_function
name|int
name|raw_attach
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|proto
parameter_list|)
block|{
name|struct
name|rawcb
modifier|*
name|rp
init|=
name|sotorawcb
argument_list|(
name|so
argument_list|)
decl_stmt|;
name|int
name|error
decl_stmt|;
comment|/* 	 * It is assumed that raw_attach is called after space has been 	 * allocated for the rawcb; consumer protocols may simply allocate 	 * type struct rawcb, or a wrapper data structure that begins with a 	 * struct rawcb. 	 */
name|KASSERT
argument_list|(
name|rp
operator|!=
name|NULL
argument_list|,
operator|(
literal|"raw_attach: rp == NULL"
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|soreserve
argument_list|(
name|so
argument_list|,
name|raw_sendspace
argument_list|,
name|raw_recvspace
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|rp
operator|->
name|rcb_socket
operator|=
name|so
expr_stmt|;
name|rp
operator|->
name|rcb_proto
operator|.
name|sp_family
operator|=
name|so
operator|->
name|so_proto
operator|->
name|pr_domain
operator|->
name|dom_family
expr_stmt|;
name|rp
operator|->
name|rcb_proto
operator|.
name|sp_protocol
operator|=
name|proto
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|rawcb_mtx
argument_list|)
expr_stmt|;
name|LIST_INSERT_HEAD
argument_list|(
operator|&
name|V_rawcb_list
argument_list|,
name|rp
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|rawcb_mtx
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Detach the raw connection block and discard socket resources.  */
end_comment

begin_function
name|void
name|raw_detach
parameter_list|(
name|struct
name|rawcb
modifier|*
name|rp
parameter_list|)
block|{
name|struct
name|socket
modifier|*
name|so
init|=
name|rp
operator|->
name|rcb_socket
decl_stmt|;
name|KASSERT
argument_list|(
name|so
operator|->
name|so_pcb
operator|==
name|rp
argument_list|,
operator|(
literal|"raw_detach: so_pcb != rp"
operator|)
argument_list|)
expr_stmt|;
name|so
operator|->
name|so_pcb
operator|=
name|NULL
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|rawcb_mtx
argument_list|)
expr_stmt|;
name|LIST_REMOVE
argument_list|(
name|rp
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|rawcb_mtx
argument_list|)
expr_stmt|;
name|free
argument_list|(
call|(
name|caddr_t
call|)
argument_list|(
name|rp
argument_list|)
argument_list|,
name|M_PCB
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

