begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
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
name|ast_intrcoal
decl_stmt|;
comment|/* interrupts coalesced */
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
name|ast_rx_phyerr
decl_stmt|;
comment|/* rx failed 'cuz of PHY err */
name|u_int32_t
name|ast_rx_phy
index|[
literal|32
index|]
decl_stmt|;
comment|/* rx PHY error per-code counts */
name|u_int32_t
name|ast_rx_tooshort
decl_stmt|;
comment|/* rx discarded 'cuz frame too short */
name|u_int32_t
name|ast_rx_ctl
decl_stmt|;
comment|/* rx discarded 'cuz ctl frame */
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGATHSTATS
value|_IOWR('i', 137, struct ifreq)
end_define

begin_comment
comment|/*  * Radio capture format.  */
end_comment

begin_define
define|#
directive|define
name|ATH_RX_RADIOTAP_PRESENT
value|(		\ 	(1<< IEEE80211_RADIOTAP_FLAGS)		| \ 	(1<< IEEE80211_RADIOTAP_RATE)		| \ 	(1<< IEEE80211_RADIOTAP_CHANNEL)	| \ 	(1<< IEEE80211_RADIOTAP_DB_ANTSIGNAL)	| \ 	(1<< IEEE80211_RADIOTAP_ANTENNA)	| \ 	0)
end_define

begin_struct
struct|struct
name|ath_rx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wr_ihdr
decl_stmt|;
name|u_int8_t
name|wr_flags
decl_stmt|;
comment|/* XXX for padding */
name|u_int8_t
name|wr_rate
decl_stmt|;
name|u_int16_t
name|wr_chan_freq
decl_stmt|;
name|u_int16_t
name|wr_chan_flags
decl_stmt|;
name|u_int8_t
name|wr_antsignal
decl_stmt|;
name|u_int8_t
name|wr_antenna
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_TX_RADIOTAP_PRESENT
value|(		\ 	(1<< IEEE80211_RADIOTAP_FLAGS)		| \ 	(1<< IEEE80211_RADIOTAP_RATE)		| \ 	(1<< IEEE80211_RADIOTAP_CHANNEL)	| \ 	0)
end_define

begin_struct
struct|struct
name|ath_tx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wt_ihdr
decl_stmt|;
name|u_int8_t
name|wt_flags
decl_stmt|;
comment|/* XXX for padding */
name|u_int8_t
name|wt_rate
decl_stmt|;
name|u_int16_t
name|wt_chan_freq
decl_stmt|;
name|u_int16_t
name|wt_chan_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_ATHIOCTL_H */
end_comment

end_unit

