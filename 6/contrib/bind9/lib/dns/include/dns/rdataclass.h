begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdataclass.h,v 1.17.206.1 2004/03/06 08:13:59 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RDATACLASS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RDATACLASS_H
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
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_rdataclass_fromtext
parameter_list|(
name|dns_rdataclass_t
modifier|*
name|classp
parameter_list|,
name|isc_textregion_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert the text 'source' refers to into a DNS class.  *  * Requires:  *	'classp' is a valid pointer.  *  *	'source' is a valid text region.  *  * Returns:  *	ISC_R_SUCCESS			on success  *	DNS_R_UNKNOWN			class is unknown  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataclass_totext
parameter_list|(
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Put a textual representation of class 'rdclass' into 'target'.  *  * Requires:  *	'rdclass' is a valid class.  *  *	'target' is a valid text buffer.  *  * Ensures:  *	If the result is success:  *		The used space in 'target' is updated.  *  * Returns:  *	ISC_R_SUCCESS			on success  *	ISC_R_NOSPACE			target buffer is too small  */
end_comment

begin_function_decl
name|void
name|dns_rdataclass_format
parameter_list|(
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|char
modifier|*
name|array
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Format a human-readable representation of the class 'rdclass'  * into the character array 'array', which is of size 'size'.  * The resulting string is guaranteed to be null-terminated.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATACLASS_FORMATSIZE
value|sizeof("CLASS65535")
end_define

begin_comment
comment|/*  * Minimum size of array to pass to dns_rdataclass_format().  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RDATACLASS_H */
end_comment

end_unit

