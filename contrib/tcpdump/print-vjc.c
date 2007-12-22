begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-vjc.c,v 1.15 2004/03/25 03:31:17 mcr Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

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
file|"slcompress.h"
end_include

begin_include
include|#
directive|include
file|"ppp.h"
end_include

begin_comment
comment|/*  * XXX - for BSD/OS PPP, what packets get supplied with a PPP header type  * of PPP_VJC and what packets get supplied with a PPP header type of  * PPP_VJNC?  PPP_VJNC is for "UNCOMPRESSED_TCP" packets, and PPP_VJC  * is for COMPRESSED_TCP packets (PPP_IP is used for TYPE_IP packets).  *  * RFC 1144 implies that, on the wire, the packet type is *not* needed  * for PPP, as different PPP protocol types can be used; it only needs  * to be put on the wire for SLIP.  *  * It also indicates that, for compressed SLIP:  *  *	If the COMPRESSED_TCP bit is set in the first byte, it's  *	a COMPRESSED_TCP packet; that byte is the change byte, and  *	the COMPRESSED_TCP bit, 0x80, isn't used in the change byte.  *  *	If the upper 4 bits of the first byte are 7, it's an  *	UNCOMPRESSED_TCP packet; that byte is the first byte of  *	the UNCOMPRESSED_TCP modified IP header, with a connection  *	number in the protocol field, and with the version field  *	being 7, not 4.  *  *	Otherwise, the packet is an IPv4 packet (where the upper 4 bits  *	of the packet are 4).  *  * So this routine looks as if it's sort-of intended to handle  * compressed SLIP, although it doesn't handle UNCOMPRESSED_TCP  * correctly for that (it doesn't fix the version number and doesn't  * do anything to the protocol field), and doesn't check for COMPRESSED_TCP  * packets correctly for that (you only check the first bit - see  * B.1 in RFC 1144).  *  * But it's called for BSD/OS PPP, not SLIP - perhaps BSD/OS does weird  * things with the headers?  *  * Without a BSD/OS VJC-compressed PPP trace, or knowledge of what the  * BSD/OS VJC code does, we can't say what's the case.  *  * We therefore leave "proto" - which is the PPP protocol type - in place,  * *not* marked as unused, for now, so that GCC warnings about the  * unused argument remind us that we should fix this some day.  */
end_comment

begin_function
name|int
name|vjc_print
parameter_list|(
specifier|register
specifier|const
name|char
modifier|*
name|bp
parameter_list|,
name|u_short
name|proto
name|_U_
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
switch|switch
condition|(
name|bp
index|[
literal|0
index|]
operator|&
literal|0xf0
condition|)
block|{
case|case
name|TYPE_IP
case|:
if|if
condition|(
name|eflag
condition|)
name|printf
argument_list|(
literal|"(vjc type=IP) "
argument_list|)
expr_stmt|;
return|return
name|PPP_IP
return|;
case|case
name|TYPE_UNCOMPRESSED_TCP
case|:
if|if
condition|(
name|eflag
condition|)
name|printf
argument_list|(
literal|"(vjc type=raw TCP) "
argument_list|)
expr_stmt|;
return|return
name|PPP_IP
return|;
case|case
name|TYPE_COMPRESSED_TCP
case|:
if|if
condition|(
name|eflag
condition|)
name|printf
argument_list|(
literal|"(vjc type=compressed TCP) "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|bp
index|[
literal|1
index|]
operator|&
operator|(
literal|0x80
operator|>>
name|i
operator|)
condition|)
name|printf
argument_list|(
literal|"%c"
argument_list|,
literal|"?CI?SAWU"
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|bp
index|[
literal|1
index|]
condition|)
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"C=0x%02x "
argument_list|,
name|bp
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sum=0x%04x "
argument_list|,
operator|*
operator|(
name|u_short
operator|*
operator|)
operator|&
name|bp
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
case|case
name|TYPE_ERROR
case|:
if|if
condition|(
name|eflag
condition|)
name|printf
argument_list|(
literal|"(vjc type=error) "
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
default|default:
if|if
condition|(
name|eflag
condition|)
name|printf
argument_list|(
literal|"(vjc type=0x%02x) "
argument_list|,
name|bp
index|[
literal|0
index|]
operator|&
literal|0xf0
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
end_function

end_unit

