begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTLD_MACHDEP_H
end_ifndef

begin_define
define|#
directive|define
name|RTLD_MACHDEP_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_comment
comment|/*  * Macros for cracking ia64 function pointers.  */
end_comment

begin_struct
struct|struct
name|fptr
block|{
name|Elf_Addr
name|target
decl_stmt|;
name|Elf_Addr
name|gp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FPTR_TARGET
parameter_list|(
name|f
parameter_list|)
value|(((struct fptr *) (f))->target)
end_define

begin_define
define|#
directive|define
name|FPTR_GP
parameter_list|(
name|f
parameter_list|)
value|(((struct fptr *) (f))->gp)
end_define

begin_comment
comment|/* Return the address of the .dynamic section in the dynamic linker. */
end_comment

begin_define
define|#
directive|define
name|rtld_dynamic
parameter_list|(
name|obj
parameter_list|)
value|(&_DYNAMIC)
end_define

begin_struct_decl
struct_decl|struct
name|Struct_Obj_Entry
struct_decl|;
end_struct_decl

begin_function_decl
name|Elf_Addr
name|reloc_jmpslot
parameter_list|(
name|Elf_Addr
modifier|*
parameter_list|,
name|Elf_Addr
parameter_list|,
specifier|const
name|struct
name|Struct_Obj_Entry
modifier|*
parameter_list|,
specifier|const
name|struct
name|Struct_Obj_Entry
modifier|*
parameter_list|,
specifier|const
name|Elf_Rel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|make_function_pointer
parameter_list|(
specifier|const
name|Elf_Sym
modifier|*
parameter_list|,
specifier|const
name|struct
name|Struct_Obj_Entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|call_initfini_pointer
parameter_list|(
specifier|const
name|struct
name|Struct_Obj_Entry
modifier|*
parameter_list|,
name|Elf_Addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|call_init_pointer
parameter_list|(
specifier|const
name|struct
name|Struct_Obj_Entry
modifier|*
parameter_list|,
name|Elf_Addr
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TLS_TCB_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|round
parameter_list|(
name|size
parameter_list|,
name|align
parameter_list|)
define|\
value|(((size) + (align) - 1)& ~((align) - 1))
end_define

begin_define
define|#
directive|define
name|calculate_first_tls_offset
parameter_list|(
name|size
parameter_list|,
name|align
parameter_list|)
define|\
value|round(TLS_TCB_SIZE, align)
end_define

begin_define
define|#
directive|define
name|calculate_tls_offset
parameter_list|(
name|prev_offset
parameter_list|,
name|prev_size
parameter_list|,
name|size
parameter_list|,
name|align
parameter_list|)
define|\
value|round(prev_offset + prev_size, align)
end_define

begin_define
define|#
directive|define
name|calculate_tls_end
parameter_list|(
name|off
parameter_list|,
name|size
parameter_list|)
value|((off) + (size))
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|__tls_get_addr
parameter_list|(
name|unsigned
name|long
name|module
parameter_list|,
name|unsigned
name|long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RTLD_DEFAULT_STACK_PF_EXEC
value|0
end_define

begin_define
define|#
directive|define
name|RTLD_DEFAULT_STACK_EXEC
value|0
end_define

begin_define
define|#
directive|define
name|RTLD_INIT_PAGESIZES_EARLY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

