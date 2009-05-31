begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005, 2007  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ipseckey_45.h,v 1.4 2007/06/19 23:47:17 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_IPSECKEY_45_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_IPSECKEY_45_H
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_ipseckey
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_uint8_t
name|precedence
decl_stmt|;
name|isc_uint8_t
name|gateway_type
decl_stmt|;
name|isc_uint8_t
name|algorithm
decl_stmt|;
name|struct
name|in_addr
name|in_addr
decl_stmt|;
comment|/* gateway type 1 */
name|struct
name|in6_addr
name|in6_addr
decl_stmt|;
comment|/* gateway type 2 */
name|dns_name_t
name|gateway
decl_stmt|;
comment|/* gateway type 3 */
name|unsigned
name|char
modifier|*
name|key
decl_stmt|;
name|isc_uint16_t
name|keylength
decl_stmt|;
block|}
name|dns_rdata_ipseckey_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_IPSECKEY_45_H */
end_comment

end_unit

