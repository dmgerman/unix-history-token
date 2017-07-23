begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Olivier Houchard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
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
file|<machine/fdt.h>
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
file|<arm/ti/ti_smc.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/omap4/omap4_machdep.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/omap4/omap4_smc.h>
end_include

begin_function
name|void
name|omap4_mp_setmaxid
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
if|if
condition|(
name|mp_ncpus
operator|!=
literal|0
condition|)
return|return;
name|mp_maxid
operator|=
literal|1
expr_stmt|;
name|mp_ncpus
operator|=
literal|2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|omap4_mp_start_ap
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|bus_addr_t
name|scu_addr
decl_stmt|;
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
literal|0x48240000
argument_list|,
literal|0x1000
argument_list|,
literal|0
argument_list|,
operator|&
name|scu_addr
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"Couldn't map the SCU\n"
argument_list|)
expr_stmt|;
comment|/* Enable the SCU */
operator|*
operator|(
specifier|volatile
name|unsigned
name|int
operator|*
operator|)
name|scu_addr
operator||=
literal|1
expr_stmt|;
comment|//*(volatile unsigned int *)(scu_addr + 0x30) |= 1;
name|dcache_wbinv_poc_all
argument_list|()
expr_stmt|;
name|ti_smc0
argument_list|(
literal|0x200
argument_list|,
literal|0xfffffdff
argument_list|,
name|MODIFY_AUX_CORE_0
argument_list|)
expr_stmt|;
name|ti_smc0
argument_list|(
name|pmap_kextract
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|mpentry
argument_list|)
argument_list|,
literal|0
argument_list|,
name|WRITE_AUX_CORE_1
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|sev
argument_list|()
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu_addr
argument_list|,
literal|0x1000
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

