begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: hip_55.h,v 1.2 2009-02-26 06:09:19 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_HIP_5_H
end_ifndef

begin_define
define|#
directive|define
name|GENERIC_HIP_5_H
value|1
end_define

begin_comment
comment|/* RFC 5205 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rdata_hip
block|{
name|dns_rdatacommon_t
name|common
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|unsigned
name|char
modifier|*
name|hit
decl_stmt|;
name|unsigned
name|char
modifier|*
name|key
decl_stmt|;
name|unsigned
name|char
modifier|*
name|servers
decl_stmt|;
name|isc_uint8_t
name|algorithm
decl_stmt|;
name|isc_uint8_t
name|hit_len
decl_stmt|;
name|isc_uint16_t
name|key_len
decl_stmt|;
name|isc_uint16_t
name|servers_len
decl_stmt|;
comment|/* Private */
name|isc_uint16_t
name|offset
decl_stmt|;
block|}
name|dns_rdata_hip_t
typedef|;
end_typedef

begin_function_decl
name|isc_result_t
name|dns_rdata_hip_first
parameter_list|(
name|dns_rdata_hip_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_rdata_hip_next
parameter_list|(
name|dns_rdata_hip_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_rdata_hip_current
parameter_list|(
name|dns_rdata_hip_t
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENERIC_HIP_5_H */
end_comment

end_unit

