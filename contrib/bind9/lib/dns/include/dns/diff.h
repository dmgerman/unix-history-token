begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: diff.h,v 1.4.12.3 2004/03/08 09:04:35 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_DIFF_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_DIFF_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * A diff is a convenience type representing a list of changes to be  * made to a database.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
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
file|<dns/types.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*  * A dns_difftuple_t represents a single RR being added or deleted.  * The RR type and class are in the 'rdata' member; the class is always  * the real one, not a DynDNS meta-class, so that the rdatas can be  * compared using dns_rdata_compare().  The TTL is significant  * even for deletions, because a deletion/addition pair cannot  * be canceled out if the TTL differs (it might be an explicit  * TTL update).  *  * Tuples are also used to represent complete RRs with owner  * names for a couple of other purposes, such as the  * individual RRs of a "RRset exists (value dependent)"  * prerequisite set.  In this case, op==DNS_DIFFOP_EXISTS,  * and the TTL is ignored.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DNS_DIFFOP_ADD
block|,
comment|/* Add an RR. */
name|DNS_DIFFOP_DEL
block|,
comment|/* Delete an RR. */
name|DNS_DIFFOP_EXISTS
comment|/* Assert RR existence. */
block|}
name|dns_diffop_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_difftuple
name|dns_difftuple_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_DIFFTUPLE_MAGIC
value|ISC_MAGIC('D','I','F','T')
end_define

begin_define
define|#
directive|define
name|DNS_DIFFTUPLE_VALID
parameter_list|(
name|t
parameter_list|)
value|ISC_MAGIC_VALID(t, DNS_DIFFTUPLE_MAGIC)
end_define

begin_struct
struct|struct
name|dns_difftuple
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_diffop_t
name|op
decl_stmt|;
name|dns_name_t
name|name
decl_stmt|;
name|dns_ttl_t
name|ttl
decl_stmt|;
name|dns_rdata_t
name|rdata
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_difftuple_t
argument_list|)
name|link
expr_stmt|;
comment|/* Variable-size name data and rdata follows. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A dns_diff_t represents a set of changes being applied to  * a zone.  Diffs are also used to represent "RRset exists  * (value dependent)" prerequisites.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_diff
name|dns_diff_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_DIFF_MAGIC
value|ISC_MAGIC('D','I','F','F')
end_define

begin_define
define|#
directive|define
name|DNS_DIFF_VALID
parameter_list|(
name|t
parameter_list|)
value|ISC_MAGIC_VALID(t, DNS_DIFF_MAGIC)
end_define

begin_struct
struct|struct
name|dns_diff
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_difftuple_t
argument_list|)
name|tuples
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Type of comparision function for sorting diffs. */
end_comment

begin_typedef
typedef|typedef
name|int
name|dns_diff_compare_func
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/**************************************************************************/
comment|/*  * Maniuplation of diffs and tuples.  */
name|isc_result_t
name|dns_difftuple_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_diffop_t
name|op
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_ttl_t
name|ttl
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_difftuple_t
modifier|*
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a tuple.  Deep copies are made of the name and rdata, so  * they need not remain valid after the call.  *  * Requires:  *	*tp != NULL&& *tp == NULL.  *  * Returns:  *	ISC_R_SUCCESS  *      ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|dns_difftuple_free
parameter_list|(
name|dns_difftuple_t
modifier|*
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free a tuple.  *  * Requires:  *       **tp is a valid tuple.  *  * Ensures:  *       *tp == NULL  *       All memory used by the tuple is freed.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_difftuple_copy
parameter_list|(
name|dns_difftuple_t
modifier|*
name|orig
parameter_list|,
name|dns_difftuple_t
modifier|*
modifier|*
name|copyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy a tuple.  *  * Requires:  * 	'orig' points to a valid tuple  *	copyp != NULL&& *copyp == NULL  */
end_comment

begin_function_decl
name|void
name|dns_diff_init
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize a diff.  *  * Requires:  *    'diff' points to an uninitialized dns_diff_t  *    allocated by the caller.  *  * Ensures:  *    '*diff' is a valid, empty diff.  */
end_comment

begin_function_decl
name|void
name|dns_diff_clear
parameter_list|(
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Clear a diff, destroying all its tuples.  *  * Requires:  *    'diff' points to a valid dns_diff_t.  *  * Ensures:  *     Any tuples in the diff are destroyed.  *     The diff now empty, but it is still valid  *     and may be reused without calling dns_diff_init  *     again.  The only memory used is that of the  *     dns_diff_t structure itself.  *  * Notes:  *     Managing the memory of the dns_diff_t structure itself  *     is the caller's responsibility.  */
end_comment

begin_function_decl
name|void
name|dns_diff_append
parameter_list|(
name|dns_diff_t
modifier|*
name|diff
parameter_list|,
name|dns_difftuple_t
modifier|*
modifier|*
name|tuple
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append a single tuple to a diff.  *  *	'diff' is a valid diff.  * 	'*tuple' is a valid tuple.  *  * Ensures:  *	*tuple is NULL.  *	The tuple has been freed, or will be freed when the diff is cleared.  */
end_comment

begin_function_decl
name|void
name|dns_diff_appendminimal
parameter_list|(
name|dns_diff_t
modifier|*
name|diff
parameter_list|,
name|dns_difftuple_t
modifier|*
modifier|*
name|tuple
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append 'tuple' to 'diff', removing any duplicate  * or conflicting updates as needed to create a minimal diff.  *  * Requires:  *	'diff' is a minimal diff.  *  * Ensures:  *	'diff' is still a minimal diff.  *   	*tuple is NULL.  *   	The tuple has been freed, or will be freed when the diff is cleared.  *  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_diff_sort
parameter_list|(
name|dns_diff_t
modifier|*
name|diff
parameter_list|,
name|dns_diff_compare_func
modifier|*
name|compare
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sort 'diff' in-place according to the comparison function 'compare'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_diff_apply
parameter_list|(
name|dns_diff_t
modifier|*
name|diff
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|ver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_diff_applysilently
parameter_list|(
name|dns_diff_t
modifier|*
name|diff
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|ver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Apply 'diff' to the database 'db'.  *  * dns_diff_apply() logs warnings about updates with no effect or  * with inconsistent TTLs; dns_diff_applysilently() does not.  *  * For efficiency, the diff should be sorted by owner name.  * If it is not sorted, operation will still be correct,  * but less efficient.  *  * Requires:  *	*diff is a valid diff (possibly empty), containing  *   	tuples of type DNS_DIFFOP_ADD and/or  *   	For DNS_DIFFOP_DEL tuples, the TTL is ignored.  *  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_diff_load
parameter_list|(
name|dns_diff_t
modifier|*
name|diff
parameter_list|,
name|dns_addrdatasetfunc_t
name|addfunc
parameter_list|,
name|void
modifier|*
name|add_private
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like dns_diff_apply, but for use when loading a new database  * instead of modifying an existing one.  This bypasses the  * database transaction mechanisms.  *  * Requires:  * 	'addfunc' is a valid dns_addradatasetfunc_t obtained from  * 	dns_db_beginload()  *  *	'add_private' points to a corresponding dns_dbload_t *  *      (XXX why is it a void pointer, then?)  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_diff_print
parameter_list|(
name|dns_diff_t
modifier|*
name|diff
parameter_list|,
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Print the differences to 'file' or if 'file' is NULL via the  * logging system.  *  * Require:  *	'diff' to be valid.  *	'file' to refer to a open file or NULL.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  *	any error from dns_rdataset_totext()  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_DIFF_H */
end_comment

end_unit

