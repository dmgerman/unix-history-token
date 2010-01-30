begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)genassym.c	5.11 (Berkeley) 5/10/91  *	from: src/sys/i386/i386/genassym.c,v 1.86.2.1 2000/05/16 06:58:06 dillon  *	JNPR: genassym.c,v 1.4 2007/08/09 11:23:32 katta  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/assym.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/sigframe.h>
end_include

begin_include
include|#
directive|include
file|<machine/proc.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|(int)((&((t *)0L)->m))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|ASSYM
argument_list|(
name|TD_PCB
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|thread
argument_list|,
name|td_pcb
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TD_UPTE
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|thread
argument_list|,
name|td_md
operator|.
name|md_upte
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TD_REALKSTACK
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|thread
argument_list|,
name|td_md
operator|.
name|md_realstack
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TD_FLAGS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|thread
argument_list|,
name|td_flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TD_LOCK
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|thread
argument_list|,
name|td_lock
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TD_FRAME
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|thread
argument_list|,
name|td_frame
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TD_TLS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|thread
argument_list|,
name|td_md
operator|.
name|md_tls
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TF_REG_SR
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|trapframe
argument_list|,
name|sr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|U_PCB_REGS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcb
argument_list|,
name|pcb_regs
operator|.
name|zero
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|U_PCB_CONTEXT
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcb
argument_list|,
name|pcb_context
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|U_PCB_ONFAULT
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcb
argument_list|,
name|pcb_onfault
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|U_PCB_FPREGS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcb
argument_list|,
name|pcb_regs
operator|.
name|f0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PC_CURPCB
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcpu
argument_list|,
name|pc_curpcb
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PC_SEGBASE
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcpu
argument_list|,
name|pc_segbase
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PC_CURTHREAD
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcpu
argument_list|,
name|pc_curthread
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PC_FPCURTHREAD
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcpu
argument_list|,
name|pc_fpcurthread
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PC_CPUID
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcpu
argument_list|,
name|pc_cpuid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PC_CURPMAP
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcpu
argument_list|,
name|pc_curpmap
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|VM_MAX_KERNEL_ADDRESS
argument_list|,
name|VM_MAX_KERNEL_ADDRESS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|VM_MAXUSER_ADDRESS
argument_list|,
name|VM_MAXUSER_ADDRESS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|VM_KERNEL_ALLOC_OFFSET
argument_list|,
name|VM_KERNEL_ALLOC_OFFSET
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SIGF_UC
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|sigframe
argument_list|,
name|sf_uc
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SIGFPE
argument_list|,
name|SIGFPE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PAGE_SHIFT
argument_list|,
name|PAGE_SHIFT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PGSHIFT
argument_list|,
name|PGSHIFT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|NBPG
argument_list|,
name|NBPG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SEGSHIFT
argument_list|,
name|SEGSHIFT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|NPTEPG
argument_list|,
name|NPTEPG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TDF_NEEDRESCHED
argument_list|,
name|TDF_NEEDRESCHED
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|TDF_ASTPENDING
argument_list|,
name|TDF_ASTPENDING
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PCPU_SIZE
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|MAXCOMLEN
argument_list|,
name|MAXCOMLEN
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

