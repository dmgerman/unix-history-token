begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* checksum-reps-table.h : internal interface to ops on `checksum-reps' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_CHECKSUM_REPS_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_CHECKSUM_REPS_TABLE_H
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
file|"svn_checksum.h"
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
comment|/* Open a `checksum-reps' table in ENV.  If CREATE is non-zero, create    one if it doesn't exist.  Set *CHECKSUM_REPS_P to the new table.    Return a Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_checksum_reps_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|checksum_reps_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Set *REP_KEY to the representation key stored as the value of key    CHECKSUM in the `checksum-reps' table.  Do this as part of TRAIL.    Use POOL for allocations.     If no such node revision ID is stored for CHECKSUM, return    SVN_ERR_FS_NO_SUCH_CHECKSUM_REP.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__get_checksum_rep
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|rep_key
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_checksum_t
modifier|*
name|checksum
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
comment|/* Store in the `checksum-reps' table a mapping of CHECKSUM to    representation key REP_KEY in FS.  Do this as part of TRAIL.  Use    POOL for temporary allocations.     WARNING: NEVER store a record that maps a checksum to a mutable    representation.  Ever.  Under pain of dismemberment and death.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__set_checksum_rep
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_checksum_t
modifier|*
name|checksum
parameter_list|,
specifier|const
name|char
modifier|*
name|rep_key
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
comment|/* Delete from the `checksum-reps' table the mapping of CHECKSUM to a    representation key in FS.  Do this as part of TRAIL.  Use POOL for    temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__delete_checksum_rep
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_checksum_t
modifier|*
name|checksum
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
comment|/* Reserve a unique reuse ID in the `checksum-reps' table in FS for a    new instance of a re-used representation as part of TRAIL.  Return    the slot's id in *REUSE_ID_P, allocated in POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__reserve_rep_reuse_id
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|reuse_id_p
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
comment|/* SVN_LIBSVN_FS_CHECKSUM_REPS_TABLE_H */
end_comment

end_unit

