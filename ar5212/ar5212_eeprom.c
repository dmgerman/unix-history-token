begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ar5212_eeprom.c,v 1.6 2008/11/10 04:08:03 sam Exp $  */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_AR5212
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
file|"ah_devid.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AH_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|"ah_desc.h"
end_include

begin_comment
comment|/* NB: for HAL_PHYERR* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ar5212/ar5212.h"
end_include

begin_include
include|#
directive|include
file|"ar5212/ar5212reg.h"
end_include

begin_include
include|#
directive|include
file|"ar5212/ar5212phy.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_AR5311
end_ifdef

begin_include
include|#
directive|include
file|"ar5212/ar5311reg.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Read 16 bits of data from offset into *data  */
end_comment

begin_function
name|HAL_BOOL
name|ar5212EepromRead
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
name|OS_REG_WRITE
argument_list|(
name|ah
argument_list|,
name|AR_EEPROM_ADDR
argument_list|,
name|off
argument_list|)
expr_stmt|;
name|OS_REG_WRITE
argument_list|(
name|ah
argument_list|,
name|AR_EEPROM_CMD
argument_list|,
name|AR_EEPROM_CMD_READ
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ath_hal_wait
argument_list|(
name|ah
argument_list|,
name|AR_EEPROM_STS
argument_list|,
name|AR_EEPROM_STS_READ_COMPLETE
operator||
name|AR_EEPROM_STS_READ_ERROR
argument_list|,
name|AR_EEPROM_STS_READ_COMPLETE
argument_list|)
condition|)
block|{
name|HALDEBUG
argument_list|(
name|ah
argument_list|,
name|HAL_DEBUG_ANY
argument_list|,
literal|"%s: read failed for entry 0x%x\n"
argument_list|,
name|__func__
argument_list|,
name|off
argument_list|)
expr_stmt|;
return|return
name|AH_FALSE
return|;
block|}
operator|*
name|data
operator|=
name|OS_REG_READ
argument_list|(
name|ah
argument_list|,
name|AR_EEPROM_DATA
argument_list|)
operator|&
literal|0xffff
expr_stmt|;
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
comment|/* AH_SUPPORT_AR5212 */
end_comment

end_unit

