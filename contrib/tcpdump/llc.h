begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/llc.h,v 1.16 2002/12/11 07:13:54 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * This stuff should come from a system header file, but there's no  * obviously portable way to do that and it's not really going  * to change from system to system.  */
end_comment

begin_comment
comment|/*  * A somewhat abstracted view of the LLC header  */
end_comment

begin_struct
struct|struct
name|llc
block|{
name|u_int8_t
name|dsap
decl_stmt|;
name|u_int8_t
name|ssap
decl_stmt|;
union|union
block|{
name|u_int8_t
name|u_ctl
decl_stmt|;
name|u_int16_t
name|is_ctl
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|snap_ui
decl_stmt|;
name|u_int8_t
name|snap_pi
index|[
literal|5
index|]
decl_stmt|;
block|}
name|snap
struct|;
struct|struct
block|{
name|u_int8_t
name|snap_ui
decl_stmt|;
name|u_int8_t
name|snap_orgcode
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|snap_ethertype
index|[
literal|2
index|]
decl_stmt|;
block|}
name|snap_ether
struct|;
block|}
name|ctl
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|llcui
value|ctl.snap.snap_ui
end_define

begin_define
define|#
directive|define
name|llcpi
value|ctl.snap.snap_pi
end_define

begin_define
define|#
directive|define
name|llc_orgcode
value|ctl.snap_ether.snap_orgcode
end_define

begin_define
define|#
directive|define
name|llc_ethertype
value|ctl.snap_ether.snap_ethertype
end_define

begin_define
define|#
directive|define
name|llcis
value|ctl.is_ctl
end_define

begin_define
define|#
directive|define
name|llcu
value|ctl.u_ctl
end_define

begin_define
define|#
directive|define
name|LLC_U_FMT
value|3
end_define

begin_define
define|#
directive|define
name|LLC_GSAP
value|1
end_define

begin_define
define|#
directive|define
name|LLC_S_FMT
value|1
end_define

begin_define
define|#
directive|define
name|LLC_U_POLL
value|0x10
end_define

begin_define
define|#
directive|define
name|LLC_IS_POLL
value|0x0100
end_define

begin_define
define|#
directive|define
name|LLC_XID_FI
value|0x81
end_define

begin_define
define|#
directive|define
name|LLC_U_CMD
parameter_list|(
name|u
parameter_list|)
value|((u)& 0xef)
end_define

begin_define
define|#
directive|define
name|LLC_UI
value|0x03
end_define

begin_define
define|#
directive|define
name|LLC_UA
value|0x63
end_define

begin_define
define|#
directive|define
name|LLC_DISC
value|0x43
end_define

begin_define
define|#
directive|define
name|LLC_DM
value|0x0f
end_define

begin_define
define|#
directive|define
name|LLC_SABME
value|0x6f
end_define

begin_define
define|#
directive|define
name|LLC_TEST
value|0xe3
end_define

begin_define
define|#
directive|define
name|LLC_XID
value|0xaf
end_define

begin_define
define|#
directive|define
name|LLC_FRMR
value|0x87
end_define

begin_define
define|#
directive|define
name|LLC_S_CMD
parameter_list|(
name|is
parameter_list|)
value|(((is)>> 1)& 0x03)
end_define

begin_define
define|#
directive|define
name|LLC_RR
value|0x0001
end_define

begin_define
define|#
directive|define
name|LLC_RNR
value|0x0005
end_define

begin_define
define|#
directive|define
name|LLC_REJ
value|0x0009
end_define

begin_define
define|#
directive|define
name|LLC_IS_NR
parameter_list|(
name|is
parameter_list|)
value|(((is)>> 9)& 0x7f)
end_define

begin_define
define|#
directive|define
name|LLC_I_NS
parameter_list|(
name|is
parameter_list|)
value|(((is)>> 1)& 0x7f)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_NULL
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_NULL
value|0x00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_GLOBAL
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_8021B_I
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_8021B_I
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_8021B_G
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_8021B_G
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_IP
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_IP
value|0x06
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_PROWAYNM
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_PROWAYNM
value|0x0e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_8021D
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_8021D
value|0x42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_RS511
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_RS511
value|0x4e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_ISO8208
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_ISO8208
value|0x7e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_PROWAY
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_PROWAY
value|0x8e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_SNAP
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_SNAP
value|0xaa
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_IPX
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_IPX
value|0xe0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_NETBEUI
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_NETBEUI
value|0xf0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_ISONS
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_ISONS
value|0xfe
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OUI_ENCAP_ETHER
value|0x000000
end_define

begin_comment
comment|/* encapsulated Ethernet */
end_comment

begin_define
define|#
directive|define
name|OUI_CISCO
value|0x00000c
end_define

begin_comment
comment|/* Cisco protocols */
end_comment

begin_define
define|#
directive|define
name|OUI_CISCO_90
value|0x0000f8
end_define

begin_comment
comment|/* Cisco bridging */
end_comment

begin_define
define|#
directive|define
name|OUI_RFC2684
value|0x0080c2
end_define

begin_comment
comment|/* RFC 2684 bridged Ethernet */
end_comment

begin_define
define|#
directive|define
name|OUI_APPLETALK
value|0x080007
end_define

begin_comment
comment|/* Appletalk */
end_comment

begin_comment
comment|/*  * PIDs for use with OUI_CISCO.  */
end_comment

begin_define
define|#
directive|define
name|PID_CISCO_CDP
value|0x2000
end_define

begin_comment
comment|/* Cisco Discovery Protocol */
end_comment

begin_comment
comment|/*  * PIDs for use with OUI_RFC2684.  */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_ETH_FCS
value|0x0001
end_define

begin_comment
comment|/* Ethernet, with FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_ETH_NOFCS
value|0x0007
end_define

begin_comment
comment|/* Ethernet, without FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_802_4_FCS
value|0x0002
end_define

begin_comment
comment|/* 802.4, with FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_802_4_NOFCS
value|0x0008
end_define

begin_comment
comment|/* 802.4, without FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_802_5_FCS
value|0x0003
end_define

begin_comment
comment|/* 802.5, with FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_802_5_NOFCS
value|0x0009
end_define

begin_comment
comment|/* 802.5, without FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_FDDI_FCS
value|0x0004
end_define

begin_comment
comment|/* FDDI, with FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_FDDI_NOFCS
value|0x000a
end_define

begin_comment
comment|/* FDDI, without FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_802_6_FCS
value|0x0005
end_define

begin_comment
comment|/* 802.6, with FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_802_6_NOFCS
value|0x000b
end_define

begin_comment
comment|/* 802.6, without FCS */
end_comment

begin_define
define|#
directive|define
name|PID_RFC2684_BPDU
value|0x000e
end_define

begin_comment
comment|/* BPDUs */
end_comment

end_unit

