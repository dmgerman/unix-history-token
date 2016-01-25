begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 The FreeBSD Foundation  * Copyright (c) 2014 Andrew Turner  * All rights reserved.  *  * Developed by Damjan Marion<damjan.marion@gmail.com>  *  * Based on OMAP4 GIC code by Ben Gray  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM64_GIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM64_GIC_H_
end_define

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|arm_gic_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|arm_gic_softc
block|{
name|device_t
name|gic_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|gic_res
index|[
literal|3
index|]
decl_stmt|;
name|bus_space_tag_t
name|gic_c_bst
decl_stmt|;
name|bus_space_tag_t
name|gic_d_bst
decl_stmt|;
name|bus_space_handle_t
name|gic_c_bsh
decl_stmt|;
name|bus_space_handle_t
name|gic_d_bsh
decl_stmt|;
name|uint8_t
name|ver
decl_stmt|;
name|struct
name|mtx
name|mutex
decl_stmt|;
name|uint32_t
name|nirqs
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|arm_gicv2m_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|gicv2m_softc
block|{
name|struct
name|resource
modifier|*
name|sc_mem
decl_stmt|;
name|struct
name|mtx
name|sc_mutex
decl_stmt|;
name|u_int
name|sc_spi_start
decl_stmt|;
name|u_int
name|sc_spi_count
decl_stmt|;
name|u_int
name|sc_spi_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|arm_gic_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

