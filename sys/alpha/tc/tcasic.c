begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* from $NetBSD: tcasic.c,v 1.23 1998/05/14 00:01:31 thorpej Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|"opt_cpu.h"
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
file|<machine/rpb.h>
end_include

begin_comment
comment|/*#include<alpha/tc/dwlpxreg.h>*/
end_comment

begin_define
define|#
directive|define
name|KV
parameter_list|(
name|pa
parameter_list|)
value|ALPHA_PHYS_TO_K0SEG(pa)
end_define

begin_decl_stmt
specifier|static
name|devclass_t
name|tcasic_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_t
name|tcasic0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX only one for now */
end_comment

begin_struct
struct|struct
name|tcasic_softc
block|{
name|vm_offset_t
name|dmem_base
decl_stmt|;
comment|/* dense memory */
name|vm_offset_t
name|smem_base
decl_stmt|;
comment|/* sparse memory */
name|vm_offset_t
name|io_base
decl_stmt|;
comment|/* sparse i/o */
name|vm_offset_t
name|cfg_base
decl_stmt|;
comment|/* sparse pci config */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TCASIC_SOFTC
parameter_list|(
name|dev
parameter_list|)
value|(struct tcasic_softc*) device_get_softc(dev)
end_define

begin_function_decl
specifier|static
name|int
name|tcasic_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tcasic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|tcasic_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|tcasic_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|tcasic_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_print_child
argument_list|,
name|bus_generic_print_child
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
name|tcasic_driver
init|=
block|{
literal|"tcasic"
block|,
name|tcasic_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|tcasic_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|device_t
name|tc0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|tcasic_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|tcasic0
condition|)
return|return
name|ENXIO
return|;
if|if
condition|(
operator|(
name|hwrpb
operator|->
name|rpb_type
operator|!=
name|ST_DEC_3000_300
operator|)
operator|&&
operator|(
name|hwrpb
operator|->
name|rpb_type
operator|!=
name|ST_DEC_3000_500
operator|)
condition|)
return|return
name|ENXIO
return|;
name|tcasic0
operator|=
name|dev
expr_stmt|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Turbochannel Host Bus Adapter"
argument_list|)
expr_stmt|;
name|tc0
operator|=
name|device_add_child
argument_list|(
name|dev
argument_list|,
literal|"tc"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|tcasic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|tcasic0
operator|=
name|dev
expr_stmt|;
comment|/*	chipset = tcasic_chipset;*/
name|device_probe_and_attach
argument_list|(
name|tc0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|tcasic
argument_list|,
name|root
argument_list|,
name|tcasic_driver
argument_list|,
name|tcasic_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

