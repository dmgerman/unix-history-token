begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: check.h,v 1.1.200.6 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIND9_CHECK_H
end_ifndef

begin_define
define|#
directive|define
name|BIND9_CHECK_H
value|1
end_define

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
file|<isccfg/cfg.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|bind9_check_namedconf
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|config
parameter_list|,
name|isc_log_t
modifier|*
name|logctx
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check the syntactic validity of a configuration parse tree generated from  * a named.conf file.  *  * Requires:  *	config is a valid parse tree  *  *	logctx is a valid logging context.  *  * Returns:  * 	ISC_R_SUCCESS  * 	ISC_R_FAILURE  */
end_comment

begin_function_decl
name|isc_result_t
name|bind9_check_key
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|config
parameter_list|,
name|isc_log_t
modifier|*
name|logctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * As above, but for a single 'key' statement.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIND9_CHECK_H */
end_comment

end_unit

