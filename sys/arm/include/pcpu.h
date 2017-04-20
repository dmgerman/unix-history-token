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
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
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

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|unsigned int pc_vfpsid;						\ 	unsigned int pc_vfpmvfr0;					\ 	unsigned int pc_vfpmvfr1;					\ 	struct pmap *pc_curpmap;					\ 	struct mtx pc_cmap_lock;					\ 	void *pc_cmap1_pte2p;						\ 	void *pc_cmap2_pte2p;						\ 	caddr_t pc_cmap1_addr;						\ 	caddr_t pc_cmap2_addr;						\ 	vm_offset_t pc_qmap_addr;					\ 	void *pc_qmap_pte2p;						\ 	unsigned int pc_dbreg[32];					\ 	int pc_dbreg_cmd;						\ 	char __pad[155]
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
value|char __pad[93]
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

begin_define
define|#
directive|define
name|PC_DBREG_CMD_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PC_DBREG_CMD_LOAD
value|1
end_define

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
name|__ARM_ARCH
operator|>=
literal|6
end_if

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
comment|/* TPIDRURW contains the authoritative value. */
asm|__asm __volatile("mrc p15, 0, %0, c13, c0, 2" : "=r" (tls));
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
comment|/* 	 * Update both TPIDRURW and TPIDRURO. TPIDRURW needs to be written 	 * first to ensure that a context switch between the two writes will 	 * still give the desired result of updating both. 	 */
asm|__asm __volatile(
literal|"mcr p15, 0, %0, c13, c0, 2\n"
literal|"mcr p15, 0, %0, c13, c0, 3\n"
operator|:
operator|:
literal|"r"
operator|(
name|tls
operator|)
block|)
function|;
end_function

begin_define
unit|}
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

begin_expr_stmt
unit|void
name|pcpu0_init
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

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

