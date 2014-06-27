begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Peter Grehan  * Copyright (c) 2009 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_comment
comment|/*  * Dispatch platform calls to the appropriate platform implementation  * through a previously registered kernel object.  */
end_comment

begin_define
define|#
directive|define
name|_ARM32_BUS_DMA_PRIVATE
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
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

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<machine/bus_dma.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/platform.h>
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
file|"platform_if.h"
end_include

begin_decl_stmt
specifier|static
name|platform_def_t
modifier|*
name|plat_def_impl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_t
name|plat_obj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|kobj_ops
name|plat_kernel_kops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|platform_kobj
name|plat_kernel_obj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|plat_name
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|platform
argument_list|,
name|CTLFLAG_RDTUN
operator||
name|CTLFLAG_NOFETCH
argument_list|,
name|plat_name
argument_list|,
literal|0
argument_list|,
literal|"Platform currently in use"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Platform install routines. Highest priority wins, using the same  * algorithm as bus attachment.  */
end_comment

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|platform_set
argument_list|,
name|platform_def_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|platform_probe_and_attach
parameter_list|(
name|void
parameter_list|)
block|{
name|platform_def_t
modifier|*
modifier|*
name|platpp
decl_stmt|,
modifier|*
name|platp
decl_stmt|;
name|int
name|prio
decl_stmt|,
name|best_prio
decl_stmt|;
name|plat_obj
operator|=
operator|&
name|plat_kernel_obj
expr_stmt|;
name|best_prio
operator|=
literal|0
expr_stmt|;
comment|/* 	 * We are unable to use TUNABLE_STR as the read will happen 	 * well after this function has returned. 	 */
name|TUNABLE_STR_FETCH
argument_list|(
literal|"hw.platform"
argument_list|,
name|plat_name
argument_list|,
sizeof|sizeof
argument_list|(
name|plat_name
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Try to locate the best platform kobj 	 */
name|SET_FOREACH
argument_list|(
argument|platpp
argument_list|,
argument|platform_set
argument_list|)
block|{
name|platp
operator|=
operator|*
name|platpp
expr_stmt|;
comment|/* 		 * Take care of compiling the selected class, and 		 * then statically initialise the MMU object 		 */
name|kobj_class_compile_static
argument_list|(
name|platp
argument_list|,
operator|&
name|plat_kernel_kops
argument_list|)
expr_stmt|;
name|kobj_init_static
argument_list|(
operator|(
name|kobj_t
operator|)
name|plat_obj
argument_list|,
name|platp
argument_list|)
expr_stmt|;
name|plat_obj
operator|->
name|cls
operator|=
name|platp
expr_stmt|;
name|prio
operator|=
name|PLATFORM_PROBE
argument_list|(
name|plat_obj
argument_list|)
expr_stmt|;
comment|/* Check for errors */
if|if
condition|(
name|prio
operator|>
literal|0
condition|)
continue|continue;
comment|/* 		 * Check if this module was specifically requested through 		 * the loader tunable we provide. 		 */
if|if
condition|(
name|strcmp
argument_list|(
name|platp
operator|->
name|name
argument_list|,
name|plat_name
argument_list|)
operator|==
literal|0
condition|)
block|{
name|plat_def_impl
operator|=
name|platp
expr_stmt|;
break|break;
block|}
comment|/* Otherwise, see if it is better than our current best */
if|if
condition|(
name|plat_def_impl
operator|==
name|NULL
operator|||
name|prio
operator|>
name|best_prio
condition|)
block|{
name|best_prio
operator|=
name|prio
expr_stmt|;
name|plat_def_impl
operator|=
name|platp
expr_stmt|;
block|}
comment|/* 		 * We can't free the KOBJ, since it is static. Reset the ops 		 * member of this class so that we can come back later. 		 */
name|platp
operator|->
name|ops
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|plat_def_impl
operator|==
name|NULL
condition|)
name|panic
argument_list|(
literal|"No platform module found!"
argument_list|)
expr_stmt|;
comment|/* 	 * Recompile to make sure we ended with the 	 * correct one, and then attach. 	 */
name|kobj_class_compile_static
argument_list|(
name|plat_def_impl
argument_list|,
operator|&
name|plat_kernel_kops
argument_list|)
expr_stmt|;
name|kobj_init_static
argument_list|(
operator|(
name|kobj_t
operator|)
name|plat_obj
argument_list|,
name|plat_def_impl
argument_list|)
expr_stmt|;
name|strlcpy
argument_list|(
name|plat_name
argument_list|,
name|plat_def_impl
operator|->
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|plat_name
argument_list|)
argument_list|)
expr_stmt|;
name|PLATFORM_ATTACH
argument_list|(
name|plat_obj
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|platform_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|PLATFORM_DEVMAP_INIT
argument_list|(
name|plat_obj
argument_list|)
return|;
block|}
end_function

begin_function
name|vm_offset_t
name|platform_lastaddr
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|PLATFORM_LASTADDR
argument_list|(
name|plat_obj
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|platform_gpio_init
parameter_list|(
name|void
parameter_list|)
block|{
name|PLATFORM_GPIO_INIT
argument_list|(
name|plat_obj
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|platform_late_init
parameter_list|(
name|void
parameter_list|)
block|{
name|PLATFORM_LATE_INIT
argument_list|(
name|plat_obj
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

