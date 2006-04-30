begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988-1997  *	The Regents of the University of California.  All rights reserved.  *  * Copyright (c) 1998-2004  Michael Richardson<mcr@tcpdump.org>  *      The TCPDUMP project  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/netdissect.h,v 1.16 2005/04/07 00:28:17 mcr Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|netdissect_h
end_ifndef

begin_define
define|#
directive|define
name|netdissect_h
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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRDUP
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
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
name|HAVE_STRSEP
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsep
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
comment|/* string */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TOKBUFSIZE
value|128
end_define

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|tok2strbuf
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
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|bufsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tok2str is deprecated */
end_comment

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
name|bittok2str
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

begin_typedef
typedef|typedef
name|struct
name|netdissect_options
name|netdissect_options
typedef|;
end_typedef

begin_struct
struct|struct
name|netdissect_options
block|{
name|int
name|ndo_aflag
decl_stmt|;
comment|/* translate network and broadcast addresses */
name|int
name|ndo_eflag
decl_stmt|;
comment|/* print ethernet header */
name|int
name|ndo_fflag
decl_stmt|;
comment|/* don't translate "foreign" IP address */
name|int
name|ndo_nflag
decl_stmt|;
comment|/* leave addresses as numbers */
name|int
name|ndo_Nflag
decl_stmt|;
comment|/* remove domains from printed host names */
name|int
name|ndo_qflag
decl_stmt|;
comment|/* quick (shorter) output */
name|int
name|ndo_Rflag
decl_stmt|;
comment|/* print sequence # field in AH/ESP*/
name|int
name|ndo_sflag
decl_stmt|;
comment|/* use the libsmi to translate OIDs */
name|int
name|ndo_Sflag
decl_stmt|;
comment|/* print raw TCP sequence numbers */
name|int
name|ndo_tflag
decl_stmt|;
comment|/* print packet arrival time */
name|int
name|ndo_Uflag
decl_stmt|;
comment|/* "unbuffered" output of dump files */
name|int
name|ndo_uflag
decl_stmt|;
comment|/* Print undecoded NFS handles */
name|int
name|ndo_vflag
decl_stmt|;
comment|/* verbose */
name|int
name|ndo_xflag
decl_stmt|;
comment|/* print packet in hex */
name|int
name|ndo_Xflag
decl_stmt|;
comment|/* print packet in hex/ascii */
name|int
name|ndo_Aflag
decl_stmt|;
comment|/* print packet only in ascii observing TAB, 				 * LF, CR and SPACE as graphical chars 				 */
name|int
name|ndo_Oflag
decl_stmt|;
comment|/* run filter code optimizer */
name|int
name|ndo_dlt
decl_stmt|;
comment|/* if != -1, ask libpcap for the DLT it names*/
name|int
name|ndo_pflag
decl_stmt|;
comment|/* don't go promiscuous */
name|int
name|ndo_Cflag
decl_stmt|;
comment|/* rotate dump files after this many bytes */
name|int
name|ndo_Cflag_count
decl_stmt|;
comment|/* Keep track of which file number we're writing */
name|int
name|ndo_Wflag
decl_stmt|;
comment|/* recycle output files after this number of files */
name|int
name|ndo_WflagChars
decl_stmt|;
specifier|const
name|char
modifier|*
name|ndo_dltname
decl_stmt|;
name|char
modifier|*
name|ndo_espsecret
decl_stmt|;
name|struct
name|sa_list
modifier|*
name|ndo_sa_list_head
decl_stmt|;
comment|/* used by print-esp.c */
name|struct
name|sa_list
modifier|*
name|ndo_sa_default
decl_stmt|;
name|char
modifier|*
name|ndo_tcpmd5secret
decl_stmt|;
comment|/* TCP-MD5 secret key */
name|struct
name|esp_algorithm
modifier|*
name|ndo_espsecret_xform
decl_stmt|;
comment|/* cache of decoded  */
name|char
modifier|*
name|ndo_espsecret_key
decl_stmt|;
name|int
name|ndo_packettype
decl_stmt|;
comment|/* as specified by -T */
name|char
modifier|*
name|ndo_program_name
decl_stmt|;
comment|/*used to generate self-identifying messages */
name|int32_t
name|ndo_thiszone
decl_stmt|;
comment|/* seconds offset from gmt to local time */
name|int
name|ndo_snaplen
decl_stmt|;
comment|/*global pointers to beginning and end of current packet (during printing) */
specifier|const
name|u_char
modifier|*
name|ndo_packetp
decl_stmt|;
specifier|const
name|u_char
modifier|*
name|ndo_snapend
decl_stmt|;
comment|/* bookkeeping for ^T output */
name|int
name|ndo_infodelay
decl_stmt|;
comment|/* pointer to void function to output stuff */
name|void
function_decl|(
modifier|*
name|ndo_default_print
function_decl|)
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
specifier|register
name|u_int
name|length
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ndo_info
function_decl|)
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ndo_printf
function_decl|)
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ndo_error
function_decl|)
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ndo_warning
function_decl|)
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

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

begin_comment
comment|/*  * True if "l" bytes of "var" were captured.  *  * The "ndo->ndo_snapend - (l)<= ndo->ndo_snapend" checks to make sure  * "l" isn't so large that "ndo->ndo_snapend - (l)" underflows.  *  * The check is for<= rather than< because "l" might be 0.  */
end_comment

begin_define
define|#
directive|define
name|ND_TTEST2
parameter_list|(
name|var
parameter_list|,
name|l
parameter_list|)
value|(ndo->ndo_snapend - (l)<= ndo->ndo_snapend&& \ 			(const u_char *)&(var)<= ndo->ndo_snapend - (l))
end_define

begin_comment
comment|/* True if "var" was captured */
end_comment

begin_define
define|#
directive|define
name|ND_TTEST
parameter_list|(
name|var
parameter_list|)
value|ND_TTEST2(var, sizeof(var))
end_define

begin_comment
comment|/* Bail if "l" bytes of "var" were not captured */
end_comment

begin_define
define|#
directive|define
name|ND_TCHECK2
parameter_list|(
name|var
parameter_list|,
name|l
parameter_list|)
value|if (!ND_TTEST2(var, l)) goto trunc
end_define

begin_comment
comment|/* Bail if "var" was not captured */
end_comment

begin_define
define|#
directive|define
name|ND_TCHECK
parameter_list|(
name|var
parameter_list|)
value|ND_TCHECK2(var, sizeof(var))
end_define

begin_define
define|#
directive|define
name|ND_PRINT
parameter_list|(
name|STUFF
parameter_list|)
value|(*ndo->ndo_printf)STUFF
end_define

begin_define
define|#
directive|define
name|ND_DEFAULTPRINT
parameter_list|(
name|ap
parameter_list|,
name|length
parameter_list|)
value|(*ndo->ndo_default_print)(ndo, ap, length)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern void ts_print(netdissect_options *ipdo, 		     const struct timeval *); extern void relts_print(int);
endif|#
directive|endif
end_endif

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
literal|0
end_if

begin_endif
unit|extern char *read_infile(netdissect_options *, char *); extern char *copy_argv(netdissect_options *, char **);
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern const char *isonsap_string(netdissect_options *, const u_char *); extern const char *llcsap_string(netdissect_options *, u_char); extern const char *protoid_string(netdissect_options *, const u_char *); extern const char *dnname_string(netdissect_options *, u_short); extern const char *dnnum_string(netdissect_options *, u_short);
endif|#
directive|endif
end_endif

begin_comment
comment|/* The printer routines. */
end_comment

begin_include
include|#
directive|include
file|<pcap.h>
end_include

begin_function_decl
specifier|extern
name|void
name|eap_print
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
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
name|esp_print
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|int
name|len
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp2
parameter_list|,
name|int
modifier|*
name|nhdr
parameter_list|,
name|int
modifier|*
name|padlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arp_print
parameter_list|(
name|netdissect_options
modifier|*
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
name|isakmp_print
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
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
name|isakmp_rfc3948_print
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
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
name|netdissect_options
modifier|*
parameter_list|,
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
name|ip_print_inner
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|nh
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bp2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stuff that has not yet been rototiled */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
unit|extern void ascii_print_with_offset(netdissect_options *, const char *, 				    u_int, u_int);     extern void ascii_print(netdissect_options *,const char *, u_int);     extern void hex_print_with_offset(netdissect_options *,const char *, 				  u_int, u_int);     extern void telnet_print(netdissect_options *,const u_char *, u_int);     extern void hex_print(netdissect_options *,const char *, u_int);     extern int ether_encap_print(netdissect_options *,u_short, const u_char *, 			     u_int, u_int, u_short *); extern int llc_print(netdissect_options *, 		     const u_char *, u_int, u_int, const u_char *, 		     const u_char *, u_short *); extern void aarp_print(netdissect_options *,const u_char *, u_int); extern void atalk_print(netdissect_options *,const u_char *, u_int); extern void atm_if_print(u_char *,const struct pcap_pkthdr *, const u_char *); extern void bootp_print(netdissect_options *,const u_char *, 			u_int, u_short, u_short); extern void bgp_print(netdissect_options *,const u_char *, int); extern void bxxp_print(netdissect_options *,const u_char *, u_int); extern void chdlc_if_print(u_char *user, const struct pcap_pkthdr *h, 			   register const u_char *p); extern void chdlc_print(netdissect_options *ndo, 			register const u_char *p, u_int length, u_int caplen); extern void cisco_autorp_print(netdissect_options *, 			       const u_char *, u_int); extern void cnfp_print(netdissect_options *,const u_char *cp, 		       u_int len, const u_char *bp); extern void decnet_print(netdissect_options *,const u_char *, 			 u_int, u_int); extern void default_print(netdissect_options *,const u_char *, u_int); extern void dvmrp_print(netdissect_options *,const u_char *, u_int); extern void egp_print(netdissect_options *,const u_char *, u_int, 		      const u_char *);  extern void arcnet_if_print(u_char*,const struct pcap_pkthdr *,const u_char *); extern void ether_if_print(u_char *,const struct pcap_pkthdr *,const u_char *); extern void token_if_print(u_char *,const struct pcap_pkthdr *,const u_char *); extern void fddi_if_print(u_char *,const struct pcap_pkthdr *, const u_char *);  extern void gre_print(netdissect_options *,const u_char *, u_int); extern void icmp_print(netdissect_options *,const u_char *, u_int, 		       const u_char *); extern void hsrp_print(netdissect_options *ndo, 		       register const u_char *bp, register u_int len); extern void ieee802_11_if_print(u_char *,const struct pcap_pkthdr *, const u_char *); extern void igmp_print(netdissect_options *, 		       register const u_char *, u_int); extern void igrp_print(netdissect_options *,const u_char *, u_int, 		       const u_char *); extern void ipN_print(netdissect_options *,const u_char *, u_int); extern void ipx_print(netdissect_options *,const u_char *, u_int); extern void isoclns_print(netdissect_options *,const u_char *, 			  u_int, u_int, const u_char *,	const u_char *); extern void krb_print(netdissect_options *,const u_char *, u_int); extern void llap_print(netdissect_options *,const u_char *, u_int); extern const char *linkaddr_string(netdissect_options *ndo, 				   const u_char *ep, const unsigned int len); extern void ltalk_if_print(netdissect_options *ndo, 			   u_char *user, const struct pcap_pkthdr *h, 			   const u_char *p); extern void mpls_print(netdissect_options *ndo, 		       const u_char *bp, u_int length); extern void msdp_print(netdissect_options *ndo, 		       const unsigned char *sp, u_int length); extern void nfsreply_print(netdissect_options *,const u_char *, 			   u_int, const u_char *); extern void nfsreq_print(netdissect_options *,const u_char *, 			 u_int, const u_char *); extern void ns_print(netdissect_options *,const u_char *, u_int); extern void ntp_print(netdissect_options *,const u_char *, u_int); extern void null_if_print(u_char *,const struct pcap_pkthdr *, const u_char *); extern void ospf_print(netdissect_options *,const u_char *, 		       u_int, const u_char *); extern void pimv1_print(netdissect_options *,const u_char *, u_int); extern void mobile_print(netdissect_options *,const u_char *, u_int); extern void pim_print(netdissect_options *,const u_char *, u_int); extern void pppoe_if_print(u_char *,const struct pcap_pkthdr *, const u_char *); extern void pppoe_print(netdissect_options *,const u_char *, u_int); extern void ppp_print(netdissect_options *, 		      register const u_char *, u_int);  extern void ppp_if_print(u_char *,const struct pcap_pkthdr *, const u_char *); extern void ppp_hdlc_if_print(u_char *, 			      const struct pcap_pkthdr *, const u_char *); extern void ppp_bsdos_if_print(u_char *, 			       const struct pcap_pkthdr *, const u_char *);  extern int vjc_print(netdissect_options *,register const char *, 		     register u_int, u_short);  extern void raw_if_print(u_char *, 			 const struct pcap_pkthdr *, const u_char *);  extern void rip_print(netdissect_options *,const u_char *, u_int);  extern void sctp_print(netdissect_options *ndo, 		       const u_char *bp, const u_char *bp2,        		       u_int sctpPacketLength);  extern void sl_if_print(u_char *,const struct pcap_pkthdr *, const u_char *);  extern void lane_if_print(u_char *,const struct pcap_pkthdr *,const u_char *); extern void cip_if_print(u_char *,const struct pcap_pkthdr *,const u_char *); extern void sl_bsdos_if_print(u_char *, 			      const struct pcap_pkthdr *, const u_char *); extern void sll_if_print(u_char *, 			 const struct pcap_pkthdr *, const u_char *);  extern void snmp_print(netdissect_options *,const u_char *, u_int); extern void sunrpcrequest_print(netdissect_options *,const u_char *, 				u_int, const u_char *); extern void tcp_print(netdissect_options *,const u_char *, u_int, 		      const u_char *, int); extern void tftp_print(netdissect_options *,const u_char *, u_int); extern void timed_print(netdissect_options *,const u_char *, u_int); extern void udp_print(netdissect_options *,const u_char *, u_int, 		      const u_char *, int); extern void wb_print(netdissect_options *,const void *, u_int); extern int ah_print(netdissect_options *,register const u_char *, 		    register const u_char *); extern void esp_print_decodesecret(netdissect_options *ndo); extern int ipcomp_print(netdissect_options *,register const u_char *, 			register const u_char *, int *); extern void rx_print(netdissect_options *,register const u_char *, 		     int, int, int, u_char *); extern void netbeui_print(netdissect_options *,u_short, 			  const u_char *, int); extern void ipx_netbios_print(netdissect_options *,const u_char *, u_int); extern void nbt_tcp_print(netdissect_options *,const u_char *, int); extern void nbt_udp137_print(netdissect_options *, 			     const u_char *data, int); extern void nbt_udp138_print(netdissect_options *, 			     const u_char *data, int); extern char *smb_errstr(netdissect_options *,int, int); extern const char *nt_errstr(netdissect_options *, u_int32_t); extern void print_data(netdissect_options *,const unsigned char *, int); extern void l2tp_print(netdissect_options *,const u_char *, u_int); extern void lcp_print(netdissect_options *,const u_char *, u_int); extern void vrrp_print(netdissect_options *,const u_char *bp, 		       u_int len, int ttl); extern void cdp_print(netdissect_options *,const u_char *, 		      u_int, u_int, const u_char *, const u_char *); extern void stp_print(netdissect_options *,const u_char *p, u_int length); extern void radius_print(netdissect_options *,const u_char *, u_int); extern void lwres_print(netdissect_options *,const u_char *, u_int); extern void pptp_print(netdissect_options *,const u_char *, u_int);
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_endif
unit|extern void ip6_print(netdissect_options *,const u_char *, u_int); extern void ip6_opt_print(netdissect_options *,const u_char *, int); extern int hbhopt_print(netdissect_options *,const u_char *); extern int dstopt_print(netdissect_options *,const u_char *); extern int frag6_print(netdissect_options *,const u_char *, 		       const u_char *); extern void icmp6_print(netdissect_options *,const u_char *, 			const u_char *); extern void ripng_print(netdissect_options *,const u_char *, int); extern int rt6_print(netdissect_options *,const u_char *, const u_char *); extern void ospf6_print(netdissect_options *,const u_char *, u_int); extern void dhcp6_print(netdissect_options *,const u_char *, 			u_int, u_int16_t, u_int16_t);  extern void zephyr_print(netdissect_options * ndo, 			 const u_char *cp, int length);
endif|#
directive|endif
end_endif

begin_comment
comment|/*INET6*/
end_comment

begin_endif
unit|extern u_short in_cksum(const u_short *, 			register u_int, int);
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* netdissect_h */
end_comment

end_unit

