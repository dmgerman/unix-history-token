begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_AVC_258_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_AVC_258_H
value|1
end_define

begin_typedef
typedef|typedef
name|dns_rdata_txt_string_t
name|dns_rdata_avc_string_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_avc
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
name|isc_uint16_t
name|length
decl_stmt|;
comment|/* private */
name|isc_uint16_t
name|offset
decl_stmt|;
block|}
name|dns_rdata_avc_t
typedef|;
end_typedef

begin_comment
comment|/*  * ISC_LANG_BEGINDECLS and ISC_LANG_ENDDECLS are already done  * via rdatastructpre.h and rdatastructsuf.h.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_AVC_258_H */
end_comment

end_unit

