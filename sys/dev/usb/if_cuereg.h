begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the CATC Netmate II USB to ethernet controller.  */
end_comment

begin_comment
comment|/*  * Vendor specific control commands.  */
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
comment|/*  * Internal registers  */
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
comment|/* Advenced operating mode register */
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
comment|/* Ethernet control register */
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
comment|/* Ethernet status register */
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
comment|/* LED control register */
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
comment|/*  * Address in ASIC's internal SRAM where the  * multicast hash table lives. The table is 64 bytes long,  * giving us a 512-bit table. We have to set the bit that  * corresponds to the broadcast address in order to enable  * reception of broadcast frames.  */
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
name|CUE_MCAST_TABLE_LEN
value|64
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
name|ETHER_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|CUE_BUFSZ
value|1536
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
name|CUE_RX_LIST_CNT
value|1
end_define

begin_define
define|#
directive|define
name|CUE_TX_LIST_CNT
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
name|CUE_CONFIG_NO
value|1
end_define

begin_comment
comment|/*  * The interrupt endpoint is currently unused  * by the KLSI part.  */
end_comment

begin_define
define|#
directive|define
name|CUE_ENDPT_RX
value|0x0
end_define

begin_define
define|#
directive|define
name|CUE_ENDPT_TX
value|0x1
end_define

begin_define
define|#
directive|define
name|CUE_ENDPT_INTR
value|0x2
end_define

begin_define
define|#
directive|define
name|CUE_ENDPT_MAX
value|0x3
end_define

begin_struct
struct|struct
name|cue_type
block|{
name|u_int16_t
name|cue_vid
decl_stmt|;
name|u_int16_t
name|cue_did
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|cue_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|cue_chain
block|{
name|struct
name|cue_softc
modifier|*
name|cue_sc
decl_stmt|;
name|usbd_xfer_handle
name|cue_xfer
decl_stmt|;
name|char
modifier|*
name|cue_buf
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|cue_mbuf
decl_stmt|;
name|int
name|cue_accum
decl_stmt|;
name|int
name|cue_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cue_cdata
block|{
name|struct
name|cue_chain
name|cue_tx_chain
index|[
name|CUE_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|cue_chain
name|cue_rx_chain
index|[
name|CUE_RX_LIST_CNT
index|]
decl_stmt|;
name|int
name|cue_tx_prod
decl_stmt|;
name|int
name|cue_tx_cons
decl_stmt|;
name|int
name|cue_tx_cnt
decl_stmt|;
name|int
name|cue_rx_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CUE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_struct
struct|struct
name|cue_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|usbd_device_handle
name|cue_udev
decl_stmt|;
name|usbd_interface_handle
name|cue_iface
decl_stmt|;
name|int
name|cue_ed
index|[
name|CUE_ENDPT_MAX
index|]
decl_stmt|;
name|usbd_pipe_handle
name|cue_ep
index|[
name|CUE_ENDPT_MAX
index|]
decl_stmt|;
name|int
name|cue_unit
decl_stmt|;
name|u_int8_t
name|cue_mctab
index|[
name|CUE_MCAST_TABLE_LEN
index|]
decl_stmt|;
name|int
name|cue_if_flags
decl_stmt|;
name|u_int16_t
name|cue_rxfilt
decl_stmt|;
name|struct
name|cue_cdata
name|cue_cdata
decl_stmt|;
name|struct
name|callout_handle
name|cue_stat_ch
decl_stmt|;
name|struct
name|mtx
name|cue_mtx
decl_stmt|;
name|char
name|cue_dying
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|CUE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->cue_mtx)
end_define

begin_define
define|#
directive|define
name|CUE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->cue_mtx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CUE_LOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CUE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

