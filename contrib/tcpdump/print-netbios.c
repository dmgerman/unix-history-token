begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Format and print NETBIOS packets.  * Contributed by Brad Parker (brad@fcr.com).  */
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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-netbios.c,v 1.17 2000/09/29 04:58:43 guy Exp $"
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
file|<stdlib.h>
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
file|"netbios.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_comment
comment|/*  * Print NETBIOS packets.  */
end_comment

begin_function
name|void
name|netbios_print
parameter_list|(
name|struct
name|p8022Hdr
modifier|*
name|nb
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
if|if
condition|(
name|length
operator|<
name|p8022Size
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" truncated-netbios %d"
argument_list|,
name|length
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|nb
operator|->
name|flags
operator|==
name|UI
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"802.1 UI "
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"802.1 CONN "
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|u_char
operator|*
operator|)
operator|(
name|nb
operator|+
literal|1
operator|)
operator|>
name|snapend
condition|)
block|{
name|printf
argument_list|(
literal|" [|netbios]"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	netbios_decode(nb, (u_char *)nb + p8022Size, length - p8022Size); */
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|never
end_ifdef

begin_expr_stmt
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s.%d> "
argument_list|,
name|ipxaddr_string
argument_list|(
name|EXTRACT_32BITS
argument_list|(
name|ipx
operator|->
name|srcNet
argument_list|)
argument_list|,
name|ipx
operator|->
name|srcNode
argument_list|)
argument_list|,
name|EXTRACT_16BITS
argument_list|(
name|ipx
operator|->
name|srcSkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s.%d:"
argument_list|,
name|ipxaddr_string
argument_list|(
name|EXTRACT_32BITS
argument_list|(
name|ipx
operator|->
name|dstNet
argument_list|)
argument_list|,
name|ipx
operator|->
name|dstNode
argument_list|)
argument_list|,
name|EXTRACT_16BITS
argument_list|(
name|ipx
operator|->
name|dstSkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|(
name|u_char
operator|*
operator|)
operator|(
name|ipx
operator|+
literal|1
operator|)
operator|>
name|snapend
condition|)
block|{
name|printf
argument_list|(
literal|" [|ipx]"
argument_list|)
expr_stmt|;
return|return;
block|}
end_if

begin_comment
comment|/* take length from ipx header */
end_comment

begin_expr_stmt
name|length
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|ipx
operator|->
name|length
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ipx_decode
argument_list|(
name|ipx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
name|ipx
operator|+
name|ipxSize
argument_list|,
name|length
operator|-
name|ipxSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

