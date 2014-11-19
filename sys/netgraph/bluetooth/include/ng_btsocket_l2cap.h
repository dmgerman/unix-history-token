begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_btsocket_l2cap.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_btsocket_l2cap.h,v 1.4 2003/03/25 23:53:33 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_BTSOCKET_L2CAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_BTSOCKET_L2CAP_H_
end_define

begin_comment
comment|/*  * L2CAP routing entry  */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_hook
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ng_message
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ng_btsocket_l2cap_rtentry
block|{
name|bdaddr_t
name|src
decl_stmt|;
comment|/* source BD_ADDR */
name|struct
name|ng_hook
modifier|*
name|hook
decl_stmt|;
comment|/* downstream hook */
name|LIST_ENTRY
argument_list|(
argument|ng_btsocket_l2cap_rtentry
argument_list|)
name|next
expr_stmt|;
comment|/* link to next */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_l2cap_rtentry
name|ng_btsocket_l2cap_rtentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_l2cap_rtentry
modifier|*
name|ng_btsocket_l2cap_rtentry_p
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *****************************************************************************  **                          SOCK_RAW L2CAP sockets                         **  *****************************************************************************  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_BTSOCKET_L2CAP_RAW_SENDSPACE
value|NG_L2CAP_MTU_DEFAULT
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_L2CAP_RAW_RECVSPACE
value|NG_L2CAP_MTU_DEFAULT
end_define

begin_comment
comment|/*  * Bluetooth raw L2CAP socket PCB  */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_raw_pcb
block|{
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
comment|/* socket */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* flags */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_RAW_PRIVILEGED
value|(1<< 0)
name|bdaddr_t
name|src
decl_stmt|;
comment|/* source address */
name|bdaddr_t
name|dst
decl_stmt|;
comment|/* dest address */
name|ng_btsocket_l2cap_rtentry_p
name|rt
decl_stmt|;
comment|/* routing info */
name|u_int32_t
name|token
decl_stmt|;
comment|/* message token */
name|struct
name|ng_mesg
modifier|*
name|msg
decl_stmt|;
comment|/* message */
name|struct
name|mtx
name|pcb_mtx
decl_stmt|;
comment|/* pcb mutex */
name|LIST_ENTRY
argument_list|(
argument|ng_btsocket_l2cap_raw_pcb
argument_list|)
name|next
expr_stmt|;
comment|/* link to next PCB */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_l2cap_raw_pcb
name|ng_btsocket_l2cap_raw_pcb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_l2cap_raw_pcb
modifier|*
name|ng_btsocket_l2cap_raw_pcb_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|so2l2cap_raw_pcb
parameter_list|(
name|so
parameter_list|)
define|\
value|((struct ng_btsocket_l2cap_raw_pcb *)((so)->so_pcb))
end_define

begin_comment
comment|/*  * Bluetooth raw L2CAP socket methods  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|ng_btsocket_l2cap_raw_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_l2cap_raw_abort
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_l2cap_raw_close
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_raw_attach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_raw_bind
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_raw_connect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_raw_control
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_l2cap_raw_detach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_raw_disconnect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_raw_peeraddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_raw_send
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_raw_sockaddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*****************************************************************************  *****************************************************************************  **                    SOCK_SEQPACKET L2CAP sockets                         **  *****************************************************************************  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_BTSOCKET_L2CAP_SENDSPACE
value|NG_L2CAP_MTU_DEFAULT
end_define

begin_comment
comment|/* (64 * 1024) */
end_comment

begin_define
define|#
directive|define
name|NG_BTSOCKET_L2CAP_RECVSPACE
value|(64 * 1024)
end_define

begin_comment
comment|/*  * Bluetooth L2CAP socket PCB  */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_pcb
block|{
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
comment|/* Pointer to socket */
name|bdaddr_t
name|src
decl_stmt|;
comment|/* Source address */
name|bdaddr_t
name|dst
decl_stmt|;
comment|/* Destination address */
name|u_int16_t
name|psm
decl_stmt|;
comment|/* PSM */
name|u_int16_t
name|cid
decl_stmt|;
comment|/* Local channel ID */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* socket flags */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CLIENT
value|(1<< 0)
comment|/* socket is client */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_TIMO
value|(1<< 1)
comment|/* timeout pending */
name|u_int8_t
name|state
decl_stmt|;
comment|/* socket state */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CLOSED
value|0
comment|/* socket closed */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CONNECTING
value|1
comment|/* wait for connect */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CONFIGURING
value|2
comment|/* wait for config */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_OPEN
value|3
comment|/* socket open */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_DISCONNECTING
value|4
comment|/* wait for disconnect */
name|u_int8_t
name|cfg_state
decl_stmt|;
comment|/* config state */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CFG_IN
value|(1<< 0)
comment|/* incoming path done */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CFG_OUT
value|(1<< 1)
comment|/* outgoing path done */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CFG_BOTH
define|\
value|(NG_BTSOCKET_L2CAP_CFG_IN | NG_BTSOCKET_L2CAP_CFG_OUT)
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CFG_IN_SENT
value|(1<< 2)
comment|/* L2CAP ConfigReq sent */
define|#
directive|define
name|NG_BTSOCKET_L2CAP_CFG_OUT_SENT
value|(1<< 3)
comment|/* ---/--- */
name|u_int16_t
name|imtu
decl_stmt|;
comment|/* Incoming MTU */
name|ng_l2cap_flow_t
name|iflow
decl_stmt|;
comment|/* Input flow spec */
name|u_int16_t
name|omtu
decl_stmt|;
comment|/* Outgoing MTU */
name|ng_l2cap_flow_t
name|oflow
decl_stmt|;
comment|/* Outgoing flow spec */
name|u_int16_t
name|flush_timo
decl_stmt|;
comment|/* flush timeout */
name|u_int16_t
name|link_timo
decl_stmt|;
comment|/* link timeout */
name|struct
name|callout
name|timo
decl_stmt|;
comment|/* timeout */
name|u_int32_t
name|token
decl_stmt|;
comment|/* message token */
name|ng_btsocket_l2cap_rtentry_p
name|rt
decl_stmt|;
comment|/* routing info */
name|struct
name|mtx
name|pcb_mtx
decl_stmt|;
comment|/* pcb mutex */
name|LIST_ENTRY
argument_list|(
argument|ng_btsocket_l2cap_pcb
argument_list|)
name|next
expr_stmt|;
comment|/* link to next PCB */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_l2cap_pcb
name|ng_btsocket_l2cap_pcb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_l2cap_pcb
modifier|*
name|ng_btsocket_l2cap_pcb_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|so2l2cap_pcb
parameter_list|(
name|so
parameter_list|)
define|\
value|((struct ng_btsocket_l2cap_pcb *)((so)->so_pcb))
end_define

begin_comment
comment|/*  * Bluetooth L2CAP socket methods  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|ng_btsocket_l2cap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_l2cap_abort
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_l2cap_close
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_accept
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_attach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_bind
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_connect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_control
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_l2cap_detach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_disconnect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_listen
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_peeraddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_send
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_l2cap_sockaddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_BTSOCKET_L2CAP_H_ */
end_comment

end_unit

