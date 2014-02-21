begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* changes-table.h : internal interface to `changes' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_CHANGES_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_CHANGES_TABLE_H
end_define

begin_define
define|#
directive|define
name|SVN_WANT_BDB
end_define

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

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
comment|/* Open a `changes' table in ENV.  If CREATE is non-zero, create one    if it doesn't exist.  Set *CHANGES_P to the new table.  Return a    Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_changes_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|changes_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Add CHANGE as a record to the `changes' table in FS as part of    TRAIL, keyed on KEY.     CHANGE->path is expected to be a canonicalized filesystem path (see    svn_fs__canonicalize_abspath).     Note that because the `changes' table uses duplicate keys, this    function will not overwrite prior additions that have the KEY    key, but simply adds this new record alongside previous ones.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__changes_add
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|change_t
modifier|*
name|change
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
comment|/* Remove all changes associated with KEY from the `changes' table in    FS, as part of TRAIL. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__changes_delete
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|key
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
comment|/* Return a hash *CHANGES_P, keyed on const char * paths, and    containing svn_fs_path_change2_t * values representing summarized    changed records associated with KEY in FS, as part of TRAIL.    Allocate the array and its items in POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__changes_fetch
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|changes_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|key
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
comment|/* Return an array *CHANGES_P of change_t * items representing    all the change records associated with KEY in FS, as part of TRAIL.    Allocate the array and its items in POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__changes_fetch_raw
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|changes_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|key
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
comment|/* SVN_LIBSVN_FS_CHANGES_TABLE_H */
end_comment

end_unit

