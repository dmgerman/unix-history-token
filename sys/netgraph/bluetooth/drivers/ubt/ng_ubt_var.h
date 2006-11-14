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
value|do { \ 		if ((m)->m_len< (s)) \ 			(m) = m_pullup((m), (s)); \ 		if ((m) == NULL) \ 			NG_UBT_ALERT("%s: %s - m_pullup(%d) failed\n", \ 				__func__, USBDEVNAME(sc->sc_dev), (s)); \ 	} while (0)
end_define

begin_comment
comment|/* Debug printf's */
end_comment

begin_define
define|#
directive|define
name|NG_UBT_ALERT
value|if (sc->sc_debug>= NG_UBT_ALERT_LEVEL) printf
end_define

begin_define
define|#
directive|define
name|NG_UBT_ERR
value|if (sc->sc_debug>= NG_UBT_ERR_LEVEL)   printf
end_define

begin_define
define|#
directive|define
name|NG_UBT_WARN
value|if (sc->sc_debug>= NG_UBT_WARN_LEVEL)  printf
end_define

begin_define
define|#
directive|define
name|NG_UBT_INFO
value|if (sc->sc_debug>= NG_UBT_INFO_LEVEL)  printf
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
name|u_int32_t
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
name|UBT_CMD_XMIT
value|(1<< 1)
comment|/* CMD xmit in progress */
define|#
directive|define
name|UBT_ACL_XMIT
value|(1<< 2)
comment|/* ACL xmit in progress */
define|#
directive|define
name|UBT_SCO_XMIT
value|(1<< 3)
comment|/* SCO xmit in progress */
define|#
directive|define
name|UBT_EVT_RECV
value|(1<< 4)
comment|/* EVN recv in progress */
define|#
directive|define
name|UBT_ACL_RECV
value|(1<< 5)
comment|/* ACL recv in progress */
define|#
directive|define
name|UBT_SCO_RECV
value|(1<< 6)
comment|/* SCO recv in progress */
define|#
directive|define
name|UBT_CTRL_DEV
value|(1<< 7)
comment|/* ctrl device is open */
define|#
directive|define
name|UBT_INTR_DEV
value|(1<< 8)
comment|/* intr device is open */
define|#
directive|define
name|UBT_BULK_DEV
value|(1<< 9)
comment|/* bulk device is open */
define|#
directive|define
name|UBT_ANY_DEV
value|(UBT_CTRL_DEV|UBT_INTR_DEV|UBT_BULK_DEV)
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
comment|/* USB device specific */
name|USBBASEDEVICE
name|sc_dev
decl_stmt|;
comment|/* pointer back to USB device */
name|usbd_device_handle
name|sc_udev
decl_stmt|;
comment|/* USB device handle */
name|usbd_interface_handle
name|sc_iface0
decl_stmt|;
comment|/* USB interface 0 */
name|usbd_interface_handle
name|sc_iface1
decl_stmt|;
comment|/* USB interface 1 */
comment|/* Interrupt pipe (HCI events) */
name|int
name|sc_intr_ep
decl_stmt|;
comment|/* interrupt endpoint */
name|usbd_pipe_handle
name|sc_intr_pipe
decl_stmt|;
comment|/* interrupt pipe handle */
name|usbd_xfer_handle
name|sc_intr_xfer
decl_stmt|;
comment|/* intr xfer */
name|struct
name|mbuf
modifier|*
name|sc_intr_buffer
decl_stmt|;
comment|/* interrupt buffer */
comment|/* Control pipe (HCI commands) */
name|usbd_xfer_handle
name|sc_ctrl_xfer
decl_stmt|;
comment|/* control xfer handle */
name|void
modifier|*
name|sc_ctrl_buffer
decl_stmt|;
comment|/* control buffer */
name|struct
name|ng_bt_mbufq
name|sc_cmdq
decl_stmt|;
comment|/* HCI command queue */
define|#
directive|define
name|UBT_CTRL_BUFFER_SIZE
define|\
value|(sizeof(ng_hci_cmd_pkt_t) + NG_HCI_CMD_PKT_SIZE)
comment|/* Bulk in pipe (ACL data) */
name|int
name|sc_bulk_in_ep
decl_stmt|;
comment|/* bulk-in enpoint */
name|usbd_pipe_handle
name|sc_bulk_in_pipe
decl_stmt|;
comment|/* bulk-in pipe */
name|usbd_xfer_handle
name|sc_bulk_in_xfer
decl_stmt|;
comment|/* bulk-in xfer */
name|struct
name|mbuf
modifier|*
name|sc_bulk_in_buffer
decl_stmt|;
comment|/* bulk-in buffer */
comment|/* Bulk out pipe (ACL data) */
name|int
name|sc_bulk_out_ep
decl_stmt|;
comment|/* bulk-out endpoint */
name|usbd_pipe_handle
name|sc_bulk_out_pipe
decl_stmt|;
comment|/* bulk-out pipe */
name|usbd_xfer_handle
name|sc_bulk_out_xfer
decl_stmt|;
comment|/* bulk-out xfer */
name|void
modifier|*
name|sc_bulk_out_buffer
decl_stmt|;
comment|/* bulk-out buffer */
name|struct
name|ng_bt_mbufq
name|sc_aclq
decl_stmt|;
comment|/* ACL data queue */
define|#
directive|define
name|UBT_BULK_BUFFER_SIZE
define|\
value|MCLBYTES
comment|/* XXX should be big enough to hold one frame */
comment|/* Isoc. in pipe (SCO data) */
name|int
name|sc_isoc_in_ep
decl_stmt|;
comment|/* isoc-in endpoint */
name|usbd_pipe_handle
name|sc_isoc_in_pipe
decl_stmt|;
comment|/* isoc-in pipe */
name|usbd_xfer_handle
name|sc_isoc_in_xfer
decl_stmt|;
comment|/* isoc-in xfer */
name|void
modifier|*
name|sc_isoc_in_buffer
decl_stmt|;
comment|/* isoc-in buffer */
name|u_int16_t
modifier|*
name|sc_isoc_in_frlen
decl_stmt|;
comment|/* isoc-in. frame length */
comment|/* Isoc. out pipe (ACL data) */
name|int
name|sc_isoc_out_ep
decl_stmt|;
comment|/* isoc-out endpoint */
name|usbd_pipe_handle
name|sc_isoc_out_pipe
decl_stmt|;
comment|/* isoc-out pipe */
name|usbd_xfer_handle
name|sc_isoc_out_xfer
decl_stmt|;
comment|/* isoc-out xfer */
name|void
modifier|*
name|sc_isoc_out_buffer
decl_stmt|;
comment|/* isoc-in buffer */
name|u_int16_t
modifier|*
name|sc_isoc_out_frlen
decl_stmt|;
comment|/* isoc-out. frame length */
name|struct
name|ng_bt_mbufq
name|sc_scoq
decl_stmt|;
comment|/* SCO data queue */
name|int
name|sc_isoc_size
decl_stmt|;
comment|/* max. size of isoc. packet */
name|u_int32_t
name|sc_isoc_nframes
decl_stmt|;
comment|/* num. isoc. frames */
define|#
directive|define
name|UBT_ISOC_BUFFER_SIZE
define|\
value|(sizeof(ng_hci_scodata_pkt_t) + NG_HCI_SCO_PKT_SIZE)
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

