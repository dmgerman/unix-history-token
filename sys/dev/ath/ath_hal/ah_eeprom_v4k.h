begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009 Rui Paulo<rpaulo@FreeBSD.org>  * Copyright (c) 2008 Sam Leffler, Errno Consulting  * Copyright (c) 2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AH_EEPROM_V4K_H_
end_ifndef

begin_define
define|#
directive|define
name|_AH_EEPROM_V4K_H_
end_define

begin_include
include|#
directive|include
file|"ah_eeprom.h"
end_include

begin_include
include|#
directive|include
file|"ah_eeprom_v14.h"
end_include

begin_undef
undef|#
directive|undef
name|owl_eep_start_loc
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__LINUX_ARM_ARCH__
end_ifdef

begin_comment
comment|/* AP71 */
end_comment

begin_define
define|#
directive|define
name|owl_eep_start_loc
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|owl_eep_start_loc
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// 16-bit offset location start of calibration struct
end_comment

begin_define
define|#
directive|define
name|AR5416_4K_EEP_START_LOC
value|64
end_define

begin_define
define|#
directive|define
name|AR5416_4K_NUM_2G_CAL_PIERS
value|3
end_define

begin_define
define|#
directive|define
name|AR5416_4K_NUM_2G_CCK_TARGET_POWERS
value|3
end_define

begin_define
define|#
directive|define
name|AR5416_4K_NUM_2G_20_TARGET_POWERS
value|3
end_define

begin_define
define|#
directive|define
name|AR5416_4K_NUM_2G_40_TARGET_POWERS
value|3
end_define

begin_define
define|#
directive|define
name|AR5416_4K_NUM_CTLS
value|12
end_define

begin_define
define|#
directive|define
name|AR5416_4K_NUM_BAND_EDGES
value|4
end_define

begin_define
define|#
directive|define
name|AR5416_4K_NUM_PD_GAINS
value|2
end_define

begin_define
define|#
directive|define
name|AR5416_4K_MAX_CHAINS
value|1
end_define

begin_comment
comment|/*  * NB: The format in EEPROM has words 0 and 2 swapped (i.e. version  * and length are swapped).  We reverse their position after reading  * the data into host memory so the version field is at the same  * offset as in previous EEPROM layouts.  This makes utilities that  * inspect the EEPROM contents work without looking at the PCI device  * id which may or may not be reliable.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BaseEepHeader4k
block|{
name|uint16_t
name|version
decl_stmt|;
comment|/* NB: length in EEPROM */
name|uint16_t
name|checksum
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
comment|/* NB: version in EEPROM */
name|uint8_t
name|opCapFlags
decl_stmt|;
name|uint8_t
name|eepMisc
decl_stmt|;
name|uint16_t
name|regDmn
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|macAddr
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|rxMask
decl_stmt|;
name|uint8_t
name|txMask
decl_stmt|;
name|uint16_t
name|rfSilent
decl_stmt|;
name|uint16_t
name|blueToothOptions
decl_stmt|;
name|uint16_t
name|deviceCap
decl_stmt|;
name|uint32_t
name|binBuildNumber
decl_stmt|;
name|uint8_t
name|deviceType
decl_stmt|;
name|uint8_t
name|txGainType
decl_stmt|;
comment|/* high power tx gain table support */
block|}
name|__packed
name|BASE_EEP4K_HEADER
typedef|;
end_typedef

begin_comment
comment|// 32 B
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ModalEepHeader4k
block|{
name|uint32_t
name|antCtrlChain
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 12
name|uint32_t
name|antCtrlCommon
decl_stmt|;
comment|// 4
name|int8_t
name|antennaGainCh
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|switchSettling
decl_stmt|;
comment|// 1
name|uint8_t
name|txRxAttenCh
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|rxTxMarginCh
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|adcDesiredSize
decl_stmt|;
comment|// 1
name|int8_t
name|pgaDesiredSize
decl_stmt|;
comment|// 1
name|uint8_t
name|xlnaGainCh
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|txEndToXpaOff
decl_stmt|;
comment|// 1
name|uint8_t
name|txEndToRxOn
decl_stmt|;
comment|// 1
name|uint8_t
name|txFrameToXpaOn
decl_stmt|;
comment|// 1
name|uint8_t
name|thresh62
decl_stmt|;
comment|// 1
name|uint8_t
name|noiseFloorThreshCh
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|xpdGain
decl_stmt|;
comment|// 1
name|uint8_t
name|xpd
decl_stmt|;
comment|// 1
name|int8_t
name|iqCalICh
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|int8_t
name|iqCalQCh
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|pdGainOverlap
decl_stmt|;
comment|// 1
name|uint8_t
name|ob
decl_stmt|;
comment|// 1
name|uint8_t
name|db
decl_stmt|;
comment|// 1
name|uint8_t
name|xpaBiasLvl
decl_stmt|;
comment|// 1
if|#
directive|if
literal|0
block|uint8_t		pwrDecreaseFor2Chain;
comment|// 1
block|uint8_t		pwrDecreaseFor3Chain;
comment|// 1 -> 48 B
endif|#
directive|endif
name|uint8_t
name|txFrameToDataStart
decl_stmt|;
comment|// 1
name|uint8_t
name|txFrameToPaOn
decl_stmt|;
comment|// 1
name|uint8_t
name|ht40PowerIncForPdadc
decl_stmt|;
comment|// 1
name|uint8_t
name|bswAtten
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|bswMargin
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|swSettleHt40
decl_stmt|;
comment|// 1
name|uint8_t
name|xatten2Db
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|xatten2Margin
index|[
name|AR5416_4K_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|uint8_t
name|ob_ch1
decl_stmt|;
comment|// 1 -> ob and db become chain specific from AR9280
name|uint8_t
name|db_ch1
decl_stmt|;
comment|// 1
name|uint8_t
name|flagBits
decl_stmt|;
comment|// 1
define|#
directive|define
name|AR5416_EEP_FLAG_USEANT1
value|0x01
comment|/* +1 configured antenna */
define|#
directive|define
name|AR5416_EEP_FLAG_FORCEXPAON
value|0x02
comment|/* force XPA bit for 5G */
define|#
directive|define
name|AR5416_EEP_FLAG_LOCALBIAS
value|0x04
comment|/* enable local bias */
define|#
directive|define
name|AR5416_EEP_FLAG_FEMBANDSELECT
value|0x08
comment|/* FEM band select used */
define|#
directive|define
name|AR5416_EEP_FLAG_XLNABUFIN
value|0x10
define|#
directive|define
name|AR5416_EEP_FLAG_XLNAISEL
value|0x60
define|#
directive|define
name|AR5416_EEP_FLAG_XLNAISEL_S
value|5
define|#
directive|define
name|AR5416_EEP_FLAG_XLNABUFMODE
value|0x80
name|uint8_t
name|miscBits
decl_stmt|;
comment|// [0..1]: bb_tx_dac_scale_cck
name|uint16_t
name|xpaBiasLvlFreq
index|[
literal|3
index|]
decl_stmt|;
comment|// 6
name|uint8_t
name|futureModal
index|[
literal|2
index|]
decl_stmt|;
comment|// 2
name|SPUR_CHAN
name|spurChans
index|[
name|AR5416_EEPROM_MODAL_SPURS
index|]
decl_stmt|;
comment|// 20 B
block|}
name|__packed
name|MODAL_EEP4K_HEADER
typedef|;
end_typedef

begin_comment
comment|// == 68 B
end_comment

begin_typedef
typedef|typedef
struct|struct
name|CalCtlData4k
block|{
name|CAL_CTL_EDGES
name|ctlEdges
index|[
name|AR5416_4K_MAX_CHAINS
index|]
index|[
name|AR5416_4K_NUM_BAND_EDGES
index|]
decl_stmt|;
block|}
name|__packed
name|CAL_CTL_DATA_4K
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|calDataPerFreq4k
block|{
name|uint8_t
name|pwrPdg
index|[
name|AR5416_4K_NUM_PD_GAINS
index|]
index|[
name|AR5416_PD_GAIN_ICEPTS
index|]
decl_stmt|;
name|uint8_t
name|vpdPdg
index|[
name|AR5416_4K_NUM_PD_GAINS
index|]
index|[
name|AR5416_PD_GAIN_ICEPTS
index|]
decl_stmt|;
block|}
name|__packed
name|CAL_DATA_PER_FREQ_4K
typedef|;
end_typedef

begin_struct
struct|struct
name|ar5416eeprom_4k
block|{
name|BASE_EEP4K_HEADER
name|baseEepHeader
decl_stmt|;
comment|// 32 B
name|uint8_t
name|custData
index|[
literal|20
index|]
decl_stmt|;
comment|// 20 B
name|MODAL_EEP4K_HEADER
name|modalHeader
decl_stmt|;
comment|// 68 B
name|uint8_t
name|calFreqPier2G
index|[
name|AR5416_4K_NUM_2G_CAL_PIERS
index|]
decl_stmt|;
name|CAL_DATA_PER_FREQ_4K
name|calPierData2G
index|[
name|AR5416_4K_MAX_CHAINS
index|]
index|[
name|AR5416_4K_NUM_2G_CAL_PIERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_LEG
name|calTargetPowerCck
index|[
name|AR5416_4K_NUM_2G_CCK_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_LEG
name|calTargetPower2G
index|[
name|AR5416_4K_NUM_2G_20_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_HT
name|calTargetPower2GHT20
index|[
name|AR5416_4K_NUM_2G_20_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_HT
name|calTargetPower2GHT40
index|[
name|AR5416_4K_NUM_2G_40_TARGET_POWERS
index|]
decl_stmt|;
name|uint8_t
name|ctlIndex
index|[
name|AR5416_4K_NUM_CTLS
index|]
decl_stmt|;
name|CAL_CTL_DATA_4K
name|ctlData
index|[
name|AR5416_4K_NUM_CTLS
index|]
decl_stmt|;
name|uint8_t
name|padding
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|ar5416eeprom_4k
name|ee_base
decl_stmt|;
define|#
directive|define
name|NUM_EDGES
value|8
name|uint16_t
name|ee_numCtls
decl_stmt|;
name|RD_EDGES_POWER
name|ee_rdEdgesPower
index|[
name|NUM_EDGES
operator|*
name|AR5416_4K_NUM_CTLS
index|]
decl_stmt|;
comment|/* XXX these are dynamically calculated for use by shared code */
name|int8_t
name|ee_antennaGainMax
index|[
literal|2
index|]
decl_stmt|;
block|}
name|HAL_EEPROM_v4k
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AH_EEPROM_V4K_H_ */
end_comment

end_unit

