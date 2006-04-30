begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdatasetiter.h,v 1.14.206.1 2004/03/06 08:13:59 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RDATASETITER_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RDATASETITER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS Rdataset Iterator  *  * The DNS Rdataset Iterator interface allows iteration of all of the  * rdatasets at a node.  *  * The dns_rdatasetiter_t type is like a "virtual class".  To actually use  * it, an implementation of the class is required.  This implementation is  * supplied by the database.  *  * It is the client's responsibility to call dns_rdataset_disassociate()  * on all rdatasets returned.  *  * XXX<more> XXX  *  * MP:  *	The iterator itself is not locked.  The caller must ensure  *	synchronization.  *  *	The iterator methods ensure appropriate database locking.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
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
file|<isc/stdtime.h>
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

begin_typedef
typedef|typedef
struct|struct
name|dns_rdatasetitermethods
block|{
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|dns_rdatasetiter_t
modifier|*
modifier|*
name|iteratorp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|first
function_decl|)
parameter_list|(
name|dns_rdatasetiter_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|next
function_decl|)
parameter_list|(
name|dns_rdatasetiter_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|current
function_decl|)
parameter_list|(
name|dns_rdatasetiter_t
modifier|*
name|iterator
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
block|}
name|dns_rdatasetitermethods_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_RDATASETITER_MAGIC
value|ISC_MAGIC('D','N','S','i')
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETITER_VALID
parameter_list|(
name|i
parameter_list|)
value|ISC_MAGIC_VALID(i, DNS_RDATASETITER_MAGIC)
end_define

begin_comment
comment|/*  * This structure is actually just the common prefix of a DNS db  * implementation's version of a dns_rdatasetiter_t.  *  * Direct use of this structure by clients is forbidden.  DB implementations  * may change the structure.  'magic' must be DNS_RDATASETITER_MAGIC for  * any of the dns_rdatasetiter routines to work.  DB implementations must  * maintain all DB rdataset iterator invariants.  */
end_comment

begin_struct
struct|struct
name|dns_rdatasetiter
block|{
comment|/* Unlocked. */
name|unsigned
name|int
name|magic
decl_stmt|;
name|dns_rdatasetitermethods_t
modifier|*
name|methods
decl_stmt|;
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|dns_dbnode_t
modifier|*
name|node
decl_stmt|;
name|dns_dbversion_t
modifier|*
name|version
decl_stmt|;
name|isc_stdtime_t
name|now
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|dns_rdatasetiter_destroy
parameter_list|(
name|dns_rdatasetiter_t
modifier|*
modifier|*
name|iteratorp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy '*iteratorp'.  *  * Requires:  *  *	'*iteratorp' is a valid iterator.  *  * Ensures:  *  *	All resources used by the iterator are freed.  *  *	*iteratorp == NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdatasetiter_first
parameter_list|(
name|dns_rdatasetiter_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Move the rdataset cursor to the first rdataset at the node (if any).  *  * Requires:  *	'iterator' is a valid iterator.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE			There are no rdatasets at the node.  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdatasetiter_next
parameter_list|(
name|dns_rdatasetiter_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Move the rdataset cursor to the next rdataset at the node (if any).  *  * Requires:  *	'iterator' is a valid iterator.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE			There are no more rdatasets at the  *					node.  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|void
name|dns_rdatasetiter_current
parameter_list|(
name|dns_rdatasetiter_t
modifier|*
name|iterator
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the current rdataset.  *  * Requires:  *	'iterator' is a valid iterator.  *  *	'rdataset' is a valid, disassociated rdataset.  *  *	The rdataset cursor of 'iterator' is at a valid location (i.e. the  *	result of last call to a cursor movement command was ISC_R_SUCCESS).  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RDATASETITER_H */
end_comment

end_unit

