begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
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
file|"ah_devid.h"
end_include

begin_include
include|#
directive|include
file|"ah_eeprom_v14.h"
end_include

begin_include
include|#
directive|include
file|"ar5416/ar5416.h"
end_include

begin_include
include|#
directive|include
file|"ar5416/ar5416reg.h"
end_include

begin_include
include|#
directive|include
file|"ar5416/ar5416phy.h"
end_include

begin_comment
comment|/*  * Read 16 bits of data from offset into *data  */
end_comment

begin_function
name|HAL_BOOL
name|ar5416EepromRead
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
name|OS_REG_READ
argument_list|(
name|ah
argument_list|,
name|AR5416_EEPROM_OFFSET
operator|+
operator|(
name|off
operator|<<
name|AR5416_EEPROM_S
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ath_hal_wait
argument_list|(
name|ah
argument_list|,
name|AR_EEPROM_STATUS_DATA
argument_list|,
name|AR_EEPROM_STATUS_DATA_BUSY
operator||
name|AR_EEPROM_STATUS_DATA_PROT_ACCESS
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|AH_FALSE
return|;
operator|*
name|data
operator|=
name|MS
argument_list|(
name|OS_REG_READ
argument_list|(
name|ah
argument_list|,
name|AR_EEPROM_STATUS_DATA
argument_list|)
argument_list|,
name|AR_EEPROM_STATUS_DATA_VAL
argument_list|)
expr_stmt|;
return|return
name|AH_TRUE
return|;
block|}
end_function

end_unit

