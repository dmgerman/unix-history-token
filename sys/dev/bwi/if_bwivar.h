begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 The DragonFly Project.  All rights reserved.  *   * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $DragonFly: src/sys/dev/netif/bwi/if_bwivar.h,v 1.14 2008/02/15 11:15:38 sephe Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_BWIVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_BWIVAR_H
end_define

begin_define
define|#
directive|define
name|BWI_ALIGN
value|0x1000
end_define

begin_define
define|#
directive|define
name|BWI_RING_ALIGN
value|BWI_ALIGN
end_define

begin_define
define|#
directive|define
name|BWI_BUS_SPACE_MAXADDR
value|0x3fffffff
end_define

begin_define
define|#
directive|define
name|BWI_TX_NRING
value|6
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_NRING
value|6
end_define

begin_define
define|#
directive|define
name|BWI_TX_NDESC
value|128
end_define

begin_define
define|#
directive|define
name|BWI_RX_NDESC
value|64
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATS_NDESC
value|64
end_define

begin_define
define|#
directive|define
name|BWI_TX_NSPRDESC
value|2
end_define

begin_define
define|#
directive|define
name|BWI_TX_DATA_RING
value|1
end_define

begin_comment
comment|/* XXX Onoe/Sample/AMRR probably need different configuration */
end_comment

begin_define
define|#
directive|define
name|BWI_SHRETRY
value|7
end_define

begin_define
define|#
directive|define
name|BWI_LGRETRY
value|4
end_define

begin_define
define|#
directive|define
name|BWI_SHRETRY_FB
value|3
end_define

begin_define
define|#
directive|define
name|BWI_LGRETRY_FB
value|2
end_define

begin_define
define|#
directive|define
name|BWI_LED_EVENT_NONE
value|-1
end_define

begin_define
define|#
directive|define
name|BWI_LED_EVENT_POLL
value|0
end_define

begin_define
define|#
directive|define
name|BWI_LED_EVENT_TX
value|1
end_define

begin_define
define|#
directive|define
name|BWI_LED_EVENT_RX
value|2
end_define

begin_define
define|#
directive|define
name|BWI_LED_SLOWDOWN
parameter_list|(
name|dur
parameter_list|)
value|(dur) = (((dur) * 3) / 2)
end_define

begin_enum
enum|enum
name|bwi_txpwrcb_type
block|{
name|BWI_TXPWR_INIT
init|=
literal|0
block|,
name|BWI_TXPWR_FORCE
init|=
literal|1
block|,
name|BWI_TXPWR_CALIB
init|=
literal|2
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|BWI_NOISE_FLOOR
value|-95
end_define

begin_comment
comment|/* TODO: noise floor calc */
end_comment

begin_define
define|#
directive|define
name|BWI_FRAME_MIN_LEN
parameter_list|(
name|hdr
parameter_list|)
define|\
value|((hdr) + sizeof(struct ieee80211_frame_ack) + IEEE80211_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_mem_bt, (sc)->sc_mem_bh, (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_mem_bt, (sc)->sc_mem_bh, (reg))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_mem_bt, (sc)->sc_mem_bh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_mem_bt, (sc)->sc_mem_bh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_SETBITS_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|CSR_WRITE_4((sc), (reg), CSR_READ_4((sc), (reg)) | (bits))
end_define

begin_define
define|#
directive|define
name|CSR_SETBITS_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|CSR_WRITE_2((sc), (reg), CSR_READ_2((sc), (reg)) | (bits))
end_define

begin_define
define|#
directive|define
name|CSR_FILT_SETBITS_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|filt
parameter_list|,
name|bits
parameter_list|)
define|\
value|CSR_WRITE_4((sc), (reg), (CSR_READ_4((sc), (reg))& (filt)) | (bits))
end_define

begin_define
define|#
directive|define
name|CSR_FILT_SETBITS_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|filt
parameter_list|,
name|bits
parameter_list|)
define|\
value|CSR_WRITE_2((sc), (reg), (CSR_READ_2((sc), (reg))& (filt)) | (bits))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBITS_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|CSR_WRITE_4((sc), (reg), CSR_READ_4((sc), (reg))& ~(bits))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBITS_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|CSR_WRITE_2((sc), (reg), CSR_READ_2((sc), (reg))& ~(bits))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BWI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|dbg
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { \ 	if ((sc)->sc_debug& (dbg)) \ 		device_printf((sc)->sc_dev, fmt, __VA_ARGS__); \ } while (0)
end_define

begin_define
define|#
directive|define
name|_DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|dbg
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { \ 	if ((sc)->sc_debug& (dbg)) \ 		printf(fmt, __VA_ARGS__); \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !BWI_DEBUG */
end_comment

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|dbg
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|_DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|dbg
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BWI_DEBUG */
end_comment

begin_struct
struct|struct
name|bwi_desc32
block|{
comment|/* Little endian */
name|uint32_t
name|ctrl
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
comment|/* BWI_DESC32_A_ */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_DESC32_A_FUNC_TXRX
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_DESC32_A_FUNC_MASK
value|__BITS(31, 30)
end_define

begin_define
define|#
directive|define
name|BWI_DESC32_A_ADDR_MASK
value|__BITS(29, 0)
end_define

begin_define
define|#
directive|define
name|BWI_DESC32_C_BUFLEN_MASK
value|__BITS(12, 0)
end_define

begin_define
define|#
directive|define
name|BWI_DESC32_C_ADDRHI_MASK
value|__BITS(17, 16)
end_define

begin_define
define|#
directive|define
name|BWI_DESC32_C_EOR
value|__BIT(28)
end_define

begin_define
define|#
directive|define
name|BWI_DESC32_C_INTR
value|__BIT(29)
end_define

begin_define
define|#
directive|define
name|BWI_DESC32_C_FRAME_END
value|__BIT(30)
end_define

begin_define
define|#
directive|define
name|BWI_DESC32_C_FRAME_START
value|__BIT(31)
end_define

begin_struct
struct|struct
name|bwi_desc64
block|{
comment|/* Little endian */
name|uint32_t
name|ctrl0
decl_stmt|;
name|uint32_t
name|ctrl1
decl_stmt|;
name|uint32_t
name|addr_lo
decl_stmt|;
name|uint32_t
name|addr_hi
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|bwi_rxbuf_hdr
block|{
comment|/* Little endian */
name|uint16_t
name|rxh_buflen
decl_stmt|;
comment|/* exclude bwi_rxbuf_hdr */
name|uint8_t
name|rxh_pad1
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|rxh_flags1
decl_stmt|;
comment|/* BWI_RXH_F1_ */
name|uint8_t
name|rxh_rssi
decl_stmt|;
name|uint8_t
name|rxh_sq
decl_stmt|;
name|uint16_t
name|rxh_phyinfo
decl_stmt|;
comment|/* BWI_RXH_PHYINFO_ */
name|uint16_t
name|rxh_flags3
decl_stmt|;
comment|/* BWI_RXH_F3_ */
name|uint16_t
name|rxh_flags2
decl_stmt|;
comment|/* BWI_RXH_F2_ */
name|uint16_t
name|rxh_tsf
decl_stmt|;
name|uint8_t
name|rxh_pad3
index|[
literal|14
index|]
decl_stmt|;
comment|/* Padded to 30bytes */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_RXH_F1_BCM2053_RSSI
value|__BIT(14)
end_define

begin_define
define|#
directive|define
name|BWI_RXH_F1_SHPREAMBLE
value|__BIT(7)
end_define

begin_define
define|#
directive|define
name|BWI_RXH_F1_OFDM
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_RXH_F2_TYPE2FRAME
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|BWI_RXH_F3_BCM2050_RSSI
value|__BIT(10)
end_define

begin_define
define|#
directive|define
name|BWI_RXH_PHYINFO_LNAGAIN
value|__BITS(15, 14)
end_define

begin_struct
struct|struct
name|bwi_txbuf_hdr
block|{
comment|/* Little endian */
name|uint32_t
name|txh_mac_ctrl
decl_stmt|;
comment|/* BWI_TXH_MAC_C_ */
name|uint8_t
name|txh_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|txh_unknown1
decl_stmt|;
name|uint16_t
name|txh_phy_ctrl
decl_stmt|;
comment|/* BWI_TXH_PHY_C_ */
name|uint8_t
name|txh_ivs
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|txh_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|txh_unknown2
decl_stmt|;
name|uint8_t
name|txh_rts_fb_plcp
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|txh_rts_fb_duration
decl_stmt|;
name|uint8_t
name|txh_fb_plcp
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|txh_fb_duration
decl_stmt|;
name|uint8_t
name|txh_pad2
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|txh_id
decl_stmt|;
comment|/* BWI_TXH_ID_ */
name|uint16_t
name|txh_unknown3
decl_stmt|;
name|uint8_t
name|txh_rts_plcp
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|txh_rts_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|txh_rts_duration
decl_stmt|;
name|uint8_t
name|txh_rts_ra
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|txh_rts_ta
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|txh_pad3
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|txh_plcp
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_TXH_ID_RING_MASK
value|__BITS(15, 13)
end_define

begin_define
define|#
directive|define
name|BWI_TXH_ID_IDX_MASK
value|__BITS(12, 0)
end_define

begin_define
define|#
directive|define
name|BWI_TXH_PHY_C_OFDM
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_TXH_PHY_C_SHPREAMBLE
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|BWI_TXH_PHY_C_ANTMODE_MASK
value|__BITS(9, 8)
end_define

begin_define
define|#
directive|define
name|BWI_TXH_MAC_C_ACK
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_TXH_MAC_C_FIRST_FRAG
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|BWI_TXH_MAC_C_HWSEQ
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|BWI_TXH_MAC_C_FB_OFDM
value|__BIT(8)
end_define

begin_struct
struct|struct
name|bwi_txstats
block|{
comment|/* Little endian */
name|uint8_t
name|txs_pad1
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|txs_id
decl_stmt|;
name|uint8_t
name|txs_flags
decl_stmt|;
comment|/* BWI_TXS_F_ */
name|uint8_t
name|txs_txcnt
decl_stmt|;
comment|/* BWI_TXS_TXCNT_ */
name|uint8_t
name|txs_pad2
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|txs_seq
decl_stmt|;
name|uint16_t
name|txs_unknown
decl_stmt|;
name|uint8_t
name|txs_pad3
index|[
literal|2
index|]
decl_stmt|;
comment|/* Padded to 16bytes */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_TXS_TXCNT_DATA
value|__BITS(7, 4)
end_define

begin_define
define|#
directive|define
name|BWI_TXS_F_ACKED
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_TXS_F_PENDING
value|__BIT(5)
end_define

begin_struct
struct|struct
name|bwi_ring_data
block|{
name|uint32_t
name|rdata_txrx_ctrl
decl_stmt|;
name|bus_dmamap_t
name|rdata_dmap
decl_stmt|;
name|bus_addr_t
name|rdata_paddr
decl_stmt|;
name|void
modifier|*
name|rdata_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwi_txbuf
block|{
name|struct
name|mbuf
modifier|*
name|tb_mbuf
decl_stmt|;
name|bus_dmamap_t
name|tb_dmap
decl_stmt|;
name|struct
name|ieee80211_node
modifier|*
name|tb_ni
decl_stmt|;
name|int
name|tb_rate
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwi_txbuf_data
block|{
name|struct
name|bwi_txbuf
name|tbd_buf
index|[
name|BWI_TX_NDESC
index|]
decl_stmt|;
name|int
name|tbd_used
decl_stmt|;
name|int
name|tbd_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwi_rxbuf
block|{
name|struct
name|mbuf
modifier|*
name|rb_mbuf
decl_stmt|;
name|bus_addr_t
name|rb_paddr
decl_stmt|;
name|bus_dmamap_t
name|rb_dmap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwi_rxbuf_data
block|{
name|struct
name|bwi_rxbuf
name|rbd_buf
index|[
name|BWI_RX_NDESC
index|]
decl_stmt|;
name|bus_dmamap_t
name|rbd_tmp_dmap
decl_stmt|;
name|int
name|rbd_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwi_txstats_data
block|{
name|bus_dma_tag_t
name|stats_ring_dtag
decl_stmt|;
name|bus_dmamap_t
name|stats_ring_dmap
decl_stmt|;
name|bus_addr_t
name|stats_ring_paddr
decl_stmt|;
name|void
modifier|*
name|stats_ring
decl_stmt|;
name|bus_dma_tag_t
name|stats_dtag
decl_stmt|;
name|bus_dmamap_t
name|stats_dmap
decl_stmt|;
name|bus_addr_t
name|stats_paddr
decl_stmt|;
name|struct
name|bwi_txstats
modifier|*
name|stats
decl_stmt|;
name|uint32_t
name|stats_ctrl_base
decl_stmt|;
name|int
name|stats_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwi_fwhdr
block|{
comment|/* Big endian */
name|uint8_t
name|fw_type
decl_stmt|;
comment|/* BWI_FW_T_ */
name|uint8_t
name|fw_gen
decl_stmt|;
comment|/* BWI_FW_GEN */
name|uint8_t
name|fw_pad
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|fw_size
decl_stmt|;
define|#
directive|define
name|fw_iv_cnt
value|fw_size
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_FWHDR_SZ
value|sizeof(struct bwi_fwhdr)
end_define

begin_define
define|#
directive|define
name|BWI_FW_T_UCODE
value|'u'
end_define

begin_define
define|#
directive|define
name|BWI_FW_T_PCM
value|'p'
end_define

begin_define
define|#
directive|define
name|BWI_FW_T_IV
value|'i'
end_define

begin_define
define|#
directive|define
name|BWI_FW_GEN_1
value|1
end_define

begin_define
define|#
directive|define
name|BWI_FW_VERSION3
value|3
end_define

begin_define
define|#
directive|define
name|BWI_FW_VERSION4
value|4
end_define

begin_define
define|#
directive|define
name|BWI_FW_VERSION3_REVMAX
value|0x128
end_define

begin_define
define|#
directive|define
name|BWI_FW_PATH
value|"bwi_v%d_"
end_define

begin_define
define|#
directive|define
name|BWI_FW_STUB_PATH
value|BWI_FW_PATH "ucode"
end_define

begin_define
define|#
directive|define
name|BWI_FW_UCODE_PATH
value|BWI_FW_PATH "ucode%d"
end_define

begin_define
define|#
directive|define
name|BWI_FW_PCM_PATH
value|BWI_FW_PATH "pcm%d"
end_define

begin_define
define|#
directive|define
name|BWI_FW_IV_PATH
value|BWI_FW_PATH "b0g0initvals%d"
end_define

begin_define
define|#
directive|define
name|BWI_FW_IV_EXT_PATH
value|BWI_FW_PATH "b0g0bsinitvals%d"
end_define

begin_struct
struct|struct
name|bwi_fw_iv
block|{
comment|/* Big endian */
name|uint16_t
name|iv_ofs
decl_stmt|;
union|union
block|{
name|uint32_t
name|val32
decl_stmt|;
name|uint16_t
name|val16
decl_stmt|;
block|}
name|iv_val
union|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_FW_IV_OFS_MASK
value|__BITS(14, 0)
end_define

begin_define
define|#
directive|define
name|BWI_FW_IV_IS_32BIT
value|__BIT(15)
end_define

begin_struct
struct|struct
name|bwi_led
block|{
name|uint8_t
name|l_flags
decl_stmt|;
comment|/* BWI_LED_F_ */
name|uint8_t
name|l_act
decl_stmt|;
comment|/* BWI_LED_ACT_ */
name|uint8_t
name|l_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_LED_F_ACTLOW
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_LED_F_BLINK
value|0x2
end_define

begin_define
define|#
directive|define
name|BWI_LED_F_POLLABLE
value|0x4
end_define

begin_define
define|#
directive|define
name|BWI_LED_F_SLOW
value|0x8
end_define

begin_enum
enum|enum
name|bwi_clock_mode
block|{
name|BWI_CLOCK_MODE_SLOW
block|,
name|BWI_CLOCK_MODE_FAST
block|,
name|BWI_CLOCK_MODE_DYN
block|}
enum|;
end_enum

begin_struct
struct|struct
name|bwi_regwin
block|{
name|uint32_t
name|rw_flags
decl_stmt|;
comment|/* BWI_REGWIN_F_ */
name|uint16_t
name|rw_type
decl_stmt|;
comment|/* BWI_REGWIN_T_ */
name|uint8_t
name|rw_id
decl_stmt|;
name|uint8_t
name|rw_rev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_REGWIN_F_EXIST
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_CREATE_REGWIN
parameter_list|(
name|rw
parameter_list|,
name|id
parameter_list|,
name|type
parameter_list|,
name|rev
parameter_list|)
define|\
value|do {						\ 	(rw)->rw_flags = BWI_REGWIN_F_EXIST;	\ 	(rw)->rw_type = (type);			\ 	(rw)->rw_id = (id);			\ 	(rw)->rw_rev = (rev);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|BWI_REGWIN_EXIST
parameter_list|(
name|rw
parameter_list|)
value|((rw)->rw_flags& BWI_REGWIN_F_EXIST)
end_define

begin_define
define|#
directive|define
name|BWI_GPIO_REGWIN
parameter_list|(
name|sc
parameter_list|)
define|\
value|(BWI_REGWIN_EXIST(&(sc)->sc_com_regwin) ? \&(sc)->sc_com_regwin :&(sc)->sc_bus_regwin)
end_define

begin_struct_decl
struct_decl|struct
name|bwi_mac
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bwi_phy
block|{
name|enum
name|ieee80211_phymode
name|phy_mode
decl_stmt|;
name|int
name|phy_rev
decl_stmt|;
name|int
name|phy_version
decl_stmt|;
name|uint32_t
name|phy_flags
decl_stmt|;
comment|/* BWI_PHY_F_ */
name|uint16_t
name|phy_tbl_ctrl
decl_stmt|;
name|uint16_t
name|phy_tbl_data_lo
decl_stmt|;
name|uint16_t
name|phy_tbl_data_hi
decl_stmt|;
name|void
function_decl|(
modifier|*
name|phy_init
function_decl|)
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_PHY_F_CALIBRATED
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_PHY_F_LINKED
value|0x2
end_define

begin_define
define|#
directive|define
name|BWI_CLEAR_PHY_FLAGS
value|(BWI_PHY_F_CALIBRATED)
end_define

begin_comment
comment|/* TX power control */
end_comment

begin_struct
struct|struct
name|bwi_tpctl
block|{
name|uint16_t
name|bbp_atten
decl_stmt|;
comment|/* BBP attenuation: 4bits */
name|uint16_t
name|rf_atten
decl_stmt|;
comment|/* RF attenuation */
name|uint16_t
name|tp_ctrl1
decl_stmt|;
comment|/* ??: 3bits */
name|uint16_t
name|tp_ctrl2
decl_stmt|;
comment|/* ??: 4bits */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_RF_ATTEN_FACTOR
value|4
end_define

begin_define
define|#
directive|define
name|BWI_RF_ATTEN_MAX0
value|9
end_define

begin_define
define|#
directive|define
name|BWI_RF_ATTEN_MAX1
value|31
end_define

begin_define
define|#
directive|define
name|BWI_BBP_ATTEN_MAX
value|11
end_define

begin_define
define|#
directive|define
name|BWI_TPCTL1_MAX
value|7
end_define

begin_struct
struct|struct
name|bwi_rf_lo
block|{
name|int8_t
name|ctrl_lo
decl_stmt|;
name|int8_t
name|ctrl_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwi_rf
block|{
name|uint16_t
name|rf_type
decl_stmt|;
comment|/* BWI_RF_T_ */
name|uint16_t
name|rf_manu
decl_stmt|;
name|int
name|rf_rev
decl_stmt|;
name|uint32_t
name|rf_flags
decl_stmt|;
comment|/* BWI_RF_F_ */
define|#
directive|define
name|BWI_RFLO_MAX
value|56
name|struct
name|bwi_rf_lo
name|rf_lo
index|[
name|BWI_RFLO_MAX
index|]
decl_stmt|;
name|uint8_t
name|rf_lo_used
index|[
literal|8
index|]
decl_stmt|;
define|#
directive|define
name|BWI_INVALID_NRSSI
value|-1000
name|int16_t
name|rf_nrssi
index|[
literal|2
index|]
decl_stmt|;
comment|/* Narrow RSSI */
name|int32_t
name|rf_nrssi_slope
decl_stmt|;
define|#
directive|define
name|BWI_NRSSI_TBLSZ
value|64
name|int8_t
name|rf_nrssi_table
index|[
name|BWI_NRSSI_TBLSZ
index|]
decl_stmt|;
name|uint16_t
name|rf_lo_gain
decl_stmt|;
comment|/* loopback gain */
name|uint16_t
name|rf_rx_gain
decl_stmt|;
comment|/* TRSW RX gain */
name|uint16_t
name|rf_calib
decl_stmt|;
comment|/* RF calibration value */
name|u_int
name|rf_curchan
decl_stmt|;
comment|/* current channel */
name|uint16_t
name|rf_ctrl_rd
decl_stmt|;
name|int
name|rf_ctrl_adj
decl_stmt|;
name|void
function_decl|(
modifier|*
name|rf_off
function_decl|)
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rf_on
function_decl|)
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rf_set_nrssi_thr
function_decl|)
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rf_calc_nrssi_slope
function_decl|)
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rf_calc_rssi
function_decl|)
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
specifier|const
name|struct
name|bwi_rxbuf_hdr
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rf_calc_noise
function_decl|)
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rf_lo_update
function_decl|)
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|BWI_TSSI_MAX
value|64
name|int8_t
name|rf_txpower_map0
index|[
name|BWI_TSSI_MAX
index|]
decl_stmt|;
comment|/* Indexed by TSSI */
name|int
name|rf_idle_tssi0
decl_stmt|;
name|int8_t
name|rf_txpower_map
index|[
name|BWI_TSSI_MAX
index|]
decl_stmt|;
name|int
name|rf_idle_tssi
decl_stmt|;
name|int
name|rf_base_tssi
decl_stmt|;
name|int
name|rf_txpower_max
decl_stmt|;
comment|/* dBm */
name|int
name|rf_ant_mode
decl_stmt|;
comment|/* BWI_ANT_MODE_ */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_RF_F_INITED
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_RF_F_ON
value|0x2
end_define

begin_define
define|#
directive|define
name|BWI_RF_CLEAR_FLAGS
value|(BWI_RF_F_INITED)
end_define

begin_define
define|#
directive|define
name|BWI_ANT_MODE_0
value|0
end_define

begin_define
define|#
directive|define
name|BWI_ANT_MODE_1
value|1
end_define

begin_define
define|#
directive|define
name|BWI_ANT_MODE_UNKN
value|2
end_define

begin_define
define|#
directive|define
name|BWI_ANT_MODE_AUTO
value|3
end_define

begin_struct_decl
struct_decl|struct
name|bwi_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|firmware
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bwi_mac
block|{
name|struct
name|bwi_regwin
name|mac_regwin
decl_stmt|;
comment|/* MUST be first field */
define|#
directive|define
name|mac_rw_flags
value|mac_regwin.rw_flags
define|#
directive|define
name|mac_type
value|mac_regwin.rw_type
define|#
directive|define
name|mac_id
value|mac_regwin.rw_id
define|#
directive|define
name|mac_rev
value|mac_regwin.rw_rev
name|struct
name|bwi_softc
modifier|*
name|mac_sc
decl_stmt|;
name|struct
name|bwi_phy
name|mac_phy
decl_stmt|;
comment|/* PHY I/F */
name|struct
name|bwi_rf
name|mac_rf
decl_stmt|;
comment|/* RF I/F */
name|struct
name|bwi_tpctl
name|mac_tpctl
decl_stmt|;
comment|/* TX power control */
name|uint32_t
name|mac_flags
decl_stmt|;
comment|/* BWI_MAC_F_ */
specifier|const
name|struct
name|firmware
modifier|*
name|mac_stub
decl_stmt|;
specifier|const
name|struct
name|firmware
modifier|*
name|mac_ucode
decl_stmt|;
specifier|const
name|struct
name|firmware
modifier|*
name|mac_pcm
decl_stmt|;
specifier|const
name|struct
name|firmware
modifier|*
name|mac_iv
decl_stmt|;
specifier|const
name|struct
name|firmware
modifier|*
name|mac_iv_ext
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_MAC_F_BSWAP
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_MAC_F_TPCTL_INITED
value|0x2
end_define

begin_define
define|#
directive|define
name|BWI_MAC_F_HAS_TXSTATS
value|0x4
end_define

begin_define
define|#
directive|define
name|BWI_MAC_F_INITED
value|0x8
end_define

begin_define
define|#
directive|define
name|BWI_MAC_F_ENABLED
value|0x10
end_define

begin_define
define|#
directive|define
name|BWI_MAC_F_LOCKED
value|0x20
end_define

begin_comment
comment|/* for debug */
end_comment

begin_define
define|#
directive|define
name|BWI_MAC_F_TPCTL_ERROR
value|0x40
end_define

begin_define
define|#
directive|define
name|BWI_MAC_F_PHYE_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|BWI_CREATE_MAC
parameter_list|(
name|mac
parameter_list|,
name|sc
parameter_list|,
name|id
parameter_list|,
name|rev
parameter_list|)
define|\
value|do {						\ 	BWI_CREATE_REGWIN(&(mac)->mac_regwin,	\ 			  (id),			\ 			  BWI_REGWIN_T_MAC,	\ 			  (rev));		\ 	(mac)->mac_sc = (sc);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_MAX
value|2
end_define

begin_define
define|#
directive|define
name|BWI_LED_MAX
value|4
end_define

begin_enum
enum|enum
name|bwi_bus_space
block|{
name|BWI_BUS_SPACE_30BIT
init|=
literal|1
block|,
name|BWI_BUS_SPACE_32BIT
block|,
name|BWI_BUS_SPACE_64BIT
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|BWI_TX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) |	\ 	 (1<< IEEE80211_RADIOTAP_RATE) |	\ 	 (1<< IEEE80211_RADIOTAP_CHANNEL))
end_define

begin_struct
struct|struct
name|bwi_tx_radiotap_hdr
block|{
name|struct
name|ieee80211_radiotap_header
name|wt_ihdr
decl_stmt|;
name|uint8_t
name|wt_flags
decl_stmt|;
name|uint8_t
name|wt_rate
decl_stmt|;
name|uint16_t
name|wt_chan_freq
decl_stmt|;
name|uint16_t
name|wt_chan_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_RX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_TSFT) |		\ 	 (1<< IEEE80211_RADIOTAP_FLAGS) |		\ 	 (1<< IEEE80211_RADIOTAP_RATE) |		\ 	 (1<< IEEE80211_RADIOTAP_CHANNEL) |		\ 	 (1<< IEEE80211_RADIOTAP_DBM_ANTSIGNAL) |	\ 	 (1<< IEEE80211_RADIOTAP_DBM_ANTNOISE))
end_define

begin_struct
struct|struct
name|bwi_rx_radiotap_hdr
block|{
name|struct
name|ieee80211_radiotap_header
name|wr_ihdr
decl_stmt|;
name|uint64_t
name|wr_tsf
decl_stmt|;
name|uint8_t
name|wr_flags
decl_stmt|;
name|uint8_t
name|wr_rate
decl_stmt|;
name|uint16_t
name|wr_chan_freq
decl_stmt|;
name|uint16_t
name|wr_chan_flags
decl_stmt|;
name|int8_t
name|wr_antsignal
decl_stmt|;
name|int8_t
name|wr_antnoise
decl_stmt|;
comment|/* TODO: sq */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwi_node
block|{
name|struct
name|ieee80211_node
name|ni
decl_stmt|;
comment|/* must be the first */
name|struct
name|ieee80211_amrr_node
name|amn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_NODE
parameter_list|(
name|ni
parameter_list|)
value|((struct bwi_node *)(ni))
end_define

begin_struct
struct|struct
name|bwi_vap
block|{
name|struct
name|ieee80211vap
name|bv_vap
decl_stmt|;
name|struct
name|ieee80211_amrr
name|bv_amrr
decl_stmt|;
name|int
function_decl|(
modifier|*
name|bv_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct bwi_vap *)(vap))
end_define

begin_struct
struct|struct
name|bwi_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|uint32_t
name|sc_flags
decl_stmt|;
comment|/* BWI_F_ */
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|int
name|sc_invalid
decl_stmt|;
name|uint32_t
name|sc_cap
decl_stmt|;
comment|/* BWI_CAP_ */
name|uint16_t
name|sc_bbp_id
decl_stmt|;
comment|/* BWI_BBPID_ */
name|uint8_t
name|sc_bbp_rev
decl_stmt|;
name|uint8_t
name|sc_bbp_pkg
decl_stmt|;
name|uint8_t
name|sc_pci_revid
decl_stmt|;
name|uint16_t
name|sc_pci_did
decl_stmt|;
name|uint16_t
name|sc_pci_subvid
decl_stmt|;
name|uint16_t
name|sc_pci_subdid
decl_stmt|;
name|uint16_t
name|sc_card_flags
decl_stmt|;
comment|/* BWI_CARD_F_ */
name|uint16_t
name|sc_pwron_delay
decl_stmt|;
name|int
name|sc_locale
decl_stmt|;
name|int
name|sc_irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|void
modifier|*
name|sc_irq_handle
decl_stmt|;
name|int
name|sc_mem_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
decl_stmt|;
name|bus_space_tag_t
name|sc_mem_bt
decl_stmt|;
name|bus_space_handle_t
name|sc_mem_bh
decl_stmt|;
name|struct
name|callout
name|sc_calib_ch
decl_stmt|;
name|struct
name|callout
name|sc_watchdog_timer
decl_stmt|;
name|struct
name|bwi_regwin
modifier|*
name|sc_cur_regwin
decl_stmt|;
name|struct
name|bwi_regwin
name|sc_com_regwin
decl_stmt|;
name|struct
name|bwi_regwin
name|sc_bus_regwin
decl_stmt|;
name|int
name|sc_nmac
decl_stmt|;
name|struct
name|bwi_mac
name|sc_mac
index|[
name|BWI_MAC_MAX
index|]
decl_stmt|;
name|int
name|sc_rx_rate
decl_stmt|;
name|int
name|sc_tx_rate
decl_stmt|;
name|enum
name|bwi_txpwrcb_type
name|sc_txpwrcb_type
decl_stmt|;
name|int
name|sc_led_blinking
decl_stmt|;
name|int
name|sc_led_ticks
decl_stmt|;
name|struct
name|bwi_led
modifier|*
name|sc_blink_led
decl_stmt|;
name|struct
name|callout
name|sc_led_blink_ch
decl_stmt|;
name|int
name|sc_led_blink_offdur
decl_stmt|;
name|struct
name|bwi_led
name|sc_leds
index|[
name|BWI_LED_MAX
index|]
decl_stmt|;
name|enum
name|bwi_bus_space
name|sc_bus_space
decl_stmt|;
name|bus_dma_tag_t
name|sc_parent_dtag
decl_stmt|;
name|bus_dma_tag_t
name|sc_buf_dtag
decl_stmt|;
name|struct
name|bwi_txbuf_data
name|sc_tx_bdata
index|[
name|BWI_TX_NRING
index|]
decl_stmt|;
name|struct
name|bwi_rxbuf_data
name|sc_rx_bdata
decl_stmt|;
name|bus_dma_tag_t
name|sc_txring_dtag
decl_stmt|;
name|struct
name|bwi_ring_data
name|sc_tx_rdata
index|[
name|BWI_TX_NRING
index|]
decl_stmt|;
name|bus_dma_tag_t
name|sc_rxring_dtag
decl_stmt|;
name|struct
name|bwi_ring_data
name|sc_rx_rdata
decl_stmt|;
name|struct
name|bwi_txstats_data
modifier|*
name|sc_txstats
decl_stmt|;
name|int
name|sc_tx_timer
decl_stmt|;
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|sc_rates
decl_stmt|;
name|struct
name|bwi_tx_radiotap_hdr
name|sc_tx_th
decl_stmt|;
name|struct
name|bwi_rx_radiotap_hdr
name|sc_rx_th
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|sc_tq
decl_stmt|;
name|struct
name|task
name|sc_restart_task
decl_stmt|;
name|int
function_decl|(
modifier|*
name|sc_init_tx_ring
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_free_tx_ring
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_init_rx_ring
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_free_rx_ring
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_init_txstats
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_free_txstats
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_setup_rxdesc
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bus_addr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_rxeof
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_setup_txdesc
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|struct
name|bwi_ring_data
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bus_addr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_start_tx
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_txeof_status
function_decl|)
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* Sysctl variables */
name|int
name|sc_fw_version
decl_stmt|;
comment|/* BWI_FW_VERSION[34] */
name|int
name|sc_dwell_time
decl_stmt|;
comment|/* milliseconds */
name|int
name|sc_led_idle
decl_stmt|;
name|int
name|sc_led_blink
decl_stmt|;
name|int
name|sc_txpwr_calib
decl_stmt|;
name|uint32_t
name|sc_debug
decl_stmt|;
comment|/* BWI_DBG_ */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWI_F_BUS_INITED
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_F_PROMISC
value|0x2
end_define

begin_define
define|#
directive|define
name|BWI_F_STOP
value|0x4
end_define

begin_define
define|#
directive|define
name|BWI_DBG_MAC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWI_DBG_RF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWI_DBG_PHY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BWI_DBG_MISC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BWI_DBG_ATTACH
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BWI_DBG_INIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BWI_DBG_FIRMWARE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BWI_DBG_80211
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BWI_DBG_TXPOWER
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BWI_DBG_INTR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BWI_DBG_RX
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BWI_DBG_TX
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BWI_DBG_TXEOF
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BWI_DBG_LED
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BWI_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->sc_mtx, device_get_nameunit((sc)->sc_dev), \ 	    MTX_NETWORK_LOCK, MTX_DEF | MTX_RECURSE)
end_define

begin_define
define|#
directive|define
name|BWI_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BWI_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BWI_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BWI_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->sc_mtx, MA_OWNED)
end_define

begin_function_decl
name|int
name|bwi_attach
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_detach
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_suspend
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_resume
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_shutdown
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_bus_init
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|struct
name|bwi_mac
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|bwi_read_sprom
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_regwin_switch
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|struct
name|bwi_regwin
modifier|*
parameter_list|,
name|struct
name|bwi_regwin
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_regwin_is_enabled
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|struct
name|bwi_regwin
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_regwin_enable
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|struct
name|bwi_regwin
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_regwin_disable
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|struct
name|bwi_regwin
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|a
parameter_list|)
value|__builtin_abs(a)
end_define

begin_comment
comment|/* XXX does not belong here */
end_comment

begin_struct
struct|struct
name|ieee80211_ds_plcp_hdr
block|{
name|uint8_t
name|i_signal
decl_stmt|;
name|uint8_t
name|i_service
decl_stmt|;
name|uint16_t
name|i_length
decl_stmt|;
name|uint16_t
name|i_crc
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_BWIVAR_H */
end_comment

end_unit

