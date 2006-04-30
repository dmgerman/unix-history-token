begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: zonekey.h,v 1.3.206.1 2004/03/06 08:14:01 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZONEKEY_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZONEKEY_H
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
name|isc_boolean_t
name|dns_zonekey_iszonekey
parameter_list|(
name|dns_rdata_t
modifier|*
name|keyrdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Determines if the key record contained in the rdata is a zone key.  *  *	Requires:  *		'keyrdata' is not NULL.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_ZONEKEY_H */
end_comment

end_unit

