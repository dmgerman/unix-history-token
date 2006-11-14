begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: nsec.h,v 1.4.2.1 2004/03/08 02:08:00 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_NSEC_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_NSEC_H
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

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_define
define|#
directive|define
name|DNS_NSEC_BUFFERSIZE
value|(DNS_NAME_MAXWIRE + 8192 + 512)
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_nsec_buildrdata
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_name_t
modifier|*
name|target
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Build the rdata of a NSEC record.  *  * Requires:  *	buffer	Points to a temporary buffer of at least  * 		DNS_NSEC_BUFFERSIZE bytes.  *	rdata	Points to an initialized dns_rdata_t.  *  * Ensures:  *      *rdata	Contains a valid NSEC rdata.  The 'data' member refers  *		to 'buffer'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_nsec_build
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_name_t
modifier|*
name|target
parameter_list|,
name|dns_ttl_t
name|ttl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Build a NSEC record and add it to a database.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_nsec_typepresent
parameter_list|(
name|dns_rdata_t
modifier|*
name|nsec
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Determine if a type is marked as present in an NSEC record.  *  * Requires:  *	'nsec' points to a valid rdataset of type NSEC  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_NSEC_H */
end_comment

end_unit

