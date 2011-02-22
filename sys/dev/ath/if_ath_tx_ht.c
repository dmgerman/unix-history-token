begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Adrian Chadd, Xenion Pty Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_ath.h"
end_include

begin_include
include|#
directive|include
file|"opt_wlan.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_llc.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_regdomain.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE80211_SUPPORT_SUPERG
end_ifdef

begin_include
include|#
directive|include
file|<net80211/ieee80211_superg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE80211_SUPPORT_TDMA
end_ifdef

begin_include
include|#
directive|include
file|<net80211/ieee80211_tdma.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/ath/if_athvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah_devid.h>
end_include

begin_comment
comment|/* XXX for softled */
end_comment

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah_diagcodes.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_TX99_DIAG
end_ifdef

begin_include
include|#
directive|include
file|<dev/ath/ath_tx99/ath_tx99.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/ath/if_ath_tx_ht.h>
end_include

begin_comment
comment|/*  * Setup a 11n rate series structure  *  * This should be called for both legacy and MCS rates.  */
end_comment

begin_function
specifier|static
name|void
name|ath_rateseries_setup
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|HAL_11N_RATE_SERIES
modifier|*
name|series
parameter_list|,
name|unsigned
name|int
name|pktlen
parameter_list|,
name|uint8_t
modifier|*
name|rix
parameter_list|,
name|uint8_t
modifier|*
name|try
parameter_list|)
block|{
name|struct
name|ieee80211com
modifier|*
name|ic
init|=
name|ni
operator|->
name|ni_ic
decl_stmt|;
name|struct
name|ath_hal
modifier|*
name|ah
init|=
name|sc
operator|->
name|sc_ah
decl_stmt|;
name|HAL_BOOL
name|shortPreamble
init|=
name|AH_FALSE
decl_stmt|;
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
name|i
decl_stmt|;
if|if
condition|(
operator|(
name|ic
operator|->
name|ic_flags
operator|&
name|IEEE80211_F_SHPREAMBLE
operator|)
operator|&&
operator|(
name|ni
operator|->
name|ni_capinfo
operator|&
name|IEEE80211_CAPINFO_SHORT_PREAMBLE
operator|)
condition|)
name|shortPreamble
operator|=
name|AH_TRUE
expr_stmt|;
name|memset
argument_list|(
name|series
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|HAL_11N_RATE_SERIES
argument_list|)
operator|*
literal|4
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
name|i
operator|++
control|)
block|{
comment|/* Only set flags for actual TX attempts */
if|if
condition|(
name|try
index|[
name|i
index|]
operator|==
literal|0
condition|)
continue|continue;
name|series
index|[
name|i
index|]
operator|.
name|Tries
operator|=
name|try
index|[
name|i
index|]
expr_stmt|;
comment|/* 		 * XXX this isn't strictly correct - sc_txchainmask 		 * XXX isn't the currently active chainmask; 		 * XXX it's the interface chainmask at startup. 		 * XXX It's overridden in the HAL rate scenario function 		 * XXX for now. 		 */
name|series
index|[
name|i
index|]
operator|.
name|ChSel
operator|=
name|sc
operator|->
name|sc_txchainmask
expr_stmt|;
comment|/* 		 * This merely enables RTS or RTS/CTS for the given scenario; 		 * it needs to be enabled elsewhere. 		 */
if|if
condition|(
name|ic
operator|->
name|ic_protmode
operator|==
name|IEEE80211_PROT_RTSCTS
operator|||
name|ic
operator|->
name|ic_protmode
operator|==
name|IEEE80211_PROT_CTSONLY
condition|)
name|series
index|[
name|i
index|]
operator|.
name|RateFlags
operator||=
name|HAL_RATESERIES_RTS_CTS
expr_stmt|;
if|if
condition|(
name|ni
operator|->
name|ni_htcap
operator|&
name|IEEE80211_HTCAP_CHWIDTH40
condition|)
name|series
index|[
name|i
index|]
operator|.
name|RateFlags
operator||=
name|HAL_RATESERIES_2040
expr_stmt|;
comment|/* 		 * The hardware only supports short-gi in 40mhz mode - 		 * if later hardware supports it in 20mhz mode, be sure 		 * to add the relevant check here. 		 */
if|if
condition|(
name|ni
operator|->
name|ni_htcap
operator|&
name|IEEE80211_HTCAP_SHORTGI40
condition|)
name|series
index|[
name|i
index|]
operator|.
name|RateFlags
operator||=
name|HAL_RATESERIES_HALFGI
expr_stmt|;
name|series
index|[
name|i
index|]
operator|.
name|Rate
operator|=
name|rt
operator|->
name|info
index|[
name|rix
index|[
name|i
index|]
index|]
operator|.
name|rateCode
expr_stmt|;
comment|/* the short preamble field is only applicable for non-MCS rates */
if|if
condition|(
name|shortPreamble
operator|&&
operator|!
operator|(
name|series
index|[
name|i
index|]
operator|.
name|Rate
operator|&
name|IEEE80211_RATE_MCS
operator|)
condition|)
name|series
index|[
name|i
index|]
operator|.
name|Rate
operator||=
name|rt
operator|->
name|info
index|[
name|rix
index|[
name|i
index|]
index|]
operator|.
name|shortPreamble
expr_stmt|;
comment|/* PktDuration doesn't include slot, ACK, RTS, etc timing - it's just the packet duration */
if|if
condition|(
name|series
index|[
name|i
index|]
operator|.
name|Rate
operator|&
name|IEEE80211_RATE_MCS
condition|)
block|{
name|series
index|[
name|i
index|]
operator|.
name|PktDuration
operator|=
name|ath_computedur_ht
argument_list|(
name|pktlen
argument_list|,
name|series
index|[
name|i
index|]
operator|.
name|Rate
argument_list|,
name|ic
operator|->
name|ic_txstream
argument_list|,
operator|(
name|ni
operator|->
name|ni_htcap
operator|&
name|IEEE80211_HTCAP_CHWIDTH40
operator|)
argument_list|,
name|series
index|[
name|i
index|]
operator|.
name|RateFlags
operator|&
name|HAL_RATESERIES_HALFGI
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|series
index|[
name|i
index|]
operator|.
name|PktDuration
operator|=
name|ath_hal_computetxtime
argument_list|(
name|ah
argument_list|,
name|rt
argument_list|,
name|pktlen
argument_list|,
name|rix
index|[
name|i
index|]
argument_list|,
name|shortPreamble
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static void ath_rateseries_print(HAL_11N_RATE_SERIES *series) { 	int i; 	for (i = 0; i< 4; i++) { 		printf("series %d: rate %x; tries %d; pktDuration %d; chSel %d; rateFlags %x\n", 		    i, 		    series[i].Rate, 		    series[i].Tries, 		    series[i].PktDuration, 		    series[i].ChSel, 		    series[i].RateFlags); 	} }
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Setup the 11n rate scenario and burst duration for the given TX descriptor  * list.  *  * This isn't useful for sending beacon frames, which has different needs  * wrt what's passed into the rate scenario function.  */
end_comment

begin_function
name|void
name|ath_buf_set_rate
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|,
name|int
name|pktlen
parameter_list|,
name|int
name|flags
parameter_list|,
name|uint8_t
name|ctsrate
parameter_list|,
name|int
name|is_pspoll
parameter_list|,
name|uint8_t
modifier|*
name|rix
parameter_list|,
name|uint8_t
modifier|*
name|try
parameter_list|)
block|{
name|HAL_11N_RATE_SERIES
name|series
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|ath_desc
modifier|*
name|ds
init|=
name|bf
operator|->
name|bf_desc
decl_stmt|;
name|struct
name|ath_desc
modifier|*
name|lastds
init|=
name|NULL
decl_stmt|;
name|struct
name|ath_hal
modifier|*
name|ah
init|=
name|sc
operator|->
name|sc_ah
decl_stmt|;
comment|/* Setup rate scenario */
name|memset
argument_list|(
operator|&
name|series
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|series
argument_list|)
argument_list|)
expr_stmt|;
name|ath_rateseries_setup
argument_list|(
name|sc
argument_list|,
name|ni
argument_list|,
name|series
argument_list|,
name|pktlen
argument_list|,
name|rix
argument_list|,
name|try
argument_list|)
expr_stmt|;
comment|/* Enforce AR5416 aggregate limit - can't do RTS w/ an agg frame> 8k */
comment|/* Enforce RTS and CTS are mutually exclusive */
comment|/* Get a pointer to the last tx descriptor in the list */
name|lastds
operator|=
operator|&
name|bf
operator|->
name|bf_desc
index|[
name|bf
operator|->
name|bf_nseg
operator|-
literal|1
index|]
expr_stmt|;
comment|/* Set rate scenario */
name|ath_hal_set11nratescenario
argument_list|(
name|ah
argument_list|,
name|ds
argument_list|,
operator|!
name|is_pspoll
argument_list|,
comment|/* whether to override the duration or not */
comment|/* don't allow hardware to override the duration on ps-poll packets */
name|ctsrate
argument_list|,
comment|/* rts/cts rate */
name|series
argument_list|,
comment|/* 11n rate series */
literal|4
argument_list|,
comment|/* number of series */
name|flags
argument_list|)
expr_stmt|;
comment|/* Setup the last descriptor in the chain */
name|ath_hal_setuplasttxdesc
argument_list|(
name|ah
argument_list|,
name|lastds
argument_list|,
name|ds
argument_list|)
expr_stmt|;
comment|/* Set burst duration */
comment|/* This should only be done if aggregate protection is enabled */
comment|//ath_hal_set11nburstduration(ah, ds, 8192);
block|}
end_function

end_unit

