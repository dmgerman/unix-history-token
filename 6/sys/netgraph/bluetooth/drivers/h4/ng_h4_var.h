begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_h4_var.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_h4_var.h,v 1.1 2002/11/24 19:46:55 max Exp $  * $FreeBSD$  *   * Based on:  * ---------  *  * FreeBSD: src/sys/netgraph/ng_tty.h  * Author: Archie Cobbs<archie@freebsd.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_H4_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_H4_VAR_H_
end_define

begin_comment
comment|/*  * Malloc declaration  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NG_SEPARATE_MALLOC
end_ifndef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NETGRAPH_H4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_NETGRAPH_H4
value|M_NETGRAPH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NG_SEPARATE_MALLOC */
end_comment

begin_comment
comment|/*   * Debug  */
end_comment

begin_define
define|#
directive|define
name|NG_H4_ALERT
value|if (sc->debug>= NG_H4_ALERT_LEVEL) printf
end_define

begin_define
define|#
directive|define
name|NG_H4_ERR
value|if (sc->debug>= NG_H4_ERR_LEVEL)   printf
end_define

begin_define
define|#
directive|define
name|NG_H4_WARN
value|if (sc->debug>= NG_H4_WARN_LEVEL)  printf
end_define

begin_define
define|#
directive|define
name|NG_H4_INFO
value|if (sc->debug>= NG_H4_INFO_LEVEL)  printf
end_define

begin_define
define|#
directive|define
name|NG_H4_HIWATER
value|256
end_define

begin_comment
comment|/* High water mark on output */
end_comment

begin_comment
comment|/*   * Per-node private info   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ng_h4_info
block|{
name|struct
name|tty
modifier|*
name|tp
decl_stmt|;
comment|/* Terminal device */
name|node_p
name|node
decl_stmt|;
comment|/* Netgraph node */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* Flags */
define|#
directive|define
name|NG_H4_TIMEOUT
value|(1<< 0)
comment|/* A timeout is pending */
name|ng_h4_node_debug_ep
name|debug
decl_stmt|;
comment|/* Debug level */
name|ng_h4_node_state_ep
name|state
decl_stmt|;
comment|/* State */
name|ng_h4_node_stat_ep
name|stat
decl_stmt|;
define|#
directive|define
name|NG_H4_STAT_PCKTS_SENT
parameter_list|(
name|s
parameter_list|)
value|(s).pckts_sent ++
define|#
directive|define
name|NG_H4_STAT_BYTES_SENT
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s).bytes_sent += (n)
define|#
directive|define
name|NG_H4_STAT_PCKTS_RECV
parameter_list|(
name|s
parameter_list|)
value|(s).pckts_recv ++
define|#
directive|define
name|NG_H4_STAT_BYTES_RECV
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s).bytes_recv += (n)
define|#
directive|define
name|NG_H4_STAT_OERROR
parameter_list|(
name|s
parameter_list|)
value|(s).oerrors ++
define|#
directive|define
name|NG_H4_STAT_IERROR
parameter_list|(
name|s
parameter_list|)
value|(s).ierrors ++
define|#
directive|define
name|NG_H4_STAT_RESET
parameter_list|(
name|s
parameter_list|)
value|bzero(&(s), sizeof((s)))
name|ng_bt_mbufq_t
name|outq
decl_stmt|;
comment|/* Queue of outgoing mbuf's */
define|#
directive|define
name|NG_H4_DEFAULTQLEN
value|12
comment|/* XXX max number of mbuf's in outq */
define|#
directive|define
name|NG_H4_IBUF_SIZE
value|1024
comment|/* XXX must be big enough to hold full  					   frame */
name|u_int8_t
name|ibuf
index|[
name|NG_H4_IBUF_SIZE
index|]
decl_stmt|;
comment|/* Incoming data */
name|u_int32_t
name|got
decl_stmt|;
comment|/* Number of bytes we have received */
name|u_int32_t
name|want
decl_stmt|;
comment|/* Number of bytes we want to receive */
name|hook_p
name|hook
decl_stmt|;
comment|/* Upstream hook */
name|struct
name|callout
name|timo
decl_stmt|;
comment|/* See man timeout(9) */
block|}
name|ng_h4_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_h4_info_t
modifier|*
name|ng_h4_info_p
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_H4_VAR_H_ */
end_comment

end_unit

