begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBIA64_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBIA64_H_
end_define

begin_include
include|#
directive|include
file|<bootstrap.h>
end_include

begin_include
include|#
directive|include
file|<ia64/include/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_define
define|#
directive|define
name|IS_LEGACY_KERNEL
parameter_list|()
value|(ia64_legacy_kernel)
end_define

begin_comment
comment|/*  * Portability functions provided by the loader  * implementation specific to the platform.  */
end_comment

begin_function_decl
name|vm_paddr_t
name|ia64_platform_alloc
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_platform_free
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_platform_bootinfo
parameter_list|(
name|struct
name|bootinfo
modifier|*
parameter_list|,
name|struct
name|bootinfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_platform_enter
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions and variables provided by the ia64 common code  * and shared by all loader implementations.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|ia64_legacy_kernel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
modifier|*
name|ia64_pgtbl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|ia64_pgtblsz
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ia64_autoload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_bootinfo
parameter_list|(
name|struct
name|preloaded_file
modifier|*
parameter_list|,
name|struct
name|bootinfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|ia64_loadaddr
parameter_list|(
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__elfN
end_ifdef

begin_function_decl
name|void
name|ia64_loadseg
parameter_list|(
name|Elf_Ehdr
modifier|*
parameter_list|,
name|Elf_Phdr
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|ia64_loadseg
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ssize_t
name|ia64_copyin
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|ia64_copyout
parameter_list|(
name|vm_offset_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_sync_icache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|ia64_readin
parameter_list|(
name|int
parameter_list|,
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ia64_va2pa
parameter_list|(
name|vm_offset_t
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ia64_fmtdev
parameter_list|(
name|struct
name|devdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_getdev
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_setcurrdev
parameter_list|(
name|struct
name|env_var
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBIA64_H_ */
end_comment

end_unit

