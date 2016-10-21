begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015,2016 Annapurna Labs Ltd. and affiliates  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  *  Ethernet  *  @{  * @file   al_init_eth_kr.h  *  * @brief auto-negotiation and link training activation sequence  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_INIT_ETH_KR_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_INIT_ETH_KR_H__
end_define

begin_include
include|#
directive|include
file|<al_hal_eth_kr.h>
end_include

begin_include
include|#
directive|include
file|<al_serdes.h>
end_include

begin_comment
comment|/**  * execute Auto-negotiation process  *  * @param adapter pointer to the private structure  * @param serdes_obj pointer to serdes private structure  * @param grp serdes's group  * @param lane serdes's lane  * @param an_adv pointer to the AN Advertisement Registers structure  *        when NULL, the registers will not be updated.  * @param partner_adv pointer to the AN Advertisement received from the lp  *  * @return 0 on success. otherwise on failure.  */
end_comment

begin_function_decl
name|int
name|al_eth_an_lt_execute
parameter_list|(
name|struct
name|al_hal_eth_adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|al_serdes_grp_obj
modifier|*
name|serdes_obj
parameter_list|,
name|enum
name|al_serdes_lane
name|lane
parameter_list|,
name|struct
name|al_eth_an_adv
modifier|*
name|an_adv
parameter_list|,
name|struct
name|al_eth_an_adv
modifier|*
name|partner_adv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__AL_INIT_ETH_KR_H__*/
end_comment

end_unit

