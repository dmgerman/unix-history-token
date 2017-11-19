begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the CATC Netmate II USB to ethernet controller.  */
end_comment

begin_comment
comment|/* Vendor specific control commands. */
end_comment

begin_define
define|#
directive|define
name|CUE_CMD_RESET
value|0xF4
end_define

begin_define
define|#
directive|define
name|CUE_CMD_GET_MACADDR
value|0xF2
end_define

begin_define
define|#
directive|define
name|CUE_CMD_WRITEREG
value|0xFA
end_define

begin_define
define|#
directive|define
name|CUE_CMD_READREG
value|0xFB
end_define

begin_define
define|#
directive|define
name|CUE_CMD_READSRAM
value|0xF1
end_define

begin_define
define|#
directive|define
name|CUE_CMD_WRITESRAM
value|0xFC
end_define

begin_comment
comment|/* Internal registers. */
end_comment

begin_define
define|#
directive|define
name|CUE_TX_BUFCNT
value|0x20
end_define

begin_define
define|#
directive|define
name|CUE_RX_BUFCNT
value|0x21
end_define

begin_define
define|#
directive|define
name|CUE_ADVANCED_OPMODES
value|0x22
end_define

begin_define
define|#
directive|define
name|CUE_TX_BUFPKTS
value|0x23
end_define

begin_define
define|#
directive|define
name|CUE_RX_BUFPKTS
value|0x24
end_define

begin_define
define|#
directive|define
name|CUE_RX_MAXCHAIN
value|0x25
end_define

begin_define
define|#
directive|define
name|CUE_ETHCTL
value|0x60
end_define

begin_define
define|#
directive|define
name|CUE_ETHSTS
value|0x61
end_define

begin_define
define|#
directive|define
name|CUE_PAR5
value|0x62
end_define

begin_define
define|#
directive|define
name|CUE_PAR4
value|0x63
end_define

begin_define
define|#
directive|define
name|CUE_PAR3
value|0x64
end_define

begin_define
define|#
directive|define
name|CUE_PAR2
value|0x65
end_define

begin_define
define|#
directive|define
name|CUE_PAR1
value|0x66
end_define

begin_define
define|#
directive|define
name|CUE_PAR0
value|0x67
end_define

begin_comment
comment|/* Error counters, all 16 bits wide. */
end_comment

begin_define
define|#
directive|define
name|CUE_TX_SINGLECOLL
value|0x69
end_define

begin_define
define|#
directive|define
name|CUE_TX_MULTICOLL
value|0x6B
end_define

begin_define
define|#
directive|define
name|CUE_TX_EXCESSCOLL
value|0x6D
end_define

begin_define
define|#
directive|define
name|CUE_RX_FRAMEERR
value|0x6F
end_define

begin_define
define|#
directive|define
name|CUE_LEDCTL
value|0x81
end_define

begin_comment
comment|/* Advenced operating mode register. */
end_comment

begin_define
define|#
directive|define
name|CUE_AOP_SRAMWAITS
value|0x03
end_define

begin_define
define|#
directive|define
name|CUE_AOP_EMBED_RXLEN
value|0x08
end_define

begin_define
define|#
directive|define
name|CUE_AOP_RXCOMBINE
value|0x10
end_define

begin_define
define|#
directive|define
name|CUE_AOP_TXCOMBINE
value|0x20
end_define

begin_define
define|#
directive|define
name|CUE_AOP_EVEN_PKT_READS
value|0x40
end_define

begin_define
define|#
directive|define
name|CUE_AOP_LOOPBK
value|0x80
end_define

begin_comment
comment|/* Ethernet control register. */
end_comment

begin_define
define|#
directive|define
name|CUE_ETHCTL_RX_ON
value|0x01
end_define

begin_define
define|#
directive|define
name|CUE_ETHCTL_LINK_POLARITY
value|0x02
end_define

begin_define
define|#
directive|define
name|CUE_ETHCTL_LINK_FORCE_OK
value|0x04
end_define

begin_define
define|#
directive|define
name|CUE_ETHCTL_MCAST_ON
value|0x08
end_define

begin_define
define|#
directive|define
name|CUE_ETHCTL_PROMISC
value|0x10
end_define

begin_comment
comment|/* Ethernet status register. */
end_comment

begin_define
define|#
directive|define
name|CUE_ETHSTS_NO_CARRIER
value|0x01
end_define

begin_define
define|#
directive|define
name|CUE_ETHSTS_LATECOLL
value|0x02
end_define

begin_define
define|#
directive|define
name|CUE_ETHSTS_EXCESSCOLL
value|0x04
end_define

begin_define
define|#
directive|define
name|CUE_ETHSTS_TXBUF_AVAIL
value|0x08
end_define

begin_define
define|#
directive|define
name|CUE_ETHSTS_BAD_POLARITY
value|0x10
end_define

begin_define
define|#
directive|define
name|CUE_ETHSTS_LINK_OK
value|0x20
end_define

begin_comment
comment|/* LED control register. */
end_comment

begin_define
define|#
directive|define
name|CUE_LEDCTL_BLINK_1X
value|0x00
end_define

begin_define
define|#
directive|define
name|CUE_LEDCTL_BLINK_2X
value|0x01
end_define

begin_define
define|#
directive|define
name|CUE_LEDCTL_BLINK_QUARTER_ON
value|0x02
end_define

begin_define
define|#
directive|define
name|CUE_LEDCTL_BLINK_QUARTER_OFF
value|0x03
end_define

begin_define
define|#
directive|define
name|CUE_LEDCTL_OFF
value|0x04
end_define

begin_define
define|#
directive|define
name|CUE_LEDCTL_FOLLOW_LINK
value|0x08
end_define

begin_comment
comment|/*  * Address in ASIC's internal SRAM where the multicast hash table lives.  * The table is 64 bytes long, giving us a 512-bit table.  We have to set  * the bit that corresponds to the broadcast address in order to enable  * reception of broadcast frames.  */
end_comment

begin_define
define|#
directive|define
name|CUE_MCAST_TABLE_ADDR
value|0xFA80
end_define

begin_define
define|#
directive|define
name|CUE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|CUE_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|CUE_RX_FRAMES
value|1
end_define

begin_define
define|#
directive|define
name|CUE_TX_FRAMES
value|1
end_define

begin_define
define|#
directive|define
name|CUE_CTL_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|CUE_CTL_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|CUE_CONFIG_IDX
value|0
end_define

begin_comment
comment|/* config number 1 */
end_comment

begin_define
define|#
directive|define
name|CUE_IFACE_IDX
value|0
end_define

begin_comment
comment|/* The interrupt endpoint is currently unused by the CATC part. */
end_comment

begin_enum
enum|enum
block|{
name|CUE_BULK_DT_WR
block|,
name|CUE_BULK_DT_RD
block|,
name|CUE_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|cue_softc
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
name|CUE_N_TRANSFER
index|]
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|CUE_FLAG_LINK
value|0x0001
comment|/* got a link */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CUE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|CUE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|CUE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

end_unit

