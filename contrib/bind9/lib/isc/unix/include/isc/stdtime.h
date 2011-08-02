begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2011  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: stdtime.h,v 1.14.332.2 2011-03-18 23:46:08 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_STDTIME_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_STDTIME_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/int.h>
end_include

begin_comment
comment|/*%  * It's public information that 'isc_stdtime_t' is an unsigned integral type.  * Applications that want maximum portability should not assume anything  * about its size.  */
end_comment

begin_typedef
typedef|typedef
name|isc_uint32_t
name|isc_stdtime_t
typedef|;
end_typedef

begin_comment
comment|/* but this flag helps... */
end_comment

begin_define
define|#
directive|define
name|STDTIME_ON_32BITS
value|1
end_define

begin_comment
comment|/*  * isc_stdtime32_t is a 32-bit version of isc_stdtime_t.  A variable of this  * type should only be used as an opaque integer (e.g.,) to compare two  * time values.  */
end_comment

begin_typedef
typedef|typedef
name|isc_uint32_t
name|isc_stdtime32_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/* */
name|void
name|isc_stdtime_get
parameter_list|(
name|isc_stdtime_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set 't' to the number of seconds since 00:00:00 UTC, January 1, 1970.  *  * Requires:  *  *\li	't' is a valid pointer.  */
end_comment

begin_define
define|#
directive|define
name|isc_stdtime_convert32
parameter_list|(
name|t
parameter_list|,
name|t32p
parameter_list|)
value|(*(t32p) = t)
end_define

begin_comment
comment|/*  * Convert the standard time to its 32-bit version.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_STDTIME_H */
end_comment

end_unit

