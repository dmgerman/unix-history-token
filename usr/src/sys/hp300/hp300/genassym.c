begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)genassym.c	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_include
include|#
directive|include
file|"pte.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"vmmeter.h"
end_include

begin_include
include|#
directive|include
file|"vmparam.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_include
include|#
directive|include
file|"cmap.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"text.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"msgbuf.h"
end_include

begin_include
include|#
directive|include
file|"cpu.h"
end_include

begin_include
include|#
directive|include
file|"trap.h"
end_include

begin_include
include|#
directive|include
file|"psl.h"
end_include

begin_include
include|#
directive|include
file|"reg.h"
end_include

begin_include
include|#
directive|include
file|"clockreg.h"
end_include

begin_include
include|#
directive|include
file|"syscall.h"
end_include

begin_function
name|main
parameter_list|()
block|{
specifier|register
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
specifier|register
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
specifier|register
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
specifier|register
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
name|text
modifier|*
name|tp
init|=
operator|(
expr|struct
name|text
operator|*
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
literal|"#define\tP_XLINK %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_xlink
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
literal|"#define\tP_TSIZE %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_tsize
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_DSIZE %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_dsize
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_SSIZE %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_ssize
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_P0BR %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_p0br
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_SZPT %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_szpt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_TEXTP %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_textp
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
literal|"#define\tX_CADDR %d\n"
argument_list|,
operator|&
name|tp
operator|->
name|x_caddr
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
literal|"#define\tV_PDMA %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_pdma
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
literal|"#define\tV_PGREC %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_pgrec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_FASTPGREC %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_fastpgrec
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
literal|"#define\tP1PAGES %d\n"
argument_list|,
name|P1PAGES
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
literal|"#define\tPGSHIFT %d\n"
argument_list|,
name|PGSHIFT
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
literal|"#define\tNKMEMCLUSTERS %d\n"
argument_list|,
name|NKMEMCLUSTERS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PROCP %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_procp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_RU %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_ru
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PROF %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_prof
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PROFSCALE %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_prof
operator|.
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
literal|"#define\tT_BUSERR %d\n"
argument_list|,
name|T_BUSERR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_ADDRERR %d\n"
argument_list|,
name|T_ADDRERR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_ILLINST %d\n"
argument_list|,
name|T_ILLINST
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_ZERODIV %d\n"
argument_list|,
name|T_ZERODIV
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_CHKINST %d\n"
argument_list|,
name|T_CHKINST
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_TRAPVINST %d\n"
argument_list|,
name|T_TRAPVINST
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_PRIVINST %d\n"
argument_list|,
name|T_PRIVINST
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_TRACE %d\n"
argument_list|,
name|T_TRACE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_MMUFLT %d\n"
argument_list|,
name|T_MMUFLT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_SSIR %d\n"
argument_list|,
name|T_SSIR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_FMTERR %d\n"
argument_list|,
name|T_FMTERR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_COPERR %d\n"
argument_list|,
name|T_COPERR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_FPERR %d\n"
argument_list|,
name|T_FPERR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_AST %d\n"
argument_list|,
name|T_AST
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tT_TRAP15 %d\n"
argument_list|,
name|T_TRAP15
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPSL_S %d\n"
argument_list|,
name|PSL_S
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPSL_IPL7 %d\n"
argument_list|,
name|PSL_IPL7
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPSL_LOWIPL %d\n"
argument_list|,
name|PSL_LOWIPL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPSL_HIGHIPL %d\n"
argument_list|,
name|PSL_HIGHIPL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPSL_USER %d\n"
argument_list|,
name|PSL_USER
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSPL1 %d\n"
argument_list|,
name|PSL_S
operator||
name|PSL_IPL1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSPL2 %d\n"
argument_list|,
name|PSL_S
operator||
name|PSL_IPL2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSPL3 %d\n"
argument_list|,
name|PSL_S
operator||
name|PSL_IPL3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSPL4 %d\n"
argument_list|,
name|PSL_S
operator||
name|PSL_IPL4
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSPL5 %d\n"
argument_list|,
name|PSL_S
operator||
name|PSL_IPL5
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSPL6 %d\n"
argument_list|,
name|PSL_S
operator||
name|PSL_IPL6
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tFC_USERD %d\n"
argument_list|,
name|FC_USERD
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tFC_PURGE %d\n"
argument_list|,
name|FC_PURGE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMAXADDR %d\n"
argument_list|,
name|MAXADDR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tIOMAPSIZE %d\n"
argument_list|,
name|IOMAPSIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tIOBASE %d\n"
argument_list|,
name|IOBASE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMUSTAT %d\n"
argument_list|,
name|MMUSTAT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMUCMD %d\n"
argument_list|,
name|MMUCMD
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMUSSTP %d\n"
argument_list|,
name|MMUSSTP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMUUSTP %d\n"
argument_list|,
name|MMUUSTP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMUTBINVAL %d\n"
argument_list|,
name|MMUTBINVAL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMU_BERR %d\n"
argument_list|,
name|MMU_BERR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMU_ENAB %d\n"
argument_list|,
name|MMU_ENAB
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMU_FAULT %d\n"
argument_list|,
name|MMU_FAULT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMU_CEN %d\n"
argument_list|,
name|MMU_CEN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMU_IEN %d\n"
argument_list|,
name|MMU_IEN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMMU_FPE %d\n"
argument_list|,
name|MMU_FPE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCACHE_ON %d\n"
argument_list|,
name|CACHE_ON
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCACHE_OFF %d\n"
argument_list|,
name|CACHE_OFF
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCACHE_CLR %d\n"
argument_list|,
name|CACHE_CLR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tIC_CLEAR %d\n"
argument_list|,
name|IC_CLEAR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tDC_CLEAR %d\n"
argument_list|,
name|DC_CLEAR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPG_V %d\n"
argument_list|,
name|PG_V
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPG_NV %d\n"
argument_list|,
name|PG_NV
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPG_RO %d\n"
argument_list|,
name|PG_RO
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPG_RW %d\n"
argument_list|,
name|PG_RW
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPG_CI %d\n"
argument_list|,
name|PG_CI
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPG_PROT %d\n"
argument_list|,
name|PG_PROT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPG_FRAME %d\n"
argument_list|,
name|PG_FRAME
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSG_V %d\n"
argument_list|,
name|SG_V
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSG_NV %d\n"
argument_list|,
name|SG_NV
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSG_RW %d\n"
argument_list|,
name|SG_RW
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSG_FRAME %d\n"
argument_list|,
name|SG_FRAME
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
literal|"#define\tPCB_PS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ps
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_USTP %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ustp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_USP %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_usp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_REGS %d\n"
argument_list|,
name|pcb
operator|->
name|pcb_regs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_P0BR %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_p0br
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_P0LR %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_p0lr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_P1BR %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_p1br
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_P1LR %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_p1lr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SZPT %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_szpt
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
literal|"#define\tPCB_SSWAP %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_sswap
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
literal|"#define\tPCB_FPCTX %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_fpregs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSP %d\n"
argument_list|,
name|SP
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
literal|"#define\tCLKCR1 %d\n"
argument_list|,
name|CLKCR1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCLKCR2 %d\n"
argument_list|,
name|CLKCR2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCLKCR3 %d\n"
argument_list|,
name|CLKCR3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCLKSR %d\n"
argument_list|,
name|CLKSR
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCLKMSB1 %d\n"
argument_list|,
name|CLKMSB1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCLKMSB2 %d\n"
argument_list|,
name|CLKMSB2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCLKMSB3 %d\n"
argument_list|,
name|CLKMSB3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSYS_exit %d\n"
argument_list|,
name|SYS_exit
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSYS_execv %d\n"
argument_list|,
name|SYS_execv
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSYS_sigreturn %d\n"
argument_list|,
name|SYS_sigreturn
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
literal|1
operator|<<
name|i
operator|)
operator|&
name|SPTECHG
condition|)
name|printf
argument_list|(
literal|"#define\tSPTECHGB %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
literal|1
operator|<<
name|i
operator|)
operator|&
name|PCB_AST
condition|)
name|printf
argument_list|(
literal|"#define\tPCB_ASTB %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
literal|1
operator|<<
name|i
operator|)
operator|&
name|PCB_HPUXTRACE
condition|)
name|printf
argument_list|(
literal|"#define\tPCB_TRCB %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

