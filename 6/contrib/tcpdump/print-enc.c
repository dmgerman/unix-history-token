begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: print-enc.c,v 1.7 2002/02/19 19:39:40 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-enc.c,v 1.4 2005/04/06 21:32:39 mcr Exp $ (LBL)"
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
file|"enc.h"
end_include

begin_define
define|#
directive|define
name|ENC_PRINT_TYPE
parameter_list|(
name|wh
parameter_list|,
name|xf
parameter_list|,
name|nam
parameter_list|)
define|\
value|if ((wh)& (xf)) { \ 		printf("%s%s", nam, (wh) == (xf) ? "): " : ","); \ 		(wh)&= ~(xf); \ 	}
end_define

begin_function
name|u_int
name|enc_if_print
parameter_list|(
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
name|u_int
name|length
init|=
name|h
operator|->
name|len
decl_stmt|;
specifier|register
name|u_int
name|caplen
init|=
name|h
operator|->
name|caplen
decl_stmt|;
name|int
name|flags
decl_stmt|;
specifier|const
name|struct
name|enchdr
modifier|*
name|hdr
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
name|ENC_HDRLEN
condition|)
block|{
name|printf
argument_list|(
literal|"[|enc]"
argument_list|)
expr_stmt|;
goto|goto
name|out
goto|;
block|}
name|hdr
operator|=
operator|(
expr|struct
name|enchdr
operator|*
operator|)
name|p
expr_stmt|;
name|flags
operator|=
name|hdr
operator|->
name|flags
expr_stmt|;
if|if
condition|(
name|flags
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"(unprotected): "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"("
argument_list|)
expr_stmt|;
name|ENC_PRINT_TYPE
argument_list|(
name|flags
argument_list|,
name|M_AUTH
argument_list|,
literal|"authentic"
argument_list|)
expr_stmt|;
name|ENC_PRINT_TYPE
argument_list|(
name|flags
argument_list|,
name|M_CONF
argument_list|,
literal|"confidential"
argument_list|)
expr_stmt|;
comment|/* ENC_PRINT_TYPE(flags, M_TUNNEL, "tunnel"); */
name|printf
argument_list|(
literal|"SPI 0x%08x: "
argument_list|,
operator|(
name|u_int32_t
operator|)
name|ntohl
argument_list|(
name|hdr
operator|->
name|spi
argument_list|)
argument_list|)
expr_stmt|;
name|length
operator|-=
name|ENC_HDRLEN
expr_stmt|;
comment|/* XXX - use the address family */
name|ip_print
argument_list|(
name|gndo
argument_list|,
name|p
operator|+
name|ENC_HDRLEN
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|out
label|:
return|return
operator|(
name|ENC_HDRLEN
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Local Variables:  * c-style: whitesmith  * c-basic-offset: 8  * End:  */
end_comment

end_unit

