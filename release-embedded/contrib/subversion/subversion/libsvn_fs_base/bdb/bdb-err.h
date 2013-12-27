begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * err.h : interface to routines for returning Berkeley DB errors  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_BDB_ERR_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_BDB_ERR_H
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

begin_include
include|#
directive|include
file|"env.h"
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
comment|/* Return an svn_error_t object that reports a Berkeley DB error.    DB_ERR is the error value returned by the Berkeley DB routine.    Wrap and consume pending errors in BDB.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__dberr
parameter_list|(
name|bdb_env_baton_t
modifier|*
name|bdb_baton
parameter_list|,
name|int
name|db_err
parameter_list|)
function_decl|;
comment|/* Allocate an error object for a Berkeley DB error, with a formatted message.    Wrap and consume pending errors in BDB.     DB_ERR is the Berkeley DB error code.    FMT is a printf-style format string, describing how to format any       subsequent arguments.     The svn_error_t object returned has a message consisting of:    - the text specified by FMT and the subsequent arguments, and    - the Berkeley DB error message for the error code DB_ERR.     There is no separator between the two messages; if you want one,    you should include it in FMT.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__dberrf
parameter_list|(
name|bdb_env_baton_t
modifier|*
name|bdb_baton
parameter_list|,
name|int
name|db_err
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Clear errors associated with BDB. */
end_comment

begin_function_decl
name|void
name|svn_fs_bdb__clear_err
parameter_list|(
name|bdb_env_t
modifier|*
name|bdb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check the return status from the Berkeley DB operation.  If the    operation succeeded, return zero.  Otherwise, construct an    appropriate Subversion error object describing what went wrong.    - FS is the Subversion filesystem we're operating on.    - OPERATION is a gerund clause describing what we were trying to do.    - BDB_ERR is the return status from the Berkeley DB function.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_bdb__wrap_db
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|operation
parameter_list|,
name|int
name|db_err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A terse wrapper for svn_fs_bdb__wrap_db.  */
end_comment

begin_define
define|#
directive|define
name|BDB_WRAP
parameter_list|(
name|fs
parameter_list|,
name|op
parameter_list|,
name|err
parameter_list|)
value|(svn_fs_bdb__wrap_db((fs), (op), (err)))
end_define

begin_comment
comment|/* If EXPR returns a non-zero value, pass that value to    svn_fs_bdb__dberr and return that function's value.  This is like    SVN_ERR, but is used by functions that return a Subversion error    and call other functions that return a Berkeley DB error code. */
end_comment

begin_define
define|#
directive|define
name|SVN_BDB_ERR
parameter_list|(
name|bdb
parameter_list|,
name|expr
parameter_list|)
define|\
value|do {                                                   \     int db_err__temp = (expr);                           \     if (db_err__temp)                                    \       return svn_fs_bdb__dberr((bdb), db_err__temp);     \     svn_error_clear((bdb)->error_info->pending_errors);  \     (bdb)->error_info->pending_errors = NULL;            \   } while (0)
end_define

begin_comment
comment|/* If EXPR returns a non-zero value, return it.  This is like SVN_ERR,    but for functions that return a Berkeley DB error code.  */
end_comment

begin_define
define|#
directive|define
name|BDB_ERR
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {                                          \     int db_err__temp = (expr);                  \     if (db_err__temp)                           \       return db_err__temp;                      \   } while (0)
end_define

begin_comment
comment|/* Verify that FS refers to an open database; return an appropriate    error if this is not the case.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_bdb__check_fs
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
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
comment|/* SVN_LIBSVN_FS_BDB_ERR_H */
end_comment

end_unit

