begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: log.h,v 1.3.2.1.10.3 2004/03/08 09:05:07 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCFG_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCFG_LOG_H
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
file|<isc/log.h>
end_include

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|isc_logcategory_t
name|cfg_categories
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|isc_logmodule_t
name|cfg_modules
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CFG_LOGCATEGORY_CONFIG
value|(&cfg_categories[0])
end_define

begin_define
define|#
directive|define
name|CFG_LOGMODULE_PARSER
value|(&cfg_modules[0])
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|cfg_log_init
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make the libisccfg categories and modules available for use with the  * ISC logging library.  *  * Requires:  *	lctx is a valid logging context.  *  *	cfg_log_init() is called only once.  *  * Ensures:  * 	The catgories and modules defined above are available for  * 	use by isc_log_usechannnel() and isc_log_write().  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCCFG_LOG_H */
end_comment

end_unit

