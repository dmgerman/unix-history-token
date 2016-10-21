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
file|<dev/rtwn/rtl8812a/r12a.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/r12a_tx_desc.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8821a/r21a.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8821a/r21a_reg.h>
end_include

begin_function
name|void
name|r21a_beacon_init
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
name|id
parameter_list|)
block|{
name|struct
name|r12a_tx_desc
modifier|*
name|txd
init|=
operator|(
expr|struct
name|r12a_tx_desc
operator|*
operator|)
name|buf
decl_stmt|;
name|r12a_beacon_init
argument_list|(
name|sc
argument_list|,
name|buf
argument_list|,
name|id
argument_list|)
expr_stmt|;
comment|/* XXX sequence number for beacon 1 is not stable. */
name|txd
operator|->
name|txdw3
operator|&=
operator|~
name|htole32
argument_list|(
name|R12A_TXDW3_SEQ_SEL_M
argument_list|)
expr_stmt|;
name|txd
operator|->
name|txdw3
operator||=
name|htole32
argument_list|(
name|SM
argument_list|(
name|R12A_TXDW3_SEQ_SEL
argument_list|,
name|id
operator|*
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|r21a_beacon_select
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|int
name|id
parameter_list|)
block|{
switch|switch
condition|(
name|id
condition|)
block|{
case|case
literal|0
case|:
comment|/* Switch to port 0 beacon. */
name|rtwn_setbits_1_shift
argument_list|(
name|sc
argument_list|,
name|R21A_DWBCN1_CTRL
argument_list|,
name|R21A_DWBCN1_CTRL_SEL_BCN1
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|/* Switch to port 1 beacon. */
name|rtwn_setbits_1_shift
argument_list|(
name|sc
argument_list|,
name|R21A_DWBCN1_CTRL
argument_list|,
literal|0
argument_list|,
name|R21A_DWBCN1_CTRL_SEL_BCN1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
break|break;
default|default:
name|KASSERT
argument_list|(
literal|0
argument_list|,
operator|(
literal|"wrong port id %d\n"
operator|,
name|id
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

end_unit

