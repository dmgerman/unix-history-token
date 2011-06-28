begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2008  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rcode.h,v 1.21 2008-09-25 04:02:39 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RCODE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RCODE_H
value|1
end_define

begin_comment
comment|/*! \file dns/rcode.h */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_rcode_fromtext
parameter_list|(
name|dns_rcode_t
modifier|*
name|rcodep
parameter_list|,
name|isc_textregion_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the text 'source' refers to into a DNS error value.  *  * Requires:  *\li	'rcodep' is a valid pointer.  *  *\li	'source' is a valid text region.  *  * Returns:  *\li	#ISC_R_SUCCESS			on success  *\li	#DNS_R_UNKNOWN			type is unknown  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rcode_totext
parameter_list|(
name|dns_rcode_t
name|rcode
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Put a textual representation of error 'rcode' into 'target'.  *  * Requires:  *\li	'rcode' is a valid rcode.  *  *\li	'target' is a valid text buffer.  *  * Ensures:  *\li	If the result is success:  *		The used space in 'target' is updated.  *  * Returns:  *\li	#ISC_R_SUCCESS			on success  *\li	#ISC_R_NOSPACE			target buffer is too small  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tsigrcode_fromtext
parameter_list|(
name|dns_rcode_t
modifier|*
name|rcodep
parameter_list|,
name|isc_textregion_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the text 'source' refers to into a TSIG/TKEY error value.  *  * Requires:  *\li	'rcodep' is a valid pointer.  *  *\li	'source' is a valid text region.  *  * Returns:  *\li	#ISC_R_SUCCESS			on success  *\li	#DNS_R_UNKNOWN			type is unknown  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_tsigrcode_totext
parameter_list|(
name|dns_rcode_t
name|rcode
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Put a textual representation of TSIG/TKEY error 'rcode' into 'target'.  *  * Requires:  *\li	'rcode' is a valid TSIG/TKEY error code.  *  *\li	'target' is a valid text buffer.  *  * Ensures:  *\li	If the result is success:  *		The used space in 'target' is updated.  *  * Returns:  *\li	#ISC_R_SUCCESS			on success  *\li	#ISC_R_NOSPACE			target buffer is too small  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_hashalg_fromtext
parameter_list|(
name|unsigned
name|char
modifier|*
name|hashalg
parameter_list|,
name|isc_textregion_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the text 'source' refers to into a has algorithm value.  *  * Requires:  *\li	'hashalg' is a valid pointer.  *  *\li	'source' is a valid text region.  *  * Returns:  *\li	#ISC_R_SUCCESS			on success  *\li	#DNS_R_UNKNOWN			type is unknown  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RCODE_H */
end_comment

end_unit

