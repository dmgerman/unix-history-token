begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: log.h,v 1.19.12.3 2004/03/08 04:04:21 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_LOG_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/log.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/log.h>
end_include

begin_include
include|#
directive|include
file|<named/globals.h>
end_include

begin_comment
comment|/* Required for ns_g_(categories|modules). */
end_comment

begin_comment
comment|/* Unused slot 0. */
end_comment

begin_define
define|#
directive|define
name|NS_LOGCATEGORY_CLIENT
value|(&ns_g_categories[1])
end_define

begin_define
define|#
directive|define
name|NS_LOGCATEGORY_NETWORK
value|(&ns_g_categories[2])
end_define

begin_define
define|#
directive|define
name|NS_LOGCATEGORY_UPDATE
value|(&ns_g_categories[3])
end_define

begin_define
define|#
directive|define
name|NS_LOGCATEGORY_QUERIES
value|(&ns_g_categories[4])
end_define

begin_define
define|#
directive|define
name|NS_LOGCATEGORY_UNMATCHED
value|(&ns_g_categories[5])
end_define

begin_define
define|#
directive|define
name|NS_LOGCATEGORY_UPDATE_SECURITY
value|(&ns_g_categories[6])
end_define

begin_comment
comment|/*  * Backwards compatibility.  */
end_comment

begin_define
define|#
directive|define
name|NS_LOGCATEGORY_GENERAL
value|ISC_LOGCATEGORY_GENERAL
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_MAIN
value|(&ns_g_modules[0])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_CLIENT
value|(&ns_g_modules[1])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_SERVER
value|(&ns_g_modules[2])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_QUERY
value|(&ns_g_modules[3])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_INTERFACEMGR
value|(&ns_g_modules[4])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_UPDATE
value|(&ns_g_modules[5])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_XFER_IN
value|(&ns_g_modules[6])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_XFER_OUT
value|(&ns_g_modules[7])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_NOTIFY
value|(&ns_g_modules[8])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_CONTROL
value|(&ns_g_modules[9])
end_define

begin_define
define|#
directive|define
name|NS_LOGMODULE_LWRESD
value|(&ns_g_modules[10])
end_define

begin_function_decl
name|isc_result_t
name|ns_log_init
parameter_list|(
name|isc_boolean_t
name|safe
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize the logging system and set up an initial default  * logging default configuration that will be used until the  * config file has been read.  *  * If 'safe' is true, use a default configuration that refrains  * from opening files.  This is to avoid creating log files  * as root.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_log_setdefaultchannels
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set up logging channels according to the named defaults, which  * may differ from the logging library defaults.  Currently,  * this just means setting up default_debug.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_log_setsafechannels
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like ns_log_setdefaultchannels(), but omits any logging to files.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_log_setdefaultcategory
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set up "category default" to go to the right places.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_log_setunmatchedcategory
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set up "category unmatched" to go to the right places.  */
end_comment

begin_function_decl
name|void
name|ns_log_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_LOG_H */
end_comment

end_unit

