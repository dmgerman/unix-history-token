begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ar5312phy.h,v 1.3 2008/10/06 18:32:50 sam Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5312PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5312PHY_H_
end_define

begin_include
include|#
directive|include
file|"ar5212/ar5212phy.h"
end_include

begin_comment
comment|/* PHY registers */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_44_5312
value|0x14d6
end_define

begin_comment
comment|/* 44 MHz for 11b, 11g */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_40_5312
value|0x14d4
end_define

begin_comment
comment|/* 40 MHz for 11a, turbos */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_40_5312_HALF
value|0x15d4
end_define

begin_comment
comment|/* 40 MHz for 11a, turbos (Half)*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_40_5312_QUARTER
value|0x16d4
end_define

begin_comment
comment|/* 40 MHz for 11a, turbos (Quarter)*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5312PHY_H_ */
end_comment

end_unit

