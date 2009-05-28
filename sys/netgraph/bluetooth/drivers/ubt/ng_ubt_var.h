begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_ubt_var.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2009 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_ubt_var.h,v 1.2 2003/03/22 23:44:36 max Exp $  * $FreeBSD$  */
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
value|1
end_define

begin_comment
comment|/* Debug printf's */
end_comment

begin_define
define|#
directive|define
name|UBT_DEBUG
parameter_list|(
name|level
parameter_list|,
name|sc
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {								\ 	if ((sc)->sc_debug>= (level))				\ 		device_printf((sc)->sc_dev, "%s:%d: " fmt, 	\ 			__FUNCTION__, __LINE__,## __VA_ARGS__);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|UBT_ALERT
parameter_list|(
modifier|...
parameter_list|)
value|UBT_DEBUG(NG_UBT_ALERT_LEVEL, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|UBT_ERR
parameter_list|(
modifier|...
parameter_list|)
value|UBT_DEBUG(NG_UBT_ERR_LEVEL, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|UBT_WARN
parameter_list|(
modifier|...
parameter_list|)
value|UBT_DEBUG(NG_UBT_WARN_LEVEL, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|UBT_INFO
parameter_list|(
modifier|...
parameter_list|)
value|UBT_DEBUG(NG_UBT_INFO_LEVEL, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|UBT_NG_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_ng_mtx)
end_define

begin_define
define|#
directive|define
name|UBT_NG_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_ng_mtx)
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
value|64
end_define

begin_define
define|#
directive|define
name|UBT_ISOC_NFRAMES
value|32
end_define

begin_comment
comment|/* should be factor of 8 */
end_comment

begin_comment
comment|/* Bluetooth USB defines */
end_comment

begin_enum
enum|enum
block|{
comment|/* Interface #0 transfers */
name|UBT_IF_0_BULK_DT_WR
init|=
literal|0
block|,
name|UBT_IF_0_BULK_DT_RD
block|,
name|UBT_IF_0_INTR_DT_RD
block|,
name|UBT_IF_0_CTRL_DT_WR
block|,
comment|/* Interface #1 transfers */
name|UBT_IF_1_ISOC_DT_RD1
block|,
name|UBT_IF_1_ISOC_DT_RD2
block|,
name|UBT_IF_1_ISOC_DT_WR1
block|,
name|UBT_IF_1_ISOC_DT_WR2
block|,
name|UBT_N_TRANSFER
block|,
comment|/* total number of transfers */
block|}
enum|;
end_enum

begin_comment
comment|/* USB device softc structure */
end_comment

begin_struct
struct|struct
name|ubt_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* for debug printf */
comment|/* State */
name|ng_ubt_node_debug_ep
name|sc_debug
decl_stmt|;
comment|/* debug level */
name|ng_ubt_node_stat_ep
name|sc_stat
decl_stmt|;
comment|/* statistic */
define|#
directive|define
name|UBT_STAT_PCKTS_SENT
parameter_list|(
name|sc
parameter_list|)
value|(sc)->sc_stat.pckts_sent ++
define|#
directive|define
name|UBT_STAT_BYTES_SENT
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(sc)->sc_stat.bytes_sent += (n)
define|#
directive|define
name|UBT_STAT_PCKTS_RECV
parameter_list|(
name|sc
parameter_list|)
value|(sc)->sc_stat.pckts_recv ++
define|#
directive|define
name|UBT_STAT_BYTES_RECV
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(sc)->sc_stat.bytes_recv += (n)
define|#
directive|define
name|UBT_STAT_OERROR
parameter_list|(
name|sc
parameter_list|)
value|(sc)->sc_stat.oerrors ++
define|#
directive|define
name|UBT_STAT_IERROR
parameter_list|(
name|sc
parameter_list|)
value|(sc)->sc_stat.ierrors ++
define|#
directive|define
name|UBT_STAT_RESET
parameter_list|(
name|sc
parameter_list|)
value|bzero(&(sc)->sc_stat, sizeof((sc)->sc_stat))
comment|/* USB device specific */
name|struct
name|mtx
name|sc_if_mtx
decl_stmt|;
comment|/* interfaces lock */
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|UBT_N_TRANSFER
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_ng_mtx
decl_stmt|;
comment|/* lock for shared NG data */
comment|/* HCI commands */
name|struct
name|ng_bt_mbufq
name|sc_cmdq
decl_stmt|;
comment|/* HCI command queue */
define|#
directive|define
name|UBT_CTRL_BUFFER_SIZE
value|(sizeof(struct usb_device_request) +	\ 				 sizeof(ng_hci_cmd_pkt_t) + NG_HCI_CMD_PKT_SIZE)
define|#
directive|define
name|UBT_INTR_BUFFER_SIZE
value|(MCLBYTES-1)
comment|/* reserve 1 byte for ID-tag */
comment|/* ACL data */
name|struct
name|ng_bt_mbufq
name|sc_aclq
decl_stmt|;
comment|/* ACL data queue */
define|#
directive|define
name|UBT_BULK_READ_BUFFER_SIZE
value|(MCLBYTES-1)
comment|/* reserve 1 byte for ID-tag */
define|#
directive|define
name|UBT_BULK_WRITE_BUFFER_SIZE
value|(MCLBYTES)
comment|/* SCO data */
name|struct
name|ng_bt_mbufq
name|sc_scoq
decl_stmt|;
comment|/* SCO data queue */
name|struct
name|mbuf
modifier|*
name|sc_isoc_in_buffer
decl_stmt|;
comment|/* SCO reassembly buffer */
comment|/* Netgraph specific */
name|node_p
name|sc_node
decl_stmt|;
comment|/* pointer back to node */
name|hook_p
name|sc_hook
decl_stmt|;
comment|/* upstream hook */
comment|/* Glue */
name|int
name|sc_task_flags
decl_stmt|;
comment|/* task flags */
define|#
directive|define
name|UBT_FLAG_T_PENDING
value|(1<< 0)
comment|/* task pending */
define|#
directive|define
name|UBT_FLAG_T_STOP_ALL
value|(1<< 1)
comment|/* stop all xfers */
define|#
directive|define
name|UBT_FLAG_T_START_ALL
value|(1<< 2)
comment|/* start all read and isoc 						   write xfers */
define|#
directive|define
name|UBT_FLAG_T_START_CTRL
value|(1<< 3)
comment|/* start control xfer (write) */
define|#
directive|define
name|UBT_FLAG_T_START_BULK
value|(1<< 4)
comment|/* start bulk xfer (write) */
name|struct
name|task
name|sc_task
decl_stmt|;
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

