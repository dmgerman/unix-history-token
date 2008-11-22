begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: platform.h.in,v 1.12.2.1.10.5 2005/06/08 02:08:32 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_PLATFORM_H
value|1
end_define

begin_comment
comment|/*****  ***** Platform-dependent defines.  *****/
end_comment

begin_comment
comment|/***  *** Network.  ***/
end_comment

begin_comment
comment|/*  * Define if this system needs the<netinet/in6.h> header file for IPv6.  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_NEEDNETINETIN6H
end_undef

begin_comment
comment|/*  * Define if this system needs the<netinet6/in6.h> header file for IPv6.  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_NEEDNETINET6IN6H
end_undef

begin_comment
comment|/*  * If sockaddrs on this system have an sa_len field, LWRES_PLATFORM_HAVESALEN  * will be defined.  */
end_comment

begin_define
define|#
directive|define
name|LWRES_PLATFORM_HAVESALEN
value|1
end_define

begin_comment
comment|/*  * If this system has the IPv6 structure definitions, LWRES_PLATFORM_HAVEIPV6  * will be defined.  */
end_comment

begin_define
define|#
directive|define
name|LWRES_PLATFORM_HAVEIPV6
value|1
end_define

begin_comment
comment|/*  * If this system is missing in6addr_any, LWRES_PLATFORM_NEEDIN6ADDRANY will  * be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_NEEDIN6ADDRANY
end_undef

begin_comment
comment|/*  * If this system is missing in6addr_loopback,   * LWRES_PLATFORM_NEEDIN6ADDRLOOPBACK will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_NEEDIN6ADDRLOOPBACK
end_undef

begin_comment
comment|/*  * If this system has in_addr6, rather than in6_addr,  * LWRES_PLATFORM_HAVEINADDR6 will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_HAVEINADDR6
end_undef

begin_comment
comment|/*  * Defined if unistd.h does not cause fd_set to be delared.  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_NEEDSYSSELECTH
end_undef

begin_comment
comment|/*  * Used to control how extern data is linked; needed for Win32 platforms.  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_USEDECLSPEC
end_undef

begin_comment
comment|/*  * Defined this system needs vsnprintf() and snprintf().  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_NEEDVSNPRINTF
end_undef

begin_comment
comment|/*  * If this system need a modern sprintf() that returns (int) not (char*).  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_NEEDSPRINTF
end_undef

begin_comment
comment|/*  * The printf format string modifier to use with lwres_uint64_t values.  */
end_comment

begin_define
define|#
directive|define
name|LWRES_PLATFORM_QUADFORMAT
value|"ll"
end_define

begin_comment
comment|/*! \brief  * Define if this system needs strtoul.  */
end_comment

begin_undef
undef|#
directive|undef
name|LWRES_PLATFORM_NEEDSTRTOUL
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_PLATFORM_USEDECLSPEC
end_ifndef

begin_define
define|#
directive|define
name|LIBLWRES_EXTERNAL_DATA
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|LIBLWRES_EXPORTS
end_ifdef

begin_define
define|#
directive|define
name|LIBLWRES_EXTERNAL_DATA
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBLWRES_EXTERNAL_DATA
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_PLATFORM_H */
end_comment

end_unit

