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

begin_define
define|#
directive|define
name|reloc_jmpslot
parameter_list|(
name|where
parameter_list|,
name|target
parameter_list|)
define|\
value|do {						\ 	dbg("reloc_jmpslot: *%p = %p", (void *)(where),	\ 	  (void *)(target));				\ 	(*(Elf_Addr *)(where) = (Elf_Addr)(target));	\     } while (0)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|atomic_decr_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|p
parameter_list|)
block|{
asm|__asm __volatile ("lock; decl %0" : "=m"(*p) : "0"(*p) : "cc");
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|atomic_incr_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|p
parameter_list|)
block|{
asm|__asm __volatile ("lock; incl %0" : "=m"(*p) : "0"(*p) : "cc");
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|atomic_add_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|p
parameter_list|,
name|int
name|val
parameter_list|)
block|{
asm|__asm __volatile ("lock; addl %1, %0"
block|:
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"ri"
operator|(
name|val
operator|)
operator|,
literal|"0"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"cc"
block|)
function|;
end_function

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

