begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"@(#) $Header: print-pim.c,v 1.6 96/07/23 14:17:26 leres Exp $ (LBL)"
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

begin_include
include|#
directive|include
file|<netinet/tcpip.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
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

begin_function
name|void
name|pim_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
specifier|register
name|u_int
name|len
parameter_list|)
block|{
specifier|register
specifier|const
name|u_char
modifier|*
name|ep
decl_stmt|;
specifier|register
name|u_char
name|type
decl_stmt|;
name|ep
operator|=
operator|(
specifier|const
name|u_char
operator|*
operator|)
name|snapend
expr_stmt|;
if|if
condition|(
name|bp
operator|>=
name|ep
condition|)
return|return;
name|type
operator|=
name|bp
index|[
literal|1
index|]
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
literal|0
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" Query"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" Register"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" Register-Stop"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" Join/Prune"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|4
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" RP-reachable"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|5
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" Assert"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|6
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" Graft"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|7
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" Graft-ACK"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|8
case|:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" Mode"
argument_list|)
expr_stmt|;
break|break;
default|default:
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" [type %d]"
argument_list|,
name|type
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

end_unit

