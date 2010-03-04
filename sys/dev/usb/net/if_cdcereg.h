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
name|CDCE_FRAMES_MAX
value|8
end_define

begin_comment
comment|/* units */
end_comment

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
name|CDCE_NCM_TX_MAXLEN
value|2048UL
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|CDCE_NCM_TX_FRAMES_MAX
value|8
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|CDCE_NCM_RX_MAXLEN
value|(1UL<< 14)
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|CDCE_NCM_RX_FRAMES_MAX
value|1
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|CDCE_NCM_SUBFRAMES_MAX
value|32
end_define

begin_comment
comment|/* units */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CDCE_HAVE_NCM
end_ifndef

begin_define
define|#
directive|define
name|CDCE_HAVE_NCM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
block|{
name|CDCE_BULK_RX
block|,
name|CDCE_BULK_TX
block|,
name|CDCE_INTR_RX
block|,
name|CDCE_INTR_TX
block|,
name|CDCE_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|cdce_ncm
block|{
name|struct
name|usb_ncm16_hdr
name|hdr
decl_stmt|;
name|struct
name|usb_ncm16_dpt
name|dpt
decl_stmt|;
name|struct
name|usb_ncm16_dp
name|dp
index|[
name|CDCE_NCM_SUBFRAMES_MAX
index|]
decl_stmt|;
name|uint32_t
name|rx_max
decl_stmt|;
name|uint32_t
name|tx_max
decl_stmt|;
name|uint16_t
name|tx_remainder
decl_stmt|;
name|uint16_t
name|tx_modulus
decl_stmt|;
name|uint16_t
name|tx_struct_align
decl_stmt|;
name|uint16_t
name|tx_seq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdce_softc
block|{
name|struct
name|usb_ether
name|sc_ue
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
if|#
directive|if
name|CDCE_HAVE_NCM
name|struct
name|cdce_ncm
name|sc_ncm
decl_stmt|;
endif|#
directive|endif
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|CDCE_N_TRANSFER
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|sc_rx_buf
index|[
name|CDCE_FRAMES_MAX
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|sc_tx_buf
index|[
name|CDCE_FRAMES_MAX
index|]
decl_stmt|;
name|int
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
name|CDCE_FLAG_RX_DATA
value|0x0010
name|uint8_t
name|sc_eaddr_str_index
decl_stmt|;
name|uint8_t
name|sc_ifaces_index
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDCE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|CDCE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|CDCE_LOCK_ASSERT
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
comment|/* _USB_IF_CDCEREG_H_ */
end_comment

end_unit

