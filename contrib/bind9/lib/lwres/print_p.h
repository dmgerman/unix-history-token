begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: print_p.h,v 1.2.4.1 2004/08/28 06:25:25 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_PRINT_P_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_PRINT_P_H
value|1
end_define

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<lwres/lang.h>
end_include

begin_include
include|#
directive|include
file|<lwres/platform.h>
end_include

begin_comment
comment|/*  * This block allows lib/lwres/print.c to be cleanly compiled even if  * the platform does not need it.  The standard Makefile will still  * not compile print.c or archive print.o, so this is just to make test  * compilation ("make print.o") easier.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LWRES_PLATFORM_NEEDVSNPRINTF
argument_list|)
operator|&&
name|defined
argument_list|(
name|LWRES__PRINT_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|LWRES_PLATFORM_NEEDVSNPRINTF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LWRES_PLATFORM_NEEDSPRINTF
argument_list|)
operator|&&
name|defined
argument_list|(
name|LWRES__PRINT_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|LWRES_PLATFORM_NEEDSPRINTF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***  *** Macros.  ***/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|LWRES_FORMAT_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
define|\
value|__attribute__((__format__(__printf__, fmt, args)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LWRES_FORMAT_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LWRES_PLATFORM_NEEDVSNPRINTF
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|LWRES_LANG_BEGINDECLS
ifdef|#
directive|ifdef
name|LWRES_PLATFORM_NEEDVSNPRINTF
name|int
name|lwres__print_vsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|LWRES_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|vsnprintf
value|lwres__print_vsnprintf
end_define

begin_function_decl
name|int
name|lwres__print_snprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|LWRES_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|snprintf
value|lwres__print_snprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_PLATFORM_NEEDVSNPRINTF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LWRES_PLATFORM_NEEDSPRINTF
end_ifdef

begin_function_decl
name|int
name|lwres__print_sprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|LWRES_FORMAT_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|sprintf
value|lwres__print_sprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|LWRES_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_PRINT_P_H */
end_comment

end_unit

