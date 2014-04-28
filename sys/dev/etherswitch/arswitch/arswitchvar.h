begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Stefan Bethke.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARSWITCHVAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARSWITCHVAR_H__
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|AR8X16_SWITCH_NONE
block|,
name|AR8X16_SWITCH_AR7240
block|,
name|AR8X16_SWITCH_AR8216
block|,
name|AR8X16_SWITCH_AR8226
block|,
name|AR8X16_SWITCH_AR8316
block|,
name|AR8X16_SWITCH_AR9340
block|,
name|AR8X16_SWITCH_AR8327
block|,
name|AR8X16_SWITCH_AR8337
block|, }
name|ar8x16_switch_type
typedef|;
end_typedef

begin_comment
comment|/*  * XXX TODO: start using this where required  */
end_comment

begin_define
define|#
directive|define
name|AR8X16_IS_SWITCH
parameter_list|(
name|_sc
parameter_list|,
name|_type
parameter_list|)
define|\
value|(!!((_sc)->sc_switchtype == AR8X16_SWITCH_ ## _type))
end_define

begin_define
define|#
directive|define
name|ARSWITCH_NUM_PORTS
value|MAX(AR8327_NUM_PORTS, AR8X16_NUM_PORTS)
end_define

begin_define
define|#
directive|define
name|ARSWITCH_NUM_PHYS
value|MAX(AR8327_NUM_PHYS, AR8X16_NUM_PHYS)
end_define

begin_struct
struct|struct
name|arswitch_softc
block|{
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* serialize access to softc */
name|device_t
name|sc_dev
decl_stmt|;
name|int
name|phy4cpu
decl_stmt|;
comment|/* PHY4 is connected to the CPU */
name|int
name|numphys
decl_stmt|;
comment|/* PHYs we manage */
name|int
name|is_rgmii
decl_stmt|;
comment|/* PHY mode is RGMII (XXX which PHY?) */
name|int
name|is_gmii
decl_stmt|;
comment|/* PHY mode is GMII (XXX which PHY?) */
name|int
name|is_mii
decl_stmt|;
comment|/* PHY mode is MII (XXX which PHY?) */
name|int
name|page
decl_stmt|;
name|int
name|is_internal_switch
decl_stmt|;
name|int
name|chip_ver
decl_stmt|;
name|int
name|chip_rev
decl_stmt|;
name|int
name|mii_lo_first
decl_stmt|;
name|ar8x16_switch_type
name|sc_switchtype
decl_stmt|;
comment|/* should be the max of both pre-AR8327 and AR8327 ports */
name|char
modifier|*
name|ifname
index|[
name|ARSWITCH_NUM_PHYS
index|]
decl_stmt|;
name|device_t
name|miibus
index|[
name|ARSWITCH_NUM_PHYS
index|]
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
index|[
name|ARSWITCH_NUM_PHYS
index|]
decl_stmt|;
name|struct
name|callout
name|callout_tick
decl_stmt|;
name|etherswitch_info_t
name|info
decl_stmt|;
comment|/* VLANs support */
name|int
name|vid
index|[
name|AR8X16_MAX_VLANS
index|]
decl_stmt|;
name|uint32_t
name|vlan_mode
decl_stmt|;
struct|struct
block|{
comment|/* Global setup */
name|int
function_decl|(
modifier|*
name|arswitch_hw_setup
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|arswitch_hw_global_setup
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* Port functions */
name|void
function_decl|(
modifier|*
name|arswitch_port_init
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* ATU functions */
name|int
function_decl|(
modifier|*
name|arswitch_atu_flush
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* VLAN functions */
name|int
function_decl|(
modifier|*
name|arswitch_port_vlan_setup
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|,
name|etherswitch_port_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|arswitch_port_vlan_get
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|,
name|etherswitch_port_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|arswitch_vlan_init_hw
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|arswitch_vlan_getvgroup
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|,
name|etherswitch_vlangroup_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|arswitch_vlan_setvgroup
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|,
name|etherswitch_vlangroup_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|arswitch_vlan_get_pvid
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|arswitch_vlan_set_pvid
function_decl|)
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
name|hal
struct|;
struct|struct
block|{
name|uint32_t
name|port0_status
decl_stmt|;
name|uint32_t
name|port5_status
decl_stmt|;
name|uint32_t
name|port6_status
decl_stmt|;
block|}
name|ar8327
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ARSWITCH_LOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ARSWITCH_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ARSWITCH_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|_what
parameter_list|)
define|\
value|mtx_assert(&(_sc)->sc_mtx, (_what))
end_define

begin_define
define|#
directive|define
name|ARSWITCH_TRYLOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_trylock(&(_sc)->sc_mtx)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|dev
parameter_list|,
name|args
modifier|...
parameter_list|)
value|device_printf(dev, args)
end_define

begin_define
define|#
directive|define
name|DEVERR
parameter_list|(
name|dev
parameter_list|,
name|err
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do { \ 		if (err != 0) device_printf(dev, fmt, err, args); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_INCRVAR
parameter_list|(
name|var
parameter_list|)
value|do { \ 		var++; \ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|dev
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEVERR
parameter_list|(
name|dev
parameter_list|,
name|err
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_INCRVAR
parameter_list|(
name|var
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ARSWITCHVAR_H__ */
end_comment

end_unit

