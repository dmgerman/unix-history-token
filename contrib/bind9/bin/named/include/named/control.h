begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: control.h,v 1.6.2.2.2.9 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_CONTROL_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_CONTROL_H
value|1
end_define

begin_comment
comment|/*  * The name server command channel.  */
end_comment

begin_include
include|#
directive|include
file|<isccc/types.h>
end_include

begin_include
include|#
directive|include
file|<named/aclconf.h>
end_include

begin_include
include|#
directive|include
file|<named/types.h>
end_include

begin_define
define|#
directive|define
name|NS_CONTROL_PORT
value|953
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_STOP
value|"stop"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_HALT
value|"halt"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_RELOAD
value|"reload"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_RECONFIG
value|"reconfig"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_REFRESH
value|"refresh"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_RETRANSFER
value|"retransfer"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_DUMPSTATS
value|"stats"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_QUERYLOG
value|"querylog"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_DUMPDB
value|"dumpdb"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_TRACE
value|"trace"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_NOTRACE
value|"notrace"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_FLUSH
value|"flush"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_FLUSHNAME
value|"flushname"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_STATUS
value|"status"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_FREEZE
value|"freeze"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_UNFREEZE
value|"unfreeze"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_THAW
value|"thaw"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_RECURSING
value|"recursing"
end_define

begin_define
define|#
directive|define
name|NS_COMMAND_NULL
value|"null"
end_define

begin_function_decl
name|isc_result_t
name|ns_controls_create
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|ns_controls_t
modifier|*
modifier|*
name|ctrlsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create an initial, empty set of command channels for 'server'.  */
end_comment

begin_function_decl
name|void
name|ns_controls_destroy
parameter_list|(
name|ns_controls_t
modifier|*
modifier|*
name|ctrlsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a set of command channels.  *  * Requires:  *	Shutdown of the channels has completed.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_controls_configure
parameter_list|(
name|ns_controls_t
modifier|*
name|controls
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|config
parameter_list|,
name|ns_aclconfctx_t
modifier|*
name|aclconfctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Configure zero or more command channels into 'controls'  * as defined in the configuration parse tree 'config'.  * The channels will evaluate ACLs in the context of  * 'aclconfctx'.  */
end_comment

begin_function_decl
name|void
name|ns_controls_shutdown
parameter_list|(
name|ns_controls_t
modifier|*
name|controls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initiate shutdown of all the command channels in 'controls'.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_control_docommand
parameter_list|(
name|isccc_sexpr_t
modifier|*
name|message
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_CONTROL_H */
end_comment

end_unit

