begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Hans Petter Selasky. All rights reserved.  * Copyright (c) 2009 Diego Giagio. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Thanks to Diego Giagio for figuring out the programming details for  * the Apple iPhone Ethernet driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_IPHETHVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_IPHETHVAR_H_
end_define

begin_define
define|#
directive|define
name|IPHETH_USBINTF_CLASS
value|255
end_define

begin_define
define|#
directive|define
name|IPHETH_USBINTF_SUBCLASS
value|253
end_define

begin_define
define|#
directive|define
name|IPHETH_USBINTF_PROTO
value|1
end_define

begin_define
define|#
directive|define
name|IPHETH_BUF_SIZE
value|1516
end_define

begin_define
define|#
directive|define
name|IPHETH_TX_TIMEOUT
value|5000
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|IPHETH_RX_FRAMES_MAX
value|1
end_define

begin_define
define|#
directive|define
name|IPHETH_TX_FRAMES_MAX
value|8
end_define

begin_define
define|#
directive|define
name|IPHETH_RX_ADJ
value|2
end_define

begin_define
define|#
directive|define
name|IPHETH_CFG_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|IPHETH_IF_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|IPHETH_ALT_INTFNUM
value|1
end_define

begin_define
define|#
directive|define
name|IPHETH_CTRL_ENDP
value|0x00
end_define

begin_define
define|#
directive|define
name|IPHETH_CTRL_BUF_SIZE
value|0x40
end_define

begin_define
define|#
directive|define
name|IPHETH_CTRL_TIMEOUT
value|5000
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|IPHETH_CMD_GET_MACADDR
value|0x00
end_define

begin_define
define|#
directive|define
name|IPHETH_CMD_CARRIER_CHECK
value|0x45
end_define

begin_define
define|#
directive|define
name|IPHETH_CARRIER_ON
value|0x04
end_define

begin_enum
enum|enum
block|{
name|IPHETH_BULK_TX
block|,
name|IPHETH_BULK_RX
block|,
name|IPHETH_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ipheth_softc
block|{
name|struct
name|usb_ether
name|sc_ue
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|IPHETH_N_TRANSFER
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|sc_rx_buf
index|[
name|IPHETH_RX_FRAMES_MAX
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|sc_tx_buf
index|[
name|IPHETH_TX_FRAMES_MAX
index|]
decl_stmt|;
name|uint8_t
name|sc_data
index|[
name|IPHETH_CTRL_BUF_SIZE
index|]
decl_stmt|;
name|uint8_t
name|sc_iface_no
decl_stmt|;
name|uint8_t
name|sc_carrier_on
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPHETH_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|IPHETH_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|IPHETH_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_IPHETHVAR_H_ */
end_comment

end_unit

