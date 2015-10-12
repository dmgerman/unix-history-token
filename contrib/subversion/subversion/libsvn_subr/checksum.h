begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * checksum.h: Converting and comparing checksums  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_CHECKSUM_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_CHECKSUM_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_checksum.h"
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
comment|/* The digest of the given KIND for the empty string. */
specifier|const
name|unsigned
name|char
modifier|*
name|svn__empty_string_digest
parameter_list|(
name|svn_checksum_kind_t
name|kind
parameter_list|)
function_decl|;
comment|/* Return the hex representation of DIGEST, which must be  * DIGEST_SIZE bytes long, allocating the string in POOL.  */
specifier|const
name|char
modifier|*
name|svn__digest_to_cstring_display
parameter_list|(
specifier|const
name|unsigned
name|char
name|digest
index|[]
parameter_list|,
name|apr_size_t
name|digest_size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return the hex representation of DIGEST, which must be  * DIGEST_SIZE bytes long, allocating the string in POOL.  * If DIGEST is all zeros, then return NULL.  */
specifier|const
name|char
modifier|*
name|svn__digest_to_cstring
parameter_list|(
specifier|const
name|unsigned
name|char
name|digest
index|[]
parameter_list|,
name|apr_size_t
name|digest_size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Compare digests D1 and D2, each DIGEST_SIZE bytes long.  * If neither is all zeros, and they do not match, then return FALSE;  * else return TRUE.  */
name|svn_boolean_t
name|svn__digests_match
parameter_list|(
specifier|const
name|unsigned
name|char
name|d1
index|[]
parameter_list|,
specifier|const
name|unsigned
name|char
name|d2
index|[]
parameter_list|,
name|apr_size_t
name|digest_size
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
comment|/* SVN_LIBSVN_SUBR_CHECKSUM_H */
end_comment

end_unit

