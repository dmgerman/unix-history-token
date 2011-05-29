begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2008 Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|"opt_hwpmc_hooks.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/pmc.h>
end_include

begin_include
include|#
directive|include
file|<sys/pmckern.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HWPMC_HOOKS
end_ifdef

begin_expr_stmt
name|FEATURE
argument_list|(
name|hwpmc_hooks
argument_list|,
literal|"Kernel support for HW PMC"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PMC_KERNEL_VERSION
value|PMC_VERSION
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PMC_KERNEL_VERSION
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|int
name|pmc_kernel_version
init|=
name|PMC_KERNEL_VERSION
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hook variable. */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|pmc_hook
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|function
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_comment
comment|/* Interrupt handler */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|pmc_intr
function_decl|)
parameter_list|(
name|int
name|cpu
parameter_list|,
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_comment
comment|/* Bitmask of CPUs requiring servicing at hardclock time */
end_comment

begin_decl_stmt
specifier|volatile
name|cpumask_t
name|pmc_cpumask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * A global count of SS mode PMCs.  When non-zero, this means that  * we have processes that are sampling the system as a whole.  */
end_comment

begin_decl_stmt
specifier|volatile
name|int
name|pmc_ss_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Since PMC(4) may not be loaded in the current kernel, the  * convention followed is that a non-NULL value of 'pmc_hook' implies  * the presence of this kernel module.  *  * This requires us to protect 'pmc_hook' with a  * shared (sx) lock -- thus making the process of calling into PMC(4)  * somewhat more expensive than a simple 'if' check and indirect call.  */
end_comment

begin_decl_stmt
name|struct
name|sx
name|pmc_sx
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|pmc_init_sx
parameter_list|(
name|void
parameter_list|)
block|{
name|sx_init_flags
argument_list|(
operator|&
name|pmc_sx
argument_list|,
literal|"pmc-sx"
argument_list|,
name|SX_NOWITNESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|pmcsx
argument_list|,
name|SI_SUB_LOCK
argument_list|,
name|SI_ORDER_MIDDLE
argument_list|,
name|pmc_init_sx
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Helper functions.  */
end_comment

begin_comment
comment|/*  * A note on the CPU numbering scheme used by the hwpmc(4) driver.  *  * CPUs are denoted using numbers in the range 0..[pmc_cpu_max()-1].  * CPUs could be numbered "sparsely" in this range; the predicate  * `pmc_cpu_is_present()' is used to test whether a given CPU is  * physically present.  *  * Further, a CPU that is physically present may be administratively  * disabled or otherwise unavailable for use by hwpmc(4).  The  * `pmc_cpu_is_active()' predicate tests for CPU usability.  An  * "active" CPU participates in thread scheduling and can field  * interrupts raised by PMC hardware.  *  * On systems with hyperthreaded CPUs, multiple logical CPUs may share  * PMC hardware resources.  For such processors one logical CPU is  * denoted as the primary owner of the in-CPU PMC resources. The  * pmc_cpu_is_primary() predicate is used to distinguish this primary  * CPU from the others.  */
end_comment

begin_function
name|int
name|pmc_cpu_is_active
parameter_list|(
name|int
name|cpu
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
return|return
operator|(
name|pmc_cpu_is_present
argument_list|(
name|cpu
argument_list|)
operator|&&
operator|(
name|hlt_cpus_mask
operator|&
operator|(
literal|1
operator|<<
name|cpu
operator|)
operator|)
operator|==
literal|0
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Deprecated. */
end_comment

begin_function
name|int
name|pmc_cpu_is_disabled
parameter_list|(
name|int
name|cpu
parameter_list|)
block|{
return|return
operator|(
operator|!
name|pmc_cpu_is_active
argument_list|(
name|cpu
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|pmc_cpu_is_present
parameter_list|(
name|int
name|cpu
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
return|return
operator|(
operator|!
name|CPU_ABSENT
argument_list|(
name|cpu
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_function
name|int
name|pmc_cpu_is_primary
parameter_list|(
name|int
name|cpu
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
return|return
operator|(
operator|(
name|logical_cpus_mask
operator|&
operator|(
literal|1
operator|<<
name|cpu
operator|)
operator|)
operator|==
literal|0
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Return the maximum CPU number supported by the system.  The return  * value is used for scaling internal data structures and for runtime  * checks.  */
end_comment

begin_function
name|unsigned
name|int
name|pmc_cpu_max
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
return|return
operator|(
name|mp_maxid
operator|+
literal|1
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_comment
comment|/*  * Return the count of CPUs in the `active' state in the system.  */
end_comment

begin_function
name|int
name|pmc_cpu_max_active
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
comment|/* 	 * When support for CPU hot-plugging is added to the kernel, 	 * this function would change to return the current number 	 * of "active" CPUs. 	 */
return|return
operator|(
name|mp_ncpus
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

