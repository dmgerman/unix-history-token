begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_hci_misc.c  */
end_comment

begin_comment
comment|/*-  * Copyright (c) Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_hci_misc.c,v 1.5 2003/09/08 18:57:51 max Exp $  * $FreeBSD$  */
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
file|<sys/queue.h>
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
file|<netgraph/bluetooth/include/ng_bluetooth.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/include/ng_hci.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/hci/ng_hci_var.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/hci/ng_hci_cmds.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/hci/ng_hci_evnt.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/hci/ng_hci_ulpi.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/hci/ng_hci_misc.h>
end_include

begin_comment
comment|/******************************************************************************  ******************************************************************************  **                              Utility routines  ******************************************************************************  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Give packet to RAW hook  * Assumes input mbuf is read only.  */
end_comment

begin_function
name|void
name|ng_hci_mtap
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
init|=
name|NULL
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|unit
operator|->
name|raw
operator|!=
name|NULL
operator|&&
name|NG_HOOK_IS_VALID
argument_list|(
name|unit
operator|->
name|raw
argument_list|)
condition|)
block|{
name|m
operator|=
name|m_dup
argument_list|(
name|m0
argument_list|,
name|M_DONTWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|!=
name|NULL
condition|)
name|NG_SEND_DATA_ONLY
argument_list|(
name|error
argument_list|,
name|unit
operator|->
name|raw
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
name|NG_HCI_INFO
argument_list|(
literal|"%s: %s - Could not forward packet, error=%d\n"
argument_list|,
name|__func__
argument_list|,
name|NG_NODE_NAME
argument_list|(
name|unit
operator|->
name|node
argument_list|)
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* ng_hci_mtap */
end_comment

begin_comment
comment|/*  * Send notification to the upper layer's  */
end_comment

begin_function
name|void
name|ng_hci_node_is_up
parameter_list|(
name|node_p
name|node
parameter_list|,
name|hook_p
name|hook
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|int
name|arg2
parameter_list|)
block|{
name|ng_hci_unit_p
name|unit
init|=
name|NULL
decl_stmt|;
name|struct
name|ng_mesg
modifier|*
name|msg
init|=
name|NULL
decl_stmt|;
name|ng_hci_node_up_ep
modifier|*
name|ep
init|=
name|NULL
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
name|node
operator|==
name|NULL
operator|||
name|NG_NODE_NOT_VALID
argument_list|(
name|node
argument_list|)
operator|||
name|hook
operator|==
name|NULL
operator|||
name|NG_HOOK_NOT_VALID
argument_list|(
name|hook
argument_list|)
condition|)
return|return;
name|unit
operator|=
operator|(
name|ng_hci_unit_p
operator|)
name|NG_NODE_PRIVATE
argument_list|(
name|node
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|unit
operator|->
name|state
operator|&
name|NG_HCI_UNIT_READY
operator|)
operator|!=
name|NG_HCI_UNIT_READY
condition|)
return|return;
if|if
condition|(
name|hook
operator|!=
name|unit
operator|->
name|acl
operator|&&
name|hook
operator|!=
name|unit
operator|->
name|sco
condition|)
return|return;
name|NG_MKMESSAGE
argument_list|(
name|msg
argument_list|,
name|NGM_HCI_COOKIE
argument_list|,
name|NGM_HCI_NODE_UP
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|ep
argument_list|)
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|msg
operator|!=
name|NULL
condition|)
block|{
name|ep
operator|=
operator|(
name|ng_hci_node_up_ep
operator|*
operator|)
operator|(
name|msg
operator|->
name|data
operator|)
expr_stmt|;
if|if
condition|(
name|hook
operator|==
name|unit
operator|->
name|acl
condition|)
block|{
name|NG_HCI_BUFF_ACL_SIZE
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|ep
operator|->
name|pkt_size
argument_list|)
expr_stmt|;
name|NG_HCI_BUFF_ACL_TOTAL
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|ep
operator|->
name|num_pkts
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|NG_HCI_BUFF_SCO_SIZE
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|ep
operator|->
name|pkt_size
argument_list|)
expr_stmt|;
name|NG_HCI_BUFF_SCO_TOTAL
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|ep
operator|->
name|num_pkts
argument_list|)
expr_stmt|;
block|}
name|bcopy
argument_list|(
operator|&
name|unit
operator|->
name|bdaddr
argument_list|,
operator|&
name|ep
operator|->
name|bdaddr
argument_list|,
sizeof|sizeof
argument_list|(
name|ep
operator|->
name|bdaddr
argument_list|)
argument_list|)
expr_stmt|;
name|NG_SEND_MSG_HOOK
argument_list|(
name|error
argument_list|,
name|node
argument_list|,
name|msg
argument_list|,
name|hook
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
name|error
operator|=
name|ENOMEM
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
name|NG_HCI_INFO
argument_list|(
literal|"%s: %s - failed to send NODE_UP message to hook \"%s\", error=%d\n"
argument_list|,
name|__func__
argument_list|,
name|NG_NODE_NAME
argument_list|(
name|unit
operator|->
name|node
argument_list|)
argument_list|,
name|NG_HOOK_NAME
argument_list|(
name|hook
argument_list|)
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ng_hci_node_is_up */
end_comment

begin_comment
comment|/*  * Clean unit (helper)  */
end_comment

begin_function
name|void
name|ng_hci_unit_clean
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|,
name|int
name|reason
parameter_list|)
block|{
name|int
name|size
decl_stmt|;
comment|/* Drain command queue */
if|if
condition|(
name|unit
operator|->
name|state
operator|&
name|NG_HCI_UNIT_COMMAND_PENDING
condition|)
name|ng_hci_command_untimeout
argument_list|(
name|unit
argument_list|)
expr_stmt|;
name|NG_BT_MBUFQ_DRAIN
argument_list|(
operator|&
name|unit
operator|->
name|cmdq
argument_list|)
expr_stmt|;
name|NG_HCI_BUFF_CMD_SET
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Clean up connection list */
while|while
condition|(
operator|!
name|LIST_EMPTY
argument_list|(
operator|&
name|unit
operator|->
name|con_list
argument_list|)
condition|)
block|{
name|ng_hci_unit_con_p
name|con
init|=
name|LIST_FIRST
argument_list|(
operator|&
name|unit
operator|->
name|con_list
argument_list|)
decl_stmt|;
comment|/* Remove all timeouts (if any) */
if|if
condition|(
name|con
operator|->
name|flags
operator|&
name|NG_HCI_CON_TIMEOUT_PENDING
condition|)
name|ng_hci_con_untimeout
argument_list|(
name|con
argument_list|)
expr_stmt|;
comment|/* 		 * Notify upper layer protocol and destroy connection  		 * descriptor. Do not really care about the result. 		 */
name|ng_hci_lp_discon_ind
argument_list|(
name|con
argument_list|,
name|reason
argument_list|)
expr_stmt|;
name|ng_hci_free_con
argument_list|(
name|con
argument_list|)
expr_stmt|;
block|}
name|NG_HCI_BUFF_ACL_TOTAL
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|NG_HCI_BUFF_ACL_FREE
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|NG_HCI_BUFF_SCO_TOTAL
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|NG_HCI_BUFF_SCO_FREE
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|size
argument_list|)
expr_stmt|;
comment|/* Clean up neighbors list */
name|ng_hci_flush_neighbor_cache
argument_list|(
name|unit
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ng_hci_unit_clean */
end_comment

begin_comment
comment|/*  * Allocate and link new unit neighbor cache entry  */
end_comment

begin_function
name|ng_hci_neighbor_p
name|ng_hci_new_neighbor
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|)
block|{
name|ng_hci_neighbor_p
name|n
init|=
name|NULL
decl_stmt|;
name|MALLOC
argument_list|(
name|n
argument_list|,
name|ng_hci_neighbor_p
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|n
argument_list|)
argument_list|,
name|M_NETGRAPH_HCI
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|!=
name|NULL
condition|)
block|{
name|getmicrotime
argument_list|(
operator|&
name|n
operator|->
name|updated
argument_list|)
expr_stmt|;
name|LIST_INSERT_HEAD
argument_list|(
operator|&
name|unit
operator|->
name|neighbors
argument_list|,
name|n
argument_list|,
name|next
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_hci_new_neighbor */
end_comment

begin_comment
comment|/*  * Free unit neighbor cache entry  */
end_comment

begin_function
name|void
name|ng_hci_free_neighbor
parameter_list|(
name|ng_hci_neighbor_p
name|n
parameter_list|)
block|{
name|LIST_REMOVE
argument_list|(
name|n
argument_list|,
name|next
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|n
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|n
argument_list|)
argument_list|)
expr_stmt|;
name|FREE
argument_list|(
name|n
argument_list|,
name|M_NETGRAPH_HCI
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ng_hci_free_neighbor */
end_comment

begin_comment
comment|/*  * Flush neighbor cache   */
end_comment

begin_function
name|void
name|ng_hci_flush_neighbor_cache
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|)
block|{
while|while
condition|(
operator|!
name|LIST_EMPTY
argument_list|(
operator|&
name|unit
operator|->
name|neighbors
argument_list|)
condition|)
name|ng_hci_free_neighbor
argument_list|(
name|LIST_FIRST
argument_list|(
operator|&
name|unit
operator|->
name|neighbors
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ng_hci_flush_neighbor_cache */
end_comment

begin_comment
comment|/*  * Lookup unit in neighbor cache  */
end_comment

begin_function
name|ng_hci_neighbor_p
name|ng_hci_get_neighbor
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|,
name|bdaddr_p
name|bdaddr
parameter_list|)
block|{
name|ng_hci_neighbor_p
name|n
init|=
name|NULL
decl_stmt|;
for|for
control|(
name|n
operator|=
name|LIST_FIRST
argument_list|(
operator|&
name|unit
operator|->
name|neighbors
argument_list|)
init|;
name|n
operator|!=
name|NULL
condition|;
control|)
block|{
name|ng_hci_neighbor_p
name|nn
init|=
name|LIST_NEXT
argument_list|(
name|n
argument_list|,
name|next
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ng_hci_neighbor_stale
argument_list|(
name|n
argument_list|)
condition|)
block|{
if|if
condition|(
name|bcmp
argument_list|(
operator|&
name|n
operator|->
name|bdaddr
argument_list|,
name|bdaddr
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|bdaddr
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
else|else
name|ng_hci_free_neighbor
argument_list|(
name|n
argument_list|)
expr_stmt|;
comment|/* remove old entry */
name|n
operator|=
name|nn
expr_stmt|;
block|}
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_hci_get_neighbor */
end_comment

begin_comment
comment|/*  * Check if neighbor entry is stale  */
end_comment

begin_function
name|int
name|ng_hci_neighbor_stale
parameter_list|(
name|ng_hci_neighbor_p
name|n
parameter_list|)
block|{
name|struct
name|timeval
name|now
decl_stmt|;
name|getmicrotime
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
return|return
operator|(
name|now
operator|.
name|tv_sec
operator|-
name|n
operator|->
name|updated
operator|.
name|tv_sec
operator|>
name|bluetooth_hci_max_neighbor_age
argument_list|()
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_hci_neighbor_stale */
end_comment

begin_comment
comment|/*  * Allocate and link new connection descriptor  */
end_comment

begin_function
name|ng_hci_unit_con_p
name|ng_hci_new_con
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|,
name|int
name|link_type
parameter_list|)
block|{
name|ng_hci_unit_con_p
name|con
init|=
name|NULL
decl_stmt|;
name|int
name|num_pkts
decl_stmt|;
specifier|static
name|int
name|fake_con_handle
init|=
literal|0x0f00
decl_stmt|;
name|MALLOC
argument_list|(
name|con
argument_list|,
name|ng_hci_unit_con_p
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|con
argument_list|)
argument_list|,
name|M_NETGRAPH_HCI
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
if|if
condition|(
name|con
operator|!=
name|NULL
condition|)
block|{
name|con
operator|->
name|unit
operator|=
name|unit
expr_stmt|;
name|con
operator|->
name|state
operator|=
name|NG_HCI_CON_CLOSED
expr_stmt|;
comment|/* 		 * XXX 		 * 		 * Assign fake connection handle to the connection descriptor. 		 * Bluetooth specification marks 0x0f00 - 0x0fff connection 		 * handles as reserved. We need this fake connection handles 		 * for timeouts. Connection handle will be passed as argument 		 * to timeout so when timeout happens we can find the right 		 * connection descriptor. We can not pass pointers, because 		 * timeouts are external (to Netgraph) events and there might 		 * be a race when node/hook goes down and timeout event already 		 * went into node's queue 		 */
name|con
operator|->
name|con_handle
operator|=
name|fake_con_handle
operator|++
expr_stmt|;
if|if
condition|(
name|fake_con_handle
operator|>
literal|0x0fff
condition|)
name|fake_con_handle
operator|=
literal|0x0f00
expr_stmt|;
name|con
operator|->
name|link_type
operator|=
name|link_type
expr_stmt|;
if|if
condition|(
name|con
operator|->
name|link_type
operator|==
name|NG_HCI_LINK_ACL
condition|)
name|NG_HCI_BUFF_ACL_TOTAL
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|num_pkts
argument_list|)
expr_stmt|;
else|else
name|NG_HCI_BUFF_SCO_TOTAL
argument_list|(
name|unit
operator|->
name|buffer
argument_list|,
name|num_pkts
argument_list|)
expr_stmt|;
name|NG_BT_ITEMQ_INIT
argument_list|(
operator|&
name|con
operator|->
name|conq
argument_list|,
name|num_pkts
argument_list|)
expr_stmt|;
name|ng_callout_init
argument_list|(
operator|&
name|con
operator|->
name|con_timo
argument_list|)
expr_stmt|;
name|LIST_INSERT_HEAD
argument_list|(
operator|&
name|unit
operator|->
name|con_list
argument_list|,
name|con
argument_list|,
name|next
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|con
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_hci_new_con */
end_comment

begin_comment
comment|/*  * Free connection descriptor  */
end_comment

begin_function
name|void
name|ng_hci_free_con
parameter_list|(
name|ng_hci_unit_con_p
name|con
parameter_list|)
block|{
name|LIST_REMOVE
argument_list|(
name|con
argument_list|,
name|next
argument_list|)
expr_stmt|;
comment|/* 	 * If we have pending packets then assume that Host Controller has  	 * flushed these packets and we can free them too 	 */
if|if
condition|(
name|con
operator|->
name|link_type
operator|==
name|NG_HCI_LINK_ACL
condition|)
name|NG_HCI_BUFF_ACL_FREE
argument_list|(
name|con
operator|->
name|unit
operator|->
name|buffer
argument_list|,
name|con
operator|->
name|pending
argument_list|)
expr_stmt|;
else|else
name|NG_HCI_BUFF_SCO_FREE
argument_list|(
name|con
operator|->
name|unit
operator|->
name|buffer
argument_list|,
name|con
operator|->
name|pending
argument_list|)
expr_stmt|;
name|NG_BT_ITEMQ_DESTROY
argument_list|(
operator|&
name|con
operator|->
name|conq
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|con
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|con
argument_list|)
argument_list|)
expr_stmt|;
name|FREE
argument_list|(
name|con
argument_list|,
name|M_NETGRAPH_HCI
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ng_hci_free_con */
end_comment

begin_comment
comment|/*  * Lookup connection for given unit and connection handle.  */
end_comment

begin_function
name|ng_hci_unit_con_p
name|ng_hci_con_by_handle
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|,
name|int
name|con_handle
parameter_list|)
block|{
name|ng_hci_unit_con_p
name|con
init|=
name|NULL
decl_stmt|;
name|LIST_FOREACH
argument_list|(
argument|con
argument_list|,
argument|&unit->con_list
argument_list|,
argument|next
argument_list|)
if|if
condition|(
name|con
operator|->
name|con_handle
operator|==
name|con_handle
condition|)
break|break;
return|return
operator|(
name|con
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_hci_con_by_handle */
end_comment

begin_comment
comment|/*  * Lookup connection for given unit, link type and remove unit address  */
end_comment

begin_function
name|ng_hci_unit_con_p
name|ng_hci_con_by_bdaddr
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|,
name|bdaddr_p
name|bdaddr
parameter_list|,
name|int
name|link_type
parameter_list|)
block|{
name|ng_hci_unit_con_p
name|con
init|=
name|NULL
decl_stmt|;
name|LIST_FOREACH
argument_list|(
argument|con
argument_list|,
argument|&unit->con_list
argument_list|,
argument|next
argument_list|)
if|if
condition|(
name|con
operator|->
name|link_type
operator|==
name|link_type
operator|&&
name|bcmp
argument_list|(
operator|&
name|con
operator|->
name|bdaddr
argument_list|,
name|bdaddr
argument_list|,
sizeof|sizeof
argument_list|(
name|bdaddr_t
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
break|break;
return|return
operator|(
name|con
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_hci_con_by_bdaddr */
end_comment

begin_comment
comment|/*  * Set HCI command timeout  * XXX FIXME: check return code from ng_callout  */
end_comment

begin_function
name|int
name|ng_hci_command_timeout
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|)
block|{
if|if
condition|(
name|unit
operator|->
name|state
operator|&
name|NG_HCI_UNIT_COMMAND_PENDING
condition|)
name|panic
argument_list|(
literal|"%s: %s - Duplicated command timeout!\n"
argument_list|,
name|__func__
argument_list|,
name|NG_NODE_NAME
argument_list|(
name|unit
operator|->
name|node
argument_list|)
argument_list|)
expr_stmt|;
name|unit
operator|->
name|state
operator||=
name|NG_HCI_UNIT_COMMAND_PENDING
expr_stmt|;
name|ng_callout
argument_list|(
operator|&
name|unit
operator|->
name|cmd_timo
argument_list|,
name|unit
operator|->
name|node
argument_list|,
name|NULL
argument_list|,
name|bluetooth_hci_command_timeout
argument_list|()
argument_list|,
name|ng_hci_process_command_timeout
argument_list|,
name|NULL
argument_list|,
literal|0
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
comment|/* ng_hci_command_timeout */
end_comment

begin_comment
comment|/*  * Unset HCI command timeout  */
end_comment

begin_function
name|int
name|ng_hci_command_untimeout
parameter_list|(
name|ng_hci_unit_p
name|unit
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|unit
operator|->
name|state
operator|&
name|NG_HCI_UNIT_COMMAND_PENDING
operator|)
condition|)
name|panic
argument_list|(
literal|"%s: %s - No command timeout!\n"
argument_list|,
name|__func__
argument_list|,
name|NG_NODE_NAME
argument_list|(
name|unit
operator|->
name|node
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ng_uncallout
argument_list|(
operator|&
name|unit
operator|->
name|cmd_timo
argument_list|,
name|unit
operator|->
name|node
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|ETIMEDOUT
operator|)
return|;
name|unit
operator|->
name|state
operator|&=
operator|~
name|NG_HCI_UNIT_COMMAND_PENDING
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_hci_command_untimeout */
end_comment

begin_comment
comment|/*  * Set HCI connection timeout  * XXX FIXME: check return code from ng_callout  */
end_comment

begin_function
name|int
name|ng_hci_con_timeout
parameter_list|(
name|ng_hci_unit_con_p
name|con
parameter_list|)
block|{
if|if
condition|(
name|con
operator|->
name|flags
operator|&
name|NG_HCI_CON_TIMEOUT_PENDING
condition|)
name|panic
argument_list|(
literal|"%s: %s - Duplicated connection timeout!\n"
argument_list|,
name|__func__
argument_list|,
name|NG_NODE_NAME
argument_list|(
name|con
operator|->
name|unit
operator|->
name|node
argument_list|)
argument_list|)
expr_stmt|;
name|con
operator|->
name|flags
operator||=
name|NG_HCI_CON_TIMEOUT_PENDING
expr_stmt|;
name|ng_callout
argument_list|(
operator|&
name|con
operator|->
name|con_timo
argument_list|,
name|con
operator|->
name|unit
operator|->
name|node
argument_list|,
name|NULL
argument_list|,
name|bluetooth_hci_connect_timeout
argument_list|()
argument_list|,
name|ng_hci_process_con_timeout
argument_list|,
name|NULL
argument_list|,
name|con
operator|->
name|con_handle
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
comment|/* ng_hci_con_timeout */
end_comment

begin_comment
comment|/*  * Unset HCI connection timeout  */
end_comment

begin_function
name|int
name|ng_hci_con_untimeout
parameter_list|(
name|ng_hci_unit_con_p
name|con
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|con
operator|->
name|flags
operator|&
name|NG_HCI_CON_TIMEOUT_PENDING
operator|)
condition|)
name|panic
argument_list|(
literal|"%s: %s - No connection timeout!\n"
argument_list|,
name|__func__
argument_list|,
name|NG_NODE_NAME
argument_list|(
name|con
operator|->
name|unit
operator|->
name|node
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ng_uncallout
argument_list|(
operator|&
name|con
operator|->
name|con_timo
argument_list|,
name|con
operator|->
name|unit
operator|->
name|node
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|ETIMEDOUT
operator|)
return|;
name|con
operator|->
name|flags
operator|&=
operator|~
name|NG_HCI_CON_TIMEOUT_PENDING
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_hci_con_untimeout */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Convert numeric error code/reason to a string  */
end_comment

begin_define
unit|char const * const ng_hci_str_error(u_int16_t code) {
define|#
directive|define
name|LAST_ERROR_CODE
value|((sizeof(s)/sizeof(s[0]))-1)
end_define

begin_comment
unit|static char const * const	s[] = {
comment|/* 0x00 */
end_comment

begin_comment
unit|"No error",
comment|/* 0x01 */
end_comment

begin_comment
unit|"Unknown HCI command",
comment|/* 0x02 */
end_comment

begin_comment
unit|"No connection",
comment|/* 0x03 */
end_comment

begin_comment
unit|"Hardware failure",
comment|/* 0x04 */
end_comment

begin_comment
unit|"Page timeout",
comment|/* 0x05 */
end_comment

begin_comment
unit|"Authentication failure",
comment|/* 0x06 */
end_comment

begin_comment
unit|"Key missing",
comment|/* 0x07 */
end_comment

begin_comment
unit|"Memory full",
comment|/* 0x08 */
end_comment

begin_comment
unit|"Connection timeout",
comment|/* 0x09 */
end_comment

begin_comment
unit|"Max number of connections",
comment|/* 0x0a */
end_comment

begin_comment
unit|"Max number of SCO connections to a unit",
comment|/* 0x0b */
end_comment

begin_comment
unit|"ACL connection already exists",
comment|/* 0x0c */
end_comment

begin_comment
unit|"Command disallowed",
comment|/* 0x0d */
end_comment

begin_comment
unit|"Host rejected due to limited resources",
comment|/* 0x0e */
end_comment

begin_comment
unit|"Host rejected due to securiity reasons",
comment|/* 0x0f */
end_comment

begin_comment
unit|"Host rejected due to remote unit is a personal unit",
comment|/* 0x10 */
end_comment

begin_comment
unit|"Host timeout",
comment|/* 0x11 */
end_comment

begin_comment
unit|"Unsupported feature or parameter value",
comment|/* 0x12 */
end_comment

begin_comment
unit|"Invalid HCI command parameter",
comment|/* 0x13 */
end_comment

begin_comment
unit|"Other end terminated connection: User ended connection",
comment|/* 0x14 */
end_comment

begin_comment
unit|"Other end terminated connection: Low resources",
comment|/* 0x15 */
end_comment

begin_comment
unit|"Other end terminated connection: About to power off",
comment|/* 0x16 */
end_comment

begin_comment
unit|"Connection terminated by local host",
comment|/* 0x17 */
end_comment

begin_comment
unit|"Repeated attempts",
comment|/* 0x18 */
end_comment

begin_comment
unit|"Pairing not allowed",
comment|/* 0x19 */
end_comment

begin_comment
unit|"Unknown LMP PDU",
comment|/* 0x1a */
end_comment

begin_comment
unit|"Unsupported remote feature",
comment|/* 0x1b */
end_comment

begin_comment
unit|"SCO offset rejected",
comment|/* 0x1c */
end_comment

begin_comment
unit|"SCO interval rejected",
comment|/* 0x1d */
end_comment

begin_comment
unit|"SCO air mode rejected",
comment|/* 0x1e */
end_comment

begin_comment
unit|"Invalid LMP parameters",
comment|/* 0x1f */
end_comment

begin_comment
unit|"Unspecified error",
comment|/* 0x20 */
end_comment

begin_comment
unit|"Unsupported LMP parameter value",
comment|/* 0x21 */
end_comment

begin_comment
unit|"Role change not allowed",
comment|/* 0x22 */
end_comment

begin_comment
unit|"LMP response timeout",
comment|/* 0x23 */
end_comment

begin_comment
unit|"LMP error transaction collision",
comment|/* 0x24 */
end_comment

begin_comment
unit|"LMP PSU not allowed",
comment|/* 0x25 */
end_comment

begin_comment
unit|"Encryption mode not acceptable",
comment|/* 0x26 */
end_comment

begin_comment
unit|"Unit key used",
comment|/* 0x27 */
end_comment

begin_comment
unit|"QoS is not supported",
comment|/* 0x28 */
end_comment

begin_comment
unit|"Instant passed",
comment|/* 0x29 */
end_comment

begin_comment
unit|"Paring with unit key not supported",
comment|/* SHOULD ALWAYS BE LAST */
end_comment

begin_comment
unit|"Unknown error" 	};  	return ((code>= LAST_ERROR_CODE)? s[LAST_ERROR_CODE] : s[code]); }
comment|/* ng_hci_str_error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

