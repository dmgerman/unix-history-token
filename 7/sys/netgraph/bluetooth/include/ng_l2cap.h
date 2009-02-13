begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_l2cap.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_l2cap.h,v 1.2 2003/04/27 00:52:26 max Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file contains everything that application needs to know about  * Link Layer Control and Adaptation Protocol (L2CAP). All information   * was obtained from Bluetooth Specification Book v1.1.  *  * This file can be included by both kernel and userland applications.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_L2CAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_L2CAP_H_
end_define

begin_comment
comment|/**************************************************************************  **************************************************************************  **     Netgraph node hook name, type name and type cookie and commands  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* Netgraph node hook names */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_HOOK_HCI
value|"hci"
end_define

begin_comment
comment|/* HCI<-> L2CAP */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_HOOK_L2C
value|"l2c"
end_define

begin_comment
comment|/* L2CAP<-> Upper */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_HOOK_CTL
value|"ctl"
end_define

begin_comment
comment|/* L2CAP<-> User  */
end_comment

begin_comment
comment|/* Node type name and type cookie */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_NODE_TYPE
value|"l2cap"
end_define

begin_define
define|#
directive|define
name|NGM_L2CAP_COOKIE
value|1000774185
end_define

begin_comment
comment|/**************************************************************************  **************************************************************************  **                   Common defines and types (L2CAP)  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/*  * Channel IDs are assigned relative to the instance of L2CAP node, i.e.  * relative to the unit. So the total number of channels that unit can have  * open at the same time is 0xffff - 0x0040 = 0xffbf (65471). This number  * does not depend on number of connections.  */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_NULL_CID
value|0x0000
end_define

begin_comment
comment|/* DO NOT USE THIS CID */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_SIGNAL_CID
value|0x0001
end_define

begin_comment
comment|/* signaling channel ID */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CLT_CID
value|0x0002
end_define

begin_comment
comment|/* connectionless channel ID */
end_comment

begin_comment
comment|/* 0x0003 - 0x003f Reserved */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_FIRST_CID
value|0x0040
end_define

begin_comment
comment|/* dynamically alloc. (start) */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_LAST_CID
value|0xffff
end_define

begin_comment
comment|/* dynamically alloc. (end) */
end_comment

begin_comment
comment|/* L2CAP MTU */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_MTU_MINIMUM
value|48
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_MTU_DEFAULT
value|672
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_MTU_MAXIMUM
value|0xffff
end_define

begin_comment
comment|/* L2CAP flush and link timeouts */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_FLUSH_TIMO_DEFAULT
value|0xffff
end_define

begin_comment
comment|/* always retransmit */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_LINK_TIMO_DEFAULT
value|0xffff
end_define

begin_comment
comment|/* L2CAP Command Reject reasons */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_REJ_NOT_UNDERSTOOD
value|0x0000
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_REJ_MTU_EXCEEDED
value|0x0001
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_REJ_INVALID_CID
value|0x0002
end_define

begin_comment
comment|/* 0x0003 - 0xffff - reserved for future use */
end_comment

begin_comment
comment|/* Protocol/Service Multioplexor (PSM) values */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_PSM_ANY
value|0x0000
end_define

begin_comment
comment|/* Any/Invalid PSM */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_PSM_SDP
value|0x0001
end_define

begin_comment
comment|/* Service Discovery Protocol */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_PSM_RFCOMM
value|0x0003
end_define

begin_comment
comment|/* RFCOMM protocol */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_PSM_TCP
value|0x0005
end_define

begin_comment
comment|/* Telephony Control Protocol */
end_comment

begin_comment
comment|/* 0x0006 - 0x1000 - reserved for future use */
end_comment

begin_comment
comment|/* L2CAP Connection response command result codes */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_PENDING
value|0x0001
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_PSM_NOT_SUPPORTED
value|0x0002
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_SEQUIRY_BLOCK
value|0x0003
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_NO_RESOURCES
value|0x0004
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_TIMEOUT
value|0xeeee
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_UNKNOWN
value|0xffff
end_define

begin_comment
comment|/* 0x0005 - 0xffff - reserved for future use */
end_comment

begin_comment
comment|/* L2CAP Connection response status codes */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_NO_INFO
value|0x0000
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_AUTH_PENDING
value|0x0001
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_AUTZ_PENDING
value|0x0002
end_define

begin_comment
comment|/* 0x0003 - 0xffff - reserved for future use */
end_comment

begin_comment
comment|/* L2CAP Configuration response result codes */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_UNACCEPTABLE_PARAMS
value|0x0001
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_REJECT
value|0x0002
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_UNKNOWN_OPTION
value|0x0003
end_define

begin_comment
comment|/* 0x0003 - 0xffff - reserved for future use */
end_comment

begin_comment
comment|/* L2CAP Configuration options */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_CFLAG_BIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_CFLAG
parameter_list|(
name|flags
parameter_list|)
value|((flags)& NG_L2CAP_OPT_CFLAG_BIT)
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_HINT_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_HINT
parameter_list|(
name|type
parameter_list|)
value|((type)& NG_L2CAP_OPT_HINT_BIT)
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_HINT_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_MTU
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_MTU_SIZE
value|sizeof(u_int16_t)
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_FLUSH_TIMO
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_FLUSH_TIMO_SIZE
value|sizeof(u_int16_t)
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_QOS
value|0x03
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_OPT_QOS_SIZE
value|sizeof(ng_l2cap_flow_t)
end_define

begin_comment
comment|/* 0x4 - 0xff - reserved for future use */
end_comment

begin_comment
comment|/* L2CAP Information request type codes */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CONNLESS_MTU
value|0x0001
end_define

begin_comment
comment|/* 0x0002 - 0xffff - reserved for future use */
end_comment

begin_comment
comment|/* L2CAP Information response codes */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_NOT_SUPPORTED
value|0x0001
end_define

begin_comment
comment|/* 0x0002 - 0xffff - reserved for future use */
end_comment

begin_comment
comment|/* L2CAP flow control */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|flags
decl_stmt|;
comment|/* reserved for future use */
name|u_int8_t
name|service_type
decl_stmt|;
comment|/* service type */
name|u_int32_t
name|token_rate
decl_stmt|;
comment|/* bytes per second */
name|u_int32_t
name|token_bucket_size
decl_stmt|;
comment|/* bytes */
name|u_int32_t
name|peak_bandwidth
decl_stmt|;
comment|/* bytes per second */
name|u_int32_t
name|latency
decl_stmt|;
comment|/* microseconds */
name|u_int32_t
name|delay_variation
decl_stmt|;
comment|/* microseconds */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_flow_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_flow_t
modifier|*
name|ng_l2cap_flow_p
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **                 Link level defines, headers and types  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* L2CAP header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|length
decl_stmt|;
comment|/* payload size */
name|u_int16_t
name|dcid
decl_stmt|;
comment|/* destination channel ID */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_hdr_t
typedef|;
end_typedef

begin_comment
comment|/* L2CAP ConnectionLess Traffic (CLT) (if destination cid == 0x2) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|psm
decl_stmt|;
comment|/* Protocol/Service Multiplexor */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_clt_hdr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_L2CAP_CLT_MTU_MAXIMUM
define|\
value|(NG_L2CAP_MTU_MAXIMUM - sizeof(ng_l2cap_clt_hdr_t))
end_define

begin_comment
comment|/* L2CAP command header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|code
decl_stmt|;
comment|/* command OpCode */
name|u_int8_t
name|ident
decl_stmt|;
comment|/* identifier to match request and response */
name|u_int16_t
name|length
decl_stmt|;
comment|/* command parameters length */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_cmd_hdr_t
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Command Reject */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CMD_REJ
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|reason
decl_stmt|;
comment|/* reason to reject command */
comment|/*	u_int8_t	data[]; -- optional data (depends on reason) */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_cmd_rej_cp
typedef|;
end_typedef

begin_comment
comment|/* CommandReject data */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
comment|/* NG_L2CAP_REJ_MTU_EXCEEDED */
struct|struct
block|{
name|u_int16_t
name|mtu
decl_stmt|;
comment|/* actual signaling MTU */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|mtu
struct|;
comment|/* NG_L2CAP_REJ_INVALID_CID */
struct|struct
block|{
name|u_int16_t
name|scid
decl_stmt|;
comment|/* local CID */
name|u_int16_t
name|dcid
decl_stmt|;
comment|/* remote CID */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|cid
struct|;
block|}
name|ng_l2cap_cmd_rej_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_cmd_rej_data_t
modifier|*
name|ng_l2cap_cmd_rej_data_p
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Connection Request */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_REQ
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|psm
decl_stmt|;
comment|/* Protocol/Service Multiplexor (PSM) */
name|u_int16_t
name|scid
decl_stmt|;
comment|/* source channel ID */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_con_req_cp
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Connection Response */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_RSP
value|0x03
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|dcid
decl_stmt|;
comment|/* destination channel ID */
name|u_int16_t
name|scid
decl_stmt|;
comment|/* source channel ID */
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|status
decl_stmt|;
comment|/* more info if result != 0x00 */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_con_rsp_cp
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Configuration Request */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CFG_REQ
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|dcid
decl_stmt|;
comment|/* destination channel ID */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* flags */
comment|/*	u_int8_t	options[] --  options */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_cfg_req_cp
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Configuration Response */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CFG_RSP
value|0x05
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|scid
decl_stmt|;
comment|/* source channel ID */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* flags */
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
comment|/*	u_int8_t	options[] -- options */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_cfg_rsp_cp
typedef|;
end_typedef

begin_comment
comment|/* L2CAP configuration option */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|type
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
comment|/*	u_int8_t	value[] -- option value (depends on type) */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_cfg_opt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_cfg_opt_t
modifier|*
name|ng_l2cap_cfg_opt_p
typedef|;
end_typedef

begin_comment
comment|/* L2CAP configuration option value */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|u_int16_t
name|mtu
decl_stmt|;
comment|/* NG_L2CAP_OPT_MTU */
name|u_int16_t
name|flush_timo
decl_stmt|;
comment|/* NG_L2CAP_OPT_FLUSH_TIMO */
name|ng_l2cap_flow_t
name|flow
decl_stmt|;
comment|/* NG_L2CAP_OPT_QOS */
block|}
name|ng_l2cap_cfg_opt_val_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_cfg_opt_val_t
modifier|*
name|ng_l2cap_cfg_opt_val_p
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Disconnect Request */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_DISCON_REQ
value|0x06
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|dcid
decl_stmt|;
comment|/* destination channel ID */
name|u_int16_t
name|scid
decl_stmt|;
comment|/* source channel ID */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_discon_req_cp
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Disconnect Response */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_DISCON_RSP
value|0x07
end_define

begin_typedef
typedef|typedef
name|ng_l2cap_discon_req_cp
name|ng_l2cap_discon_rsp_cp
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Echo Request */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_ECHO_REQ
value|0x08
end_define

begin_comment
comment|/* No command parameters, only optional data */
end_comment

begin_comment
comment|/* L2CAP Echo Response */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_ECHO_RSP
value|0x09
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_MAX_ECHO_SIZE
define|\
value|(NG_L2CAP_MTU_MAXIMUM - sizeof(ng_l2cap_cmd_hdr_t))
end_define

begin_comment
comment|/* No command parameters, only optional data */
end_comment

begin_comment
comment|/* L2CAP Information Request */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_INFO_REQ
value|0x0a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|type
decl_stmt|;
comment|/* requested information type */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_info_req_cp
typedef|;
end_typedef

begin_comment
comment|/* L2CAP Information Response */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_INFO_RSP
value|0x0b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|type
decl_stmt|;
comment|/* requested information type */
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
comment|/*	u_int8_t	info[]  -- info data (depends on type)  *  * NG_L2CAP_CONNLESS_MTU - 2 bytes connectionless MTU  */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_info_rsp_cp
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
comment|/* NG_L2CAP_CONNLESS_MTU */
struct|struct
block|{
name|u_int16_t
name|mtu
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|mtu
struct|;
block|}
name|ng_l2cap_info_rsp_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_info_rsp_data_t
modifier|*
name|ng_l2cap_info_rsp_data_p
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  **************************************************************************  **        Upper layer protocol interface. L2CA_xxx messages   **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/*  * NOTE! NOTE! NOTE!  *  * Bluetooth specification says that L2CA_xxx request must block until  * response is ready. We are not allowed to block in Netgraph, so we   * need to queue request and save some information that can be used   * later and help match request and response.  *  * The idea is to use "token" field from Netgraph message header. The  * upper layer protocol _MUST_ populate "token". L2CAP will queue request  * (using L2CAP command descriptor) and start processing. Later, when  * response is ready or timeout has occur L2CAP layer will create new   * Netgraph message, set "token" and RESP flag and send the message to  * the upper layer protocol.   *  * L2CA_xxx_Ind messages _WILL_NOT_ populate "token" and _WILL_NOT_  * set RESP flag. There is no reason for this, because they are just  * notifications and do not require acknowlegment.  *  * NOTE: This is _NOT_ what NG_MKRESPONSE and NG_RESPOND_MSG do, however  *       it is somewhat similar.  */
end_comment

begin_comment
comment|/* L2CA data packet header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|token
decl_stmt|;
comment|/* token to use in L2CAP_L2CA_WRITE */
name|u_int16_t
name|length
decl_stmt|;
comment|/* length of the data */
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ng_l2cap_l2ca_hdr_t
typedef|;
end_typedef

begin_comment
comment|/* L2CA_Connect */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_CON
value|0x80
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|psm
decl_stmt|;
comment|/* Protocol/Service Multiplexor */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|ng_l2cap_l2ca_con_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|status
decl_stmt|;
comment|/* if result != 0x00 */
block|}
name|ng_l2cap_l2ca_con_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_ConnectInd */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_CON_IND
value|0x81
end_define

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
name|u_int16_t
name|psm
decl_stmt|;
comment|/* Procotol/Service Multiplexor */
name|u_int8_t
name|ident
decl_stmt|;
comment|/* indentifier */
name|u_int8_t
name|unused
decl_stmt|;
comment|/* place holder */
block|}
name|ng_l2cap_l2ca_con_ind_ip
typedef|;
end_typedef

begin_comment
comment|/* No output parameters */
end_comment

begin_comment
comment|/* L2CA_ConnectRsp */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_CON_RSP
value|0x82
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|u_int8_t
name|ident
decl_stmt|;
comment|/* "ident" from L2CAP_ConnectInd event */
name|u_int8_t
name|unused
decl_stmt|;
comment|/* place holder */
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|status
decl_stmt|;
comment|/* if response != 0x00 */
block|}
name|ng_l2cap_l2ca_con_rsp_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
block|}
name|ng_l2cap_l2ca_con_rsp_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_Config */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_CFG
value|0x83
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
name|u_int16_t
name|imtu
decl_stmt|;
comment|/* receiving MTU for the local channel */
name|ng_l2cap_flow_t
name|oflow
decl_stmt|;
comment|/* out flow */
name|u_int16_t
name|flush_timo
decl_stmt|;
comment|/* flush timeout (msec) */
name|u_int16_t
name|link_timo
decl_stmt|;
comment|/* link timeout (msec) */
block|}
name|ng_l2cap_l2ca_cfg_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|imtu
decl_stmt|;
comment|/* sending MTU for the remote channel */
name|ng_l2cap_flow_t
name|oflow
decl_stmt|;
comment|/* out flow */
name|u_int16_t
name|flush_timo
decl_stmt|;
comment|/* flush timeout (msec) */
block|}
name|ng_l2cap_l2ca_cfg_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_ConfigRsp */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_CFG_RSP
value|0x84
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
name|u_int16_t
name|omtu
decl_stmt|;
comment|/* sending MTU for the local channel */
name|ng_l2cap_flow_t
name|iflow
decl_stmt|;
comment|/* in FLOW */
block|}
name|ng_l2cap_l2ca_cfg_rsp_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - sucsess */
block|}
name|ng_l2cap_l2ca_cfg_rsp_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_ConfigInd */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_CFG_IND
value|0x85
end_define

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
name|u_int16_t
name|omtu
decl_stmt|;
comment|/* outgoing MTU for the local channel */
name|ng_l2cap_flow_t
name|iflow
decl_stmt|;
comment|/* in flow */
name|u_int16_t
name|flush_timo
decl_stmt|;
comment|/* flush timeout (msec) */
block|}
name|ng_l2cap_l2ca_cfg_ind_ip
typedef|;
end_typedef

begin_comment
comment|/* No output parameters */
end_comment

begin_comment
comment|/* L2CA_QoSViolationInd */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_QOS_IND
value|0x86
end_define

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|ng_l2cap_l2ca_qos_ind_ip
typedef|;
end_typedef

begin_comment
comment|/* No output parameters */
end_comment

begin_comment
comment|/* L2CA_Disconnect */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_DISCON
value|0x87
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
block|}
name|ng_l2cap_l2ca_discon_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - sucsess */
block|}
name|ng_l2cap_l2ca_discon_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_DisconnectInd */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_DISCON_IND
value|0x88
end_define

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
name|ng_l2cap_l2ca_discon_ip
name|ng_l2cap_l2ca_discon_ind_ip
typedef|;
end_typedef

begin_comment
comment|/* No output parameters */
end_comment

begin_comment
comment|/* L2CA_Write response */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_WRITE
value|0x89
end_define

begin_comment
comment|/* No input parameters */
end_comment

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|result
decl_stmt|;
comment|/* result (0x00 - success) */
name|u_int16_t
name|length
decl_stmt|;
comment|/* amount of data written */
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local channel ID */
block|}
name|ng_l2cap_l2ca_write_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_GroupCreate */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_GRP_CREATE
value|0x8a
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|psm
decl_stmt|;
comment|/* Protocol/Service Multiplexor */
block|}
name|ng_l2cap_l2ca_grp_create_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local group channel ID */
block|}
name|ng_l2cap_l2ca_grp_create_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_GroupClose */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_GRP_CLOSE
value|0x8b
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local group channel ID */
block|}
name|ng_l2cap_l2ca_grp_close_ip
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_comment
unit|* typedef struct {  * 	u_int16_t	result;
comment|/* 0x00 - success */
end_comment

begin_endif
unit|* } ng_l2cap_l2ca_grp_close_op;
endif|#
directive|endif
end_endif

begin_comment
comment|/* L2CA_GroupAddMember */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_GRP_ADD_MEMBER
value|0x8c
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local group channel ID */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
block|}
name|ng_l2cap_l2ca_grp_add_member_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
block|}
name|ng_l2cap_l2ca_grp_add_member_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_GroupRemoveMember */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_GRP_REM_MEMBER
value|0x8d
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
name|ng_l2cap_l2ca_grp_add_member_ip
name|ng_l2cap_l2ca_grp_rem_member_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|* typedef ng_l2cap_l2ca_grp_add_member_op	ng_l2cap_l2ca_grp_rem_member_op;
endif|#
directive|endif
end_endif

begin_comment
comment|/* L2CA_GroupMembeship */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_GRP_MEMBERSHIP
value|0x8e
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|lcid
decl_stmt|;
comment|/* local group channel ID */
block|}
name|ng_l2cap_l2ca_grp_get_members_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|nmembers
decl_stmt|;
comment|/* number of group members */
comment|/*	bdaddr_t	members[] -- group memebers */
block|}
name|ng_l2cap_l2ca_grp_get_members_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_Ping */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_PING
value|0x8f
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|u_int16_t
name|echo_size
decl_stmt|;
comment|/* size of echo data in bytes */
comment|/*	u_int8_t	echo_data[] -- echo data */
block|}
name|ng_l2cap_l2ca_ping_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|u_int16_t
name|echo_size
decl_stmt|;
comment|/* size of echo data in bytes */
comment|/*	u_int8_t	echo_data[] -- echo data */
block|}
name|ng_l2cap_l2ca_ping_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_GetInfo */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_GET_INFO
value|0x90
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote unit address */
name|u_int16_t
name|info_type
decl_stmt|;
comment|/* info type */
block|}
name|ng_l2cap_l2ca_get_info_ip
typedef|;
end_typedef

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|result
decl_stmt|;
comment|/* 0x00 - success */
name|u_int16_t
name|info_size
decl_stmt|;
comment|/* size of info data in bytes */
comment|/*	u_int8_t	info_data[] -- info data */
block|}
name|ng_l2cap_l2ca_get_info_op
typedef|;
end_typedef

begin_comment
comment|/* L2CA_EnableCLT/L2CA_DisableCLT */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_L2CA_ENABLE_CLT
value|0x91
end_define

begin_comment
comment|/* Upper -> L2CAP */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|psm
decl_stmt|;
comment|/* Protocol/Service Multiplexor */
name|u_int16_t
name|enable
decl_stmt|;
comment|/* 0x00 - disable */
block|}
name|ng_l2cap_l2ca_enable_clt_ip
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_comment
unit|* typedef struct {  * 	u_int16_t	result;
comment|/* 0x00 - success */
end_comment

begin_endif
unit|* } ng_l2cap_l2ca_enable_clt_op;
endif|#
directive|endif
end_endif

begin_comment
comment|/**************************************************************************  **************************************************************************  **                          L2CAP node messages  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* L2CAP connection states */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_CLOSED
value|0
end_define

begin_comment
comment|/* connection closed */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_W4_LP_CON_CFM
value|1
end_define

begin_comment
comment|/* waiting... */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_OPEN
value|2
end_define

begin_comment
comment|/* connection open */
end_comment

begin_comment
comment|/* L2CAP channel states */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CLOSED
value|0
end_define

begin_comment
comment|/* channel closed */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_W4_L2CAP_CON_RSP
value|1
end_define

begin_comment
comment|/* wait for L2CAP resp. */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_W4_L2CA_CON_RSP
value|2
end_define

begin_comment
comment|/* wait for upper resp. */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CONFIG
value|3
end_define

begin_comment
comment|/* L2CAP configuration */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_OPEN
value|4
end_define

begin_comment
comment|/* channel open */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_W4_L2CAP_DISCON_RSP
value|5
end_define

begin_comment
comment|/* wait for L2CAP discon. */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_W4_L2CA_DISCON_RSP
value|6
end_define

begin_comment
comment|/* wait for upper discon. */
end_comment

begin_comment
comment|/* Node flags */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CLT_SDP_DISABLED
value|(1<< 0)
end_define

begin_comment
comment|/* disable SDP CLT */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CLT_RFCOMM_DISABLED
value|(1<< 1)
end_define

begin_comment
comment|/* disable RFCOMM CLT */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CLT_TCP_DISABLED
value|(1<< 2)
end_define

begin_comment
comment|/* disable TCP CLT */
end_comment

begin_comment
comment|/* Debug levels */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_ALERT_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_ERR_LEVEL
value|2
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_WARN_LEVEL
value|3
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_INFO_LEVEL
value|4
end_define

begin_comment
comment|/* Get node flags (see flags above) */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_NODE_GET_FLAGS
value|0x400
end_define

begin_comment
comment|/* L2CAP -> User */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_l2cap_node_flags_ep
typedef|;
end_typedef

begin_comment
comment|/* Get/Set debug level (see levels above) */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_NODE_GET_DEBUG
value|0x401
end_define

begin_comment
comment|/* L2CAP -> User */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_NODE_SET_DEBUG
value|0x402
end_define

begin_comment
comment|/* User -> L2CAP */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_l2cap_node_debug_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_L2CAP_NODE_HOOK_INFO
value|0x409
end_define

begin_comment
comment|/* L2CAP -> Upper */
end_comment

begin_comment
comment|/* bdaddr_t bdaddr; -- local (source BDADDR) */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_NODE_GET_CON_LIST
value|0x40a
end_define

begin_comment
comment|/* L2CAP -> User */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|num_connections
decl_stmt|;
comment|/* number of connections */
block|}
name|ng_l2cap_node_con_list_ep
typedef|;
end_typedef

begin_comment
comment|/* Connection flags */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_TX
value|(1<< 0)
end_define

begin_comment
comment|/* sending data */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_RX
value|(1<< 1)
end_define

begin_comment
comment|/* receiving data */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_OUTGOING
value|(1<< 2)
end_define

begin_comment
comment|/* outgoing connection */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_LP_TIMO
value|(1<< 3)
end_define

begin_comment
comment|/* LP timeout */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_AUTO_DISCON_TIMO
value|(1<< 4)
end_define

begin_comment
comment|/* auto discon. timeout */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_CON_DYING
value|(1<< 5)
end_define

begin_comment
comment|/* connection is dying */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|state
decl_stmt|;
comment|/* connection state */
name|u_int8_t
name|flags
decl_stmt|;
comment|/* flags */
name|int16_t
name|pending
decl_stmt|;
comment|/* num. pending packets */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* connection handle */
name|bdaddr_t
name|remote
decl_stmt|;
comment|/* remote bdaddr */
block|}
name|ng_l2cap_node_con_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_L2CAP_MAX_CON_NUM
define|\
value|((0xffff - sizeof(ng_l2cap_node_con_list_ep))/sizeof(ng_l2cap_node_con_ep))
end_define

begin_define
define|#
directive|define
name|NGM_L2CAP_NODE_GET_CHAN_LIST
value|0x40b
end_define

begin_comment
comment|/* L2CAP -> User */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|num_channels
decl_stmt|;
comment|/* number of channels */
block|}
name|ng_l2cap_node_chan_list_ep
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|state
decl_stmt|;
comment|/* channel state */
name|u_int16_t
name|scid
decl_stmt|;
comment|/* source (local) channel ID */
name|u_int16_t
name|dcid
decl_stmt|;
comment|/* destination (remote) channel ID */
name|u_int16_t
name|imtu
decl_stmt|;
comment|/* incomming MTU */
name|u_int16_t
name|omtu
decl_stmt|;
comment|/* outgoing MTU */
name|u_int16_t
name|psm
decl_stmt|;
comment|/* PSM */
name|bdaddr_t
name|remote
decl_stmt|;
comment|/* remote bdaddr */
block|}
name|ng_l2cap_node_chan_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_L2CAP_MAX_CHAN_NUM
define|\
value|((0xffff - sizeof(ng_l2cap_node_chan_list_ep))/sizeof(ng_l2cap_node_chan_ep))
end_define

begin_define
define|#
directive|define
name|NGM_L2CAP_NODE_GET_AUTO_DISCON_TIMO
value|0x40c
end_define

begin_comment
comment|/* L2CAP -> User */
end_comment

begin_define
define|#
directive|define
name|NGM_L2CAP_NODE_SET_AUTO_DISCON_TIMO
value|0x40d
end_define

begin_comment
comment|/* User -> L2CAP */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_l2cap_node_auto_discon_ep
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NETGRAPH_L2CAP_H_ */
end_comment

end_unit

