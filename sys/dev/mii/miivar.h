begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: miivar.h,v 1.8 1999/04/23 04:24:32 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_comment
comment|/* XXX driver API temporary */
end_comment

begin_comment
comment|/*  * Media Independent Interface data structure defintions  */
end_comment

begin_struct_decl
struct_decl|struct
name|mii_softc
struct_decl|;
end_struct_decl

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
name|if_t
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
name|u_int
name|mii_instance
decl_stmt|;
comment|/* 	 * PHY driver fills this in with active media status. 	 */
name|u_int
name|mii_media_status
decl_stmt|;
name|u_int
name|mii_media_active
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
comment|/*  * Functions provided by the PHY to perform various functions.  */
end_comment

begin_struct
struct|struct
name|mii_phy_funcs
block|{
name|int
function_decl|(
modifier|*
name|pf_service
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
name|void
function_decl|(
modifier|*
name|pf_status
function_decl|)
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pf_reset
function_decl|)
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

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
name|uint32_t
name|mii_mpd_oui
decl_stmt|;
comment|/* the PHY's OUI (MII_OUI())*/
name|uint32_t
name|mii_mpd_model
decl_stmt|;
comment|/* the PHY's model (MII_MODEL())*/
name|uint32_t
name|mii_mpd_rev
decl_stmt|;
comment|/* the PHY's revision (MII_REV())*/
name|u_int
name|mii_capmask
decl_stmt|;
comment|/* capability mask for BMSR */
name|u_int
name|mii_phy
decl_stmt|;
comment|/* our MII address */
name|u_int
name|mii_offset
decl_stmt|;
comment|/* first PHY, second PHY, etc. */
name|u_int
name|mii_inst
decl_stmt|;
comment|/* instance for ifmedia */
comment|/* Our PHY functions. */
specifier|const
name|struct
name|mii_phy_funcs
modifier|*
name|mii_funcs
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|mii_pdata
decl_stmt|;
comment|/* pointer to parent's mii_data */
name|u_int
name|mii_flags
decl_stmt|;
comment|/* misc. flags; see below */
name|u_int
name|mii_capabilities
decl_stmt|;
comment|/* capabilities from BMSR */
name|u_int
name|mii_extcapabilities
decl_stmt|;
comment|/* extended capabilities */
name|u_int
name|mii_ticks
decl_stmt|;
comment|/* MII_TICK counter */
name|u_int
name|mii_anegticks
decl_stmt|;
comment|/* ticks before retrying aneg */
name|u_int
name|mii_media_active
decl_stmt|;
comment|/* last active media */
name|u_int
name|mii_media_status
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
name|MIIF_INITDONE
value|0x00000001
end_define

begin_comment
comment|/* has been initialized (mii_data) */
end_comment

begin_define
define|#
directive|define
name|MIIF_NOISOLATE
value|0x00000002
end_define

begin_comment
comment|/* do not isolate the PHY */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MIIF_NOLOOP
value|0x00000004
end_define

begin_comment
comment|/* no loopback capability */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIIF_DOINGAUTO
value|0x00000008
end_define

begin_comment
comment|/* doing autonegotiation (mii_softc) */
end_comment

begin_define
define|#
directive|define
name|MIIF_AUTOTSLEEP
value|0x00000010
end_define

begin_comment
comment|/* use tsleep(), not callout() */
end_comment

begin_define
define|#
directive|define
name|MIIF_HAVEFIBER
value|0x00000020
end_define

begin_comment
comment|/* from parent: has fiber interface */
end_comment

begin_define
define|#
directive|define
name|MIIF_HAVE_GTCR
value|0x00000040
end_define

begin_comment
comment|/* has 100base-T2/1000base-T CR */
end_comment

begin_define
define|#
directive|define
name|MIIF_IS_1000X
value|0x00000080
end_define

begin_comment
comment|/* is a 1000BASE-X device */
end_comment

begin_define
define|#
directive|define
name|MIIF_DOPAUSE
value|0x00000100
end_define

begin_comment
comment|/* advertise PAUSE capability */
end_comment

begin_define
define|#
directive|define
name|MIIF_IS_HPNA
value|0x00000200
end_define

begin_comment
comment|/* is a HomePNA device */
end_comment

begin_define
define|#
directive|define
name|MIIF_FORCEANEG
value|0x00000400
end_define

begin_comment
comment|/* force auto-negotiation */
end_comment

begin_define
define|#
directive|define
name|MIIF_NOMANPAUSE
value|0x00100000
end_define

begin_comment
comment|/* no manual PAUSE selection */
end_comment

begin_define
define|#
directive|define
name|MIIF_FORCEPAUSE
value|0x00200000
end_define

begin_comment
comment|/* force PAUSE advertisement */
end_comment

begin_define
define|#
directive|define
name|MIIF_MACPRIV0
value|0x01000000
end_define

begin_comment
comment|/* private to the MAC driver */
end_comment

begin_define
define|#
directive|define
name|MIIF_MACPRIV1
value|0x02000000
end_define

begin_comment
comment|/* private to the MAC driver */
end_comment

begin_define
define|#
directive|define
name|MIIF_MACPRIV2
value|0x04000000
end_define

begin_comment
comment|/* private to the MAC driver */
end_comment

begin_define
define|#
directive|define
name|MIIF_PHYPRIV0
value|0x10000000
end_define

begin_comment
comment|/* private to the PHY driver */
end_comment

begin_define
define|#
directive|define
name|MIIF_PHYPRIV1
value|0x20000000
end_define

begin_comment
comment|/* private to the PHY driver */
end_comment

begin_define
define|#
directive|define
name|MIIF_PHYPRIV2
value|0x40000000
end_define

begin_comment
comment|/* private to the PHY driver */
end_comment

begin_comment
comment|/* Default mii_anegticks values */
end_comment

begin_define
define|#
directive|define
name|MII_ANEGTICKS
value|5
end_define

begin_define
define|#
directive|define
name|MII_ANEGTICKS_GIGE
value|17
end_define

begin_define
define|#
directive|define
name|MIIF_INHERIT_MASK
value|(MIIF_NOISOLATE|MIIF_NOLOOP|MIIF_AUTOTSLEEP)
end_define

begin_comment
comment|/*  * Special `locators' passed to mii_attach().  If one of these is not  * an `any' value, we look for *that* PHY and configure it.  If both  * are not `any', that is an error, and mii_attach() will fail.  */
end_comment

begin_define
define|#
directive|define
name|MII_OFFSET_ANY
value|-1
end_define

begin_define
define|#
directive|define
name|MII_PHY_ANY
value|-1
end_define

begin_comment
comment|/*  * Constants used to describe the type of attachment between MAC and PHY.  */
end_comment

begin_enum
enum|enum
name|mii_contype
block|{
name|MII_CONTYPE_UNKNOWN
block|,
comment|/* Must be have value 0. */
name|MII_CONTYPE_MII
block|,
name|MII_CONTYPE_GMII
block|,
name|MII_CONTYPE_SGMII
block|,
name|MII_CONTYPE_QSGMII
block|,
name|MII_CONTYPE_TBI
block|,
name|MII_CONTYPE_REVMII
block|,
comment|/* Reverse MII */
name|MII_CONTYPE_RMII
block|,
name|MII_CONTYPE_RGMII
block|,
comment|/* Delays provided by MAC or PCB */
name|MII_CONTYPE_RGMII_ID
block|,
comment|/* Rx and tx delays provided by PHY */
name|MII_CONTYPE_RGMII_RXID
block|,
comment|/* Only rx delay provided by PHY */
name|MII_CONTYPE_RGMII_TXID
block|,
comment|/* Only tx delay provided by PHY */
name|MII_CONTYPE_RTBI
block|,
name|MII_CONTYPE_SMII
block|,
name|MII_CONTYPE_XGMII
block|,
name|MII_CONTYPE_TRGMII
block|,
name|MII_CONTYPE_2000BX
block|,
name|MII_CONTYPE_2500BX
block|,
name|MII_CONTYPE_RXAUI
block|,
name|MII_CONTYPE_COUNT
comment|/* Add new types before this line. */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|mii_contype
name|mii_contype_t
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|bool
name|mii_contype_is_rgmii
parameter_list|(
name|mii_contype_t
name|con
parameter_list|)
block|{
return|return
operator|(
name|con
operator|>=
name|MII_CONTYPE_RGMII
operator|&&
name|con
operator|<=
name|MII_CONTYPE_RGMII_TXID
operator|)
return|;
block|}
end_function

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
name|u_int
name|mii_phyno
decl_stmt|;
comment|/* MII address */
name|u_int
name|mii_offset
decl_stmt|;
comment|/* first PHY, second PHY, etc. */
name|uint32_t
name|mii_id1
decl_stmt|;
comment|/* PHY ID register 1 */
name|uint32_t
name|mii_id2
decl_stmt|;
comment|/* PHY ID register 2 */
name|u_int
name|mii_capmask
decl_stmt|;
comment|/* capability mask for BMSR */
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

begin_comment
comment|/*  * Used to match a PHY.  */
end_comment

begin_struct
struct|struct
name|mii_phydesc
block|{
name|uint32_t
name|mpd_oui
decl_stmt|;
comment|/* the PHY's OUI */
name|uint32_t
name|mpd_model
decl_stmt|;
comment|/* the PHY's model */
specifier|const
name|char
modifier|*
name|mpd_name
decl_stmt|;
comment|/* the PHY's name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MII_PHY_DESC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ MII_OUI_ ## a, MII_MODEL_ ## a ## _ ## b, \ 	MII_STR_ ## a ## _ ## b }
end_define

begin_define
define|#
directive|define
name|MII_PHY_END
value|{ 0, 0, NULL }
end_define

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

begin_define
define|#
directive|define
name|PHY_SERVICE
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|o
parameter_list|)
define|\
value|(*(p)->mii_funcs->pf_service)((p), (d), (o))
end_define

begin_define
define|#
directive|define
name|PHY_STATUS
parameter_list|(
name|p
parameter_list|)
define|\
value|(*(p)->mii_funcs->pf_status)(p)
end_define

begin_define
define|#
directive|define
name|PHY_RESET
parameter_list|(
name|p
parameter_list|)
define|\
value|(*(p)->mii_funcs->pf_reset)(p)
end_define

begin_enum
enum|enum
name|miibus_device_ivars
block|{
name|MIIBUS_IVAR_FLAGS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for miibus  */
end_comment

begin_define
define|#
directive|define
name|MIIBUS_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(miibus, var, MIIBUS, ivar, type)
end_define

begin_macro
name|MIIBUS_ACCESSOR
argument_list|(
argument|flags
argument_list|,
argument|FLAGS
argument_list|,
argument|u_int
argument_list|)
end_macro

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
name|mii_attach
parameter_list|(
name|device_t
parameter_list|,
name|device_t
modifier|*
parameter_list|,
name|if_t
parameter_list|,
name|ifm_change_cb_t
parameter_list|,
name|ifm_stat_cb_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
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
name|void
name|mii_phy_add_media
parameter_list|(
name|struct
name|mii_softc
modifier|*
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_phy_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|mii_phy_flowstatus
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
name|mii_phy_setmedia
parameter_list|(
name|struct
name|mii_softc
modifier|*
name|sc
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
name|int
name|mii_phy_mac_match
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_dev_mac_match
parameter_list|(
name|device_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mii_phy_mac_softc
parameter_list|(
name|struct
name|mii_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mii_dev_mac_softc
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|mii_phydesc
modifier|*
name|mii_phy_match
parameter_list|(
specifier|const
name|struct
name|mii_attach_args
modifier|*
name|ma
parameter_list|,
specifier|const
name|struct
name|mii_phydesc
modifier|*
name|mpd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|mii_phydesc
modifier|*
name|mii_phy_match_gen
parameter_list|(
specifier|const
name|struct
name|mii_attach_args
modifier|*
name|ma
parameter_list|,
specifier|const
name|struct
name|mii_phydesc
modifier|*
name|mpd
parameter_list|,
name|size_t
name|endlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mii_phy_dev_probe
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|mii_phydesc
modifier|*
name|mpd
parameter_list|,
name|int
name|mrv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_phy_dev_attach
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|flags
parameter_list|,
specifier|const
name|struct
name|mii_phy_funcs
modifier|*
name|mpf
parameter_list|,
name|int
name|add_media
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

begin_function_decl
name|u_int
name|mii_oui
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MII_OUI
parameter_list|(
name|id1
parameter_list|,
name|id2
parameter_list|)
value|mii_oui(id1, id2)
end_define

begin_define
define|#
directive|define
name|MII_MODEL
parameter_list|(
name|id2
parameter_list|)
value|(((id2)& IDR2_MODEL)>> 4)
end_define

begin_define
define|#
directive|define
name|MII_REV
parameter_list|(
name|id2
parameter_list|)
value|((id2)& IDR2_REV)
end_define

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

