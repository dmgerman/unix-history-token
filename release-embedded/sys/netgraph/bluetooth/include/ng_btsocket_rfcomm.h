begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_btsocket_rfcomm.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2003 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_btsocket_rfcomm.h,v 1.10 2003/03/29 22:27:42 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_BTSOCKET_RFCOMM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_BTSOCKET_RFCOMM_H_
end_define

begin_comment
comment|/*****************************************************************************  *****************************************************************************  **                              RFCOMM                                     **  *****************************************************************************  *****************************************************************************/
end_comment

begin_comment
comment|/* XXX FIXME this does not belong here */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_DEFAULT_MTU
value|667
end_define

begin_define
define|#
directive|define
name|RFCOMM_MAX_MTU
value|1024
end_define

begin_define
define|#
directive|define
name|RFCOMM_DEFAULT_CREDITS
value|7
end_define

begin_define
define|#
directive|define
name|RFCOMM_MAX_CREDITS
value|40
end_define

begin_comment
comment|/* RFCOMM frame types */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_FRAME_SABM
value|0x2f
end_define

begin_define
define|#
directive|define
name|RFCOMM_FRAME_DISC
value|0x43
end_define

begin_define
define|#
directive|define
name|RFCOMM_FRAME_UA
value|0x63
end_define

begin_define
define|#
directive|define
name|RFCOMM_FRAME_DM
value|0x0f
end_define

begin_define
define|#
directive|define
name|RFCOMM_FRAME_UIH
value|0xef
end_define

begin_comment
comment|/* RFCOMM MCC commands */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_TEST
value|0x08
end_define

begin_comment
comment|/* Test */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_FCON
value|0x28
end_define

begin_comment
comment|/* Flow Control on */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_FCOFF
value|0x18
end_define

begin_comment
comment|/* Flow Control off */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_MSC
value|0x38
end_define

begin_comment
comment|/* Modem Status Command */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_RPN
value|0x24
end_define

begin_comment
comment|/* Remote Port Negotiation */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_RLS
value|0x14
end_define

begin_comment
comment|/* Remote Line Status */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_PN
value|0x20
end_define

begin_comment
comment|/* Port Negotiation */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_NSC
value|0x04
end_define

begin_comment
comment|/* Non Supported Command */
end_comment

begin_comment
comment|/* RFCOMM modem signals */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MODEM_FC
value|0x02
end_define

begin_comment
comment|/* Flow Control asserted */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MODEM_RTC
value|0x04
end_define

begin_comment
comment|/* Ready To Communicate */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MODEM_RTR
value|0x08
end_define

begin_comment
comment|/* Ready To Receive */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MODEM_IC
value|0x40
end_define

begin_comment
comment|/* Incomming Call */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MODEM_DV
value|0x80
end_define

begin_comment
comment|/* Data Valid */
end_comment

begin_comment
comment|/* RPN parameters - baud rate */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_2400
value|0x0
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_4800
value|0x1
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_7200
value|0x2
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_9600
value|0x3
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_19200
value|0x4
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_38400
value|0x5
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_57600
value|0x6
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_115200
value|0x7
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_BR_230400
value|0x8
end_define

begin_comment
comment|/* RPN parameters - data bits */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_RPN_DATA_5
value|0x0
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_DATA_6
value|0x2
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_DATA_7
value|0x1
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_DATA_8
value|0x3
end_define

begin_comment
comment|/* RPN parameters - stop bit */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_RPN_STOP_1
value|0
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_STOP_15
value|1
end_define

begin_comment
comment|/* RPN parameters - parity */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_RPN_PARITY_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PARITY_ODD
value|0x4
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PARITY_EVEN
value|0x5
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PARITY_MARK
value|0x6
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PARITY_SPACE
value|0x7
end_define

begin_comment
comment|/* RPN parameters - flow control */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_RPN_FLOW_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_XON_CHAR
value|0x11
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_XOFF_CHAR
value|0x13
end_define

begin_comment
comment|/* RPN parameters - mask */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_BITRATE
value|0x0001
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_DATA
value|0x0002
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_STOP
value|0x0004
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_PARITY
value|0x0008
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_PARITY_TYPE
value|0x0010
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_XON
value|0x0020
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_XOFF
value|0x0040
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_FLOW
value|0x3F00
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PM_ALL
value|0x3F7F
end_define

begin_comment
comment|/* RFCOMM frame header */
end_comment

begin_struct
struct|struct
name|rfcomm_frame_hdr
block|{
name|u_int8_t
name|address
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
comment|/* Actual size could be 2 bytes */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* RFCOMM command frame header */
end_comment

begin_struct
struct|struct
name|rfcomm_cmd_hdr
block|{
name|u_int8_t
name|address
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
name|fcs
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* RFCOMM MCC command header */
end_comment

begin_struct
struct|struct
name|rfcomm_mcc_hdr
block|{
name|u_int8_t
name|type
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
comment|/* XXX FIXME Can actual size be 2 bytes?? */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* RFCOMM MSC command */
end_comment

begin_struct
struct|struct
name|rfcomm_mcc_msc
block|{
name|u_int8_t
name|address
decl_stmt|;
name|u_int8_t
name|modem
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* RFCOMM RPN command */
end_comment

begin_struct
struct|struct
name|rfcomm_mcc_rpn
block|{
name|u_int8_t
name|dlci
decl_stmt|;
name|u_int8_t
name|bit_rate
decl_stmt|;
name|u_int8_t
name|line_settings
decl_stmt|;
name|u_int8_t
name|flow_control
decl_stmt|;
name|u_int8_t
name|xon_char
decl_stmt|;
name|u_int8_t
name|xoff_char
decl_stmt|;
name|u_int16_t
name|param_mask
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* RFCOMM RLS command */
end_comment

begin_struct
struct|struct
name|rfcomm_mcc_rls
block|{
name|u_int8_t
name|address
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* RFCOMM PN command */
end_comment

begin_struct
struct|struct
name|rfcomm_mcc_pn
block|{
name|u_int8_t
name|dlci
decl_stmt|;
name|u_int8_t
name|flow_control
decl_stmt|;
name|u_int8_t
name|priority
decl_stmt|;
name|u_int8_t
name|ack_timer
decl_stmt|;
name|u_int16_t
name|mtu
decl_stmt|;
name|u_int8_t
name|max_retrans
decl_stmt|;
name|u_int8_t
name|credits
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* RFCOMM frame parsing macros */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_DLCI
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0xfc)>> 2)
end_define

begin_define
define|#
directive|define
name|RFCOMM_CHANNEL
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0xf8)>> 3)
end_define

begin_define
define|#
directive|define
name|RFCOMM_DIRECTION
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0x04)>> 2)
end_define

begin_define
define|#
directive|define
name|RFCOMM_TYPE
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0xef))
end_define

begin_define
define|#
directive|define
name|RFCOMM_EA
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0x01))
end_define

begin_define
define|#
directive|define
name|RFCOMM_CR
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0x02)>> 1)
end_define

begin_define
define|#
directive|define
name|RFCOMM_PF
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0x10)>> 4)
end_define

begin_define
define|#
directive|define
name|RFCOMM_SRVCHANNEL
parameter_list|(
name|dlci
parameter_list|)
value|((dlci)>> 1)
end_define

begin_define
define|#
directive|define
name|RFCOMM_MKADDRESS
parameter_list|(
name|cr
parameter_list|,
name|dlci
parameter_list|)
define|\
value|((((dlci)& 0x3f)<< 2) | ((cr)<< 1) | 0x01)
end_define

begin_define
define|#
directive|define
name|RFCOMM_MKCONTROL
parameter_list|(
name|type
parameter_list|,
name|pf
parameter_list|)
value|((((type)& 0xef) | ((pf)<< 4)))
end_define

begin_define
define|#
directive|define
name|RFCOMM_MKDLCI
parameter_list|(
name|dir
parameter_list|,
name|channel
parameter_list|)
value|((((channel)& 0x1f)<< 1) | (dir))
end_define

begin_define
define|#
directive|define
name|RFCOMM_MKLEN8
parameter_list|(
name|len
parameter_list|)
value|(((len)<< 1) | 1)
end_define

begin_define
define|#
directive|define
name|RFCOMM_MKLEN16
parameter_list|(
name|len
parameter_list|)
value|((len)<< 1)
end_define

begin_comment
comment|/* RFCOMM MCC macros */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_MCC_TYPE
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0xfc)>> 2)
end_define

begin_define
define|#
directive|define
name|RFCOMM_MCC_LENGTH
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0xfe)>> 1)
end_define

begin_define
define|#
directive|define
name|RFCOMM_MKMCC_TYPE
parameter_list|(
name|cr
parameter_list|,
name|type
parameter_list|)
value|((((type)<< 2) | ((cr)<< 1) | 0x01))
end_define

begin_comment
comment|/* RPN macros */
end_comment

begin_define
define|#
directive|define
name|RFCOMM_RPN_DATA_BITS
parameter_list|(
name|line
parameter_list|)
value|((line)& 0x3)
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_STOP_BITS
parameter_list|(
name|line
parameter_list|)
value|(((line)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|RFCOMM_RPN_PARITY
parameter_list|(
name|line
parameter_list|)
value|(((line)>> 3)& 0x3)
end_define

begin_define
define|#
directive|define
name|RFCOMM_MKRPN_LINE_SETTINGS
parameter_list|(
name|data
parameter_list|,
name|stop
parameter_list|,
name|parity
parameter_list|)
define|\
value|(((data)& 0x3) | (((stop)& 0x1)<< 2) | (((parity)& 0x3)<< 3))
end_define

begin_comment
comment|/*****************************************************************************  *****************************************************************************  **                      SOCK_STREAM RFCOMM sockets                         **  *****************************************************************************  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SENDSPACE
define|\
value|(RFCOMM_MAX_CREDITS * RFCOMM_DEFAULT_MTU * 2)
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_RECVSPACE
define|\
value|(RFCOMM_MAX_CREDITS * RFCOMM_DEFAULT_MTU * 2)
end_define

begin_comment
comment|/*  * Bluetooth RFCOMM session. One L2CAP connection == one RFCOMM session  */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_btsocket_rfcomm_pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ng_btsocket_rfcomm_session
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ng_btsocket_rfcomm_session
block|{
name|struct
name|socket
modifier|*
name|l2so
decl_stmt|;
comment|/* L2CAP socket */
name|u_int16_t
name|state
decl_stmt|;
comment|/* session state */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_CLOSED
value|0
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_LISTENING
value|1
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_CONNECTING
value|2
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_CONNECTED
value|3
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_OPEN
value|4
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_DISCONNECTING
value|5
name|u_int16_t
name|flags
decl_stmt|;
comment|/* session flags */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_INITIATOR
value|(1<< 0)
comment|/* initiator */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_LFC
value|(1<< 1)
comment|/* local flow */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_SESSION_RFC
value|(1<< 2)
comment|/* remote flow */
define|#
directive|define
name|INITIATOR
parameter_list|(
name|s
parameter_list|)
define|\
value|(((s)->flags& NG_BTSOCKET_RFCOMM_SESSION_INITIATOR)? 1 : 0)
name|u_int16_t
name|mtu
decl_stmt|;
comment|/* default MTU */
name|struct
name|ng_bt_mbufq
name|outq
decl_stmt|;
comment|/* outgoing queue */
name|struct
name|mtx
name|session_mtx
decl_stmt|;
comment|/* session lock */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ng_btsocket_rfcomm_pcb
argument_list|)
name|dlcs
expr_stmt|;
comment|/* active DLC */
name|LIST_ENTRY
argument_list|(
argument|ng_btsocket_rfcomm_session
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
name|ng_btsocket_rfcomm_session
name|ng_btsocket_rfcomm_session_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_rfcomm_session
modifier|*
name|ng_btsocket_rfcomm_session_p
typedef|;
end_typedef

begin_comment
comment|/*  * Bluetooth RFCOMM socket PCB (DLC)  */
end_comment

begin_struct
struct|struct
name|ng_btsocket_rfcomm_pcb
block|{
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
comment|/* RFCOMM socket */
name|struct
name|ng_btsocket_rfcomm_session
modifier|*
name|session
decl_stmt|;
comment|/* RFCOMM session */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* DLC flags */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_TIMO
value|(1<< 0)
comment|/* timeout pending */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_CFC
value|(1<< 1)
comment|/* credit flow ctrl */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_TIMEDOUT
value|(1<< 2)
comment|/* timeout happend */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_DETACHED
value|(1<< 3)
comment|/* DLC detached */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_SENDING
value|(1<< 4)
comment|/* send pending */
name|u_int16_t
name|state
decl_stmt|;
comment|/* DLC state */
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_CLOSED
value|0
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_W4_CONNECT
value|1
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_CONFIGURING
value|2
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_CONNECTING
value|3
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_CONNECTED
value|4
define|#
directive|define
name|NG_BTSOCKET_RFCOMM_DLC_DISCONNECTING
value|5
name|bdaddr_t
name|src
decl_stmt|;
comment|/* source address */
name|bdaddr_t
name|dst
decl_stmt|;
comment|/* dest. address */
name|u_int8_t
name|channel
decl_stmt|;
comment|/* RFCOMM channel */
name|u_int8_t
name|dlci
decl_stmt|;
comment|/* RFCOMM DLCI */
name|u_int8_t
name|lmodem
decl_stmt|;
comment|/* local mdm signls */
name|u_int8_t
name|rmodem
decl_stmt|;
comment|/* remote -/- */
name|u_int16_t
name|mtu
decl_stmt|;
comment|/* MTU */
name|int16_t
name|rx_cred
decl_stmt|;
comment|/* RX credits */
name|int16_t
name|tx_cred
decl_stmt|;
comment|/* TX credits */
name|struct
name|mtx
name|pcb_mtx
decl_stmt|;
comment|/* PCB lock */
name|struct
name|callout_handle
name|timo
decl_stmt|;
comment|/* timeout */
name|LIST_ENTRY
argument_list|(
argument|ng_btsocket_rfcomm_pcb
argument_list|)
name|session_next
expr_stmt|;
comment|/* link to next */
name|LIST_ENTRY
argument_list|(
argument|ng_btsocket_rfcomm_pcb
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
name|ng_btsocket_rfcomm_pcb
name|ng_btsocket_rfcomm_pcb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_btsocket_rfcomm_pcb
modifier|*
name|ng_btsocket_rfcomm_pcb_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|so2rfcomm_pcb
parameter_list|(
name|so
parameter_list|)
define|\
value|((struct ng_btsocket_rfcomm_pcb *)((so)->so_pcb))
end_define

begin_comment
comment|/*  * Bluetooth RFCOMM socket methods  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|ng_btsocket_rfcomm_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_rfcomm_abort
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_btsocket_rfcomm_close
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_rfcomm_accept
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
name|ng_btsocket_rfcomm_attach
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
name|ng_btsocket_rfcomm_bind
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
name|ng_btsocket_rfcomm_connect
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
name|ng_btsocket_rfcomm_control
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
name|ng_btsocket_rfcomm_ctloutput
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
name|ng_btsocket_rfcomm_detach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_rfcomm_disconnect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_btsocket_rfcomm_listen
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
name|ng_btsocket_rfcomm_peeraddr
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
name|ng_btsocket_rfcomm_send
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
name|ng_btsocket_rfcomm_sockaddr
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
comment|/* _NETGRAPH_BTSOCKET_RFCOMM_H_ */
end_comment

end_unit

