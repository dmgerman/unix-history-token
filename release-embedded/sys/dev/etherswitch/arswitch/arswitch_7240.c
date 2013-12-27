begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Stefan Bethke.  * Copyright (c) 2012 Adrian Chadd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
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
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iic.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iiconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iicbus.h>
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
file|<dev/etherswitch/mdio.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/etherswitch.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitchreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitchvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitch_reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitch_phy.h>
end_include

begin_comment
comment|/* XXX for probe */
end_comment

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitch_7240.h>
end_include

begin_include
include|#
directive|include
file|"mdio_if.h"
end_include

begin_include
include|#
directive|include
file|"miibus_if.h"
end_include

begin_include
include|#
directive|include
file|"etherswitch_if.h"
end_include

begin_comment
comment|/*  * AR7240 specific functions  */
end_comment

begin_function
specifier|static
name|int
name|ar7240_hw_setup
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialise other global values for the AR7240.  */
end_comment

begin_function
specifier|static
name|int
name|ar7240_hw_global_setup
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* Enable CPU port; disable mirror port */
name|arswitch_writereg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_CPU_PORT
argument_list|,
name|AR8X16_CPU_PORT_EN
operator||
name|AR8X16_CPU_MIRROR_DIS
argument_list|)
expr_stmt|;
comment|/* Setup TAG priority mapping */
name|arswitch_writereg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_TAG_PRIO
argument_list|,
literal|0xfa50
argument_list|)
expr_stmt|;
comment|/* Enable broadcast frames transmitted to the CPU */
name|arswitch_writereg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_FLOOD_MASK
argument_list|,
name|AR8X16_FLOOD_MASK_BCAST_TO_CPU
operator||
literal|0x003f003f
argument_list|)
expr_stmt|;
comment|/* Setup MTU */
name|arswitch_modifyreg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_GLOBAL_CTRL
argument_list|,
name|AR7240_GLOBAL_CTRL_MTU_MASK
argument_list|,
name|SM
argument_list|(
literal|1536
argument_list|,
name|AR7240_GLOBAL_CTRL_MTU_MASK
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Service Tag */
name|arswitch_modifyreg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_SERVICE_TAG
argument_list|,
name|AR8X16_SERVICE_TAG_MASK
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The AR7240 probes the same as the AR8216.  *  * However, the support is slightly different.  *  * So instead of checking the PHY revision or mask register contents,  * we simply fall back to a hint check.  */
end_comment

begin_function
name|int
name|ar7240_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|is_7240
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|resource_int_value
argument_list|(
name|device_get_name
argument_list|(
name|dev
argument_list|)
argument_list|,
name|device_get_unit
argument_list|(
name|dev
argument_list|)
argument_list|,
literal|"is_7240"
argument_list|,
operator|&
name|is_7240
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
name|is_7240
operator|==
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ar7240_attach
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
block|{
name|sc
operator|->
name|hal
operator|.
name|arswitch_hw_setup
operator|=
name|ar7240_hw_setup
expr_stmt|;
name|sc
operator|->
name|hal
operator|.
name|arswitch_hw_global_setup
operator|=
name|ar7240_hw_global_setup
expr_stmt|;
comment|/* Set the switch vlan capabilities. */
name|sc
operator|->
name|info
operator|.
name|es_vlan_caps
operator|=
name|ETHERSWITCH_VLAN_DOT1Q
operator||
name|ETHERSWITCH_VLAN_PORT
operator||
name|ETHERSWITCH_VLAN_DOUBLE_TAG
expr_stmt|;
name|sc
operator|->
name|info
operator|.
name|es_nvlangroups
operator|=
name|AR8X16_MAX_VLANS
expr_stmt|;
block|}
end_function

end_unit

