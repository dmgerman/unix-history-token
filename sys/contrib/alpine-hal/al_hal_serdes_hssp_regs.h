begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  *  @{  * @file   al_hal_serdes_regs.h  *  * @brief ... registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_SERDES_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_SERDES_REGS_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_plat_types.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* * Unit Registers */
struct|struct
name|serdes_gen
block|{
comment|/* [0x0] SerDes Registers Version */
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|rsrvd_0
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x10] SerDes register file address */
name|uint32_t
name|reg_addr
decl_stmt|;
comment|/* [0x14] SerDes register file data */
name|uint32_t
name|reg_data
decl_stmt|;
name|uint32_t
name|rsrvd_1
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x20] SerDes control */
name|uint32_t
name|ictl_multi_bist
decl_stmt|;
comment|/* [0x24] SerDes control */
name|uint32_t
name|ictl_pcs
decl_stmt|;
comment|/* [0x28] SerDes control */
name|uint32_t
name|ictl_pma
decl_stmt|;
name|uint32_t
name|rsrvd_2
decl_stmt|;
comment|/* [0x30] SerDes control */
name|uint32_t
name|ipd_multi_synth
decl_stmt|;
comment|/* [0x34] SerDes control */
name|uint32_t
name|irst
decl_stmt|;
comment|/* [0x38] SerDes control */
name|uint32_t
name|octl_multi_synthready
decl_stmt|;
comment|/* [0x3c] SerDes control */
name|uint32_t
name|octl_multi_synthstatus
decl_stmt|;
comment|/* [0x40] SerDes control */
name|uint32_t
name|clk_out
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|47
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|serdes_lane
block|{
name|uint32_t
name|rsrvd1
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x10] SerDes status */
name|uint32_t
name|octl_pma
decl_stmt|;
comment|/* [0x14] SerDes control */
name|uint32_t
name|ictl_multi_andme
decl_stmt|;
comment|/* [0x18] SerDes control */
name|uint32_t
name|ictl_multi_lb
decl_stmt|;
comment|/* [0x1c] SerDes control */
name|uint32_t
name|ictl_multi_rxbist
decl_stmt|;
comment|/* [0x20] SerDes control */
name|uint32_t
name|ictl_multi_txbist
decl_stmt|;
comment|/* [0x24] SerDes control */
name|uint32_t
name|ictl_multi
decl_stmt|;
comment|/* [0x28] SerDes control */
name|uint32_t
name|ictl_multi_rxeq
decl_stmt|;
comment|/* [0x2c] SerDes control */
name|uint32_t
name|ictl_multi_rxeq_l_low
decl_stmt|;
comment|/* [0x30] SerDes control */
name|uint32_t
name|ictl_multi_rxeq_l_high
decl_stmt|;
comment|/* [0x34] SerDes control */
name|uint32_t
name|ictl_multi_rxeyediag
decl_stmt|;
comment|/* [0x38] SerDes control */
name|uint32_t
name|ictl_multi_txdeemph
decl_stmt|;
comment|/* [0x3c] SerDes control */
name|uint32_t
name|ictl_multi_txmargin
decl_stmt|;
comment|/* [0x40] SerDes control */
name|uint32_t
name|ictl_multi_txswing
decl_stmt|;
comment|/* [0x44] SerDes control */
name|uint32_t
name|idat_multi
decl_stmt|;
comment|/* [0x48] SerDes control */
name|uint32_t
name|ipd_multi
decl_stmt|;
comment|/* [0x4c] SerDes control */
name|uint32_t
name|octl_multi_rxbist
decl_stmt|;
comment|/* [0x50] SerDes control */
name|uint32_t
name|octl_multi
decl_stmt|;
comment|/* [0x54] SerDes control */
name|uint32_t
name|octl_multi_rxeyediag
decl_stmt|;
comment|/* [0x58] SerDes control */
name|uint32_t
name|odat_multi_rxbist
decl_stmt|;
comment|/* [0x5c] SerDes control */
name|uint32_t
name|odat_multi_rxeq
decl_stmt|;
comment|/* [0x60] SerDes control */
name|uint32_t
name|multi_rx_dvalid
decl_stmt|;
comment|/* [0x64] SerDes control */
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_serdes_regs
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|serdes_gen
name|gen
decl_stmt|;
comment|/* [0x100] */
name|struct
name|serdes_lane
name|lane
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x200] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** version register ****/
comment|/*  Revision number (Minor) */
define|#
directive|define
name|SERDES_GEN_VERSION_RELEASE_NUM_MINOR_MASK
value|0x000000FF
define|#
directive|define
name|SERDES_GEN_VERSION_RELEASE_NUM_MINOR_SHIFT
value|0
comment|/*  Revision number (Major) */
define|#
directive|define
name|SERDES_GEN_VERSION_RELEASE_NUM_MAJOR_MASK
value|0x0000FF00
define|#
directive|define
name|SERDES_GEN_VERSION_RELEASE_NUM_MAJOR_SHIFT
value|8
comment|/*  Date of release */
define|#
directive|define
name|SERDES_GEN_VERSION_DATE_DAY_MASK
value|0x001F0000
define|#
directive|define
name|SERDES_GEN_VERSION_DATE_DAY_SHIFT
value|16
comment|/*  Month of release */
define|#
directive|define
name|SERDES_GEN_VERSION_DATA_MONTH_MASK
value|0x01E00000
define|#
directive|define
name|SERDES_GEN_VERSION_DATA_MONTH_SHIFT
value|21
comment|/* Year of release (starting from 2000) */
define|#
directive|define
name|SERDES_GEN_VERSION_DATE_YEAR_MASK
value|0x3E000000
define|#
directive|define
name|SERDES_GEN_VERSION_DATE_YEAR_SHIFT
value|25
comment|/*  Reserved */
define|#
directive|define
name|SERDES_GEN_VERSION_RESERVED_MASK
value|0xC0000000
define|#
directive|define
name|SERDES_GEN_VERSION_RESERVED_SHIFT
value|30
comment|/**** reg_addr register ****/
comment|/* Address value */
define|#
directive|define
name|SERDES_GEN_REG_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|SERDES_GEN_REG_ADDR_VAL_SHIFT
value|0
comment|/**** reg_data register ****/
comment|/* Data value */
define|#
directive|define
name|SERDES_GEN_REG_DATA_VAL_MASK
value|0x000000FF
define|#
directive|define
name|SERDES_GEN_REG_DATA_VAL_SHIFT
value|0
comment|/**** ICTL_MULTI_BIST register ****/
define|#
directive|define
name|SERDES_GEN_ICTL_MULTI_BIST_MODESEL_NT_MASK
value|0x00000007
define|#
directive|define
name|SERDES_GEN_ICTL_MULTI_BIST_MODESEL_NT_SHIFT
value|0
comment|/**** ICTL_PCS register ****/
define|#
directive|define
name|SERDES_GEN_ICTL_PCS_EN_NT
value|(1<< 0)
comment|/**** ICTL_PMA register ****/
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REF_SEL_NT_MASK
value|0x00000007
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REF_SEL_NT_SHIFT
value|0
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REF_SEL_NT_REF
define|\
value|(0<< (SERDES_GEN_ICTL_PMA_REF_SEL_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REF_SEL_NT_R2L
define|\
value|(3<< (SERDES_GEN_ICTL_PMA_REF_SEL_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REF_SEL_NT_L2R
define|\
value|(4<< (SERDES_GEN_ICTL_PMA_REF_SEL_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSRIGHT2LEFT_MODE_NT_MASK
value|0x00000070
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSRIGHT2LEFT_MODE_NT_SHIFT
value|4
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSRIGHT2LEFT_MODE_NT_0
define|\
value|(0<< (SERDES_GEN_ICTL_PMA_REFBUSRIGHT2LEFT_MODE_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSRIGHT2LEFT_MODE_NT_REF
define|\
value|(2<< (SERDES_GEN_ICTL_PMA_REFBUSRIGHT2LEFT_MODE_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSRIGHT2LEFT_MODE_NT_R2L
define|\
value|(3<< (SERDES_GEN_ICTL_PMA_REFBUSRIGHT2LEFT_MODE_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSLEFT2RIGHT_MODE_NT_MASK
value|0x00000700
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSLEFT2RIGHT_MODE_NT_SHIFT
value|8
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSLEFT2RIGHT_MODE_NT_0
define|\
value|(0<< (SERDES_GEN_ICTL_PMA_REFBUSLEFT2RIGHT_MODE_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSLEFT2RIGHT_MODE_NT_REF
define|\
value|(2<< (SERDES_GEN_ICTL_PMA_REFBUSLEFT2RIGHT_MODE_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_REFBUSLEFT2RIGHT_MODE_NT_L2R
define|\
value|(3<< (SERDES_GEN_ICTL_PMA_REFBUSLEFT2RIGHT_MODE_NT_SHIFT))
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_TXENABLE_A_SRC
value|(1<< 11)
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_TXENABLE_A_SRC_THIS
value|(0<< 11)
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_TXENABLE_A_SRC_MASTER
value|(1<< 11)
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_TXENABLE_A
value|(1<< 12)
define|#
directive|define
name|SERDES_GEN_ICTL_PMA_SYNTHCKBYPASSEN_NT
value|(1<< 13)
comment|/**** IPD_MULTI_SYNTH register ****/
define|#
directive|define
name|SERDES_GEN_IPD_MULTI_SYNTH_B
value|(1<< 0)
comment|/**** IRST register ****/
define|#
directive|define
name|SERDES_GEN_IRST_PIPE_RST_L3_B_A
value|(1<< 0)
define|#
directive|define
name|SERDES_GEN_IRST_PIPE_RST_L2_B_A
value|(1<< 1)
define|#
directive|define
name|SERDES_GEN_IRST_PIPE_RST_L1_B_A
value|(1<< 2)
define|#
directive|define
name|SERDES_GEN_IRST_PIPE_RST_L0_B_A
value|(1<< 3)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_TXRX_L3_B_A
value|(1<< 4)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_TXRX_L2_B_A
value|(1<< 5)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_TXRX_L1_B_A
value|(1<< 6)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_TXRX_L0_B_A
value|(1<< 7)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_SYNTH_B_A
value|(1<< 8)
define|#
directive|define
name|SERDES_GEN_IRST_POR_B_A
value|(1<< 12)
define|#
directive|define
name|SERDES_GEN_IRST_PIPE_RST_L3_B_A_SEL
value|(1<< 16)
define|#
directive|define
name|SERDES_GEN_IRST_PIPE_RST_L2_B_A_SEL
value|(1<< 17)
define|#
directive|define
name|SERDES_GEN_IRST_PIPE_RST_L1_B_A_SEL
value|(1<< 18)
define|#
directive|define
name|SERDES_GEN_IRST_PIPE_RST_L0_B_A_SEL
value|(1<< 19)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_TXRX_L3_B_A_SEL
value|(1<< 20)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_TXRX_L2_B_A_SEL
value|(1<< 21)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_TXRX_L1_B_A_SEL
value|(1<< 22)
define|#
directive|define
name|SERDES_GEN_IRST_MULTI_HARD_TXRX_L0_B_A_SEL
value|(1<< 23)
comment|/**** OCTL_MULTI_SYNTHREADY register ****/
define|#
directive|define
name|SERDES_GEN_OCTL_MULTI_SYNTHREADY_A
value|(1<< 0)
comment|/**** OCTL_MULTI_SYNTHSTATUS register ****/
define|#
directive|define
name|SERDES_GEN_OCTL_MULTI_SYNTHSTATUS_A
value|(1<< 0)
comment|/**** clk_out register ****/
define|#
directive|define
name|SERDES_GEN_CLK_OUT_SEL_MASK
value|0x0000003F
define|#
directive|define
name|SERDES_GEN_CLK_OUT_SEL_SHIFT
value|0
comment|/**** OCTL_PMA register ****/
define|#
directive|define
name|SERDES_LANE_OCTL_PMA_TXSTATUS_L_A
value|(1<< 0)
comment|/**** ICTL_MULTI_ANDME register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_ANDME_EN_L_A
value|(1<< 0)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_ANDME_EN_L_A_SEL
value|(1<< 1)
comment|/**** ICTL_MULTI_LB register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_LB_TX2RXIOTIMEDEN_L_NT
value|(1<< 0)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_LB_TX2RXBUFTIMEDEN_L_NT
value|(1<< 1)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_LB_RX2TXUNTIMEDEN_L_NT
value|(1<< 2)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_LB_PARRX2TXTIMEDEN_L_NT
value|(1<< 3)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_LB_CDRCLK2TXEN_L_NT
value|(1<< 4)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_LB_TX2RXBUFTIMEDEN_L_NT_SEL
value|(1<< 8)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_LB_RX2TXUNTIMEDEN_L_NT_SEL
value|(1<< 9)
comment|/**** ICTL_MULTI_RXBIST register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXBIST_EN_L_A
value|(1<< 0)
comment|/**** ICTL_MULTI_TXBIST register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXBIST_EN_L_A
value|(1<< 0)
comment|/**** ICTL_MULTI register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_PSTATE_L_MASK
value|0x00000003
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_PSTATE_L_SHIFT
value|0
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_PSTATE_L_SEL
value|(1<< 2)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXDATAWIDTH_L_MASK
value|0x00000070
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXDATAWIDTH_L_SHIFT
value|4
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXOVRCDRLOCK2DATAEN_L_A
value|(1<< 8)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXOVRCDRLOCK2DATA_L_A
value|(1<< 9)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXBEACON_L_A
value|(1<< 12)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDETECTRXREQ_L_A
value|(1<< 13)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXRATE_L_MASK
value|0x00070000
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXRATE_L_SHIFT
value|16
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXRATE_L_SEL
value|(1<< 19)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXRATE_L_MASK
value|0x00700000
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXRATE_L_SHIFT
value|20
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXRATE_L_SEL
value|(1<< 23)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXAMP_L_MASK
value|0x07000000
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXAMP_L_SHIFT
value|24
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXAMP_EN_L
value|(1<< 27)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDATAWIDTH_L_MASK
value|0x70000000
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDATAWIDTH_L_SHIFT
value|28
comment|/**** ICTL_MULTI_RXEQ register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXEQ_EN_L
value|(1<< 0)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXEQ_START_L_A
value|(1<< 1)
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXEQ_PRECAL_CODE_SEL_MASK
value|0x00000070
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXEQ_PRECAL_CODE_SEL_SHIFT
value|4
comment|/**** ICTL_MULTI_RXEQ_L_high register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXEQ_L_HIGH_VAL
value|(1<< 0)
comment|/**** ICTL_MULTI_RXEYEDIAG register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_RXEYEDIAG_START_L_A
value|(1<< 0)
comment|/**** ICTL_MULTI_TXDEEMPH register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDEEMPH_L_MASK
value|0x0003FFFF
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDEEMPH_L_SHIFT
value|0
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDEEMPH_C_ZERO_MASK
value|0x7c0
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDEEMPH_C_ZERO_SHIFT
value|6
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDEEMPH_C_PLUS_MASK
value|0xf000
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDEEMPH_C_PLUS_SHIFT
value|12
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDEEMPH_C_MINUS_MASK
value|0x7
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXDEEMPH_C_MINUS_SHIFT
value|0
comment|/**** ICTL_MULTI_TXMARGIN register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXMARGIN_L_MASK
value|0x00000007
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXMARGIN_L_SHIFT
value|0
comment|/**** ICTL_MULTI_TXSWING register ****/
define|#
directive|define
name|SERDES_LANE_ICTL_MULTI_TXSWING_L
value|(1<< 0)
comment|/**** IDAT_MULTI register ****/
define|#
directive|define
name|SERDES_LANE_IDAT_MULTI_TXELECIDLE_L_MASK
value|0x0000000F
define|#
directive|define
name|SERDES_LANE_IDAT_MULTI_TXELECIDLE_L_SHIFT
value|0
define|#
directive|define
name|SERDES_LANE_IDAT_MULTI_TXELECIDLE_L_SEL
value|(1<< 4)
comment|/**** IPD_MULTI register ****/
define|#
directive|define
name|SERDES_LANE_IPD_MULTI_TX_L_B
value|(1<< 0)
define|#
directive|define
name|SERDES_LANE_IPD_MULTI_RX_L_B
value|(1<< 1)
comment|/**** OCTL_MULTI_RXBIST register ****/
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXBIST_DONE_L_A
value|(1<< 0)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXBIST_RXLOCKED_L_A
value|(1<< 1)
comment|/**** OCTL_MULTI register ****/
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXCDRLOCK2DATA_L_A
value|(1<< 0)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXEQ_DONE_L_A
value|(1<< 1)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXREADY_L_A
value|(1<< 2)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXSTATUS_L_A
value|(1<< 3)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_TXREADY_L_A
value|(1<< 4)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_TXDETECTRXSTAT_L_A
value|(1<< 5)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_TXDETECTRXACK_L_A
value|(1<< 6)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXSIGNALDETECT_L_A
value|(1<< 7)
comment|/**** OCTL_MULTI_RXEYEDIAG register ****/
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXEYEDIAG_STAT_L_A_MASK
value|0x00003FFF
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXEYEDIAG_STAT_L_A_SHIFT
value|0
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXEYEDIAG_DONE_L_A
value|(1<< 16)
define|#
directive|define
name|SERDES_LANE_OCTL_MULTI_RXEYEDIAG_ERR_L_A
value|(1<< 17)
comment|/**** ODAT_MULTI_RXBIST register ****/
define|#
directive|define
name|SERDES_LANE_ODAT_MULTI_RXBIST_ERRCOUNT_L_A_MASK
value|0x0000FFFF
define|#
directive|define
name|SERDES_LANE_ODAT_MULTI_RXBIST_ERRCOUNT_L_A_SHIFT
value|0
define|#
directive|define
name|SERDES_LANE_ODAT_MULTI_RXBIST_ERRCOUNT_OVERFLOW_L_A
value|(1<< 16)
comment|/**** ODAT_MULTI_RXEQ register ****/
define|#
directive|define
name|SERDES_LANE_ODAT_MULTI_RXEQ_BEST_EYE_VAL_L_A_MASK
value|0x00003FFF
define|#
directive|define
name|SERDES_LANE_ODAT_MULTI_RXEQ_BEST_EYE_VAL_L_A_SHIFT
value|0
comment|/**** MULTI_RX_DVALID register ****/
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_MASK_CDR_LOCK
value|(1<< 0)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_MASK_SIGNALDETECT
value|(1<< 1)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_MASK_TX_READY
value|(1<< 2)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_MASK_RX_READY
value|(1<< 3)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_MASK_SYNT_READY
value|(1<< 4)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_MASK_RX_ELECIDLE
value|(1<< 5)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_MUX_SEL_MASK
value|0x00FF0000
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_MUX_SEL_SHIFT
value|16
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_PS_00_SEL
value|(1<< 24)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_PS_00_VAL
value|(1<< 25)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_PS_01_SEL
value|(1<< 26)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_PS_01_VAL
value|(1<< 27)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_PS_10_SEL
value|(1<< 28)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_PS_10_VAL
value|(1<< 29)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_PS_11_SEL
value|(1<< 30)
define|#
directive|define
name|SERDES_LANE_MULTI_RX_DVALID_PS_11_VAL
value|(1<< 31)
comment|/**** reserved register ****/
define|#
directive|define
name|SERDES_LANE_RESERVED_OUT_MASK
value|0x000000FF
define|#
directive|define
name|SERDES_LANE_RESERVED_OUT_SHIFT
value|0
define|#
directive|define
name|SERDES_LANE_RESERVED_IN_MASK
value|0x00FF0000
define|#
directive|define
name|SERDES_LANE_RESERVED_IN_SHIFT
value|16
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_serdes_REGS_H__ */
end_comment

begin_comment
comment|/** @} end of ... group */
end_comment

end_unit

