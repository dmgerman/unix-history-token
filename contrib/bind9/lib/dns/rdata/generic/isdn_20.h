begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_ISDN_20_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_ISDN_20_H
value|1
end_define

begin_comment
comment|/* $Id: isdn_20.h,v 1.13.206.1 2004/03/06 08:14:05 marka Exp $ */
end_comment

begin_comment
comment|/* RFC 1183 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_isdn
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|char
modifier|*
name|isdn
decl_stmt|;
name|char
modifier|*
name|subaddress
decl_stmt|;
name|isc_uint8_t
name|isdn_len
decl_stmt|;
name|isc_uint8_t
name|subaddress_len
decl_stmt|;
block|}
name|dns_rdata_isdn_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_ISDN_20_H */
end_comment

end_unit

