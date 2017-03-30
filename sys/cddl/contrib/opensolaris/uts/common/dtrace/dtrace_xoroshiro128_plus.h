begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 (Graeme Jenkinson)  * All rights reserved.  *  * This software was developed by BAE Systems, the University of Cambridge  * Computer Laboratory, and Memorial University under DARPA/AFRL contract  * FA8650-15-C-7558 ("CADETS"), as part of the DARPA Transparent Computing  * (TC) research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DTRACE_XOROSHIRO128_PLUS_H
end_ifndef

begin_define
define|#
directive|define
name|_DTRACE_XOROSHIRO128_PLUS_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
name|void
name|dtrace_xoroshiro128_plus_jump
parameter_list|(
name|uint64_t
modifier|*
specifier|const
parameter_list|,
name|uint64_t
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|dtrace_xoroshiro128_plus_next
parameter_list|(
name|uint64_t
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

