begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)genassym.c	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"../i386/pte.h"
end_include

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
file|"dir.h"
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
literal|"#define\tU_EOSYS %d\n"
argument_list|,
operator|&
name|u
operator|->
name|u_eosys
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
literal|"#define\tP_CR3 %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_cr3
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
literal|"#define\tP1PAGES %d\n"
argument_list|,
name|P1PAGES
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
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
name|pcbtss
operator|.
name|tss_ioopt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tPCB_FPSAV %d\n"
argument_list|,
operator|&
name|pcb
operator|->
name|pcb_fpsav
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

