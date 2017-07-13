begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_USBVAR_H
end_ifndef

begin_define
define|#
directive|define
name|RTWN_USBVAR_H
end_define

begin_define
define|#
directive|define
name|RTWN_USB_TXBUFSZ
value|(16 * 1024)
end_define

begin_define
define|#
directive|define
name|RTWN_IFACE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RTWN_USB_RX_LIST_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|RTWN_USB_TX_LIST_COUNT
value|16
end_define

begin_struct
struct|struct
name|rtwn_data
block|{
name|uint8_t
modifier|*
name|buf
decl_stmt|;
comment|/* 'id' is meaningful for beacons only */
name|int
name|id
decl_stmt|;
name|uint16_t
name|buflen
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|ieee80211_node
modifier|*
name|ni
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|rtwn_data
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|rtwn_data
argument_list|)
name|rtwn_datahead
expr_stmt|;
end_typedef

begin_enum
enum|enum
block|{
name|RTWN_BULK_RX
block|,
name|RTWN_BULK_TX_BE
block|,
comment|/* = WME_AC_BE */
name|RTWN_BULK_TX_BK
block|,
comment|/* = WME_AC_BK */
name|RTWN_BULK_TX_VI
block|,
comment|/* = WME_AC_VI */
name|RTWN_BULK_TX_VO
block|,
comment|/* = WME_AC_VO */
name|RTWN_N_TRANSFER
init|=
literal|5
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|RTWN_EP_QUEUES
value|RTWN_BULK_RX
end_define

begin_struct
struct|struct
name|rtwn_usb_softc
block|{
name|struct
name|rtwn_softc
name|uc_sc
decl_stmt|;
comment|/* must be the first */
name|struct
name|usb_device
modifier|*
name|uc_udev
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|uc_xfer
index|[
name|RTWN_N_TRANSFER
index|]
decl_stmt|;
name|struct
name|rtwn_data
name|uc_rx
index|[
name|RTWN_USB_RX_LIST_COUNT
index|]
decl_stmt|;
name|rtwn_datahead
name|uc_rx_active
decl_stmt|;
name|rtwn_datahead
name|uc_rx_inactive
decl_stmt|;
name|struct
name|rtwn_data
name|uc_tx
index|[
name|RTWN_USB_TX_LIST_COUNT
index|]
decl_stmt|;
name|rtwn_datahead
name|uc_tx_active
decl_stmt|;
name|rtwn_datahead
name|uc_tx_inactive
decl_stmt|;
name|rtwn_datahead
name|uc_tx_pending
decl_stmt|;
name|int
function_decl|(
modifier|*
name|uc_align_rx
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|ntx
decl_stmt|;
name|int
name|tx_agg_desc_num
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTWN_USB_SOFTC
parameter_list|(
name|sc
parameter_list|)
value|((struct rtwn_usb_softc *)(sc))
end_define

begin_define
define|#
directive|define
name|rtwn_usb_align_rx
parameter_list|(
name|_uc
parameter_list|,
name|_totlen
parameter_list|,
name|_len
parameter_list|)
define|\
value|(((_uc)->uc_align_rx)((_totlen), (_len)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTWN_USBVAR_H */
end_comment

end_unit

