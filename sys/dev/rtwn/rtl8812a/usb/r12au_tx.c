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
file|<dev/rtwn/if_rtwn_debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/usb/r12au.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/usb/r12au_tx_desc.h>
end_include

begin_function
name|void
name|r12au_dump_tx_desc
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
specifier|const
name|void
modifier|*
name|desc
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|RTWN_DEBUG
specifier|const
name|struct
name|r12au_tx_desc
modifier|*
name|txd
init|=
name|desc
decl_stmt|;
name|RTWN_DPRINTF
argument_list|(
name|sc
argument_list|,
name|RTWN_DEBUG_XMIT_DESC
argument_list|,
literal|"%s: len %d, off %d, flags0 %02X, dw: 1 %08X, 2 %08X, 3 %08X, "
literal|"4 %08X, 5 %08X, 6 %08X, sum %04X, flags7 %04X, 8 %08X, 9 %08X\n"
argument_list|,
name|__func__
argument_list|,
name|le16toh
argument_list|(
name|txd
operator|->
name|pktlen
argument_list|)
argument_list|,
name|txd
operator|->
name|offset
argument_list|,
name|txd
operator|->
name|flags0
argument_list|,
name|le32toh
argument_list|(
name|txd
operator|->
name|txdw1
argument_list|)
argument_list|,
name|le32toh
argument_list|(
name|txd
operator|->
name|txdw2
argument_list|)
argument_list|,
name|le32toh
argument_list|(
name|txd
operator|->
name|txdw3
argument_list|)
argument_list|,
name|le32toh
argument_list|(
name|txd
operator|->
name|txdw4
argument_list|)
argument_list|,
name|le32toh
argument_list|(
name|txd
operator|->
name|txdw5
argument_list|)
argument_list|,
name|le32toh
argument_list|(
name|txd
operator|->
name|txdw6
argument_list|)
argument_list|,
name|le16toh
argument_list|(
name|txd
operator|->
name|txdsum
argument_list|)
argument_list|,
name|le16toh
argument_list|(
name|txd
operator|->
name|flags7
argument_list|)
argument_list|,
name|le32toh
argument_list|(
name|txd
operator|->
name|txdw8
argument_list|)
argument_list|,
name|le32toh
argument_list|(
name|txd
operator|->
name|txdw9
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

