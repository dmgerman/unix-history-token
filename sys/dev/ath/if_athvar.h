begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Defintions for the Atheros Wireless LAN controller driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_ATHVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_ATHVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/ath/ah.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_athioctl.h>
end_include

begin_define
define|#
directive|define
name|ATH_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ATH_RXBUF
value|40
end_define

begin_comment
comment|/* number of RX buffers */
end_comment

begin_define
define|#
directive|define
name|ATH_TXBUF
value|60
end_define

begin_comment
comment|/* number of TX buffers */
end_comment

begin_define
define|#
directive|define
name|ATH_TXDESC
value|8
end_define

begin_comment
comment|/* number of descriptors per buffer */
end_comment

begin_comment
comment|/* driver-specific node */
end_comment

begin_struct
struct|struct
name|ath_node
block|{
name|struct
name|ieee80211_node
name|st_node
decl_stmt|;
comment|/* base class */
name|u_int
name|an_tx_ok
decl_stmt|;
comment|/* tx ok pkt */
name|u_int
name|an_tx_err
decl_stmt|;
comment|/* tx !ok pkt */
name|u_int
name|an_tx_retr
decl_stmt|;
comment|/* tx retry count */
name|int
name|an_tx_upper
decl_stmt|;
comment|/* tx upper rate req cnt */
name|u_int
name|an_tx_antenna
decl_stmt|;
comment|/* antenna for last good frame */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_buf
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ath_buf
argument_list|)
name|bf_list
expr_stmt|;
name|int
name|bf_nseg
decl_stmt|;
name|bus_dmamap_t
name|bf_dmamap
decl_stmt|;
comment|/* DMA map of the buffer */
name|struct
name|ath_desc
modifier|*
name|bf_desc
decl_stmt|;
comment|/* virtual addr of desc */
name|bus_addr_t
name|bf_daddr
decl_stmt|;
comment|/* physical addr of desc */
name|struct
name|mbuf
modifier|*
name|bf_m
decl_stmt|;
comment|/* mbuf for buf */
name|struct
name|ieee80211_node
modifier|*
name|bf_node
decl_stmt|;
comment|/* pointer to the node */
name|bus_size_t
name|bf_mapsize
decl_stmt|;
define|#
directive|define
name|ATH_MAX_SCATTER
value|64
name|bus_dma_segment_t
name|bf_segs
index|[
name|ATH_MAX_SCATTER
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_softc
block|{
name|struct
name|ieee80211com
name|sc_ic
decl_stmt|;
comment|/* IEEE 802.11 common */
name|int
function_decl|(
modifier|*
name|sc_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|device_t
name|sc_dev
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
comment|/* bus space handle */
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* bus DMA tag */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* master lock (recursive) */
name|struct
name|ath_hal
modifier|*
name|sc_ah
decl_stmt|;
comment|/* Atheros HAL */
name|unsigned
name|int
name|sc_invalid
range|:
literal|1
decl_stmt|,
comment|/* disable hardware accesses */
name|sc_have11g
range|:
literal|1
decl_stmt|,
comment|/* have 11g support */
name|sc_doani
range|:
literal|1
decl_stmt|,
comment|/* dynamic noise immunity */
name|sc_probing
range|:
literal|1
decl_stmt|;
comment|/* probing AP on beacon miss */
comment|/* rate tables */
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|sc_rates
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|sc_currates
decl_stmt|;
comment|/* current rate table */
name|enum
name|ieee80211_phymode
name|sc_curmode
decl_stmt|;
comment|/* current phy mode */
name|u_int8_t
name|sc_rixmap
index|[
literal|256
index|]
decl_stmt|;
comment|/* IEEE to h/w rate table ix */
name|u_int8_t
name|sc_hwmap
index|[
literal|32
index|]
decl_stmt|;
comment|/* h/w rate ix to IEEE table */
name|HAL_INT
name|sc_imask
decl_stmt|;
comment|/* interrupt mask copy */
name|struct
name|ath_desc
modifier|*
name|sc_desc
decl_stmt|;
comment|/* TX/RX descriptors */
name|bus_dma_segment_t
name|sc_dseg
decl_stmt|;
name|bus_dmamap_t
name|sc_ddmamap
decl_stmt|;
comment|/* DMA map for descriptors */
name|bus_addr_t
name|sc_desc_paddr
decl_stmt|;
comment|/* physical addr of sc_desc */
name|bus_addr_t
name|sc_desc_len
decl_stmt|;
comment|/* size of sc_desc */
name|struct
name|task
name|sc_fataltask
decl_stmt|;
comment|/* fatal int processing */
name|struct
name|task
name|sc_rxorntask
decl_stmt|;
comment|/* rxorn int processing */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ath_buf
argument_list|)
name|sc_rxbuf
expr_stmt|;
comment|/* receive buffer */
name|u_int32_t
modifier|*
name|sc_rxlink
decl_stmt|;
comment|/* link ptr in last RX desc */
name|struct
name|task
name|sc_rxtask
decl_stmt|;
comment|/* rx int processing */
name|u_int
name|sc_txhalq
decl_stmt|;
comment|/* HAL q for outgoing frames */
name|u_int32_t
modifier|*
name|sc_txlink
decl_stmt|;
comment|/* link ptr in last TX desc */
name|int
name|sc_tx_timer
decl_stmt|;
comment|/* transmit timeout */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ath_buf
argument_list|)
name|sc_txbuf
expr_stmt|;
comment|/* transmit buffer */
name|struct
name|mtx
name|sc_txbuflock
decl_stmt|;
comment|/* txbuf lock */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ath_buf
argument_list|)
name|sc_txq
expr_stmt|;
comment|/* transmitting queue */
name|struct
name|mtx
name|sc_txqlock
decl_stmt|;
comment|/* lock on txq and txlink */
name|struct
name|task
name|sc_txtask
decl_stmt|;
comment|/* tx int processing */
name|u_int
name|sc_bhalq
decl_stmt|;
comment|/* HAL q for outgoing beacons */
name|struct
name|ath_buf
modifier|*
name|sc_bcbuf
decl_stmt|;
comment|/* beacon buffer */
name|struct
name|ath_buf
modifier|*
name|sc_bufptr
decl_stmt|;
comment|/* allocated buffer ptr */
name|struct
name|task
name|sc_swbatask
decl_stmt|;
comment|/* swba int processing */
name|struct
name|task
name|sc_bmisstask
decl_stmt|;
comment|/* bmiss int processing */
name|struct
name|callout
name|sc_cal_ch
decl_stmt|;
comment|/* callout handle for cals */
name|struct
name|callout
name|sc_scan_ch
decl_stmt|;
comment|/* callout handle for scan */
name|struct
name|ath_stats
name|sc_stats
decl_stmt|;
comment|/* interface statistics */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ath_attach
parameter_list|(
name|u_int16_t
parameter_list|,
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ath_detach
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_resume
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_suspend
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_shutdown
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * HAL definitions to comply with local coding convention.  */
end_comment

begin_define
define|#
directive|define
name|ath_hal_reset
parameter_list|(
name|_ah
parameter_list|,
name|_opmode
parameter_list|,
name|_chan
parameter_list|,
name|_outdoor
parameter_list|,
name|_pstatus
parameter_list|)
define|\
value|((*(_ah)->ah_reset)((_ah), (_opmode), (_chan), (_outdoor), (_pstatus)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getratetable
parameter_list|(
name|_ah
parameter_list|,
name|_mode
parameter_list|)
define|\
value|((*(_ah)->ah_getRateTable)((_ah), (_mode)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getregdomain
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getRegDomain)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getcountrycode
parameter_list|(
name|_ah
parameter_list|)
value|(_ah)->ah_countryCode
end_define

begin_define
define|#
directive|define
name|ath_hal_getmac
parameter_list|(
name|_ah
parameter_list|,
name|_mac
parameter_list|)
define|\
value|((*(_ah)->ah_getMacAddress)((_ah), (_mac)))
end_define

begin_define
define|#
directive|define
name|ath_hal_detach
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_detach)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_intrset
parameter_list|(
name|_ah
parameter_list|,
name|_mask
parameter_list|)
define|\
value|((*(_ah)->ah_setInterrupts)((_ah), (_mask)))
end_define

begin_define
define|#
directive|define
name|ath_hal_intrget
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getInterrupts)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_intrpend
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_isInterruptPending)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getisr
parameter_list|(
name|_ah
parameter_list|,
name|_pmask
parameter_list|)
define|\
value|((*(_ah)->ah_getPendingInterrupts)((_ah), (_pmask)))
end_define

begin_define
define|#
directive|define
name|ath_hal_updatetxtriglevel
parameter_list|(
name|_ah
parameter_list|,
name|_inc
parameter_list|)
define|\
value|((*(_ah)->ah_updateTxTrigLevel)((_ah), (_inc)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setpower
parameter_list|(
name|_ah
parameter_list|,
name|_mode
parameter_list|,
name|_sleepduration
parameter_list|)
define|\
value|((*(_ah)->ah_setPowerMode)((_ah), (_mode), AH_TRUE, (_sleepduration)))
end_define

begin_define
define|#
directive|define
name|ath_hal_keyreset
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|)
define|\
value|((*(_ah)->ah_resetKeyCacheEntry)((_ah), (_ix)))
end_define

begin_define
define|#
directive|define
name|ath_hal_keyset
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|,
name|_pk
parameter_list|)
define|\
value|((*(_ah)->ah_setKeyCacheEntry)((_ah), (_ix), (_pk), NULL, AH_FALSE))
end_define

begin_define
define|#
directive|define
name|ath_hal_keyisvalid
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|)
define|\
value|(((*(_ah)->ah_isKeyCacheEntryValid)((_ah), (_ix))))
end_define

begin_define
define|#
directive|define
name|ath_hal_keysetmac
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|,
name|_mac
parameter_list|)
define|\
value|((*(_ah)->ah_setKeyCacheEntryMac)((_ah), (_ix), (_mac)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getrxfilter
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getRxFilter)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setrxfilter
parameter_list|(
name|_ah
parameter_list|,
name|_filter
parameter_list|)
define|\
value|((*(_ah)->ah_setRxFilter)((_ah), (_filter)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setmcastfilter
parameter_list|(
name|_ah
parameter_list|,
name|_mfilt0
parameter_list|,
name|_mfilt1
parameter_list|)
define|\
value|((*(_ah)->ah_setMulticastFilter)((_ah), (_mfilt0), (_mfilt1)))
end_define

begin_define
define|#
directive|define
name|ath_hal_waitforbeacon
parameter_list|(
name|_ah
parameter_list|,
name|_bf
parameter_list|)
define|\
value|((*(_ah)->ah_waitForBeaconDone)((_ah), (_bf)->bf_daddr))
end_define

begin_define
define|#
directive|define
name|ath_hal_putrxbuf
parameter_list|(
name|_ah
parameter_list|,
name|_bufaddr
parameter_list|)
define|\
value|((*(_ah)->ah_setRxDP)((_ah), (_bufaddr)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettsf32
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getTsf32)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettsf64
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getTsf64)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_resettsf
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_resetTsf)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_rxena
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_enableReceive)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_puttxbuf
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|,
name|_bufaddr
parameter_list|)
define|\
value|((*(_ah)->ah_setTxDP)((_ah), (_q), (_bufaddr)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxbuf
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_getTxDP)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getrxbuf
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getRxDP)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_txstart
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_startTxDma)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setchannel
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|)
define|\
value|((*(_ah)->ah_setChannel)((_ah), (_chan)))
end_define

begin_define
define|#
directive|define
name|ath_hal_calibrate
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|)
define|\
value|((*(_ah)->ah_perCalibration)((_ah), (_chan)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setledstate
parameter_list|(
name|_ah
parameter_list|,
name|_state
parameter_list|)
define|\
value|((*(_ah)->ah_setLedState)((_ah), (_state)))
end_define

begin_define
define|#
directive|define
name|ath_hal_beaconinit
parameter_list|(
name|_ah
parameter_list|,
name|_opmode
parameter_list|,
name|_nextb
parameter_list|,
name|_bperiod
parameter_list|)
define|\
value|((*(_ah)->ah_beaconInit)((_ah), (_opmode), (_nextb), (_bperiod)))
end_define

begin_define
define|#
directive|define
name|ath_hal_beaconreset
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_resetStationBeaconTimers)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_beacontimers
parameter_list|(
name|_ah
parameter_list|,
name|_bs
parameter_list|,
name|_tsf
parameter_list|,
name|_dc
parameter_list|,
name|_cc
parameter_list|)
define|\
value|((*(_ah)->ah_setStationBeaconTimers)((_ah), (_bs), (_tsf), \ 		(_dc), (_cc)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setassocid
parameter_list|(
name|_ah
parameter_list|,
name|_bss
parameter_list|,
name|_associd
parameter_list|)
define|\
value|((*(_ah)->ah_writeAssocid)((_ah), (_bss), (_associd), 0))
end_define

begin_define
define|#
directive|define
name|ath_hal_setopmode
parameter_list|(
name|_ah
parameter_list|,
name|_opmode
parameter_list|)
define|\
value|((*(_ah)->ah_setPCUConfig)((_ah), (_opmode)))
end_define

begin_define
define|#
directive|define
name|ath_hal_stoptxdma
parameter_list|(
name|_ah
parameter_list|,
name|_qnum
parameter_list|)
define|\
value|((*(_ah)->ah_stopTxDma)((_ah), (_qnum)))
end_define

begin_define
define|#
directive|define
name|ath_hal_stoppcurecv
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_stopPcuReceive)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_startpcurecv
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_startPcuReceive)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_stopdmarecv
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_stopDmaReceive)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_dumpstate
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_dumpState)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_dumpeeprom
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_dumpEeprom)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_dumprfgain
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_dumpRfGain)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_dumpani
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_dumpAni)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setuptxqueue
parameter_list|(
name|_ah
parameter_list|,
name|_type
parameter_list|,
name|_irq
parameter_list|)
define|\
value|((*(_ah)->ah_setupTxQueue)((_ah), (_type), (_irq)))
end_define

begin_define
define|#
directive|define
name|ath_hal_resettxqueue
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_resetTxQueue)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_releasetxqueue
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_releaseTxQueue)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_hasveol
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_hasVEOL)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getrfgain
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getRfGain)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_rxmonitor
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_rxMonitor)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setupbeacondesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_opmode
parameter_list|,
name|_flen
parameter_list|,
name|_hlen
parameter_list|, \
name|_rate
parameter_list|,
name|_antmode
parameter_list|)
define|\
value|((*(_ah)->ah_setupBeaconDesc)((_ah), (_ds), (_opmode), \ 		(_flen), (_hlen), (_rate), (_antmode)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setuprxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_size
parameter_list|,
name|_intreq
parameter_list|)
define|\
value|((*(_ah)->ah_setupRxDesc)((_ah), (_ds), (_size), (_intreq)))
end_define

begin_define
define|#
directive|define
name|ath_hal_rxprocdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|)
define|\
value|((*(_ah)->ah_procRxDesc)((_ah), (_ds)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setuptxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_plen
parameter_list|,
name|_hlen
parameter_list|,
name|_atype
parameter_list|,
name|_txpow
parameter_list|, \
name|_txr0
parameter_list|,
name|_txtr0
parameter_list|,
name|_keyix
parameter_list|,
name|_ant
parameter_list|,
name|_flags
parameter_list|, \
name|_rtsrate
parameter_list|,
name|_rtsdura
parameter_list|)
define|\
value|((*(_ah)->ah_setupTxDesc)((_ah), (_ds), (_plen), (_hlen), (_atype), \ 		(_txpow), (_txr0), (_txtr0), (_keyix), (_ant), \ 		(_flags), (_rtsrate), (_rtsdura)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setupxtxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_short
parameter_list|, \
name|_txr1
parameter_list|,
name|_txtr1
parameter_list|,
name|_txr2
parameter_list|,
name|_txtr2
parameter_list|,
name|_txr3
parameter_list|,
name|_txtr3
parameter_list|)
define|\
value|((*(_ah)->ah_setupXTxDesc)((_ah), (_ds), (_short), \ 		(_txr1), (_txtr1), (_txr2), (_txtr2), (_txr3), (_txtr3)))
end_define

begin_define
define|#
directive|define
name|ath_hal_filltxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_l
parameter_list|,
name|_first
parameter_list|,
name|_last
parameter_list|)
define|\
value|((*(_ah)->ah_fillTxDesc)((_ah), (_ds), (_l), (_first), (_last)))
end_define

begin_define
define|#
directive|define
name|ath_hal_txprocdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|)
define|\
value|((*(_ah)->ah_procTxDesc)((_ah), (_ds)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_ATHVAR_H */
end_comment

end_unit

