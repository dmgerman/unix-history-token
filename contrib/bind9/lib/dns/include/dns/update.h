begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: update.h,v 1.5 2011/08/30 23:46:53 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_UPDATE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_UPDATE_H
value|1
end_define

begin_comment
comment|/*! \file dns/update.h */
end_comment

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/diff.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg
decl_stmt|;
block|}
name|dns_update_log_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  ***	Functions  ***/
name|isc_uint32_t
name|dns_update_soaserial
parameter_list|(
name|isc_uint32_t
name|serial
parameter_list|,
name|dns_updatemethod_t
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the next serial number after 'serial', depending on the  * update method 'method':  *  *\li	* dns_updatemethod_increment increments the serial number by one  *\li	* dns_updatemethod_unixtime sets the serial number to the current  *	  time (seconds since UNIX epoch) if possible, or increments by one  *	  if not.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_update_signatures
parameter_list|(
name|dns_update_log_t
modifier|*
name|log
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|oldver
parameter_list|,
name|dns_dbversion_t
modifier|*
name|newver
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|,
name|isc_uint32_t
name|sigvalidityinterval
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_UPDATE_H */
end_comment

end_unit

