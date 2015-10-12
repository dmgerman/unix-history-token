begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fs_id.h : FSX's implementation of svn_fs_id_t  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_X_FS_ID_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_X_FS_ID_H
end_define

begin_include
include|#
directive|include
file|"id.h"
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
comment|/* Transparent FS access object to be used with FSX's implementation for    svn_fs_id_t.  It allows the ID object query data from the respective FS    to check for node relationships etc.  It also allows to re-open the repo    after the original svn_fs_t object got cleaned up, i.e. the ID object's    functionality does not depend on any other object's lifetime.     For efficiency, multiple svn_fs_id_t should share the same context.  */
typedef|typedef
name|struct
name|svn_fs_x__id_context_t
name|svn_fs_x__id_context_t
typedef|;
comment|/* Return a context object for filesystem FS; construct it in RESULT_POOL. */
name|svn_fs_x__id_context_t
modifier|*
name|svn_fs_x__id_create_context
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Create a permanent ID based on NODEREV_ID, allocated in RESULT_POOL.    For complex requests, access the filesystem provided with CONTEXT.     For efficiency, CONTEXT should have been created in RESULT_POOL and be    shared between multiple ID instances allocated in the same pool.  */
name|svn_fs_id_t
modifier|*
name|svn_fs_x__id_create
parameter_list|(
name|svn_fs_x__id_context_t
modifier|*
name|context
parameter_list|,
specifier|const
name|svn_fs_x__id_t
modifier|*
name|noderev_id
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
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
comment|/* SVN_LIBSVN_FS_X_FS_ID_H */
end_comment

end_unit

