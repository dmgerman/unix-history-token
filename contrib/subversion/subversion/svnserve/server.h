begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * svn_server.h :  declarations for the svn server  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SERVER_H
end_ifndef

begin_define
define|#
directive|define
name|SERVER_H
end_define

begin_include
include|#
directive|include
file|<apr_network_io.h>
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
include|#
directive|include
file|"svn_config.h"
include|#
directive|include
file|"svn_repos.h"
include|#
directive|include
file|"svn_ra_svn.h"
enum|enum
name|username_case_type
block|{
name|CASE_FORCE_UPPER
block|,
name|CASE_FORCE_LOWER
block|,
name|CASE_ASIS
block|}
enum|;
typedef|typedef
struct|struct
name|server_baton_t
block|{
name|svn_repos_t
modifier|*
name|repos
decl_stmt|;
specifier|const
name|char
modifier|*
name|repos_name
decl_stmt|;
comment|/* URI-encoded name of repository (not for authz) */
name|svn_fs_t
modifier|*
name|fs
decl_stmt|;
comment|/* For convenience; same as svn_repos_fs(repos) */
specifier|const
name|char
modifier|*
name|base
decl_stmt|;
comment|/* Base directory for config files */
name|svn_config_t
modifier|*
name|cfg
decl_stmt|;
comment|/* Parsed repository svnserve.conf */
name|svn_config_t
modifier|*
name|pwdb
decl_stmt|;
comment|/* Parsed password database */
name|svn_authz_t
modifier|*
name|authzdb
decl_stmt|;
comment|/* Parsed authz rules */
specifier|const
name|char
modifier|*
name|authz_repos_name
decl_stmt|;
comment|/* The name of the repository for authz */
specifier|const
name|char
modifier|*
name|realm
decl_stmt|;
comment|/* Authentication realm */
specifier|const
name|char
modifier|*
name|repos_url
decl_stmt|;
comment|/* URL to base of repository */
name|svn_stringbuf_t
modifier|*
name|fs_path
decl_stmt|;
comment|/* Decoded base in-repos path (w/ leading slash) */
name|apr_hash_t
modifier|*
name|fs_config
decl_stmt|;
comment|/* Additional FS configuration parameters */
specifier|const
name|char
modifier|*
name|user
decl_stmt|;
comment|/* Authenticated username of the user */
name|enum
name|username_case_type
name|username_case
decl_stmt|;
comment|/* Case-normalize the username? */
specifier|const
name|char
modifier|*
name|authz_user
decl_stmt|;
comment|/* Username for authz ('user' + 'username_case') */
name|svn_boolean_t
name|tunnel
decl_stmt|;
comment|/* Tunneled through login agent */
specifier|const
name|char
modifier|*
name|tunnel_user
decl_stmt|;
comment|/* Allow EXTERNAL to authenticate as this */
name|svn_boolean_t
name|read_only
decl_stmt|;
comment|/* Disallow write access (global flag) */
name|svn_boolean_t
name|use_sasl
decl_stmt|;
comment|/* Use Cyrus SASL for authentication;                               always false if SVN_HAVE_SASL not defined */
name|apr_file_t
modifier|*
name|log_file
decl_stmt|;
comment|/* Log filehandle. */
name|svn_boolean_t
name|vhost
decl_stmt|;
comment|/* Use virtual-host-based path to repo. */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
block|}
name|server_baton_t
typedef|;
enum|enum
name|authn_type
block|{
name|UNAUTHENTICATED
block|,
name|AUTHENTICATED
block|}
enum|;
enum|enum
name|access_type
block|{
name|NO_ACCESS
block|,
name|READ_ACCESS
block|,
name|WRITE_ACCESS
block|}
enum|;
name|enum
name|access_type
name|get_access
parameter_list|(
name|server_baton_t
modifier|*
name|b
parameter_list|,
name|enum
name|authn_type
name|auth
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
name|serve_params_t
block|{
comment|/* The virtual root of the repositories to serve.  The client URL      path is interpreted relative to this root and is not allowed to      escape it. */
specifier|const
name|char
modifier|*
name|root
decl_stmt|;
comment|/* True if the connection is tunneled over an ssh-like transport,      such that the client may use EXTERNAL to authenticate as the      current uid's username. */
name|svn_boolean_t
name|tunnel
decl_stmt|;
comment|/* If tunnel is true, overrides the current uid's username as the      identity EXTERNAL authenticates as. */
specifier|const
name|char
modifier|*
name|tunnel_user
decl_stmt|;
comment|/* True if the read-only flag was specified on the command-line,      which forces all connections to be read-only. */
name|svn_boolean_t
name|read_only
decl_stmt|;
comment|/* The base directory for any relative configuration files. */
specifier|const
name|char
modifier|*
name|base
decl_stmt|;
comment|/* A parsed repository svnserve configuration file, ala      svnserve.conf.  If this is NULL, then no configuration file was      specified on the command line.  If this is non-NULL, then      per-repository svnserve.conf are not read. */
name|svn_config_t
modifier|*
name|cfg
decl_stmt|;
comment|/* A filehandle open for writing logs to; possibly NULL. */
name|apr_file_t
modifier|*
name|log_file
decl_stmt|;
comment|/* Username case normalization style. */
name|enum
name|username_case_type
name|username_case
decl_stmt|;
comment|/* Enable text delta caching for all FSFS repositories. */
name|svn_boolean_t
name|cache_txdeltas
decl_stmt|;
comment|/* Enable full-text caching for all FSFS repositories. */
name|svn_boolean_t
name|cache_fulltexts
decl_stmt|;
comment|/* Enable revprop caching for all FSFS repositories. */
name|svn_boolean_t
name|cache_revprops
decl_stmt|;
comment|/* Size of the in-memory cache (used by FSFS only). */
name|apr_uint64_t
name|memory_cache_size
decl_stmt|;
comment|/* Data compression level to reduce for network traffic. If this      is 0, no compression should be applied and the protocol may      fall back to svndiff "version 0" bypassing zlib entirely.      Defaults to SVN_DELTA_COMPRESSION_LEVEL_DEFAULT. */
name|int
name|compression_level
decl_stmt|;
comment|/* Item size up to which we use the zero-copy code path to transmit      them over the network.  0 disables that code path. */
name|apr_size_t
name|zero_copy_limit
decl_stmt|;
comment|/* Amount of data to send between checks for cancellation requests      coming in from the client. */
name|apr_size_t
name|error_check_interval
decl_stmt|;
comment|/* Use virtual-host-based path to repo. */
name|svn_boolean_t
name|vhost
decl_stmt|;
block|}
name|serve_params_t
typedef|;
comment|/* Serve the connection CONN according to the parameters PARAMS. */
name|svn_error_t
modifier|*
name|serve
parameter_list|(
name|svn_ra_svn_conn_t
modifier|*
name|conn
parameter_list|,
name|serve_params_t
modifier|*
name|params
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Load the password database for the listening server based on the    entries in the SERVER struct.     SERVER and CONN must not be NULL. The real errors will be logged with    SERVER and CONN but return generic errors to the client. */
name|svn_error_t
modifier|*
name|load_pwdb_config
parameter_list|(
name|server_baton_t
modifier|*
name|server
parameter_list|,
name|svn_ra_svn_conn_t
modifier|*
name|conn
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Load the authz database for the listening server based on the    entries in the SERVER struct.     SERVER and CONN must not be NULL. The real errors will be logged with    SERVER and CONN but return generic errors to the client. */
name|svn_error_t
modifier|*
name|load_authz_config
parameter_list|(
name|server_baton_t
modifier|*
name|server
parameter_list|,
name|svn_ra_svn_conn_t
modifier|*
name|conn
parameter_list|,
specifier|const
name|char
modifier|*
name|repos_root
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Initialize the Cyrus SASL library. POOL is used for allocations. */
name|svn_error_t
modifier|*
name|cyrus_init
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Authenticate using Cyrus SASL. */
name|svn_error_t
modifier|*
name|cyrus_auth_request
parameter_list|(
name|svn_ra_svn_conn_t
modifier|*
name|conn
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
name|server_baton_t
modifier|*
name|b
parameter_list|,
name|enum
name|access_type
name|required
parameter_list|,
name|svn_boolean_t
name|needs_username
parameter_list|)
function_decl|;
comment|/* Escape SOURCE into DEST where SOURCE is null-terminated and DEST is    size BUFLEN DEST will be null-terminated.  Returns number of bytes    written, including terminating null byte. */
name|apr_size_t
name|escape_errorlog_item
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|apr_size_t
name|buflen
parameter_list|)
function_decl|;
comment|/* Log ERR to LOG_FILE if LOG_FILE is not NULL.  Include REMOTE_HOST,    USER, and REPOS in the log if they are not NULL.  Allocate temporary    char buffers in POOL (which caller can then clear or dispose of). */
name|void
name|log_error
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|,
name|apr_file_t
modifier|*
name|log_file
parameter_list|,
specifier|const
name|char
modifier|*
name|remote_host
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
specifier|const
name|char
modifier|*
name|repos
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
comment|/* SERVER_H */
end_comment

end_unit

