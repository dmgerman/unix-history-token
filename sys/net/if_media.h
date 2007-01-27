begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_media.h,v 1.3 1997/03/26 01:19:27 thorpej Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997  *	Jonathan Stone and Jason R. Thorpe.  All rights reserved.  *  * This software is derived from information provided by Matt Thomas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jonathan Stone  *	and Jason R. Thorpe for the NetBSD Project.  * 4. The names of the authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
function_decl|(
modifier|*
name|ifm_change_cb_t
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ifm_stat_cb_t
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|ifmediareq
modifier|*
name|req
parameter_list|)
function_decl|;
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

begin_function_decl
name|void
name|ifmedia_init
parameter_list|(
name|struct
name|ifmedia
modifier|*
name|ifm
parameter_list|,
name|int
name|dontcare_mask
parameter_list|,
name|ifm_change_cb_t
name|change_callback
parameter_list|,
name|ifm_stat_cb_t
name|status_callback
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove all mediums from a struct ifmedia.  */
end_comment

begin_function_decl
name|void
name|ifmedia_removeall
parameter_list|(
name|struct
name|ifmedia
modifier|*
name|ifm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add one supported medium to a struct ifmedia. */
end_comment

begin_function_decl
name|void
name|ifmedia_add
parameter_list|(
name|struct
name|ifmedia
modifier|*
name|ifm
parameter_list|,
name|int
name|mword
parameter_list|,
name|int
name|data
parameter_list|,
name|void
modifier|*
name|aux
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|ifmedia_set
parameter_list|(
name|struct
name|ifmedia
modifier|*
name|ifm
parameter_list|,
name|int
name|mword
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Common ioctl function for getting/setting media, called by driver. */
end_comment

begin_function_decl
name|int
name|ifmedia_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|ifreq
modifier|*
name|ifr
parameter_list|,
name|struct
name|ifmedia
modifier|*
name|ifm
parameter_list|,
name|u_long
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute baudrate for a given media. */
end_comment

begin_function_decl
name|uint64_t
name|ifmedia_baudrate
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_KERNEL */
end_comment

begin_comment
comment|/*  * if_media Options word:  *	Bits	Use  *	----	-------  *	0-4	Media variant  *	5-7	Media type  *	8-15	Type specific options  *	16-18	Mode (for multi-mode devices)  *	19	RFU  *	20-27	Shared (global) options  *	28-31	Instance  */
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
name|IFM_1000_SX
value|11
end_define

begin_comment
comment|/* 1000BaseSX - multi-mode fiber */
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
comment|/* 10BaseFL - Fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_1000_LX
value|14
end_define

begin_comment
comment|/* 1000baseLX - single-mode fiber */
end_comment

begin_define
define|#
directive|define
name|IFM_1000_CX
value|15
end_define

begin_comment
comment|/* 1000baseCX - 150ohm STP */
end_comment

begin_define
define|#
directive|define
name|IFM_1000_T
value|16
end_define

begin_comment
comment|/* 1000baseT - 4 pair cat 5 */
end_comment

begin_define
define|#
directive|define
name|IFM_HPNA_1
value|17
end_define

begin_comment
comment|/* HomePNA 1.0 (1Mb/s) */
end_comment

begin_define
define|#
directive|define
name|IFM_10G_LR
value|18
end_define

begin_comment
comment|/* 10GBase-LR 1310nm Single-mode */
end_comment

begin_define
define|#
directive|define
name|IFM_10G_SR
value|19
end_define

begin_comment
comment|/* 10GBase-SR 850nm Multi-mode */
end_comment

begin_define
define|#
directive|define
name|IFM_10G_CX4
value|20
end_define

begin_comment
comment|/* 10GBase CX4 copper */
end_comment

begin_comment
comment|/* note 31 is the max! */
end_comment

begin_define
define|#
directive|define
name|IFM_ETH_MASTER
value|0x00000100
end_define

begin_comment
comment|/* master mode (1000baseT) */
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

begin_comment
comment|/* NB: 0,1,2 are auto, manual, none defined below */
end_comment

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
name|IFM_IEEE80211_OFDM6
value|10
end_define

begin_comment
comment|/* OFDM 6Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM9
value|11
end_define

begin_comment
comment|/* OFDM 9Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM12
value|12
end_define

begin_comment
comment|/* OFDM 12Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM18
value|13
end_define

begin_comment
comment|/* OFDM 18Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM24
value|14
end_define

begin_comment
comment|/* OFDM 24Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM36
value|15
end_define

begin_comment
comment|/* OFDM 36Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM48
value|16
end_define

begin_comment
comment|/* OFDM 48Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM54
value|17
end_define

begin_comment
comment|/* OFDM 54Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM72
value|18
end_define

begin_comment
comment|/* OFDM 72Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_DS354k
value|19
end_define

begin_comment
comment|/* Direct Sequence 354Kbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_DS512k
value|20
end_define

begin_comment
comment|/* Direct Sequence 512Kbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM3
value|21
end_define

begin_comment
comment|/* OFDM 3Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM4
value|22
end_define

begin_comment
comment|/* OFDM 4.5Mbps */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_OFDM27
value|23
end_define

begin_comment
comment|/* OFDM 27Mbps */
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

begin_define
define|#
directive|define
name|IFM_IEEE80211_HOSTAP
value|0x00000200
end_define

begin_comment
comment|/* Operate in Host AP mode */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_IBSS
value|0x00000400
end_define

begin_comment
comment|/* Operate in IBSS mode */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_IBSSMASTER
value|0x00000800
end_define

begin_comment
comment|/* Operate as an IBSS master */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_TURBO
value|0x00001000
end_define

begin_comment
comment|/* Operate in turbo mode */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_MONITOR
value|0x00002000
end_define

begin_comment
comment|/* Operate in monitor mode */
end_comment

begin_comment
comment|/* operating mode for multi-mode devices */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_11A
value|0x00010000
end_define

begin_comment
comment|/* 5Ghz, OFDM mode */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_11B
value|0x00020000
end_define

begin_comment
comment|/* Direct Sequence mode */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_11G
value|0x00030000
end_define

begin_comment
comment|/* 2Ghz, CCK mode */
end_comment

begin_define
define|#
directive|define
name|IFM_IEEE80211_FH
value|0x00040000
end_define

begin_comment
comment|/* 2Ghz, GFSK mode */
end_comment

begin_comment
comment|/*  * ATM  */
end_comment

begin_define
define|#
directive|define
name|IFM_ATM
value|0x000000a0
end_define

begin_define
define|#
directive|define
name|IFM_ATM_UNKNOWN
value|3
end_define

begin_define
define|#
directive|define
name|IFM_ATM_UTP_25
value|4
end_define

begin_define
define|#
directive|define
name|IFM_ATM_TAXI_100
value|5
end_define

begin_define
define|#
directive|define
name|IFM_ATM_TAXI_140
value|6
end_define

begin_define
define|#
directive|define
name|IFM_ATM_MM_155
value|7
end_define

begin_define
define|#
directive|define
name|IFM_ATM_SM_155
value|8
end_define

begin_define
define|#
directive|define
name|IFM_ATM_UTP_155
value|9
end_define

begin_define
define|#
directive|define
name|IFM_ATM_MM_622
value|10
end_define

begin_define
define|#
directive|define
name|IFM_ATM_SM_622
value|11
end_define

begin_define
define|#
directive|define
name|IFM_ATM_VIRTUAL
value|12
end_define

begin_define
define|#
directive|define
name|IFM_ATM_SDH
value|0x00000100
end_define

begin_comment
comment|/* SDH instead of SONET */
end_comment

begin_define
define|#
directive|define
name|IFM_ATM_NOSCRAMB
value|0x00000200
end_define

begin_comment
comment|/* no scrambling */
end_comment

begin_define
define|#
directive|define
name|IFM_ATM_UNASSIGNED
value|0x00000400
end_define

begin_comment
comment|/* unassigned cells */
end_comment

begin_comment
comment|/*  * CARP Common Address Redundancy Protocol  */
end_comment

begin_define
define|#
directive|define
name|IFM_CARP
value|0x000000c0
end_define

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
name|IFM_MMASK
value|0x00070000
end_define

begin_comment
comment|/* Mode */
end_comment

begin_define
define|#
directive|define
name|IFM_MSHIFT
value|16
end_define

begin_comment
comment|/* Mode shift */
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
comment|/* Mask of "status valid" bits, for ifconfig(8). */
end_comment

begin_define
define|#
directive|define
name|IFM_STATUS_VALID
value|IFM_AVALID
end_define

begin_comment
comment|/* List of "status valid" bits, for ifconfig(8). */
end_comment

begin_define
define|#
directive|define
name|IFM_STATUS_VALID_LIST
value|{						\         IFM_AVALID,							\         0								\ }
end_define

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
name|IFM_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)& IFM_MMASK)
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

begin_define
define|#
directive|define
name|IFM_MAKEMODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|(((mode)<< IFM_MSHIFT)& IFM_MMASK)
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
value|{						\ 	{ IFM_ETHER,		"Ethernet" },				\ 	{ IFM_TOKEN,		"Token ring" },				\ 	{ IFM_FDDI,		"FDDI" },				\ 	{ IFM_IEEE80211,	"IEEE 802.11 Wireless Ethernet" },	\ 	{ IFM_ATM,		"ATM" },				\ 	{ IFM_CARP,		"Common Address Redundancy Protocol" }, \ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_ETHERNET_DESCRIPTIONS
value|{				\ 	{ IFM_10_T,	"10baseT/UTP" },				\ 	{ IFM_10_2,	"10base2/BNC" },				\ 	{ IFM_10_5,	"10base5/AUI" },				\ 	{ IFM_100_TX,	"100baseTX" },					\ 	{ IFM_100_FX,	"100baseFX" },					\ 	{ IFM_100_T4,	"100baseT4" },					\ 	{ IFM_100_VG,	"100baseVG" },					\ 	{ IFM_100_T2,	"100baseT2" },					\ 	{ IFM_10_STP,	"10baseSTP" },					\ 	{ IFM_10_FL,	"10baseFL" },					\ 	{ IFM_1000_SX,	"1000baseSX" },					\ 	{ IFM_1000_LX,	"1000baseLX" },					\ 	{ IFM_1000_CX,	"1000baseCX" },					\ 	{ IFM_1000_T,	"1000baseTX" },					\ 	{ IFM_1000_T,	"1000baseT" },					\ 	{ IFM_HPNA_1,	"homePNA" },					\ 	{ IFM_10G_LR,	"10Gbase-LR" },					\ 	{ IFM_10G_SR,	"10Gbase-SR" },					\ 	{ IFM_10G_CX4,	"10Gbase-CX4" },				\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_ETHERNET_ALIASES
value|{					\ 	{ IFM_10_T,	"UTP" },					\ 	{ IFM_10_T,	"10UTP" },					\ 	{ IFM_10_2,	"BNC" },					\ 	{ IFM_10_2,	"10BNC" },					\ 	{ IFM_10_5,	"AUI" },					\ 	{ IFM_10_5,	"10AUI" },					\ 	{ IFM_100_TX,	"100TX" },					\ 	{ IFM_100_T4,	"100T4" },					\ 	{ IFM_100_VG,	"100VG" },					\ 	{ IFM_100_T2,	"100T2" },					\ 	{ IFM_10_STP,	"10STP" },					\ 	{ IFM_10_FL,	"10FL" },					\ 	{ IFM_1000_SX,	"1000SX" },					\ 	{ IFM_1000_LX,	"1000LX" },					\ 	{ IFM_1000_CX,	"1000CX" },					\ 	{ IFM_1000_T,	"1000TX" },					\ 	{ IFM_1000_T,	"1000T" },					\ 	{ 0, NULL },							\ }
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
value|{				\ 	{ IFM_IEEE80211_FH1, "FH/1Mbps" },				\ 	{ IFM_IEEE80211_FH2, "FH/2Mbps" },				\ 	{ IFM_IEEE80211_DS1, "DS/1Mbps" },				\ 	{ IFM_IEEE80211_DS2, "DS/2Mbps" },				\ 	{ IFM_IEEE80211_DS5, "DS/5.5Mbps" },				\ 	{ IFM_IEEE80211_DS11, "DS/11Mbps" },				\ 	{ IFM_IEEE80211_DS22, "DS/22Mbps" },				\ 	{ IFM_IEEE80211_OFDM6, "OFDM/6Mbps" },				\ 	{ IFM_IEEE80211_OFDM9, "OFDM/9Mbps" },				\ 	{ IFM_IEEE80211_OFDM12, "OFDM/12Mbps" },			\ 	{ IFM_IEEE80211_OFDM18, "OFDM/18Mbps" },			\ 	{ IFM_IEEE80211_OFDM24, "OFDM/24Mbps" },			\ 	{ IFM_IEEE80211_OFDM36, "OFDM/36Mbps" },			\ 	{ IFM_IEEE80211_OFDM48, "OFDM/48Mbps" },			\ 	{ IFM_IEEE80211_OFDM54, "OFDM/54Mbps" },			\ 	{ IFM_IEEE80211_OFDM72, "OFDM/72Mbps" },			\ 	{ IFM_IEEE80211_DS354k, "DS/354Kbps" },				\ 	{ IFM_IEEE80211_DS512k, "DS/512Kbps" },				\ 	{ IFM_IEEE80211_OFDM3, "OFDM/3Mbps" },				\ 	{ IFM_IEEE80211_OFDM4, "OFDM/4.5Mbps" },			\ 	{ IFM_IEEE80211_OFDM27, "OFDM/27Mbps" },			\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_IEEE80211_ALIASES
value|{					\ 	{ IFM_IEEE80211_FH1, "FH1" },					\ 	{ IFM_IEEE80211_FH2, "FH2" },					\ 	{ IFM_IEEE80211_FH1, "FrequencyHopping/1Mbps" },		\ 	{ IFM_IEEE80211_FH2, "FrequencyHopping/2Mbps" },		\ 	{ IFM_IEEE80211_DS1, "DS1" },					\ 	{ IFM_IEEE80211_DS2, "DS2" },					\ 	{ IFM_IEEE80211_DS5, "DS5.5" },					\ 	{ IFM_IEEE80211_DS11, "DS11" },					\ 	{ IFM_IEEE80211_DS22, "DS22" },					\ 	{ IFM_IEEE80211_DS1, "DirectSequence/1Mbps" },			\ 	{ IFM_IEEE80211_DS2, "DirectSequence/2Mbps" },			\ 	{ IFM_IEEE80211_DS5, "DirectSequence/5.5Mbps" },		\ 	{ IFM_IEEE80211_DS11, "DirectSequence/11Mbps" },		\ 	{ IFM_IEEE80211_DS22, "DirectSequence/22Mbps" },		\ 	{ IFM_IEEE80211_OFDM6, "OFDM6" },				\ 	{ IFM_IEEE80211_OFDM9, "OFDM9" },				\ 	{ IFM_IEEE80211_OFDM12, "OFDM12" },				\ 	{ IFM_IEEE80211_OFDM18, "OFDM18" },				\ 	{ IFM_IEEE80211_OFDM24, "OFDM24" },				\ 	{ IFM_IEEE80211_OFDM36, "OFDM36" },				\ 	{ IFM_IEEE80211_OFDM48, "OFDM48" },				\ 	{ IFM_IEEE80211_OFDM54, "OFDM54" },				\ 	{ IFM_IEEE80211_OFDM72, "OFDM72" },				\ 	{ IFM_IEEE80211_DS1, "CCK1" },					\ 	{ IFM_IEEE80211_DS2, "CCK2" },					\ 	{ IFM_IEEE80211_DS5, "CCK5.5" },				\ 	{ IFM_IEEE80211_DS11, "CCK11" },				\ 	{ IFM_IEEE80211_DS354k, "DS354K" },				\ 	{ IFM_IEEE80211_DS354k, "DirectSequence/354Kbps" },		\ 	{ IFM_IEEE80211_DS512k, "DS512K" },				\ 	{ IFM_IEEE80211_DS512k, "DirectSequence/512Kbps" },		\ 	{ IFM_IEEE80211_OFDM3, "OFDM3" },				\ 	{ IFM_IEEE80211_OFDM4, "OFDM4.5" },				\ 	{ IFM_IEEE80211_OFDM27, "OFDM27" },				\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_IEEE80211_OPTION_DESCRIPTIONS
value|{			\ 	{ IFM_IEEE80211_ADHOC, "adhoc" },				\ 	{ IFM_IEEE80211_HOSTAP, "hostap" },				\ 	{ IFM_IEEE80211_IBSS, "ibss" },					\ 	{ IFM_IEEE80211_IBSSMASTER, "ibss-master" },			\ 	{ IFM_IEEE80211_TURBO, "turbo" },				\ 	{ IFM_IEEE80211_MONITOR, "monitor" },				\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_IEEE80211_MODE_DESCRIPTIONS
value|{			\ 	{ IFM_AUTO, "autoselect" },					\ 	{ IFM_IEEE80211_11A, "11a" },					\ 	{ IFM_IEEE80211_11B, "11b" },					\ 	{ IFM_IEEE80211_11G, "11g" },					\ 	{ IFM_IEEE80211_FH, "fh" },					\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_IEEE80211_MODE_ALIASES
value|{				\ 	{ IFM_AUTO, "auto" },						\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_ATM_DESCRIPTIONS
value|{					\ 	{ IFM_ATM_UNKNOWN,	"Unknown" },				\ 	{ IFM_ATM_UTP_25,	"UTP/25.6MBit" },			\ 	{ IFM_ATM_TAXI_100,	"Taxi/100MBit" },			\ 	{ IFM_ATM_TAXI_140,	"Taxi/140MBit" },			\ 	{ IFM_ATM_MM_155,	"Multi-mode/155MBit" },			\ 	{ IFM_ATM_SM_155,	"Single-mode/155MBit" },		\ 	{ IFM_ATM_UTP_155,	"UTP/155MBit" },			\ 	{ IFM_ATM_MM_622,	"Multi-mode/622MBit" },			\ 	{ IFM_ATM_SM_622,	"Single-mode/622MBit" },		\ 	{ IFM_ATM_VIRTUAL,	"Virtual" },				\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_ATM_ALIASES
value|{					\ 	{ IFM_ATM_UNKNOWN,	"UNKNOWN" },				\ 	{ IFM_ATM_UTP_25,	"UTP-25" },				\ 	{ IFM_ATM_TAXI_100,	"TAXI-100" },				\ 	{ IFM_ATM_TAXI_140,	"TAXI-140" },				\ 	{ IFM_ATM_MM_155,	"MM-155" },				\ 	{ IFM_ATM_SM_155,	"SM-155" },				\ 	{ IFM_ATM_UTP_155,	"UTP-155" },				\ 	{ IFM_ATM_MM_622,	"MM-622" },				\ 	{ IFM_ATM_SM_622,	"SM-622" },				\ 	{ IFM_ATM_VIRTUAL,	"VIRTUAL" },				\ 	{ 0, NULL },							\ }
end_define

begin_define
define|#
directive|define
name|IFM_SUBTYPE_ATM_OPTION_DESCRIPTIONS
value|{				\ 	{ IFM_ATM_SDH, "SDH" },						\ 	{ IFM_ATM_NOSCRAMB, "Noscramb" },				\ 	{ IFM_ATM_UNASSIGNED, "Unassigned" },				\ 	{ 0, NULL },							\ }
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

begin_comment
comment|/*  * Baudrate descriptions for the various media types.  */
end_comment

begin_struct
struct|struct
name|ifmedia_baudrate
block|{
name|int
name|ifmb_word
decl_stmt|;
comment|/* media word */
name|uint64_t
name|ifmb_baudrate
decl_stmt|;
comment|/* corresponding baudrate */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFM_BAUDRATE_DESCRIPTIONS
value|{					\ 	{ IFM_ETHER | IFM_10_T,		IF_Mbps(10) },			\ 	{ IFM_ETHER | IFM_10_2,		IF_Mbps(10) },			\ 	{ IFM_ETHER | IFM_10_5,		IF_Mbps(10) },			\ 	{ IFM_ETHER | IFM_100_TX,	IF_Mbps(100) },			\ 	{ IFM_ETHER | IFM_100_FX,	IF_Mbps(100) },			\ 	{ IFM_ETHER | IFM_100_T4,	IF_Mbps(100) },			\ 	{ IFM_ETHER | IFM_100_VG,	IF_Mbps(100) },			\ 	{ IFM_ETHER | IFM_100_T2,	IF_Mbps(100) },			\ 	{ IFM_ETHER | IFM_1000_SX,	IF_Mbps(1000) },		\ 	{ IFM_ETHER | IFM_10_STP,	IF_Mbps(10) },			\ 	{ IFM_ETHER | IFM_10_FL,	IF_Mbps(10) },			\ 	{ IFM_ETHER | IFM_1000_LX,	IF_Mbps(1000) },		\ 	{ IFM_ETHER | IFM_1000_CX,	IF_Mbps(1000) },		\ 	{ IFM_ETHER | IFM_1000_T,	IF_Mbps(1000) },		\ 	{ IFM_ETHER | IFM_HPNA_1,	IF_Mbps(1) },			\ 	{ IFM_ETHER | IFM_10G_LR,	IF_Gbps(10ULL) },		\ 	{ IFM_ETHER | IFM_10G_SR,	IF_Gbps(10ULL) },		\ 	{ IFM_ETHER | IFM_10G_CX4,	IF_Gbps(10ULL) },		\ 									\ 	{ IFM_TOKEN | IFM_TOK_STP4,	IF_Mbps(4) },			\ 	{ IFM_TOKEN | IFM_TOK_STP16,	IF_Mbps(16) },			\ 	{ IFM_TOKEN | IFM_TOK_UTP4,	IF_Mbps(4) },			\ 	{ IFM_TOKEN | IFM_TOK_UTP16,	IF_Mbps(16) },			\ 									\ 	{ IFM_FDDI | IFM_FDDI_SMF,	IF_Mbps(100) },			\ 	{ IFM_FDDI | IFM_FDDI_MMF,	IF_Mbps(100) },			\ 	{ IFM_FDDI | IFM_FDDI_UTP,	IF_Mbps(100) },			\ 									\ 	{ IFM_IEEE80211 | IFM_IEEE80211_FH1,	IF_Mbps(1) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_FH2,	IF_Mbps(2) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_DS2,	IF_Mbps(2) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_DS5,	IF_Kbps(5500) },	\ 	{ IFM_IEEE80211 | IFM_IEEE80211_DS11,	IF_Mbps(11) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_DS1,	IF_Mbps(1) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_DS22,	IF_Mbps(22) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM6,	IF_Mbps(6) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM9,	IF_Mbps(9) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM12,	IF_Mbps(12) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM18,	IF_Mbps(18) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM24,	IF_Mbps(24) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM36,	IF_Mbps(36) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM48,	IF_Mbps(48) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM54,	IF_Mbps(54) },		\ 	{ IFM_IEEE80211 | IFM_IEEE80211_OFDM72,	IF_Mbps(72) },		\ 									\ 	{ 0, 0 },							\ }
end_define

begin_comment
comment|/*  * Status descriptions for the various media types.  */
end_comment

begin_struct
struct|struct
name|ifmedia_status_description
block|{
name|int
name|ifms_type
decl_stmt|;
name|int
name|ifms_valid
decl_stmt|;
name|int
name|ifms_bit
decl_stmt|;
specifier|const
name|char
modifier|*
name|ifms_string
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFM_STATUS_DESC
parameter_list|(
name|ifms
parameter_list|,
name|bit
parameter_list|)
define|\
value|(ifms)->ifms_string[((ifms)->ifms_bit& (bit)) ? 1 : 0]
end_define

begin_define
define|#
directive|define
name|IFM_STATUS_DESCRIPTIONS
value|{					\ 	{ IFM_ETHER,		IFM_AVALID,	IFM_ACTIVE,		\ 	    { "no carrier", "active" } },				\ 	{ IFM_FDDI,		IFM_AVALID,	IFM_ACTIVE,		\ 	    { "no ring", "inserted" } },				\ 	{ IFM_TOKEN,		IFM_AVALID,	IFM_ACTIVE,		\ 	    { "no ring", "inserted" } },				\ 	{ IFM_IEEE80211,	IFM_AVALID,	IFM_ACTIVE,		\ 	    { "no network", "active" } },				\ 	{ IFM_ATM,		IFM_AVALID,	IFM_ACTIVE,		\ 	    { "no network", "active" } },				\ 	{ IFM_CARP,		IFM_AVALID,	IFM_ACTIVE,		\ 	    { "backup", "master" } },					\ 	{ 0,			0,		0,			\ 	    { NULL, NULL } }						\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_MEDIA_H_ */
end_comment

end_unit

