begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994,1995 Stefan Esser, Wolfgang StanglMeier  * Copyright (c) 2000 Michael Smith<msmith@freebsd.org>  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * PCI:ISA bridge support  */
end_comment

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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_function_decl
specifier|static
name|int
name|isab_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|isab_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|isab_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|isab_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|isab_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|bus_generic_shutdown
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_suspend
argument_list|,
name|bus_generic_suspend
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_resume
argument_list|,
name|bus_generic_resume
argument_list|)
block|,
comment|/* Bus interface */
name|DEVMETHOD
argument_list|(
name|bus_print_child
argument_list|,
name|bus_generic_print_child
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_alloc_resource
argument_list|,
name|bus_generic_alloc_resource
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_release_resource
argument_list|,
name|bus_generic_release_resource
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_activate_resource
argument_list|,
name|bus_generic_activate_resource
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_deactivate_resource
argument_list|,
name|bus_generic_deactivate_resource
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_setup_intr
argument_list|,
name|bus_generic_setup_intr
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_teardown_intr
argument_list|,
name|bus_generic_teardown_intr
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
name|isab_driver
init|=
block|{
literal|"isab"
block|,
name|isab_methods
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|isab_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|isab
argument_list|,
name|pci
argument_list|,
name|isab_driver
argument_list|,
name|isab_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * XXX we need to add a quirk list here for bridges that don't correctly  *     report themselves.  */
end_comment

begin_function
specifier|static
name|int
name|isab_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|matched
init|=
literal|0
decl_stmt|;
comment|/*      * Try for a generic match based on class/subclass.      */
if|if
condition|(
operator|(
name|pci_get_class
argument_list|(
name|dev
argument_list|)
operator|==
name|PCIC_BRIDGE
operator|)
operator|&&
operator|(
name|pci_get_subclass
argument_list|(
name|dev
argument_list|)
operator|==
name|PCIS_BRIDGE_ISA
operator|)
condition|)
block|{
name|matched
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|/* 	 * These are devices that we *know* are PCI:ISA bridges.  	 * Sometimes, however, they don't report themselves as 	 * such.  Check in case one of them is pretending to be 	 * something else. 	 */
switch|switch
condition|(
name|pci_get_devid
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
literal|0x04848086
case|:
comment|/* Intel 82378ZB/82378IB */
case|case
literal|0x122e8086
case|:
comment|/* Intel 82371FB */
case|case
literal|0x70008086
case|:
comment|/* Intel 82371SB */
case|case
literal|0x71108086
case|:
comment|/* Intel 82371AB */
case|case
literal|0x71988086
case|:
comment|/* Intel 82443MX */
case|case
literal|0x24108086
case|:
comment|/* Intel 82801AA (ICH) */
case|case
literal|0x24208086
case|:
comment|/* Intel 82801AB (ICH0) */
case|case
literal|0x24408086
case|:
comment|/* Intel 82801AB (ICH2) */
case|case
literal|0x00061004
case|:
comment|/* VLSI 82C593 */
case|case
literal|0x05861106
case|:
comment|/* VIA 82C586 */
case|case
literal|0x05961106
case|:
comment|/* VIA 82C596 */
case|case
literal|0x06861106
case|:
comment|/* VIA 82C686 */
case|case
literal|0x153310b9
case|:
comment|/* AcerLabs M1533 */
case|case
literal|0x154310b9
case|:
comment|/* AcerLabs M1543 */
case|case
literal|0x00081039
case|:
comment|/* SiS 85c503 */
case|case
literal|0x00001078
case|:
comment|/* Cyrix Cx5510 */
case|case
literal|0x01001078
case|:
comment|/* Cyrix Cx5530 */
case|case
literal|0xc7001045
case|:
comment|/* OPTi 82C700 (FireStar) */
case|case
literal|0x00011033
case|:
comment|/* NEC 0001 (C-bus) */
case|case
literal|0x002c1033
case|:
comment|/* NEC 002C (C-bus) */
case|case
literal|0x003b1033
case|:
comment|/* NEC 003B (C-bus) */
case|case
literal|0x886a1060
case|:
comment|/* UMC UM8886 ISA */
case|case
literal|0x02001166
case|:
comment|/* ServerWorks IB6566 PCI */
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"PCI-ISA bridge with incorrect subclass 0x%x\n"
argument_list|,
name|pci_get_subclass
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
name|matched
operator|=
literal|1
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
if|if
condition|(
name|matched
condition|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"PCI-ISA bridge"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|10000
operator|)
return|;
block|}
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|isab_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_t
name|child
decl_stmt|;
comment|/*      * Attach an ISA bus.  Note that we can only have one ISA bus.      */
name|child
operator|=
name|device_add_child
argument_list|(
name|dev
argument_list|,
literal|"isa"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|child
operator|!=
name|NULL
condition|)
return|return
operator|(
name|bus_generic_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

