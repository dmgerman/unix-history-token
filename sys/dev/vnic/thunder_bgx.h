begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2015 Cavium Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|THUNDER_BGX_H
end_ifndef

begin_define
define|#
directive|define
name|THUNDER_BGX_H
end_define

begin_define
define|#
directive|define
name|MAX_BGX_THUNDER
value|8
end_define

begin_comment
comment|/* Max 4 nodes, 2 per node */
end_comment

begin_define
define|#
directive|define
name|MAX_BGX_PER_CN88XX
value|2
end_define

begin_define
define|#
directive|define
name|MAX_LMAC_PER_BGX
value|4
end_define

begin_define
define|#
directive|define
name|MAX_BGX_CHANS_PER_LMAC
value|16
end_define

begin_define
define|#
directive|define
name|MAX_DMAC_PER_LMAC
value|8
end_define

begin_define
define|#
directive|define
name|MAX_FRAME_SIZE
value|9216
end_define

begin_define
define|#
directive|define
name|MAX_DMAC_PER_LMAC_TNS_BYPASS_MODE
value|2
end_define

begin_define
define|#
directive|define
name|MAX_LMAC
value|(MAX_BGX_PER_CN88XX * MAX_LMAC_PER_BGX)
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|BGX_CMRX_CFG
value|0x00
end_define

begin_define
define|#
directive|define
name|CMR_PKT_TX_EN
value|(1UL<< 13)
end_define

begin_define
define|#
directive|define
name|CMR_PKT_RX_EN
value|(1UL<< 14)
end_define

begin_define
define|#
directive|define
name|CMR_EN
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|BGX_CMR_GLOBAL_CFG
value|0x08
end_define

begin_define
define|#
directive|define
name|CMR_GLOBAL_CFG_FCS_STRIP
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_ID_MAP
value|0x60
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT0
value|0x70
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT1
value|0x78
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT2
value|0x80
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT3
value|0x88
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT4
value|0x90
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT5
value|0x98
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT6
value|0xA0
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT7
value|0xA8
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT8
value|0xB0
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT9
value|0xB8
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_STAT10
value|0xC0
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_BP_DROP
value|0xC8
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_RX_DMAC_CTL
value|0x0E8
end_define

begin_define
define|#
directive|define
name|BGX_CMR_RX_DMACX_CAM
value|0x200
end_define

begin_define
define|#
directive|define
name|RX_DMACX_CAM_EN
value|(1UL<< 48)
end_define

begin_define
define|#
directive|define
name|RX_DMACX_CAM_LMACID
parameter_list|(
name|x
parameter_list|)
value|(x<< 49)
end_define

begin_define
define|#
directive|define
name|RX_DMAC_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|BGX_CMR_RX_STREERING
value|0x300
end_define

begin_define
define|#
directive|define
name|RX_TRAFFIC_STEER_RULE_COUNT
value|8
end_define

begin_define
define|#
directive|define
name|BGX_CMR_CHAN_MSK_AND
value|0x450
end_define

begin_define
define|#
directive|define
name|BGX_CMR_BIST_STATUS
value|0x460
end_define

begin_define
define|#
directive|define
name|BGX_CMR_RX_LMACS
value|0x468
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT0
value|0x600
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT1
value|0x608
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT2
value|0x610
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT3
value|0x618
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT4
value|0x620
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT5
value|0x628
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT6
value|0x630
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT7
value|0x638
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT8
value|0x640
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT9
value|0x648
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT10
value|0x650
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT11
value|0x658
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT12
value|0x660
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT13
value|0x668
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT14
value|0x670
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT15
value|0x678
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT16
value|0x680
end_define

begin_define
define|#
directive|define
name|BGX_CMRX_TX_STAT17
value|0x688
end_define

begin_define
define|#
directive|define
name|BGX_CMR_TX_LMACS
value|0x1000
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_CONTROL1
value|0x10000
end_define

begin_define
define|#
directive|define
name|SPU_CTL_LOW_POWER
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|SPU_CTL_LOOPBACK
value|(1UL<< 14)
end_define

begin_define
define|#
directive|define
name|SPU_CTL_RESET
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_STATUS1
value|0x10008
end_define

begin_define
define|#
directive|define
name|SPU_STATUS1_RCV_LNK
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_STATUS2
value|0x10020
end_define

begin_define
define|#
directive|define
name|SPU_STATUS2_RCVFLT
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_BX_STATUS
value|0x10028
end_define

begin_define
define|#
directive|define
name|SPU_BX_STATUS_RX_ALIGN
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_BR_STATUS1
value|0x10030
end_define

begin_define
define|#
directive|define
name|SPU_BR_STATUS_BLK_LOCK
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|SPU_BR_STATUS_RCV_LNK
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_BR_PMD_CRTL
value|0x10068
end_define

begin_define
define|#
directive|define
name|SPU_PMD_CRTL_TRAIN_EN
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_BR_PMD_LP_CUP
value|0x10078
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_BR_PMD_LD_CUP
value|0x10088
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_BR_PMD_LD_REP
value|0x10090
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_FEC_CONTROL
value|0x100A0
end_define

begin_define
define|#
directive|define
name|SPU_FEC_CTL_FEC_EN
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|SPU_FEC_CTL_ERR_EN
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_AN_CONTROL
value|0x100C8
end_define

begin_define
define|#
directive|define
name|SPU_AN_CTL_AN_EN
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|SPU_AN_CTL_XNP_EN
value|(1UL<< 13)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_AN_ADV
value|0x100D8
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_MISC_CONTROL
value|0x10218
end_define

begin_define
define|#
directive|define
name|SPU_MISC_CTL_INTLV_RDISP
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|SPU_MISC_CTL_RX_DIS
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_INT
value|0x10220
end_define

begin_comment
comment|/* +(0..3)<< 20 */
end_comment

begin_define
define|#
directive|define
name|BGX_SPUX_INT_W1S
value|0x10228
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_INT_ENA_W1C
value|0x10230
end_define

begin_define
define|#
directive|define
name|BGX_SPUX_INT_ENA_W1S
value|0x10238
end_define

begin_define
define|#
directive|define
name|BGX_SPU_DBG_CONTROL
value|0x10300
end_define

begin_define
define|#
directive|define
name|SPU_DBG_CTL_AN_ARB_LINK_CHK_EN
value|(1UL<< 18)
end_define

begin_define
define|#
directive|define
name|SPU_DBG_CTL_AN_NONCE_MCT_DIS
value|(1UL<< 29)
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_RX_INT
value|0x20000
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_RX_JABBER
value|0x20030
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_RX_CTL
value|0x20048
end_define

begin_define
define|#
directive|define
name|SMU_RX_CTL_STATUS
value|(3UL<< 0)
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_TX_APPEND
value|0x20100
end_define

begin_define
define|#
directive|define
name|SMU_TX_APPEND_FCS_D
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_TX_MIN_PKT
value|0x20118
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_TX_INT
value|0x20140
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_TX_CTL
value|0x20178
end_define

begin_define
define|#
directive|define
name|SMU_TX_CTL_DIC_EN
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|SMU_TX_CTL_UNI_EN
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|SMU_TX_CTL_LNK_STATUS
value|(3UL<< 4)
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_TX_THRESH
value|0x20180
end_define

begin_define
define|#
directive|define
name|BGX_SMUX_CTL
value|0x20200
end_define

begin_define
define|#
directive|define
name|SMU_CTL_RX_IDLE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|SMU_CTL_TX_IDLE
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|BGX_GMP_PCS_MRX_CTL
value|0x30000
end_define

begin_define
define|#
directive|define
name|PCS_MRX_CTL_RST_AN
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|PCS_MRX_CTL_PWR_DN
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|PCS_MRX_CTL_AN_EN
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|PCS_MRX_CTL_LOOPBACK1
value|(1UL<< 14)
end_define

begin_define
define|#
directive|define
name|PCS_MRX_CTL_RESET
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|BGX_GMP_PCS_MRX_STATUS
value|0x30008
end_define

begin_define
define|#
directive|define
name|PCS_MRX_STATUS_AN_CPT
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|BGX_GMP_PCS_ANX_AN_RESULTS
value|0x30020
end_define

begin_define
define|#
directive|define
name|BGX_GMP_PCS_SGM_AN_ADV
value|0x30068
end_define

begin_define
define|#
directive|define
name|BGX_GMP_PCS_MISCX_CTL
value|0x30078
end_define

begin_define
define|#
directive|define
name|PCS_MISC_CTL_GMX_ENO
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|PCS_MISC_CTL_SAMP_PT_MASK
value|0x7FUL
end_define

begin_define
define|#
directive|define
name|BGX_GMP_GMI_PRTX_CFG
value|0x38020
end_define

begin_define
define|#
directive|define
name|GMI_PORT_CFG_SPEED
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|GMI_PORT_CFG_DUPLEX
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|GMI_PORT_CFG_SLOT_TIME
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|GMI_PORT_CFG_SPEED_MSB
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|BGX_GMP_GMI_RXX_JABBER
value|0x38038
end_define

begin_define
define|#
directive|define
name|BGX_GMP_GMI_TXX_THRESH
value|0x38210
end_define

begin_define
define|#
directive|define
name|BGX_GMP_GMI_TXX_APPEND
value|0x38218
end_define

begin_define
define|#
directive|define
name|BGX_GMP_GMI_TXX_SLOT
value|0x38220
end_define

begin_define
define|#
directive|define
name|BGX_GMP_GMI_TXX_BURST
value|0x38228
end_define

begin_define
define|#
directive|define
name|BGX_GMP_GMI_TXX_MIN_PKT
value|0x38240
end_define

begin_define
define|#
directive|define
name|BGX_GMP_GMI_TXX_SGMII_CTL
value|0x38300
end_define

begin_define
define|#
directive|define
name|BGX_MSIX_VEC_0_29_ADDR
value|0x400000
end_define

begin_comment
comment|/* +(0..29)<< 4 */
end_comment

begin_define
define|#
directive|define
name|BGX_MSIX_VEC_0_29_CTL
value|0x400008
end_define

begin_define
define|#
directive|define
name|BGX_MSIX_PBA_0
value|0x4F0000
end_define

begin_comment
comment|/* MSI-X interrupts */
end_comment

begin_define
define|#
directive|define
name|BGX_MSIX_VECTORS
value|30
end_define

begin_define
define|#
directive|define
name|BGX_LMAC_VEC_OFFSET
value|7
end_define

begin_define
define|#
directive|define
name|BGX_MSIX_VEC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|CMRX_INT
value|0
end_define

begin_define
define|#
directive|define
name|SPUX_INT
value|1
end_define

begin_define
define|#
directive|define
name|SMUX_RX_INT
value|2
end_define

begin_define
define|#
directive|define
name|SMUX_TX_INT
value|3
end_define

begin_define
define|#
directive|define
name|GMPX_PCS_INT
value|4
end_define

begin_define
define|#
directive|define
name|GMPX_GMI_RX_INT
value|5
end_define

begin_define
define|#
directive|define
name|GMPX_GMI_TX_INT
value|6
end_define

begin_define
define|#
directive|define
name|CMR_MEM_INT
value|28
end_define

begin_define
define|#
directive|define
name|SPU_MEM_INT
value|29
end_define

begin_define
define|#
directive|define
name|LMAC_INTR_LINK_UP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LMAC_INTR_LINK_DOWN
value|(1<< 1)
end_define

begin_comment
comment|/*  RX_DMAC_CTL configuration*/
end_comment

begin_enum
enum|enum
name|MCAST_MODE
block|{
name|MCAST_MODE_REJECT
block|,
name|MCAST_MODE_ACCEPT
block|,
name|MCAST_MODE_CAM_FILTER
block|,
name|RSVD
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|BCAST_ACCEPT
value|1
end_define

begin_define
define|#
directive|define
name|CAM_ACCEPT
value|1
end_define

begin_function_decl
name|void
name|octeon_mdiobus_force_mod_depencency
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bgx_add_dmac_addr
parameter_list|(
name|uint64_t
name|dmac
parameter_list|,
name|int
name|node
parameter_list|,
name|int
name|bgx_idx
parameter_list|,
name|int
name|lmac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|bgx_get_map
parameter_list|(
name|int
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bgx_get_lmac_count
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|bgx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|uint8_t
modifier|*
name|bgx_get_lmac_mac
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|bgx_idx
parameter_list|,
name|int
name|lmacid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bgx_set_lmac_mac
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|bgx_idx
parameter_list|,
name|int
name|lmacid
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bgx_get_lmac_link_state
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|bgx_idx
parameter_list|,
name|int
name|lmacid
parameter_list|,
name|void
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bgx_lmac_internal_loopback
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|bgx_idx
parameter_list|,
name|int
name|lmac_idx
parameter_list|,
name|boolean_t
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|bgx_get_rx_stats
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|bgx_idx
parameter_list|,
name|int
name|lmac
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|bgx_get_tx_stats
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|bgx_idx
parameter_list|,
name|int
name|lmac
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BGX_RX_STATS_COUNT
value|11
end_define

begin_define
define|#
directive|define
name|BGX_TX_STATS_COUNT
value|18
end_define

begin_struct
struct|struct
name|bgx_stats
block|{
name|uint64_t
name|rx_stats
index|[
name|BGX_RX_STATS_COUNT
index|]
decl_stmt|;
name|uint64_t
name|tx_stats
index|[
name|BGX_TX_STATS_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BGX_IN_PROMISCUOUS_MODE
value|1
end_define

begin_enum
enum|enum
name|LMAC_TYPE
block|{
name|BGX_MODE_SGMII
init|=
literal|0
block|,
comment|/* 1 lane, 1.250 Gbaud */
name|BGX_MODE_XAUI
init|=
literal|1
block|,
comment|/* 4 lanes, 3.125 Gbaud */
name|BGX_MODE_DXAUI
init|=
literal|1
block|,
comment|/* 4 lanes, 6.250 Gbaud */
name|BGX_MODE_RXAUI
init|=
literal|2
block|,
comment|/* 2 lanes, 6.250 Gbaud */
name|BGX_MODE_XFI
init|=
literal|3
block|,
comment|/* 1 lane, 10.3125 Gbaud */
name|BGX_MODE_XLAUI
init|=
literal|4
block|,
comment|/* 4 lanes, 10.3125 Gbaud */
name|BGX_MODE_10G_KR
init|=
literal|3
block|,
comment|/* 1 lane, 10.3125 Gbaud */
name|BGX_MODE_40G_KR
init|=
literal|4
block|,
comment|/* 4 lanes, 10.3125 Gbaud */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|qlm_mode
block|{
name|QLM_MODE_SGMII
block|,
comment|/* SGMII, each lane independent */
name|QLM_MODE_XAUI_1X4
block|,
comment|/* 1 XAUI or DXAUI, 4 lanes */
name|QLM_MODE_RXAUI_2X2
block|,
comment|/* 2 RXAUI, 2 lanes each */
name|QLM_MODE_XFI_4X1
block|,
comment|/* 4 XFI, 1 lane each */
name|QLM_MODE_XLAUI_1X4
block|,
comment|/* 1 XLAUI, 4 lanes each */
name|QLM_MODE_10G_KR_4X1
block|,
comment|/* 4 10GBASE-KR, 1 lane each */
name|QLM_MODE_40G_KR4_1X4
block|,
comment|/* 1 40GBASE-KR4, 4 lanes each */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* THUNDER_BGX_H */
end_comment

end_unit

