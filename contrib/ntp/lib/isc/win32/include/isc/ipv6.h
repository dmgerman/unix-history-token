begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2011, 2012  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
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
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * IPv6 definitions for systems which do not support IPv6.  *  * MP:  *	No impact.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	N/A.  *  * Security:  *	No anticipated impact.  *  * Standards:  *	RFC2553.  */
end_comment

begin_if
if|#
directive|if
name|_MSC_VER
operator|<
literal|1300
end_if

begin_define
define|#
directive|define
name|in6_addr
value|in_addr6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_ANY_INIT
end_ifndef

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
value|{{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_LOOPBACK_INIT
end_ifndef

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
value|{{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
specifier|const
expr|struct
name|in6_addr
name|isc_net_in6addrany
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
specifier|const
expr|struct
name|in6_addr
name|isc_net_in6addrloop
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Unspecified  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_UNSPECIFIED
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_UNSPECIFIED
parameter_list|(
name|a
parameter_list|)
value|(\ *((u_long *)((a)->s6_addr)    ) == 0&& \ *((u_long *)((a)->s6_addr) + 1) == 0&& \ *((u_long *)((a)->s6_addr) + 2) == 0&& \ *((u_long *)((a)->s6_addr) + 3) == 0 \ )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Loopback  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LOOPBACK
parameter_list|(
name|a
parameter_list|)
value|(\ *((u_long *)((a)->s6_addr)    ) == 0&& \ *((u_long *)((a)->s6_addr) + 1) == 0&& \ *((u_long *)((a)->s6_addr) + 2) == 0&& \ *((u_long *)((a)->s6_addr) + 3) == htonl(1) \ )
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(\ *((u_long *)((a)->s6_addr)    ) == 0&& \ *((u_long *)((a)->s6_addr) + 1) == 0&& \ *((u_long *)((a)->s6_addr) + 2) == 0&& \ *((u_long *)((a)->s6_addr) + 3) != 0&& \ *((u_long *)((a)->s6_addr) + 3) != htonl(1) \ )
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
value|(\ *((u_long *)((a)->s6_addr)    ) == 0&& \ *((u_long *)((a)->s6_addr) + 1) == 0&& \ *((u_long *)((a)->s6_addr) + 2) == htonl(0x0000ffff))
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
value|((a)->s6_addr[0] == 0xffU)
end_define

begin_comment
comment|/*  * Unicast link / site local.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_LINKLOCAL
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
value|(\ 	((a)->s6_addr[0] == 0xfe)&& \ 	(((a)->s6_addr[1]& 0xc0) == 0x80))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_SITELOCAL
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_SITELOCAL
parameter_list|(
name|a
parameter_list|)
value|(\ 	((a)->s6_addr[0] == 0xfe)&& \ 	(((a)->s6_addr[1]& 0xc0) == 0xc0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_IPV6_H */
end_comment

end_unit

