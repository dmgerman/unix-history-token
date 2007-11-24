begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ipv6.h,v 1.17.12.4 2004/03/09 05:21:09 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_IPV6_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_IPV6_H
value|1
end_define

begin_comment
comment|/*  * Also define LWRES_IPV6_H to keep it from being included if liblwres is  * being used, or redefinition errors will occur.  */
end_comment

begin_define
define|#
directive|define
name|LWRES_IPV6_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * IPv6 definitions for systems which do not support IPv6.  *  * MP:  *	No impact.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	N/A.  *  * Security:  *	No anticipated impact.  *  * Standards:  *	RFC 2553.  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/int.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_comment
comment|/***  *** Types.  ***/
end_comment

begin_struct
struct|struct
name|in6_addr
block|{
union|union
block|{
name|isc_uint8_t
name|_S6_u8
index|[
literal|16
index|]
decl_stmt|;
name|isc_uint16_t
name|_S6_u16
index|[
literal|8
index|]
decl_stmt|;
name|isc_uint32_t
name|_S6_u32
index|[
literal|4
index|]
decl_stmt|;
block|}
name|_S6_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|s6_addr
value|_S6_un._S6_u8
end_define

begin_define
define|#
directive|define
name|s6_addr8
value|_S6_un._S6_u8
end_define

begin_define
define|#
directive|define
name|s6_addr16
value|_S6_un._S6_u16
end_define

begin_define
define|#
directive|define
name|s6_addr32
value|_S6_un._S6_u32
end_define

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
value|{{{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }}}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
value|{{{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }}}
end_define

begin_expr_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
specifier|const
expr|struct
name|in6_addr
name|in6addr_any
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
specifier|const
expr|struct
name|in6_addr
name|in6addr_loopback
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sockaddr_in6
block|{
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVESALEN
name|isc_uint8_t
name|sin6_len
decl_stmt|;
name|isc_uint8_t
name|sin6_family
decl_stmt|;
else|#
directive|else
name|isc_uint16_t
name|sin6_family
decl_stmt|;
endif|#
directive|endif
name|isc_uint16_t
name|sin6_port
decl_stmt|;
name|isc_uint32_t
name|sin6_flowinfo
decl_stmt|;
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
name|isc_uint32_t
name|sin6_scope_id
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVESALEN
end_ifdef

begin_define
define|#
directive|define
name|SIN6_LEN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Unspecified  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_UNSPECIFIED
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr32[0] == 0)&&    \          ((a)->s6_addr32[1] == 0)&&    \          ((a)->s6_addr32[2] == 0)&&    \          ((a)->s6_addr32[3] == 0))
end_define

begin_comment
comment|/*  * Loopback  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LOOPBACK
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr32[0] == 0)&&    \          ((a)->s6_addr32[1] == 0)&&    \          ((a)->s6_addr32[2] == 0)&&    \          ((a)->s6_addr32[3] == htonl(1)))
end_define

begin_comment
comment|/*  * IPv4 compatible  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4COMPAT
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr32[0] == 0)&&    \          ((a)->s6_addr32[1] == 0)&&    \          ((a)->s6_addr32[2] == 0)&&    \          ((a)->s6_addr32[3] != 0)&&    \          ((a)->s6_addr32[3] != htonl(1)))
end_define

begin_comment
comment|/*  * Mapped  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4MAPPED
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr32[0] == 0)&&          \          ((a)->s6_addr32[1] == 0)&&          \          ((a)->s6_addr32[2] == htonl(0x0000ffff)))
end_define

begin_comment
comment|/*  * Multicast  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MULTICAST
parameter_list|(
name|a
parameter_list|)
define|\
value|((a)->s6_addr8[0] == 0xffU)
end_define

begin_comment
comment|/*  * Unicast link / site local.  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr[0] == 0xfe)&& (((a)->s6_addr[1]& 0xc0) == 0x80))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_SITELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr[0] == 0xfe)&& (((a)->s6_addr[1]& 0xc0) == 0xc0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_IPV6_H */
end_comment

end_unit

