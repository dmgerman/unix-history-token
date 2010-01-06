begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|CFE
end_ifdef

begin_include
include|#
directive|include
file|<dev/cfe/cfe_api.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
ifdef|#
directive|ifdef
name|CFE
comment|/* 	 * Query DRAM memory map from CFE. 	 */
name|physmem
operator|=
literal|0
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
operator|+=
literal|2
control|)
block|{
name|int
name|result
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|,
name|len
decl_stmt|,
name|type
decl_stmt|;
name|result
operator|=
name|cfe_enummem
argument_list|(
name|i
argument_list|,
literal|0
argument_list|,
operator|&
name|addr
argument_list|,
operator|&
name|len
argument_list|,
operator|&
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|<
literal|0
condition|)
block|{
name|phys_avail
index|[
name|i
index|]
operator|=
name|phys_avail
index|[
name|i
operator|+
literal|1
index|]
operator|=
literal|0
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|type
operator|!=
name|CFE_MI_AVAILABLE
condition|)
continue|continue;
name|phys_avail
index|[
name|i
index|]
operator|=
name|addr
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
operator|&&
name|addr
operator|==
literal|0
condition|)
block|{
comment|/* 			 * If this is the first physical memory segment probed 			 * from CFE, omit the region at the start of physical 			 * memory where the kernel has been loaded. 			 */
name|phys_avail
index|[
name|i
index|]
operator|+=
name|MIPS_KSEG0_TO_PHYS
argument_list|(
operator|(
name|vm_offset_t
operator|)
operator|&
name|end
argument_list|)
expr_stmt|;
block|}
name|phys_avail
index|[
name|i
operator|+
literal|1
index|]
operator|=
name|addr
operator|+
name|len
expr_stmt|;
name|physmem
operator|+=
name|len
expr_stmt|;
block|}
name|realmem
operator|=
name|btoc
argument_list|(
name|physmem
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
if|#
directive|if
name|defined
argument_list|(
name|CFE
argument_list|)
name|cfe_exit
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
operator|*
operator|(
operator|(
specifier|volatile
name|uint8_t
operator|*
operator|)
name|MIPS_PHYS_TO_KSEG1
argument_list|(
name|SENTRY5_EXTIFADR
argument_list|)
operator|)
operator|=
literal|0x80
expr_stmt|;
endif|#
directive|endif
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
parameter_list|,
name|__register_t
name|a3
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
ifdef|#
directive|ifdef
name|CFE
comment|/* 	 * Initialize CFE firmware trampolines before 	 * we initialize the low-level console. 	 * 	 * CFE passes the following values in registers: 	 * a0: firmware handle 	 * a2: firmware entry point 	 * a3: entry point seal 	 */
if|if
condition|(
name|a3
operator|==
name|CFE_EPTSEAL
condition|)
name|cfe_init
argument_list|(
name|a0
argument_list|,
name|a2
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|cninit
argument_list|()
expr_stmt|;
name|mips_init
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
comment|/* 	 * Probe the Broadcom Sentry5's on-chip PLL clock registers 	 * and discover the CPU pipeline clock and bus clock 	 * multipliers from this. 	 * XXX: Wrong place. You have to ask the ChipCommon 	 * or External Interface cores on the SiBa. 	 */
block|uint32_t busmult, cpumult, refclock, clkcfg1;
define|#
directive|define
name|S5_CLKCFG1_REFCLOCK_MASK
value|0x0000001F
define|#
directive|define
name|S5_CLKCFG1_BUSMULT_MASK
value|0x000003E0
define|#
directive|define
name|S5_CLKCFG1_BUSMULT_SHIFT
value|5
define|#
directive|define
name|S5_CLKCFG1_CPUMULT_MASK
value|0xFFFFFC00
define|#
directive|define
name|S5_CLKCFG1_CPUMULT_SHIFT
value|10
block|counter_freq = 100000000;
comment|/* XXX */
block|clkcfg1 = s5_rd_clkcfg1(); 	printf("clkcfg1 = 0x%08x\n", clkcfg1);  	refclock = clkcfg1& 0x1F; 	busmult = ((clkcfg1& 0x000003E0)>> 5) + 1; 	cpumult = ((clkcfg1& 0xFFFFFC00)>> 10) + 1;  	printf("refclock = %u\n", refclock); 	printf("busmult = %u\n", busmult); 	printf("cpumult = %u\n", cpumult);  	counter_freq = cpumult * refclock;
else|#
directive|else
name|platform_counter_freq
operator|=
literal|200
operator|*
literal|1000
operator|*
literal|1000
expr_stmt|;
comment|/* Sentry5 is 200MHz */
endif|#
directive|endif
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

