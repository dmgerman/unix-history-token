begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* txn-table.h : internal interface to ops on `transactions' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_TXN_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_TXN_TABLE_H
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
comment|/* Open a `transactions' table in ENV.  If CREATE is non-zero, create    one if it doesn't exist.  Set *TRANSACTIONS_P to the new table.    Return a Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_transactions_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|transactions_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Create a new transaction in FS as part of TRAIL, with an initial    root and base root ID of ROOT_ID.  Set *TXN_NAME_P to the name of the    new transaction, allocated in POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__create_txn
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|txn_name_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|root_id
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
comment|/* Remove the transaction whose name is TXN_NAME from the `transactions'    table of FS, as part of TRAIL.     Returns SVN_ERR_FS_TRANSACTION_NOT_MUTABLE if TXN_NAME refers to a    transaction that has already been committed.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__delete_txn
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|txn_name
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
comment|/* Retrieve the transaction *TXN_P for the Subversion transaction    named TXN_NAME from the `transactions' table of FS, as part of    TRAIL.  Perform all allocations in POOL.     If there is no such transaction, SVN_ERR_FS_NO_SUCH_TRANSACTION is    the error returned.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__get_txn
parameter_list|(
name|transaction_t
modifier|*
modifier|*
name|txn_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|txn_name
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
comment|/* Store the Subversion transaction TXN in FS with an ID of TXN_NAME as    part of TRAIL. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__put_txn
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|transaction_t
modifier|*
name|txn
parameter_list|,
specifier|const
name|char
modifier|*
name|txn_name
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
comment|/* Set *NAMES_P to an array of const char * IDs (unfinished    transactions in FS) as part of TRAIL.  Allocate the array and the    names in POOL, and use POOL for any temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__get_txn_list
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|names_p
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
comment|/* SVN_LIBSVN_FS_TXN_TABLE_H */
end_comment

end_unit

