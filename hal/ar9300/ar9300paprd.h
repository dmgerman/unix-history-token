begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*   * Copyright (c) 2002-2010 Atheros Communications, Inc.   * All Rights Reserved.  *   * Copyright (c) 2011 Qualcomm Atheros, Inc.  * All Rights Reserved.  * Qualcomm Atheros Confidential and Proprietary.  *    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR9300PAPRD_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR9300PAPRD_H__
end_define

begin_include
include|#
directive|include
file|<ah.h>
end_include

begin_include
include|#
directive|include
file|"ar9300.h"
end_include

begin_include
include|#
directive|include
file|"ar9300phy.h"
end_include

begin_define
define|#
directive|define
name|AH_PAPRD_AM_PM_MASK
value|0x1ffffff
end_define

begin_define
define|#
directive|define
name|AH_PAPRD_IDEAL_AGC2_PWR_RANGE
value|0xe0
end_define

begin_function_decl
specifier|extern
name|int
name|ar9300_paprd_init_table
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_CHANNEL
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_STATUS
name|ar9300_paprd_setup_gain_table
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|chain_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_STATUS
name|ar9300_paprd_create_curve
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_CHANNEL
modifier|*
name|chan
parameter_list|,
name|int
name|chain_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_paprd_is_done
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
name|ar9300_enable_paprd
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|enable_flag
parameter_list|,
name|HAL_CHANNEL
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_swizzle_paprd_entries
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|unsigned
name|int
name|txchain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_populate_paprd_single_table
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_CHANNEL
modifier|*
name|chan
parameter_list|,
name|int
name|chain_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_paprd_dec_tx_pwr
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
name|int
name|ar9300_paprd_thermal_send
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

