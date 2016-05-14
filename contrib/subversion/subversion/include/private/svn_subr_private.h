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
file|"svn_config.h"
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
comment|/* Create a spill buffer, with extra parameters.  */
name|svn_spillbuf_t
modifier|*
name|svn_spillbuf__create_extended
parameter_list|(
name|apr_size_t
name|blocksize
parameter_list|,
name|apr_size_t
name|maxsize
parameter_list|,
name|svn_boolean_t
name|delete_on_close
parameter_list|,
name|svn_boolean_t
name|spill_all_contents
parameter_list|,
specifier|const
name|char
modifier|*
name|dirpath
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
comment|/* Determine how much content the spill buffer is caching in memory.  */
name|svn_filesize_t
name|svn_spillbuf__get_memory_size
parameter_list|(
specifier|const
name|svn_spillbuf_t
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/* Retrieve the name of the spill file. The returned value can be NULL    if the file has not been created yet. */
specifier|const
name|char
modifier|*
name|svn_spillbuf__get_filename
parameter_list|(
specifier|const
name|svn_spillbuf_t
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/* Retrieve the handle of the spill file. The returned value can be    NULL if the file has not been created yet. */
name|apr_file_t
modifier|*
name|svn_spillbuf__get_file
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
comment|/* Create a spill-buffer and a reader for it, using the same arguments as    svn_spillbuf__create().  */
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
comment|/* Return a stream built on top of a spillbuf.     This stream can be used for reading and writing, but implements the    same basic semantics of a spillbuf for the underlying storage. */
name|svn_stream_t
modifier|*
name|svn_stream__from_spillbuf
parameter_list|(
name|svn_spillbuf_t
modifier|*
name|buf
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/** @} */
comment|/*----------------------------------------------------*/
comment|/**  * @defgroup svn_checksum_private Checksumming helper APIs  * @{  */
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
comment|/**  * Internal function for creating a 32 bit FNV-1a checksum from a binary  * digest.  *  * @since New in 1.9  */
name|svn_checksum_t
modifier|*
name|svn_checksum__from_digest_fnv1a_32
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
comment|/**  * Internal function for creating a modified 32 bit FNV-1a checksum from  * a binary digest.  *  * @since New in 1.9  */
name|svn_checksum_t
modifier|*
name|svn_checksum__from_digest_fnv1a_32x4
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
comment|/**  * Return a stream that calculates a checksum of type @a kind over all  * data written to the @a inner_stream.  When the returned stream gets  * closed, write the checksum to @a *checksum.  * Allocate the result in @a pool.  *  * @note The stream returned only supports #svn_stream_write and  * #svn_stream_close.  */
name|svn_stream_t
modifier|*
name|svn_checksum__wrap_write_stream
parameter_list|(
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
name|svn_stream_t
modifier|*
name|inner_stream
parameter_list|,
name|svn_checksum_kind_t
name|kind
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return a stream that calculates a 32 bit modified FNV-1a checksum  * over all data written to the @a inner_stream and writes the digest  * to @a *digest when the returned stream gets closed.  * Allocate the stream in @a pool.  */
name|svn_stream_t
modifier|*
name|svn_checksum__wrap_write_stream_fnv1a_32x4
parameter_list|(
name|apr_uint32_t
modifier|*
name|digest
parameter_list|,
name|svn_stream_t
modifier|*
name|inner_stream
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return a 32 bit FNV-1a checksum for the first @a len bytes in @a input.  *  * @since New in 1.9  */
name|apr_uint32_t
name|svn__fnv1a_32
parameter_list|(
specifier|const
name|void
modifier|*
name|input
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Return a 32 bit modified FNV-1a checksum for the first @a len bytes in  * @a input.  *  * @note This is a proprietary checksumming algorithm based FNV-1a with  *       approximately the same strength.  It is up to 4 times faster  *       than plain FNV-1a for longer data blocks.  *  * @since New in 1.9  */
name|apr_uint32_t
name|svn__fnv1a_32x4
parameter_list|(
specifier|const
name|void
modifier|*
name|input
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/** @} */
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
comment|/**  * @defgroup svn_hash_read Reading serialized hash tables  * @{  */
comment|/** Struct that represents a key value pair read from a serialized hash  * representation.  There are special cases that can also be represented:  * a #NULL @a key signifies the end of the hash, a #NULL @a val for non-  * NULL keys is only possible in incremental mode describes a deletion.  *  * @since New in 1.9.  */
typedef|typedef
struct|struct
name|svn_hash__entry_t
block|{
comment|/** 0-terminated Key.  #NULL if this contains no data at all because we    * encountered the end of the hash. */
name|char
modifier|*
name|key
decl_stmt|;
comment|/** Length of @a key.  Must be 0 if @a key is #NULL. */
name|apr_size_t
name|keylen
decl_stmt|;
comment|/** 0-terminated value stored with the key.  If this is #NULL for a    * non-NULL @a key, then this means that the key shall be removed from    * the hash (only used in incremental mode).  Must be #NULL if @a key is    * #NULL. */
name|char
modifier|*
name|val
decl_stmt|;
comment|/** Length of @a val.  Must be 0 if @a val is #NULL. */
name|apr_size_t
name|vallen
decl_stmt|;
block|}
name|svn_hash__entry_t
typedef|;
comment|/** Reads a single key-value pair from @a stream and returns it in the  * caller-provided @a *entry (members don't need to be pre-initialized).  * @a pool is used to allocate members of @a *entry and for tempoaries.  *  * @see #svn_hash_read2 for more details.  *  * @since New in 1.9.  */
name|svn_error_t
modifier|*
name|svn_hash__read_entry
parameter_list|(
name|svn_hash__entry_t
modifier|*
name|entry
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|terminator
parameter_list|,
name|svn_boolean_t
name|incremental
parameter_list|,
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
comment|/** @} */
comment|/**  * @defgroup svn_compress Data (de-)compression API  * @{  */
comment|/* This is at least as big as the largest size of an integer that    svn__encode_uint() can generate; it is sufficient for creating buffers    for it to write into.  This assumes that integers are at most 64 bits,    and so 10 bytes (with 7 bits of information each) are sufficient to    represent them. */
define|#
directive|define
name|SVN__MAX_ENCODED_UINT_LEN
value|10
comment|/* Compression method parameters for svn__encode_uint. */
comment|/* No compression (but a length prefix will still be added to the buffer) */
define|#
directive|define
name|SVN__COMPRESSION_NONE
value|0
comment|/* Fastest, least effective compression method& level provided by zlib. */
define|#
directive|define
name|SVN__COMPRESSION_ZLIB_MIN
value|1
comment|/* Default compression method& level provided by zlib. */
define|#
directive|define
name|SVN__COMPRESSION_ZLIB_DEFAULT
value|5
comment|/* Slowest, best compression method& level provided by zlib. */
define|#
directive|define
name|SVN__COMPRESSION_ZLIB_MAX
value|9
comment|/* Encode VAL into the buffer P using the variable-length 7b/8b unsigned    integer format.  Return the incremented value of P after the    encoded bytes have been written.  P must point to a buffer of size    at least SVN__MAX_ENCODED_UINT_LEN.     This encoding uses the high bit of each byte as a continuation bit    and the other seven bits as data bits.  High-order data bits are    encoded first, followed by lower-order bits, so the value can be    reconstructed by concatenating the data bits from left to right and    interpreting the result as a binary number.  Examples (brackets    denote byte boundaries, spaces are for clarity only):             1 encodes as [0 0000001]           33 encodes as [0 0100001]          129 encodes as [1 0000001] [0 0000001]         2000 encodes as [1 0001111] [0 1010000] */
name|unsigned
name|char
modifier|*
name|svn__encode_uint
parameter_list|(
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|apr_uint64_t
name|val
parameter_list|)
function_decl|;
comment|/* Decode an unsigned 7b/8b-encoded integer into *VAL and return a pointer    to the byte after the integer.  The bytes to be decoded live in the    range [P..END-1].  If these bytes do not contain a whole encoded    integer, return NULL; in this case *VAL is undefined.     See the comment for svn__encode_uint() earlier in this file for more    detail on the encoding format.  */
specifier|const
name|unsigned
name|char
modifier|*
name|svn__decode_uint
parameter_list|(
name|apr_uint64_t
modifier|*
name|val
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|end
parameter_list|)
function_decl|;
comment|/* Get the data from IN, compress it according to the specified  * COMPRESSION_METHOD and write the result to OUT.  * SVN__COMPRESSION_NONE is valid for COMPRESSION_METHOD.  */
name|svn_error_t
modifier|*
name|svn__compress
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|in
parameter_list|,
name|svn_stringbuf_t
modifier|*
name|out
parameter_list|,
name|int
name|compression_method
parameter_list|)
function_decl|;
comment|/* Get the compressed data from IN, decompress it and write the result to  * OUT.  Return an error if the decompressed size is larger than LIMIT.  */
name|svn_error_t
modifier|*
name|svn__decompress
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|in
parameter_list|,
name|svn_stringbuf_t
modifier|*
name|out
parameter_list|,
name|apr_size_t
name|limit
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * @defgroup svn_root_pools Recycle-able root pools API  * @{  */
comment|/* Opaque thread-safe container for unused / recylcleable root pools.  *  * Recyling root pools (actually, their allocators) circumvents a  * scalability bottleneck in the OS memory management when multi-threaded  * applications frequently create and destroy allocators.  */
typedef|typedef
name|struct
name|svn_root_pools__t
name|svn_root_pools__t
typedef|;
comment|/* Create a new root pools container and return it in *POOLS.  */
name|svn_error_t
modifier|*
name|svn_root_pools__create
parameter_list|(
name|svn_root_pools__t
modifier|*
modifier|*
name|pools
parameter_list|)
function_decl|;
comment|/* Return a currently unused pool from POOLS.  If POOLS is empty, create a  * new root pool and return that.  The pool returned is not thread-safe.  */
name|apr_pool_t
modifier|*
name|svn_root_pools__acquire_pool
parameter_list|(
name|svn_root_pools__t
modifier|*
name|pools
parameter_list|)
function_decl|;
comment|/* Clear and release the given root POOL and put it back into POOLS.  * If that fails, destroy POOL.  */
name|void
name|svn_root_pools__release_pool
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
name|svn_root_pools__t
modifier|*
name|pools
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * @defgroup svn_config_private Private configuration handling API  * @{  */
comment|/* Future attempts to modify CFG will trigger an assertion. */
name|void
name|svn_config__set_read_only
parameter_list|(
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Return TRUE, if CFG cannot be modified. */
name|svn_boolean_t
name|svn_config__is_read_only
parameter_list|(
name|svn_config_t
modifier|*
name|cfg
parameter_list|)
function_decl|;
comment|/* Return TRUE, if OPTION in SECTION in CFG exists and does not require  * further expansion (due to either containing no placeholders or already  * having been expanded). */
name|svn_boolean_t
name|svn_config__is_expanded
parameter_list|(
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
specifier|const
name|char
modifier|*
name|section
parameter_list|,
specifier|const
name|char
modifier|*
name|option
parameter_list|)
function_decl|;
comment|/* Return a shallow copy of SCR in POOL.  If SRC is read-only, different  * shallow copies may be used from different threads.  *  * Any single r/o svn_config_t or shallow copy is not thread-safe because  * it contains shared buffers for tempoary data.  */
name|svn_config_t
modifier|*
name|svn_config__shallow_copy
parameter_list|(
name|svn_config_t
modifier|*
name|src
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Add / replace SECTION in TARGET with the same section from SOURCE by  * simply adding a reference to it.  If TARGET is read-only, the sections  * list in target gets duplicated before the modification.  *  * This is an API tailored for use by the svn_repos__authz_pool_t API to  * prevent breach of encapsulation.  */
name|void
name|svn_config__shallow_replace_section
parameter_list|(
name|svn_config_t
modifier|*
name|target
parameter_list|,
name|svn_config_t
modifier|*
name|source
parameter_list|,
specifier|const
name|char
modifier|*
name|section
parameter_list|)
function_decl|;
comment|/* Allocate *CFG_HASH and populate it with default, empty,  * svn_config_t for the configuration categories (@c  * SVN_CONFIG_CATEGORY_SERVERS, @c SVN_CONFIG_CATEGORY_CONFIG, etc.).  * This returns a hash equivalent to svn_config_get_config when the  * config files are empty.  */
name|svn_error_t
modifier|*
name|svn_config__get_default_config
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|cfg_hash
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * @defgroup svn_bit_array Packed bit array handling API  * @{  */
comment|/* This opaque data struct is an alternative to an INT->VOID hash.  *  * Technically, it is an automatically growing packed bit array.  * All indexes not previously set are implicitly 0 and setting it will  * grow the array as needed.  */
typedef|typedef
name|struct
name|svn_bit_array__t
name|svn_bit_array__t
typedef|;
comment|/* Return a new bit array allocated in POOL.  MAX is a mere hint for  * the initial size of the array in bits.  */
name|svn_bit_array__t
modifier|*
name|svn_bit_array__create
parameter_list|(
name|apr_size_t
name|max
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set bit at index IDX in ARRAY to VALUE.  If necessary, grow the  * underlying data buffer, i.e. any IDX is valid unless we run OOM.  */
name|void
name|svn_bit_array__set
parameter_list|(
name|svn_bit_array__t
modifier|*
name|array
parameter_list|,
name|apr_size_t
name|idx
parameter_list|,
name|svn_boolean_t
name|value
parameter_list|)
function_decl|;
comment|/* Get the bit value at index IDX in ARRAY.  Bits not previously accessed  * are implicitly 0 (or FALSE).  That implies IDX can never be out-of-range.  */
name|svn_boolean_t
name|svn_bit_array__get
parameter_list|(
name|svn_bit_array__t
modifier|*
name|array
parameter_list|,
name|apr_size_t
name|idx
parameter_list|)
function_decl|;
comment|/* Return the global pool used by the DSO loader, this may be NULL if    no DSOs have been loaded. */
name|apr_pool_t
modifier|*
name|svn_dso__pool
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** @} */
comment|/* Return the xml (expat) version we compiled against. */
specifier|const
name|char
modifier|*
name|svn_xml__compiled_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return the xml (expat) version we run against. */
specifier|const
name|char
modifier|*
name|svn_xml__runtime_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return the zlib version we compiled against. */
specifier|const
name|char
modifier|*
name|svn_zlib__compiled_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return the zlib version we run against. */
specifier|const
name|char
modifier|*
name|svn_zlib__runtime_version
parameter_list|(
name|void
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
comment|/* SVN_SUBR_PRIVATE_H */
end_comment

end_unit

