begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * delta.h:  private delta library things  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_comment
comment|/* ==================================================================== */
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_include
include|#
directive|include
file|"svn_delta.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_DELTA_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_DELTA_H
end_define

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
comment|/* Private interface for text deltas. */
comment|/* The standard size of one svndiff window. */
define|#
directive|define
name|SVN_DELTA_WINDOW_SIZE
value|102400
comment|/* Context/baton for building an operation sequence. */
typedef|typedef
struct|struct
name|svn_txdelta__ops_baton_t
block|{
name|int
name|num_ops
decl_stmt|;
comment|/* current number of ops */
name|int
name|src_ops
decl_stmt|;
comment|/* current number of source copy ops */
name|int
name|ops_size
decl_stmt|;
comment|/* number of ops allocated */
name|svn_txdelta_op_t
modifier|*
name|ops
decl_stmt|;
comment|/* the operations */
name|svn_stringbuf_t
modifier|*
name|new_data
decl_stmt|;
comment|/* any new data used by the operations */
block|}
name|svn_txdelta__ops_baton_t
typedef|;
comment|/* Insert a delta op into the delta window being built via BUILD_BATON. If    OPCODE is svn_delta_new, bytes from NEW_DATA are copied into the window    data and OFFSET is ignored.  Otherwise NEW_DATA is ignored. All    allocations are performed in POOL. */
name|void
name|svn_txdelta__insert_op
parameter_list|(
name|svn_txdelta__ops_baton_t
modifier|*
name|build_baton
parameter_list|,
name|enum
name|svn_delta_action
name|opcode
parameter_list|,
name|apr_size_t
name|offset
parameter_list|,
name|apr_size_t
name|length
parameter_list|,
specifier|const
name|char
modifier|*
name|new_data
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Remove / truncate the last delta ops spanning the last MAX_LEN bytes    from the delta window being built via BUILD_BATON starting.  Return the    number of bytes that were actually removed. */
name|apr_size_t
name|svn_txdelta__remove_copy
parameter_list|(
name|svn_txdelta__ops_baton_t
modifier|*
name|build_baton
parameter_list|,
name|apr_size_t
name|max_len
parameter_list|)
function_decl|;
comment|/* Allocate a delta window from POOL. */
name|svn_txdelta_window_t
modifier|*
name|svn_txdelta__make_window
parameter_list|(
specifier|const
name|svn_txdelta__ops_baton_t
modifier|*
name|build_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create xdelta window data. Allocate temporary data from POOL. */
name|void
name|svn_txdelta__xdelta
parameter_list|(
name|svn_txdelta__ops_baton_t
modifier|*
name|build_baton
parameter_list|,
specifier|const
name|char
modifier|*
name|start
parameter_list|,
name|apr_size_t
name|source_len
parameter_list|,
name|apr_size_t
name|target_len
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
comment|/* SVN_LIBSVN_DELTA_H */
end_comment

end_unit

