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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_if

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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-vjc.c,v 1.2.2.1 2000/01/11 06:58:28 fenner Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

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
file|<netinet/if_ether.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<net/ppp_defs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<net/if_ppp.h>
end_include

begin_include
include|#
directive|include
file|<net/slcompress.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
specifier|register
name|u_int
name|length
parameter_list|,
name|u_short
name|proto
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__bsdi__) || defined(__NetBSD__) */
end_comment

end_unit

