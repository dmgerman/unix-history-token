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
file|<dev/rtwn/rtl8812a/r12a.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/r12a_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/r12a_rom_image.h>
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
name|r21a_parse_rom
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|)
block|{
name|struct
name|r12a_softc
modifier|*
name|rs
init|=
name|sc
operator|->
name|sc_priv
decl_stmt|;
name|struct
name|r12a_rom
modifier|*
name|rom
init|=
operator|(
expr|struct
name|r12a_rom
operator|*
operator|)
name|buf
decl_stmt|;
name|uint8_t
name|pa_type
decl_stmt|,
name|lna_type_2g
decl_stmt|,
name|lna_type_5g
decl_stmt|;
comment|/* Read PA/LNA types. */
name|pa_type
operator|=
name|RTWN_GET_ROM_VAR
argument_list|(
name|rom
operator|->
name|pa_type
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|lna_type_2g
operator|=
name|RTWN_GET_ROM_VAR
argument_list|(
name|rom
operator|->
name|lna_type_2g
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|lna_type_5g
operator|=
name|RTWN_GET_ROM_VAR
argument_list|(
name|rom
operator|->
name|lna_type_5g
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|rs
operator|->
name|ext_pa_2g
operator|=
name|R21A_ROM_IS_PA_EXT_2GHZ
argument_list|(
name|pa_type
argument_list|)
expr_stmt|;
name|rs
operator|->
name|ext_pa_5g
operator|=
name|R21A_ROM_IS_PA_EXT_5GHZ
argument_list|(
name|pa_type
argument_list|)
expr_stmt|;
name|rs
operator|->
name|ext_lna_2g
operator|=
name|R21A_ROM_IS_LNA_EXT
argument_list|(
name|lna_type_2g
argument_list|)
expr_stmt|;
name|rs
operator|->
name|ext_lna_5g
operator|=
name|R21A_ROM_IS_LNA_EXT
argument_list|(
name|lna_type_5g
argument_list|)
expr_stmt|;
name|RTWN_LOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|rs
operator|->
name|bt_coex
operator|=
operator|!
operator|!
operator|(
name|rtwn_read_4
argument_list|(
name|sc
argument_list|,
name|R92C_MULTI_FUNC_CTRL
argument_list|)
operator|&
name|R92C_MULTI_BT_FUNC_EN
operator|)
expr_stmt|;
name|RTWN_UNLOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|rs
operator|->
name|bt_ant_num
operator|=
operator|(
name|rom
operator|->
name|rf_bt_opt
operator|&
name|R12A_RF_BT_OPT_ANT_NUM
operator|)
expr_stmt|;
comment|/* Read MAC address. */
name|IEEE80211_ADDR_COPY
argument_list|(
name|sc
operator|->
name|sc_ic
operator|.
name|ic_macaddr
argument_list|,
name|rom
operator|->
name|macaddr_21a
argument_list|)
expr_stmt|;
comment|/* Execute common part of initialization. */
name|r12a_parse_rom_common
argument_list|(
name|sc
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

