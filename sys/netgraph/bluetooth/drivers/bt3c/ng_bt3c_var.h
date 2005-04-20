begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_bt3c_var.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_bt3c_var.h,v 1.1 2002/11/24 19:46:54 max Exp $  * $FreeBSD$  *  * XXX XXX XX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX   *  * Based on information obrained from: Jose Orlando Pereira<jop@di.uminho.pt>  * and disassembled w2k driver.  *  * XXX XXX XX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX   *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NG_BT3C_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NG_BT3C_VAR_H_
end_define

begin_comment
comment|/* Debug printf's */
end_comment

begin_define
define|#
directive|define
name|NG_BT3C_ALERT
value|if (sc->debug>= NG_BT3C_ALERT_LEVEL) device_printf
end_define

begin_define
define|#
directive|define
name|NG_BT3C_ERR
value|if (sc->debug>= NG_BT3C_ERR_LEVEL)   device_printf
end_define

begin_define
define|#
directive|define
name|NG_BT3C_WARN
value|if (sc->debug>= NG_BT3C_WARN_LEVEL)  device_printf
end_define

begin_define
define|#
directive|define
name|NG_BT3C_INFO
value|if (sc->debug>= NG_BT3C_INFO_LEVEL)  device_printf
end_define

begin_comment
comment|/* Device registers */
end_comment

begin_define
define|#
directive|define
name|BT3C_DATA_L
value|0x00
end_define

begin_comment
comment|/* data low byte */
end_comment

begin_define
define|#
directive|define
name|BT3C_DATA_H
value|0x01
end_define

begin_comment
comment|/* high byte */
end_comment

begin_define
define|#
directive|define
name|BT3C_ADDR_L
value|0x02
end_define

begin_comment
comment|/* address low byte */
end_comment

begin_define
define|#
directive|define
name|BT3C_ADDR_H
value|0x03
end_define

begin_comment
comment|/* high byte */
end_comment

begin_define
define|#
directive|define
name|BT3C_CONTROL
value|0x04
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|BT3C_FIFO_SIZE
value|256
end_define

begin_comment
comment|/* Device softc structure */
end_comment

begin_struct
struct|struct
name|bt3c_softc
block|{
comment|/* Device specific */
name|device_t
name|dev
decl_stmt|;
comment|/* pointer back to device */
name|int
name|iobase_rid
decl_stmt|;
comment|/* iobase RID */
name|struct
name|resource
modifier|*
name|iobase
decl_stmt|;
comment|/* iobase */
name|int
name|irq_rid
decl_stmt|;
comment|/* irq RID */
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
comment|/* irq */
name|void
modifier|*
name|irq_cookie
decl_stmt|;
comment|/* irq cookie */
comment|/* Netgraph specific */
name|node_p
name|node
decl_stmt|;
comment|/* pointer back to node */
name|hook_p
name|hook
decl_stmt|;
comment|/* hook */
name|ng_bt3c_node_debug_ep
name|debug
decl_stmt|;
comment|/* debug level */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* device flags */
define|#
directive|define
name|BT3C_ANTENNA_OUT
value|(1<< 0)
comment|/* antena is out */
define|#
directive|define
name|BT3C_XMIT
value|(1<< 1)
comment|/* xmit in progress */
name|ng_bt3c_node_state_ep
name|state
decl_stmt|;
comment|/* receiving state */
name|ng_bt3c_node_stat_ep
name|stat
decl_stmt|;
comment|/* statistic */
define|#
directive|define
name|NG_BT3C_STAT_PCKTS_SENT
parameter_list|(
name|s
parameter_list|)
value|(s).pckts_sent ++
define|#
directive|define
name|NG_BT3C_STAT_BYTES_SENT
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s).bytes_sent += (n)
define|#
directive|define
name|NG_BT3C_STAT_PCKTS_RECV
parameter_list|(
name|s
parameter_list|)
value|(s).pckts_recv ++
define|#
directive|define
name|NG_BT3C_STAT_BYTES_RECV
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s).bytes_recv += (n)
define|#
directive|define
name|NG_BT3C_STAT_OERROR
parameter_list|(
name|s
parameter_list|)
value|(s).oerrors ++
define|#
directive|define
name|NG_BT3C_STAT_IERROR
parameter_list|(
name|s
parameter_list|)
value|(s).ierrors ++
define|#
directive|define
name|NG_BT3C_STAT_RESET
parameter_list|(
name|s
parameter_list|)
value|bzero(&(s), sizeof((s)))
name|u_int32_t
name|status
decl_stmt|;
comment|/* from ISR */
name|void
modifier|*
name|ith
decl_stmt|;
comment|/* ithread handler */
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* current frame */
name|u_int32_t
name|want
decl_stmt|;
comment|/* # of chars we want */
name|struct
name|ifqueue
name|inq
decl_stmt|;
comment|/* queue of incoming mbuf's */
name|struct
name|ifqueue
name|outq
decl_stmt|;
comment|/* queue of outgoing mbuf's */
define|#
directive|define
name|BT3C_DEFAULTQLEN
value|12
comment|/* XXX max. size of out queue */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bt3c_softc
name|bt3c_softc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bt3c_softc
modifier|*
name|bt3c_softc_p
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NG_BT3C_VAR_H_ */
end_comment

end_unit

