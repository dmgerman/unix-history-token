begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_EEPROM_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_EEPROM_H_
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VER1
value|0x1000
end_define

begin_comment
comment|/* Version 1.0; 5210 only */
end_comment

begin_comment
comment|/*  * Version 3 EEPROMs are all 16K.  * 3.1 adds turbo limit, antenna gain, 16 CTL's, 11g info,  *	and 2.4Ghz ob/db for B& G  * 3.2 has more accurate pcdac intercepts and analog chip  *	calibration.  * 3.3 adds ctl in-band limit, 32 ctl's, and frequency  *	expansion  * 3.4 adds xr power, gainI, and 2.4 turbo params  */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER3
value|0x3000
end_define

begin_comment
comment|/* Version 3.0; start of 16k EEPROM */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER3_1
value|0x3001
end_define

begin_comment
comment|/* Version 3.1 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER3_2
value|0x3002
end_define

begin_comment
comment|/* Version 3.2 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER3_3
value|0x3003
end_define

begin_comment
comment|/* Version 3.3 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER3_4
value|0x3004
end_define

begin_comment
comment|/* Version 3.4 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER4
value|0x4000
end_define

begin_comment
comment|/* Version 4.x */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER4_0
value|0x4000
end_define

begin_comment
comment|/* Version 4.0 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER4_1
value|0x4001
end_define

begin_comment
comment|/* Version 4.0 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER4_2
value|0x4002
end_define

begin_comment
comment|/* Version 4.0 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER4_3
value|0x4003
end_define

begin_comment
comment|/* Version 4.0 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER4_6
value|0x4006
end_define

begin_comment
comment|/* Version 4.0 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER4_7
value|0x3007
end_define

begin_comment
comment|/* Version 4.7 */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER4_9
value|0x4009
end_define

begin_comment
comment|/* EEPROM EAR futureproofing */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER5
value|0x5000
end_define

begin_comment
comment|/* Version 5.x */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER5_0
value|0x5000
end_define

begin_comment
comment|/* Adds new 2413 cal powers and added params */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER5_1
value|0x5001
end_define

begin_comment
comment|/* Adds capability values */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER5_3
value|0x5003
end_define

begin_comment
comment|/* Adds spur mitigation table */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER5_4
value|0x5004
end_define

begin_comment
comment|/*  * Version 14 EEPROMs came in with AR5416.  * 14.2 adds txFrameToPaOn, txFrameToDataStart, ht40PowerInc  * 14.3 adds bswAtten, bswMargin, swSettle, and base OpFlags for HT20/40  */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER14
value|0xE000
end_define

begin_comment
comment|/* Version 14.x */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER14_1
value|0xE001
end_define

begin_comment
comment|/* Adds 11n support */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_VER14_2
value|0xE002
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VER14_3
value|0xE003
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VER14_7
value|0xE007
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VER14_9
value|0xE009
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VER14_16
value|0xE010
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VER14_17
value|0xE011
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_VER14_19
value|0xE013
end_define

begin_enum
enum|enum
block|{
name|AR_EEP_RFKILL
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_AMODE
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_BMODE
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_GMODE
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_TURBO5DISABLE
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_TURBO2DISABLE
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_ISTALON
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_32KHZCRYSTAL
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_MACADDR
block|,
comment|/* uint8_t* */
name|AR_EEP_COMPRESS
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_FASTFRAME
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_AES
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_BURST
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_MAXQCU
block|,
comment|/* uint16_t* */
name|AR_EEP_KCENTRIES
block|,
comment|/* uint16_t* */
name|AR_EEP_NFTHRESH_5
block|,
comment|/* int16_t* */
name|AR_EEP_NFTHRESH_2
block|,
comment|/* int16_t* */
name|AR_EEP_REGDMN_0
block|,
comment|/* uint16_t* */
name|AR_EEP_REGDMN_1
block|,
comment|/* uint16_t* */
name|AR_EEP_OPCAP
block|,
comment|/* uint16_t* */
name|AR_EEP_OPMODE
block|,
comment|/* uint16_t* */
name|AR_EEP_RFSILENT
block|,
comment|/* uint16_t* */
name|AR_EEP_OB_5
block|,
comment|/* uint8_t* */
name|AR_EEP_DB_5
block|,
comment|/* uint8_t* */
name|AR_EEP_OB_2
block|,
comment|/* uint8_t* */
name|AR_EEP_DB_2
block|,
comment|/* uint8_t* */
name|AR_EEP_TXMASK
block|,
comment|/* uint8_t* */
name|AR_EEP_RXMASK
block|,
comment|/* uint8_t* */
name|AR_EEP_RXGAIN_TYPE
block|,
comment|/* uint8_t* */
name|AR_EEP_TXGAIN_TYPE
block|,
comment|/* uint8_t* */
name|AR_EEP_DAC_HPWR_5G
block|,
comment|/* uint8_t* */
name|AR_EEP_OL_PWRCTRL
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_FSTCLK_5G
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_ANTGAINMAX_5
block|,
comment|/* int8_t* */
name|AR_EEP_ANTGAINMAX_2
block|,
comment|/* int8_t* */
name|AR_EEP_WRITEPROTECT
block|,
comment|/* use ath_hal_eepromGetFlag */
name|AR_EEP_PWR_TABLE_OFFSET
block|,
comment|/* int8_t* */
name|AR_EEP_PWDCLKIND
block|,
comment|/* uint8_t* */
name|AR_EEP_TEMPSENSE_SLOPE
block|,
comment|/* int8_t* */
name|AR_EEP_TEMPSENSE_SLOPE_PAL_ON
block|,
comment|/* int8_t* */
name|AR_EEP_FRAC_N_5G
block|,
comment|/* uint8_t* */
comment|/* New fields for AR9300 and later */
name|AR_EEP_DRIVE_STRENGTH
block|,
name|AR_EEP_PAPRD_ENABLED
block|, }
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|rdEdge
decl_stmt|;
name|uint16_t
name|twice_rdEdgePower
decl_stmt|;
name|HAL_BOOL
name|flag
decl_stmt|;
block|}
name|RD_EDGES_POWER
typedef|;
end_typedef

begin_comment
comment|/* XXX should probably be version-dependent */
end_comment

begin_define
define|#
directive|define
name|SD_NO_CTL
value|0xf0
end_define

begin_define
define|#
directive|define
name|NO_CTL
value|0xff
end_define

begin_define
define|#
directive|define
name|CTL_MODE_M
value|0x0f
end_define

begin_define
define|#
directive|define
name|CTL_11A
value|0
end_define

begin_define
define|#
directive|define
name|CTL_11B
value|1
end_define

begin_define
define|#
directive|define
name|CTL_11G
value|2
end_define

begin_define
define|#
directive|define
name|CTL_TURBO
value|3
end_define

begin_define
define|#
directive|define
name|CTL_108G
value|4
end_define

begin_define
define|#
directive|define
name|CTL_2GHT20
value|5
end_define

begin_define
define|#
directive|define
name|CTL_5GHT20
value|6
end_define

begin_define
define|#
directive|define
name|CTL_2GHT40
value|7
end_define

begin_define
define|#
directive|define
name|CTL_5GHT40
value|8
end_define

begin_comment
comment|/* XXX must match what FCC/MKK/ETSI are defined as in ah_regdomain.h */
end_comment

begin_define
define|#
directive|define
name|HAL_REG_DMN_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|HAL_REGDMN_FCC
value|0x10
end_define

begin_define
define|#
directive|define
name|HAL_REGDMN_MKK
value|0x40
end_define

begin_define
define|#
directive|define
name|HAL_REGDMN_ETSI
value|0x30
end_define

begin_define
define|#
directive|define
name|is_reg_dmn_fcc
parameter_list|(
name|reg_dmn
parameter_list|)
define|\
value|(((reg_dmn& HAL_REG_DMN_MASK) == HAL_REGDMN_FCC) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|is_reg_dmn_etsi
parameter_list|(
name|reg_dmn
parameter_list|)
define|\
value|(((reg_dmn& HAL_REG_DMN_MASK) == HAL_REGDMN_ETSI) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|is_reg_dmn_mkk
parameter_list|(
name|reg_dmn
parameter_list|)
define|\
value|(((reg_dmn& HAL_REG_DMN_MASK) == HAL_REGDMN_MKK) ? 1 : 0)
end_define

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

begin_define
define|#
directive|define
name|AR_NO_SPUR
value|0x8000
end_define

begin_comment
comment|/* XXX exposed to chip code */
end_comment

begin_define
define|#
directive|define
name|MAX_RATE_POWER
value|63
end_define

begin_function_decl
name|HAL_STATUS
name|ath_hal_v1EepromAttach
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HAL_STATUS
name|ath_hal_legacyEepromAttach
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HAL_STATUS
name|ath_hal_v14EepromAttach
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HAL_STATUS
name|ath_hal_v4kEepromAttach
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HAL_STATUS
name|ath_hal_9287EepromAttach
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_EEPROM_H_ */
end_comment

end_unit

