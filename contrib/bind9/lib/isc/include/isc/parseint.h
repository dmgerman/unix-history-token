begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001, 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: parseint.h,v 1.2.202.4 2004/03/08 09:04:52 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PARSEINT_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_PARSEINT_H
value|1
end_define

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

begin_comment
comment|/*  * Parse integers, in a saner way than atoi() or strtoul() do.  */
end_comment

begin_comment
comment|/***  ***	Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_parse_uint32
parameter_list|(
name|isc_uint32_t
modifier|*
name|uip
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_parse_uint16
parameter_list|(
name|isc_uint16_t
modifier|*
name|uip
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_parse_uint8
parameter_list|(
name|isc_uint8_t
modifier|*
name|uip
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parse the null-terminated string 'string' containing a base 'base'  * integer, storing the result in '*uip'.  The base is interpreted  * as in strtoul().  Unlike strtoul(), leading whitespace, minus or  * plus signs are not accepted, and all errors (including overflow)  * are reported uniformly through the return value.  *  * Requires:  *	'string' points to a null-terminated string  *	0<= 'base'<= 36  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_BADNUMBER   The string is not numeric (in the given base)  *	ISC_R_RANGE	  The number is not representable as the requested type.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PARSEINT_H */
end_comment

end_unit

