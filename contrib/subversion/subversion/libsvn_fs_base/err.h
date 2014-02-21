begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * err.h : interface to routines for returning Berkeley DB errors  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_ERR_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_ERR_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
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
comment|/* Building common error objects.  */
comment|/* SVN_ERR_FS_CORRUPT: the REVISION skel of revision REV in FS is corrupt.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_corrupt_fs_revision
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_ID_NOT_FOUND: something in FS refers to node revision    ID, but that node revision doesn't exist.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_dangling_id
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_CORRUPT: something in FS refers to filesystem revision REV,    but that filesystem revision doesn't exist.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_dangling_rev
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_CORRUPT: the entry for TXN in the `transactions' table    is corrupt.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_corrupt_txn
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|txn
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_CORRUPT: the entry for COPY_ID in the `copies' table    is corrupt.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_corrupt_copy
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|copy_id
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_NO_SUCH_TRANSACTION: there is no transaction named TXN in FS.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_no_such_txn
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|txn
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_TRANSACTION_NOT_MUTABLE: trying to change the    unchangeable transaction named TXN in FS.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_txn_not_mutable
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|txn
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_NO_SUCH_COPY: there is no copy with id COPY_ID in FS.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_no_such_copy
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|copy_id
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_BAD_LOCK_TOKEN: LOCK_TOKEN does not refer to a lock in FS.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_bad_lock_token
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|lock_token
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_NO_LOCK_TOKEN: no lock token given for PATH in FS.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_no_lock_token
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_CORRUPT: a lock in `locks' table is corrupt.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_corrupt_lock
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|lock_token
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_NO_SUCH_NODE_ORIGIN: no recorded node origin for NODE_ID    in FS.  */
name|svn_error_t
modifier|*
name|svn_fs_base__err_no_such_node_origin
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|node_id
parameter_list|)
function_decl|;
comment|/* SVN_ERR_FS_NO_SUCH_CHECKSUM_REP: no recorded rep key for CHECKSUM in FS. */
name|svn_error_t
modifier|*
name|svn_fs_base__err_no_such_checksum_rep
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_checksum_t
modifier|*
name|checksum
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
comment|/* SVN_LIBSVN_FS_ERR_H */
end_comment

end_unit

