begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2014, 2017 Kevin Lo<kevlo@FreeBSD.org>  * Copyright (c) 2015-2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<net80211/ieee80211_ratectl.h>
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
file|<dev/rtwn/if_rtwn_debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/if_rtwn_ridx.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8188e/r88e.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192e/r92e.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_rx_desc.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/r12a_fw_cmd.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
end_ifndef

begin_function
name|void
name|r92e_handle_c2h_report
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
block|{
comment|/* Skip Rx descriptor. */
name|buf
operator|+=
sizeof|sizeof
argument_list|(
expr|struct
name|r92c_rx_stat
argument_list|)
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
expr|struct
name|r92c_rx_stat
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|<
literal|2
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"C2H report too short (len %d)\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return;
block|}
name|len
operator|-=
literal|2
expr_stmt|;
switch|switch
condition|(
name|buf
index|[
literal|0
index|]
condition|)
block|{
comment|/* command id */
case|case
name|R12A_C2H_TX_REPORT
case|:
comment|/* NOTREACHED */
name|KASSERT
argument_list|(
literal|0
argument_list|,
operator|(
literal|"use handle_tx_report() instead of %s\n"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|r92e_handle_c2h_report
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
block|{
comment|/* Should not happen. */
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: called\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int8_t
name|r92e_get_rssi_cck
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|void
modifier|*
name|physt
parameter_list|)
block|{
return|return
operator|(
literal|10
operator|+
name|r88e_get_rssi_cck
argument_list|(
name|sc
argument_list|,
name|physt
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

