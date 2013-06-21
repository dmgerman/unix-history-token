begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* repos.c : repository creation; shared and exclusive repository locking  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_file_io.h>
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_dirent_uri.h"
end_include

begin_include
include|#
directive|include
file|"svn_path.h"
end_include

begin_include
include|#
directive|include
file|"svn_utf.h"
end_include

begin_include
include|#
directive|include
file|"svn_time.h"
end_include

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"svn_ra.h"
end_include

begin_comment
comment|/* for SVN_RA_CAPABILITY_* */
end_comment

begin_include
include|#
directive|include
file|"svn_repos.h"
end_include

begin_include
include|#
directive|include
file|"svn_hash.h"
end_include

begin_include
include|#
directive|include
file|"svn_version.h"
end_include

begin_include
include|#
directive|include
file|"svn_config.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_repos_private.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_subr_private.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_comment
comment|/* for SVN_TEMPLATE_ROOT_DIR */
end_comment

begin_include
include|#
directive|include
file|"repos.h"
end_include

begin_comment
comment|/* Used to terminate lines in large multi-line string literals. */
end_comment

begin_define
define|#
directive|define
name|NL
value|APR_EOL_STR
end_define

begin_escape
end_escape

begin_comment
comment|/* Path accessor functions. */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|svn_repos_path
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|repos
operator|->
name|path
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|svn_repos_db_env
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|repos
operator|->
name|db_path
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|svn_repos_conf_dir
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|repos
operator|->
name|conf_path
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|svn_repos_svnserve_conf
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|conf_path
argument_list|,
name|SVN_REPOS__CONF_SVNSERVE_CONF
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
name|svn_repos_lock_dir
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|repos
operator|->
name|lock_path
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|svn_repos_db_lockfile
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|lock_path
argument_list|,
name|SVN_REPOS__DB_LOCKFILE
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
name|svn_repos_db_logs_lockfile
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|lock_path
argument_list|,
name|SVN_REPOS__DB_LOGS_LOCKFILE
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
name|svn_repos_hook_dir
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|repos
operator|->
name|hook_path
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|svn_repos_start_commit_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_START_COMMIT
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
name|svn_repos_pre_commit_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_PRE_COMMIT
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
name|svn_repos_pre_lock_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_PRE_LOCK
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
name|svn_repos_pre_unlock_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_PRE_UNLOCK
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
name|svn_repos_post_lock_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_POST_LOCK
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
name|svn_repos_post_unlock_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_POST_UNLOCK
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
name|svn_repos_post_commit_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_POST_COMMIT
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
name|svn_repos_pre_revprop_change_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_PRE_REVPROP_CHANGE
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
name|svn_repos_post_revprop_change_hook
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|SVN_REPOS__HOOK_POST_REVPROP_CHANGE
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|svn_error_t
modifier|*
name|create_repos_dir
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_error_t
modifier|*
name|err
decl_stmt|;
name|err
operator|=
name|svn_io_dir_make
argument_list|(
name|path
argument_list|,
name|APR_OS_DEFAULT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|&&
operator|(
name|APR_STATUS_IS_EEXIST
argument_list|(
name|err
operator|->
name|apr_err
argument_list|)
operator|)
condition|)
block|{
name|svn_boolean_t
name|is_empty
decl_stmt|;
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_dir_empty
argument_list|(
operator|&
name|is_empty
argument_list|,
name|path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|is_empty
condition|)
name|err
operator|=
name|NULL
expr_stmt|;
else|else
name|err
operator|=
name|svn_error_createf
argument_list|(
name|SVN_ERR_DIR_NOT_EMPTY
argument_list|,
literal|0
argument_list|,
name|_
argument_list|(
literal|"'%s' exists and is non-empty"
argument_list|)
argument_list|,
name|svn_dirent_local_style
argument_list|(
name|path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|svn_error_trace
argument_list|(
name|err
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|bdb_lock_file_contents
init|=
literal|"DB lock file, representing locks on the versioned filesystem."
name|NL
literal|""
name|NL
literal|"All accessors -- both readers and writers -- of the repository's"
name|NL
literal|"Berkeley DB environment take out shared locks on this file, and"
name|NL
literal|"each accessor removes its lock when done.  If and when the DB"
name|NL
literal|"recovery procedure is run, the recovery code takes out an"
name|NL
literal|"exclusive lock on this file, so we can be sure no one else is"
name|NL
literal|"using the DB during the recovery."
name|NL
literal|""
name|NL
literal|"You should never have to edit or remove this file."
name|NL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|bdb_logs_lock_file_contents
init|=
literal|"DB logs lock file, representing locks on the versioned filesystem logs."
name|NL
literal|""
name|NL
literal|"All log manipulators of the repository's Berkeley DB environment"
name|NL
literal|"take out exclusive locks on this file to ensure that only one"
name|NL
literal|"accessor manipulates the logs at a time."
name|NL
literal|""
name|NL
literal|"You should never have to edit or remove this file."
name|NL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pre12_compat_unneeded_file_contents
init|=
literal|"This file is not used by Subversion 1.3.x or later."
name|NL
literal|"However, its existence is required for compatibility with"
name|NL
literal|"Subversion 1.2.x or earlier."
name|NL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create the DB logs lockfile. */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|create_db_logs_lock
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|contents
decl_stmt|;
specifier|const
name|char
modifier|*
name|lockfile_path
decl_stmt|;
name|lockfile_path
operator|=
name|svn_repos_db_logs_lockfile
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|repos
operator|->
name|fs_type
argument_list|,
name|SVN_FS_TYPE_BDB
argument_list|)
operator|==
literal|0
condition|)
name|contents
operator|=
name|bdb_logs_lock_file_contents
expr_stmt|;
else|else
name|contents
operator|=
name|pre12_compat_unneeded_file_contents
expr_stmt|;
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|lockfile_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating db logs lock file"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Create the DB lockfile. */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|create_db_lock
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|contents
decl_stmt|;
specifier|const
name|char
modifier|*
name|lockfile_path
decl_stmt|;
name|lockfile_path
operator|=
name|svn_repos_db_lockfile
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|repos
operator|->
name|fs_type
argument_list|,
name|SVN_FS_TYPE_BDB
argument_list|)
operator|==
literal|0
condition|)
name|contents
operator|=
name|bdb_lock_file_contents
expr_stmt|;
else|else
name|contents
operator|=
name|pre12_compat_unneeded_file_contents
expr_stmt|;
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|lockfile_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating db lock file"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
specifier|static
name|svn_error_t
modifier|*
name|create_locks
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
comment|/* Create the locks directory. */
name|SVN_ERR_W
argument_list|(
name|create_repos_dir
argument_list|(
name|repos
operator|->
name|lock_path
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating lock dir"
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|create_db_lock
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|create_db_logs_lock
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|HOOKS_ENVIRONMENT_TEXT
define|\
value|"# The hook program typically does not inherit the environment of"       NL \   "# its parent process.  For example, a common problem is for the"        NL \   "# PATH environment variable to not be set to its usual value, so"       NL \   "# that subprograms fail to launch unless invoked via absolute path."    NL \   "# If you're having unexpected problems with a hook program, the"        NL \   "# culprit may be unusual (or missing) environment variables."           NL
end_define

begin_define
define|#
directive|define
name|PREWRITTEN_HOOKS_TEXT
define|\
value|"# For more examples and pre-written hooks, see those in"                NL \   "# the Subversion repository at"                                         NL \   "# http://svn.apache.org/repos/asf/subversion/trunk/tools/hook-scripts/ and"        NL \   "# http://svn.apache.org/repos/asf/subversion/trunk/contrib/hook-scripts/"          NL
end_define

begin_function
specifier|static
name|svn_error_t
modifier|*
name|create_hooks
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|this_path
decl_stmt|,
modifier|*
name|contents
decl_stmt|;
comment|/* Create the hook directory. */
name|SVN_ERR_W
argument_list|(
name|create_repos_dir
argument_list|(
name|repos
operator|->
name|hook_path
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating hook directory"
argument_list|)
argument_list|)
expr_stmt|;
comment|/*** Write a default template for each standard hook file. */
comment|/* Start-commit hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_start_commit_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_START_COMMIT
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# START-COMMIT HOOK"
name|NL
literal|"#"
name|NL
literal|"# The start-commit hook is invoked immediately after a Subversion txn is"
name|NL
literal|"# created and populated with initial revprops in the process of doing a"
name|NL
literal|"# commit. Subversion runs this hook by invoking a program (script, "
name|NL
literal|"# executable, binary, etc.) named '"
name|SCRIPT_NAME
literal|"' (for which this file"
name|NL
literal|"# is a template) with the following ordered arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] USER         (the authenticated user attempting to commit)"
name|NL
literal|"#   [3] CAPABILITIES (a colon-separated list of capabilities reported"
name|NL
literal|"#                     by the client; see note below)"
name|NL
literal|"#   [4] TXN-NAME     (the name of the commit txn just created)"
name|NL
literal|"#"
name|NL
literal|"# Note: The CAPABILITIES parameter is new in Subversion 1.5, and 1.5"
name|NL
literal|"# clients will typically report at least the \""
expr|\
name|SVN_RA_CAPABILITY_MERGEINFO
literal|"\" capability."
name|NL
literal|"# If there are other capabilities, then the list is colon-separated,"
name|NL
literal|"# e.g.: \""
name|SVN_RA_CAPABILITY_MERGEINFO
literal|":some-other-capability\" "
expr|\
literal|"(the order is undefined)."
name|NL
literal|"#"
name|NL
literal|"# Note: The TXN-NAME parameter is new in Subversion 1.8.  Prior to version"
name|NL
literal|"# 1.8, the start-commit hook was invoked before the commit txn was even"
name|NL
literal|"# created, so the ability to inspect the commit txn and its metadata from"
name|NL
literal|"# within the start-commit hook was not possible."
name|NL
literal|"# "
name|NL
literal|"# The list is self-reported by the client.  Therefore, you should not"
name|NL
literal|"# make security assumptions based on the capabilities list, nor should"
name|NL
literal|"# you assume that clients reliably report every capability they have."
name|NL
literal|"#"
name|NL
literal|"# The working directory for this hook program's invocation is undefined,"
name|NL
literal|"# so the program should set one explicitly if it cares."
name|NL
literal|"#"
name|NL
literal|"# If the hook program exits with success, the commit continues; but"
name|NL
literal|"# if it exits with failure (non-zero), the commit is stopped before"
name|NL
literal|"# a Subversion txn is created, and STDERR is returned to the client."
name|NL
literal|"#"
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"# "
name|NL
name|HOOKS_ENVIRONMENT_TEXT
literal|"# "
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter."
name|NL
name|PREWRITTEN_HOOKS_TEXT
literal|""
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"USER=\"$2\""
name|NL
literal|""
name|NL
literal|"commit-allower.pl --repository \"$REPOS\" --user \"$USER\" || exit 1"
name|NL
literal|"special-auth-check.py --user \"$USER\" --auth-level 3 || exit 1"
name|NL
literal|""
name|NL
literal|"# All checks passed, so allow the commit."
name|NL
literal|"exit 0"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating start-commit hook"
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end start-commit hook */
comment|/* Pre-commit hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_pre_commit_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_PRE_COMMIT
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# PRE-COMMIT HOOK"
name|NL
literal|"#"
name|NL
literal|"# The pre-commit hook is invoked before a Subversion txn is"
name|NL
literal|"# committed.  Subversion runs this hook by invoking a program"
name|NL
literal|"# (script, executable, binary, etc.) named '"
name|SCRIPT_NAME
literal|"' (for which"
name|NL
literal|"# this file is a template), with the following ordered arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] TXN-NAME     (the name of the txn about to be committed)"
name|NL
literal|"#"
name|NL
literal|"#   [STDIN] LOCK-TOKENS ** the lock tokens are passed via STDIN."
name|NL
literal|"#"
name|NL
literal|"#   If STDIN contains the line \"LOCK-TOKENS:\\n\" (the \"\\n\" denotes a"
name|NL
literal|"#   single newline), the lines following it are the lock tokens for"
name|NL
literal|"#   this commit.  The end of the list is marked by a line containing"
name|NL
literal|"#   only a newline character."
name|NL
literal|"#"
name|NL
literal|"#   Each lock token line consists of a URI-escaped path, followed"
name|NL
literal|"#   by the separator character '|', followed by the lock token string,"
name|NL
literal|"#   followed by a newline."
name|NL
literal|"#"
name|NL
literal|"# The default working directory for the invocation is undefined, so"
name|NL
literal|"# the program should set one explicitly if it cares."
name|NL
literal|"#"
name|NL
literal|"# If the hook program exits with success, the txn is committed; but"
name|NL
literal|"# if it exits with failure (non-zero), the txn is aborted, no commit"
name|NL
literal|"# takes place, and STDERR is returned to the client.   The hook"
name|NL
literal|"# program can use the 'svnlook' utility to help it examine the txn."
name|NL
literal|"#"
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"#   ***  NOTE: THE HOOK PROGRAM MUST NOT MODIFY THE TXN, EXCEPT  ***"
name|NL
literal|"#   ***  FOR REVISION PROPERTIES (like svn:log or svn:author).   ***"
name|NL
literal|"#"
name|NL
literal|"#   This is why we recommend using the read-only 'svnlook' utility."
name|NL
literal|"#   In the future, Subversion may enforce the rule that pre-commit"
name|NL
literal|"#   hooks should not modify the versioned data in txns, or else come"
name|NL
literal|"#   up with a mechanism to make it safe to do so (by informing the"
name|NL
literal|"#   committing client of the changes).  However, right now neither"
name|NL
literal|"#   mechanism is implemented, so hook writers just have to be careful."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"#"
name|NL
name|HOOKS_ENVIRONMENT_TEXT
literal|"# "
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter."
name|NL
name|PREWRITTEN_HOOKS_TEXT
literal|""
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"TXN=\"$2\""
name|NL
literal|""
name|NL
literal|"# Make sure that the log message contains some text."
name|NL
literal|"SVNLOOK="
name|SVN_BINDIR
literal|"/svnlook"
name|NL
literal|"$SVNLOOK log -t \"$TXN\" \"$REPOS\" | \\"
name|NL
literal|"   grep \"[a-zA-Z0-9]\"> /dev/null || exit 1"
name|NL
literal|""
name|NL
literal|"# Check that the author of this commit has the rights to perform"
name|NL
literal|"# the commit on the files and directories being modified."
name|NL
literal|"commit-access-control.pl \"$REPOS\" \"$TXN\" commit-access-control.cfg || exit 1"
name|NL
literal|""
name|NL
literal|"# All checks passed, so allow the commit."
name|NL
literal|"exit 0"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating pre-commit hook"
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end pre-commit hook */
comment|/* Pre-revprop-change hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_pre_revprop_change_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_PRE_REVPROP_CHANGE
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# PRE-REVPROP-CHANGE HOOK"
name|NL
literal|"#"
name|NL
literal|"# The pre-revprop-change hook is invoked before a revision property"
name|NL
literal|"# is added, modified or deleted.  Subversion runs this hook by invoking"
name|NL
literal|"# a program (script, executable, binary, etc.) named '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# (for which this file is a template), with the following ordered"
name|NL
literal|"# arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] REV          (the revision being tweaked)"
name|NL
literal|"#   [3] USER         (the username of the person tweaking the property)"
name|NL
literal|"#   [4] PROPNAME     (the property being set on the revision)"
name|NL
literal|"#   [5] ACTION       (the property is being 'A'dded, 'M'odified, or 'D'eleted)"
name|NL
literal|"#"
name|NL
literal|"#   [STDIN] PROPVAL  ** the new property value is passed via STDIN."
name|NL
literal|"#"
name|NL
literal|"# If the hook program exits with success, the propchange happens; but"
name|NL
literal|"# if it exits with failure (non-zero), the propchange doesn't happen."
name|NL
literal|"# The hook program can use the 'svnlook' utility to examine the "
name|NL
literal|"# existing value of the revision property."
name|NL
literal|"#"
name|NL
literal|"# WARNING: unlike other hooks, this hook MUST exist for revision"
name|NL
literal|"# properties to be changed.  If the hook does not exist, Subversion "
name|NL
literal|"# will behave as if the hook were present, but failed.  The reason"
name|NL
literal|"# for this is that revision properties are UNVERSIONED, meaning that"
name|NL
literal|"# a successful propchange is destructive;  the old value is gone"
name|NL
literal|"# forever.  We recommend the hook back up the old value somewhere."
name|NL
literal|"#"
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"#"
name|NL
name|HOOKS_ENVIRONMENT_TEXT
literal|"# "
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter."
name|NL
name|PREWRITTEN_HOOKS_TEXT
literal|""
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"REV=\"$2\""
name|NL
literal|"USER=\"$3\""
name|NL
literal|"PROPNAME=\"$4\""
name|NL
literal|"ACTION=\"$5\""
name|NL
literal|""
name|NL
literal|"if [ \"$ACTION\" = \"M\" -a \"$PROPNAME\" = \"svn:log\" ]; then exit 0; fi"
name|NL
literal|""
name|NL
literal|"echo \"Changing revision properties other than svn:log is prohibited\">&2"
name|NL
literal|"exit 1"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating pre-revprop-change hook"
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end pre-revprop-change hook */
comment|/* Pre-lock hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_pre_lock_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_PRE_LOCK
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# PRE-LOCK HOOK"
name|NL
literal|"#"
name|NL
literal|"# The pre-lock hook is invoked before an exclusive lock is"
name|NL
literal|"# created.  Subversion runs this hook by invoking a program "
name|NL
literal|"# (script, executable, binary, etc.) named '"
name|SCRIPT_NAME
literal|"' (for which"
name|NL
literal|"# this file is a template), with the following ordered arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] PATH         (the path in the repository about to be locked)"
name|NL
literal|"#   [3] USER         (the user creating the lock)"
name|NL
literal|"#   [4] COMMENT      (the comment of the lock)"
name|NL
literal|"#   [5] STEAL-LOCK   (1 if the user is trying to steal the lock, else 0)"
name|NL
literal|"#"
name|NL
literal|"# If the hook program outputs anything on stdout, the output string will"
name|NL
literal|"# be used as the lock token for this lock operation.  If you choose to use"
name|NL
literal|"# this feature, you must guarantee the tokens generated are unique across"
name|NL
literal|"# the repository each time."
name|NL
literal|"#"
name|NL
literal|"# The default working directory for the invocation is undefined, so"
name|NL
literal|"# the program should set one explicitly if it cares."
name|NL
literal|"#"
name|NL
literal|"# If the hook program exits with success, the lock is created; but"
name|NL
literal|"# if it exits with failure (non-zero), the lock action is aborted"
name|NL
literal|"# and STDERR is returned to the client."
name|NL
literal|""
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"#"
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter:"
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"PATH=\"$2\""
name|NL
literal|"USER=\"$3\""
name|NL
literal|"COMMENT=\"$4\""
name|NL
literal|"STEAL=\"$5\""
name|NL
literal|""
name|NL
literal|"# If a lock exists and is owned by a different person, don't allow it"
name|NL
literal|"# to be stolen (e.g., with 'svn lock --force ...')."
name|NL
literal|""
name|NL
literal|"# (Maybe this script could send email to the lock owner?)"
name|NL
literal|"SVNLOOK="
name|SVN_BINDIR
literal|"/svnlook"
name|NL
literal|"GREP=/bin/grep"
name|NL
literal|"SED=/bin/sed"
name|NL
literal|""
name|NL
literal|"LOCK_OWNER=`$SVNLOOK lock \"$REPOS\" \"$PATH\" | \\"
name|NL
literal|"            $GREP '^Owner: ' | $SED 's/Owner: //'`"
name|NL
literal|""
name|NL
literal|"# If we get no result from svnlook, there's no lock, allow the lock to"
name|NL
literal|"# happen:"
name|NL
literal|"if [ \"$LOCK_OWNER\" = \"\" ]; then"
name|NL
literal|"  exit 0"
name|NL
literal|"fi"
name|NL
literal|""
name|NL
literal|"# If the person locking matches the lock's owner, allow the lock to"
name|NL
literal|"# happen:"
name|NL
literal|"if [ \"$LOCK_OWNER\" = \"$USER\" ]; then"
name|NL
literal|"  exit 0"
name|NL
literal|"fi"
name|NL
literal|""
name|NL
literal|"# Otherwise, we've got an owner mismatch, so return failure:"
name|NL
literal|"echo \"Error: $PATH already locked by ${LOCK_OWNER}.\" 1>&2"
name|NL
literal|"exit 1"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
literal|"Creating pre-lock hook"
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end pre-lock hook */
comment|/* Pre-unlock hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_pre_unlock_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_PRE_UNLOCK
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# PRE-UNLOCK HOOK"
name|NL
literal|"#"
name|NL
literal|"# The pre-unlock hook is invoked before an exclusive lock is"
name|NL
literal|"# destroyed.  Subversion runs this hook by invoking a program "
name|NL
literal|"# (script, executable, binary, etc.) named '"
name|SCRIPT_NAME
literal|"' (for which"
name|NL
literal|"# this file is a template), with the following ordered arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] PATH         (the path in the repository about to be unlocked)"
name|NL
literal|"#   [3] USER         (the user destroying the lock)"
name|NL
literal|"#   [4] TOKEN        (the lock token to be destroyed)"
name|NL
literal|"#   [5] BREAK-UNLOCK (1 if the user is breaking the lock, else 0)"
name|NL
literal|"#"
name|NL
literal|"# The default working directory for the invocation is undefined, so"
name|NL
literal|"# the program should set one explicitly if it cares."
name|NL
literal|"#"
name|NL
literal|"# If the hook program exits with success, the lock is destroyed; but"
name|NL
literal|"# if it exits with failure (non-zero), the unlock action is aborted"
name|NL
literal|"# and STDERR is returned to the client."
name|NL
literal|""
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"#"
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter:"
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"PATH=\"$2\""
name|NL
literal|"USER=\"$3\""
name|NL
literal|"TOKEN=\"$4\""
name|NL
literal|"BREAK=\"$5\""
name|NL
literal|""
name|NL
literal|"# If a lock is owned by a different person, don't allow it be broken."
name|NL
literal|"# (Maybe this script could send email to the lock owner?)"
name|NL
literal|""
name|NL
literal|"SVNLOOK="
name|SVN_BINDIR
literal|"/svnlook"
name|NL
literal|"GREP=/bin/grep"
name|NL
literal|"SED=/bin/sed"
name|NL
literal|""
name|NL
literal|"LOCK_OWNER=`$SVNLOOK lock \"$REPOS\" \"$PATH\" | \\"
name|NL
literal|"            $GREP '^Owner: ' | $SED 's/Owner: //'`"
name|NL
literal|""
name|NL
literal|"# If we get no result from svnlook, there's no lock, return success:"
name|NL
literal|"if [ \"$LOCK_OWNER\" = \"\" ]; then"
name|NL
literal|"  exit 0"
name|NL
literal|"fi"
name|NL
literal|""
name|NL
literal|"# If the person unlocking matches the lock's owner, return success:"
name|NL
literal|"if [ \"$LOCK_OWNER\" = \"$USER\" ]; then"
name|NL
literal|"  exit 0"
name|NL
literal|"fi"
name|NL
literal|""
name|NL
literal|"# Otherwise, we've got an owner mismatch, so return failure:"
name|NL
literal|"echo \"Error: $PATH locked by ${LOCK_OWNER}.\" 1>&2"
name|NL
literal|"exit 1"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
literal|"Creating pre-unlock hook"
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end pre-unlock hook */
comment|/* Post-commit hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_post_commit_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_POST_COMMIT
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# POST-COMMIT HOOK"
name|NL
literal|"#"
name|NL
literal|"# The post-commit hook is invoked after a commit.  Subversion runs"
name|NL
literal|"# this hook by invoking a program (script, executable, binary, etc.)"
name|NL
literal|"# named '"
name|SCRIPT_NAME
literal|"' (for which this file is a template) with the "
name|NL
literal|"# following ordered arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] REV          (the number of the revision just committed)"
name|NL
literal|"#   [3] TXN-NAME     (the name of the transaction that has become REV)"
name|NL
literal|"#"
name|NL
literal|"# The default working directory for the invocation is undefined, so"
name|NL
literal|"# the program should set one explicitly if it cares."
name|NL
literal|"#"
name|NL
literal|"# Because the commit has already completed and cannot be undone,"
name|NL
literal|"# the exit code of the hook program is ignored.  The hook program"
name|NL
literal|"# can use the 'svnlook' utility to help it examine the"
name|NL
literal|"# newly-committed tree."
name|NL
literal|"#"
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"# "
name|NL
name|HOOKS_ENVIRONMENT_TEXT
literal|"# "
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter."
name|NL
name|PREWRITTEN_HOOKS_TEXT
literal|""
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"REV=\"$2\""
name|NL
literal|"TXN_NAME=\"$3\""
name|NL
name|NL
literal|"mailer.py commit \"$REPOS\" \"$REV\" /path/to/mailer.conf"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating post-commit hook"
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end post-commit hook */
comment|/* Post-lock hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_post_lock_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_POST_LOCK
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# POST-LOCK HOOK"
name|NL
literal|"#"
name|NL
literal|"# The post-lock hook is run after a path is locked.  Subversion runs"
name|NL
literal|"# this hook by invoking a program (script, executable, binary, etc.)"
name|NL
literal|"# named '"
name|SCRIPT_NAME
literal|"' (for which this file is a template) with the "
name|NL
literal|"# following ordered arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] USER         (the user who created the lock)"
name|NL
literal|"#"
name|NL
literal|"# The paths that were just locked are passed to the hook via STDIN (as"
name|NL
literal|"# of Subversion 1.2, only one path is passed per invocation, but the"
name|NL
literal|"# plan is to pass all locked paths at once, so the hook program"
name|NL
literal|"# should be written accordingly)."
name|NL
literal|"#"
name|NL
literal|"# The default working directory for the invocation is undefined, so"
name|NL
literal|"# the program should set one explicitly if it cares."
name|NL
literal|"#"
name|NL
literal|"# Because the lock has already been created and cannot be undone,"
name|NL
literal|"# the exit code of the hook program is ignored.  The hook program"
name|NL
literal|"# can use the 'svnlook' utility to help it examine the"
name|NL
literal|"# newly-created lock."
name|NL
literal|"#"
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"# "
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter:"
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"USER=\"$2\""
name|NL
literal|""
name|NL
literal|"# Send email to interested parties, let them know a lock was created:"
name|NL
literal|"mailer.py lock \"$REPOS\" \"$USER\" /path/to/mailer.conf"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
literal|"Creating post-lock hook"
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end post-lock hook */
comment|/* Post-unlock hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_post_unlock_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_POST_UNLOCK
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# POST-UNLOCK HOOK"
name|NL
literal|"#"
name|NL
literal|"# The post-unlock hook runs after a path is unlocked.  Subversion runs"
name|NL
literal|"# this hook by invoking a program (script, executable, binary, etc.)"
name|NL
literal|"# named '"
name|SCRIPT_NAME
literal|"' (for which this file is a template) with the "
name|NL
literal|"# following ordered arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] USER         (the user who destroyed the lock)"
name|NL
literal|"#"
name|NL
literal|"# The paths that were just unlocked are passed to the hook via STDIN"
name|NL
literal|"# (as of Subversion 1.2, only one path is passed per invocation, but"
name|NL
literal|"# the plan is to pass all unlocked paths at once, so the hook program"
name|NL
literal|"# should be written accordingly)."
name|NL
literal|"#"
name|NL
literal|"# The default working directory for the invocation is undefined, so"
name|NL
literal|"# the program should set one explicitly if it cares."
name|NL
literal|"#"
name|NL
literal|"# Because the lock has already been destroyed and cannot be undone,"
name|NL
literal|"# the exit code of the hook program is ignored."
name|NL
literal|"#"
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"# "
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter:"
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"USER=\"$2\""
name|NL
literal|""
name|NL
literal|"# Send email to interested parties, let them know a lock was removed:"
name|NL
literal|"mailer.py unlock \"$REPOS\" \"$USER\" /path/to/mailer.conf"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
literal|"Creating post-unlock hook"
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end post-unlock hook */
comment|/* Post-revprop-change hook. */
block|{
name|this_path
operator|=
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
literal|"%s%s"
argument_list|,
name|svn_repos_post_revprop_change_hook
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__HOOK_DESC_EXT
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCRIPT_NAME
value|SVN_REPOS__HOOK_POST_REVPROP_CHANGE
name|contents
operator|=
literal|"#!/bin/sh"
name|NL
literal|""
name|NL
literal|"# POST-REVPROP-CHANGE HOOK"
name|NL
literal|"#"
name|NL
literal|"# The post-revprop-change hook is invoked after a revision property"
name|NL
literal|"# has been added, modified or deleted.  Subversion runs this hook by"
name|NL
literal|"# invoking a program (script, executable, binary, etc.) named"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|"' (for which this file is a template), with the"
name|NL
literal|"# following ordered arguments:"
name|NL
literal|"#"
name|NL
literal|"#   [1] REPOS-PATH   (the path to this repository)"
name|NL
literal|"#   [2] REV          (the revision that was tweaked)"
name|NL
literal|"#   [3] USER         (the username of the person tweaking the property)"
name|NL
literal|"#   [4] PROPNAME     (the property that was changed)"
name|NL
literal|"#   [5] ACTION       (the property was 'A'dded, 'M'odified, or 'D'eleted)"
name|NL
literal|"#"
name|NL
literal|"#   [STDIN] PROPVAL  ** the old property value is passed via STDIN."
name|NL
literal|"#"
name|NL
literal|"# Because the propchange has already completed and cannot be undone,"
name|NL
literal|"# the exit code of the hook program is ignored.  The hook program"
name|NL
literal|"# can use the 'svnlook' utility to help it examine the"
name|NL
literal|"# new property value."
name|NL
literal|"#"
name|NL
literal|"# On a Unix system, the normal procedure is to have '"
name|SCRIPT_NAME
literal|"'"
name|NL
literal|"# invoke other programs to do the real work, though it may do the"
name|NL
literal|"# work itself too."
name|NL
literal|"#"
name|NL
literal|"# Note that '"
name|SCRIPT_NAME
literal|"' must be executable by the user(s) who will"
name|NL
literal|"# invoke it (typically the user httpd runs as), and that user must"
name|NL
literal|"# have filesystem-level permission to access the repository."
name|NL
literal|"#"
name|NL
literal|"# On a Windows system, you should name the hook program"
name|NL
literal|"# '"
name|SCRIPT_NAME
literal|".bat' or '"
name|SCRIPT_NAME
literal|".exe',"
name|NL
literal|"# but the basic idea is the same."
name|NL
literal|"# "
name|NL
name|HOOKS_ENVIRONMENT_TEXT
literal|"# "
name|NL
literal|"# Here is an example hook script, for a Unix /bin/sh interpreter."
name|NL
name|PREWRITTEN_HOOKS_TEXT
literal|""
name|NL
literal|""
name|NL
literal|"REPOS=\"$1\""
name|NL
literal|"REV=\"$2\""
name|NL
literal|"USER=\"$3\""
name|NL
literal|"PROPNAME=\"$4\""
name|NL
literal|"ACTION=\"$5\""
name|NL
literal|""
name|NL
literal|"mailer.py propchange2 \"$REPOS\" \"$REV\" \"$USER\" \"$PROPNAME\" "
literal|"\"$ACTION\" /path/to/mailer.conf"
name|NL
expr_stmt|;
undef|#
directive|undef
name|SCRIPT_NAME
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|this_path
argument_list|,
name|contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating post-revprop-change hook"
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_set_file_executable
argument_list|(
name|this_path
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* end post-revprop-change hook */
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
specifier|static
name|svn_error_t
modifier|*
name|create_conf
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|SVN_ERR_W
argument_list|(
name|create_repos_dir
argument_list|(
name|repos
operator|->
name|conf_path
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating conf directory"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Write a default template for svnserve.conf. */
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|svnserve_conf_contents
init|=
literal|"### This file controls the configuration of the svnserve daemon, if you"
name|NL
literal|"### use it to allow access to this repository.  (If you only allow"
name|NL
literal|"### access through http: and/or file: URLs, then this file is"
name|NL
literal|"### irrelevant.)"
name|NL
literal|""
name|NL
literal|"### Visit http://subversion.apache.org/ for more information."
name|NL
literal|""
name|NL
literal|"[general]"
name|NL
literal|"### The anon-access and auth-access options control access to the"
name|NL
literal|"### repository for unauthenticated (a.k.a. anonymous) users and"
name|NL
literal|"### authenticated users, respectively."
name|NL
literal|"### Valid values are \"write\", \"read\", and \"none\"."
name|NL
literal|"### Setting the value to \"none\" prohibits both reading and writing;"
name|NL
literal|"### \"read\" allows read-only access, and \"write\" allows complete "
name|NL
literal|"### read/write access to the repository."
name|NL
literal|"### The sample settings below are the defaults and specify that anonymous"
name|NL
literal|"### users have read-only access to the repository, while authenticated"
name|NL
literal|"### users have read and write access to the repository."
name|NL
literal|"# anon-access = read"
name|NL
literal|"# auth-access = write"
name|NL
literal|"### The password-db option controls the location of the password"
name|NL
literal|"### database file.  Unless you specify a path starting with a /,"
name|NL
literal|"### the file's location is relative to the directory containing"
name|NL
literal|"### this configuration file."
name|NL
literal|"### If SASL is enabled (see below), this file will NOT be used."
name|NL
literal|"### Uncomment the line below to use the default password file."
name|NL
literal|"# password-db = passwd"
name|NL
literal|"### The authz-db option controls the location of the authorization"
name|NL
literal|"### rules for path-based access control.  Unless you specify a path"
name|NL
literal|"### starting with a /, the file's location is relative to the"
name|NL
literal|"### directory containing this file.  The specified path may be a"
name|NL
literal|"### repository relative URL (^/) or an absolute file:// URL to a text"
name|NL
literal|"### file in a Subversion repository.  If you don't specify an authz-db,"
name|NL
literal|"### no path-based access control is done."
name|NL
literal|"### Uncomment the line below to use the default authorization file."
name|NL
literal|"# authz-db = "
name|SVN_REPOS__CONF_AUTHZ
name|NL
literal|"### The groups-db option controls the location of the groups file."
name|NL
literal|"### Unless you specify a path starting with a /, the file's location is"
name|NL
literal|"### relative to the directory containing this file.  The specified path"
name|NL
literal|"### may be a repository relative URL (^/) or an absolute file:// URL to a"
name|NL
literal|"### text file in a Subversion repository."
name|NL
literal|"# groups-db = "
name|SVN_REPOS__CONF_GROUPS
name|NL
literal|"### This option specifies the authentication realm of the repository."
name|NL
literal|"### If two repositories have the same authentication realm, they should"
name|NL
literal|"### have the same password database, and vice versa.  The default realm"
name|NL
literal|"### is repository's uuid."
name|NL
literal|"# realm = My First Repository"
name|NL
literal|"### The force-username-case option causes svnserve to case-normalize"
name|NL
literal|"### usernames before comparing them against the authorization rules in the"
name|NL
literal|"### authz-db file configured above.  Valid values are \"upper\" (to upper-"
name|NL
literal|"### case the usernames), \"lower\" (to lowercase the usernames), and"
name|NL
literal|"### \"none\" (to compare usernames as-is without case conversion, which"
name|NL
literal|"### is the default behavior)."
name|NL
literal|"# force-username-case = none"
name|NL
literal|"### The hooks-env options specifies a path to the hook script environment "
name|NL
literal|"### configuration file. This option overrides the per-repository default"
name|NL
literal|"### and can be used to configure the hook script environment for multiple "
name|NL
literal|"### repositories in a single file, if an absolute path is specified."
name|NL
literal|"### Unless you specify an absolute path, the file's location is relative"
name|NL
literal|"### to the directory containing this file."
name|NL
literal|"# hooks-env = "
name|SVN_REPOS__CONF_HOOKS_ENV
name|NL
literal|""
name|NL
literal|"[sasl]"
name|NL
literal|"### This option specifies whether you want to use the Cyrus SASL"
name|NL
literal|"### library for authentication. Default is false."
name|NL
literal|"### This section will be ignored if svnserve is not built with Cyrus"
name|NL
literal|"### SASL support; to check, run 'svnserve --version' and look for a line"
name|NL
literal|"### reading 'Cyrus SASL authentication is available.'"
name|NL
literal|"# use-sasl = true"
name|NL
literal|"### These options specify the desired strength of the security layer"
name|NL
literal|"### that you want SASL to provide. 0 means no encryption, 1 means"
name|NL
literal|"### integrity-checking only, values larger than 1 are correlated"
name|NL
literal|"### to the effective key length for encryption (e.g. 128 means 128-bit"
name|NL
literal|"### encryption). The values below are the defaults."
name|NL
literal|"# min-encryption = 0"
name|NL
literal|"# max-encryption = 256"
name|NL
decl_stmt|;
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|svn_repos_svnserve_conf
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|svnserve_conf_contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating svnserve.conf file"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|passwd_contents
init|=
literal|"### This file is an example password file for svnserve."
name|NL
literal|"### Its format is similar to that of svnserve.conf. As shown in the"
name|NL
literal|"### example below it contains one section labelled [users]."
name|NL
literal|"### The name and password for each user follow, one account per line."
name|NL
literal|""
name|NL
literal|"[users]"
name|NL
literal|"# harry = harryssecret"
name|NL
literal|"# sally = sallyssecret"
name|NL
decl_stmt|;
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|conf_path
argument_list|,
name|SVN_REPOS__CONF_PASSWD
argument_list|,
name|pool
argument_list|)
argument_list|,
name|passwd_contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating passwd file"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|authz_contents
init|=
literal|"### This file is an example authorization file for svnserve."
name|NL
literal|"### Its format is identical to that of mod_authz_svn authorization"
name|NL
literal|"### files."
name|NL
literal|"### As shown below each section defines authorizations for the path and"
name|NL
literal|"### (optional) repository specified by the section name."
name|NL
literal|"### The authorizations follow. An authorization line can refer to:"
name|NL
literal|"###  - a single user,"
name|NL
literal|"###  - a group of users defined in a special [groups] section,"
name|NL
literal|"###  - an alias defined in a special [aliases] section,"
name|NL
literal|"###  - all authenticated users, using the '$authenticated' token,"
name|NL
literal|"###  - only anonymous users, using the '$anonymous' token,"
name|NL
literal|"###  - anyone, using the '*' wildcard."
name|NL
literal|"###"
name|NL
literal|"### A match can be inverted by prefixing the rule with '~'. Rules can"
name|NL
literal|"### grant read ('r') access, read-write ('rw') access, or no access"
name|NL
literal|"### ('')."
name|NL
literal|""
name|NL
literal|"[aliases]"
name|NL
literal|"# joe = /C=XZ/ST=Dessert/L=Snake City/O=Snake Oil, Ltd./OU=Research Institute/CN=Joe Average"
name|NL
literal|""
name|NL
literal|"[groups]"
name|NL
literal|"# harry_and_sally = harry,sally"
name|NL
literal|"# harry_sally_and_joe = harry,sally,&joe"
name|NL
literal|""
name|NL
literal|"# [/foo/bar]"
name|NL
literal|"# harry = rw"
name|NL
literal|"#&joe = r"
name|NL
literal|"# * ="
name|NL
literal|""
name|NL
literal|"# [repository:/baz/fuz]"
name|NL
literal|"# @harry_and_sally = rw"
name|NL
literal|"# * = r"
name|NL
decl_stmt|;
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|conf_path
argument_list|,
name|SVN_REPOS__CONF_AUTHZ
argument_list|,
name|pool
argument_list|)
argument_list|,
name|authz_contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating authz file"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|hooks_env_contents
init|=
literal|"### This file is an example hook script environment configuration file."
name|NL
literal|"### Hook scripts run in an empty environment by default."
name|NL
literal|"### As shown below each section defines environment variables for a"
name|NL
literal|"### particular hook script. The [default] section defines environment"
name|NL
literal|"### variables for all hook scripts, unless overridden by a hook-specific"
name|NL
literal|"### section."
name|NL
literal|""
name|NL
literal|"### This example configures a UTF-8 locale for all hook scripts, so that "
name|NL
literal|"### special characters, such as umlauts, may be printed to stderr."
name|NL
literal|"### If UTF-8 is used with a mod_dav_svn server, the SVNUseUTF8 option must"
name|NL
literal|"### also be set to 'yes' in httpd.conf."
name|NL
literal|"### With svnserve, the LANG environment variable of the svnserve process"
name|NL
literal|"### must be set to the same value as given here."
name|NL
literal|"[default]"
name|NL
literal|"LANG = en_US.UTF-8"
name|NL
literal|""
name|NL
literal|"### This sets the PATH environment variable for the pre-commit hook."
name|NL
literal|"[pre-commit]"
name|NL
literal|"PATH = /usr/local/bin:/usr/bin:/usr/sbin"
name|NL
decl_stmt|;
name|SVN_ERR_W
argument_list|(
name|svn_io_file_create
argument_list|(
name|svn_dirent_join
argument_list|(
argument|repos->conf_path
argument_list|,
argument|SVN_REPOS__CONF_HOOKS_ENV \                                                  SVN_REPOS__HOOK_DESC_EXT
argument_list|,
argument|pool
argument_list|)
argument_list|,
name|hooks_env_contents
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating hooks-env file"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_hooks_setenv
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
specifier|const
name|char
modifier|*
name|hooks_env_path
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
block|{
if|if
condition|(
name|hooks_env_path
operator|==
name|NULL
condition|)
name|repos
operator|->
name|hooks_env_path
operator|=
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|conf_path
argument_list|,
name|SVN_REPOS__CONF_HOOKS_ENV
argument_list|,
name|repos
operator|->
name|pool
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|svn_dirent_is_absolute
argument_list|(
name|hooks_env_path
argument_list|)
condition|)
name|repos
operator|->
name|hooks_env_path
operator|=
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|conf_path
argument_list|,
name|hooks_env_path
argument_list|,
name|repos
operator|->
name|pool
argument_list|)
expr_stmt|;
else|else
name|repos
operator|->
name|hooks_env_path
operator|=
name|apr_pstrdup
argument_list|(
name|repos
operator|->
name|pool
argument_list|,
name|hooks_env_path
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Allocate and return a new svn_repos_t * object, initializing the    directory pathname members based on PATH, and initializing the    REPOSITORY_CAPABILITIES member.    The members FS, FORMAT, and FS_TYPE are *not* initialized (they are null),    and it is the caller's responsibility to fill them in if needed.  */
end_comment

begin_function
specifier|static
name|svn_repos_t
modifier|*
name|create_svn_repos_t
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_repos_t
modifier|*
name|repos
init|=
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|repos
argument_list|)
argument_list|)
decl_stmt|;
name|repos
operator|->
name|path
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|repos
operator|->
name|db_path
operator|=
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__DB_DIR
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|repos
operator|->
name|conf_path
operator|=
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__CONF_DIR
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|repos
operator|->
name|hook_path
operator|=
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__HOOK_DIR
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|repos
operator|->
name|lock_path
operator|=
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__LOCK_DIR
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|repos
operator|->
name|hooks_env_path
operator|=
name|NULL
expr_stmt|;
name|repos
operator|->
name|repository_capabilities
operator|=
name|apr_hash_make
argument_list|(
name|pool
argument_list|)
expr_stmt|;
name|repos
operator|->
name|pool
operator|=
name|pool
expr_stmt|;
return|return
name|repos
return|;
block|}
end_function

begin_function
specifier|static
name|svn_error_t
modifier|*
name|create_repos_structure
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_hash_t
modifier|*
name|fs_config
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
comment|/* Create the top-level repository directory. */
name|SVN_ERR_W
argument_list|(
name|create_repos_dir
argument_list|(
name|path
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Could not create top-level directory"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Create the DAV sandbox directory if pre-1.4 or pre-1.5-compatible. */
if|if
condition|(
name|fs_config
operator|&&
operator|(
name|svn_hash_gets
argument_list|(
name|fs_config
argument_list|,
name|SVN_FS_CONFIG_PRE_1_4_COMPATIBLE
argument_list|)
operator|||
name|svn_hash_gets
argument_list|(
name|fs_config
argument_list|,
name|SVN_FS_CONFIG_PRE_1_5_COMPATIBLE
argument_list|)
operator|)
condition|)
block|{
specifier|const
name|char
modifier|*
name|dav_path
init|=
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|path
argument_list|,
name|SVN_REPOS__DAV_DIR
argument_list|,
name|pool
argument_list|)
decl_stmt|;
name|SVN_ERR_W
argument_list|(
name|create_repos_dir
argument_list|(
name|dav_path
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Creating DAV sandbox dir"
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Create the lock directory.  */
name|SVN_ERR
argument_list|(
name|create_locks
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Create the hooks directory.  */
name|SVN_ERR
argument_list|(
name|create_hooks
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Create the conf directory.  */
name|SVN_ERR
argument_list|(
name|create_conf
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Write the top-level README file. */
block|{
specifier|const
name|char
modifier|*
specifier|const
name|readme_header
init|=
literal|"This is a Subversion repository; use the 'svnadmin' and 'svnlook' "
name|NL
literal|"tools to examine it.  Do not add, delete, or modify files here "
name|NL
literal|"unless you know how to avoid corrupting the repository."
name|NL
literal|""
name|NL
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|readme_bdb_insert
init|=
literal|"The directory \""
name|SVN_REPOS__DB_DIR
literal|"\" contains a Berkeley DB environment."
name|NL
literal|"you may need to tweak the values in \""
name|SVN_REPOS__DB_DIR
literal|"/DB_CONFIG\" to match the"
name|NL
literal|"requirements of your site."
name|NL
literal|""
name|NL
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|readme_footer
init|=
literal|"Visit http://subversion.apache.org/ for more information."
name|NL
decl_stmt|;
name|apr_file_t
modifier|*
name|f
decl_stmt|;
name|apr_size_t
name|written
decl_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_file_open
argument_list|(
operator|&
name|f
argument_list|,
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__README
argument_list|,
name|pool
argument_list|)
argument_list|,
operator|(
name|APR_WRITE
operator||
name|APR_CREATE
operator||
name|APR_EXCL
operator|)
argument_list|,
name|APR_OS_DEFAULT
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_file_write_full
argument_list|(
name|f
argument_list|,
name|readme_header
argument_list|,
name|strlen
argument_list|(
name|readme_header
argument_list|)
argument_list|,
operator|&
name|written
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|repos
operator|->
name|fs_type
argument_list|,
name|SVN_FS_TYPE_BDB
argument_list|)
operator|==
literal|0
condition|)
name|SVN_ERR
argument_list|(
name|svn_io_file_write_full
argument_list|(
name|f
argument_list|,
name|readme_bdb_insert
argument_list|,
name|strlen
argument_list|(
name|readme_bdb_insert
argument_list|)
argument_list|,
operator|&
name|written
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_file_write_full
argument_list|(
name|f
argument_list|,
name|readme_footer
argument_list|,
name|strlen
argument_list|(
name|readme_footer
argument_list|)
argument_list|,
operator|&
name|written
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|svn_io_file_close
argument_list|(
name|f
argument_list|,
name|pool
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/* There is, at present, nothing within the direct responsibility    of libsvn_repos which requires locking.  For historical compatibility    reasons, the BDB libsvn_fs backend does not do its own locking, expecting    libsvn_repos to do the locking for it.  Here we take care of that    backend-specific requirement.    The kind of lock is controlled by EXCLUSIVE and NONBLOCKING.    The lock is scoped to POOL.  */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|lock_repos
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|svn_boolean_t
name|exclusive
parameter_list|,
name|svn_boolean_t
name|nonblocking
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|repos
operator|->
name|fs_type
argument_list|,
name|SVN_FS_TYPE_BDB
argument_list|)
operator|==
literal|0
condition|)
block|{
name|svn_error_t
modifier|*
name|err
decl_stmt|;
specifier|const
name|char
modifier|*
name|lockfile_path
init|=
name|svn_repos_db_lockfile
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
decl_stmt|;
name|err
operator|=
name|svn_io_file_lock2
argument_list|(
name|lockfile_path
argument_list|,
name|exclusive
argument_list|,
name|nonblocking
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
name|NULL
operator|&&
name|APR_STATUS_IS_EAGAIN
argument_list|(
name|err
operator|->
name|apr_err
argument_list|)
condition|)
return|return
name|svn_error_trace
argument_list|(
name|err
argument_list|)
return|;
name|SVN_ERR_W
argument_list|(
name|err
argument_list|,
name|_
argument_list|(
literal|"Error opening db lockfile"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_create
parameter_list|(
name|svn_repos_t
modifier|*
modifier|*
name|repos_p
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|unused_1
parameter_list|,
specifier|const
name|char
modifier|*
name|unused_2
parameter_list|,
name|apr_hash_t
modifier|*
name|config
parameter_list|,
name|apr_hash_t
modifier|*
name|fs_config
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_repos_t
modifier|*
name|repos
decl_stmt|;
name|svn_error_t
modifier|*
name|err
decl_stmt|;
specifier|const
name|char
modifier|*
name|root_path
decl_stmt|;
specifier|const
name|char
modifier|*
name|local_abspath
decl_stmt|;
comment|/* Allocate a repository object, filling in the format we will create. */
name|repos
operator|=
name|create_svn_repos_t
argument_list|(
name|path
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|repos
operator|->
name|format
operator|=
name|SVN_REPOS__FORMAT_NUMBER
expr_stmt|;
comment|/* Discover the type of the filesystem we are about to create. */
name|repos
operator|->
name|fs_type
operator|=
name|svn_hash__get_cstring
argument_list|(
name|fs_config
argument_list|,
name|SVN_FS_CONFIG_FS_TYPE
argument_list|,
name|DEFAULT_FS_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|svn_hash__get_bool
argument_list|(
name|fs_config
argument_list|,
name|SVN_FS_CONFIG_PRE_1_4_COMPATIBLE
argument_list|,
name|FALSE
argument_list|)
condition|)
name|repos
operator|->
name|format
operator|=
name|SVN_REPOS__FORMAT_NUMBER_LEGACY
expr_stmt|;
comment|/* Don't create a repository inside another repository. */
name|SVN_ERR
argument_list|(
name|svn_dirent_get_absolute
argument_list|(
operator|&
name|local_abspath
argument_list|,
name|path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|root_path
operator|=
name|svn_repos_find_root_path
argument_list|(
name|local_abspath
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|root_path
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|root_path
argument_list|,
name|local_abspath
argument_list|)
operator|==
literal|0
condition|)
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_REPOS_BAD_ARGS
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"'%s' is an existing repository"
argument_list|)
argument_list|,
name|svn_dirent_local_style
argument_list|(
name|root_path
argument_list|,
name|pool
argument_list|)
argument_list|)
return|;
else|else
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_REPOS_BAD_ARGS
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"'%s' is a subdirectory of an existing "
literal|"repository "
literal|"rooted at '%s'"
argument_list|)
argument_list|,
name|svn_dirent_local_style
argument_list|(
name|local_abspath
argument_list|,
name|pool
argument_list|)
argument_list|,
name|svn_dirent_local_style
argument_list|(
name|root_path
argument_list|,
name|pool
argument_list|)
argument_list|)
return|;
block|}
comment|/* Create the various files and subdirectories for the repository. */
name|SVN_ERR_W
argument_list|(
name|create_repos_structure
argument_list|(
name|repos
argument_list|,
name|path
argument_list|,
name|fs_config
argument_list|,
name|pool
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Repository creation failed"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Lock if needed. */
name|SVN_ERR
argument_list|(
name|lock_repos
argument_list|(
name|repos
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Create an environment for the filesystem. */
if|if
condition|(
operator|(
name|err
operator|=
name|svn_fs_create
argument_list|(
operator|&
name|repos
operator|->
name|fs
argument_list|,
name|repos
operator|->
name|db_path
argument_list|,
name|fs_config
argument_list|,
name|pool
argument_list|)
operator|)
condition|)
block|{
comment|/* If there was an error making the filesytem, e.g. unknown/supported        * filesystem type.  Clean up after ourselves.  Yes this is safe because        * create_repos_structure will fail if the path existed before we started        * so we can't accidentally remove a directory that previously existed.        */
return|return
name|svn_error_trace
argument_list|(
name|svn_error_compose_create
argument_list|(
name|err
argument_list|,
name|svn_io_remove_dir2
argument_list|(
name|path
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
comment|/* This repository is ready.  Stamp it with a format number. */
name|SVN_ERR
argument_list|(
name|svn_io_write_version_file
argument_list|(
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__FORMAT
argument_list|,
name|pool
argument_list|)
argument_list|,
name|repos
operator|->
name|format
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|repos_p
operator|=
name|repos
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Check if @a path is the root of a repository by checking if the  * path contains the expected files and directories.  Return TRUE  * on errors (which would be permission errors, probably) so that  * we the user will see them after we try to open the repository  * for real.  */
end_comment

begin_function
specifier|static
name|svn_boolean_t
name|check_repos_path
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_node_kind_t
name|kind
decl_stmt|;
name|svn_error_t
modifier|*
name|err
decl_stmt|;
name|err
operator|=
name|svn_io_check_path
argument_list|(
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__FORMAT
argument_list|,
name|pool
argument_list|)
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
if|if
condition|(
name|kind
operator|!=
name|svn_node_file
condition|)
return|return
name|FALSE
return|;
comment|/* Check the db/ subdir, but allow it to be a symlink (Subversion      works just fine if it's a symlink). */
name|err
operator|=
name|svn_io_check_resolved_path
argument_list|(
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__DB_DIR
argument_list|,
name|pool
argument_list|)
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
if|if
condition|(
name|kind
operator|!=
name|svn_node_dir
condition|)
return|return
name|FALSE
return|;
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* Verify that REPOS's format is suitable.    Use POOL for temporary allocation. */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|check_repos_format
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|int
name|format
decl_stmt|;
specifier|const
name|char
modifier|*
name|format_path
decl_stmt|;
name|format_path
operator|=
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|path
argument_list|,
name|SVN_REPOS__FORMAT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_read_version_file
argument_list|(
operator|&
name|format
argument_list|,
name|format_path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|!=
name|SVN_REPOS__FORMAT_NUMBER
operator|&&
name|format
operator|!=
name|SVN_REPOS__FORMAT_NUMBER_LEGACY
condition|)
block|{
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_REPOS_UNSUPPORTED_VERSION
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Expected repository format '%d' or '%d'; found format '%d'"
argument_list|)
argument_list|,
name|SVN_REPOS__FORMAT_NUMBER_LEGACY
argument_list|,
name|SVN_REPOS__FORMAT_NUMBER
argument_list|,
name|format
argument_list|)
return|;
block|}
name|repos
operator|->
name|format
operator|=
name|format
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Set *REPOS_P to a repository at PATH which has been opened.    See lock_repos() above regarding EXCLUSIVE and NONBLOCKING.    OPEN_FS indicates whether the Subversion filesystem should be opened,    the handle being placed into repos->fs.    Do all allocation in POOL.  */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|get_repos
parameter_list|(
name|svn_repos_t
modifier|*
modifier|*
name|repos_p
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|svn_boolean_t
name|exclusive
parameter_list|,
name|svn_boolean_t
name|nonblocking
parameter_list|,
name|svn_boolean_t
name|open_fs
parameter_list|,
name|apr_hash_t
modifier|*
name|fs_config
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_repos_t
modifier|*
name|repos
decl_stmt|;
comment|/* Allocate a repository object. */
name|repos
operator|=
name|create_svn_repos_t
argument_list|(
name|path
argument_list|,
name|pool
argument_list|)
expr_stmt|;
comment|/* Verify the validity of our repository format. */
name|SVN_ERR
argument_list|(
name|check_repos_format
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Discover the FS type. */
name|SVN_ERR
argument_list|(
name|svn_fs_type
argument_list|(
operator|&
name|repos
operator|->
name|fs_type
argument_list|,
name|repos
operator|->
name|db_path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Lock if needed. */
name|SVN_ERR
argument_list|(
name|lock_repos
argument_list|(
name|repos
argument_list|,
name|exclusive
argument_list|,
name|nonblocking
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Open up the filesystem only after obtaining the lock. */
if|if
condition|(
name|open_fs
condition|)
name|SVN_ERR
argument_list|(
name|svn_fs_open
argument_list|(
operator|&
name|repos
operator|->
name|fs
argument_list|,
name|repos
operator|->
name|db_path
argument_list|,
name|fs_config
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SVN_DEBUG_CRASH_AT_REPOS_OPEN
comment|/* If $PATH/config/debug-abort exists, crash the server here.      This debugging feature can be used to test client recovery      when the server crashes.       See: Issue #4274 */
block|{
name|svn_node_kind_t
name|kind
decl_stmt|;
name|svn_error_t
modifier|*
name|err
init|=
name|svn_io_check_path
argument_list|(
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|conf_path
argument_list|,
literal|"debug-abort"
argument_list|,
name|pool
argument_list|)
argument_list|,
operator|&
name|kind
argument_list|,
name|pool
argument_list|)
decl_stmt|;
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
operator|&&
name|kind
operator|==
name|svn_node_file
condition|)
name|SVN_ERR_MALFUNCTION_NO_RETURN
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* SVN_DEBUG_CRASH_AT_REPOS_OPEN */
operator|*
name|repos_p
operator|=
name|repos
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|svn_repos_find_root_path
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|candidate
init|=
name|path
decl_stmt|;
specifier|const
name|char
modifier|*
name|decoded
decl_stmt|;
name|svn_error_t
modifier|*
name|err
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
comment|/* Try to decode the path, so we don't fail if it contains characters          that aren't supported by the OS filesystem.  The subversion fs          isn't restricted by the OS filesystem character set. */
name|err
operator|=
name|svn_path_cstring_from_utf8
argument_list|(
operator|&
name|decoded
argument_list|,
name|candidate
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
operator|&&
name|check_repos_path
argument_list|(
name|candidate
argument_list|,
name|pool
argument_list|)
condition|)
break|break;
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|svn_path_is_empty
argument_list|(
name|candidate
argument_list|)
operator|||
name|svn_dirent_is_root
argument_list|(
name|candidate
argument_list|,
name|strlen
argument_list|(
name|candidate
argument_list|)
argument_list|)
condition|)
return|return
name|NULL
return|;
name|candidate
operator|=
name|svn_dirent_dirname
argument_list|(
name|candidate
argument_list|,
name|pool
argument_list|)
expr_stmt|;
block|}
return|return
name|candidate
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_open2
parameter_list|(
name|svn_repos_t
modifier|*
modifier|*
name|repos_p
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_hash_t
modifier|*
name|fs_config
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
comment|/* Fetch a repository object initialized with a shared read/write      lock on the database. */
return|return
name|get_repos
argument_list|(
name|repos_p
argument_list|,
name|path
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
name|TRUE
argument_list|,
name|fs_config
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_upgrade2
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|svn_boolean_t
name|nonblocking
parameter_list|,
name|svn_repos_notify_func_t
name|notify_func
parameter_list|,
name|void
modifier|*
name|notify_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_repos_t
modifier|*
name|repos
decl_stmt|;
specifier|const
name|char
modifier|*
name|format_path
decl_stmt|;
name|int
name|format
decl_stmt|;
name|apr_pool_t
modifier|*
name|subpool
init|=
name|svn_pool_create
argument_list|(
name|pool
argument_list|)
decl_stmt|;
comment|/* Fetch a repository object; for the Berkeley DB backend, it is      initialized with an EXCLUSIVE lock on the database.  This will at      least prevent others from trying to read or write to it while we      run recovery. (Other backends should do their own locking; see      lock_repos.) */
name|SVN_ERR
argument_list|(
name|get_repos
argument_list|(
operator|&
name|repos
argument_list|,
name|path
argument_list|,
name|TRUE
argument_list|,
name|nonblocking
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|notify_func
condition|)
block|{
comment|/* We notify *twice* here, because there are two different logistical          actions occuring. */
name|svn_repos_notify_t
modifier|*
name|notify
init|=
name|svn_repos_notify_create
argument_list|(
name|svn_repos_notify_mutex_acquired
argument_list|,
name|subpool
argument_list|)
decl_stmt|;
name|notify_func
argument_list|(
name|notify_baton
argument_list|,
name|notify
argument_list|,
name|subpool
argument_list|)
expr_stmt|;
name|notify
operator|->
name|action
operator|=
name|svn_repos_notify_upgrade_start
expr_stmt|;
name|notify_func
argument_list|(
name|notify_baton
argument_list|,
name|notify
argument_list|,
name|subpool
argument_list|)
expr_stmt|;
block|}
comment|/* Try to overwrite with its own contents.  We do this only to      verify that we can, because we don't want to actually bump the      format of the repository until our underlying filesystem claims      to have been upgraded correctly. */
name|format_path
operator|=
name|svn_dirent_join
argument_list|(
name|repos
operator|->
name|path
argument_list|,
name|SVN_REPOS__FORMAT
argument_list|,
name|subpool
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_read_version_file
argument_list|(
operator|&
name|format
argument_list|,
name|format_path
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_write_version_file
argument_list|(
name|format_path
argument_list|,
name|format
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Try to upgrade the filesystem. */
name|SVN_ERR
argument_list|(
name|svn_fs_upgrade
argument_list|(
name|repos
operator|->
name|db_path
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Now overwrite our format file with the latest version. */
name|SVN_ERR
argument_list|(
name|svn_io_write_version_file
argument_list|(
name|format_path
argument_list|,
name|SVN_REPOS__FORMAT_NUMBER
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Close shop and free the subpool, to release the exclusive lock. */
name|svn_pool_destroy
argument_list|(
name|subpool
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_delete
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|db_path
init|=
name|svn_dirent_join
argument_list|(
name|path
argument_list|,
name|SVN_REPOS__DB_DIR
argument_list|,
name|pool
argument_list|)
decl_stmt|;
comment|/* Delete the filesystem environment... */
name|SVN_ERR
argument_list|(
name|svn_fs_delete_fs
argument_list|(
name|db_path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* ...then blow away everything else.  */
return|return
name|svn_io_remove_dir2
argument_list|(
name|path
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Repository supports the capability. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|capability_yes
init|=
literal|"yes"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repository does not support the capability. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|capability_no
init|=
literal|"no"
decl_stmt|;
end_decl_stmt

begin_function
name|svn_error_t
modifier|*
name|svn_repos_has_capability
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|svn_boolean_t
modifier|*
name|has
parameter_list|,
specifier|const
name|char
modifier|*
name|capability
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|val
init|=
name|svn_hash_gets
argument_list|(
name|repos
operator|->
name|repository_capabilities
argument_list|,
name|capability
argument_list|)
decl_stmt|;
if|if
condition|(
name|val
operator|==
name|capability_yes
condition|)
block|{
operator|*
name|has
operator|=
name|TRUE
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|val
operator|==
name|capability_no
condition|)
block|{
operator|*
name|has
operator|=
name|FALSE
expr_stmt|;
block|}
comment|/* Else don't know, so investigate. */
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|capability
argument_list|,
name|SVN_REPOS_CAPABILITY_MERGEINFO
argument_list|)
operator|==
literal|0
condition|)
block|{
name|svn_error_t
modifier|*
name|err
decl_stmt|;
name|svn_fs_root_t
modifier|*
name|root
decl_stmt|;
name|svn_mergeinfo_catalog_t
name|ignored
decl_stmt|;
name|apr_array_header_t
modifier|*
name|paths
init|=
name|apr_array_make
argument_list|(
name|pool
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
name|SVN_ERR
argument_list|(
name|svn_fs_revision_root
argument_list|(
operator|&
name|root
argument_list|,
name|repos
operator|->
name|fs
argument_list|,
literal|0
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|APR_ARRAY_PUSH
argument_list|(
name|paths
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
operator|=
literal|""
expr_stmt|;
name|err
operator|=
name|svn_fs_get_mergeinfo2
argument_list|(
operator|&
name|ignored
argument_list|,
name|root
argument_list|,
name|paths
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
name|TRUE
argument_list|,
name|pool
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
if|if
condition|(
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_UNSUPPORTED_FEATURE
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|svn_hash_sets
argument_list|(
name|repos
operator|->
name|repository_capabilities
argument_list|,
name|SVN_REPOS_CAPABILITY_MERGEINFO
argument_list|,
name|capability_no
argument_list|)
expr_stmt|;
operator|*
name|has
operator|=
name|FALSE
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_FS_NOT_FOUND
condition|)
block|{
comment|/* Mergeinfo requests use relative paths, and anyway we're                  in r0, so we're likely to get this error -- but it                  means the repository supports mergeinfo! */
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|svn_hash_sets
argument_list|(
name|repos
operator|->
name|repository_capabilities
argument_list|,
name|SVN_REPOS_CAPABILITY_MERGEINFO
argument_list|,
name|capability_yes
argument_list|)
expr_stmt|;
operator|*
name|has
operator|=
name|TRUE
expr_stmt|;
block|}
else|else
block|{
return|return
name|svn_error_trace
argument_list|(
name|err
argument_list|)
return|;
block|}
block|}
else|else
block|{
name|svn_hash_sets
argument_list|(
name|repos
operator|->
name|repository_capabilities
argument_list|,
name|SVN_REPOS_CAPABILITY_MERGEINFO
argument_list|,
name|capability_yes
argument_list|)
expr_stmt|;
operator|*
name|has
operator|=
name|TRUE
expr_stmt|;
block|}
block|}
else|else
block|{
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_UNKNOWN_CAPABILITY
argument_list|,
literal|0
argument_list|,
name|_
argument_list|(
literal|"unknown capability '%s'"
argument_list|)
argument_list|,
name|capability
argument_list|)
return|;
block|}
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_fs_t
modifier|*
name|svn_repos_fs
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|)
block|{
if|if
condition|(
operator|!
name|repos
condition|)
return|return
name|NULL
return|;
return|return
name|repos
operator|->
name|fs
return|;
block|}
end_function

begin_comment
comment|/* For historical reasons, for the Berkeley DB backend, this code uses  * repository locking, which is motivated by the need to support the  * Berkeley DB error DB_RUN_RECOVERY.  (FSFS takes care of locking  * itself, inside its implementation of svn_fs_recover.)  Here's how  * it works:  *  * Every accessor of a repository's database takes out a shared lock  * on the repository -- both readers and writers get shared locks, and  * there can be an unlimited number of shared locks simultaneously.  *  * Sometimes, a db access returns the error DB_RUN_RECOVERY.  When  * this happens, we need to run svn_fs_recover() on the db  * with no other accessors present.  So we take out an exclusive lock  * on the repository.  From the moment we request the exclusive lock,  * no more shared locks are granted, and when the last shared lock  * disappears, the exclusive lock is granted.  As soon as we get it,  * we can run recovery.  *  * We assume that once any berkeley call returns DB_RUN_RECOVERY, they  * all do, until recovery is run.  */
end_comment

begin_function
name|svn_error_t
modifier|*
name|svn_repos_recover4
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|svn_boolean_t
name|nonblocking
parameter_list|,
name|svn_repos_notify_func_t
name|notify_func
parameter_list|,
name|void
modifier|*
name|notify_baton
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
block|{
name|svn_repos_t
modifier|*
name|repos
decl_stmt|;
name|apr_pool_t
modifier|*
name|subpool
init|=
name|svn_pool_create
argument_list|(
name|pool
argument_list|)
decl_stmt|;
comment|/* Fetch a repository object; for the Berkeley DB backend, it is      initialized with an EXCLUSIVE lock on the database.  This will at      least prevent others from trying to read or write to it while we      run recovery. (Other backends should do their own locking; see      lock_repos.) */
name|SVN_ERR
argument_list|(
name|get_repos
argument_list|(
operator|&
name|repos
argument_list|,
name|path
argument_list|,
name|TRUE
argument_list|,
name|nonblocking
argument_list|,
name|FALSE
argument_list|,
comment|/* don't try to open the db yet. */
name|NULL
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|notify_func
condition|)
block|{
comment|/* We notify *twice* here, because there are two different logistical          actions occuring. */
name|svn_repos_notify_t
modifier|*
name|notify
init|=
name|svn_repos_notify_create
argument_list|(
name|svn_repos_notify_mutex_acquired
argument_list|,
name|subpool
argument_list|)
decl_stmt|;
name|notify_func
argument_list|(
name|notify_baton
argument_list|,
name|notify
argument_list|,
name|subpool
argument_list|)
expr_stmt|;
name|notify
operator|->
name|action
operator|=
name|svn_repos_notify_recover_start
expr_stmt|;
name|notify_func
argument_list|(
name|notify_baton
argument_list|,
name|notify
argument_list|,
name|subpool
argument_list|)
expr_stmt|;
block|}
comment|/* Recover the database to a consistent state. */
name|SVN_ERR
argument_list|(
name|svn_fs_recover
argument_list|(
name|repos
operator|->
name|db_path
argument_list|,
name|cancel_func
argument_list|,
name|cancel_baton
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Close shop and free the subpool, to release the exclusive lock. */
name|svn_pool_destroy
argument_list|(
name|subpool
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_struct
struct|struct
name|freeze_baton_t
block|{
name|apr_array_header_t
modifier|*
name|paths
decl_stmt|;
name|int
name|counter
decl_stmt|;
name|svn_repos_freeze_func_t
name|freeze_func
decl_stmt|;
name|void
modifier|*
name|freeze_baton
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|svn_error_t
modifier|*
name|multi_freeze
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|struct
name|freeze_baton_t
modifier|*
name|fb
init|=
name|baton
decl_stmt|;
if|if
condition|(
name|fb
operator|->
name|counter
operator|==
name|fb
operator|->
name|paths
operator|->
name|nelts
condition|)
block|{
name|SVN_ERR
argument_list|(
name|fb
operator|->
name|freeze_func
argument_list|(
name|fb
operator|->
name|freeze_baton
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
else|else
block|{
comment|/* Using a subpool as the only way to unlock the repos lock used          by BDB is to clear the pool used to take the lock. */
name|apr_pool_t
modifier|*
name|subpool
init|=
name|svn_pool_create
argument_list|(
name|pool
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|path
init|=
name|APR_ARRAY_IDX
argument_list|(
name|fb
operator|->
name|paths
argument_list|,
name|fb
operator|->
name|counter
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|;
name|svn_repos_t
modifier|*
name|repos
decl_stmt|;
operator|++
name|fb
operator|->
name|counter
expr_stmt|;
name|SVN_ERR
argument_list|(
name|get_repos
argument_list|(
operator|&
name|repos
argument_list|,
name|path
argument_list|,
name|TRUE
comment|/* exclusive (only applies to BDB) */
argument_list|,
name|FALSE
comment|/* non-blocking */
argument_list|,
name|FALSE
comment|/* open-fs */
argument_list|,
name|NULL
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|repos
operator|->
name|fs_type
argument_list|,
name|SVN_FS_TYPE_BDB
argument_list|)
operator|==
literal|0
condition|)
block|{
name|svn_error_t
modifier|*
name|err
init|=
name|multi_freeze
argument_list|(
name|fb
argument_list|,
name|subpool
argument_list|)
decl_stmt|;
name|svn_pool_destroy
argument_list|(
name|subpool
argument_list|)
expr_stmt|;
return|return
name|err
return|;
block|}
else|else
block|{
name|SVN_ERR
argument_list|(
name|svn_fs_open
argument_list|(
operator|&
name|repos
operator|->
name|fs
argument_list|,
name|repos
operator|->
name|db_path
argument_list|,
name|NULL
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_fs_freeze
argument_list|(
name|svn_repos_fs
argument_list|(
name|repos
argument_list|)
argument_list|,
name|multi_freeze
argument_list|,
name|fb
argument_list|,
name|subpool
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|svn_pool_destroy
argument_list|(
name|subpool
argument_list|)
expr_stmt|;
block|}
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* For BDB we fall back on BDB's repos layer lock which means that the    repository is unreadable while frozen.     For FSFS we delegate to the FS layer which uses the FSFS write-lock    and an SQLite reserved lock which means the repository is readable    while frozen. */
end_comment

begin_function
name|svn_error_t
modifier|*
name|svn_repos_freeze
parameter_list|(
name|apr_array_header_t
modifier|*
name|paths
parameter_list|,
name|svn_repos_freeze_func_t
name|freeze_func
parameter_list|,
name|void
modifier|*
name|freeze_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|struct
name|freeze_baton_t
name|fb
decl_stmt|;
name|fb
operator|.
name|paths
operator|=
name|paths
expr_stmt|;
name|fb
operator|.
name|counter
operator|=
literal|0
expr_stmt|;
name|fb
operator|.
name|freeze_func
operator|=
name|freeze_func
expr_stmt|;
name|fb
operator|.
name|freeze_baton
operator|=
name|freeze_baton
expr_stmt|;
name|SVN_ERR
argument_list|(
name|multi_freeze
argument_list|(
operator|&
name|fb
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_db_logfiles
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|logfiles
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|svn_boolean_t
name|only_unused
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_repos_t
modifier|*
name|repos
decl_stmt|;
name|int
name|i
decl_stmt|;
name|SVN_ERR
argument_list|(
name|get_repos
argument_list|(
operator|&
name|repos
argument_list|,
name|path
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
comment|/* Do not open fs. */
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_fs_berkeley_logfiles
argument_list|(
name|logfiles
argument_list|,
name|svn_repos_db_env
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|,
name|only_unused
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Loop, printing log files. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
operator|(
operator|*
name|logfiles
operator|)
operator|->
name|nelts
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|char
modifier|*
modifier|*
name|log_file
init|=
operator|&
operator|(
name|APR_ARRAY_IDX
argument_list|(
operator|*
name|logfiles
argument_list|,
name|i
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
operator|)
decl_stmt|;
operator|*
name|log_file
operator|=
name|svn_dirent_join
argument_list|(
name|SVN_REPOS__DB_DIR
argument_list|,
operator|*
name|log_file
argument_list|,
name|pool
argument_list|)
expr_stmt|;
block|}
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Baton for hotcopy_structure(). */
end_comment

begin_struct
struct|struct
name|hotcopy_ctx_t
block|{
specifier|const
name|char
modifier|*
name|dest
decl_stmt|;
comment|/* target location to construct */
name|size_t
name|src_len
decl_stmt|;
comment|/* len of the source path*/
comment|/* As in svn_repos_hotcopy2() */
name|svn_boolean_t
name|incremental
decl_stmt|;
name|svn_cancel_func_t
name|cancel_func
decl_stmt|;
name|void
modifier|*
name|cancel_baton
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Copy the repository structure of PATH to BATON->DEST, with exception of  * @c SVN_REPOS__DB_DIR, @c SVN_REPOS__LOCK_DIR and @c SVN_REPOS__FORMAT;  * those directories and files are handled separately.  *  * BATON is a (struct hotcopy_ctx_t *).  BATON->SRC_LEN is the length  * of PATH.  *  * Implements svn_io_walk_func_t.  */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|hotcopy_structure
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|apr_finfo_t
modifier|*
name|finfo
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|struct
name|hotcopy_ctx_t
modifier|*
name|ctx
init|=
name|baton
decl_stmt|;
specifier|const
name|char
modifier|*
name|sub_path
decl_stmt|;
specifier|const
name|char
modifier|*
name|target
decl_stmt|;
if|if
condition|(
name|ctx
operator|->
name|cancel_func
condition|)
name|SVN_ERR
argument_list|(
name|ctx
operator|->
name|cancel_func
argument_list|(
name|ctx
operator|->
name|cancel_baton
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|path
argument_list|)
operator|==
name|ctx
operator|->
name|src_len
condition|)
block|{
name|sub_path
operator|=
literal|""
expr_stmt|;
block|}
else|else
block|{
name|sub_path
operator|=
operator|&
name|path
index|[
name|ctx
operator|->
name|src_len
operator|+
literal|1
index|]
expr_stmt|;
comment|/* Check if we are inside db directory and if so skip it */
if|if
condition|(
name|svn_path_compare_paths
argument_list|(
name|svn_dirent_get_longest_ancestor
argument_list|(
name|SVN_REPOS__DB_DIR
argument_list|,
name|sub_path
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__DB_DIR
argument_list|)
operator|==
literal|0
condition|)
return|return
name|SVN_NO_ERROR
return|;
if|if
condition|(
name|svn_path_compare_paths
argument_list|(
name|svn_dirent_get_longest_ancestor
argument_list|(
name|SVN_REPOS__LOCK_DIR
argument_list|,
name|sub_path
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__LOCK_DIR
argument_list|)
operator|==
literal|0
condition|)
return|return
name|SVN_NO_ERROR
return|;
if|if
condition|(
name|svn_path_compare_paths
argument_list|(
name|svn_dirent_get_longest_ancestor
argument_list|(
name|SVN_REPOS__FORMAT
argument_list|,
name|sub_path
argument_list|,
name|pool
argument_list|)
argument_list|,
name|SVN_REPOS__FORMAT
argument_list|)
operator|==
literal|0
condition|)
return|return
name|SVN_NO_ERROR
return|;
block|}
name|target
operator|=
name|svn_dirent_join
argument_list|(
name|ctx
operator|->
name|dest
argument_list|,
name|sub_path
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|finfo
operator|->
name|filetype
operator|==
name|APR_DIR
condition|)
block|{
name|svn_error_t
modifier|*
name|err
decl_stmt|;
name|err
operator|=
name|create_repos_dir
argument_list|(
name|target
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|incremental
operator|&&
name|err
operator|&&
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_DIR_NOT_EMPTY
condition|)
block|{
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|err
operator|=
name|SVN_NO_ERROR
expr_stmt|;
block|}
return|return
name|svn_error_trace
argument_list|(
name|err
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|finfo
operator|->
name|filetype
operator|==
name|APR_REG
condition|)
return|return
name|svn_io_copy_file
argument_list|(
name|path
argument_list|,
name|target
argument_list|,
name|TRUE
argument_list|,
name|pool
argument_list|)
return|;
elseif|else
if|if
condition|(
name|finfo
operator|->
name|filetype
operator|==
name|APR_LNK
condition|)
return|return
name|svn_io_copy_link
argument_list|(
name|path
argument_list|,
name|target
argument_list|,
name|pool
argument_list|)
return|;
else|else
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/** Obtain a lock on db logs lock file. Create one if it does not exist.  */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|lock_db_logs_file
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
name|svn_boolean_t
name|exclusive
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|lock_file
init|=
name|svn_repos_db_logs_lockfile
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
decl_stmt|;
comment|/* Try to create a lock file, in case if it is missing. As in case of the      repositories created before hotcopy functionality.  */
name|svn_error_clear
argument_list|(
name|create_db_logs_lock
argument_list|(
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|svn_io_file_lock2
argument_list|(
name|lock_file
argument_list|,
name|exclusive
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Make a copy of a repository with hot backup of fs. */
end_comment

begin_function
name|svn_error_t
modifier|*
name|svn_repos_hotcopy2
parameter_list|(
specifier|const
name|char
modifier|*
name|src_path
parameter_list|,
specifier|const
name|char
modifier|*
name|dst_path
parameter_list|,
name|svn_boolean_t
name|clean_logs
parameter_list|,
name|svn_boolean_t
name|incremental
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
block|{
name|svn_repos_t
modifier|*
name|src_repos
decl_stmt|;
name|svn_repos_t
modifier|*
name|dst_repos
decl_stmt|;
name|struct
name|hotcopy_ctx_t
name|hotcopy_context
decl_stmt|;
name|svn_error_t
modifier|*
name|err
decl_stmt|;
specifier|const
name|char
modifier|*
name|src_abspath
decl_stmt|;
specifier|const
name|char
modifier|*
name|dst_abspath
decl_stmt|;
name|SVN_ERR
argument_list|(
name|svn_dirent_get_absolute
argument_list|(
operator|&
name|src_abspath
argument_list|,
name|src_path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_dirent_get_absolute
argument_list|(
operator|&
name|dst_abspath
argument_list|,
name|dst_path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|src_abspath
argument_list|,
name|dst_abspath
argument_list|)
operator|==
literal|0
condition|)
return|return
name|svn_error_create
argument_list|(
name|SVN_ERR_INCORRECT_PARAMS
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Hotcopy source and destination are equal"
argument_list|)
argument_list|)
return|;
comment|/* Try to open original repository */
name|SVN_ERR
argument_list|(
name|get_repos
argument_list|(
operator|&
name|src_repos
argument_list|,
name|src_abspath
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
comment|/* don't try to open the db yet. */
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* If we are going to clean logs, then get an exclusive lock on      db-logs.lock, to ensure that no one else will work with logs.       If we are just copying, then get a shared lock to ensure that      no one else will clean logs while we copying them */
name|SVN_ERR
argument_list|(
name|lock_db_logs_file
argument_list|(
name|src_repos
argument_list|,
name|clean_logs
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Copy the repository to a new path, with exception of      specially handled directories */
name|hotcopy_context
operator|.
name|dest
operator|=
name|dst_abspath
expr_stmt|;
name|hotcopy_context
operator|.
name|src_len
operator|=
name|strlen
argument_list|(
name|src_abspath
argument_list|)
expr_stmt|;
name|hotcopy_context
operator|.
name|incremental
operator|=
name|incremental
expr_stmt|;
name|hotcopy_context
operator|.
name|cancel_func
operator|=
name|cancel_func
expr_stmt|;
name|hotcopy_context
operator|.
name|cancel_baton
operator|=
name|cancel_baton
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_io_dir_walk2
argument_list|(
name|src_abspath
argument_list|,
literal|0
argument_list|,
name|hotcopy_structure
argument_list|,
operator|&
name|hotcopy_context
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Prepare dst_repos object so that we may create locks,      so that we may open repository */
name|dst_repos
operator|=
name|create_svn_repos_t
argument_list|(
name|dst_abspath
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|dst_repos
operator|->
name|fs_type
operator|=
name|src_repos
operator|->
name|fs_type
expr_stmt|;
name|dst_repos
operator|->
name|format
operator|=
name|src_repos
operator|->
name|format
expr_stmt|;
name|err
operator|=
name|create_locks
argument_list|(
name|dst_repos
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
if|if
condition|(
name|incremental
operator|&&
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_DIR_NOT_EMPTY
condition|)
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
else|else
return|return
name|svn_error_trace
argument_list|(
name|err
argument_list|)
return|;
block|}
name|err
operator|=
name|svn_io_dir_make_sgid
argument_list|(
name|dst_repos
operator|->
name|db_path
argument_list|,
name|APR_OS_DEFAULT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
if|if
condition|(
name|incremental
operator|&&
name|APR_STATUS_IS_EEXIST
argument_list|(
name|err
operator|->
name|apr_err
argument_list|)
condition|)
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
else|else
return|return
name|svn_error_trace
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* Exclusively lock the new repository.      No one should be accessing it at the moment */
name|SVN_ERR
argument_list|(
name|lock_repos
argument_list|(
name|dst_repos
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_fs_hotcopy2
argument_list|(
name|src_repos
operator|->
name|db_path
argument_list|,
name|dst_repos
operator|->
name|db_path
argument_list|,
name|clean_logs
argument_list|,
name|incremental
argument_list|,
name|cancel_func
argument_list|,
name|cancel_baton
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Destination repository is ready.  Stamp it with a format number. */
return|return
name|svn_io_write_version_file
argument_list|(
name|svn_dirent_join
argument_list|(
name|dst_repos
operator|->
name|path
argument_list|,
name|SVN_REPOS__FORMAT
argument_list|,
name|pool
argument_list|)
argument_list|,
name|dst_repos
operator|->
name|format
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_hotcopy
parameter_list|(
specifier|const
name|char
modifier|*
name|src_path
parameter_list|,
specifier|const
name|char
modifier|*
name|dst_path
parameter_list|,
name|svn_boolean_t
name|clean_logs
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
return|return
name|svn_error_trace
argument_list|(
name|svn_repos_hotcopy2
argument_list|(
name|src_path
argument_list|,
name|dst_path
argument_list|,
name|clean_logs
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return the library version number. */
end_comment

begin_function
specifier|const
name|svn_version_t
modifier|*
name|svn_repos_version
parameter_list|(
name|void
parameter_list|)
block|{
name|SVN_VERSION_BODY
expr_stmt|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_stat
parameter_list|(
name|svn_dirent_t
modifier|*
modifier|*
name|dirent
parameter_list|,
name|svn_fs_root_t
modifier|*
name|root
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_node_kind_t
name|kind
decl_stmt|;
name|svn_dirent_t
modifier|*
name|ent
decl_stmt|;
specifier|const
name|char
modifier|*
name|datestring
decl_stmt|;
name|apr_hash_t
modifier|*
name|prophash
decl_stmt|;
name|SVN_ERR
argument_list|(
name|svn_fs_check_path
argument_list|(
operator|&
name|kind
argument_list|,
name|root
argument_list|,
name|path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|kind
operator|==
name|svn_node_none
condition|)
block|{
operator|*
name|dirent
operator|=
name|NULL
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
name|ent
operator|=
name|svn_dirent_create
argument_list|(
name|pool
argument_list|)
expr_stmt|;
name|ent
operator|->
name|kind
operator|=
name|kind
expr_stmt|;
if|if
condition|(
name|kind
operator|==
name|svn_node_file
condition|)
name|SVN_ERR
argument_list|(
name|svn_fs_file_length
argument_list|(
operator|&
operator|(
name|ent
operator|->
name|size
operator|)
argument_list|,
name|root
argument_list|,
name|path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_fs_node_proplist
argument_list|(
operator|&
name|prophash
argument_list|,
name|root
argument_list|,
name|path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|apr_hash_count
argument_list|(
name|prophash
argument_list|)
operator|>
literal|0
condition|)
name|ent
operator|->
name|has_props
operator|=
name|TRUE
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_repos_get_committed_info
argument_list|(
operator|&
operator|(
name|ent
operator|->
name|created_rev
operator|)
argument_list|,
operator|&
name|datestring
argument_list|,
operator|&
operator|(
name|ent
operator|->
name|last_author
operator|)
argument_list|,
name|root
argument_list|,
name|path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|datestring
condition|)
name|SVN_ERR
argument_list|(
name|svn_time_from_cstring
argument_list|(
operator|&
operator|(
name|ent
operator|->
name|time
operator|)
argument_list|,
name|datestring
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|dirent
operator|=
name|ent
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos_remember_client_capabilities
parameter_list|(
name|svn_repos_t
modifier|*
name|repos
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|capabilities
parameter_list|)
block|{
name|repos
operator|->
name|client_capabilities
operator|=
name|capabilities
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_function
name|svn_error_t
modifier|*
name|svn_repos__fs_type
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|fs_type
parameter_list|,
specifier|const
name|char
modifier|*
name|repos_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_repos_t
name|repos
decl_stmt|;
name|repos
operator|.
name|path
operator|=
operator|(
name|char
operator|*
operator|)
name|repos_path
expr_stmt|;
name|SVN_ERR
argument_list|(
name|check_repos_format
argument_list|(
operator|&
name|repos
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|svn_fs_type
argument_list|(
name|fs_type
argument_list|,
name|svn_dirent_join
argument_list|(
name|repos_path
argument_list|,
name|SVN_REPOS__DB_DIR
argument_list|,
name|pool
argument_list|)
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

end_unit

