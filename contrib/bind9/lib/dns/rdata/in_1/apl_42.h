begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN_1_APL_42_H
end_ifndef

begin_define
define|#
directive|define
name|IN_1_APL_42_H
value|1
end_define

begin_comment
comment|/* $Id: apl_42.h,v 1.2.18.2 2005-04-29 00:16:42 marka Exp $ */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_apl_ent
block|{
name|isc_boolean_t
name|negative
decl_stmt|;
name|isc_uint16_t
name|family
decl_stmt|;
name|isc_uint8_t
name|prefix
decl_stmt|;
name|isc_uint8_t
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|dns_rdata_apl_ent_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_in_apl
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
comment|/* type& class specific elements */
name|unsigned
name|char
modifier|*
name|apl
decl_stmt|;
name|isc_uint16_t
name|apl_len
decl_stmt|;
comment|/* private */
name|isc_uint16_t
name|offset
decl_stmt|;
block|}
name|dns_rdata_in_apl_t
typedef|;
end_typedef

begin_comment
comment|/*  * ISC_LANG_BEGINDECLS and ISC_LANG_ENDDECLS are already done  * via rdatastructpre.h and rdatastructsuf.h.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_apl_first
parameter_list|(
name|dns_rdata_in_apl_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_rdata_apl_next
parameter_list|(
name|dns_rdata_in_apl_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_rdata_apl_current
parameter_list|(
name|dns_rdata_in_apl_t
modifier|*
parameter_list|,
name|dns_rdata_apl_ent_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_1_APL_42_H */
end_comment

end_unit

