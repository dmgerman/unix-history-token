begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1996 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_MIB_H
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_MIB_H
value|1
end_define

begin_struct
struct|struct
name|ifmibdata
block|{
name|char
name|ifmd_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of interface */
name|int
name|ifmd_pcount
decl_stmt|;
comment|/* number of promiscuous listeners */
name|int
name|ifmd_flags
decl_stmt|;
comment|/* interface flags */
name|int
name|ifmd_snd_len
decl_stmt|;
comment|/* instantaneous length of send queue */
name|int
name|ifmd_snd_maxlen
decl_stmt|;
comment|/* maximum length of send queue */
name|int
name|ifmd_snd_drops
decl_stmt|;
comment|/* number of drops in send queue */
name|int
name|ifmd_filler
index|[
literal|4
index|]
decl_stmt|;
comment|/* for future expansion */
name|struct
name|if_data
name|ifmd_data
decl_stmt|;
comment|/* generic information and statistics */
block|}
struct|;
end_struct

begin_comment
comment|/*  * sysctl MIB tags at the net.link.generic level  */
end_comment

begin_define
define|#
directive|define
name|IFMIB_SYSTEM
value|1
end_define

begin_comment
comment|/* non-interface-specific */
end_comment

begin_define
define|#
directive|define
name|IFMIB_IFDATA
value|2
end_define

begin_comment
comment|/* per-interface data table */
end_comment

begin_comment
comment|/*  * MIB tags for the various net.link.generic.ifdata tables  */
end_comment

begin_define
define|#
directive|define
name|IFDATA_GENERAL
value|1
end_define

begin_comment
comment|/* generic stats for all kinds of ifaces */
end_comment

begin_define
define|#
directive|define
name|IFDATA_LINKSPECIFIC
value|2
end_define

begin_comment
comment|/* specific to the type of interface */
end_comment

begin_comment
comment|/*  * MIB tags at the net.link.generic.system level  */
end_comment

begin_define
define|#
directive|define
name|IFMIB_IFCOUNT
value|1
end_define

begin_comment
comment|/* number of interfaces configured */
end_comment

begin_comment
comment|/*  * MIB tags as the net.link level  * All of the other values are IFT_* names defined in if_types.h.  */
end_comment

begin_define
define|#
directive|define
name|NETLINK_GENERIC
value|0
end_define

begin_comment
comment|/* functions not specific to a type of iface */
end_comment

begin_comment
comment|/*  * The reason why the IFDATA_LINKSPECIFIC stuff is not under the  * net.link.<iftype> branches is twofold:  *   1) It's easier to code this way, and doesn't require duplication.  *   2) The fourth level under net.link.<iftype> is<pf>; that is to say,  *	the net.link.<iftype> tree instruments the adaptation layers between  *<iftype> and a particular protocol family (e.g., net.link.ether.inet  *	instruments ARP).  This does not really leave room for anything else  *	that needs to have a well-known number.  */
end_comment

begin_comment
comment|/*  * Link-specific MIB structures for various link types.  */
end_comment

begin_comment
comment|/* For IFT_ETHER, IFT_ISO88023, and IFT_STARLAN, as used by RFC 1650 */
end_comment

begin_struct
struct|struct
name|ifmib_iso_8802_3
block|{
name|u_int32_t
name|dot3StatsAlignmentErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsFCSErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsSingleCollisionFrames
decl_stmt|;
name|u_int32_t
name|dot3StatsMultipleCollisionFrames
decl_stmt|;
name|u_int32_t
name|dot3StatsSQETestErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsDeferredTransmissions
decl_stmt|;
name|u_int32_t
name|dot3StatsLateCollisions
decl_stmt|;
name|u_int32_t
name|dot3StatsExcessiveCollisions
decl_stmt|;
name|u_int32_t
name|dot3StatsInternalMacTransmitErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsCarrierSenseErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsFrameTooLongs
decl_stmt|;
name|u_int32_t
name|dot3StatsInternalMacReceiveErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsEtherChipSet
decl_stmt|;
comment|/* Matt Thomas wants this one, not included in RFC 1650: */
name|u_int32_t
name|dot3StatsMissedFrames
decl_stmt|;
name|u_int32_t
name|dot3StatsCollFrequencies
index|[
literal|16
index|]
decl_stmt|;
comment|/* NB: index origin */
name|u_int32_t
name|dot3Compliance
decl_stmt|;
define|#
directive|define
name|DOT3COMPLIANCE_STATS
value|1
define|#
directive|define
name|DOT3COMPLIANCE_COLLS
value|2
block|}
struct|;
end_struct

begin_comment
comment|/*  * Chipset identifiers are normally part of the vendor's enterprise MIB.  * However, we don't want to be trying to represent arbitrary-length  * OBJECT IDENTIFIERs here (ick!), and the right value is not necessarily  * obvious to the driver implementor.  So, we define our own identification  * mechanism here, and let the agent writer deal with the translation.  */
end_comment

begin_define
define|#
directive|define
name|DOT3CHIPSET_VENDOR
parameter_list|(
name|x
parameter_list|)
value|((x)>> 16)
end_define

begin_define
define|#
directive|define
name|DOT3CHIPSET_PART
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|DOT3CHIPSET
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|(((v)<< 16) + ((p)& 0xffff))
end_define

begin_comment
comment|/* Driver writers!  Add your vendors here! */
end_comment

begin_enum
enum|enum
name|dot3Vendors
block|{
name|dot3VendorAMD
init|=
literal|1
block|,
name|dot3VendorIntel
init|=
literal|2
block|,
name|dot3VendorNational
init|=
literal|4
block|,
name|dot3VendorFujitsu
init|=
literal|5
block|,
name|dot3VendorDigital
init|=
literal|6
block|,
name|dot3VendorWesternDigital
init|=
literal|7
block|}
enum|;
end_enum

begin_comment
comment|/* Driver writers!  Add your chipsets here! */
end_comment

begin_enum
enum|enum
block|{
name|dot3ChipSetAMD7990
init|=
literal|1
block|,
name|dot3ChipSetAMD79900
init|=
literal|2
block|,
name|dot3ChipSetAMD79C940
init|=
literal|3
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|dot3ChipSetIntel82586
init|=
literal|1
block|,
name|dot3ChipSetIntel82596
init|=
literal|2
block|,
name|dot3ChipSetIntel82557
init|=
literal|3
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|dot3ChipSetNational8390
init|=
literal|1
block|,
name|dot3ChipSetNationalSonic
init|=
literal|2
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|dot3ChipSetFujitsu86950
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|dot3ChipSetDigitalDC21040
init|=
literal|1
block|,
name|dot3ChipSetDigitalDC21140
init|=
literal|2
block|,
name|dot3ChipSetDigitalDC21041
init|=
literal|3
block|,
name|dot3ChipSetDigitalDC21140A
init|=
literal|4
block|,
name|dot3ChipSetDigitalDC21142
init|=
literal|5
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|dot3ChipSetWesternDigital83C690
init|=
literal|1
block|,
name|dot3ChipSetWesternDigital83C790
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* END of Ethernet-link MIB stuff */
end_comment

begin_comment
comment|/*  * Put other types of interface MIBs here, or in interface-specific  * header files if convenient ones already exist.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_MIB_H */
end_comment

end_unit

