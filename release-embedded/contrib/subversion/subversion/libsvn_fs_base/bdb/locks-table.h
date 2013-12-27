begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* locks-table.h : internal interface to ops on `locks' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_LOCKS_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_LOCKS_TABLE_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"../trail.h"
end_include

begin_include
include|#
directive|include
file|"../fs.h"
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
comment|/* Open a `locks' table in ENV.  If CREATE is non-zero, create    one if it doesn't exist.  Set *LOCKS_P to the new table.    Return a Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_locks_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|locks_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Add a lock to the `locks' table in FS, as part of TRAIL.     Use LOCK_TOKEN as the key, presumably a string form of an apr_uuid_t.    Convert LOCK into a skel and store it as the value.     Warning:  if LOCK_TOKEN already exists as a key, then its value    will be overwritten. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__lock_add
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|lock_token
parameter_list|,
name|svn_lock_t
modifier|*
name|lock
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
comment|/* Remove the lock whose key is LOCK_TOKEN from the `locks' table of    FS, as part of TRAIL.     Return SVN_ERR_FS_BAD_LOCK_TOKEN if LOCK_TOKEN does not exist as a    table key. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__lock_delete
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|lock_token
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
comment|/* Retrieve the lock *LOCK_P pointed to by LOCK_TOKEN from the `locks'    table of FS, as part of TRAIL.  Perform all allocations in POOL.     Return SVN_ERR_FS_BAD_LOCK_TOKEN if LOCK_TOKEN does not exist as a    table key.     Before returning LOCK_P, check its expiration date.  If expired,    remove the row from the `locks' table and return SVN_ERR_FS_LOCK_EXPIRED.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__lock_get
parameter_list|(
name|svn_lock_t
modifier|*
modifier|*
name|lock_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|lock_token
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
comment|/* Retrieve locks representing all locks that exist at or below PATH    in FS. Pass each lock to GET_LOCKS_FUNC callback along with    GET_LOCKS_BATON.     Use DEPTH to filter the reported locks to only those within the    requested depth of PATH.     This function promises to auto-expire any locks encountered while    building the hash.  That means that the caller can trust that each    returned lock hasn't yet expired. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__locks_get
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|svn_depth_t
name|depth
parameter_list|,
name|svn_fs_get_locks_callback_t
name|get_locks_func
parameter_list|,
name|void
modifier|*
name|get_locks_baton
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
comment|/* SVN_LIBSVN_FS_LOCKS_TABLE_H */
end_comment

end_unit

