begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rbtdb.h,v 1.13.206.1 2004/03/06 08:13:42 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RBTDB_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RBTDB_H
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
file|<dns/types.h>
end_include

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS Red-Black Tree DB Implementation  */
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_rbtdb_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_name_t
modifier|*
name|base
parameter_list|,
name|dns_dbtype_t
name|type
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|unsigned
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|void
modifier|*
name|driverarg
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
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
comment|/* DNS_RBTDB_H */
end_comment

end_unit

