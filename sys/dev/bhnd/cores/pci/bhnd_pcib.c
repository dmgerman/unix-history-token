begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*  * Broadcom PCI/PCIe-Gen1 Host-PCI bridge.  *   * This driver handles all interactions with PCI bridge cores operating in  * root complex mode.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_pcireg.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_pcibvar.h"
end_include

begin_function
specifier|static
name|int
name|bhnd_pcib_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
comment|// TODO
return|return
operator|(
name|bhnd_pci_generic_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|bhnd_pcib_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
comment|// TODO
return|return
operator|(
name|bhnd_pci_generic_detach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|bhnd_pcib_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|bhnd_pci_generic_suspend
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|bhnd_pcib_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|bhnd_pci_generic_resume
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|bhnd_pcib_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|bhnd_pcib_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|bhnd_pcib_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_suspend
argument_list|,
name|bhnd_pcib_suspend
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_resume
argument_list|,
name|bhnd_pcib_resume
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|bhnd_pcib
argument_list|,
name|bhnd_pcib_driver
argument_list|,
name|bhnd_pcib_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|bhnd_pcib_softc
argument_list|)
argument_list|,
name|bhnd_pci_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|bhnd_pcib
argument_list|,
name|bhnd
argument_list|,
name|bhnd_pcib_driver
argument_list|,
name|bhnd_hostb_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|bhnd_pcib
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|bhnd_pcib
argument_list|,
name|bhnd
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|bhnd_pcib
argument_list|,
name|bhnd_pci
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|bhnd_pcib
argument_list|,
name|pci
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

