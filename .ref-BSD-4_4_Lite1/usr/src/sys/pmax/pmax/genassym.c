begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)genassym.c	8.2 (Berkeley) 9/23/93  */
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

