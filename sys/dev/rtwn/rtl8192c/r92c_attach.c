begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_urtwn.c,v 1.16 2011/02/10 17:26:40 jakemsr Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2014 Kevin Lo<kevlo@FreeBSD.org>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<dev/rtwn/rtl8192c/r92c.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_var.h>
end_include

begin_function
name|void
name|r92c_detach_private
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|r92c_softc
modifier|*
name|rs
init|=
name|sc
operator|->
name|sc_priv
decl_stmt|;
name|free
argument_list|(
name|rs
argument_list|,
name|M_RTWN_PRIV
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|r92c_read_chipid_vendor
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg_sys_cfg
parameter_list|)
block|{
name|struct
name|r92c_softc
modifier|*
name|rs
init|=
name|sc
operator|->
name|sc_priv
decl_stmt|;
if|if
condition|(
name|reg_sys_cfg
operator|&
name|R92C_SYS_CFG_TYPE_92C
condition|)
block|{
name|rs
operator|->
name|chip
operator||=
name|R92C_CHIP_92C
expr_stmt|;
comment|/* Check if it is a castrated 8192C. */
if|if
condition|(
name|MS
argument_list|(
name|rtwn_read_4
argument_list|(
name|sc
argument_list|,
name|R92C_HPON_FSM
argument_list|)
argument_list|,
name|R92C_HPON_FSM_CHIP_BONDING_ID
argument_list|)
operator|==
name|R92C_HPON_FSM_CHIP_BONDING_ID_92C_1T2R
condition|)
name|rs
operator|->
name|chip
operator||=
name|R92C_CHIP_92C_1T2R
expr_stmt|;
block|}
if|if
condition|(
name|reg_sys_cfg
operator|&
name|R92C_SYS_CFG_VENDOR_UMC
condition|)
block|{
if|if
condition|(
name|MS
argument_list|(
name|reg_sys_cfg
argument_list|,
name|R92C_SYS_CFG_CHIP_VER_RTL
argument_list|)
operator|==
literal|0
condition|)
name|rs
operator|->
name|chip
operator||=
name|R92C_CHIP_UMC_A_CUT
expr_stmt|;
block|}
block|}
end_function

end_unit

