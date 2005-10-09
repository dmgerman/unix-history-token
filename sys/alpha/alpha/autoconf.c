begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|"opt_bootp.h"
end_include

begin_include
include|#
directive|include
file|"opt_isa.h"
end_include

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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
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
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_periph.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_function_decl
specifier|static
name|void
name|configure_first
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|configure
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|configure_final
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure1
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|configure_first
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SI_ORDER_SECOND is hookable */
end_comment

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure2
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_THIRD
argument_list|,
name|configure
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SI_ORDER_MIDDLE is hookable */
end_comment

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure3
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_ANY
argument_list|,
name|configure_final
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_ISA
end_ifdef

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_decl_stmt
name|device_t
name|isa_bus_device
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Determine i/o configuration for a machine.  */
end_comment

begin_function
specifier|static
name|void
name|configure_first
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|device_add_child
argument_list|(
name|root_bus
argument_list|,
name|platform
operator|.
name|iobus
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|configure
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|root_bus_configure
argument_list|()
expr_stmt|;
comment|/* 	 * Probe ISA devices after everything. 	 */
ifdef|#
directive|ifdef
name|DEV_ISA
if|if
condition|(
name|isa_bus_device
condition|)
name|isa_probe_children
argument_list|(
name|isa_bus_device
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|void
name|configure_final
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
comment|/* 	 * Now we're ready to handle (pending) interrupts. 	 * XXX this is slightly misplaced. 	 */
name|alpha_pal_swpipl
argument_list|(
name|ALPHA_PSL_IPL_0
argument_list|)
expr_stmt|;
name|cninit_finish
argument_list|()
expr_stmt|;
name|cold
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

