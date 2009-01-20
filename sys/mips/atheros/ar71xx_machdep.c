begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Oleksandr Tymoshenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuregs.h>
end_include

begin_include
include|#
directive|include
file|<mips/sentry5/s5reg.h>
end_include

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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
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
file|<machine/hwfunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
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

begin_include
include|#
directive|include
file|<mips/atheros/ar71xxreg.h>
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
name|uint32_t
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
name|MIPS_PHYS_TO_KSEG1
argument_list|(
name|ATH_RST_RESET
argument_list|)
decl_stmt|;
name|uint32_t
name|reg
init|=
operator|*
name|p
decl_stmt|;
operator|*
name|p
operator|=
name|reg
operator||
name|RST_RESET_FULL_CHIP_RESET
expr_stmt|;
comment|/* Wait for reset */
while|while
condition|(
literal|1
condition|)
empty_stmt|;
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
comment|/* TODO: Get available memory from RedBoot. Is it possible? */
name|realmem
operator|=
name|btoc
argument_list|(
literal|64
operator|*
literal|1024
operator|*
literal|1024
argument_list|)
expr_stmt|;
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
comment|/* 	 * ns8250 uart code uses DELAY so ticker should be inititalized  	 * before cninit. And tick_init_params refers to hz, so * init_param1  	 * should be called first. 	 */
name|init_param1
argument_list|()
expr_stmt|;
comment|/* TODO: Get CPU freq from RedBoot. Is it possible? */
name|platform_counter_freq
operator|=
literal|680000000UL
expr_stmt|;
name|mips_timer_init_params
argument_list|(
name|platform_counter_freq
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|cninit
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"arguments: \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  a0 = %08x\n"
argument_list|,
name|a0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  a1 = %08x\n"
argument_list|,
name|a1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  a2 = %08x\n"
argument_list|,
name|a2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  a3 = %08x\n"
argument_list|,
name|a3
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

