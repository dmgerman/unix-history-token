begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_urtwn.c,v 1.16 2011/02/10 17:26:40 jakemsr Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2014 Kevin Lo<kevlo@FreeBSD.org>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<sys/linker.h>
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
file|<dev/rtwn/if_rtwnreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/if_rtwnvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_reg.h>
end_include

begin_function
name|void
name|r92c_iq_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* XXX TODO */
block|}
end_function

begin_function
name|void
name|r92c_lc_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
name|uint32_t
name|rf_ac
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|txmode
decl_stmt|;
name|int
name|i
decl_stmt|;
name|txmode
operator|=
name|rtwn_read_1
argument_list|(
name|sc
argument_list|,
name|R92C_OFDM1_LSTF
operator|+
literal|3
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|txmode
operator|&
literal|0x70
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* Disable all continuous Tx. */
name|rtwn_write_1
argument_list|(
name|sc
argument_list|,
name|R92C_OFDM1_LSTF
operator|+
literal|3
argument_list|,
name|txmode
operator|&
operator|~
literal|0x70
argument_list|)
expr_stmt|;
comment|/* Set RF mode to standby mode. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|sc
operator|->
name|nrxchains
condition|;
name|i
operator|++
control|)
block|{
name|rf_ac
index|[
name|i
index|]
operator|=
name|rtwn_rf_read
argument_list|(
name|sc
argument_list|,
name|i
argument_list|,
name|R92C_RF_AC
argument_list|)
expr_stmt|;
name|rtwn_rf_write
argument_list|(
name|sc
argument_list|,
name|i
argument_list|,
name|R92C_RF_AC
argument_list|,
name|RW
argument_list|(
name|rf_ac
index|[
name|i
index|]
argument_list|,
name|R92C_RF_AC_MODE
argument_list|,
name|R92C_RF_AC_MODE_STANDBY
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Block all Tx queues. */
name|rtwn_write_1
argument_list|(
name|sc
argument_list|,
name|R92C_TXPAUSE
argument_list|,
name|R92C_TX_QUEUE_ALL
argument_list|)
expr_stmt|;
block|}
comment|/* Start calibration. */
name|rtwn_rf_setbits
argument_list|(
name|sc
argument_list|,
literal|0
argument_list|,
name|R92C_RF_CHNLBW
argument_list|,
literal|0
argument_list|,
name|R92C_RF_CHNLBW_LCSTART
argument_list|)
expr_stmt|;
comment|/* Give calibration the time to complete. */
name|rtwn_delay
argument_list|(
name|sc
argument_list|,
literal|100000
argument_list|)
expr_stmt|;
comment|/* 100ms */
comment|/* Restore configuration. */
if|if
condition|(
operator|(
name|txmode
operator|&
literal|0x70
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* Restore Tx mode. */
name|rtwn_write_1
argument_list|(
name|sc
argument_list|,
name|R92C_OFDM1_LSTF
operator|+
literal|3
argument_list|,
name|txmode
argument_list|)
expr_stmt|;
comment|/* Restore RF mode. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|sc
operator|->
name|nrxchains
condition|;
name|i
operator|++
control|)
name|rtwn_rf_write
argument_list|(
name|sc
argument_list|,
name|i
argument_list|,
name|R92C_RF_AC
argument_list|,
name|rf_ac
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Unblock all Tx queues. */
name|rtwn_write_1
argument_list|(
name|sc
argument_list|,
name|R92C_TXPAUSE
argument_list|,
literal|0x00
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|r92c_temp_measure
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
name|rtwn_rf_write
argument_list|(
name|sc
argument_list|,
literal|0
argument_list|,
name|R92C_RF_T_METER
argument_list|,
name|R92C_RF_T_METER_START
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|uint8_t
name|r92c_temp_read
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
operator|(
name|MS
argument_list|(
name|rtwn_rf_read
argument_list|(
name|sc
argument_list|,
literal|0
argument_list|,
name|R92C_RF_T_METER
argument_list|)
argument_list|,
name|R92C_RF_T_METER_VAL
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

