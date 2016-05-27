begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Tycho Nightingale<tycho.nightingale@pluribusnetworks.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHYVEGC_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHYVEGC_H_
end_define

begin_struct_decl
struct_decl|struct
name|bhyvegc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bhyvegc_image
block|{
name|int
name|vgamode
decl_stmt|;
name|int
name|width
decl_stmt|;
name|int
name|height
decl_stmt|;
name|uint32_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|bhyvegc
modifier|*
name|bhyvegc_init
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|void
modifier|*
name|fbaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhyvegc_set_fbaddr
parameter_list|(
name|struct
name|bhyvegc
modifier|*
name|gc
parameter_list|,
name|void
modifier|*
name|fbaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhyvegc_resize
parameter_list|(
name|struct
name|bhyvegc
modifier|*
name|gc
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhyvegc_image
modifier|*
name|bhyvegc_get_image
parameter_list|(
name|struct
name|bhyvegc
modifier|*
name|gc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHYVEGC_H_ */
end_comment

end_unit

