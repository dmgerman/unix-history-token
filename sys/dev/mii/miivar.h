begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: miivar.h,v 1.8 1999/04/23 04:24:32 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_MIIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_MIIVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Media Independent Interface autoconfiguration defintions.  *  * This file exports an interface which attempts to be compatible  * with the BSD/OS 3.0 interface.  */
end_comment

begin_struct_decl
struct_decl|struct
name|mii_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Callbacks from MII layer into network interface device driver.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|mii_readreg_t
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mii_writereg_t
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mii_statchg_t
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * A network interface driver has one of these structures in its softc.  * It is the interface from the network interface driver to the MII  * layer.  */
end_comment

begin_struct
struct|struct
name|mii_data
block|{
name|struct
name|ifmedia
name|mii_media
decl_stmt|;
comment|/* media information */
name|struct
name|ifnet
modifier|*
name|mii_ifp
decl_stmt|;
comment|/* pointer back to network interface */
comment|/* 	 * For network interfaces with multiple PHYs, a list of all 	 * PHYs is required so they can all be notified when a media 	 * request is made. 	 */
name|LIST_HEAD
argument_list|(
argument|mii_listhead
argument_list|,
argument|mii_softc
argument_list|)
name|mii_phys
expr_stmt|;
name|int
name|mii_instance
decl_stmt|;
comment|/* 	 * PHY driver fills this in with active media status. 	 */
name|int
name|mii_media_status
decl_stmt|;
name|int
name|mii_media_active
decl_stmt|;
comment|/* 	 * Calls from MII layer into network interface driver. 	 */
name|mii_readreg_t
name|mii_readreg
decl_stmt|;
name|mii_writereg_t
name|mii_writereg
decl_stmt|;
name|mii_statchg_t
name|mii_statchg
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mii_data
name|mii_data_t
typedef|;
end_typedef

begin_comment
comment|/*  * This call is used by the MII layer to call into the PHY driver  * to perform a `service request'.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|mii_downcall_t
function_decl|)
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
end_typedef

begin_comment
comment|/*  * Requests that can be made to the downcall.  */
end_comment

begin_define
define|#
directive|define
name|MII_TICK
value|1
end_define

begin_comment
comment|/* once-per-second tick */
end_comment

begin_define
define|#
directive|define
name|MII_MEDIACHG
value|2
end_define

begin_comment
comment|/* user changed media; perform the switch */
end_comment

begin_define
define|#
directive|define
name|MII_POLLSTAT
value|3
end_define

begin_comment
comment|/* user requested media status; fill it in */
end_comment

begin_comment
comment|/*  * Each PHY driver's softc has one of these as the first member.  * XXX This would be better named "phy_softc", but this is the name  * XXX BSDI used, and we would like to have the same interface.  */
end_comment

begin_struct
struct|struct
name|mii_softc
block|{
name|device_t
name|mii_dev
decl_stmt|;
comment|/* generic device glue */
name|LIST_ENTRY
argument_list|(
argument|mii_softc
argument_list|)
name|mii_list
expr_stmt|;
comment|/* entry on parent's PHY list */
name|int
name|mii_phy
decl_stmt|;
comment|/* our MII address */
name|int
name|mii_inst
decl_stmt|;
comment|/* instance for ifmedia */
name|mii_downcall_t
name|mii_service
decl_stmt|;
comment|/* our downcall */
name|struct
name|mii_data
modifier|*
name|mii_pdata
decl_stmt|;
comment|/* pointer to parent's mii_data */
name|struct
name|callout_handle
name|mii_auto_ch
decl_stmt|;
comment|/* callout handle for phy autoneg */
name|int
name|mii_flags
decl_stmt|;
comment|/* misc. flags; see below */
name|int
name|mii_capabilities
decl_stmt|;
comment|/* capabilities from BMSR */
name|int
name|mii_ticks
decl_stmt|;
comment|/* MII_TICK counter */
name|int
name|mii_active
decl_stmt|;
comment|/* last active media */
name|int
name|mii_status
decl_stmt|;
comment|/* last active status */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mii_softc
name|mii_softc_t
typedef|;
end_typedef

begin_comment
comment|/* mii_flags */
end_comment

begin_define
define|#
directive|define
name|MIIF_NOISOLATE
value|0x0001
end_define

begin_comment
comment|/* do not isolate the PHY */
end_comment

begin_define
define|#
directive|define
name|MIIF_DOINGAUTO
value|0x0002
end_define

begin_comment
comment|/* doing autonegotiation */
end_comment

begin_comment
comment|/*  * Used to attach a PHY to a parent.  */
end_comment

begin_struct
struct|struct
name|mii_attach_args
block|{
name|struct
name|mii_data
modifier|*
name|mii_data
decl_stmt|;
comment|/* pointer to parent data */
name|int
name|mii_phyno
decl_stmt|;
comment|/* MII address */
name|int
name|mii_id1
decl_stmt|;
comment|/* PHY ID register 1 */
name|int
name|mii_id2
decl_stmt|;
comment|/* PHY ID register 2 */
name|int
name|mii_capmask
decl_stmt|;
comment|/* capability mask from BMSR */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mii_attach_args
name|mii_attach_args_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|PHY_READ
parameter_list|(
name|p
parameter_list|,
name|r
parameter_list|)
define|\
value|MIIBUS_READREG((p)->mii_dev, (p)->mii_phy, (r))
end_define

begin_define
define|#
directive|define
name|PHY_WRITE
parameter_list|(
name|p
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
define|\
value|MIIBUS_WRITEREG((p)->mii_dev, (p)->mii_phy, (r), (v))
end_define

begin_decl_stmt
specifier|extern
name|devclass_t
name|miibus_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|driver_t
name|miibus_driver
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|miibus_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|miibus_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|miibus_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_anar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_mediachg
parameter_list|(
name|struct
name|mii_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_tick
parameter_list|(
name|struct
name|mii_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_pollstat
parameter_list|(
name|struct
name|mii_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_phy_probe
parameter_list|(
name|device_t
parameter_list|,
name|device_t
modifier|*
parameter_list|,
name|ifm_change_cb_t
parameter_list|,
name|ifm_stat_cb_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_add_media
parameter_list|(
name|struct
name|mii_data
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_media_from_bmcr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_phy_auto
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_phy_auto_stop
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_phy_reset
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_phy_update
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_phy_tick
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ukphy_status
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_MIIVAR_H_ */
end_comment

end_unit

