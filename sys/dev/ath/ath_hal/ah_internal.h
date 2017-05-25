begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<net80211/_ieee80211.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* XXX for reasons */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_comment
comment|/* needed for AH_SUPPORT_AR5416 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AH_SUPPORT_AR5416
end_ifndef

begin_define
define|#
directive|define
name|AH_SUPPORT_AR5416
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|start
decl_stmt|;
comment|/* first register */
name|uint32_t
name|end
decl_stmt|;
comment|/* ending register or zero */
block|}
name|HAL_REGRANGE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|addr
decl_stmt|;
comment|/* regiser address/offset */
name|uint32_t
name|value
decl_stmt|;
comment|/* value to write */
block|}
name|HAL_REGWRITE
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
comment|/*  * Enable/disable strong signal fast diversity  */
end_comment

begin_define
define|#
directive|define
name|HAL_CAP_STRONG_DIV
value|2
end_define

begin_comment
comment|/*  * Each chip or class of chips registers to offer support.  *  * Compiled-in versions will include a linker set to iterate through the  * linked in code.  *  * Modules will have to register HAL backends separately.  */
end_comment

begin_struct
struct|struct
name|ath_hal_chip
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
name|uint16_t
name|vendorid
parameter_list|,
name|uint16_t
name|devid
parameter_list|)
function_decl|;
name|struct
name|ath_hal
modifier|*
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|uint16_t
name|devid
parameter_list|,
name|HAL_SOFTC
parameter_list|,
name|HAL_BUS_TAG
parameter_list|,
name|HAL_BUS_HANDLE
parameter_list|,
name|uint16_t
modifier|*
name|eepromdata
parameter_list|,
name|HAL_OPS_CONFIG
modifier|*
name|ah
parameter_list|,
name|HAL_STATUS
modifier|*
name|error
parameter_list|)
function_decl|;
name|TAILQ_ENTRY
argument_list|(
argument|ath_hal_chip
argument_list|)
name|node
expr_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|AH_CHIP
end_ifndef

begin_define
define|#
directive|define
name|AH_CHIP
parameter_list|(
name|_name
parameter_list|,
name|_probe
parameter_list|,
name|_attach
parameter_list|)
define|\
value|struct ath_hal_chip _name##_chip = {				\ 	.name		= #_name,				\ 	.probe		= _probe,				\ 	.attach		= _attach,				\ };								\ OS_DATA_SET(ah_chips, _name##_chip)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Each RF backend registers to offer support; this is mostly  * used by multi-chip 5212 solutions.  Single-chip solutions  * have a fixed idea about which RF to use.  *  * Compiled in versions will include this linker set to iterate through  * the linked in code.  *  * Modules will have to register RF backends separately.  */
end_comment

begin_struct
struct|struct
name|ath_hal_rf
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|HAL_BOOL
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
name|HAL_BOOL
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_STATUS
modifier|*
name|ecode
parameter_list|)
function_decl|;
name|TAILQ_ENTRY
argument_list|(
argument|ath_hal_rf
argument_list|)
name|node
expr_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|AH_RF
end_ifndef

begin_define
define|#
directive|define
name|AH_RF
parameter_list|(
name|_name
parameter_list|,
name|_probe
parameter_list|,
name|_attach
parameter_list|)
define|\
value|struct ath_hal_rf _name##_rf = {				\ 	.name		= __STRING(_name),			\ 	.probe		= _probe,				\ 	.attach		= _attach,				\ };								\ OS_DATA_SET(ah_rfs, _name##_rf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|ath_hal_rf
modifier|*
name|ath_hal_rfprobe
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_STATUS
modifier|*
name|ecode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Maximum number of internal channels.  Entries are per unique  * frequency so this might be need to be increased to handle all  * usage cases; typically no more than 32 are really needed but  * dynamically allocating the data structures is a bit painful  * right now.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AH_MAXCHAN
end_ifndef

begin_define
define|#
directive|define
name|AH_MAXCHAN
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAL_NF_CAL_HIST_LEN_FULL
value|5
end_define

begin_define
define|#
directive|define
name|HAL_NF_CAL_HIST_LEN_SMALL
value|1
end_define

begin_define
define|#
directive|define
name|HAL_NUM_NF_READINGS
value|6
end_define

begin_comment
comment|/* 3 chains * (ctl + ext) */
end_comment

begin_define
define|#
directive|define
name|HAL_NF_LOAD_DELAY
value|1000
end_define

begin_comment
comment|/*  * PER_CHAN doesn't work for now, as it looks like the device layer  * has to pre-populate the per-channel list with nominal values.  */
end_comment

begin_comment
comment|//#define	ATH_NF_PER_CHAN		1
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|curr_index
decl_stmt|;
name|int8_t
name|invalidNFcount
decl_stmt|;
comment|/* TO DO: REMOVE THIS! */
name|int16_t
name|priv_nf
index|[
name|HAL_NUM_NF_READINGS
index|]
decl_stmt|;
block|}
name|HAL_NFCAL_BASE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|HAL_NFCAL_BASE
name|base
decl_stmt|;
name|int16_t
name|nf_cal_buffer
index|[
name|HAL_NF_CAL_HIST_LEN_FULL
index|]
index|[
name|HAL_NUM_NF_READINGS
index|]
decl_stmt|;
block|}
name|HAL_NFCAL_HIST_FULL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|HAL_NFCAL_BASE
name|base
decl_stmt|;
name|int16_t
name|nf_cal_buffer
index|[
name|HAL_NF_CAL_HIST_LEN_SMALL
index|]
index|[
name|HAL_NUM_NF_READINGS
index|]
decl_stmt|;
block|}
name|HAL_NFCAL_HIST_SMALL
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_NF_PER_CHAN
end_ifdef

begin_typedef
typedef|typedef
name|HAL_NFCAL_HIST_FULL
name|HAL_CHAN_NFCAL_HIST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AH_HOME_CHAN_NFCAL_HIST
parameter_list|(
name|ah
parameter_list|,
name|ichan
parameter_list|)
value|(ichan ?&ichan->nf_cal_hist: NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|HAL_NFCAL_HIST_SMALL
name|HAL_CHAN_NFCAL_HIST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AH_HOME_CHAN_NFCAL_HIST
parameter_list|(
name|ah
parameter_list|,
name|ichan
parameter_list|)
value|(&AH_PRIVATE(ah)->nf_cal_hist)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATH_NF_PER_CHAN */
end_comment

begin_comment
comment|/*  * Internal per-channel state.  These are found  * using ic_devdata in the ieee80211_channel.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|channel
decl_stmt|;
comment|/* h/w frequency, NB: may be mapped */
name|uint8_t
name|privFlags
decl_stmt|;
define|#
directive|define
name|CHANNEL_IQVALID
value|0x01
comment|/* IQ calibration valid */
define|#
directive|define
name|CHANNEL_ANI_INIT
value|0x02
comment|/* ANI state initialized */
define|#
directive|define
name|CHANNEL_ANI_SETUP
value|0x04
comment|/* ANI state setup */
define|#
directive|define
name|CHANNEL_MIMO_NF_VALID
value|0x04
comment|/* Mimo NF values are valid */
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
ifdef|#
directive|ifdef
name|AH_SUPPORT_AR5416
name|int16_t
name|noiseFloorCtl
index|[
name|AH_MAX_CHAINS
index|]
decl_stmt|;
name|int16_t
name|noiseFloorExt
index|[
name|AH_MAX_CHAINS
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* AH_SUPPORT_AR5416 */
name|uint16_t
name|mainSpur
decl_stmt|;
comment|/* cached spur value for this channel */
comment|/*XXX TODO: make these part of privFlags */
name|uint8_t
name|paprd_done
range|:
literal|1
decl_stmt|,
comment|/* 1: PAPRD DONE, 0: PAPRD Cal not done */
name|paprd_table_write_done
range|:
literal|1
decl_stmt|;
comment|/* 1: DONE, 0: Cal data write not done */
name|int
name|one_time_cals_done
decl_stmt|;
name|HAL_CHAN_NFCAL_HIST
name|nf_cal_hist
decl_stmt|;
block|}
name|HAL_CHANNEL_INTERNAL
typedef|;
end_typedef

begin_comment
comment|/* channel requires noise floor check */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_NFCREQUIRED
value|IEEE80211_CHAN_PRIV0
end_define

begin_comment
comment|/* all full-width channels */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ALLFULL
define|\
value|(IEEE80211_CHAN_ALL - (IEEE80211_CHAN_HALF | IEEE80211_CHAN_QUARTER))
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ALLTURBOFULL
define|\
value|(IEEE80211_CHAN_ALLTURBO - \ 	 (IEEE80211_CHAN_HALF | IEEE80211_CHAN_QUARTER))
end_define

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
name|halHTSGI20Support
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
name|hal4AddrAggrSupport
range|:
literal|1
decl_stmt|,
name|halExtChanDfsSupport
range|:
literal|1
decl_stmt|,
name|halUseCombinedRadarRssi
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
name|halEnhancedDfsSupport
range|:
literal|1
decl_stmt|,
name|halMbssidAggrSupport
range|:
literal|1
decl_stmt|,
name|halBssidMatchSupport
range|:
literal|1
decl_stmt|,
name|hal4kbSplitTransSupport
range|:
literal|1
decl_stmt|,
name|halHasRxSelfLinkedTail
range|:
literal|1
decl_stmt|,
name|halSupportsFastClock5GHz
range|:
literal|1
decl_stmt|,
name|halHasBBReadWar
range|:
literal|1
decl_stmt|,
name|halSerialiseRegWar
range|:
literal|1
decl_stmt|,
name|halMciSupport
range|:
literal|1
decl_stmt|,
name|halRxTxAbortSupport
range|:
literal|1
decl_stmt|,
name|halPaprdEnabled
range|:
literal|1
decl_stmt|,
name|halHasUapsdSupport
range|:
literal|1
decl_stmt|,
name|halWpsPushButtonSupport
range|:
literal|1
decl_stmt|,
name|halBtCoexApsmWar
range|:
literal|1
decl_stmt|,
name|halGenTimerSupport
range|:
literal|1
decl_stmt|,
name|halLDPCSupport
range|:
literal|1
decl_stmt|,
name|halHwBeaconProcSupport
range|:
literal|1
decl_stmt|,
name|halEnhancedDmaSupport
range|:
literal|1
decl_stmt|;
name|uint32_t
name|halIsrRacSupport
range|:
literal|1
decl_stmt|,
name|halApmEnable
range|:
literal|1
decl_stmt|,
name|halIntrMitigation
range|:
literal|1
decl_stmt|,
name|hal49GhzSupport
range|:
literal|1
decl_stmt|,
name|halAntDivCombSupport
range|:
literal|1
decl_stmt|,
name|halAntDivCombSupportOrg
range|:
literal|1
decl_stmt|,
name|halRadioRetentionSupport
range|:
literal|1
decl_stmt|,
name|halSpectralScanSupport
range|:
literal|1
decl_stmt|,
name|halRxUsingLnaMixing
range|:
literal|1
decl_stmt|,
name|halRxDoMyBeacon
range|:
literal|1
decl_stmt|,
name|halHwUapsdTrig
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
name|halTxTstampPrecision
decl_stmt|;
name|int
name|halRxTstampPrecision
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
name|uint32_t
name|halIntrMask
decl_stmt|;
name|uint8_t
name|halTxStreams
decl_stmt|;
name|uint8_t
name|halRxStreams
decl_stmt|;
name|HAL_MFP_OPT_T
name|halMfpSupport
decl_stmt|;
comment|/* AR9300 HAL porting capabilities */
name|int
name|hal_paprd_enabled
decl_stmt|;
name|int
name|hal_pcie_lcr_offset
decl_stmt|;
name|int
name|hal_pcie_lcr_extsync_en
decl_stmt|;
name|int
name|halNumTxMaps
decl_stmt|;
name|int
name|halTxDescLen
decl_stmt|;
name|int
name|halTxStatusLen
decl_stmt|;
name|int
name|halRxStatusLen
decl_stmt|;
name|int
name|halRxHpFifoDepth
decl_stmt|;
name|int
name|halRxLpFifoDepth
decl_stmt|;
name|uint32_t
name|halRegCap
decl_stmt|;
comment|/* XXX needed? */
name|int
name|halNumMRRetries
decl_stmt|;
name|int
name|hal_ani_poll_interval
decl_stmt|;
name|int
name|hal_channel_switch_time_usec
decl_stmt|;
block|}
name|HAL_CAPABILITIES
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|regDomain
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Definitions for ah_flags in ath_hal_private  */
end_comment

begin_define
define|#
directive|define
name|AH_USE_EEPROM
value|0x1
end_define

begin_define
define|#
directive|define
name|AH_IS_HB63
value|0x2
end_define

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
name|ah_getChipPowerLimits
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
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
name|HAL_STATUS
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
name|uint32_t
name|ah_flags
decl_stmt|;
comment|/* misc flags */
name|uint8_t
name|ah_ispcie
decl_stmt|;
comment|/* PCIE, special treatment */
name|uint8_t
name|ah_devType
decl_stmt|;
comment|/* card type - CB, PCI, PCIe */
name|HAL_OPMODE
name|ah_opmode
decl_stmt|;
comment|/* operating mode from reset */
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|ah_curchan
decl_stmt|;
comment|/* operating channel */
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
name|u_int16_t
name|ah_extraTxPow
decl_stmt|;
comment|/* low rates extra-txpower */
name|uint32_t
name|ah_11nCompat
decl_stmt|;
comment|/* 11n compat controls */
comment|/* 	 * State for regulatory domain handling. 	 */
name|HAL_REG_DOMAIN
name|ah_currentRD
decl_stmt|;
comment|/* EEPROM regulatory domain */
name|HAL_REG_DOMAIN
name|ah_currentRDext
decl_stmt|;
comment|/* EEPROM extended regdomain flags */
name|HAL_DFS_DOMAIN
name|ah_dfsDomain
decl_stmt|;
comment|/* current DFS domain */
name|HAL_CHANNEL_INTERNAL
name|ah_channels
index|[
name|AH_MAXCHAN
index|]
decl_stmt|;
comment|/* private chan state */
name|u_int
name|ah_nchan
decl_stmt|;
comment|/* valid items in ah_channels */
specifier|const
name|struct
name|regDomain
modifier|*
name|ah_rd2GHz
decl_stmt|;
comment|/* reg state for 2G band */
specifier|const
name|struct
name|regDomain
modifier|*
name|ah_rd5GHz
decl_stmt|;
comment|/* reg state for 5G band */
name|uint8_t
name|ah_coverageClass
decl_stmt|;
comment|/* coverage class */
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
comment|/* Only used if ATH_NF_PER_CHAN is defined */
name|HAL_NFCAL_HIST_FULL
name|nf_cal_hist
decl_stmt|;
comment|/* 	 * Channel survey history - current channel only. 	 */
name|HAL_CHANNEL_SURVEY
name|ah_chansurvey
decl_stmt|;
comment|/* channel survey */
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
parameter_list|,
name|_type
parameter_list|)
define|\
value|(_ah)->ah_gpioCfgOutput(_ah, _gpio, _type)
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
value|(_ah)->ah_gpioCfgInput(_ah, _gpio)
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
value|(_ah)->ah_gpioGet(_ah, _gpio)
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
value|(_ah)->ah_gpioSet(_ah, _gpio, _val)
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
value|(_ah)->ah_gpioSetIntr(_ah, _gpio, _ilevel)
end_define

begin_define
define|#
directive|define
name|ath_hal_getpowerlimits
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|)
define|\
value|AH_PRIVATE(_ah)->ah_getChipPowerLimits(_ah, _chan)
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
name|ath_hal_configPCIE
parameter_list|(
name|_ah
parameter_list|,
name|_reset
parameter_list|,
name|_poweroff
parameter_list|)
define|\
value|(_ah)->ah_configPCIE(_ah, _reset, _poweroff)
end_define

begin_define
define|#
directive|define
name|ath_hal_disablePCIE
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(_ah)->ah_disablePCIE(_ah)
end_define

begin_define
define|#
directive|define
name|ath_hal_setInterrupts
parameter_list|(
name|_ah
parameter_list|,
name|_mask
parameter_list|)
define|\
value|(_ah)->ah_setInterrupts(_ah, _mask)
end_define

begin_define
define|#
directive|define
name|ath_hal_isrfkillenabled
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RFSILENT, 1, AH_NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_enable_rfkill
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_RFSILENT, 1, _v, AH_NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasrfkill_int
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RFSILENT, 3, AH_NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_eepromDetach
parameter_list|(
name|_ah
parameter_list|)
value|do {				\ 	if (AH_PRIVATE(_ah)->ah_eepromDetach != AH_NULL)	\ 		AH_PRIVATE(_ah)->ah_eepromDetach(_ah);		\ } while (0)
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

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_IEEE80211_H_
end_ifndef

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
name|IEEE80211_MAX_LEN
value|(2300 + IEEE80211_CRC_LEN + \     (IEEE80211_WEP_IVLEN + IEEE80211_WEP_KIDLEN + IEEE80211_WEP_CRCLEN))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_IEEE80211_H_ */
end_comment

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

begin_define
define|#
directive|define
name|IS_CHAN_5GHZ
parameter_list|(
name|_c
parameter_list|)
value|((_c)->channel> 4900)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_2GHZ
parameter_list|(
name|_c
parameter_list|)
value|(!IS_CHAN_5GHZ(_c))
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
name|OS_REG_RMW
parameter_list|(
name|_a
parameter_list|,
name|_r
parameter_list|,
name|_set
parameter_list|,
name|_clr
parameter_list|)
define|\
value|OS_REG_WRITE(_a, _r, (OS_REG_READ(_a, _r)& ~(_clr)) | (_set))
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

begin_define
define|#
directive|define
name|OS_REG_IS_BIT_SET
parameter_list|(
name|_a
parameter_list|,
name|_r
parameter_list|,
name|_f
parameter_list|)
define|\
value|((OS_REG_READ(_a, _r)& (_f)) != 0)
end_define

begin_define
define|#
directive|define
name|OS_REG_RMW_FIELD_ALT
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
value|OS_REG_WRITE(_a, _r, \ 	    (OS_REG_READ(_a, _r)&~(_f<<_f##_S)) | \ 	    (((_v)<< _f##_S)& (_f<<_f##_S)))
end_define

begin_define
define|#
directive|define
name|OS_REG_READ_FIELD
parameter_list|(
name|_a
parameter_list|,
name|_r
parameter_list|,
name|_f
parameter_list|)
define|\
value|(((OS_REG_READ(_a, _r)& _f)>> _f##_S))
end_define

begin_define
define|#
directive|define
name|OS_REG_READ_FIELD_ALT
parameter_list|(
name|_a
parameter_list|,
name|_r
parameter_list|,
name|_f
parameter_list|)
define|\
value|((OS_REG_READ(_a, _r)>> (_f##_S))&(_f))
end_define

begin_comment
comment|/* Analog register writes may require a delay between each one (eg Merlin?) */
end_comment

begin_define
define|#
directive|define
name|OS_A_REG_RMW_FIELD
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
value|do { OS_REG_WRITE(_a, _r, (OS_REG_READ(_a, _r)&~ (_f)) | \ 	    (((_v)<< _f##_S)& (_f))) ; OS_DELAY(100); } while (0)
end_define

begin_define
define|#
directive|define
name|OS_A_REG_WRITE
parameter_list|(
name|_a
parameter_list|,
name|_r
parameter_list|,
name|_v
parameter_list|)
define|\
value|do { OS_REG_WRITE(_a, _r, _v); OS_DELAY(100); } while (0)
end_define

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

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ath_hal_waitfor
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
parameter_list|,
name|uint32_t
name|timeout
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

begin_comment
comment|/* Global debug flags */
end_comment

begin_comment
comment|/*  * The typecast is purely because some callers will pass in  * AH_NULL directly rather than using a NULL ath_hal pointer.  */
end_comment

begin_define
define|#
directive|define
name|HALDEBUG
parameter_list|(
name|_ah
parameter_list|,
name|__m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {							\ 		if ((__m) == HAL_DEBUG_UNMASKABLE ||		\ 		    ath_hal_debug& (__m) ||			\ 		    ((_ah) != NULL&&				\ 		      ((struct ath_hal *) (_ah))->ah_config.ah_debug& (__m))) {	\ 			DO_HALDEBUG((_ah), (__m), __VA_ARGS__);	\ 		}						\ 	} while(0);
end_define

begin_function_decl
specifier|extern
name|void
name|DO_HALDEBUG
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
comment|/*   * Regulatory domain support.  */
end_comment

begin_comment
comment|/*  * Return the max allowed antenna gain and apply any regulatory  * domain specific changes.  */
end_comment

begin_function_decl
name|u_int
name|ath_hal_getantennareduction
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|,
name|u_int
name|twiceGain
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the test group for the specific channel based on  * the current regulatory setup.  */
end_comment

begin_function_decl
name|u_int
name|ath_hal_getctl
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Map a public channel definition to the corresponding  * internal data structure.  This implicitly specifies  * whether or not the specified channel is ok to use  * based on the current regulatory domain constraints.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AH_DEBUG
end_ifndef

begin_function
specifier|static
name|OS_INLINE
name|HAL_CHANNEL_INTERNAL
modifier|*
name|ath_hal_checkchannel
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|c
parameter_list|)
block|{
name|HAL_CHANNEL_INTERNAL
modifier|*
name|cc
decl_stmt|;
name|HALASSERT
argument_list|(
name|c
operator|->
name|ic_devdata
operator|<
name|AH_PRIVATE
argument_list|(
name|ah
argument_list|)
operator|->
name|ah_nchan
argument_list|)
expr_stmt|;
name|cc
operator|=
operator|&
name|AH_PRIVATE
argument_list|(
name|ah
argument_list|)
operator|->
name|ah_channels
index|[
name|c
operator|->
name|ic_devdata
index|]
expr_stmt|;
name|HALASSERT
argument_list|(
name|c
operator|->
name|ic_freq
operator|==
name|cc
operator|->
name|channel
operator|||
name|IEEE80211_IS_CHAN_GSM
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|cc
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NB: non-inline version that checks state */
end_comment

begin_function_decl
name|HAL_CHANNEL_INTERNAL
modifier|*
name|ath_hal_checkchannel
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_DEBUG */
end_comment

begin_comment
comment|/*  * Return the h/w frequency for a channel.  This may be  * different from ic_freq if this is a GSM device that  * takes 2.4GHz frequencies and down-converts them.  */
end_comment

begin_function
specifier|static
name|OS_INLINE
name|uint16_t
name|ath_hal_gethwchannel
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|c
parameter_list|)
block|{
return|return
name|ath_hal_checkchannel
argument_list|(
name|ah
argument_list|,
name|c
argument_list|)
operator|->
name|channel
return|;
block|}
end_function

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
comment|/* The diagnostic codes used to be internally defined here -adrian */
end_comment

begin_include
include|#
directive|include
file|"ah_diagcodes.h"
end_include

begin_comment
comment|/*  * The AR5416 and later HALs have MAC and baseband hang checking.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|hang_reg_offset
decl_stmt|;
name|uint32_t
name|hang_val
decl_stmt|;
name|uint32_t
name|hang_mask
decl_stmt|;
name|uint32_t
name|hang_offset
decl_stmt|;
block|}
name|hal_hw_hang_check_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|dma_dbg_3
decl_stmt|;
name|uint32_t
name|dma_dbg_4
decl_stmt|;
name|uint32_t
name|dma_dbg_5
decl_stmt|;
name|uint32_t
name|dma_dbg_6
decl_stmt|;
block|}
name|mac_dbg_regs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dcu_chain_state
init|=
literal|0x1
block|,
name|dcu_complete_state
init|=
literal|0x2
block|,
name|qcu_state
init|=
literal|0x4
block|,
name|qcu_fsp_ok
init|=
literal|0x8
block|,
name|qcu_fsp_state
init|=
literal|0x10
block|,
name|qcu_stitch_state
init|=
literal|0x20
block|,
name|qcu_fetch_state
init|=
literal|0x40
block|,
name|qcu_complete_state
init|=
literal|0x80
block|}
name|hal_mac_hangs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|states
decl_stmt|;
name|uint8_t
name|dcu_chain_state
decl_stmt|;
name|uint8_t
name|dcu_complete_state
decl_stmt|;
name|uint8_t
name|qcu_state
decl_stmt|;
name|uint8_t
name|qcu_fsp_ok
decl_stmt|;
name|uint8_t
name|qcu_fsp_state
decl_stmt|;
name|uint8_t
name|qcu_stitch_state
decl_stmt|;
name|uint8_t
name|qcu_fetch_state
decl_stmt|;
name|uint8_t
name|qcu_complete_state
decl_stmt|;
block|}
name|hal_mac_hang_check_t
typedef|;
end_typedef

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
comment|/* Merge these with above */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|hal_hw_hangs
block|{
name|HAL_DFS_BB_HANG_WAR
init|=
literal|0x1
block|,
name|HAL_RIFS_BB_HANG_WAR
init|=
literal|0x2
block|,
name|HAL_RX_STUCK_LOW_BB_HANG_WAR
init|=
literal|0x4
block|,
name|HAL_MAC_HANG_WAR
init|=
literal|0x8
block|,
name|HAL_PHYRESTART_CLR_WAR
init|=
literal|0x10
block|,
name|HAL_MAC_HANG_DETECTED
init|=
literal|0x40000000
block|,
name|HAL_BB_HANG_DETECTED
init|=
literal|0x80000000
block|}
name|hal_hw_hangs_t
typedef|;
end_typedef

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
name|int16_t
name|ath_hal_getChanNoise
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
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
name|CCK_SIFS_TIME
value|10
end_define

begin_define
define|#
directive|define
name|CCK_PREAMBLE_BITS
value|144
end_define

begin_define
define|#
directive|define
name|CCK_PLCP_BITS
value|48
end_define

begin_define
define|#
directive|define
name|OFDM_SIFS_TIME
value|16
end_define

begin_define
define|#
directive|define
name|OFDM_PREAMBLE_TIME
value|20
end_define

begin_define
define|#
directive|define
name|OFDM_PLCP_BITS
value|22
end_define

begin_define
define|#
directive|define
name|OFDM_SYMBOL_TIME
value|4
end_define

begin_define
define|#
directive|define
name|OFDM_HALF_SIFS_TIME
value|32
end_define

begin_define
define|#
directive|define
name|OFDM_HALF_PREAMBLE_TIME
value|40
end_define

begin_define
define|#
directive|define
name|OFDM_HALF_PLCP_BITS
value|22
end_define

begin_define
define|#
directive|define
name|OFDM_HALF_SYMBOL_TIME
value|8
end_define

begin_define
define|#
directive|define
name|OFDM_QUARTER_SIFS_TIME
value|64
end_define

begin_define
define|#
directive|define
name|OFDM_QUARTER_PREAMBLE_TIME
value|80
end_define

begin_define
define|#
directive|define
name|OFDM_QUARTER_PLCP_BITS
value|22
end_define

begin_define
define|#
directive|define
name|OFDM_QUARTER_SYMBOL_TIME
value|16
end_define

begin_define
define|#
directive|define
name|TURBO_SIFS_TIME
value|8
end_define

begin_define
define|#
directive|define
name|TURBO_PREAMBLE_TIME
value|14
end_define

begin_define
define|#
directive|define
name|TURBO_PLCP_BITS
value|22
end_define

begin_define
define|#
directive|define
name|TURBO_SYMBOL_TIME
value|4
end_define

begin_define
define|#
directive|define
name|WLAN_CTRL_FRAME_SIZE
value|(2+2+6+4)
end_define

begin_comment
comment|/* ACK+FCS */
end_comment

begin_comment
comment|/* Generic EEPROM board value functions */
end_comment

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ath_ee_getLowerUpperIndex
parameter_list|(
name|uint8_t
name|target
parameter_list|,
name|uint8_t
modifier|*
name|pList
parameter_list|,
name|uint16_t
name|listSize
parameter_list|,
name|uint16_t
modifier|*
name|indexL
parameter_list|,
name|uint16_t
modifier|*
name|indexR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ath_ee_FillVpdTable
parameter_list|(
name|uint8_t
name|pwrMin
parameter_list|,
name|uint8_t
name|pwrMax
parameter_list|,
name|uint8_t
modifier|*
name|pPwrList
parameter_list|,
name|uint8_t
modifier|*
name|pVpdList
parameter_list|,
name|uint16_t
name|numIntercepts
parameter_list|,
name|uint8_t
modifier|*
name|pRetVpdList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int16_t
name|ath_ee_interpolate
parameter_list|(
name|uint16_t
name|target
parameter_list|,
name|uint16_t
name|srcLeft
parameter_list|,
name|uint16_t
name|srcRight
parameter_list|,
name|int16_t
name|targetLeft
parameter_list|,
name|int16_t
name|targetRight
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Whether 5ghz fast clock is needed */
end_comment

begin_comment
comment|/*  * The chipset (Merlin, AR9300/later) should set the capability flag below;  * this flag simply says that the hardware can do it, not that the EEPROM  * says it can.  *  * Merlin 2.0/2.1 chips with an EEPROM version> 16 do 5ghz fast clock  *   if the relevant eeprom flag is set.  * Merlin 2.0/2.1 chips with an EEPROM version<= 16 do 5ghz fast clock  *   by default.  */
end_comment

begin_define
define|#
directive|define
name|IS_5GHZ_FAST_CLOCK_EN
parameter_list|(
name|_ah
parameter_list|,
name|_c
parameter_list|)
define|\
value|(IEEE80211_IS_CHAN_5GHZ(_c)&& \ 	 AH_PRIVATE((_ah))->ah_caps.halSupportsFastClock5GHz&& \ 	ath_hal_eepromGetFlag((_ah), AR_EEP_FSTCLK_5G))
end_define

begin_comment
comment|/*  * Fetch the maximum regulatory domain power for the given channel  * in 1/2dBm steps.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|ath_hal_get_twice_max_regpower
parameter_list|(
name|struct
name|ath_hal_private
modifier|*
name|ahp
parameter_list|,
specifier|const
name|HAL_CHANNEL_INTERNAL
modifier|*
name|ichan
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
block|{
name|struct
name|ath_hal
modifier|*
name|ah
init|=
operator|&
name|ahp
operator|->
name|h
decl_stmt|;
if|if
condition|(
operator|!
name|chan
condition|)
block|{
name|ath_hal_printf
argument_list|(
name|ah
argument_list|,
literal|"%s: called with chan=NULL!\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
name|chan
operator|->
name|ic_maxpower
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Get the maximum antenna gain allowed, in 1/2dBm steps.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|ath_hal_getantennaallowed
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
block|{
if|if
condition|(
operator|!
name|chan
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|chan
operator|->
name|ic_maxantgain
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Map the given 2GHz channel to an IEEE number.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ath_hal_mhz2ieee_2ghz
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Clear the channel survey data.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ath_hal_survey_clear
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a sample to the channel survey data.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ath_hal_survey_add_sample
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_SURVEY_SAMPLE
modifier|*
name|hs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Chip registration - for modules.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ath_hal_add_chip
parameter_list|(
name|struct
name|ath_hal_chip
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_hal_remove_chip
parameter_list|(
name|struct
name|ath_hal_chip
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_hal_add_rf
parameter_list|(
name|struct
name|ath_hal_rf
modifier|*
name|arf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_hal_remove_rf
parameter_list|(
name|struct
name|ath_hal_rf
modifier|*
name|arf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_INTERAL_H_ */
end_comment

end_unit

