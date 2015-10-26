begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ntpaths.h,v 1.20 2009/07/14 22:54:57 each Exp $ */
end_comment

begin_comment
comment|/*  * Windows-specific path definitions  * These routines are used to set up and return system-specific path  * information about the files enumerated in NtPaths  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_NTPATHS_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_NTPATHS_H
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_comment
comment|/*  * Index of paths needed  */
end_comment

begin_enum
enum|enum
name|NtPaths
block|{
name|NAMED_CONF_PATH
block|,
name|LWRES_CONF_PATH
block|,
name|RESOLV_CONF_PATH
block|,
name|RNDC_CONF_PATH
block|,
name|NAMED_PID_PATH
block|,
name|LWRESD_PID_PATH
block|,
name|LOCAL_STATE_DIR
block|,
name|SYS_CONF_DIR
block|,
name|RNDC_KEY_PATH
block|,
name|SESSION_KEY_PATH
block|}
enum|;
end_enum

begin_comment
comment|/*  * Define macros to get the path of the config files  */
end_comment

begin_define
define|#
directive|define
name|NAMED_CONFFILE
value|isc_ntpaths_get(NAMED_CONF_PATH)
end_define

begin_define
define|#
directive|define
name|RNDC_CONFFILE
value|isc_ntpaths_get(RNDC_CONF_PATH)
end_define

begin_define
define|#
directive|define
name|RNDC_KEYFILE
value|isc_ntpaths_get(RNDC_KEY_PATH)
end_define

begin_define
define|#
directive|define
name|SESSION_KEYFILE
value|isc_ntpaths_get(SESSION_KEY_PATH)
end_define

begin_define
define|#
directive|define
name|RESOLV_CONF
value|isc_ntpaths_get(RESOLV_CONF_PATH)
end_define

begin_comment
comment|/*  * Information about where the files are on disk  */
end_comment

begin_define
define|#
directive|define
name|NS_LOCALSTATEDIR
value|"/dns/bin"
end_define

begin_define
define|#
directive|define
name|NS_SYSCONFDIR
value|"/dns/etc"
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isc_ntpaths_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_ntpaths_get
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_NTPATHS_H */
end_comment

end_unit

