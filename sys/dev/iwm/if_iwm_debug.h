begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Adrian Chadd<adrian@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_IWM_DEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_IWM_DEBUG_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IWM_DEBUG
end_ifdef

begin_enum
enum|enum
block|{
name|IWM_DEBUG_XMIT
init|=
literal|0x00000001
block|,
comment|/* basic xmit operation */
name|IWM_DEBUG_RECV
init|=
literal|0x00000002
block|,
comment|/* basic recv operation */
name|IWM_DEBUG_STATE
init|=
literal|0x00000004
block|,
comment|/* 802.11 state transitions */
name|IWM_DEBUG_TXPOW
init|=
literal|0x00000008
block|,
comment|/* tx power processing */
name|IWM_DEBUG_RESET
init|=
literal|0x00000010
block|,
comment|/* reset processing */
name|IWM_DEBUG_OPS
init|=
literal|0x00000020
block|,
comment|/* iwm_ops processing */
name|IWM_DEBUG_BEACON
init|=
literal|0x00000040
block|,
comment|/* beacon handling */
name|IWM_DEBUG_WATCHDOG
init|=
literal|0x00000080
block|,
comment|/* watchdog timeout */
name|IWM_DEBUG_INTR
init|=
literal|0x00000100
block|,
comment|/* ISR */
name|IWM_DEBUG_CALIBRATE
init|=
literal|0x00000200
block|,
comment|/* periodic calibration */
name|IWM_DEBUG_NODE
init|=
literal|0x00000400
block|,
comment|/* node management */
name|IWM_DEBUG_LED
init|=
literal|0x00000800
block|,
comment|/* led management */
name|IWM_DEBUG_CMD
init|=
literal|0x00001000
block|,
comment|/* cmd submission */
name|IWM_DEBUG_TXRATE
init|=
literal|0x00002000
block|,
comment|/* TX rate debugging */
name|IWM_DEBUG_PWRSAVE
init|=
literal|0x00004000
block|,
comment|/* Power save operations */
name|IWM_DEBUG_SCAN
init|=
literal|0x00008000
block|,
comment|/* Scan related operations */
name|IWM_DEBUG_STATS
init|=
literal|0x00010000
block|,
comment|/* Statistics updates */
name|IWM_DEBUG_FIRMWARE_TLV
init|=
literal|0x00020000
block|,
comment|/* Firmware TLV parsing */
name|IWM_DEBUG_TRANS
init|=
literal|0x00040000
block|,
comment|/* Transport layer (eg PCIe) */
name|IWM_DEBUG_EEPROM
init|=
literal|0x00080000
block|,
comment|/* EEPROM/channel information */
name|IWM_DEBUG_TEMP
init|=
literal|0x00100000
block|,
comment|/* Thermal Sensor handling */
name|IWM_DEBUG_FW
init|=
literal|0x00200000
block|,
comment|/* Firmware management */
name|IWM_DEBUG_LAR
init|=
literal|0x00400000
block|,
comment|/* Location Aware Regulatory */
name|IWM_DEBUG_REGISTER
init|=
literal|0x20000000
block|,
comment|/* print chipset register */
name|IWM_DEBUG_TRACE
init|=
literal|0x40000000
block|,
comment|/* Print begin and start driver function */
name|IWM_DEBUG_FATAL
init|=
literal|0x80000000
block|,
comment|/* fatal errors */
name|IWM_DEBUG_ANY
init|=
literal|0xffffffff
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (sc->sc_debug& (m))				\ 		device_printf(sc->sc_dev, fmt, ##__VA_ARGS__);	\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IWM_DPRINTF
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_IWM_DEBUG_H__ */
end_comment

end_unit

