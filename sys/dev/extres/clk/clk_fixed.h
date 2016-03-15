begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_EXTRES_CLK_FIXED_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_EXTRES_CLK_FIXED_H_
end_define

begin_include
include|#
directive|include
file|<dev/extres/clk/clk.h>
end_include

begin_comment
comment|/*  * A fixed clock can represent several different real-world objects, including  * an oscillator with a fixed output frequency, a fixed divider (multiplier and  * divisor must both be> 0), or a phase-fractional divider within a PLL  * (however the code currently divides first, then multiplies, potentially  * leading to different roundoff errors than the hardware PLL).  */
end_comment

begin_struct
struct|struct
name|clk_fixed_def
block|{
name|struct
name|clknode_init_def
name|clkdef
decl_stmt|;
name|uint64_t
name|freq
decl_stmt|;
name|uint32_t
name|mult
decl_stmt|;
name|uint32_t
name|div
decl_stmt|;
name|int
name|fixed_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|clknode_fixed_register
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|struct
name|clk_fixed_def
modifier|*
name|clkdef
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_DEV_EXTRES_CLK_FIXED_H_*/
end_comment

end_unit

