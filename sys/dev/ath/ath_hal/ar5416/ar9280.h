begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008-2009 Sam Leffler, Errno Consulting  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR9280_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR9280_H_
end_define

begin_include
include|#
directive|include
file|"ar5416/ar5416.h"
end_include

begin_struct
struct|struct
name|ath_hal_9280
block|{
name|struct
name|ath_hal_5416
name|ah_5416
decl_stmt|;
name|HAL_INI_ARRAY
name|ah_ini_xmodes
decl_stmt|;
name|HAL_INI_ARRAY
name|ah_ini_rxgain
decl_stmt|;
name|HAL_INI_ARRAY
name|ah_ini_txgain
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AH9280
parameter_list|(
name|_ah
parameter_list|)
value|((struct ath_hal_9280 *)(_ah))
end_define

begin_define
define|#
directive|define
name|AR9280_DEFAULT_RXCHAINMASK
value|3
end_define

begin_define
define|#
directive|define
name|AR9280_DEFAULT_TXCHAINMASK
value|1
end_define

begin_function_decl
name|HAL_BOOL
name|ar9280RfAttach
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_STATUS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ath_hal
struct_decl|;
end_struct_decl

begin_function_decl
name|HAL_BOOL
name|ar9280SetAntennaSwitch
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_ANT_SETTING
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AR9280_H_ */
end_comment

end_unit

