begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: if_urndisreg.h,v 1.19 2013/11/21 14:08:05 mpi Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2010 Jonathan Armani<armani@openbsd.org>  * Copyright (c) 2010 Fabien Romano<fabien@openbsd.org>  * Copyright (c) 2010 Michael Knudsen<mk@openbsd.org>  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_URNDISREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_URNDISREG_H_
end_define

begin_define
define|#
directive|define
name|RNDIS_RESPONSE_LEN
value|1024
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|RNDIS_RX_MAXLEN
value|(16 * 1024)
end_define

begin_define
define|#
directive|define
name|RNDIS_TX_FRAMES_MAX
value|8
end_define

begin_define
define|#
directive|define
name|RNDIS_TX_MAXLEN
value|MCLBYTES
end_define

begin_enum
enum|enum
block|{
name|URNDIS_BULK_RX
block|,
name|URNDIS_BULK_TX
block|,
name|URNDIS_INTR_RX
block|,
name|URNDIS_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|urndis_softc
block|{
name|struct
name|usb_ether
name|sc_ue
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* RNDIS device info */
name|uint32_t
name|sc_lim_pktsz
decl_stmt|;
name|uint32_t
name|sc_filter
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_udev
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|URNDIS_N_TRANSFER
index|]
decl_stmt|;
name|uint8_t
name|sc_ifaceno_ctl
decl_stmt|;
name|uint8_t
name|sc_response_buf
index|[
name|RNDIS_RESPONSE_LEN
index|]
name|__aligned
argument_list|(
literal|4
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|URNDIS_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|URNDIS_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|URNDIS_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->sc_mtx, (what))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_URNDISREG_H_ */
end_comment

end_unit

