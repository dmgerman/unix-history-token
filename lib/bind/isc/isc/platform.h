begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: platform.h.in,v 1.24.2.1.10.11 2004/03/08 09:04:52 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_PLATFORM_H
value|1
end_define

begin_comment
comment|/*****  ***** Platform-dependent defines.  *****/
end_comment

begin_comment
comment|/***  *** Network.  ***/
end_comment

begin_comment
comment|/*  * Define if this system needs the<netinet/in6.h> header file included  * for full IPv6 support (pretty much only UnixWare).  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDNETINETIN6H
end_undef

begin_comment
comment|/*  * Define if this system needs the<netinet6/in6.h> header file included  * to support in6_pkinfo (pretty much only BSD/OS).  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDNETINET6IN6H
end_undef

begin_comment
comment|/*  * If sockaddrs on this system have an sa_len field, ISC_PLATFORM_HAVESALEN  * will be defined.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVESALEN
value|1
end_define

begin_comment
comment|/*  * If this system has the IPv6 structure definitions, ISC_PLATFORM_HAVEIPV6  * will be defined.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVEIPV6
value|1
end_define

begin_comment
comment|/*  * If this system is missing in6addr_any, ISC_PLATFORM_NEEDIN6ADDRANY will  * be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDIN6ADDRANY
end_undef

begin_comment
comment|/*  * If this system is missing in6addr_loopback, ISC_PLATFORM_NEEDIN6ADDRLOOPBACK  * will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDIN6ADDRLOOPBACK
end_undef

begin_comment
comment|/*  * If this system has in6_pktinfo, ISC_PLATFORM_HAVEIN6PKTINFO will be  * defined.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVEIN6PKTINFO
value|1
end_define

begin_comment
comment|/*  * If this system has in_addr6, rather than in6_addr, ISC_PLATFORM_HAVEINADDR6  * will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_HAVEINADDR6
end_undef

begin_comment
comment|/*  * If this system has sin6_scope_id, ISC_PLATFORM_HAVESCOPEID will be defined.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVESCOPEID
value|1
end_define

begin_comment
comment|/*  * If this system needs inet_ntop(), ISC_PLATFORM_NEEDNTOP will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDNTOP
end_undef

begin_comment
comment|/*  * If this system needs inet_pton(), ISC_PLATFORM_NEEDPTON will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDPTON
end_undef

begin_comment
comment|/*  * If this system needs inet_aton(), ISC_PLATFORM_NEEDATON will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDATON
end_undef

begin_comment
comment|/*  * If this system needs in_port_t, ISC_PLATFORM_NEEDPORTT will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDPORTT
end_undef

begin_comment
comment|/*  * If the system needs strsep(), ISC_PLATFORM_NEEDSTRSEP will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDSTRSEP
end_undef

begin_comment
comment|/*  * If the system needs strlcpy(), ISC_PLATFORM_NEEDSTRLCPY will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDSTRLCPY
end_undef

begin_comment
comment|/*  * If the system needs strlcat(), ISC_PLATFORM_NEEDSTRLCAT will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDSTRLCAT
end_undef

begin_comment
comment|/*  * Define either ISC_PLATFORM_BSD44MSGHDR or ISC_PLATFORM_BSD43MSGHDR.  */
end_comment

begin_define
define|#
directive|define
name|ISC_NET_BSD44MSGHDR
value|1
end_define

begin_comment
comment|/*  * Define if PTHREAD_ONCE_INIT should be surrounded by braces to  * prevent compiler warnings (such as with gcc on Solaris 2.8).  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_BRACEPTHREADONCEINIT
end_undef

begin_comment
comment|/*  * Define on some UnixWare systems to fix erroneous definitions of various  * IN6_IS_ADDR_* macros.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_FIXIN6ISADDR
end_undef

begin_comment
comment|/***  *** Printing.  ***/
end_comment

begin_comment
comment|/*  * If this system needs vsnprintf() and snprintf(), ISC_PLATFORM_NEEDVSNPRINTF  * will be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDVSNPRINTF
end_undef

begin_comment
comment|/*  * If this system need a modern sprintf() that returns (int) not (char*).  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDSPRINTF
end_undef

begin_comment
comment|/*  * The printf format string modifier to use with isc_uint64_t values.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_QUADFORMAT
value|"ll"
end_define

begin_comment
comment|/*  * Defined if we are using threads.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_USETHREADS
end_undef

begin_comment
comment|/*  * Defined if unistd.h does not cause fd_set to be delared.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDSYSSELECTH
end_undef

begin_comment
comment|/*  * Type used for resource limits.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_RLIMITTYPE
value|rlim_t
end_define

begin_comment
comment|/*  * Define if your compiler supports "long long int".  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVELONGLONG
value|1
end_define

begin_comment
comment|/*  * Define if the system has struct lifconf which is a extended struct ifconf  * for IPv6.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_HAVELIFCONF
end_undef

begin_comment
comment|/*  * Define if the system has struct if_laddrconf which is a extended struct  * ifconf for IPv6.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_HAVEIF_LADDRCONF
end_undef

begin_comment
comment|/*  * Define if the system has struct if_laddrreq.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_HAVEIF_LADDRREQ
end_undef

begin_comment
comment|/*  * Used to control how extern data is linked; needed for Win32 platforms.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_USEDECLSPEC
end_undef

begin_comment
comment|/*  * Define if the system supports if_nametoindex.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVEIFNAMETOINDEX
value|1
end_define

begin_comment
comment|/*  * Define if this system needs strtoul.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDSTRTOUL
end_undef

begin_comment
comment|/*  * Define if this system needs memmove.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDMEMMOVE
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_USEDECLSPEC
end_ifndef

begin_define
define|#
directive|define
name|LIBISC_EXTERNAL_DATA
end_define

begin_define
define|#
directive|define
name|LIBDNS_EXTERNAL_DATA
end_define

begin_define
define|#
directive|define
name|LIBISCCC_EXTERNAL_DATA
end_define

begin_define
define|#
directive|define
name|LIBISCCFG_EXTERNAL_DATA
end_define

begin_define
define|#
directive|define
name|LIBBIND9_EXTERNAL_DATA
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ISC_PLATFORM_USEDECLSPEC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LIBISC_EXPORTS
end_ifdef

begin_define
define|#
directive|define
name|LIBISC_EXTERNAL_DATA
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBISC_EXTERNAL_DATA
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LIBDNS_EXPORTS
end_ifdef

begin_define
define|#
directive|define
name|LIBDNS_EXTERNAL_DATA
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBDNS_EXTERNAL_DATA
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LIBISCCC_EXPORTS
end_ifdef

begin_define
define|#
directive|define
name|LIBISCCC_EXTERNAL_DATA
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBISCCC_EXTERNAL_DATA
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LIBISCCFG_EXPORTS
end_ifdef

begin_define
define|#
directive|define
name|LIBISCCFG_EXTERNAL_DATA
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBISCCFG_EXTERNAL_DATA
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LIBBIND9_EXPORTS
end_ifdef

begin_define
define|#
directive|define
name|LIBBIND9_EXTERNAL_DATA
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBBIND9_EXTERNAL_DATA
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

begin_comment
comment|/* ISC_PLATFORM_USEDECLSPEC */
end_comment

begin_comment
comment|/*  * Tell emacs to use C mode for this file.  *  * Local Variables:  * mode: c  * End:  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_H */
end_comment

end_unit

