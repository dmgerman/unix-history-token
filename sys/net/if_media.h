begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_media.h,v 1.3 1997/03/26 01:19:27 thorpej Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997  *	Jonathan Stone and Jason R. Thorpe.  All rights reserved.  *  * This software is derived from information provided by Matt Thomas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jonathan Stone  *	and Jason R. Thorpe for the NetBSD Project.  * 4. The names of the authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_MEDIA_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_MEDIA_H_
end_define

begin_comment
comment|/*  * Prototypes and definitions for BSD/OS-compatible network interface  * media selection.  *  * Where it is safe to do so, this code strays slightly from the BSD/OS  * design.  Software which uses the API (device drivers, basically)  * shouldn't notice any difference.  *  * Many thanks to Matt Thomas for providing the information necessary  * to implement this interface.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Driver callbacks for media status and change requests.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*ifm_change_cb_t
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
name|ifp
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*ifm_stat_cb_t
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
expr|struct
name|ifmediareq
operator|*
name|req
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/*  * In-kernel representation of a single supported media type.  */
end_comment

begin_struct
struct|struct
name|ifmedia_entry
block|{
name|LIST_ENTRY
argument_list|(
argument|ifmedia_entry
argument_list|)
name|ifm_list
expr_stmt|;
name|int
name|ifm_media
decl_stmt|;
comment|/* description of this media attachment */
name|int
name|ifm_data
decl_stmt|;
comment|/* for driver-specific use */
name|void
modifier|*
name|ifm_aux
decl_stmt|;
comment|/* for driver-specific use */
block|}
struct|;
end_struct

begin_comment
comment|/*  * One of these goes into a network interface's softc structure.  * It is used to keep general media state.  */
end_comment

begin_struct
struct|struct
name|ifmedia
block|{
name|int
name|ifm_mask
decl_stmt|;
comment|/* mask of changes we don't care about */
name|int
name|ifm_media
decl_stmt|;
comment|/* current user-set media word */
name|struct
name|ifmedia_entry
modifier|*
name|ifm_cur
decl_stmt|;
comment|/* currently selected media */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ifmedia_entry
argument_list|)
name|ifm_list
expr_stmt|;
comment|/* list of all supported media */
name|ifm_change_cb_t
name|ifm_change
decl_stmt|;
comment|/* media change driver callback */
name|ifm_stat_cb_t
name|ifm_status
decl_stmt|;
comment|/* media status driver callback */
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize an interface's struct if_media field. */
end_comment

begin_decl_stmt
name|void
name|ifmedia_init
name|__P
argument_list|(
operator|(
expr|struct
name|ifmedia
operator|*
name|ifm
operator|,
name|int
name|dontcare_mask
operator|,
name|ifm_change_cb_t
name|change_callback
operator|,
name|ifm_stat_cb_t
name|status_callback
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove all mediums from a struct ifmedia.  */
end_comment

begin_decl_stmt
name|void
name|ifmedia_removeall
name|__P
argument_list|(
operator|(
expr|struct
name|ifmedia
operator|*
name|ifm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add one supported medium to a struct ifmedia. */
end_comment

begin_decl_stmt
name|void
name|ifmedia_add
name|__P
argument_list|(
operator|(
expr|struct
name|ifmedia
operator|*
name|ifm
operator|,
name|int
name|mword
operator|,
name|int
name|data
operator|,
name|void
operator|*
name|aux
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add an array (of ifmedia_entry) media to a struct ifmedia. */
end_comment

begin_function_decl
name|void
name|ifmedia_list_add
parameter_list|(
name|struct
name|ifmedia
modifier|*
name|mp
parameter_list|,
name|struct
name|ifmedia_entry
modifier|*
name|lp
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set default media type on initialization. */
end_comment

begin_decl_stmt
name|void
name|ifmedia_set
name|__P
argument_list|(
operator|(
expr|struct
name|ifmedia
operator|*
name|ifm
operator|,
name|int
name|mword
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Common ioctl function for getting/setting media, called by driver. */
end_comment

begin_decl_stmt
name|int
name|ifmedia_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
expr|struct
name|ifreq
operator|*
name|ifr
operator|,
expr|struct
name|ifmedia
operator|*
name|ifm
operator|,
name|u_long
name|cmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_KERNEL */
end_comment

begin_comment
comment|/*  * if_media Options word:  *	Bits	Use  *	----	-------  *	0-4	Media variant  *	5-7	Media type  *	8-15	Type specific options  *	16-19	RFU  *	20-27	Shared (global) options  *	28-31	Instance  */
end_comment

begin_comment
comment|/*  * Ethernet  */
end_comment

begin_define
define|#
directive|define
name|IFM_ETHER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IFM_10_T
value|3
end_define

begin_comment
comment|/* 10BaseT - RJ45 */
end_comment

begin_define
define|#
directive|define
name|IFM_10_2
value|4
end_define

begin_comment
comment|/* 10Base2 - Thinnet */
end_comment

begin_define
define|#
directive|define
name|IFM_10_5
value|5
end_define

begin_comment
comment|/* 10Base5 - AUI */
end_comment

begin_define
define|#
directive|define
name|IFM_100_TX
value|6
end_define

begin_comment
comment|/* 100BaseTX - RJ45 */
end_comment

begin_define
define|#
directive|define
name|IFM_100_FX
value|7
end_define

begin_comment
comment|/* 100BaseFX - Fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_100_T4
value|8
end_define

begin_comment
comment|/* 100BaseT4 - 4 pair cat 3 */
end_comment

begin_define
define|#
directive|define
name|IFM_100_VG
value|9
end_define

begin_comment
comment|/* 100VG-AnyLAN */
end_comment

begin_define
define|#
directive|define
name|IFM_100_T2
value|10
end_define

begin_comment
comment|/* 100BaseT2 */
end_comment

begin_define
define|#
directive|define
name|IFM_1000_FX
value|11
end_define

begin_comment
comment|/* 1000BaseFX - gigabit over fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_10_STP
value|12
end_define

begin_comment
comment|/* 10BaseT over shielded TP */
end_comment

begin_define
define|#
directive|define
name|IFM_10_FL
value|13
end_define

begin_comment
comment|/* 10baseFL - Fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_1000_SX
value|14
end_define

begin_comment
comment|/* 1000BaseSX Multi-mode Fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_1000_LX
value|15
end_define

begin_comment
comment|/* 1000BaseLX Single-mode Fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_1000_CX
value|16
end_define

begin_comment
comment|/* 1000BaseCX 150ohm STP */
end_comment

begin_define
define|#
directive|define
name|IFM_1000_TX
value|17
end_define

begin_comment
comment|/* 1000BaseTX 4 pair cat 5 */
end_comment

begin_define
define|#
directive|define
name|IFM_homePNA
value|18
end_define

begin_comment
comment|/* HomePNA media for ethernet frames */
end_comment

begin_comment
comment|/* note 31 is the max! */
end_comment

begin_comment
comment|/*  * Token ring  */
end_comment

begin_define
define|#
directive|define
name|IFM_TOKEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IFM_TOK_STP4
value|3
end_define

begin_comment
comment|/* Shielded twisted pair 4m - DB9 */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_STP16
value|4
end_define

begin_comment
comment|/* Shielded twisted pair 16m - DB9 */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_UTP4
value|5
end_define

begin_comment
comment|/* Unshielded twisted pair 4m - RJ45 */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_UTP16
value|6
end_define

begin_comment
comment|/* Unshielded twisted pair 16m - RJ45 */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_STP100
value|7
end_define

begin_comment
comment|/* Shielded twisted pair 100m - DB9 */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_UTP100
value|8
end_define

begin_comment
comment|/* Unshielded twisted pair 100m - RJ45 */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_ETR
value|0x00000200
end_define

begin_comment
comment|/* Early token release */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_SRCRT
value|0x00000400
end_define

begin_comment
comment|/* Enable source routing features */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_ALLR
value|0x00000800
end_define

begin_comment
comment|/* All routes / Single route bcast */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_DTR
value|0x00002000
end_define

begin_comment
comment|/* Dedicated token ring */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_CLASSIC
value|0x00004000
end_define

begin_comment
comment|/* Classic token ring */
end_comment

begin_define
define|#
directive|define
name|IFM_TOK_AUTO
value|0x00008000
end_define

begin_comment
comment|/* Automatic Dedicate/Classic token ring */
end_comment

begin_comment
comment|/*  * FDDI  */
end_comment

begin_define
define|#
directive|define
name|IFM_FDDI
value|0x00000060
end_define

begin_define
define|#
directive|define
name|IFM_FDDI_SMF
value|3
end_define

begin_comment
comment|/* Single-mode fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_FDDI_MMF
value|4
end_define

begin_comment
comment|/* Multi-mode fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_FDDI_UTP
value|5
end_define

begin_comment
comment|/* CDDI / UTP */
end_comment

begin_define
define|#
directive|define
name|IFM_FDDI_DA
value|0x00000100
end_define

begin_comment
comment|/* Dual attach / single attach */
end_comment

begin_comment
comment|/*  * IEEE 802.11 Wireless  */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IFM_IEEE80211_FH1
value|3
end_define

begin_comment
comment|/* Frequency Hopping 1Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_FH2
value|4
end_define

begin_comment
comment|/* Frequency Hopping 2Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_DS1
value|5
end_define

begin_comment
comment|/* Direct Sequence 1Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_DS2
value|6
end_define

begin_comment
comment|/* Direct Sequence 2Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_DS5
value|7
end_define

begin_comment
comment|/* Direct Sequence 5.5Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_DS11
value|8
end_define

begin_comment
comment|/* Direct Sequence 11Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_DS22
value|9
end_define

begin_comment
comment|/* Direct Sequence 22Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_ADHOC
value|0x00000100
end_define

begin_comment
comment|/* Operate in Adhoc mode */
end_comment

begin_comment
comment|/*  * Shared media sub-types  */
end_comment

begin_define
define|#
directive|define
name|IFM_AUTO
value|0
end_define

begin_comment
comment|/* Autoselect best media */
end_comment

begin_define
define|#
directive|define
name|IFM_MANUAL
value|1
end_define

begin_comment
comment|/* Jumper/dipswitch selects media */
end_comment

begin_define
define|#
directive|define
name|IFM_NONE
value|2
end_define

begin_comment
comment|/* Deselect all media */
end_comment

begin_comment
comment|/*  * Shared options  */
end_comment

begin_define
define|#
directive|define
name|IFM_FDX
value|0x00100000
end_define

begin_comment
comment|/* Force full duplex */
end_comment

begin_define
define|#
directive|define
name|IFM_HDX
value|0x00200000
end_define

begin_comment
comment|/* Force half duplex */
end_comment

begin_define
define|#
directive|define
name|IFM_FLAG0
value|0x01000000
end_define

begin_comment
comment|/* Driver defined flag */
end_comment

begin_define
define|#
directive|define
name|IFM_FLAG1
value|0x02000000
end_define

begin_comment
comment|/* Driver defined flag */
end_comment

begin_define
define|#
directive|define
name|IFM_FLAG2
value|0x04000000
end_define

begin_comment
comment|/* Driver defined flag */
end_comment

begin_define
define|#
directive|define
name|IFM_LOOP
value|0x08000000
end_define

begin_comment
comment|/* Put hardware in loopback */
end_comment

begin_comment
comment|/*  * Masks  */
end_comment

begin_define
define|#
directive|define
name|IFM_NMASK
value|0x000000e0
end_define

begin_comment
comment|/* Network type */
end_comment

begin_define
define|#
directive|define
name|IFM_TMASK
value|0x0000001f
end_define

begin_comment
comment|/* Media sub-type */
end_comment

begin_define
define|#
directive|define
name|IFM_IMASK
value|0xf0000000
end_define

begin_comment
comment|/* Instance */
end_comment

begin_define
define|#
directive|define
name|IFM_ISHIFT
value|28
end_define

begin_comment
comment|/* Instance shift */
end_comment

begin_define
define|#
directive|define
name|IFM_OMASK
value|0x0000ff00
end_define

begin_comment
comment|/* Type specific options */
end_comment

begin_define
define|#
directive|define
name|IFM_GMASK
value|0x0ff00000
end_define

begin_comment
comment|/* Global options */
end_comment

begin_comment
comment|/*  * Status bits  */
end_comment

begin_define
define|#
directive|define
name|IFM_AVALID
value|0x00000001
end_define

begin_comment
comment|/* Active bit valid */
end_comment

begin_define
define|#
directive|define
name|IFM_ACTIVE
value|0x00000002
end_define

begin_comment
comment|/* Interface attached to working net */
end_comment

begin_comment
comment|/*  * Macros to extract various bits of information from the media word.  */
end_comment

begin_define
define|#
directive|define
name|IFM_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& IFM_NMASK)
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& IFM_TMASK)
end_define

begin_define
define|#
directive|define
name|IFM_TYPE_OPTIONS
parameter_list|(
name|x
parameter_list|)
value|((x)& IFM_OMASK)
end_define

begin_define
define|#
directive|define
name|IFM_INST
parameter_list|(
name|x
parameter_list|)
value|(((x)& IFM_IMASK)>> IFM_ISHIFT)
end_define

begin_define
define|#
directive|define
name|IFM_OPTIONS
parameter_list|(
name|x
parameter_list|)
value|((x)& (IFM_OMASK|IFM_GMASK))
end_define

begin_define
define|#
directive|define
name|IFM_INST_MAX
value|IFM_INST(IFM_IMASK)
end_define

begin_comment
comment|/*  * Macro to create a media word.  */
end_comment

begin_define
define|#
directive|define
name|IFM_MAKEWORD
parameter_list|(
name|type
parameter_list|,
name|subtype
parameter_list|,
name|options
parameter_list|,
name|instance
parameter_list|)
define|\
value|((type) | (subtype) | (options) | ((instance)<< IFM_ISHIFT))
end_define

begin_comment
comment|/*  * NetBSD extension not defined in the BSDI API.  This is used in various  * places to get the canonical description for a given type/subtype.  *  * NOTE: all but the top-level type descriptions must contain NO whitespace!  * Otherwise, parsing these in ifconfig(8) would be a nightmare.  */
end_comment

begin_struct
struct|struct
name|ifmedia_description
block|{
name|int
name|ifmt_word
decl_stmt|;
comment|/* word value; may be masked */
specifier|const
name|char
modifier|*
name|ifmt_string
decl_stmt|;
comment|/* description */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFM_TYPE_DESCRIPTIONS
value|{						\ 	{ IFM_ETHER,		"Ethernet" },				\ 	{ IFM_TOKEN,		"Token ring" },				\ 	{ IFM_FDDI,		"FDDI" },				\ 	{ IFM_IEEE80211,	"IEEE 802.11 Wireless Ethernet" },	\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_ETHERNET_DESCRIPTIONS
value|{				\ 	{ IFM_10_T,	"10baseT/UTP" },				\ 	{ IFM_10_2,	"10base2/BNC" },				\ 	{ IFM_10_5,	"10base5/AUI" },				\ 	{ IFM_100_TX,	"100baseTX" },					\ 	{ IFM_100_FX,	"100baseFX" },					\ 	{ IFM_100_T4,	"100baseT4" },					\ 	{ IFM_100_VG,	"100baseVG" },					\ 	{ IFM_100_T2,	"100baseT2" },					\ 	{ IFM_1000_FX,	"1000baseFX" },					\ 	{ IFM_10_STP,	"10baseSTP" },					\ 	{ IFM_10_FL,	"10baseFL" },					\ 	{ IFM_1000_SX,	"1000baseSX" },					\ 	{ IFM_1000_LX,	"1000baseLX" },					\ 	{ IFM_1000_CX,	"1000baseCX" },					\ 	{ IFM_1000_TX,	"1000baseTX" },					\ 	{ IFM_homePNA,	"homePNA" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_ETHERNET_ALIASES
value|{					\ 	{ IFM_10_T,	"UTP" },					\ 	{ IFM_10_T,	"10UTP" },					\ 	{ IFM_10_2,	"BNC" },					\ 	{ IFM_10_2,	"10BNC" },					\ 	{ IFM_10_5,	"AUI" },					\ 	{ IFM_10_5,	"10AUI" },					\ 	{ IFM_100_TX,	"100TX" },					\ 	{ IFM_100_FX,	"100FX" },					\ 	{ IFM_100_T4,	"100T4" },					\ 	{ IFM_100_VG,	"100VG" },					\ 	{ IFM_100_T2,	"100T2" },					\ 	{ IFM_1000_FX,	"1000FX" },					\ 	{ IFM_10_STP,	"10STP" },					\ 	{ IFM_10_FL,	"10FL" },					\ 	{ IFM_1000_FX,	"1000SX" },					\ 	{ IFM_1000_FX,	"1000LX" },					\ 	{ IFM_1000_FX,	"1000CX" },					\ 	{ IFM_1000_FX,	"1000TX" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_ETHERNET_OPTION_DESCRIPTIONS
value|{			\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_TOKENRING_DESCRIPTIONS
value|{				\ 	{ IFM_TOK_STP4,	"DB9/4Mbit" },					\ 	{ IFM_TOK_STP16, "DB9/16Mbit" },				\ 	{ IFM_TOK_UTP4,	"UTP/4Mbit" },					\ 	{ IFM_TOK_UTP16, "UTP/16Mbit" },				\ 	{ IFM_TOK_STP100, "STP/100Mbit" },				\ 	{ IFM_TOK_UTP100, "UTP/100Mbit" },				\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_TOKENRING_ALIASES
value|{					\ 	{ IFM_TOK_STP4,	"4STP" },					\ 	{ IFM_TOK_STP16, "16STP" },					\ 	{ IFM_TOK_UTP4,	"4UTP" },					\ 	{ IFM_TOK_UTP16, "16UTP" },					\ 	{ IFM_TOK_STP100, "100STP" },					\ 	{ IFM_TOK_UTP100, "100UTP" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_TOKENRING_OPTION_DESCRIPTIONS
value|{			\ 	{ IFM_TOK_ETR,	"EarlyTokenRelease" },				\ 	{ IFM_TOK_SRCRT, "SourceRouting" },				\ 	{ IFM_TOK_ALLR,	"AllRoutes" },					\ 	{ IFM_TOK_DTR,	"Dedicated" },					\ 	{ IFM_TOK_CLASSIC,"Classic" },					\ 	{ IFM_TOK_AUTO,	" " },						\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_FDDI_DESCRIPTIONS
value|{					\ 	{ IFM_FDDI_SMF, "Single-mode" },				\ 	{ IFM_FDDI_MMF, "Multi-mode" },					\ 	{ IFM_FDDI_UTP, "UTP" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_FDDI_ALIASES
value|{					\ 	{ IFM_FDDI_SMF,	"SMF" },					\ 	{ IFM_FDDI_MMF,	"MMF" },					\ 	{ IFM_FDDI_UTP,	"CDDI" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_FDDI_OPTION_DESCRIPTIONS
value|{				\ 	{ IFM_FDDI_DA, "Dual-attach" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_IEEE80211_DESCRIPTIONS
value|{				\ 	{ IFM_IEEE80211_FH1, "FH/1Mbps" },				\ 	{ IFM_IEEE80211_FH2, "FH/2Mbps" },				\ 	{ IFM_IEEE80211_DS1, "DS/1Mbps" },				\ 	{ IFM_IEEE80211_DS2, "DS/2Mbps" },				\ 	{ IFM_IEEE80211_DS5, "DS/5.5Mbps" },				\ 	{ IFM_IEEE80211_DS11, "DS/11Mbps" },				\ 	{ IFM_IEEE80211_DS22, "DS/22Mbps" },				\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_IEEE80211_ALIASES
value|{					\ 	{ IFM_IEEE80211_FH1, "FH1" },					\ 	{ IFM_IEEE80211_FH2, "FH2" },					\ 	{ IFM_IEEE80211_FH1, "FrequencyHopping/1Mbps" },		\ 	{ IFM_IEEE80211_FH2, "FrequencyHopping/2Mbps" },		\ 	{ IFM_IEEE80211_DS1, "DS1" },					\ 	{ IFM_IEEE80211_DS2, "DS2" },					\ 	{ IFM_IEEE80211_DS5, "DS5.5" },					\ 	{ IFM_IEEE80211_DS11, "DS11" },					\ 	{ IFM_IEEE80211_DS22, "DS22" },					\ 	{ IFM_IEEE80211_DS1, "DirectSequence/1Mbps" },			\ 	{ IFM_IEEE80211_DS2, "DirectSequence/2Mbps" },			\ 	{ IFM_IEEE80211_DS5, "DirectSequence/5.5Mbps" },		\ 	{ IFM_IEEE80211_DS11, "DirectSequence/11Mbps" },		\ 	{ IFM_IEEE80211_DS22, "DirectSequence/22Mbps" },		\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_IEEE80211_OPTION_DESCRIPTIONS
value|{			\ 	{ IFM_IEEE80211_ADHOC, "adhoc" },				\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_SHARED_DESCRIPTIONS
value|{				\ 	{ IFM_AUTO,	"autoselect" },					\ 	{ IFM_MANUAL,	"manual" },					\ 	{ IFM_NONE,	"none" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_SHARED_ALIASES
value|{					\ 	{ IFM_AUTO,	"auto" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SHARED_OPTION_DESCRIPTIONS
value|{				\ 	{ IFM_FDX,	"full-duplex" },				\ 	{ IFM_HDX,	"half-duplex" },				\ 	{ IFM_FLAG0,	"flag0" },					\ 	{ IFM_FLAG1,	"flag1" },					\ 	{ IFM_FLAG2,	"flag2" },					\ 	{ IFM_LOOP,	"hw-loopback" },				\ 	{ 0, NULL },							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_MEDIA_H_ */
end_comment

end_unit

