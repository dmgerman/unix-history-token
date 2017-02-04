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
name|int
name|r92c_llt_write
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
name|data
parameter_list|)
block|{
name|int
name|ntries
decl_stmt|,
name|error
decl_stmt|;
name|error
operator|=
name|rtwn_write_4
argument_list|(
name|sc
argument_list|,
name|R92C_LLT_INIT
argument_list|,
name|SM
argument_list|(
name|R92C_LLT_INIT_OP
argument_list|,
name|R92C_LLT_INIT_OP_WRITE
argument_list|)
operator||
name|SM
argument_list|(
name|R92C_LLT_INIT_ADDR
argument_list|,
name|addr
argument_list|)
operator||
name|SM
argument_list|(
name|R92C_LLT_INIT_DATA
argument_list|,
name|data
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* Wait for write operation to complete. */
for|for
control|(
name|ntries
operator|=
literal|0
init|;
name|ntries
operator|<
literal|20
condition|;
name|ntries
operator|++
control|)
block|{
if|if
condition|(
name|MS
argument_list|(
name|rtwn_read_4
argument_list|(
name|sc
argument_list|,
name|R92C_LLT_INIT
argument_list|)
argument_list|,
name|R92C_LLT_INIT_OP
argument_list|)
operator|==
name|R92C_LLT_INIT_OP_NO_ACTIVE
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|rtwn_delay
argument_list|(
name|sc
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ETIMEDOUT
operator|)
return|;
block|}
end_function

end_unit

