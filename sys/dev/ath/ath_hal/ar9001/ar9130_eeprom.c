begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011 Adrian Chadd, Xenion Pty Ltd  * Copyright (c) 2010 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_include
include|#
directive|include
file|"ah.h"
end_include

begin_include
include|#
directive|include
file|"ah_internal.h"
end_include

begin_include
include|#
directive|include
file|"ar9001/ar9130_eeprom.h"
end_include

begin_comment
comment|/* XXX this shouldn't be done here */
end_comment

begin_comment
comment|/* This is in 16 bit words; not bytes -adrian */
end_comment

begin_define
define|#
directive|define
name|ATH_DATA_EEPROM_SIZE
value|2048
end_define

begin_function
name|HAL_BOOL
name|ar9130EepromRead
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|off
parameter_list|,
name|uint16_t
modifier|*
name|data
parameter_list|)
block|{
if|if
condition|(
name|ah
operator|->
name|ah_eepromdata
operator|==
name|AH_NULL
condition|)
block|{
name|HALDEBUG
argument_list|(
name|ah
argument_list|,
name|HAL_DEBUG_ANY
argument_list|,
literal|"%s: no eeprom data!\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
name|AH_FALSE
return|;
block|}
if|if
condition|(
name|off
operator|>
name|ATH_DATA_EEPROM_SIZE
condition|)
block|{
name|HALDEBUG
argument_list|(
name|ah
argument_list|,
name|HAL_DEBUG_ANY
argument_list|,
literal|"ar9130EepromRead: offset %x> %x\n"
argument_list|,
name|off
argument_list|,
name|ATH_DATA_EEPROM_SIZE
argument_list|)
expr_stmt|;
return|return
name|AH_FALSE
return|;
block|}
operator|(
operator|*
name|data
operator|)
operator|=
name|ah
operator|->
name|ah_eepromdata
index|[
name|off
index|]
expr_stmt|;
return|return
name|AH_TRUE
return|;
block|}
end_function

end_unit

