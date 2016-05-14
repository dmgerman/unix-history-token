begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hotcopy.h : interface to the native filesystem layer  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__HOTCOPY_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__HOTCOPY_H
end_define

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_comment
comment|/* Create an empty copy of the fsfs filesystem SRC_FS into a new DST_FS at  * DST_PATH.  If INCREMENTAL is TRUE, perform a few pre-checks only if  * a repo already exists at DST_PATH. Use POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__hotcopy_prepare_target
parameter_list|(
name|svn_fs_t
modifier|*
name|src_fs
parameter_list|,
name|svn_fs_t
modifier|*
name|dst_fs
parameter_list|,
specifier|const
name|char
modifier|*
name|dst_path
parameter_list|,
name|svn_boolean_t
name|incremental
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy the fsfs filesystem SRC_FS into DST_FS. If INCREMENTAL is TRUE, do  * not re-copy data which already exists in DST_FS.  Indicate progress via  * the optional NOTIFY_FUNC callback using NOTIFY_BATON.  Use POOL for  * temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__hotcopy
parameter_list|(
name|svn_fs_t
modifier|*
name|src_fs
parameter_list|,
name|svn_fs_t
modifier|*
name|dst_fs
parameter_list|,
name|svn_boolean_t
name|incremental
parameter_list|,
name|svn_fs_hotcopy_notify_t
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
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

