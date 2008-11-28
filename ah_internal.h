begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ah_internal.h,v 1.21 2008/11/27 22:29:27 sam Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_INTERAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_INTERAL_H_
end_define

begin_comment
comment|/*  * Atheros Device Hardware Access Layer (HAL).  *  * Internal definitions.  */
end_comment

begin_define
define|#
directive|define
name|AH_NULL
value|0
end_define

begin_define
define|#
directive|define
name|AH_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<(b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|AH_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(a):(b))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NBBY
end_ifndef

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits/byte */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|roundup
end_ifndef

begin_define
define|#
directive|define
name|roundup
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x)+((y)-1))/(y))*(y))
end_define

begin_comment
comment|/* to any y */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|howmany
end_ifndef

begin_define
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))/(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|((size_t)(&((type *)0)->field))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Remove const in a way that keeps the compiler happy.  * This works for gcc but may require other magic for  * other compilers (not sure where this should reside).  * Note that uintptr_t is C99.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DECONST
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_UINTPTR_T
end_ifndef

begin_if
if|#
directive|if
name|AH_WORDSIZE
operator|==
literal|64
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|uintptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uintptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__DECONST
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((type)(uintptr_t)(const void *)(var))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|start
decl_stmt|;
comment|/* first register */
name|uint16_t
name|end
decl_stmt|;
comment|/* ending register or zero */
block|}
name|HAL_REGRANGE
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit power scale factor.  *  * NB: This is not public because we want to discourage the use of  *     scaling; folks should use the tx power limit interface.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_TP_SCALE_MAX
init|=
literal|0
block|,
comment|/* no scaling (default) */
name|HAL_TP_SCALE_50
init|=
literal|1
block|,
comment|/* 50% of max (-3 dBm) */
name|HAL_TP_SCALE_25
init|=
literal|2
block|,
comment|/* 25% of max (-6 dBm) */
name|HAL_TP_SCALE_12
init|=
literal|3
block|,
comment|/* 12% of max (-9 dBm) */
name|HAL_TP_SCALE_MIN
init|=
literal|4
block|,
comment|/* min, but still on */
block|}
name|HAL_TP_SCALE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_CAP_RADAR
init|=
literal|0
block|,
comment|/* Radar capability */
name|HAL_CAP_AR
init|=
literal|1
block|,
comment|/* AR capability */
block|}
name|HAL_PHYDIAG_CAPS
typedef|;
end_typedef

begin_comment
comment|/*  * Internal form of a HAL_CHANNEL.  Note that the structure  * must be defined such that you can cast references to a  * HAL_CHANNEL so don't shuffle the first two members.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|channelFlags
decl_stmt|;
name|uint16_t
name|channel
decl_stmt|;
comment|/* NB: must be first for casting */
name|uint8_t
name|privFlags
decl_stmt|;
name|int8_t
name|maxRegTxPower
decl_stmt|;
name|int8_t
name|maxTxPower
decl_stmt|;
name|int8_t
name|minTxPower
decl_stmt|;
comment|/* as above... */
name|HAL_BOOL
name|bssSendHere
decl_stmt|;
name|uint8_t
name|gainI
decl_stmt|;
name|HAL_BOOL
name|iqCalValid
decl_stmt|;
name|uint8_t
name|calValid
decl_stmt|;
comment|/* bitmask of cal types */
name|int8_t
name|iCoff
decl_stmt|;
name|int8_t
name|qCoff
decl_stmt|;
name|int16_t
name|rawNoiseFloor
decl_stmt|;
name|int16_t
name|noiseFloorAdjust
decl_stmt|;
name|int8_t
name|antennaMax
decl_stmt|;
name|uint32_t
name|regDmnFlags
decl_stmt|;
comment|/* Flags for channel use in reg */
name|uint32_t
name|conformanceTestLimit
decl_stmt|;
comment|/* conformance test limit from reg domain */
name|uint16_t
name|mainSpur
decl_stmt|;
comment|/* cached spur value for this cahnnel */
block|}
name|HAL_CHANNEL_INTERNAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|halChanSpreadSupport
range|:
literal|1
decl_stmt|,
name|halSleepAfterBeaconBroken
range|:
literal|1
decl_stmt|,
name|halCompressSupport
range|:
literal|1
decl_stmt|,
name|halBurstSupport
range|:
literal|1
decl_stmt|,
name|halFastFramesSupport
range|:
literal|1
decl_stmt|,
name|halChapTuningSupport
range|:
literal|1
decl_stmt|,
name|halTurboGSupport
range|:
literal|1
decl_stmt|,
name|halTurboPrimeSupport
range|:
literal|1
decl_stmt|,
name|halMicAesCcmSupport
range|:
literal|1
decl_stmt|,
name|halMicCkipSupport
range|:
literal|1
decl_stmt|,
name|halMicTkipSupport
range|:
literal|1
decl_stmt|,
name|halTkipMicTxRxKeySupport
range|:
literal|1
decl_stmt|,
name|halCipherAesCcmSupport
range|:
literal|1
decl_stmt|,
name|halCipherCkipSupport
range|:
literal|1
decl_stmt|,
name|halCipherTkipSupport
range|:
literal|1
decl_stmt|,
name|halPSPollBroken
range|:
literal|1
decl_stmt|,
name|halVEOLSupport
range|:
literal|1
decl_stmt|,
name|halBssIdMaskSupport
range|:
literal|1
decl_stmt|,
name|halMcastKeySrchSupport
range|:
literal|1
decl_stmt|,
name|halTsfAddSupport
range|:
literal|1
decl_stmt|,
name|halChanHalfRate
range|:
literal|1
decl_stmt|,
name|halChanQuarterRate
range|:
literal|1
decl_stmt|,
name|halHTSupport
range|:
literal|1
decl_stmt|,
name|halRfSilentSupport
range|:
literal|1
decl_stmt|,
name|halHwPhyCounterSupport
range|:
literal|1
decl_stmt|,
name|halWowSupport
range|:
literal|1
decl_stmt|,
name|halWowMatchPatternExact
range|:
literal|1
decl_stmt|,
name|halAutoSleepSupport
range|:
literal|1
decl_stmt|,
name|halFastCCSupport
range|:
literal|1
decl_stmt|,
name|halBtCoexSupport
range|:
literal|1
decl_stmt|;
name|uint32_t
name|halRxStbcSupport
range|:
literal|1
decl_stmt|,
name|halTxStbcSupport
range|:
literal|1
decl_stmt|,
name|halGTTSupport
range|:
literal|1
decl_stmt|,
name|halCSTSupport
range|:
literal|1
decl_stmt|,
name|halRifsRxSupport
range|:
literal|1
decl_stmt|,
name|halRifsTxSupport
range|:
literal|1
decl_stmt|,
name|halExtChanDfsSupport
range|:
literal|1
decl_stmt|,
name|halForcePpmSupport
range|:
literal|1
decl_stmt|,
name|halEnhancedPmSupport
range|:
literal|1
decl_stmt|,
name|halMbssidAggrSupport
range|:
literal|1
decl_stmt|;
name|uint32_t
name|halWirelessModes
decl_stmt|;
name|uint16_t
name|halTotalQueues
decl_stmt|;
name|uint16_t
name|halKeyCacheSize
decl_stmt|;
name|uint16_t
name|halLow5GhzChan
decl_stmt|,
name|halHigh5GhzChan
decl_stmt|;
name|uint16_t
name|halLow2GhzChan
decl_stmt|,
name|halHigh2GhzChan
decl_stmt|;
name|int
name|halTstampPrecision
decl_stmt|;
name|int
name|halRtsAggrLimit
decl_stmt|;
name|uint8_t
name|halTxChainMask
decl_stmt|;
name|uint8_t
name|halRxChainMask
decl_stmt|;
name|uint8_t
name|halNumGpioPins
decl_stmt|;
name|uint8_t
name|halNumAntCfg2GHz
decl_stmt|;
name|uint8_t
name|halNumAntCfg5GHz
decl_stmt|;
block|}
name|HAL_CAPABILITIES
typedef|;
end_typedef

begin_comment
comment|/*  * The ``private area'' follows immediately after the ``public area''  * in the data structure returned by ath_hal_attach.  Private data are  * used by device-independent code such as the regulatory domain support.  * In general, code within the HAL should never depend on data in the  * public area.  Instead any public data needed internally should be  * shadowed here.  *  * When declaring a device-specific ath_hal data structure this structure  * is assumed to at the front; e.g.  *  *	struct ath_hal_5212 {  *		struct ath_hal_private	ah_priv;  *		...  *	};  *  * It might be better to manage the method pointers in this structure  * using an indirect pointer to a read-only data structure but this would  * disallow class-style method overriding.  */
end_comment

begin_struct
struct|struct
name|ath_hal_private
block|{
name|struct
name|ath_hal
name|h
decl_stmt|;
comment|/* public area */
comment|/* NB: all methods go first to simplify initialization */
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_getChannelEdges
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint16_t
name|channelFlags
parameter_list|,
name|uint16_t
modifier|*
name|lowChannel
parameter_list|,
name|uint16_t
modifier|*
name|highChannel
parameter_list|)
function_decl|;
name|u_int
function_decl|(
modifier|*
name|ah_getWirelessModes
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_eepromRead
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|off
parameter_list|,
name|uint16_t
modifier|*
name|data
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_eepromWrite
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|off
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_gpioCfgOutput
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|gpio
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_gpioCfgInput
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|gpio
parameter_list|)
function_decl|;
name|uint32_t
function_decl|(
modifier|*
name|ah_gpioGet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|gpio
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_gpioSet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|gpio
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ah_gpioSetIntr
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_getChipPowerLimits
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_CHANNEL
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|int16_t
function_decl|(
modifier|*
name|ah_getNfAdjust
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|HAL_CHANNEL_INTERNAL
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ah_getNoiseFloor
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int16_t
name|nfarray
index|[]
parameter_list|)
function_decl|;
name|void
modifier|*
name|ah_eeprom
decl_stmt|;
comment|/* opaque EEPROM state */
name|uint16_t
name|ah_eeversion
decl_stmt|;
comment|/* EEPROM version */
name|void
function_decl|(
modifier|*
name|ah_eepromDetach
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_STATUS
function_decl|(
modifier|*
name|ah_eepromGet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_eepromSet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|uint16_t
function_decl|(
modifier|*
name|ah_getSpurChan
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
parameter_list|,
name|HAL_BOOL
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|ah_eepromDiag
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
name|request
parameter_list|,
specifier|const
name|void
modifier|*
name|args
parameter_list|,
name|uint32_t
name|argsize
parameter_list|,
name|void
modifier|*
modifier|*
name|result
parameter_list|,
name|uint32_t
modifier|*
name|resultsize
parameter_list|)
function_decl|;
comment|/* 	 * Device revision information. 	 */
name|uint16_t
name|ah_devid
decl_stmt|;
comment|/* PCI device ID */
name|uint16_t
name|ah_subvendorid
decl_stmt|;
comment|/* PCI subvendor ID */
name|uint32_t
name|ah_macVersion
decl_stmt|;
comment|/* MAC version id */
name|uint16_t
name|ah_macRev
decl_stmt|;
comment|/* MAC revision */
name|uint16_t
name|ah_phyRev
decl_stmt|;
comment|/* PHY revision */
name|uint16_t
name|ah_analog5GhzRev
decl_stmt|;
comment|/* 2GHz radio revision */
name|uint16_t
name|ah_analog2GhzRev
decl_stmt|;
comment|/* 5GHz radio revision */
name|HAL_OPMODE
name|ah_opmode
decl_stmt|;
comment|/* operating mode from reset */
name|HAL_CAPABILITIES
name|ah_caps
decl_stmt|;
comment|/* device capabilities */
name|uint32_t
name|ah_diagreg
decl_stmt|;
comment|/* user-specified AR_DIAG_SW */
name|int16_t
name|ah_powerLimit
decl_stmt|;
comment|/* tx power cap */
name|uint16_t
name|ah_maxPowerLevel
decl_stmt|;
comment|/* calculated max tx power */
name|u_int
name|ah_tpScale
decl_stmt|;
comment|/* tx power scale factor */
name|uint32_t
name|ah_11nCompat
decl_stmt|;
comment|/* 11n compat controls */
comment|/* 	 * State for regulatory domain handling. 	 */
name|HAL_REG_DOMAIN
name|ah_currentRD
decl_stmt|;
comment|/* Current regulatory domain */
name|HAL_CTRY_CODE
name|ah_countryCode
decl_stmt|;
comment|/* current country code */
name|HAL_CHANNEL_INTERNAL
name|ah_channels
index|[
literal|256
index|]
decl_stmt|;
comment|/* calculated channel list */
name|u_int
name|ah_nchan
decl_stmt|;
comment|/* valid channels in list */
name|HAL_CHANNEL_INTERNAL
modifier|*
name|ah_curchan
decl_stmt|;
comment|/* current channel */
name|uint8_t
name|ah_coverageClass
decl_stmt|;
comment|/* coverage class */
name|HAL_BOOL
name|ah_regdomainUpdate
decl_stmt|;
comment|/* regdomain is updated? */
comment|/* 	 * RF Silent handling; setup according to the EEPROM. 	 */
name|uint16_t
name|ah_rfsilent
decl_stmt|;
comment|/* GPIO pin + polarity */
name|HAL_BOOL
name|ah_rfkillEnabled
decl_stmt|;
comment|/* enable/disable RfKill */
comment|/* 	 * Diagnostic support for discriminating HIUERR reports. 	 */
name|uint32_t
name|ah_fatalState
index|[
literal|6
index|]
decl_stmt|;
comment|/* AR_ISR+shadow regs */
name|int
name|ah_rxornIsFatal
decl_stmt|;
comment|/* how to treat HAL_INT_RXORN */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AH_PRIVATE
parameter_list|(
name|_ah
parameter_list|)
value|((struct ath_hal_private *)(_ah))
end_define

begin_define
define|#
directive|define
name|ath_hal_getChannelEdges
parameter_list|(
name|_ah
parameter_list|,
name|_cf
parameter_list|,
name|_lc
parameter_list|,
name|_hc
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_getChannelEdges(_ah, _cf, _lc, _hc)
end_define

begin_define
define|#
directive|define
name|ath_hal_getWirelessModes
parameter_list|(
name|_ah
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_getWirelessModes(_ah)
end_define

begin_define
define|#
directive|define
name|ath_hal_eepromRead
parameter_list|(
name|_ah
parameter_list|,
name|_off
parameter_list|,
name|_data
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_eepromRead(_ah, _off, _data)
end_define

begin_define
define|#
directive|define
name|ath_hal_eepromWrite
parameter_list|(
name|_ah
parameter_list|,
name|_off
parameter_list|,
name|_data
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_eepromWrite(_ah, _off, _data)
end_define

begin_define
define|#
directive|define
name|ath_hal_gpioCfgOutput
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_gpioCfgOutput(_ah, _gpio)
end_define

begin_define
define|#
directive|define
name|ath_hal_gpioCfgInput
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_gpioCfgInput(_ah, _gpio)
end_define

begin_define
define|#
directive|define
name|ath_hal_gpioGet
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_gpioGet(_ah, _gpio)
end_define

begin_define
define|#
directive|define
name|ath_hal_gpioSet
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|,
name|_val
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_gpioGet(_ah, _gpio, _val)
end_define

begin_define
define|#
directive|define
name|ath_hal_gpioSetIntr
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|,
name|_ilevel
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_gpioSetIntr(_ah, _gpio, _ilevel)
end_define

begin_define
define|#
directive|define
name|ath_hal_getpowerlimits
parameter_list|(
name|_ah
parameter_list|,
name|_chans
parameter_list|,
name|_nchan
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_getChipPowerLimits(_ah, _chans, _nchan)
end_define

begin_define
define|#
directive|define
name|ath_hal_getNfAdjust
parameter_list|(
name|_ah
parameter_list|,
name|_c
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_getNfAdjust(_ah, _c)
end_define

begin_define
define|#
directive|define
name|ath_hal_getNoiseFloor
parameter_list|(
name|_ah
parameter_list|,
name|_nfArray
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_getNoiseFloor(_ah, _nfArray)
end_define

begin_define
define|#
directive|define
name|ath_hal_eepromDetach
parameter_list|(
name|_ah
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_eepromDetach(_ah)
end_define

begin_define
define|#
directive|define
name|ath_hal_eepromGet
parameter_list|(
name|_ah
parameter_list|,
name|_param
parameter_list|,
name|_val
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_eepromGet(_ah, _param, _val)
end_define

begin_define
define|#
directive|define
name|ath_hal_eepromSet
parameter_list|(
name|_ah
parameter_list|,
name|_param
parameter_list|,
name|_val
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_eepromSet(_ah, _param, _val)
end_define

begin_define
define|#
directive|define
name|ath_hal_eepromGetFlag
parameter_list|(
name|_ah
parameter_list|,
name|_param
parameter_list|)
define|\
value|(AH_PRIVATE(_ah)->ah_eepromGet(_ah, _param, AH_NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getSpurChan
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|,
name|_is2G
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_getSpurChan(_ah, _ix, _is2G)
end_define

begin_define
define|#
directive|define
name|ath_hal_eepromDiag
parameter_list|(
name|_ah
parameter_list|,
name|_request
parameter_list|,
name|_a
parameter_list|,
name|_asize
parameter_list|,
name|_r
parameter_list|,
name|_rsize
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_eepromDiag(_ah, _request, _a, _asize,  _r, _rsize)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_NET_IF_IEEE80211_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_NET80211__IEEE80211_H_
argument_list|)
end_if

begin_comment
comment|/*  * Stuff that would naturally come from _ieee80211.h  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_KEYLEN
value|5
end_define

begin_comment
comment|/* 40bit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_IVLEN
value|3
end_define

begin_comment
comment|/* 24bit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_KIDLEN
value|1
end_define

begin_comment
comment|/* 1 octet */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_CRCLEN
value|4
end_define

begin_comment
comment|/* CRC-32 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CRC_LEN
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|IEEE80211_MAX_LEN
value|(2300 + IEEE80211_CRC_LEN + \     (IEEE80211_WEP_IVLEN + IEEE80211_WEP_KIDLEN + IEEE80211_WEP_CRCLEN))
end_define

begin_enum
enum|enum
block|{
name|IEEE80211_T_DS
block|,
comment|/* direct sequence spread spectrum */
name|IEEE80211_T_FH
block|,
comment|/* frequency hopping */
name|IEEE80211_T_OFDM
block|,
comment|/* frequency division multiplexing */
name|IEEE80211_T_TURBO
block|,
comment|/* high rate DS */
name|IEEE80211_T_HT
block|,
comment|/* HT - full GI */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_T_CCK
value|IEEE80211_T_DS
end_define

begin_comment
comment|/* more common nomenclatur */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_IEEE80211_H_ */
end_comment

begin_comment
comment|/* NB: these are defined privately until XR support is announced */
end_comment

begin_enum
enum|enum
block|{
name|ATHEROS_T_XR
init|=
name|IEEE80211_T_HT
operator|+
literal|1
block|,
comment|/* extended range */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|HAL_TXQ_USE_LOCKOUT_BKOFF_DIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INIT_AIFS
value|2
end_define

begin_define
define|#
directive|define
name|INIT_CWMIN
value|15
end_define

begin_define
define|#
directive|define
name|INIT_CWMIN_11B
value|31
end_define

begin_define
define|#
directive|define
name|INIT_CWMAX
value|1023
end_define

begin_define
define|#
directive|define
name|INIT_SH_RETRY
value|10
end_define

begin_define
define|#
directive|define
name|INIT_LG_RETRY
value|10
end_define

begin_define
define|#
directive|define
name|INIT_SSH_RETRY
value|32
end_define

begin_define
define|#
directive|define
name|INIT_SLG_RETRY
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|tqi_ver
decl_stmt|;
comment|/* HAL TXQ verson */
name|HAL_TX_QUEUE
name|tqi_type
decl_stmt|;
comment|/* hw queue type*/
name|HAL_TX_QUEUE_SUBTYPE
name|tqi_subtype
decl_stmt|;
comment|/* queue subtype, if applicable */
name|HAL_TX_QUEUE_FLAGS
name|tqi_qflags
decl_stmt|;
comment|/* queue flags */
name|uint32_t
name|tqi_priority
decl_stmt|;
name|uint32_t
name|tqi_aifs
decl_stmt|;
comment|/* aifs */
name|uint32_t
name|tqi_cwmin
decl_stmt|;
comment|/* cwMin */
name|uint32_t
name|tqi_cwmax
decl_stmt|;
comment|/* cwMax */
name|uint16_t
name|tqi_shretry
decl_stmt|;
comment|/* frame short retry limit */
name|uint16_t
name|tqi_lgretry
decl_stmt|;
comment|/* frame long retry limit */
name|uint32_t
name|tqi_cbrPeriod
decl_stmt|;
name|uint32_t
name|tqi_cbrOverflowLimit
decl_stmt|;
name|uint32_t
name|tqi_burstTime
decl_stmt|;
name|uint32_t
name|tqi_readyTime
decl_stmt|;
name|uint32_t
name|tqi_physCompBuf
decl_stmt|;
name|uint32_t
name|tqi_intFlags
decl_stmt|;
comment|/* flags for internal use */
block|}
name|HAL_TX_QUEUE_INFO
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ath_hal_setTxQProps
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_TX_QUEUE_INFO
modifier|*
name|qi
parameter_list|,
specifier|const
name|HAL_TXQ_INFO
modifier|*
name|qInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ath_hal_getTxQProps
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_TXQ_INFO
modifier|*
name|qInfo
parameter_list|,
specifier|const
name|HAL_TX_QUEUE_INFO
modifier|*
name|qi
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_ANI_PRESENT
block|,
comment|/* is ANI support present */
name|HAL_ANI_NOISE_IMMUNITY_LEVEL
block|,
comment|/* set level */
name|HAL_ANI_OFDM_WEAK_SIGNAL_DETECTION
block|,
comment|/* enable/disable */
name|HAL_ANI_CCK_WEAK_SIGNAL_THR
block|,
comment|/* enable/disable */
name|HAL_ANI_FIRSTEP_LEVEL
block|,
comment|/* set level */
name|HAL_ANI_SPUR_IMMUNITY_LEVEL
block|,
comment|/* set level */
name|HAL_ANI_MODE
init|=
literal|6
block|,
comment|/* 0 => manual, 1 => auto (XXX do not change) */
name|HAL_ANI_PHYERR_RESET
block|,
comment|/* reset phy error stats */
block|}
name|HAL_ANI_CMD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_SPUR_VAL_MASK
value|0x3FFF
end_define

begin_define
define|#
directive|define
name|HAL_SPUR_CHAN_WIDTH
value|87
end_define

begin_define
define|#
directive|define
name|HAL_BIN_WIDTH_BASE_100HZ
value|3125
end_define

begin_define
define|#
directive|define
name|HAL_BIN_WIDTH_TURBO_100HZ
value|6250
end_define

begin_define
define|#
directive|define
name|HAL_MAX_BINS_ALLOWED
value|28
end_define

begin_comment
comment|/*  * A    = 5GHZ|OFDM  * T    = 5GHZ|OFDM|TURBO  *  * IS_CHAN_A(T) will return TRUE.  This is probably  * not the default behavior we want.  We should migrate to a better mask --  * perhaps CHANNEL_ALL.  *  * For now, IS_CHAN_G() masks itself with CHANNEL_108G.  *  */
end_comment

begin_define
define|#
directive|define
name|IS_CHAN_A
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_A) == CHANNEL_A)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_B
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_B) == CHANNEL_B)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_G
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& (CHANNEL_108G|CHANNEL_G)) == CHANNEL_G)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_108G
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_108G) == CHANNEL_108G)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_T
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_T) == CHANNEL_T)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_PUREG
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->channelFlags& CHANNEL_PUREG) == CHANNEL_PUREG)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_TURBO
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_TURBO) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_CCK
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_CCK) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_OFDM
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_OFDM) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_5GHZ
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_5GHZ) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_2GHZ
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_2GHZ) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_PASSIVE
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_PASSIVE) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_HALF_RATE
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_HALF) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_QUARTER_RATE
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_QUARTER) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_IN_PUBLIC_SAFETY_BAND
parameter_list|(
name|_c
parameter_list|)
value|((_c)> 4940&& (_c)< 4990)
end_define

begin_define
define|#
directive|define
name|CHANNEL_HT40
value|(CHANNEL_HT40PLUS | CHANNEL_HT40MINUS)
end_define

begin_define
define|#
directive|define
name|CHANNEL_HT
value|(CHANNEL_HT20 | CHANNEL_HT40)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_HT
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_HT) != 0)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_HT20
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_HT) == CHANNEL_HT20)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_HT40
parameter_list|(
name|_c
parameter_list|)
value|(((_c)->channelFlags& CHANNEL_HT40) != 0)
end_define

begin_comment
comment|/*  * Deduce if the host cpu has big- or litt-endian byte order.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|isBigEndian
parameter_list|(
name|void
parameter_list|)
block|{
union|union
block|{
name|int32_t
name|i
decl_stmt|;
name|char
name|c
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|u
operator|.
name|c
index|[
literal|0
index|]
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* unalligned little endian access */
end_comment

begin_define
define|#
directive|define
name|LE_READ_2
parameter_list|(
name|p
parameter_list|)
define|\
value|((uint16_t)							\ 	 ((((const uint8_t *)(p))[0]    ) | (((const uint8_t *)(p))[1]<< 8)))
end_define

begin_define
define|#
directive|define
name|LE_READ_4
parameter_list|(
name|p
parameter_list|)
define|\
value|((uint32_t)							\ 	 ((((const uint8_t *)(p))[0]    ) | (((const uint8_t *)(p))[1]<< 8) |\ 	  (((const uint8_t *)(p))[2]<<16) | (((const uint8_t *)(p))[3]<<24)))
end_define

begin_comment
comment|/*  * Register manipulation macros that expect bit field defines  * to follow the convention that an _S suffix is appended for  * a shift count, while the field mask has no suffix.  */
end_comment

begin_define
define|#
directive|define
name|SM
parameter_list|(
name|_v
parameter_list|,
name|_f
parameter_list|)
value|(((_v)<< _f##_S)& (_f))
end_define

begin_define
define|#
directive|define
name|MS
parameter_list|(
name|_v
parameter_list|,
name|_f
parameter_list|)
value|(((_v)& (_f))>> _f##_S)
end_define

begin_define
define|#
directive|define
name|OS_REG_RMW_FIELD
parameter_list|(
name|_a
parameter_list|,
name|_r
parameter_list|,
name|_f
parameter_list|,
name|_v
parameter_list|)
define|\
value|OS_REG_WRITE(_a, _r, \ 		(OS_REG_READ(_a, _r)&~ (_f)) | (((_v)<< _f##_S)& (_f)))
end_define

begin_define
define|#
directive|define
name|OS_REG_SET_BIT
parameter_list|(
name|_a
parameter_list|,
name|_r
parameter_list|,
name|_f
parameter_list|)
define|\
value|OS_REG_WRITE(_a, _r, OS_REG_READ(_a, _r) | (_f))
end_define

begin_define
define|#
directive|define
name|OS_REG_CLR_BIT
parameter_list|(
name|_a
parameter_list|,
name|_r
parameter_list|,
name|_f
parameter_list|)
define|\
value|OS_REG_WRITE(_a, _r, OS_REG_READ(_a, _r)&~ (_f))
end_define

begin_comment
comment|/*   * Regulatory domain support.  */
end_comment

begin_comment
comment|/*  * Return the max allowed antenna gain based on the current  * regulatory domain.  */
end_comment

begin_function_decl
specifier|extern
name|u_int
name|ath_hal_getantennareduction
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_CHANNEL
modifier|*
parameter_list|,
name|u_int
name|twiceGain
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the test group for the specific channel based on  * the current regulator domain.  */
end_comment

begin_function_decl
specifier|extern
name|u_int
name|ath_hal_getctl
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_CHANNEL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return whether or not a noise floor check is required  * based on the current regulatory domain for the specified  * channel.  */
end_comment

begin_function_decl
specifier|extern
name|u_int
name|ath_hal_getnfcheckrequired
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_CHANNEL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Map a public channel definition to the corresponding  * internal data structure.  This implicitly specifies  * whether or not the specified channel is ok to use  * based on the current regulatory domain constraints.  */
end_comment

begin_function_decl
specifier|extern
name|HAL_CHANNEL_INTERNAL
modifier|*
name|ath_hal_checkchannel
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|HAL_CHANNEL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* system-configurable parameters */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ath_hal_dma_beacon_response_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in TU's */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ath_hal_sw_beacon_response_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in TU's */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ath_hal_additional_swba_backoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in TU's */
end_comment

begin_comment
comment|/* wait for the register contents to have the specified value */
end_comment

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ath_hal_wait
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|uint32_t
name|mask
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return the first n bits in val reversed */
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|ath_hal_reverseBits
parameter_list|(
name|uint32_t
name|val
parameter_list|,
name|uint32_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* printf interfaces */
end_comment

begin_function_decl
specifier|extern
name|void
name|ath_hal_printf
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|ath_hal_vprintf
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|ath_hal_ether_sprintf
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* allocate and free memory */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ath_hal_malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_hal_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* common debugging interfaces */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AH_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|"ah_debug.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|ath_hal_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|HALDEBUG
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HALDEBUG
parameter_list|(
name|_ah
parameter_list|,
name|__m
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_DEBUG */
end_comment

begin_comment
comment|/*  * Register logging definitions shared with ardecode.  */
end_comment

begin_include
include|#
directive|include
file|"ah_decode.h"
end_include

begin_comment
comment|/*  * Common assertion interface.  Note: it is a bad idea to generate  * an assertion failure for any recoverable event.  Instead catch  * the violation and, if possible, fix it up or recover from it; either  * with an error return value or a diagnostic messages.  System software  * does not panic unless the situation is hopeless.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AH_ASSERT
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ath_hal_assert_failed
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|lineno
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HALASSERT
parameter_list|(
name|_x
parameter_list|)
value|do {					\ 	if (!(_x)) {						\ 		ath_hal_assert_failed(__FILE__, __LINE__, #_x);	\ 	}							\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HALASSERT
parameter_list|(
name|_x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_ASSERT */
end_comment

begin_comment
comment|/*  * Convert between microseconds and core system clocks.  */
end_comment

begin_function_decl
specifier|extern
name|u_int
name|ath_hal_mac_clks
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|usecs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int
name|ath_hal_mac_usec
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|clks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Generic get/set capability support.  Each chip overrides  * this routine to support chip-specific capabilities.  */
end_comment

begin_function_decl
specifier|extern
name|HAL_STATUS
name|ath_hal_getcapability
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_CAPABILITY_TYPE
name|type
parameter_list|,
name|uint32_t
name|capability
parameter_list|,
name|uint32_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ath_hal_setcapability
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_CAPABILITY_TYPE
name|type
parameter_list|,
name|uint32_t
name|capability
parameter_list|,
name|uint32_t
name|setting
parameter_list|,
name|HAL_STATUS
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Diagnostic interface.  This is an open-ended interface that  * is opaque to applications.  Diagnostic programs use this to  * retrieve internal data structures, etc.  There is no guarantee  * that calling conventions for calls other than HAL_DIAG_REVS  * are stable between HAL releases; a diagnostic application must  * use the HAL revision information to deal with ABI/API differences.  *  * NB: do not renumber these, certain codes are publicly used.  */
end_comment

begin_enum
enum|enum
block|{
name|HAL_DIAG_REVS
init|=
literal|0
block|,
comment|/* MAC/PHY/Radio revs */
name|HAL_DIAG_EEPROM
init|=
literal|1
block|,
comment|/* EEPROM contents */
name|HAL_DIAG_EEPROM_EXP_11A
init|=
literal|2
block|,
comment|/* EEPROM 5112 power exp for 11a */
name|HAL_DIAG_EEPROM_EXP_11B
init|=
literal|3
block|,
comment|/* EEPROM 5112 power exp for 11b */
name|HAL_DIAG_EEPROM_EXP_11G
init|=
literal|4
block|,
comment|/* EEPROM 5112 power exp for 11g */
name|HAL_DIAG_ANI_CURRENT
init|=
literal|5
block|,
comment|/* ANI current channel state */
name|HAL_DIAG_ANI_OFDM
init|=
literal|6
block|,
comment|/* ANI OFDM timing error stats */
name|HAL_DIAG_ANI_CCK
init|=
literal|7
block|,
comment|/* ANI CCK timing error stats */
name|HAL_DIAG_ANI_STATS
init|=
literal|8
block|,
comment|/* ANI statistics */
name|HAL_DIAG_RFGAIN
init|=
literal|9
block|,
comment|/* RfGain GAIN_VALUES */
name|HAL_DIAG_RFGAIN_CURSTEP
init|=
literal|10
block|,
comment|/* RfGain GAIN_OPTIMIZATION_STEP */
name|HAL_DIAG_PCDAC
init|=
literal|11
block|,
comment|/* PCDAC table */
name|HAL_DIAG_TXRATES
init|=
literal|12
block|,
comment|/* Transmit rate table */
name|HAL_DIAG_REGS
init|=
literal|13
block|,
comment|/* Registers */
name|HAL_DIAG_ANI_CMD
init|=
literal|14
block|,
comment|/* ANI issue command (XXX do not change!) */
name|HAL_DIAG_SETKEY
init|=
literal|15
block|,
comment|/* Set keycache backdoor */
name|HAL_DIAG_RESETKEY
init|=
literal|16
block|,
comment|/* Reset keycache backdoor */
name|HAL_DIAG_EEREAD
init|=
literal|17
block|,
comment|/* Read EEPROM word */
name|HAL_DIAG_EEWRITE
init|=
literal|18
block|,
comment|/* Write EEPROM word */
comment|/* 19 was HAL_DIAG_TXCONT, 20-23 were for radar */
name|HAL_DIAG_REGREAD
init|=
literal|24
block|,
comment|/* Reg reads */
name|HAL_DIAG_REGWRITE
init|=
literal|25
block|,
comment|/* Reg writes */
name|HAL_DIAG_GET_REGBASE
init|=
literal|26
block|,
comment|/* Get register base */
name|HAL_DIAG_RDWRITE
init|=
literal|27
block|,
comment|/* Write regulatory domain */
name|HAL_DIAG_RDREAD
init|=
literal|28
block|,
comment|/* Get regulatory domain */
name|HAL_DIAG_FATALERR
init|=
literal|29
block|,
comment|/* Read cached interrupt state */
name|HAL_DIAG_11NCOMPAT
init|=
literal|30
block|,
comment|/* 11n compatibility tweaks */
name|HAL_DIAG_ANI_PARAMS
init|=
literal|31
block|,
comment|/* ANI noise immunity parameters */
name|HAL_DIAG_CHECK_HANGS
init|=
literal|32
block|,
comment|/* check h/w hangs */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|HAL_BB_HANG_DFS
init|=
literal|0x0001
block|,
name|HAL_BB_HANG_RIFS
init|=
literal|0x0002
block|,
name|HAL_BB_HANG_RX_CLEAR
init|=
literal|0x0004
block|,
name|HAL_BB_HANG_UNKNOWN
init|=
literal|0x0080
block|,
name|HAL_MAC_HANG_SIG1
init|=
literal|0x0100
block|,
name|HAL_MAC_HANG_SIG2
init|=
literal|0x0200
block|,
name|HAL_MAC_HANG_UNKNOWN
init|=
literal|0x8000
block|,
name|HAL_BB_HANGS
init|=
name|HAL_BB_HANG_DFS
operator||
name|HAL_BB_HANG_RIFS
operator||
name|HAL_BB_HANG_RX_CLEAR
operator||
name|HAL_BB_HANG_UNKNOWN
block|,
name|HAL_MAC_HANGS
init|=
name|HAL_MAC_HANG_SIG1
operator||
name|HAL_MAC_HANG_SIG2
operator||
name|HAL_MAC_HANG_UNKNOWN
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Device revision information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|ah_devid
decl_stmt|;
comment|/* PCI device ID */
name|uint16_t
name|ah_subvendorid
decl_stmt|;
comment|/* PCI subvendor ID */
name|uint32_t
name|ah_macVersion
decl_stmt|;
comment|/* MAC version id */
name|uint16_t
name|ah_macRev
decl_stmt|;
comment|/* MAC revision */
name|uint16_t
name|ah_phyRev
decl_stmt|;
comment|/* PHY revision */
name|uint16_t
name|ah_analog5GhzRev
decl_stmt|;
comment|/* 2GHz radio revision */
name|uint16_t
name|ah_analog2GhzRev
decl_stmt|;
comment|/* 5GHz radio revision */
block|}
name|HAL_REVS
typedef|;
end_typedef

begin_comment
comment|/*  * Argument payload for HAL_DIAG_SETKEY.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|HAL_KEYVAL
name|dk_keyval
decl_stmt|;
name|uint16_t
name|dk_keyix
decl_stmt|;
comment|/* key index */
name|uint8_t
name|dk_mac
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|int
name|dk_xor
decl_stmt|;
comment|/* XOR key data */
block|}
name|HAL_DIAG_KEYVAL
typedef|;
end_typedef

begin_comment
comment|/*  * Argument payload for HAL_DIAG_EEWRITE.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|ee_off
decl_stmt|;
comment|/* eeprom offset */
name|uint16_t
name|ee_data
decl_stmt|;
comment|/* write data */
block|}
name|HAL_DIAG_EEVAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|offset
decl_stmt|;
comment|/* reg offset */
name|uint32_t
name|val
decl_stmt|;
comment|/* reg value  */
block|}
name|HAL_DIAG_REGVAL
typedef|;
end_typedef

begin_comment
comment|/*  * 11n compatibility tweaks.  */
end_comment

begin_define
define|#
directive|define
name|HAL_DIAG_11N_SERVICES
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HAL_DIAG_11N_SERVICES_S
value|0
end_define

begin_define
define|#
directive|define
name|HAL_DIAG_11N_TXSTOMP
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|HAL_DIAG_11N_TXSTOMP_S
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|maxNoiseImmunityLevel
decl_stmt|;
comment|/* [0..4] */
name|int
name|totalSizeDesired
index|[
literal|5
index|]
decl_stmt|;
name|int
name|coarseHigh
index|[
literal|5
index|]
decl_stmt|;
name|int
name|coarseLow
index|[
literal|5
index|]
decl_stmt|;
name|int
name|firpwr
index|[
literal|5
index|]
decl_stmt|;
name|int
name|maxSpurImmunityLevel
decl_stmt|;
comment|/* [0..7] */
name|int
name|cycPwrThr1
index|[
literal|8
index|]
decl_stmt|;
name|int
name|maxFirstepLevel
decl_stmt|;
comment|/* [0..2] */
name|int
name|firstep
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|ofdmTrigHigh
decl_stmt|;
name|uint32_t
name|ofdmTrigLow
decl_stmt|;
name|int32_t
name|cckTrigHigh
decl_stmt|;
name|int32_t
name|cckTrigLow
decl_stmt|;
name|int32_t
name|rssiThrLow
decl_stmt|;
name|int32_t
name|rssiThrHigh
decl_stmt|;
name|int
name|period
decl_stmt|;
comment|/* update listen period */
block|}
name|HAL_ANI_PARAMS
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ath_hal_getdiagstate
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|request
parameter_list|,
specifier|const
name|void
modifier|*
name|args
parameter_list|,
name|uint32_t
name|argsize
parameter_list|,
name|void
modifier|*
modifier|*
name|result
parameter_list|,
name|uint32_t
modifier|*
name|resultsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Setup a h/w rate table for use.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ath_hal_setupratetable
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_RATE_TABLE
modifier|*
name|rt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Common routine for implementing getChanNoise api.  */
end_comment

begin_function_decl
specifier|extern
name|int16_t
name|ath_hal_getChanNoise
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_CHANNEL
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialization support.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|uint32_t
modifier|*
name|data
decl_stmt|;
name|int
name|rows
decl_stmt|,
name|cols
decl_stmt|;
block|}
name|HAL_INI_ARRAY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_INI_INIT
parameter_list|(
name|_ia
parameter_list|,
name|_data
parameter_list|,
name|_cols
parameter_list|)
value|do {			\ 	(_ia)->data = (const uint32_t *)(_data);		\ 	(_ia)->rows = sizeof(_data) / sizeof((_data)[0]);	\ 	(_ia)->cols = (_cols);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|HAL_INI_VAL
parameter_list|(
name|_ia
parameter_list|,
name|_r
parameter_list|,
name|_c
parameter_list|)
define|\
value|((_ia)->data[((_r)*(_ia)->cols) + (_c)])
end_define

begin_comment
comment|/*  * OS_DELAY() does a PIO READ on the PCI bus which allows  * other cards' DMA reads to complete in the middle of our reset.  */
end_comment

begin_define
define|#
directive|define
name|DMA_YIELD
parameter_list|(
name|x
parameter_list|)
value|do {		\ 	if ((++(x) % 64) == 0)		\ 		OS_DELAY(1);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|HAL_INI_WRITE_ARRAY
parameter_list|(
name|ah
parameter_list|,
name|regArray
parameter_list|,
name|col
parameter_list|,
name|regWr
parameter_list|)
value|do {             	\ 	int r;								\ 	for (r = 0; r< N(regArray); r++) {				\ 		OS_REG_WRITE(ah, (regArray)[r][0], (regArray)[r][col]);	\ 		DMA_YIELD(regWr);					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|HAL_INI_WRITE_BANK
parameter_list|(
name|ah
parameter_list|,
name|regArray
parameter_list|,
name|bankData
parameter_list|,
name|regWr
parameter_list|)
value|do {		\ 	int r;								\ 	for (r = 0; r< N(regArray); r++) {				\ 		OS_REG_WRITE(ah, (regArray)[r][0], (bankData)[r]);	\ 		DMA_YIELD(regWr);					\ 	}								\ } while (0)
end_define

begin_function_decl
specifier|extern
name|int
name|ath_hal_ini_write
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|HAL_INI_ARRAY
modifier|*
name|ia
parameter_list|,
name|int
name|col
parameter_list|,
name|int
name|regWr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_hal_ini_bank_setup
parameter_list|(
name|uint32_t
name|data
index|[]
parameter_list|,
specifier|const
name|HAL_INI_ARRAY
modifier|*
name|ia
parameter_list|,
name|int
name|col
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_hal_ini_bank_write
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|HAL_INI_ARRAY
modifier|*
name|ia
parameter_list|,
specifier|const
name|uint32_t
name|data
index|[]
parameter_list|,
name|int
name|regWr
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|WLAN_CTRL_FRAME_SIZE
value|(2+2+6+4)
end_define

begin_comment
comment|/* ACK+FCS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_INTERAL_H_ */
end_comment

end_unit

