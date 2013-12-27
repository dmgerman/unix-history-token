begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strings-table.h : internal interface to `strings' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_STRINGS_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_STRINGS_TABLE_H
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

begin_include
include|#
directive|include
file|"../trail.h"
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
comment|/* This interface provides raw access to the `strings' table.  It does    not deal with deltification, undeltification, or skels.  It just    reads and writes strings of bytes. */
comment|/* Open a `strings' table in ENV.  If CREATE is non-zero, create  * one if it doesn't exist.  Set *STRINGS_P to the new table.  * Return a Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_strings_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|strings_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Read *LEN bytes into BUF from OFFSET in string KEY in FS, as part  * of TRAIL.  *  * On return, *LEN is set to the number of bytes read.  If this value  * is less than the number requested, the end of the string has been  * reached (no error is returned on end-of-string).  *  * If OFFSET is past the end of the string, then *LEN will be set to  * zero. Callers which are advancing OFFSET as they read portions of  * the string can terminate their loop when *LEN is returned as zero  * (which will occur when OFFSET == length(the string)).  *  * If string KEY does not exist, the error SVN_ERR_FS_NO_SUCH_STRING  * is returned.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__string_read
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|svn_filesize_t
name|offset
parameter_list|,
name|apr_size_t
modifier|*
name|len
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
comment|/* Set *SIZE to the size in bytes of string KEY in FS, as part of  * TRAIL.  *  * If string KEY does not exist, return SVN_ERR_FS_NO_SUCH_STRING.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__string_size
parameter_list|(
name|svn_filesize_t
modifier|*
name|size
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|key
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
comment|/* Append LEN bytes from BUF to string *KEY in FS, as part of TRAIL.  *  * If *KEY is null, then create a new string and store the new key in  * *KEY (allocating it in POOL), and write LEN bytes from BUF  * as the initial contents of the string.  *  * If *KEY is not null but there is no string named *KEY, return  * SVN_ERR_FS_NO_SUCH_STRING.  *  * Note: to overwrite the old contents of a string, call  * svn_fs_bdb__string_clear() and then svn_fs_bdb__string_append().  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__string_append
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|key
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
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
comment|/* Make string KEY in FS zero length, as part of TRAIL.  * If the string does not exist, return SVN_ERR_FS_NO_SUCH_STRING.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__string_clear
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|key
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
comment|/* Delete string KEY from FS, as part of TRAIL.  *  * If string KEY does not exist, return SVN_ERR_FS_NO_SUCH_STRING.  *  * WARNING: Deleting a string renders unusable any representations  * that refer to it.  Be careful.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__string_delete
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|key
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
comment|/* Copy the contents of the string referred to by KEY in FS into a new  * record, returning the new record's key in *NEW_KEY.  All  * allocations (including *NEW_KEY) occur in POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__string_copy
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|new_key
parameter_list|,
specifier|const
name|char
modifier|*
name|key
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
comment|/* SVN_LIBSVN_FS_STRINGS_TABLE_H */
end_comment

end_unit

