begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: statschannel.h,v 1.3 2008-04-03 05:55:51 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_STATSCHANNEL_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_STATSCHANNEL_H
value|1
end_define

begin_comment
comment|/*! \file  * \brief  * The statistics channels built-in the name server.  */
end_comment

begin_include
include|#
directive|include
file|<isccc/types.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/aclconf.h>
end_include

begin_include
include|#
directive|include
file|<named/types.h>
end_include

begin_define
define|#
directive|define
name|NS_STATSCHANNEL_HTTPPORT
value|80
end_define

begin_function_decl
name|isc_result_t
name|ns_statschannels_configure
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|config
parameter_list|,
name|cfg_aclconfctx_t
modifier|*
name|aclconfctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * [Re]configure the statistics channels.  *  * If it is no longer there but was previously configured, destroy  * it here.  *  * If the IP address or port has changed, destroy the old server  * and create a new one.  */
end_comment

begin_function_decl
name|void
name|ns_statschannels_shutdown
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Initiate shutdown of all the statistics channel listeners.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_stats_dump
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump statistics counters managed by the server to the file fp.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_STATSCHANNEL_H */
end_comment

end_unit

