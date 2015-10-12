begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_io_private.h  * @brief Private IO API  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_IO_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_IO_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
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
comment|/* The flags to pass to apr_stat to check for executable and/or readonly */
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__OS2__
argument_list|)
define|#
directive|define
name|SVN__APR_FINFO_EXECUTABLE
value|(0)
define|#
directive|define
name|SVN__APR_FINFO_READONLY
value|(0)
define|#
directive|define
name|SVN__APR_FINFO_MASK_OUT
value|(APR_FINFO_PROT | APR_FINFO_OWNER)
else|#
directive|else
define|#
directive|define
name|SVN__APR_FINFO_EXECUTABLE
value|(APR_FINFO_PROT)
define|#
directive|define
name|SVN__APR_FINFO_READONLY
value|(APR_FINFO_PROT | APR_FINFO_OWNER)
define|#
directive|define
name|SVN__APR_FINFO_MASK_OUT
value|(0)
endif|#
directive|endif
comment|/* 90% of the lines we encounter will be less than this many chars.  *  * Line-based functions like svn_stream_readline should fetch data in  * blocks no longer than this.  Although using a larger prefetch size is  * not illegal and must not break any functionality, it may be  * significantly less efficient in certain situations.  */
define|#
directive|define
name|SVN__LINE_CHUNK_SIZE
value|80
comment|/** Set @a *executable TRUE if @a file_info is executable for the  * user, FALSE otherwise.  *  * Always returns FALSE on Windows or platforms without user support.  */
name|svn_error_t
modifier|*
name|svn_io__is_finfo_executable
parameter_list|(
name|svn_boolean_t
modifier|*
name|executable
parameter_list|,
name|apr_finfo_t
modifier|*
name|file_info
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *read_only TRUE if @a file_info is read-only for the user,  * FALSE otherwise.  */
name|svn_error_t
modifier|*
name|svn_io__is_finfo_read_only
parameter_list|(
name|svn_boolean_t
modifier|*
name|read_only
parameter_list|,
name|apr_finfo_t
modifier|*
name|file_info
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Lock file at @a lock_file. If that file does not exist, create an empty  * file.  *  * Lock will be automatically released when @a pool is cleared or destroyed.  * Use @a pool for memory allocations.  */
name|svn_error_t
modifier|*
name|svn_io__file_lock_autocreate
parameter_list|(
specifier|const
name|char
modifier|*
name|lock_file
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Buffer test handler function for a generic stream. @see svn_stream_t  * and svn_stream__is_buffered().  *  * @since New in 1.7.  */
typedef|typedef
name|svn_boolean_t
function_decl|(
modifier|*
name|svn_stream__is_buffered_fn_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/** Set @a stream's buffer test function to @a is_buffered_fn  *  * @since New in 1.7.  */
name|void
name|svn_stream__set_is_buffered
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|svn_stream__is_buffered_fn_t
name|is_buffered_fn
parameter_list|)
function_decl|;
comment|/** Return whether this generic @a stream uses internal buffering.  * This may be used to work around subtle differences between buffered  * and non-buffered APR files.  A lazy-open stream cannot report the  * true buffering state until after the lazy open: a stream that  * initially reports as non-buffered may report as buffered later.  *  * @since New in 1.7.  */
name|svn_boolean_t
name|svn_stream__is_buffered
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/** Return the underlying file, if any, associated with the stream, or  * NULL if not available.  Accessing the file bypasses the stream.  */
name|apr_file_t
modifier|*
name|svn_stream__aprfile
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Creates as *INSTALL_STREAM a stream that once completed can be installed    using Windows checkouts much slower than Unix.     While writing the stream is temporarily stored in TMP_ABSPATH.  */
name|svn_error_t
modifier|*
name|svn_stream__create_for_install
parameter_list|(
name|svn_stream_t
modifier|*
modifier|*
name|install_stream
parameter_list|,
specifier|const
name|char
modifier|*
name|tmp_abspath
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Installs a stream created with svn_stream__create_for_install in its final    location FINAL_ABSPATH, potentially using platform specific optimizations.     If MAKE_PARENTS is TRUE, this function will create missing parent    directories if needed.  */
name|svn_error_t
modifier|*
name|svn_stream__install_stream
parameter_list|(
name|svn_stream_t
modifier|*
name|install_stream
parameter_list|,
specifier|const
name|char
modifier|*
name|final_abspath
parameter_list|,
name|svn_boolean_t
name|make_parents
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Deletes the install stream (when installing is not necessary after all) */
name|svn_error_t
modifier|*
name|svn_stream__install_delete
parameter_list|(
name|svn_stream_t
modifier|*
name|install_stream
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Optimized apr_file_stat / apr_file_info_get operating on a closed    install stream */
name|svn_error_t
modifier|*
name|svn_stream__install_get_info
parameter_list|(
name|apr_finfo_t
modifier|*
name|finfo
parameter_list|,
name|svn_stream_t
modifier|*
name|install_stream
parameter_list|,
name|apr_int32_t
name|wanted
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
comment|/* ### Move to something like io.h or subr.h, to avoid making it        part of the DLL api */
comment|/* This is semantically the same as the APR utf8_to_unicode_path    function, but reimplemented here because APR does not export it.     Note that this function creates "\\?\" paths so the resulting path    can only be used for WINAPI functions that explicitly document support    for this kind of paths. Newer Windows functions (Vista+) that support    long paths directly DON'T want this kind of escaping.  */
name|svn_error_t
modifier|*
name|svn_io__utf8_to_unicode_longpath
parameter_list|(
specifier|const
name|WCHAR
modifier|*
modifier|*
name|result
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* This Windows-specific function marks the file to be deleted on close using    an existing file handle. It can be used to avoid having to reopen the file    as part of the delete handling. Return SVN_ERR_UNSUPPORTED_FEATURE if    delete on close operation is not supported by OS. */
name|svn_error_t
modifier|*
name|svn_io__win_delete_file_on_close
parameter_list|(
name|apr_file_t
modifier|*
name|file
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
comment|/* This Windows-specific function renames the file using an existing file    handle. It can be used to avoid having to reopen the file as part of the    rename operation. Return SVN_ERR_UNSUPPORTED_FEATURE if renaming open    file is not supported by OS.*/
name|svn_error_t
modifier|*
name|svn_io__win_rename_open_file
parameter_list|(
name|apr_file_t
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|from_path
parameter_list|,
specifier|const
name|char
modifier|*
name|to_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* WIN32 */
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
comment|/* SVN_IO_PRIVATE_H */
end_comment

end_unit

