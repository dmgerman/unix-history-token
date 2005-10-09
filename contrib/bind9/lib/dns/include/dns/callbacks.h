begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: callbacks.h,v 1.15.2.2.8.1 2004/03/06 08:13:51 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_CALLBACKS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_CALLBACKS_H
value|1
end_define

begin_comment
comment|/***  ***	Imports  ***/
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

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  ***	Types  ***/
end_comment

begin_struct
struct|struct
name|dns_rdatacallbacks
block|{
comment|/* 	 * dns_load_master calls this when it has rdatasets to commit. 	 */
name|dns_addrdatasetfunc_t
name|add
decl_stmt|;
comment|/* 	 * dns_load_master / dns_rdata_fromtext call this to issue a error. 	 */
name|void
function_decl|(
modifier|*
name|error
function_decl|)
parameter_list|(
name|struct
name|dns_rdatacallbacks
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/* 	 * dns_load_master / dns_rdata_fromtext call this to issue a warning. 	 */
name|void
function_decl|(
modifier|*
name|warn
function_decl|)
parameter_list|(
name|struct
name|dns_rdatacallbacks
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/* 	 * Private data handles for use by the above callback functions. 	 */
name|void
modifier|*
name|add_private
decl_stmt|;
name|void
modifier|*
name|error_private
decl_stmt|;
name|void
modifier|*
name|warn_private
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  ***	Initialization  ***/
end_comment

begin_function_decl
name|void
name|dns_rdatacallbacks_init
parameter_list|(
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize 'callbacks'.  * 	'error' and 'warn' are set to default callbacks that print the  *	error message through the DNS library log context.  *  *	All other elements are initialized to NULL.  *  * Requires:  *      'callbacks' is a valid dns_rdatacallbacks_t,  */
end_comment

begin_function_decl
name|void
name|dns_rdatacallbacks_init_stdio
parameter_list|(
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like dns_rdatacallbacks_init, but logs to stdio.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_CALLBACKS_H */
end_comment

end_unit

