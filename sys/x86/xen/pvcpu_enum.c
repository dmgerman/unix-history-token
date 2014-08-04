begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 John Baldwin<jhb@FreeBSD.org>  * Copyright (c) 2013 Roger Pau MonnÃ©<roger.pau@citrix.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<x86/apicvar.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<xen/hypervisor.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/vcpu.h>
end_include

begin_function_decl
specifier|static
name|int
name|xenpv_probe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|xenpv_probe_cpus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|xenpv_setup_local
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|xenpv_setup_io
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|apic_enumerator
name|xenpv_enumerator
init|=
block|{
literal|"Xen PV"
block|,
name|xenpv_probe
block|,
name|xenpv_probe_cpus
block|,
name|xenpv_setup_local
block|,
name|xenpv_setup_io
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This enumerator will only be registered on PVH  */
end_comment

begin_function
specifier|static
name|int
name|xenpv_probe
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Test each possible vCPU in order to find the number of vCPUs  */
end_comment

begin_function
specifier|static
name|int
name|xenpv_probe_cpus
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
name|int
name|i
decl_stmt|,
name|ret
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXCPU
condition|;
name|i
operator|++
control|)
block|{
name|ret
operator|=
name|HYPERVISOR_vcpu_op
argument_list|(
name|VCPUOP_is_up
argument_list|,
name|i
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|>=
literal|0
condition|)
name|lapic_create
argument_list|(
operator|(
name|i
operator|*
literal|2
operator|)
argument_list|,
operator|(
name|i
operator|==
literal|0
operator|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialize the vCPU id of the BSP  */
end_comment

begin_function
specifier|static
name|int
name|xenpv_setup_local
parameter_list|(
name|void
parameter_list|)
block|{
name|PCPU_SET
argument_list|(
name|vcpu_id
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|lapic_init
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * On PVH guests there's no IO APIC  */
end_comment

begin_function
specifier|static
name|int
name|xenpv_setup_io
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|xenpv_register
parameter_list|(
name|void
modifier|*
name|dummy
name|__unused
parameter_list|)
block|{
if|if
condition|(
name|xen_pv_domain
argument_list|()
condition|)
block|{
name|apic_register_enumerator
argument_list|(
operator|&
name|xenpv_enumerator
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|xenpv_register
argument_list|,
name|SI_SUB_TUNABLES
operator|-
literal|1
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|xenpv_register
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Setup per-CPU vCPU IDs  */
end_comment

begin_function
specifier|static
name|void
name|xenpv_set_ids
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|struct
name|pcpu
modifier|*
name|pc
decl_stmt|;
name|int
name|i
decl_stmt|;
name|CPU_FOREACH
argument_list|(
argument|i
argument_list|)
block|{
name|pc
operator|=
name|pcpu_find
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|pc
operator|->
name|pc_vcpu_id
operator|=
name|i
expr_stmt|;
block|}
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|xenpv_set_ids
argument_list|,
name|SI_SUB_CPU
argument_list|,
name|SI_ORDER_MIDDLE
argument_list|,
name|xenpv_set_ids
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

