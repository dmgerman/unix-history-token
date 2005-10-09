begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: time.h,v 1.9.12.3 2004/03/08 09:04:39 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_TIME_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_TIME_H
value|1
end_define

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  ***	Functions  ***/
name|isc_result_t
name|dns_time64_fromtext
parameter_list|(
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|isc_int64_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a date and time in YYYYMMDDHHMMSS text format at 'source'  * into to a 64-bit count of seconds since Jan 1 1970 0:00 GMT.  * Store the count at 'target'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_time32_fromtext
parameter_list|(
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|isc_uint32_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like dns_time64_fromtext, but returns the second count modulo 2^32  * as per RFC2535.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_time64_totext
parameter_list|(
name|isc_int64_t
name|value
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a 64-bit count of seconds since Jan 1 1970 0:00 GMT into  * a YYYYMMDDHHMMSS text representation and append it to 'target'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_time32_totext
parameter_list|(
name|isc_uint32_t
name|value
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like dns_time64_totext, but for a 32-bit cyclic time value.  * Of those dates whose counts of seconds since Jan 1 1970 0:00 GMT  * are congruent with 'value' modulo 2^32, the one closest to the  * current date is chosen.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_TIME_H */
end_comment

end_unit

