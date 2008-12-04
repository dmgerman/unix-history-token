begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ah_eeprom_v3.h,v 1.2 2008/11/10 04:08:00 sam Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_EEPROM_V3_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_EEPROM_V3_H_
end_define

begin_include
include|#
directive|include
file|"ah_eeprom.h"
end_include

begin_comment
comment|/* EEPROM defines for Version 2& 3 AR5211 chips */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT
value|0x0f
end_define

begin_comment
comment|/* RF Silent/Clock Run Enable */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_MAC
parameter_list|(
name|i
parameter_list|)
value|(0x1d+(i))
end_define

begin_comment
comment|/* MAC address word */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_MAGIC
value|0x3d
end_define

begin_comment
comment|/* magic number */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT
value|0x3f
end_define

begin_comment
comment|/* EEPROM protect bits */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_PCIE
value|0x01
end_define

begin_comment
comment|/* EEPROM protect bits for Condor/Swan*/
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_REG_DOMAIN
value|0xbf
end_define

begin_comment
comment|/* current regulatory domain */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS_BASE
value|0xc0
end_define

begin_comment
comment|/* Base of Atheros-specific data */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS
parameter_list|(
name|i
parameter_list|)
value|(AR_EEPROM_ATHEROS_BASE+(i))
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS_MAX
value|(0x400-AR_EEPROM_ATHEROS_BASE)
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VERSION
value|AR_EEPROM_ATHEROS(1)
end_define

begin_comment
comment|/* FLASH(EEPROM) Defines for AR531X chips */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_SIZE_LOWER
value|0x1b
end_define

begin_comment
comment|/* size info -- lower */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_SIZE_UPPER
value|0x1c
end_define

begin_comment
comment|/* size info -- upper */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_SIZE_UPPER_MASK
value|0xfff0
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_SIZE_UPPER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_SIZE_ENDLOC_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS_MAX_LOC
value|0x400
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_ATHEROS_MAX_OFF
value|(AR_EEPROM_ATHEROS_MAX_LOC-AR_EEPROM_ATHEROS_BASE)
end_define

begin_comment
comment|/* regulatory capabilities offsets */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_REG_CAPABILITIES_OFFSET
value|0xCA
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_REG_CAPABILITIES_OFFSET_PRE4_0
value|0xCF
end_define

begin_comment
comment|/* prior to 4.0 */
end_comment

begin_comment
comment|/* regulatory capabilities */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_EEREGCAP_EN_FCC_MIDBAND
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEREGCAP_EN_KK_U1_EVEN
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEREGCAP_EN_KK_U2
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEREGCAP_EN_KK_MIDBAND
value|0x0200
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEREGCAP_EN_KK_U1_ODD
value|0x0400
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEREGCAP_EN_KK_NEW_11A
value|0x0800
end_define

begin_comment
comment|/* regulatory capabilities prior to eeprom version 4.0 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_EEREGCAP_EN_KK_U1_ODD_PRE4_0
value|0x4000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_EEREGCAP_EN_KK_NEW_11A_PRE4_0
value|0x8000
end_define

begin_comment
comment|/*  * AR2413 (includes AR5413)  */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_SERIAL_NUM_OFFSET
value|0xB0
end_define

begin_comment
comment|/* EEPROM serial number */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_SERIAL_NUM_SIZE
value|12
end_define

begin_comment
comment|/* EEPROM serial number size */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CAPABILITIES_OFFSET
value|0xC9
end_define

begin_comment
comment|/* EEPROM Location of capabilities */
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

begin_comment
comment|/* XXX used to index various EEPROM-derived data structures */
end_comment

begin_enum
enum|enum
block|{
name|headerInfo11A
init|=
literal|0
block|,
name|headerInfo11B
init|=
literal|1
block|,
name|headerInfo11G
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|GROUPS_OFFSET3_2
value|0x100
end_define

begin_comment
comment|/* groups offset for ver3.2 and earlier */
end_comment

begin_define
define|#
directive|define
name|GROUPS_OFFSET3_3
value|0x150
end_define

begin_comment
comment|/* groups offset for ver3.3 */
end_comment

begin_comment
comment|/* relative offset of GROUPi to GROUPS_OFFSET */
end_comment

begin_define
define|#
directive|define
name|GROUP1_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|GROUP2_OFFSET
value|0x5
end_define

begin_define
define|#
directive|define
name|GROUP3_OFFSET
value|0x37
end_define

begin_define
define|#
directive|define
name|GROUP4_OFFSET
value|0x46
end_define

begin_define
define|#
directive|define
name|GROUP5_OFFSET
value|0x55
end_define

begin_define
define|#
directive|define
name|GROUP6_OFFSET
value|0x65
end_define

begin_define
define|#
directive|define
name|GROUP7_OFFSET
value|0x69
end_define

begin_define
define|#
directive|define
name|GROUP8_OFFSET
value|0x6f
end_define

begin_comment
comment|/* RF silent fields in EEPROM */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT_GPIO_SEL
value|0x001c
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT_GPIO_SEL_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT_POLARITY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_RFSILENT_POLARITY_S
value|1
end_define

begin_comment
comment|/* Protect Bits RP is read protect, WP is write protect */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_RP_0_31
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_WP_0_31
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_RP_32_63
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_WP_32_63
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_RP_64_127
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_WP_64_127
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_RP_128_191
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_WP_128_191
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_RP_192_207
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_WP_192_207
value|0x0200
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_RP_208_223
value|0x0400
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_WP_208_223
value|0x0800
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_RP_224_239
value|0x1000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_WP_224_239
value|0x2000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_RP_240_255
value|0x4000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROTECT_WP_240_255
value|0x8000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_MODAL_SPURS
value|5
end_define

begin_define
define|#
directive|define
name|AR_SPUR_5413_1
value|1640
end_define

begin_comment
comment|/* Freq 2464 */
end_comment

begin_define
define|#
directive|define
name|AR_SPUR_5413_2
value|1200
end_define

begin_comment
comment|/* Freq 2420 */
end_comment

begin_comment
comment|/*  * EEPROM fixed point conversion scale factors.  * NB: if you change one be sure to keep the other in sync.  */
end_comment

begin_define
define|#
directive|define
name|EEP_SCALE
value|100
end_define

begin_comment
comment|/* conversion scale to avoid fp arith */
end_comment

begin_define
define|#
directive|define
name|EEP_DELTA
value|10
end_define

begin_comment
comment|/* SCALE/10, to avoid arith divide */
end_comment

begin_define
define|#
directive|define
name|PWR_MIN
value|0
end_define

begin_define
define|#
directive|define
name|PWR_MAX
value|3150
end_define

begin_comment
comment|/* 31.5 * SCALE */
end_comment

begin_define
define|#
directive|define
name|PWR_STEP
value|50
end_define

begin_comment
comment|/* 0.5 * SCALE */
end_comment

begin_comment
comment|/* Keep 2 above defines together */
end_comment

begin_define
define|#
directive|define
name|NUM_11A_EEPROM_CHANNELS
value|10
end_define

begin_define
define|#
directive|define
name|NUM_2_4_EEPROM_CHANNELS
value|3
end_define

begin_define
define|#
directive|define
name|NUM_PCDAC_VALUES
value|11
end_define

begin_define
define|#
directive|define
name|NUM_TEST_FREQUENCIES
value|8
end_define

begin_define
define|#
directive|define
name|NUM_EDGES
value|8
end_define

begin_define
define|#
directive|define
name|NUM_INTERCEPTS
value|11
end_define

begin_define
define|#
directive|define
name|FREQ_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|FREQ_MASK_3_3
value|0xff
end_define

begin_comment
comment|/* expanded in version 3.3 */
end_comment

begin_define
define|#
directive|define
name|PCDAC_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|POWER_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|NON_EDGE_FLAG_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|CHANNEL_POWER_INFO
value|8
end_define

begin_define
define|#
directive|define
name|OBDB_UNSET
value|0xffff
end_define

begin_define
define|#
directive|define
name|CHANNEL_UNUSED
value|0xff
end_define

begin_define
define|#
directive|define
name|SCALE_OC_DELTA
parameter_list|(
name|_x
parameter_list|)
value|(((_x) * 2) / 10)
end_define

begin_comment
comment|/* Used during pcdac table construction */
end_comment

begin_define
define|#
directive|define
name|PCDAC_START
value|1
end_define

begin_define
define|#
directive|define
name|PCDAC_STOP
value|63
end_define

begin_define
define|#
directive|define
name|PCDAC_STEP
value|1
end_define

begin_define
define|#
directive|define
name|PWR_TABLE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|MAX_RATE_POWER
value|63
end_define

begin_comment
comment|/* Used during power/rate table construction */
end_comment

begin_define
define|#
directive|define
name|NUM_CTLS
value|16
end_define

begin_define
define|#
directive|define
name|NUM_CTLS_3_3
value|32
end_define

begin_comment
comment|/* expanded in version 3.3 */
end_comment

begin_define
define|#
directive|define
name|NUM_CTLS_MAX
value|NUM_CTLS_3_3
end_define

begin_typedef
typedef|typedef
struct|struct
name|fullPcdacStruct
block|{
name|uint16_t
name|channelValue
decl_stmt|;
name|uint16_t
name|pcdacMin
decl_stmt|;
name|uint16_t
name|pcdacMax
decl_stmt|;
name|uint16_t
name|numPcdacValues
decl_stmt|;
name|uint16_t
name|PcdacValues
index|[
literal|64
index|]
decl_stmt|;
comment|/* power is 32bit since in dest it is scaled */
name|int16_t
name|PwrValues
index|[
literal|64
index|]
decl_stmt|;
block|}
name|FULL_PCDAC_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dataPerChannel
block|{
name|uint16_t
name|channelValue
decl_stmt|;
name|uint16_t
name|pcdacMin
decl_stmt|;
name|uint16_t
name|pcdacMax
decl_stmt|;
name|uint16_t
name|numPcdacValues
decl_stmt|;
name|uint16_t
name|PcdacValues
index|[
name|NUM_PCDAC_VALUES
index|]
decl_stmt|;
comment|/* NB: power is 32bit since in dest it is scaled */
name|int16_t
name|PwrValues
index|[
name|NUM_PCDAC_VALUES
index|]
decl_stmt|;
block|}
name|DATA_PER_CHANNEL
typedef|;
end_typedef

begin_comment
comment|/* points to the appropriate pcdac structs in the above struct based on mode */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pcdacsEeprom
block|{
specifier|const
name|uint16_t
modifier|*
name|pChannelList
decl_stmt|;
name|uint16_t
name|numChannels
decl_stmt|;
specifier|const
name|DATA_PER_CHANNEL
modifier|*
name|pDataPerChannel
decl_stmt|;
block|}
name|PCDACS_EEPROM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|trgtPowerInfo
block|{
name|uint16_t
name|twicePwr54
decl_stmt|;
name|uint16_t
name|twicePwr48
decl_stmt|;
name|uint16_t
name|twicePwr36
decl_stmt|;
name|uint16_t
name|twicePwr6_24
decl_stmt|;
name|uint16_t
name|testChannel
decl_stmt|;
block|}
name|TRGT_POWER_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|trgtPowerAllModes
block|{
name|uint16_t
name|numTargetPwr_11a
decl_stmt|;
name|TRGT_POWER_INFO
name|trgtPwr_11a
index|[
name|NUM_TEST_FREQUENCIES
index|]
decl_stmt|;
name|uint16_t
name|numTargetPwr_11g
decl_stmt|;
name|TRGT_POWER_INFO
name|trgtPwr_11g
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|numTargetPwr_11b
decl_stmt|;
name|TRGT_POWER_INFO
name|trgtPwr_11b
index|[
literal|2
index|]
decl_stmt|;
block|}
name|TRGT_POWER_ALL_MODES
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cornerCalInfo
block|{
name|uint16_t
name|gSel
decl_stmt|;
name|uint16_t
name|pd84
decl_stmt|;
name|uint16_t
name|pd90
decl_stmt|;
name|uint16_t
name|clip
decl_stmt|;
block|}
name|CORNER_CAL_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * EEPROM version 4 definitions  */
end_comment

begin_define
define|#
directive|define
name|NUM_XPD_PER_CHANNEL
value|4
end_define

begin_define
define|#
directive|define
name|NUM_POINTS_XPD0
value|4
end_define

begin_define
define|#
directive|define
name|NUM_POINTS_XPD3
value|3
end_define

begin_define
define|#
directive|define
name|IDEAL_10dB_INTERCEPT_2G
value|35
end_define

begin_define
define|#
directive|define
name|IDEAL_10dB_INTERCEPT_5G
value|55
end_define

begin_define
define|#
directive|define
name|TENX_OFDM_CCK_DELTA_INIT
value|15
end_define

begin_comment
comment|/* power 1.5 dbm */
end_comment

begin_define
define|#
directive|define
name|TENX_CH14_FILTER_CCK_DELTA_INIT
value|15
end_define

begin_comment
comment|/* power 1.5 dbm */
end_comment

begin_define
define|#
directive|define
name|CCK_OFDM_GAIN_DELTA
value|15
end_define

begin_define
define|#
directive|define
name|NUM_TARGET_POWER_LOCATIONS_11B
value|4
end_define

begin_define
define|#
directive|define
name|NUM_TARGET_POWER_LOCATIONS_11G
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|xpd_gain
decl_stmt|;
name|uint16_t
name|numPcdacs
decl_stmt|;
name|uint16_t
name|pcdac
index|[
name|NUM_POINTS_XPD0
index|]
decl_stmt|;
name|int16_t
name|pwr_t4
index|[
name|NUM_POINTS_XPD0
index|]
decl_stmt|;
comment|/* or gainF */
block|}
name|EXPN_DATA_PER_XPD_5112
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|channelValue
decl_stmt|;
name|int16_t
name|maxPower_t4
decl_stmt|;
name|EXPN_DATA_PER_XPD_5112
name|pDataPerXPD
index|[
name|NUM_XPD_PER_CHANNEL
index|]
decl_stmt|;
block|}
name|EXPN_DATA_PER_CHANNEL_5112
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
modifier|*
name|pChannels
decl_stmt|;
name|uint16_t
name|numChannels
decl_stmt|;
name|uint16_t
name|xpdMask
decl_stmt|;
comment|/* mask of permitted xpd_gains */
name|EXPN_DATA_PER_CHANNEL_5112
modifier|*
name|pDataPerChannel
decl_stmt|;
block|}
name|EEPROM_POWER_EXPN_5112
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|channelValue
decl_stmt|;
name|uint16_t
name|pcd1_xg0
decl_stmt|;
name|int16_t
name|pwr1_xg0
decl_stmt|;
name|uint16_t
name|pcd2_delta_xg0
decl_stmt|;
name|int16_t
name|pwr2_xg0
decl_stmt|;
name|uint16_t
name|pcd3_delta_xg0
decl_stmt|;
name|int16_t
name|pwr3_xg0
decl_stmt|;
name|uint16_t
name|pcd4_delta_xg0
decl_stmt|;
name|int16_t
name|pwr4_xg0
decl_stmt|;
name|int16_t
name|maxPower_t4
decl_stmt|;
name|int16_t
name|pwr1_xg3
decl_stmt|;
comment|/* pcdac = 20 */
name|int16_t
name|pwr2_xg3
decl_stmt|;
comment|/* pcdac = 35 */
name|int16_t
name|pwr3_xg3
decl_stmt|;
comment|/* pcdac = 63 */
comment|/* XXX - Should be pwr1_xg2, etc to agree with documentation */
block|}
name|EEPROM_DATA_PER_CHANNEL_5112
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pChannels
index|[
name|NUM_11A_EEPROM_CHANNELS
index|]
decl_stmt|;
name|uint16_t
name|numChannels
decl_stmt|;
name|uint16_t
name|xpdMask
decl_stmt|;
comment|/* mask of permitted xpd_gains */
name|EEPROM_DATA_PER_CHANNEL_5112
name|pDataPerChannel
index|[
name|NUM_11A_EEPROM_CHANNELS
index|]
decl_stmt|;
block|}
name|EEPROM_POWER_5112
typedef|;
end_typedef

begin_comment
comment|/*  * EEPROM version 5 definitions (Griffin, et. al.).  */
end_comment

begin_define
define|#
directive|define
name|NUM_2_4_EEPROM_CHANNELS_2413
value|4
end_define

begin_define
define|#
directive|define
name|NUM_11A_EEPROM_CHANNELS_2413
value|10
end_define

begin_define
define|#
directive|define
name|PWR_TABLE_SIZE_2413
value|128
end_define

begin_comment
comment|/* Used during pdadc construction */
end_comment

begin_define
define|#
directive|define
name|MAX_NUM_PDGAINS_PER_CHANNEL
value|4
end_define

begin_define
define|#
directive|define
name|NUM_PDGAINS_PER_CHANNEL
value|2
end_define

begin_define
define|#
directive|define
name|NUM_POINTS_LAST_PDGAIN
value|5
end_define

begin_define
define|#
directive|define
name|NUM_POINTS_OTHER_PDGAINS
value|4
end_define

begin_define
define|#
directive|define
name|XPD_GAIN1_GEN5
value|3
end_define

begin_define
define|#
directive|define
name|XPD_GAIN2_GEN5
value|1
end_define

begin_define
define|#
directive|define
name|MAX_PWR_RANGE_IN_HALF_DB
value|64
end_define

begin_define
define|#
directive|define
name|PD_GAIN_BOUNDARY_STRETCH_IN_HALF_DB
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pd_gain
decl_stmt|;
name|uint16_t
name|numVpd
decl_stmt|;
name|uint16_t
name|Vpd
index|[
name|NUM_POINTS_LAST_PDGAIN
index|]
decl_stmt|;
name|int16_t
name|pwr_t4
index|[
name|NUM_POINTS_LAST_PDGAIN
index|]
decl_stmt|;
comment|/* or gainF */
block|}
name|RAW_DATA_PER_PDGAIN_2413
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|channelValue
decl_stmt|;
name|int16_t
name|maxPower_t4
decl_stmt|;
name|uint16_t
name|numPdGains
decl_stmt|;
comment|/* # Pd Gains per channel */
name|RAW_DATA_PER_PDGAIN_2413
name|pDataPerPDGain
index|[
name|MAX_NUM_PDGAINS_PER_CHANNEL
index|]
decl_stmt|;
block|}
name|RAW_DATA_PER_CHANNEL_2413
typedef|;
end_typedef

begin_comment
comment|/* XXX: assumes NUM_11A_EEPROM_CHANNELS_2413>= NUM_2_4_EEPROM_CHANNELS_2413 ??? */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pChannels
index|[
name|NUM_11A_EEPROM_CHANNELS_2413
index|]
decl_stmt|;
name|uint16_t
name|numChannels
decl_stmt|;
name|uint16_t
name|xpd_mask
decl_stmt|;
comment|/* mask of permitted xpd_gains */
name|RAW_DATA_PER_CHANNEL_2413
name|pDataPerChannel
index|[
name|NUM_11A_EEPROM_CHANNELS_2413
index|]
decl_stmt|;
block|}
name|RAW_DATA_STRUCT_2413
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|channelValue
decl_stmt|;
name|uint16_t
name|numPdGains
decl_stmt|;
name|uint16_t
name|Vpd_I
index|[
name|MAX_NUM_PDGAINS_PER_CHANNEL
index|]
decl_stmt|;
name|int16_t
name|pwr_I
index|[
name|MAX_NUM_PDGAINS_PER_CHANNEL
index|]
decl_stmt|;
name|uint16_t
name|Vpd_delta
index|[
name|NUM_POINTS_LAST_PDGAIN
index|]
index|[
name|MAX_NUM_PDGAINS_PER_CHANNEL
index|]
decl_stmt|;
name|int16_t
name|pwr_delta_t2
index|[
name|NUM_POINTS_LAST_PDGAIN
index|]
index|[
name|MAX_NUM_PDGAINS_PER_CHANNEL
index|]
decl_stmt|;
name|int16_t
name|maxPower_t4
decl_stmt|;
block|}
name|EEPROM_DATA_PER_CHANNEL_2413
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pChannels
index|[
name|NUM_11A_EEPROM_CHANNELS_2413
index|]
decl_stmt|;
name|uint16_t
name|numChannels
decl_stmt|;
name|uint16_t
name|xpd_mask
decl_stmt|;
comment|/* mask of permitted xpd_gains */
name|EEPROM_DATA_PER_CHANNEL_2413
name|pDataPerChannel
index|[
name|NUM_11A_EEPROM_CHANNELS_2413
index|]
decl_stmt|;
block|}
name|EEPROM_DATA_STRUCT_2413
typedef|;
end_typedef

begin_comment
comment|/*  * Information retrieved from EEPROM.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|ee_version
decl_stmt|;
comment|/* Version field */
name|uint16_t
name|ee_protect
decl_stmt|;
comment|/* EEPROM protect field */
name|uint16_t
name|ee_regdomain
decl_stmt|;
comment|/* Regulatory domain */
comment|/* General Device Parameters */
name|uint16_t
name|ee_turbo5Disable
decl_stmt|;
name|uint16_t
name|ee_turbo2Disable
decl_stmt|;
name|uint16_t
name|ee_rfKill
decl_stmt|;
name|uint16_t
name|ee_deviceType
decl_stmt|;
name|uint16_t
name|ee_turbo2WMaxPower5
decl_stmt|;
name|uint16_t
name|ee_turbo2WMaxPower2
decl_stmt|;
name|uint16_t
name|ee_xrTargetPower5
decl_stmt|;
name|uint16_t
name|ee_xrTargetPower2
decl_stmt|;
name|uint16_t
name|ee_Amode
decl_stmt|;
name|uint16_t
name|ee_regCap
decl_stmt|;
name|uint16_t
name|ee_Bmode
decl_stmt|;
name|uint16_t
name|ee_Gmode
decl_stmt|;
name|int8_t
name|ee_antennaGainMax
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|ee_xtnd5GSupport
decl_stmt|;
name|uint8_t
name|ee_cckOfdmPwrDelta
decl_stmt|;
name|uint8_t
name|ee_exist32kHzCrystal
decl_stmt|;
name|uint16_t
name|ee_targetPowersStart
decl_stmt|;
name|uint16_t
name|ee_fixedBias5
decl_stmt|;
name|uint16_t
name|ee_fixedBias2
decl_stmt|;
name|uint16_t
name|ee_cckOfdmGainDelta
decl_stmt|;
name|uint16_t
name|ee_scaledCh14FilterCckDelta
decl_stmt|;
name|uint16_t
name|ee_eepMap
decl_stmt|;
name|uint16_t
name|ee_earStart
decl_stmt|;
comment|/* 5 GHz / 2.4 GHz CKK / 2.4 GHz OFDM common parameters */
name|uint16_t
name|ee_switchSettling
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_txrxAtten
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_txEndToXLNAOn
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_thresh62
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_txEndToXPAOff
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_txFrameToXPAOn
index|[
literal|3
index|]
decl_stmt|;
name|int8_t
name|ee_adcDesiredSize
index|[
literal|3
index|]
decl_stmt|;
comment|/* 8-bit signed value */
name|int8_t
name|ee_pgaDesiredSize
index|[
literal|3
index|]
decl_stmt|;
comment|/* 8-bit signed value */
name|int16_t
name|ee_noiseFloorThresh
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_xlnaGain
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_xgain
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_xpd
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_antennaControl
index|[
literal|11
index|]
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_falseDetectBackoff
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_gainI
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ee_rxtxMargin
index|[
literal|3
index|]
decl_stmt|;
comment|/* new parameters added for the AR2413 */
name|HAL_BOOL
name|ee_disableXr5
decl_stmt|;
name|HAL_BOOL
name|ee_disableXr2
decl_stmt|;
name|uint16_t
name|ee_eepMap2PowerCalStart
decl_stmt|;
name|uint16_t
name|ee_capField
decl_stmt|;
name|uint16_t
name|ee_switchSettlingTurbo
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|ee_txrxAttenTurbo
index|[
literal|2
index|]
decl_stmt|;
name|int8_t
name|ee_adcDesiredSizeTurbo
index|[
literal|2
index|]
decl_stmt|;
name|int8_t
name|ee_pgaDesiredSizeTurbo
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|ee_rxtxMarginTurbo
index|[
literal|2
index|]
decl_stmt|;
comment|/* 5 GHz parameters */
name|uint16_t
name|ee_ob1
decl_stmt|;
name|uint16_t
name|ee_db1
decl_stmt|;
name|uint16_t
name|ee_ob2
decl_stmt|;
name|uint16_t
name|ee_db2
decl_stmt|;
name|uint16_t
name|ee_ob3
decl_stmt|;
name|uint16_t
name|ee_db3
decl_stmt|;
name|uint16_t
name|ee_ob4
decl_stmt|;
name|uint16_t
name|ee_db4
decl_stmt|;
comment|/* 2.4 GHz parameters */
name|uint16_t
name|ee_obFor24
decl_stmt|;
name|uint16_t
name|ee_dbFor24
decl_stmt|;
name|uint16_t
name|ee_obFor24g
decl_stmt|;
name|uint16_t
name|ee_dbFor24g
decl_stmt|;
name|uint16_t
name|ee_ob2GHz
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|ee_db2GHz
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|ee_numCtls
decl_stmt|;
name|uint16_t
name|ee_ctl
index|[
name|NUM_CTLS_MAX
index|]
decl_stmt|;
name|uint16_t
name|ee_iqCalI
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|ee_iqCalQ
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|ee_calPier11g
index|[
name|NUM_2_4_EEPROM_CHANNELS
index|]
decl_stmt|;
name|uint16_t
name|ee_calPier11b
index|[
name|NUM_2_4_EEPROM_CHANNELS
index|]
decl_stmt|;
comment|/* corner calibration information */
name|CORNER_CAL_INFO
name|ee_cornerCal
decl_stmt|;
name|uint16_t
name|ee_opCap
decl_stmt|;
comment|/* 11a info */
name|uint16_t
name|ee_channels11a
index|[
name|NUM_11A_EEPROM_CHANNELS
index|]
decl_stmt|;
name|uint16_t
name|ee_numChannels11a
decl_stmt|;
name|DATA_PER_CHANNEL
name|ee_dataPerChannel11a
index|[
name|NUM_11A_EEPROM_CHANNELS
index|]
decl_stmt|;
name|uint16_t
name|ee_numChannels2_4
decl_stmt|;
name|uint16_t
name|ee_channels11g
index|[
name|NUM_2_4_EEPROM_CHANNELS
index|]
decl_stmt|;
name|uint16_t
name|ee_channels11b
index|[
name|NUM_2_4_EEPROM_CHANNELS
index|]
decl_stmt|;
name|uint16_t
name|ee_spurChans
index|[
name|AR_EEPROM_MODAL_SPURS
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* 11g info */
name|DATA_PER_CHANNEL
name|ee_dataPerChannel11g
index|[
name|NUM_2_4_EEPROM_CHANNELS
index|]
decl_stmt|;
comment|/* 11b info */
name|DATA_PER_CHANNEL
name|ee_dataPerChannel11b
index|[
name|NUM_2_4_EEPROM_CHANNELS
index|]
decl_stmt|;
name|TRGT_POWER_ALL_MODES
name|ee_tpow
decl_stmt|;
name|RD_EDGES_POWER
name|ee_rdEdgesPower
index|[
name|NUM_EDGES
operator|*
name|NUM_CTLS_MAX
index|]
decl_stmt|;
union|union
block|{
name|EEPROM_POWER_EXPN_5112
name|eu_modePowerArray5112
index|[
literal|3
index|]
decl_stmt|;
name|RAW_DATA_STRUCT_2413
name|eu_rawDataset2413
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ee_u
union|;
block|}
name|HAL_EEPROM
typedef|;
end_typedef

begin_comment
comment|/* write-around defines */
end_comment

begin_define
define|#
directive|define
name|ee_numTargetPwr_11a
value|ee_tpow.numTargetPwr_11a
end_define

begin_define
define|#
directive|define
name|ee_trgtPwr_11a
value|ee_tpow.trgtPwr_11a
end_define

begin_define
define|#
directive|define
name|ee_numTargetPwr_11g
value|ee_tpow.numTargetPwr_11g
end_define

begin_define
define|#
directive|define
name|ee_trgtPwr_11g
value|ee_tpow.trgtPwr_11g
end_define

begin_define
define|#
directive|define
name|ee_numTargetPwr_11b
value|ee_tpow.numTargetPwr_11b
end_define

begin_define
define|#
directive|define
name|ee_trgtPwr_11b
value|ee_tpow.trgtPwr_11b
end_define

begin_define
define|#
directive|define
name|ee_modePowerArray5112
value|ee_u.eu_modePowerArray5112
end_define

begin_define
define|#
directive|define
name|ee_rawDataset2413
value|ee_u.eu_rawDataset2413
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_EEPROM_V3_H_ */
end_comment

end_unit

