begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_LOC_29_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_LOC_29_H
value|1
end_define

begin_comment
comment|/* $Id: loc_29.h,v 1.14.206.1 2004/03/06 08:14:06 marka Exp $ */
end_comment

begin_comment
comment|/* RFC 1876 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_loc_0
block|{
name|isc_uint8_t
name|version
decl_stmt|;
comment|/* must be first and zero */
name|isc_uint8_t
name|size
decl_stmt|;
name|isc_uint8_t
name|horizontal
decl_stmt|;
name|isc_uint8_t
name|vertical
decl_stmt|;
name|isc_uint32_t
name|latitude
decl_stmt|;
name|isc_uint32_t
name|longitude
decl_stmt|;
name|isc_uint32_t
name|altitude
decl_stmt|;
block|}
name|dns_rdata_loc_0_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_loc
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
union|union
block|{
name|dns_rdata_loc_0_t
name|v0
decl_stmt|;
block|}
name|v
union|;
block|}
name|dns_rdata_loc_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_LOC_29_H */
end_comment

end_unit

