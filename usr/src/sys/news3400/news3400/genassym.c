begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)genassym.c	7.7 (Berkeley) %G%  */
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
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
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
comment|/* 	 * struct proc 	 */
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
comment|/* 	 * struct vmmeter 	 */
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
comment|/* 	 * struct user 	 */
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
literal|"#define\tNBPW %d\n"
argument_list|,
name|NBPW
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

