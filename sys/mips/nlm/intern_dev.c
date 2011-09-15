begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Netlogic Microsystems Inc.  *  * (based on pci/ignore_pci.c)  * Copyright (c) 2000 Michael Smith<msmith@freebsd.org>  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
comment|/*  * 'Ignore' driver - eats devices that show up errnoeously on PCI  * but shouldn't ever be listed or handled by a driver.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/haldefs.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/iomap.h>
end_include

begin_function_decl
specifier|static
name|int
name|nlm_soc_pci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|nlm_soc_pci_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|nlm_soc_pci_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|bus_generic_attach
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
name|nlm_soc_pci_driver
init|=
block|{
literal|"nlm_soc_pci"
block|,
name|nlm_soc_pci_methods
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|nlm_soc_pci_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|nlm_soc_pci
argument_list|,
name|pci
argument_list|,
name|nlm_soc_pci_driver
argument_list|,
name|nlm_soc_pci_devclass
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
name|nlm_soc_pci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|pci_get_vendor
argument_list|(
name|dev
argument_list|)
operator|!=
name|PCI_VENDOR_NETLOGIC
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* Ignore SoC internal devices */
switch|switch
condition|(
name|pci_get_device
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
name|PCI_DEVICE_ID_NLM_ICI
case|:
case|case
name|PCI_DEVICE_ID_NLM_PIC
case|:
case|case
name|PCI_DEVICE_ID_NLM_FMN
case|:
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Netlogic Internal"
argument_list|)
expr_stmt|;
name|device_quiet
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|10000
operator|)
return|;
default|default:
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
block|}
end_function

end_unit

