begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Benno Rice under sponsorship from  * the FreeBSD Foundation.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X86_EFI_COPY_H_
end_ifndef

begin_define
define|#
directive|define
name|_X86_EFI_COPY_H_
end_define

begin_function_decl
name|int
name|x86_efi_autoload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x86_efi_getdev
parameter_list|(
name|void
modifier|*
modifier|*
name|vdev
parameter_list|,
specifier|const
name|char
modifier|*
name|devspec
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|x86_efi_fmtdev
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x86_efi_setcurrdev
parameter_list|(
name|struct
name|env_var
modifier|*
name|ev
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x86_efi_copy_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|x86_efi_copy_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|x86_efi_copyin
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
specifier|const
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|x86_efi_copyout
parameter_list|(
specifier|const
name|vm_offset_t
name|src
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
specifier|const
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|x86_efi_readin
parameter_list|(
specifier|const
name|int
name|fd
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
specifier|const
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|UINTN
name|x86_efi_mapkey
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _X86_EFI_COPY_H_ */
end_comment

end_unit

