begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_compat.h"
end_include

begin_include
include|#
directive|include
file|"opt_kstack_pages.h"
end_include

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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
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
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<machine/pal.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
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
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_IA32
end_ifdef

begin_expr_stmt
name|ASSYM
argument_list|(
name|COMPAT_IA32
argument_list|,
name|COMPAT_IA32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|ASSYM
argument_list|(
name|DT_NULL
argument_list|,
name|DT_NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|DT_RELA
argument_list|,
name|DT_RELA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|DT_RELAENT
argument_list|,
name|DT_RELAENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|DT_RELASZ
argument_list|,
name|DT_RELASZ
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|DT_SYMTAB
argument_list|,
name|DT_SYMTAB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|DT_SYMENT
argument_list|,
name|DT_SYMENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|EFAULT
argument_list|,
name|EFAULT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ENAMETOOLONG
argument_list|,
name|ENAMETOOLONG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ERESTART
argument_list|,
name|ERESTART
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_SYSCALL
argument_list|,
name|FRAME_SYSCALL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|IA64_ID_PAGE_SHIFT
argument_list|,
name|IA64_ID_PAGE_SHIFT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|KSTACK_PAGES
argument_list|,
name|KSTACK_PAGES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|MC_PRESERVED
argument_list|,
name|offsetof
argument_list|(
name|mcontext_t
argument_list|,
name|mc_preserved
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|MC_PRESERVED_FP
argument_list|,
name|offsetof
argument_list|(
name|mcontext_t
argument_list|,
name|mc_preserved_fp
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|MC_SPECIAL
argument_list|,
name|offsetof
argument_list|(
name|mcontext_t
argument_list|,
name|mc_special
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|MC_SPECIAL_BSPSTORE
argument_list|,
name|offsetof
argument_list|(
name|mcontext_t
argument_list|,
name|mc_special
operator|.
name|bspstore
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|MC_SPECIAL_RNAT
argument_list|,
name|offsetof
argument_list|(
name|mcontext_t
argument_list|,
name|mc_special
operator|.
name|rnat
argument_list|)
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
name|PAGE_SIZE
argument_list|,
name|PAGE_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PC_CURRENT_PMAP
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcpu
argument_list|,
name|pc_md
operator|.
name|current_pmap
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
name|PC_IDLETHREAD
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcpu
argument_list|,
name|pc_idlethread
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PCB_CURRENT_PMAP
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcb
argument_list|,
name|pcb_current_pmap
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PCB_ONFAULT
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
name|PCB_SPECIAL_RP
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcb
argument_list|,
name|pcb_special
operator|.
name|rp
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|R_IA_64_DIR64LSB
argument_list|,
name|R_IA_64_DIR64LSB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|R_IA_64_FPTR64LSB
argument_list|,
name|R_IA_64_FPTR64LSB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|R_IA_64_NONE
argument_list|,
name|R_IA_64_NONE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|R_IA_64_REL64LSB
argument_list|,
name|R_IA_64_REL64LSB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SIZEOF_PCB
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pcb
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SIZEOF_SPECIAL
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|_special
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SIZEOF_TRAPFRAME
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|trapframe
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
name|TD_KSTACK
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|thread
argument_list|,
name|td_kstack
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|TDF_ASTPENDING
argument_list|,
name|TDF_ASTPENDING
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
name|UC_MCONTEXT
argument_list|,
name|offsetof
argument_list|(
name|ucontext_t
argument_list|,
name|uc_mcontext
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|VM_MAX_ADDRESS
argument_list|,
name|VM_MAX_ADDRESS
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

