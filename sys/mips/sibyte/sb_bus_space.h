begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Neelkanth Natu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SB_BUS_SPACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SB_BUS_SPACE_H_
end_define

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_function_decl
name|uint8_t
name|sb_big_endian_read8
parameter_list|(
name|bus_addr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|sb_big_endian_read16
parameter_list|(
name|bus_addr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|sb_big_endian_read32
parameter_list|(
name|bus_addr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_big_endian_write8
parameter_list|(
name|bus_addr_t
name|addr
parameter_list|,
name|uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_big_endian_write16
parameter_list|(
name|bus_addr_t
name|addr
parameter_list|,
name|uint16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_big_endian_write32
parameter_list|(
name|bus_addr_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

