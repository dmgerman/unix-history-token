begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2005 Craig Boston  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul, THE VOICES IN HIS HEAD OR  * THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_IF_CDCEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_IF_CDCEREG_H_
end_define

begin_define
define|#
directive|define
name|CDCE_IND_SIZE_MAX
value|32
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|CDCE_512X4_IFQ_MAXLEN
value|MAX((2*CDCE_512X4_FRAMES_MAX), IFQ_MAXLEN)
end_define

begin_union
union|union
name|cdce_eth_rx
block|{
comment|/* multiframe header */
name|struct
name|usb2_cdc_mf_eth_512x4_header
name|hdr
decl_stmt|;
name|uint8_t
name|data
index|[
name|MCLBYTES
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|USB_HOST_ALIGN
argument_list|)
union|;
end_union

begin_union
union|union
name|cdce_eth_tx
block|{
comment|/* multiframe header */
name|struct
name|usb2_cdc_mf_eth_512x4_header
name|hdr
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|USB_HOST_ALIGN
argument_list|)
union|;
end_union

begin_struct
struct|struct
name|cdce_mq
block|{
comment|/* mini-queue */
name|struct
name|mbuf
modifier|*
name|ifq_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ifq_tail
decl_stmt|;
name|uint16_t
name|ifq_len
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|CDCE_BULK_A
block|,
name|CDCE_BULK_B
block|,
name|CDCE_INTR
block|,
name|CDCE_N_TRANSFER
init|=
literal|3
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|cdce_softc
block|{
name|void
modifier|*
name|sc_evilhack
decl_stmt|;
comment|/* XXX this pointer must be first */
name|union
name|cdce_eth_tx
name|sc_tx
decl_stmt|;
name|union
name|cdce_eth_rx
name|sc_rx
decl_stmt|;
name|struct
name|ifmedia
name|sc_ifmedia
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|cdce_mq
name|sc_rx_mq
decl_stmt|;
name|struct
name|cdce_mq
name|sc_tx_mq
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|struct
name|usb2_xfer
modifier|*
name|sc_xfer
index|[
name|CDCE_N_TRANSFER
index|]
decl_stmt|;
name|struct
name|usb2_device
modifier|*
name|sc_udev
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|uint32_t
name|sc_unit
decl_stmt|;
name|uint16_t
name|sc_flags
decl_stmt|;
define|#
directive|define
name|CDCE_FLAG_ZAURUS
value|0x0001
define|#
directive|define
name|CDCE_FLAG_NO_UNION
value|0x0002
define|#
directive|define
name|CDCE_FLAG_LL_READY
value|0x0004
define|#
directive|define
name|CDCE_FLAG_HL_READY
value|0x0008
define|#
directive|define
name|CDCE_FLAG_RX_DATA
value|0x0010
name|uint8_t
name|sc_name
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|sc_data_iface_no
decl_stmt|;
name|uint8_t
name|sc_ifaces_index
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|sc_iface_protocol
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_IF_CDCEREG_H_ */
end_comment

end_unit

