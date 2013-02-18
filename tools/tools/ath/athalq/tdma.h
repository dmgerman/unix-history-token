begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Adrian Chadd<adrian@FreeBSD.org>  * All Rights Reserved.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TDMA_H__
end_ifndef

begin_define
define|#
directive|define
name|__TDMA_H__
end_define

begin_function_decl
specifier|extern
name|void
name|ath_tdma_beacon_state
parameter_list|(
name|struct
name|if_ath_alq_payload
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tdma_timer_config
parameter_list|(
name|struct
name|if_ath_alq_payload
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tdma_slot_calc
parameter_list|(
name|struct
name|if_ath_alq_payload
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tdma_tsf_adjust
parameter_list|(
name|struct
name|if_ath_alq_payload
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tdma_timer_set
parameter_list|(
name|struct
name|if_ath_alq_payload
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TDMA_H__ */
end_comment

end_unit

