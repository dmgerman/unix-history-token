begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACCESS601_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACCESS601_H_
end_define

begin_function_decl
name|void
name|HPTLIBAPI
name|BeepOn
parameter_list|(
name|MV_BUS_ADDR_T
name|BaseAddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|BeepOff
parameter_list|(
name|MV_BUS_ADDR_T
name|BaseAddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UCHAR
name|HPTLIBAPI
name|check_protect_circuit
parameter_list|(
name|MV_BUS_ADDR_T
name|BaseAddr
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_FAIL_LED
end_ifdef

begin_function_decl
name|void
name|HPTLIBAPI
name|set_fail_led
parameter_list|(
name|MV_SATA_ADAPTER
modifier|*
name|pAdapter
parameter_list|,
name|UCHAR
name|channel
parameter_list|,
name|UCHAR
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|set_fail_leds
parameter_list|(
name|MV_SATA_ADAPTER
modifier|*
name|pAdapter
parameter_list|,
name|UCHAR
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|set_fail_led
parameter_list|(
name|pAdapter
parameter_list|,
name|channel
parameter_list|,
name|state
parameter_list|)
end_define

begin_define
define|#
directive|define
name|set_fail_leds
parameter_list|(
name|pAdapter
parameter_list|,
name|mask
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

