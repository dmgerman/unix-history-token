begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1991, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-icmp.c,v 1.57 2000/10/10 05:03:32 guy Exp $ (LBL)"
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

begin_include
include|#
directive|include
file|<netinet/in.h>
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
file|<netdb.h>
end_include

begin_comment
comment|/* for MAXHOSTNAMELEN on some platforms */
end_comment

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

begin_include
include|#
directive|include
file|"ip.h"
end_include

begin_include
include|#
directive|include
file|"udp.h"
end_include

begin_comment
comment|/*  * Interface Control Message Protocol Definitions.  * Per RFC 792, September 1981.  */
end_comment

begin_comment
comment|/*  * Structure of an icmp header.  */
end_comment

begin_struct
struct|struct
name|icmp
block|{
name|u_int8_t
name|icmp_type
decl_stmt|;
comment|/* type of message, see below */
name|u_int8_t
name|icmp_code
decl_stmt|;
comment|/* type sub code */
name|u_int16_t
name|icmp_cksum
decl_stmt|;
comment|/* ones complement cksum of struct */
union|union
block|{
name|u_int8_t
name|ih_pptr
decl_stmt|;
comment|/* ICMP_PARAMPROB */
name|struct
name|in_addr
name|ih_gwaddr
decl_stmt|;
comment|/* ICMP_REDIRECT */
struct|struct
name|ih_idseq
block|{
name|u_int16_t
name|icd_id
decl_stmt|;
name|u_int16_t
name|icd_seq
decl_stmt|;
block|}
name|ih_idseq
struct|;
name|u_int32_t
name|ih_void
decl_stmt|;
comment|/* ICMP_UNREACH_NEEDFRAG -- Path MTU Discovery (RFC1191) */
struct|struct
name|ih_pmtu
block|{
name|u_int16_t
name|ipm_void
decl_stmt|;
name|u_int16_t
name|ipm_nextmtu
decl_stmt|;
block|}
name|ih_pmtu
struct|;
block|}
name|icmp_hun
union|;
define|#
directive|define
name|icmp_pptr
value|icmp_hun.ih_pptr
define|#
directive|define
name|icmp_gwaddr
value|icmp_hun.ih_gwaddr
define|#
directive|define
name|icmp_id
value|icmp_hun.ih_idseq.icd_id
define|#
directive|define
name|icmp_seq
value|icmp_hun.ih_idseq.icd_seq
define|#
directive|define
name|icmp_void
value|icmp_hun.ih_void
define|#
directive|define
name|icmp_pmvoid
value|icmp_hun.ih_pmtu.ipm_void
define|#
directive|define
name|icmp_nextmtu
value|icmp_hun.ih_pmtu.ipm_nextmtu
union|union
block|{
struct|struct
name|id_ts
block|{
name|u_int32_t
name|its_otime
decl_stmt|;
name|u_int32_t
name|its_rtime
decl_stmt|;
name|u_int32_t
name|its_ttime
decl_stmt|;
block|}
name|id_ts
struct|;
struct|struct
name|id_ip
block|{
name|struct
name|ip
name|idi_ip
decl_stmt|;
comment|/* options and then 64 bits of data */
block|}
name|id_ip
struct|;
name|u_int32_t
name|id_mask
decl_stmt|;
name|u_int8_t
name|id_data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|icmp_dun
union|;
define|#
directive|define
name|icmp_otime
value|icmp_dun.id_ts.its_otime
define|#
directive|define
name|icmp_rtime
value|icmp_dun.id_ts.its_rtime
define|#
directive|define
name|icmp_ttime
value|icmp_dun.id_ts.its_ttime
define|#
directive|define
name|icmp_ip
value|icmp_dun.id_ip.idi_ip
define|#
directive|define
name|icmp_mask
value|icmp_dun.id_mask
define|#
directive|define
name|icmp_data
value|icmp_dun.id_data
block|}
struct|;
end_struct

begin_comment
comment|/*  * Lower bounds on packet lengths for various types.  * For the error advice packets must first insure that the  * packet is large enought to contain the returned ip header.  * Only then can we do the check to see if 64 bits of packet  * data have been returned, since we need to check the returned  * ip header length.  */
end_comment

begin_define
define|#
directive|define
name|ICMP_MINLEN
value|8
end_define

begin_comment
comment|/* abs minimum */
end_comment

begin_define
define|#
directive|define
name|ICMP_TSLEN
value|(8 + 3 * sizeof (u_int32_t))
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|ICMP_MASKLEN
value|12
end_define

begin_comment
comment|/* address mask */
end_comment

begin_define
define|#
directive|define
name|ICMP_ADVLENMIN
value|(8 + sizeof (struct ip) + 8)
end_define

begin_comment
comment|/* min */
end_comment

begin_define
define|#
directive|define
name|ICMP_ADVLEN
parameter_list|(
name|p
parameter_list|)
value|(8 + (IP_HL(&(p)->icmp_ip)<< 2) + 8)
end_define

begin_comment
comment|/* N.B.: must separately check that ip_hl>= 5 */
end_comment

begin_comment
comment|/*  * Definition of type and code field values.  */
end_comment

begin_define
define|#
directive|define
name|ICMP_ECHOREPLY
value|0
end_define

begin_comment
comment|/* echo reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH
value|3
end_define

begin_comment
comment|/* dest unreachable, codes: */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET
value|0
end_define

begin_comment
comment|/* bad net */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST
value|1
end_define

begin_comment
comment|/* bad host */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_PROTOCOL
value|2
end_define

begin_comment
comment|/* bad protocol */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_PORT
value|3
end_define

begin_comment
comment|/* bad port */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_NEEDFRAG
value|4
end_define

begin_comment
comment|/* IP_DF caused drop */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_SRCFAIL
value|5
end_define

begin_comment
comment|/* src route failed */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET_UNKNOWN
value|6
end_define

begin_comment
comment|/* unknown net */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_UNKNOWN
value|7
end_define

begin_comment
comment|/* unknown host */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_ISOLATED
value|8
end_define

begin_comment
comment|/* src host isolated */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET_PROHIB
value|9
end_define

begin_comment
comment|/* prohibited access */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_PROHIB
value|10
end_define

begin_comment
comment|/* ditto */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSNET
value|11
end_define

begin_comment
comment|/* bad tos for net */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSHOST
value|12
end_define

begin_comment
comment|/* bad tos for host */
end_comment

begin_define
define|#
directive|define
name|ICMP_SOURCEQUENCH
value|4
end_define

begin_comment
comment|/* packet lost, slow down */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT
value|5
end_define

begin_comment
comment|/* shorter route, codes: */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_NET
value|0
end_define

begin_comment
comment|/* for network */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_HOST
value|1
end_define

begin_comment
comment|/* for host */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_TOSNET
value|2
end_define

begin_comment
comment|/* for tos and net */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIRECT_TOSHOST
value|3
end_define

begin_comment
comment|/* for tos and host */
end_comment

begin_define
define|#
directive|define
name|ICMP_ECHO
value|8
end_define

begin_comment
comment|/* echo service */
end_comment

begin_define
define|#
directive|define
name|ICMP_ROUTERADVERT
value|9
end_define

begin_comment
comment|/* router advertisement */
end_comment

begin_define
define|#
directive|define
name|ICMP_ROUTERSOLICIT
value|10
end_define

begin_comment
comment|/* router solicitation */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMXCEED
value|11
end_define

begin_comment
comment|/* time exceeded, code: */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_INTRANS
value|0
end_define

begin_comment
comment|/* ttl==0 in transit */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_REASS
value|1
end_define

begin_comment
comment|/* ttl==0 in reass */
end_comment

begin_define
define|#
directive|define
name|ICMP_PARAMPROB
value|12
end_define

begin_comment
comment|/* ip header bad */
end_comment

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_OPTABSENT
value|1
end_define

begin_comment
comment|/* req. opt. absent */
end_comment

begin_define
define|#
directive|define
name|ICMP_TSTAMP
value|13
end_define

begin_comment
comment|/* timestamp request */
end_comment

begin_define
define|#
directive|define
name|ICMP_TSTAMPREPLY
value|14
end_define

begin_comment
comment|/* timestamp reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_IREQ
value|15
end_define

begin_comment
comment|/* information request */
end_comment

begin_define
define|#
directive|define
name|ICMP_IREQREPLY
value|16
end_define

begin_comment
comment|/* information reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_MASKREQ
value|17
end_define

begin_comment
comment|/* address mask request */
end_comment

begin_define
define|#
directive|define
name|ICMP_MASKREPLY
value|18
end_define

begin_comment
comment|/* address mask reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_MAXTYPE
value|18
end_define

begin_define
define|#
directive|define
name|ICMP_INFOTYPE
parameter_list|(
name|type
parameter_list|)
define|\
value|((type) == ICMP_ECHOREPLY || (type) == ICMP_ECHO || \ 	(type) == ICMP_ROUTERADVERT || (type) == ICMP_ROUTERSOLICIT || \ 	(type) == ICMP_TSTAMP || (type) == ICMP_TSTAMPREPLY || \ 	(type) == ICMP_IREQ || (type) == ICMP_IREQREPLY || \ 	(type) == ICMP_MASKREQ || (type) == ICMP_MASKREPLY)
end_define

begin_comment
comment|/* rfc1700 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NET_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET_UNKNOWN
value|6
end_define

begin_comment
comment|/* destination net unknown */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_UNKNOWN
value|7
end_define

begin_comment
comment|/* destination host unknown */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_ISOLATED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_ISOLATED
value|8
end_define

begin_comment
comment|/* source host isolated */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NET_PROHIB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET_PROHIB
value|9
end_define

begin_comment
comment|/* admin prohibited net */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_PROHIB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_PROHIB
value|10
end_define

begin_comment
comment|/* admin prohibited host */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_TOSNET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSNET
value|11
end_define

begin_comment
comment|/* tos prohibited net */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_TOSHOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSHOST
value|12
end_define

begin_comment
comment|/* tos prohibited host */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rfc1716 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_FILTER_PROHIB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_FILTER_PROHIB
value|13
end_define

begin_comment
comment|/* admin prohibited filter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_PRECEDENCE
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_PRECEDENCE
value|14
end_define

begin_comment
comment|/* host precedence violation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_PRECEDENCE_CUTOFF
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_PRECEDENCE_CUTOFF
value|15
end_define

begin_comment
comment|/* precedence cutoff */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Most of the icmp types */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|tok
name|icmp2str
index|[]
init|=
block|{
block|{
name|ICMP_ECHOREPLY
block|,
literal|"echo reply"
block|}
block|,
block|{
name|ICMP_SOURCEQUENCH
block|,
literal|"source quench"
block|}
block|,
block|{
name|ICMP_ECHO
block|,
literal|"echo request"
block|}
block|,
block|{
name|ICMP_ROUTERSOLICIT
block|,
literal|"router solicitation"
block|}
block|,
block|{
name|ICMP_TSTAMP
block|,
literal|"time stamp request"
block|}
block|,
block|{
name|ICMP_TSTAMPREPLY
block|,
literal|"time stamp reply"
block|}
block|,
block|{
name|ICMP_IREQ
block|,
literal|"information request"
block|}
block|,
block|{
name|ICMP_IREQREPLY
block|,
literal|"information reply"
block|}
block|,
block|{
name|ICMP_MASKREQ
block|,
literal|"address mask request"
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
comment|/* Formats for most of the ICMP_UNREACH codes */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|tok
name|unreach2str
index|[]
init|=
block|{
block|{
name|ICMP_UNREACH_NET
block|,
literal|"net %s unreachable"
block|}
block|,
block|{
name|ICMP_UNREACH_HOST
block|,
literal|"host %s unreachable"
block|}
block|,
block|{
name|ICMP_UNREACH_SRCFAIL
block|,
literal|"%s unreachable - source route failed"
block|}
block|,
block|{
name|ICMP_UNREACH_NET_UNKNOWN
block|,
literal|"net %s unreachable - unknown"
block|}
block|,
block|{
name|ICMP_UNREACH_HOST_UNKNOWN
block|,
literal|"host %s unreachable - unknown"
block|}
block|,
block|{
name|ICMP_UNREACH_ISOLATED
block|,
literal|"%s unreachable - source host isolated"
block|}
block|,
block|{
name|ICMP_UNREACH_NET_PROHIB
block|,
literal|"net %s unreachable - admin prohibited"
block|}
block|,
block|{
name|ICMP_UNREACH_HOST_PROHIB
block|,
literal|"host %s unreachable - admin prohibited"
block|}
block|,
block|{
name|ICMP_UNREACH_TOSNET
block|,
literal|"net %s unreachable - tos prohibited"
block|}
block|,
block|{
name|ICMP_UNREACH_TOSHOST
block|,
literal|"host %s unreachable - tos prohibited"
block|}
block|,
block|{
name|ICMP_UNREACH_FILTER_PROHIB
block|,
literal|"host %s unreachable - admin prohibited filter"
block|}
block|,
block|{
name|ICMP_UNREACH_HOST_PRECEDENCE
block|,
literal|"host %s unreachable - host precedence violation"
block|}
block|,
block|{
name|ICMP_UNREACH_PRECEDENCE_CUTOFF
block|,
literal|"host %s unreachable - precedence cutoff"
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
comment|/* Formats for the ICMP_REDIRECT codes */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|tok
name|type2str
index|[]
init|=
block|{
block|{
name|ICMP_REDIRECT_NET
block|,
literal|"redirect %s to net %s"
block|}
block|,
block|{
name|ICMP_REDIRECT_HOST
block|,
literal|"redirect %s to host %s"
block|}
block|,
block|{
name|ICMP_REDIRECT_TOSNET
block|,
literal|"redirect-tos %s to net %s"
block|}
block|,
block|{
name|ICMP_REDIRECT_TOSHOST
block|,
literal|"redirect-tos %s to net %s"
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
comment|/* rfc1191 */
end_comment

begin_struct
struct|struct
name|mtu_discovery
block|{
name|u_int16_t
name|unused
decl_stmt|;
name|u_int16_t
name|nexthopmtu
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* rfc1256 */
end_comment

begin_struct
struct|struct
name|ih_rdiscovery
block|{
name|u_int8_t
name|ird_addrnum
decl_stmt|;
name|u_int8_t
name|ird_addrsiz
decl_stmt|;
name|u_int16_t
name|ird_lifetime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|id_rdiscovery
block|{
name|u_int32_t
name|ird_addr
decl_stmt|;
name|u_int32_t
name|ird_pref
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|icmp_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|plen
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp2
parameter_list|)
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
specifier|register
specifier|const
name|struct
name|icmp
modifier|*
name|dp
decl_stmt|;
specifier|register
specifier|const
name|struct
name|ip
modifier|*
name|ip
decl_stmt|;
specifier|register
specifier|const
name|char
modifier|*
name|str
decl_stmt|,
modifier|*
name|fmt
decl_stmt|;
specifier|register
specifier|const
name|struct
name|ip
modifier|*
name|oip
decl_stmt|;
specifier|register
specifier|const
name|struct
name|udphdr
modifier|*
name|ouh
decl_stmt|;
specifier|register
name|u_int
name|hlen
decl_stmt|,
name|dport
decl_stmt|,
name|mtu
decl_stmt|;
name|char
name|buf
index|[
name|MAXHOSTNAMELEN
operator|+
literal|100
index|]
decl_stmt|;
name|dp
operator|=
operator|(
expr|struct
name|icmp
operator|*
operator|)
name|bp
expr_stmt|;
name|ip
operator|=
operator|(
expr|struct
name|ip
operator|*
operator|)
name|bp2
expr_stmt|;
name|str
operator|=
name|buf
expr_stmt|;
if|#
directive|if
literal|0
block|(void)printf("%s> %s: ", 		ipaddr_string(&ip->ip_src), 		ipaddr_string(&ip->ip_dst));
endif|#
directive|endif
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_code
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|dp
operator|->
name|icmp_type
condition|)
block|{
case|case
name|ICMP_UNREACH
case|:
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_dst
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|dp
operator|->
name|icmp_code
condition|)
block|{
case|case
name|ICMP_UNREACH_PROTOCOL
case|:
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_p
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s protocol %d unreachable"
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_dst
argument_list|)
argument_list|,
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_p
argument_list|)
expr_stmt|;
break|break;
case|case
name|ICMP_UNREACH_PORT
case|:
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_p
argument_list|)
expr_stmt|;
name|oip
operator|=
operator|&
name|dp
operator|->
name|icmp_ip
expr_stmt|;
name|hlen
operator|=
name|IP_HL
argument_list|(
name|oip
argument_list|)
operator|*
literal|4
expr_stmt|;
name|ouh
operator|=
operator|(
expr|struct
name|udphdr
operator|*
operator|)
operator|(
operator|(
operator|(
name|u_char
operator|*
operator|)
name|oip
operator|)
operator|+
name|hlen
operator|)
expr_stmt|;
name|dport
operator|=
name|ntohs
argument_list|(
name|ouh
operator|->
name|uh_dport
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|oip
operator|->
name|ip_p
condition|)
block|{
case|case
name|IPPROTO_TCP
case|:
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s tcp port %s unreachable"
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|oip
operator|->
name|ip_dst
argument_list|)
argument_list|,
name|tcpport_string
argument_list|(
name|dport
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPPROTO_UDP
case|:
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s udp port %s unreachable"
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|oip
operator|->
name|ip_dst
argument_list|)
argument_list|,
name|udpport_string
argument_list|(
name|dport
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s protocol %d port %d unreachable"
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|oip
operator|->
name|ip_dst
argument_list|)
argument_list|,
name|oip
operator|->
name|ip_p
argument_list|,
name|dport
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|ICMP_UNREACH_NEEDFRAG
case|:
block|{
specifier|register
specifier|const
name|struct
name|mtu_discovery
modifier|*
name|mp
decl_stmt|;
name|mp
operator|=
operator|(
expr|struct
name|mtu_discovery
operator|*
operator|)
operator|&
name|dp
operator|->
name|icmp_void
expr_stmt|;
name|mtu
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|mp
operator|->
name|nexthopmtu
argument_list|)
expr_stmt|;
if|if
condition|(
name|mtu
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s unreachable - need to frag (mtu %d)"
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_dst
argument_list|)
argument_list|,
name|mtu
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s unreachable - need to frag"
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_dst
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
default|default:
name|fmt
operator|=
name|tok2str
argument_list|(
name|unreach2str
argument_list|,
literal|"#%d %%s unreachable"
argument_list|,
name|dp
operator|->
name|icmp_code
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|fmt
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_dst
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|ICMP_REDIRECT
case|:
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_dst
argument_list|)
expr_stmt|;
name|fmt
operator|=
name|tok2str
argument_list|(
name|type2str
argument_list|,
literal|"redirect-#%d %%s to net %%s"
argument_list|,
name|dp
operator|->
name|icmp_code
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|fmt
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_dst
argument_list|)
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|dp
operator|->
name|icmp_gwaddr
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ICMP_ROUTERADVERT
case|:
block|{
specifier|register
specifier|const
name|struct
name|ih_rdiscovery
modifier|*
name|ihp
decl_stmt|;
specifier|register
specifier|const
name|struct
name|id_rdiscovery
modifier|*
name|idp
decl_stmt|;
name|u_int
name|lifetime
decl_stmt|,
name|num
decl_stmt|,
name|size
decl_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"router advertisement"
argument_list|)
expr_stmt|;
name|cp
operator|=
name|buf
operator|+
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|ihp
operator|=
operator|(
expr|struct
name|ih_rdiscovery
operator|*
operator|)
operator|&
name|dp
operator|->
name|icmp_void
expr_stmt|;
name|TCHECK
argument_list|(
operator|*
name|ihp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|cp
argument_list|,
literal|" lifetime "
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
operator|(
name|cp
operator|-
name|buf
operator|)
argument_list|)
expr_stmt|;
name|cp
operator|=
name|buf
operator|+
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|lifetime
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|ihp
operator|->
name|ird_lifetime
argument_list|)
expr_stmt|;
if|if
condition|(
name|lifetime
operator|<
literal|60
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|cp
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
operator|(
name|cp
operator|-
name|buf
operator|)
argument_list|,
literal|"%u"
argument_list|,
name|lifetime
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|lifetime
operator|<
literal|60
operator|*
literal|60
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|cp
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
operator|(
name|cp
operator|-
name|buf
operator|)
argument_list|,
literal|"%u:%02u"
argument_list|,
name|lifetime
operator|/
literal|60
argument_list|,
name|lifetime
operator|%
literal|60
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|cp
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
operator|(
name|cp
operator|-
name|buf
operator|)
argument_list|,
literal|"%u:%02u:%02u"
argument_list|,
name|lifetime
operator|/
literal|3600
argument_list|,
operator|(
name|lifetime
operator|%
literal|3600
operator|)
operator|/
literal|60
argument_list|,
name|lifetime
operator|%
literal|60
argument_list|)
expr_stmt|;
block|}
name|cp
operator|=
name|buf
operator|+
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|num
operator|=
name|ihp
operator|->
name|ird_addrnum
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|cp
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
operator|(
name|cp
operator|-
name|buf
operator|)
argument_list|,
literal|" %d:"
argument_list|,
name|num
argument_list|)
expr_stmt|;
name|cp
operator|=
name|buf
operator|+
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|size
operator|=
name|ihp
operator|->
name|ird_addrsiz
expr_stmt|;
if|if
condition|(
name|size
operator|!=
literal|2
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|cp
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
operator|(
name|cp
operator|-
name|buf
operator|)
argument_list|,
literal|" [size %d]"
argument_list|,
name|size
argument_list|)
expr_stmt|;
break|break;
block|}
name|idp
operator|=
operator|(
expr|struct
name|id_rdiscovery
operator|*
operator|)
operator|&
name|dp
operator|->
name|icmp_data
expr_stmt|;
while|while
condition|(
name|num
operator|--
operator|>
literal|0
condition|)
block|{
name|TCHECK
argument_list|(
operator|*
name|idp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|cp
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
operator|(
name|cp
operator|-
name|buf
operator|)
argument_list|,
literal|" {%s %u}"
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|idp
operator|->
name|ird_addr
argument_list|)
argument_list|,
name|EXTRACT_32BITS
argument_list|(
operator|&
name|idp
operator|->
name|ird_pref
argument_list|)
argument_list|)
expr_stmt|;
name|cp
operator|=
name|buf
operator|+
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
operator|++
name|idp
expr_stmt|;
block|}
block|}
break|break;
case|case
name|ICMP_TIMXCEED
case|:
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_ip
operator|.
name|ip_dst
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|dp
operator|->
name|icmp_code
condition|)
block|{
case|case
name|ICMP_TIMXCEED_INTRANS
case|:
name|str
operator|=
literal|"time exceeded in-transit"
expr_stmt|;
break|break;
case|case
name|ICMP_TIMXCEED_REASS
case|:
name|str
operator|=
literal|"ip reassembly time exceeded"
expr_stmt|;
break|break;
default|default:
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"time exceeded-#%d"
argument_list|,
name|dp
operator|->
name|icmp_code
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|ICMP_PARAMPROB
case|:
if|if
condition|(
name|dp
operator|->
name|icmp_code
condition|)
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"parameter problem - code %d"
argument_list|,
name|dp
operator|->
name|icmp_code
argument_list|)
expr_stmt|;
else|else
block|{
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_pptr
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"parameter problem - octet %d"
argument_list|,
name|dp
operator|->
name|icmp_pptr
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|ICMP_MASKREPLY
case|:
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_mask
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"address mask is 0x%08x"
argument_list|,
operator|(
name|unsigned
operator|)
name|ntohl
argument_list|(
name|dp
operator|->
name|icmp_mask
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ICMP_TSTAMP
case|:
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_seq
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"time stamp query id %u seq %u"
argument_list|,
operator|(
name|unsigned
operator|)
name|ntohs
argument_list|(
name|dp
operator|->
name|icmp_id
argument_list|)
argument_list|,
operator|(
name|unsigned
operator|)
name|ntohs
argument_list|(
name|dp
operator|->
name|icmp_seq
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ICMP_TSTAMPREPLY
case|:
name|TCHECK
argument_list|(
name|dp
operator|->
name|icmp_ttime
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"time stamp reply id %u seq %u : org 0x%lx recv 0x%lx xmit 0x%lx"
argument_list|,
operator|(
name|unsigned
operator|)
name|ntohs
argument_list|(
name|dp
operator|->
name|icmp_id
argument_list|)
argument_list|,
operator|(
name|unsigned
operator|)
name|ntohs
argument_list|(
name|dp
operator|->
name|icmp_seq
argument_list|)
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|ntohl
argument_list|(
name|dp
operator|->
name|icmp_otime
argument_list|)
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|ntohl
argument_list|(
name|dp
operator|->
name|icmp_rtime
argument_list|)
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|ntohl
argument_list|(
name|dp
operator|->
name|icmp_ttime
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|str
operator|=
name|tok2str
argument_list|(
name|icmp2str
argument_list|,
literal|"type-#%d"
argument_list|,
name|dp
operator|->
name|icmp_type
argument_list|)
expr_stmt|;
break|break;
block|}
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"icmp: %s"
argument_list|,
name|str
argument_list|)
expr_stmt|;
if|if
condition|(
name|vflag
condition|)
block|{
if|if
condition|(
name|TTEST2
argument_list|(
operator|*
name|bp
argument_list|,
name|plen
argument_list|)
condition|)
block|{
if|if
condition|(
name|in_cksum
argument_list|(
operator|(
name|u_short
operator|*
operator|)
name|dp
argument_list|,
name|plen
argument_list|,
literal|0
argument_list|)
condition|)
name|printf
argument_list|(
literal|" (wrong icmp csum)"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|vflag
operator|>
literal|1
operator|&&
operator|!
name|ICMP_INFOTYPE
argument_list|(
name|dp
operator|->
name|icmp_type
argument_list|)
condition|)
block|{
name|bp
operator|+=
literal|8
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" for "
argument_list|)
expr_stmt|;
name|ip
operator|=
operator|(
expr|struct
name|ip
operator|*
operator|)
name|bp
expr_stmt|;
name|snaplen
operator|=
name|snapend
operator|-
name|bp
expr_stmt|;
name|ip_print
argument_list|(
name|bp
argument_list|,
name|ntohs
argument_list|(
name|ip
operator|->
name|ip_len
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return;
name|trunc
label|:
name|fputs
argument_list|(
literal|"[|icmp]"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

