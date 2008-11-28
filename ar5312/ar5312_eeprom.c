begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ar5312_eeprom.c,v 1.4 2008/11/10 04:08:04 sam Exp $  */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_AR5312
end_ifdef

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
file|"ar5312/ar5312.h"
end_include

begin_include
include|#
directive|include
file|"ar5312/ar5312reg.h"
end_include

begin_include
include|#
directive|include
file|"ar5212/ar5212desc.h"
end_include

begin_comment
comment|/*  * Read 16 bits of data from offset into *data  */
end_comment

begin_function
name|HAL_BOOL
name|ar5312EepromRead
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
name|dataIn
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|offset
decl_stmt|;
specifier|const
name|char
modifier|*
name|eepromAddr
init|=
name|AR5312_RADIOCONFIG
argument_list|(
name|ah
argument_list|)
decl_stmt|;
name|uint8_t
modifier|*
name|data
decl_stmt|;
name|data
operator|=
operator|(
name|uint8_t
operator|*
operator|)
name|dataIn
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|offset
operator|=
literal|2
operator|*
name|off
init|;
name|i
operator|<
literal|2
condition|;
name|i
operator|++
operator|,
name|offset
operator|++
control|)
block|{
name|data
index|[
name|i
index|]
operator|=
name|eepromAddr
index|[
name|offset
index|]
expr_stmt|;
block|}
return|return
name|AH_TRUE
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_SUPPORT_AR5312 */
end_comment

end_unit

