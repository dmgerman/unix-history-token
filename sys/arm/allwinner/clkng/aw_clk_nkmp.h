begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AW_CLK_NKMP_H__
end_ifndef

begin_define
define|#
directive|define
name|__AW_CLK_NKMP_H__
end_define

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk.h>
end_include

begin_struct
struct|struct
name|aw_clk_nkmp_def
block|{
name|struct
name|clknode_init_def
name|clkdef
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|struct
name|aw_clk_factor
name|m
decl_stmt|;
name|struct
name|aw_clk_factor
name|k
decl_stmt|;
name|struct
name|aw_clk_factor
name|n
decl_stmt|;
name|struct
name|aw_clk_factor
name|p
decl_stmt|;
name|uint32_t
name|mux_shift
decl_stmt|;
name|uint32_t
name|mux_width
decl_stmt|;
name|uint32_t
name|gate_shift
decl_stmt|;
name|uint32_t
name|lock_shift
decl_stmt|;
name|uint32_t
name|lock_retries
decl_stmt|;
name|uint32_t
name|update_shift
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|aw_clk_nkmp_register
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|struct
name|aw_clk_nkmp_def
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
comment|/* __AW_CLK_NKMP_H__ */
end_comment

end_unit

