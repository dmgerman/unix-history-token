begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $NetBSD: trap.c,v 1.26 2000/05/27 00:40:40 sommerfeld Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_ktrace.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktrace.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_comment
comment|/* These definitions should probably be somewhere else				XXX */
end_comment

begin_define
define|#
directive|define
name|FIRSTARG
value|3
end_define

begin_comment
comment|/* first argument is in reg 3 */
end_comment

begin_define
define|#
directive|define
name|NARGREG
value|8
end_define

begin_comment
comment|/* 8 args are in registers */
end_comment

begin_define
define|#
directive|define
name|MOREARGS
parameter_list|(
name|sp
parameter_list|)
value|((caddr_t)((int)(sp) + 8))
end_define

begin_comment
comment|/* more args go here */
end_comment

begin_decl_stmt
specifier|volatile
name|int
name|astpending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|want_resched
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: not used yet */
end_comment

begin_endif
unit|static int fix_unaligned __P((struct proc *p, struct trapframe *frame));
endif|#
directive|endif
end_endif

begin_function
name|void
name|trap
parameter_list|(
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
block|{
if|#
directive|if
literal|0
comment|/* XXX: This code hasn't been reworked yet. */
block|struct proc *p; 	int type; 	u_int sticks;  	p = curproc; 	type = frame->exc;  	if (frame->srr1& PSL_PR) { 		type |= EXC_USER; 		sticks = p->p_sticks; 	}  	switch (type) { 	case EXC_TRC|EXC_USER: 		frame->srr1&= ~PSL_SE; 		trapsignal(p, SIGTRAP, EXC_TRC); 		break; 	case EXC_DSI: 		{ 			vm_map_t map; 			vaddr_t va; 			int ftype; 			faultbuf *fb; 			 			map = kernel_map; 			va = frame->dar; 			if ((va>> ADDR_SR_SHFT) == USER_SR) { 				sr_t user_sr; 				 				__asm ("mfsr %0, %1" 				     : "=r"(user_sr) : "K"(USER_SR)); 				va&= ADDR_PIDX | ADDR_POFF; 				va |= user_sr<< ADDR_SR_SHFT; 				map =&p->p_vmspace->vm_map; 			} 			if (frame->dsisr& DSISR_STORE) 				ftype = VM_PROT_READ | VM_PROT_WRITE; 			else 				ftype = VM_PROT_READ; 			if (uvm_fault(map, trunc_page(va), 0, ftype) 			    == KERN_SUCCESS) 				return; 			if (fb = p->p_addr->u_pcb.pcb_onfault) { 				frame->srr0 = (*fb)[0]; 				frame->fixreg[1] = (*fb)[1]; 				frame->fixreg[2] = (*fb)[2]; 				frame->cr = (*fb)[3]; 				bcopy(&(*fb)[4],&frame->fixreg[13], 				      19 * sizeof(register_t)); 				return; 			} 			map = kernel_map; 		} 		goto brain_damage; 	case EXC_DSI|EXC_USER: 		{ 			int ftype, rv; 			 			if (frame->dsisr& DSISR_STORE) 				ftype = VM_PROT_READ | VM_PROT_WRITE; 			else 				ftype = VM_PROT_READ; 			if ((rv = uvm_fault(&p->p_vmspace->vm_map, 					    trunc_page(frame->dar), 0, ftype)) 			    == KERN_SUCCESS) 				break; 			if (rv == KERN_RESOURCE_SHORTAGE) { 				printf("UVM: pid %d (%s), uid %d killed: " 				       "out of swap\n", 				       p->p_pid, p->p_comm, 				       p->p_cred&& p->p_ucred ? 				       p->p_ucred->cr_uid : -1); 				trapsignal(p, SIGKILL, EXC_DSI); 			} else { 				trapsignal(p, SIGSEGV, EXC_DSI); 			} 		} 		break; 	case EXC_ISI|EXC_USER: 		{ 			int ftype; 			 			ftype = VM_PROT_READ | VM_PROT_EXECUTE; 			if (uvm_fault(&p->p_vmspace->vm_map, 				     trunc_page(frame->srr0), 0, ftype) 			    == KERN_SUCCESS) 				break; 		} 		trapsignal(p, SIGSEGV, EXC_ISI); 		break; 	case EXC_SC|EXC_USER: 		{ 			struct sysent *callp; 			size_t argsize; 			register_t code, error; 			register_t *params, rval[2]; 			int nsys, n; 			register_t args[10]; 			 			uvmexp.syscalls++; 			 			nsys = p->p_emul->e_nsysent; 			callp = p->p_emul->e_sysent; 			 			code = frame->fixreg[0]; 			params = frame->fixreg + FIRSTARG; 			 			switch (code) { 			case SYS_syscall:
comment|/* 				 * code is first argument, 				 * followed by actual args. 				 */
block|code = *params++; 				break; 			case SYS___syscall:
comment|/* 				 * Like syscall, but code is a quad, 				 * so as to maintain quad alignment 				 * for the rest of the args. 				 */
block|if (callp != sysent) 					break; 				params++; 				code = *params++; 				break; 			default: 				break; 			} 			if (code< 0 || code>= nsys) 				callp += p->p_emul->e_nosys; 			else 				callp += code; 			argsize = callp->sy_argsize; 			n = NARGREG - (params - (frame->fixreg + FIRSTARG)); 			if (argsize> n * sizeof(register_t)) { 				bcopy(params, args, n * sizeof(register_t)); 				if (error = copyin(MOREARGS(frame->fixreg[1]), 						   args + n, 						   argsize - n * sizeof(register_t))) {
ifdef|#
directive|ifdef
name|KTRACE
comment|/* Can't get all the arguments! */
block|if (KTRPOINT(p, KTR_SYSCALL)) 						ktrsyscall(p, code, argsize, 						    args);
endif|#
directive|endif
block|goto syscall_bad; 				} 				params = args; 			}
ifdef|#
directive|ifdef
name|KTRACE
block|if (KTRPOINT(p, KTR_SYSCALL)) 				ktrsyscall(p, code, argsize, params);
endif|#
directive|endif
block|rval[0] = 0; 			rval[1] = frame->fixreg[FIRSTARG + 1]; 			 			switch (error = (*callp->sy_call)(p, params, rval)) { 			case 0: 				frame->fixreg[FIRSTARG] = rval[0]; 				frame->fixreg[FIRSTARG + 1] = rval[1]; 				frame->cr&= ~0x10000000; 				break; 			case ERESTART:
comment|/* 				 * Set user's pc back to redo the system call. 				 */
block|frame->srr0 -= 4; 				break; 			case EJUSTRETURN:
comment|/* nothing to do */
block|break; 			default: syscall_bad: 				if (p->p_emul->e_errno) 					error = p->p_emul->e_errno[error]; 				frame->fixreg[FIRSTARG] = error; 				frame->cr |= 0x10000000; 				break; 			}
ifdef|#
directive|ifdef
name|KTRACE
block|if (KTRPOINT(p, KTR_SYSRET)) 				ktrsysret(p, code, error, rval[0]);
endif|#
directive|endif
block|} 		break;  	case EXC_FPU|EXC_USER: 		if (fpuproc) 			save_fpu(fpuproc); 		fpuproc = p; 		enable_fpu(p); 		break;  	case EXC_AST|EXC_USER:
comment|/* This is just here that we trap */
block|break;  	case EXC_ALI|EXC_USER: 		if (fix_unaligned(p, frame) != 0) 			trapsignal(p, SIGBUS, EXC_ALI); 		else 			frame->srr0 += 4; 		break;  	case EXC_PGM|EXC_USER:
comment|/* XXX temporarily */
block|if (frame->srr1& 0x0002000) 			trapsignal(p, SIGTRAP, EXC_PGM); 		else 			trapsignal(p, SIGILL, EXC_PGM); 		break;  	case EXC_MCHK: 		{ 			faultbuf *fb;  			if (fb = p->p_addr->u_pcb.pcb_onfault) { 				frame->srr0 = (*fb)[0]; 				frame->fixreg[1] = (*fb)[1]; 				frame->fixreg[2] = (*fb)[2]; 				frame->cr = (*fb)[3]; 				bcopy(&(*fb)[4],&frame->fixreg[13], 				      19 * sizeof(register_t)); 				return; 			} 		} 		goto brain_damage;  	default: brain_damage: 		printf("trap type %x at %x\n", type, frame->srr0);
ifdef|#
directive|ifdef
name|DDB
block|Debugger();
comment|/* XXX temporarily */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TRAP_PANICWAIT
block|printf("Press a key to panic.\n"); 		cngetc();
endif|#
directive|endif
block|panic("trap"); 	}  	astpending = 0;
comment|/* we are about to do it */
block|uvmexp.softs++;  	if (p->p_flag& P_OWEUPC) { 		p->p_flag&= ~P_OWEUPC; 		ADDUPROF(p); 	}
comment|/* take pending signals */
block|{ 		int sig;  		while (sig = CURSIG(p)) 			postsig(sig); 	}  	p->p_priority = p->p_usrpri; 	if (want_resched) { 		int sig;
comment|/* 		 * We are being preempted. 		 */
block|preempt(NULL); 		while (sig = CURSIG(p)) 			postsig(sig); 	}
comment|/* 	 * If profiling, charge recent system time to the trapped pc. 	 */
block|if (p->p_flag& P_PROFIL) { 		extern int psratio;  		addupc_task(p, frame->srr0, 			    (int)(p->p_sticks - sticks) * psratio); 	}
comment|/* 	 * If someone stole the fpu while we were away, disable it 	 */
block|if (p != fpuproc) 		frame->srr1&= ~PSL_FP; 	curcpu()->ci_schedstate.spc_curpriority = p->p_priority;
endif|#
directive|endif
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: child_return not used */
end_comment

begin_comment
unit|void child_return(void *arg) { 	struct proc *p; 	struct trapframe *tf;  	p = arg; 	tf = trapframe(p);  	tf->fixreg[FIRSTARG] = 0; 	tf->fixreg[FIRSTARG + 1] = 1; 	tf->cr&= ~0x10000000; 	tf->srr1&= ~PSL_FP;
comment|/* Disable FPU, as we can't be fpuproc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KTRACE
end_ifdef

begin_endif
unit|if (KTRPOINT(p, KTR_SYSRET)) 		ktrsysret(p, SYS_fork, 0, 0);
endif|#
directive|endif
end_endif

begin_comment
comment|/* Profiling?							XXX */
end_comment

begin_endif
unit|curcpu()->ci_schedstate.spc_curpriority = p->p_priority; }
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|setusr
parameter_list|(
name|int
name|content
parameter_list|)
block|{
asm|__asm __volatile ("isync; mtsr %0,%1; isync"
operator|::
literal|"n"
operator|(
name|USER_SR
operator|)
operator|,
literal|"r"
operator|(
name|content
operator|)
block|)
function|;
end_function

begin_macro
unit|}  int
name|copyin
argument_list|(
argument|udaddr
argument_list|,
argument|kaddr
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
specifier|const
name|void
modifier|*
name|udaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|kaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|const
name|char
modifier|*
name|up
decl_stmt|;
name|char
modifier|*
name|kp
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|size_t
name|l
decl_stmt|;
name|faultbuf
name|env
decl_stmt|;
name|uint
name|segment
decl_stmt|;
name|up
operator|=
name|udaddr
expr_stmt|;
name|kp
operator|=
name|kaddr
expr_stmt|;
if|#
directive|if
literal|0
block|if (setfault(env)) { 		PCPU_GET(curpcb)->pcb_onfault = 0; 		return EFAULT; 	}
endif|#
directive|endif
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|p
operator|=
operator|(
name|char
operator|*
operator|)
name|USER_ADDR
operator|+
operator|(
operator|(
name|u_int
operator|)
name|up
operator|&
operator|~
name|SEGMENT_MASK
operator|)
expr_stmt|;
name|l
operator|=
operator|(
operator|(
name|char
operator|*
operator|)
name|USER_ADDR
operator|+
name|SEGMENT_LENGTH
operator|)
operator|-
name|p
expr_stmt|;
if|if
condition|(
name|l
operator|>
name|len
condition|)
name|l
operator|=
name|len
expr_stmt|;
name|segment
operator|=
operator|(
name|uint
operator|)
name|up
operator|>>
name|ADDR_SR_SHFT
expr_stmt|;
name|setusr
argument_list|(
name|PCPU_GET
argument_list|(
name|curpcb
argument_list|)
operator|->
name|pcb_pm
operator|->
name|pm_sr
index|[
name|segment
index|]
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|p
argument_list|,
name|kp
argument_list|,
name|l
argument_list|)
expr_stmt|;
name|up
operator|+=
name|l
expr_stmt|;
name|kp
operator|+=
name|l
expr_stmt|;
name|len
operator|-=
name|l
expr_stmt|;
block|}
name|PCPU_GET
argument_list|(
name|curpcb
argument_list|)
operator|->
name|pcb_onfault
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_function
name|int
name|copyout
parameter_list|(
name|kaddr
parameter_list|,
name|udaddr
parameter_list|,
name|len
parameter_list|)
specifier|const
name|void
modifier|*
name|kaddr
decl_stmt|;
name|void
modifier|*
name|udaddr
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|kp
decl_stmt|;
name|char
modifier|*
name|up
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|size_t
name|l
decl_stmt|;
name|faultbuf
name|env
decl_stmt|;
name|uint
name|segment
decl_stmt|;
name|kp
operator|=
name|kaddr
expr_stmt|;
name|up
operator|=
name|udaddr
expr_stmt|;
if|#
directive|if
literal|0
block|if (setfault(env)) { 		PCPU_GET(curpcb)->pcb_onfault = 0; 		return EFAULT; 	}
endif|#
directive|endif
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|p
operator|=
operator|(
name|char
operator|*
operator|)
name|USER_ADDR
operator|+
operator|(
operator|(
name|u_int
operator|)
name|up
operator|&
operator|~
name|SEGMENT_MASK
operator|)
expr_stmt|;
name|l
operator|=
operator|(
operator|(
name|char
operator|*
operator|)
name|USER_ADDR
operator|+
name|SEGMENT_LENGTH
operator|)
operator|-
name|p
expr_stmt|;
if|if
condition|(
name|l
operator|>
name|len
condition|)
name|l
operator|=
name|len
expr_stmt|;
name|segment
operator|=
operator|(
name|u_int
operator|)
name|up
operator|>>
name|ADDR_SR_SHFT
expr_stmt|;
name|setusr
argument_list|(
name|PCPU_GET
argument_list|(
name|curpcb
argument_list|)
operator|->
name|pcb_pm
operator|->
name|pm_sr
index|[
name|segment
index|]
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|kp
argument_list|,
name|p
argument_list|,
name|l
argument_list|)
expr_stmt|;
name|up
operator|+=
name|l
expr_stmt|;
name|kp
operator|+=
name|l
expr_stmt|;
name|len
operator|-=
name|l
expr_stmt|;
block|}
name|PCPU_GET
argument_list|(
name|curpcb
argument_list|)
operator|->
name|pcb_onfault
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: not used yet */
end_comment

begin_comment
comment|/*  * kcopy(const void *src, void *dst, size_t len);  *  * Copy len bytes from src to dst, aborting if we encounter a fatal  * page fault.  *  * kcopy() _must_ save and restore the old fault handler since it is  * called by uiomove(), which may be in the path of servicing a non-fatal  * page fault.  */
end_comment

begin_comment
unit|int kcopy(const void *src, void *dst, size_t len) { 	faultbuf env, *oldfault;  	oldfault = PCPU_GET(curpcb)->pcb_onfault; 	if (setfault(env)) { 		PCPU_GET(curpcb)->pcb_onfault = oldfault; 		return EFAULT; 	}  	bcopy(src, dst, len);  	PCPU_GET(curpcb)->pcb_onfault = oldfault; 	return 0; }  int badaddr(void *addr, size_t size) {  	return badaddr_read(addr, size, NULL); }  int badaddr_read(void *addr, size_t size, int *rptr) { 	faultbuf env; 	int x;
comment|/* Get rid of any stale machine checks that have been waiting.  */
end_comment

begin_comment
unit|__asm __volatile ("sync; isync");  	if (setfault(env)) { 		PCPU_GET(curpcb)->pcb_onfault = 0; 		__asm __volatile ("sync"); 		return 1; 	}  	__asm __volatile ("sync");  	switch (size) { 	case 1: 		x = *(volatile int8_t *)addr; 		break; 	case 2: 		x = *(volatile int16_t *)addr; 		break; 	case 4: 		x = *(volatile int32_t *)addr; 		break; 	default: 		panic("badaddr: invalid size (%d)", size); 	}
comment|/* Make sure we took the machine check, if we caused one. */
end_comment

begin_comment
unit|__asm __volatile ("sync; isync");  	PCPU_GET(curpcb)->pcb_onfault = 0; 	__asm __volatile ("sync");
comment|/* To be sure. */
end_comment

begin_comment
comment|/* Use the value to avoid reorder. */
end_comment

begin_endif
unit|if (rptr) 		*rptr = x;  	return 0; }
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For now, this only deals with the particular unaligned access case  * that gcc tends to generate.  Eventually it should handle all of the  * possibilities that can happen on a 32-bit PowerPC in big-endian mode.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: Not used yet */
end_comment

begin_comment
unit|static int fix_unaligned(p, frame) 	struct proc *p; 	struct trapframe *frame; { 	int indicator; 	 	indicator = EXC_ALI_OPCODE_INDICATOR(frame->dsisr);  	switch (indicator) { 	case EXC_ALI_LFD: 	case EXC_ALI_STFD: 		{ 			int reg = EXC_ALI_RST(frame->dsisr); 			double *fpr =&p->p_addr->u_pcb.pcb_fpu.fpr[reg];
comment|/* Juggle the FPU to ensure that we've initialized 			 * the FPRs, and that their current state is in 			 * the PCB. 			 */
end_comment

begin_endif
unit|if (fpuproc != p) { 				if (fpuproc) 					save_fpu(fpuproc); 				enable_fpu(p); 			} 			save_fpu(p);  			if (indicator == EXC_ALI_LFD) { 				if (copyin((void *)frame->dar, fpr, 				    sizeof(double)) != 0) 					return -1; 				enable_fpu(p); 			} else { 				if (copyout(fpr, (void *)frame->dar, 				    sizeof(double)) != 0) 					return -1; 			} 			return 0; 		} 		break; 	}  	return -1; }
endif|#
directive|endif
end_endif

end_unit

