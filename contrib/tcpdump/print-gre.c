begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996  *      The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Lawrence Berkeley Laboratory,  * Berkeley, CA.  The name of the University may not be used to  * endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Initial contribution from John Hawkinson<jhawk@bbnplanet.com>  *  * This module implements support for decoding GRE (Generic Routing  * Encapsulation) tunnels; they're documented in RFC1701 and RFC1702.  * This code only supports the IP encapsulation thereof.  */
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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-gre.c,v 1.13 2001/06/15 22:17:31 fenner Exp $"
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
file|<sys/uio.h>
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
file|<netdb.h>
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
file|"extract.h"
end_include

begin_comment
comment|/* must come after interface.h */
end_comment

begin_struct
struct|struct
name|gre
block|{
name|u_int16_t
name|flags
decl_stmt|;
name|u_int16_t
name|proto
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RFC 2784 - GRE */
end_comment

begin_define
define|#
directive|define
name|GRE_CP
value|0x8000
end_define

begin_comment
comment|/* Checksum Present */
end_comment

begin_define
define|#
directive|define
name|GRE_VER_MASK
value|0x0007
end_define

begin_comment
comment|/* Version */
end_comment

begin_comment
comment|/* RFC 2890 - Key and Sequence extensions to GRE */
end_comment

begin_define
define|#
directive|define
name|GRE_KP
value|0x2000
end_define

begin_comment
comment|/* Key Present */
end_comment

begin_define
define|#
directive|define
name|GRE_SP
value|0x1000
end_define

begin_comment
comment|/* Sequence Present */
end_comment

begin_comment
comment|/* Legacy from RFC 1700 */
end_comment

begin_define
define|#
directive|define
name|GRE_RP
value|0x4000
end_define

begin_comment
comment|/* Routing Present */
end_comment

begin_define
define|#
directive|define
name|GRE_sP
value|0x0800
end_define

begin_comment
comment|/* strict source route present */
end_comment

begin_define
define|#
directive|define
name|GRE_RECUR_MASK
value|0x0700
end_define

begin_comment
comment|/* Recursion Control */
end_comment

begin_define
define|#
directive|define
name|GRE_RECUR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GRE_COP
value|(GRE_RP|GRE_CP)
end_define

begin_comment
comment|/* Checksum& Offset Present */
end_comment

begin_comment
comment|/* "Enhanced GRE" from RFC2637 - PPTP */
end_comment

begin_define
define|#
directive|define
name|GRE_AP
value|0x0080
end_define

begin_comment
comment|/* Ack present */
end_comment

begin_define
define|#
directive|define
name|GRE_MBZ_MASK
value|0x0078
end_define

begin_comment
comment|/* not defined */
end_comment

begin_comment
comment|/*  * Deencapsulate and print a GRE-tunneled IP datagram  */
end_comment

begin_function
name|void
name|gre_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
specifier|const
name|u_char
modifier|*
name|cp
init|=
name|bp
operator|+
literal|4
decl_stmt|;
specifier|const
name|struct
name|gre
modifier|*
name|gre
decl_stmt|;
name|u_int16_t
name|flags
decl_stmt|,
name|proto
decl_stmt|;
name|u_short
name|ver
init|=
literal|0
decl_stmt|;
name|u_short
name|extracted_ethertype
decl_stmt|;
name|gre
operator|=
operator|(
specifier|const
expr|struct
name|gre
operator|*
operator|)
name|bp
expr_stmt|;
name|TCHECK
argument_list|(
name|gre
operator|->
name|proto
argument_list|)
expr_stmt|;
name|flags
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|gre
operator|->
name|flags
argument_list|)
expr_stmt|;
name|proto
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|gre
operator|->
name|proto
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"gre "
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
condition|)
block|{
comment|/* Decode the flags */
name|putchar
argument_list|(
literal|'['
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_CP
condition|)
name|putchar
argument_list|(
literal|'C'
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_RP
condition|)
name|putchar
argument_list|(
literal|'R'
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_KP
condition|)
name|putchar
argument_list|(
literal|'K'
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_SP
condition|)
name|putchar
argument_list|(
literal|'S'
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_sP
condition|)
name|putchar
argument_list|(
literal|'s'
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_AP
condition|)
name|putchar
argument_list|(
literal|'A'
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_RECUR_MASK
condition|)
name|printf
argument_list|(
literal|"R%x"
argument_list|,
operator|(
name|flags
operator|&
name|GRE_RECUR_MASK
operator|)
operator|>>
name|GRE_RECUR_SHIFT
argument_list|)
expr_stmt|;
name|ver
operator|=
name|flags
operator|&
name|GRE_VER_MASK
expr_stmt|;
name|printf
argument_list|(
literal|"v%u"
argument_list|,
name|ver
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_MBZ_MASK
condition|)
name|printf
argument_list|(
literal|"!%x"
argument_list|,
name|flags
operator|&
name|GRE_MBZ_MASK
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"] "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|flags
operator|&
name|GRE_COP
condition|)
block|{
name|int
name|checksum
decl_stmt|,
name|offset
decl_stmt|;
name|TCHECK2
argument_list|(
operator|*
name|cp
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|checksum
operator|=
name|EXTRACT_16BITS
argument_list|(
name|cp
argument_list|)
expr_stmt|;
name|offset
operator|=
name|EXTRACT_16BITS
argument_list|(
name|cp
operator|+
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|GRE_CP
condition|)
block|{
comment|/* Checksum present */
comment|/* todo: check checksum */
if|if
condition|(
name|vflag
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"C:%04x "
argument_list|,
name|checksum
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|flags
operator|&
name|GRE_RP
condition|)
block|{
comment|/* Offset present */
if|if
condition|(
name|vflag
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"O:%04x "
argument_list|,
name|offset
argument_list|)
expr_stmt|;
block|}
name|cp
operator|+=
literal|4
expr_stmt|;
comment|/* skip checksum and offset */
block|}
if|if
condition|(
name|flags
operator|&
name|GRE_KP
condition|)
block|{
name|TCHECK2
argument_list|(
operator|*
name|cp
argument_list|,
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|ver
operator|==
literal|1
condition|)
block|{
comment|/* PPTP */
if|if
condition|(
name|vflag
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"PL:%u "
argument_list|,
name|EXTRACT_16BITS
argument_list|(
name|cp
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ID:%04x "
argument_list|,
name|EXTRACT_16BITS
argument_list|(
name|cp
operator|+
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|printf
argument_list|(
literal|"K:%08x "
argument_list|,
name|EXTRACT_32BITS
argument_list|(
name|cp
argument_list|)
argument_list|)
expr_stmt|;
name|cp
operator|+=
literal|4
expr_stmt|;
comment|/* skip key */
block|}
if|if
condition|(
name|flags
operator|&
name|GRE_SP
condition|)
block|{
name|TCHECK2
argument_list|(
operator|*
name|cp
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"S:%u "
argument_list|,
name|EXTRACT_32BITS
argument_list|(
name|cp
argument_list|)
argument_list|)
expr_stmt|;
name|cp
operator|+=
literal|4
expr_stmt|;
comment|/* skip seq */
block|}
if|if
condition|(
name|flags
operator|&
name|GRE_AP
operator|&&
name|ver
operator|>=
literal|1
condition|)
block|{
name|TCHECK2
argument_list|(
operator|*
name|cp
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"A:%u "
argument_list|,
name|EXTRACT_32BITS
argument_list|(
name|cp
argument_list|)
argument_list|)
expr_stmt|;
name|cp
operator|+=
literal|4
expr_stmt|;
comment|/* skip ack */
block|}
comment|/* We don't support routing fields (variable length) now. Punt. */
if|if
condition|(
name|flags
operator|&
name|GRE_RP
condition|)
return|return;
name|TCHECK
argument_list|(
name|cp
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|length
operator|-=
name|cp
operator|-
name|bp
expr_stmt|;
if|if
condition|(
name|ether_encap_print
argument_list|(
name|proto
argument_list|,
name|cp
argument_list|,
name|length
argument_list|,
name|length
argument_list|,
operator|&
name|extracted_ethertype
argument_list|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"gre-proto-0x%04X"
argument_list|,
name|proto
argument_list|)
expr_stmt|;
return|return;
name|trunc
label|:
name|fputs
argument_list|(
literal|"[|gre]"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

