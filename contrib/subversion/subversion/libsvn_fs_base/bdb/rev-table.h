begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rev-table.h : internal interface to revision table operations  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_REV_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_REV_TABLE_H
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
comment|/* Creating and opening the `revisions' table.  */
comment|/* Open a `revisions' table in ENV.  If CREATE is non-zero, create one    if it doesn't exist.  Set *REVS_P to the new table.  Return a    Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_revisions_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|revisions_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Storing and retrieving filesystem revisions.  */
comment|/* Set *REVISION_P to point to the revision structure for the    filesystem revision REV in FS, as part of TRAIL.  Perform all    allocations in POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__get_rev
parameter_list|(
name|revision_t
modifier|*
modifier|*
name|revision_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
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
comment|/* Store REVISION in FS as revision *REV as part of TRAIL.  If *REV is    an invalid revision number, create a brand new revision and return    its revision number as *REV to the caller.  Do any necessary    temporary allocation in POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__put_rev
parameter_list|(
name|svn_revnum_t
modifier|*
name|rev
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|revision_t
modifier|*
name|revision
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
comment|/* Set *YOUNGEST_P to the youngest revision in filesystem FS,    as part of TRAIL.  Use POOL for all temporary allocation. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__youngest_rev
parameter_list|(
name|svn_revnum_t
modifier|*
name|youngest_p
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
comment|/* SVN_LIBSVN_FS_REV_TABLE_H */
end_comment

end_unit

