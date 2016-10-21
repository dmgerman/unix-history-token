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
file|<dev/rtwn/usb/rtwn_usb_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/usb/r92cu.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8821a/usb/r21au.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8821a/usb/r21au_reg.h>
end_include

begin_function
name|void
name|r21au_init_tx_agg
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|rtwn_usb_softc
modifier|*
name|uc
init|=
name|RTWN_USB_SOFTC
argument_list|(
name|sc
argument_list|)
decl_stmt|;
name|r92cu_init_tx_agg
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|rtwn_write_1
argument_list|(
name|sc
argument_list|,
name|R21A_DWBCN1_CTRL
argument_list|,
name|uc
operator|->
name|tx_agg_desc_num
operator|<<
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|r21au_init_burstlen
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
if|if
condition|(
operator|(
name|rtwn_read_1
argument_list|(
name|sc
argument_list|,
name|R92C_USB_INFO
argument_list|)
operator|&
literal|0x30
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Set burst packet length to 512 B. */
name|rtwn_setbits_1
argument_list|(
name|sc
argument_list|,
name|R12A_RXDMA_PRO
argument_list|,
literal|0x20
argument_list|,
literal|0x1e
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Set burst packet length to 64 B. */
name|rtwn_setbits_1
argument_list|(
name|sc
argument_list|,
name|R12A_RXDMA_PRO
argument_list|,
literal|0x10
argument_list|,
literal|0x2e
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

