begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: keyflags.h,v 1.9.206.1 2004/03/06 08:13:56 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_KEYFLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_KEYFLAGS_H
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
name|dns_keyflags_fromtext
parameter_list|(
name|dns_keyflags_t
modifier|*
name|flagsp
parameter_list|,
name|isc_textregion_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert the text 'source' refers to into a DNSSEC KEY flags value.  * The text may contain either a set of flag mnemonics separated by  * vertical bars or a decimal flags value.  For compatibility with  * older versions of BIND and the DNSSEC signer, octal values  * prefixed with a zero and hexadecimal values prefixed with "0x"  * are also accepted.  *  * Requires:  *	'flagsp' is a valid pointer.  *  *	'source' is a valid text region.  *  * Returns:  *	ISC_R_SUCCESS			on success  *	ISC_R_RANGE			numeric flag value is out of range  *	DNS_R_UNKNOWN			mnemonic flag is unknown  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_KEYFLAGS_H */
end_comment

end_unit

