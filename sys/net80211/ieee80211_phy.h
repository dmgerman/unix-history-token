begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_PHY_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * IEEE 802.11 PHY-related definitions.  */
end_comment

begin_comment
comment|/*  * Contention window (slots).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CW_MAX
value|1023
end_define

begin_comment
comment|/* aCWmax */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CW_MIN_0
value|31
end_define

begin_comment
comment|/* DS/CCK aCWmin, ERP aCWmin(0) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CW_MIN_1
value|15
end_define

begin_comment
comment|/* OFDM aCWmin, ERP aCWmin(1) */
end_comment

begin_comment
comment|/*  * SIFS (microseconds).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DUR_SIFS
value|10
end_define

begin_comment
comment|/* DS/CCK/ERP SIFS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DUR_OFDM_SIFS
value|16
end_define

begin_comment
comment|/* OFDM SIFS */
end_comment

begin_comment
comment|/*  * Slot time (microseconds).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DUR_SLOT
value|20
end_define

begin_comment
comment|/* DS/CCK slottime, ERP long slottime */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DUR_SHSLOT
value|9
end_define

begin_comment
comment|/* ERP short slottime */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DUR_OFDM_SLOT
value|9
end_define

begin_comment
comment|/* OFDM slottime */
end_comment

begin_comment
comment|/*  * DIFS (microseconds).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DUR_DIFS
parameter_list|(
name|sifs
parameter_list|,
name|slot
parameter_list|)
value|((sifs) + 2 * (slot))
end_define

begin_struct_decl
struct_decl|struct
name|ieee80211_channel
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|IEEE80211_RATE_TABLE_SIZE
value|128
end_define

begin_struct
struct|struct
name|ieee80211_rate_table
block|{
name|int
name|rateCount
decl_stmt|;
comment|/* NB: for proper padding */
name|uint8_t
name|rateCodeToIndex
index|[
literal|256
index|]
decl_stmt|;
comment|/* back mapping */
struct|struct
block|{
name|uint8_t
name|phy
decl_stmt|;
comment|/* CCK/OFDM/TURBO */
name|uint32_t
name|rateKbps
decl_stmt|;
comment|/* transfer rate in kbs */
name|uint8_t
name|shortPreamble
decl_stmt|;
comment|/* mask for enabling short 						 * preamble in CCK rate code */
name|uint8_t
name|dot11Rate
decl_stmt|;
comment|/* value for supported rates 						 * info element of MLME */
name|uint8_t
name|ctlRateIndex
decl_stmt|;
comment|/* index of next lower basic 						 * rate; used for dur. calcs */
name|uint16_t
name|lpAckDuration
decl_stmt|;
comment|/* long preamble ACK dur. */
name|uint16_t
name|spAckDuration
decl_stmt|;
comment|/* short preamble ACK dur. */
block|}
name|info
index|[
name|IEEE80211_RATE_TABLE_SIZE
index|]
struct|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|ieee80211_get_ratetable
parameter_list|(
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline__
name|uint8_t
name|ieee80211_ack_rate
parameter_list|(
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|rt
parameter_list|,
name|uint8_t
name|rate
parameter_list|)
block|{
comment|/* 	 * XXX Assert this is for a legacy rate; not for an MCS rate. 	 * If the caller wishes to use it for a basic rate, they should 	 * clear the high bit first. 	 */
name|KASSERT
argument_list|(
operator|!
operator|(
name|rate
operator|&
literal|0x80
operator|)
argument_list|,
operator|(
literal|"rate %d is basic/mcs?"
operator|,
name|rate
operator|)
argument_list|)
expr_stmt|;
name|uint8_t
name|cix
init|=
name|rt
operator|->
name|info
index|[
name|rt
operator|->
name|rateCodeToIndex
index|[
name|rate
operator|&
name|IEEE80211_RATE_VAL
index|]
index|]
operator|.
name|ctlRateIndex
decl_stmt|;
name|KASSERT
argument_list|(
name|cix
operator|!=
operator|(
name|uint8_t
operator|)
operator|-
literal|1
argument_list|,
operator|(
literal|"rate %d has no info"
operator|,
name|rate
operator|)
argument_list|)
expr_stmt|;
return|return
name|rt
operator|->
name|info
index|[
name|cix
index|]
operator|.
name|dot11Rate
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint8_t
name|ieee80211_ctl_rate
parameter_list|(
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|rt
parameter_list|,
name|uint8_t
name|rate
parameter_list|)
block|{
comment|/* 	 * XXX Assert this is for a legacy rate; not for an MCS rate. 	 * If the caller wishes to use it for a basic rate, they should 	 * clear the high bit first. 	 */
name|KASSERT
argument_list|(
operator|!
operator|(
name|rate
operator|&
literal|0x80
operator|)
argument_list|,
operator|(
literal|"rate %d is basic/mcs?"
operator|,
name|rate
operator|)
argument_list|)
expr_stmt|;
name|uint8_t
name|cix
init|=
name|rt
operator|->
name|info
index|[
name|rt
operator|->
name|rateCodeToIndex
index|[
name|rate
operator|&
name|IEEE80211_RATE_VAL
index|]
index|]
operator|.
name|ctlRateIndex
decl_stmt|;
name|KASSERT
argument_list|(
name|cix
operator|!=
operator|(
name|uint8_t
operator|)
operator|-
literal|1
argument_list|,
operator|(
literal|"rate %d has no info"
operator|,
name|rate
operator|)
argument_list|)
expr_stmt|;
return|return
name|rt
operator|->
name|info
index|[
name|cix
index|]
operator|.
name|dot11Rate
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|enum
name|ieee80211_phytype
name|ieee80211_rate2phytype
parameter_list|(
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|rt
parameter_list|,
name|uint8_t
name|rate
parameter_list|)
block|{
comment|/* 	 * XXX Assert this is for a legacy rate; not for an MCS rate. 	 * If the caller wishes to use it for a basic rate, they should 	 * clear the high bit first. 	 */
name|KASSERT
argument_list|(
operator|!
operator|(
name|rate
operator|&
literal|0x80
operator|)
argument_list|,
operator|(
literal|"rate %d is basic/mcs?"
operator|,
name|rate
operator|)
argument_list|)
expr_stmt|;
name|uint8_t
name|rix
init|=
name|rt
operator|->
name|rateCodeToIndex
index|[
name|rate
operator|&
name|IEEE80211_RATE_VAL
index|]
decl_stmt|;
name|KASSERT
argument_list|(
name|rix
operator|!=
operator|(
name|uint8_t
operator|)
operator|-
literal|1
argument_list|,
operator|(
literal|"rate %d has no info"
operator|,
name|rate
operator|)
argument_list|)
expr_stmt|;
return|return
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|phy
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|ieee80211_isratevalid
parameter_list|(
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|rt
parameter_list|,
name|uint8_t
name|rate
parameter_list|)
block|{
comment|/* 	 * XXX Assert this is for a legacy rate; not for an MCS rate. 	 * If the caller wishes to use it for a basic rate, they should 	 * clear the high bit first. 	 */
name|KASSERT
argument_list|(
operator|!
operator|(
name|rate
operator|&
literal|0x80
operator|)
argument_list|,
operator|(
literal|"rate %d is basic/mcs?"
operator|,
name|rate
operator|)
argument_list|)
expr_stmt|;
return|return
name|rt
operator|->
name|rateCodeToIndex
index|[
name|rate
index|]
operator|!=
operator|(
name|uint8_t
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Calculate ACK field for  * o  non-fragment data frames  * o  management frames  * sent using rate, phy and short preamble setting.  */
end_comment

begin_function
specifier|static
name|__inline__
name|uint16_t
name|ieee80211_ack_duration
parameter_list|(
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|rt
parameter_list|,
name|uint8_t
name|rate
parameter_list|,
name|int
name|isShortPreamble
parameter_list|)
block|{
name|uint8_t
name|rix
init|=
name|rt
operator|->
name|rateCodeToIndex
index|[
name|rate
index|]
decl_stmt|;
name|KASSERT
argument_list|(
name|rix
operator|!=
operator|(
name|uint8_t
operator|)
operator|-
literal|1
argument_list|,
operator|(
literal|"rate %d has no info"
operator|,
name|rate
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|isShortPreamble
condition|)
block|{
name|KASSERT
argument_list|(
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|spAckDuration
operator|!=
literal|0
argument_list|,
operator|(
literal|"shpreamble ack dur is not computed!\n"
operator|)
argument_list|)
expr_stmt|;
return|return
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|spAckDuration
return|;
block|}
else|else
block|{
name|KASSERT
argument_list|(
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|lpAckDuration
operator|!=
literal|0
argument_list|,
operator|(
literal|"lgpreamble ack dur is not computed!\n"
operator|)
argument_list|)
expr_stmt|;
return|return
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|lpAckDuration
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint8_t
name|ieee80211_legacy_rate_lookup
parameter_list|(
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|rt
parameter_list|,
name|uint8_t
name|rate
parameter_list|)
block|{
return|return
operator|(
name|rt
operator|->
name|rateCodeToIndex
index|[
name|rate
operator|&
name|IEEE80211_RATE_VAL
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Compute the time to transmit a frame of length frameLen bytes  * using the specified 802.11 rate code, phy, and short preamble  * setting.  *  * NB: SIFS is included.  */
end_comment

begin_function_decl
name|uint16_t
name|ieee80211_compute_duration
parameter_list|(
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
parameter_list|,
name|uint32_t
name|frameLen
parameter_list|,
name|uint16_t
name|rate
parameter_list|,
name|int
name|isShortPreamble
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert PLCP signal/rate field to 802.11 rate code (.5Mbits/s)  */
end_comment

begin_function_decl
name|uint8_t
name|ieee80211_plcp2rate
parameter_list|(
name|uint8_t
parameter_list|,
name|enum
name|ieee80211_phytype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert 802.11 rate code to PLCP signal.  */
end_comment

begin_function_decl
name|uint8_t
name|ieee80211_rate2plcp
parameter_list|(
name|int
parameter_list|,
name|enum
name|ieee80211_phytype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ieee80211_compute_duration_ht
parameter_list|(
name|uint32_t
name|frameLen
parameter_list|,
name|uint16_t
name|rate
parameter_list|,
name|int
name|streams
parameter_list|,
name|int
name|isht40
parameter_list|,
name|int
name|isShortGI
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET80211_IEEE80211_PHY_H_ */
end_comment

end_unit

