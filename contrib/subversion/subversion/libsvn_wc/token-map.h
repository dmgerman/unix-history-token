begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  *  * This header is parsed by transform-sql.py to allow SQLite  * statements to refer to string values by symbolic names.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_WC_TOKEN_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_WC_TOKEN_MAP_H
end_define

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"wc_db.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_token.h"
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
specifier|static
specifier|const
name|svn_token_map_t
name|kind_map
index|[]
init|=
block|{
block|{
literal|"file"
block|,
name|svn_node_file
block|}
block|,
comment|/* MAP_FILE */
block|{
literal|"dir"
block|,
name|svn_node_dir
block|}
block|,
comment|/* MAP_DIR */
block|{
literal|"symlink"
block|,
name|svn_node_symlink
block|}
block|,
comment|/* MAP_SYMLINK */
block|{
literal|"unknown"
block|,
name|svn_node_unknown
block|}
block|,
comment|/* MAP_UNKNOWN */
block|{
name|NULL
block|}
block|}
decl_stmt|;
comment|/* Note: we only decode presence values from the database. These are a    subset of all the status values. */
specifier|static
specifier|const
name|svn_token_map_t
name|presence_map
index|[]
init|=
block|{
block|{
literal|"normal"
block|,
name|svn_wc__db_status_normal
block|}
block|,
comment|/* MAP_NORMAL */
block|{
literal|"server-excluded"
block|,
name|svn_wc__db_status_server_excluded
block|}
block|,
comment|/* MAP_SERVER_EXCLUDED */
block|{
literal|"excluded"
block|,
name|svn_wc__db_status_excluded
block|}
block|,
comment|/* MAP_EXCLUDED */
block|{
literal|"not-present"
block|,
name|svn_wc__db_status_not_present
block|}
block|,
comment|/* MAP_NOT_PRESENT */
block|{
literal|"incomplete"
block|,
name|svn_wc__db_status_incomplete
block|}
block|,
comment|/* MAP_INCOMPLETE */
block|{
literal|"base-deleted"
block|,
name|svn_wc__db_status_base_deleted
block|}
block|,
comment|/* MAP_BASE_DELETED */
block|{
name|NULL
block|}
block|}
decl_stmt|;
comment|/* The subset of svn_depth_t used in the database. */
specifier|static
specifier|const
name|svn_token_map_t
name|depth_map
index|[]
init|=
block|{
block|{
literal|"unknown"
block|,
name|svn_depth_unknown
block|}
block|,
comment|/* MAP_DEPTH_UNKNOWN */
block|{
literal|"empty"
block|,
name|svn_depth_empty
block|}
block|,
block|{
literal|"files"
block|,
name|svn_depth_files
block|}
block|,
block|{
literal|"immediates"
block|,
name|svn_depth_immediates
block|}
block|,
block|{
literal|"infinity"
block|,
name|svn_depth_infinity
block|}
block|,
comment|/* MAP_DEPTH_INFINITY */
block|{
name|NULL
block|}
block|}
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

