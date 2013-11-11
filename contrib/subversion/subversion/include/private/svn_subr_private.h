begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * svn_subr_private.h : private definitions from libsvn_subr  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_SUBR_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_SUBR_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_include
include|#
directive|include
file|"svn_version.h"
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
comment|/** Spill-to-file Buffers  *  * @defgroup svn_spillbuf_t Spill-to-file Buffers  * @{  */
comment|/** A buffer that collects blocks of content, possibly using a file.  *  * The spill-buffer is created with two basic parameters: the size of the  * blocks that will be written into the spill-buffer ("blocksize"), and  * the (approximate) maximum size that will be allowed in memory ("maxsize").  * Once the maxsize is reached, newly written content will be "spilled"  * into a temporary file.  *  * When writing, content will be buffered into memory unless a given write  * will cause the amount of in-memory content to exceed the specified  * maxsize. At that point, the file is created, and the content will be  * written to that file.  *  * To read information back out of a spill buffer, there are two approaches  * available to the application:  *  *   *) reading blocks using svn_spillbuf_read() (a "pull" model)  *   *) having blocks passed to a callback via svn_spillbuf_process()  *      (a "push" model to your application)  *  * In both cases, the spill-buffer will provide you with a block of N bytes  * that you must fully consume before asking for more data. The callback  * style provides for a "stop" parameter to temporarily pause the reading  * until another read is desired. The two styles of reading may be mixed,  * as the caller desires. Generally, N will be the blocksize, and will be  * less when the end of the content is reached.  *  * For a more stream-oriented style of reading, where the caller specifies  * the number of bytes to read into a caller-provided buffer, please see  * svn_spillbuf_reader_t. That overlaid type will cause more memory copies  * to be performed (whereas the bare spill-buffer type hands you a buffer  * to consume).  *  * Writes may be interleaved with reading, and content will be returned  * in a FIFO manner. Thus, if content has been placed into the spill-buffer  * you will always read the earliest-written data, and any newly-written  * content will be appended to the buffer.  *  * Note: the file is created in the same pool where the spill-buffer was  * created. If the content is completely read from that file, it will be  * closed and deleted. Should writing further content cause another spill  * file to be created, that will increase the size of the pool. There is  * no bound on the amount of file-related resources that may be consumed  * from the pool. It is entirely related to the read/write pattern and  * whether spill files are repeatedly created.  */
typedef|typedef
name|struct
name|svn_spillbuf_t
name|svn_spillbuf_t
typedef|;
comment|/* Create a spill buffer.  */
name|svn_spillbuf_t
modifier|*
name|svn_spillbuf__create
parameter_list|(
name|apr_size_t
name|blocksize
parameter_list|,
name|apr_size_t
name|maxsize
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Determine how much content is stored in the spill buffer.  */
name|svn_filesize_t
name|svn_spillbuf__get_size
parameter_list|(
specifier|const
name|svn_spillbuf_t
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/* Write some data into the spill buffer.  */
name|svn_error_t
modifier|*
name|svn_spillbuf__write
parameter_list|(
name|svn_spillbuf_t
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Read a block of memory from the spill buffer. @a *data will be set to    NULL if no content remains. Otherwise, @a data and @a len will point to    data that must be fully-consumed by the caller. This data will remain    valid until another call to svn_spillbuf_write(), svn_spillbuf_read(),    or svn_spillbuf_process(), or if the spill buffer's pool is cleared.  */
name|svn_error_t
modifier|*
name|svn_spillbuf__read
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|data
parameter_list|,
name|apr_size_t
modifier|*
name|len
parameter_list|,
name|svn_spillbuf_t
modifier|*
name|buf
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Callback for reading content out of the spill buffer. Set @a stop if    you want to stop the processing (and will call svn_spillbuf_process    again, at a later time).  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_spillbuf_read_t
function_decl|)
parameter_list|(
name|svn_boolean_t
modifier|*
name|stop
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Process the content stored in the spill buffer. @a exhausted will be    set to TRUE if all of the content is processed by @a read_func. This    function may return early if the callback returns TRUE for its 'stop'    parameter.  */
name|svn_error_t
modifier|*
name|svn_spillbuf__process
parameter_list|(
name|svn_boolean_t
modifier|*
name|exhausted
parameter_list|,
name|svn_spillbuf_t
modifier|*
name|buf
parameter_list|,
name|svn_spillbuf_read_t
name|read_func
parameter_list|,
name|void
modifier|*
name|read_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/** Classic stream reading layer on top of spill-buffers.  *  * This type layers upon a spill-buffer to enable a caller to read a  * specified number of bytes into the caller's provided buffer. This  * implies more memory copies than the standard spill-buffer reading  * interface, but is sometimes required by spill-buffer users.  */
typedef|typedef
name|struct
name|svn_spillbuf_reader_t
name|svn_spillbuf_reader_t
typedef|;
comment|/* Create a spill-buffer and a reader for it.  */
name|svn_spillbuf_reader_t
modifier|*
name|svn_spillbuf__reader_create
parameter_list|(
name|apr_size_t
name|blocksize
parameter_list|,
name|apr_size_t
name|maxsize
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Read @a len bytes from @a reader into @a data. The number of bytes    actually read is stored in @a amt. If the content is exhausted, then    @a amt is set to zero. It will always be non-zero if the spill-buffer    contains content.     If @a len is zero, then SVN_ERR_INCORRECT_PARAMS is returned.  */
name|svn_error_t
modifier|*
name|svn_spillbuf__reader_read
parameter_list|(
name|apr_size_t
modifier|*
name|amt
parameter_list|,
name|svn_spillbuf_reader_t
modifier|*
name|reader
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Read a single character from @a reader, and place it in @a c. If there    is no content in the spill-buffer, then SVN_ERR_STREAM_UNEXPECTED_EOF    is returned.  */
name|svn_error_t
modifier|*
name|svn_spillbuf__reader_getc
parameter_list|(
name|char
modifier|*
name|c
parameter_list|,
name|svn_spillbuf_reader_t
modifier|*
name|reader
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Write @a len bytes from @a data into the spill-buffer in @a reader.  */
name|svn_error_t
modifier|*
name|svn_spillbuf__reader_write
parameter_list|(
name|svn_spillbuf_reader_t
modifier|*
name|reader
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Return a stream built on top of a spillbuf, using the same arguments as    svn_spillbuf__create().  This stream can be used for reading and writing,    but implements the same basic sematics of a spillbuf for the underlying    storage. */
name|svn_stream_t
modifier|*
name|svn_stream__from_spillbuf
parameter_list|(
name|apr_size_t
name|blocksize
parameter_list|,
name|apr_size_t
name|maxsize
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * Internal function for creating a MD5 checksum from a binary digest.  *  * @since New in 1.8  */
name|svn_checksum_t
modifier|*
name|svn_checksum__from_digest_md5
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|digest
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/**  * Internal function for creating a SHA1 checksum from a binary  * digest.  *  * @since New in 1.8  */
name|svn_checksum_t
modifier|*
name|svn_checksum__from_digest_sha1
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|digest
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/**  * @defgroup svn_hash_support Hash table serialization support  * @{  */
comment|/*----------------------------------------------------*/
comment|/**  * @defgroup svn_hash_misc Miscellaneous hash APIs  * @{  */
comment|/** @} */
comment|/**  * @defgroup svn_hash_getters Specialized getter APIs for hashes  * @{  */
comment|/** Find the value of a @a key in @a hash, return the value.  *  * If @a hash is @c NULL or if the @a key cannot be found, the  * @a default_value will be returned.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_hash__get_cstring
parameter_list|(
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|default_value
parameter_list|)
function_decl|;
comment|/** Like svn_hash_get_cstring(), but for boolean values.  *  * Parses the value as a boolean value. The recognized representations  * are 'TRUE'/'FALSE', 'yes'/'no', 'on'/'off', '1'/'0'; case does not  * matter.  *  * @since New in 1.7.  */
name|svn_boolean_t
name|svn_hash__get_bool
parameter_list|(
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|svn_boolean_t
name|default_value
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * @defgroup svn_hash_create Create optimized APR hash tables  * @{  */
comment|/** Returns a hash table, allocated in @a pool, with the same ordering of  * elements as APR 1.4.5 or earlier (using apr_hashfunc_default) but uses  * a faster hash function implementation.  *  * @since New in 1.8.  */
name|apr_hash_t
modifier|*
name|svn_hash__make
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @} */
comment|/** @} */
comment|/** Apply the changes described by @a prop_changes to @a original_props and  * return the result.  The inverse of svn_prop_diffs().  *  * Allocate the resulting hash from @a pool, but allocate its keys and  * values from @a pool and/or by reference to the storage of the inputs.  *  * Note: some other APIs use an array of pointers to svn_prop_t.  *  * @since New in 1.8.  */
name|apr_hash_t
modifier|*
name|svn_prop__patch
parameter_list|(
specifier|const
name|apr_hash_t
modifier|*
name|original_props
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|prop_changes
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * @defgroup svn_version Version number dotted triplet parsing  * @{  */
comment|/* Set @a *version to a version structure parsed from the version  * string representation in @a version_string.  Return  * @c SVN_ERR_MALFORMED_VERSION_STRING if the string fails to parse  * cleanly.  *  * @since New in 1.8.  */
name|svn_error_t
modifier|*
name|svn_version__parse_version_string
parameter_list|(
name|svn_version_t
modifier|*
modifier|*
name|version
parameter_list|,
specifier|const
name|char
modifier|*
name|version_string
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Return true iff @a version represents a version number of at least  * the level represented by @a major, @a minor, and @a patch.  *  * @since New in 1.8.  */
name|svn_boolean_t
name|svn_version__at_least
parameter_list|(
name|svn_version_t
modifier|*
name|version
parameter_list|,
name|int
name|major
parameter_list|,
name|int
name|minor
parameter_list|,
name|int
name|patch
parameter_list|)
function_decl|;
comment|/** Like svn_ver_check_list(), but with a @a comparator parameter.  * Private backport of svn_ver_check_list2() from trunk.  */
name|svn_error_t
modifier|*
name|svn_ver__check_list2
parameter_list|(
specifier|const
name|svn_version_t
modifier|*
name|my_version
parameter_list|,
specifier|const
name|svn_version_checklist_t
modifier|*
name|checklist
parameter_list|,
name|svn_boolean_t
function_decl|(
modifier|*
name|comparator
function_decl|)
parameter_list|(
specifier|const
name|svn_version_t
modifier|*
parameter_list|,
specifier|const
name|svn_version_t
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|/** To minimize merge churn in callers, alias the trunk name privately. */
define|#
directive|define
name|svn_ver_check_list2
value|svn_ver__check_list2
comment|/** @} */
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
comment|/* SVN_SUBR_PRIVATE_H */
end_comment

end_unit

