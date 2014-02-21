begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011 Adrian Chadd, Xenion Pty Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ATH_TX_HT_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ATH_TX_HT_H__
end_define

begin_enum
enum|enum
block|{
name|MCS_HT20
block|,
name|MCS_HT20_SGI
block|,
name|MCS_HT40
block|,
name|MCS_HT40_SGI
block|, }
enum|;
end_enum

begin_typedef
typedef|typedef
enum|enum
block|{
name|ATH_AGGR_DONE
block|,
name|ATH_AGGR_BAW_CLOSED
block|,
name|ATH_AGGR_LIMITED
block|,
name|ATH_AGGR_SHORTPKT
block|,
name|ATH_AGGR_8K_LIMITED
block|,
name|ATH_AGGR_ERROR
block|,
name|ATH_AGGR_NONAGGR
block|,
name|ATH_AGGR_LEAK_CLOSED
block|, }
name|ATH_AGGR_STATUS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|ath_max_4ms_framelen
index|[
literal|4
index|]
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ath_tx_rate_fill_rcflags
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_buf_set_rate
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ATH_AGGR_STATUS
name|ath_tx_form_aggr
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|,
name|struct
name|ath_tid
modifier|*
name|tid
parameter_list|,
name|ath_bufhead
modifier|*
name|bf_q
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

