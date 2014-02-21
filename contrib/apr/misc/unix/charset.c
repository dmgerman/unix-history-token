begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_private.h"
end_include

begin_include
include|#
directive|include
file|"apr_strings.h"
end_include

begin_include
include|#
directive|include
file|"apr_portable.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LANGINFO_H
end_ifdef

begin_include
include|#
directive|include
file|<langinfo.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * simple heuristic to determine codepage of source code so that  * literal strings (e.g., "GET /\r\n") in source code can be translated  * properly  *  * If appropriate, a symbol can be set at configure time to determine  * this.  On EBCDIC platforms, it will be important how the code was  * unpacked.  */
end_comment

begin_macro
name|APR_DECLARE
argument_list|(
argument|const char*
argument_list|)
end_macro

begin_macro
name|apr_os_default_encoding
argument_list|(
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|__MVS__
ifdef|#
directive|ifdef
name|__CODESET__
return|return
name|__CODESET__
return|;
else|#
directive|else
return|return
literal|"IBM-1047"
return|;
endif|#
directive|endif
endif|#
directive|endif
if|if
condition|(
literal|'}'
operator|==
literal|0xD0
condition|)
block|{
return|return
literal|"IBM-1047"
return|;
block|}
if|if
condition|(
literal|'{'
operator|==
literal|0xFB
condition|)
block|{
return|return
literal|"EDF04"
return|;
block|}
if|if
condition|(
literal|'A'
operator|==
literal|0xC1
condition|)
block|{
return|return
literal|"EBCDIC"
return|;
comment|/* not useful */
block|}
if|if
condition|(
literal|'A'
operator|==
literal|0x41
condition|)
block|{
return|return
literal|"ISO-8859-1"
return|;
comment|/* not necessarily true */
block|}
return|return
literal|"unknown"
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|const char*
argument_list|)
end_macro

begin_macro
name|apr_os_locale_encoding
argument_list|(
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_NL_LANGINFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|CODESET
argument_list|)
specifier|const
name|char
modifier|*
name|charset
decl_stmt|;
name|charset
operator|=
name|nl_langinfo
argument_list|(
name|CODESET
argument_list|)
expr_stmt|;
if|if
condition|(
name|charset
operator|&&
operator|*
name|charset
condition|)
block|{
ifdef|#
directive|ifdef
name|_OSD_POSIX
comment|/* Bug workaround - delete as soon as fixed in OSD_POSIX */
comment|/* Some versions of OSD_POSIX return nl_langinfo(CODESET)="^[nN]" */
comment|/* Ignore the bogus information and use apr_os_default_encoding() */
if|if
condition|(
name|charset
index|[
literal|0
index|]
operator|!=
literal|'^'
condition|)
endif|#
directive|endif
return|return
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|charset
argument_list|)
return|;
block|}
endif|#
directive|endif
return|return
name|apr_os_default_encoding
argument_list|(
name|pool
argument_list|)
return|;
block|}
end_block

end_unit

