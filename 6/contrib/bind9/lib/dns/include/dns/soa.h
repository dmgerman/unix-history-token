begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: soa.h,v 1.2.206.1 2004/03/06 08:14:00 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_SOA_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_SOA_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * SOA utilities.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_uint32_t
name|dns_soa_getserial
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|dns_soa_getrefresh
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|dns_soa_getretry
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|dns_soa_getexpire
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|dns_soa_getminimum
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Extract an integer field from the rdata of a SOA record.  *  * Requires:  *	rdata refers to the rdata of a well-formed SOA record.  */
end_comment

begin_function_decl
name|void
name|dns_soa_setserial
parameter_list|(
name|isc_uint32_t
name|val
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_soa_setrefresh
parameter_list|(
name|isc_uint32_t
name|val
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_soa_setretry
parameter_list|(
name|isc_uint32_t
name|val
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_soa_setexpire
parameter_list|(
name|isc_uint32_t
name|val
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_soa_setminimum
parameter_list|(
name|isc_uint32_t
name|val
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Change an integer field of a SOA record by modifying the  * rdata in-place.  *  * Requires:  *	rdata refers to the rdata of a well-formed SOA record.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_SOA_H */
end_comment

end_unit

