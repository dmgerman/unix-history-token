begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_auth.h  * @brief Subversion's authentication system  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_AUTH_H
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
file|<apr_hash.h>
end_include

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/** Overview of the svn authentication system.  *  * We define an authentication "provider" as a module that is able to  * return a specific set of credentials. (e.g. username/password,  * certificate, etc.)  Each provider implements a vtable that  *  * - can fetch initial credentials  * - can retry the fetch (or try to fetch something different)  * - can store the credentials for future use  *  * For any given type of credentials, there can exist any number of  * separate providers -- each provider has a different method of  * fetching. (i.e. from a disk store, by prompting the user, etc.)  *  * The application begins by creating an auth baton object, and  * "registers" some number of providers with the auth baton, in a  * specific order.  (For example, it may first register a  * username/password provider that looks in disk store, then register  * a username/password provider that prompts the user.)  *  * Later on, when any svn library is challenged, it asks the auth  * baton for the specific credentials.  If the initial credentials  * fail to authenticate, the caller keeps requesting new credentials.  * Under the hood, libsvn_auth effectively "walks" over each provider  * (in order of registry), one at a time, until all the providers have  * exhausted all their retry options.  *  * This system allows an application to flexibly define authentication  * behaviors (by changing registration order), and very easily write  * new authentication providers.  *  * An auth_baton also contains an internal hashtable of run-time  * parameters; any provider or library layer can set these run-time  * parameters at any time, so that the provider has access to the  * data.  (For example, certain run-time data may not be available  * until an authentication challenge is made.)  Each credential type  * must document the run-time parameters that are made available to  * its providers.  *  * @defgroup auth_fns Authentication functions  * @{  */
comment|/** The type of a Subversion authentication object */
typedef|typedef
name|struct
name|svn_auth_baton_t
name|svn_auth_baton_t
typedef|;
comment|/** The type of a Subversion authentication-iteration object */
typedef|typedef
name|struct
name|svn_auth_iterstate_t
name|svn_auth_iterstate_t
typedef|;
comment|/** The main authentication "provider" vtable. */
typedef|typedef
struct|struct
name|svn_auth_provider_t
block|{
comment|/** The kind of credentials this provider knows how to retrieve. */
specifier|const
name|char
modifier|*
name|cred_kind
decl_stmt|;
comment|/** Get an initial set of credentials.    *    * Set @a *credentials to a set of valid credentials within @a    * realmstring, or NULL if no credentials are available.  Set @a    * *iter_baton to context that allows a subsequent call to @c    * next_credentials, in case the first credentials fail to    * authenticate.  @a provider_baton is general context for the    * vtable, @a parameters contains any run-time data that the    * provider may need, and @a realmstring comes from the    * svn_auth_first_credentials() call.    */
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|first_credentials
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
name|credentials
parameter_list|,
name|void
modifier|*
modifier|*
name|iter_baton
parameter_list|,
name|void
modifier|*
name|provider_baton
parameter_list|,
name|apr_hash_t
modifier|*
name|parameters
parameter_list|,
specifier|const
name|char
modifier|*
name|realmstring
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Get a different set of credentials.    *    * Set @a *credentials to another set of valid credentials (using @a    * iter_baton as the context from previous call to first_credentials    * or next_credentials).  If no more credentials are available, set    * @a *credentials to NULL.  If the provider only has one set of    * credentials, this function pointer should simply be NULL. @a    * provider_baton is general context for the vtable, @a parameters    * contains any run-time data that the provider may need, and @a    * realmstring comes from the svn_auth_first_credentials() call.    */
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|next_credentials
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
name|credentials
parameter_list|,
name|void
modifier|*
name|iter_baton
parameter_list|,
name|void
modifier|*
name|provider_baton
parameter_list|,
name|apr_hash_t
modifier|*
name|parameters
parameter_list|,
specifier|const
name|char
modifier|*
name|realmstring
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Save credentials.    *    * Store @a credentials for future use.  @a provider_baton is    * general context for the vtable, and @a parameters contains any    * run-time data the provider may need.  Set @a *saved to TRUE if    * the save happened, or FALSE if not.  The provider is not required    * to save; if it refuses or is unable to save for non-fatal    * reasons, return FALSE.  If the provider never saves data, then    * this function pointer should simply be NULL. @a realmstring comes    * from the svn_auth_first_credentials() call.    */
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|save_credentials
function_decl|)
parameter_list|(
name|svn_boolean_t
modifier|*
name|saved
parameter_list|,
name|void
modifier|*
name|credentials
parameter_list|,
name|void
modifier|*
name|provider_baton
parameter_list|,
name|apr_hash_t
modifier|*
name|parameters
parameter_list|,
specifier|const
name|char
modifier|*
name|realmstring
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
block|}
name|svn_auth_provider_t
typedef|;
comment|/** A provider object, ready to be put into an array and given to     svn_auth_open(). */
typedef|typedef
struct|struct
name|svn_auth_provider_object_t
block|{
specifier|const
name|svn_auth_provider_t
modifier|*
name|vtable
decl_stmt|;
name|void
modifier|*
name|provider_baton
decl_stmt|;
block|}
name|svn_auth_provider_object_t
typedef|;
comment|/** The type of function returning authentication provider. */
typedef|typedef
name|void
function_decl|(
modifier|*
name|svn_auth_simple_provider_func_t
function_decl|)
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
comment|/** Specific types of credentials **/
comment|/** Simple username/password pair credential kind.  *  * The following auth parameters are available to the providers:  *  * - @c SVN_AUTH_PARAM_CONFIG_CATEGORY_CONFIG (@c svn_config_t*)  * - @c SVN_AUTH_PARAM_CONFIG_CATEGORY_SERVERS (@c svn_config_t*)  *  * The following auth parameters may be available to the providers:  *  * - @c SVN_AUTH_PARAM_NO_AUTH_CACHE (@c void*)  * - @c SVN_AUTH_PARAM_DEFAULT_USERNAME (@c char*)  * - @c SVN_AUTH_PARAM_DEFAULT_PASSWORD (@c char*)  */
define|#
directive|define
name|SVN_AUTH_CRED_SIMPLE
value|"svn.simple"
comment|/** @c SVN_AUTH_CRED_SIMPLE credentials. */
typedef|typedef
struct|struct
name|svn_auth_cred_simple_t
block|{
comment|/** Username */
specifier|const
name|char
modifier|*
name|username
decl_stmt|;
comment|/** Password */
specifier|const
name|char
modifier|*
name|password
decl_stmt|;
comment|/** Indicates if the credentials may be saved (to disk). For example, a    * GUI prompt implementation with a remember password checkbox shall set    * @a may_save to TRUE if the checkbox is checked.    */
name|svn_boolean_t
name|may_save
decl_stmt|;
block|}
name|svn_auth_cred_simple_t
typedef|;
comment|/** Username credential kind.  *  * The following optional auth parameters are relevant to the providers:  *  * - @c SVN_AUTH_PARAM_NO_AUTH_CACHE (@c void*)  * - @c SVN_AUTH_PARAM_DEFAULT_USERNAME (@c char*)  */
define|#
directive|define
name|SVN_AUTH_CRED_USERNAME
value|"svn.username"
comment|/** @c SVN_AUTH_CRED_USERNAME credentials. */
typedef|typedef
struct|struct
name|svn_auth_cred_username_t
block|{
comment|/** Username */
specifier|const
name|char
modifier|*
name|username
decl_stmt|;
comment|/** Indicates if the credentials may be saved (to disk). For example, a    * GUI prompt implementation with a remember username checkbox shall set    * @a may_save to TRUE if the checkbox is checked.    */
name|svn_boolean_t
name|may_save
decl_stmt|;
block|}
name|svn_auth_cred_username_t
typedef|;
comment|/** SSL client certificate credential type.  *  * The following auth parameters are available to the providers:  *  * - @c SVN_AUTH_PARAM_CONFIG_CATEGORY_SERVERS (@c svn_config_t*)  * - @c SVN_AUTH_PARAM_SERVER_GROUP (@c char*)  *  * The following optional auth parameters are relevant to the providers:  *  * - @c SVN_AUTH_PARAM_NO_AUTH_CACHE (@c void*)  */
define|#
directive|define
name|SVN_AUTH_CRED_SSL_CLIENT_CERT
value|"svn.ssl.client-cert"
comment|/** @c SVN_AUTH_CRED_SSL_CLIENT_CERT credentials. */
typedef|typedef
struct|struct
name|svn_auth_cred_ssl_client_cert_t
block|{
comment|/** Absolute path to the certificate file */
specifier|const
name|char
modifier|*
name|cert_file
decl_stmt|;
comment|/** Indicates if the credentials may be saved (to disk). For example, a    * GUI prompt implementation with a remember certificate checkbox shall    * set @a may_save to TRUE if the checkbox is checked.    */
name|svn_boolean_t
name|may_save
decl_stmt|;
block|}
name|svn_auth_cred_ssl_client_cert_t
typedef|;
comment|/** A function returning an SSL client certificate passphrase provider. */
typedef|typedef
name|void
function_decl|(
modifier|*
name|svn_auth_ssl_client_cert_pw_provider_func_t
function_decl|)
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
comment|/** SSL client certificate passphrase credential type.  *  * @note The realmstring used with this credential type must be a name that  * makes it possible for the user to identify the certificate.  *  * The following auth parameters are available to the providers:  *  * - @c SVN_AUTH_PARAM_CONFIG_CATEGORY_CONFIG (@c svn_config_t*)  * - @c SVN_AUTH_PARAM_CONFIG_CATEGORY_SERVERS (@c svn_config_t*)  * - @c SVN_AUTH_PARAM_SERVER_GROUP (@c char*)  *  * The following optional auth parameters are relevant to the providers:  *  * - @c SVN_AUTH_PARAM_NO_AUTH_CACHE (@c void*)  */
define|#
directive|define
name|SVN_AUTH_CRED_SSL_CLIENT_CERT_PW
value|"svn.ssl.client-passphrase"
comment|/** @c SVN_AUTH_CRED_SSL_CLIENT_CERT_PW credentials. */
typedef|typedef
struct|struct
name|svn_auth_cred_ssl_client_cert_pw_t
block|{
comment|/** Certificate password */
specifier|const
name|char
modifier|*
name|password
decl_stmt|;
comment|/** Indicates if the credentials may be saved (to disk). For example, a    * GUI prompt implementation with a remember password checkbox shall set    * @a may_save to TRUE if the checkbox is checked.    */
name|svn_boolean_t
name|may_save
decl_stmt|;
block|}
name|svn_auth_cred_ssl_client_cert_pw_t
typedef|;
comment|/** SSL server verification credential type.  *  * The following auth parameters are available to the providers:  *  * - @c SVN_AUTH_PARAM_CONFIG_CATEGORY_SERVERS (@c svn_config_t*)  * - @c SVN_AUTH_PARAM_SERVER_GROUP (@c char*)  * - @c SVN_AUTH_PARAM_SSL_SERVER_FAILURES (@c apr_uint32_t*)  * - @c SVN_AUTH_PARAM_SSL_SERVER_CERT_INFO  *      (@c svn_auth_ssl_server_cert_info_t*)  *  * The following optional auth parameters are relevant to the providers:  *  * - @c SVN_AUTH_PARAM_NO_AUTH_CACHE (@c void*)  */
define|#
directive|define
name|SVN_AUTH_CRED_SSL_SERVER_TRUST
value|"svn.ssl.server"
comment|/** SSL server certificate information used by @c  * SVN_AUTH_CRED_SSL_SERVER_TRUST providers.  */
typedef|typedef
struct|struct
name|svn_auth_ssl_server_cert_info_t
block|{
comment|/** Primary CN */
specifier|const
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/** ASCII fingerprint */
specifier|const
name|char
modifier|*
name|fingerprint
decl_stmt|;
comment|/** ASCII date from which the certificate is valid */
specifier|const
name|char
modifier|*
name|valid_from
decl_stmt|;
comment|/** ASCII date until which the certificate is valid */
specifier|const
name|char
modifier|*
name|valid_until
decl_stmt|;
comment|/** DN of the certificate issuer */
specifier|const
name|char
modifier|*
name|issuer_dname
decl_stmt|;
comment|/** Base-64 encoded DER certificate representation */
specifier|const
name|char
modifier|*
name|ascii_cert
decl_stmt|;
block|}
name|svn_auth_ssl_server_cert_info_t
typedef|;
comment|/**  * Return a deep copy of @a info, allocated in @a pool.  *  * @since New in 1.3.  */
name|svn_auth_ssl_server_cert_info_t
modifier|*
name|svn_auth_ssl_server_cert_info_dup
parameter_list|(
specifier|const
name|svn_auth_ssl_server_cert_info_t
modifier|*
name|info
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @c SVN_AUTH_CRED_SSL_SERVER_TRUST credentials. */
typedef|typedef
struct|struct
name|svn_auth_cred_ssl_server_trust_t
block|{
comment|/** Indicates if the credentials may be saved (to disk). For example, a    * GUI prompt implementation with a checkbox to accept the certificate    * permanently shall set @a may_save to TRUE if the checkbox is checked.    */
name|svn_boolean_t
name|may_save
decl_stmt|;
comment|/** Bit mask of the accepted failures */
name|apr_uint32_t
name|accepted_failures
decl_stmt|;
block|}
name|svn_auth_cred_ssl_server_trust_t
typedef|;
comment|/** Credential-constructing prompt functions. **/
comment|/** These exist so that different client applications can use  * different prompt mechanisms to supply the same credentials.  For  * example, if authentication requires a username and password, a  * command-line client's prompting function might prompt first for the  * username and then for the password, whereas a GUI client's would  * present a single dialog box asking for both, and a telepathic  * client's would read all the information directly from the user's  * mind.  All these prompting functions return the same type of  * credential, but the information used to construct the credential is  * gathered in an interface-specific way in each case.  */
comment|/** Set @a *cred by prompting the user, allocating @a *cred in @a pool.  * @a baton is an implementation-specific closure.  *  * If @a realm is non-NULL, maybe use it in the prompt string.  *  * If @a username is non-NULL, then the user might be prompted only  * for a password, but @a *cred would still be filled with both  * username and password.  For example, a typical usage would be to  * pass @a username on the first call, but then leave it NULL for  * subsequent calls, on the theory that if credentials failed, it's  * as likely to be due to incorrect username as incorrect password.  *  * If @a may_save is FALSE, the auth system does not allow the credentials  * to be saved (to disk). A prompt function shall not ask the user if the  * credentials shall be saved if @a may_save is FALSE. For example, a GUI  * client with a remember password checkbox would grey out the checkbox if  * @a may_save is FALSE.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_auth_simple_prompt_func_t
function_decl|)
parameter_list|(
name|svn_auth_cred_simple_t
modifier|*
modifier|*
name|cred
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
specifier|const
name|char
modifier|*
name|username
parameter_list|,
name|svn_boolean_t
name|may_save
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *cred by prompting the user, allocating @a *cred in @a pool.  * @a baton is an implementation-specific closure.  *  * If @a realm is non-NULL, maybe use it in the prompt string.  *  * If @a may_save is FALSE, the auth system does not allow the credentials  * to be saved (to disk). A prompt function shall not ask the user if the  * credentials shall be saved if @a may_save is FALSE. For example, a GUI  * client with a remember username checkbox would grey out the checkbox if  * @a may_save is FALSE.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_auth_username_prompt_func_t
function_decl|)
parameter_list|(
name|svn_auth_cred_username_t
modifier|*
modifier|*
name|cred
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
name|svn_boolean_t
name|may_save
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @name SSL server certificate failure bits  *  * @note These values are stored in the on disk auth cache by the SSL  * server certificate auth provider, so the meaning of these bits must  * not be changed.  * @{  */
comment|/** Certificate is not yet valid. */
define|#
directive|define
name|SVN_AUTH_SSL_NOTYETVALID
value|0x00000001
comment|/** Certificate has expired. */
define|#
directive|define
name|SVN_AUTH_SSL_EXPIRED
value|0x00000002
comment|/** Certificate's CN (hostname) does not match the remote hostname. */
define|#
directive|define
name|SVN_AUTH_SSL_CNMISMATCH
value|0x00000004
comment|/** @brief Certificate authority is unknown (i.e. not trusted) */
define|#
directive|define
name|SVN_AUTH_SSL_UNKNOWNCA
value|0x00000008
comment|/** @brief Other failure. This can happen if an unknown failure occurs  * that we do not handle yet. */
define|#
directive|define
name|SVN_AUTH_SSL_OTHER
value|0x40000000
comment|/** @} */
comment|/** Set @a *cred by prompting the user, allocating @a *cred in @a pool.  * @a baton is an implementation-specific closure.  *  * @a cert_info is a structure describing the server cert that was  * presented to the client, and @a failures is a bitmask that  * describes exactly why the cert could not be automatically validated,  * composed from the constants SVN_AUTH_SSL_* (@c SVN_AUTH_SSL_NOTYETVALID  * etc.).  @a realm is a string that can be used in the prompt string.  *  * If @a may_save is FALSE, the auth system does not allow the credentials  * to be saved (to disk). A prompt function shall not ask the user if the  * credentials shall be saved if @a may_save is FALSE. For example, a GUI  * client with a trust permanently checkbox would grey out the checkbox if  * @a may_save is FALSE.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_auth_ssl_server_trust_prompt_func_t
function_decl|)
parameter_list|(
name|svn_auth_cred_ssl_server_trust_t
modifier|*
modifier|*
name|cred
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
name|apr_uint32_t
name|failures
parameter_list|,
specifier|const
name|svn_auth_ssl_server_cert_info_t
modifier|*
name|cert_info
parameter_list|,
name|svn_boolean_t
name|may_save
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *cred by prompting the user, allocating @a *cred in @a pool.  * @a baton is an implementation-specific closure.  @a realm is a string  * that can be used in the prompt string.  *  * If @a may_save is FALSE, the auth system does not allow the credentials  * to be saved (to disk). A prompt function shall not ask the user if the  * credentials shall be saved if @a may_save is FALSE. For example, a GUI  * client with a remember certificate checkbox would grey out the checkbox  * if @a may_save is FALSE.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_auth_ssl_client_cert_prompt_func_t
function_decl|)
parameter_list|(
name|svn_auth_cred_ssl_client_cert_t
modifier|*
modifier|*
name|cred
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
name|svn_boolean_t
name|may_save
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *cred by prompting the user, allocating @a *cred in @a pool.  * @a baton is an implementation-specific closure.  @a realm is a string  * identifying the certificate, and can be used in the prompt string.  *  * If @a may_save is FALSE, the auth system does not allow the credentials  * to be saved (to disk). A prompt function shall not ask the user if the  * credentials shall be saved if @a may_save is FALSE. For example, a GUI  * client with a remember password checkbox would grey out the checkbox if  * @a may_save is FALSE.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_auth_ssl_client_cert_pw_prompt_func_t
function_decl|)
parameter_list|(
name|svn_auth_cred_ssl_client_cert_pw_t
modifier|*
modifier|*
name|cred
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
name|svn_boolean_t
name|may_save
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** A type of callback function for asking whether storing a password to  * disk in plaintext is allowed.  *  * In this callback, the client should ask the user whether storing  * a password for the realm identified by @a realmstring to disk  * in plaintext is allowed.  *  * The answer is returned in @a *may_save_plaintext.  * @a baton is an implementation-specific closure.  * All allocations should be done in @a pool.  *  * @since New in 1.6  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_auth_plaintext_prompt_func_t
function_decl|)
parameter_list|(
name|svn_boolean_t
modifier|*
name|may_save_plaintext
parameter_list|,
specifier|const
name|char
modifier|*
name|realmstring
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** A type of callback function for asking whether storing a passphrase to  * disk in plaintext is allowed.  *  * In this callback, the client should ask the user whether storing  * a passphrase for the realm identified by @a realmstring to disk  * in plaintext is allowed.  *  * The answer is returned in @a *may_save_plaintext.  * @a baton is an implementation-specific closure.  * All allocations should be done in @a pool.  *  * @since New in 1.6  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_auth_plaintext_passphrase_prompt_func_t
function_decl|)
parameter_list|(
name|svn_boolean_t
modifier|*
name|may_save_plaintext
parameter_list|,
specifier|const
name|char
modifier|*
name|realmstring
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Initialize an authentication system.  *  * Return an authentication object in @a *auth_baton (allocated in @a  * pool) that represents a particular instance of the svn  * authentication system.  @a providers is an array of @c  * svn_auth_provider_object_t pointers, already allocated in @a pool  * and intentionally ordered.  These pointers will be stored within @a  * *auth_baton, grouped by credential type, and searched in this exact  * order.  */
name|void
name|svn_auth_open
parameter_list|(
name|svn_auth_baton_t
modifier|*
modifier|*
name|auth_baton
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|providers
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set an authentication run-time parameter.  *  * Store @a name / @a value pair as a run-time parameter in @a  * auth_baton, making the data accessible to all providers.  @a name  * and @a value will NOT be duplicated into the auth_baton's pool.  * To delete a run-time parameter, pass NULL for @a value.  */
name|void
name|svn_auth_set_parameter
parameter_list|(
name|svn_auth_baton_t
modifier|*
name|auth_baton
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
comment|/** Get an authentication run-time parameter.  *  * Return a value for run-time parameter @a name from @a auth_baton.  * Return NULL if the parameter doesn't exist.  */
specifier|const
name|void
modifier|*
name|svn_auth_get_parameter
parameter_list|(
name|svn_auth_baton_t
modifier|*
name|auth_baton
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/** Universal run-time parameters, made available to all providers.      If you are writing a new provider, then to be a "good citizen",     you should notice these global parameters!  Note that these     run-time params should be treated as read-only by providers; the     application is responsible for placing them into the auth_baton     hash. */
comment|/** The auth-hash prefix indicating that the parameter is global. */
define|#
directive|define
name|SVN_AUTH_PARAM_PREFIX
value|"svn:auth:"
comment|/**  * @name Default credentials defines  * Property values are const char *.  * @{ */
comment|/** Default username provided by the application itself (e.g. --username) */
define|#
directive|define
name|SVN_AUTH_PARAM_DEFAULT_USERNAME
value|SVN_AUTH_PARAM_PREFIX "username"
comment|/** Default password provided by the application itself (e.g. --password) */
define|#
directive|define
name|SVN_AUTH_PARAM_DEFAULT_PASSWORD
value|SVN_AUTH_PARAM_PREFIX "password"
comment|/** @} */
comment|/** @brief The application doesn't want any providers to prompt  * users. Property value is irrelevant; only property's existence  * matters. */
define|#
directive|define
name|SVN_AUTH_PARAM_NON_INTERACTIVE
value|SVN_AUTH_PARAM_PREFIX "non-interactive"
comment|/** @brief The application doesn't want any providers to save passwords  * to disk. Property value is irrelevant; only property's existence  * matters. */
define|#
directive|define
name|SVN_AUTH_PARAM_DONT_STORE_PASSWORDS
value|SVN_AUTH_PARAM_PREFIX \                                                  "dont-store-passwords"
comment|/** @brief Indicates whether providers may save passwords to disk in  * plaintext. Property value can be either SVN_CONFIG_TRUE,  * SVN_CONFIG_FALSE, or SVN_CONFIG_ASK.  * @since New in 1.6.  */
define|#
directive|define
name|SVN_AUTH_PARAM_STORE_PLAINTEXT_PASSWORDS
value|SVN_AUTH_PARAM_PREFIX \                                                   "store-plaintext-passwords"
comment|/** @brief The application doesn't want any providers to save passphrase  * to disk. Property value is irrelevant; only property's existence  * matters.  * @since New in 1.6.  */
define|#
directive|define
name|SVN_AUTH_PARAM_DONT_STORE_SSL_CLIENT_CERT_PP
define|\
value|SVN_AUTH_PARAM_PREFIX "dont-store-ssl-client-cert-pp"
comment|/** @brief Indicates whether providers may save passphrase to disk in  * plaintext. Property value can be either SVN_CONFIG_TRUE,  * SVN_CONFIG_FALSE, or SVN_CONFIG_ASK.  * @since New in 1.6.  */
define|#
directive|define
name|SVN_AUTH_PARAM_STORE_SSL_CLIENT_CERT_PP_PLAINTEXT
define|\
value|SVN_AUTH_PARAM_PREFIX "store-ssl-client-cert-pp-plaintext"
comment|/** @brief The application doesn't want any providers to save credentials  * to disk. Property value is irrelevant; only property's existence  * matters. */
define|#
directive|define
name|SVN_AUTH_PARAM_NO_AUTH_CACHE
value|SVN_AUTH_PARAM_PREFIX "no-auth-cache"
comment|/** @brief The following property is for SSL server cert providers. This  * provides a pointer to an @c apr_uint32_t containing the failures  * detected by the certificate validator. */
define|#
directive|define
name|SVN_AUTH_PARAM_SSL_SERVER_FAILURES
value|SVN_AUTH_PARAM_PREFIX \   "ssl:failures"
comment|/** @brief The following property is for SSL server cert providers. This  * provides the cert info (svn_auth_ssl_server_cert_info_t). */
define|#
directive|define
name|SVN_AUTH_PARAM_SSL_SERVER_CERT_INFO
value|SVN_AUTH_PARAM_PREFIX \   "ssl:cert-info"
comment|/** This provides a pointer to a @c svn_config_t containting the config  * category. */
define|#
directive|define
name|SVN_AUTH_PARAM_CONFIG_CATEGORY_CONFIG
value|SVN_AUTH_PARAM_PREFIX \   "config-category-config"
comment|/** This provides a pointer to a @c svn_config_t containting the servers  * category. */
define|#
directive|define
name|SVN_AUTH_PARAM_CONFIG_CATEGORY_SERVERS
value|SVN_AUTH_PARAM_PREFIX \   "config-category-servers"
comment|/** @deprecated Provided for backward compatibility with the 1.5 API. */
define|#
directive|define
name|SVN_AUTH_PARAM_CONFIG
value|SVN_AUTH_PARAM_CONFIG_CATEGORY_SERVERS
comment|/** The current server group. */
define|#
directive|define
name|SVN_AUTH_PARAM_SERVER_GROUP
value|SVN_AUTH_PARAM_PREFIX "server-group"
comment|/** @brief A configuration directory that overrides the default  * ~/.subversion. */
define|#
directive|define
name|SVN_AUTH_PARAM_CONFIG_DIR
value|SVN_AUTH_PARAM_PREFIX "config-dir"
comment|/** Get an initial set of credentials.  *  * Ask @a auth_baton to set @a *credentials to a set of credentials  * defined by @a cred_kind and valid within @a realmstring, or NULL if  * no credentials are available.  Otherwise, return an iteration state  * in @a *state, so that the caller can call  * svn_auth_next_credentials(), in case the first set of credentials  * fails to authenticate.  *  * Use @a pool to allocate @a *state, and for temporary allocation.  * Note that @a *credentials will be allocated in @a auth_baton's pool.  */
name|svn_error_t
modifier|*
name|svn_auth_first_credentials
parameter_list|(
name|void
modifier|*
modifier|*
name|credentials
parameter_list|,
name|svn_auth_iterstate_t
modifier|*
modifier|*
name|state
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
name|svn_auth_baton_t
modifier|*
name|auth_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Get another set of credentials, assuming previous ones failed to  * authenticate.  *  * Use @a state to fetch a different set of @a *credentials, as a  * follow-up to svn_auth_first_credentials() or  * svn_auth_next_credentials().  If no more credentials are available,  * set @a *credentials to NULL.  *  * Note that @a *credentials will be allocated in @c auth_baton's pool.  */
name|svn_error_t
modifier|*
name|svn_auth_next_credentials
parameter_list|(
name|void
modifier|*
modifier|*
name|credentials
parameter_list|,
name|svn_auth_iterstate_t
modifier|*
name|state
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Save a set of credentials.  *  * Ask @a state to store the most recently returned credentials,  * presumably because they successfully authenticated.  * All allocations should be done in @a pool.  *  * If no credentials were ever returned, do nothing.  */
name|svn_error_t
modifier|*
name|svn_auth_save_credentials
parameter_list|(
name|svn_auth_iterstate_t
modifier|*
name|state
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Forget a set (or all) memory-cached credentials.  *  * Remove references (if any) in @a auth_baton to credentials cached  * therein.  If @a cred_kind and @a realmstring are non-NULL, forget  * only the credentials associated with those credential types and  * realm.  Otherwise @a cred_kind and @a realmstring must both be  * NULL, and this function will forget all credentials cached within  * @a auth_baton.  *  * @note This function does not affect persisted authentication  * credential storage at all.  It is merely a way to cause Subversion  * to forget about credentials already fetched from a provider,  * forcing them to be fetched again later should they be required.  *  * @since New in 1.8.  */
name|svn_error_t
modifier|*
name|svn_auth_forget_credentials
parameter_list|(
name|svn_auth_baton_t
modifier|*
name|auth_baton
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @} */
comment|/** Set @a *provider to an authentication provider of type  * svn_auth_cred_simple_t that gets information by prompting the user  * with @a prompt_func and @a prompt_baton.  Allocate @a *provider in  * @a pool.  *  * If both @c SVN_AUTH_PARAM_DEFAULT_USERNAME and  * @c SVN_AUTH_PARAM_DEFAULT_PASSWORD are defined as runtime  * parameters in the @c auth_baton, then @a *provider will return the  * default arguments when svn_auth_first_credentials() is called.  If  * svn_auth_first_credentials() fails, then @a *provider will  * re-prompt @a retry_limit times (via svn_auth_next_credentials()).  * For infinite retries, set @a retry_limit to value less than 0.  *  * @since New in 1.4.  */
name|void
name|svn_auth_get_simple_prompt_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|svn_auth_simple_prompt_func_t
name|prompt_func
parameter_list|,
name|void
modifier|*
name|prompt_baton
parameter_list|,
name|int
name|retry_limit
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_username_t that gets information by prompting the  * user with @a prompt_func and @a prompt_baton.  Allocate @a *provider  * in @a pool.  *  * If @c SVN_AUTH_PARAM_DEFAULT_USERNAME is defined as a runtime  * parameter in the @c auth_baton, then @a *provider will return the  * default argument when svn_auth_first_credentials() is called.  If  * svn_auth_first_credentials() fails, then @a *provider will  * re-prompt @a retry_limit times (via svn_auth_next_credentials()).  * For infinite retries, set @a retry_limit to value less than 0.  *  * @since New in 1.4.  */
name|void
name|svn_auth_get_username_prompt_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|svn_auth_username_prompt_func_t
name|prompt_func
parameter_list|,
name|void
modifier|*
name|prompt_baton
parameter_list|,
name|int
name|retry_limit
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  *  * If the provider is going to save the password unencrypted, it calls @a  * plaintext_prompt_func, passing @a prompt_baton, before saving the  * password.  *  * If @a plaintext_prompt_func is NULL it is not called and the answer is  * assumed to be TRUE. This matches the deprecated behaviour of storing  * unencrypted passwords by default, and is only done this way for backward  * compatibility reasons.  * Client developers are highly encouraged to provide this callback  * to ensure their users are made aware of the fact that their password  * is going to be stored unencrypted. In the future, providers may  * default to not storing the password unencrypted if this callback is NULL.  *  * Clients can however set the callback to NULL and set  * SVN_AUTH_PARAM_STORE_PLAINTEXT_PASSWORDS to SVN_CONFIG_FALSE or  * SVN_CONFIG_TRUE to enforce a certain behaviour.  *  * Allocate @a *provider in @a pool.  *  * If a default username or password is available, @a *provider will  * honor them as well, and return them when  * svn_auth_first_credentials() is called.  (see @c  * SVN_AUTH_PARAM_DEFAULT_USERNAME and @c  * SVN_AUTH_PARAM_DEFAULT_PASSWORD).  *  * @since New in 1.6.  */
name|void
name|svn_auth_get_simple_provider2
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|svn_auth_plaintext_prompt_func_t
name|plaintext_prompt_func
parameter_list|,
name|void
modifier|*
name|prompt_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Like svn_auth_get_simple_provider2, but without the ability to  * call the svn_auth_plaintext_prompt_func_t callback, and the provider  * always assumes that it is allowed to store the password in plaintext.  *  * @deprecated Provided for backwards compatibility with the 1.5 API.  * @since New in 1.4.  */
name|SVN_DEPRECATED
name|void
name|svn_auth_get_simple_provider
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
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_provider_object_t, or return @c NULL if the provider is not  * available for the requested platform or the requested provider is unknown.  *  * Valid @a provider_name values are: "gnome_keyring", "keychain", "kwallet",  * "gpg_agent", and "windows".  *  * Valid @a provider_type values are: "simple", "ssl_client_cert_pw" and  * "ssl_server_trust".  *  * Allocate @a *provider in @a pool.  *  * What actually happens is we invoke the appropriate provider function to  * supply the @a provider, like so:  *  *    svn_auth_get_<name>_<type>_provider(@a provider, @a pool);  *  * @since New in 1.6.  */
name|svn_error_t
modifier|*
name|svn_auth_get_platform_specific_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
specifier|const
name|char
modifier|*
name|provider_name
parameter_list|,
specifier|const
name|char
modifier|*
name|provider_type
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *providers to an array of<tt>svn_auth_provider_object_t *</tt>  * objects.  * Only client authentication providers available for the current platform are  * returned. Order of the platform-specific authentication providers is  * determined by the 'password-stores' configuration option which is retrieved  * from @a config. @a config can be NULL.  *  * Create and allocate @a *providers in @a pool.  *  * Default order of the platform-specific authentication providers:  *   1. gnome-keyring  *   2. kwallet  *   3. keychain  *   4. gpg-agent  *   5. windows-cryptoapi  *  * @since New in 1.6.  */
name|svn_error_t
modifier|*
name|svn_auth_get_platform_specific_client_providers
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|providers
parameter_list|,
name|svn_config_t
modifier|*
name|config
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
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_auth_get_simple_provider(), except that, when  * running on Window 2000 or newer (or any other Windows version that  * includes the CryptoAPI), the provider encrypts the password before  * storing it to disk. On earlier versions of Windows, the provider  * does nothing.  *  * @since New in 1.4.  * @note This function is only available on Windows.  *  * @note An administrative password reset may invalidate the account's  * secret key. This function will detect that situation and behave as  * if the password were not cached at all.  */
name|void
name|svn_auth_get_windows_simple_provider
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
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_pw_t that gets/sets information from the  * user's ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_auth_get_ssl_client_cert_pw_file_provider(), except that  * when running on Window 2000 or newer, the provider encrypts the password  * before storing it to disk. On earlier versions of Windows, the provider  * does nothing.  *  * @since New in 1.6  * @note This function is only available on Windows.  *  * @note An administrative password reset may invalidate the account's  * secret key. This function will detect that situation and behave as  * if the password were not cached at all.  */
name|void
name|svn_auth_get_windows_ssl_client_cert_pw_provider
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
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_server_trust_t, allocated in @a pool.  *  * This provider automatically validates ssl server certificates with  * the CryptoApi, like Internet Explorer and the Windows network API do.  * This allows the rollout of root certificates via Windows Domain  * policies, instead of Subversion specific configuration.  *  * @since New in 1.5.  * @note This function is only available on Windows.  */
name|void
name|svn_auth_get_windows_ssl_server_trust_provider
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
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_auth_get_simple_provider(), except that the  * password is stored in the Mac OS KeyChain.  *  * @since New in 1.4  * @note This function is only available on Mac OS 10.2 and higher.  */
name|void
name|svn_auth_get_keychain_simple_provider
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
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_pw_t that gets/sets information from the  * user's ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_auth_get_ssl_client_cert_pw_file_provider(), except  * that the password is stored in the Mac OS KeyChain.  *  * @since New in 1.6  * @note This function is only available on Mac OS 10.2 and higher.  */
name|void
name|svn_auth_get_keychain_ssl_client_cert_pw_provider
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
comment|/* Note that the gnome keyring unlock prompt related items below must be  * declared for all platforms in order to allow SWIG interfaces to be  * used regardless of the platform. */
comment|/** A type of callback function for obtaining the GNOME Keyring password.  *  * In this callback, the client should ask the user for default keyring  * @a keyring_name password.  *  * The answer is returned in @a *keyring_password.  * @a baton is an implementation-specific closure.  * All allocations should be done in @a pool.  *  * @since New in 1.6  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_auth_gnome_keyring_unlock_prompt_func_t
function_decl|)
parameter_list|(
name|char
modifier|*
modifier|*
name|keyring_password
parameter_list|,
specifier|const
name|char
modifier|*
name|keyring_name
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** libsvn_auth_gnome_keyring-specific run-time parameters. */
comment|/** @brief The pointer to function which prompts user for GNOME Keyring  * password.  * The type of this pointer should be svn_auth_gnome_keyring_unlock_prompt_func_t. */
define|#
directive|define
name|SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_FUNC
value|"gnome-keyring-unlock-prompt-func"
comment|/** @brief The baton which is passed to  * @c *SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_FUNC. */
define|#
directive|define
name|SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_BATON
value|"gnome-keyring-unlock-prompt-baton"
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|DARWIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * Get libsvn_auth_gnome_keyring version information.  *  * @since New in 1.6  */
specifier|const
name|svn_version_t
modifier|*
name|svn_auth_gnome_keyring_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  *  * This is like svn_client_get_simple_provider(), except that the  * password is stored in GNOME Keyring.  *  * If the GNOME Keyring is locked the provider calls  * @c *SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_FUNC in order to unlock  * the keyring.  *  * @c SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_BATON is passed to  * @c *SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_FUNC.  *  * Allocate @a *provider in @a pool.  *  * @since New in 1.6  * @note This function actually works only on systems with  * libsvn_auth_gnome_keyring and GNOME Keyring installed.  */
name|void
name|svn_auth_get_gnome_keyring_simple_provider
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
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_pw_t that gets/sets information from the  * user's ~/.subversion configuration directory.  *  * This is like svn_client_get_ssl_client_cert_pw_file_provider(), except  * that the password is stored in GNOME Keyring.  *  * If the GNOME Keyring is locked the provider calls  * @c *SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_FUNC in order to unlock  * the keyring.  *  * @c SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_BATON is passed to  * @c *SVN_AUTH_PARAM_GNOME_KEYRING_UNLOCK_PROMPT_FUNC.  *  * Allocate @a *provider in @a pool.  *  * @since New in 1.6  * @note This function actually works only on systems with  * libsvn_auth_gnome_keyring and GNOME Keyring installed.  */
name|void
name|svn_auth_get_gnome_keyring_ssl_client_cert_pw_provider
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
comment|/**  * Get libsvn_auth_kwallet version information.  *  * @since New in 1.6  */
specifier|const
name|svn_version_t
modifier|*
name|svn_auth_kwallet_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_client_get_simple_provider(), except that the  * password is stored in KWallet.  *  * @since New in 1.6  * @note This function actually works only on systems with libsvn_auth_kwallet  * and KWallet installed.  */
name|void
name|svn_auth_get_kwallet_simple_provider
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
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_pw_t that gets/sets information from the  * user's ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * This is like svn_client_get_ssl_client_cert_pw_file_provider(), except  * that the password is stored in KWallet.  *  * @since New in 1.6  * @note This function actually works only on systems with libsvn_auth_kwallet  * and KWallet installed.  */
name|void
name|svn_auth_get_kwallet_ssl_client_cert_pw_provider
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
comment|/* (!DARWIN&& !WIN32) || DOXYGEN */
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
comment|/**  * Set @a *provider to an authentication provider of type @c  * svn_auth_cred_simple_t that gets/sets information from the user's  * ~/.subversion configuration directory.  *  * This is like svn_client_get_simple_provider(), except that the  * password is obtained from gpg_agent, which will keep it in  * a memory cache.  *  * Allocate @a *provider in @a pool.  *  * @since New in 1.8  * @note This function actually works only on systems with  * GNU Privacy Guard installed.  */
name|void
name|svn_auth_get_gpg_agent_simple_provider
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
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_username_t that gets/sets information from a user's  * ~/.subversion configuration directory.  Allocate @a *provider in  * @a pool.  *  * If a default username is available, @a *provider will honor it,  * and return it when svn_auth_first_credentials() is called.  (See  * @c SVN_AUTH_PARAM_DEFAULT_USERNAME.)  *  * @since New in 1.4.  */
name|void
name|svn_auth_get_username_provider
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
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_server_trust_t, allocated in @a pool.  *  * @a *provider retrieves its credentials from the configuration  * mechanism.  The returned credential is used to override SSL  * security on an error.  *  * @since New in 1.4.  */
name|void
name|svn_auth_get_ssl_server_trust_file_provider
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
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_t, allocated in @a pool.  *  * @a *provider retrieves its credentials from the configuration  * mechanism.  The returned credential is used to load the appropriate  * client certificate for authentication when requested by a server.  *  * @since New in 1.4.  */
name|void
name|svn_auth_get_ssl_client_cert_file_provider
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
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_pw_t that gets/sets information from the user's  * ~/.subversion configuration directory.  *  * If the provider is going to save the passphrase unencrypted,  * it calls @a plaintext_passphrase_prompt_func, passing @a  * prompt_baton, before saving the passphrase.  *  * If @a plaintext_passphrase_prompt_func is NULL it is not called  * and the passphrase is not stored in plaintext.  * Client developers are highly encouraged to provide this callback  * to ensure their users are made aware of the fact that their passphrase  * is going to be stored unencrypted.  *  * Clients can however set the callback to NULL and set  * SVN_AUTH_PARAM_STORE_SSL_CLIENT_CERT_PP_PLAINTEXT to SVN_CONFIG_FALSE or  * SVN_CONFIG_TRUE to enforce a certain behaviour.  *  * Allocate @a *provider in @a pool.  *  * @since New in 1.6.  */
name|void
name|svn_auth_get_ssl_client_cert_pw_file_provider2
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|svn_auth_plaintext_passphrase_prompt_func_t
name|plaintext_passphrase_prompt_func
parameter_list|,
name|void
modifier|*
name|prompt_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Like svn_auth_get_ssl_client_cert_pw_file_provider2, but without  * the ability to call the svn_auth_plaintext_passphrase_prompt_func_t  * callback, and the provider always assumes that it is not allowed  * to store the passphrase in plaintext.  *  * @deprecated Provided for backwards compatibility with the 1.5 API.  * @since New in 1.4.  */
name|SVN_DEPRECATED
name|void
name|svn_auth_get_ssl_client_cert_pw_file_provider
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
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_server_trust_t, allocated in @a pool.  *  * @a *provider retrieves its credentials by using the @a prompt_func  * and @a prompt_baton.  The returned credential is used to override  * SSL security on an error.  *  * @since New in 1.4.  */
name|void
name|svn_auth_get_ssl_server_trust_prompt_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|svn_auth_ssl_server_trust_prompt_func_t
name|prompt_func
parameter_list|,
name|void
modifier|*
name|prompt_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_t, allocated in @a pool.  *  * @a *provider retrieves its credentials by using the @a prompt_func  * and @a prompt_baton.  The returned credential is used to load the  * appropriate client certificate for authentication when requested by  * a server.  The prompt will be retried @a retry_limit times. For  * infinite retries, set @a retry_limit to value less than 0.  *  * @since New in 1.4.  */
name|void
name|svn_auth_get_ssl_client_cert_prompt_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|svn_auth_ssl_client_cert_prompt_func_t
name|prompt_func
parameter_list|,
name|void
modifier|*
name|prompt_baton
parameter_list|,
name|int
name|retry_limit
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *provider to an authentication provider of type @c  * svn_auth_cred_ssl_client_cert_pw_t, allocated in @a pool.  *  * @a *provider retrieves its credentials by using the @a prompt_func  * and @a prompt_baton.  The returned credential is used when a loaded  * client certificate is protected by a passphrase.  The prompt will  * be retried @a retry_limit times. For infinite retries, set  * @a retry_limit to value less than 0.  *  * @since New in 1.4.  */
name|void
name|svn_auth_get_ssl_client_cert_pw_prompt_provider
parameter_list|(
name|svn_auth_provider_object_t
modifier|*
modifier|*
name|provider
parameter_list|,
name|svn_auth_ssl_client_cert_pw_prompt_func_t
name|prompt_func
parameter_list|,
name|void
modifier|*
name|prompt_baton
parameter_list|,
name|int
name|retry_limit
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
comment|/* SVN_AUTH_H */
end_comment

end_unit

