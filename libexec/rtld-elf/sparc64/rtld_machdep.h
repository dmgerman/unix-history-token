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
file|<machine/atomic.h>
end_include

begin_define
define|#
directive|define
name|atomic_incr_int
parameter_list|(
name|p
parameter_list|)
value|atomic_add_int((p), 1)
end_define

begin_define
define|#
directive|define
name|atomic_decr_int
parameter_list|(
name|p
parameter_list|)
value|atomic_subtract_int((p), 1)
end_define

begin_comment
comment|/*  * This value of CACHE_LINE_SIZE is conservative.  The actual size  * is 32 on the  21064, 21064A, 21066, 21066A, and 21164.  It is 64  * on the 21264.  Compaq recommends sequestering each lock in its own  * 128-byte block to allow for future implementations with larger  * cache lines.  */
end_comment

begin_define
define|#
directive|define
name|CACHE_LINE_SIZE
value|128
end_define

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
value|((Elf_Dyn *)(((char *)&_DYNAMIC) + (vm_offset_t)(obj)->relocbase))
end_define

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
name|obj
parameter_list|)
function_decl|;
end_function_decl

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

