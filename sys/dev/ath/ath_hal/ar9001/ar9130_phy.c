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
file|"ah_devid.h"
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

begin_include
include|#
directive|include
file|"ar9001/ar9130_phy.h"
end_include

begin_function
name|void
name|ar9130InitPLL
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
block|{
name|uint32_t
name|pll
decl_stmt|;
comment|/* 	 * XXX TODO: support half/quarter rates 	 */
if|if
condition|(
name|chan
operator|&&
name|IEEE80211_IS_CHAN_5GHZ
argument_list|(
name|chan
argument_list|)
condition|)
name|pll
operator|=
literal|0x1450
expr_stmt|;
else|else
name|pll
operator|=
literal|0x1458
expr_stmt|;
name|OS_REG_WRITE
argument_list|(
name|ah
argument_list|,
name|AR_RTC_PLL_CONTROL
argument_list|,
name|pll
argument_list|)
expr_stmt|;
name|OS_DELAY
argument_list|(
name|RTC_PLL_SETTLE_DELAY
argument_list|)
expr_stmt|;
name|OS_REG_WRITE
argument_list|(
name|ah
argument_list|,
name|AR_RTC_SLEEP_CLK
argument_list|,
name|AR_RTC_SLEEP_DERIVED_CLK
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

