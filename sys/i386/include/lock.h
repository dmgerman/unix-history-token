begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: lock.h,v 1.4 1997/09/07 22:01:39 fsmp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_LOCK_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MPLOCKED
value|lock ;
end_define

begin_comment
comment|/*  * Some handy macros to allow logical organization and  * convenient reassignment of various locks.  */
end_comment

begin_define
define|#
directive|define
name|FPU_LOCK
value|call	_get_fpu_lock
end_define

begin_define
define|#
directive|define
name|ALIGN_LOCK
value|call	_get_align_lock
end_define

begin_define
define|#
directive|define
name|SYSCALL_LOCK
value|call	_get_syscall_lock
end_define

begin_define
define|#
directive|define
name|ALTSYSCALL_LOCK
value|call	_get_altsyscall_lock
end_define

begin_comment
comment|/*  * Protects INTR() ISRs.  */
end_comment

begin_define
define|#
directive|define
name|ISR_TRYLOCK
define|\
value|pushl	$_mp_lock ;
comment|/* GIANT_LOCK */
value|\ 	call	_MPtrylock ;
comment|/* try to get lock */
value|\ 	add	$4, %esp
end_define

begin_define
define|#
directive|define
name|ISR_RELLOCK
define|\
value|pushl	$_mp_lock ;
comment|/* GIANT_LOCK */
value|\ 	call	_MPrellock ;						\ 	add	$4, %esp
end_define

begin_comment
comment|/*  * Protects the IO APIC and apic_imen as a critical region.  */
end_comment

begin_define
define|#
directive|define
name|IMASK_LOCK
define|\
value|pushl	$_imen_lock ;
comment|/* address of lock */
value|\ 	call	_s_lock ;
comment|/* MP-safe */
value|\ 	addl	$4, %esp
end_define

begin_define
define|#
directive|define
name|IMASK_UNLOCK
define|\
value|pushl	$_imen_lock ;
comment|/* address of lock */
value|\ 	call	_s_unlock ;
comment|/* MP-safe */
value|\ 	addl	$4, %esp
end_define

begin_comment
comment|/*  * Variations of CPL_LOCK protect spl updates as a critical region.  * Items within this 'region' include:  *  cpl  *  cml  *  cil  *  ipending  */
end_comment

begin_comment
comment|/*  * Botom half routines, ie. those already protected from INTs.  *  * Used in:  *  sys/i386/i386/microtime.s (XXX currently NOT used, possible race?)  *  sys/i386/isa/ipl.s:		_doreti  *  sys/i386/isa/apic_vector.s:	_Xintr0, ..., _Xintr23  */
end_comment

begin_define
define|#
directive|define
name|CPL_LOCK
define|\
value|pushl	$_cpl_lock ;
comment|/* address of lock */
value|\ 	call	_s_lock ;
comment|/* MP-safe */
value|\ 	addl	$4, %esp
end_define

begin_define
define|#
directive|define
name|CPL_UNLOCK
define|\
value|pushl	$_cpl_lock ;
comment|/* address of lock */
value|\ 	call	_s_unlock ;
comment|/* MP-safe */
value|\ 	addl	$4, %esp
end_define

begin_comment
comment|/*  * INT safe version for top half of kernel.  *  * Used in:  *  sys/i386/i386/exception.s:	_Xfpu, _Xalign, _Xsyscall, _Xint0x80_syscall  *  sys/i386/isa/apic_ipl.s:	splz()  */
end_comment

begin_define
define|#
directive|define
name|SCPL_LOCK
define|\
value|pushl	$_cpl_lock ;						\ 	call	_ss_lock ;						\ 	addl	$4, %esp
end_define

begin_define
define|#
directive|define
name|SCPL_UNLOCK
define|\
value|pushl	$_cpl_lock ;						\ 	call	_ss_unlock ;						\ 	addl	$4, %esp
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|MPLOCKED
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|FPU_LOCK
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|ALIGN_LOCK
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|SYSCALL_LOCK
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|ALTSYSCALL_LOCK
end_define

begin_comment
comment|/* NOP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LOCORE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_include
include|#
directive|include
file|<machine/smptests.h>
end_include

begin_comment
comment|/** xxx_LOCK */
end_comment

begin_comment
comment|/*  * Locks regions protected in UP kernel via cli/sti.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MPINTRLOCK
end_ifdef

begin_define
define|#
directive|define
name|MPINTR_LOCK
parameter_list|()
value|s_lock(&mpintr_lock)
end_define

begin_define
define|#
directive|define
name|MPINTR_UNLOCK
parameter_list|()
value|s_unlock(&mpintr_lock)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MPINTR_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|MPINTR_UNLOCK
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_MPINTRLOCK */
end_comment

begin_comment
comment|/*  * Protects cpl/cml/cil/ipending data as a critical region.  *  * Used in:  *  sys/i386/isa/ipl_funcs.c:	DO_SETBITS, softclockpending(), GENSPL,  *				spl0(), splx(), splq()  */
end_comment

begin_define
define|#
directive|define
name|CPL_LOCK
parameter_list|()
value|s_lock(&cpl_lock)
end_define

begin_comment
comment|/* Bottom end */
end_comment

begin_define
define|#
directive|define
name|CPL_UNLOCK
parameter_list|()
value|s_unlock(&cpl_lock)
end_define

begin_define
define|#
directive|define
name|SCPL_LOCK
parameter_list|()
value|ss_lock(&cpl_lock)
end_define

begin_comment
comment|/* INT safe: top end */
end_comment

begin_define
define|#
directive|define
name|SCPL_UNLOCK
parameter_list|()
value|ss_unlock(&cpl_lock)
end_define

begin_comment
comment|/*  * sio/cy lock.  * XXX should rc (RISCom/8) use this?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_COMLOCK
end_ifdef

begin_define
define|#
directive|define
name|COM_LOCK
parameter_list|()
value|s_lock(&com_lock)
end_define

begin_define
define|#
directive|define
name|COM_UNLOCK
parameter_list|()
value|s_unlock(&com_lock)
end_define

begin_define
define|#
directive|define
name|COM_DISABLE_INTR
parameter_list|()
define|\
value|{ __asm __volatile("cli" : : : "memory"); COM_LOCK(); }
end_define

begin_define
define|#
directive|define
name|COM_ENABLE_INTR
parameter_list|()
define|\
value|{ COM_UNLOCK(); __asm __volatile("sti"); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COM_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|COM_UNLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|COM_DISABLE_INTR
parameter_list|()
value|disable_intr()
end_define

begin_define
define|#
directive|define
name|COM_ENABLE_INTR
parameter_list|()
value|enable_intr()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_COMLOCK */
end_comment

begin_comment
comment|/*   * Clock hardware/struct lock.  * XXX pcaudio and friends still need this lock installed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_CLOCKLOCK
end_ifdef

begin_define
define|#
directive|define
name|CLOCK_LOCK
parameter_list|()
value|s_lock(&clock_lock)
end_define

begin_define
define|#
directive|define
name|CLOCK_UNLOCK
parameter_list|()
value|s_unlock(&clock_lock)
end_define

begin_define
define|#
directive|define
name|CLOCK_DISABLE_INTR
parameter_list|()
define|\
value|{ __asm __volatile("cli" : : : "memory"); CLOCK_LOCK(); }
end_define

begin_define
define|#
directive|define
name|CLOCK_ENABLE_INTR
parameter_list|()
define|\
value|{ CLOCK_UNLOCK(); __asm __volatile("sti"); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLOCK_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|CLOCK_UNLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|CLOCK_DISABLE_INTR
parameter_list|()
value|disable_intr()
end_define

begin_define
define|#
directive|define
name|CLOCK_ENABLE_INTR
parameter_list|()
value|enable_intr()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_CLOCKLOCK */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|MPINTR_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|MPINTR_UNLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|CPL_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|CPL_UNLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|SCPL_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|SCPL_UNLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|COM_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|COM_UNLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|CLOCK_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|CLOCK_UNLOCK
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_comment
comment|/*  * Simple spin lock.  * It is an error to hold one of these locks while a process is sleeping.  */
end_comment

begin_struct
struct|struct
name|simplelock
block|{
specifier|volatile
name|int
name|lock_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* functions in simplelock.s */
end_comment

begin_decl_stmt
name|void
name|s_lock_init
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|s_lock
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s_lock_try
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|s_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ss_lock
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ss_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|s_lock_np
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|s_unlock_np
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global data in mp_machdep.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|imen_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|cpl_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|fast_intr_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|intr_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|clock_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|com_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|mpintr_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|mcount_lock
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIMPLELOCK_DEBUG
argument_list|)
operator|&&
name|NCPUS
operator|>
literal|1
end_if

begin_comment
comment|/*  * This set of defines turns on the real functions in i386/isa/apic_ipl.s.  */
end_comment

begin_define
define|#
directive|define
name|simple_lock_init
parameter_list|(
name|alp
parameter_list|)
value|s_lock_init(alp)
end_define

begin_define
define|#
directive|define
name|simple_lock
parameter_list|(
name|alp
parameter_list|)
value|s_lock(alp)
end_define

begin_define
define|#
directive|define
name|simple_lock_try
parameter_list|(
name|alp
parameter_list|)
value|s_lock_try(alp)
end_define

begin_define
define|#
directive|define
name|simple_unlock
parameter_list|(
name|alp
parameter_list|)
value|s_unlock(alp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SIMPLELOCK_DEBUG&& NCPUS> 1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_LOCK_H_ */
end_comment

end_unit

