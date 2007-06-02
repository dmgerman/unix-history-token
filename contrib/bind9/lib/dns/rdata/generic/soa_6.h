begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_SOA_6_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_SOA_6_H
value|1
end_define

begin_comment
comment|/* $Id: soa_6.h,v 1.28.18.2 2005/04/29 00:16:40 marka Exp $ */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_soa
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_name_t
name|origin
decl_stmt|;
name|dns_name_t
name|contact
decl_stmt|;
name|isc_uint32_t
name|serial
decl_stmt|;
comment|/*%< host order */
name|isc_uint32_t
name|refresh
decl_stmt|;
comment|/*%< host order */
name|isc_uint32_t
name|retry
decl_stmt|;
comment|/*%< host order */
name|isc_uint32_t
name|expire
decl_stmt|;
comment|/*%< host order */
name|isc_uint32_t
name|minimum
decl_stmt|;
comment|/*%< host order */
block|}
name|dns_rdata_soa_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_SOA_6_H */
end_comment

end_unit

