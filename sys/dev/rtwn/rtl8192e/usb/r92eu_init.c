begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Kevin Lo<kevlo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<dev/rtwn/rtl8192e/r92e_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192e/usb/r92eu.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192e/usb/r92eu_reg.h>
end_include

begin_function
name|void
name|r92eu_init_rx_agg
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|r92e_softc
modifier|*
name|rs
init|=
name|sc
operator|->
name|sc_priv
decl_stmt|;
comment|/* Rx aggregation (USB). */
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
name|rtwn_write_4
argument_list|(
name|sc
argument_list|,
name|R92C_RXDMA_AGG_PG_TH
argument_list|,
name|rs
operator|->
name|ac_usb_dma_size
operator||
operator|(
name|rs
operator|->
name|ac_usb_dma_time
operator|<<
literal|8
operator|)
argument_list|)
expr_stmt|;
name|rtwn_setbits_1
argument_list|(
name|sc
argument_list|,
name|R92C_TRXDMA_CTRL
argument_list|,
literal|0
argument_list|,
name|R92C_TRXDMA_CTRL_RXDMA_AGG_EN
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|r92eu_post_init
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* Setup RTS BW (equal to data BW). */
name|rtwn_setbits_1
argument_list|(
name|sc
argument_list|,
name|R92C_QUEUE_CTRL
argument_list|,
literal|0x08
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Reset USB mode switch setting. */
name|rtwn_write_1
argument_list|(
name|sc
argument_list|,
name|R92C_ACLK_MON
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|rtwn_write_1
argument_list|(
name|sc
argument_list|,
name|R92C_USB_HRPWM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
if|if
condition|(
name|sc
operator|->
name|sc_flags
operator|&
name|RTWN_FW_LOADED
condition|)
block|{
if|if
condition|(
name|sc
operator|->
name|sc_ratectl_sysctl
operator|==
name|RTWN_RATECTL_FW
condition|)
block|{
comment|/* TODO: implement */
name|sc
operator|->
name|sc_ratectl
operator|=
name|RTWN_RATECTL_NET80211
expr_stmt|;
block|}
else|else
name|sc
operator|->
name|sc_ratectl
operator|=
name|sc
operator|->
name|sc_ratectl_sysctl
expr_stmt|;
block|}
else|else
endif|#
directive|endif
name|sc
operator|->
name|sc_ratectl
operator|=
name|RTWN_RATECTL_NONE
expr_stmt|;
block|}
end_function

end_unit

