begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2006-2008  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: httpd.h,v 1.9 2008/08/08 05:06:49 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_HTTPD_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_HTTPD_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/event.h>
end_include

begin_include
include|#
directive|include
file|<isc/eventclass.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/task.h>
end_include

begin_define
define|#
directive|define
name|HTTPD_EVENTCLASS
value|ISC_EVENTCLASS(4300)
end_define

begin_define
define|#
directive|define
name|HTTPD_SHUTDOWN
value|(HTTPD_EVENTCLASS + 0x0001)
end_define

begin_define
define|#
directive|define
name|ISC_HTTPDMGR_FLAGSHUTTINGDOWN
value|0x00000001
end_define

begin_comment
comment|/*  * Create a new http daemon which will send, once every time period,  * a http-like header followed by HTTP data.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_httpdmgr_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_httpdclientok_t
modifier|*
name|client_ok
parameter_list|,
name|isc_httpdondestroy_t
modifier|*
name|ondestory
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|,
name|isc_timermgr_t
modifier|*
name|tmgr
parameter_list|,
name|isc_httpdmgr_t
modifier|*
modifier|*
name|httpdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_httpdmgr_shutdown
parameter_list|(
name|isc_httpdmgr_t
modifier|*
modifier|*
name|httpdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_httpdmgr_addurl
parameter_list|(
name|isc_httpdmgr_t
modifier|*
name|httpdmgr
parameter_list|,
specifier|const
name|char
modifier|*
name|url
parameter_list|,
name|isc_httpdaction_t
modifier|*
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_httpd_response
parameter_list|(
name|isc_httpd_t
modifier|*
name|httpd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_httpd_addheader
parameter_list|(
name|isc_httpd_t
modifier|*
name|httpd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_httpd_addheaderuint
parameter_list|(
name|isc_httpd_t
modifier|*
name|httpd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_httpd_endheaders
parameter_list|(
name|isc_httpd_t
modifier|*
name|httpd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_HTTPD_H */
end_comment

end_unit

