begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: tsig_250.h,v 1.20.206.1 2004/03/06 08:14:02 marka Exp $ */
end_comment

begin_comment
comment|/* RFC 2845 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ANY_255_TSIG_250_H
end_ifndef

begin_define
define|#
directive|define
name|ANY_255_TSIG_250_H
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_any_tsig
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_name_t
name|algorithm
decl_stmt|;
name|isc_uint64_t
name|timesigned
decl_stmt|;
name|isc_uint16_t
name|fudge
decl_stmt|;
name|isc_uint16_t
name|siglen
decl_stmt|;
name|unsigned
name|char
modifier|*
name|signature
decl_stmt|;
name|isc_uint16_t
name|originalid
decl_stmt|;
name|isc_uint16_t
name|error
decl_stmt|;
name|isc_uint16_t
name|otherlen
decl_stmt|;
name|unsigned
name|char
modifier|*
name|other
decl_stmt|;
block|}
name|dns_rdata_any_tsig_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANY_255_TSIG_250_H */
end_comment

end_unit

