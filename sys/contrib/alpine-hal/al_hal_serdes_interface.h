begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_serdes_api API  * SerDes HAL driver API  * @ingroup group_serdes SerDes  * @{  *  * @file   al_hal_serdes_interface.h  *  * @brief Header file for the SerDes HAL driver  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_SERDES_INTERFACE_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_SERDES_INTERFACE_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_common.h"
end_include

begin_comment
comment|/* *INDENT-OFF* */
end_comment

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
comment|/* *INDENT-ON* */
enum|enum
name|al_serdes_type
block|{
name|AL_SRDS_TYPE_HSSP
block|,
name|AL_SRDS_TYPE_25G
block|, }
enum|;
enum|enum
name|al_serdes_reg_page
block|{
comment|/* Relevant to Serdes hssp and 25g */
name|AL_SRDS_REG_PAGE_0_LANE_0
init|=
literal|0
block|,
name|AL_SRDS_REG_PAGE_1_LANE_1
block|,
comment|/* Relevant to Serdes hssp only */
name|AL_SRDS_REG_PAGE_2_LANE_2
block|,
name|AL_SRDS_REG_PAGE_3_LANE_3
block|,
comment|/* Relevant to Serdes hssp and 25g */
name|AL_SRDS_REG_PAGE_4_COMMON
block|,
comment|/* Relevant to Serdes hssp only */
name|AL_SRDS_REG_PAGE_0123_LANES_0123
init|=
literal|7
block|,
comment|/* Relevant to Serdes 25g only */
name|AL_SRDS_REG_PAGE_TOP
block|, }
enum|;
comment|/* Relevant to Serdes hssp only */
enum|enum
name|al_serdes_reg_type
block|{
name|AL_SRDS_REG_TYPE_PMA
init|=
literal|0
block|,
name|AL_SRDS_REG_TYPE_PCS
block|, }
enum|;
enum|enum
name|al_serdes_lane
block|{
name|AL_SRDS_LANE_0
init|=
name|AL_SRDS_REG_PAGE_0_LANE_0
block|,
name|AL_SRDS_LANE_1
init|=
name|AL_SRDS_REG_PAGE_1_LANE_1
block|,
name|AL_SRDS_LANE_2
init|=
name|AL_SRDS_REG_PAGE_2_LANE_2
block|,
name|AL_SRDS_LANE_3
init|=
name|AL_SRDS_REG_PAGE_3_LANE_3
block|,
name|AL_SRDS_NUM_LANES
block|,
name|AL_SRDS_LANES_0123
init|=
name|AL_SRDS_REG_PAGE_0123_LANES_0123
block|, }
enum|;
comment|/** Serdes loopback mode */
enum|enum
name|al_serdes_lb_mode
block|{
comment|/** No loopback */
name|AL_SRDS_LB_MODE_OFF
block|,
comment|/** 	 * Transmits the untimed, partial equalized RX signal out the transmit 	 * IO pins. 	 * No clock used (untimed) 	 */
name|AL_SRDS_LB_MODE_PMA_IO_UN_TIMED_RX_TO_TX
block|,
comment|/** 	 * Loops back the TX serializer output into the CDR. 	 * CDR recovered bit clock used (without attenuation) 	 */
name|AL_SRDS_LB_MODE_PMA_INTERNALLY_BUFFERED_SERIAL_TX_TO_RX
block|,
comment|/** 	 * Loops back the TX driver IO signal to the RX IO pins 	 * CDR recovered bit clock used (only through IO) 	 */
name|AL_SRDS_LB_MODE_PMA_SERIAL_TX_IO_TO_RX_IO
block|,
comment|/** 	 * Parallel loopback from the PMA receive lane data ports, to the 	 * transmit lane data ports 	 * CDR recovered bit clock used 	 */
name|AL_SRDS_LB_MODE_PMA_PARALLEL_RX_TO_TX
block|,
comment|/** Loops received data after elastic buffer to transmit path */
name|AL_SRDS_LB_MODE_PCS_PIPE
block|,
comment|/** Loops TX data (to PMA) to RX path (instead of PMA data) */
name|AL_SRDS_LB_MODE_PCS_NEAR_END
block|,
comment|/** Loops receive data prior to interface block to transmit path */
name|AL_SRDS_LB_MODE_PCS_FAR_END
block|, }
enum|;
enum|enum
name|al_serdes_clk_freq
block|{
name|AL_SRDS_CLK_FREQ_NA
block|,
name|AL_SRDS_CLK_FREQ_100_MHZ
block|,
name|AL_SRDS_CLK_FREQ_125_MHZ
block|,
name|AL_SRDS_CLK_FREQ_156_MHZ
block|, }
enum|;
enum|enum
name|al_serdes_clk_src
block|{
name|AL_SRDS_CLK_SRC_LOGIC_0
block|,
name|AL_SRDS_CLK_SRC_REF_PINS
block|,
name|AL_SRDS_CLK_SRC_R2L
block|,
name|AL_SRDS_CLK_SRC_R2L_PLL
block|,
name|AL_SRDS_CLK_SRC_L2R
block|, }
enum|;
comment|/** Serdes BIST pattern */
enum|enum
name|al_serdes_bist_pattern
block|{
name|AL_SRDS_BIST_PATTERN_USER
block|,
name|AL_SRDS_BIST_PATTERN_PRBS7
block|,
name|AL_SRDS_BIST_PATTERN_PRBS23
block|,
name|AL_SRDS_BIST_PATTERN_PRBS31
block|,
name|AL_SRDS_BIST_PATTERN_CLK1010
block|, }
enum|;
comment|/** SerDes group rate */
enum|enum
name|al_serdes_rate
block|{
name|AL_SRDS_RATE_1_8
block|,
name|AL_SRDS_RATE_1_4
block|,
name|AL_SRDS_RATE_1_2
block|,
name|AL_SRDS_RATE_FULL
block|, }
enum|;
comment|/** SerDes power mode */
enum|enum
name|al_serdes_pm
block|{
name|AL_SRDS_PM_PD
block|,
name|AL_SRDS_PM_P2
block|,
name|AL_SRDS_PM_P1
block|,
name|AL_SRDS_PM_P0S
block|,
name|AL_SRDS_PM_P0
block|, }
enum|;
comment|/**  * Tx de-emphasis parameters  */
enum|enum
name|al_serdes_tx_deemph_param
block|{
name|AL_SERDES_TX_DEEMP_C_ZERO
block|,
comment|/*< c(0) */
name|AL_SERDES_TX_DEEMP_C_PLUS
block|,
comment|/*< c(1) */
name|AL_SERDES_TX_DEEMP_C_MINUS
block|,
comment|/*< c(-1) */
block|}
enum|;
struct|struct
name|al_serdes_adv_tx_params
block|{
comment|/* 	 * select the input values location. 	 * When set to true the values will be taken from the internal registers 	 * that will be override with the next following parameters. 	 * When set to false the values will be taken from external pins (the 	 * other parameters in this case is not needed) 	 */
name|al_bool
name|override
decl_stmt|;
comment|/* 	 * Transmit Amplitude control signal. Used to define the full-scale 	 * maximum swing of the driver. 	 *	000 - Not Supported 	 *	001 - 952mVdiff-pkpk 	 *	010 - 1024mVdiff-pkpk 	 *	011 - 1094mVdiff-pkpk 	 *	100 - 1163mVdiff-pkpk 	 *	101 - 1227mVdiff-pkpk 	 *	110 - 1283mVdiff-pkpk 	 *	111 - 1331mVdiff-pkpk 	 */
name|uint8_t
name|amp
decl_stmt|;
comment|/* Defines the total number of driver units allocated in the driver */
name|uint8_t
name|total_driver_units
decl_stmt|;
comment|/* Defines the total number of driver units allocated to the 	 * first post-cursor (C+1) tap. */
name|uint8_t
name|c_plus_1
decl_stmt|;
comment|/* Defines the total number of driver units allocated to the 	 * second post-cursor (C+2) tap. */
name|uint8_t
name|c_plus_2
decl_stmt|;
comment|/* Defines the total number of driver units allocated to the 	 * first pre-cursor (C-1) tap. */
name|uint8_t
name|c_minus_1
decl_stmt|;
comment|/* TX driver Slew Rate control: 	 *	00 - 31ps 	 *	01 - 33ps 	 *	10 - 68ps 	 *	11 - 170ps 	 */
name|uint8_t
name|slew_rate
decl_stmt|;
block|}
struct|;
struct|struct
name|al_serdes_adv_rx_params
block|{
comment|/* 	 * select the input values location. 	 * When set to true the values will be taken from the internal registers 	 * that will be override with the next following parameters. 	 * When set to false the values will be taken based in the equalization 	 * results (the other parameters in this case is not needed) 	 */
name|al_bool
name|override
decl_stmt|;
comment|/* RX agc high frequency dc gain: 	 *	-3'b000: -3dB 	 *	-3'b001: -2.5dB 	 *	-3'b010: -2dB 	 *	-3'b011: -1.5dB 	 *	-3'b100: -1dB 	 *	-3'b101: -0.5dB 	 *	-3'b110: -0dB 	 *	-3'b111: 0.5dB 	 */
name|uint8_t
name|dcgain
decl_stmt|;
comment|/* DFE post-shaping tap 3dB frequency 	 *	-3'b000: 684MHz 	 *	-3'b001: 576MHz 	 *	-3'b010: 514MHz 	 *	-3'b011: 435MHz 	 *	-3'b100: 354MHz 	 *	-3'b101: 281MHz 	 *	-3'b110: 199MHz 	 *	-3'b111: 125MHz 	 */
name|uint8_t
name|dfe_3db_freq
decl_stmt|;
comment|/* DFE post-shaping tap gain 	 *	0: no pulse shaping tap 	 *	1: -24mVpeak 	 *	2: -45mVpeak 	 *	3: -64mVpeak 	 *	4: -80mVpeak 	 *	5: -93mVpeak 	 *	6: -101mVpeak 	 *	7: -105mVpeak 	 */
name|uint8_t
name|dfe_gain
decl_stmt|;
comment|/* DFE first tap gain control 	 *	-4'b0000: +1mVpeak 	 *	-4'b0001: +10mVpeak 	 *	.... 	 *	-4'b0110: +55mVpeak 	 *	-4'b0111: +64mVpeak 	 *	-4'b1000: -1mVpeak 	 *	-4'b1001: -10mVpeak 	 *	.... 	 *	-4'b1110: -55mVpeak 	 *	-4'b1111: -64mVpeak 	 */
name|uint8_t
name|dfe_first_tap_ctrl
decl_stmt|;
comment|/* DFE second tap gain control 	 *	-4'b0000: +0mVpeak 	 *	-4'b0001: +9mVpeak 	 *	.... 	 *	-4'b0110: +46mVpeak 	 *	-4'b0111: +53mVpeak 	 *	-4'b1000: -0mVpeak 	 *	-4'b1001: -9mVpeak 	 *	.... 	 *	-4'b1110: -46mVpeak 	 *	-4'b1111: -53mVpeak 	 */
name|uint8_t
name|dfe_secound_tap_ctrl
decl_stmt|;
comment|/* DFE third tap gain control 	 *	-4'b0000: +0mVpeak 	 *	-4'b0001: +7mVpeak 	 *	.... 	 *	-4'b0110: +38mVpeak 	 *	-4'b0111: +44mVpeak 	 *	-4'b1000: -0mVpeak 	 *	-4'b1001: -7mVpeak 	 *	.... 	 *	-4'b1110: -38mVpeak 	 *	-4'b1111: -44mVpeak 	 */
name|uint8_t
name|dfe_third_tap_ctrl
decl_stmt|;
comment|/* DFE fourth tap gain control 	 *	-4'b0000: +0mVpeak 	 *	-4'b0001: +6mVpeak 	 *	.... 	 *	-4'b0110: +29mVpeak 	 *	-4'b0111: +33mVpeak 	 *	-4'b1000: -0mVpeak 	 *	-4'b1001: -6mVpeak 	 *	.... 	 *	-4'b1110: -29mVpeak 	 *	-4'b1111: -33mVpeak 	 */
name|uint8_t
name|dfe_fourth_tap_ctrl
decl_stmt|;
comment|/* Low frequency agc gain (att) select 	 *	-3'b000: Disconnected 	 *	-3'b001: -18.5dB 	 *	-3'b010: -12.5dB 	 *	-3'b011: -9dB 	 *	-3'b100: -6.5dB 	 *	-3'b101: -4.5dB 	 *	-3'b110: -2.9dB 	 *	-3'b111: -1.6dB 	 */
name|uint8_t
name|low_freq_agc_gain
decl_stmt|;
comment|/* Provides a RX Equalizer pre-hint, prior to beginning 	 * adaptive equalization */
name|uint8_t
name|precal_code_sel
decl_stmt|;
comment|/* High frequency agc boost control 	 *	Min d0: Boost ~4dB 	 *	Max d31: Boost ~20dB 	 */
name|uint8_t
name|high_freq_agc_boost
decl_stmt|;
block|}
struct|;
struct|struct
name|al_serdes_25g_adv_rx_params
block|{
comment|/* ATT (PLE Flat-Band Gain) */
name|uint8_t
name|att
decl_stmt|;
comment|/* APG (CTLE's Flat-Band Gain) */
name|uint8_t
name|apg
decl_stmt|;
comment|/* LFG (Low-Freq Gain) */
name|uint8_t
name|lfg
decl_stmt|;
comment|/* HFG (High-Freq Gain) */
name|uint8_t
name|hfg
decl_stmt|;
comment|/* MBG (MidBand-Freq-knob Gain) */
name|uint8_t
name|mbg
decl_stmt|;
comment|/* MBF (MidBand-Freq-knob Frequency position Gain) */
name|uint8_t
name|mbf
decl_stmt|;
comment|/* DFE Tap1 even#0 Value */
name|int8_t
name|dfe_first_tap_even0_ctrl
decl_stmt|;
comment|/* DFE Tap1 even#1 Value */
name|int8_t
name|dfe_first_tap_even1_ctrl
decl_stmt|;
comment|/* DFE Tap1 odd#0 Value */
name|int8_t
name|dfe_first_tap_odd0_ctrl
decl_stmt|;
comment|/* DFE Tap1 odd#1 Value */
name|int8_t
name|dfe_first_tap_odd1_ctrl
decl_stmt|;
comment|/* DFE Tap2 Value */
name|int8_t
name|dfe_second_tap_ctrl
decl_stmt|;
comment|/* DFE Tap3 Value */
name|int8_t
name|dfe_third_tap_ctrl
decl_stmt|;
comment|/* DFE Tap4 Value */
name|int8_t
name|dfe_fourth_tap_ctrl
decl_stmt|;
comment|/* DFE Tap5 Value */
name|int8_t
name|dfe_fifth_tap_ctrl
decl_stmt|;
block|}
struct|;
struct|struct
name|al_serdes_25g_tx_diag_info
block|{
name|uint8_t
name|regulated_supply
decl_stmt|;
name|int8_t
name|dcd_trim
decl_stmt|;
name|uint8_t
name|clk_delay
decl_stmt|;
name|uint8_t
name|calp_multiplied_by_2
decl_stmt|;
name|uint8_t
name|caln_multiplied_by_2
decl_stmt|;
block|}
struct|;
struct|struct
name|al_serdes_25g_rx_diag_info
block|{
name|int8_t
name|los_offset
decl_stmt|;
name|int8_t
name|agc_offset
decl_stmt|;
name|int8_t
name|leq_gainstage_offset
decl_stmt|;
name|int8_t
name|leq_eq1_offset
decl_stmt|;
name|int8_t
name|leq_eq2_offset
decl_stmt|;
name|int8_t
name|leq_eq3_offset
decl_stmt|;
name|int8_t
name|leq_eq4_offset
decl_stmt|;
name|int8_t
name|leq_eq5_offset
decl_stmt|;
name|int8_t
name|summer_even_offset
decl_stmt|;
name|int8_t
name|summer_odd_offset
decl_stmt|;
name|int8_t
name|vscan_even_offset
decl_stmt|;
name|int8_t
name|vscan_odd_offset
decl_stmt|;
name|int8_t
name|data_slicer_even0_offset
decl_stmt|;
name|int8_t
name|data_slicer_even1_offset
decl_stmt|;
name|int8_t
name|data_slicer_odd0_offset
decl_stmt|;
name|int8_t
name|data_slicer_odd1_offset
decl_stmt|;
name|int8_t
name|edge_slicer_even_offset
decl_stmt|;
name|int8_t
name|edge_slicer_odd_offset
decl_stmt|;
name|int8_t
name|eye_slicer_even_offset
decl_stmt|;
name|int8_t
name|eye_slicer_odd_offset
decl_stmt|;
name|uint8_t
name|cdr_clk_i
decl_stmt|;
name|uint8_t
name|cdr_clk_q
decl_stmt|;
name|uint8_t
name|cdr_dll
decl_stmt|;
name|uint8_t
name|cdr_vco_dosc
decl_stmt|;
name|uint8_t
name|cdr_vco_fr
decl_stmt|;
name|uint16_t
name|cdr_dlpf
decl_stmt|;
name|uint8_t
name|ple_resistance
decl_stmt|;
name|uint8_t
name|rx_term_mode
decl_stmt|;
name|uint8_t
name|rx_coupling
decl_stmt|;
name|uint8_t
name|rx_term_cal_code
decl_stmt|;
name|uint8_t
name|rx_sheet_res_cal_code
decl_stmt|;
block|}
struct|;
comment|/**  * SRIS parameters  */
struct|struct
name|al_serdes_sris_params
block|{
comment|/* Controls the frequency accuracy threshold (ppm) for lock detection CDR */
name|uint16_t
name|ppm_drift_count
decl_stmt|;
comment|/* Controls the frequency accuracy threshold (ppm) for lock detection in the CDR */
name|uint16_t
name|ppm_drift_max
decl_stmt|;
comment|/* Controls the frequency accuracy threshold (ppm) for lock detection in PLL */
name|uint16_t
name|synth_ppm_drift_max
decl_stmt|;
comment|/* Elastic buffer full threshold for PCIE modes: GEN1/GEN2 */
name|uint8_t
name|full_d2r1
decl_stmt|;
comment|/* Elastic buffer full threshold for PCIE modes: GEN3 */
name|uint8_t
name|full_pcie_g3
decl_stmt|;
comment|/* Elastic buffer midpoint threshold. 	 * Sets the depth of the buffer while in PCIE mode, GEN1/GEN2 	 */
name|uint8_t
name|rd_threshold_d2r1
decl_stmt|;
comment|/* Elastic buffer midpoint threshold. 	 * Sets the depth of the buffer while in PCIE mode, GEN3 	 */
name|uint8_t
name|rd_threshold_pcie_g3
decl_stmt|;
block|}
struct|;
comment|/** SerDes PCIe Rate - values are important for proper behavior */
enum|enum
name|al_serdes_pcie_rate
block|{
name|AL_SRDS_PCIE_RATE_GEN1
init|=
literal|0
block|,
name|AL_SRDS_PCIE_RATE_GEN2
block|,
name|AL_SRDS_PCIE_RATE_GEN3
block|, }
enum|;
struct|struct
name|al_serdes_grp_obj
block|{
name|void
name|__iomem
modifier|*
name|regs_base
decl_stmt|;
comment|/** 	 * get the type of the serdes. 	 * Must be implemented for all SerDes unit. 	 * 	 * @return the serdes type. 	 */
name|enum
name|al_serdes_type
function_decl|(
modifier|*
name|type_get
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** 	 * Reads a SERDES internal register 	 * 	 * @param obj		The object context 	 * @param page		The SERDES register page within the group 	 * @param type		The SERDES register type (PMA /PCS) 	 * @param offset	The SERDES register offset (0 - 4095) 	 * @param data		The read data 	 * 	 * @return 0 if no error found. 	 */
name|int
function_decl|(
modifier|*
name|reg_read
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_reg_page
parameter_list|,
name|enum
name|al_serdes_reg_type
parameter_list|,
name|uint16_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * Writes a SERDES internal register 	 * 	 * @param obj		The object context 	 * @param page		The SERDES register page within the group 	 * @param type		The SERDES register type (PMA /PCS) 	 * @param offset	The SERDES register offset (0 - 4095) 	 * @param data		The data to write 	 * 	 * @return 0 if no error found. 	 */
name|int
function_decl|(
modifier|*
name|reg_write
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_reg_page
parameter_list|,
name|enum
name|al_serdes_reg_type
parameter_list|,
name|uint16_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
comment|/** 	 * Enable BIST required overrides 	 * 	 * @param obj		The object context 	 * @param grp		The SERDES group 	 * @param rate		The required speed rate 	 */
name|void
function_decl|(
modifier|*
name|bist_overrides_enable
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_rate
parameter_list|)
function_decl|;
comment|/** 	 * Disable BIST required overrides 	 * 	 * @param obj		The object context 	 * @param grp		The SERDES group 	 * @param rate		The required speed rate 	 */
name|void
function_decl|(
modifier|*
name|bist_overrides_disable
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * Rx rate change 	 * 	 * @param obj		The object context 	 * @param grp		The SERDES group 	 * @param rate		The Rx required rate 	 */
name|void
function_decl|(
modifier|*
name|rx_rate_change
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_rate
parameter_list|)
function_decl|;
comment|/** 	 * SERDES lane Rx rate change software flow enable 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 */
name|void
function_decl|(
modifier|*
name|rx_rate_change_sw_flow_en
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * SERDES lane Rx rate change software flow disable 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 */
name|void
function_decl|(
modifier|*
name|rx_rate_change_sw_flow_dis
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * PCIe lane rate override check 	 * 	 * @param obj		The object context 	 * @param grp		The SERDES group 	 * @param lane		The SERDES lane within the group 	 * 	 * @returns	AL_TRUE if the override is enabled 	 */
name|al_bool
function_decl|(
modifier|*
name|pcie_rate_override_is_enabled
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * PCIe lane rate override control 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param en		Enable/disable 	 */
name|void
function_decl|(
modifier|*
name|pcie_rate_override_enable_set
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|al_bool
name|en
parameter_list|)
function_decl|;
comment|/** 	 * PCIe lane rate get 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 */
name|enum
name|al_serdes_pcie_rate
function_decl|(
modifier|*
name|pcie_rate_get
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * PCIe lane rate set 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param rate		The required rate 	 */
name|void
function_decl|(
modifier|*
name|pcie_rate_set
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|enum
name|al_serdes_pcie_rate
name|rate
parameter_list|)
function_decl|;
comment|/** 	 * SERDES group power mode control 	 * 	 * @param obj		The object context 	 * @param grp		The SERDES group 	 * @param pm		The required power mode 	 */
name|void
function_decl|(
modifier|*
name|group_pm_set
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_pm
parameter_list|)
function_decl|;
comment|/** 	 * SERDES lane power mode control 	 * 	 * @param obj		The object context 	 * @param grp		The SERDES group 	 * @param lane		The SERDES lane within the group 	 * @param rx_pm		The required RX power mode 	 * @param tx_pm		The required TX power mode 	 */
name|void
function_decl|(
modifier|*
name|lane_pm_set
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|enum
name|al_serdes_pm
parameter_list|,
name|enum
name|al_serdes_pm
parameter_list|)
function_decl|;
comment|/** 	 * SERDES group PMA hard reset 	 * Controls Serdes group PMA hard reset 	 * 	 * @param obj		The object context 	 * @param grp		The SERDES group 	 * @param enable	Enable/disable hard reset 	 */
name|void
function_decl|(
modifier|*
name|pma_hard_reset_group
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|al_bool
parameter_list|)
function_decl|;
comment|/** 	 * SERDES lane PMA hard reset 	 * Controls Serdes lane PMA hard reset 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param enable	Enable/disable hard reset 	 */
name|void
function_decl|(
modifier|*
name|pma_hard_reset_lane
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|al_bool
parameter_list|)
function_decl|;
comment|/** 	 * Configure SERDES loopback 	 * Controls the loopback 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param mode		The requested loopback mode 	 */
name|void
function_decl|(
modifier|*
name|loopback_control
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|enum
name|al_serdes_lb_mode
parameter_list|)
function_decl|;
comment|/** 	 * SERDES BIST pattern selection 	 * Selects the BIST pattern to be used 	 * 	 * @param obj		The object context 	 * @param pattern	The pattern to set 	 * @param user_data	The pattern user data (when pattern == AL_SRDS_BIST_PATTERN_USER) 	 *			80 bits (8 bytes array) 	 */
name|void
function_decl|(
modifier|*
name|bist_pattern_select
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_bist_pattern
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * SERDES BIST TX Enable 	 * Enables/disables TX BIST per lane 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param enable	Enable or disable TX BIST 	 */
name|void
function_decl|(
modifier|*
name|bist_tx_enable
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|al_bool
parameter_list|)
function_decl|;
comment|/** 	 * SERDES BIST TX single bit error injection 	 * Injects single bit error during a TX BIST 	 * 	 * @param obj		The object context 	 */
name|void
function_decl|(
modifier|*
name|bist_tx_err_inject
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * SERDES BIST RX Enable 	 * Enables/disables RX BIST per lane 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param enable	Enable or disable TX BIST 	 */
name|void
function_decl|(
modifier|*
name|bist_rx_enable
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|al_bool
parameter_list|)
function_decl|;
comment|/** 	 * SERDES BIST RX status 	 * Checks the RX BIST status for a specific SERDES lane 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param is_locked	An indication whether RX BIST is locked 	 * @param err_cnt_overflow	An indication whether error count overflow occured 	 * @param err_cnt	Current bit error count 	 */
name|void
function_decl|(
modifier|*
name|bist_rx_status
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|al_bool
modifier|*
parameter_list|,
name|al_bool
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * Set the tx de-emphasis to preset values 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * 	 */
name|void
function_decl|(
modifier|*
name|tx_deemph_preset
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * Increase tx de-emphasis param. 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param param		which tx de-emphasis to change 	 * 	 * @return false in case max is reached. true otherwise. 	 */
name|al_bool
function_decl|(
modifier|*
name|tx_deemph_inc
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|enum
name|al_serdes_tx_deemph_param
parameter_list|)
function_decl|;
comment|/** 	 * Decrease tx de-emphasis param. 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param param		which tx de-emphasis to change 	 * 	 * @return false in case min is reached. true otherwise. 	 */
name|al_bool
function_decl|(
modifier|*
name|tx_deemph_dec
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|enum
name|al_serdes_tx_deemph_param
parameter_list|)
function_decl|;
comment|/** 	 * run Rx eye measurement. 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param timeout	timeout in uSec 	 * @param value		Rx eye measurement value 	 *			(0 - completely closed eye, 0xffff - completely open eye). 	 * 	 * @return 0 if no error found. 	 */
name|int
function_decl|(
modifier|*
name|eye_measure_run
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|uint32_t
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * Eye diagram single sampling 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param x		Sampling X position (0 - 63 --> -1.00 UI ... 1.00 UI) 	 * @param y		Sampling Y position (0 - 62 --> 500mV ... -500mV) 	 * @param timeout	timeout in uSec 	 * @param value		Eye diagram sample value (BER - 0x0000 - 0xffff) 	 * 	 * @return 0 if no error found. 	 */
name|int
function_decl|(
modifier|*
name|eye_diag_sample
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * Eye diagram full run 	 * 	 * @param obj			The object context 	 * @param lane			The SERDES lane within the group 	 * @param x_start		Sampling from X position 	 * @param x_stop		Sampling to X position 	 * @param x_step		jump in x_step 	 * @param y_start		Sampling from Y position 	 * @param y_stop		Sampling to Y position 	 * @param y_step		jump in y_step 	 * @param num_bits_per_sample	How many bits to check 	 * @param buf			array of results 	 * @param buf_size		array size - must be equal to 	 *				(((y_stop - y_start) / y_step) + 1) * 	 *				(((x_stop - x_start) / x_step) + 1) 	 * 	 * @return 0 if no error found. 	 */
name|int
function_decl|(
modifier|*
name|eye_diag_run
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/** 	 * Check if signal is detected 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * 	 * @return true if signal is detected. false otherwise. 	 */
name|al_bool
function_decl|(
modifier|*
name|signal_is_detected
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * Check if CDR is locked 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * 	 * @return true if cdr is locked. false otherwise. 	 */
name|al_bool
function_decl|(
modifier|*
name|cdr_is_locked
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * Check if rx is valid for this lane 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * 	 * @return true if rx is valid. false otherwise. 	 */
name|al_bool
function_decl|(
modifier|*
name|rx_valid
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * configure tx advanced parameters 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param params	pointer to the tx parameters 	 */
name|void
function_decl|(
modifier|*
name|tx_advanced_params_set
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * read tx advanced parameters 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param params	pointer to the tx parameters 	 */
name|void
function_decl|(
modifier|*
name|tx_advanced_params_get
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * configure rx advanced parameters 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param params	pointer to the rx parameters 	 */
name|void
function_decl|(
modifier|*
name|rx_advanced_params_set
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * read rx advanced parameters 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param params	pointer to the rx parameters 	 */
name|void
function_decl|(
modifier|*
name|rx_advanced_params_get
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 *  Switch entire SerDes group to SGMII mode based on 156.25 Mhz reference clock 	 * 	 * @param obj		The object context 	 * 	 */
name|void
function_decl|(
modifier|*
name|mode_set_sgmii
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 *  Switch entire SerDes group to KR mode based on 156.25 Mhz reference clock 	 * 	 * @param obj		The object context 	 * 	 */
name|void
function_decl|(
modifier|*
name|mode_set_kr
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * performs SerDes HW equalization test and update equalization parameters 	 * 	 * @param obj		the object context 	 * @param lane		The SERDES lane within the group 	 */
name|int
function_decl|(
modifier|*
name|rx_equalization
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|)
function_decl|;
comment|/** 	 * performs Rx equalization and compute the width and height of the eye 	 * 	 * @param obj		the object context 	 * @param lane		The SERDES lane within the group 	 * @param width		the output width of the eye 	 * @param height	the output height of the eye 	 */
name|int
function_decl|(
modifier|*
name|calc_eye_size
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * SRIS: Separate Refclk Independent SSC (Spread Spectrum Clocking) 	 * Currently available only for PCIe interfaces. 	 * When working with local Refclk, same SRIS configuration in both serdes sides 	 * (EP and RC in PCIe interface) is required. 	 * 	 * performs SRIS configuration according to params 	 * 	 * @param obj		the object context 	 * @param params	the SRIS parameters 	 */
name|void
function_decl|(
modifier|*
name|sris_config
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * set SERDES dcgain parameter 	 * 	 * @param obj		the object context 	 * @param dcgain	dcgain value to set 	 */
name|void
function_decl|(
modifier|*
name|dcgain_set
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
comment|/** 	 * read tx diagnostics info 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param params	pointer to the tx diagnostics info structure 	 */
name|void
function_decl|(
modifier|*
name|tx_diag_info_get
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** 	 * read rx diagnostics info 	 * 	 * @param obj		The object context 	 * @param lane		The SERDES lane within the group 	 * @param params	pointer to the rx diagnostics info structure 	 */
name|void
function_decl|(
modifier|*
name|rx_diag_info_get
function_decl|)
parameter_list|(
name|struct
name|al_serdes_grp_obj
modifier|*
parameter_list|,
name|enum
name|al_serdes_lane
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
comment|/* *INDENT-OFF* */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_SERDES_INTERFACE_H__ */
end_comment

begin_comment
comment|/** @} end of SERDES group */
end_comment

end_unit

