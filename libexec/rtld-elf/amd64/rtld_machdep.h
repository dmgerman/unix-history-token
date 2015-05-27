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

begin_struct_decl
struct_decl|struct
name|Struct_Obj_Entry
struct_decl|;
end_struct_decl

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
define|\
value|((const Elf_Dyn *)((obj)->relocbase + (Elf_Addr)&_DYNAMIC))
end_define

begin_comment
comment|/* Fixup the jump slot at "where" to transfer control to "target". */
end_comment

begin_function
specifier|static
specifier|inline
name|Elf_Addr
name|reloc_jmpslot
parameter_list|(
name|Elf_Addr
modifier|*
name|where
parameter_list|,
name|Elf_Addr
name|target
parameter_list|,
specifier|const
name|struct
name|Struct_Obj_Entry
modifier|*
name|obj
parameter_list|,
specifier|const
name|struct
name|Struct_Obj_Entry
modifier|*
name|refobj
parameter_list|,
specifier|const
name|Elf_Rel
modifier|*
name|rel
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|dbg
name|dbg
argument_list|(
literal|"reloc_jmpslot: *%p = %p"
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|where
operator|)
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|target
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
operator|*
operator|(
name|Elf_Addr
operator|*
operator|)
operator|(
name|where
operator|)
operator|=
call|(
name|Elf_Addr
call|)
argument_list|(
name|target
argument_list|)
operator|)
expr_stmt|;
return|return
name|target
return|;
block|}
end_function

begin_define
define|#
directive|define
name|make_function_pointer
parameter_list|(
name|def
parameter_list|,
name|defobj
parameter_list|)
define|\
value|((defobj)->relocbase + (def)->st_value)
end_define

begin_define
define|#
directive|define
name|call_initfini_pointer
parameter_list|(
name|obj
parameter_list|,
name|target
parameter_list|)
define|\
value|(((InitFunc)(target))())
end_define

begin_define
define|#
directive|define
name|call_init_pointer
parameter_list|(
name|obj
parameter_list|,
name|target
parameter_list|)
define|\
value|(((InitArrFunc)(target))(main_argc, main_argv, environ))
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
value|round(size, align)
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
value|round((prev_offset) + (size), align)
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
value|(off)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|ti_module
decl_stmt|;
name|unsigned
name|long
name|ti_offset
decl_stmt|;
block|}
name|tls_index
typedef|;
end_typedef

begin_decl_stmt
name|void
modifier|*
name|__tls_get_addr
argument_list|(
name|tls_index
operator|*
name|ti
argument_list|)
name|__exported
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RTLD_DEFAULT_STACK_PF_EXEC
value|PF_X
end_define

begin_define
define|#
directive|define
name|RTLD_DEFAULT_STACK_EXEC
value|PROT_EXEC
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

