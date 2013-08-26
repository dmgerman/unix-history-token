begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009, 2011  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rriterator.h,v 1.4 2011/11/01 23:47:00 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RRITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RRITERATOR_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file dns/rriterator.h  * \brief  * Functions for "walking" a zone database, visiting each RR or RRset in turn.  */
end_comment

begin_comment
comment|/*****  ***** Imports  *****/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/ondestroy.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<dns/db.h>
end_include

begin_include
include|#
directive|include
file|<dns/dbiterator.h>
end_include

begin_include
include|#
directive|include
file|<dns/fixedname.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdata.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdataset.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdatasetiter.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*****  ***** Types  *****/
end_comment

begin_comment
comment|/*%  * A dns_rriterator_t is an iterator that iterates over an entire database,  * returning one RR at a time, in some arbitrary order.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_rriterator
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|dns_dbiterator_t
modifier|*
name|dbit
decl_stmt|;
name|dns_dbversion_t
modifier|*
name|ver
decl_stmt|;
name|isc_stdtime_t
name|now
decl_stmt|;
name|dns_dbnode_t
modifier|*
name|node
decl_stmt|;
name|dns_fixedname_t
name|fixedname
decl_stmt|;
name|dns_rdatasetiter_t
modifier|*
name|rdatasetit
decl_stmt|;
name|dns_rdataset_t
name|rdataset
decl_stmt|;
name|dns_rdata_t
name|rdata
decl_stmt|;
block|}
name|dns_rriterator_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RRITERATOR_MAGIC
value|ISC_MAGIC('R', 'R', 'I', 't')
end_define

begin_define
define|#
directive|define
name|VALID_RRITERATOR
parameter_list|(
name|m
parameter_list|)
value|ISC_MAGIC_VALID(m, RRITERATOR_MAGIC)
end_define

begin_function_decl
name|isc_result_t
name|dns_rriterator_init
parameter_list|(
name|dns_rriterator_t
modifier|*
name|it
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|ver
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Initialize an rriterator; sets the cursor to the origin node  * of the database.  *  * Requires:  *  * \li	'db' is a valid database.  *  * Returns:  *  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rriterator_first
parameter_list|(
name|dns_rriterator_t
modifier|*
name|it
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Move the rriterator cursor to the first rdata in the database.  *  * Requires:  *\li	'it' is a valid, initialized rriterator  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMORE			There are no rdata in the set.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rriterator_nextrrset
parameter_list|(
name|dns_rriterator_t
modifier|*
name|it
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Move the rriterator cursor to the next rrset in the database,  * skipping over any remaining records that have the same rdatatype  * as the current one.  *  * Requires:  *\li	'it' is a valid, initialized rriterator  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMORE			No more rrsets in the database  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rriterator_next
parameter_list|(
name|dns_rriterator_t
modifier|*
name|it
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Move the rriterator cursor to the next rrset in the database,  * skipping over any remaining records that have the same rdatatype  * as the current one.  *  * Requires:  *\li	'it' is a valid, initialized rriterator  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMORE			No more records in the database  */
end_comment

begin_function_decl
name|void
name|dns_rriterator_current
parameter_list|(
name|dns_rriterator_t
modifier|*
name|it
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|name
parameter_list|,
name|isc_uint32_t
modifier|*
name|ttl
parameter_list|,
name|dns_rdataset_t
modifier|*
modifier|*
name|rdataset
parameter_list|,
name|dns_rdata_t
modifier|*
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make '*name' refer to the current name.  If 'rdataset' is not NULL,  * make '*rdataset' refer to the current * rdataset.  If '*rdata' is not  * NULL, make '*rdata' refer to the current record.  *  * Requires:  *\li	'*name' is a valid name object  *\li	'rdataset' is NULL or '*rdataset' is NULL  *\li	'rdata' is NULL or '*rdata' is NULL  *  * Ensures:  *\li	'rdata' refers to the rdata at the rdata cursor location of  *\li	'rdataset'.  */
end_comment

begin_function_decl
name|void
name|dns_rriterator_pause
parameter_list|(
name|dns_rriterator_t
modifier|*
name|it
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Pause rriterator.  Frees any locks held by the database iterator.  * Callers should use this routine any time they are not going to  * execute another rriterator method in the immediate future.  *  * Requires:  *\li	'it' is a valid iterator.  *  * Ensures:  *\li	Any database locks being held for efficiency of iterator access are  *	released.  */
end_comment

begin_function_decl
name|void
name|dns_rriterator_destroy
parameter_list|(
name|dns_rriterator_t
modifier|*
name|it
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Shut down and free resources in rriterator 'it'.  *  * Requires:  *  *\li	'it' is a valid iterator.  *  * Ensures:  *  *\li	All resources used by the rriterator are freed.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RRITERATOR_H */
end_comment

end_unit

