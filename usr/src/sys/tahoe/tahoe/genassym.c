begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983, 1988 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)genassym.c	7.6 (Berkeley) %G%"
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
file|"param.h"
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
file|"buf.h"
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
file|"pte.h"
end_include

begin_include
include|#
directive|include
file|"scb.h"
end_include

begin_include
include|#
directive|include
file|"../tahoevba/vbaparam.h"
end_include

begin_function
name|main
parameter_list|()
block|{
specifier|register
name|struct
name|user
modifier|*
name|u
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
name|struct
name|scb
modifier|*
name|scb
init|=
operator|(
expr|struct
name|scb
operator|*
operator|)
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"#ifdef LOCORE\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PROCP %d\n"
argument_list|,
operator|&
name|u
operator|->
name|u_procp
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
literal|"#define\tP_DKEY %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_dkey
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_CKEY %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_ckey
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
literal|"#define\tV_FPE %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_fpe
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_ALIGN %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_align
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
literal|"#define\tUPAGES %d\n"
argument_list|,
name|UPAGES
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
literal|"#define\tMAXPHYS %d\n"
argument_list|,
name|MAXPHYS
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
literal|"#define\tVBIOSIZE %d\n"
argument_list|,
name|VBIOSIZE
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
literal|"#define\tNKMEMCLUSTERS %d\n"
argument_list|,
name|NKMEMCLUSTERS
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
literal|"#define\tPCB_KSP %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ksp
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
literal|"#define\tPCB_R0 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R1 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R2 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R3 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R4 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r4
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R5 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r5
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R6 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r6
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R7 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r7
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R8 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r8
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R9 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r9
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R10 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R11 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r11
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R12 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r12
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_R13 %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_r13
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_FP %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_fp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_PC %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_pc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_PSL %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_psl
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
literal|"#define\tPCB_P2BR %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_p2br
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_P2LR %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_p2lr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ACH %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_ach
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_ACL %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_acl
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_HFS %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_hfs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_SAVACC %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_savacc
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
literal|"#define\tSCB_DOADUMP %d\n"
argument_list|,
operator|&
name|scb
operator|->
name|scb_doadump
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSCB_BUSERR %d\n"
argument_list|,
operator|&
name|scb
operator|->
name|scb_buserr
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCB_DEVBASE
value|(((int)((struct scb *)0)->scb_devint)/sizeof (int))
name|printf
argument_list|(
literal|"#define\tSCB_DEVBASE %d\n"
argument_list|,
name|SCB_DEVBASE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n"
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

