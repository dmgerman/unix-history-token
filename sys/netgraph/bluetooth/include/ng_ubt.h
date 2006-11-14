begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_ubt.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_ubt.h,v 1.6 2003/04/13 21:34:42 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NG_UBT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NG_UBT_H_
end_define

begin_comment
comment|/**************************************************************************  **************************************************************************  **     Netgraph node hook name, type name and type cookie and commands   **************************************************************************    **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NG_UBT_NODE_TYPE
value|"ubt"
end_define

begin_define
define|#
directive|define
name|NG_UBT_HOOK
value|"hook"
end_define

begin_define
define|#
directive|define
name|NGM_UBT_COOKIE
value|1021837971
end_define

begin_comment
comment|/* Debug levels */
end_comment

begin_define
define|#
directive|define
name|NG_UBT_ALERT_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|NG_UBT_ERR_LEVEL
value|2
end_define

begin_define
define|#
directive|define
name|NG_UBT_WARN_LEVEL
value|3
end_define

begin_define
define|#
directive|define
name|NG_UBT_INFO_LEVEL
value|4
end_define

begin_comment
comment|/**************************************************************************  **************************************************************************  **                    UBT node command/event parameters  **************************************************************************  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NGM_UBT_NODE_SET_DEBUG
value|1
end_define

begin_comment
comment|/* set debug level */
end_comment

begin_define
define|#
directive|define
name|NGM_UBT_NODE_GET_DEBUG
value|2
end_define

begin_comment
comment|/* get debug level */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_ubt_node_debug_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_UBT_NODE_SET_QLEN
value|3
end_define

begin_comment
comment|/* set queue length */
end_comment

begin_define
define|#
directive|define
name|NGM_UBT_NODE_GET_QLEN
value|4
end_define

begin_comment
comment|/* get queue length */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|queue
decl_stmt|;
comment|/* queue index */
define|#
directive|define
name|NGM_UBT_NODE_QUEUE_CMD
value|1
comment|/* commands */
define|#
directive|define
name|NGM_UBT_NODE_QUEUE_ACL
value|2
comment|/* ACL data */
define|#
directive|define
name|NGM_UBT_NODE_QUEUE_SCO
value|3
comment|/* SCO data */
name|int32_t
name|qlen
decl_stmt|;
comment|/* queue length */
block|}
name|ng_ubt_node_qlen_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_UBT_NODE_GET_STAT
value|5
end_define

begin_comment
comment|/* get statistic */
end_comment

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
name|ng_ubt_node_stat_ep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NGM_UBT_NODE_RESET_STAT
value|6
end_define

begin_comment
comment|/* reset statistic */
end_comment

begin_define
define|#
directive|define
name|NGM_UBT_NODE_DEV_NODES
value|7
end_define

begin_comment
comment|/* on/off device interface */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|ng_ubt_node_dev_nodes_ep
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NG_UBT_H_ */
end_comment

end_unit

