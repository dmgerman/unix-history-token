begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ukphy.c,v 1.2 1999/04/23 04:24:32 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center, and by Frank van der Linden.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Manuel Bouyer.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/*  * driver for generic unknown PHYs  */
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
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
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
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/miivar.h>
end_include

begin_include
include|#
directive|include
file|"miibus_if.h"
end_include

begin_function_decl
specifier|static
name|int
name|ukphy_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ukphy_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|ukphy_methods
index|[]
init|=
block|{
comment|/* device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ukphy_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ukphy_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|mii_phy_detach
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
specifier|static
name|devclass_t
name|ukphy_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|ukphy_driver
init|=
block|{
literal|"ukphy"
block|,
name|ukphy_methods
block|,
expr|sizeof
operator|(
expr|struct
name|mii_softc
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ukphy
argument_list|,
name|miibus
argument_list|,
name|ukphy_driver
argument_list|,
name|ukphy_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|int
name|ukphy_service
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|,
name|struct
name|mii_data
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|mii_phy_funcs
name|ukphy_funcs
init|=
block|{
name|ukphy_service
block|,
name|ukphy_status
block|,
name|mii_phy_reset
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|ukphy_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
comment|/* 	 * We know something is here, so always match at a low priority. 	 */
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Generic IEEE 802.3u media interface"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_GENERIC
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ukphy_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|mii_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|mii_phy_dev_attach
argument_list|(
name|dev
argument_list|,
name|MIIF_NOMANPAUSE
argument_list|,
operator|&
name|ukphy_funcs
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mii_phy_setmedia
argument_list|(
name|sc
argument_list|)
expr_stmt|;
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
name|ukphy_service
parameter_list|(
name|struct
name|mii_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mii_data
modifier|*
name|mii
parameter_list|,
name|int
name|cmd
parameter_list|)
block|{
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|MII_POLLSTAT
case|:
break|break;
case|case
name|MII_MEDIACHG
case|:
name|mii_phy_setmedia
argument_list|(
name|sc
argument_list|)
expr_stmt|;
break|break;
case|case
name|MII_TICK
case|:
if|if
condition|(
name|mii_phy_tick
argument_list|(
name|sc
argument_list|)
operator|==
name|EJUSTRETURN
condition|)
return|return
operator|(
literal|0
operator|)
return|;
break|break;
block|}
comment|/* Update the media status. */
name|PHY_STATUS
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* Callback if something changed. */
name|mii_phy_update
argument_list|(
name|sc
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

