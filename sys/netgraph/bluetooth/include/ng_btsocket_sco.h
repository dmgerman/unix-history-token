begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_btsocket_sco.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_btsocket_sco.h,v 1.3 2005/10/31 18:08:52 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_BTSOCKET_SCO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_BTSOCKET_SCO_H_
end_define

begin_comment
comment|/*  * SCO routing entry  */
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
name|ng_btsocket_sco_rtentry
block|{
name|bdaddr_t
name|src
decl_stmt|;
comment|/* source BD_ADDR */
name|u_int16_t
name|pkt_size
decl_stmt|;
comment|/* mtu */
name|u_int16_t
name|num_pkts
decl_stmt|;
comment|/* buffer size */
name|int32_t
name|pending
decl_stmt|;
comment|/* pending packets */
name|struct
name|ng_hook
modifier|*
name|hook
decl_stmt|;
comment|/* downstream hook */
name|LIST_ENTRY
argument_list|(
argument|ng_btsocket_sco_rtentry
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
name|ng_btsocket_sco_rtentry
name|ng_btsocket_sco_rtentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_sco_rtentry
modifier|*
name|ng_btsocket_sco_rtentry_p
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *****************************************************************************  **                      SOCK_SEQPACKET SCO sockets                         **  *****************************************************************************  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_BTSOCKET_SCO_SENDSPACE
value|1024
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_SCO_RECVSPACE
value|(64 * 1024)
end_define

begin_comment
comment|/*  * Bluetooth SCO socket PCB  */
end_comment

begin_struct
struct|struct
name|ng_btsocket_sco_pcb
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
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* socket flags */
define|#
directive|define
name|NG_BTSOCKET_SCO_CLIENT
value|(1<< 0)
comment|/* socket is client */
define|#
directive|define
name|NG_BTSOCKET_SCO_TIMO
value|(1<< 1)
comment|/* timeout pending */
name|u_int8_t
name|state
decl_stmt|;
comment|/* socket state */
define|#
directive|define
name|NG_BTSOCKET_SCO_CLOSED
value|0
comment|/* socket closed */
define|#
directive|define
name|NG_BTSOCKET_SCO_CONNECTING
value|1
comment|/* wait for connect */
define|#
directive|define
name|NG_BTSOCKET_SCO_OPEN
value|2
comment|/* socket open */
define|#
directive|define
name|NG_BTSOCKET_SCO_DISCONNECTING
value|3
comment|/* wait for disconnect */
name|struct
name|callout
name|timo
decl_stmt|;
comment|/* timeout */
name|ng_btsocket_sco_rtentry_p
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
argument|ng_btsocket_sco_pcb
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
name|ng_btsocket_sco_pcb
name|ng_btsocket_sco_pcb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_sco_pcb
modifier|*
name|ng_btsocket_sco_pcb_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|so2sco_pcb
parameter_list|(
name|so
parameter_list|)
define|\
value|((struct ng_btsocket_sco_pcb *)((so)->so_pcb))
end_define

begin_comment
comment|/*  * Bluetooth SCO socket methods  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|ng_btsocket_sco_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_sco_abort
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_sco_close
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_sco_accept
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
name|ng_btsocket_sco_attach
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
name|ng_btsocket_sco_bind
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
name|ng_btsocket_sco_connect
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
name|ng_btsocket_sco_control
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
name|ng_btsocket_sco_ctloutput
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
name|ng_btsocket_sco_detach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_sco_disconnect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_sco_listen
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
name|ng_btsocket_sco_peeraddr
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
name|ng_btsocket_sco_send
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
name|ng_btsocket_sco_sockaddr
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
comment|/* _NETGRAPH_BTSOCKET_SCO_H_ */
end_comment

end_unit

