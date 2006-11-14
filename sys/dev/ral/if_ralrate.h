begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/* $NetBSD: ieee80211_rssadapt.h,v 1.4 2005/02/26 22:45:09 perry Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003, 2004 David Young.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. The name of David Young may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY David Young ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL David  * Young BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Data-rate adaptation loosely based on "Link Adaptation Strategy  * for IEEE 802.11 WLAN via Received Signal Strength Measurement"  * by Javier del Prado Pavon and Sunghyun Choi.  */
end_comment

begin_comment
comment|/* Buckets for frames 0-128 bytes long, 129-1024, 1025-maximum. */
end_comment

begin_define
define|#
directive|define
name|RAL_RSSADAPT_BKTS
value|3
end_define

begin_define
define|#
directive|define
name|RAL_RSSADAPT_BKT0
value|128
end_define

begin_define
define|#
directive|define
name|RAL_RSSADAPT_BKTPOWER
value|3
end_define

begin_comment
comment|/* 2**_BKTPOWER */
end_comment

begin_define
define|#
directive|define
name|ral_rssadapt_thresh_new
define|\
value|(ral_rssadapt_thresh_denom - ral_rssadapt_thresh_old)
end_define

begin_define
define|#
directive|define
name|ral_rssadapt_decay_new
define|\
value|(ral_rssadapt_decay_denom - ral_rssadapt_decay_old)
end_define

begin_define
define|#
directive|define
name|ral_rssadapt_avgrssi_new
define|\
value|(ral_rssadapt_avgrssi_denom - ral_rssadapt_avgrssi_old)
end_define

begin_struct
struct|struct
name|ral_rssadapt_expavgctl
block|{
comment|/* RSS threshold decay. */
name|u_int
name|rc_decay_denom
decl_stmt|;
name|u_int
name|rc_decay_old
decl_stmt|;
comment|/* RSS threshold update. */
name|u_int
name|rc_thresh_denom
decl_stmt|;
name|u_int
name|rc_thresh_old
decl_stmt|;
comment|/* RSS average update. */
name|u_int
name|rc_avgrssi_denom
decl_stmt|;
name|u_int
name|rc_avgrssi_old
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ral_rssadapt
block|{
comment|/* exponential average RSSI<< 8 */
name|u_int16_t
name|ra_avg_rssi
decl_stmt|;
comment|/* Tx failures in this update interval */
name|u_int32_t
name|ra_nfail
decl_stmt|;
comment|/* Tx successes in this update interval */
name|u_int32_t
name|ra_nok
decl_stmt|;
comment|/* exponential average packets/second */
name|u_int32_t
name|ra_pktrate
decl_stmt|;
comment|/* RSSI threshold for each Tx rate */
name|u_int16_t
name|ra_rate_thresh
index|[
name|RAL_RSSADAPT_BKTS
index|]
index|[
name|IEEE80211_RATE_SIZE
index|]
decl_stmt|;
name|struct
name|timeval
name|ra_last_raise
decl_stmt|;
name|struct
name|timeval
name|ra_raise_interval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Properties of a Tx packet, for link adaptation. */
end_comment

begin_struct
struct|struct
name|ral_rssdesc
block|{
name|u_int
name|id_len
decl_stmt|;
comment|/* Tx packet length */
name|u_int
name|id_rateidx
decl_stmt|;
comment|/* index into ni->ni_rates */
name|struct
name|ieee80211_node
modifier|*
name|id_node
decl_stmt|;
comment|/* destination STA MAC */
name|u_int8_t
name|id_rssi
decl_stmt|;
comment|/* destination STA avg RSS @ 						 * Tx time 						 */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ral_rssadapt_updatestats
parameter_list|(
name|struct
name|ral_rssadapt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ral_rssadapt_input
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ral_rssadapt
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ral_rssadapt_lower_rate
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ral_rssadapt
modifier|*
parameter_list|,
name|struct
name|ral_rssdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ral_rssadapt_raise_rate
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ral_rssadapt
modifier|*
parameter_list|,
name|struct
name|ral_rssdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ral_rssadapt_choose
parameter_list|(
name|struct
name|ral_rssadapt
modifier|*
parameter_list|,
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|,
name|struct
name|ieee80211_frame
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

