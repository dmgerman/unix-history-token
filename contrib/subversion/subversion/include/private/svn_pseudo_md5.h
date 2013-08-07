begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_pseudo_md5.h  * @brief Subversion hash sum calculation for runtime data (only)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_PSEUDO_MD5_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_PSEUDO_MD5_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_comment
comment|/* for apr_uint32_t */
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
comment|/**  * Calculates a hash sum for 15 bytes in @a x and returns it in @a digest.  * The most significant byte in @a x must be 0 (independent of being on a  * little or big endian machine).  *  * @note Use for runtime data hashing only.  *  * @note The output is NOT an MD5 digest shares has the same basic  *       cryptographic properties.  Collisions with proper MD5 on the same  *       or other input data is equally unlikely as any MD5 collision.  */
name|void
name|svn__pseudo_md5_15
parameter_list|(
name|apr_uint32_t
name|digest
index|[
literal|4
index|]
parameter_list|,
specifier|const
name|apr_uint32_t
name|x
index|[
literal|4
index|]
parameter_list|)
function_decl|;
comment|/**  * Calculates a hash sum for 31 bytes in @a x and returns it in @a digest.  * The most significant byte in @a x must be 0 (independent of being on a  * little or big endian machine).  *  * @note Use for runtime data hashing only.  *  * @note The output is NOT an MD5 digest shares has the same basic  *       cryptographic properties.  Collisions with proper MD5 on the same  *       or other input data is equally unlikely as any MD5 collision.  */
name|void
name|svn__pseudo_md5_31
parameter_list|(
name|apr_uint32_t
name|digest
index|[
literal|4
index|]
parameter_list|,
specifier|const
name|apr_uint32_t
name|x
index|[
literal|8
index|]
parameter_list|)
function_decl|;
comment|/**  * Calculates a hash sum for 63 bytes in @a x and returns it in @a digest.  * The most significant byte in @a x must be 0 (independent of being on a  * little or big endian machine).  *  * @note Use for runtime data hashing only.  *  * @note The output is NOT an MD5 digest shares has the same basic  *       cryptographic properties.  Collisions with proper MD5 on the same  *       or other input data is equally unlikely as any MD5 collision.  */
name|void
name|svn__pseudo_md5_63
parameter_list|(
name|apr_uint32_t
name|digest
index|[
literal|4
index|]
parameter_list|,
specifier|const
name|apr_uint32_t
name|x
index|[
literal|16
index|]
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
comment|/* SVN_PSEUDO_MD5_H */
end_comment

end_unit

