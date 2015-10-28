begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * md5.c:   checksum routines  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|<apr_md5.h>
end_include

begin_include
include|#
directive|include
file|"svn_checksum.h"
end_include

begin_include
include|#
directive|include
file|"svn_md5.h"
end_include

begin_include
include|#
directive|include
file|"checksum.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* These are all deprecated, and just wrap the internal functions defined    above. */
end_comment

begin_function
specifier|const
name|unsigned
name|char
modifier|*
name|svn_md5_empty_string_digest
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|svn__empty_string_digest
argument_list|(
name|svn_checksum_md5
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|svn_md5_digest_to_cstring_display
parameter_list|(
specifier|const
name|unsigned
name|char
name|digest
index|[]
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn__digest_to_cstring_display
argument_list|(
name|digest
argument_list|,
name|APR_MD5_DIGESTSIZE
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|svn_md5_digest_to_cstring
parameter_list|(
specifier|const
name|unsigned
name|char
name|digest
index|[]
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn__digest_to_cstring
argument_list|(
name|digest
argument_list|,
name|APR_MD5_DIGESTSIZE
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_function
name|svn_boolean_t
name|svn_md5_digests_match
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
parameter_list|)
block|{
return|return
name|svn__digests_match
argument_list|(
name|d1
argument_list|,
name|d2
argument_list|,
name|APR_MD5_DIGESTSIZE
argument_list|)
return|;
block|}
end_function

end_unit

