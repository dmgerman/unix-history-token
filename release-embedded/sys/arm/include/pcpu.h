begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/include/globaldata.h,v 1.27 2001/04/27  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_define
define|#
directive|define
name|ALT_STACK_SIZE
value|128
end_define

begin_struct_decl
struct_decl|struct
name|vmspace
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VFP
end_ifdef

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|unsigned int pc_cpu;						\ 	unsigned int pc_vfpsid;						\ 	unsigned int pc_vfpmvfr0;					\ 	unsigned int pc_vfpmvfr1;					\ 	struct thread *pc_vfpcthread;					\ 	struct pmap *pc_curpmap;					\ 	char __pad[133]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|char __pad[157]
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|ARM_ARCH_6
operator|||
name|ARM_ARCH_7A
end_if

begin_comment
comment|/* or ARM_TP_ADDRESS 	mark REMOVE ME NOTE */
end_comment

begin_define
define|#
directive|define
name|CPU_MASK
value|(0xf)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_define
define|#
directive|define
name|get_pcpu
parameter_list|()
value|(pcpup)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|get_pcpu
parameter_list|()
value|__extension__ ({			  		\     	int id;								\         __asm __volatile("mrc p15, 0, %0, c0, c0, 5" : "=r" (id));	\     	(pcpup + (id& CPU_MASK));					\     })
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|void
modifier|*
name|ret
decl_stmt|;
asm|__asm __volatile("mrc p15, 0, %0, c13, c0, 4" : "=r" (ret));
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_curthread
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
asm|__asm __volatile("mcr p15, 0, %0, c13, c0, 4" : : "r" (td));
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|get_tls
parameter_list|(
name|void
parameter_list|)
block|{
name|void
modifier|*
name|tls
decl_stmt|;
asm|__asm __volatile("mrc p15, 0, %0, c13, c0, 3" : "=r" (tls));
return|return
operator|(
name|tls
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_tls
parameter_list|(
name|void
modifier|*
name|tls
parameter_list|)
block|{
asm|__asm __volatile("mcr p15, 0, %0, c13, c0, 3" : : "r" (tls));
block|}
end_function

begin_define
define|#
directive|define
name|curthread
value|get_curthread()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|get_pcpu
parameter_list|()
value|pcpup
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
name|void
name|pcpu0_init
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

