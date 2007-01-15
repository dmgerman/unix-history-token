begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 John Bicket  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Defintions for the Atheros Wireless LAN controller driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_RATE_SAMPLE_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_RATE_SAMPLE_H
end_define

begin_comment
comment|/* per-device state */
end_comment

begin_struct
struct|struct
name|sample_softc
block|{
name|struct
name|ath_ratectrl
name|arc
decl_stmt|;
comment|/* base state */
name|int
name|ath_smoothing_rate
decl_stmt|;
comment|/* ewma percentage (out of 100) */
name|int
name|ath_sample_rate
decl_stmt|;
comment|/* send a different bit-rate 1/X packets */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_SOFTC_SAMPLE
parameter_list|(
name|sc
parameter_list|)
value|((struct sample_softc *)sc->sc_rc)
end_define

begin_struct
struct|struct
name|rate_info
block|{
name|int
name|rate
decl_stmt|;
name|int
name|rix
decl_stmt|;
name|int
name|rateCode
decl_stmt|;
name|int
name|shortPreambleRateCode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rate_stats
block|{
name|unsigned
name|average_tx_time
decl_stmt|;
name|int
name|successive_failures
decl_stmt|;
name|int
name|tries
decl_stmt|;
name|int
name|total_packets
decl_stmt|;
name|int
name|packets_acked
decl_stmt|;
name|unsigned
name|perfect_tx_time
decl_stmt|;
comment|/* transmit time for 0 retries */
name|int
name|last_tx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * for now, we track performance for three different packet  * size buckets  */
end_comment

begin_define
define|#
directive|define
name|NUM_PACKET_SIZE_BINS
value|3
end_define

begin_decl_stmt
specifier|static
name|int
name|packet_size_bins
index|[
name|NUM_PACKET_SIZE_BINS
index|]
init|=
block|{
literal|250
block|,
literal|1600
block|,
literal|3000
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per-node state */
end_comment

begin_struct
struct|struct
name|sample_node
block|{
name|int
name|static_rate_ndx
decl_stmt|;
name|int
name|num_rates
decl_stmt|;
name|struct
name|rate_info
name|rates
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
name|struct
name|rate_stats
name|stats
index|[
name|NUM_PACKET_SIZE_BINS
index|]
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
name|int
name|last_sample_ndx
index|[
name|NUM_PACKET_SIZE_BINS
index|]
decl_stmt|;
name|int
name|current_sample_ndx
index|[
name|NUM_PACKET_SIZE_BINS
index|]
decl_stmt|;
name|int
name|packets_sent
index|[
name|NUM_PACKET_SIZE_BINS
index|]
decl_stmt|;
name|int
name|current_rate
index|[
name|NUM_PACKET_SIZE_BINS
index|]
decl_stmt|;
name|int
name|packets_since_switch
index|[
name|NUM_PACKET_SIZE_BINS
index|]
decl_stmt|;
name|unsigned
name|ticks_since_switch
index|[
name|NUM_PACKET_SIZE_BINS
index|]
decl_stmt|;
name|int
name|packets_since_sample
index|[
name|NUM_PACKET_SIZE_BINS
index|]
decl_stmt|;
name|unsigned
name|sample_tt
index|[
name|NUM_PACKET_SIZE_BINS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_NODE_SAMPLE
parameter_list|(
name|an
parameter_list|)
value|((struct sample_node *)&an[1])
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WIFI_CW_MIN
value|31
end_define

begin_define
define|#
directive|define
name|WIFI_CW_MAX
value|1023
end_define

begin_comment
comment|/*  * Definitions for pulling the rate and trie counts from  * a 5212 h/w descriptor.  These Don't belong here; the  * driver should record this information so the rate control  * code doesn't go groveling around in the descriptor bits.  */
end_comment

begin_define
define|#
directive|define
name|ds_ctl2
value|ds_hw[0]
end_define

begin_define
define|#
directive|define
name|ds_ctl3
value|ds_hw[1]
end_define

begin_comment
comment|/* TX ds_ctl2 */
end_comment

begin_define
define|#
directive|define
name|AR_XmitDataTries0
value|0x000f0000
end_define

begin_comment
comment|/* series 0 max attempts */
end_comment

begin_define
define|#
directive|define
name|AR_XmitDataTries0_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries1
value|0x00f00000
end_define

begin_comment
comment|/* series 1 max attempts */
end_comment

begin_define
define|#
directive|define
name|AR_XmitDataTries1_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries2
value|0x0f000000
end_define

begin_comment
comment|/* series 2 max attempts */
end_comment

begin_define
define|#
directive|define
name|AR_XmitDataTries2_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries3
value|0xf0000000
end_define

begin_comment
comment|/* series 3 max attempts */
end_comment

begin_define
define|#
directive|define
name|AR_XmitDataTries3_S
value|28
end_define

begin_comment
comment|/* TX ds_ctl3 */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate0
value|0x0000001f
end_define

begin_comment
comment|/* series 0 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_XmitRate1
value|0x000003e0
end_define

begin_comment
comment|/* series 1 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate1_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_XmitRate2
value|0x00007c00
end_define

begin_comment
comment|/* series 2 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate2_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_XmitRate3
value|0x000f8000
end_define

begin_comment
comment|/* series 3 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate3_S
value|15
end_define

begin_comment
comment|/* TX ds_ctl3 for 5416 */
end_comment

begin_define
define|#
directive|define
name|AR5416_XmitRate0
value|0x000000ff
end_define

begin_comment
comment|/* series 0 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR5416_XmitRate0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR5416_XmitRate1
value|0x0000ff00
end_define

begin_comment
comment|/* series 1 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR5416_XmitRate1_S
value|8
end_define

begin_define
define|#
directive|define
name|AR5416_XmitRate2
value|0x00ff0000
end_define

begin_comment
comment|/* series 2 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR5416_XmitRate2_S
value|16
end_define

begin_define
define|#
directive|define
name|AR5416_XmitRate3
value|0xff000000
end_define

begin_comment
comment|/* series 3 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR5416_XmitRate3_S
value|24
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

begin_comment
comment|/*  * Calculate the transmit duration of a frame.  */
end_comment

begin_function
specifier|static
name|unsigned
name|calc_usecs_unicast_packet
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|rix
parameter_list|,
name|int
name|short_retries
parameter_list|,
name|int
name|long_retries
parameter_list|)
block|{
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|rt
init|=
name|sc
operator|->
name|sc_currates
decl_stmt|;
name|int
name|rts
decl_stmt|,
name|cts
decl_stmt|;
name|unsigned
name|t_slot
init|=
literal|20
decl_stmt|;
name|unsigned
name|t_difs
init|=
literal|50
decl_stmt|;
name|unsigned
name|t_sifs
init|=
literal|10
decl_stmt|;
name|struct
name|ieee80211com
modifier|*
name|ic
init|=
operator|&
name|sc
operator|->
name|sc_ic
decl_stmt|;
name|int
name|tt
init|=
literal|0
decl_stmt|;
name|int
name|x
init|=
literal|0
decl_stmt|;
name|int
name|cw
init|=
name|WIFI_CW_MIN
decl_stmt|;
name|int
name|cix
decl_stmt|;
name|KASSERT
argument_list|(
name|rt
operator|!=
name|NULL
argument_list|,
operator|(
literal|"no rate table, mode %u"
operator|,
name|sc
operator|->
name|sc_curmode
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|rix
operator|>=
name|rt
operator|->
name|rateCount
condition|)
block|{
name|printf
argument_list|(
literal|"bogus rix %d, max %u, mode %u\n"
argument_list|,
name|rix
argument_list|,
name|rt
operator|->
name|rateCount
argument_list|,
name|sc
operator|->
name|sc_curmode
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|cix
operator|=
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|controlRate
expr_stmt|;
comment|/*  	 * XXX getting mac/phy level timings should be fixed for turbo 	 * rates, and there is probably a way to get this from the 	 * hal... 	 */
switch|switch
condition|(
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|phy
condition|)
block|{
case|case
name|IEEE80211_T_OFDM
case|:
name|t_slot
operator|=
literal|9
expr_stmt|;
name|t_sifs
operator|=
literal|16
expr_stmt|;
name|t_difs
operator|=
literal|28
expr_stmt|;
comment|/* fall through */
case|case
name|IEEE80211_T_TURBO
case|:
name|t_slot
operator|=
literal|9
expr_stmt|;
name|t_sifs
operator|=
literal|8
expr_stmt|;
name|t_difs
operator|=
literal|28
expr_stmt|;
break|break;
case|case
name|IEEE80211_T_DS
case|:
comment|/* fall through to default */
default|default:
comment|/* pg 205 ieee.802.11.pdf */
name|t_slot
operator|=
literal|20
expr_stmt|;
name|t_difs
operator|=
literal|50
expr_stmt|;
name|t_sifs
operator|=
literal|10
expr_stmt|;
block|}
name|rts
operator|=
name|cts
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|ic
operator|->
name|ic_flags
operator|&
name|IEEE80211_F_USEPROT
operator|)
operator|&&
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|phy
operator|==
name|IEEE80211_T_OFDM
condition|)
block|{
if|if
condition|(
name|ic
operator|->
name|ic_protmode
operator|==
name|IEEE80211_PROT_RTSCTS
condition|)
name|rts
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|ic
operator|->
name|ic_protmode
operator|==
name|IEEE80211_PROT_CTSONLY
condition|)
name|cts
operator|=
literal|1
expr_stmt|;
name|cix
operator|=
name|rt
operator|->
name|info
index|[
name|sc
operator|->
name|sc_protrix
index|]
operator|.
name|controlRate
expr_stmt|;
block|}
if|if
condition|(
literal|0
comment|/*length> ic->ic_rtsthreshold */
condition|)
block|{
name|rts
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|rts
operator|||
name|cts
condition|)
block|{
name|int
name|ctsrate
decl_stmt|;
name|int
name|ctsduration
init|=
literal|0
decl_stmt|;
comment|/* NB: this is intentionally not a runtime check */
name|KASSERT
argument_list|(
name|cix
operator|<
name|rt
operator|->
name|rateCount
argument_list|,
operator|(
literal|"bogus cix %d, max %u, mode %u\n"
operator|,
name|cix
operator|,
name|rt
operator|->
name|rateCount
operator|,
name|sc
operator|->
name|sc_curmode
operator|)
argument_list|)
expr_stmt|;
name|ctsrate
operator|=
name|rt
operator|->
name|info
index|[
name|cix
index|]
operator|.
name|rateCode
operator||
name|rt
operator|->
name|info
index|[
name|cix
index|]
operator|.
name|shortPreamble
expr_stmt|;
if|if
condition|(
name|rts
condition|)
comment|/* SIFS + CTS */
name|ctsduration
operator|+=
name|rt
operator|->
name|info
index|[
name|cix
index|]
operator|.
name|spAckDuration
expr_stmt|;
name|ctsduration
operator|+=
name|ath_hal_computetxtime
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|rt
argument_list|,
name|length
argument_list|,
name|rix
argument_list|,
name|AH_TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|cts
condition|)
comment|/* SIFS + ACK */
name|ctsduration
operator|+=
name|rt
operator|->
name|info
index|[
name|cix
index|]
operator|.
name|spAckDuration
expr_stmt|;
name|tt
operator|+=
operator|(
name|short_retries
operator|+
literal|1
operator|)
operator|*
name|ctsduration
expr_stmt|;
block|}
name|tt
operator|+=
name|t_difs
expr_stmt|;
name|tt
operator|+=
operator|(
name|long_retries
operator|+
literal|1
operator|)
operator|*
operator|(
name|t_sifs
operator|+
name|rt
operator|->
name|info
index|[
name|rix
index|]
operator|.
name|spAckDuration
operator|)
expr_stmt|;
name|tt
operator|+=
operator|(
name|long_retries
operator|+
literal|1
operator|)
operator|*
name|ath_hal_computetxtime
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|rt
argument_list|,
name|length
argument_list|,
name|rix
argument_list|,
name|AH_TRUE
argument_list|)
expr_stmt|;
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<=
name|short_retries
operator|+
name|long_retries
condition|;
name|x
operator|++
control|)
block|{
name|cw
operator|=
name|MIN
argument_list|(
name|WIFI_CW_MAX
argument_list|,
operator|(
name|cw
operator|+
literal|1
operator|)
operator|*
literal|2
argument_list|)
expr_stmt|;
name|tt
operator|+=
operator|(
name|t_slot
operator|*
name|cw
operator|/
literal|2
operator|)
expr_stmt|;
block|}
return|return
name|tt
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_RATE_SAMPLE_H */
end_comment

end_unit

