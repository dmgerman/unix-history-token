begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/interface.h,v 1.149 2001/01/02 22:47:06 guy Exp $ (LBL)  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___ATTRIBUTE__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* snprintf et al */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SNPRINTF
argument_list|)
end_if

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|sz
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_VSNPRINTF
argument_list|)
end_if

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|sz
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCAT
end_ifndef

begin_function_decl
specifier|extern
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_function_decl
specifier|extern
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

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
name|aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* translate network and broadcast addresses */
end_comment

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
name|fflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't translate "foreign" IP address */
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
name|Rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print sequence # field in AH/ESP*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use the libsmi to translate OIDs */
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
name|uflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print undecoded NFS handles */
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
name|Xflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print packet in hex/ascii */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|espsecret
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|PT_SNMP
value|6
end_define

begin_comment
comment|/* Simple Network Management Protocol */
end_comment

begin_define
define|#
directive|define
name|PT_CNFP
value|7
end_define

begin_comment
comment|/* Cisco NetFlow protocol */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|INET6
end_ifndef

begin_comment
comment|/*  * The default snapshot length.  This value allows most printers to print  * useful information while keeping the amount of unwanted data down.  * In particular, it allows for an ethernet header, tcp/ip header, and  * 14 bytes of data (assuming no ip options).  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SNAPLEN
value|68
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_SNAPLEN
value|96
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

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
name|void
name|relts_print
parameter_list|(
name|int
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
name|void
name|wrapup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
function_decl|(noreturn
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
name|void
name|safeputchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|safeputs
parameter_list|(
specifier|const
name|char
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

begin_struct_decl
struct_decl|struct
name|pcap_pkthdr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|ascii_print_with_offset
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
name|ascii_print
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
name|hex_print_with_offset
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
name|telnet_print
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
name|hex_print
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
parameter_list|,
name|u_short
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
parameter_list|,
name|u_short
modifier|*
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
name|bgp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bxxp_print
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
name|cnfp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
name|u_int
name|len
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bp
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
name|token_if_print
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
name|gre_print
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
name|icmp_print
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
name|igmp_print
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
name|ipN_print
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

begin_function_decl
specifier|extern
name|void
name|llap_print
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
name|pimv1_print
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
name|cisco_autorp_print
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
name|mobile_print
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
name|pppoe_print
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
name|ppp_print
parameter_list|(
specifier|register
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
name|ppp_hdlc_if_print
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
name|ppp_bsdos_if_print
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
name|int
name|vjc_print
parameter_list|(
specifier|register
specifier|const
name|char
modifier|*
parameter_list|,
specifier|register
name|u_int
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|raw_if_print
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
name|lane_if_print
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
name|cip_if_print
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
name|sl_bsdos_if_print
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
name|chdlc_if_print
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
name|sll_if_print
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
parameter_list|,
name|int
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
name|timed_print
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
parameter_list|,
name|int
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
name|int
name|ah_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|esp_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isakmp_print
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
name|ipcomp_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rx_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|netbeui_print
parameter_list|(
name|u_short
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
name|ipx_netbios_print
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
name|nbt_tcp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nbt_udp137_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nbt_udp138_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|smb_errstr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_data
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l2tp_print
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
name|lcp_print
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
name|vrrp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|len
parameter_list|,
name|int
name|ttl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cdp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|caplen
parameter_list|,
specifier|const
name|u_char
modifier|*
name|esrc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|edst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stp_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radius_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ip6_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ip6_opt_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hbhopt_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dstopt_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|frag6_print
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
name|icmp6_print
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
name|ripng_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rt6_print
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
name|ospf6_print
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
name|dhcp6_print
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*INET6*/
end_comment

begin_function_decl
specifier|extern
name|u_short
name|in_cksum
parameter_list|(
specifier|const
name|u_short
modifier|*
name|addr
parameter_list|,
specifier|register
name|int
name|len
parameter_list|,
name|u_short
name|csum
parameter_list|)
function_decl|;
end_function_decl

end_unit

