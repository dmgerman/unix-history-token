begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2008  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_NSEC_47_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_NSEC_47_H
value|1
end_define

begin_comment
comment|/* $Id: nsec_47.h,v 1.10 2008/07/15 23:47:21 tbox Exp $ */
end_comment

begin_comment
comment|/*!  * \brief Per RFC 3845 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_nsec
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_name_t
name|next
decl_stmt|;
name|unsigned
name|char
modifier|*
name|typebits
decl_stmt|;
name|isc_uint16_t
name|len
decl_stmt|;
block|}
name|dns_rdata_nsec_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_NSEC_47_H */
end_comment

end_unit

