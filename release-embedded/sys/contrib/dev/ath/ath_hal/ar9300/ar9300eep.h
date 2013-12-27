begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR9300_EEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR9300_EEP_H_
end_define

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_include
include|#
directive|include
file|"ah.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN64
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|ar9300
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FreeBSD extras - should be in ah_eeprom.h ? */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_COMPRESS_DIS
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_AES_DIS
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_FASTFRAME_DIS
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_BURST_DIS
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_MAXQCU
value|0x01F0
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_MAXQCU_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_HEAVY_CLIP_EN
value|0x0200
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_KC_ENTRIES
value|0xF000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEPCAP_KC_ENTRIES_S
value|12
end_define

begin_define
define|#
directive|define
name|MSTATE
value|100
end_define

begin_define
define|#
directive|define
name|MOUTPUT
value|2048
end_define

begin_define
define|#
directive|define
name|MDEFAULT
value|15
end_define

begin_define
define|#
directive|define
name|MVALUE
value|100
end_define

begin_enum
enum|enum
name|CompressAlgorithm
block|{
name|_compress_none
init|=
literal|0
block|,
name|_compress_lzma
block|,
name|_compress_pairs
block|,
name|_compress_block
block|,
name|_compress4
block|,
name|_compress5
block|,
name|_compress6
block|,
name|_compress7
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|calibration_data_none
init|=
literal|0
block|,
name|calibration_data_dram
block|,
name|calibration_data_flash
block|,
name|calibration_data_eeprom
block|,
name|calibration_data_otp
block|,
ifdef|#
directive|ifdef
name|ATH_CAL_NAND_FLASH
name|calibration_data_nand
block|,
endif|#
directive|endif
name|CalibrationDataDontLoad
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|HOST_CALDATA_SIZE
value|(16*1024)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// DO NOT CHANGE THE DEFINTIONS OF THESE SYMBOLS.
end_comment

begin_comment
comment|// Add additional definitions to the end.
end_comment

begin_comment
comment|// Yes, the first one is 2. Do not use 0 or 1.
end_comment

begin_comment
comment|//
end_comment

begin_enum
enum|enum
name|Ar9300EepromTemplate
block|{
name|ar9300_eeprom_template_generic
init|=
literal|2
block|,
name|ar9300_eeprom_template_hb112
init|=
literal|3
block|,
name|ar9300_eeprom_template_hb116
init|=
literal|4
block|,
name|ar9300_eeprom_template_xb112
init|=
literal|5
block|,
name|ar9300_eeprom_template_xb113
init|=
literal|6
block|,
name|ar9300_eeprom_template_xb114
init|=
literal|7
block|,
name|ar9300_eeprom_template_tb417
init|=
literal|8
block|,
name|ar9300_eeprom_template_ap111
init|=
literal|9
block|,
name|ar9300_eeprom_template_ap121
init|=
literal|10
block|,
name|ar9300_eeprom_template_hornet_generic
init|=
literal|11
block|,
name|ar9300_eeprom_template_wasp_2
init|=
literal|12
block|,
name|ar9300_eeprom_template_wasp_k31
init|=
literal|13
block|,
name|ar9300_eeprom_template_osprey_k31
init|=
literal|14
block|,
name|ar9300_eeprom_template_aphrodite
init|=
literal|15
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|ar9300_eeprom_template_default
value|ar9300_eeprom_template_generic
end_define

begin_define
define|#
directive|define
name|Ar9300EepromFormatDefault
value|2
end_define

begin_define
define|#
directive|define
name|reference_current
value|0
end_define

begin_define
define|#
directive|define
name|compression_header_length
value|4
end_define

begin_define
define|#
directive|define
name|compression_checksum_length
value|2
end_define

begin_define
define|#
directive|define
name|OSPREY_EEP_VER
value|0xD000
end_define

begin_define
define|#
directive|define
name|OSPREY_EEP_VER_MINOR_MASK
value|0xFFF
end_define

begin_define
define|#
directive|define
name|OSPREY_EEP_MINOR_VER_1
value|0x1
end_define

begin_define
define|#
directive|define
name|OSPREY_EEP_MINOR_VER
value|OSPREY_EEP_MINOR_VER_1
end_define

begin_comment
comment|// 16-bit offset location start of calibration struct
end_comment

begin_define
define|#
directive|define
name|OSPREY_EEP_START_LOC
value|256
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_5G_CAL_PIERS
value|8
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_2G_CAL_PIERS
value|3
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_5G_20_TARGET_POWERS
value|8
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_5G_40_TARGET_POWERS
value|8
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_2G_CCK_TARGET_POWERS
value|2
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_2G_20_TARGET_POWERS
value|3
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_2G_40_TARGET_POWERS
value|3
end_define

begin_comment
comment|//#define OSPREY_NUM_CTLS              21
end_comment

begin_define
define|#
directive|define
name|OSPREY_NUM_CTLS_5G
value|9
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_CTLS_2G
value|12
end_define

begin_define
define|#
directive|define
name|OSPREY_CTL_MODE_M
value|0xF
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_BAND_EDGES_5G
value|8
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_BAND_EDGES_2G
value|4
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_PD_GAINS
value|4
end_define

begin_define
define|#
directive|define
name|OSPREY_PD_GAINS_IN_MASK
value|4
end_define

begin_define
define|#
directive|define
name|OSPREY_PD_GAIN_ICEPTS
value|5
end_define

begin_define
define|#
directive|define
name|OSPREY_EEPROM_MODAL_SPURS
value|5
end_define

begin_define
define|#
directive|define
name|OSPREY_MAX_RATE_POWER
value|63
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_PDADC_VALUES
value|128
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_RATES
value|16
end_define

begin_define
define|#
directive|define
name|OSPREY_BCHAN_UNUSED
value|0xFF
end_define

begin_define
define|#
directive|define
name|OSPREY_MAX_PWR_RANGE_IN_HALF_DB
value|64
end_define

begin_define
define|#
directive|define
name|OSPREY_OPFLAGS_11A
value|0x01
end_define

begin_define
define|#
directive|define
name|OSPREY_OPFLAGS_11G
value|0x02
end_define

begin_define
define|#
directive|define
name|OSPREY_OPFLAGS_5G_HT40
value|0x04
end_define

begin_define
define|#
directive|define
name|OSPREY_OPFLAGS_2G_HT40
value|0x08
end_define

begin_define
define|#
directive|define
name|OSPREY_OPFLAGS_5G_HT20
value|0x10
end_define

begin_define
define|#
directive|define
name|OSPREY_OPFLAGS_2G_HT20
value|0x20
end_define

begin_define
define|#
directive|define
name|OSPREY_EEPMISC_BIG_ENDIAN
value|0x01
end_define

begin_define
define|#
directive|define
name|OSPREY_EEPMISC_WOW
value|0x02
end_define

begin_define
define|#
directive|define
name|OSPREY_CUSTOMER_DATA_SIZE
value|20
end_define

begin_define
define|#
directive|define
name|FREQ2FBIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(((y) == HAL_FREQ_BAND_2GHZ) ? ((x) - 2300) : (((x) - 4800) / 5))
end_define

begin_define
define|#
directive|define
name|FBIN2FREQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(((y) == HAL_FREQ_BAND_2GHZ) ? (2300 + x) : (4800 + 5 * x))
end_define

begin_define
define|#
directive|define
name|OSPREY_MAX_CHAINS
value|3
end_define

begin_define
define|#
directive|define
name|OSPREY_ANT_16S
value|25
end_define

begin_define
define|#
directive|define
name|OSPREY_FUTURE_MODAL_SZ
value|6
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_ANT_CHAIN_FIELDS
value|7
end_define

begin_define
define|#
directive|define
name|OSPREY_NUM_ANT_COMMON_FIELDS
value|4
end_define

begin_define
define|#
directive|define
name|OSPREY_SIZE_ANT_CHAIN_FIELD
value|3
end_define

begin_define
define|#
directive|define
name|OSPREY_SIZE_ANT_COMMON_FIELD
value|4
end_define

begin_define
define|#
directive|define
name|OSPREY_ANT_CHAIN_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|OSPREY_ANT_COMMON_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|OSPREY_CHAIN_0_IDX
value|0
end_define

begin_define
define|#
directive|define
name|OSPREY_CHAIN_1_IDX
value|1
end_define

begin_define
define|#
directive|define
name|OSPREY_CHAIN_2_IDX
value|2
end_define

begin_define
define|#
directive|define
name|OSPREY_1_CHAINMASK
value|1
end_define

begin_define
define|#
directive|define
name|OSPREY_2LOHI_CHAINMASK
value|5
end_define

begin_define
define|#
directive|define
name|OSPREY_2LOMID_CHAINMASK
value|3
end_define

begin_define
define|#
directive|define
name|OSPREY_3_CHAINMASK
value|7
end_define

begin_define
define|#
directive|define
name|AR928X_NUM_ANT_CHAIN_FIELDS
value|6
end_define

begin_define
define|#
directive|define
name|AR928X_SIZE_ANT_CHAIN_FIELD
value|2
end_define

begin_define
define|#
directive|define
name|AR928X_ANT_CHAIN_MASK
value|0x3
end_define

begin_comment
comment|/* Delta from which to start power to pdadc table */
end_comment

begin_comment
comment|/* This offset is used in both open loop and closed loop power control  * schemes. In open loop power control, it is not really needed, but for  * the "sake of consistency" it was kept.  * For certain AP designs, this value is overwritten by the value in the flag  * "pwrTableOffset" just before writing the pdadc vs pwr into the chip registers.  */
end_comment

begin_define
define|#
directive|define
name|OSPREY_PWR_TABLE_OFFSET
value|0
end_define

begin_comment
comment|//enable flags for voltage and temp compensation
end_comment

begin_define
define|#
directive|define
name|ENABLE_TEMP_COMPENSATION
value|0x01
end_define

begin_define
define|#
directive|define
name|ENABLE_VOLT_COMPENSATION
value|0x02
end_define

begin_define
define|#
directive|define
name|FLASH_BASE_CALDATA_OFFSET
value|0x1000
end_define

begin_define
define|#
directive|define
name|AR9300_EEPROM_SIZE
value|16*1024
end_define

begin_comment
comment|// byte addressable
end_comment

begin_define
define|#
directive|define
name|FIXED_CCA_THRESHOLD
value|15
end_define

begin_typedef
typedef|typedef
struct|struct
name|eepFlags
block|{
name|u_int8_t
name|op_flags
decl_stmt|;
name|u_int8_t
name|eepMisc
decl_stmt|;
block|}
name|__packed
name|EEP_FLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|targetPowerHTRates
block|{
name|HT_TARGET_RATE_0_8_16
block|,
name|HT_TARGET_RATE_1_3_9_11_17_19
block|,
name|HT_TARGET_RATE_4
block|,
name|HT_TARGET_RATE_5
block|,
name|HT_TARGET_RATE_6
block|,
name|HT_TARGET_RATE_7
block|,
name|HT_TARGET_RATE_12
block|,
name|HT_TARGET_RATE_13
block|,
name|HT_TARGET_RATE_14
block|,
name|HT_TARGET_RATE_15
block|,
name|HT_TARGET_RATE_20
block|,
name|HT_TARGET_RATE_21
block|,
name|HT_TARGET_RATE_22
block|,
name|HT_TARGET_RATE_23
block|}
name|TARGET_POWER_HT_RATES
typedef|;
end_typedef

begin_decl_stmt
specifier|const
specifier|static
name|int
name|mapRate2Index
index|[
literal|24
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
name|targetPowerLegacyRates
block|{
name|LEGACY_TARGET_RATE_6_24
block|,
name|LEGACY_TARGET_RATE_36
block|,
name|LEGACY_TARGET_RATE_48
block|,
name|LEGACY_TARGET_RATE_54
block|}
name|TARGET_POWER_LEGACY_RATES
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|targetPowerCckRates
block|{
name|LEGACY_TARGET_RATE_1L_5L
block|,
name|LEGACY_TARGET_RATE_5S
block|,
name|LEGACY_TARGET_RATE_11L
block|,
name|LEGACY_TARGET_RATE_11S
block|}
name|TARGET_POWER_CCK_RATES
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_MODAL_RESERVED
value|11
end_define

begin_define
define|#
directive|define
name|MAX_MODAL_FUTURE
value|5
end_define

begin_define
define|#
directive|define
name|MAX_BASE_EXTENSION_FUTURE
value|2
end_define

begin_define
define|#
directive|define
name|MAX_TEMP_SLOPE
value|8
end_define

begin_define
define|#
directive|define
name|OSPREY_CHECKSUM_LOCATION
value|(OSPREY_EEP_START_LOC + 1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|osprey_BaseEepHeader
block|{
name|u_int16_t
name|reg_dmn
index|[
literal|2
index|]
decl_stmt|;
comment|//Does this need to be outside of this structure, if it gets written after calibration
name|u_int8_t
name|txrx_mask
decl_stmt|;
comment|//4 bits tx and 4 bits rx
name|EEP_FLAGS
name|op_cap_flags
decl_stmt|;
name|u_int8_t
name|rf_silent
decl_stmt|;
name|u_int8_t
name|blue_tooth_options
decl_stmt|;
name|u_int8_t
name|device_cap
decl_stmt|;
name|u_int8_t
name|device_type
decl_stmt|;
comment|// takes lower byte in eeprom location
name|int8_t
name|pwrTableOffset
decl_stmt|;
comment|// offset in dB to be added to beginning of pdadc table in calibration
name|u_int8_t
name|params_for_tuning_caps
index|[
literal|2
index|]
decl_stmt|;
comment|//placeholder, get more details from Don
name|u_int8_t
name|feature_enable
decl_stmt|;
comment|//bit0 - enable tx temp comp
comment|//bit1 - enable tx volt comp
comment|//bit2 - enable fastClock - default to 1
comment|//bit3 - enable doubling - default to 1
comment|//bit4 - enable internal regulator - default to 1
comment|//bit5 - enable paprd - default to 0
comment|//bit6 - enable TuningCaps - default to 0
comment|//bit7 - enable tx_frame_to_xpa_on - default to 0
name|u_int8_t
name|misc_configuration
decl_stmt|;
comment|//misc flags: bit0 - turn down drivestrength
comment|// bit 1:2 - 0=don't force, 1=force to thermometer 0, 2=force to thermometer 1, 3=force to thermometer 2
comment|// bit 3 - reduce chain mask from 0x7 to 0x3 on 2 stream rates
comment|// bit 4 - enable quick drop
comment|// bit 5 - enable 8 temp slop
comment|// bit 6;	enable xLNA_bias_strength
comment|// bit 7;	enable rf_gain_cap
name|u_int8_t
name|eeprom_write_enable_gpio
decl_stmt|;
name|u_int8_t
name|wlan_disable_gpio
decl_stmt|;
name|u_int8_t
name|wlan_led_gpio
decl_stmt|;
name|u_int8_t
name|rx_band_select_gpio
decl_stmt|;
name|u_int8_t
name|txrxgain
decl_stmt|;
name|u_int32_t
name|swreg
decl_stmt|;
comment|// SW controlled internal regulator fields
block|}
name|__packed
name|OSPREY_BASE_EEP_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|osprey_BaseExtension_1
block|{
name|u_int8_t
name|ant_div_control
decl_stmt|;
name|u_int8_t
name|future
index|[
name|MAX_BASE_EXTENSION_FUTURE
index|]
decl_stmt|;
name|u_int8_t
name|misc_enable
decl_stmt|;
name|int8_t
name|tempslopextension
index|[
name|MAX_TEMP_SLOPE
index|]
decl_stmt|;
name|int8_t
name|quick_drop_low
decl_stmt|;
name|int8_t
name|quick_drop_high
decl_stmt|;
block|}
name|__packed
name|OSPREY_BASE_EXTENSION_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|osprey_BaseExtension_2
block|{
name|int8_t
name|temp_slope_low
decl_stmt|;
name|int8_t
name|temp_slope_high
decl_stmt|;
name|u_int8_t
name|xatten1_db_low
index|[
name|OSPREY_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3  //xatten1_db for merlin (0xa20c/b20c 5:0)
name|u_int8_t
name|xatten1_margin_low
index|[
name|OSPREY_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3  //xatten1_margin for merlin (0xa20c/b20c 16:12
name|u_int8_t
name|xatten1_db_high
index|[
name|OSPREY_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3  //xatten1_db for merlin (0xa20c/b20c 5:0)
name|u_int8_t
name|xatten1_margin_high
index|[
name|OSPREY_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3  //xatten1_margin for merlin (0xa20c/b20c 16:12
block|}
name|__packed
name|OSPREY_BASE_EXTENSION_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|spurChanStruct
block|{
name|u_int16_t
name|spur_chan
decl_stmt|;
name|u_int8_t
name|spurRangeLow
decl_stmt|;
name|u_int8_t
name|spurRangeHigh
decl_stmt|;
block|}
name|__packed
name|SPUR_CHAN
typedef|;
end_typedef

begin_comment
comment|//Note the order of the fields in this structure has been optimized to put all fields likely to change together
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ospreyModalEepHeader
block|{
name|u_int32_t
name|ant_ctrl_common
decl_stmt|;
comment|// 4   idle, t1, t2, b (4 bits per setting)
name|u_int32_t
name|ant_ctrl_common2
decl_stmt|;
comment|// 4    ra1l1, ra2l1, ra1l2, ra2l2, ra12
name|u_int16_t
name|ant_ctrl_chain
index|[
name|OSPREY_MAX_CHAINS
index|]
decl_stmt|;
comment|// 6   idle, t, r, rx1, rx12, b (2 bits each)
name|u_int8_t
name|xatten1_db
index|[
name|OSPREY_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3  //xatten1_db for merlin (0xa20c/b20c 5:0)
name|u_int8_t
name|xatten1_margin
index|[
name|OSPREY_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3  //xatten1_margin for merlin (0xa20c/b20c 16:12
name|int8_t
name|temp_slope
decl_stmt|;
name|int8_t
name|voltSlope
decl_stmt|;
name|u_int8_t
name|spur_chans
index|[
name|OSPREY_EEPROM_MODAL_SPURS
index|]
decl_stmt|;
comment|// spur channels in usual fbin coding format
name|int8_t
name|noise_floor_thresh_ch
index|[
name|OSPREY_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3    //Check if the register is per chain
name|u_int8_t
name|reserved
index|[
name|MAX_MODAL_RESERVED
index|]
decl_stmt|;
name|int8_t
name|quick_drop
decl_stmt|;
name|u_int8_t
name|xpa_bias_lvl
decl_stmt|;
comment|// 1
name|u_int8_t
name|tx_frame_to_data_start
decl_stmt|;
comment|// 1
name|u_int8_t
name|tx_frame_to_pa_on
decl_stmt|;
comment|// 1
name|u_int8_t
name|txClip
decl_stmt|;
comment|// 4 bits tx_clip, 4 bits dac_scale_cck
name|int8_t
name|antenna_gain
decl_stmt|;
comment|// 1
name|u_int8_t
name|switchSettling
decl_stmt|;
comment|// 1
name|int8_t
name|adcDesiredSize
decl_stmt|;
comment|// 1
name|u_int8_t
name|tx_end_to_xpa_off
decl_stmt|;
comment|// 1
name|u_int8_t
name|txEndToRxOn
decl_stmt|;
comment|// 1
name|u_int8_t
name|tx_frame_to_xpa_on
decl_stmt|;
comment|// 1
name|u_int8_t
name|thresh62
decl_stmt|;
comment|// 1
name|u_int32_t
name|paprd_rate_mask_ht20
decl_stmt|;
name|u_int32_t
name|paprd_rate_mask_ht40
decl_stmt|;
name|u_int16_t
name|switchcomspdt
decl_stmt|;
name|u_int8_t
name|xLNA_bias_strength
decl_stmt|;
comment|// bit: 0,1:chain0, 2,3:chain1, 4,5:chain2
name|u_int8_t
name|rf_gain_cap
decl_stmt|;
name|u_int8_t
name|tx_gain_cap
decl_stmt|;
comment|// bit0:4 txgain cap, txgain index for max_txgain + 20 (10dBm higher than max txgain)
name|u_int8_t
name|futureModal
index|[
name|MAX_MODAL_FUTURE
index|]
decl_stmt|;
comment|// last 12 bytes stolen and moved to newly created base extension structure
block|}
name|__packed
name|OSPREY_MODAL_EEP_HEADER
typedef|;
end_typedef

begin_comment
comment|// == 100 B
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ospCalDataPerFreqOpLoop
block|{
name|int8_t
name|ref_power
decl_stmt|;
comment|/*   */
name|u_int8_t
name|volt_meas
decl_stmt|;
comment|/* pdadc voltage at power measurement */
name|u_int8_t
name|temp_meas
decl_stmt|;
comment|/* pcdac used for power measurement   */
name|int8_t
name|rx_noisefloor_cal
decl_stmt|;
comment|/*range is -60 to -127 create a mapping equation 1db resolution */
name|int8_t
name|rx_noisefloor_power
decl_stmt|;
comment|/*range is same as noisefloor */
name|u_int8_t
name|rxTempMeas
decl_stmt|;
comment|/*temp measured when noisefloor cal was performed */
block|}
name|__packed
name|OSP_CAL_DATA_PER_FREQ_OP_LOOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|CalTargetPowerLegacy
block|{
name|u_int8_t
name|t_pow2x
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
name|CAL_TARGET_POWER_LEG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ospCalTargetPowerHt
block|{
name|u_int8_t
name|t_pow2x
index|[
literal|14
index|]
decl_stmt|;
block|}
name|__packed
name|OSP_CAL_TARGET_POWER_HT
typedef|;
end_typedef

begin_if
if|#
directive|if
name|AH_BYTE_ORDER
operator|==
name|AH_BIG_ENDIAN
end_if

begin_typedef
typedef|typedef
struct|struct
name|CalCtlEdgePwr
block|{
name|u_int8_t
name|flag
range|:
literal|2
decl_stmt|,
name|t_power
range|:
literal|6
decl_stmt|;
block|}
name|__packed
name|CAL_CTL_EDGE_PWR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
name|CalCtlEdgePwr
block|{
name|u_int8_t
name|t_power
range|:
literal|6
decl_stmt|,
name|flag
range|:
literal|2
decl_stmt|;
block|}
name|__packed
name|CAL_CTL_EDGE_PWR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|ospCalCtlData_5G
block|{
name|CAL_CTL_EDGE_PWR
name|ctl_edges
index|[
name|OSPREY_NUM_BAND_EDGES_5G
index|]
decl_stmt|;
block|}
name|__packed
name|OSP_CAL_CTL_DATA_5G
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ospCalCtlData_2G
block|{
name|CAL_CTL_EDGE_PWR
name|ctl_edges
index|[
name|OSPREY_NUM_BAND_EDGES_2G
index|]
decl_stmt|;
block|}
name|__packed
name|OSP_CAL_CTL_DATA_2G
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ospreyEeprom
block|{
name|u_int8_t
name|eeprom_version
decl_stmt|;
name|u_int8_t
name|template_version
decl_stmt|;
name|u_int8_t
name|mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|custData
index|[
name|OSPREY_CUSTOMER_DATA_SIZE
index|]
decl_stmt|;
name|OSPREY_BASE_EEP_HEADER
name|base_eep_header
decl_stmt|;
name|OSPREY_MODAL_EEP_HEADER
name|modal_header_2g
decl_stmt|;
name|OSPREY_BASE_EXTENSION_1
name|base_ext1
decl_stmt|;
name|u_int8_t
name|cal_freq_pier_2g
index|[
name|OSPREY_NUM_2G_CAL_PIERS
index|]
decl_stmt|;
name|OSP_CAL_DATA_PER_FREQ_OP_LOOP
name|cal_pier_data_2g
index|[
name|OSPREY_MAX_CHAINS
index|]
index|[
name|OSPREY_NUM_2G_CAL_PIERS
index|]
decl_stmt|;
name|u_int8_t
name|cal_target_freqbin_cck
index|[
name|OSPREY_NUM_2G_CCK_TARGET_POWERS
index|]
decl_stmt|;
name|u_int8_t
name|cal_target_freqbin_2g
index|[
name|OSPREY_NUM_2G_20_TARGET_POWERS
index|]
decl_stmt|;
name|u_int8_t
name|cal_target_freqbin_2g_ht20
index|[
name|OSPREY_NUM_2G_20_TARGET_POWERS
index|]
decl_stmt|;
name|u_int8_t
name|cal_target_freqbin_2g_ht40
index|[
name|OSPREY_NUM_2G_40_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_LEG
name|cal_target_power_cck
index|[
name|OSPREY_NUM_2G_CCK_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_LEG
name|cal_target_power_2g
index|[
name|OSPREY_NUM_2G_20_TARGET_POWERS
index|]
decl_stmt|;
name|OSP_CAL_TARGET_POWER_HT
name|cal_target_power_2g_ht20
index|[
name|OSPREY_NUM_2G_20_TARGET_POWERS
index|]
decl_stmt|;
name|OSP_CAL_TARGET_POWER_HT
name|cal_target_power_2g_ht40
index|[
name|OSPREY_NUM_2G_40_TARGET_POWERS
index|]
decl_stmt|;
name|u_int8_t
name|ctl_index_2g
index|[
name|OSPREY_NUM_CTLS_2G
index|]
decl_stmt|;
name|u_int8_t
name|ctl_freqbin_2G
index|[
name|OSPREY_NUM_CTLS_2G
index|]
index|[
name|OSPREY_NUM_BAND_EDGES_2G
index|]
decl_stmt|;
name|OSP_CAL_CTL_DATA_2G
name|ctl_power_data_2g
index|[
name|OSPREY_NUM_CTLS_2G
index|]
decl_stmt|;
name|OSPREY_MODAL_EEP_HEADER
name|modal_header_5g
decl_stmt|;
name|OSPREY_BASE_EXTENSION_2
name|base_ext2
decl_stmt|;
name|u_int8_t
name|cal_freq_pier_5g
index|[
name|OSPREY_NUM_5G_CAL_PIERS
index|]
decl_stmt|;
name|OSP_CAL_DATA_PER_FREQ_OP_LOOP
name|cal_pier_data_5g
index|[
name|OSPREY_MAX_CHAINS
index|]
index|[
name|OSPREY_NUM_5G_CAL_PIERS
index|]
decl_stmt|;
name|u_int8_t
name|cal_target_freqbin_5g
index|[
name|OSPREY_NUM_5G_20_TARGET_POWERS
index|]
decl_stmt|;
name|u_int8_t
name|cal_target_freqbin_5g_ht20
index|[
name|OSPREY_NUM_5G_20_TARGET_POWERS
index|]
decl_stmt|;
name|u_int8_t
name|cal_target_freqbin_5g_ht40
index|[
name|OSPREY_NUM_5G_40_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_LEG
name|cal_target_power_5g
index|[
name|OSPREY_NUM_5G_20_TARGET_POWERS
index|]
decl_stmt|;
name|OSP_CAL_TARGET_POWER_HT
name|cal_target_power_5g_ht20
index|[
name|OSPREY_NUM_5G_20_TARGET_POWERS
index|]
decl_stmt|;
name|OSP_CAL_TARGET_POWER_HT
name|cal_target_power_5g_ht40
index|[
name|OSPREY_NUM_5G_40_TARGET_POWERS
index|]
decl_stmt|;
name|u_int8_t
name|ctl_index_5g
index|[
name|OSPREY_NUM_CTLS_5G
index|]
decl_stmt|;
name|u_int8_t
name|ctl_freqbin_5G
index|[
name|OSPREY_NUM_CTLS_5G
index|]
index|[
name|OSPREY_NUM_BAND_EDGES_5G
index|]
decl_stmt|;
name|OSP_CAL_CTL_DATA_5G
name|ctl_power_data_5g
index|[
name|OSPREY_NUM_CTLS_5G
index|]
decl_stmt|;
block|}
name|__packed
name|ar9300_eeprom_t
typedef|;
end_typedef

begin_comment
comment|/* ** SWAP Functions ** used to read EEPROM data, which is apparently stored in little ** endian form.  We have included both forms of the swap functions, ** one for big endian and one for little endian.  The indices of the ** array elements are the differences */
end_comment

begin_if
if|#
directive|if
name|AH_BYTE_ORDER
operator|==
name|AH_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|AR9300_EEPROM_MAGIC
value|0x5aa5
end_define

begin_define
define|#
directive|define
name|SWAP16
parameter_list|(
name|_x
parameter_list|)
value|( (u_int16_t)( (((const u_int8_t *)(&_x))[0] ) |\                      ( ( (const u_int8_t *)(&_x ) )[1]<< 8) ) )
end_define

begin_define
define|#
directive|define
name|SWAP32
parameter_list|(
name|_x
parameter_list|)
value|((u_int32_t)(                       \                     (((const u_int8_t *)(&_x))[0]) |        \                     (((const u_int8_t *)(&_x))[1]<< 8) |    \                     (((const u_int8_t *)(&_x))[2]<<16) |    \                     (((const u_int8_t *)(&_x))[3]<<24)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// AH_BYTE_ORDER
end_comment

begin_define
define|#
directive|define
name|AR9300_EEPROM_MAGIC
value|0xa55a
end_define

begin_define
define|#
directive|define
name|SWAP16
parameter_list|(
name|_x
parameter_list|)
value|( (u_int16_t)( (((const u_int8_t *)(&_x))[1] ) |\                         ( ( (const u_int8_t *)(&_x ) )[0]<< 8) ) )
end_define

begin_define
define|#
directive|define
name|SWAP32
parameter_list|(
name|_x
parameter_list|)
value|((u_int32_t)(                       \                     (((const u_int8_t *)(&_x))[3]) |        \                     (((const u_int8_t *)(&_x))[2]<< 8) |    \                     (((const u_int8_t *)(&_x))[1]<<16) |    \                     (((const u_int8_t *)(&_x))[0]<<24)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AH_BYTE_ORDER
end_comment

begin_comment
comment|// OTP registers for OSPREY
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_IN_OUT
value|0x4048
end_define

begin_comment
comment|// GPIO input / output register
end_comment

begin_define
define|#
directive|define
name|OTP_MEM_START_ADDRESS
value|0x14000
end_define

begin_define
define|#
directive|define
name|OTP_STATUS0_OTP_SM_BUSY
value|0x00015f18
end_define

begin_define
define|#
directive|define
name|OTP_STATUS1_EFUSE_READ_DATA
value|0x00015f1c
end_define

begin_define
define|#
directive|define
name|OTP_LDO_CONTROL_ENABLE
value|0x00015f24
end_define

begin_define
define|#
directive|define
name|OTP_LDO_STATUS_POWER_ON
value|0x00015f2c
end_define

begin_define
define|#
directive|define
name|OTP_INTF0_EFUSE_WR_ENABLE_REG_V
value|0x00015f00
end_define

begin_comment
comment|// OTP register for Jupiter
end_comment

begin_define
define|#
directive|define
name|GLB_OTP_LDO_CONTROL_ENABLE
value|0x00020020
end_define

begin_define
define|#
directive|define
name|GLB_OTP_LDO_STATUS_POWER_ON
value|0x00020028
end_define

begin_define
define|#
directive|define
name|OTP_PGENB_SETUP_HOLD_TIME_DELAY
value|0x15f34
end_define

begin_comment
comment|// OTP register for Jupiter BT
end_comment

begin_define
define|#
directive|define
name|BTOTP_MEM_START_ADDRESS
value|0x64000
end_define

begin_define
define|#
directive|define
name|BTOTP_STATUS0_OTP_SM_BUSY
value|0x00065f18
end_define

begin_define
define|#
directive|define
name|BTOTP_STATUS1_EFUSE_READ_DATA
value|0x00065f1c
end_define

begin_define
define|#
directive|define
name|BTOTP_INTF0_EFUSE_WR_ENABLE_REG_V
value|0x00065f00
end_define

begin_define
define|#
directive|define
name|BTOTP_INTF2
value|0x00065f08
end_define

begin_define
define|#
directive|define
name|BTOTP_PGENB_SETUP_HOLD_TIME_DELAY
value|0x65f34
end_define

begin_define
define|#
directive|define
name|BT_RESET_CTL
value|0x44000
end_define

begin_define
define|#
directive|define
name|BT_CLOCK_CONTROL
value|0x44028
end_define

begin_comment
comment|// OTP register for WASP
end_comment

begin_define
define|#
directive|define
name|OTP_MEM_START_ADDRESS_WASP
value|0x00030000
end_define

begin_define
define|#
directive|define
name|OTP_STATUS0_OTP_SM_BUSY_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x1018)
end_define

begin_define
define|#
directive|define
name|OTP_STATUS1_EFUSE_READ_DATA_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x101C)
end_define

begin_define
define|#
directive|define
name|OTP_LDO_CONTROL_ENABLE_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x1024)
end_define

begin_define
define|#
directive|define
name|OTP_LDO_STATUS_POWER_ON_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x102C)
end_define

begin_define
define|#
directive|define
name|OTP_INTF0_EFUSE_WR_ENABLE_REG_V_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x1000)
end_define

begin_comment
comment|// Below control the access timing of OTP read/write
end_comment

begin_define
define|#
directive|define
name|OTP_PG_STROBE_PW_REG_V_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x1008)
end_define

begin_define
define|#
directive|define
name|OTP_RD_STROBE_PW_REG_V_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x100C)
end_define

begin_define
define|#
directive|define
name|OTP_VDDQ_HOLD_TIME_DELAY_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x1030)
end_define

begin_define
define|#
directive|define
name|OTP_PGENB_SETUP_HOLD_TIME_DELAY_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x1034)
end_define

begin_define
define|#
directive|define
name|OTP_STROBE_PULSE_INTERVAL_DELAY_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x1038)
end_define

begin_define
define|#
directive|define
name|OTP_CSB_ADDR_LOAD_SETUP_HOLD_DELAY_WASP
value|(OTP_MEM_START_ADDRESS_WASP + 0x103C)
end_define

begin_define
define|#
directive|define
name|AR9300_EEPROM_MAGIC_OFFSET
value|0x0
end_define

begin_comment
comment|/* reg_off = 4 * (eep_off) */
end_comment

begin_define
define|#
directive|define
name|AR9300_EEPROM_S
value|2
end_define

begin_define
define|#
directive|define
name|AR9300_EEPROM_OFFSET
value|0x2000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AR9100
end_ifdef

begin_define
define|#
directive|define
name|AR9300_EEPROM_START_ADDR
value|0x1fff1000
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AR9300_EEPROM_START_ADDR
value|0x503f1200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AR9300_FLASH_CAL_START_OFFSET
value|0x1000
end_define

begin_define
define|#
directive|define
name|AR9300_EEPROM_MAX
value|0xae0
end_define

begin_define
define|#
directive|define
name|IS_EEP_MINOR_V3
parameter_list|(
name|_ahp
parameter_list|)
value|(ar9300_eeprom_get((_ahp), EEP_MINOR_REV)>= AR9300_EEP_MINOR_VER_3)
end_define

begin_define
define|#
directive|define
name|ar9300_get_ntxchains
parameter_list|(
name|_txchainmask
parameter_list|)
define|\
value|(((_txchainmask>> 2)& 1) + ((_txchainmask>> 1)& 1) + (_txchainmask& 1))
end_define

begin_comment
comment|/* RF silent fields in \ */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_ENABLED
value|0x0001
end_define

begin_comment
comment|/* bit 0: enabled/disabled */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_ENABLED_S
value|0
end_define

begin_comment
comment|/* bit 0: enabled/disabled */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_POLARITY
value|0x0002
end_define

begin_comment
comment|/* bit 1: polarity */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_POLARITY_S
value|1
end_define

begin_comment
comment|/* bit 1: polarity */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_GPIO_SEL
value|0x00fc
end_define

begin_comment
comment|/* bits 2..7: gpio PIN */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_GPIO_SEL_S
value|2
end_define

begin_comment
comment|/* bits 2..7: gpio PIN */
end_comment

begin_define
define|#
directive|define
name|AR9300_EEP_VER
value|0xE
end_define

begin_define
define|#
directive|define
name|AR9300_BCHAN_UNUSED
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR9300_MAX_RATE_POWER
value|63
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|CALDATA_AUTO
init|=
literal|0
block|,
name|CALDATA_EEPROM
block|,
name|CALDATA_FLASH
block|,
name|CALDATA_OTP
block|}
name|CALDATA_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EEP_NFTHRESH_5
block|,
name|EEP_NFTHRESH_2
block|,
name|EEP_MAC_MSW
block|,
name|EEP_MAC_MID
block|,
name|EEP_MAC_LSW
block|,
name|EEP_REG_0
block|,
name|EEP_REG_1
block|,
name|EEP_OP_CAP
block|,
name|EEP_OP_MODE
block|,
name|EEP_RF_SILENT
block|,
name|EEP_OB_5
block|,
name|EEP_DB_5
block|,
name|EEP_OB_2
block|,
name|EEP_DB_2
block|,
name|EEP_MINOR_REV
block|,
name|EEP_TX_MASK
block|,
name|EEP_RX_MASK
block|,
name|EEP_FSTCLK_5G
block|,
name|EEP_RXGAIN_TYPE
block|,
name|EEP_OL_PWRCTRL
block|,
name|EEP_TXGAIN_TYPE
block|,
name|EEP_RC_CHAIN_MASK
block|,
name|EEP_DAC_HPWR_5G
block|,
name|EEP_FRAC_N_5G
block|,
name|EEP_DEV_TYPE
block|,
name|EEP_TEMPSENSE_SLOPE
block|,
name|EEP_TEMPSENSE_SLOPE_PAL_ON
block|,
name|EEP_PWR_TABLE_OFFSET
block|,
name|EEP_DRIVE_STRENGTH
block|,
name|EEP_INTERNAL_REGULATOR
block|,
name|EEP_SWREG
block|,
name|EEP_PAPRD_ENABLED
block|,
name|EEP_ANTDIV_control
block|,
name|EEP_CHAIN_MASK_REDUCE
block|, }
name|EEPROM_PARAM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AR9300_RATES_OFDM_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|AR9300_RATES_CCK_OFFSET
value|4
end_define

begin_define
define|#
directive|define
name|AR9300_RATES_HT20_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|AR9300_RATES_HT40_OFFSET
value|22
end_define

begin_typedef
typedef|typedef
enum|enum
name|ar9300_Rates
block|{
name|ALL_TARGET_LEGACY_6_24
block|,
name|ALL_TARGET_LEGACY_36
block|,
name|ALL_TARGET_LEGACY_48
block|,
name|ALL_TARGET_LEGACY_54
block|,
name|ALL_TARGET_LEGACY_1L_5L
block|,
name|ALL_TARGET_LEGACY_5S
block|,
name|ALL_TARGET_LEGACY_11L
block|,
name|ALL_TARGET_LEGACY_11S
block|,
name|ALL_TARGET_HT20_0_8_16
block|,
name|ALL_TARGET_HT20_1_3_9_11_17_19
block|,
name|ALL_TARGET_HT20_4
block|,
name|ALL_TARGET_HT20_5
block|,
name|ALL_TARGET_HT20_6
block|,
name|ALL_TARGET_HT20_7
block|,
name|ALL_TARGET_HT20_12
block|,
name|ALL_TARGET_HT20_13
block|,
name|ALL_TARGET_HT20_14
block|,
name|ALL_TARGET_HT20_15
block|,
name|ALL_TARGET_HT20_20
block|,
name|ALL_TARGET_HT20_21
block|,
name|ALL_TARGET_HT20_22
block|,
name|ALL_TARGET_HT20_23
block|,
name|ALL_TARGET_HT40_0_8_16
block|,
name|ALL_TARGET_HT40_1_3_9_11_17_19
block|,
name|ALL_TARGET_HT40_4
block|,
name|ALL_TARGET_HT40_5
block|,
name|ALL_TARGET_HT40_6
block|,
name|ALL_TARGET_HT40_7
block|,
name|ALL_TARGET_HT40_12
block|,
name|ALL_TARGET_HT40_13
block|,
name|ALL_TARGET_HT40_14
block|,
name|ALL_TARGET_HT40_15
block|,
name|ALL_TARGET_HT40_20
block|,
name|ALL_TARGET_HT40_21
block|,
name|ALL_TARGET_HT40_22
block|,
name|ALL_TARGET_HT40_23
block|,
name|ar9300_rate_size
block|}
name|AR9300_RATES
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  * fbin2freq  *  * Get channel value from binary representation held in eeprom  * RETURNS: the frequency in MHz  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int16_t
name|fbin2freq
parameter_list|(
name|u_int8_t
name|fbin
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
block|{
comment|/*     * Reserved value 0xFF provides an empty definition both as     * an fbin and as a frequency - do not convert     */
if|if
condition|(
name|fbin
operator|==
name|AR9300_BCHAN_UNUSED
condition|)
block|{
return|return
name|fbin
return|;
block|}
return|return
call|(
name|u_int16_t
call|)
argument_list|(
operator|(
name|is_2ghz
operator|)
condition|?
operator|(
literal|2300
operator|+
name|fbin
operator|)
else|:
operator|(
literal|4800
operator|+
literal|5
operator|*
name|fbin
operator|)
argument_list|)
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|CompressionHeaderUnpack
parameter_list|(
name|u_int8_t
modifier|*
name|best
parameter_list|,
name|int
modifier|*
name|code
parameter_list|,
name|int
modifier|*
name|reference
parameter_list|,
name|int
modifier|*
name|length
parameter_list|,
name|int
modifier|*
name|major
parameter_list|,
name|int
modifier|*
name|minor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Ar9300EepromFormatConvert
parameter_list|(
name|ar9300_eeprom_t
modifier|*
name|mptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_eeprom_restore
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_eeprom_restore_internal
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|ar9300_eeprom_t
modifier|*
name|mptr
parameter_list|,
name|int
comment|/*msize*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_eeprom_base_address
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_eeprom_volatile
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_eeprom_low_limit
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int16_t
name|ar9300_compression_checksum
parameter_list|(
name|u_int8_t
modifier|*
name|data
parameter_list|,
name|int
name|dsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_compression_header_unpack
parameter_list|(
name|u_int8_t
modifier|*
name|best
parameter_list|,
name|int
modifier|*
name|code
parameter_list|,
name|int
modifier|*
name|reference
parameter_list|,
name|int
modifier|*
name|length
parameter_list|,
name|int
modifier|*
name|major
parameter_list|,
name|int
modifier|*
name|minor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int16_t
name|ar9300_eeprom_struct_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ar9300_eeprom_t
modifier|*
name|ar9300EepromStructInit
parameter_list|(
name|int
name|default_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ar9300_eeprom_t
modifier|*
name|ar9300EepromStructGet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ar9300_eeprom_t
modifier|*
name|ar9300_eeprom_struct_default
parameter_list|(
name|int
name|default_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ar9300_eeprom_t
modifier|*
name|ar9300_eeprom_struct_default_find_by_id
parameter_list|(
name|int
name|ver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_eeprom_struct_default_many
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300EepromUpdateCalPier
parameter_list|(
name|int
name|pierIdx
parameter_list|,
name|int
name|freq
parameter_list|,
name|int
name|chain
parameter_list|,
name|int
name|pwrCorrection
parameter_list|,
name|int
name|volt_meas
parameter_list|,
name|int
name|temp_meas
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_power_control_override
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|frequency
parameter_list|,
name|int
modifier|*
name|correction
parameter_list|,
name|int
modifier|*
name|voltage
parameter_list|,
name|int
modifier|*
name|temperature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300EepromDisplayCalData
parameter_list|(
name|int
name|for2GHz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300EepromDisplayAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_target_power_from_eeprom
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int16_t
name|freq
parameter_list|,
name|u_int8_t
modifier|*
name|target_power_val_t2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_eeprom_set_power_per_rate_table
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|ar9300_eeprom_t
modifier|*
name|p_eep_data
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|,
name|u_int8_t
modifier|*
name|p_pwr_array
parameter_list|,
name|u_int16_t
name|cfg_ctl
parameter_list|,
name|u_int16_t
name|antenna_reduction
parameter_list|,
name|u_int16_t
name|twice_max_regulatory_power
parameter_list|,
name|u_int16_t
name|power_limit
parameter_list|,
name|u_int8_t
name|chainmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_transmit_power_reg_write
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int8_t
modifier|*
name|p_pwr_array
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int8_t
name|ar9300_eeprom_get_legacy_trgt_pwr
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int16_t
name|rate_index
parameter_list|,
name|u_int16_t
name|freq
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int8_t
name|ar9300_eeprom_get_ht20_trgt_pwr
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int16_t
name|rate_index
parameter_list|,
name|u_int16_t
name|freq
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int8_t
name|ar9300_eeprom_get_ht40_trgt_pwr
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int16_t
name|rate_index
parameter_list|,
name|u_int16_t
name|freq
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int8_t
name|ar9300_eeprom_get_cck_trgt_pwr
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int16_t
name|rate_index
parameter_list|,
name|u_int16_t
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_internal_regulator_apply
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_drive_strength_apply
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_attenuation_apply
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int16_t
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_thermometer_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_thermometer_apply
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_xpa_timing_control_apply
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_x_lNA_bias_strength_apply
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300MacAdressGet
parameter_list|(
name|u_int8_t
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300CustomerDataGet
parameter_list|(
name|u_int8_t
modifier|*
name|data
parameter_list|,
name|int32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300ReconfigDriveStrengthGet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300EnableTempCompensationGet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300EnableVoltCompensationGet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300FastClockEnableGet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300EnableDoublingGet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int16_t
modifier|*
name|ar9300_regulatory_domain_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_eeprom_write_enable_gpio_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_wlan_led_gpio_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_wlan_disable_gpio_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_rx_band_select_gpio_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_rx_gain_index_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_tx_gain_index_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_xpa_bias_level_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_xpa_bias_level_apply
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|ar9300_ant_ctrl_common_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|ar9300_ant_ctrl_common2_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int16_t
name|ar9300_ant_ctrl_chain_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|chain
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_ant_ctrl_apply
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_2ghz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* since valid noise floor values are negative, returns 1 on error */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_noise_floor_cal_or_power_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int32_t
name|frequency
parameter_list|,
name|int32_t
name|ichain
parameter_list|,
name|HAL_BOOL
name|use_cal
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ar9300NoiseFloorGet
parameter_list|(
name|ah
parameter_list|,
name|frequency
parameter_list|,
name|ichain
parameter_list|)
define|\
value|ar9300_noise_floor_cal_or_power_get(ah, frequency, ichain, 1
comment|/*use_cal*/
value|)
end_define

begin_define
define|#
directive|define
name|ar9300NoiseFloorPowerGet
parameter_list|(
name|ah
parameter_list|,
name|frequency
parameter_list|,
name|ichain
parameter_list|)
define|\
value|ar9300_noise_floor_cal_or_power_get(ah, frequency, ichain, 0
comment|/*use_cal*/
value|)
end_define

begin_function_decl
specifier|extern
name|void
name|ar9300_eeprom_template_preference
parameter_list|(
name|int32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_eeprom_template_install
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_calibration_data_set
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int32_t
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_calibration_data_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_calibration_data_address_get
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_calibration_data_address_set
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int32_t
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_calibration_data_read_flash
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|long
name|address
parameter_list|,
name|u_int8_t
modifier|*
name|buffer
parameter_list|,
name|int
name|many
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_calibration_data_read_eeprom
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|long
name|address
parameter_list|,
name|u_int8_t
modifier|*
name|buffer
parameter_list|,
name|int
name|many
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_calibration_data_read_otp
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|long
name|address
parameter_list|,
name|u_int8_t
modifier|*
name|buffer
parameter_list|,
name|int
name|many
parameter_list|,
name|HAL_BOOL
name|is_wifi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_calibration_data_read
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|long
name|address
parameter_list|,
name|u_int8_t
modifier|*
name|buffer
parameter_list|,
name|int
name|many
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_eeprom_size
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|ar9300_otp_size
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_calibration_data_read_array
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|address
parameter_list|,
name|u_int8_t
modifier|*
name|buffer
parameter_list|,
name|int
name|many
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN64
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|,
name|ar9300
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AR9300_EEP_H_ */
end_comment

end_unit

