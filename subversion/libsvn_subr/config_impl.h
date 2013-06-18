begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config_impl.h :  private header for the config file implementation.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_CONFIG_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_CONFIG_IMPL_H
end_define

begin_define
define|#
directive|define
name|APR_WANT_STDIO
end_define

begin_include
include|#
directive|include
file|<apr_want.h>
end_include

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_string.h"
end_include

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_include
include|#
directive|include
file|"svn_config.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
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
comment|/* The configuration data. This is a superhash of sections and options. */
struct|struct
name|svn_config_t
block|{
comment|/* Table of cfg_section_t's. */
name|apr_hash_t
modifier|*
name|sections
decl_stmt|;
comment|/* Pool for hash tables, table entries and unexpanded values */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/* Pool for expanded values -- this is separate, so that we can      clear it when modifying the config data. */
name|apr_pool_t
modifier|*
name|x_pool
decl_stmt|;
comment|/* Indicates that some values in the configuration have been expanded. */
name|svn_boolean_t
name|x_values
decl_stmt|;
comment|/* Temporary string used for lookups.  (Using a stringbuf so that      frequent resetting is efficient.) */
name|svn_stringbuf_t
modifier|*
name|tmp_key
decl_stmt|;
comment|/* Temporary value used for expanded default values in svn_config_get.      (Using a stringbuf so that frequent resetting is efficient.) */
name|svn_stringbuf_t
modifier|*
name|tmp_value
decl_stmt|;
comment|/* Specifies whether section names are populated case sensitively. */
name|svn_boolean_t
name|section_names_case_sensitive
decl_stmt|;
comment|/* Specifies whether option names are populated case sensitively. */
name|svn_boolean_t
name|option_names_case_sensitive
decl_stmt|;
block|}
struct|;
comment|/* Read sections and options from a file. */
name|svn_error_t
modifier|*
name|svn_config__parse_file
parameter_list|(
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|svn_boolean_t
name|must_exist
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Read sections and options from a stream. */
name|svn_error_t
modifier|*
name|svn_config__parse_stream
parameter_list|(
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* The name of the magic [DEFAULT] section. */
define|#
directive|define
name|SVN_CONFIG__DEFAULT_SECTION
value|"DEFAULT"
ifdef|#
directive|ifdef
name|WIN32
comment|/* Get the common or user-specific AppData folder */
name|svn_error_t
modifier|*
name|svn_config__win_config_path
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|folder
parameter_list|,
name|int
name|system_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Read sections and options from the Windows Registry. */
name|svn_error_t
modifier|*
name|svn_config__parse_registry
parameter_list|(
name|svn_config_t
modifier|*
name|cfg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|svn_boolean_t
name|must_exist
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* ### It's unclear to me whether this registry stuff should get the    double underscore or not, and if so, where the extra underscore    would go.  Thoughts?  -kff */
define|#
directive|define
name|SVN_REGISTRY_PREFIX
value|"REGISTRY:"
define|#
directive|define
name|SVN_REGISTRY_PREFIX_LEN
value|((sizeof(SVN_REGISTRY_PREFIX)) - 1)
define|#
directive|define
name|SVN_REGISTRY_HKLM
value|"HKLM\\"
define|#
directive|define
name|SVN_REGISTRY_HKLM_LEN
value|((sizeof(SVN_REGISTRY_HKLM)) - 1)
define|#
directive|define
name|SVN_REGISTRY_HKCU
value|"HKCU\\"
define|#
directive|define
name|SVN_REGISTRY_HKCU_LEN
value|((sizeof(SVN_REGISTRY_HKCU)) - 1)
define|#
directive|define
name|SVN_REGISTRY_PATH
value|"Software\\Tigris.org\\Subversion\\"
define|#
directive|define
name|SVN_REGISTRY_PATH_LEN
value|((sizeof(SVN_REGISTRY_PATH)) - 1)
define|#
directive|define
name|SVN_REGISTRY_SYS_CONFIG_PATH
define|\
value|SVN_REGISTRY_PREFIX     \                                SVN_REGISTRY_HKLM       \                                SVN_REGISTRY_PATH
define|#
directive|define
name|SVN_REGISTRY_USR_CONFIG_PATH
define|\
value|SVN_REGISTRY_PREFIX     \                                SVN_REGISTRY_HKCU       \                                SVN_REGISTRY_PATH
endif|#
directive|endif
comment|/* WIN32 */
comment|/* System-wide and configuration subdirectory names.    NOTE: Don't use these directly; call svn_config__sys_config_path()    or svn_config_get_user_config_path() instead. */
ifdef|#
directive|ifdef
name|WIN32
define|#
directive|define
name|SVN_CONFIG__SUBDIRECTORY
value|"Subversion"
elif|#
directive|elif
name|defined
name|__HAIKU__
comment|/* HAIKU */
define|#
directive|define
name|SVN_CONFIG__SYS_DIRECTORY
value|"subversion"
define|#
directive|define
name|SVN_CONFIG__USR_DIRECTORY
value|"subversion"
else|#
directive|else
comment|/* ! WIN32&& ! __HAIKU__ */
define|#
directive|define
name|SVN_CONFIG__SYS_DIRECTORY
value|"/etc/subversion"
define|#
directive|define
name|SVN_CONFIG__USR_DIRECTORY
value|".subversion"
endif|#
directive|endif
comment|/* WIN32 */
comment|/* The description/instructions file in the config directory. */
define|#
directive|define
name|SVN_CONFIG__USR_README_FILE
value|"README.txt"
comment|/* The name of the main authentication subdir in the config directory */
define|#
directive|define
name|SVN_CONFIG__AUTH_SUBDIR
value|"auth"
comment|/* Set *PATH_P to the path to config file FNAME in the system    configuration area, allocated in POOL.  If FNAME is NULL, set    *PATH_P to the directory name of the system config area, either    allocated in POOL or a static constant string.     If the system configuration area cannot be located (possible under    Win32), set *PATH_P to NULL regardless of FNAME.  */
name|svn_error_t
modifier|*
name|svn_config__sys_config_path
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|path_p
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
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
comment|/* SVN_LIBSVN_SUBR_CONFIG_IMPL_H */
end_comment

end_unit

