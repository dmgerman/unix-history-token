begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)genassym.c	5.11 (Berkeley) 5/10/91  *	$Id: genassym.c,v 1.6 1993/11/13 02:24:59 davidg Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/map.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/msgbuf.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|struct
name|proc
modifier|*
name|p
init|=
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|vmmeter
modifier|*
name|vm
init|=
operator|(
expr|struct
name|vmmeter
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|user
modifier|*
name|up
init|=
operator|(
expr|struct
name|user
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|rusage
modifier|*
name|rup
init|=
operator|(
expr|struct
name|rusage
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|uprof
modifier|*
name|uprof
init|=
operator|(
expr|struct
name|uprof
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|vmspace
modifier|*
name|vms
init|=
operator|(
expr|struct
name|vmspace
operator|*
operator|)
literal|0
decl_stmt|;
name|vm_map_t
name|map
init|=
operator|(
name|vm_map_t
operator|)
literal|0
decl_stmt|;
name|pmap_t
name|pmap
init|=
operator|(
name|pmap_t
operator|)
literal|0
decl_stmt|;
name|struct
name|pcb
modifier|*
name|pcb
init|=
operator|(
expr|struct
name|pcb
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|trapframe
modifier|*
name|tf
init|=
operator|(
expr|struct
name|trapframe
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|sigframe
modifier|*
name|sigf
init|=
operator|(
expr|struct
name|sigframe
operator|*
operator|)
literal|0
decl_stmt|;
specifier|register
name|unsigned
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"#define\tI386_CR3PAT %d\n"
argument_list|,
name|I386_CR3PAT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUDOT_SZ %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|user
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_LINK %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_forw
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_RLINK %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_back
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_VMSPACE %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_vmspace
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tVM_PMAP %d\n"
argument_list|,
operator|&
name|vms
operator|->
name|vm_pmap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_ADDR %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_addr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_PRI %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_priority
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_STAT %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_stat
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_WCHAN %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_wchan
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_FLAG %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_flag
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_PID %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_pid
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSSLEEP %d\n"
argument_list|,
name|SSLEEP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSRUN %d\n"
argument_list|,
name|SRUN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_SWTCH %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_swtch
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_TRAP %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_trap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_SYSCALL %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_syscall
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_INTR %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_intr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_SOFT %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_soft
argument_list|)
expr_stmt|;
comment|/*	printf("#define\tV_PDMA %d\n",&vm->v_pdma); */
name|printf
argument_list|(
literal|"#define\tV_FAULTS %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_faults
argument_list|)
expr_stmt|;
comment|/*	printf("#define\tV_PGREC %d\n",&vm->v_pgrec); */
comment|/*	printf("#define\tV_FASTPGREC %d\n",&vm->v_fastpgrec); */
name|printf
argument_list|(
literal|"#define\tUPAGES %d\n"
argument_list|,
name|UPAGES
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tHIGHPAGES %d\n"
argument_list|,
name|HIGHPAGES
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCLSIZE %d\n"
argument_list|,
name|CLSIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNBPG %d\n"
argument_list|,
name|NBPG
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNPTEPG %d\n"
argument_list|,
name|NPTEPG
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPDESIZE %d\n"
argument_list|,
name|PDESIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPTESIZE %d\n"
argument_list|,
name|PTESIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNKPDE %d\n"
argument_list|,
name|NKPDE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNKPT %d\n"
argument_list|,
name|NKPT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tKPTDI 0x%x\n"
argument_list|,
name|KPTDI
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tKSTKPTDI 0x%x\n"
argument_list|,
name|KSTKPTDI
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tKSTKPTEOFF 0x%x\n"
argument_list|,
name|KSTKPTEOFF
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPTDPTDI 0x%x\n"
argument_list|,
name|PTDPTDI
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tAPTDPTDI 0x%x\n"
argument_list|,
name|APTDPTDI
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPGSHIFT %d\n"
argument_list|,
name|PGSHIFT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPDRSHIFT %d\n"
argument_list|,
name|PDRSHIFT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSYSPTSIZE %d\n"
argument_list|,
name|SYSPTSIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUSRPTSIZE %d\n"
argument_list|,
name|USRPTSIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUSRIOSIZE %d\n"
argument_list|,
name|USRIOSIZE
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SYSVSHM
name|printf
argument_list|(
literal|"#define\tSHMMAXPGS %d\n"
argument_list|,
name|SHMMAXPGS
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"#define\tUSRSTACK 0x%x\n"
argument_list|,
name|USRSTACK
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tVM_MAXUSER_ADDRESS 0x%x\n"
argument_list|,
name|VM_MAXUSER_ADDRESS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tKERNBASE 0x%x\n"
argument_list|,
name|KERNBASE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMSGBUFPTECNT %d\n"
argument_list|,
name|btoc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|msgbuf
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNMBCLUSTERS %d\n"
argument_list|,
name|NMBCLUSTERS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMCLBYTES %d\n"
argument_list|,
name|MCLBYTES
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_LINK %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_link
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ESP0 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_esp0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SS0 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ss0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ESP1 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_esp1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SS1 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ss1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ESP2 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_esp2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SS2 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ss2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_CR3 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_cr3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EIP %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_eip
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EFLAGS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_eflags
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EAX %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_eax
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ECX %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ecx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EDX %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_edx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EBX %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ebx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ESP %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_esp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EBP %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ebp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ESI %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_esi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_EDI %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_edi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ES %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_es
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_CS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_cs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ss
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_DS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ds
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_FS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_fs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_GS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_gs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_LDT %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ldt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_USERLDT %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ldt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_IOOPT %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_tss
operator|.
name|tss_ioopt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PROF %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_stats
operator|.
name|p_prof
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PROFSCALE %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_stats
operator|.
name|p_prof
operator|.
name|pr_scale
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPR_BASE %d\n"
argument_list|,
operator|&
name|uprof
operator|->
name|pr_base
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPR_SIZE %d\n"
argument_list|,
operator|&
name|uprof
operator|->
name|pr_size
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPR_OFF %d\n"
argument_list|,
operator|&
name|uprof
operator|->
name|pr_off
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPR_SCALE %d\n"
argument_list|,
operator|&
name|uprof
operator|->
name|pr_scale
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tRU_MINFLT %d\n"
argument_list|,
operator|&
name|rup
operator|->
name|ru_minflt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_FLAGS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_flags
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SAVEFPU %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_savefpu
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tFP_USESEMC %d\n"
argument_list|,
name|FP_USESEMC
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SAVEEMC %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_saveemc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_CMAP2 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_cmap2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_IML %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_iml
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ONFAULT %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_onfault
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ES %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_es
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_DS %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ds
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EDI %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_edi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ESI %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_esi
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EBP %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ebp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ISP %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_isp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EBX %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ebx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EDX %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_edx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ECX %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ecx
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EAX %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_eax
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_TRAPNO %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_trapno
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ERR %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_err
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EIP %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_eip
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_CS %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_cs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_EFLAGS %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_eflags
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_ESP %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_esp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tTF_SS %d\n"
argument_list|,
operator|&
name|tf
operator|->
name|tf_ss
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_SIGNUM %d\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_signum
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_CODE %d\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_code
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_SCP %d\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_scp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_HANDLER %d\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_handler
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGF_SC %d\n"
argument_list|,
operator|&
name|sigf
operator|->
name|sf_sc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tB_READ %d\n"
argument_list|,
name|B_READ
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tENOENT %d\n"
argument_list|,
name|ENOENT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tEFAULT %d\n"
argument_list|,
name|EFAULT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tENAMETOOLONG %d\n"
argument_list|,
name|ENAMETOOLONG
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

