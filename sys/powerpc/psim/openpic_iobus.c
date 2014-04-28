begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * The psim iobus attachment for the OpenPIC interrupt controller.  */
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/pio.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
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
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/openpicreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/openpicvar.h>
end_include

begin_include
include|#
directive|include
file|<powerpc/psim/iobusvar.h>
end_include

begin_include
include|#
directive|include
file|"pic_if.h"
end_include

begin_comment
comment|/*  * PSIM IOBus interface  */
end_comment

begin_function_decl
specifier|static
name|int
name|openpic_iobus_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|openpic_iobus_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|openpic_iobus_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|openpic_iobus_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|openpic_iobus_attach
argument_list|)
block|,
comment|/* PIC interface */
name|DEVMETHOD
argument_list|(
name|pic_config
argument_list|,
name|openpic_config
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|pic_dispatch
argument_list|,
name|openpic_dispatch
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|pic_enable
argument_list|,
name|openpic_enable
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|pic_eoi
argument_list|,
name|openpic_eoi
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|pic_ipi
argument_list|,
name|openpic_ipi
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|pic_mask
argument_list|,
name|openpic_mask
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|pic_unmask
argument_list|,
name|openpic_unmask
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|openpic_iobus_driver
init|=
block|{
literal|"openpic"
block|,
name|openpic_iobus_methods
block|,
expr|sizeof
operator|(
expr|struct
name|openpic_softc
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|openpic
argument_list|,
name|iobus
argument_list|,
name|openpic_iobus_driver
argument_list|,
name|openpic_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|openpic_iobus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|openpic_softc
modifier|*
name|sc
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|name
operator|=
name|iobus_get_name
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"interrupt-controller"
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* 	 * The description was already printed out in the nexus 	 * probe, so don't do it again here 	 */
name|device_set_desc
argument_list|(
name|dev
argument_list|,
name|OPENPIC_DEVSTR
argument_list|)
expr_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_psim
operator|=
literal|1
expr_stmt|;
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
name|openpic_iobus_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|openpic_common_attach
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

