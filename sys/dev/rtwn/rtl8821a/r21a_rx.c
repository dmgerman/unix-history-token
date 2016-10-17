begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<dev/rtwn/if_rtwnvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/r12a_rx_desc.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8821a/r21a.h>
end_include

begin_function
name|int8_t
name|r21a_get_rssi_cck
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
name|struct
name|r12a_rx_phystat
modifier|*
name|stat
init|=
operator|(
expr|struct
name|r12a_rx_phystat
operator|*
operator|)
name|physt
decl_stmt|;
name|int8_t
name|lna_idx
decl_stmt|,
name|rssi
decl_stmt|;
name|lna_idx
operator|=
operator|(
name|stat
operator|->
name|cfosho
index|[
literal|0
index|]
operator|&
literal|0xe0
operator|)
operator|>>
literal|5
expr_stmt|;
name|rssi
operator|=
operator|-
literal|6
operator|-
literal|2
operator|*
operator|(
name|stat
operator|->
name|cfosho
index|[
literal|0
index|]
operator|&
literal|0x1f
operator|)
expr_stmt|;
comment|/* Pout - (2 * VGA_idx) */
switch|switch
condition|(
name|lna_idx
condition|)
block|{
case|case
literal|5
case|:
name|rssi
operator|-=
literal|32
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|rssi
operator|-=
literal|24
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|rssi
operator|-=
literal|11
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|rssi
operator|+=
literal|5
expr_stmt|;
break|break;
case|case
literal|0
case|:
name|rssi
operator|+=
literal|21
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|rssi
operator|)
return|;
block|}
end_function

end_unit

