begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 John Baldwin<jhb@FreeBSD.org>  * Copyright (c) 1996, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<x86/apicreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/apicvar.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/mptable.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_include
include|#
directive|include
file|<xen/hypervisor.h>
end_include

begin_include
include|#
directive|include
file|<machine/xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/vcpu.h>
end_include

begin_function_decl
specifier|static
name|int
name|mptable_probe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|mptable_probe_cpus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mptable_register
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|mptable_setup_local
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|mptable_setup_io
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|apic_enumerator
name|mptable_enumerator
init|=
block|{
literal|"MPTable"
block|,
name|mptable_probe
block|,
name|mptable_probe_cpus
block|,
name|mptable_setup_local
block|,
name|mptable_setup_io
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|mptable_probe
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|-
literal|100
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mptable_probe_cpus
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|rc
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
name|rc
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
name|rc
operator|>=
literal|0
condition|)
name|cpu_add
argument_list|(
name|i
argument_list|,
operator|(
name|i
operator|==
literal|0
operator|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialize the local APIC on the BSP.  */
end_comment

begin_function
specifier|static
name|int
name|mptable_setup_local
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
name|int
name|mptable_setup_io
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
name|mptable_register
parameter_list|(
name|void
modifier|*
name|dummy
name|__unused
parameter_list|)
block|{
name|apic_register_enumerator
argument_list|(
operator|&
name|mptable_enumerator
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|mptable_register
argument_list|,
name|SI_SUB_CPU
operator|-
literal|1
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|mptable_register
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|mptable_pci_probe_table
parameter_list|(
name|int
name|bus
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
name|int
name|mptable_pci_route_interrupt
parameter_list|(
name|device_t
name|pcib
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|pin
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

