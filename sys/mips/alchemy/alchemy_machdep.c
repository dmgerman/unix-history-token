begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2007 by Oleksandr Tymoshenko. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  */
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
specifier|static
name|void
name|mips_init
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"entry: mips_init()\n"
argument_list|)
expr_stmt|;
name|bootverbose
operator|=
literal|1
expr_stmt|;
name|realmem
operator|=
name|btoc
argument_list|(
literal|16
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
name|init_param1
argument_list|()
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
name|kdb_init
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|KDB
if|if
condition|(
name|boothowto
operator|&
name|RB_KDB
condition|)
name|kdb_enter
argument_list|(
name|KDB_WHY_BOOTFLAGS
argument_list|,
literal|"Boot flags requested debugger"
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|__unused
parameter_list|,
name|__register_t
name|a1
name|__unused
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
name|vm_offset_t
name|kernend
decl_stmt|;
name|uint64_t
name|platform_counter_freq
init|=
literal|175
operator|*
literal|1000
operator|*
literal|1000
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
comment|/* Initialize pcpu stuff */
name|mips_pcpu0_init
argument_list|()
expr_stmt|;
name|cninit
argument_list|()
expr_stmt|;
name|mips_init
argument_list|()
expr_stmt|;
comment|/* Set counter_freq for tick_init_params() */
name|platform_counter_freq
operator|=
literal|175
operator|*
literal|1000
operator|*
literal|1000
expr_stmt|;
name|mips_timer_init_params
argument_list|(
name|platform_counter_freq
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

