begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_GLOBALS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_GLOBALS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|GLOBAL_LVALUE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|(*(type *)_global_ptr_##name())
end_define

begin_define
define|#
directive|define
name|GLOBAL_RVALUE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)_global_##name())
end_define

begin_comment
comment|/* non-volatile version */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_LVALUE_NV
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|(*(type *)_global_ptr_##name##_nv())
end_define

begin_define
define|#
directive|define
name|GLOBAL_RVALUE_NV
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)_global_##name##_nv())
end_define

begin_define
define|#
directive|define
name|GLOBAL_FUNC
parameter_list|(
name|name
parameter_list|)
define|\
value|static __inline void *_global_ptr_##name(void) { \ 		void *val; \ 		__asm __volatile("movl $gd_" #name ",%0;" \ 			"addl %%fs:globaldata,%0" : "=r" (val)); \ 		return (val); \ 	} \ 	static __inline void *_global_ptr_##name##_nv(void) { \ 		void *val; \ 		__asm("movl $gd_" #name ",%0;" \ 			"addl %%fs:globaldata,%0" : "=r" (val)); \ 		return (val); \ 	} \ 	static __inline int _global_##name(void) { \ 		int val; \ 		__asm __volatile("movl %%fs:gd_" #name ",%0" : "=r" (val)); \ 		return (val); \ 	} \ 	static __inline int _global_##name##_nv(void) { \ 		int val; \ 		__asm("movl %%fs:gd_" #name ",%0" : "=r" (val)); \ 		return (val); \ 	} \ 	static __inline void _global_##name##_set(int val) { \ 		__asm __volatile("movl %0,%%fs:gd_" #name : : "r" (val)); \ 	} \ 	static __inline void _global_##name##_set_nv(int val) { \ 		__asm("movl %0,%%fs:gd_" #name : : "r" (val)); \ 	}
end_define

begin_function
specifier|static
name|__inline
name|int
name|_global_globaldata
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|val
decl_stmt|;
asm|__asm("movl %%fs:globaldata,%0" : "=r" (val));
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_comment
comment|/*  * The following set of macros works for UP kernel as well, but for maximum  * performance we allow the global variables to be accessed directly. On the  * other hand, kernel modules should always use these macros to maintain  * portability between UP and SMP kernels.  */
end_comment

begin_define
define|#
directive|define
name|curproc
value|GLOBAL_RVALUE_NV(curproc, struct proc *)
end_define

begin_define
define|#
directive|define
name|curpcb
value|GLOBAL_RVALUE_NV(curpcb, struct pcb *)
end_define

begin_define
define|#
directive|define
name|npxproc
value|GLOBAL_RVALUE_NV(npxproc, struct proc *)
end_define

begin_define
define|#
directive|define
name|idleproc
value|GLOBAL_RVALUE_NV(idleproc, struct proc *)
end_define

begin_define
define|#
directive|define
name|common_tss
value|GLOBAL_LVALUE(common_tss, struct i386tss)
end_define

begin_define
define|#
directive|define
name|switchtime
value|GLOBAL_LVALUE(switchtime, struct timeval)
end_define

begin_define
define|#
directive|define
name|switchticks
value|GLOBAL_LVALUE(switchticks, int)
end_define

begin_define
define|#
directive|define
name|intr_nesting_level
value|GLOBAL_RVALUE(intr_nesting_level, u_char)
end_define

begin_define
define|#
directive|define
name|common_tssd
value|GLOBAL_LVALUE(common_tssd, struct segment_descriptor)
end_define

begin_define
define|#
directive|define
name|tss_gdt
value|GLOBAL_LVALUE(tss_gdt, struct segment_descriptor *)
end_define

begin_define
define|#
directive|define
name|astpending
value|GLOBAL_RVALUE(astpending, u_int)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USER_LDT
end_ifdef

begin_define
define|#
directive|define
name|currentldt
value|GLOBAL_RVALUE(currentldt, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|cpuid
value|GLOBAL_RVALUE(cpuid, u_int)
end_define

begin_define
define|#
directive|define
name|other_cpus
value|GLOBAL_LVALUE(other_cpus, u_int)
end_define

begin_define
define|#
directive|define
name|inside_intr
value|GLOBAL_LVALUE(inside_intr, int)
end_define

begin_define
define|#
directive|define
name|prv_CMAP1
value|GLOBAL_LVALUE(prv_CMAP1, pt_entry_t *)
end_define

begin_define
define|#
directive|define
name|prv_CMAP2
value|GLOBAL_LVALUE(prv_CMAP2, pt_entry_t *)
end_define

begin_define
define|#
directive|define
name|prv_CMAP3
value|GLOBAL_LVALUE(prv_CMAP3, pt_entry_t *)
end_define

begin_define
define|#
directive|define
name|prv_PMAP1
value|GLOBAL_LVALUE(prv_PMAP1, pt_entry_t *)
end_define

begin_define
define|#
directive|define
name|prv_CADDR1
value|GLOBAL_RVALUE(prv_CADDR1, caddr_t)
end_define

begin_define
define|#
directive|define
name|prv_CADDR2
value|GLOBAL_RVALUE(prv_CADDR2, caddr_t)
end_define

begin_define
define|#
directive|define
name|prv_CADDR3
value|GLOBAL_RVALUE(prv_CADDR3, caddr_t)
end_define

begin_define
define|#
directive|define
name|prv_PADDR1
value|GLOBAL_RVALUE(prv_PADDR1, unsigned *)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|witness_spin_check
value|GLOBAL_RVALUE(witness_spin_check, int)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(SMP || KLD_MODULE) */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|astpending
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP || KLD_MODULE */
end_comment

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|curproc
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|astpending
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|curpcb
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|npxproc
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|idleproc
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|common_tss
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|switchtime
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|switchticks
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|intr_nesting_level
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|common_tssd
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|tss_gdt
argument_list|)
end_macro

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KTR_PERCPU
end_ifdef

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|ktr_idx
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|ktr_buf
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|ktr_buf_data
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USER_LDT
end_ifdef

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|currentldt
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|cpuid
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|other_cpus
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|inside_intr
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|prv_CMAP1
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|prv_CMAP2
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|prv_CMAP3
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|prv_PMAP1
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|prv_CADDR1
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|prv_CADDR2
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|prv_CADDR3
argument_list|)
end_macro

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|prv_PADDR1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|GLOBAL_FUNC
argument_list|(
argument|witness_spin_check
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|GLOBALDATA
value|GLOBAL_RVALUE(globaldata, struct globaldata *)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GLOBALDATA
value|(&globaldata)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CURPROC
value|curproc
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
value|(_global_##name##_set((int)value))
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
comment|/* !_MACHINE_GLOBALS_H_ */
end_comment

end_unit

