begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uuids-table.h : internal interface to `uuids' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_UUIDS_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_UUIDS_TABLE_H
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
comment|/* Open a `uuids' table in @a env.  *  * Open a `uuids' table in @a env.  If @a create is non-zero, create  * one if it doesn't exist.  Set @a *uuids_p to the new table.  * Return a Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_uuids_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|uuids_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Get the UUID at index @a idx in the uuids table within @a fs,  * storing the result in @a *uuid.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__get_uuid
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|uuid
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
comment|/* Set the UUID at index @a idx in the uuids table within @a fs  * to @a uuid.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__set_uuid
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|char
modifier|*
name|uuid
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
comment|/* SVN_LIBSVN_FS_UUIDS_TABLE_H */
end_comment

end_unit

