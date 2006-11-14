begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_h4.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_h4.h,v 1.1 2002/11/24 19:47:05 max Exp $  * $FreeBSD$  *   * Based on:  * ---------  *  * FreeBSD: src/sys/netgraph/ng_tty.h  * Author: Archie Cobbs<archie@freebsd.org>  */
end_comment

begin_comment
comment|/*  * This file contains everything that application needs to know about  * Bluetooth HCI UART transport layer as per chapter H4 of the Bluetooth  * Specification Book v1.1.  *  * This file can be included by both kernel and userland applications.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_H4_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_H4_H_
end_define

begin_comment
comment|/**************************************************************************  **************************************************************************  **     Netgraph node hook name, type name and type cookie and commands  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* Hook name */
end_comment

begin_define
define|#
directive|define
name|NG_H4_HOOK
value|"hook"
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_H4_NODE_TYPE
value|"h4"
end_define

begin_define
define|#
directive|define
name|NGM_H4_COOKIE
value|1013899512
end_define

begin_comment
comment|/* Node states */
end_comment

begin_define
define|#
directive|define
name|NG_H4_W4_PKT_IND
value|1
end_define

begin_comment
comment|/* Waiting for packet indicator */
end_comment

begin_define
define|#
directive|define
name|NG_H4_W4_PKT_HDR
value|2
end_define

begin_comment
comment|/* Waiting for packet header */
end_comment

begin_define
define|#
directive|define
name|NG_H4_W4_PKT_DATA
value|3
end_define

begin_comment
comment|/* Waiting for packet data */
end_comment

begin_comment
comment|/* Debug levels */
end_comment

begin_define
define|#
directive|define
name|NG_H4_ALERT_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|NG_H4_ERR_LEVEL
value|2
end_define

begin_define
define|#
directive|define
name|NG_H4_WARN_LEVEL
value|3
end_define

begin_define
define|#
directive|define
name|NG_H4_INFO_LEVEL
value|4
end_define

begin_comment
comment|/**************************************************************************  **************************************************************************  **                    H4 node command/event parameters  **************************************************************************  **************************************************************************/
end_comment

begin_comment
comment|/* Reset node */
end_comment

begin_define
define|#
directive|define
name|NGM_H4_NODE_RESET
value|1
end_define

begin_comment
comment|/* Get node state (see states above) */
end_comment

begin_define
define|#
directive|define
name|NGM_H4_NODE_GET_STATE
value|2
end_define

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_h4_node_state_ep
typedef|;
end_typedef

begin_comment
comment|/* Get/Set node debug level (see levels above) */
end_comment

begin_define
define|#
directive|define
name|NGM_H4_NODE_GET_DEBUG
value|3
end_define

begin_define
define|#
directive|define
name|NGM_H4_NODE_SET_DEBUG
value|4
end_define

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_h4_node_debug_ep
typedef|;
end_typedef

begin_comment
comment|/* Get/Set max queue length for the node */
end_comment

begin_define
define|#
directive|define
name|NGM_H4_NODE_GET_QLEN
value|5
end_define

begin_define
define|#
directive|define
name|NGM_H4_NODE_SET_QLEN
value|6
end_define

begin_typedef
typedef|typedef
name|int32_t
name|ng_h4_node_qlen_ep
typedef|;
end_typedef

begin_comment
comment|/* Get node statistic */
end_comment

begin_define
define|#
directive|define
name|NGM_H4_NODE_GET_STAT
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|pckts_recv
decl_stmt|;
comment|/* # of packets received */
name|u_int32_t
name|bytes_recv
decl_stmt|;
comment|/* # of bytes received */
name|u_int32_t
name|pckts_sent
decl_stmt|;
comment|/* # of packets sent */
name|u_int32_t
name|bytes_sent
decl_stmt|;
comment|/* # of bytes sent */
name|u_int32_t
name|oerrors
decl_stmt|;
comment|/* # of output errors */
name|u_int32_t
name|ierrors
decl_stmt|;
comment|/* # of input errors */
block|}
name|ng_h4_node_stat_ep
typedef|;
end_typedef

begin_comment
comment|/* Reset node statistic */
end_comment

begin_define
define|#
directive|define
name|NGM_H4_NODE_RESET_STAT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_H4_H_ */
end_comment

end_unit

