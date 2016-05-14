begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* id.h : interface to node ID functions, private to libsvn_fs_fs  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_FS_ID_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_FS_ID_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_fs_fs_private.h"
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
comment|/*** Operations on ID parts. ***/
comment|/* Return TRUE, if both elements of the PART is 0, i.e. this is the default  * value if e.g. no copies were made of this node. */
name|svn_boolean_t
name|svn_fs_fs__id_part_is_root
parameter_list|(
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|part
parameter_list|)
function_decl|;
comment|/* Return TRUE, if all element values of *LHS and *RHS match. */
name|svn_boolean_t
name|svn_fs_fs__id_part_eq
parameter_list|(
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|lhs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|rhs
parameter_list|)
function_decl|;
comment|/* Return TRUE, if TXN_ID is used, i.e. doesn't contain just the defaults. */
name|svn_boolean_t
name|svn_fs_fs__id_txn_used
parameter_list|(
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|)
function_decl|;
comment|/* Reset TXN_ID to the defaults. */
name|void
name|svn_fs_fs__id_txn_reset
parameter_list|(
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|)
function_decl|;
comment|/* Parse the transaction id in DATA and store the result in *TXN_ID */
name|svn_error_t
modifier|*
name|svn_fs_fs__id_txn_parse
parameter_list|(
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/* Convert the transaction id in *TXN_ID into a textual representation  * allocated in POOL. */
specifier|const
name|char
modifier|*
name|svn_fs_fs__id_txn_unparse
parameter_list|(
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/*** ID accessor functions. ***/
comment|/* Get the "node id" portion of ID. */
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|svn_fs_fs__id_node_id
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Get the "copy id" portion of ID. */
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|svn_fs_fs__id_copy_id
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Get the "txn id" portion of ID, or NULL if it is a permanent ID. */
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|svn_fs_fs__id_txn_id
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Get the "rev,item" portion of ID. */
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|svn_fs_fs__id_rev_item
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Get the "rev" portion of ID, or SVN_INVALID_REVNUM if it is a    transaction ID. */
name|svn_revnum_t
name|svn_fs_fs__id_rev
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Access the "item" portion of the ID, or 0 if it is a transaction    ID. */
name|apr_uint64_t
name|svn_fs_fs__id_item
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Return TRUE, if this is a transaction ID. */
name|svn_boolean_t
name|svn_fs_fs__id_is_txn
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Convert ID into string form, allocated in POOL. */
name|svn_string_t
modifier|*
name|svn_fs_fs__id_unparse
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return true if A and B are equal. */
name|svn_boolean_t
name|svn_fs_fs__id_eq
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|a
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/* Return true if A and B are related. */
name|svn_boolean_t
name|svn_fs_fs__id_check_related
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|a
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/* Return the noderev relationship between A and B. */
name|svn_fs_node_relation_t
name|svn_fs_fs__id_compare
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|a
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/* Return 0 if A and B are equal, 1 if A is "greater than" B, -1 otherwise. */
name|int
name|svn_fs_fs__id_part_compare
parameter_list|(
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|a
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/* Create the txn root ID for transaction TXN_ID.  Allocate it in POOL. */
name|svn_fs_id_t
modifier|*
name|svn_fs_fs__id_txn_create_root
parameter_list|(
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create the root ID for REVISION (logical addressing node only).    Allocate it in POOL. */
name|svn_fs_id_t
modifier|*
name|svn_fs_fs__id_create_root
parameter_list|(
specifier|const
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create an ID within a transaction based on NODE_ID, COPY_ID, and    TXN_ID, allocated in POOL. */
name|svn_fs_id_t
modifier|*
name|svn_fs_fs__id_txn_create
parameter_list|(
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|node_id
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|copy_id
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create a permanent ID based on NODE_ID, COPY_ID and REV_ITEM,    allocated in POOL. */
name|svn_fs_id_t
modifier|*
name|svn_fs_fs__id_rev_create
parameter_list|(
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|node_id
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|copy_id
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|rev_item
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return a copy of ID, allocated from POOL. */
name|svn_fs_id_t
modifier|*
name|svn_fs_fs__id_copy
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return an ID in *ID_P resulting from parsing the string DATA, or an error    if DATA is an invalid ID string. *DATA will be modified / invalidated by    this call. */
name|svn_error_t
modifier|*
name|svn_fs_fs__id_parse
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
modifier|*
name|id_p
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* (de-)serialization support*/
struct_decl|struct
name|svn_temp_serializer__context_t
struct_decl|;
comment|/**  * Serialize an @a id within the serialization @a context.  */
name|void
name|svn_fs_fs__id_serialize
parameter_list|(
name|struct
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
specifier|const
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/**  * Deserialize an @a id within the @a buffer.  */
name|void
name|svn_fs_fs__id_deserialize
parameter_list|(
name|void
modifier|*
name|buffer
parameter_list|,
name|svn_fs_id_t
modifier|*
modifier|*
name|id
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
comment|/* SVN_LIBSVN_FS_FS_ID_H */
end_comment

end_unit

