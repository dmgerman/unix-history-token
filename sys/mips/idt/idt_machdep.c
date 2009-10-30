begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2007 by Oleksandr Tymoshenko. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $Id: $  *   */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/imgact.h>
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pager.h>
end_include

begin_include
include|#
directive|include
file|<machine/cache.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuregs.h>
end_include

begin_include
include|#
directive|include
file|<machine/hwfunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/locore.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<machine/sigframe.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|edata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|end
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|platform_cpu_init
parameter_list|()
block|{
comment|/* Nothing special */
block|}
end_function

begin_function
name|void
name|platform_halt
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|platform_identify
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|platform_reset
parameter_list|(
name|void
parameter_list|)
block|{
specifier|volatile
name|unsigned
name|int
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
literal|0xb8008000
decl_stmt|;
comment|/*  	 * TODO: we should take care of TLB stuff here. Otherwise 	 * board does not boots properly next time 	 */
comment|/* Write 0x8000_0001 to the Reset register */
operator|*
name|p
operator|=
literal|0x80000001
expr_stmt|;
asm|__asm __volatile("li	$25, 0xbfc00000");
asm|__asm __volatile("j	$25");
block|}
end_function

begin_function
name|void
name|platform_trap_enter
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|platform_trap_exit
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|platform_start
parameter_list|(
name|__register_t
name|a0
parameter_list|,
name|__register_t
name|a1
parameter_list|,
name|__register_t
name|a2
name|__unused
parameter_list|,
name|__register_t
name|a3
name|__unused
parameter_list|)
block|{
name|uint64_t
name|platform_counter_freq
decl_stmt|;
name|vm_offset_t
name|kernend
decl_stmt|;
name|int
name|argc
init|=
name|a0
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
init|=
operator|(
name|char
operator|*
operator|*
operator|)
name|a1
decl_stmt|;
name|int
name|i
decl_stmt|,
name|mem
decl_stmt|;
comment|/* clear the BSS and SBSS segments */
name|kernend
operator|=
name|round_page
argument_list|(
operator|(
name|vm_offset_t
operator|)
operator|&
name|end
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|edata
argument_list|,
literal|0
argument_list|,
name|kernend
operator|-
call|(
name|vm_offset_t
call|)
argument_list|(
operator|&
name|edata
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Looking for mem=XXM argument 	 */
name|mem
operator|=
literal|0
expr_stmt|;
comment|/* Just something to start with */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|argc
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|strncmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"mem="
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
condition|)
block|{
name|mem
operator|=
name|strtol
argument_list|(
name|argv
index|[
name|i
index|]
operator|+
literal|4
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|bootverbose
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|mem
operator|>
literal|0
condition|)
name|realmem
operator|=
name|btoc
argument_list|(
name|mem
operator|<<
literal|20
argument_list|)
expr_stmt|;
else|else
name|realmem
operator|=
name|btoc
argument_list|(
literal|32
operator|<<
literal|20
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
literal|10
condition|;
name|i
operator|++
control|)
block|{
name|phys_avail
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
comment|/* phys_avail regions are in bytes */
name|phys_avail
index|[
literal|0
index|]
operator|=
name|MIPS_KSEG0_TO_PHYS
argument_list|(
operator|(
name|vm_offset_t
operator|)
operator|&
name|end
argument_list|)
expr_stmt|;
name|phys_avail
index|[
literal|1
index|]
operator|=
name|ctob
argument_list|(
name|realmem
argument_list|)
expr_stmt|;
name|physmem
operator|=
name|realmem
expr_stmt|;
comment|/*  	 * ns8250 uart code uses DELAY so ticker should be inititalized  	 * before cninit. And tick_init_params refers to hz, so * init_param1  	 * should be called first. 	 */
name|init_param1
argument_list|()
expr_stmt|;
comment|/* TODO: parse argc,argv */
name|platform_counter_freq
operator|=
literal|330000000UL
expr_stmt|;
name|mips_timer_init_params
argument_list|(
name|platform_counter_freq
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|cninit
argument_list|()
expr_stmt|;
comment|/* Panic here, after cninit */
if|if
condition|(
name|mem
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"No mem=XX parameter in arguments"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"cmd line: "
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
name|argc
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|init_param2
argument_list|(
name|physmem
argument_list|)
expr_stmt|;
name|mips_cpu_init
argument_list|()
expr_stmt|;
name|pmap_bootstrap
argument_list|()
expr_stmt|;
name|mips_proc0_init
argument_list|()
expr_stmt|;
name|mutex_init
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DDB
name|kdb_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

