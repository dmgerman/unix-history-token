begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_btsocket_hci_raw.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_btsocket_hci_raw.h,v 1.3 2003/03/25 23:53:32 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_BTSOCKET_HCI_RAW_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_BTSOCKET_HCI_RAW_H_
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_HCI_RAW_SENDSPACE
value|(4 * 1024)
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_HCI_RAW_RECVSPACE
value|(4 * 1024)
end_define

begin_comment
comment|/*  * Bluetooth raw HCI socket PCB  */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_pcb
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
name|NG_BTSOCKET_HCI_RAW_DIRECTION
value|(1<< 0)
define|#
directive|define
name|NG_BTSOCKET_HCI_RAW_PRIVILEGED
value|(1<< 1)
name|struct
name|sockaddr_hci
name|addr
decl_stmt|;
comment|/* local address */
name|struct
name|ng_btsocket_hci_raw_filter
name|filter
decl_stmt|;
comment|/* filter */
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
name|LIST_ENTRY
argument_list|(
argument|ng_btsocket_hci_raw_pcb
argument_list|)
name|next
expr_stmt|;
comment|/* link to next */
name|struct
name|mtx
name|pcb_mtx
decl_stmt|;
comment|/* pcb mutex */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_hci_raw_pcb
name|ng_btsocket_hci_raw_pcb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_hci_raw_pcb
modifier|*
name|ng_btsocket_hci_raw_pcb_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|so2hci_raw_pcb
parameter_list|(
name|so
parameter_list|)
define|\
value|((struct ng_btsocket_hci_raw_pcb *)((so)->so_pcb))
end_define

begin_comment
comment|/*  * Bluetooth raw HCI socket methods  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|ng_btsocket_hci_raw_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_hci_raw_abort
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_hci_raw_attach
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
name|ng_btsocket_hci_raw_bind
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
name|ng_btsocket_hci_raw_connect
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
name|ng_btsocket_hci_raw_control
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
name|ng_btsocket_hci_raw_ctloutput
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
name|ng_btsocket_hci_raw_detach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_hci_raw_disconnect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_hci_raw_peeraddr
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
name|ng_btsocket_hci_raw_send
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
name|ng_btsocket_hci_raw_sockaddr
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
comment|/* ndef _NETGRAPH_BTSOCKET_HCI_RAW_H_ */
end_comment

end_unit

