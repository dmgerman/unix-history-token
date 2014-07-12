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
file|<sys/iic.h>
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
file|<dev/etherswitch/arswitch/arswitch_8316.h>
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
comment|/*  * AR8316 specific functions  */
end_comment

begin_function
specifier|static
name|int
name|ar8316_hw_setup
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* 	 * Configure the switch mode based on whether: 	 * 	 * + The switch port is GMII/RGMII; 	 * + Port 4 is either connected to the CPU or to the internal switch. 	 */
if|if
condition|(
name|sc
operator|->
name|is_rgmii
operator|&&
name|sc
operator|->
name|phy4cpu
condition|)
block|{
name|arswitch_writereg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_MODE
argument_list|,
name|AR8X16_MODE_RGMII_PORT4_ISO
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: MAC port == RGMII, port 4 = dedicated PHY\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sc
operator|->
name|is_rgmii
condition|)
block|{
name|arswitch_writereg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_MODE
argument_list|,
name|AR8X16_MODE_RGMII_PORT4_SWITCH
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: MAC port == RGMII, port 4 = switch port\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sc
operator|->
name|is_gmii
condition|)
block|{
name|arswitch_writereg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_MODE
argument_list|,
name|AR8X16_MODE_GMII
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: MAC port == GMII\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: unknown switch PHY config\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* 1ms wait for things to settle */
comment|/* 	 * If port 4 is RGMII, force workaround 	 */
if|if
condition|(
name|sc
operator|->
name|is_rgmii
operator|&&
name|sc
operator|->
name|phy4cpu
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: port 4 RGMII workaround\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
comment|/* work around for phy4 rgmii mode */
name|arswitch_writedbg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|4
argument_list|,
literal|0x12
argument_list|,
literal|0x480c
argument_list|)
expr_stmt|;
comment|/* rx delay */
name|arswitch_writedbg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|4
argument_list|,
literal|0x0
argument_list|,
literal|0x824e
argument_list|)
expr_stmt|;
comment|/* tx delay */
name|arswitch_writedbg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|4
argument_list|,
literal|0x5
argument_list|,
literal|0x3d47
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* 1ms, again to let things settle */
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialise other global values, for the AR8316.  */
end_comment

begin_function
specifier|static
name|int
name|ar8316_hw_global_setup
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
block|{
name|arswitch_writereg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|0x38
argument_list|,
name|AR8X16_MAGIC
argument_list|)
expr_stmt|;
comment|/* Enable CPU port and disable mirror port. */
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
comment|/* Setup TAG priority mapping. */
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
comment|/* Enable ARP frame acknowledge. */
name|arswitch_modifyreg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_AT_CTRL
argument_list|,
literal|0
argument_list|,
name|AR8X16_AT_CTRL_ARP_EN
argument_list|)
expr_stmt|;
comment|/* 	 * Flood address table misses to all ports, and enable forwarding of 	 * broadcasts to the cpu port. 	 */
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
comment|/* Enable jumbo frames. */
name|arswitch_modifyreg
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
name|AR8X16_REG_GLOBAL_CTRL
argument_list|,
name|AR8316_GLOBAL_CTRL_MTU_MASK
argument_list|,
literal|9018
operator|+
literal|8
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|/* Setup service TAG. */
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

begin_function
name|void
name|ar8316_attach
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
name|ar8316_hw_setup
expr_stmt|;
name|sc
operator|->
name|hal
operator|.
name|arswitch_hw_global_setup
operator|=
name|ar8316_hw_global_setup
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

