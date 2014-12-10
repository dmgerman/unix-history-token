begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Roger Pau MonnÃ©<roger.pau@citrix.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/accommon.h>
end_include

begin_include
include|#
directive|include
file|<dev/acpica/acpivar.h>
end_include

begin_include
include|#
directive|include
file|<sys/pciio.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pci_private.h>
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
file|<xen/xen_pci.h>
end_include

begin_include
include|#
directive|include
file|"pcib_if.h"
end_include

begin_include
include|#
directive|include
file|"pci_if.h"
end_include

begin_function
specifier|static
name|int
name|xen_acpi_pci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|xen_pv_domain
argument_list|()
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
name|acpi_get_handle
argument_list|(
name|dev
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Xen ACPI PCI bus"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_SPECIFIC
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|xen_acpi_pci_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|xen_acpi_pci_probe
argument_list|)
block|,
comment|/* PCI interface overwrites */
name|DEVMETHOD
argument_list|(
name|pci_enable_msi
argument_list|,
name|xen_pci_enable_msi_method
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|pci_disable_msi
argument_list|,
name|xen_pci_disable_msi_method
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|pci_child_added
argument_list|,
name|xen_pci_child_added_method
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|pci_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|acpi_pci_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|pci
argument_list|,
name|xen_acpi_pci_driver
argument_list|,
name|xen_acpi_pci_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pci_softc
argument_list|)
argument_list|,
name|acpi_pci_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|xen_acpi_pci
argument_list|,
name|pcib
argument_list|,
name|xen_acpi_pci_driver
argument_list|,
name|pci_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|xen_acpi_pci
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

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|xen_acpi_pci
argument_list|,
name|acpi
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
name|MODULE_VERSION
argument_list|(
name|xen_acpi_pci
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

