begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX_IOMUXVAR_H
end_ifndef

begin_define
define|#
directive|define
name|IMX_IOMUXVAR_H
end_define

begin_comment
comment|/*  * IOMUX interface functions  */
end_comment

begin_function_decl
name|void
name|iomux_set_function
parameter_list|(
name|u_int
name|pin
parameter_list|,
name|u_int
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iomux_set_pad
parameter_list|(
name|u_int
name|pin
parameter_list|,
name|u_int
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|iomux_get_pad_config
parameter_list|(
name|u_int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The IOMUX Controller device has a small set of "general purpose registers"   * which control various aspects of SoC operation that really have nothing to do  * with IO pin assignments or pad control.  These functions let other soc level  * code manipulate these values.  */
end_comment

begin_function_decl
name|uint32_t
name|imx_iomux_gpr_get
parameter_list|(
name|u_int
name|regaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx_iomux_gpr_set
parameter_list|(
name|u_int
name|regaddr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx_iomux_gpr_set_masked
parameter_list|(
name|u_int
name|regaddr
parameter_list|,
name|uint32_t
name|clrbits
parameter_list|,
name|uint32_t
name|setbits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

