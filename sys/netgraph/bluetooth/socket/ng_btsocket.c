begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_btsocket.c  *  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_btsocket.c,v 1.3 2003/01/19 00:19:04 max Exp $  * $FreeBSD$  */
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
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
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
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/bitstring.h>
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
file|"ng_bluetooth.h"
end_include

begin_include
include|#
directive|include
file|"ng_hci.h"
end_include

begin_include
include|#
directive|include
file|"ng_l2cap.h"
end_include

begin_include
include|#
directive|include
file|"ng_btsocket.h"
end_include

begin_include
include|#
directive|include
file|"ng_btsocket_hci_raw.h"
end_include

begin_include
include|#
directive|include
file|"ng_btsocket_l2cap.h"
end_include

begin_include
include|#
directive|include
file|"ng_btsocket_rfcomm.h"
end_include

begin_function_decl
specifier|static
name|int
name|ng_btsocket_modevent
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|ng_btsocket_domain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Bluetooth raw HCI sockets  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|pr_usrreqs
name|ng_btsocket_hci_raw_usrreqs
init|=
block|{
name|ng_btsocket_hci_raw_abort
block|,
comment|/* abort */
name|pru_accept_notsupp
block|,
comment|/* accept */
name|ng_btsocket_hci_raw_attach
block|,
comment|/* attach */
name|ng_btsocket_hci_raw_bind
block|,
comment|/* bind */
name|ng_btsocket_hci_raw_connect
block|,
comment|/* connect */
name|pru_connect2_notsupp
block|,
comment|/* connect2 */
name|ng_btsocket_hci_raw_control
block|,
comment|/* control */
name|ng_btsocket_hci_raw_detach
block|,
comment|/* detach */
name|ng_btsocket_hci_raw_disconnect
block|,
comment|/* disconnect */
name|pru_listen_notsupp
block|,
comment|/* listen */
name|ng_btsocket_hci_raw_peeraddr
block|,
comment|/* peeraddr */
name|pru_rcvd_notsupp
block|,
comment|/* rcvd */
name|pru_rcvoob_notsupp
block|,
comment|/* rcvoob */
name|ng_btsocket_hci_raw_send
block|,
comment|/* send */
name|pru_sense_null
block|,
comment|/* send */
name|NULL
block|,
comment|/* shutdown */
name|ng_btsocket_hci_raw_sockaddr
block|,
comment|/* sockaddr */
name|sosend
block|,
name|soreceive
block|,
name|sopoll
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Bluetooth raw L2CAP sockets  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|pr_usrreqs
name|ng_btsocket_l2cap_raw_usrreqs
init|=
block|{
name|ng_btsocket_l2cap_raw_abort
block|,
comment|/* abort */
name|pru_accept_notsupp
block|,
comment|/* accept */
name|ng_btsocket_l2cap_raw_attach
block|,
comment|/* attach */
name|ng_btsocket_l2cap_raw_bind
block|,
comment|/* bind */
name|ng_btsocket_l2cap_raw_connect
block|,
comment|/* connect */
name|pru_connect2_notsupp
block|,
comment|/* connect2 */
name|ng_btsocket_l2cap_raw_control
block|,
comment|/* control */
name|ng_btsocket_l2cap_raw_detach
block|,
comment|/* detach */
name|ng_btsocket_l2cap_raw_disconnect
block|,
comment|/* disconnect */
name|pru_listen_notsupp
block|,
comment|/* listen */
name|ng_btsocket_l2cap_raw_peeraddr
block|,
comment|/* peeraddr */
name|pru_rcvd_notsupp
block|,
comment|/* rcvd */
name|pru_rcvoob_notsupp
block|,
comment|/* rcvoob */
name|ng_btsocket_l2cap_raw_send
block|,
comment|/* send */
name|pru_sense_null
block|,
comment|/* send */
name|NULL
block|,
comment|/* shutdown */
name|ng_btsocket_l2cap_raw_sockaddr
block|,
comment|/* sockaddr */
name|sosend
block|,
name|soreceive
block|,
name|sopoll
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Bluetooth SEQPACKET L2CAP sockets  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|pr_usrreqs
name|ng_btsocket_l2cap_usrreqs
init|=
block|{
name|ng_btsocket_l2cap_abort
block|,
comment|/* abort */
name|ng_btsocket_l2cap_accept
block|,
comment|/* accept */
name|ng_btsocket_l2cap_attach
block|,
comment|/* attach */
name|ng_btsocket_l2cap_bind
block|,
comment|/* bind */
name|ng_btsocket_l2cap_connect
block|,
comment|/* connect */
name|pru_connect2_notsupp
block|,
comment|/* connect2 */
name|ng_btsocket_l2cap_control
block|,
comment|/* control */
name|ng_btsocket_l2cap_detach
block|,
comment|/* detach */
name|ng_btsocket_l2cap_disconnect
block|,
comment|/* disconnect */
name|ng_btsocket_l2cap_listen
block|,
comment|/* listen */
name|ng_btsocket_l2cap_peeraddr
block|,
comment|/* peeraddr */
name|pru_rcvd_notsupp
block|,
comment|/* rcvd */
name|pru_rcvoob_notsupp
block|,
comment|/* rcvoob */
name|ng_btsocket_l2cap_send
block|,
comment|/* send */
name|pru_sense_null
block|,
comment|/* send */
name|NULL
block|,
comment|/* shutdown */
name|ng_btsocket_l2cap_sockaddr
block|,
comment|/* sockaddr */
name|sosend
block|,
name|soreceive
block|,
name|sopoll
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Bluetooth STREAM RFCOMM sockets  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|pr_usrreqs
name|ng_btsocket_rfcomm_usrreqs
init|=
block|{
name|ng_btsocket_rfcomm_abort
block|,
comment|/* abort */
name|ng_btsocket_rfcomm_accept
block|,
comment|/* accept */
name|ng_btsocket_rfcomm_attach
block|,
comment|/* attach */
name|ng_btsocket_rfcomm_bind
block|,
comment|/* bind */
name|ng_btsocket_rfcomm_connect
block|,
comment|/* connect */
name|pru_connect2_notsupp
block|,
comment|/* connect2 */
name|ng_btsocket_rfcomm_control
block|,
comment|/* control */
name|ng_btsocket_rfcomm_detach
block|,
comment|/* detach */
name|ng_btsocket_rfcomm_disconnect
block|,
comment|/* disconnect */
name|ng_btsocket_rfcomm_listen
block|,
comment|/* listen */
name|ng_btsocket_rfcomm_peeraddr
block|,
comment|/* peeraddr */
name|pru_rcvd_notsupp
block|,
comment|/* rcvd */
name|pru_rcvoob_notsupp
block|,
comment|/* rcvoob */
name|ng_btsocket_rfcomm_send
block|,
comment|/* send */
name|pru_sense_null
block|,
comment|/* send */
name|NULL
block|,
comment|/* shutdown */
name|ng_btsocket_rfcomm_sockaddr
block|,
comment|/* sockaddr */
name|sosend
block|,
name|soreceive
block|,
name|sopoll
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Definitions of protocols supported in the BLUETOOTH domain   */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|protosw
name|ng_btsocket_protosw
index|[]
init|=
block|{
block|{
name|SOCK_RAW
block|,
comment|/* protocol type */
operator|&
name|ng_btsocket_domain
block|,
comment|/* backpointer to domain */
name|BLUETOOTH_PROTO_HCI
block|,
comment|/* protocol */
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
comment|/* flags */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* input, output, ctlinput */
name|ng_btsocket_hci_raw_ctloutput
block|,
comment|/* ctloutput */
name|NULL
block|,
comment|/* ousrreq() */
name|ng_btsocket_hci_raw_init
block|,
comment|/* init */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* fasttimeo, slowtimo, drain */
operator|&
name|ng_btsocket_hci_raw_usrreqs
block|,
comment|/* usrreq table (above) */
comment|/* { NULL } */
comment|/* pfh (protocol filter head?) */
block|}
block|,
block|{
name|SOCK_RAW
block|,
comment|/* protocol type */
operator|&
name|ng_btsocket_domain
block|,
comment|/* backpointer to domain */
name|BLUETOOTH_PROTO_L2CAP
block|,
comment|/* protocol */
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
comment|/* flags */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* input, output, ctlinput */
name|NULL
block|,
comment|/* ctloutput */
name|NULL
block|,
comment|/* ousrreq() */
name|ng_btsocket_l2cap_raw_init
block|,
comment|/* init */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* fasttimeo, slowtimo, drain */
operator|&
name|ng_btsocket_l2cap_raw_usrreqs
block|,
comment|/* usrreq table (above) */
comment|/* { NULL } */
comment|/* pfh (protocol filter head?) */
block|}
block|,
block|{
name|SOCK_SEQPACKET
block|,
comment|/* protocol type */
operator|&
name|ng_btsocket_domain
block|,
comment|/* backpointer to domain */
name|BLUETOOTH_PROTO_L2CAP
block|,
comment|/* protocol */
name|PR_ATOMIC
operator||
name|PR_CONNREQUIRED
block|,
comment|/* flags */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* input, output, ctlinput */
name|ng_btsocket_l2cap_ctloutput
block|,
comment|/* ctloutput */
name|NULL
block|,
comment|/* ousrreq() */
name|ng_btsocket_l2cap_init
block|,
comment|/* init */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* fasttimeo, slowtimo, drain */
operator|&
name|ng_btsocket_l2cap_usrreqs
block|,
comment|/* usrreq table (above) */
comment|/* { NULL } */
comment|/* pfh (protocol filter head?) */
block|}
block|,
block|{
name|SOCK_STREAM
block|,
comment|/* protocol type */
operator|&
name|ng_btsocket_domain
block|,
comment|/* backpointer to domain */
name|BLUETOOTH_PROTO_RFCOMM
block|,
comment|/* protocol */
name|PR_ATOMIC
operator||
name|PR_CONNREQUIRED
block|,
comment|/* flags */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* input, output, ctlinput */
name|ng_btsocket_rfcomm_ctloutput
block|,
comment|/* ctloutput */
name|NULL
block|,
comment|/* ousrreq() */
name|ng_btsocket_rfcomm_init
block|,
comment|/* init */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* fasttimeo, slowtimo, drain */
operator|&
name|ng_btsocket_rfcomm_usrreqs
block|,
comment|/* usrreq table (above) */
comment|/* { NULL } */
comment|/* pfh (protocol filter head?) */
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ng_btsocket_protosw_size
define|\
value|(sizeof(ng_btsocket_protosw)/sizeof(ng_btsocket_protosw[0]))
end_define

begin_define
define|#
directive|define
name|ng_btsocket_protosw_end
define|\
value|&ng_btsocket_protosw[ng_btsocket_protosw_size]
end_define

begin_comment
comment|/*  * BLUETOOTH domain  */
end_comment

begin_decl_stmt
name|struct
name|domain
name|ng_btsocket_domain
init|=
block|{
name|AF_BLUETOOTH
block|,
comment|/* family */
literal|"bluetooth"
block|,
comment|/* domain name */
name|NULL
block|,
comment|/* init() */
name|NULL
block|,
comment|/* externalize() */
name|NULL
block|,
comment|/* dispose() */
name|ng_btsocket_protosw
block|,
comment|/* protosw entry */
name|ng_btsocket_protosw_end
block|,
comment|/* end of protosw entries */
name|NULL
block|,
comment|/* next domain in list */
name|NULL
block|,
comment|/* rtattach() */
literal|0
block|,
comment|/* arg to rtattach in bits */
literal|0
comment|/* maxrtkey */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Socket sysctl tree   */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_bluetooth_hci
argument_list|,
name|OID_AUTO
argument_list|,
name|sockets
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Bluetooth HCI sockets family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_bluetooth_l2cap
argument_list|,
name|OID_AUTO
argument_list|,
name|sockets
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Bluetooth L2CAP sockets family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_bluetooth_rfcomm
argument_list|,
name|OID_AUTO
argument_list|,
name|sockets
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Bluetooth RFCOMM sockets family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * Module   */
end_comment

begin_decl_stmt
specifier|static
name|moduledata_t
name|ng_btsocket_mod
init|=
block|{
literal|"ng_btsocket"
block|,
name|ng_btsocket_modevent
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|ng_btsocket
argument_list|,
name|ng_btsocket_mod
argument_list|,
name|SI_SUB_PSEUDO
argument_list|,
name|SI_ORDER_ANY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ng_btsocket
argument_list|,
name|NG_BLUETOOTH_VERSION
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ng_btsocket
argument_list|,
name|ng_bluetooth
argument_list|,
name|NG_BLUETOOTH_VERSION
argument_list|,
name|NG_BLUETOOTH_VERSION
argument_list|,
name|NG_BLUETOOTH_VERSION
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ng_btsocket
argument_list|,
name|netgraph
argument_list|,
name|NG_ABI_VERSION
argument_list|,
name|NG_ABI_VERSION
argument_list|,
name|NG_ABI_VERSION
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Handle loading and unloading for this node type.  * This is to handle auxiliary linkages (e.g protocol domain addition).  */
end_comment

begin_function
specifier|static
name|int
name|ng_btsocket_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|event
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|event
condition|)
block|{
case|case
name|MOD_LOAD
case|:
name|net_add_domain
argument_list|(
operator|&
name|ng_btsocket_domain
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
comment|/* XXX can't unload protocol domain yet */
name|error
operator|=
name|EBUSY
expr_stmt|;
break|break;
default|default:
name|error
operator|=
name|EOPNOTSUPP
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ng_btsocket_modevent */
end_comment

end_unit

