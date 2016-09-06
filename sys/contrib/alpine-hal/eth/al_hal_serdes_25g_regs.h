begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* Copyright (C) 2013 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 or V3 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, 	  this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright 	  notice, this list of conditions and the following disclaimer in 	  the documentation and/or other materials provided with the 	  distribution.   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  *  @{  * @file   al_hal_serdes_c_regs.h  *  * @brief ... registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_serdes_c_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_serdes_c_REGS_H__
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
name|al_serdes_c_gen
block|{
comment|/* [0x0] SERDES registers Version */
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|rsrvd_0
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x10] SERDES register file address */
name|uint32_t
name|reg_addr
decl_stmt|;
comment|/* [0x14] SERDES register file data */
name|uint32_t
name|reg_data
decl_stmt|;
comment|/* [0x18] SERDES control */
name|uint32_t
name|ctrl
decl_stmt|;
comment|/* [0x1c] SERDES cpu mem address */
name|uint32_t
name|cpu_prog_addr
decl_stmt|;
comment|/* [0x20] SERDES cpu mem data */
name|uint32_t
name|cpu_prog_data
decl_stmt|;
comment|/* [0x24] SERDES data mem address */
name|uint32_t
name|cpu_data_mem_addr
decl_stmt|;
comment|/* [0x28] SERDES data mem data */
name|uint32_t
name|cpu_data_mem_data
decl_stmt|;
comment|/* [0x2c] SERDES control */
name|uint32_t
name|rst
decl_stmt|;
comment|/* [0x30] SERDES control */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|51
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_serdes_c_lane
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x10] Data configuration */
name|uint32_t
name|cfg
decl_stmt|;
comment|/* [0x14] Lane status */
name|uint32_t
name|stat
decl_stmt|;
comment|/* [0x18] SERDES control */
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|25
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_serdes_c_regs
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|al_serdes_c_gen
name|gen
decl_stmt|;
comment|/* [0x100] */
name|struct
name|al_serdes_c_lane
name|lane
index|[
literal|2
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
name|SERDES_C_GEN_VERSION_RELEASE_NUM_MINOR_MASK
value|0x000000FF
define|#
directive|define
name|SERDES_C_GEN_VERSION_RELEASE_NUM_MINOR_SHIFT
value|0
comment|/*  Revision number (Major) */
define|#
directive|define
name|SERDES_C_GEN_VERSION_RELEASE_NUM_MAJOR_MASK
value|0x0000FF00
define|#
directive|define
name|SERDES_C_GEN_VERSION_RELEASE_NUM_MAJOR_SHIFT
value|8
comment|/*  date of release */
define|#
directive|define
name|SERDES_C_GEN_VERSION_DATE_DAY_MASK
value|0x001F0000
define|#
directive|define
name|SERDES_C_GEN_VERSION_DATE_DAY_SHIFT
value|16
comment|/*  month of release */
define|#
directive|define
name|SERDES_C_GEN_VERSION_DATA_MONTH_MASK
value|0x01E00000
define|#
directive|define
name|SERDES_C_GEN_VERSION_DATA_MONTH_SHIFT
value|21
comment|/*  year of release (starting from 2000) */
define|#
directive|define
name|SERDES_C_GEN_VERSION_DATE_YEAR_MASK
value|0x3E000000
define|#
directive|define
name|SERDES_C_GEN_VERSION_DATE_YEAR_SHIFT
value|25
comment|/*  Reserved */
define|#
directive|define
name|SERDES_C_GEN_VERSION_RESERVED_MASK
value|0xC0000000
define|#
directive|define
name|SERDES_C_GEN_VERSION_RESERVED_SHIFT
value|30
comment|/**** reg_addr register ****/
comment|/* address value */
define|#
directive|define
name|SERDES_C_GEN_REG_ADDR_VAL_MASK
value|0x00007FFF
define|#
directive|define
name|SERDES_C_GEN_REG_ADDR_VAL_SHIFT
value|0
comment|/**** reg_data register ****/
comment|/* data value */
define|#
directive|define
name|SERDES_C_GEN_REG_DATA_VAL_MASK
value|0x000000FF
define|#
directive|define
name|SERDES_C_GEN_REG_DATA_VAL_SHIFT
value|0
comment|/* Bit-wise write enable */
define|#
directive|define
name|SERDES_C_GEN_REG_DATA_STRB_MASK
value|0x0000FF00
define|#
directive|define
name|SERDES_C_GEN_REG_DATA_STRB_SHIFT
value|8
comment|/**** ctrl register ****/
comment|/*  * 0x0 â Select reference clock from Bump  * 0x1 â Select inter-macro reference clock from the left side  * 0x2 â Same as 0x0  * 0x3 â Select inter-macro reference clock from the right side  */
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_INPUT_SEL_MASK
value|0x00000003
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_INPUT_SEL_SHIFT
value|0
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_INPUT_SEL_REF
define|\
value|(0<< (SERDES_C_GEN_CTRL_REFCLK_INPUT_SEL_SHIFT))
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_INPUT_SEL_L2R
define|\
value|(1<< (SERDES_C_GEN_CTRL_REFCLK_INPUT_SEL_SHIFT))
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_INPUT_SEL_R2L
define|\
value|(3<< (SERDES_C_GEN_CTRL_REFCLK_INPUT_SEL_SHIFT))
comment|/*  * 0x0 â Tied to 0 to save power  * 0x1 â Select reference clock from Bump  * 0x2 â Select inter-macro reference clock input from right side  * 0x3 â Same as 0x2  */
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_LEFT_SEL_MASK
value|0x00000030
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_LEFT_SEL_SHIFT
value|4
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_LEFT_SEL_0
define|\
value|(0<< (SERDES_C_GEN_CTRL_REFCLK_LEFT_SEL_SHIFT))
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_LEFT_SEL_REF
define|\
value|(1<< (SERDES_C_GEN_CTRL_REFCLK_LEFT_SEL_SHIFT))
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_LEFT_SEL_R2L
define|\
value|(2<< (SERDES_C_GEN_CTRL_REFCLK_LEFT_SEL_SHIFT))
comment|/*  * 0x0 â Tied to 0 to save power  * 0x1 â Select reference clock from Bump  * 0x2 â Select inter-macro reference clock input from left side  * 0x3 â Same as 0x2  */
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_RIGHT_SEL_MASK
value|0x000000C0
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_RIGHT_SEL_SHIFT
value|6
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_RIGHT_SEL_0
define|\
value|(0<< (SERDES_C_GEN_CTRL_REFCLK_RIGHT_SEL_SHIFT))
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_RIGHT_SEL_REF
define|\
value|(1<< (SERDES_C_GEN_CTRL_REFCLK_RIGHT_SEL_SHIFT))
define|#
directive|define
name|SERDES_C_GEN_CTRL_REFCLK_RIGHT_SEL_L2R
define|\
value|(2<< (SERDES_C_GEN_CTRL_REFCLK_RIGHT_SEL_SHIFT))
comment|/*  * Program memory acknowledge -  Only when the access  * to the program memory is not  * ready for the microcontroller, it  * is driven to 0  */
define|#
directive|define
name|SERDES_C_GEN_CTRL_CPU_MEMPSACK
value|(1<< 8)
comment|/*  * Data memory acknowledge -  Only when the access  * to the program memory is not  * ready for the microcontroller, it  * is driven to 0  */
define|#
directive|define
name|SERDES_C_GEN_CTRL_CPU_MEMACK
value|(1<< 12)
comment|/*  * 0 - keep cpu clk as sb clk  * 1 â cpu_clk is sb_clk divided by 2  */
define|#
directive|define
name|SERDES_C_GEN_CTRL_CPU_CLK_DIV
value|(1<< 16)
comment|/*  * 0x0 â OIF CEI-28G-SR  * 0x1 â OIF CIE-25G-LR  * 0x8 â XFI  * Others â Reserved  *  * Note that phy_ctrl_cfg_i[3] is used to signify high-speed/low-speed  */
define|#
directive|define
name|SERDES_C_GEN_CTRL_PHY_CTRL_CFG_MASK
value|0x00F00000
define|#
directive|define
name|SERDES_C_GEN_CTRL_PHY_CTRL_CFG_SHIFT
value|20
comment|/*  * 0 - Internal 8051 micro- controller is allowed to access the internal APB  * CSR. Internal APB runs at cpu_clk_i, and the accesses from the external APB  * in apb_clk_i domain to APB CSR are resynchronized to cpu_clk_i. 1 â Bypass  * CPU. Internal 8051 micro-controller is blocked from accessing the internal  * APB CSR. Internal APB runs at apb_clk_i.  */
define|#
directive|define
name|SERDES_C_GEN_CTRL_CPU_BYPASS
value|(1<< 24)
comment|/**** cpu_prog_addr register ****/
comment|/*  * address value 32 bit,  * The firmware data will be 1 byte with 64K rows  */
define|#
directive|define
name|SERDES_C_GEN_CPU_PROG_ADDR_VAL_MASK
value|0x00007FFF
define|#
directive|define
name|SERDES_C_GEN_CPU_PROG_ADDR_VAL_SHIFT
value|0
comment|/**** cpu_data_mem_addr register ****/
comment|/* address value â 8K byte memory */
define|#
directive|define
name|SERDES_C_GEN_CPU_DATA_MEM_ADDR_VAL_MASK
value|0x00001FFF
define|#
directive|define
name|SERDES_C_GEN_CPU_DATA_MEM_ADDR_VAL_SHIFT
value|0
comment|/**** cpu_data_mem_data register ****/
comment|/* data value */
define|#
directive|define
name|SERDES_C_GEN_CPU_DATA_MEM_DATA_VAL_MASK
value|0x000000FF
define|#
directive|define
name|SERDES_C_GEN_CPU_DATA_MEM_DATA_VAL_SHIFT
value|0
comment|/**** rst register ****/
comment|/* Power on reset Signal  â active low */
define|#
directive|define
name|SERDES_C_GEN_RST_POR_N
value|(1<< 0)
comment|/* CMU reset   Active low */
define|#
directive|define
name|SERDES_C_GEN_RST_CM0_RST_N
value|(1<< 1)
comment|/*  * 0x0 â Normal / Active  * 0x1 â Partial power down  * 0x2 â Near complete power down (only  * refclk buffers and portions of analog bias  * active)  * 0x3 â complete power down (IDDQ mode)  * Can be asserted when CMU is in normal  * mode.  These modes provide an increased  * power savings compared to reset mode.  * Signal is overridden by por_n_i so has no  * effect in power on reset state.  */
define|#
directive|define
name|SERDES_C_GEN_RST_CM0_PD_MASK
value|0x00000030
define|#
directive|define
name|SERDES_C_GEN_RST_CM0_PD_SHIFT
value|4
comment|/* Lane0 reset signal  active low */
define|#
directive|define
name|SERDES_C_GEN_RST_LN0_RST_N
value|(1<< 6)
comment|/* Lane1 reset signal  active low */
define|#
directive|define
name|SERDES_C_GEN_RST_LN1_RST_N
value|(1<< 7)
comment|/*  * 0x0 â Normal / Active  * 0x1 â Partial power down  * 0x2 â Most blocks powered down (only LOS  * active)  * 0x3 â complete power down (IDDQ mode)  * Can be asserted when Lane is in normal  * mode.  These modes provide an increased  * power savings compared to reset mode.  * Signal is overridden by por_n_i so has no  * affect in power on reset state  */
define|#
directive|define
name|SERDES_C_GEN_RST_LN0_PD_MASK
value|0x00000300
define|#
directive|define
name|SERDES_C_GEN_RST_LN0_PD_SHIFT
value|8
comment|/*  * 0x0 â Normal / Active  * 0x1 â Partial power down  * 0x2 â Most blocks powered down (only LOS  * active)  * 0x3 â complete power down (IDDQ mode)  * Can be asserted when Lane is in normal  * mode.  These modes provide an increased  * power savings compared to reset mode.  * Signal is overridden by por_n_i so has no  * affect in power on reset state  */
define|#
directive|define
name|SERDES_C_GEN_RST_LN1_PD_MASK
value|0x00000C00
define|#
directive|define
name|SERDES_C_GEN_RST_LN1_PD_SHIFT
value|10
define|#
directive|define
name|SERDES_C_GEN_RST_CPU_MEM_RESET
value|(1<< 12)
define|#
directive|define
name|SERDES_C_GEN_RST_CPU_MEM_SHUTDOWN
value|(1<< 13)
define|#
directive|define
name|SERDES_C_GEN_RST_CAPRI_APB_RESET
value|(1<< 14)
comment|/**** status register ****/
comment|/*  * 0x0 â No error  * 0x1 â PHY has an internal error  */
define|#
directive|define
name|SERDES_C_GEN_STATUS_ERR_O
value|(1<< 0)
comment|/*  * 0x0 â PHY is not ready to respond to  * cm0_rst_n_i and cm0_pd_i[1:0]. The  * signals should not be changed.  * 0x1 - PHY is ready to respond to  * cm0_rst_n_i and cm0_pd_i[1:0]  */
define|#
directive|define
name|SERDES_C_GEN_STATUS_CM0_RST_PD_READY
value|(1<< 1)
comment|/*  * Indicates CMU PLL has locked to the  * reference clock and all output clocks are at  * the correct frequency  */
define|#
directive|define
name|SERDES_C_GEN_STATUS_CM0_OK_O
value|(1<< 2)
comment|/*  * 0x0 â PHY is not ready to respond to  * ln0_rst_n and ln0_pd[1:0]. The signals  * should not be changed.  * 0x1 - PHY is ready to respond to lnX_rst_n_i  * and lnX_pd_i[1:0]  */
define|#
directive|define
name|SERDES_C_GEN_STATUS_LN0_RST_PD_READY
value|(1<< 3)
comment|/*  * 0x0 â PHY is not ready to respond to  * ln1_rst_n_i and ln1_pd[1:0]. The signals  * should not be changed.  * 0x1 - PHY is ready to respond to lnX_rst_n_i  * and lnX_pd_i[1:0]  */
define|#
directive|define
name|SERDES_C_GEN_STATUS_LN1_RST_PD_READY
value|(1<< 4)
comment|/*  * Active low when the CPU performs a wait cycle (internally or externally  * generated)  */
define|#
directive|define
name|SERDES_C_GEN_STATUS_CPU_WAITSTATE
value|(1<< 5)
define|#
directive|define
name|SERDES_C_GEN_STATUS_TBUS_MASK
value|0x000FFF00
define|#
directive|define
name|SERDES_C_GEN_STATUS_TBUS_SHIFT
value|8
comment|/**** cfg register ****/
comment|/* 1- Swap 32 bit data on RX side */
define|#
directive|define
name|SERDES_C_LANE_CFG_RX_LANE_SWAP
value|(1<< 0)
comment|/* 1- Swap 32 bit data on TX side */
define|#
directive|define
name|SERDES_C_LANE_CFG_TX_LANE_SWAP
value|(1<< 1)
comment|/* 1 â invert rx data polarity */
define|#
directive|define
name|SERDES_C_LANE_CFG_LN_CTRL_RXPOLARITY
value|(1<< 2)
comment|/* 1 â invert tx data polarity */
define|#
directive|define
name|SERDES_C_LANE_CFG_TX_LANE_POLARITY
value|(1<< 3)
comment|/*  * 0x0 âData on lnX_txdata_o will not be  * transmitted. Transmitter will be placed into  * electrical idle.  * 0x1 â Data on the active bits of  * lnX_txdata_o will be transmitted  */
define|#
directive|define
name|SERDES_C_LANE_CFG_LN_CTRL_TX_EN
value|(1<< 4)
comment|/*  * Informs the PHY to bypass the output of the  * analog LOS detector and instead rely upon  * a protocol LOS mechanism in the SoC/ASIC  * 0x0 â LOS operates as normal  * 0x1 â Bypass analog LOS output and  * instead rely upon protocol-level LOS  * detection via input lnX_ctrl_los_eii_value  */
define|#
directive|define
name|SERDES_C_LANE_CFG_LN_CTRL_LOS_EII_EN
value|(1<< 5)
comment|/*  * If lnX_ctrl_los_eii_en_i = 1 then Informs  * the PHY that the received signal was lost  */
define|#
directive|define
name|SERDES_C_LANE_CFG_LN_CTRL_LOS_EII_VALUE
value|(1<< 6)
comment|/* One hot mux */
define|#
directive|define
name|SERDES_C_LANE_CFG_TX_DATA_SRC_SELECT_MASK
value|0x00000F00
define|#
directive|define
name|SERDES_C_LANE_CFG_TX_DATA_SRC_SELECT_SHIFT
value|8
comment|/* 0x0 - 20-bit 0x1 â 40-bit */
define|#
directive|define
name|SERDES_C_LANE_CFG_LN_CTRL_DATA_WIDTH
value|(1<< 12)
comment|/**** stat register ****/
comment|/*  * x0 â lane is not ready to send and receive data  * 0x1 â lane is ready to send and receive data  */
define|#
directive|define
name|SERDES_C_LANE_STAT_LNX_STAT_OK
value|(1<< 0)
comment|/*  * 0x0 â received data run length has not  * exceed the programmable run length  * detector threshold  * 0x1 â received data run length has  * exceeded the programmable run length  * detector threshold  */
define|#
directive|define
name|SERDES_C_LANE_STAT_LN_STAT_RUNLEN_ERR
value|(1<< 1)
comment|/*  * 0x0 â data on lnX_rxdata_o are invalid  * 0x1 â data on the active bits of  * lnX_rxdata_o are valid  */
define|#
directive|define
name|SERDES_C_LANE_STAT_LN_STAT_RXVALID
value|(1<< 2)
comment|/*  * Loss of Signal (LOS) indicator that includes  * the combined functions of the digitally  * assisted analog LOS, digital LOS, and  * protocol LOS override features  * 0x0 â Signal detected on  lnX_rxp_i /  * lnX_rxm_i pins  * 0x1 â No signal detected on lnX_rxp_i /  * lnX_rxm_i pins  */
define|#
directive|define
name|SERDES_C_LANE_STAT_LN_STAT_LOS
value|(1<< 3)
define|#
directive|define
name|SERDES_C_LANE_STAT_LN_STAT_LOS_DEGLITCH
value|(1<< 4)
comment|/**** reserved register ****/
define|#
directive|define
name|SERDES_C_LANE_RESERVED_DEF_0_MASK
value|0x0000FFFF
define|#
directive|define
name|SERDES_C_LANE_RESERVED_DEF_0_SHIFT
value|0
define|#
directive|define
name|SERDES_C_LANE_RESERVED_DEF_1_MASK
value|0xFFFF0000
define|#
directive|define
name|SERDES_C_LANE_RESERVED_DEF_1_SHIFT
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
comment|/* __AL_HAL_serdes_c_REGS_H__ */
end_comment

begin_comment
comment|/** @} end of ... group */
end_comment

end_unit

