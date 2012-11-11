begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_DIAGCODES_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_DIAGCODES_H_
end_define

begin_comment
comment|/*  * Atheros Device Hardware Access Layer (HAL).  *  * Internal diagnostic API definitions.  */
end_comment

begin_comment
comment|/*  * Diagnostic interface.  This is an open-ended interface that  * is opaque to applications.  Diagnostic programs use this to  * retrieve internal data structures, etc.  There is no guarantee  * that calling conventions for calls other than HAL_DIAG_REVS  * are stable between HAL releases; a diagnostic application must  * use the HAL revision information to deal with ABI/API differences.  *  * NB: do not renumber these, certain codes are publicly used.  */
end_comment

begin_enum
enum|enum
block|{
name|HAL_DIAG_REVS
init|=
literal|0
block|,
comment|/* MAC/PHY/Radio revs */
name|HAL_DIAG_EEPROM
init|=
literal|1
block|,
comment|/* EEPROM contents */
name|HAL_DIAG_EEPROM_EXP_11A
init|=
literal|2
block|,
comment|/* EEPROM 5112 power exp for 11a */
name|HAL_DIAG_EEPROM_EXP_11B
init|=
literal|3
block|,
comment|/* EEPROM 5112 power exp for 11b */
name|HAL_DIAG_EEPROM_EXP_11G
init|=
literal|4
block|,
comment|/* EEPROM 5112 power exp for 11g */
name|HAL_DIAG_ANI_CURRENT
init|=
literal|5
block|,
comment|/* ANI current channel state */
name|HAL_DIAG_ANI_OFDM
init|=
literal|6
block|,
comment|/* ANI OFDM timing error stats */
name|HAL_DIAG_ANI_CCK
init|=
literal|7
block|,
comment|/* ANI CCK timing error stats */
name|HAL_DIAG_ANI_STATS
init|=
literal|8
block|,
comment|/* ANI statistics */
name|HAL_DIAG_RFGAIN
init|=
literal|9
block|,
comment|/* RfGain GAIN_VALUES */
name|HAL_DIAG_RFGAIN_CURSTEP
init|=
literal|10
block|,
comment|/* RfGain GAIN_OPTIMIZATION_STEP */
name|HAL_DIAG_PCDAC
init|=
literal|11
block|,
comment|/* PCDAC table */
name|HAL_DIAG_TXRATES
init|=
literal|12
block|,
comment|/* Transmit rate table */
name|HAL_DIAG_REGS
init|=
literal|13
block|,
comment|/* Registers */
name|HAL_DIAG_ANI_CMD
init|=
literal|14
block|,
comment|/* ANI issue command (XXX do not change!) */
name|HAL_DIAG_SETKEY
init|=
literal|15
block|,
comment|/* Set keycache backdoor */
name|HAL_DIAG_RESETKEY
init|=
literal|16
block|,
comment|/* Reset keycache backdoor */
name|HAL_DIAG_EEREAD
init|=
literal|17
block|,
comment|/* Read EEPROM word */
name|HAL_DIAG_EEWRITE
init|=
literal|18
block|,
comment|/* Write EEPROM word */
comment|/* 19-26 removed, do not reuse */
name|HAL_DIAG_RDWRITE
init|=
literal|27
block|,
comment|/* Write regulatory domain */
name|HAL_DIAG_RDREAD
init|=
literal|28
block|,
comment|/* Get regulatory domain */
name|HAL_DIAG_FATALERR
init|=
literal|29
block|,
comment|/* Read cached interrupt state */
name|HAL_DIAG_11NCOMPAT
init|=
literal|30
block|,
comment|/* 11n compatibility tweaks */
name|HAL_DIAG_ANI_PARAMS
init|=
literal|31
block|,
comment|/* ANI noise immunity parameters */
name|HAL_DIAG_CHECK_HANGS
init|=
literal|32
block|,
comment|/* check h/w hangs */
name|HAL_DIAG_SETREGS
init|=
literal|33
block|,
comment|/* write registers */
name|HAL_DIAG_CHANSURVEY
init|=
literal|34
block|,
comment|/* channel survey */
name|HAL_DIAG_PRINT_REG
init|=
literal|35
block|,
name|HAL_DIAG_PRINT_REG_ALL
init|=
literal|36
block|,
name|HAL_DIAG_CHANNELS
init|=
literal|37
block|,
name|HAL_DIAG_PRINT_REG_COUNTER
init|=
literal|38
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_DIAGCODES_H_ */
end_comment

end_unit

