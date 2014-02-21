begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Ioctl-related defintions for the Atheros Wireless LAN controller driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_ATHIOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_ATHIOCTL_H
end_define

begin_struct
struct|struct
name|ath_tx_aggr_stats
block|{
name|u_int32_t
name|aggr_pkts
index|[
literal|64
index|]
decl_stmt|;
name|u_int32_t
name|aggr_single_pkt
decl_stmt|;
name|u_int32_t
name|aggr_nonbaw_pkt
decl_stmt|;
name|u_int32_t
name|aggr_aggr_pkt
decl_stmt|;
name|u_int32_t
name|aggr_baw_closed_single_pkt
decl_stmt|;
name|u_int32_t
name|aggr_low_hwq_single_pkt
decl_stmt|;
name|u_int32_t
name|aggr_sched_nopkt
decl_stmt|;
name|u_int32_t
name|aggr_rts_aggr_limited
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_intr_stats
block|{
name|u_int32_t
name|sync_intr
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_stats
block|{
name|u_int32_t
name|ast_watchdog
decl_stmt|;
comment|/* device reset by watchdog */
name|u_int32_t
name|ast_hardware
decl_stmt|;
comment|/* fatal hardware error interrupts */
name|u_int32_t
name|ast_bmiss
decl_stmt|;
comment|/* beacon miss interrupts */
name|u_int32_t
name|ast_bmiss_phantom
decl_stmt|;
comment|/* beacon miss interrupts */
name|u_int32_t
name|ast_bstuck
decl_stmt|;
comment|/* beacon stuck interrupts */
name|u_int32_t
name|ast_rxorn
decl_stmt|;
comment|/* rx overrun interrupts */
name|u_int32_t
name|ast_rxeol
decl_stmt|;
comment|/* rx eol interrupts */
name|u_int32_t
name|ast_txurn
decl_stmt|;
comment|/* tx underrun interrupts */
name|u_int32_t
name|ast_mib
decl_stmt|;
comment|/* mib interrupts */
name|u_int32_t
name|ast_intrcoal
decl_stmt|;
comment|/* interrupts coalesced */
name|u_int32_t
name|ast_tx_packets
decl_stmt|;
comment|/* packet sent on the interface */
name|u_int32_t
name|ast_tx_mgmt
decl_stmt|;
comment|/* management frames transmitted */
name|u_int32_t
name|ast_tx_discard
decl_stmt|;
comment|/* frames discarded prior to assoc */
name|u_int32_t
name|ast_tx_qstop
decl_stmt|;
comment|/* output stopped 'cuz no buffer */
name|u_int32_t
name|ast_tx_encap
decl_stmt|;
comment|/* tx encapsulation failed */
name|u_int32_t
name|ast_tx_nonode
decl_stmt|;
comment|/* tx failed 'cuz no node */
name|u_int32_t
name|ast_tx_nombuf
decl_stmt|;
comment|/* tx failed 'cuz no mbuf */
name|u_int32_t
name|ast_tx_nomcl
decl_stmt|;
comment|/* tx failed 'cuz no cluster */
name|u_int32_t
name|ast_tx_linear
decl_stmt|;
comment|/* tx linearized to cluster */
name|u_int32_t
name|ast_tx_nodata
decl_stmt|;
comment|/* tx discarded empty frame */
name|u_int32_t
name|ast_tx_busdma
decl_stmt|;
comment|/* tx failed for dma resrcs */
name|u_int32_t
name|ast_tx_xretries
decl_stmt|;
comment|/* tx failed 'cuz too many retries */
name|u_int32_t
name|ast_tx_fifoerr
decl_stmt|;
comment|/* tx failed 'cuz FIFO underrun */
name|u_int32_t
name|ast_tx_filtered
decl_stmt|;
comment|/* tx failed 'cuz xmit filtered */
name|u_int32_t
name|ast_tx_shortretry
decl_stmt|;
comment|/* tx on-chip retries (short) */
name|u_int32_t
name|ast_tx_longretry
decl_stmt|;
comment|/* tx on-chip retries (long) */
name|u_int32_t
name|ast_tx_badrate
decl_stmt|;
comment|/* tx failed 'cuz bogus xmit rate */
name|u_int32_t
name|ast_tx_noack
decl_stmt|;
comment|/* tx frames with no ack marked */
name|u_int32_t
name|ast_tx_rts
decl_stmt|;
comment|/* tx frames with rts enabled */
name|u_int32_t
name|ast_tx_cts
decl_stmt|;
comment|/* tx frames with cts enabled */
name|u_int32_t
name|ast_tx_shortpre
decl_stmt|;
comment|/* tx frames with short preamble */
name|u_int32_t
name|ast_tx_altrate
decl_stmt|;
comment|/* tx frames with alternate rate */
name|u_int32_t
name|ast_tx_protect
decl_stmt|;
comment|/* tx frames with protection */
name|u_int32_t
name|ast_tx_ctsburst
decl_stmt|;
comment|/* tx frames with cts and bursting */
name|u_int32_t
name|ast_tx_ctsext
decl_stmt|;
comment|/* tx frames with cts extension */
name|u_int32_t
name|ast_rx_nombuf
decl_stmt|;
comment|/* rx setup failed 'cuz no mbuf */
name|u_int32_t
name|ast_rx_busdma
decl_stmt|;
comment|/* rx setup failed for dma resrcs */
name|u_int32_t
name|ast_rx_orn
decl_stmt|;
comment|/* rx failed 'cuz of desc overrun */
name|u_int32_t
name|ast_rx_crcerr
decl_stmt|;
comment|/* rx failed 'cuz of bad CRC */
name|u_int32_t
name|ast_rx_fifoerr
decl_stmt|;
comment|/* rx failed 'cuz of FIFO overrun */
name|u_int32_t
name|ast_rx_badcrypt
decl_stmt|;
comment|/* rx failed 'cuz decryption */
name|u_int32_t
name|ast_rx_badmic
decl_stmt|;
comment|/* rx failed 'cuz MIC failure */
name|u_int32_t
name|ast_rx_phyerr
decl_stmt|;
comment|/* rx failed 'cuz of PHY err */
name|u_int32_t
name|ast_rx_phy
index|[
literal|64
index|]
decl_stmt|;
comment|/* rx PHY error per-code counts */
name|u_int32_t
name|ast_rx_tooshort
decl_stmt|;
comment|/* rx discarded 'cuz frame too short */
name|u_int32_t
name|ast_rx_toobig
decl_stmt|;
comment|/* rx discarded 'cuz frame too large */
name|u_int32_t
name|ast_rx_packets
decl_stmt|;
comment|/* packet recv on the interface */
name|u_int32_t
name|ast_rx_mgt
decl_stmt|;
comment|/* management frames received */
name|u_int32_t
name|ast_rx_ctl
decl_stmt|;
comment|/* rx discarded 'cuz ctl frame */
name|int8_t
name|ast_tx_rssi
decl_stmt|;
comment|/* tx rssi of last ack */
name|int8_t
name|ast_rx_rssi
decl_stmt|;
comment|/* rx rssi from histogram */
name|u_int8_t
name|ast_tx_rate
decl_stmt|;
comment|/* IEEE rate of last unicast tx */
name|u_int32_t
name|ast_be_xmit
decl_stmt|;
comment|/* beacons transmitted */
name|u_int32_t
name|ast_be_nombuf
decl_stmt|;
comment|/* beacon setup failed 'cuz no mbuf */
name|u_int32_t
name|ast_per_cal
decl_stmt|;
comment|/* periodic calibration calls */
name|u_int32_t
name|ast_per_calfail
decl_stmt|;
comment|/* periodic calibration failed */
name|u_int32_t
name|ast_per_rfgain
decl_stmt|;
comment|/* periodic calibration rfgain reset */
name|u_int32_t
name|ast_rate_calls
decl_stmt|;
comment|/* rate control checks */
name|u_int32_t
name|ast_rate_raise
decl_stmt|;
comment|/* rate control raised xmit rate */
name|u_int32_t
name|ast_rate_drop
decl_stmt|;
comment|/* rate control dropped xmit rate */
name|u_int32_t
name|ast_ant_defswitch
decl_stmt|;
comment|/* rx/default antenna switches */
name|u_int32_t
name|ast_ant_txswitch
decl_stmt|;
comment|/* tx antenna switches */
name|u_int32_t
name|ast_ant_rx
index|[
literal|8
index|]
decl_stmt|;
comment|/* rx frames with antenna */
name|u_int32_t
name|ast_ant_tx
index|[
literal|8
index|]
decl_stmt|;
comment|/* tx frames with antenna */
name|u_int32_t
name|ast_cabq_xmit
decl_stmt|;
comment|/* cabq frames transmitted */
name|u_int32_t
name|ast_cabq_busy
decl_stmt|;
comment|/* cabq found busy */
name|u_int32_t
name|ast_tx_raw
decl_stmt|;
comment|/* tx frames through raw api */
name|u_int32_t
name|ast_ff_txok
decl_stmt|;
comment|/* fast frames tx'd successfully */
name|u_int32_t
name|ast_ff_txerr
decl_stmt|;
comment|/* fast frames tx'd w/ error */
name|u_int32_t
name|ast_ff_rx
decl_stmt|;
comment|/* fast frames rx'd */
name|u_int32_t
name|ast_ff_flush
decl_stmt|;
comment|/* fast frames flushed from staging q */
name|u_int32_t
name|ast_tx_qfull
decl_stmt|;
comment|/* tx dropped 'cuz of queue limit */
name|int8_t
name|ast_rx_noise
decl_stmt|;
comment|/* rx noise floor */
name|u_int32_t
name|ast_tx_nobuf
decl_stmt|;
comment|/* tx dropped 'cuz no ath buffer */
name|u_int32_t
name|ast_tdma_update
decl_stmt|;
comment|/* TDMA slot timing updates */
name|u_int32_t
name|ast_tdma_timers
decl_stmt|;
comment|/* TDMA slot update set beacon timers */
name|u_int32_t
name|ast_tdma_tsf
decl_stmt|;
comment|/* TDMA slot update set TSF */
name|u_int16_t
name|ast_tdma_tsfadjp
decl_stmt|;
comment|/* TDMA slot adjust+ (usec, smoothed)*/
name|u_int16_t
name|ast_tdma_tsfadjm
decl_stmt|;
comment|/* TDMA slot adjust- (usec, smoothed)*/
name|u_int32_t
name|ast_tdma_ack
decl_stmt|;
comment|/* TDMA tx failed 'cuz ACK required */
name|u_int32_t
name|ast_tx_raw_fail
decl_stmt|;
comment|/* raw tx failed 'cuz h/w down */
name|u_int32_t
name|ast_tx_nofrag
decl_stmt|;
comment|/* tx dropped 'cuz no ath frag buffer */
name|u_int32_t
name|ast_be_missed
decl_stmt|;
comment|/* missed beacons */
name|u_int32_t
name|ast_ani_cal
decl_stmt|;
comment|/* ANI calibrations performed */
name|u_int32_t
name|ast_rx_agg
decl_stmt|;
comment|/* number of aggregate frames RX'ed */
name|u_int32_t
name|ast_rx_halfgi
decl_stmt|;
comment|/* RX half-GI */
name|u_int32_t
name|ast_rx_2040
decl_stmt|;
comment|/* RX 40mhz frame */
name|u_int32_t
name|ast_rx_pre_crc_err
decl_stmt|;
comment|/* RX pre-delimiter CRC error */
name|u_int32_t
name|ast_rx_post_crc_err
decl_stmt|;
comment|/* RX post-delimiter CRC error */
name|u_int32_t
name|ast_rx_decrypt_busy_err
decl_stmt|;
comment|/* RX decrypt engine busy error */
name|u_int32_t
name|ast_rx_hi_rx_chain
decl_stmt|;
name|u_int32_t
name|ast_tx_htprotect
decl_stmt|;
comment|/* HT tx frames with protection */
name|u_int32_t
name|ast_rx_hitqueueend
decl_stmt|;
comment|/* RX hit descr queue end */
name|u_int32_t
name|ast_tx_timeout
decl_stmt|;
comment|/* Global TX timeout */
name|u_int32_t
name|ast_tx_cst
decl_stmt|;
comment|/* Carrier sense timeout */
name|u_int32_t
name|ast_tx_xtxop
decl_stmt|;
comment|/* tx exceeded TXOP */
name|u_int32_t
name|ast_tx_timerexpired
decl_stmt|;
comment|/* tx exceeded TX_TIMER */
name|u_int32_t
name|ast_tx_desccfgerr
decl_stmt|;
comment|/* tx desc cfg error */
name|u_int32_t
name|ast_tx_swretries
decl_stmt|;
comment|/* software TX retries */
name|u_int32_t
name|ast_tx_swretrymax
decl_stmt|;
comment|/* software TX retry max limit reach */
name|u_int32_t
name|ast_tx_data_underrun
decl_stmt|;
name|u_int32_t
name|ast_tx_delim_underrun
decl_stmt|;
name|u_int32_t
name|ast_tx_aggr_failall
decl_stmt|;
comment|/* aggregate TX failed in its entirety */
name|u_int32_t
name|ast_tx_getnobuf
decl_stmt|;
name|u_int32_t
name|ast_tx_getbusybuf
decl_stmt|;
name|u_int32_t
name|ast_tx_intr
decl_stmt|;
name|u_int32_t
name|ast_rx_intr
decl_stmt|;
name|u_int32_t
name|ast_tx_aggr_ok
decl_stmt|;
comment|/* aggregate TX ok */
name|u_int32_t
name|ast_tx_aggr_fail
decl_stmt|;
comment|/* aggregate TX failed */
name|u_int32_t
name|ast_tx_mcastq_overflow
decl_stmt|;
comment|/* multicast queue overflow */
name|u_int32_t
name|ast_rx_keymiss
decl_stmt|;
name|u_int32_t
name|ast_tx_swfiltered
decl_stmt|;
name|u_int32_t
name|ast_tx_node_psq_overflow
decl_stmt|;
name|u_int32_t
name|ast_rx_stbc
decl_stmt|;
comment|/* RX STBC frame */
name|u_int32_t
name|ast_tx_nodeq_overflow
decl_stmt|;
comment|/* node sw queue overflow */
name|u_int32_t
name|ast_pad
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGATHSTATS
value|_IOWR('i', 137, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCZATHSTATS
value|_IOWR('i', 139, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGATHAGSTATS
value|_IOWR('i', 141, struct ifreq)
end_define

begin_struct
struct|struct
name|ath_diag
block|{
name|char
name|ad_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "ath0" */
name|u_int16_t
name|ad_id
decl_stmt|;
define|#
directive|define
name|ATH_DIAG_DYN
value|0x8000
comment|/* allocate buffer in caller */
define|#
directive|define
name|ATH_DIAG_IN
value|0x4000
comment|/* copy in parameters */
define|#
directive|define
name|ATH_DIAG_OUT
value|0x0000
comment|/* copy out results (always) */
define|#
directive|define
name|ATH_DIAG_ID
value|0x0fff
name|u_int16_t
name|ad_in_size
decl_stmt|;
comment|/* pack to fit, yech */
name|caddr_t
name|ad_in_data
decl_stmt|;
name|caddr_t
name|ad_out_data
decl_stmt|;
name|u_int
name|ad_out_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGATHDIAG
value|_IOWR('i', 138, struct ath_diag)
end_define

begin_define
define|#
directive|define
name|SIOCGATHPHYERR
value|_IOWR('i', 140, struct ath_diag)
end_define

begin_comment
comment|/*  * The rate control ioctl has to support multiple potential rate  * control classes.  For now, instead of trying to support an  * abstraction for this in the API, let's just use a TLV  * representation for the payload and let userspace sort it out.  */
end_comment

begin_struct
struct|struct
name|ath_rateioctl_tlv
block|{
name|uint16_t
name|tlv_id
decl_stmt|;
name|uint16_t
name|tlv_len
decl_stmt|;
comment|/* length excluding TLV header */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is purely the six byte MAC address.  */
end_comment

begin_define
define|#
directive|define
name|ATH_RATE_TLV_MACADDR
value|0xaab0
end_define

begin_comment
comment|/*  * The rate control modules may decide to push a mapping table  * of rix -> net80211 ratecode as part of the update.  */
end_comment

begin_define
define|#
directive|define
name|ATH_RATE_TLV_RATETABLE_NENTRIES
value|64
end_define

begin_struct
struct|struct
name|ath_rateioctl_rt
block|{
name|uint16_t
name|nentries
decl_stmt|;
name|uint16_t
name|pad
index|[
literal|1
index|]
decl_stmt|;
name|uint8_t
name|ratecode
index|[
name|ATH_RATE_TLV_RATETABLE_NENTRIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_RATE_TLV_RATETABLE
value|0xaab1
end_define

begin_comment
comment|/*  * This is the sample node statistics structure.  * More in ath_rate/sample/sample.h.  */
end_comment

begin_define
define|#
directive|define
name|ATH_RATE_TLV_SAMPLENODE
value|0xaab2
end_define

begin_struct
struct|struct
name|ath_rateioctl
block|{
name|char
name|if_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name */
union|union
block|{
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint64_t
name|pad
decl_stmt|;
block|}
name|is_u
union|;
name|uint32_t
name|len
decl_stmt|;
name|caddr_t
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGATHNODERATESTATS
value|_IOWR('i', 149, struct ath_rateioctl)
end_define

begin_define
define|#
directive|define
name|SIOCGATHRATESTATS
value|_IOWR('i', 150, struct ath_rateioctl)
end_define

begin_comment
comment|/*  * Radio capture format.  */
end_comment

begin_define
define|#
directive|define
name|ATH_RX_RADIOTAP_PRESENT_BASE
value|(		\ 	(1<< IEEE80211_RADIOTAP_TSFT)		| \ 	(1<< IEEE80211_RADIOTAP_FLAGS)		| \ 	(1<< IEEE80211_RADIOTAP_RATE)		| \ 	(1<< IEEE80211_RADIOTAP_ANTENNA)	| \ 	(1<< IEEE80211_RADIOTAP_DBM_ANTSIGNAL)	| \ 	(1<< IEEE80211_RADIOTAP_DBM_ANTNOISE)	| \ 	(1<< IEEE80211_RADIOTAP_XCHANNEL)	| \ 	0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_ENABLE_RADIOTAP_VENDOR_EXT
end_ifdef

begin_define
define|#
directive|define
name|ATH_RX_RADIOTAP_PRESENT
define|\
value|(ATH_RX_RADIOTAP_PRESENT_BASE		| \ 	(1<< IEEE80211_RADIOTAP_VENDOREXT)	| \ 	(1<< IEEE80211_RADIOTAP_EXT)		| \ 	0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATH_RX_RADIOTAP_PRESENT
value|ATH_RX_RADIOTAP_PRESENT_BASE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATH_ENABLE_RADIOTAP_PRESENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_ENABLE_RADIOTAP_VENDOR_EXT
end_ifdef

begin_comment
comment|/*  * This is higher than the vendor bitmap used inside  * the Atheros reference codebase.  */
end_comment

begin_comment
comment|/* Bit 8 */
end_comment

begin_define
define|#
directive|define
name|ATH_RADIOTAP_VENDOR_HEADER
value|8
end_define

begin_comment
comment|/*  * Using four chains makes all the fields in the  * per-chain info header be 4-byte aligned.  */
end_comment

begin_define
define|#
directive|define
name|ATH_RADIOTAP_MAX_CHAINS
value|4
end_define

begin_comment
comment|/*  * AR9380 and later chips are 3x3, which requires  * 5 EVM DWORDs in HT40 mode.  */
end_comment

begin_define
define|#
directive|define
name|ATH_RADIOTAP_MAX_EVM
value|5
end_define

begin_comment
comment|/*  * The vendor radiotap header data needs to be:  *  * + Aligned to a 4 byte address  * + .. so all internal fields are 4 bytes aligned;  * + .. and no 64 bit fields are allowed.  *  * So padding is required to ensure this is the case.  *  * Note that because of the lack of alignment with the  * vendor header (6 bytes), the first field must be  * two bytes so it can be accessed by alignment-strict  * platform (eg MIPS.)  */
end_comment

begin_struct
struct|struct
name|ath_radiotap_vendor_hdr
block|{
comment|/* 30 bytes */
name|uint8_t
name|vh_version
decl_stmt|;
comment|/* 1 */
name|uint8_t
name|vh_rx_chainmask
decl_stmt|;
comment|/* 1 */
comment|/* At this point it should be 4 byte aligned */
name|uint32_t
name|evm
index|[
name|ATH_RADIOTAP_MAX_EVM
index|]
decl_stmt|;
comment|/* 5 * 4 = 20 */
name|uint8_t
name|rssi_ctl
index|[
name|ATH_RADIOTAP_MAX_CHAINS
index|]
decl_stmt|;
comment|/* 4 */
name|uint8_t
name|rssi_ext
index|[
name|ATH_RADIOTAP_MAX_CHAINS
index|]
decl_stmt|;
comment|/* 4 */
name|uint8_t
name|vh_phyerr_code
decl_stmt|;
comment|/* Phy error code, or 0xff */
name|uint8_t
name|vh_rs_status
decl_stmt|;
comment|/* RX status */
name|uint8_t
name|vh_rssi
decl_stmt|;
comment|/* Raw RSSI */
name|uint8_t
name|vh_flags
decl_stmt|;
comment|/* General flags */
define|#
directive|define
name|ATH_VENDOR_PKT_RX
value|0x01
define|#
directive|define
name|ATH_VENDOR_PKT_TX
value|0x02
define|#
directive|define
name|ATH_VENDOR_PKT_RXPHYERR
value|0x04
define|#
directive|define
name|ATH_VENDOR_PKT_ISAGGR
value|0x08
define|#
directive|define
name|ATH_VENDOR_PKT_MOREAGGR
value|0x10
name|uint8_t
name|vh_rx_hwrate
decl_stmt|;
comment|/* hardware RX ratecode */
name|uint8_t
name|vh_rs_flags
decl_stmt|;
comment|/* RX HAL flags */
name|uint8_t
name|vh_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* pad to DWORD boundary */
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATH_ENABLE_RADIOTAP_VENDOR_EXT */
end_comment

begin_struct
struct|struct
name|ath_rx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wr_ihdr
decl_stmt|;
ifdef|#
directive|ifdef
name|ATH_ENABLE_RADIOTAP_VENDOR_EXT
comment|/* Vendor extension header bitmap */
name|uint32_t
name|wr_ext_bitmap
decl_stmt|;
comment|/* 4 */
comment|/* 	 * This padding is needed because: 	 * + the radiotap header is 8 bytes; 	 * + the extension bitmap is 4 bytes; 	 * + the tsf is 8 bytes, so it must start on an 8 byte 	 *   boundary. 	 */
name|uint32_t
name|wr_pad1
decl_stmt|;
endif|#
directive|endif
comment|/* ATH_ENABLE_RADIOTAP_VENDOR_EXT */
comment|/* Normal radiotap fields */
name|u_int64_t
name|wr_tsf
decl_stmt|;
name|u_int8_t
name|wr_flags
decl_stmt|;
name|u_int8_t
name|wr_rate
decl_stmt|;
name|int8_t
name|wr_antsignal
decl_stmt|;
name|int8_t
name|wr_antnoise
decl_stmt|;
name|u_int8_t
name|wr_antenna
decl_stmt|;
name|u_int8_t
name|wr_pad
index|[
literal|3
index|]
decl_stmt|;
name|u_int32_t
name|wr_chan_flags
decl_stmt|;
name|u_int16_t
name|wr_chan_freq
decl_stmt|;
name|u_int8_t
name|wr_chan_ieee
decl_stmt|;
name|int8_t
name|wr_chan_maxpow
decl_stmt|;
ifdef|#
directive|ifdef
name|ATH_ENABLE_RADIOTAP_VENDOR_EXT
comment|/* 	 * Vendor header section, as required by the 	 * presence of the vendor extension bit and bitmap 	 * entry. 	 * 	 * XXX This must be aligned to a 4 byte address? 	 * XXX or 8 byte address? 	 */
name|struct
name|ieee80211_radiotap_vendor_header
name|wr_vh
decl_stmt|;
comment|/* 6 bytes */
comment|/* 	 * Because of the lack of alignment enforced by the above 	 * header, this vendor section won't be aligned in any 	 * useful way.  So, this will include a two-byte version 	 * value which will force the structure to be 4-byte aligned. 	 */
name|struct
name|ath_radiotap_vendor_hdr
name|wr_v
decl_stmt|;
endif|#
directive|endif
comment|/* ATH_ENABLE_RADIOTAP_VENDOR_EXT */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_TX_RADIOTAP_PRESENT
value|(		\ 	(1<< IEEE80211_RADIOTAP_TSFT)		| \ 	(1<< IEEE80211_RADIOTAP_FLAGS)		| \ 	(1<< IEEE80211_RADIOTAP_RATE)		| \ 	(1<< IEEE80211_RADIOTAP_DBM_TX_POWER)	| \ 	(1<< IEEE80211_RADIOTAP_ANTENNA)	| \ 	(1<< IEEE80211_RADIOTAP_XCHANNEL)	| \ 	0)
end_define

begin_struct
struct|struct
name|ath_tx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wt_ihdr
decl_stmt|;
name|u_int64_t
name|wt_tsf
decl_stmt|;
name|u_int8_t
name|wt_flags
decl_stmt|;
name|u_int8_t
name|wt_rate
decl_stmt|;
name|u_int8_t
name|wt_txpower
decl_stmt|;
name|u_int8_t
name|wt_antenna
decl_stmt|;
name|u_int32_t
name|wt_chan_flags
decl_stmt|;
name|u_int16_t
name|wt_chan_freq
decl_stmt|;
name|u_int8_t
name|wt_chan_ieee
decl_stmt|;
name|int8_t
name|wt_chan_maxpow
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * DFS ioctl commands  */
end_comment

begin_define
define|#
directive|define
name|DFS_SET_THRESH
value|2
end_define

begin_define
define|#
directive|define
name|DFS_GET_THRESH
value|3
end_define

begin_define
define|#
directive|define
name|DFS_RADARDETECTS
value|6
end_define

begin_comment
comment|/*  * DFS ioctl parameter types  */
end_comment

begin_define
define|#
directive|define
name|DFS_PARAM_FIRPWR
value|1
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_RRSSI
value|2
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_HEIGHT
value|3
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_PRSSI
value|4
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_INBAND
value|5
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_NOL
value|6
end_define

begin_comment
comment|/* XXX not used in FreeBSD */
end_comment

begin_define
define|#
directive|define
name|DFS_PARAM_RELSTEP_EN
value|7
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_RELSTEP
value|8
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_RELPWR_EN
value|9
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_RELPWR
value|10
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_MAXLEN
value|11
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_USEFIR128
value|12
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_BLOCKRADAR
value|13
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_MAXRSSI_EN
value|14
end_define

begin_comment
comment|/* FreeBSD-specific start at 32 */
end_comment

begin_define
define|#
directive|define
name|DFS_PARAM_ENABLE
value|32
end_define

begin_define
define|#
directive|define
name|DFS_PARAM_EN_EXTCH
value|33
end_define

begin_comment
comment|/*  * Spectral ioctl parameter types  */
end_comment

begin_define
define|#
directive|define
name|SPECTRAL_PARAM_FFT_PERIOD
value|1
end_define

begin_define
define|#
directive|define
name|SPECTRAL_PARAM_SS_PERIOD
value|2
end_define

begin_define
define|#
directive|define
name|SPECTRAL_PARAM_SS_COUNT
value|3
end_define

begin_define
define|#
directive|define
name|SPECTRAL_PARAM_SS_SHORT_RPT
value|4
end_define

begin_define
define|#
directive|define
name|SPECTRAL_PARAM_ENABLED
value|5
end_define

begin_define
define|#
directive|define
name|SPECTRAL_PARAM_ACTIVE
value|6
end_define

begin_comment
comment|/*  * Spectral control parameters  */
end_comment

begin_define
define|#
directive|define
name|SIOCGATHSPECTRAL
value|_IOWR('i', 151, struct ath_diag)
end_define

begin_define
define|#
directive|define
name|SPECTRAL_CONTROL_ENABLE
value|2
end_define

begin_define
define|#
directive|define
name|SPECTRAL_CONTROL_DISABLE
value|3
end_define

begin_define
define|#
directive|define
name|SPECTRAL_CONTROL_START
value|4
end_define

begin_define
define|#
directive|define
name|SPECTRAL_CONTROL_STOP
value|5
end_define

begin_define
define|#
directive|define
name|SPECTRAL_CONTROL_GET_PARAMS
value|6
end_define

begin_define
define|#
directive|define
name|SPECTRAL_CONTROL_SET_PARAMS
value|7
end_define

begin_define
define|#
directive|define
name|SPECTRAL_CONTROL_ENABLE_AT_RESET
value|8
end_define

begin_define
define|#
directive|define
name|SPECTRAL_CONTROL_DISABLE_AT_RESET
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_ATHIOCTL_H */
end_comment

end_unit

