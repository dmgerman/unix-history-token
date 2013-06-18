begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_cmdline.h  * @brief Support functions for command line programs  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CMDLINE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CMDLINE_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_getopt.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DOXYGEN_SHOULD_SKIP_THIS
end_ifndef

begin_define
define|#
directive|define
name|APR_WANT_STDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<apr_want.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_auth.h"
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
comment|/** Set up the locale for character conversion, and initialize APR.  * If @a error_stream is non-NULL, print error messages to the stream,  * using @a progname as the program name.  Attempt to set @c stdout to  * line-buffered mode, and @a error_stream to unbuffered mode.  Return  * @c EXIT_SUCCESS if successful, otherwise @c EXIT_FAILURE.  *  * @note This function should be called exactly once at program startup,  *       before calling any other APR or Subversion functions.  */
name|int
name|svn_cmdline_init
parameter_list|(
specifier|const
name|char
modifier|*
name|progname
parameter_list|,
name|FILE
modifier|*
name|error_stream
parameter_list|)
function_decl|;
comment|/** Set @a *dest to an output-encoded C string from UTF-8 C string @a  * src; allocate @a *dest in @a pool.  */
name|svn_error_t
modifier|*
name|svn_cmdline_cstring_from_utf8
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Like svn_utf_cstring_from_utf8_fuzzy(), but converts to an  * output-encoded C string. */
specifier|const
name|char
modifier|*
name|svn_cmdline_cstring_from_utf8_fuzzy
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *dest to a UTF-8-encoded C string from input-encoded C  * string @a src; allocate @a *dest in @a pool.  */
name|svn_error_t
modifier|*
name|svn_cmdline_cstring_to_utf8
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Set @a *dest to an output-encoded natively-formatted path string  * from canonical path @a src; allocate @a *dest in @a pool.  */
name|svn_error_t
modifier|*
name|svn_cmdline_path_local_style_from_utf8
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Write to stdout, using a printf-like format string @a fmt, passed  * through apr_pvsprintf().  All string arguments are in UTF-8; the output  * is converted to the output encoding.  Use @a pool for temporary  * allocation.  *  * @since New in 1.1.  */
name|svn_error_t
modifier|*
name|svn_cmdline_printf
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
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
function_decl|2
operator|,
function_decl|3
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Write to the stdio @a stream, using a printf-like format string @a fmt,  * passed through apr_pvsprintf().  All string arguments are in UTF-8;  * the output is converted to the output encoding.  Use @a pool for  * temporary allocation.  *  * @since New in 1.1.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_fprintf
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Output the @a string to the stdio @a stream, converting from UTF-8  * to the output encoding.  Use @a pool for temporary allocation.  *  * @since New in 1.1.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_fputs
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Flush output buffers of the stdio @a stream, returning an error if that  * fails.  This is just a wrapper for the standard fflush() function for  * consistent error handling.  *  * @since New in 1.1.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_fflush
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return the name of the output encoding allocated in @a pool, or @c  * APR_LOCALE_CHARSET if the output encoding is the same as the locale  * encoding.  *  * @since New in 1.3.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_cmdline_output_encoding
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Handle @a error in preparation for immediate exit from a  * command-line client.  Specifically:  *  * Call svn_handle_error2(@a error, stderr, FALSE, @a prefix), clear  * @a error, destroy @a pool iff it is non-NULL, and return EXIT_FAILURE.  *  * @since New in 1.3.  */
end_comment

begin_function_decl
name|int
name|svn_cmdline_handle_exit_error
parameter_list|(
name|svn_error_t
modifier|*
name|error
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** A prompt function/baton pair, and the path to the configuration  * directory. To be passed as the baton argument to the  * @c svn_cmdline_*_prompt functions.  *  * @since New in 1.6.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_cmdline_prompt_baton2_t
block|{
name|svn_cancel_func_t
name|cancel_func
decl_stmt|;
name|void
modifier|*
name|cancel_baton
decl_stmt|;
specifier|const
name|char
modifier|*
name|config_dir
decl_stmt|;
block|}
name|svn_cmdline_prompt_baton2_t
typedef|;
end_typedef

begin_comment
comment|/** Like svn_cmdline_prompt_baton2_t, but without the path to the  * configuration directory.  *  * @since New in 1.4.  * @deprecated Provided for backward compatibility with the 1.5 API.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_cmdline_prompt_baton_t
block|{
name|svn_cancel_func_t
name|cancel_func
decl_stmt|;
name|void
modifier|*
name|cancel_baton
decl_stmt|;
block|}
name|svn_cmdline_prompt_baton_t
typedef|;
end_typedef

begin_comment
comment|/** Prompt the user for input, using @a prompt_str for the prompt and  * @a baton (which may be @c NULL) for cancellation, and returning the  * user's response in @a result, allocated in @a pool.  *  * @since New in 1.5.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_prompt_user2
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|result
parameter_list|,
specifier|const
name|char
modifier|*
name|prompt_str
parameter_list|,
name|svn_cmdline_prompt_baton_t
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Similar to svn_cmdline_prompt_user2, but without cancellation  * support.  *  * @deprecated Provided for backward compatibility with the 1.4 API.  */
end_comment

begin_function_decl
name|SVN_DEPRECATED
name|svn_error_t
modifier|*
name|svn_cmdline_prompt_user
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|result
parameter_list|,
specifier|const
name|char
modifier|*
name|prompt_str
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** An implementation of @c svn_auth_simple_prompt_func_t that prompts  * the user for keyboard input on the command line.  *  * @since New in 1.4.  *  * Expects a @c svn_cmdline_prompt_baton_t to be passed as @a baton.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_auth_simple_prompt
parameter_list|(
name|svn_auth_cred_simple_t
modifier|*
modifier|*
name|cred_p
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
end_function_decl

begin_comment
comment|/** An implementation of @c svn_auth_username_prompt_func_t that prompts  * the user for their username via the command line.  *  * @since New in 1.4.  *  * Expects a @c svn_cmdline_prompt_baton_t to be passed as @a baton.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_auth_username_prompt
parameter_list|(
name|svn_auth_cred_username_t
modifier|*
modifier|*
name|cred_p
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
end_function_decl

begin_comment
comment|/** An implementation of @c svn_auth_ssl_server_trust_prompt_func_t that  * asks the user if they trust a specific ssl server via the command line.  *  * @since New in 1.4.  *  * Expects a @c svn_cmdline_prompt_baton_t to be passed as @a baton.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_auth_ssl_server_trust_prompt
parameter_list|(
name|svn_auth_cred_ssl_server_trust_t
modifier|*
modifier|*
name|cred_p
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
end_function_decl

begin_comment
comment|/** An implementation of @c svn_auth_ssl_client_cert_prompt_func_t that  * prompts the user for the filename of their SSL client certificate via  * the command line.  *  * Records absolute path of the SSL client certificate file.  *  * @since New in 1.4.  *  * Expects a @c svn_cmdline_prompt_baton_t to be passed as @a baton.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_auth_ssl_client_cert_prompt
parameter_list|(
name|svn_auth_cred_ssl_client_cert_t
modifier|*
modifier|*
name|cred_p
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
end_function_decl

begin_comment
comment|/** An implementation of @c svn_auth_ssl_client_cert_pw_prompt_func_t that  * prompts the user for their SSL certificate password via the command line.  *  * @since New in 1.4.  *  * Expects a @c svn_cmdline_prompt_baton_t to be passed as @a baton.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_auth_ssl_client_cert_pw_prompt
parameter_list|(
name|svn_auth_cred_ssl_client_cert_pw_t
modifier|*
modifier|*
name|cred_p
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
end_function_decl

begin_comment
comment|/** An implementation of @c svn_auth_plaintext_prompt_func_t that  * prompts the user whether storing unencrypted passwords to disk is OK.  *  * Expects a @c svn_cmdline_prompt_baton2_t to be passed as @a baton.  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_auth_plaintext_prompt
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
end_function_decl

begin_comment
comment|/** An implementation of @c svn_auth_plaintext_passphrase_prompt_func_t that  * prompts the user whether storing unencrypted passphrase to disk is OK.  *  * Expects a @c svn_cmdline_prompt_baton2_t to be passed as @a baton.  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_auth_plaintext_passphrase_prompt
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
end_function_decl

begin_comment
comment|/** Set @a *ab to an authentication baton allocated from @a pool and  * initialized with the standard set of authentication providers used  * by the command line client.  *  * @a non_interactive, @a username, @a password, @a config_dir,  * @a no_auth_cache, and @a trust_server_cert are the values of the  * command line options of the corresponding names.  *  * @a cfg is the @c SVN_CONFIG_CATEGORY_CONFIG configuration, and  * @a cancel_func and @a cancel_baton control the cancellation of the  * prompting providers that are initialized.  *  * Use @a pool for all allocations.  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_cmdline_create_auth_baton
parameter_list|(
name|svn_auth_baton_t
modifier|*
modifier|*
name|ab
parameter_list|,
name|svn_boolean_t
name|non_interactive
parameter_list|,
specifier|const
name|char
modifier|*
name|username
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|,
specifier|const
name|char
modifier|*
name|config_dir
parameter_list|,
name|svn_boolean_t
name|no_auth_cache
parameter_list|,
name|svn_boolean_t
name|trust_server_cert
parameter_list|,
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Similar to svn_cmdline_create_auth_baton(), but with  * @a trust_server_cert always set to false.  *  * @since New in 1.4.  * @deprecated Provided for backward compatibility with the 1.5 API.  * Use svn_cmdline_create_auth_baton() instead.  *  * @note This deprecation does not follow the usual pattern of putting  * a new number on end of the function's name.  Instead, the new  * function name is distinguished from the old by a grammatical  * improvement: the verb "create" instead of the noun "setup".  */
end_comment

begin_function_decl
name|SVN_DEPRECATED
name|svn_error_t
modifier|*
name|svn_cmdline_setup_auth_baton
parameter_list|(
name|svn_auth_baton_t
modifier|*
modifier|*
name|ab
parameter_list|,
name|svn_boolean_t
name|non_interactive
parameter_list|,
specifier|const
name|char
modifier|*
name|username
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|,
specifier|const
name|char
modifier|*
name|config_dir
parameter_list|,
name|svn_boolean_t
name|no_auth_cache
parameter_list|,
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* SVN_CMDLINE_H */
end_comment

end_unit

