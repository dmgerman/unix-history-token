begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007-2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: platform.h,v 1.19 2009/09/29 23:48:04 tbox Exp $ */
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

begin_define
define|#
directive|define
name|ISC_PLATFORM_USETHREADS
end_define

begin_comment
comment|/***  *** Network.  ***/
end_comment

begin_if
if|#
directive|if
name|_MSC_VER
operator|>
literal|1200
end_if

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVEIPV6
end_define

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVEIN6PKTINFO
end_define

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVESCOPEID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDPORTT
end_define

begin_undef
undef|#
directive|undef
name|MSG_TRUNC
end_undef

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDNTOP
end_define

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDPTON
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_QUADFORMAT
end_ifndef

begin_define
define|#
directive|define
name|ISC_PLATFORM_QUADFORMAT
value|"I64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDSTRSEP
end_define

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDSTRLCPY
end_define

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDSTRLCAT
end_define

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDSTRLCPY
end_define

begin_comment
comment|/*  * Used to control how extern data is linked; needed for Win32 platforms.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_USEDECLSPEC
value|1
end_define

begin_comment
comment|/*  * Define this here for now as winsock2.h defines h_errno  * and we don't want to redeclare it.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_NONSTDHERRNO
end_define

begin_comment
comment|/*  * Define if the platform has<sys/un.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_HAVESYSUNH
end_undef

begin_comment
comment|/*  * Defines for the noreturn attribute.  */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_NORETURN_PRE
value|__declspec(noreturn)
end_define

begin_define
define|#
directive|define
name|ISC_PLATFORM_NORETURN_POST
end_define

begin_comment
comment|/*  * Set up a macro for importing and exporting from the DLL  *  * To build static libraries on win32, #define ISC_STATIC_WIN  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_STATIC_WIN
end_ifndef

begin_define
define|#
directive|define
name|ISC_DLLEXP
value|__declspec(dllexport)
end_define

begin_define
define|#
directive|define
name|ISC_DLLIMP
value|__declspec(dllimport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_DLLEXP
end_define

begin_define
define|#
directive|define
name|ISC_DLLIMP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LIBISC_EXPORTS
end_ifdef

begin_define
define|#
directive|define
name|LIBISC_EXTERNAL_DATA
value|ISC_DLLEXP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBISC_EXTERNAL_DATA
value|ISC_DLLIMP
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
value|ISC_DLLEXP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBISCCFG_EXTERNAL_DATA
value|ISC_DLLIMP
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
value|ISC_DLLEXP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBISCCC_EXTERNAL_DATA
value|ISC_DLLIMP
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
value|ISC_DLLEXP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBDNS_EXTERNAL_DATA
value|ISC_DLLIMP
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
value|ISC_DLLEXP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBBIND9_EXTERNAL_DATA
value|ISC_DLLIMP
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
comment|/* ISC_PLATFORM_H */
end_comment

end_unit

