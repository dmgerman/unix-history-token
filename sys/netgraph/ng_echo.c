begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_echo.c  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elisher<julian@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_echo.c,v 1.13 1999/11/01 09:24:51 julian Exp $  */
end_comment

begin_comment
comment|/*  * Netgraph "echo" node  *  * This node simply bounces data and messages back to whence they came.  */
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
file|<netgraph/ng_echo.h>
end_include

begin_comment
comment|/* Netgraph methods */
end_comment

begin_decl_stmt
specifier|static
name|ng_constructor_t
name|nge_cons
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_rcvmsg_t
name|nge_rcvmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_rcvdata_t
name|nge_rcvdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_disconnect_t
name|nge_disconnect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Netgraph type */
end_comment

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
name|NG_ECHO_NODE_TYPE
block|,
operator|.
name|constructor
operator|=
name|nge_cons
block|,
operator|.
name|rcvmsg
operator|=
name|nge_rcvmsg
block|,
operator|.
name|rcvdata
operator|=
name|nge_rcvdata
block|,
operator|.
name|disconnect
operator|=
name|nge_disconnect
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NETGRAPH_INIT
argument_list|(
name|echo
argument_list|,
operator|&
name|typestruct
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|nge_cons
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
comment|/*  * Receive control message. We just bounce it back as a reply.  */
end_comment

begin_function
specifier|static
name|int
name|nge_rcvmsg
parameter_list|(
name|node_p
name|node
parameter_list|,
name|item_p
name|item
parameter_list|,
name|hook_p
name|lasthook
parameter_list|)
block|{
name|struct
name|ng_mesg
modifier|*
name|msg
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|NGI_GET_MSG
argument_list|(
name|item
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|msg
operator|->
name|header
operator|.
name|flags
operator||=
name|NGF_RESP
expr_stmt|;
name|NG_RESPOND_MSG
argument_list|(
name|error
argument_list|,
name|node
argument_list|,
name|item
argument_list|,
name|msg
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
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
name|nge_rcvdata
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|item_p
name|item
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|NG_FWD_ITEM_HOOK
argument_list|(
name|error
argument_list|,
name|item
argument_list|,
name|hook
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Removal of the last link destroys the nodeo  */
end_comment

begin_function
specifier|static
name|int
name|nge_disconnect
parameter_list|(
name|hook_p
name|hook
parameter_list|)
block|{
if|if
condition|(
operator|(
name|NG_NODE_NUMHOOKS
argument_list|(
name|NG_HOOK_NODE
argument_list|(
name|hook
argument_list|)
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|NG_NODE_IS_VALID
argument_list|(
name|NG_HOOK_NODE
argument_list|(
name|hook
argument_list|)
argument_list|)
operator|)
condition|)
block|{
name|ng_rmnode_self
argument_list|(
name|NG_HOOK_NODE
argument_list|(
name|hook
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

