begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Eric McCorkle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_DRIVERS_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFI_DRIVERS_H_
end_define

begin_include
include|#
directive|include
file|<bootstrap.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|efi_driver_t
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
name|efi_driver_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|efipart_dev
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|efipart_getdesc
parameter_list|(
name|struct
name|devdesc
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EFI drivers. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|efi_driver_t
name|fs_driver
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

