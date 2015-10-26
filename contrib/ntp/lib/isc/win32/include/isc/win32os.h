begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: win32os.h,v 1.7 2009/06/25 23:48:02 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_WIN32OS_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_WIN32OS_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/*  * Return the number of CPUs available on the system, or 1 if this cannot  * be determined.  */
name|unsigned
name|int
name|isc_win32os_majorversion
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Major Version of the O/S.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_win32os_minorversion
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Minor Version of the O/S.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_win32os_servicepackmajor
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Major Version of the Service Pack for O/S.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_win32os_servicepackminor
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Minor Version of the Service Pack for O/S.  */
end_comment

begin_function_decl
name|int
name|isc_win32os_versioncheck
parameter_list|(
name|unsigned
name|int
name|major
parameter_list|,
name|unsigned
name|int
name|minor
parameter_list|,
name|unsigned
name|int
name|updatemajor
parameter_list|,
name|unsigned
name|int
name|updateminor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Checks the current version of the operating system with the  * supplied version information.  * Returns:  * -1	if less than the version information supplied  *  0   if equal to all of the version information supplied  * +1   if greater than the version information supplied  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_WIN32OS_H */
end_comment

end_unit

