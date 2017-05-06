begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Luiz Otavio O Souza.  * Copyright (c) 2011-2012 Stefan Bethke.  * Copyright (c) 2012 Adrian Chadd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP17X_VAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP17X_VAR_H__
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|IP17X_SWITCH_NONE
block|,
name|IP17X_SWITCH_IP175A
block|,
name|IP17X_SWITCH_IP175C
block|,
name|IP17X_SWITCH_IP175D
block|,
name|IP17X_SWITCH_IP178C
block|, }
name|ip17x_switch_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ip17x_vlan
block|{
name|uint32_t
name|ports
decl_stmt|;
name|int
name|vlanid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ip17x_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|int
name|media
decl_stmt|;
comment|/* cpu port media */
name|int
name|cpuport
decl_stmt|;
comment|/* which PHY is connected to the CPU */
name|int
name|phymask
decl_stmt|;
comment|/* PHYs we manage */
name|int
name|phyport
index|[
name|MII_NPHY
index|]
decl_stmt|;
name|int
name|numports
decl_stmt|;
comment|/* number of ports */
name|int
modifier|*
name|portphy
decl_stmt|;
name|device_t
modifier|*
modifier|*
name|miibus
decl_stmt|;
name|int
name|miipoll
decl_stmt|;
name|etherswitch_info_t
name|info
decl_stmt|;
name|ip17x_switch_type
name|sc_switchtype
decl_stmt|;
name|struct
name|callout
name|callout_tick
decl_stmt|;
name|struct
name|ifnet
modifier|*
modifier|*
name|ifp
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* serialize access to softc */
name|struct
name|ip17x_vlan
name|vlan
index|[
name|IP17X_MAX_VLANS
index|]
decl_stmt|;
name|uint32_t
modifier|*
name|pvid
decl_stmt|;
comment|/* PVID */
name|uint32_t
name|addtag
decl_stmt|;
comment|/* per port add tag flag */
name|uint32_t
name|striptag
decl_stmt|;
comment|/* per port strip tag flag */
name|uint32_t
name|vlan_mode
decl_stmt|;
comment|/* VLAN mode */
struct|struct
block|{
name|int
function_decl|(
modifier|*
name|ip17x_reset
function_decl|)
parameter_list|(
name|struct
name|ip17x_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ip17x_hw_setup
function_decl|)
parameter_list|(
name|struct
name|ip17x_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ip17x_get_vlan_mode
function_decl|)
parameter_list|(
name|struct
name|ip17x_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ip17x_set_vlan_mode
function_decl|)
parameter_list|(
name|struct
name|ip17x_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
block|}
name|hal
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IP17X_IS_SWITCH
parameter_list|(
name|_sc
parameter_list|,
name|_type
parameter_list|)
define|\
value|(!!((_sc)->sc_switchtype == IP17X_SWITCH_ ## _type))
end_define

begin_define
define|#
directive|define
name|IP17X_LOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|IP17X_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|IP17X_LOCK_ASSERT
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
name|IP17X_TRYLOCK
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP17X_VAR_H__ */
end_comment

end_unit

