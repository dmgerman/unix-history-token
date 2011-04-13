begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008-2010 Atheros Communications Inc.  * Copyright (c) 2011 Adrian Chadd, Xenion Pty Ltd.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR9285_DIVERSITY_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR9285_DIVERSITY_H__
end_define

begin_comment
comment|/* Antenna diversity/combining */
end_comment

begin_define
define|#
directive|define
name|ATH_ANT_RX_CURRENT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ATH_ANT_RX_MAIN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ATH_ANT_RX_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_SHORT_SCAN_INTR
value|50
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_SHORT_SCAN_PKTCOUNT
value|0x100
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_MAX_PKTCOUNT
value|0x200
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_INIT_COUNT
value|95
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_MAX_COUNT
value|100
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_ALT_ANT_RATIO
value|30
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_ALT_ANT_RATIO2
value|20
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_LNA1_LNA2_DELTA
value|-3
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_LNA1_LNA2_SWITCH_DELTA
value|-1
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_LNA1_DELTA_HI
value|-4
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_LNA1_DELTA_MID
value|-2
end_define

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB_LNA1_DELTA_LOW
value|2
end_define

begin_function_decl
specifier|extern
name|void
name|ar9285_ant_comb_scan
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_rx_status
modifier|*
name|rs
parameter_list|,
name|unsigned
name|long
name|ticks
parameter_list|,
name|int
name|hz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

