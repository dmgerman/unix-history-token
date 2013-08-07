begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Sam Leffler, Errno Consulting  * Copyright (c) 2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_DEBUG_H_
end_define

begin_comment
comment|/*  * Atheros Device Hardware Access Layer (HAL).  *  * Debug mask definitions.  */
end_comment

begin_enum
enum|enum
block|{
name|HAL_DEBUG_REGDOMAIN
init|=
literal|0x00000001
block|,
comment|/* regulatory handling */
name|HAL_DEBUG_ATTACH
init|=
literal|0x00000002
block|,
comment|/* work done in attach */
name|HAL_DEBUG_RESET
init|=
literal|0x00000004
block|,
comment|/* reset work */
name|HAL_DEBUG_NFCAL
init|=
literal|0x00000008
block|,
comment|/* noise floor calibration */
name|HAL_DEBUG_PERCAL
init|=
literal|0x00000010
block|,
comment|/* periodic calibration */
name|HAL_DEBUG_ANI
init|=
literal|0x00000020
block|,
comment|/* ANI operation */
name|HAL_DEBUG_PHYIO
init|=
literal|0x00000040
block|,
comment|/* phy i/o operations */
name|HAL_DEBUG_REGIO
init|=
literal|0x00000080
block|,
comment|/* register i/o operations */
name|HAL_DEBUG_RFPARAM
init|=
literal|0x00000100
block|,
name|HAL_DEBUG_TXQUEUE
init|=
literal|0x00000200
block|,
comment|/* tx queue handling */
name|HAL_DEBUG_TX
init|=
literal|0x00000400
block|,
name|HAL_DEBUG_TXDESC
init|=
literal|0x00000800
block|,
name|HAL_DEBUG_RX
init|=
literal|0x00001000
block|,
name|HAL_DEBUG_RXDESC
init|=
literal|0x00002000
block|,
name|HAL_DEBUG_KEYCACHE
init|=
literal|0x00004000
block|,
comment|/* keycache handling */
name|HAL_DEBUG_EEPROM
init|=
literal|0x00008000
block|,
name|HAL_DEBUG_BEACON
init|=
literal|0x00010000
block|,
comment|/* beacon setup work */
name|HAL_DEBUG_POWER
init|=
literal|0x00020000
block|,
comment|/* power management */
name|HAL_DEBUG_GPIO
init|=
literal|0x00040000
block|,
comment|/* GPIO debugging */
name|HAL_DEBUG_INTERRUPT
init|=
literal|0x00080000
block|,
comment|/* interrupt handling */
name|HAL_DEBUG_DIVERSITY
init|=
literal|0x00100000
block|,
comment|/* diversity debugging */
name|HAL_DEBUG_DFS
init|=
literal|0x00200000
block|,
comment|/* DFS debugging */
name|HAL_DEBUG_HANG
init|=
literal|0x00400000
block|,
comment|/* BB/MAC hang debugging */
name|HAL_DEBUG_CALIBRATE
init|=
literal|0x00800000
block|,
comment|/* setup calibration */
name|HAL_DEBUG_POWER_MGMT
init|=
literal|0x01000000
block|,
comment|/* power calibration */
name|HAL_DEBUG_CHANNEL
init|=
literal|0x02000000
block|,
name|HAL_DEBUG_QUEUE
init|=
literal|0x04000000
block|,
name|HAL_DEBUG_PRINT_REG
init|=
literal|0x08000000
block|,
name|HAL_DEBUG_FCS_RTT
init|=
literal|0x10000000
block|,
name|HAL_DEBUG_BT_COEX
init|=
literal|0x20000000
block|,
name|HAL_DEBUG_UNMASKABLE
init|=
literal|0x80000000
block|,
comment|/* always printed */
name|HAL_DEBUG_ANY
init|=
literal|0xffffffff
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_DEBUG_H_ */
end_comment

end_unit

