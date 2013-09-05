begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008-2009 Sam Leffler, Errno Consulting  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR9285_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR9285_H_
end_define

begin_include
include|#
directive|include
file|"ar5416/ar5416.h"
end_include

begin_struct
struct|struct
name|ath_hal_9285
block|{
name|struct
name|ath_hal_5416
name|ah_5416
decl_stmt|;
name|HAL_INI_ARRAY
name|ah_ini_txgain
decl_stmt|;
name|HAL_INI_ARRAY
name|ah_ini_rxgain
decl_stmt|;
struct|struct
block|{
name|int32_t
name|prev_offset
decl_stmt|;
comment|/* Previous value of PA offset value */
name|int8_t
name|max_skipcount
decl_stmt|;
comment|/* Max No. of times PACAL can be skipped */
name|int8_t
name|skipcount
decl_stmt|;
comment|/* No. of times the PACAL to be skipped */
block|}
name|pacal_info
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AH9285
parameter_list|(
name|_ah
parameter_list|)
value|((struct ath_hal_9285 *)(_ah))
end_define

begin_define
define|#
directive|define
name|AR9285_DEFAULT_RXCHAINMASK
value|1
end_define

begin_define
define|#
directive|define
name|AR9285_DEFAULT_TXCHAINMASK
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_NOM_VAL_9285_2GHZ
value|-118
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_MIN_GOOD_VAL_9285_2GHZ
value|-127
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_MAX_GOOD_VAL_9285_2GHZ
value|-108
end_define

begin_function_decl
name|HAL_BOOL
name|ar9285RfAttach
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

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9285SetTransmitPower
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9285SetBoardValues
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ar9285_btcoex.h */
end_comment

begin_function_decl
specifier|extern
name|void
name|ar9285BTCoexAntennaDiversity
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9285BTCoexSetParameter
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int32_t
name|value
parameter_list|,
name|u_int32_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AR9285_H_ */
end_comment

end_unit

