begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988-2002  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

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
name|HAVE_SNPRINTF
argument_list|)
end_if

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
ifdef|#
directive|ifdef
name|__ATTRIBUTE___FORMAT_OK
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

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ATTRIBUTE___FORMAT_OK */
end_comment

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_SNPRINTF) */
end_comment

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
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
ifdef|#
directive|ifdef
name|__ATTRIBUTE___FORMAT_OK
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

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ATTRIBUTE___FORMAT_OK */
end_comment

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_VSNPRINTF) */
end_comment

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

begin_define
define|#
directive|define
name|PT_TFTP
value|8
end_define

begin_comment
comment|/* trivial file transfer protocol */
end_comment

begin_define
define|#
directive|define
name|PT_AODV
value|9
end_define

begin_comment
comment|/* Ad-hoc On-demand Distance Vector Protocol */
end_comment

begin_define
define|#
directive|define
name|PT_CARP
value|10
end_define

begin_comment
comment|/* Common Address Redundancy Protocol */
end_comment

begin_define
define|#
directive|define
name|PT_RADIUS
value|11
end_define

begin_comment
comment|/* RADIUS authentication Protocol */
end_comment

begin_define
define|#
directive|define
name|PT_ZMTP1
value|12
end_define

begin_comment
comment|/* ZeroMQ Message Transport Protocol 1.0 */
end_comment

begin_define
define|#
directive|define
name|PT_VXLAN
value|13
end_define

begin_comment
comment|/* Virtual eXtensible Local Area Network */
end_comment

begin_define
define|#
directive|define
name|PT_PGM
value|14
end_define

begin_comment
comment|/* [UDP-encapsulated] Pragmatic General Multicast */
end_comment

begin_define
define|#
directive|define
name|PT_PGM_ZMTP1
value|15
end_define

begin_comment
comment|/* ZMTP/1.0 inside PGM (native or UDP-encapsulated) */
end_comment

begin_define
define|#
directive|define
name|PT_LMP
value|16
end_define

begin_comment
comment|/* Link Management Protocol */
end_comment

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

begin_comment
comment|/*  * True if  "l" bytes of "var" were captured.  *  * The "snapend - (l)<= snapend" checks to make sure "l" isn't so large  * that "snapend - (l)" underflows.  *  * The check is for<= rather than< because "l" might be 0.  */
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
value|(snapend - (l)<= snapend&& \ 			(const u_char *)&(var)<= snapend - (l))
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

begin_function_decl
specifier|extern
name|int
name|mask2plen
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|tok2strary_internal
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tok2strary
parameter_list|(
name|a
parameter_list|,
name|f
parameter_list|,
name|i
parameter_list|)
value|tok2strary_internal(a, sizeof(a)/sizeof(a[0]),f,i)
end_define

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
end_function_decl

begin_ifdef
unit|))
ifdef|#
directive|ifdef
name|__ATTRIBUTE___FORMAT_OK
end_ifdef

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
comment|/* __ATTRIBUTE___FORMAT_OK */
expr_stmt|;
end_expr_stmt

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
ifdef|#
directive|ifdef
name|__ATTRIBUTE___FORMAT_OK
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

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ATTRIBUTE___FORMAT_OK */
end_comment

begin_empty_stmt
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
specifier|const
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
specifier|const
name|char
modifier|*
name|dnnum_string
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* checksum routines */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_checksum
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint16_t
name|verify_crc10_cksum
parameter_list|(
name|uint16_t
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
name|uint16_t
name|create_osi_cksum
parameter_list|(
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|char
modifier|*
name|q922_string
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
specifier|const
name|char
modifier|*
name|nt_errstr
parameter_list|(
name|uint32_t
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
name|int
name|mask62plen
parameter_list|(
specifier|const
name|u_char
modifier|*
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

begin_struct
struct|struct
name|cksum_vec
block|{
specifier|const
name|uint8_t
modifier|*
name|ptr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|uint16_t
name|in_cksum
parameter_list|(
specifier|const
name|struct
name|cksum_vec
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint16_t
name|in_cksum_shouldbe
parameter_list|(
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BPF_DUMP
end_ifndef

begin_struct_decl
struct_decl|struct
name|bpf_program
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|bpf_dump
parameter_list|(
specifier|const
name|struct
name|bpf_program
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_comment
comment|/* forward compatibility */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETDISSECT_REWORKED
end_ifndef

begin_decl_stmt
specifier|extern
name|netdissect_options
modifier|*
name|gndo
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|bflag
value|gndo->ndo_bflag
end_define

begin_define
define|#
directive|define
name|eflag
value|gndo->ndo_eflag
end_define

begin_define
define|#
directive|define
name|fflag
value|gndo->ndo_fflag
end_define

begin_define
define|#
directive|define
name|jflag
value|gndo->ndo_jflag
end_define

begin_define
define|#
directive|define
name|Kflag
value|gndo->ndo_Kflag
end_define

begin_define
define|#
directive|define
name|nflag
value|gndo->ndo_nflag
end_define

begin_define
define|#
directive|define
name|Nflag
value|gndo->ndo_Nflag
end_define

begin_define
define|#
directive|define
name|Oflag
value|gndo->ndo_Oflag
end_define

begin_define
define|#
directive|define
name|pflag
value|gndo->ndo_pflag
end_define

begin_define
define|#
directive|define
name|qflag
value|gndo->ndo_qflag
end_define

begin_define
define|#
directive|define
name|Rflag
value|gndo->ndo_Rflag
end_define

begin_define
define|#
directive|define
name|sflag
value|gndo->ndo_sflag
end_define

begin_define
define|#
directive|define
name|Sflag
value|gndo->ndo_Sflag
end_define

begin_define
define|#
directive|define
name|tflag
value|gndo->ndo_tflag
end_define

begin_define
define|#
directive|define
name|Uflag
value|gndo->ndo_Uflag
end_define

begin_define
define|#
directive|define
name|uflag
value|gndo->ndo_uflag
end_define

begin_define
define|#
directive|define
name|vflag
value|gndo->ndo_vflag
end_define

begin_define
define|#
directive|define
name|xflag
value|gndo->ndo_xflag
end_define

begin_define
define|#
directive|define
name|Xflag
value|gndo->ndo_Xflag
end_define

begin_define
define|#
directive|define
name|Cflag
value|gndo->ndo_Cflag
end_define

begin_define
define|#
directive|define
name|Gflag
value|gndo->ndo_Gflag
end_define

begin_define
define|#
directive|define
name|Aflag
value|gndo->ndo_Aflag
end_define

begin_define
define|#
directive|define
name|Bflag
value|gndo->ndo_Bflag
end_define

begin_define
define|#
directive|define
name|Iflag
value|gndo->ndo_Iflag
end_define

begin_define
define|#
directive|define
name|suppress_default_print
value|gndo->ndo_suppress_default_print
end_define

begin_define
define|#
directive|define
name|packettype
value|gndo->ndo_packettype
end_define

begin_define
define|#
directive|define
name|sigsecret
value|gndo->ndo_sigsecret
end_define

begin_define
define|#
directive|define
name|Wflag
value|gndo->ndo_Wflag
end_define

begin_define
define|#
directive|define
name|WflagChars
value|gndo->ndo_WflagChars
end_define

begin_define
define|#
directive|define
name|Cflag_count
value|gndo->ndo_Cflag_count
end_define

begin_define
define|#
directive|define
name|Gflag_count
value|gndo->ndo_Gflag_count
end_define

begin_define
define|#
directive|define
name|Gflag_time
value|gndo->ndo_Gflag_time
end_define

begin_define
define|#
directive|define
name|Hflag
value|gndo->ndo_Hflag
end_define

begin_define
define|#
directive|define
name|snaplen
value|gndo->ndo_snaplen
end_define

begin_define
define|#
directive|define
name|snapend
value|gndo->ndo_snapend
end_define

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

