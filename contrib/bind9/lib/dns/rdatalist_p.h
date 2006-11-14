begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdatalist_p.h,v 1.3.206.2 2004/03/08 02:07:56 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RDATALIST_P_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RDATALIST_P_H
end_define

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isc__rdatalist_disassociate
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdatasetp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc__rdatalist_first
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc__rdatalist_next
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc__rdatalist_current
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc__rdatalist_clone
parameter_list|(
name|dns_rdataset_t
modifier|*
name|source
parameter_list|,
name|dns_rdataset_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|isc__rdatalist_count
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc__rdatalist_addnoqname
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc__rdatalist_getnoqname
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nsec
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nsecsig
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RDATALIST_P_H */
end_comment

end_unit

