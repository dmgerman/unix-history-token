begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: interface.h,v 1.95 96/07/14 19:38:52 leres Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tcpdump_interface_h
end_ifndef

begin_define
define|#
directive|define
name|tcpdump_interface_h
end_define

begin_include
include|#
directive|include
file|"gnuc.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OS_PROTO_H
end_ifdef

begin_include
include|#
directive|include
file|"os-proto.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tok
block|{
name|int
name|v
decl_stmt|;
comment|/* value */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* string */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print filter code */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|eflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print ethernet header */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* leave addresses as numbers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remove domains from printed host names */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|qflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quick (shorter) output */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print raw TCP sequence numbers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print packet arrival time */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verbose */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print packet in hex */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|packettype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as specified by -T */
end_comment

begin_define
define|#
directive|define
name|PT_VAT
value|1
end_define

begin_comment
comment|/* Visual Audio Tool */
end_comment

begin_define
define|#
directive|define
name|PT_WB
value|2
end_define

begin_comment
comment|/* distributed White Board */
end_comment

begin_define
define|#
directive|define
name|PT_RPC
value|3
end_define

begin_comment
comment|/* Remote Procedure Call */
end_comment

begin_define
define|#
directive|define
name|PT_RTP
value|4
end_define

begin_comment
comment|/* Real-Time Applications protocol */
end_comment

begin_define
define|#
directive|define
name|PT_RTCP
value|5
end_define

begin_comment
comment|/* Real-Time Applications control protocol */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to generate self-identifying messages */
end_comment

begin_decl_stmt
specifier|extern
name|int32_t
name|thiszone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds offset from gmt to local time */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|snaplen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global pointers to beginning and end of current packet (during printing) */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|u_char
modifier|*
name|packetp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_char
modifier|*
name|snapend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if  "l" bytes of "var" were captured */
end_comment

begin_define
define|#
directive|define
name|TTEST2
parameter_list|(
name|var
parameter_list|,
name|l
parameter_list|)
value|((u_char *)&(var)<= snapend - (l))
end_define

begin_comment
comment|/* True if "var" was captured */
end_comment

begin_define
define|#
directive|define
name|TTEST
parameter_list|(
name|var
parameter_list|)
value|TTEST2(var, sizeof(var))
end_define

begin_comment
comment|/* Bail if "l" bytes of "var" were not captured */
end_comment

begin_define
define|#
directive|define
name|TCHECK2
parameter_list|(
name|var
parameter_list|,
name|l
parameter_list|)
value|if (!TTEST2(var, l)) goto trunc
end_define

begin_comment
comment|/* Bail if "var" was not captured */
end_comment

begin_define
define|#
directive|define
name|TCHECK
parameter_list|(
name|var
parameter_list|)
value|TCHECK2(var, sizeof(var))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|ts_print
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int32_t
name|gmt2local
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fn_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fn_printn
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|tok2str
parameter_list|(
specifier|const
name|struct
name|tok
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dnaddr_string
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|savestr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wrapup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
specifier|extern
name|__dead
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(volatile
operator|,
function_decl|format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|warning
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|read_infile
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|copy_argv
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|isonsap_string
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|llcsap_string
parameter_list|(
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|protoid_string
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dnname_string
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dnnum_string
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The printer routines. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|pcap_pkthdr
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|atm_if_print
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ether_if_print
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fddi_if_print
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|null_if_print
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ppp_if_print
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sl_if_print
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ip_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|udp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|icmp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|igrp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_print_unaligned
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aarp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|atalk_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bootp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|decnet_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|egp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ether_encap_print
parameter_list|(
name|u_short
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipx_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isoclns_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|llc_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nfsreply_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nfsreq_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ns_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ntp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ospf_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rip_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|snmp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sunrpcrequest_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tftp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wb_print
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dvmrp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pim_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|krb_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(b):(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((b)>(a)?(b):(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The default snapshot length.  This value allows most printers to print  * useful information while keeping the amount of unwanted data down.  * In particular, it allows for an ethernet header, tcp/ip header, and  * 14 bytes of data (assuming no ip options).  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SNAPLEN
value|68
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ETHER_HEADER_HAS_EA
end_ifdef

begin_define
define|#
directive|define
name|ESRC
parameter_list|(
name|ep
parameter_list|)
value|((ep)->ether_shost.ether_addr_octet)
end_define

begin_define
define|#
directive|define
name|EDST
parameter_list|(
name|ep
parameter_list|)
value|((ep)->ether_dhost.ether_addr_octet)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ESRC
parameter_list|(
name|ep
parameter_list|)
value|((ep)->ether_shost)
end_define

begin_define
define|#
directive|define
name|EDST
parameter_list|(
name|ep
parameter_list|)
value|((ep)->ether_dhost)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ETHER_ARP_HAS_X
end_ifdef

begin_define
define|#
directive|define
name|SHA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_xsha)
end_define

begin_define
define|#
directive|define
name|THA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_xtha)
end_define

begin_define
define|#
directive|define
name|SPA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_xspa)
end_define

begin_define
define|#
directive|define
name|TPA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_xtpa)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ETHER_ARP_HAS_EA
end_ifdef

begin_define
define|#
directive|define
name|SHA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_sha.ether_addr_octet)
end_define

begin_define
define|#
directive|define
name|THA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_tha.ether_addr_octet)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SHA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_sha)
end_define

begin_define
define|#
directive|define
name|THA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_tha)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_spa)
end_define

begin_define
define|#
directive|define
name|TPA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_tpa)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NTOHL
end_ifndef

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohl(x)
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohs(x)
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|x
parameter_list|)
value|(x) = htonl(x)
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|x
parameter_list|)
value|(x) = htons(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

