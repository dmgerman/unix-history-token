begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_SIG_24_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_SIG_24_H
value|1
end_define

begin_comment
comment|/* $Id: sig_24.h,v 1.21.206.1 2004/03/06 08:14:12 marka Exp $ */
end_comment

begin_comment
comment|/* RFC 2535 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_sig_t
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_rdatatype_t
name|covered
decl_stmt|;
name|dns_secalg_t
name|algorithm
decl_stmt|;
name|isc_uint8_t
name|labels
decl_stmt|;
name|isc_uint32_t
name|originalttl
decl_stmt|;
name|isc_uint32_t
name|timeexpire
decl_stmt|;
name|isc_uint32_t
name|timesigned
decl_stmt|;
name|isc_uint16_t
name|keyid
decl_stmt|;
name|dns_name_t
name|signer
decl_stmt|;
name|isc_uint16_t
name|siglen
decl_stmt|;
name|unsigned
name|char
modifier|*
name|signature
decl_stmt|;
block|}
name|dns_rdata_sig_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_SIG_24_H */
end_comment

end_unit

