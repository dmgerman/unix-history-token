begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_ip_input.c  */
end_comment

begin_comment
comment|/*-  * Copyright 2001 The Aerospace Corporation.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions, and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions, and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  The name of The Aerospace Corporation may not be used to endorse or  *     promote products derived from this software.  *  * THIS SOFTWARE IS PROVIDED BY THE AEROSPACE CORPORATION "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AEROSPACE CORPORATION BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author:		Brooks Davis<brooks@FreeBSD.org>  * Derived from:	ng_hole.c  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This node simply takes IP packets and calls ip_input on them  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
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
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/ng_message.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/netgraph.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/ng_ip_input.h>
end_include

begin_comment
comment|/* Netgraph methods */
end_comment

begin_decl_stmt
specifier|static
name|ng_constructor_t
name|ngipi_cons
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_rcvdata_t
name|ngipi_rcvdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_disconnect_t
name|ngipi_disconnect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|ng_type
name|typestruct
init|=
block|{
operator|.
name|version
operator|=
name|NG_ABI_VERSION
block|,
operator|.
name|name
operator|=
name|NG_IP_INPUT_NODE_TYPE
block|,
operator|.
name|constructor
operator|=
name|ngipi_cons
block|,
operator|.
name|rcvdata
operator|=
name|ngipi_rcvdata
block|,
operator|.
name|disconnect
operator|=
name|ngipi_disconnect
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NETGRAPH_INIT
argument_list|(
name|ip_input
argument_list|,
operator|&
name|typestruct
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * Be obliging. but no work to do.  */
end_comment

begin_function
specifier|static
name|int
name|ngipi_cons
parameter_list|(
name|node_p
name|node
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Receive data  */
end_comment

begin_function
specifier|static
name|int
name|ngipi_rcvdata
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|item_p
name|item
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|NGI_GET_M
argument_list|(
name|item
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|NG_FREE_ITEM
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|netisr_dispatch
argument_list|(
name|NETISR_IP
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Hook disconnection  */
end_comment

begin_function
specifier|static
name|int
name|ngipi_disconnect
parameter_list|(
name|hook_p
name|hook
parameter_list|)
block|{
if|if
condition|(
name|NG_NODE_NUMHOOKS
argument_list|(
name|NG_HOOK_NODE
argument_list|(
name|hook
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
name|ng_rmnode_self
argument_list|(
name|NG_HOOK_NODE
argument_list|(
name|hook
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

