begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * nls.c :  Helpers for NLS programs.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<apr_errno.h>
end_include

begin_include
include|#
directive|include
file|"svn_nls.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_path.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_utf_private.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_function
name|svn_error_t
modifier|*
name|svn_nls_init
parameter_list|(
name|void
parameter_list|)
block|{
name|svn_error_t
modifier|*
name|err
init|=
name|SVN_NO_ERROR
decl_stmt|;
ifdef|#
directive|ifdef
name|ENABLE_NLS
if|if
condition|(
name|getenv
argument_list|(
literal|"SVN_LOCALE_DIR"
argument_list|)
condition|)
block|{
name|bindtextdomain
argument_list|(
name|PACKAGE_NAME
argument_list|,
name|getenv
argument_list|(
literal|"SVN_LOCALE_DIR"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|WIN32
name|WCHAR
name|ucs2_path
index|[
name|MAX_PATH
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|utf8_path
decl_stmt|;
specifier|const
name|char
modifier|*
name|internal_path
decl_stmt|;
name|apr_pool_t
modifier|*
name|scratch_pool
decl_stmt|;
name|scratch_pool
operator|=
name|svn_pool_create
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
comment|/* get exe name - our locale info will be in '../share/locale' */
name|GetModuleFileNameW
argument_list|(
name|NULL
argument_list|,
name|ucs2_path
argument_list|,
sizeof|sizeof
argument_list|(
name|ucs2_path
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ucs2_path
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|apr_get_os_error
argument_list|()
condition|)
block|{
name|err
operator|=
name|svn_error_wrap_apr
argument_list|(
name|apr_get_os_error
argument_list|()
argument_list|,
name|_
argument_list|(
literal|"Can't get module file name"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|err
condition|)
name|err
operator|=
name|svn_utf__win32_utf16_to_utf8
argument_list|(
operator|&
name|utf8_path
argument_list|,
name|ucs2_path
argument_list|,
name|NULL
argument_list|,
name|scratch_pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
block|{
name|internal_path
operator|=
name|svn_dirent_internal_style
argument_list|(
name|utf8_path
argument_list|,
name|scratch_pool
argument_list|)
expr_stmt|;
comment|/* get base path name */
name|internal_path
operator|=
name|svn_dirent_dirname
argument_list|(
name|internal_path
argument_list|,
name|scratch_pool
argument_list|)
expr_stmt|;
name|internal_path
operator|=
name|svn_dirent_join
argument_list|(
name|internal_path
argument_list|,
name|SVN_LOCALE_RELATIVE_PATH
argument_list|,
name|scratch_pool
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_dirent_get_absolute
argument_list|(
operator|&
name|internal_path
argument_list|,
name|internal_path
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
name|bindtextdomain
argument_list|(
name|PACKAGE_NAME
argument_list|,
name|internal_path
argument_list|)
expr_stmt|;
block|}
name|svn_pool_destroy
argument_list|(
name|scratch_pool
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* ! WIN32 */
name|bindtextdomain
argument_list|(
name|PACKAGE_NAME
argument_list|,
name|SVN_LOCALE_DIR
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BIND_TEXTDOMAIN_CODESET
end_ifdef

begin_expr_stmt
name|bind_textdomain_codeset
argument_list|(
name|PACKAGE_NAME
argument_list|,
literal|"UTF-8"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BIND_TEXTDOMAIN_CODESET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENABLE_NLS */
end_comment

begin_return
return|return
name|err
return|;
end_return

unit|}
end_unit

