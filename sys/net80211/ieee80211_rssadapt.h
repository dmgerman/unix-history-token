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

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_RSSADAPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_RSSADAPT_H_
end_define

begin_comment
comment|/* Data-rate adaptation loosely based on "Link Adaptation Strategy  * for IEEE 802.11 WLAN via Received Signal Strength Measurement"  * by Javier del Prado Pavon and Sunghyun Choi.  */
end_comment

begin_comment
comment|/* Buckets for frames 0-128 bytes long, 129-1024, 1025-maximum. */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RSSADAPT_BKTS
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_RSSADAPT_BKT0
value|128
end_define

begin_define
define|#
directive|define
name|IEEE80211_RSSADAPT_BKTPOWER
value|3
end_define

begin_comment
comment|/* 2**_BKTPOWER */
end_comment

begin_struct
struct|struct
name|ieee80211_rssadapt
block|{
name|struct
name|ieee80211vap
modifier|*
name|vap
decl_stmt|;
name|int
name|interval
decl_stmt|;
comment|/* update interval (ticks) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_rssadapt_node
block|{
name|struct
name|ieee80211_rssadapt
modifier|*
name|ra_rs
decl_stmt|;
comment|/* backpointer */
name|struct
name|ieee80211_rateset
name|ra_rates
decl_stmt|;
comment|/* negotiated rates */
name|int
name|ra_rix
decl_stmt|;
comment|/* current rate index */
name|int
name|ra_ticks
decl_stmt|;
comment|/* time of last update */
name|int
name|ra_last_raise
decl_stmt|;
comment|/* time of last rate raise */
name|int
name|ra_raise_interval
decl_stmt|;
comment|/* rate raise time threshold */
comment|/* Tx failures in this update interval */
name|uint32_t
name|ra_nfail
decl_stmt|;
comment|/* Tx successes in this update interval */
name|uint32_t
name|ra_nok
decl_stmt|;
comment|/* exponential average packets/second */
name|uint32_t
name|ra_pktrate
decl_stmt|;
comment|/* RSSI threshold for each Tx rate */
name|uint16_t
name|ra_rate_thresh
index|[
name|IEEE80211_RSSADAPT_BKTS
index|]
index|[
name|IEEE80211_RATE_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_rssadapt_init
parameter_list|(
name|struct
name|ieee80211_rssadapt
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_rssadapt_cleanup
parameter_list|(
name|struct
name|ieee80211_rssadapt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_rssadapt_setinterval
parameter_list|(
name|struct
name|ieee80211_rssadapt
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_rssadapt_node_init
parameter_list|(
name|struct
name|ieee80211_rssadapt
modifier|*
parameter_list|,
name|struct
name|ieee80211_rssadapt_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_rssadapt_choose
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_rssadapt_node
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NB: these are public only for the inline below */
end_comment

begin_function_decl
name|void
name|ieee80211_rssadapt_raise_rate
parameter_list|(
name|struct
name|ieee80211_rssadapt_node
modifier|*
parameter_list|,
name|int
name|pktlen
parameter_list|,
name|int
name|rssi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_rssadapt_lower_rate
parameter_list|(
name|struct
name|ieee80211_rssadapt_node
modifier|*
parameter_list|,
name|int
name|pktlen
parameter_list|,
name|int
name|rssi
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IEEE80211_RSSADAPT_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_RSSADAPT_FAILURE
value|0
end_define

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_rssadapt_tx_complete
parameter_list|(
name|struct
name|ieee80211_rssadapt_node
modifier|*
name|ra
parameter_list|,
name|int
name|success
parameter_list|,
name|int
name|pktlen
parameter_list|,
name|int
name|rssi
parameter_list|)
block|{
if|if
condition|(
name|success
condition|)
block|{
name|ra
operator|->
name|ra_nok
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|ra
operator|->
name|ra_rix
operator|+
literal|1
operator|)
operator|<
name|ra
operator|->
name|ra_rates
operator|.
name|rs_nrates
operator|&&
operator|(
name|ticks
operator|-
name|ra
operator|->
name|ra_last_raise
operator|)
operator|>=
name|ra
operator|->
name|ra_raise_interval
condition|)
name|ieee80211_rssadapt_raise_rate
argument_list|(
name|ra
argument_list|,
name|pktlen
argument_list|,
name|rssi
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ra
operator|->
name|ra_nfail
operator|++
expr_stmt|;
name|ieee80211_rssadapt_lower_rate
argument_list|(
name|ra
argument_list|,
name|pktlen
argument_list|,
name|rssi
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_RSSADAPT_H_ */
end_comment

end_unit

