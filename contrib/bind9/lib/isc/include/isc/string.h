begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: string.h,v 1.9.164.3 2004/03/06 08:14:49 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_STRING_H
value|1
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<isc/int.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_uint64_t
name|isc_string_touint64
parameter_list|(
name|char
modifier|*
name|source
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert the string pointed to by 'source' to isc_uint64_t.  *  * On successful conversion 'endp' points to the first character  * after conversion is complete.  *  * 'base': 0 or 2..36  *  * If base is 0 the base is computed from the string type.  *  * On error 'endp' points to 'source'.  */
end_comment

begin_function_decl
name|char
modifier|*
name|isc_string_separate
parameter_list|(
name|char
modifier|*
modifier|*
name|stringp
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSTRSEP
end_ifdef

begin_define
define|#
directive|define
name|strsep
value|isc_string_separate
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDMEMMOVE
end_ifdef

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy(b,a,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|size_t
name|isc_string_strlcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSTRLCPY
end_ifdef

begin_define
define|#
directive|define
name|strlcpy
value|isc_string_strlcpy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|size_t
name|isc_string_strlcat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSTRLCAT
end_ifdef

begin_define
define|#
directive|define
name|strlcat
value|isc_string_strlcat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_STRING_H */
end_comment

end_unit

