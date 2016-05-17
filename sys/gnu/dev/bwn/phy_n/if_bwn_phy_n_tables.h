begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    Broadcom B43 wireless driver   IEEE 802.11n PHY data tables    Copyright (c) 2008 Michael Buesch<m@bues.ch>   Copyright (c) 2010 RafaÅ MiÅecki<zajec5@gmail.com>    This program is free software; you can redistribute it and/or modify   it under the terms of the GNU General Public License as published by   the Free Software Foundation; either version 2 of the License, or   (at your option) any later version.    This program is distributed in the hope that it will be useful,   but WITHOUT ANY WARRANTY; without even the implied warranty of   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the   GNU General Public License for more details.    You should have received a copy of the GNU General Public License   along with this program; see the file COPYING.  If not, write to   the Free Software Foundation, Inc., 51 Franklin Steet, Fifth Floor,   Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_BWN_TABLES_NPHY_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_BWN_TABLES_NPHY_H__
end_define

begin_struct
struct|struct
name|bwn_phy_n_sfo_cfg
block|{
name|uint16_t
name|phy_bw1a
decl_stmt|;
name|uint16_t
name|phy_bw2
decl_stmt|;
name|uint16_t
name|phy_bw3
decl_stmt|;
name|uint16_t
name|phy_bw4
decl_stmt|;
name|uint16_t
name|phy_bw5
decl_stmt|;
name|uint16_t
name|phy_bw6
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|bwn_mac
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bwn_nphy_txiqcal_ladder
block|{
name|uint8_t
name|percent
decl_stmt|;
name|uint8_t
name|g_env
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwn_nphy_rf_control_override_rev2
block|{
name|uint8_t
name|addr0
decl_stmt|;
name|uint8_t
name|addr1
decl_stmt|;
name|uint16_t
name|bmask
decl_stmt|;
name|uint8_t
name|shift
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwn_nphy_rf_control_override_rev3
block|{
name|uint16_t
name|val_mask
decl_stmt|;
name|uint8_t
name|val_shift
decl_stmt|;
name|uint8_t
name|en_addr0
decl_stmt|;
name|uint8_t
name|val_addr0
decl_stmt|;
name|uint8_t
name|en_addr1
decl_stmt|;
name|uint8_t
name|val_addr1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwn_nphy_rf_control_override_rev7
block|{
name|uint16_t
name|field
decl_stmt|;
name|uint16_t
name|val_addr_core0
decl_stmt|;
name|uint16_t
name|val_addr_core1
decl_stmt|;
name|uint16_t
name|val_mask
decl_stmt|;
name|uint8_t
name|val_shift
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwn_nphy_gain_ctl_workaround_entry
block|{
name|int8_t
name|lna1_gain
index|[
literal|4
index|]
decl_stmt|;
name|int8_t
name|lna2_gain
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|gain_db
index|[
literal|10
index|]
decl_stmt|;
name|uint8_t
name|gain_bits
index|[
literal|10
index|]
decl_stmt|;
name|uint16_t
name|init_gain
decl_stmt|;
name|uint16_t
name|rfseq_init
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|cliphi_gain
decl_stmt|;
name|uint16_t
name|clipmd_gain
decl_stmt|;
name|uint16_t
name|cliplo_gain
decl_stmt|;
name|uint16_t
name|crsmin
decl_stmt|;
name|uint16_t
name|crsminl
decl_stmt|;
name|uint16_t
name|crsminu
decl_stmt|;
name|uint16_t
name|nbclip
decl_stmt|;
name|uint16_t
name|wlclip
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Get entry with workaround values for gain ctl. Does not return NULL. */
end_comment

begin_function_decl
name|struct
name|bwn_nphy_gain_ctl_workaround_entry
modifier|*
name|bwn_nphy_get_gain_ctl_workaround_ent
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|bool
name|ghz5
parameter_list|,
name|bool
name|ext_lna
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The N-PHY tables. */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TYPEMASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_8BIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_16BIT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_32BIT
value|0x30000000
end_define

begin_define
define|#
directive|define
name|BWN_NTAB8
parameter_list|(
name|table
parameter_list|,
name|offset
parameter_list|)
value|(((table)<< 10) | (offset) | BWN_NTAB_8BIT)
end_define

begin_define
define|#
directive|define
name|BWN_NTAB16
parameter_list|(
name|table
parameter_list|,
name|offset
parameter_list|)
value|(((table)<< 10) | (offset) | BWN_NTAB_16BIT)
end_define

begin_define
define|#
directive|define
name|BWN_NTAB32
parameter_list|(
name|table
parameter_list|,
name|offset
parameter_list|)
value|(((table)<< 10) | (offset) | BWN_NTAB_32BIT)
end_define

begin_comment
comment|/* Static N-PHY tables */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_FRAMESTRUCT
value|BWN_NTAB32(0x0A, 0x000)
end_define

begin_comment
comment|/* Frame Struct Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_FRAMESTRUCT_SIZE
value|832
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_FRAMELT
value|BWN_NTAB8 (0x18, 0x000)
end_define

begin_comment
comment|/* Frame Lookup Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_FRAMELT_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TMAP
value|BWN_NTAB32(0x0C, 0x000)
end_define

begin_comment
comment|/* T Map Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TMAP_SIZE
value|448
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TDTRN
value|BWN_NTAB32(0x0E, 0x000)
end_define

begin_comment
comment|/* TDTRN Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDTRN_SIZE
value|704
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_INTLEVEL
value|BWN_NTAB32(0x0D, 0x000)
end_define

begin_comment
comment|/* Int Level Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_INTLEVEL_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_PILOT
value|BWN_NTAB16(0x0B, 0x000)
end_define

begin_comment
comment|/* Pilot Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_PILOT_SIZE
value|88
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_PILOTLT
value|BWN_NTAB32(0x14, 0x000)
end_define

begin_comment
comment|/* Pilot Lookup Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_PILOTLT_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TDI20A0
value|BWN_NTAB32(0x13, 0x080)
end_define

begin_comment
comment|/* TDI Table 20 Antenna 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDI20A0_SIZE
value|55
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TDI20A1
value|BWN_NTAB32(0x13, 0x100)
end_define

begin_comment
comment|/* TDI Table 20 Antenna 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDI20A1_SIZE
value|55
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TDI40A0
value|BWN_NTAB32(0x13, 0x280)
end_define

begin_comment
comment|/* TDI Table 40 Antenna 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDI40A0_SIZE
value|110
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TDI40A1
value|BWN_NTAB32(0x13, 0x300)
end_define

begin_comment
comment|/* TDI Table 40 Antenna 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDI40A1_SIZE
value|110
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_BDI
value|BWN_NTAB16(0x15, 0x000)
end_define

begin_comment
comment|/* BDI Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_BDI_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_CHANEST
value|BWN_NTAB32(0x16, 0x000)
end_define

begin_comment
comment|/* Channel Estimate Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_CHANEST_SIZE
value|96
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_MCS
value|BWN_NTAB8 (0x12, 0x000)
end_define

begin_comment
comment|/* MCS Table */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_MCS_SIZE
value|128
end_define

begin_comment
comment|/* Volatile N-PHY tables */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_NOISEVAR10
value|BWN_NTAB32(0x10, 0x000)
end_define

begin_comment
comment|/* Noise Var Table 10 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_NOISEVAR10_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_NOISEVAR11
value|BWN_NTAB32(0x10, 0x080)
end_define

begin_comment
comment|/* Noise Var Table 11 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_NOISEVAR11_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C0_ESTPLT
value|BWN_NTAB8 (0x1A, 0x000)
end_define

begin_comment
comment|/* Estimate Power Lookup Table Core 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_ESTPLT_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C0_ADJPLT
value|BWN_NTAB8 (0x1A, 0x040)
end_define

begin_comment
comment|/* Adjust Power Lookup Table Core 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_ADJPLT_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C0_GAINCTL
value|BWN_NTAB32(0x1A, 0x0C0)
end_define

begin_comment
comment|/* Gain Control Lookup Table Core 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_GAINCTL_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C0_IQLT
value|BWN_NTAB32(0x1A, 0x140)
end_define

begin_comment
comment|/* IQ Lookup Table Core 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_IQLT_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C0_LOFEEDTH
value|BWN_NTAB16(0x1A, 0x1C0)
end_define

begin_comment
comment|/* Local Oscillator Feed Through Lookup Table Core 0 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_LOFEEDTH_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C1_ESTPLT
value|BWN_NTAB8 (0x1B, 0x000)
end_define

begin_comment
comment|/* Estimate Power Lookup Table Core 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_ESTPLT_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C1_ADJPLT
value|BWN_NTAB8 (0x1B, 0x040)
end_define

begin_comment
comment|/* Adjust Power Lookup Table Core 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_ADJPLT_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C1_GAINCTL
value|BWN_NTAB32(0x1B, 0x0C0)
end_define

begin_comment
comment|/* Gain Control Lookup Table Core 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_GAINCTL_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C1_IQLT
value|BWN_NTAB32(0x1B, 0x140)
end_define

begin_comment
comment|/* IQ Lookup Table Core 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_IQLT_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C1_LOFEEDTH
value|BWN_NTAB16(0x1B, 0x1C0)
end_define

begin_comment
comment|/* Local Oscillator Feed Through Lookup Table Core 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_LOFEEDTH_SIZE
value|128
end_define

begin_comment
comment|/* Volatile N-PHY tables, PHY revision>= 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_ANT_SW_CTL_R3
value|BWN_NTAB16( 9,   0)
end_define

begin_comment
comment|/* antenna software control */
end_comment

begin_comment
comment|/* Static N-PHY tables, PHY revision>= 3 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_FRAMESTRUCT_R3
value|BWN_NTAB32(10,   0)
end_define

begin_comment
comment|/* frame struct  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_PILOT_R3
value|BWN_NTAB16(11,   0)
end_define

begin_comment
comment|/* pilot  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TMAP_R3
value|BWN_NTAB32(12,   0)
end_define

begin_comment
comment|/* TM AP  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_INTLEVEL_R3
value|BWN_NTAB32(13,   0)
end_define

begin_comment
comment|/* INT LV  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDTRN_R3
value|BWN_NTAB32(14,   0)
end_define

begin_comment
comment|/* TD TRN  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_NOISEVAR_R3
value|BWN_NTAB32(16,   0)
end_define

begin_comment
comment|/* noise variance */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_MCS_R3
value|BWN_NTAB16(18,   0)
end_define

begin_comment
comment|/* MCS  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDI20A0_R3
value|BWN_NTAB32(19, 128)
end_define

begin_comment
comment|/* TDI 20/0  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDI20A1_R3
value|BWN_NTAB32(19, 256)
end_define

begin_comment
comment|/* TDI 20/1  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDI40A0_R3
value|BWN_NTAB32(19, 640)
end_define

begin_comment
comment|/* TDI 40/0  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TDI40A1_R3
value|BWN_NTAB32(19, 768)
end_define

begin_comment
comment|/* TDI 40/1  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_PILOTLT_R3
value|BWN_NTAB32(20,   0)
end_define

begin_comment
comment|/* PLT lookup  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_CHANEST_R3
value|BWN_NTAB32(22,   0)
end_define

begin_comment
comment|/* channel estimate  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_FRAMELT_R3
value|BWN_NTAB8(24,   0)
end_define

begin_comment
comment|/* frame lookup  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_ESTPLT_R3
value|BWN_NTAB8(26,   0)
end_define

begin_comment
comment|/* estimated power lookup 0  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_ADJPLT_R3
value|BWN_NTAB8(26,  64)
end_define

begin_comment
comment|/* adjusted power lookup 0  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_GAINCTL_R3
value|BWN_NTAB32(26, 192)
end_define

begin_comment
comment|/* gain control lookup 0  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_IQLT_R3
value|BWN_NTAB32(26, 320)
end_define

begin_comment
comment|/* I/Q lookup 0  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_LOFEEDTH_R3
value|BWN_NTAB16(26, 448)
end_define

begin_comment
comment|/* Local Oscillator Feed Through lookup 0  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C0_PAPD_COMP_R3
value|BWN_NTAB16(26, 576)
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_C1_ESTPLT_R3
value|BWN_NTAB8(27,   0)
end_define

begin_comment
comment|/* estimated power lookup 1  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_ADJPLT_R3
value|BWN_NTAB8(27,  64)
end_define

begin_comment
comment|/* adjusted power lookup 1  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_GAINCTL_R3
value|BWN_NTAB32(27, 192)
end_define

begin_comment
comment|/* gain control lookup 1  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_IQLT_R3
value|BWN_NTAB32(27, 320)
end_define

begin_comment
comment|/* I/Q lookup 1  */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_LOFEEDTH_R3
value|BWN_NTAB16(27, 448)
end_define

begin_comment
comment|/* Local Oscillator Feed Through lookup 1 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_C1_PAPD_COMP_R3
value|BWN_NTAB16(27, 576)
end_define

begin_comment
comment|/* Static N-PHY tables, PHY revision>= 7 */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TMAP_R7
value|BWN_NTAB32(12,   0)
end_define

begin_comment
comment|/* TM AP */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_NOISEVAR_R7
value|BWN_NTAB32(16,   0)
end_define

begin_comment
comment|/* noise variance */
end_comment

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_LOFT_LADDER_40_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_LOFT_LADDER_20_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_IQIMB_LADDER_40_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_IQIMB_LADDER_20_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_STARTCOEFS_REV3
value|11
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_STARTCOEFS
value|9
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_CMDS_RECAL_REV3
value|12
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_CMDS_RECAL
value|10
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_CMDS_FULLCAL
value|10
end_define

begin_define
define|#
directive|define
name|BWN_NTAB_TX_IQLO_CAL_CMDS_FULLCAL_REV3
value|12
end_define

begin_function_decl
name|uint32_t
name|bwn_ntab_read
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|uint32_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwn_ntab_read_bulk
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|unsigned
name|int
name|nr_elements
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwn_ntab_write
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwn_ntab_write_bulk
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|unsigned
name|int
name|nr_elements
parameter_list|,
specifier|const
name|void
modifier|*
name|_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwn_nphy_tables_init
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|uint32_t
modifier|*
name|bwn_nphy_get_tx_gain_table
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|int16_t
modifier|*
name|bwn_ntab_get_rf_pwr_offset_table
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|int8_t
name|bwn_ntab_papd_pga_gain_delta_ipa_2g
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_iqcal_gainparams
index|[
literal|2
index|]
index|[
literal|9
index|]
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bwn_nphy_txiqcal_ladder
name|ladder_lo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bwn_nphy_txiqcal_ladder
name|ladder_iq
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|loscale
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_loft_ladder_40
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_loft_ladder_20
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_iqimb_ladder_40
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_iqimb_ladder_20
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_startcoefs_nphyrev3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_startcoefs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_cmds_recal_nphyrev3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_cmds_recal
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_cmds_fullcal
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint16_t
name|tbl_tx_iqlo_cal_cmds_fullcal_nphyrev3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int16_t
name|tbl_tx_filter_coef_rev4
index|[
literal|7
index|]
index|[
literal|15
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bwn_nphy_rf_control_override_rev2
name|tbl_rf_control_override_rev2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bwn_nphy_rf_control_override_rev3
name|tbl_rf_control_override_rev3
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|struct
name|bwn_nphy_rf_control_override_rev7
modifier|*
name|bwn_nphy_get_rf_ctl_over_rev7
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|uint16_t
name|field
parameter_list|,
name|uint8_t
name|override
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_BWN_PHY_TABLES_N_H__ */
end_comment

end_unit

