begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_ubt_var.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_ubt_var.h,v 1.2 2003/03/22 23:44:36 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NG_UBT_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NG_UBT_VAR_H_
end_define

begin_comment
comment|/* pullup wrapper */
end_comment

begin_define
define|#
directive|define
name|NG_UBT_M_PULLUP
parameter_list|(
name|m
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		if ((m)->m_len< (s)) \ 			(m) = m_pullup((m), (s)); \ 		if ((m) == NULL) { \ 			NG_UBT_ALERT("%s: %s - m_pullup(%d) failed\n", \ 				__func__, sc->sc_name, (s)); \ 		} \ 	} while (0)
end_define

begin_comment
comment|/* Debug printf's */
end_comment

begin_define
define|#
directive|define
name|NG_UBT_DEBUG
parameter_list|(
name|level
parameter_list|,
name|sc
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do { \     if ((sc)->sc_debug>= (level)) { \         printf("%s:%s:%d: " fmt, (sc)->sc_name, \ 	       __FUNCTION__, __LINE__,## __VA_ARGS__); \     } \ } while (0)
end_define

begin_define
define|#
directive|define
name|NG_UBT_ALERT
parameter_list|(
modifier|...
parameter_list|)
value|NG_UBT_DEBUG(NG_UBT_ALERT_LEVEL, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|NG_UBT_ERR
parameter_list|(
modifier|...
parameter_list|)
value|NG_UBT_DEBUG(NG_UBT_ERR_LEVEL, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|NG_UBT_WARN
parameter_list|(
modifier|...
parameter_list|)
value|NG_UBT_DEBUG(NG_UBT_WARN_LEVEL, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|NG_UBT_INFO
parameter_list|(
modifier|...
parameter_list|)
value|NG_UBT_DEBUG(NG_UBT_INFO_LEVEL, __VA_ARGS__)
end_define

begin_comment
comment|/* Bluetooth USB control request type */
end_comment

begin_define
define|#
directive|define
name|UBT_HCI_REQUEST
value|0x20
end_define

begin_define
define|#
directive|define
name|UBT_DEFAULT_QLEN
value|12
end_define

begin_comment
comment|/* Bluetooth USB defines */
end_comment

begin_define
define|#
directive|define
name|UBT_IF_0_N_TRANSFER
value|7
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|UBT_IF_1_N_TRANSFER
value|4
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|UBT_ISOC_NFRAMES
value|25
end_define

begin_comment
comment|/* units */
end_comment

begin_comment
comment|/* USB device softc structure */
end_comment

begin_struct
struct|struct
name|ubt_softc
block|{
comment|/* State */
name|ng_ubt_node_debug_ep
name|sc_debug
decl_stmt|;
comment|/* debug level */
name|uint32_t
name|sc_flags
decl_stmt|;
comment|/* device flags */
define|#
directive|define
name|UBT_NEED_FRAME_TYPE
value|(1<< 0)
comment|/* device required frame type */
define|#
directive|define
name|UBT_HAVE_FRAME_TYPE
value|UBT_NEED_FRAME_TYPE
define|#
directive|define
name|UBT_FLAG_READ_STALL
value|(1<< 1)
comment|/* read transfer has stalled */
define|#
directive|define
name|UBT_FLAG_WRITE_STALL
value|(1<< 2)
comment|/* write transfer has stalled */
define|#
directive|define
name|UBT_FLAG_INTR_STALL
value|(1<< 3)
comment|/* interrupt transfer has stalled */
name|ng_ubt_node_stat_ep
name|sc_stat
decl_stmt|;
comment|/* statistic */
define|#
directive|define
name|NG_UBT_STAT_PCKTS_SENT
parameter_list|(
name|s
parameter_list|)
value|(s).pckts_sent ++
define|#
directive|define
name|NG_UBT_STAT_BYTES_SENT
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s).bytes_sent += (n)
define|#
directive|define
name|NG_UBT_STAT_PCKTS_RECV
parameter_list|(
name|s
parameter_list|)
value|(s).pckts_recv ++
define|#
directive|define
name|NG_UBT_STAT_BYTES_RECV
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s).bytes_recv += (n)
define|#
directive|define
name|NG_UBT_STAT_OERROR
parameter_list|(
name|s
parameter_list|)
value|(s).oerrors ++
define|#
directive|define
name|NG_UBT_STAT_IERROR
parameter_list|(
name|s
parameter_list|)
value|(s).ierrors ++
define|#
directive|define
name|NG_UBT_STAT_RESET
parameter_list|(
name|s
parameter_list|)
value|bzero(&(s), sizeof((s)))
name|uint8_t
name|sc_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* USB device specific */
name|struct
name|usb2_xfer
modifier|*
name|sc_xfer_if_0
index|[
name|UBT_IF_0_N_TRANSFER
index|]
decl_stmt|;
name|struct
name|usb2_xfer
modifier|*
name|sc_xfer_if_1
index|[
name|UBT_IF_1_N_TRANSFER
index|]
decl_stmt|;
comment|/* Interrupt pipe (HCI events) */
name|struct
name|mbuf
modifier|*
name|sc_intr_buffer
decl_stmt|;
comment|/* interrupt buffer */
comment|/* Control pipe (HCI commands) */
name|struct
name|ng_bt_mbufq
name|sc_cmdq
decl_stmt|;
comment|/* HCI command queue */
define|#
directive|define
name|UBT_CTRL_BUFFER_SIZE
value|(sizeof(ng_hci_cmd_pkt_t) + NG_HCI_CMD_PKT_SIZE)
comment|/* Bulk in pipe (ACL data) */
name|struct
name|mbuf
modifier|*
name|sc_bulk_in_buffer
decl_stmt|;
comment|/* bulk-in buffer */
comment|/* Bulk out pipe (ACL data) */
name|struct
name|ng_bt_mbufq
name|sc_aclq
decl_stmt|;
comment|/* ACL data queue */
define|#
directive|define
name|UBT_BULK_READ_BUFFER_SIZE
value|(MCLBYTES-1)
comment|/* reserve one byte for ID-tag */
define|#
directive|define
name|UBT_BULK_WRITE_BUFFER_SIZE
value|(MCLBYTES)
comment|/* Isoc. out pipe (ACL data) */
name|struct
name|ng_bt_mbufq
name|sc_scoq
decl_stmt|;
comment|/* SCO data queue */
comment|/* Isoc. in pipe (ACL data) */
name|struct
name|ng_bt_mbufq
name|sc_sciq
decl_stmt|;
comment|/* SCO data queue */
comment|/* Netgraph specific */
name|node_p
name|sc_node
decl_stmt|;
comment|/* pointer back to node */
name|hook_p
name|sc_hook
decl_stmt|;
comment|/* upstream hook */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ubt_softc
name|ubt_softc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ubt_softc
modifier|*
name|ubt_softc_p
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NG_UBT_VAR_H_ */
end_comment

end_unit

