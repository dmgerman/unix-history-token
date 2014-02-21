begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* id.h : interface to node ID functions, private to libsvn_fs_base  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_BASE_ID_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_BASE_ID_H
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
comment|/*** ID accessor functions. ***/
comment|/* Get the "node id" portion of ID. */
specifier|const
name|char
modifier|*
name|svn_fs_base__id_node_id
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Get the "copy id" portion of ID. */
specifier|const
name|char
modifier|*
name|svn_fs_base__id_copy_id
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* Get the "txn id" portion of ID. */
specifier|const
name|char
modifier|*
name|svn_fs_base__id_txn_id
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
name|svn_fs_base__id_unparse
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
name|svn_fs_base__id_eq
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
name|svn_fs_base__id_check_related
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
comment|/* Return 0 if A and B are equal, 1 if they are related, -1 otherwise. */
name|int
name|svn_fs_base__id_compare
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
comment|/* Create an ID based on NODE_ID, COPY_ID, and TXN_ID, allocated in    POOL. */
name|svn_fs_id_t
modifier|*
name|svn_fs_base__id_create
parameter_list|(
specifier|const
name|char
modifier|*
name|node_id
parameter_list|,
specifier|const
name|char
modifier|*
name|copy_id
parameter_list|,
specifier|const
name|char
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return a copy of ID, allocated from POOL. */
name|svn_fs_id_t
modifier|*
name|svn_fs_base__id_copy
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
comment|/* Return an ID resulting from parsing the string DATA (with length    LEN), or NULL if DATA is an invalid ID string. */
name|svn_fs_id_t
modifier|*
name|svn_fs_base__id_parse
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
comment|/* SVN_LIBSVN_FS_ID_H */
end_comment

end_unit

