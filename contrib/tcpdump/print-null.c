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
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-null.c,v 1.40 2000/12/16 22:00:50 guy Exp $ (LBL)"
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

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|AF_NS
end_ifndef

begin_define
define|#
directive|define
name|AF_NS
value|6
end_define

begin_comment
comment|/* XEROX NS protocols */
end_comment

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
name|AF_INET
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
name|AF_INET6
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
name|AF_NS
case|:
name|printf
argument_list|(
literal|"ns "
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

begin_function
name|void
name|null_if_print
parameter_list|(
name|u_char
modifier|*
name|user
parameter_list|,
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
specifier|const
name|struct
name|ip
modifier|*
name|ip
decl_stmt|;
name|u_int
name|family
decl_stmt|;
name|ts_print
argument_list|(
operator|&
name|h
operator|->
name|ts
argument_list|)
expr_stmt|;
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
comment|/* 	 * Some printers want to get back at the link level addresses, 	 * and/or check that they're not walking off the end of the packet. 	 * Rather than pass them all the way down, we set these globals. 	 */
name|packetp
operator|=
name|p
expr_stmt|;
name|snapend
operator|=
name|p
operator|+
name|caplen
expr_stmt|;
name|length
operator|-=
name|NULL_HDRLEN
expr_stmt|;
name|ip
operator|=
operator|(
expr|struct
name|ip
operator|*
operator|)
operator|(
name|p
operator|+
name|NULL_HDRLEN
operator|)
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
name|IP_V
argument_list|(
name|ip
argument_list|)
condition|)
block|{
case|case
literal|4
case|:
name|ip_print
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
name|ip
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|INET6
case|case
literal|6
case|:
name|ip6_print
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
name|ip
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
default|default:
name|printf
argument_list|(
literal|"ip v%d"
argument_list|,
name|IP_V
argument_list|(
name|ip
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|xflag
condition|)
name|default_print
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
name|ip
argument_list|,
name|caplen
operator|-
name|NULL_HDRLEN
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

