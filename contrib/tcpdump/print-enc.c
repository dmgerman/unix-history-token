begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: print-enc.c,v 1.7 2002/02/19 19:39:40 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_define
define|#
directive|define
name|NETDISSECT_REWORKED
end_define

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
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_comment
comment|/* From $OpenBSD: if_enc.h,v 1.8 2001/06/25 05:14:00 angelos Exp $ */
end_comment

begin_comment
comment|/*  * The authors of this code are John Ioannidis (ji@tla.org),  * Angelos D. Keromytis (kermit@csd.uch.gr) and  * Niels Provos (provos@physnet.uni-hamburg.de).  *  * This code was written by John Ioannidis for BSD/OS in Athens, Greece,  * in November 1995.  *  * Ported to OpenBSD and NetBSD, with additional transforms, in December 1996,  * by Angelos D. Keromytis.  *  * Additional transforms and features in 1997 and 1998 by Angelos D. Keromytis  * and Niels Provos.  *  * Copyright (C) 1995, 1996, 1997, 1998 by John Ioannidis, Angelos D. Keromytis  * and Niels Provos.  * Copyright (c) 2001, Angelos D. Keromytis.  *  * Permission to use, copy, and modify this software with or without fee  * is hereby granted, provided that this entire notice is included in  * all copies of any software which is or includes a copy or  * modification of this software.  * You may use this code under the GNU public license if you so wish. Please  * contribute changes back to the authors under this freer than GPL license  * so that we may further the use of strong encryption without limitations to  * all.  *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_define
define|#
directive|define
name|ENC_HDRLEN
value|12
end_define

begin_comment
comment|/* From $OpenBSD: mbuf.h,v 1.56 2002/01/25 15:50:23 art Exp $	*/
end_comment

begin_define
define|#
directive|define
name|M_CONF
value|0x0400
end_define

begin_comment
comment|/* packet was encrypted (ESP-transport) */
end_comment

begin_define
define|#
directive|define
name|M_AUTH
value|0x0800
end_define

begin_comment
comment|/* packet was authenticated (AH) */
end_comment

begin_struct
struct|struct
name|enchdr
block|{
name|uint32_t
name|af
decl_stmt|;
name|uint32_t
name|spi
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

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
value|if ((wh)& (xf)) { \ 		ND_PRINT((ndo, "%s%s", nam, (wh) == (xf) ? "): " : ",")); \ 		(wh)&= ~(xf); \ 	}
end_define

begin_function
name|u_int
name|enc_if_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
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
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"[|enc]"
operator|)
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
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"(unprotected): "
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"("
operator|)
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
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"SPI 0x%08x: "
operator|,
name|EXTRACT_32BITS
argument_list|(
operator|&
name|hdr
operator|->
name|spi
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|length
operator|-=
name|ENC_HDRLEN
expr_stmt|;
name|caplen
operator|-=
name|ENC_HDRLEN
expr_stmt|;
name|p
operator|+=
name|ENC_HDRLEN
expr_stmt|;
switch|switch
condition|(
name|hdr
operator|->
name|af
condition|)
block|{
case|case
name|AF_INET
case|:
name|ip_print
argument_list|(
name|ndo
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
name|AF_INET6
case|:
name|ip6_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/*INET6*/
block|}
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

