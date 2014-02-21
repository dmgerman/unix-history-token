begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* svn_token.h : value/string-token functions  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_TOKEN_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_TOKEN_H
end_define

begin_include
include|#
directive|include
file|"svn_error.h"
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
comment|/** A mapping between a string STR and an enumeration value VAL.  *  * Maps are an array of these, terminated with a struct where STR == NULL.  */
typedef|typedef
struct|struct
name|svn_token_map_t
block|{
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
name|svn_token_map_t
typedef|;
comment|/* A value used by some token functions to indicate an unrecognized token.  */
define|#
directive|define
name|SVN_TOKEN_UNKNOWN
value|(-9999)
comment|/* Return the string form of the given VALUE as found in MAP. If the value    is not recognized, then a MALFUNCTION will occur.  */
specifier|const
name|char
modifier|*
name|svn_token__to_word
parameter_list|(
specifier|const
name|svn_token_map_t
modifier|*
name|map
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
comment|/* NOTE: in the following functions, if WORD is NULL, then SVN_TOKEN_UNKNOWN    will be returned, or will cause the appropriate MALFUNCTION or ERROR.  */
comment|/* Return the integer value of the given token WORD, as found in MAP. If the    string is not recognized, then a MALFUNCTION will occur.     Note: this function is for persisted string values. Because this function    will throw a MALFUNCTION, it should not be used for network input or    user input.  */
name|int
name|svn_token__from_word_strict
parameter_list|(
specifier|const
name|svn_token_map_t
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
comment|/* Store the integer value of WORD into *VALUE. If the string is not    recognized, then SVN_ERR_BAD_TOKEN is returned.  */
name|svn_error_t
modifier|*
name|svn_token__from_word_err
parameter_list|(
name|int
modifier|*
name|value
parameter_list|,
specifier|const
name|svn_token_map_t
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
comment|/* Return the integer value of the given token WORD as found in MAP. If the    string is not recognized, then SVN_TOKEN_UNKNOWN will be returned.  */
name|int
name|svn_token__from_word
parameter_list|(
specifier|const
name|svn_token_map_t
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
comment|/* Return the integer value of the given token WORD/LEN as found in MAP. If    the string is not recognized, then SVN_TOKEN_UNKNOWN will be returned.  */
name|int
name|svn_token__from_mem
parameter_list|(
specifier|const
name|svn_token_map_t
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|word
parameter_list|,
name|apr_size_t
name|len
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
comment|/* SVN_TOKEN_H */
end_comment

end_unit

