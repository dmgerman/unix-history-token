begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* env.h : managing the BDB environment  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_BDB_ENV_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_BDB_ENV_H
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
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_file_io.h>
end_include

begin_include
include|#
directive|include
file|"bdb_compat.h"
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
comment|/* The name of the Berkeley DB config file.  */
define|#
directive|define
name|BDB_CONFIG_FILE
value|"DB_CONFIG"
comment|/* Prefix string for BDB errors. */
define|#
directive|define
name|BDB_ERRPFX_STRING
value|"svn (bdb): "
comment|/* Opaque descriptor of an open BDB environment. */
typedef|typedef
name|struct
name|bdb_env_t
name|bdb_env_t
typedef|;
comment|/* Thread-specific error info related to the bdb_env_t. */
typedef|typedef
struct|struct
name|bdb_error_info_t
block|{
comment|/* We hold the extended info here until the Berkeley DB function returns.      It usually returns an error code, triggering the collection and      wrapping of the additional errors stored here.       Note: In some circumstances BDB will call the error function and not      go on to return an error code, so the caller must always check whether      pending_errors is non-NULL to avoid leaking errors.  This behaviour      has been seen when running recovery on a repository upgraded to 4.3      that still has old 4.2 log files present, a typical error string is      "Skipping log file db/log.0000000002: historic log version 8" */
name|svn_error_t
modifier|*
name|pending_errors
decl_stmt|;
comment|/* We permitted clients of our library to install a Berkeley BDB errcall.      Since we now use the errcall ourselves, we must store and invoke a user      errcall, to maintain our API guarantees. */
name|void
function_decl|(
modifier|*
name|user_callback
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|errpfx
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
comment|/* The reference count.  It counts the number of bdb_env_baton_t      instances that refer to this object. */
name|unsigned
name|refcount
decl_stmt|;
block|}
name|bdb_error_info_t
typedef|;
comment|/* The Berkeley DB environment baton. */
typedef|typedef
struct|struct
name|bdb_env_baton_t
block|{
comment|/* The Berkeley DB environment. This pointer must be identical to      the one in the bdb_env_t. */
name|DB_ENV
modifier|*
name|env
decl_stmt|;
comment|/* The (opaque) cached environment descriptor. */
name|bdb_env_t
modifier|*
name|bdb
decl_stmt|;
comment|/* The error info related to this baton. */
name|bdb_error_info_t
modifier|*
name|error_info
decl_stmt|;
block|}
name|bdb_env_baton_t
typedef|;
comment|/* Flag combination for opening a shared BDB environment. */
define|#
directive|define
name|SVN_BDB_STANDARD_ENV_FLAGS
value|(DB_CREATE       \                                     | DB_INIT_LOCK  \                                     | DB_INIT_LOG   \                                     | DB_INIT_MPOOL \                                     | DB_INIT_TXN   \                                     | SVN_BDB_AUTO_RECOVER)
comment|/* Flag combination for opening a private BDB environment. */
define|#
directive|define
name|SVN_BDB_PRIVATE_ENV_FLAGS
value|(DB_CREATE       \                                    | DB_INIT_LOG   \                                    | DB_INIT_MPOOL \                                    | DB_INIT_TXN   \                                    | DB_PRIVATE)
comment|/* Iniitalize the BDB back-end's private stuff. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__init
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Allocate the Berkeley DB descriptor BDB and open the environment.  *  * Allocate *BDBP from POOL and open (*BDBP)->env in PATH, using FLAGS  * and MODE.  If applicable, set the BDB_AUTO_COMMIT flag for this  * environment.  *  * Use POOL for temporary allocation.  *  * Note: This function may return a bdb_env_baton_t object that refers  *       to a previously opened environment.  If FLAGS contains  *       DB_PRIVATE and the environment is already open, the function  *       will fail (this isn't a problem in practice, because a caller  *       should obtain an exclusive lock on the repository before  *       opening the environment).  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__open
parameter_list|(
name|bdb_env_baton_t
modifier|*
modifier|*
name|bdb_batonp
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|u_int32_t
name|flags
parameter_list|,
name|int
name|mode
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Close the Berkeley DB descriptor BDB.  *  * Note: This function might not actually close the environment if it  *       has been opened more than once.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__close
parameter_list|(
name|bdb_env_baton_t
modifier|*
name|bdb_baton
parameter_list|)
function_decl|;
comment|/* Get the panic state of the open BDB environment. */
name|svn_boolean_t
name|svn_fs_bdb__get_panic
parameter_list|(
name|bdb_env_baton_t
modifier|*
name|bdb_baton
parameter_list|)
function_decl|;
comment|/* Set the panic flag on the open BDB environment. */
name|void
name|svn_fs_bdb__set_panic
parameter_list|(
name|bdb_env_baton_t
modifier|*
name|bdb_baton
parameter_list|)
function_decl|;
comment|/* Remove the Berkeley DB environment at PATH.  *  * Use POOL for temporary allocation.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__remove
parameter_list|(
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
comment|/* SVN_LIBSVN_FS_BDB_ENV_H */
end_comment

end_unit

