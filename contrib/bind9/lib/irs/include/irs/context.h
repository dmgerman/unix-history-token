begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: context.h,v 1.3 2009-09-02 23:48:02 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IRS_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|IRS_CONTEXT_H
value|1
end_define

begin_comment
comment|/*! \file  *  * \brief  * The IRS context module provides an abstract interface to the DNS library  * with an application.  An IRS context object initializes and holds various  * resources used in the DNS library.  */
end_comment

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<irs/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|irs_context_create
parameter_list|(
name|irs_context_t
modifier|*
modifier|*
name|contextp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create an IRS context.  It internally initializes the ISC and DNS libraries  * (if not yet), creates a DNS client object and initializes the client using  * the configuration files parsed via the 'resconf' and 'dnsconf' IRS modules.  * Some of the internally initialized objects can be used by the application  * via irs_context_getxxx() functions (see below).  *  * Requires:  *  *\li	contextp != NULL&& *contextp == NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|irs_context_get
parameter_list|(
name|irs_context_t
modifier|*
modifier|*
name|contextp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return an IRS context for the calling thread.  If no IRS context is  * associated to the thread, this function creates a new one by calling  * irs_context_create(), and associates it with the thread as a thread specific  * data value.  This function is provided for standard libraries that are  * expected to be thread-safe but do not accept an appropriate IRS context  * as a library parameter, e.g., getaddrinfo().  *  * Requires:  *  *\li	contextp != NULL&& *contextp == NULL.  */
end_comment

begin_function_decl
name|void
name|irs_context_destroy
parameter_list|(
name|irs_context_t
modifier|*
modifier|*
name|contextp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy an IRS context.  *  * Requires:  *  *\li	'*contextp' is a valid IRS context.  *  * Ensures:  *\li	'*contextp' == NULL.  */
end_comment

begin_function_decl
name|isc_mem_t
modifier|*
name|irs_context_getmctx
parameter_list|(
name|irs_context_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the memory context held in the context.  *  * Requires:  *  *\li	'context' is a valid IRS context.  */
end_comment

begin_function_decl
name|isc_appctx_t
modifier|*
name|irs_context_getappctx
parameter_list|(
name|irs_context_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the application context held in the context.  *  * Requires:  *  *\li	'context' is a valid IRS context.  */
end_comment

begin_function_decl
name|isc_taskmgr_t
modifier|*
name|irs_context_gettaskmgr
parameter_list|(
name|irs_context_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the task manager held in the context.  *  * Requires:  *  *\li	'context' is a valid IRS context.  */
end_comment

begin_function_decl
name|isc_timermgr_t
modifier|*
name|irs_context_gettimermgr
parameter_list|(
name|irs_context_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the timer manager held in the context.  *  * Requires:  *  *\li	'context' is a valid IRS context.  */
end_comment

begin_function_decl
name|isc_task_t
modifier|*
name|irs_context_gettask
parameter_list|(
name|irs_context_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the task object held in the context.  *  * Requires:  *  *\li	'context' is a valid IRS context.  */
end_comment

begin_function_decl
name|dns_client_t
modifier|*
name|irs_context_getdnsclient
parameter_list|(
name|irs_context_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the DNS client object held in the context.  *  * Requires:  *  *\li	'context' is a valid IRS context.  */
end_comment

begin_function_decl
name|irs_resconf_t
modifier|*
name|irs_context_getresconf
parameter_list|(
name|irs_context_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the resolver configuration object held in the context.  *  * Requires:  *  *\li	'context' is a valid IRS context.  */
end_comment

begin_function_decl
name|irs_dnsconf_t
modifier|*
name|irs_context_getdnsconf
parameter_list|(
name|irs_context_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the advanced DNS configuration object held in the context.  *  * Requires:  *  *\li	'context' is a valid IRS context.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRS_CONTEXT_H */
end_comment

end_unit

