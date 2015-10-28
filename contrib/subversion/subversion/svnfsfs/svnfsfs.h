begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * svnfsfs.h:  shared stuff in the command line program  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVNFSFS_H
end_ifndef

begin_define
define|#
directive|define
name|SVNFSFS_H
end_define

begin_comment
comment|/*** Includes. ***/
end_comment

begin_include
include|#
directive|include
file|"svn_opt.h"
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
comment|/*** Command dispatch. ***/
comment|/* Baton for passing option/argument state to a subcommand function. */
typedef|typedef
struct|struct
name|svnfsfs__opt_state
block|{
specifier|const
name|char
modifier|*
name|repository_path
decl_stmt|;
name|svn_opt_revision_t
name|start_revision
decl_stmt|,
name|end_revision
decl_stmt|;
comment|/* -r X[:Y] */
name|svn_boolean_t
name|help
decl_stmt|;
comment|/* --help or -? */
name|svn_boolean_t
name|version
decl_stmt|;
comment|/* --version */
name|svn_boolean_t
name|quiet
decl_stmt|;
comment|/* --quiet */
name|apr_uint64_t
name|memory_cache_size
decl_stmt|;
comment|/* --memory-cache-size M */
block|}
name|svnfsfs__opt_state
typedef|;
comment|/* Declare all the command procedures */
name|svn_opt_subcommand_t
name|subcommand__help
decl_stmt|,
name|subcommand__dump_index
decl_stmt|,
name|subcommand__load_index
decl_stmt|,
name|subcommand__stats
decl_stmt|;
comment|/* Check that the filesystem at PATH is an FSFS repository and then open it.  * Return the filesystem in *FS, allocated in POOL. */
name|svn_error_t
modifier|*
name|open_fs
parameter_list|(
name|svn_fs_t
modifier|*
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Our cancellation callback. */
name|svn_error_t
modifier|*
name|check_cancel
parameter_list|(
name|void
modifier|*
name|baton
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
comment|/* SVNFSFS_H */
end_comment

end_unit

