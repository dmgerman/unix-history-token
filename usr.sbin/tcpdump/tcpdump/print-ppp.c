begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)$FreeBSD$ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PPP
end_ifdef

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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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
file|<signal.h>
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

begin_comment
comment|/* XXX This goes somewhere else. */
end_comment

begin_define
define|#
directive|define
name|PPP_HDRLEN
value|4
end_define

begin_function
name|void
name|ppp_if_print
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
specifier|register
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
specifier|register
name|int
name|length
init|=
name|h
operator|->
name|len
decl_stmt|;
specifier|register
name|int
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
name|ts_print
argument_list|(
operator|&
name|h
operator|->
name|ts
argument_list|)
expr_stmt|;
if|if
condition|(
name|caplen
operator|<
name|PPP_HDRLEN
condition|)
block|{
name|printf
argument_list|(
literal|"[|ppp]"
argument_list|)
expr_stmt|;
goto|goto
name|out
goto|;
block|}
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
if|if
condition|(
name|eflag
condition|)
name|printf
argument_list|(
literal|"%c %4d %02x %04x: "
argument_list|,
name|p
index|[
literal|0
index|]
condition|?
literal|'O'
else|:
literal|'I'
argument_list|,
name|length
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|,
name|ntohs
argument_list|(
operator|*
operator|(
name|u_short
operator|*
operator|)
operator|&
name|p
index|[
literal|2
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|length
operator|-=
name|PPP_HDRLEN
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
name|PPP_HDRLEN
operator|)
expr_stmt|;
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
name|PPP_HDRLEN
argument_list|)
expr_stmt|;
name|out
label|:
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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

begin_function
name|void
name|ppp_if_print
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
name|error
argument_list|(
literal|"not configured for ppp"
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

