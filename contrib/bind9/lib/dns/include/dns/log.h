begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: log.h,v 1.30.2.1.10.2 2004/03/06 08:13:57 marka Exp $ */
end_comment

begin_comment
comment|/* Principal Authors: DCL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_LOG_H
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
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|isc_log_t
modifier|*
name|dns_lctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|isc_logcategory_t
name|dns_categories
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
name|isc_logmodule_t
name|dns_modules
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_NOTIFY
value|(&dns_categories[0])
end_define

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_DATABASE
value|(&dns_categories[1])
end_define

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_SECURITY
value|(&dns_categories[2])
end_define

begin_comment
comment|/* DNS_LOGCATEGORY_CONFIG superseded by CFG_LOGCATEGORY_CONFIG */
end_comment

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_DNSSEC
value|(&dns_categories[4])
end_define

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_RESOLVER
value|(&dns_categories[5])
end_define

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_XFER_IN
value|(&dns_categories[6])
end_define

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_XFER_OUT
value|(&dns_categories[7])
end_define

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_DISPATCH
value|(&dns_categories[8])
end_define

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_LAME_SERVERS
value|(&dns_categories[9])
end_define

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_DELEGATION_ONLY
value|(&dns_categories[10])
end_define

begin_comment
comment|/* Backwards compatibility. */
end_comment

begin_define
define|#
directive|define
name|DNS_LOGCATEGORY_GENERAL
value|ISC_LOGCATEGORY_GENERAL
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_DB
value|(&dns_modules[0])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_RBTDB
value|(&dns_modules[1])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_RBTDB64
value|(&dns_modules[2])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_RBT
value|(&dns_modules[3])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_RDATA
value|(&dns_modules[4])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_MASTER
value|(&dns_modules[5])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_MESSAGE
value|(&dns_modules[6])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_CACHE
value|(&dns_modules[7])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_CONFIG
value|(&dns_modules[8])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_RESOLVER
value|(&dns_modules[9])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_ZONE
value|(&dns_modules[10])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_JOURNAL
value|(&dns_modules[11])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_ADB
value|(&dns_modules[12])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_XFER_IN
value|(&dns_modules[13])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_XFER_OUT
value|(&dns_modules[14])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_ACL
value|(&dns_modules[15])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_VALIDATOR
value|(&dns_modules[16])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_DISPATCH
value|(&dns_modules[17])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_REQUEST
value|(&dns_modules[18])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_MASTERDUMP
value|(&dns_modules[19])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_TSIG
value|(&dns_modules[20])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_TKEY
value|(&dns_modules[21])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_SDB
value|(&dns_modules[22])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_DIFF
value|(&dns_modules[23])
end_define

begin_define
define|#
directive|define
name|DNS_LOGMODULE_HINTS
value|(&dns_modules[24])
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|dns_log_init
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make the libdns categories and modules available for use with the  * ISC logging library.  *  * Requires:  *	lctx is a valid logging context.  *  *	dns_log_init() is called only once.  *  * Ensures:  * 	The catgories and modules defined above are available for  * 	use by isc_log_usechannnel() and isc_log_write().  */
end_comment

begin_function_decl
name|void
name|dns_log_setcontext
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make the libdns library use the provided context for logging internal  * messages.  *  * Requires:  *	lctx is a valid logging context.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_LOG_H */
end_comment

end_unit

