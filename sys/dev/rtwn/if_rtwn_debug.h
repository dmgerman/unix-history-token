begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_urtwn.c,v 1.16 2011/02/10 17:26:40 jakemsr Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2014 Kevin Lo<kevlo@FreeBSD.org>  * Copyright (c) 2015-2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IF_RTWN_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|IF_RTWN_DEBUG_H
end_define

begin_include
include|#
directive|include
file|"opt_rtwn.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RTWN_DEBUG
end_ifdef

begin_enum
enum|enum
block|{
name|RTWN_DEBUG_XMIT
init|=
literal|0x00000001
block|,
comment|/* basic xmit operation */
name|RTWN_DEBUG_XMIT_DESC
init|=
literal|0x00000002
block|,
comment|/* xmit descriptors */
name|RTWN_DEBUG_RECV
init|=
literal|0x00000004
block|,
comment|/* basic recv operation */
name|RTWN_DEBUG_RECV_DESC
init|=
literal|0x00000008
block|,
comment|/* recv descriptors */
name|RTWN_DEBUG_STATE
init|=
literal|0x00000010
block|,
comment|/* 802.11 state transitions */
name|RTWN_DEBUG_RA
init|=
literal|0x00000020
block|,
comment|/* f/w rate adaptation setup */
name|RTWN_DEBUG_USB
init|=
literal|0x00000040
block|,
comment|/* usb requests */
name|RTWN_DEBUG_FIRMWARE
init|=
literal|0x00000080
block|,
comment|/* firmware(9) loading debug */
name|RTWN_DEBUG_BEACON
init|=
literal|0x00000100
block|,
comment|/* beacon handling */
name|RTWN_DEBUG_INTR
init|=
literal|0x00000200
block|,
comment|/* ISR */
name|RTWN_DEBUG_TEMP
init|=
literal|0x00000400
block|,
comment|/* temperature calibration */
name|RTWN_DEBUG_ROM
init|=
literal|0x00000800
block|,
comment|/* various ROM info */
name|RTWN_DEBUG_KEY
init|=
literal|0x00001000
block|,
comment|/* crypto keys management */
name|RTWN_DEBUG_TXPWR
init|=
literal|0x00002000
block|,
comment|/* dump Tx power values */
name|RTWN_DEBUG_RSSI
init|=
literal|0x00004000
block|,
comment|/* dump RSSI lookups */
name|RTWN_DEBUG_RESET
init|=
literal|0x00008000
block|,
comment|/* initialization progress */
name|RTWN_DEBUG_CALIB
init|=
literal|0x00010000
block|,
comment|/* calibration progress */
name|RTWN_DEBUG_RADAR
init|=
literal|0x00020000
block|,
comment|/* radar detection status */
name|RTWN_DEBUG_ANY
init|=
literal|0xffffffff
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|RTWN_DPRINTF
parameter_list|(
name|_sc
parameter_list|,
name|_m
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if ((_sc)->sc_debug& (_m))				\ 		device_printf((_sc)->sc_dev, __VA_ARGS__);	\ } while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RTWN_DPRINTF
parameter_list|(
name|_sc
parameter_list|,
name|_m
parameter_list|,
modifier|...
parameter_list|)
value|do { (void) _sc; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_RTWN_DEBUG_H */
end_comment

end_unit

