begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: tkeyconf.h,v 1.9.208.3 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NS_TKEYCONF_H
end_ifndef

begin_define
define|#
directive|define
name|NS_TKEYCONF_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/cfg.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|ns_tkeyctx_fromconfig
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|options
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_entropy_t
modifier|*
name|ectx
parameter_list|,
name|dns_tkeyctx_t
modifier|*
modifier|*
name|tctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * 	Create a TKEY context and configure it, including the default DH key  *	and default domain, according to 'options'.  *  *	Requires:  *		'cfg' is a valid configuration options object.  *		'mctx' is not NULL  *		'ectx' is not NULL  *		'tctx' is not NULL  *		'*tctx' is NULL  *  *	Returns:  *		ISC_R_SUCCESS  *		ISC_R_NOMEMORY  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NS_TKEYCONF_H */
end_comment

end_unit

