begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2010  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: check-tool.h,v 1.16 2010-09-07 23:46:59 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHECK_TOOL_H
end_ifndef

begin_define
define|#
directive|define
name|CHECK_TOOL_H
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/masterdump.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|setup_logging
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|FILE
modifier|*
name|errout
parameter_list|,
name|isc_log_t
modifier|*
modifier|*
name|logp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|load_zone
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|char
modifier|*
name|zonename
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|dns_masterformat_t
name|fileformat
parameter_list|,
specifier|const
name|char
modifier|*
name|classname
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dump_zone
parameter_list|(
specifier|const
name|char
modifier|*
name|zonename
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|dns_masterformat_t
name|fileformat
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_function_decl
name|void
name|InitSockets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DestroySockets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_boolean_t
name|nomerge
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_boolean_t
name|docheckmx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_boolean_t
name|docheckns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_boolean_t
name|dochecksrv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|zone_options
decl_stmt|;
end_decl_stmt

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

