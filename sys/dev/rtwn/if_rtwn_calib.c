begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_urtwn.c,v 1.16 2011/02/10 17:26:40 jakemsr Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2014 Kevin Lo<kevlo@FreeBSD.org>  * Copyright (c) 2015-2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<sys/mbuf.h>
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
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
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_radiotap.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/if_rtwnvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/if_rtwn_calib.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/if_rtwn_debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/if_rtwn_task.h>
end_include

begin_function
specifier|static
name|void
name|rtwn_temp_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
name|uint8_t
name|temp
decl_stmt|;
name|RTWN_ASSERT_LOCKED
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|sc
operator|->
name|sc_flags
operator|&
name|RTWN_TEMP_MEASURED
operator|)
condition|)
block|{
comment|/* Start measuring temperature. */
name|RTWN_DPRINTF
argument_list|(
name|sc
argument_list|,
name|RTWN_DEBUG_TEMP
argument_list|,
literal|"%s: start measuring temperature\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
name|rtwn_temp_measure
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_flags
operator||=
name|RTWN_TEMP_MEASURED
expr_stmt|;
return|return;
block|}
name|sc
operator|->
name|sc_flags
operator|&=
operator|~
name|RTWN_TEMP_MEASURED
expr_stmt|;
comment|/* Read measured temperature. */
name|temp
operator|=
name|rtwn_temp_read
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
name|temp
operator|==
literal|0
condition|)
block|{
comment|/* Read failed, skip. */
name|RTWN_DPRINTF
argument_list|(
name|sc
argument_list|,
name|RTWN_DEBUG_TEMP
argument_list|,
literal|"%s: temperature read failed, skipping\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return;
block|}
name|RTWN_DPRINTF
argument_list|(
name|sc
argument_list|,
name|RTWN_DEBUG_TEMP
argument_list|,
literal|"temperature: previous %u, current %u\n"
argument_list|,
name|sc
operator|->
name|thcal_temp
argument_list|,
name|temp
argument_list|)
expr_stmt|;
comment|/* 	 * Redo LC/IQ calibration if temperature changed significantly since 	 * last calibration. 	 */
if|if
condition|(
name|sc
operator|->
name|thcal_temp
operator|==
literal|0xff
condition|)
block|{
comment|/* efuse value is absent; do LCK at initial status. */
name|rtwn_lc_calib
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sc
operator|->
name|thcal_temp
operator|=
name|temp
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|abs
argument_list|(
name|temp
operator|-
name|sc
operator|->
name|thcal_temp
argument_list|)
operator|>
name|sc
operator|->
name|temp_delta
condition|)
block|{
name|RTWN_DPRINTF
argument_list|(
name|sc
argument_list|,
name|RTWN_DEBUG_TEMP
argument_list|,
literal|"%s: LC/IQ calib triggered by temp: %u -> %u\n"
argument_list|,
name|__func__
argument_list|,
name|sc
operator|->
name|thcal_temp
argument_list|,
name|temp
argument_list|)
expr_stmt|;
name|rtwn_lc_calib
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|rtwn_iq_calib
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* Record temperature of last calibration. */
name|sc
operator|->
name|thcal_temp
operator|=
name|temp
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|rtwn_calib_cb
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|union
name|sec_param
modifier|*
name|data
parameter_list|)
block|{
comment|/* Do temperature compensation. */
name|rtwn_temp_calib
argument_list|(
name|sc
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
if|if
condition|(
name|sc
operator|->
name|sc_ratectl
operator|==
name|RTWN_RATECTL_FW
condition|)
block|{
comment|/* Refresh per-node RSSI. */
name|rtwn_set_rssi
argument_list|(
name|sc
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|sc
operator|->
name|vaps_running
operator|>
name|sc
operator|->
name|monvaps_running
condition|)
name|callout_reset
argument_list|(
operator|&
name|sc
operator|->
name|sc_calib_to
argument_list|,
literal|2
operator|*
name|hz
argument_list|,
name|rtwn_calib_to
argument_list|,
name|sc
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|rtwn_calib_to
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|rtwn_softc
modifier|*
name|sc
init|=
name|arg
decl_stmt|;
comment|/* Do it in a process context. */
name|rtwn_cmd_sleepable
argument_list|(
name|sc
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|rtwn_calib_cb
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

