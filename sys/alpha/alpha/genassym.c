begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)genassym.c	5.11 (Berkeley) 5/10/91  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
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
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/chipset.h>
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
file|<sys/user.h>
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

begin_include
include|#
directive|include
file|<nfs/nfsv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/rpcv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfsdiskless.h>
end_include

begin_expr_stmt
name|ASSYM
argument_list|(
name|P_ADDR
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|proc
argument_list|,
name|p_addr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|P_MD_FLAGS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|proc
argument_list|,
name|p_md
operator|.
name|md_flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|P_MD_PCBPADDR
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|proc
argument_list|,
name|p_md
operator|.
name|md_pcbpaddr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|P_MD_HAE
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|proc
argument_list|,
name|p_md
operator|.
name|md_hae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|MDP_HAEUSED
argument_list|,
name|MDP_HAEUSED
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|CHIPSET_WRITE_HAE
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|alpha_chipset
argument_list|,
name|write_hae
argument_list|)
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
name|PTLEV1I
argument_list|,
name|PTLEV1I
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PTESIZE
argument_list|,
name|PTESIZE
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
name|user
argument_list|,
name|u_pcb
operator|.
name|pcb_onfault
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|U_PCB_HWPCB_KSP
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|user
argument_list|,
name|u_pcb
operator|.
name|pcb_hw
operator|.
name|apcb_ksp
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
name|user
argument_list|,
name|u_pcb
operator|.
name|pcb_context
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|PCB_HW
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|pcb
argument_list|,
name|pcb_hw
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FPREG_FPR_REGS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|fpreg
argument_list|,
name|fpr_regs
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FPREG_FPR_CR
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|fpreg
argument_list|,
name|fpr_cr
argument_list|)
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

begin_comment
comment|/* Register offsets, for stack frames. */
end_comment

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_V0
argument_list|,
name|FRAME_V0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T0
argument_list|,
name|FRAME_T0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T1
argument_list|,
name|FRAME_T1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T2
argument_list|,
name|FRAME_T2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T3
argument_list|,
name|FRAME_T3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T4
argument_list|,
name|FRAME_T4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T5
argument_list|,
name|FRAME_T5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T6
argument_list|,
name|FRAME_T6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T7
argument_list|,
name|FRAME_T7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_S0
argument_list|,
name|FRAME_S0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_S1
argument_list|,
name|FRAME_S1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_S2
argument_list|,
name|FRAME_S2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_S3
argument_list|,
name|FRAME_S3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_S4
argument_list|,
name|FRAME_S4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_S5
argument_list|,
name|FRAME_S5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_S6
argument_list|,
name|FRAME_S6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_A3
argument_list|,
name|FRAME_A3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_A4
argument_list|,
name|FRAME_A4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_A5
argument_list|,
name|FRAME_A5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T8
argument_list|,
name|FRAME_T8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T9
argument_list|,
name|FRAME_T9
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T10
argument_list|,
name|FRAME_T10
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T11
argument_list|,
name|FRAME_T11
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_RA
argument_list|,
name|FRAME_RA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_T12
argument_list|,
name|FRAME_T12
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_AT
argument_list|,
name|FRAME_AT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_SP
argument_list|,
name|FRAME_SP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_SW_SIZE
argument_list|,
name|FRAME_SW_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_PS
argument_list|,
name|FRAME_PS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_PC
argument_list|,
name|FRAME_PC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_GP
argument_list|,
name|FRAME_GP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_A0
argument_list|,
name|FRAME_A0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_A1
argument_list|,
name|FRAME_A1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_A2
argument_list|,
name|FRAME_A2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|FRAME_SIZE
argument_list|,
name|FRAME_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* bits of the PS register */
end_comment

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PSL_USERMODE
argument_list|,
name|ALPHA_PSL_USERMODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PSL_IPL_MASK
argument_list|,
name|ALPHA_PSL_IPL_MASK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PSL_IPL_0
argument_list|,
name|ALPHA_PSL_IPL_0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PSL_IPL_SOFT
argument_list|,
name|ALPHA_PSL_IPL_SOFT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PSL_IPL_HIGH
argument_list|,
name|ALPHA_PSL_IPL_HIGH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* pte bits */
end_comment

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_L1SHIFT
argument_list|,
name|ALPHA_L1SHIFT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_L2SHIFT
argument_list|,
name|ALPHA_L2SHIFT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_L3SHIFT
argument_list|,
name|ALPHA_L3SHIFT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_K1SEG_BASE
argument_list|,
name|ALPHA_K1SEG_BASE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PTE_VALID
argument_list|,
name|ALPHA_PTE_VALID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PTE_ASM
argument_list|,
name|ALPHA_PTE_ASM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PTE_KR
argument_list|,
name|ALPHA_PTE_KR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_PTE_KW
argument_list|,
name|ALPHA_PTE_KW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Kernel entries */
end_comment

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_KENTRY_ARITH
argument_list|,
name|ALPHA_KENTRY_ARITH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_KENTRY_MM
argument_list|,
name|ALPHA_KENTRY_MM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_KENTRY_IF
argument_list|,
name|ALPHA_KENTRY_IF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|ALPHA_KENTRY_UNA
argument_list|,
name|ALPHA_KENTRY_UNA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|VPTBASE
argument_list|,
name|VPTBASE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|KERNBASE
argument_list|,
name|KERNBASE
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

