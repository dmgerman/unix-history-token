begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * auth.h :  shared stuff internal to the subr library.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_AUTH_H
end_define

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
include|#
directive|include
file|"svn_auth.h"
comment|/* Helper for svn_config_{read|write}_auth_data.  Return a path to a    file within ~/.subversion/auth/ that holds CRED_KIND credentials    within REALMSTRING.  If no path is available *PATH will be set to    NULL. */
name|svn_error_t
modifier|*
name|svn_auth__file_path
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|cred_kind
parameter_list|,
specifier|const
name|char
modifier|*
name|realmstring
parameter_list|,
specifier|const
name|char
modifier|*
name|config_dir
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_auth_get_simple_provider(), except that, when  * running on Window 2000 or newer (or any other Windows version that  * includes the CryptoAPI), the provider encrypts the password before  * storing it to disk. On earlier versions of Windows, the provider  * does nothing.  *  * @note This function is only available on Windows.  *  * @note An administrative password reset may invalidate the account's  * secret key. This function will detect that situation and behave as  * if the password were not cached at all.  */
name|void
name|svn_auth__get_windows_simple_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_pw_t that gets/sets information from the  * user's ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_auth_get_ssl_client_cert_pw_file_provider(), except that  * when running on Window 2000 or newer, the provider encrypts the password  * before storing it to disk. On earlier versions of Windows, the provider  * does nothing.  *  * @note This function is only available on Windows.  *  * @note An administrative password reset may invalidate the account's  * secret key. This function will detect that situation and behave as  * if the password were not cached at all.  */
name|void
name|svn_auth__get_windows_ssl_client_cert_pw_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_server_trust_t, allocated in @a pool.  *  * This provider automatically validates ssl server certificates with  * the CryptoApi, like Internet Explorer and the Windows network API do.  * This allows the rollout of root certificates via Windows Domain  * policies, instead of Subversion specific configuration.  *  * @note This function is only available on Windows.  */
name|void
name|svn_auth__get_windows_ssl_server_trust_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* WIN32&& !__MINGW32__ || DOXYGEN */
if|#
directive|if
name|defined
argument_list|(
name|DARWIN
argument_list|)
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_auth_get_simple_provider(), except that the  * password is stored in the Mac OS KeyChain.  *  * @note This function is only available on Mac OS 10.2 and higher.  */
name|void
name|svn_auth__get_keychain_simple_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_pw_t that gets/sets information from the  * user's ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_auth_get_ssl_client_cert_pw_file_provider(), except  * that the password is stored in the Mac OS KeyChain.  *  * @note This function is only available on Mac OS 10.2 and higher.  */
name|void
name|svn_auth__get_keychain_ssl_client_cert_pw_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* DARWIN || DOXYGEN */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  *  * This is like svn_client_get_simple_provider(), except that the  * password is obtained from gpg_agent, which will keep it in  * a memory cache.  *  * Allocate @a *provider in @a pool.  *  * @note This function actually works only on systems with  * GNU Privacy Guard installed.  */
name|void
name|svn_auth__get_gpg_agent_simple_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* !defined(WIN32) || defined(DOXYGEN) */
comment|/**  * Set @a *provider to a dummy provider of type @c  * svn_auth_cred_simple_t that never returns or stores any  * credentials.  */
name|void
name|svn_auth__get_dummmy_simple_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
comment|/* SVN_LIBSVN_SUBR_AUTH_H */
end_comment

end_unit

