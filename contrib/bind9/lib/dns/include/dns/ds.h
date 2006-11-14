begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ds.h,v 1.3.2.1 2004/03/08 02:08:00 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_DS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_DS_H
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

begin_define
define|#
directive|define
name|DNS_DSDIGEST_SHA1
value|(1)
end_define

begin_comment
comment|/*  * Assuming SHA-1 digest type.  */
end_comment

begin_define
define|#
directive|define
name|DNS_DS_BUFFERSIZE
value|(24)
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_ds_buildrdata
parameter_list|(
name|dns_name_t
modifier|*
name|owner
parameter_list|,
name|dns_rdata_t
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|digest_type
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Build the rdata of a DS record.  *  * Requires:  *	key	Points to a valid DNS KEY record.  *	buffer	Points to a temporary buffer of at least  * 		DNS_DS_BUFFERSIZE bytes.  *	rdata	Points to an initialized dns_rdata_t.  *  * Ensures:  *      *rdata	Contains a valid DS rdata.  The 'data' member refers  *		to 'buffer'.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_DS_H */
end_comment

end_unit

