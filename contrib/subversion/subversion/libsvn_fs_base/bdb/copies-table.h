begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* copies-table.h : internal interface to ops on `copies' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_COPIES_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_COPIES_TABLE_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"../fs.h"
end_include

begin_include
include|#
directive|include
file|"../trail.h"
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
comment|/* Open a `copies' table in ENV.  If CREATE is non-zero, create    one if it doesn't exist.  Set *COPIES_P to the new table.    Return a Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_copies_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|copies_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Reserve a slot in the `copies' table in FS for a new copy operation    as part of TRAIL.  Return the slot's id in *COPY_ID_P, allocated in    POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__reserve_copy_id
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|copy_id_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create a new copy with id COPY_ID in FS as part of TRAIL.    SRC_PATH/SRC_TXN_ID are the path/transaction ID (respectively) of    the copy source, and DST_NODEREV_ID is the node revision id of the    copy destination.  KIND describes the type of copy operation.     SRC_PATH is expected to be a canonicalized filesystem path (see    svn_fs__canonicalize_abspath).     COPY_ID should generally come from a call to    svn_fs_bdb__reserve_copy_id().  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__create_copy
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|copy_id
parameter_list|,
specifier|const
name|char
modifier|*
name|src_path
parameter_list|,
specifier|const
name|char
modifier|*
name|src_txn_id
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|dst_noderev_id
parameter_list|,
name|copy_kind_t
name|kind
parameter_list|,
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Remove the copy whose name is COPY_ID from the `copies' table of    FS, as part of TRAIL.  If there is no such copy,    SVN_ERR_FS_NO_SUCH_COPY is the error returned.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__delete_copy
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|copy_id
parameter_list|,
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Retrieve the copy *COPY_P named COPY_ID from the `copies' table of    FS, as part of TRAIL.  Perform all allocations in POOL.  If    there is no such copy, SVN_ERR_FS_NO_SUCH_COPY is the error    returned.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__get_copy
parameter_list|(
name|copy_t
modifier|*
modifier|*
name|copy_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|copy_id
parameter_list|,
name|trail_t
modifier|*
name|trail
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
comment|/* SVN_LIBSVN_FS_COPIES_TABLE_H */
end_comment

end_unit

