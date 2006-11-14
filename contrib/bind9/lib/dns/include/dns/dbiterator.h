begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dbiterator.h,v 1.18.206.1 2004/03/06 08:13:54 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_DBITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_DBITERATOR_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS DB Iterator  *  * The DNS DB Iterator interface allows iteration of all of the nodes in a  * database.  *  * The dns_dbiterator_t type is like a "virtual class".  To actually use  * it, an implementation of the class is required.  This implementation is  * supplied by the database.  *  * It is the client's responsibility to call dns_db_detachnode() on all  * nodes returned.  *  * XXX<more> XXX  *  * MP:  *	The iterator itself is not locked.  The caller must ensure  *	synchronization.  *  *	The iterator methods ensure appropriate database locking.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
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
name|dns_dbiteratormethods
block|{
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|dns_dbiterator_t
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
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|last
function_decl|)
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|seek
function_decl|)
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|prev
function_decl|)
parameter_list|(
name|dns_dbiterator_t
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
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|current
function_decl|)
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|pause
function_decl|)
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|origin
function_decl|)
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
block|}
name|dns_dbiteratormethods_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_DBITERATOR_MAGIC
value|ISC_MAGIC('D','N','S','I')
end_define

begin_define
define|#
directive|define
name|DNS_DBITERATOR_VALID
parameter_list|(
name|dbi
parameter_list|)
value|ISC_MAGIC_VALID(dbi, DNS_DBITERATOR_MAGIC)
end_define

begin_comment
comment|/*  * This structure is actually just the common prefix of a DNS db  * implementation's version of a dns_dbiterator_t.  *  * Clients may use the 'db' field of this structure.  Except for that field,  * direct use of this structure by clients is forbidden.  DB implementations  * may change the structure.  'magic' must be DNS_DBITERATOR_MAGIC for any of  * the dns_dbiterator routines to work.  DB iterator implementations must  * maintain all DB iterator invariants.  */
end_comment

begin_struct
struct|struct
name|dns_dbiterator
block|{
comment|/* Unlocked. */
name|unsigned
name|int
name|magic
decl_stmt|;
name|dns_dbiteratormethods_t
modifier|*
name|methods
decl_stmt|;
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|isc_boolean_t
name|relative_names
decl_stmt|;
name|isc_boolean_t
name|cleaning
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|dns_dbiterator_destroy
parameter_list|(
name|dns_dbiterator_t
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
name|dns_dbiterator_first
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Move the node cursor to the first node in the database (if any).  *  * Requires:  *	'iterator' is a valid iterator.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE			There are no nodes in the database.  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbiterator_last
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Move the node cursor to the last node in the database (if any).  *  * Requires:  *	'iterator' is a valid iterator.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE			There are no nodes in the database.  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbiterator_seek
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Move the node cursor to the node with name 'name'.  *  * Requires:  *	'iterator' is a valid iterator.  *  *	'name' is a valid name.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbiterator_prev
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Move the node cursor to the previous node in the database (if any).  *  * Requires:  *	'iterator' is a valid iterator.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE			There are no more nodes in the  *					database.  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbiterator_next
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Move the node cursor to the next node in the database (if any).  *  * Requires:  *	'iterator' is a valid iterator.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE			There are no more nodes in the  *					database.  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbiterator_current
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the current node.  *  * Notes:  *	If 'name' is not NULL, it will be set to the name of the node.  *  * Requires:  *	'iterator' is a valid iterator.  *  *	nodep != NULL&& *nodep == NULL  *  *	The node cursor of 'iterator' is at a valid location (i.e. the  *	result of last call to a cursor movement command was ISC_R_SUCCESS).  *  *	'name' is NULL, or is a valid name with a dedicated buffer.  *  * Returns:  *  *	ISC_R_SUCCESS  *	DNS_R_NEWORIGIN			If this iterator was created with  *					'relative_names' set to ISC_TRUE,  *					then DNS_R_NEWORIGIN will be returned  *					when the origin the names are  *					relative to changes.  This result  *					can occur only when 'name' is not  *					NULL.  This is also a successful  *					result.  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbiterator_pause
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Pause iteration.  *  * Calling a cursor movement method or dns_dbiterator_current() may cause  * database locks to be acquired.  Rather than reacquire these locks every  * time one of these routines is called, the locks may simply be held.  * Calling dns_dbiterator_pause() releases any such locks.  Iterator clients  * should call this routine any time they are not going to execute another  * iterator method in the immediate future.  *  * Requires:  *	'iterator' is a valid iterator.  *  * Ensures:  *	Any database locks being held for efficiency of iterator access are  *	released.  *  * Returns:  *	ISC_R_SUCCESS  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbiterator_origin
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the origin to which returned node names are relative.  *  * Requires:  *  *	'iterator' is a valid relative_names iterator.  *  *	'name' is a valid name with a dedicated buffer.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOSPACE  *  *	Other results are possible, depending on the DB implementation.  */
end_comment

begin_function_decl
name|void
name|dns_dbiterator_setcleanmode
parameter_list|(
name|dns_dbiterator_t
modifier|*
name|iterator
parameter_list|,
name|isc_boolean_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Indicate that the given iterator is/is not cleaning the DB.  *  * Notes:  *	When 'mode' is ISC_TRUE,   *  * Requires:  *	'iterator' is a valid iterator.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_DBITERATOR_H */
end_comment

end_unit

