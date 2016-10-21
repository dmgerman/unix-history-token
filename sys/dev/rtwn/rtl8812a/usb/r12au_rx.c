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
file|<net80211/ieee80211_ratectl.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/if_rtwnvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/r12a_fw_cmd.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/r12a_rx_desc.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/usb/r12au.h>
end_include

begin_function
name|int
name|r12au_classify_intr
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
name|uint32_t
name|rxdw2
init|=
name|le32toh
argument_list|(
name|stat
operator|->
name|rxdw2
argument_list|)
decl_stmt|;
if|if
condition|(
name|rxdw2
operator|&
name|R12A_RXDW2_RPT_C2H
condition|)
block|{
name|int
name|pos
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|r92c_rx_stat
argument_list|)
decl_stmt|;
comment|/* Check if Rx descriptor + command id/sequence fits. */
if|if
condition|(
name|len
operator|<
name|pos
operator|+
literal|2
condition|)
comment|/* unknown, skip */
return|return
operator|(
name|RTWN_RX_DATA
operator|)
return|;
if|if
condition|(
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|buf
operator|)
index|[
name|pos
index|]
operator|==
name|R12A_C2H_TX_REPORT
condition|)
return|return
operator|(
name|RTWN_RX_TX_REPORT
operator|)
return|;
else|else
return|return
operator|(
name|RTWN_RX_OTHER
operator|)
return|;
block|}
else|else
return|return
operator|(
name|RTWN_RX_DATA
operator|)
return|;
block|}
end_function

begin_function
name|int
name|r12au_align_rx
parameter_list|(
name|int
name|totlen
parameter_list|,
name|int
name|len
parameter_list|)
block|{
if|if
condition|(
name|totlen
operator|<
name|len
condition|)
return|return
operator|(
name|roundup2
argument_list|(
name|totlen
argument_list|,
literal|8
argument_list|)
operator|)
return|;
return|return
operator|(
name|totlen
operator|)
return|;
block|}
end_function

end_unit

