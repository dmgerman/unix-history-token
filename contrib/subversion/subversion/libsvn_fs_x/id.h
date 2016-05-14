begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* id.h : interface to FSX-internal ID functions  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_X_ID_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_X_ID_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/* Unique identifier for a transaction within the given repository. */
typedef|typedef
name|apr_int64_t
name|svn_fs_x__txn_id_t
typedef|;
comment|/* svn_fs_x__txn_id_t value for everything that is not a transaction. */
define|#
directive|define
name|SVN_FS_X__INVALID_TXN_ID
value|((svn_fs_x__txn_id_t)(-1))
comment|/* Change set is the umbrella term for transaction and revision in FSX.  * Revision numbers (>=0) map 1:1 onto change sets while txns are mapped  * onto the negatve value range. */
typedef|typedef
name|apr_int64_t
name|svn_fs_x__change_set_t
typedef|;
comment|/* Invalid / unused change set number. */
define|#
directive|define
name|SVN_FS_X__INVALID_CHANGE_SET
value|((svn_fs_x__change_set_t)(-1))
comment|/* Return TRUE iff the CHANGE_SET refers to a revision    (will return FALSE for SVN_INVALID_REVNUM). */
name|svn_boolean_t
name|svn_fs_x__is_revision
parameter_list|(
name|svn_fs_x__change_set_t
name|change_set
parameter_list|)
function_decl|;
comment|/* Return TRUE iff the CHANGE_SET refers to a transaction    (will return FALSE for SVN_FS_X__INVALID_TXN_ID). */
name|svn_boolean_t
name|svn_fs_x__is_txn
parameter_list|(
name|svn_fs_x__change_set_t
name|change_set
parameter_list|)
function_decl|;
comment|/* Return the revision number that corresponds to CHANGE_SET.    Will SVN_INVALID_REVNUM for transactions. */
name|svn_revnum_t
name|svn_fs_x__get_revnum
parameter_list|(
name|svn_fs_x__change_set_t
name|change_set
parameter_list|)
function_decl|;
comment|/* Return the transaction ID that corresponds to CHANGE_SET.    Will SVN_FS_X__INVALID_TXN_ID for revisions. */
name|svn_fs_x__txn_id_t
name|svn_fs_x__get_txn_id
parameter_list|(
name|svn_fs_x__change_set_t
name|change_set
parameter_list|)
function_decl|;
comment|/* Convert REVNUM into a change set number */
name|svn_fs_x__change_set_t
name|svn_fs_x__change_set_by_rev
parameter_list|(
name|svn_revnum_t
name|revnum
parameter_list|)
function_decl|;
comment|/* Convert TXN_ID into a change set number */
name|svn_fs_x__change_set_t
name|svn_fs_x__change_set_by_txn
parameter_list|(
name|svn_fs_x__txn_id_t
name|txn_id
parameter_list|)
function_decl|;
comment|/* An ID in FSX consists of a creation CHANGE_SET number and some changeset-  * local counter value (NUMBER).  */
typedef|typedef
struct|struct
name|svn_fs_x__id_t
block|{
name|svn_fs_x__change_set_t
name|change_set
decl_stmt|;
name|apr_uint64_t
name|number
decl_stmt|;
block|}
name|svn_fs_x__id_t
typedef|;
comment|/*** Operations on ID parts. ***/
comment|/* Return TRUE, if both elements of the PART is 0, i.e. this is the default  * value if e.g. no copies were made of this node. */
name|svn_boolean_t
name|svn_fs_x__id_is_root
parameter_list|(
specifier|const
name|svn_fs_x__id_t
modifier|*
name|part
parameter_list|)
function_decl|;
comment|/* Return TRUE, if all element values of *LHS and *RHS match. */
name|svn_boolean_t
name|svn_fs_x__id_eq
parameter_list|(
specifier|const
name|svn_fs_x__id_t
modifier|*
name|lhs
parameter_list|,
specifier|const
name|svn_fs_x__id_t
modifier|*
name|rhs
parameter_list|)
function_decl|;
comment|/* Parse the NUL-terminated ID part at DATA and write the result into *PART.  */
name|svn_error_t
modifier|*
name|svn_fs_x__id_parse
parameter_list|(
name|svn_fs_x__id_t
modifier|*
name|part
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/* Convert ID into string form, allocated in RESULT_POOL. */
name|svn_string_t
modifier|*
name|svn_fs_x__id_unparse
parameter_list|(
specifier|const
name|svn_fs_x__id_t
modifier|*
name|id
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Set *PART to "unused". */
name|void
name|svn_fs_x__id_reset
parameter_list|(
name|svn_fs_x__id_t
modifier|*
name|part
parameter_list|)
function_decl|;
comment|/* Return TRUE if *PART is belongs to either a revision or transaction. */
name|svn_boolean_t
name|svn_fs_x__id_used
parameter_list|(
specifier|const
name|svn_fs_x__id_t
modifier|*
name|part
parameter_list|)
function_decl|;
comment|/* Return 0 if A and B are equal, 1 if A is "greater than" B, -1 otherwise. */
name|int
name|svn_fs_x__id_compare
parameter_list|(
specifier|const
name|svn_fs_x__id_t
modifier|*
name|a
parameter_list|,
specifier|const
name|svn_fs_x__id_t
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/* Set *NODEREV_ID to the root node ID of transaction TXN_ID. */
name|void
name|svn_fs_x__init_txn_root
parameter_list|(
name|svn_fs_x__id_t
modifier|*
name|noderev_id
parameter_list|,
name|svn_fs_x__txn_id_t
name|txn_id
parameter_list|)
function_decl|;
comment|/* Set *NODEREV_ID to the root node ID of revision REV. */
name|void
name|svn_fs_x__init_rev_root
parameter_list|(
name|svn_fs_x__id_t
modifier|*
name|noderev_id
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_LIBSVN_FS_X_ID_H */
end_comment

end_unit

