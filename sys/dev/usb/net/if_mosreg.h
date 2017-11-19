begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010, 2011 Rick van der Zwet<info@rickvanderzwet.nl>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Johann Christian Rode<jcrode@gmx.net>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1997, 1998, 1999, 2000-2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Ravikanth.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul, THE VOICES IN HIS HEAD OR  * THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * Register definitions for the Moschip MCS7x30 ethernet controller.  */
end_comment

begin_define
define|#
directive|define
name|MOS_MCAST_TABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|MOS_IPG0
value|0x08
end_define

begin_define
define|#
directive|define
name|MOS_IPG1
value|0x09
end_define

begin_define
define|#
directive|define
name|MOS_PHY_DATA0
value|0x0a
end_define

begin_define
define|#
directive|define
name|MOS_PHY_DATA1
value|0x0b
end_define

begin_define
define|#
directive|define
name|MOS_PHY_CTL
value|0x0c
end_define

begin_define
define|#
directive|define
name|MOS_PHY_STS
value|0x0d
end_define

begin_define
define|#
directive|define
name|MOS_PHY_DATA
value|MOS_PHY_DATA0
end_define

begin_define
define|#
directive|define
name|MOS_CTL
value|0x0e
end_define

begin_define
define|#
directive|define
name|MOS_MAC0
value|0x0f
end_define

begin_define
define|#
directive|define
name|MOS_MAC1
value|0x10
end_define

begin_define
define|#
directive|define
name|MOS_MAC2
value|0x11
end_define

begin_define
define|#
directive|define
name|MOS_MAC3
value|0x12
end_define

begin_define
define|#
directive|define
name|MOS_MAC4
value|0x13
end_define

begin_define
define|#
directive|define
name|MOS_MAC5
value|0x14
end_define

begin_define
define|#
directive|define
name|MOS_MAC
value|MOS_MAC0
end_define

begin_comment
comment|/* apparently only available on hardware rev. C */
end_comment

begin_define
define|#
directive|define
name|MOS_FRAME_DROP_CNT
value|0x15
end_define

begin_define
define|#
directive|define
name|MOS_PAUSE_TRHD
value|0x16
end_define

begin_define
define|#
directive|define
name|MOS_PHYCTL_PHYADDR
value|0x1f
end_define

begin_define
define|#
directive|define
name|MOS_PHYCTL_WRITE
value|0x20
end_define

begin_define
define|#
directive|define
name|MOS_PHYCTL_READ
value|0x40
end_define

begin_define
define|#
directive|define
name|MOS_PHYSTS_PHYREG
value|0x1f
end_define

begin_define
define|#
directive|define
name|MOS_PHYSTS_READY
value|0x40
end_define

begin_define
define|#
directive|define
name|MOS_PHYSTS_PENDING
value|0x80
end_define

begin_define
define|#
directive|define
name|MOS_CTL_RX_PROMISC
value|0x01
end_define

begin_define
define|#
directive|define
name|MOS_CTL_ALLMULTI
value|0x02
end_define

begin_define
define|#
directive|define
name|MOS_CTL_SLEEP
value|0x04
end_define

begin_define
define|#
directive|define
name|MOS_CTL_TX_ENB
value|0x08
end_define

begin_comment
comment|/*  * The documentation calls this bit 'reserved', but in the FreeBSD driver  * provided by the vendor, this enables the receiver.  */
end_comment

begin_define
define|#
directive|define
name|MOS_CTL_RX_ENB
value|0x10
end_define

begin_define
define|#
directive|define
name|MOS_CTL_FDX_ENB
value|0x20
end_define

begin_comment
comment|/* 0 = 10 Mbps, 1 = 100 Mbps */
end_comment

begin_define
define|#
directive|define
name|MOS_CTL_SPEEDSEL
value|0x40
end_define

begin_comment
comment|/* 0 = PHY controls speed/duplex mode, 1 = bridge controls speed/duplex mode */
end_comment

begin_define
define|#
directive|define
name|MOS_CTL_BS_ENB
value|0x80
end_define

begin_define
define|#
directive|define
name|MOS_RXSTS_SHORT_FRAME
value|0x01
end_define

begin_define
define|#
directive|define
name|MOS_RXSTS_LENGTH_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|MOS_RXSTS_ALIGN_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|MOS_RXSTS_CRC_ERROR
value|0x08
end_define

begin_define
define|#
directive|define
name|MOS_RXSTS_LARGE_FRAME
value|0x10
end_define

begin_define
define|#
directive|define
name|MOS_RXSTS_VALID
value|0x20
end_define

begin_comment
comment|/*  * The EtherType field of an Ethernet frame can contain values other than  * the frame length, hence length errors are ignored.  */
end_comment

begin_define
define|#
directive|define
name|MOS_RXSTS_MASK
value|0x3d
end_define

begin_define
define|#
directive|define
name|MOS_PAUSE_TRHD_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|MOS_PAUSE_REWRITES
value|3
end_define

begin_define
define|#
directive|define
name|MOS_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|MOS_RX_LIST_CNT
value|1
end_define

begin_define
define|#
directive|define
name|MOS_TX_LIST_CNT
value|1
end_define

begin_comment
comment|/* Maximum size of a fast ethernet frame plus one byte for the status */
end_comment

begin_define
define|#
directive|define
name|MOS_BUFSZ
value|(ETHER_MAX_LEN+1)
end_define

begin_comment
comment|/*  * USB endpoints.  */
end_comment

begin_define
define|#
directive|define
name|MOS_ENDPT_RX
value|0
end_define

begin_define
define|#
directive|define
name|MOS_ENDPT_TX
value|1
end_define

begin_define
define|#
directive|define
name|MOS_ENDPT_INTR
value|2
end_define

begin_define
define|#
directive|define
name|MOS_ENDPT_MAX
value|3
end_define

begin_comment
comment|/*  * USB vendor requests.  */
end_comment

begin_define
define|#
directive|define
name|MOS_UR_READREG
value|0x0e
end_define

begin_define
define|#
directive|define
name|MOS_UR_WRITEREG
value|0x0d
end_define

begin_define
define|#
directive|define
name|MOS_CONFIG_IDX
value|0
end_define

begin_define
define|#
directive|define
name|MOS_IFACE_IDX
value|0
end_define

begin_define
define|#
directive|define
name|MCS7730
value|0x0001
end_define

begin_define
define|#
directive|define
name|MCS7830
value|0x0002
end_define

begin_define
define|#
directive|define
name|MCS7832
value|0x0004
end_define

begin_define
define|#
directive|define
name|MOS_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_struct
struct|struct
name|mos_softc
block|{
name|struct
name|usb_ether
name|sc_ue
decl_stmt|;
name|struct
name|ifnet
name|ifp
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
name|MOS_ENDPT_MAX
index|]
decl_stmt|;
name|uint16_t
name|mos_flags
decl_stmt|;
name|int
name|mos_link
decl_stmt|;
name|unsigned
name|char
name|mos_ipgs
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|mos_phyaddrs
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
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|uether_getmii(&(sc)->sc_ue)
end_define

begin_define
define|#
directive|define
name|MOS_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|MOS_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|MOS_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

end_unit

