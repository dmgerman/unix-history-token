begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2008 SÃ¸ren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009-2013 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/ata.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
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
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/ata/ata-all.h>
end_include

begin_include
include|#
directive|include
file|<dev/ata/ata-pci.h>
end_include

begin_include
include|#
directive|include
file|<ata_if.h>
end_include

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
specifier|static
name|int
name|hv_ata_pci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|hv_ata_pci_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|hv_ata_pci_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * generic PCI ATA device probe  */
end_comment

begin_function
specifier|static
name|int
name|hv_ata_pci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_t
name|parent
init|=
name|device_get_parent
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|int
name|ata_disk_enable
decl_stmt|;
name|ata_disk_enable
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Don't probe if not running in a Hyper-V environment 	 */
if|if
condition|(
name|vm_guest
operator|!=
name|VM_GUEST_HV
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
name|device_get_unit
argument_list|(
name|parent
argument_list|)
operator|!=
literal|0
operator|||
name|device_get_ivars
argument_list|(
name|dev
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* 	 * On Hyper-V the default is to use the enlightened driver for 	 * IDE disks. However, if the user wishes to use the native 	 * ATA driver, the environment variable 	 * hw_ata.disk_enable must be explicitly set to 1. 	 */
if|if
condition|(
name|getenv_int
argument_list|(
literal|"hw.ata.disk_enable"
argument_list|,
operator|&
name|ata_disk_enable
argument_list|)
condition|)
block|{
if|if
condition|(
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"hw.ata.disk_enable flag is disabling Hyper-V"
literal|" ATA driver support\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Hyper-V ATA storage disengage driver"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|hv_ata_pci_attach
parameter_list|(
name|device_t
name|dev
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
name|hv_ata_pci_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|hv_ata_pci_methods
index|[]
init|=
block|{
comment|/* device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|hv_ata_pci_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|hv_ata_pci_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|hv_ata_pci_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|bus_generic_shutdown
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|devclass_t
name|hv_ata_pci_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|hv_ata_pci_disengage_driver
init|=
block|{
literal|"ata"
block|,
name|hv_ata_pci_methods
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|atapci_dis
argument_list|,
name|atapci
argument_list|,
name|hv_ata_pci_disengage_driver
argument_list|,
name|hv_ata_pci_devclass
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|atapci_dis
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|atapci_dis
argument_list|,
name|ata
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

