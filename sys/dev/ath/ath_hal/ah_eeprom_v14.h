begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Sam Leffler, Errno Consulting  * Copyright (c) 2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ah_eeprom_v14.h,v 1.3 2008/11/10 04:08:00 sam Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AH_EEPROM_V14_H_
end_ifndef

begin_define
define|#
directive|define
name|_AH_EEPROM_V14_H_
end_define

begin_include
include|#
directive|include
file|"ah_eeprom.h"
end_include

begin_comment
comment|/* reg_off = 4 * (eep_off) */
end_comment

begin_define
define|#
directive|define
name|AR5416_EEPROM_S
value|2
end_define

begin_define
define|#
directive|define
name|AR5416_EEPROM_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|AR5416_EEPROM_START_ADDR
value|0x503f1200
end_define

begin_define
define|#
directive|define
name|AR5416_EEPROM_MAX
value|0xae0
end_define

begin_comment
comment|/* Ignore for the moment used only on the flash implementations */
end_comment

begin_define
define|#
directive|define
name|AR5416_EEPROM_MAGIC
value|0xa55a
end_define

begin_define
define|#
directive|define
name|AR5416_EEPROM_MAGIC_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|owl_get_ntxchains
parameter_list|(
name|_txchainmask
parameter_list|)
define|\
value|(((_txchainmask>> 2)& 1) + ((_txchainmask>> 1)& 1) + (_txchainmask& 1))
end_define

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
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End temp defines */
end_comment

begin_define
define|#
directive|define
name|AR5416_EEP_NO_BACK_VER
value|0x1
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_VER
value|0xE
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_VER_MINOR_MASK
value|0xFFF
end_define

begin_comment
comment|// Adds modal params txFrameToPaOn, txFrametoDataStart, ht40PowerInc
end_comment

begin_define
define|#
directive|define
name|AR5416_EEP_MINOR_VER_2
value|0x2
end_define

begin_comment
comment|// Adds modal params bswAtten, bswMargin, swSettle and base OpFlags for HT20/40 Disable
end_comment

begin_define
define|#
directive|define
name|AR5416_EEP_MINOR_VER_3
value|0x3
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_MINOR_VER_7
value|0x7
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_MINOR_VER_9
value|0x9
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_MINOR_VER_16
value|0x10
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_MINOR_VER_17
value|0x11
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_MINOR_VER_19
value|0x13
end_define

begin_comment
comment|// 16-bit offset location start of calibration struct
end_comment

begin_define
define|#
directive|define
name|AR5416_EEP_START_LOC
value|256
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_5G_CAL_PIERS
value|8
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_2G_CAL_PIERS
value|4
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_5G_20_TARGET_POWERS
value|8
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_5G_40_TARGET_POWERS
value|8
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_2G_CCK_TARGET_POWERS
value|3
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_2G_20_TARGET_POWERS
value|4
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_2G_40_TARGET_POWERS
value|4
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_CTLS
value|24
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_BAND_EDGES
value|8
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_PD_GAINS
value|4
end_define

begin_define
define|#
directive|define
name|AR5416_PD_GAINS_IN_MASK
value|4
end_define

begin_define
define|#
directive|define
name|AR5416_PD_GAIN_ICEPTS
value|5
end_define

begin_define
define|#
directive|define
name|AR5416_EEPROM_MODAL_SPURS
value|5
end_define

begin_define
define|#
directive|define
name|AR5416_MAX_RATE_POWER
value|63
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_PDADC_VALUES
value|128
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_RATES
value|16
end_define

begin_define
define|#
directive|define
name|AR5416_BCHAN_UNUSED
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR5416_MAX_PWR_RANGE_IN_HALF_DB
value|64
end_define

begin_define
define|#
directive|define
name|AR5416_EEPMISC_BIG_ENDIAN
value|0x01
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
value|((y) ? ((x) - 2300) : (((x) - 4800) / 5))
end_define

begin_define
define|#
directive|define
name|AR5416_MAX_CHAINS
value|3
end_define

begin_define
define|#
directive|define
name|AR5416_ANT_16S
value|25
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_ANT_CHAIN_FIELDS
value|7
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_ANT_COMMON_FIELDS
value|4
end_define

begin_define
define|#
directive|define
name|AR5416_SIZE_ANT_CHAIN_FIELD
value|3
end_define

begin_define
define|#
directive|define
name|AR5416_SIZE_ANT_COMMON_FIELD
value|4
end_define

begin_define
define|#
directive|define
name|AR5416_ANT_CHAIN_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|AR5416_ANT_COMMON_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|AR5416_CHAIN_0_IDX
value|0
end_define

begin_define
define|#
directive|define
name|AR5416_CHAIN_1_IDX
value|1
end_define

begin_define
define|#
directive|define
name|AR5416_CHAIN_2_IDX
value|2
end_define

begin_define
define|#
directive|define
name|AR5416_OPFLAGS_11A
value|0x01
end_define

begin_define
define|#
directive|define
name|AR5416_OPFLAGS_11G
value|0x02
end_define

begin_define
define|#
directive|define
name|AR5416_OPFLAGS_5G_HT40
value|0x04
end_define

begin_define
define|#
directive|define
name|AR5416_OPFLAGS_2G_HT40
value|0x08
end_define

begin_define
define|#
directive|define
name|AR5416_OPFLAGS_5G_HT20
value|0x10
end_define

begin_define
define|#
directive|define
name|AR5416_OPFLAGS_2G_HT20
value|0x20
end_define

begin_comment
comment|/* RF silent fields in EEPROM */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_ENABLED
value|0x0001
end_define

begin_comment
comment|/* enabled/disabled */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_ENABLED_S
value|0
end_define

begin_define
define|#
directive|define
name|EEP_RFSILENT_POLARITY
value|0x0002
end_define

begin_comment
comment|/* polarity */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_POLARITY_S
value|1
end_define

begin_define
define|#
directive|define
name|EEP_RFSILENT_GPIO_SEL
value|0x001c
end_define

begin_comment
comment|/* gpio PIN */
end_comment

begin_define
define|#
directive|define
name|EEP_RFSILENT_GPIO_SEL_S
value|2
end_define

begin_comment
comment|/* Rx gain type values */
end_comment

begin_define
define|#
directive|define
name|AR5416_EEP_RXGAIN_23dB_BACKOFF
value|0
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_RXGAIN_13dB_BACKOFF
value|1
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_RXGAIN_ORIG
value|2
end_define

begin_comment
comment|/* Tx gain type values */
end_comment

begin_define
define|#
directive|define
name|AR5416_EEP_TXGAIN_ORIG
value|0
end_define

begin_define
define|#
directive|define
name|AR5416_EEP_TXGAIN_HIGH_POWER
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|spurChanStruct
block|{
name|uint16_t
name|spurChan
decl_stmt|;
name|uint8_t
name|spurRangeLow
decl_stmt|;
name|uint8_t
name|spurRangeHigh
decl_stmt|;
block|}
name|__packed
name|SPUR_CHAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|CalTargetPowerLegacy
block|{
name|uint8_t
name|bChannel
decl_stmt|;
name|uint8_t
name|tPow2x
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
name|CalTargetPowerHt
block|{
name|uint8_t
name|bChannel
decl_stmt|;
name|uint8_t
name|tPow2x
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
name|CAL_TARGET_POWER_HT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|CalCtlEdges
block|{
name|uint8_t
name|bChannel
decl_stmt|;
name|uint8_t
name|tPowerFlag
decl_stmt|;
comment|/* [0..5] tPower [6..7] flag */
define|#
directive|define
name|CAL_CTL_EDGES_POWER
value|0x3f
define|#
directive|define
name|CAL_CTL_EDGES_POWER_S
value|0
define|#
directive|define
name|CAL_CTL_EDGES_FLAG
value|0xc0
define|#
directive|define
name|CAL_CTL_EDGES_FLAG_S
value|6
block|}
name|__packed
name|CAL_CTL_EDGES
typedef|;
end_typedef

begin_comment
comment|/*  * NB: The format in EEPROM has words 0 and 2 swapped (i.e. version  * and length are swapped).  We reverse their position after reading  * the data into host memory so the version field is at the same  * offset as in previous EEPROM layouts.  This makes utilities that  * inspect the EEPROM contents work without looking at the PCI device  * id which may or may not be reliable.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BaseEepHeader
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
name|pwdclkind
decl_stmt|;
name|uint8_t
name|fastClk5g
decl_stmt|;
name|uint8_t
name|divChain
decl_stmt|;
name|uint8_t
name|rxGainType
decl_stmt|;
name|uint8_t
name|dacHiPwrMode
decl_stmt|;
comment|/* use the DAC high power mode (MB91) */
name|uint8_t
name|openLoopPwrCntl
decl_stmt|;
comment|/* 1: use open loop power control, 					   0: use closed loop power control */
name|uint8_t
name|dacLpMode
decl_stmt|;
name|uint8_t
name|txGainType
decl_stmt|;
comment|/* high power tx gain table support */
name|uint8_t
name|rcChainMask
decl_stmt|;
comment|/* "1" if the card is an HB93 1x2 */
name|uint8_t
name|futureBase
index|[
literal|24
index|]
decl_stmt|;
block|}
name|__packed
name|BASE_EEP_HEADER
typedef|;
end_typedef

begin_comment
comment|// 64 B
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ModalEepHeader
block|{
name|uint32_t
name|antCtrlChain
index|[
name|AR5416_MAX_CHAINS
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
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3
name|uint8_t
name|switchSettling
decl_stmt|;
comment|// 1
name|uint8_t
name|txRxAttenCh
index|[
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3
name|uint8_t
name|rxTxMarginCh
index|[
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3
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
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3
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
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3
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
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 1
name|int8_t
name|iqCalQCh
index|[
name|AR5416_MAX_CHAINS
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
name|uint8_t
name|pwrDecreaseFor2Chain
decl_stmt|;
comment|// 1
name|uint8_t
name|pwrDecreaseFor3Chain
decl_stmt|;
comment|// 1 -> 48 B
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
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3
name|uint8_t
name|bswMargin
index|[
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3
name|uint8_t
name|swSettleHt40
decl_stmt|;
comment|// 1
name|uint8_t
name|xatten2Db
index|[
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3 -> New for AR9280 (0xa20c/b20c 11:6)
name|uint8_t
name|xatten2Margin
index|[
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
comment|// 3 -> New for AR9280 (0xa20c/b20c 21:17)
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
comment|// 3
name|uint8_t
name|futureModal
index|[
literal|6
index|]
decl_stmt|;
comment|// 6
name|SPUR_CHAN
name|spurChans
index|[
name|AR5416_EEPROM_MODAL_SPURS
index|]
decl_stmt|;
comment|// 20 B
block|}
name|__packed
name|MODAL_EEP_HEADER
typedef|;
end_typedef

begin_comment
comment|// == 100 B
end_comment

begin_typedef
typedef|typedef
struct|struct
name|calDataPerFreqOpLoop
block|{
name|uint8_t
name|pwrPdg
index|[
literal|2
index|]
index|[
literal|5
index|]
decl_stmt|;
comment|/* power measurement */
name|uint8_t
name|vpdPdg
index|[
literal|2
index|]
index|[
literal|5
index|]
decl_stmt|;
comment|/* pdadc voltage at power measurement */
name|uint8_t
name|pcdac
index|[
literal|2
index|]
index|[
literal|5
index|]
decl_stmt|;
comment|/* pcdac used for power measurement */
name|uint8_t
name|empty
index|[
literal|2
index|]
index|[
literal|5
index|]
decl_stmt|;
comment|/* future use */
block|}
name|__packed
name|CAL_DATA_PER_FREQ_OP_LOOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|CalCtlData
block|{
name|CAL_CTL_EDGES
name|ctlEdges
index|[
name|AR5416_MAX_CHAINS
index|]
index|[
name|AR5416_NUM_BAND_EDGES
index|]
decl_stmt|;
block|}
name|__packed
name|CAL_CTL_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|calDataPerFreq
block|{
name|uint8_t
name|pwrPdg
index|[
name|AR5416_NUM_PD_GAINS
index|]
index|[
name|AR5416_PD_GAIN_ICEPTS
index|]
decl_stmt|;
name|uint8_t
name|vpdPdg
index|[
name|AR5416_NUM_PD_GAINS
index|]
index|[
name|AR5416_PD_GAIN_ICEPTS
index|]
decl_stmt|;
block|}
name|__packed
name|CAL_DATA_PER_FREQ
typedef|;
end_typedef

begin_struct
struct|struct
name|ar5416eeprom
block|{
name|BASE_EEP_HEADER
name|baseEepHeader
decl_stmt|;
comment|// 64 B
name|uint8_t
name|custData
index|[
literal|64
index|]
decl_stmt|;
comment|// 64 B
name|MODAL_EEP_HEADER
name|modalHeader
index|[
literal|2
index|]
decl_stmt|;
comment|// 200 B
name|uint8_t
name|calFreqPier5G
index|[
name|AR5416_NUM_5G_CAL_PIERS
index|]
decl_stmt|;
name|uint8_t
name|calFreqPier2G
index|[
name|AR5416_NUM_2G_CAL_PIERS
index|]
decl_stmt|;
name|CAL_DATA_PER_FREQ
name|calPierData5G
index|[
name|AR5416_MAX_CHAINS
index|]
index|[
name|AR5416_NUM_5G_CAL_PIERS
index|]
decl_stmt|;
name|CAL_DATA_PER_FREQ
name|calPierData2G
index|[
name|AR5416_MAX_CHAINS
index|]
index|[
name|AR5416_NUM_2G_CAL_PIERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_LEG
name|calTargetPower5G
index|[
name|AR5416_NUM_5G_20_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_HT
name|calTargetPower5GHT20
index|[
name|AR5416_NUM_5G_20_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_HT
name|calTargetPower5GHT40
index|[
name|AR5416_NUM_5G_40_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_LEG
name|calTargetPowerCck
index|[
name|AR5416_NUM_2G_CCK_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_LEG
name|calTargetPower2G
index|[
name|AR5416_NUM_2G_20_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_HT
name|calTargetPower2GHT20
index|[
name|AR5416_NUM_2G_20_TARGET_POWERS
index|]
decl_stmt|;
name|CAL_TARGET_POWER_HT
name|calTargetPower2GHT40
index|[
name|AR5416_NUM_2G_40_TARGET_POWERS
index|]
decl_stmt|;
name|uint8_t
name|ctlIndex
index|[
name|AR5416_NUM_CTLS
index|]
decl_stmt|;
name|CAL_CTL_DATA
name|ctlData
index|[
name|AR5416_NUM_CTLS
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
name|ar5416eeprom
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
name|AR5416_NUM_CTLS
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
name|HAL_EEPROM_v14
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AH_EEPROM_V14_H_ */
end_comment

end_unit

