begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dlv_32769.h,v 1.2.4.2 2006/02/19 06:50:46 marka Exp $ */
end_comment

begin_comment
comment|/* draft-ietf-dnsext-delegation-signer-05.txt */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_DLV_32769_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_DLV_32769_H
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_dlv
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_uint16_t
name|key_tag
decl_stmt|;
name|isc_uint8_t
name|algorithm
decl_stmt|;
name|isc_uint8_t
name|digest_type
decl_stmt|;
name|isc_uint16_t
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|digest
decl_stmt|;
block|}
name|dns_rdata_dlv_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_DLV_32769_H */
end_comment

end_unit

