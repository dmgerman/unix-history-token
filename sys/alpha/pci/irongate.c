begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Andrew Gallatin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/malloc.h>
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

begin_include
include|#
directive|include
file|<alpha/isa/isavar.h>
end_include

begin_include
include|#
directive|include
file|<alpha/pci/irongatereg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/pci/irongatevar.h>
end_include

begin_include
include|#
directive|include
file|<machine/bwx.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/intrcnt.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<machine/sgmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

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
name|irongate_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_t
name|irongate0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX only one for now */
end_comment

begin_struct
struct|struct
name|irongate_softc
block|{
name|int
name|junk
decl_stmt|;
comment|/* no softc */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IRONGATE_SOFTC
parameter_list|(
name|dev
parameter_list|)
value|(struct irongate_softc*) device_get_softc(dev)
end_define

begin_decl_stmt
specifier|static
name|alpha_chipset_read_hae_t
name|irongate_read_hae
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|alpha_chipset_write_hae_t
name|irongate_write_hae
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|alpha_chipset_t
name|irongate_chipset
init|=
block|{
name|irongate_read_hae
block|,
name|irongate_write_hae
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * There doesn't appear to be an hae on this platform  */
end_comment

begin_function
specifier|static
name|u_int64_t
name|irongate_read_hae
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|irongate_write_hae
parameter_list|(
name|u_int64_t
name|hae
parameter_list|)
block|{ }
end_function

begin_function_decl
specifier|static
name|int
name|irongate_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|irongate_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|irongate_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|irongate_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|irongate_attach
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
name|bus_setup_intr
argument_list|,
name|isa_setup_intr
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_teardown_intr
argument_list|,
name|isa_teardown_intr
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
name|irongate_driver
init|=
block|{
literal|"irongate"
block|,
name|irongate_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|irongate_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|irongate_init
parameter_list|()
block|{
specifier|static
name|int
name|initted
init|=
literal|0
decl_stmt|;
specifier|static
name|struct
name|bwx_space
name|io_space
decl_stmt|,
name|mem_space
decl_stmt|;
if|if
condition|(
name|initted
condition|)
return|return;
name|initted
operator|=
literal|1
expr_stmt|;
name|chipset
operator|=
name|irongate_chipset
expr_stmt|;
name|alpha_XXX_dmamap_or
operator|=
literal|0UL
expr_stmt|;
name|bwx_init_space
argument_list|(
operator|&
name|io_space
argument_list|,
name|KV
argument_list|(
name|IRONGATE_IO
argument_list|)
argument_list|)
expr_stmt|;
name|bwx_init_space
argument_list|(
operator|&
name|mem_space
argument_list|,
name|KV
argument_list|(
name|IRONGATE_MEM
argument_list|)
argument_list|)
expr_stmt|;
name|busspace_isa_io
operator|=
operator|(
expr|struct
name|alpha_busspace
operator|*
operator|)
operator|&
name|io_space
expr_stmt|;
name|busspace_isa_mem
operator|=
operator|(
expr|struct
name|alpha_busspace
operator|*
operator|)
operator|&
name|mem_space
expr_stmt|;
if|if
condition|(
name|platform
operator|.
name|pci_intr_init
condition|)
name|platform
operator|.
name|pci_intr_init
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|irongate_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|irongate0
condition|)
return|return
name|ENXIO
return|;
name|irongate0
operator|=
name|dev
expr_stmt|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"AMD 751 Core Logic chipset"
argument_list|)
expr_stmt|;
name|isa_init_intr
argument_list|()
expr_stmt|;
name|device_add_child
argument_list|(
name|dev
argument_list|,
literal|"pcib"
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
name|irongate_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|irongate_init
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|platform
operator|.
name|iointr
condition|)
comment|/* XXX */
name|set_iointr
argument_list|(
name|alpha_dispatch_intr
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|chipset_type
argument_list|,
sizeof|sizeof
argument_list|(
name|chipset_type
argument_list|)
argument_list|,
literal|"irongate"
argument_list|)
expr_stmt|;
name|chipset_bwx
operator|=
literal|1
expr_stmt|;
name|chipset_ports
operator|=
name|IRONGATE_IO
expr_stmt|;
name|chipset_memory
operator|=
name|IRONGATE_MEM
expr_stmt|;
name|chipset_dense
operator|=
name|IRONGATE_MEM
expr_stmt|;
comment|/* no s/g support in this chipset, must use bounce-buffers */
name|chipset
operator|.
name|sgmap
operator|=
name|NULL
expr_stmt|;
name|bus_generic_attach
argument_list|(
name|dev
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
name|irongate
argument_list|,
name|root
argument_list|,
name|irongate_driver
argument_list|,
name|irongate_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

