begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*  * BHNDB PCI SPROM driver.  *   * Provides support for early PCI bridge cores that vend SPROM CSRs  * via PCI configuration space.  */
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
file|<sys/limits.h>
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
file|<sys/systm.h>
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
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/cores/pci/bhnd_pci_hostbvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/nvram/bhnd_spromvar.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_if.h"
end_include

begin_include
include|#
directive|include
file|"bhndb_pcireg.h"
end_include

begin_include
include|#
directive|include
file|"bhndb_pcivar.h"
end_include

begin_function
specifier|static
name|int
name|bhndb_pci_sprom_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_t
name|bridge
decl_stmt|;
name|int
name|error
decl_stmt|;
comment|/* Our parent must be a PCI-BHND bridge */
name|bridge
operator|=
name|device_get_parent
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|device_get_driver
argument_list|(
name|bridge
argument_list|)
operator|!=
operator|&
name|bhndb_pci_driver
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* Defer to default driver implementation */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_sprom_probe
argument_list|(
name|dev
argument_list|)
operator|)
operator|>
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
return|return
operator|(
name|BUS_PROBE_NOWILDCARD
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|bhndb_pci_sprom_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|bhndb_pci_sprom_probe
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|bhnd_nvram
argument_list|,
name|bhndb_pci_sprom_driver
argument_list|,
name|bhndb_pci_sprom_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|bhnd_sprom_softc
argument_list|)
argument_list|,
name|bhnd_sprom_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|bhndb_pci_sprom
argument_list|,
name|bhndb
argument_list|,
name|bhndb_pci_sprom_driver
argument_list|,
name|bhnd_nvram_devclass
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|bhndb_pci_sprom
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
name|bhndb_pci_sprom
argument_list|,
name|bhnd_sprom
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
name|bhndb_pci_sprom
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

