begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-domain.c,v 1.42 1999/11/21 09:36:50 fenner Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NOERROR
end_ifdef

begin_undef
undef|#
directive|undef
name|NOERROR
end_undef

begin_comment
comment|/* Solaris sucks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOERROR
end_ifdef

begin_undef
undef|#
directive|undef
name|T_UNSPEC
end_undef

begin_comment
comment|/* SINIX does too */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_comment
comment|/* must come after interface.h */
end_comment

begin_comment
comment|/* Compatibility */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T_TXT
end_ifndef

begin_define
define|#
directive|define
name|T_TXT
value|16
end_define

begin_comment
comment|/* text strings */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_RP
end_ifndef

begin_define
define|#
directive|define
name|T_RP
value|17
end_define

begin_comment
comment|/* responsible person */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_AFSDB
end_ifndef

begin_define
define|#
directive|define
name|T_AFSDB
value|18
end_define

begin_comment
comment|/* AFS cell database */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_X25
end_ifndef

begin_define
define|#
directive|define
name|T_X25
value|19
end_define

begin_comment
comment|/* X_25 calling address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_ISDN
end_ifndef

begin_define
define|#
directive|define
name|T_ISDN
value|20
end_define

begin_comment
comment|/* ISDN calling address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_RT
end_ifndef

begin_define
define|#
directive|define
name|T_RT
value|21
end_define

begin_comment
comment|/* router */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_NSAP
end_ifndef

begin_define
define|#
directive|define
name|T_NSAP
value|22
end_define

begin_comment
comment|/* NSAP address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_NSAP_PTR
end_ifndef

begin_define
define|#
directive|define
name|T_NSAP_PTR
value|23
end_define

begin_comment
comment|/* reverse NSAP lookup (deprecated) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_SIG
end_ifndef

begin_define
define|#
directive|define
name|T_SIG
value|24
end_define

begin_comment
comment|/* security signature */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_KEY
end_ifndef

begin_define
define|#
directive|define
name|T_KEY
value|25
end_define

begin_comment
comment|/* security key */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_PX
end_ifndef

begin_define
define|#
directive|define
name|T_PX
value|26
end_define

begin_comment
comment|/* X.400 mail mapping */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_GPOS
end_ifndef

begin_define
define|#
directive|define
name|T_GPOS
value|27
end_define

begin_comment
comment|/* geographical position (withdrawn) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_AAAA
end_ifndef

begin_define
define|#
directive|define
name|T_AAAA
value|28
end_define

begin_comment
comment|/* IP6 Address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_LOC
end_ifndef

begin_define
define|#
directive|define
name|T_LOC
value|29
end_define

begin_comment
comment|/* Location Information */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_NXT
end_ifndef

begin_define
define|#
directive|define
name|T_NXT
value|30
end_define

begin_comment
comment|/* Next Valid Name in Zone */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_EID
end_ifndef

begin_define
define|#
directive|define
name|T_EID
value|31
end_define

begin_comment
comment|/* Endpoint identifier */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_NIMLOC
end_ifndef

begin_define
define|#
directive|define
name|T_NIMLOC
value|32
end_define

begin_comment
comment|/* Nimrod locator */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_SRV
end_ifndef

begin_define
define|#
directive|define
name|T_SRV
value|33
end_define

begin_comment
comment|/* Server selection */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_ATMA
end_ifndef

begin_define
define|#
directive|define
name|T_ATMA
value|34
end_define

begin_comment
comment|/* ATM Address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_NAPTR
end_ifndef

begin_define
define|#
directive|define
name|T_NAPTR
value|35
end_define

begin_comment
comment|/* Naming Authority PoinTeR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_A6
end_ifndef

begin_define
define|#
directive|define
name|T_A6
value|38
end_define

begin_comment
comment|/* IP6 address (ipngwg-dns-lookups) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_UNSPEC
end_ifndef

begin_define
define|#
directive|define
name|T_UNSPEC
value|103
end_define

begin_comment
comment|/* Unspecified format (binary data) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_UNSPECA
end_ifndef

begin_define
define|#
directive|define
name|T_UNSPECA
value|104
end_define

begin_comment
comment|/* "unspecified ascii". Ugly MIT hack */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|C_CHAOS
end_ifndef

begin_define
define|#
directive|define
name|C_CHAOS
value|3
end_define

begin_comment
comment|/* for chaos net (MIT) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|C_HS
end_ifndef

begin_define
define|#
directive|define
name|C_HS
value|4
end_define

begin_comment
comment|/* for Hesiod name server (MIT) (XXX) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ns_ops
index|[]
init|=
block|{
literal|""
block|,
literal|" inv_q"
block|,
literal|" stat"
block|,
literal|" op3"
block|,
literal|" notify"
block|,
literal|" op5"
block|,
literal|" op6"
block|,
literal|" op7"
block|,
literal|" op8"
block|,
literal|" updataA"
block|,
literal|" updateD"
block|,
literal|" updateDA"
block|,
literal|" updateM"
block|,
literal|" updateMA"
block|,
literal|" zoneInit"
block|,
literal|" zoneRef"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ns_resp
index|[]
init|=
block|{
literal|""
block|,
literal|" FormErr"
block|,
literal|" ServFail"
block|,
literal|" NXDomain"
block|,
literal|" NotImp"
block|,
literal|" Refused"
block|,
literal|" Resp6"
block|,
literal|" Resp7"
block|,
literal|" Resp8"
block|,
literal|" Resp9"
block|,
literal|" Resp10"
block|,
literal|" Resp11"
block|,
literal|" Resp12"
block|,
literal|" Resp13"
block|,
literal|" Resp14"
block|,
literal|" NoChange"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* skip over a domain name */
end_comment

begin_function
specifier|static
specifier|const
name|u_char
modifier|*
name|ns_nskip
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|)
block|{
specifier|register
name|u_char
name|i
decl_stmt|;
if|if
condition|(
operator|(
operator|(
name|i
operator|=
operator|*
name|cp
operator|++
operator|)
operator|&
name|INDIR_MASK
operator|)
operator|==
name|INDIR_MASK
condition|)
return|return
operator|(
name|cp
operator|+
literal|1
operator|)
return|;
while|while
condition|(
name|i
operator|&&
name|cp
operator|<
name|snapend
condition|)
block|{
name|cp
operator|+=
name|i
expr_stmt|;
name|i
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|cp
operator|)
return|;
block|}
end_function

begin_comment
comment|/* print a<domain-name> */
end_comment

begin_function
specifier|static
specifier|const
name|u_char
modifier|*
name|ns_nprint
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|)
block|{
specifier|register
name|u_int
name|i
decl_stmt|;
specifier|register
specifier|const
name|u_char
modifier|*
name|rp
decl_stmt|;
specifier|register
name|int
name|compress
decl_stmt|;
name|i
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
name|rp
operator|=
name|cp
operator|+
name|i
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|&
name|INDIR_MASK
operator|)
operator|==
name|INDIR_MASK
condition|)
block|{
name|rp
operator|=
name|cp
operator|+
literal|1
expr_stmt|;
name|compress
operator|=
literal|1
expr_stmt|;
block|}
else|else
name|compress
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
while|while
condition|(
name|i
operator|&&
name|cp
operator|<
name|snapend
condition|)
block|{
if|if
condition|(
operator|(
name|i
operator|&
name|INDIR_MASK
operator|)
operator|==
name|INDIR_MASK
condition|)
block|{
name|cp
operator|=
name|bp
operator|+
operator|(
operator|(
operator|(
name|i
operator|<<
literal|8
operator|)
operator||
operator|*
name|cp
operator|)
operator|&
literal|0x3fff
operator|)
expr_stmt|;
name|i
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|fn_printn
argument_list|(
name|cp
argument_list|,
name|i
argument_list|,
name|snapend
argument_list|)
condition|)
break|break;
name|cp
operator|+=
name|i
expr_stmt|;
name|putchar
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
name|i
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
if|if
condition|(
operator|!
name|compress
condition|)
name|rp
operator|+=
name|i
operator|+
literal|1
expr_stmt|;
block|}
else|else
name|putchar
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
return|return
operator|(
name|rp
operator|)
return|;
block|}
end_function

begin_comment
comment|/* print a<character-string> */
end_comment

begin_function
specifier|static
specifier|const
name|u_char
modifier|*
name|ns_cprint
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|)
block|{
specifier|register
name|u_int
name|i
decl_stmt|;
name|i
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
operator|(
name|void
operator|)
name|fn_printn
argument_list|(
name|cp
argument_list|,
name|i
argument_list|,
name|snapend
argument_list|)
expr_stmt|;
return|return
operator|(
name|cp
operator|+
name|i
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|struct
name|tok
name|type2str
index|[]
init|=
block|{
block|{
name|T_A
block|,
literal|"A"
block|}
block|,
block|{
name|T_NS
block|,
literal|"NS"
block|}
block|,
block|{
name|T_MD
block|,
literal|"MD"
block|}
block|,
block|{
name|T_MF
block|,
literal|"MF"
block|}
block|,
block|{
name|T_CNAME
block|,
literal|"CNAME"
block|}
block|,
block|{
name|T_SOA
block|,
literal|"SOA"
block|}
block|,
block|{
name|T_MB
block|,
literal|"MB"
block|}
block|,
block|{
name|T_MG
block|,
literal|"MG"
block|}
block|,
block|{
name|T_MR
block|,
literal|"MR"
block|}
block|,
block|{
name|T_NULL
block|,
literal|"NULL"
block|}
block|,
block|{
name|T_WKS
block|,
literal|"WKS"
block|}
block|,
block|{
name|T_PTR
block|,
literal|"PTR"
block|}
block|,
block|{
name|T_HINFO
block|,
literal|"HINFO"
block|}
block|,
block|{
name|T_MINFO
block|,
literal|"MINFO"
block|}
block|,
block|{
name|T_MX
block|,
literal|"MX"
block|}
block|,
block|{
name|T_TXT
block|,
literal|"TXT"
block|}
block|,
block|{
name|T_RP
block|,
literal|"RP"
block|}
block|,
block|{
name|T_AFSDB
block|,
literal|"AFSDB"
block|}
block|,
block|{
name|T_X25
block|,
literal|"X25"
block|}
block|,
block|{
name|T_ISDN
block|,
literal|"ISDN"
block|}
block|,
block|{
name|T_RT
block|,
literal|"RT"
block|}
block|,
block|{
name|T_NSAP
block|,
literal|"NSAP"
block|}
block|,
block|{
name|T_NSAP_PTR
block|,
literal|"NSAP_PTR"
block|}
block|,
block|{
name|T_SIG
block|,
literal|"SIG"
block|}
block|,
block|{
name|T_KEY
block|,
literal|"KEY"
block|}
block|,
block|{
name|T_PX
block|,
literal|"PX"
block|}
block|,
block|{
name|T_GPOS
block|,
literal|"GPOS"
block|}
block|,
block|{
name|T_AAAA
block|,
literal|"AAAA"
block|}
block|,
block|{
name|T_LOC
block|,
literal|"LOC "
block|}
block|,
block|{
name|T_NXT
block|,
literal|"NXT "
block|}
block|,
block|{
name|T_EID
block|,
literal|"EID "
block|}
block|,
block|{
name|T_NIMLOC
block|,
literal|"NIMLOC "
block|}
block|,
block|{
name|T_SRV
block|,
literal|"SRV "
block|}
block|,
block|{
name|T_ATMA
block|,
literal|"ATMA "
block|}
block|,
block|{
name|T_NAPTR
block|,
literal|"NAPTR "
block|}
block|,
block|{
name|T_A6
block|,
literal|"A6 "
block|}
block|,
ifndef|#
directive|ifndef
name|T_UINFO
define|#
directive|define
name|T_UINFO
value|100
endif|#
directive|endif
block|{
name|T_UINFO
block|,
literal|"UINFO"
block|}
block|,
ifndef|#
directive|ifndef
name|T_UID
define|#
directive|define
name|T_UID
value|101
endif|#
directive|endif
block|{
name|T_UID
block|,
literal|"UID"
block|}
block|,
ifndef|#
directive|ifndef
name|T_GID
define|#
directive|define
name|T_GID
value|102
endif|#
directive|endif
block|{
name|T_GID
block|,
literal|"GID"
block|}
block|,
block|{
name|T_UNSPEC
block|,
literal|"UNSPEC"
block|}
block|,
block|{
name|T_UNSPECA
block|,
literal|"UNSPECA"
block|}
block|,
block|{
name|T_AXFR
block|,
literal|"AXFR"
block|}
block|,
block|{
name|T_MAILB
block|,
literal|"MAILB"
block|}
block|,
block|{
name|T_MAILA
block|,
literal|"MAILA"
block|}
block|,
block|{
name|T_ANY
block|,
literal|"ANY"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|tok
name|class2str
index|[]
init|=
block|{
block|{
name|C_IN
block|,
literal|"IN"
block|}
block|,
comment|/* Not used */
block|{
name|C_CHAOS
block|,
literal|"CHAOS)"
block|}
block|,
block|{
name|C_HS
block|,
literal|"HS"
block|}
block|,
block|{
name|C_ANY
block|,
literal|"ANY"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print a query */
end_comment

begin_function
specifier|static
name|void
name|ns_qprint
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|)
block|{
specifier|register
specifier|const
name|u_char
modifier|*
name|np
init|=
name|cp
decl_stmt|;
specifier|register
name|u_int
name|i
decl_stmt|;
name|cp
operator|=
name|ns_nskip
argument_list|(
name|cp
argument_list|,
name|bp
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
operator|+
literal|4
operator|>
name|snapend
condition|)
return|return;
comment|/* print the qtype and qclass (if it's not IN) */
name|i
operator|=
operator|*
name|cp
operator|++
operator|<<
literal|8
expr_stmt|;
name|i
operator||=
operator|*
name|cp
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|tok2str
argument_list|(
name|type2str
argument_list|,
literal|"Type%d"
argument_list|,
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|i
operator|=
operator|*
name|cp
operator|++
operator|<<
literal|8
expr_stmt|;
name|i
operator||=
operator|*
name|cp
operator|++
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|C_IN
condition|)
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|tok2str
argument_list|(
name|class2str
argument_list|,
literal|"(Class %d)"
argument_list|,
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"? "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|ns_nprint
argument_list|(
name|np
argument_list|,
name|bp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* print a reply */
end_comment

begin_function
specifier|static
specifier|const
name|u_char
modifier|*
name|ns_rprint
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|)
block|{
specifier|register
name|u_int
name|i
decl_stmt|;
specifier|register
name|u_short
name|typ
decl_stmt|,
name|len
decl_stmt|;
specifier|register
specifier|const
name|u_char
modifier|*
name|rp
decl_stmt|;
if|if
condition|(
name|vflag
condition|)
block|{
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|cp
operator|=
name|ns_nprint
argument_list|(
name|cp
argument_list|,
name|bp
argument_list|)
expr_stmt|;
block|}
else|else
name|cp
operator|=
name|ns_nskip
argument_list|(
name|cp
argument_list|,
name|bp
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
operator|+
literal|10
operator|>
name|snapend
condition|)
return|return
operator|(
name|snapend
operator|)
return|;
comment|/* print the type/qtype and class (if it's not IN) */
name|typ
operator|=
operator|*
name|cp
operator|++
operator|<<
literal|8
expr_stmt|;
name|typ
operator||=
operator|*
name|cp
operator|++
expr_stmt|;
name|i
operator|=
operator|*
name|cp
operator|++
operator|<<
literal|8
expr_stmt|;
name|i
operator||=
operator|*
name|cp
operator|++
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|C_IN
condition|)
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|tok2str
argument_list|(
name|class2str
argument_list|,
literal|"(Class %d)"
argument_list|,
name|i
argument_list|)
argument_list|)
expr_stmt|;
comment|/* ignore ttl */
name|cp
operator|+=
literal|4
expr_stmt|;
name|len
operator|=
operator|*
name|cp
operator|++
operator|<<
literal|8
expr_stmt|;
name|len
operator||=
operator|*
name|cp
operator|++
expr_stmt|;
name|rp
operator|=
name|cp
operator|+
name|len
expr_stmt|;
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|tok2str
argument_list|(
name|type2str
argument_list|,
literal|"Type%d"
argument_list|,
name|typ
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|typ
condition|)
block|{
case|case
name|T_A
case|:
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|ipaddr_string
argument_list|(
name|cp
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_NS
case|:
case|case
name|T_CNAME
case|:
case|case
name|T_PTR
case|:
ifdef|#
directive|ifdef
name|T_DNAME
case|case
name|T_DNAME
case|:
comment|/*XXX not checked as there's no server support yet*/
endif|#
directive|endif
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ns_nprint
argument_list|(
name|cp
argument_list|,
name|bp
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_MX
case|:
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ns_nprint
argument_list|(
name|cp
operator|+
literal|2
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %d"
argument_list|,
name|EXTRACT_16BITS
argument_list|(
name|cp
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_TXT
case|:
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ns_cprint
argument_list|(
name|cp
argument_list|,
name|bp
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|INET6
case|case
name|T_AAAA
case|:
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|ip6addr_string
argument_list|(
name|cp
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_A6
case|:
comment|/*XXX not checked as there's no server support yet*/
block|{
name|struct
name|in6_addr
name|a
decl_stmt|;
name|int
name|pbyte
decl_stmt|;
name|pbyte
operator|=
operator|(
operator|*
name|cp
operator|+
literal|7
operator|)
operator|/
literal|8
expr_stmt|;
name|memset
argument_list|(
operator|&
name|a
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|a
argument_list|,
name|cp
operator|+
literal|1
argument_list|,
name|pbyte
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %u %s "
argument_list|,
operator|*
name|cp
argument_list|,
name|ip6addr_string
argument_list|(
operator|&
name|a
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ns_nprint
argument_list|(
name|cp
operator|+
literal|1
operator|+
name|pbyte
argument_list|,
name|bp
argument_list|)
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
comment|/*INET6*/
case|case
name|T_UNSPECA
case|:
comment|/* One long string */
name|printf
argument_list|(
literal|" %.*s"
argument_list|,
name|len
argument_list|,
name|cp
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|rp
operator|)
return|;
comment|/* XXX This isn't always right */
block|}
end_function

begin_function
name|void
name|ns_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
specifier|register
specifier|const
name|HEADER
modifier|*
name|np
decl_stmt|;
specifier|register
name|int
name|qdcount
decl_stmt|,
name|ancount
decl_stmt|,
name|nscount
decl_stmt|,
name|arcount
decl_stmt|;
specifier|register
specifier|const
name|u_char
modifier|*
name|cp
decl_stmt|;
name|np
operator|=
operator|(
specifier|const
name|HEADER
operator|*
operator|)
name|bp
expr_stmt|;
comment|/* get the byte-order right */
name|qdcount
operator|=
name|ntohs
argument_list|(
name|np
operator|->
name|qdcount
argument_list|)
expr_stmt|;
name|ancount
operator|=
name|ntohs
argument_list|(
name|np
operator|->
name|ancount
argument_list|)
expr_stmt|;
name|nscount
operator|=
name|ntohs
argument_list|(
name|np
operator|->
name|nscount
argument_list|)
expr_stmt|;
name|arcount
operator|=
name|ntohs
argument_list|(
name|np
operator|->
name|arcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|np
operator|->
name|qr
condition|)
block|{
comment|/* this is a response */
name|printf
argument_list|(
literal|" %d%s%s%s%s%s"
argument_list|,
name|ntohs
argument_list|(
name|np
operator|->
name|id
argument_list|)
argument_list|,
name|ns_ops
index|[
name|np
operator|->
name|opcode
index|]
argument_list|,
name|ns_resp
index|[
name|np
operator|->
name|rcode
index|]
argument_list|,
name|np
operator|->
name|aa
condition|?
literal|"*"
else|:
literal|""
argument_list|,
name|np
operator|->
name|ra
condition|?
literal|""
else|:
literal|"-"
argument_list|,
name|np
operator|->
name|tc
condition|?
literal|"|"
else|:
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|qdcount
operator|!=
literal|1
condition|)
name|printf
argument_list|(
literal|" [%dq]"
argument_list|,
name|qdcount
argument_list|)
expr_stmt|;
comment|/* Print QUESTION section on -vv */
if|if
condition|(
name|vflag
operator|>
literal|1
condition|)
block|{
name|fputs
argument_list|(
literal|" q: "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|cp
operator|=
name|ns_nprint
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
operator|(
name|np
operator|+
literal|1
operator|)
argument_list|,
name|bp
argument_list|)
expr_stmt|;
block|}
else|else
name|cp
operator|=
name|ns_nskip
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
operator|(
name|np
operator|+
literal|1
operator|)
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %d/%d/%d"
argument_list|,
name|ancount
argument_list|,
name|nscount
argument_list|,
name|arcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|ancount
operator|--
condition|)
block|{
name|cp
operator|=
name|ns_rprint
argument_list|(
name|cp
operator|+
literal|4
argument_list|,
name|bp
argument_list|)
expr_stmt|;
while|while
condition|(
name|ancount
operator|--
operator|&&
name|cp
operator|<
name|snapend
condition|)
block|{
name|putchar
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|cp
operator|=
name|ns_rprint
argument_list|(
name|cp
argument_list|,
name|bp
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|/* this is a request */
name|printf
argument_list|(
literal|" %d%s%s"
argument_list|,
name|ntohs
argument_list|(
name|np
operator|->
name|id
argument_list|)
argument_list|,
name|ns_ops
index|[
name|np
operator|->
name|opcode
index|]
argument_list|,
name|np
operator|->
name|rd
condition|?
literal|"+"
else|:
literal|""
argument_list|)
expr_stmt|;
comment|/* any weirdness? */
if|if
condition|(
operator|*
operator|(
operator|(
operator|(
name|u_short
operator|*
operator|)
name|np
operator|)
operator|+
literal|1
operator|)
operator|&
name|htons
argument_list|(
literal|0x6ff
argument_list|)
condition|)
name|printf
argument_list|(
literal|" [b2&3=0x%x]"
argument_list|,
name|ntohs
argument_list|(
operator|*
operator|(
operator|(
operator|(
name|u_short
operator|*
operator|)
name|np
operator|)
operator|+
literal|1
operator|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|np
operator|->
name|opcode
operator|==
name|IQUERY
condition|)
block|{
if|if
condition|(
name|qdcount
condition|)
name|printf
argument_list|(
literal|" [%dq]"
argument_list|,
name|qdcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|ancount
operator|!=
literal|1
condition|)
name|printf
argument_list|(
literal|" [%da]"
argument_list|,
name|ancount
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|ancount
condition|)
name|printf
argument_list|(
literal|" [%da]"
argument_list|,
name|ancount
argument_list|)
expr_stmt|;
if|if
condition|(
name|qdcount
operator|!=
literal|1
condition|)
name|printf
argument_list|(
literal|" [%dq]"
argument_list|,
name|qdcount
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|nscount
condition|)
name|printf
argument_list|(
literal|" [%dn]"
argument_list|,
name|nscount
argument_list|)
expr_stmt|;
if|if
condition|(
name|arcount
condition|)
name|printf
argument_list|(
literal|" [%dau]"
argument_list|,
name|arcount
argument_list|)
expr_stmt|;
name|ns_qprint
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
operator|(
name|np
operator|+
literal|1
operator|)
argument_list|,
operator|(
specifier|const
name|u_char
operator|*
operator|)
name|np
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|" (%d)"
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

