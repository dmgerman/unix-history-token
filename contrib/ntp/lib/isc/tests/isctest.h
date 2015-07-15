begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011, 2012  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<isc/entropy.h>
end_include

begin_include
include|#
directive|include
file|<isc/hash.h>
end_include

begin_include
include|#
directive|include
file|<isc/log.h>
end_include

begin_include
include|#
directive|include
file|<isc/mem.h>
end_include

begin_include
include|#
directive|include
file|<isc/print.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<isc/string.h>
end_include

begin_include
include|#
directive|include
file|<isc/task.h>
end_include

begin_include
include|#
directive|include
file|<isc/timer.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|r
parameter_list|)
define|\
value|do { \ 		result = (r); \ 		if (result != ISC_R_SUCCESS) \ 			goto cleanup; \ 	} while (0)
end_define

begin_decl_stmt
specifier|extern
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_entropy_t
modifier|*
name|ectx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_log_t
modifier|*
name|lctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_taskmgr_t
modifier|*
name|taskmgr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|isc_timermgr_t
modifier|*
name|timermgr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|isc_socketmgr_t
modifier|*
name|socketmgr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ncpus
decl_stmt|;
end_decl_stmt

begin_function_decl
name|isc_result_t
name|isc_test_begin
parameter_list|(
name|FILE
modifier|*
name|logfile
parameter_list|,
name|isc_boolean_t
name|start_managers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_test_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_test_nap
parameter_list|(
name|isc_uint32_t
name|usec
parameter_list|)
function_decl|;
end_function_decl

end_unit

