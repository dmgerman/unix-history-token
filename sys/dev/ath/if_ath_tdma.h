begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ATH_TDMA_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ATH_TDMA_H__
end_define

begin_define
define|#
directive|define
name|TDMA_EP_MULTIPLIER
value|(1<<10)
end_define

begin_comment
comment|/* pow2 to optimize out * and / */
end_comment

begin_define
define|#
directive|define
name|TDMA_LPF_LEN
value|6
end_define

begin_define
define|#
directive|define
name|TDMA_DUMMY_MARKER
value|0x127
end_define

begin_define
define|#
directive|define
name|TDMA_EP_MUL
parameter_list|(
name|x
parameter_list|,
name|mul
parameter_list|)
value|((x) * (mul))
end_define

begin_define
define|#
directive|define
name|TDMA_IN
parameter_list|(
name|x
parameter_list|)
value|(TDMA_EP_MUL((x), TDMA_EP_MULTIPLIER))
end_define

begin_define
define|#
directive|define
name|TDMA_LPF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|len
parameter_list|)
define|\
value|((x != TDMA_DUMMY_MARKER) ? (((x) * ((len)-1) + (y)) / (len)) : (y))
end_define

begin_define
define|#
directive|define
name|TDMA_SAMPLE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do {				\         x = TDMA_LPF((x), TDMA_IN(y), TDMA_LPF_LEN);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|TDMA_EP_RND
parameter_list|(
name|x
parameter_list|,
name|mul
parameter_list|)
define|\
value|((((x)%(mul))>= ((mul)/2)) ?			\ 	     ((x) + ((mul) - 1)) / (mul) : (x)/(mul))
end_define

begin_define
define|#
directive|define
name|TDMA_AVG
parameter_list|(
name|x
parameter_list|)
value|TDMA_EP_RND(x, TDMA_EP_MULTIPLIER)
end_define

begin_function_decl
specifier|extern
name|void
name|ath_tdma_config
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tdma_update
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
specifier|const
name|struct
name|ieee80211_tdma_param
modifier|*
name|tdma
parameter_list|,
name|int
name|changed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tdma_beacon_send
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

