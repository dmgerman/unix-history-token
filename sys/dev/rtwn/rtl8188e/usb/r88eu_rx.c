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
file|<dev/rtwn/if_rtwn_debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8188e/r88e_rx_desc.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8188e/usb/r88eu.h>
end_include

begin_function
name|int
name|r88eu_classify_intr
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
block|{
name|struct
name|r92c_rx_stat
modifier|*
name|stat
init|=
name|buf
decl_stmt|;
name|int
name|report_sel
init|=
name|MS
argument_list|(
name|le32toh
argument_list|(
name|stat
operator|->
name|rxdw3
argument_list|)
argument_list|,
name|R88E_RXDW3_RPT
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|report_sel
condition|)
block|{
case|case
name|R88E_RXDW3_RPT_RX
case|:
return|return
operator|(
name|RTWN_RX_DATA
operator|)
return|;
case|case
name|R88E_RXDW3_RPT_TX1
case|:
comment|/* per-packet Tx report */
case|case
name|R88E_RXDW3_RPT_TX2
case|:
comment|/* periodical Tx report */
return|return
operator|(
name|RTWN_RX_TX_REPORT
operator|)
return|;
case|case
name|R88E_RXDW3_RPT_HIS
case|:
return|return
operator|(
name|RTWN_RX_OTHER
operator|)
return|;
default|default:
comment|/* shut up the compiler */
return|return
operator|(
name|RTWN_RX_DATA
operator|)
return|;
block|}
block|}
end_function

end_unit

