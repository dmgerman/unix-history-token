begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)genassym.c	8.2 (Berkeley) %G%  */
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
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
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
name|int
name|size
decl_stmt|,
name|s
decl_stmt|,
name|n
decl_stmt|;
name|printf
argument_list|(
literal|"#define\tP_FORW %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_forw
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_BACK %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_back
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_PRIORITY %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_priority
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
literal|"#define\tP_UPTE %d\n"
argument_list|,
name|p
operator|->
name|p_md
operator|.
name|md_upte
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PCB_REGS %d\n"
argument_list|,
name|up
operator|->
name|u_pcb
operator|.
name|pcb_regs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PCB_FPREGS %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_pcb
operator|.
name|pcb_regs
index|[
name|F0
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PCB_CONTEXT %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_pcb
operator|.
name|pcb_context
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PCB_ONFAULT %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_pcb
operator|.
name|pcb_onfault
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_PCB_SEGTAB %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_pcb
operator|.
name|pcb_segtab
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tVM_MIN_ADDRESS 0x%x\n"
argument_list|,
name|VM_MIN_ADDRESS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tVM_MIN_KERNEL_ADDRESS 0x%x\n"
argument_list|,
name|VM_MIN_KERNEL_ADDRESS
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
literal|"#define\tSIGILL %d\n"
argument_list|,
name|SIGILL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSIGFPE %d\n"
argument_list|,
name|SIGFPE
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

