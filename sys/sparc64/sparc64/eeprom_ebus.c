begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1994 Gordon W. Ross  * Copyright (c) 1993 Adam Glass  * Copyright (c) 1996 Paul Kranenburg  * Copyright (c) 1996  * 	The President and Fellows of Harvard College. All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by Harvard University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Paul Kranenburg.  *	This product includes software developed by Harvard University.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)clock.c	8.1 (Berkeley) 6/11/93  *	from: NetBSD: clock.c,v 1.41 2001/07/24 19:29:25 eeh Exp  *  * $FreeBSD$  */
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/eeprom.h>
end_include

begin_include
include|#
directive|include
file|<dev/mk48txx/mk48txxvar.h>
end_include

begin_include
include|#
directive|include
file|"clock_if.h"
end_include

begin_comment
comment|/*  * clock (eeprom) attaches at the sbus or the ebus  */
end_comment

begin_function_decl
specifier|static
name|int
name|eeprom_ebus_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|eeprom_ebus_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|eeprom_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|eeprom_ebus_attach
argument_list|)
block|,
comment|/* clock interface */
name|DEVMETHOD
argument_list|(
name|clock_gettime
argument_list|,
name|mk48txx_gettime
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|clock_settime
argument_list|,
name|mk48txx_settime
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
name|eeprom_ebus_driver
init|=
block|{
literal|"eeprom"
block|,
name|eeprom_ebus_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|mk48txx_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|eeprom
argument_list|,
name|ebus
argument_list|,
name|eeprom_ebus_driver
argument_list|,
name|eeprom_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Attach a clock (really `eeprom') to the ebus.  *  * This is mapped read-only on NetBSD for safety, but this is not possible  * with the current FreeBSD bus code.  *  * the MK48T02 is 2K.  the MK48T08 is 8K, and the MK48T59 is supposed to be  * identical to it.  */
end_comment

begin_function
specifier|static
name|int
name|eeprom_ebus_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|mk48txx_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|sc
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|mk48txx_softc
argument_list|)
argument_list|)
expr_stmt|;
name|rid
operator|=
literal|0
expr_stmt|;
name|res
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
operator|&
name|rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"could not allocate resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|sc
operator|->
name|sc_bst
operator|=
name|rman_get_bustag
argument_list|(
name|res
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_bsh
operator|=
name|rman_get_bushandle
argument_list|(
name|res
argument_list|)
expr_stmt|;
return|return
operator|(
name|eeprom_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

