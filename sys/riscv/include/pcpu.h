begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * Copyright (c) 2015-2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/include/globaldata.h,v 1.27 2001/04/27  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCPU_H_
end_define

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_define
define|#
directive|define
name|ALT_STACK_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|uint32_t pc_pending_ipis;
comment|/* IPIs pending to this CPU */
value|\ 	char __pad[61]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|pcpu
modifier|*
name|pcpup
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|struct
name|pcpu
modifier|*
name|get_pcpu
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|pcpu
modifier|*
name|pcpu
decl_stmt|;
asm|__asm __volatile("mv %0, gp" : "=&r"(pcpu));
return|return
operator|(
name|pcpu
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|thread
modifier|*
name|get_curthread
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
asm|__asm __volatile("ld %0, 0(gp)" : "=&r"(td));
return|return
operator|(
name|td
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|curthread
value|get_curthread()
end_define

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|(get_pcpu()->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_ADD
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(get_pcpu()->pc_ ## member += (value))
end_define

begin_define
define|#
directive|define
name|PCPU_INC
parameter_list|(
name|member
parameter_list|)
value|PCPU_ADD(member, 1)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|member
parameter_list|)
value|(&get_pcpu()->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(get_pcpu()->pc_ ## member = (value))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PCPU_H_ */
end_comment

end_unit

