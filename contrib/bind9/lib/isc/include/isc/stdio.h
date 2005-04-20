begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: stdio.h,v 1.6.206.1 2004/03/06 08:14:48 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_STDIO_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_STDIO_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_stdio_open
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|,
name|FILE
modifier|*
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_stdio_close
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_stdio_seek
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|long
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_stdio_read
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|nmemb
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|,
name|size_t
modifier|*
name|nret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_stdio_write
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|nmemb
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|,
name|size_t
modifier|*
name|nret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_stdio_flush
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These functions are wrappers around the corresponding stdio functions,  * returning a detailed error code in the form of an an isc_result_t.  ANSI C  * does not guarantee that stdio functions set errno, hence these functions  * must use platform dependent methods (e.g., the POSIX errno) to construct the  * error code.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_stdio_sync
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Invoke fsync() on the file descriptor underlying an stdio stream, or an  * equivalent system-dependent operation.  Note that this function has no  * direct counterpart in the stdio library.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_STDIO_H */
end_comment

end_unit

