begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: secalg.h,v 1.13.18.2 2005/04/29 00:16:21 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_SECALG_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_SECALG_H
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
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_secalg_fromtext
parameter_list|(
name|dns_secalg_t
modifier|*
name|secalgp
parameter_list|,
name|isc_textregion_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the text 'source' refers to into a DNSSEC security algorithm value.  * The text may contain either a mnemonic algorithm name or a decimal algorithm  * number.  *  * Requires:  *\li	'secalgp' is a valid pointer.  *  *\li	'source' is a valid text region.  *  * Returns:  *\li	ISC_R_SUCCESS			on success  *\li	ISC_R_RANGE			numeric type is out of range  *\li	DNS_R_UNKNOWN			mnemonic type is unknown  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_secalg_totext
parameter_list|(
name|dns_secalg_t
name|secalg
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Put a textual representation of the DNSSEC security algorithm 'secalg'  * into 'target'.  *  * Requires:  *\li	'secalg' is a valid secalg.  *  *\li	'target' is a valid text buffer.  *  * Ensures,  *	if the result is success:  *\li		The used space in 'target' is updated.  *  * Returns:  *\li	ISC_R_SUCCESS			on success  *\li	ISC_R_NOSPACE			target buffer is too small  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_SECALG_H */
end_comment

end_unit

