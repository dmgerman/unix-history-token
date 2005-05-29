begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
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
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-null.c,v 1.53 2005/04/06 21:32:41 mcr Exp $ (LBL)"
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
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|<pcap.h>
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
file|"ip.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_include
include|#
directive|include
file|"ip6.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The DLT_NULL packet header is 4 bytes long. It contains a host-byte-order  * 32-bit integer that specifies the family, e.g. AF_INET.  *  * Note here that "host" refers to the host on which the packets were  * captured; that isn't necessarily *this* host.  *  * The OpenBSD DLT_LOOP packet header is the same, except that the integer  * is in network byte order.  */
end_comment

begin_define
define|#
directive|define
name|NULL_HDRLEN
value|4
end_define

begin_comment
comment|/*  * BSD AF_ values.  *  * Unfortunately, the BSDs don't all use the same value for AF_INET6,  * so, because we want to be able to read captures from all of the BSDs,  * we check for all of them.  */
end_comment

begin_define
define|#
directive|define
name|BSD_AF_INET
value|2
end_define

begin_define
define|#
directive|define
name|BSD_AF_NS
value|6
end_define

begin_comment
comment|/* XEROX NS protocols */
end_comment

begin_define
define|#
directive|define
name|BSD_AF_ISO
value|7
end_define

begin_define
define|#
directive|define
name|BSD_AF_APPLETALK
value|16
end_define

begin_define
define|#
directive|define
name|BSD_AF_IPX
value|23
end_define

begin_define
define|#
directive|define
name|BSD_AF_INET6_BSD
value|24
end_define

begin_comment
comment|/* OpenBSD (and probably NetBSD), BSD/OS */
end_comment

begin_define
define|#
directive|define
name|BSD_AF_INET6_FREEBSD
value|28
end_define

begin_define
define|#
directive|define
name|BSD_AF_INET6_DARWIN
value|30
end_define

begin_function
specifier|static
name|void
name|null_print
parameter_list|(
name|u_int
name|family
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
if|if
condition|(
name|nflag
condition|)
name|printf
argument_list|(
literal|"AF %u "
argument_list|,
name|family
argument_list|)
expr_stmt|;
else|else
block|{
switch|switch
condition|(
name|family
condition|)
block|{
case|case
name|BSD_AF_INET
case|:
name|printf
argument_list|(
literal|"ip "
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|INET6
case|case
name|BSD_AF_INET6_BSD
case|:
case|case
name|BSD_AF_INET6_FREEBSD
case|:
case|case
name|BSD_AF_INET6_DARWIN
case|:
name|printf
argument_list|(
literal|"ip6 "
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|BSD_AF_NS
case|:
name|printf
argument_list|(
literal|"ns "
argument_list|)
expr_stmt|;
break|break;
case|case
name|BSD_AF_ISO
case|:
name|printf
argument_list|(
literal|"osi "
argument_list|)
expr_stmt|;
break|break;
case|case
name|BSD_AF_APPLETALK
case|:
name|printf
argument_list|(
literal|"atalk "
argument_list|)
expr_stmt|;
break|break;
case|case
name|BSD_AF_IPX
case|:
name|printf
argument_list|(
literal|"ipx "
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"AF %u "
argument_list|,
name|family
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|printf
argument_list|(
literal|"%d: "
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Byte-swap a 32-bit number.  * ("htonl()" or "ntohl()" won't work - we want to byte-swap even on  * big-endian platforms.)  */
end_comment

begin_define
define|#
directive|define
name|SWAPLONG
parameter_list|(
name|y
parameter_list|)
define|\
value|((((y)&0xff)<<24) | (((y)&0xff00)<<8) | (((y)&0xff0000)>>8) | (((y)>>24)&0xff))
end_define

begin_comment
comment|/*  * This is the top level routine of the printer.  'p' points  * to the ether header of the packet, 'h->ts' is the timestamp,  * 'h->len' is the length of the packet off the wire, and 'h->caplen'  * is the number of bytes actually captured.  */
end_comment

begin_function
name|u_int
name|null_if_print
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
name|u_int
name|length
init|=
name|h
operator|->
name|len
decl_stmt|;
name|u_int
name|caplen
init|=
name|h
operator|->
name|caplen
decl_stmt|;
name|u_int
name|family
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
name|NULL_HDRLEN
condition|)
block|{
name|printf
argument_list|(
literal|"[|null]"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL_HDRLEN
operator|)
return|;
block|}
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|family
argument_list|,
operator|(
name|char
operator|*
operator|)
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|family
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * This isn't necessarily in our host byte order; if this is 	 * a DLT_LOOP capture, it's in network byte order, and if 	 * this is a DLT_NULL capture from a machine with the opposite 	 * byte-order, it's in the opposite byte order from ours. 	 * 	 * If the upper 16 bits aren't all zero, assume it's byte-swapped. 	 */
if|if
condition|(
operator|(
name|family
operator|&
literal|0xFFFF0000
operator|)
operator|!=
literal|0
condition|)
name|family
operator|=
name|SWAPLONG
argument_list|(
name|family
argument_list|)
expr_stmt|;
name|length
operator|-=
name|NULL_HDRLEN
expr_stmt|;
name|caplen
operator|-=
name|NULL_HDRLEN
expr_stmt|;
name|p
operator|+=
name|NULL_HDRLEN
expr_stmt|;
if|if
condition|(
name|eflag
condition|)
name|null_print
argument_list|(
name|family
argument_list|,
name|length
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|family
condition|)
block|{
case|case
name|BSD_AF_INET
case|:
name|ip_print
argument_list|(
name|gndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|INET6
case|case
name|BSD_AF_INET6_BSD
case|:
case|case
name|BSD_AF_INET6_FREEBSD
case|:
case|case
name|BSD_AF_INET6_DARWIN
case|:
name|ip6_print
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|BSD_AF_ISO
case|:
name|isoclns_print
argument_list|(
name|p
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|)
expr_stmt|;
break|break;
case|case
name|BSD_AF_APPLETALK
case|:
name|atalk_print
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
case|case
name|BSD_AF_IPX
case|:
name|ipx_print
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* unknown AF_ value */
if|if
condition|(
operator|!
name|eflag
condition|)
name|null_print
argument_list|(
name|family
argument_list|,
name|length
operator|+
name|NULL_HDRLEN
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|xflag
operator|&&
operator|!
name|qflag
condition|)
name|default_print
argument_list|(
name|p
argument_list|,
name|caplen
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|NULL_HDRLEN
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Local Variables:  * c-style: whitesmith  * c-basic-offset: 8  * End:  */
end_comment

end_unit

