begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 Weongyo Jeong<weongyo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_BWN_DEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_BWN_DEBUG_H__
end_define

begin_define
define|#
directive|define
name|BWN_DEBUG
end_define

begin_enum
enum|enum
block|{
name|BWN_DEBUG_XMIT
init|=
literal|0x00000001
block|,
comment|/* basic xmit operation */
name|BWN_DEBUG_RECV
init|=
literal|0x00000002
block|,
comment|/* basic recv operation */
name|BWN_DEBUG_STATE
init|=
literal|0x00000004
block|,
comment|/* 802.11 state transitions */
name|BWN_DEBUG_TXPOW
init|=
literal|0x00000008
block|,
comment|/* tx power processing */
name|BWN_DEBUG_RESET
init|=
literal|0x00000010
block|,
comment|/* reset processing */
name|BWN_DEBUG_OPS
init|=
literal|0x00000020
block|,
comment|/* bwn_ops processing */
name|BWN_DEBUG_BEACON
init|=
literal|0x00000040
block|,
comment|/* beacon handling */
name|BWN_DEBUG_WATCHDOG
init|=
literal|0x00000080
block|,
comment|/* watchdog timeout */
name|BWN_DEBUG_INTR
init|=
literal|0x00000100
block|,
comment|/* ISR */
name|BWN_DEBUG_CALIBRATE
init|=
literal|0x00000200
block|,
comment|/* periodic calibration */
name|BWN_DEBUG_NODE
init|=
literal|0x00000400
block|,
comment|/* node management */
name|BWN_DEBUG_LED
init|=
literal|0x00000800
block|,
comment|/* led management */
name|BWN_DEBUG_CMD
init|=
literal|0x00001000
block|,
comment|/* cmd submission */
name|BWN_DEBUG_LO
init|=
literal|0x00002000
block|,
comment|/* LO */
name|BWN_DEBUG_FW
init|=
literal|0x00004000
block|,
comment|/* firmware */
name|BWN_DEBUG_WME
init|=
literal|0x00008000
block|,
comment|/* WME */
name|BWN_DEBUG_RF
init|=
literal|0x00010000
block|,
comment|/* RF */
name|BWN_DEBUG_XMIT_POWER
init|=
literal|0x00020000
block|,
name|BWN_DEBUG_PHY
init|=
literal|0x00040000
block|,
name|BWN_DEBUG_EEPROM
init|=
literal|0x00080000
block|,
name|BWN_DEBUG_FATAL
init|=
literal|0x80000000
block|,
comment|/* fatal errors */
name|BWN_DEBUG_ANY
init|=
literal|0xffffffff
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|BWN_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (sc->sc_debug& (m))				\ 		printf(fmt, __VA_ARGS__);		\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BWN_DEBUG */
end_comment

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do { (void) sc; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BWN_DEBUG */
end_comment

begin_define
define|#
directive|define
name|BWN_ERRPRINTF
parameter_list|(
name|sc
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 		printf(__VA_ARGS__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|BWN_DBGPRINTF
parameter_list|(
name|sc
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 		printf(__VA_ARGS__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|BWN_WARNPRINTF
parameter_list|(
name|sc
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 		printf(__VA_ARGS__);		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_BWN_DEBUG_H__ */
end_comment

end_unit

