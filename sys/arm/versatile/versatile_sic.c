begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf(fmt, ##args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIC_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|SIC_RAWSTAT
value|0x04
end_define

begin_define
define|#
directive|define
name|SIC_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SIC_ENSET
value|0x08
end_define

begin_define
define|#
directive|define
name|SIC_ENCLR
value|0x0C
end_define

begin_define
define|#
directive|define
name|SIC_SOFTINTSET
value|0x10
end_define

begin_define
define|#
directive|define
name|SIC_SOFTINTCLR
value|0x14
end_define

begin_define
define|#
directive|define
name|SIC_PICENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|SIC_PICENSET
value|0x20
end_define

begin_define
define|#
directive|define
name|SIC_PICENCLR
value|0x24
end_define

begin_struct
struct|struct
name|versatile_sic_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sic_read_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4(sc->mem_res, (reg))
end_define

begin_define
define|#
directive|define
name|sic_write_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4(sc->mem_res, (reg), (val))
end_define

begin_function
specifier|static
name|int
name|versatile_sic_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_status_okay
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"arm,versatile-sic"
argument_list|)
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
literal|"ARM Versatile SIC"
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
name|versatile_sic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|versatile_sic_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|uint32_t
name|pass_irqs
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|sc
operator|->
name|sc_dev
operator|=
name|dev
expr_stmt|;
comment|/* Request memory resources */
name|rid
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|mem_res
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|mem_res
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Error: could not allocate memory resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Disable all interrupts on SIC */
name|sic_write_4
argument_list|(
name|sc
argument_list|,
name|SIC_ENCLR
argument_list|,
literal|0xffffffff
argument_list|)
expr_stmt|;
comment|/*  	 * XXX: Enable IRQ3 for KMI 	 * Should be replaced by proper interrupts cascading 	 */
name|sic_write_4
argument_list|(
name|sc
argument_list|,
name|SIC_ENSET
argument_list|,
operator|(
literal|1
operator|<<
literal|3
operator|)
argument_list|)
expr_stmt|;
comment|/* 	 * Let PCI and Ethernet interrupts pass through 	 * IRQ25, IRQ27..IRQ31 	 */
name|pass_irqs
operator|=
operator|(
literal|0x1f
operator|<<
literal|27
operator|)
operator||
operator|(
literal|1
operator|<<
literal|25
operator|)
expr_stmt|;
name|sic_write_4
argument_list|(
name|sc
argument_list|,
name|SIC_PICENSET
argument_list|,
name|pass_irqs
argument_list|)
expr_stmt|;
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
name|versatile_sic_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|versatile_sic_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|versatile_sic_attach
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
name|versatile_sic_driver
init|=
block|{
literal|"sic"
block|,
name|versatile_sic_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|versatile_sic_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|versatile_sic_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|sic
argument_list|,
name|simplebus
argument_list|,
name|versatile_sic_driver
argument_list|,
name|versatile_sic_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

