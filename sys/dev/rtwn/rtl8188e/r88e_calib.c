begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<dev/rtwn/rtl8188e/r88e.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8188e/r88e_reg.h>
end_include

begin_function
name|void
name|r88e_iq_calib
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
name|r88e_temp_measure
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
name|R88E_RF_T_METER
argument_list|,
name|R88E_RF_T_METER_START
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|uint8_t
name|r88e_temp_read
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
name|R88E_RF_T_METER
argument_list|)
argument_list|,
name|R88E_RF_T_METER_VAL
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

