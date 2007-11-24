begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: print.h,v 1.17.188.4 2005/06/09 23:54:30 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PRINT_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_PRINT_H
value|1
end_define

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/formatcheck.h>
end_include

begin_comment
comment|/* Required for ISC_FORMAT_PRINTF() macro. */
end_comment

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

begin_comment
comment|/*  * This block allows lib/isc/print.c to be cleanly compiled even if  * the platform does not need it.  The standard Makefile will still  * not compile print.c or archive print.o, so this is just to make test  * compilation ("make print.o") easier.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ISC_PLATFORM_NEEDVSNPRINTF
argument_list|)
operator|&&
name|defined
argument_list|(
name|ISC__PRINT_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDVSNPRINTF
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
name|ISC_PLATFORM_NEEDSPRINTF
argument_list|)
operator|&&
name|defined
argument_list|(
name|ISC__PRINT_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ISC_PLATFORM_NEEDSPRINTF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***  *** Macros  ***/
end_comment

begin_define
define|#
directive|define
name|ISC_PRINT_QUADFORMAT
value|ISC_PLATFORM_QUADFORMAT
end_define

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDVSNPRINTF
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

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSPRINTF
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ISC_LANG_BEGINDECLS
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDVSNPRINTF
name|int
name|isc_print_vsnprintf
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
function_decl|ISC_FORMAT_PRINTF
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
value|isc_print_vsnprintf
end_define

begin_function_decl
name|int
name|isc_print_snprintf
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
function_decl|ISC_FORMAT_PRINTF
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
value|isc_print_snprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_NEEDVSNPRINTF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSPRINTF
end_ifdef

begin_function_decl
name|int
name|isc_print_sprintf
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
function_decl|ISC_FORMAT_PRINTF
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
value|isc_print_sprintf
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
comment|/* ISC_PRINT_H */
end_comment

end_unit

