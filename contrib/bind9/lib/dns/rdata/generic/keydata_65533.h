begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_KEYDATA_65533_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_KEYDATA_65533_H
value|1
end_define

begin_comment
comment|/* $Id: keydata_65533.h,v 1.2 2009-06-30 02:52:32 each Exp $ */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_keydata
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_uint32_t
name|refresh
decl_stmt|;
comment|/* Timer for refreshing data */
name|isc_uint32_t
name|addhd
decl_stmt|;
comment|/* Hold-down timer for adding */
name|isc_uint32_t
name|removehd
decl_stmt|;
comment|/* Hold-down timer for removing */
name|isc_uint16_t
name|flags
decl_stmt|;
comment|/* Copy of DNSKEY_48 */
name|isc_uint8_t
name|protocol
decl_stmt|;
name|isc_uint8_t
name|algorithm
decl_stmt|;
name|isc_uint16_t
name|datalen
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|dns_rdata_keydata_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_KEYDATA_65533_H */
end_comment

end_unit

