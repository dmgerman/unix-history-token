begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 INRIA  * Copyright (c) 2002-2004 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,     without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_RATE_AMRR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_RATE_AMRR_H
end_define

begin_comment
comment|/* per-device state */
end_comment

begin_struct
struct|struct
name|amrr_softc
block|{
name|struct
name|ath_ratectrl
name|arc
decl_stmt|;
comment|/* base state */
name|struct
name|callout
name|timer
decl_stmt|;
comment|/* periodic timer */
block|}
struct|;
end_struct

begin_comment
comment|/* per-node state */
end_comment

begin_struct
struct|struct
name|amrr_node
block|{
comment|/* AMRR statistics for this node */
name|u_int
name|amn_tx_try0_cnt
decl_stmt|;
name|u_int
name|amn_tx_try1_cnt
decl_stmt|;
name|u_int
name|amn_tx_try2_cnt
decl_stmt|;
name|u_int
name|amn_tx_try3_cnt
decl_stmt|;
name|u_int
name|amn_tx_failure_cnt
decl_stmt|;
comment|/* AMRR algorithm state for this node */
name|u_int
name|amn_success_threshold
decl_stmt|;
name|u_int
name|amn_success
decl_stmt|;
name|u_int
name|amn_recovery
decl_stmt|;
comment|/* rate index et al. */
name|u_int8_t
name|amn_tx_rix0
decl_stmt|;
comment|/* series 0 rate index */
name|u_int8_t
name|amn_tx_rate0
decl_stmt|;
comment|/* series 0 h/w rate */
name|u_int8_t
name|amn_tx_rate1
decl_stmt|;
comment|/* series 1 h/w rate */
name|u_int8_t
name|amn_tx_rate2
decl_stmt|;
comment|/* series 2 h/w rate */
name|u_int8_t
name|amn_tx_rate3
decl_stmt|;
comment|/* series 3 h/w rate */
name|u_int8_t
name|amn_tx_rate0sp
decl_stmt|;
comment|/* series 0 short preamble h/w rate */
name|u_int8_t
name|amn_tx_rate1sp
decl_stmt|;
comment|/* series 1 short preamble h/w rate */
name|u_int8_t
name|amn_tx_rate2sp
decl_stmt|;
comment|/* series 2 short preamble h/w rate */
name|u_int8_t
name|amn_tx_rate3sp
decl_stmt|;
comment|/* series 3 short preamble h/w rate */
name|u_int8_t
name|amn_tx_try0
decl_stmt|;
comment|/* series 0 try count */
name|u_int
name|amn_tx_try1
decl_stmt|;
comment|/* series 1 try count */
name|u_int
name|amn_tx_try2
decl_stmt|;
comment|/* series 2 try count */
name|u_int
name|amn_tx_try3
decl_stmt|;
comment|/* series 3 try count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_NODE_AMRR
parameter_list|(
name|an
parameter_list|)
value|((struct amrr_node *)&an[1])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_RATE_AMRR_H */
end_comment

end_unit

