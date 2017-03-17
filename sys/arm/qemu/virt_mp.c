begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
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
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_cpu.h>
end_include

begin_include
include|#
directive|include
file|<dev/psci/psci.h>
end_include

begin_include
include|#
directive|include
file|<arm/qemu/virt_mp.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|running_cpus
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|boolean_t
name|virt_start_ap
parameter_list|(
name|u_int
name|id
parameter_list|,
name|phandle_t
name|node
parameter_list|,
name|u_int
name|addr_cells
parameter_list|,
name|pcell_t
modifier|*
name|reg
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
if|if
condition|(
name|running_cpus
operator|>=
name|mp_ncpus
condition|)
return|return
operator|(
name|false
operator|)
return|;
name|running_cpus
operator|++
expr_stmt|;
name|err
operator|=
name|psci_cpu_on
argument_list|(
operator|*
name|reg
argument_list|,
name|pmap_kextract
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|mpentry
argument_list|)
argument_list|,
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
name|PSCI_RETVAL_SUCCESS
condition|)
return|return
operator|(
name|false
operator|)
return|;
return|return
operator|(
name|true
operator|)
return|;
block|}
end_function

begin_function
name|void
name|virt_mp_start_ap
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|ofw_cpu_early_foreach
argument_list|(
name|virt_start_ap
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

