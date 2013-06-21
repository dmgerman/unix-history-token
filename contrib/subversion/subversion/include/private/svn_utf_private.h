begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_utf_private.h  * @brief UTF validation routines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_UTF_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_UTF_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/* Return TRUE if the string SRC of length LEN is a valid UTF-8 encoding  * according to the rules laid down by the Unicode 4.0 standard, FALSE  * otherwise.  This function is faster than svn_utf__last_valid().  */
name|svn_boolean_t
name|svn_utf__is_valid
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/* As for svn_utf__is_valid but SRC is NULL terminated. */
name|svn_boolean_t
name|svn_utf__cstring_is_valid
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
comment|/* Return a pointer to the first character after the last valid UTF-8  * potentially multi-byte character in the string SRC of length LEN.  * Validity of bytes from SRC to SRC+LEN-1, inclusively, is checked.  * If SRC is a valid UTF-8, the return value will point to the byte SRC+LEN,  * otherwise it will point to the start of the first invalid character.  * In either case all the characters between SRC and the return pointer - 1,  * inclusively, are valid UTF-8.  *  * See also svn_utf__is_valid().  */
specifier|const
name|char
modifier|*
name|svn_utf__last_valid
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/* As for svn_utf__last_valid but uses a different implementation without    lookup tables.  It avoids the table memory use (about 400 bytes) but the    function is longer (about 200 bytes extra) and likely to be slower when    the string is valid.  If the string is invalid this function may be    faster since it returns immediately rather than continuing to the end of    the string.  The main reason this function exists is to test the table    driven implementation.  */
specifier|const
name|char
modifier|*
name|svn_utf__last_valid2
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|svn_utf__cstring_from_utf8_fuzzy
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|convert_from_utf8
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|apr_pool_t
modifier|*
parameter_list|)
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
comment|/* SVN_UTF_PRIVATE_H */
end_comment

end_unit

