begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: xfrin.h,v 1.18.136.4 2006/07/20 01:10:29 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_XFRIN_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_XFRIN_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Incoming zone transfers (AXFR + IXFR).  */
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
file|<dns/types.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*  * A transfer in progress.  This is an opaque type.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_xfrin_ctx
name|dns_xfrin_ctx_t
typedef|;
end_typedef

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_xfrin_create
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_rdatatype_t
name|xfrtype
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|masteraddr
parameter_list|,
name|dns_tsigkey_t
modifier|*
name|tsigkey
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_xfrindone_t
name|done
parameter_list|,
name|dns_xfrin_ctx_t
modifier|*
modifier|*
name|xfrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_xfrin_create2
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_rdatatype_t
name|xfrtype
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|masteraddr
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|sourceaddr
parameter_list|,
name|dns_tsigkey_t
modifier|*
name|tsigkey
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_xfrindone_t
name|done
parameter_list|,
name|dns_xfrin_ctx_t
modifier|*
modifier|*
name|xfrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attempt to start an incoming zone transfer of 'zone'  * from 'masteraddr', creating a dns_xfrin_ctx_t object to  * manage it.  Attach '*xfrp' to the newly created object.  *  * Iff ISC_R_SUCCESS is returned, '*done' is guaranteed to be  * called in the context of 'task', with 'zone' and a result  * code as arguments when the transfer finishes.  *  * Requires:  *	'xfrtype' is dns_rdatatype_axfr, dns_rdatatype_ixfr  *	or dns_rdatatype_soa (soa query followed by axfr if  *	serial is greater than current serial).  *  *	If 'xfrtype' is dns_rdatatype_ixfr or dns_rdatatype_soa,  *	the zone has a database.  */
end_comment

begin_function_decl
name|void
name|dns_xfrin_shutdown
parameter_list|(
name|dns_xfrin_ctx_t
modifier|*
name|xfr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If the zone transfer 'xfr' has already finished,  * do nothing.  Otherwise, abort it and cause it to call  * its done callback with a status of ISC_R_CANCELLED.  */
end_comment

begin_function_decl
name|void
name|dns_xfrin_detach
parameter_list|(
name|dns_xfrin_ctx_t
modifier|*
modifier|*
name|xfrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach a reference to a zone transfer object.  * Caller to maintain external locking if required.  */
end_comment

begin_function_decl
name|void
name|dns_xfrin_attach
parameter_list|(
name|dns_xfrin_ctx_t
modifier|*
name|source
parameter_list|,
name|dns_xfrin_ctx_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Caller to maintain external locking if required.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_XFRIN_H */
end_comment

end_unit

