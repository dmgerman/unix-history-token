begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)genassym.c	5.16 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)genassym.c	5.16 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_define
define|#
directive|define
name|KERNEL
end_define

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
name|p_link
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_RLINK %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_rlink
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
name|p_pri
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
literal|"#define\tUSRSTACK %d\n"
argument_list|,
name|USRSTACK
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
literal|"#define\tNKMEMCLUSTERS %d\n"
argument_list|,
name|NKMEMCLUSTERS
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
literal|"#define\tFP_WASUSED %d\n"
argument_list|,
name|FP_WASUSED
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tFP_NEEDSSAVE %d\n"
argument_list|,
name|FP_NEEDSSAVE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tFP_NEEDSRESTORE %d\n"
argument_list|,
name|FP_NEEDSRESTORE
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
literal|"#define\tPCB_SIGC %d\n"
argument_list|,
name|pcb
operator|->
name|pcb_sigc
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

