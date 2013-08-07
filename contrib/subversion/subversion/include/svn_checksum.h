begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_checksum.h  * @brief Subversion checksum routines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CHECKSUM_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CHECKSUM_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_comment
comment|/* for apr_size_t */
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_comment
comment|/* for apr_pool_t */
end_comment

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_comment
comment|/* for svn_boolean_t, svn_error_t */
end_comment

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
comment|/**  * Various types of checksums.  *  * @since New in 1.6.  */
typedef|typedef
enum|enum
name|svn_checksum_kind_t
block|{
comment|/** The checksum is (or should be set to) an MD5 checksum. */
name|svn_checksum_md5
block|,
comment|/** The checksum is (or should be set to) a SHA1 checksum. */
name|svn_checksum_sha1
block|}
name|svn_checksum_kind_t
typedef|;
comment|/**  * A generic checksum representation.  *  * @since New in 1.6.  */
typedef|typedef
struct|struct
name|svn_checksum_t
block|{
comment|/** The bytes of the checksum. */
specifier|const
name|unsigned
name|char
modifier|*
name|digest
decl_stmt|;
comment|/** The type of the checksum.  This should never be changed by consumers       of the APIs. */
name|svn_checksum_kind_t
name|kind
decl_stmt|;
block|}
name|svn_checksum_t
typedef|;
comment|/**  * Opaque type for creating checksums of data.  */
typedef|typedef
name|struct
name|svn_checksum_ctx_t
name|svn_checksum_ctx_t
typedef|;
comment|/** Return a new checksum structure of type @a kind, initialized to the all-  * zeros value, allocated in @a pool.  *  * @since New in 1.6.  */
name|svn_checksum_t
modifier|*
name|svn_checksum_create
parameter_list|(
name|svn_checksum_kind_t
name|kind
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a checksum->digest to all zeros, which, by convention, matches  * all other checksums.  *  * @since New in 1.6.  */
name|svn_error_t
modifier|*
name|svn_checksum_clear
parameter_list|(
name|svn_checksum_t
modifier|*
name|checksum
parameter_list|)
function_decl|;
comment|/** Compare checksums @a checksum1 and @a checksum2.  If their kinds do not  * match or if neither is all zeros, and their content does not match, then  * return FALSE; else return TRUE.  *  * @since New in 1.6.  */
name|svn_boolean_t
name|svn_checksum_match
parameter_list|(
specifier|const
name|svn_checksum_t
modifier|*
name|checksum1
parameter_list|,
specifier|const
name|svn_checksum_t
modifier|*
name|checksum2
parameter_list|)
function_decl|;
comment|/**  * Return a deep copy of @a checksum, allocated in @a pool.  If @a  * checksum is NULL then NULL is returned.  *  * @since New in 1.6.  */
name|svn_checksum_t
modifier|*
name|svn_checksum_dup
parameter_list|(
specifier|const
name|svn_checksum_t
modifier|*
name|checksum
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return the hex representation of @a checksum, allocating the string  * in @a pool.  *  * @since New in 1.6.  */
specifier|const
name|char
modifier|*
name|svn_checksum_to_cstring_display
parameter_list|(
specifier|const
name|svn_checksum_t
modifier|*
name|checksum
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return the hex representation of @a checksum, allocating the  * string in @a pool.  If @a checksum->digest is all zeros (that is,  * 0, not '0') then return NULL. In 1.7+, @a checksum may be NULL  * and NULL will be returned in that case.  *  * @since New in 1.6.  * @note Passing NULL for @a checksum in 1.6 will cause a segfault.  */
specifier|const
name|char
modifier|*
name|svn_checksum_to_cstring
parameter_list|(
specifier|const
name|svn_checksum_t
modifier|*
name|checksum
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return a serialized representation of @a checksum, allocated in  * @a result_pool. Temporary allocations are performed in @a scratch_pool.  *  * Note that @a checksum may not be NULL.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_checksum_serialize
parameter_list|(
specifier|const
name|svn_checksum_t
modifier|*
name|checksum
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
comment|/** Return @a checksum from the serialized format at @a data. The checksum  * will be allocated in @a result_pool, with any temporary allocations  * performed in @a scratch_pool.  *  * @since New in 1.7.  */
name|svn_error_t
modifier|*
name|svn_checksum_deserialize
parameter_list|(
specifier|const
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
specifier|const
name|char
modifier|*
name|data
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
comment|/** Parse the hex representation @a hex of a checksum of kind @a kind and  * set @a *checksum to the result, allocating in @a pool.  *  * If @a hex is @c NULL or is the all-zeros checksum, then set @a *checksum  * to @c NULL.  *  * @since New in 1.6.  */
name|svn_error_t
modifier|*
name|svn_checksum_parse_hex
parameter_list|(
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
name|svn_checksum_kind_t
name|kind
parameter_list|,
specifier|const
name|char
modifier|*
name|hex
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return in @a *checksum the checksum of type @a kind for the bytes beginning  * at @a data, and going for @a len.  @a *checksum is allocated in @a pool.  *  * @since New in 1.6.  */
name|svn_error_t
modifier|*
name|svn_checksum
parameter_list|(
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
name|svn_checksum_kind_t
name|kind
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return in @a pool a newly allocated checksum populated with the checksum  * of type @a kind for the empty string.  *  * @since New in 1.6.  */
name|svn_checksum_t
modifier|*
name|svn_checksum_empty_checksum
parameter_list|(
name|svn_checksum_kind_t
name|kind
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Create a new @c svn_checksum_ctx_t structure, allocated from @a pool for  * calculating checksums of type @a kind.  @see svn_checksum_final()  *  * @since New in 1.6.  */
name|svn_checksum_ctx_t
modifier|*
name|svn_checksum_ctx_create
parameter_list|(
name|svn_checksum_kind_t
name|kind
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Update the checksum represented by @a ctx, with @a len bytes starting at  * @a data.  *  * @since New in 1.6.  */
name|svn_error_t
modifier|*
name|svn_checksum_update
parameter_list|(
name|svn_checksum_ctx_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Finalize the checksum used when creating @a ctx, and put the resultant  * checksum in @a *checksum, allocated in @a pool.  *  * @since New in 1.6.  */
name|svn_error_t
modifier|*
name|svn_checksum_final
parameter_list|(
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
specifier|const
name|svn_checksum_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return the digest size of @a checksum.  *  * @since New in 1.6.  */
name|apr_size_t
name|svn_checksum_size
parameter_list|(
specifier|const
name|svn_checksum_t
modifier|*
name|checksum
parameter_list|)
function_decl|;
comment|/**  * Return @c TRUE iff @a checksum matches the checksum for the empty  * string.  *  * @since New in 1.8.  */
name|svn_boolean_t
name|svn_checksum_is_empty_checksum
parameter_list|(
name|svn_checksum_t
modifier|*
name|checksum
parameter_list|)
function_decl|;
comment|/**  * Return an error of type #SVN_ERR_CHECKSUM_MISMATCH for @a actual and  * @a expected checksums which do not match.  Use @a fmt, and the following  * parameters to populate the error message.  *  * @note This function does not actually check for the mismatch, it just  * constructs the error.  *  * @a scratch_pool is used for temporary allocations; the returned error  * will be allocated in its own pool (as is typical).  *  * @since New in 1.7.  */
name|svn_error_t
modifier|*
name|svn_checksum_mismatch_err
parameter_list|(
specifier|const
name|svn_checksum_t
modifier|*
name|expected
parameter_list|,
specifier|const
name|svn_checksum_t
modifier|*
name|actual
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
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
function_decl|4
operator|,
function_decl|5
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

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
comment|/* SVN_CHECKSUM_H */
end_comment

end_unit

