begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) Peter Wemm  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
literal|"sys/cdefs.h is a prerequisite for this file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<machine/tss.h>
end_include

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

begin_comment
comment|/*  * The SMP parts are setup in pmap.c and locore.s for the BSP, and  * mp_machdep.c sets up the data for the AP's to "see" when they awake.  * The reason for doing it via a struct is so that an array of pointers  * to each CPU's data can be set up for things like "check curproc on all  * other processors"  */
end_comment

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|char	pc_monitorbuf[128] __aligned(128);
comment|/* cache line */
value|\ 	struct	pcpu *pc_prvspace;
comment|/* Self-reference */
value|\ 	struct	pmap *pc_curpmap;					\ 	struct	i386tss pc_common_tss;					\ 	struct	segment_descriptor pc_common_tssd;			\ 	struct	segment_descriptor *pc_tss_gdt;				\ 	struct	segment_descriptor *pc_fsgs_gdt;			\ 	int	pc_currentldt;						\ 	u_int   pc_acpi_id;
comment|/* ACPI CPU id */
value|\ 	u_int	pc_apic_id;						\ 	int	pc_private_tss;
comment|/* Flag indicating private tss*/
value|\ 	u_int	pc_cmci_mask;
comment|/* MCx banks for CMCI */
value|\ 	u_int	pc_vcpu_id;
comment|/* Xen vCPU ID */
value|\ 	struct	mtx pc_cmap_lock;					\ 	void	*pc_cmap_pte1;						\ 	void	*pc_cmap_pte2;						\ 	caddr_t	pc_cmap_addr1;						\ 	caddr_t	pc_cmap_addr2;						\ 	vm_offset_t pc_qmap_addr;
comment|/* KVA for temporary mappings */
value|\ 	uint32_t pc_smp_tlb_done;
comment|/* TLB op acknowledgement */
value|\ 	char	__pad[445]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pcpu
modifier|*
name|pcpup
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|get_pcpu
parameter_list|()
value|(pcpup)
end_define

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|(pcpup->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_ADD
parameter_list|(
name|member
parameter_list|,
name|val
parameter_list|)
value|(pcpup->pc_ ## member += (val))
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
value|(&pcpup->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|val
parameter_list|)
value|(pcpup->pc_ ## member = (val))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUCLIKE_ASM
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUCLIKE___TYPEOF
argument_list|)
end_elif

begin_comment
comment|/*  * Evaluates to the byte offset of the per-cpu variable name.  */
end_comment

begin_define
define|#
directive|define
name|__pcpu_offset
parameter_list|(
name|name
parameter_list|)
define|\
value|__offsetof(struct pcpu, name)
end_define

begin_comment
comment|/*  * Evaluates to the type of the per-cpu variable name.  */
end_comment

begin_define
define|#
directive|define
name|__pcpu_type
parameter_list|(
name|name
parameter_list|)
define|\
value|__typeof(((struct pcpu *)0)->name)
end_define

begin_comment
comment|/*  * Evaluates to the address of the per-cpu variable name.  */
end_comment

begin_define
define|#
directive|define
name|__PCPU_PTR
parameter_list|(
name|name
parameter_list|)
value|__extension__ ({				\ 	__pcpu_type(name) *__p;						\ 									\ 	__asm __volatile("movl %%fs:%1,%0; addl %2,%0"			\ 	    : "=r" (__p)						\ 	    : "m" (*(struct pcpu *)(__pcpu_offset(pc_prvspace))),	\ 	      "i" (__pcpu_offset(name)));				\ 									\ 	__p;								\ })
end_define

begin_comment
comment|/*  * Evaluates to the value of the per-cpu variable name.  */
end_comment

begin_define
define|#
directive|define
name|__PCPU_GET
parameter_list|(
name|name
parameter_list|)
value|__extension__ ({				\ 	__pcpu_type(name) __res;					\ 	struct __s {							\ 		u_char	__b[MIN(sizeof(__res), 4)];			\ 	} __s;								\ 									\ 	if (sizeof(__res) == 1 || sizeof(__res) == 2 ||			\ 	    sizeof(__res) == 4) {					\ 		__asm __volatile("mov %%fs:%1,%0"			\ 		    : "=r" (__s)					\ 		    : "m" (*(struct __s *)(__pcpu_offset(name))));	\ 		*(struct __s *)(void *)&__res = __s;			\ 	} else {							\ 		__res = *__PCPU_PTR(name);				\ 	}								\ 	__res;								\ })
end_define

begin_comment
comment|/*  * Adds a value of the per-cpu counter name.  The implementation  * must be atomic with respect to interrupts.  */
end_comment

begin_define
define|#
directive|define
name|__PCPU_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	__pcpu_type(name) __val;					\ 	struct __s {							\ 		u_char	__b[MIN(sizeof(__val), 4)];			\ 	} __s;								\ 									\ 	__val = (val);							\ 	if (sizeof(__val) == 1 || sizeof(__val) == 2 ||			\ 	    sizeof(__val) == 4) {					\ 		__s = *(struct __s *)(void *)&__val;			\ 		__asm __volatile("add %1,%%fs:%0"			\ 		    : "=m" (*(struct __s *)(__pcpu_offset(name)))	\ 		    : "r" (__s));					\ 	} else								\ 		*__PCPU_PTR(name) += __val;				\ } while (0)
end_define

begin_comment
comment|/*  * Increments the value of the per-cpu counter name.  The implementation  * must be atomic with respect to interrupts.  */
end_comment

begin_define
define|#
directive|define
name|__PCPU_INC
parameter_list|(
name|name
parameter_list|)
value|do {						\ 	CTASSERT(sizeof(__pcpu_type(name)) == 1 ||			\ 	    sizeof(__pcpu_type(name)) == 2 ||				\ 	    sizeof(__pcpu_type(name)) == 4);				\ 	if (sizeof(__pcpu_type(name)) == 1) {				\ 		__asm __volatile("incb %%fs:%0"				\ 		    : "=m" (*(__pcpu_type(name) *)(__pcpu_offset(name)))\ 		    : "m" (*(__pcpu_type(name) *)(__pcpu_offset(name))));\ 	} else if (sizeof(__pcpu_type(name)) == 2) {			\ 		__asm __volatile("incw %%fs:%0"				\ 		    : "=m" (*(__pcpu_type(name) *)(__pcpu_offset(name)))\ 		    : "m" (*(__pcpu_type(name) *)(__pcpu_offset(name))));\ 	} else if (sizeof(__pcpu_type(name)) == 4) {			\ 		__asm __volatile("incl %%fs:%0"				\ 		    : "=m" (*(__pcpu_type(name) *)(__pcpu_offset(name)))\ 		    : "m" (*(__pcpu_type(name) *)(__pcpu_offset(name))));\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Sets the value of the per-cpu variable name to value val.  */
end_comment

begin_define
define|#
directive|define
name|__PCPU_SET
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	__pcpu_type(name) __val;					\ 	struct __s {							\ 		u_char	__b[MIN(sizeof(__val), 4)];			\ 	} __s;								\ 									\ 	__val = (val);							\ 	if (sizeof(__val) == 1 || sizeof(__val) == 2 ||			\ 	    sizeof(__val) == 4) {					\ 		__s = *(struct __s *)(void *)&__val;			\ 		__asm __volatile("mov %1,%%fs:%0"			\ 		    : "=m" (*(struct __s *)(__pcpu_offset(name)))	\ 		    : "r" (__s));					\ 	} else {							\ 		*__PCPU_PTR(name) = __val;				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|get_pcpu
parameter_list|()
value|__extension__ ({					\ 	struct pcpu *__pc;						\ 									\ 	__asm __volatile("movl %%fs:%1,%0"				\ 	    : "=r" (__pc)						\ 	    : "m" (*(struct pcpu *)(__pcpu_offset(pc_prvspace))));	\ 	__pc;								\ })
end_define

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|__PCPU_GET(pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_ADD
parameter_list|(
name|member
parameter_list|,
name|val
parameter_list|)
value|__PCPU_ADD(pc_ ## member, val)
end_define

begin_define
define|#
directive|define
name|PCPU_INC
parameter_list|(
name|member
parameter_list|)
value|__PCPU_INC(pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|member
parameter_list|)
value|__PCPU_PTR(pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|val
parameter_list|)
value|__PCPU_SET(pc_ ## member, val)
end_define

begin_define
define|#
directive|define
name|OFFSETOF_CURTHREAD
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wnull-dereference"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
specifier|static
name|__inline
name|__pure2
expr|struct
name|thread
operator|*
name|__curthread
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|thread
operator|*
name|td
block|;
asm|__asm("movl %%fs:%1,%0" : "=r" (td)
operator|:
literal|"m"
operator|(
operator|*
operator|(
name|char
operator|*
operator|)
name|OFFSETOF_CURTHREAD
operator|)
block|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|td
operator|)
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|curthread
value|(__curthread())
end_define

begin_define
define|#
directive|define
name|OFFSETOF_CURPCB
value|16
end_define

begin_expr_stmt
unit|static
name|__inline
name|__pure2
expr|struct
name|pcb
operator|*
name|__curpcb
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|pcb
operator|*
name|pcb
block|;
asm|__asm("movl %%fs:%1,%0" : "=r" (pcb) : "m" (*(char *)OFFSETOF_CURPCB));
return|return
operator|(
name|pcb
operator|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|curpcb
value|(__curpcb())
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !lint || defined(__GNUCLIKE_ASM)&& defined(__GNUCLIKE___TYPEOF) */
end_comment

begin_error
error|#
directive|error
literal|"this file needs to be ported to your compiler"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint, etc. */
end_comment

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

