begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pack.h : interface FSX pack functionality  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__PACK_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__PACK_H
end_define

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_comment
comment|/* Possibly pack the repository at PATH.  This just take full shards, and    combines all the revision files into a single one, with a manifest header.    Use optional CANCEL_FUNC/CANCEL_BATON for cancellation support.    Use SCRATCH_POOL for temporary allocations.     Existing filesystem references need not change.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__pack
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_pack_notify_t
name|notify_func
parameter_list|,
name|void
modifier|*
name|notify_baton
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * For the packed revision REV in FS,  determine the offset within the  * revision pack file and return it in REV_OFFSET.  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_packed_offset
parameter_list|(
name|apr_off_t
modifier|*
name|rev_offset
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the svn_dir_entry_t* objects of DIRECTORY in an APR array  * allocated in RESULT_POOL with entries added in storage (on-disk) order.  * FS' format will be used to pick the optimal ordering strategy.  Use  * SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|apr_array_header_t
modifier|*
name|svn_fs_x__order_dir_entries
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_hash_t
modifier|*
name|directory
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

