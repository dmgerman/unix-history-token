begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_EFI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_EFI_H_
end_define

begin_include
include|#
directive|include
file|<boot/efi/include/ia64/efibind.h>
end_include

begin_include
include|#
directive|include
file|<boot/efi/include/efidef.h>
end_include

begin_include
include|#
directive|include
file|<boot/efi/include/efierr.h>
end_include

begin_include
include|#
directive|include
file|<boot/efi/include/efidevp.h>
end_include

begin_include
include|#
directive|include
file|<boot/efi/include/eficon.h>
end_include

begin_include
include|#
directive|include
file|<boot/efi/include/efiapi.h>
end_include

begin_include
include|#
directive|include
file|<boot/efi/include/efifpswa.h>
end_include

begin_decl_stmt
specifier|extern
name|EFI_SYSTEM_TABLE
modifier|*
name|ia64_efi_systab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_RUNTIME_SERVICES
modifier|*
name|ia64_efi_runtime
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ia64_efi_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_EFI_H_ */
end_comment

end_unit

