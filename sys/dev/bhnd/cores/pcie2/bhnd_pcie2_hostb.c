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
comment|/*  * Broadcom BHND PCIe-Gen2 PCI-Host Bridge.  *   * This driver handles all interactions with PCIe-G2 bridge cores operating in  * endpoint mode.  *   * Host-level PCI operations are handled at the bhndb bridge level by the  * bhndb_pci driver.  */
end_comment

begin_comment
comment|// TODO
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A full survey of known quirks/work-arounds has not been completed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Work-arounds for the following are not yet implemented:
end_comment

begin_comment
comment|// - BHND_PCIE2_QUIRK_SERDES_TXDRV_DEEMPH
end_comment

begin_comment
comment|//   4360 PCIe SerDes Tx amplitude/deemphasis (vendor Apple, boards
end_comment

begin_comment
comment|//   BCM94360X51P2, BCM94360X51A)
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
file|<sys/malloc.h>
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
file|<sys/systm.h>
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
file|"bhnd_pcie2_reg.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_pcie2_hostbvar.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|bhnd_device_quirk
name|bhnd_pcie2_quirks
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|bhnd_pcie2_wars_early_once
parameter_list|(
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|bhnd_pcie2_wars_hwup
parameter_list|(
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|bhnd_pcie2_wars_hwdown
parameter_list|(
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * device/quirk tables  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_DEV
parameter_list|(
name|_core
parameter_list|,
name|_quirks
parameter_list|)
define|\
value|BHND_DEVICE(_core, NULL, _quirks, BHND_DF_HOSTB)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|bhnd_device
name|bhnd_pcie2_devs
index|[]
init|=
block|{
name|BHND_PCI_DEV
argument_list|(
name|PCIE2
argument_list|,
name|bhnd_pcie2_quirks
argument_list|)
block|,
name|BHND_DEVICE_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|bhnd_device_quirk
name|bhnd_pcie2_quirks
index|[]
init|=
block|{
comment|/* Apple BCM4360 boards that require adjusting TX amplitude and 	 * differential output de-emphasis of the PCIe SerDes */
block|{
block|{
name|BHND_MATCH_BOARD
argument_list|(
name|PCI_VENDOR_APPLE
argument_list|,
name|BCM94360X51P2
argument_list|)
block|, }
block|,
name|BHND_PCIE2_QUIRK_SERDES_TXDRV_DEEMPH
block|}
block|,
block|{
block|{
name|BHND_MATCH_BOARD
argument_list|(
name|PCI_VENDOR_APPLE
argument_list|,
name|BCM94360X51A
argument_list|)
block|, }
block|,
name|BHND_PCIE2_QUIRK_SERDES_TXDRV_DEEMPH
block|}
block|,
name|BHND_DEVICE_QUIRK_END
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|bhnd_pcie2_hostb_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|dev
operator|=
name|dev
expr_stmt|;
name|sc
operator|->
name|quirks
operator|=
name|bhnd_device_quirks
argument_list|(
name|dev
argument_list|,
name|bhnd_pcie2_devs
argument_list|,
sizeof|sizeof
argument_list|(
name|bhnd_pcie2_devs
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Find the host PCI bridge device */
name|sc
operator|->
name|pci_dev
operator|=
name|bhnd_find_bridge_root
argument_list|(
name|dev
argument_list|,
name|devclass_find
argument_list|(
literal|"pci"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|pci_dev
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"parent pci bridge device not found\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Common setup */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_pcie2_generic_attach
argument_list|(
name|dev
argument_list|)
operator|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* Apply early single-shot work-arounds */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_pcie2_wars_early_once
argument_list|(
name|sc
argument_list|)
operator|)
condition|)
goto|goto
name|failed
goto|;
comment|/* Apply attach/resume work-arounds */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_pcie2_wars_hwup
argument_list|(
name|sc
argument_list|)
operator|)
condition|)
goto|goto
name|failed
goto|;
return|return
operator|(
literal|0
operator|)
return|;
name|failed
label|:
name|bhnd_pcie2_generic_detach
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|bhnd_pcie2_hostb_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* Apply suspend/detach work-arounds */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_pcie2_wars_hwdown
argument_list|(
name|sc
argument_list|)
operator|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
return|return
operator|(
name|bhnd_pcie2_generic_detach
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
name|bhnd_pcie2_hostb_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* Apply suspend/detach work-arounds */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_pcie2_wars_hwdown
argument_list|(
name|sc
argument_list|)
operator|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
return|return
operator|(
name|bhnd_pcie2_generic_suspend
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
name|bhnd_pcie2_hostb_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_pcie2_generic_resume
argument_list|(
name|dev
argument_list|)
operator|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* Apply attach/resume work-arounds */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_pcie2_wars_hwup
argument_list|(
name|sc
argument_list|)
operator|)
condition|)
block|{
name|bhnd_pcie2_generic_detach
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Apply any hardware work-arounds that must be executed exactly once, early in  * the attach process.  *   * This must be called after core enumeration and discovery of all applicable  * quirks, but prior to probe/attach of any cores, parsing of  * SPROM, etc.  */
end_comment

begin_function
specifier|static
name|int
name|bhnd_pcie2_wars_early_once
parameter_list|(
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|// TODO
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Apply any hardware workarounds that are required upon attach or resume  * of the bridge device.  */
end_comment

begin_function
specifier|static
name|int
name|bhnd_pcie2_wars_hwup
parameter_list|(
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|// TODO
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Apply any hardware workarounds that are required upon detach or suspend  * of the bridge device.  */
end_comment

begin_function
specifier|static
name|int
name|bhnd_pcie2_wars_hwdown
parameter_list|(
name|struct
name|bhnd_pcie2hb_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|// TODO
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|bhnd_pcie2_hostb_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|bhnd_pcie2_hostb_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|bhnd_pcie2_hostb_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_suspend
argument_list|,
name|bhnd_pcie2_hostb_suspend
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_resume
argument_list|,
name|bhnd_pcie2_hostb_resume
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|bhnd_hostb
argument_list|,
name|bhnd_pcie2_hostb_driver
argument_list|,
name|bhnd_pcie2_hostb_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|bhnd_pcie2hb_softc
argument_list|)
argument_list|,
name|bhnd_pcie2_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|bhnd_pcie2_hostb
argument_list|,
name|bhnd
argument_list|,
name|bhnd_pcie2_hostb_driver
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
name|bhnd_pcie2_hostb
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|bhnd_pcie2_hostb
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
name|bhnd_pcie2_hostb
argument_list|,
name|bhnd_pcie2
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

