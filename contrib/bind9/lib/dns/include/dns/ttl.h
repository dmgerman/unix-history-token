begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ttl.h,v 1.12.206.1 2004/03/06 08:14:01 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_TTL_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_TTL_H
value|1
end_define

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  ***	Functions  ***/
name|isc_result_t
name|dns_ttl_totext
parameter_list|(
name|isc_uint32_t
name|src
parameter_list|,
name|isc_boolean_t
name|verbose
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Output a TTL or other time interval in a human-readable form.  * The time interval is given as a count of seconds in 'src'.  * The text representation is appended to 'target'.  *  * If 'verbose' is ISC_FALSE, use the terse BIND 8 style, like "1w2d3h4m5s".  *  * If 'verbose' is ISC_TRUE, use a verbose style like the SOA comments  * in "dig", like "1 week 2 days 3 hours 4 minutes 5 seconds".  *  * Returns:  * 	ISC_R_SUCCESS  * 	ISC_R_NOSPACE  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_counter_fromtext
parameter_list|(
name|isc_textregion_t
modifier|*
name|source
parameter_list|,
name|isc_uint32_t
modifier|*
name|ttl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Converts a counter from either a plain number or a BIND 8 style value.  *  * Returns:  *	ISC_R_SUCCESS  *	DNS_R_SYNTAX  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_ttl_fromtext
parameter_list|(
name|isc_textregion_t
modifier|*
name|source
parameter_list|,
name|isc_uint32_t
modifier|*
name|ttl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Converts a ttl from either a plain number or a BIND 8 style value.  *  * Returns:  *	ISC_R_SUCCESS  *	DNS_R_BADTTL  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_TTL_H */
end_comment

end_unit

