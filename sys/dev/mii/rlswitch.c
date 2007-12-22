begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  * Copyright (c) 2006 Bernd Walter.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/*  * driver for RealTek 8305 pseudo PHYs  */
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
file|<net/if_arp.h>
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
file|"miidevs.h"
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<pci/if_rlreg.h>
end_include

begin_include
include|#
directive|include
file|"miibus_if.h"
end_include

begin_comment
comment|//#define RL_DEBUG
end_comment

begin_define
define|#
directive|define
name|RL_VLAN
end_define

begin_function_decl
specifier|static
name|int
name|rlswitch_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|rlswitch_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|rlswitch_methods
index|[]
init|=
block|{
comment|/* device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|rlswitch_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|rlswitch_attach
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
name|devclass_t
name|rlswitch_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|rlswitch_driver
init|=
block|{
literal|"rlswitch"
block|,
name|rlswitch_methods
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
name|rlswitch
argument_list|,
name|miibus
argument_list|,
name|rlswitch_driver
argument_list|,
name|rlswitch_devclass
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
name|rlswitch_service
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

begin_function_decl
specifier|static
name|void
name|rlswitch_status
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|RL_DEBUG
end_ifdef

begin_function_decl
specifier|static
name|void
name|rlswitch_phydump
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|mii_phydesc
name|rlswitches
index|[]
init|=
block|{
name|MII_PHY_DESC
argument_list|(
name|xxREALTEK
argument_list|,
name|RTL8305SC
argument_list|)
block|,
name|MII_PHY_END
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|rlswitch_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|rv
decl_stmt|;
name|rv
operator|=
name|mii_phy_dev_probe
argument_list|(
name|dev
argument_list|,
name|rlswitches
argument_list|,
name|BUS_PROBE_DEFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|<=
literal|0
condition|)
return|return
operator|(
name|rv
operator|)
return|;
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
name|rlswitch_attach
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
name|struct
name|mii_attach_args
modifier|*
name|ma
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|mii
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|ma
operator|=
name|device_get_ivars
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|mii_dev
operator|=
name|device_get_parent
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|mii
operator|=
name|device_get_softc
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|)
expr_stmt|;
comment|/* 	 * We handle all pseudo PHY in a single instance, so never allow 	 * non-zero * instances! 	 */
if|if
condition|(
name|mii
operator|->
name|mii_instance
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"ignoring this PHY, non-zero instance\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|LIST_INSERT_HEAD
argument_list|(
operator|&
name|mii
operator|->
name|mii_phys
argument_list|,
name|sc
argument_list|,
name|mii_list
argument_list|)
expr_stmt|;
name|sc
operator|->
name|mii_inst
operator|=
name|mii
operator|->
name|mii_instance
expr_stmt|;
name|sc
operator|->
name|mii_phy
operator|=
name|ma
operator|->
name|mii_phyno
expr_stmt|;
name|sc
operator|->
name|mii_service
operator|=
name|rlswitch_service
expr_stmt|;
name|sc
operator|->
name|mii_pdata
operator|=
name|mii
expr_stmt|;
name|mii
operator|->
name|mii_instance
operator|++
expr_stmt|;
name|sc
operator|->
name|mii_flags
operator||=
name|MIIF_NOISOLATE
expr_stmt|;
define|#
directive|define
name|ADD
parameter_list|(
name|m
parameter_list|,
name|c
parameter_list|)
value|ifmedia_add(&mii->mii_media, (m), (c), NULL)
if|#
directive|if
literal|0
comment|/* See above. */
block|ADD(IFM_MAKEWORD(IFM_ETHER, IFM_NONE, 0, sc->mii_inst), 	    BMCR_ISO);
endif|#
directive|endif
if|#
directive|if
literal|0
block|ADD(IFM_MAKEWORD(IFM_ETHER, IFM_100_TX, IFM_LOOP, sc->mii_inst), 	    BMCR_LOOP|BMCR_S100);
endif|#
directive|endif
name|sc
operator|->
name|mii_capabilities
operator|=
name|BMSR_100TXFDX
operator|&
name|ma
operator|->
name|mii_capmask
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|mii_phy_add_media
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|ADD
ifdef|#
directive|ifdef
name|RL_DEBUG
name|rlswitch_phydump
argument_list|(
name|dev
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|RL_VLAN
name|int
name|val
decl_stmt|;
comment|/* Global Control 0 */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|0
operator|<<
literal|10
expr_stmt|;
comment|/* enable 802.1q VLAN Tag support */
name|val
operator||=
literal|0
operator|<<
literal|9
expr_stmt|;
comment|/* enable VLAN ingress filtering */
name|val
operator||=
literal|1
operator|<<
literal|8
expr_stmt|;
comment|/* disable VLAN tag admit control */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|5
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|4
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|3
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|1
expr_stmt|;
comment|/* reserved */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|0
argument_list|,
literal|16
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Global Control 2 */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* reserved */
name|val
operator||=
literal|0
operator|<<
literal|14
expr_stmt|;
comment|/* enable 1552 Bytes support */
name|val
operator||=
literal|1
operator|<<
literal|13
expr_stmt|;
comment|/* enable broadcast input drop */
name|val
operator||=
literal|1
operator|<<
literal|12
expr_stmt|;
comment|/* forward reserved control frames */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* disable forwarding unicast frames to other VLAN's */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* disable forwarding ARP broadcasts to other VLAN's */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* enable 48 pass 1 */
name|val
operator||=
literal|0
operator|<<
literal|8
expr_stmt|;
comment|/* enable VLAN */
name|val
operator||=
literal|1
operator|<<
literal|7
expr_stmt|;
comment|/* reserved */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* enable defer */
name|val
operator||=
literal|1
operator|<<
literal|5
expr_stmt|;
comment|/* 43ms LED blink time */
name|val
operator||=
literal|3
operator|<<
literal|3
expr_stmt|;
comment|/* 16:1 queue weight */
name|val
operator||=
literal|1
operator|<<
literal|2
expr_stmt|;
comment|/* disable broadcast storm control */
name|val
operator||=
literal|1
operator|<<
literal|1
expr_stmt|;
comment|/* enable power-on LED blinking */
name|val
operator||=
literal|1
operator|<<
literal|0
expr_stmt|;
comment|/* reserved */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|0
argument_list|,
literal|18
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 0 Control Register 0 */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* reserved */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* drop received packets with wrong VLAN tag */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* disable 802.1p priority classification */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* disable diffserv priority classification */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|3
operator|<<
literal|4
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|3
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|2
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|0
expr_stmt|;
comment|/* remove VLAN tags on output */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|0
argument_list|,
literal|22
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 1 Control Register 0 */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* reserved */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* drop received packets with wrong VLAN tag */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* disable 802.1p priority classification */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* disable diffserv priority classification */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|3
operator|<<
literal|4
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|3
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|2
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|0
expr_stmt|;
comment|/* remove VLAN tags on output */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|1
argument_list|,
literal|22
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 2 Control Register 0 */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* reserved */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* drop received packets with wrong VLAN tag */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* disable 802.1p priority classification */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* disable diffserv priority classification */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|3
operator|<<
literal|4
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|3
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|2
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|0
expr_stmt|;
comment|/* remove VLAN tags on output */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|2
argument_list|,
literal|22
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 3 Control Register 0 */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* reserved */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* drop received packets with wrong VLAN tag */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* disable 802.1p priority classification */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* disable diffserv priority classification */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|3
operator|<<
literal|4
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|3
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|2
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|0
expr_stmt|;
comment|/* remove VLAN tags on output */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|3
argument_list|,
literal|22
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 4 (system port) Control Register 0 */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* reserved */
name|val
operator||=
literal|0
operator|<<
literal|11
expr_stmt|;
comment|/* don't drop received packets with wrong VLAN tag */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* disable 802.1p priority classification */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* disable diffserv priority classification */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|3
operator|<<
literal|4
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|3
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|2
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|2
operator|<<
literal|0
expr_stmt|;
comment|/* add VLAN tags for untagged packets on output */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|4
argument_list|,
literal|22
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 0 Control Register 1 and VLAN A */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|0x0
operator|<<
literal|12
expr_stmt|;
comment|/* Port 0 VLAN Index */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|7
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x11
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN A membership */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|0
argument_list|,
literal|24
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 0 Control Register 2 and VLAN A */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|14
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|13
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|12
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x100
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN A ID */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|0
argument_list|,
literal|25
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 1 Control Register 1 and VLAN B */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|0x1
operator|<<
literal|12
expr_stmt|;
comment|/* Port 1 VLAN Index */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|7
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x12
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN B membership */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|1
argument_list|,
literal|24
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 1 Control Register 2 and VLAN B */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|14
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|13
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|12
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x101
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN B ID */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|1
argument_list|,
literal|25
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 2 Control Register 1 and VLAN C */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|0x2
operator|<<
literal|12
expr_stmt|;
comment|/* Port 2 VLAN Index */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|7
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x14
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN C membership */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|2
argument_list|,
literal|24
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 2 Control Register 2 and VLAN C */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|14
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|13
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|12
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x102
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN C ID */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|2
argument_list|,
literal|25
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 3 Control Register 1 and VLAN D */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|0x3
operator|<<
literal|12
expr_stmt|;
comment|/* Port 3 VLAN Index */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|7
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x18
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN D membership */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|3
argument_list|,
literal|24
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 3 Control Register 2 and VLAN D */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|14
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|13
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|12
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x103
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN D ID */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|3
argument_list|,
literal|25
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 4 Control Register 1 and VLAN E */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|0x0
operator|<<
literal|12
expr_stmt|;
comment|/* Port 4 VLAN Index */
name|val
operator||=
literal|1
operator|<<
literal|11
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|10
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|9
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|7
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|6
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN E membership */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|4
argument_list|,
literal|24
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Port 4 Control Register 2 and VLAN E */
name|val
operator|=
literal|0
expr_stmt|;
name|val
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|14
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|13
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|1
operator|<<
literal|12
expr_stmt|;
comment|/* internal use */
name|val
operator||=
literal|0x104
operator|<<
literal|0
expr_stmt|;
comment|/* VLAN E ID */
name|MIIBUS_WRITEREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
literal|4
argument_list|,
literal|25
argument_list|,
name|val
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|RL_DEBUG
name|rlswitch_phydump
argument_list|(
name|dev
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|MIIBUS_MEDIAINIT
argument_list|(
name|sc
operator|->
name|mii_dev
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
name|rlswitch_service
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
break|break;
case|case
name|MII_TICK
case|:
comment|/* 		 * Is the interface even up? 		 */
if|if
condition|(
operator|(
name|mii
operator|->
name|mii_ifp
operator|->
name|if_flags
operator|&
name|IFF_UP
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
break|break;
block|}
comment|/* Update the media status. */
name|rlswitch_status
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* Callback if something changed. */
comment|// mii_phy_update(sc, cmd);
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|rlswitch_status
parameter_list|(
name|struct
name|mii_softc
modifier|*
name|phy
parameter_list|)
block|{
name|struct
name|mii_data
modifier|*
name|mii
init|=
name|phy
operator|->
name|mii_pdata
decl_stmt|;
name|mii
operator|->
name|mii_media_status
operator|=
name|IFM_AVALID
expr_stmt|;
name|mii
operator|->
name|mii_media_active
operator|=
name|IFM_ETHER
expr_stmt|;
name|mii
operator|->
name|mii_media_status
operator||=
name|IFM_ACTIVE
expr_stmt|;
name|mii
operator|->
name|mii_media_active
operator||=
name|IFM_100_TX
operator||
name|IFM_FDX
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|RL_DEBUG
end_ifdef

begin_function
specifier|static
name|void
name|rlswitch_phydump
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|phy
decl_stmt|,
name|reg
decl_stmt|,
name|val
decl_stmt|;
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
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"rlswitchphydump\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|phy
operator|=
literal|0
init|;
name|phy
operator|<=
literal|5
condition|;
name|phy
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"PHY%i:"
argument_list|,
name|phy
argument_list|)
expr_stmt|;
for|for
control|(
name|reg
operator|=
literal|0
init|;
name|reg
operator|<=
literal|31
condition|;
name|reg
operator|++
control|)
block|{
name|val
operator|=
name|MIIBUS_READREG
argument_list|(
name|sc
operator|->
name|mii_dev
argument_list|,
name|phy
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" 0x%x"
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

