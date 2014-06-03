begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2014 Warner Losh.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Atmel at91-family integrated NAND controller driver.  *  * Interface to board setup code to set parameters.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_NAND_NFC_AT91_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_NAND_NFC_AT91_H
value|1
end_define

begin_struct
struct|struct
name|at91_nand_params
block|{
name|uint32_t
name|ale
decl_stmt|;
comment|/* Address for ALE (address) NAND cycles */
name|uint32_t
name|cle
decl_stmt|;
comment|/* Address for CLE (command) NAND cycles */
name|uint32_t
name|width
decl_stmt|;
comment|/* 8 or 16 bits (specify in bits) */
name|uint32_t
name|cs
decl_stmt|;
comment|/* Chip Select NAND is connected to */
name|uint32_t
name|rnb_pin
decl_stmt|;
comment|/* GPIO pin # for Read/notBusy */
name|uint32_t
name|nce_pin
decl_stmt|;
comment|/* GPIO pin # for CE (active low) */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|at91_enable_nand
parameter_list|(
specifier|const
name|struct
name|at91_nand_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_NAND_NFC_AT91_H */
end_comment

end_unit

