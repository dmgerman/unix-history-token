begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: a_1.h,v 1.2.2.2 2005/06/05 00:02:22 marka Exp $ */
end_comment

begin_comment
comment|/* by Bjorn.Victor@it.uu.se, 2005-05-07 */
end_comment

begin_comment
comment|/* Based on generic/mx_15.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CH_3_A_1_H
end_ifndef

begin_define
define|#
directive|define
name|CH_3_A_1_H
value|1
end_define

begin_typedef
typedef|typedef
name|isc_uint16_t
name|ch_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_ch_a
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_name_t
name|ch_addr_dom
decl_stmt|;
comment|/* ch-addr domain for back mapping */
name|ch_addr_t
name|ch_addr
decl_stmt|;
comment|/* chaos address (16 bit) network order */
block|}
name|dns_rdata_ch_a_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CH_3_A_1_H */
end_comment

end_unit

