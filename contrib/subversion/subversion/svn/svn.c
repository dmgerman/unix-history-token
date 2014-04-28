begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * svn.c:  Subversion command line client main file.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_comment
comment|/* ==================================================================== */
end_comment

begin_escape
end_escape

begin_comment
comment|/*** Includes. ***/
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<apr_strings.h>
end_include

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_include
include|#
directive|include
file|<apr_general.h>
end_include

begin_include
include|#
directive|include
file|<apr_signal.h>
end_include

begin_include
include|#
directive|include
file|"svn_cmdline.h"
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_wc.h"
end_include

begin_include
include|#
directive|include
file|"svn_client.h"
end_include

begin_include
include|#
directive|include
file|"svn_config.h"
end_include

begin_include
include|#
directive|include
file|"svn_string.h"
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
file|"svn_delta.h"
end_include

begin_include
include|#
directive|include
file|"svn_diff.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_include
include|#
directive|include
file|"svn_opt.h"
end_include

begin_include
include|#
directive|include
file|"svn_utf.h"
end_include

begin_include
include|#
directive|include
file|"svn_auth.h"
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
file|"cl.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_opt_private.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_cmdline_private.h"
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

begin_escape
end_escape

begin_comment
comment|/*** Option Processing ***/
end_comment

begin_comment
comment|/* Add an identifier here for long options that don't have a short    option. Options that have both long and short options should just    use the short option letter as identifier.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|svn_cl__longopt_t
block|{
name|opt_auth_password
init|=
name|SVN_OPT_FIRST_LONGOPT_ID
block|,
name|opt_auth_username
block|,
name|opt_autoprops
block|,
name|opt_changelist
block|,
name|opt_config_dir
block|,
name|opt_config_options
block|,
comment|/* diff options */
name|opt_diff_cmd
block|,
name|opt_internal_diff
block|,
name|opt_no_diff_added
block|,
name|opt_no_diff_deleted
block|,
name|opt_show_copies_as_adds
block|,
name|opt_notice_ancestry
block|,
name|opt_summarize
block|,
name|opt_use_git_diff_format
block|,
name|opt_ignore_properties
block|,
name|opt_properties_only
block|,
name|opt_patch_compatible
block|,
comment|/* end of diff options */
name|opt_dry_run
block|,
name|opt_editor_cmd
block|,
name|opt_encoding
block|,
name|opt_force_log
block|,
name|opt_force
block|,
name|opt_keep_changelists
block|,
name|opt_ignore_ancestry
block|,
name|opt_ignore_externals
block|,
name|opt_incremental
block|,
name|opt_merge_cmd
block|,
name|opt_native_eol
block|,
name|opt_new_cmd
block|,
name|opt_no_auth_cache
block|,
name|opt_no_autoprops
block|,
name|opt_no_ignore
block|,
name|opt_no_unlock
block|,
name|opt_non_interactive
block|,
name|opt_force_interactive
block|,
name|opt_old_cmd
block|,
name|opt_record_only
block|,
name|opt_relocate
block|,
name|opt_remove
block|,
name|opt_revprop
block|,
name|opt_stop_on_copy
block|,
name|opt_strict
block|,
name|opt_targets
block|,
name|opt_depth
block|,
name|opt_set_depth
block|,
name|opt_version
block|,
name|opt_xml
block|,
name|opt_keep_local
block|,
name|opt_with_revprop
block|,
name|opt_with_all_revprops
block|,
name|opt_with_no_revprops
block|,
name|opt_parents
block|,
name|opt_accept
block|,
name|opt_show_revs
block|,
name|opt_reintegrate
block|,
name|opt_trust_server_cert
block|,
name|opt_strip
block|,
name|opt_ignore_keywords
block|,
name|opt_reverse_diff
block|,
name|opt_ignore_whitespace
block|,
name|opt_diff
block|,
name|opt_allow_mixed_revisions
block|,
name|opt_include_externals
block|,
name|opt_show_inherited_props
block|,
name|opt_search
block|,
name|opt_search_and
block|}
name|svn_cl__longopt_t
typedef|;
end_typedef

begin_comment
comment|/* Option codes and descriptions for the command line client.  *  * The entire list must be terminated with an entry of nulls.  */
end_comment

begin_decl_stmt
specifier|const
name|apr_getopt_option_t
name|svn_cl__options
index|[]
init|=
block|{
block|{
literal|"force"
block|,
name|opt_force
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"force operation to run"
argument_list|)
block|}
block|,
block|{
literal|"force-log"
block|,
name|opt_force_log
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"force validity of log message source"
argument_list|)
block|}
block|,
block|{
literal|"help"
block|,
literal|'h'
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"show help on a subcommand"
argument_list|)
block|}
block|,
block|{
name|NULL
block|,
literal|'?'
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"show help on a subcommand"
argument_list|)
block|}
block|,
block|{
literal|"message"
block|,
literal|'m'
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"specify log message ARG"
argument_list|)
block|}
block|,
block|{
literal|"quiet"
block|,
literal|'q'
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"print nothing, or only summary information"
argument_list|)
block|}
block|,
block|{
literal|"recursive"
block|,
literal|'R'
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"descend recursively, same as --depth=infinity"
argument_list|)
block|}
block|,
block|{
literal|"non-recursive"
block|,
literal|'N'
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"obsolete; try --depth=files or --depth=immediates"
argument_list|)
block|}
block|,
block|{
literal|"change"
block|,
literal|'c'
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"the change made by revision ARG (like -r ARG-1:ARG)\n"
literal|"                             "
literal|"If ARG is negative this is like -r ARG:ARG-1\n"
literal|"                             "
literal|"If ARG is of the form ARG1-ARG2 then this is like\n"
literal|"                             "
literal|"ARG1:ARG2, where ARG1 is inclusive"
argument_list|)
block|}
block|,
block|{
literal|"revision"
block|,
literal|'r'
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"ARG (some commands also take ARG1:ARG2 range)\n"
literal|"                             "
literal|"A revision argument can be one of:\n"
literal|"                             "
literal|"   NUMBER       revision number\n"
literal|"                             "
literal|"   '{' DATE '}' revision at start of the date\n"
literal|"                             "
literal|"   'HEAD'       latest in repository\n"
literal|"                             "
literal|"   'BASE'       base rev of item's working copy\n"
literal|"                             "
literal|"   'COMMITTED'  last commit at or before BASE\n"
literal|"                             "
literal|"   'PREV'       revision just before COMMITTED"
argument_list|)
block|}
block|,
block|{
literal|"file"
block|,
literal|'F'
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"read log message from file ARG"
argument_list|)
block|}
block|,
block|{
literal|"incremental"
block|,
name|opt_incremental
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"give output suitable for concatenation"
argument_list|)
block|}
block|,
block|{
literal|"encoding"
block|,
name|opt_encoding
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"treat value as being in charset encoding ARG"
argument_list|)
block|}
block|,
block|{
literal|"version"
block|,
name|opt_version
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"show program version information"
argument_list|)
block|}
block|,
block|{
literal|"verbose"
block|,
literal|'v'
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"print extra information"
argument_list|)
block|}
block|,
block|{
literal|"show-updates"
block|,
literal|'u'
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"display update information"
argument_list|)
block|}
block|,
block|{
literal|"username"
block|,
name|opt_auth_username
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"specify a username ARG"
argument_list|)
block|}
block|,
block|{
literal|"password"
block|,
name|opt_auth_password
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"specify a password ARG"
argument_list|)
block|}
block|,
block|{
literal|"extensions"
block|,
literal|'x'
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"Specify differencing options for external diff or\n"
literal|"                             "
literal|"internal diff or blame. Default: '-u'. Options are\n"
literal|"                             "
literal|"separated by spaces. Internal diff and blame take:\n"
literal|"                             "
literal|"  -u, --unified: Show 3 lines of unified context\n"
literal|"                             "
literal|"  -b, --ignore-space-change: Ignore changes in\n"
literal|"                             "
literal|"    amount of white space\n"
literal|"                             "
literal|"  -w, --ignore-all-space: Ignore all white space\n"
literal|"                             "
literal|"  --ignore-eol-style: Ignore changes in EOL style\n"
literal|"                             "
literal|"  -p, --show-c-function: Show C function name"
argument_list|)
block|}
block|,
block|{
literal|"targets"
block|,
name|opt_targets
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"pass contents of file ARG as additional args"
argument_list|)
block|}
block|,
block|{
literal|"depth"
block|,
name|opt_depth
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"limit operation by depth ARG ('empty', 'files',\n"
literal|"                             "
literal|"'immediates', or 'infinity')"
argument_list|)
block|}
block|,
block|{
literal|"set-depth"
block|,
name|opt_set_depth
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"set new working copy depth to ARG ('exclude',\n"
literal|"                             "
literal|"'empty', 'files', 'immediates', or 'infinity')"
argument_list|)
block|}
block|,
block|{
literal|"xml"
block|,
name|opt_xml
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"output in XML"
argument_list|)
block|}
block|,
block|{
literal|"strict"
block|,
name|opt_strict
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"use strict semantics"
argument_list|)
block|}
block|,
block|{
literal|"stop-on-copy"
block|,
name|opt_stop_on_copy
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"do not cross copies while traversing history"
argument_list|)
block|}
block|,
block|{
literal|"no-ignore"
block|,
name|opt_no_ignore
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"disregard default and svn:ignore and\n"
literal|"                             "
literal|"svn:global-ignores property ignores"
argument_list|)
block|}
block|,
block|{
literal|"no-auth-cache"
block|,
name|opt_no_auth_cache
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"do not cache authentication tokens"
argument_list|)
block|}
block|,
block|{
literal|"trust-server-cert"
block|,
name|opt_trust_server_cert
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"accept SSL server certificates from unknown\n"
literal|"                             "
literal|"certificate authorities without prompting (but only\n"
literal|"                             "
literal|"with '--non-interactive')"
argument_list|)
block|}
block|,
block|{
literal|"non-interactive"
block|,
name|opt_non_interactive
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"do no interactive prompting (default is to prompt\n"
literal|"                             "
literal|"only if standard input is a terminal device)"
argument_list|)
block|}
block|,
block|{
literal|"force-interactive"
block|,
name|opt_force_interactive
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"do interactive prompting even if standard input\n"
literal|"                             "
literal|"is not a terminal device"
argument_list|)
block|}
block|,
block|{
literal|"dry-run"
block|,
name|opt_dry_run
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"try operation but make no changes"
argument_list|)
block|}
block|,
block|{
literal|"ignore-ancestry"
block|,
name|opt_ignore_ancestry
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"disable merge tracking; diff nodes as if related"
argument_list|)
block|}
block|,
block|{
literal|"ignore-externals"
block|,
name|opt_ignore_externals
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"ignore externals definitions"
argument_list|)
block|}
block|,
block|{
literal|"diff3-cmd"
block|,
name|opt_merge_cmd
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"use ARG as merge command"
argument_list|)
block|}
block|,
block|{
literal|"editor-cmd"
block|,
name|opt_editor_cmd
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"use ARG as external editor"
argument_list|)
block|}
block|,
block|{
literal|"record-only"
block|,
name|opt_record_only
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"merge only mergeinfo differences"
argument_list|)
block|}
block|,
block|{
literal|"old"
block|,
name|opt_old_cmd
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"use ARG as the older target"
argument_list|)
block|}
block|,
block|{
literal|"new"
block|,
name|opt_new_cmd
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"use ARG as the newer target"
argument_list|)
block|}
block|,
block|{
literal|"revprop"
block|,
name|opt_revprop
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"operate on a revision property (use with -r)"
argument_list|)
block|}
block|,
block|{
literal|"relocate"
block|,
name|opt_relocate
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"relocate via URL-rewriting"
argument_list|)
block|}
block|,
block|{
literal|"config-dir"
block|,
name|opt_config_dir
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"read user configuration files from directory ARG"
argument_list|)
block|}
block|,
block|{
literal|"config-option"
block|,
name|opt_config_options
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"set user configuration option in the format:\n"
literal|"                             "
literal|"    FILE:SECTION:OPTION=[VALUE]\n"
literal|"                             "
literal|"For example:\n"
literal|"                             "
literal|"    servers:global:http-library=serf"
argument_list|)
block|}
block|,
block|{
literal|"auto-props"
block|,
name|opt_autoprops
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"enable automatic properties"
argument_list|)
block|}
block|,
block|{
literal|"no-auto-props"
block|,
name|opt_no_autoprops
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"disable automatic properties"
argument_list|)
block|}
block|,
block|{
literal|"native-eol"
block|,
name|opt_native_eol
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"use a different EOL marker than the standard\n"
literal|"                             "
literal|"system marker for files with the svn:eol-style\n"
literal|"                             "
literal|"property set to 'native'.\n"
literal|"                             "
literal|"ARG may be one of 'LF', 'CR', 'CRLF'"
argument_list|)
block|}
block|,
block|{
literal|"limit"
block|,
literal|'l'
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"maximum number of log entries"
argument_list|)
block|}
block|,
block|{
literal|"no-unlock"
block|,
name|opt_no_unlock
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"don't unlock the targets"
argument_list|)
block|}
block|,
block|{
literal|"remove"
block|,
name|opt_remove
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"remove changelist association"
argument_list|)
block|}
block|,
block|{
literal|"changelist"
block|,
name|opt_changelist
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"operate only on members of changelist ARG"
argument_list|)
block|}
block|,
block|{
literal|"keep-changelists"
block|,
name|opt_keep_changelists
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"don't delete changelists after commit"
argument_list|)
block|}
block|,
block|{
literal|"keep-local"
block|,
name|opt_keep_local
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"keep path in working copy"
argument_list|)
block|}
block|,
block|{
literal|"with-all-revprops"
block|,
name|opt_with_all_revprops
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"retrieve all revision properties"
argument_list|)
block|}
block|,
block|{
literal|"with-no-revprops"
block|,
name|opt_with_no_revprops
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"retrieve no revision properties"
argument_list|)
block|}
block|,
block|{
literal|"with-revprop"
block|,
name|opt_with_revprop
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"set revision property ARG in new revision\n"
literal|"                             "
literal|"using the name[=value] format"
argument_list|)
block|}
block|,
block|{
literal|"parents"
block|,
name|opt_parents
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"make intermediate directories"
argument_list|)
block|}
block|,
block|{
literal|"use-merge-history"
block|,
literal|'g'
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"use/display additional information from merge\n"
literal|"                             "
literal|"history"
argument_list|)
block|}
block|,
block|{
literal|"accept"
block|,
name|opt_accept
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"specify automatic conflict resolution action\n"
literal|"                             "
literal|"('postpone', 'working', 'base', 'mine-conflict',\n"
literal|"                             "
literal|"'theirs-conflict', 'mine-full', 'theirs-full',\n"
literal|"                             "
literal|"'edit', 'launch')\n"
literal|"                             "
literal|"(shorthand: 'p', 'mc', 'tc', 'mf', 'tf', 'e', 'l')"
argument_list|)
block|}
block|,
block|{
literal|"show-revs"
block|,
name|opt_show_revs
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"specify which collection of revisions to display\n"
literal|"                             "
literal|"('merged', 'eligible')"
argument_list|)
block|}
block|,
block|{
literal|"reintegrate"
block|,
name|opt_reintegrate
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"deprecated"
argument_list|)
block|}
block|,
block|{
literal|"strip"
block|,
name|opt_strip
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"number of leading path components to strip from\n"
literal|"                             "
literal|"paths parsed from the patch file. --strip 0\n"
literal|"                             "
literal|"is the default and leaves paths unmodified.\n"
literal|"                             "
literal|"--strip 1 would change the path\n"
literal|"                             "
literal|"'doc/fudge/crunchy.html' to 'fudge/crunchy.html'.\n"
literal|"                             "
literal|"--strip 2 would leave just 'crunchy.html'\n"
literal|"                             "
literal|"The expected component separator is '/' on all\n"
literal|"                             "
literal|"platforms. A leading '/' counts as one component."
argument_list|)
block|}
block|,
block|{
literal|"ignore-keywords"
block|,
name|opt_ignore_keywords
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"don't expand keywords"
argument_list|)
block|}
block|,
block|{
literal|"reverse-diff"
block|,
name|opt_reverse_diff
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"apply the unidiff in reverse"
argument_list|)
block|}
block|,
block|{
literal|"ignore-whitespace"
block|,
name|opt_ignore_whitespace
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"ignore whitespace during pattern matching"
argument_list|)
block|}
block|,
block|{
literal|"diff"
block|,
name|opt_diff
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"produce diff output"
argument_list|)
block|}
block|,
comment|/* maps to show_diff */
comment|/* diff options */
block|{
literal|"diff-cmd"
block|,
name|opt_diff_cmd
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"use ARG as diff command"
argument_list|)
block|}
block|,
block|{
literal|"internal-diff"
block|,
name|opt_internal_diff
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"override diff-cmd specified in config file"
argument_list|)
block|}
block|,
block|{
literal|"no-diff-added"
block|,
name|opt_no_diff_added
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"do not print differences for added files"
argument_list|)
block|}
block|,
block|{
literal|"no-diff-deleted"
block|,
name|opt_no_diff_deleted
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"do not print differences for deleted files"
argument_list|)
block|}
block|,
block|{
literal|"show-copies-as-adds"
block|,
name|opt_show_copies_as_adds
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"don't diff copied or moved files with their source"
argument_list|)
block|}
block|,
block|{
literal|"notice-ancestry"
block|,
name|opt_notice_ancestry
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"diff unrelated nodes as delete and add"
argument_list|)
block|}
block|,
block|{
literal|"summarize"
block|,
name|opt_summarize
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"show a summary of the results"
argument_list|)
block|}
block|,
block|{
literal|"git"
block|,
name|opt_use_git_diff_format
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"use git's extended diff format"
argument_list|)
block|}
block|,
block|{
literal|"ignore-properties"
block|,
name|opt_ignore_properties
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"ignore properties during the operation"
argument_list|)
block|}
block|,
block|{
literal|"properties-only"
block|,
name|opt_properties_only
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"show only properties during the operation"
argument_list|)
block|}
block|,
block|{
literal|"patch-compatible"
block|,
name|opt_patch_compatible
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"generate diff suitable for generic third-party\n"
literal|"                             "
literal|"patch tools; currently the same as\n"
literal|"                             "
literal|"--show-copies-as-adds --ignore-properties"
argument_list|)
block|}
block|,
comment|/* end of diff options */
block|{
literal|"allow-mixed-revisions"
block|,
name|opt_allow_mixed_revisions
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"Allow operation on mixed-revision working copy.\n"
literal|"                             "
literal|"Use of this option is not recommended!\n"
literal|"                             "
literal|"Please run 'svn update' instead."
argument_list|)
block|}
block|,
block|{
literal|"include-externals"
block|,
name|opt_include_externals
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"Also commit file and dir externals reached by\n"
literal|"                             "
literal|"recursion. This does not include externals with a\n"
literal|"                             "
literal|"fixed revision. (See the svn:externals property)"
argument_list|)
block|}
block|,
block|{
literal|"show-inherited-props"
block|,
name|opt_show_inherited_props
block|,
literal|0
block|,
name|N_
argument_list|(
literal|"retrieve target's inherited properties"
argument_list|)
block|}
block|,
block|{
literal|"search"
block|,
name|opt_search
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"use ARG as search pattern (glob syntax)"
argument_list|)
block|}
block|,
block|{
literal|"search-and"
block|,
name|opt_search_and
block|,
literal|1
block|,
name|N_
argument_list|(
literal|"combine ARG with the previous search pattern"
argument_list|)
block|}
block|,
comment|/* Long-opt Aliases    *    * These have NULL desriptions, but an option code that matches some    * other option (whose description should probably mention its aliases).   */
block|{
literal|"cl"
block|,
name|opt_changelist
block|,
literal|1
block|,
name|NULL
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*** Command dispatch. ***/
end_comment

begin_comment
comment|/* Our array of available subcommands.  *  * The entire list must be terminated with an entry of nulls.  *  * In most of the help text "PATH" is used where a working copy path is  * required, "URL" where a repository URL is required and "TARGET" when  * either a path or a url can be used.  Hmm, should this be part of the  * help text?  */
end_comment

begin_comment
comment|/* Options that apply to all commands.  (While not every command may    currently require authentication or be interactive, allowing every    command to take these arguments allows scripts to just pass them    willy-nilly to every invocation of 'svn') . */
end_comment

begin_decl_stmt
specifier|const
name|int
name|svn_cl__global_options
index|[]
init|=
block|{
name|opt_auth_username
block|,
name|opt_auth_password
block|,
name|opt_no_auth_cache
block|,
name|opt_non_interactive
block|,
name|opt_force_interactive
block|,
name|opt_trust_server_cert
block|,
name|opt_config_dir
block|,
name|opt_config_options
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Options for giving a log message.  (Some of these also have other uses.)  */
end_comment

begin_define
define|#
directive|define
name|SVN_CL__LOG_MSG_OPTIONS
value|'m', 'F', \                                 opt_force_log, \                                 opt_editor_cmd, \                                 opt_encoding, \                                 opt_with_revprop
end_define

begin_decl_stmt
specifier|const
name|svn_opt_subcommand_desc2_t
name|svn_cl__cmd_table
index|[]
init|=
block|{
block|{
literal|"add"
block|,
name|svn_cl__add
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Put files and directories under version control, scheduling\n"
literal|"them for addition to repository.  They will be added in next commit.\n"
literal|"usage: add PATH...\n"
argument_list|)
block|,
block|{
name|opt_targets
block|,
literal|'N'
block|,
name|opt_depth
block|,
literal|'q'
block|,
name|opt_force
block|,
name|opt_no_ignore
block|,
name|opt_autoprops
block|,
name|opt_no_autoprops
block|,
name|opt_parents
block|}
block|,
block|{
block|{
name|opt_parents
block|,
name|N_
argument_list|(
literal|"add intermediate parents"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"blame"
block|,
name|svn_cl__blame
block|,
block|{
literal|"praise"
block|,
literal|"annotate"
block|,
literal|"ann"
block|}
block|,
name|N_
argument_list|(
literal|"Output the content of specified files or\n"
literal|"URLs with revision and author information in-line.\n"
literal|"usage: blame TARGET[@REV]...\n"
literal|"\n"
literal|"  If specified, REV determines in which revision the target is first\n"
literal|"  looked up.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'v'
block|,
literal|'g'
block|,
name|opt_incremental
block|,
name|opt_xml
block|,
literal|'x'
block|,
name|opt_force
block|}
block|}
block|,
block|{
literal|"cat"
block|,
name|svn_cl__cat
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Output the content of specified files or URLs.\n"
literal|"usage: cat TARGET[@REV]...\n"
literal|"\n"
literal|"  If specified, REV determines in which revision the target is first\n"
literal|"  looked up.\n"
argument_list|)
block|,
block|{
literal|'r'
block|}
block|}
block|,
block|{
literal|"changelist"
block|,
name|svn_cl__changelist
block|,
block|{
literal|"cl"
block|}
block|,
name|N_
argument_list|(
literal|"Associate (or dissociate) changelist CLNAME with the named files.\n"
literal|"usage: 1. changelist CLNAME PATH...\n"
literal|"       2. changelist --remove PATH...\n"
argument_list|)
block|,
block|{
literal|'q'
block|,
literal|'R'
block|,
name|opt_depth
block|,
name|opt_remove
block|,
name|opt_targets
block|,
name|opt_changelist
block|}
block|}
block|,
block|{
literal|"checkout"
block|,
name|svn_cl__checkout
block|,
block|{
literal|"co"
block|}
block|,
name|N_
argument_list|(
literal|"Check out a working copy from a repository.\n"
literal|"usage: checkout URL[@REV]... [PATH]\n"
literal|"\n"
literal|"  If specified, REV determines in which revision the URL is first\n"
literal|"  looked up.\n"
literal|"\n"
literal|"  If PATH is omitted, the basename of the URL will be used as\n"
literal|"  the destination. If multiple URLs are given each will be checked\n"
literal|"  out into a sub-directory of PATH, with the name of the sub-directory\n"
literal|"  being the basename of the URL.\n"
literal|"\n"
literal|"  If --force is used, unversioned obstructing paths in the working\n"
literal|"  copy destination do not automatically cause the check out to fail.\n"
literal|"  If the obstructing path is the same type (file or directory) as the\n"
literal|"  corresponding path in the repository it becomes versioned but its\n"
literal|"  contents are left 'as-is' in the working copy.  This means that an\n"
literal|"  obstructing directory's unversioned children may also obstruct and\n"
literal|"  become versioned.  For files, any content differences between the\n"
literal|"  obstruction and the repository are treated like a local modification\n"
literal|"  to the working copy.  All properties from the repository are applied\n"
literal|"  to the obstructing path.\n"
literal|"\n"
literal|"  See also 'svn help update' for a list of possible characters\n"
literal|"  reporting the action taken.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'q'
block|,
literal|'N'
block|,
name|opt_depth
block|,
name|opt_force
block|,
name|opt_ignore_externals
block|}
block|}
block|,
block|{
literal|"cleanup"
block|,
name|svn_cl__cleanup
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Recursively clean up the working copy, removing write locks, resuming\n"
literal|"unfinished operations, etc.\n"
literal|"usage: cleanup [WCPATH...]\n"
literal|"\n"
literal|"  Finish any unfinished business in the working copy at WCPATH, and remove\n"
literal|"  write locks (shown as 'L' by the 'svn status' command) from the working\n"
literal|"  copy. Usually, this is only necessary if a Subversion client has crashed\n"
literal|"  while using the working copy, leaving it in an unusable state.\n"
literal|"\n"
literal|"  WARNING: There is no mechanism that will protect write locks still\n"
literal|"           being used by other Subversion clients. Running this command\n"
literal|"           while another client is using the working copy can corrupt\n"
literal|"           the working copy beyond repair!\n"
argument_list|)
block|,
block|{
name|opt_merge_cmd
block|}
block|}
block|,
block|{
literal|"commit"
block|,
name|svn_cl__commit
block|,
block|{
literal|"ci"
block|}
block|,
name|N_
argument_list|(
literal|"Send changes from your working copy to the repository.\n"
literal|"usage: commit [PATH...]\n"
literal|"\n"
literal|"  A log message must be provided, but it can be empty.  If it is not\n"
literal|"  given by a --message or --file option, an editor will be started.\n"
literal|"  If any targets are (or contain) locked items, those will be\n"
literal|"  unlocked after a successful commit.\n"
argument_list|)
block|,
block|{
literal|'q'
block|,
literal|'N'
block|,
name|opt_depth
block|,
name|opt_targets
block|,
name|opt_no_unlock
block|,
name|SVN_CL__LOG_MSG_OPTIONS
block|,
name|opt_changelist
block|,
name|opt_keep_changelists
block|,
name|opt_include_externals
block|}
block|}
block|,
block|{
literal|"copy"
block|,
name|svn_cl__copy
block|,
block|{
literal|"cp"
block|}
block|,
name|N_
argument_list|(
literal|"Copy files and directories in a working copy or repository.\n"
literal|"usage: copy SRC[@REV]... DST\n"
literal|"\n"
literal|"  SRC and DST can each be either a working copy (WC) path or URL:\n"
literal|"    WC  -> WC:   copy and schedule for addition (with history)\n"
literal|"    WC  -> URL:  immediately commit a copy of WC to URL\n"
literal|"    URL -> WC:   check out URL into WC, schedule for addition\n"
literal|"    URL -> URL:  complete server-side copy;  used to branch and tag\n"
literal|"  All the SRCs must be of the same type. When copying multiple sources,\n"
literal|"  they will be added as children of DST, which must be a directory.\n"
literal|"\n"
literal|"  WARNING: For compatibility with previous versions of Subversion,\n"
literal|"  copies performed using two working copy paths (WC -> WC) will not\n"
literal|"  contact the repository.  As such, they may not, by default, be able\n"
literal|"  to propagate merge tracking information from the source of the copy\n"
literal|"  to the destination.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'q'
block|,
name|opt_ignore_externals
block|,
name|opt_parents
block|,
name|SVN_CL__LOG_MSG_OPTIONS
block|}
block|}
block|,
block|{
literal|"delete"
block|,
name|svn_cl__delete
block|,
block|{
literal|"del"
block|,
literal|"remove"
block|,
literal|"rm"
block|}
block|,
name|N_
argument_list|(
literal|"Remove files and directories from version control.\n"
literal|"usage: 1. delete PATH...\n"
literal|"       2. delete URL...\n"
literal|"\n"
literal|"  1. Each item specified by a PATH is scheduled for deletion upon\n"
literal|"    the next commit.  Files, and directories that have not been\n"
literal|"    committed, are immediately removed from the working copy\n"
literal|"    unless the --keep-local option is given.\n"
literal|"    PATHs that are, or contain, unversioned or modified items will\n"
literal|"    not be removed unless the --force or --keep-local option is given.\n"
literal|"\n"
literal|"  2. Each item specified by a URL is deleted from the repository\n"
literal|"    via an immediate commit.\n"
argument_list|)
block|,
block|{
name|opt_force
block|,
literal|'q'
block|,
name|opt_targets
block|,
name|SVN_CL__LOG_MSG_OPTIONS
block|,
name|opt_keep_local
block|}
block|}
block|,
block|{
literal|"diff"
block|,
name|svn_cl__diff
block|,
block|{
literal|"di"
block|}
block|,
name|N_
argument_list|(
literal|"Display local changes or differences between two revisions or paths.\n"
literal|"usage: 1. diff\n"
literal|"       2. diff [-c M | -r N[:M]] [TARGET[@REV]...]\n"
literal|"       3. diff [-r N[:M]] --old=OLD-TGT[@OLDREV] [--new=NEW-TGT[@NEWREV]] \\\n"
literal|"               [PATH...]\n"
literal|"       4. diff OLD-URL[@OLDREV] NEW-URL[@NEWREV]\n"
literal|"       5. diff OLD-URL[@OLDREV] NEW-PATH[@NEWREV]\n"
literal|"       6. diff OLD-PATH[@OLDREV] NEW-URL[@NEWREV]\n"
literal|"\n"
literal|"  1. Use just 'svn diff' to display local modifications in a working copy.\n"
literal|"\n"
literal|"  2. Display the changes made to TARGETs as they are seen in REV between\n"
literal|"     two revisions.  TARGETs may be all working copy paths or all URLs.\n"
literal|"     If TARGETs are working copy paths, N defaults to BASE and M to the\n"
literal|"     working copy; if URLs, N must be specified and M defaults to HEAD.\n"
literal|"     The '-c M' option is equivalent to '-r N:M' where N = M-1.\n"
literal|"     Using '-c -M' does the reverse: '-r M:N' where N = M-1.\n"
literal|"\n"
literal|"  3. Display the differences between OLD-TGT as it was seen in OLDREV and\n"
literal|"     NEW-TGT as it was seen in NEWREV.  PATHs, if given, are relative to\n"
literal|"     OLD-TGT and NEW-TGT and restrict the output to differences for those\n"
literal|"     paths.  OLD-TGT and NEW-TGT may be working copy paths or URL[@REV].\n"
literal|"     NEW-TGT defaults to OLD-TGT if not specified.  -r N makes OLDREV default\n"
literal|"     to N, -r N:M makes OLDREV default to N and NEWREV default to M.\n"
literal|"     If OLDREV or NEWREV are not specified, they default to WORKING for\n"
literal|"     working copy targets and to HEAD for URL targets.\n"
literal|"\n"
literal|"     Either or both OLD-TGT and NEW-TGT may also be paths to unversioned\n"
literal|"     targets. Revisions cannot be specified for unversioned targets.\n"
literal|"     Both targets must be of the same node kind (file or directory).\n"
literal|"     Diffing unversioned targets against URL targets is not supported.\n"
literal|"\n"
literal|"  4. Shorthand for 'svn diff --old=OLD-URL[@OLDREV] --new=NEW-URL[@NEWREV]'\n"
literal|"  5. Shorthand for 'svn diff --old=OLD-URL[@OLDREV] --new=NEW-PATH[@NEWREV]'\n"
literal|"  6. Shorthand for 'svn diff --old=OLD-PATH[@OLDREV] --new=NEW-URL[@NEWREV]'\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'c'
block|,
name|opt_old_cmd
block|,
name|opt_new_cmd
block|,
literal|'N'
block|,
name|opt_depth
block|,
name|opt_diff_cmd
block|,
name|opt_internal_diff
block|,
literal|'x'
block|,
name|opt_no_diff_added
block|,
name|opt_no_diff_deleted
block|,
name|opt_ignore_properties
block|,
name|opt_properties_only
block|,
name|opt_show_copies_as_adds
block|,
name|opt_notice_ancestry
block|,
name|opt_summarize
block|,
name|opt_changelist
block|,
name|opt_force
block|,
name|opt_xml
block|,
name|opt_use_git_diff_format
block|,
name|opt_patch_compatible
block|}
block|}
block|,
block|{
literal|"export"
block|,
name|svn_cl__export
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Create an unversioned copy of a tree.\n"
literal|"usage: 1. export [-r REV] URL[@PEGREV] [PATH]\n"
literal|"       2. export [-r REV] PATH1[@PEGREV] [PATH2]\n"
literal|"\n"
literal|"  1. Exports a clean directory tree from the repository specified by\n"
literal|"     URL, at revision REV if it is given, otherwise at HEAD, into\n"
literal|"     PATH. If PATH is omitted, the last component of the URL is used\n"
literal|"     for the local directory name.\n"
literal|"\n"
literal|"  2. Exports a clean directory tree from the working copy specified by\n"
literal|"     PATH1, at revision REV if it is given, otherwise at WORKING, into\n"
literal|"     PATH2.  If PATH2 is omitted, the last component of the PATH1 is used\n"
literal|"     for the local directory name. If REV is not specified, all local\n"
literal|"     changes will be preserved.  Files not under version control will\n"
literal|"     not be copied.\n"
literal|"\n"
literal|"  If specified, PEGREV determines in which revision the target is first\n"
literal|"  looked up.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'q'
block|,
literal|'N'
block|,
name|opt_depth
block|,
name|opt_force
block|,
name|opt_native_eol
block|,
name|opt_ignore_externals
block|,
name|opt_ignore_keywords
block|}
block|}
block|,
block|{
literal|"help"
block|,
name|svn_cl__help
block|,
block|{
literal|"?"
block|,
literal|"h"
block|}
block|,
name|N_
argument_list|(
literal|"Describe the usage of this program or its subcommands.\n"
literal|"usage: help [SUBCOMMAND...]\n"
argument_list|)
block|,
block|{
literal|0
block|}
block|}
block|,
comment|/* This command is also invoked if we see option "--help", "-h" or "-?". */
block|{
literal|"import"
block|,
name|svn_cl__import
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Commit an unversioned file or tree into the repository.\n"
literal|"usage: import [PATH] URL\n"
literal|"\n"
literal|"  Recursively commit a copy of PATH to URL.\n"
literal|"  If PATH is omitted '.' is assumed.\n"
literal|"  Parent directories are created as necessary in the repository.\n"
literal|"  If PATH is a directory, the contents of the directory are added\n"
literal|"  directly under URL.\n"
literal|"  Unversionable items such as device files and pipes are ignored\n"
literal|"  if --force is specified.\n"
argument_list|)
block|,
block|{
literal|'q'
block|,
literal|'N'
block|,
name|opt_depth
block|,
name|opt_autoprops
block|,
name|opt_force
block|,
name|opt_no_autoprops
block|,
name|SVN_CL__LOG_MSG_OPTIONS
block|,
name|opt_no_ignore
block|}
block|}
block|,
block|{
literal|"info"
block|,
name|svn_cl__info
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Display information about a local or remote item.\n"
literal|"usage: info [TARGET[@REV]...]\n"
literal|"\n"
literal|"  Print information about each TARGET (default: '.').\n"
literal|"  TARGET may be either a working-copy path or URL.  If specified, REV\n"
literal|"  determines in which revision the target is first looked up.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'R'
block|,
name|opt_depth
block|,
name|opt_targets
block|,
name|opt_incremental
block|,
name|opt_xml
block|,
name|opt_changelist
block|}
block|}
block|,
block|{
literal|"list"
block|,
name|svn_cl__list
block|,
block|{
literal|"ls"
block|}
block|,
name|N_
argument_list|(
literal|"List directory entries in the repository.\n"
literal|"usage: list [TARGET[@REV]...]\n"
literal|"\n"
literal|"  List each TARGET file and the contents of each TARGET directory as\n"
literal|"  they exist in the repository.  If TARGET is a working copy path, the\n"
literal|"  corresponding repository URL will be used. If specified, REV determines\n"
literal|"  in which revision the target is first looked up.\n"
literal|"\n"
literal|"  The default TARGET is '.', meaning the repository URL of the current\n"
literal|"  working directory.\n"
literal|"\n"
literal|"  With --verbose, the following fields will be shown for each item:\n"
literal|"\n"
literal|"    Revision number of the last commit\n"
literal|"    Author of the last commit\n"
literal|"    If locked, the letter 'O'.  (Use 'svn info URL' to see details)\n"
literal|"    Size (in bytes)\n"
literal|"    Date and time of the last commit\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'v'
block|,
literal|'R'
block|,
name|opt_depth
block|,
name|opt_incremental
block|,
name|opt_xml
block|,
name|opt_include_externals
block|}
block|,
block|{
block|{
name|opt_include_externals
block|,
name|N_
argument_list|(
literal|"include externals definitions"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"lock"
block|,
name|svn_cl__lock
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Lock working copy paths or URLs in the repository, so that\n"
literal|"no other user can commit changes to them.\n"
literal|"usage: lock TARGET...\n"
literal|"\n"
literal|"  Use --force to steal the lock from another user or working copy.\n"
argument_list|)
block|,
block|{
name|opt_targets
block|,
literal|'m'
block|,
literal|'F'
block|,
name|opt_force_log
block|,
name|opt_encoding
block|,
name|opt_force
block|}
block|,
block|{
block|{
literal|'F'
block|,
name|N_
argument_list|(
literal|"read lock comment from file ARG"
argument_list|)
block|}
block|,
block|{
literal|'m'
block|,
name|N_
argument_list|(
literal|"specify lock comment ARG"
argument_list|)
block|}
block|,
block|{
name|opt_force_log
block|,
name|N_
argument_list|(
literal|"force validity of lock comment source"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"log"
block|,
name|svn_cl__log
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Show the log messages for a set of revision(s) and/or path(s).\n"
literal|"usage: 1. log [PATH][@REV]\n"
literal|"       2. log URL[@REV] [PATH...]\n"
literal|"\n"
literal|"  1. Print the log messages for the URL corresponding to PATH\n"
literal|"     (default: '.'). If specified, REV is the revision in which the\n"
literal|"     URL is first looked up, and the default revision range is REV:1.\n"
literal|"     If REV is not specified, the default revision range is BASE:1,\n"
literal|"     since the URL might not exist in the HEAD revision.\n"
literal|"\n"
literal|"  2. Print the log messages for the PATHs (default: '.') under URL.\n"
literal|"     If specified, REV is the revision in which the URL is first\n"
literal|"     looked up, and the default revision range is REV:1; otherwise,\n"
literal|"     the URL is looked up in HEAD, and the default revision range is\n"
literal|"     HEAD:1.\n"
literal|"\n"
literal|"  Multiple '-c' or '-r' options may be specified (but not a\n"
literal|"  combination of '-c' and '-r' options), and mixing of forward and\n"
literal|"  reverse ranges is allowed.\n"
literal|"\n"
literal|"  With -v, also print all affected paths with each log message.\n"
literal|"  With -q, don't print the log message body itself (note that this is\n"
literal|"  compatible with -v).\n"
literal|"\n"
literal|"  Each log message is printed just once, even if more than one of the\n"
literal|"  affected paths for that revision were explicitly requested.  Logs\n"
literal|"  follow copy history by default.  Use --stop-on-copy to disable this\n"
literal|"  behavior, which can be useful for determining branchpoints.\n"
literal|"\n"
literal|"  The --depth option is only valid in combination with the --diff option\n"
literal|"  and limits the scope of the displayed diff to the specified depth.\n"
literal|"\n"
literal|"  If the --search option is used, log messages are displayed only if the\n"
literal|"  provided search pattern matches any of the author, date, log message\n"
literal|"  text (unless --quiet is used), or, if the --verbose option is also\n"
literal|"  provided, a changed path.\n"
literal|"  The search pattern may include \"glob syntax\" wildcards:\n"
literal|"      ?      matches any single character\n"
literal|"      *      matches a sequence of arbitrary characters\n"
literal|"      [abc]  matches any of the characters listed inside the brackets\n"
literal|"  If multiple --search options are provided, a log message is shown if\n"
literal|"  it matches any of the provided search patterns. If the --search-and\n"
literal|"  option is used, that option's argument is combined with the pattern\n"
literal|"  from the previous --search or --search-and option, and a log message\n"
literal|"  is shown only if it matches the combined search pattern.\n"
literal|"  If --limit is used in combination with --search, --limit restricts the\n"
literal|"  number of log messages searched, rather than restricting the output\n"
literal|"  to a particular number of matching log messages.\n"
literal|"\n"
literal|"  Examples:\n"
literal|"\n"
literal|"    Show the latest 5 log messages for the current working copy\n"
literal|"    directory and display paths changed in each commit:\n"
literal|"      svn log -l 5 -v\n"
literal|"\n"
literal|"    Show the log for bar.c as of revision 42:\n"
literal|"      svn log bar.c@42\n"
literal|"\n"
literal|"    Show log messages and diffs for each commit to foo.c:\n"
literal|"      svn log --diff http://www.example.com/repo/project/foo.c\n"
literal|"    (Because the above command uses a full URL it does not require\n"
literal|"     a working copy.)\n"
literal|"\n"
literal|"    Show log messages for the children foo.c and bar.c of the directory\n"
literal|"    '/trunk' as it appeared in revision 50, using the ^/ URL shortcut:\n"
literal|"      svn log ^/trunk@50 foo.c bar.c\n"
literal|"\n"
literal|"    Show the log messages for any incoming changes to foo.c during the\n"
literal|"    next 'svn update':\n"
literal|"      svn log -r BASE:HEAD foo.c\n"
literal|"\n"
literal|"    Show the log message for the revision in which /branches/foo\n"
literal|"    was created:\n"
literal|"      svn log --stop-on-copy --limit 1 -r0:HEAD ^/branches/foo\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'q'
block|,
literal|'v'
block|,
literal|'g'
block|,
literal|'c'
block|,
name|opt_targets
block|,
name|opt_stop_on_copy
block|,
name|opt_incremental
block|,
name|opt_xml
block|,
literal|'l'
block|,
name|opt_with_all_revprops
block|,
name|opt_with_no_revprops
block|,
name|opt_with_revprop
block|,
name|opt_depth
block|,
name|opt_diff
block|,
name|opt_diff_cmd
block|,
name|opt_internal_diff
block|,
literal|'x'
block|,
name|opt_search
block|,
name|opt_search_and
block|, }
block|,
block|{
block|{
name|opt_with_revprop
block|,
name|N_
argument_list|(
literal|"retrieve revision property ARG"
argument_list|)
block|}
block|,
block|{
literal|'c'
block|,
name|N_
argument_list|(
literal|"the change made in revision ARG"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"merge"
block|,
name|svn_cl__merge
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
comment|/* For this large section, let's keep it unindented for easier        * viewing/editing. It has been vim-treated with a textwidth=75 and 'gw'        * (with quotes and newlines removed). */
literal|"Merge changes into a working copy.\n"
literal|"usage: 1. merge SOURCE[@REV] [TARGET_WCPATH]\n"
literal|"          (the 'complete' merge)\n"
literal|"       2. merge [-c M[,N...] | -r N:M ...] SOURCE[@REV] [TARGET_WCPATH]\n"
literal|"          (the 'cherry-pick' merge)\n"
literal|"       3. merge SOURCE1[@REV1] SOURCE2[@REV2] [TARGET_WCPATH]\n"
literal|"          (the '2-URL' merge)\n"
literal|"\n"
literal|"  1. This form, with one source path and no revision range, is called\n"
literal|"     a 'complete' merge:\n"
literal|"\n"
literal|"       svn merge SOURCE[@REV] [TARGET_WCPATH]\n"
literal|"\n"
literal|"     The complete merge is used for the 'sync' and 'reintegrate' merges\n"
literal|"     in the 'feature branch' pattern described below. It finds all the\n"
literal|"     changes on the source branch that have not already been merged to the\n"
literal|"     target branch, and merges them into the working copy. Merge tracking\n"
literal|"     is used to know which changes have already been merged.\n"
literal|"\n"
literal|"     SOURCE specifies the branch from where the changes will be pulled, and\n"
literal|"     TARGET_WCPATH specifies a working copy of the target branch to which\n"
literal|"     the changes will be applied. Normally SOURCE and TARGET_WCPATH should\n"
literal|"     each correspond to the root of a branch. (If you want to merge only a\n"
literal|"     subtree, then the subtree path must be included in both SOURCE and\n"
literal|"     TARGET_WCPATH; this is discouraged, to avoid subtree mergeinfo.)\n"
literal|"\n"
literal|"     SOURCE is usually a URL. The optional '@REV' specifies both the peg\n"
literal|"     revision of the URL and the latest revision that will be considered\n"
literal|"     for merging; if REV is not specified, the HEAD revision is assumed. If\n"
literal|"     SOURCE is a working copy path, the corresponding URL of the path is\n"
literal|"     used, and the default value of 'REV' is the base revision (usually the\n"
literal|"     revision last updated to).\n"
literal|"\n"
literal|"     TARGET_WCPATH is a working copy path; if omitted, '.' is generally\n"
literal|"     assumed. There are some special cases:\n"
literal|"\n"
literal|"       - If SOURCE is a URL:\n"
literal|"\n"
literal|"           - If the basename of the URL and the basename of '.' are the\n"
literal|"             same, then the differences are applied to '.'. Otherwise,\n"
literal|"             if a file with the same basename as that of the URL is found\n"
literal|"             within '.', then the differences are applied to that file.\n"
literal|"             In all other cases, the target defaults to '.'.\n"
literal|"\n"
literal|"       - If SOURCE is a working copy path:\n"
literal|"\n"
literal|"           - If the source is a file, then differences are applied to that\n"
literal|"             file (useful for reverse-merging earlier changes). Otherwise,\n"
literal|"             if the source is a directory, then the target defaults to '.'.\n"
literal|"\n"
literal|"     In normal usage the working copy should be up to date, at a single\n"
literal|"     revision, with no local modifications and no switched subtrees.\n"
literal|"\n"
literal|"       - The 'Feature Branch' Merging Pattern -\n"
literal|"\n"
literal|"     In this commonly used work flow, known also as the 'development\n"
literal|"     branch' pattern, a developer creates a branch and commits a series of\n"
literal|"     changes that implement a new feature. The developer periodically\n"
literal|"     merges all the latest changes from the parent branch so as to keep the\n"
literal|"     development branch up to date with those changes. When the feature is\n"
literal|"     complete, the developer performs a merge from the feature branch to\n"
literal|"     the parent branch to re-integrate the changes.\n"
literal|"\n"
literal|"         parent --+----------o------o-o-------------o--\n"
literal|"                   \\            \\           \\      /\n"
literal|"                    \\          merge      merge  merge\n"
literal|"                     \\            \\           \\  /\n"
literal|"         feature      +--o-o-------o----o-o----o-------\n"
literal|"\n"
literal|"     A merge from the parent branch to the feature branch is called a\n"
literal|"     'sync' or 'catch-up' merge, and a merge from the feature branch to the\n"
literal|"     parent branch is called a 'reintegrate' merge.\n"
literal|"\n"
literal|"       - Sync Merge Example -\n"
literal|"                                 ............\n"
literal|"                                .            .\n"
literal|"         trunk  --+------------L--------------R------\n"
literal|"                   \\                           \\\n"
literal|"                    \\                          |\n"
literal|"                     \\                         v\n"
literal|"         feature      +------------------------o-----\n"
literal|"                             r100            r200\n"
literal|"\n"
literal|"     Subversion will locate all the changes on 'trunk' that have not yet\n"
literal|"     been merged into the 'feature' branch. In this case that is a single\n"
literal|"     range, r100:200. In the diagram above, L marks the left side (trunk@100)\n"
literal|"     and R marks the right side (trunk@200) of the merge source. The\n"
literal|"     difference between L and R will be applied to the target working copy\n"
literal|"     path. In this case, the working copy is a clean checkout of the entire\n"
literal|"     'feature' branch.\n"
literal|"\n"
literal|"     To perform this sync merge, have a clean working copy of the feature\n"
literal|"     branch and run the following command in its top-level directory:\n"
literal|"\n"
literal|"         svn merge ^/trunk\n"
literal|"\n"
literal|"     Note that the merge is now only in your local working copy and still\n"
literal|"     needs to be committed to the repository so that it can be seen by\n"
literal|"     others. You can review the changes and you may have to resolve\n"
literal|"     conflicts before you commit the merge.\n"
literal|"\n"
literal|"       - Reintegrate Merge Example -\n"
literal|"\n"
literal|"     The feature branch was last synced with trunk up to revision X. So the\n"
literal|"     difference between trunk@X and feature@HEAD contains the complete set\n"
literal|"     of changes that implement the feature, and no other changes. These\n"
literal|"     changes are applied to trunk.\n"
literal|"\n"
literal|"                    rW                   rX\n"
literal|"         trunk ------+--------------------L------------------o\n"
literal|"                      \\                    .                 ^\n"
literal|"                       \\                    .............   /\n"
literal|"                        \\                                . /\n"
literal|"         feature         +--------------------------------R\n"
literal|"\n"
literal|"     In the diagram above, L marks the left side (trunk@X) and R marks the\n"
literal|"     right side (feature@HEAD) of the merge. The difference between the\n"
literal|"     left and right side is merged into trunk, the target.\n"
literal|"\n"
literal|"     To perform the merge, have a clean working copy of trunk and run the\n"
literal|"     following command in its top-level directory:\n"
literal|"\n"
literal|"         svn merge ^/feature\n"
literal|"\n"
literal|"     To prevent unnecessary merge conflicts, a reintegrate merge requires\n"
literal|"     that TARGET_WCPATH is not a mixed-revision working copy, has no local\n"
literal|"     modifications, and has no switched subtrees.\n"
literal|"\n"
literal|"     A reintegrate merge also requires that the source branch is coherently\n"
literal|"     synced with the target -- in the above example, this means that all\n"
literal|"     revisions between the branch point W and the last merged revision X\n"
literal|"     are merged to the feature branch, so that there are no unmerged\n"
literal|"     revisions in-between.\n"
literal|"\n"
literal|"\n"
literal|"  2. This form is called a 'cherry-pick' merge:\n"
literal|"\n"
literal|"       svn merge [-c M[,N...] | -r N:M ...] SOURCE[@REV] [TARGET_WCPATH]\n"
literal|"\n"
literal|"     A cherry-pick merge is used to merge specific revisions (or revision\n"
literal|"     ranges) from one branch to another. By default, this uses merge\n"
literal|"     tracking to automatically skip any revisions that have already been\n"
literal|"     merged to the target; you can use the --ignore-ancestry option to\n"
literal|"     disable such skipping.\n"
literal|"\n"
literal|"     SOURCE is usually a URL. The optional '@REV' specifies only the peg\n"
literal|"     revision of the URL and does not affect the merge range; if REV is not\n"
literal|"     specified, the HEAD revision is assumed. If SOURCE is a working copy\n"
literal|"     path, the corresponding URL of the path is used, and the default value\n"
literal|"     of 'REV' is the base revision (usually the revision last updated to).\n"
literal|"\n"
literal|"     TARGET_WCPATH is a working copy path; if omitted, '.' is generally\n"
literal|"     assumed. The special cases noted above in the 'complete' merge form\n"
literal|"     also apply here.\n"
literal|"\n"
literal|"     The revision ranges to be merged are specified by the '-r' and/or '-c'\n"
literal|"     options. '-r N:M' refers to the difference in the history of the\n"
literal|"     source branch between revisions N and M. You can use '-c M' to merge\n"
literal|"     single revisions: '-c M' is equivalent to '-r<M-1>:M'. Each such\n"
literal|"     difference is applied to TARGET_WCPATH.\n"
literal|"\n"
literal|"     If the mergeinfo in TARGET_WCPATH indicates that revisions within the\n"
literal|"     range were already merged, changes made in those revisions are not\n"
literal|"     merged again. If needed, the range is broken into multiple sub-ranges,\n"
literal|"     and each sub-range is merged separately.\n"
literal|"\n"
literal|"     A 'reverse range' can be used to undo changes. For example, when\n"
literal|"     source and target refer to the same branch, a previously committed\n"
literal|"     revision can be 'undone'. In a reverse range, N is greater than M in\n"
literal|"     '-r N:M', or the '-c' option is used with a negative number: '-c -M'\n"
literal|"     is equivalent to '-r M:<M-1>'. Undoing changes like this is also known\n"
literal|"     as performing a 'reverse merge'.\n"
literal|"\n"
literal|"     Multiple '-c' and/or '-r' options may be specified and mixing of\n"
literal|"     forward and reverse ranges is allowed.\n"
literal|"\n"
literal|"       - Cherry-pick Merge Example -\n"
literal|"\n"
literal|"     A bug has been fixed on trunk in revision 50. This fix needs to\n"
literal|"     be merged from trunk onto the release branch.\n"
literal|"\n"
literal|"            1.x-release  +-----------------------o-----\n"
literal|"                        /                        ^\n"
literal|"                       /                         |\n"
literal|"                      /                          |\n"
literal|"         trunk ------+--------------------------LR-----\n"
literal|"                                                r50\n"
literal|"\n"
literal|"     In the above diagram, L marks the left side (trunk@49) and R marks the\n"
literal|"     right side (trunk@50) of the merge. The difference between the left\n"
literal|"     and right side is applied to the target working copy path.\n"
literal|"\n"
literal|"     Note that the difference between revision 49 and 50 is exactly those\n"
literal|"     changes that were committed in revision 50, not including changes\n"
literal|"     committed in revision 49.\n"
literal|"\n"
literal|"     To perform the merge, have a clean working copy of the release branch\n"
literal|"     and run the following command in its top-level directory; remember\n"
literal|"     that the default target is '.':\n"
literal|"\n"
literal|"         svn merge -c50 ^/trunk\n"
literal|"\n"
literal|"     You can also cherry-pick several revisions and/or revision ranges:\n"
literal|"\n"
literal|"         svn merge -c50,54,60 -r65:68 ^/trunk\n"
literal|"\n"
literal|"\n"
literal|"  3. This form is called a '2-URL merge':\n"
literal|"\n"
literal|"       svn merge SOURCE1[@REV1] SOURCE2[@REV2] [TARGET_WCPATH]\n"
literal|"\n"
literal|"     You should use this merge variant only if the other variants do not\n"
literal|"     apply to your situation, as this variant can be quite complex to\n"
literal|"     master.\n"
literal|"\n"
literal|"     Two source URLs are specified, identifying two trees on the same\n"
literal|"     branch or on different branches. The trees are compared and the\n"
literal|"     difference from SOURCE1@REV1 to SOURCE2@REV2 is applied to the\n"
literal|"     working copy of the target branch at TARGET_WCPATH. The target\n"
literal|"     branch may be the same as one or both sources, or different again.\n"
literal|"     The three branches involved can be completely unrelated.\n"
literal|"\n"
literal|"     TARGET_WCPATH is a working copy path; if omitted, '.' is generally\n"
literal|"     assumed. The special cases noted above in the 'complete' merge form\n"
literal|"     also apply here.\n"
literal|"\n"
literal|"     SOURCE1 and/or SOURCE2 can also be specified as a working copy path,\n"
literal|"     in which case the merge source URL is derived from the working copy.\n"
literal|"\n"
literal|"       - 2-URL Merge Example -\n"
literal|"\n"
literal|"     Two features have been developed on separate branches called 'foo' and\n"
literal|"     'bar'. It has since become clear that 'bar' should be combined with\n"
literal|"     the 'foo' branch for further development before reintegration.\n"
literal|"\n"
literal|"     Although both feature branches originate from trunk, they are not\n"
literal|"     directly related -- one is not a direct copy of the other. A 2-URL\n"
literal|"     merge is necessary.\n"
literal|"\n"
literal|"     The 'bar' branch has been synced with trunk up to revision 500.\n"
literal|"     (If this revision number is not known, it can be located using the\n"
literal|"     'svn log' and/or 'svn mergeinfo' commands.)\n"
literal|"     The difference between trunk@500 and bar@HEAD contains the complete\n"
literal|"     set of changes related to feature 'bar', and no other changes. These\n"
literal|"     changes are applied to the 'foo' branch.\n"
literal|"\n"
literal|"                           foo  +-----------------------------------o\n"
literal|"                               /                                    ^\n"
literal|"                              /                                    /\n"
literal|"                             /              r500                  /\n"
literal|"         trunk ------+------+-----------------L--------->        /\n"
literal|"                      \\                        .                /\n"
literal|"                       \\                        ............   /\n"
literal|"                        \\                                   . /\n"
literal|"                    bar  +-----------------------------------R\n"
literal|"\n"
literal|"     In the diagram above, L marks the left side (trunk@500) and R marks\n"
literal|"     the right side (bar@HEAD) of the merge. The difference between the\n"
literal|"     left and right side is applied to the target working copy path, in\n"
literal|"     this case a working copy of the 'foo' branch.\n"
literal|"\n"
literal|"     To perform the merge, have a clean working copy of the 'foo' branch\n"
literal|"     and run the following command in its top-level directory:\n"
literal|"\n"
literal|"         svn merge ^/trunk@500 ^/bar\n"
literal|"\n"
literal|"     The exact changes applied by a 2-URL merge can be previewed with svn's\n"
literal|"     diff command, which is a good idea to verify if you do not have the\n"
literal|"     luxury of a clean working copy to merge to. In this case:\n"
literal|"\n"
literal|"         svn diff ^/trunk@500 ^/bar@HEAD\n"
literal|"\n"
literal|"\n"
literal|"  The following applies to all types of merges:\n"
literal|"\n"
literal|"  To prevent unnecessary merge conflicts, svn merge requires that\n"
literal|"  TARGET_WCPATH is not a mixed-revision working copy. Running 'svn update'\n"
literal|"  before starting a merge ensures that all items in the working copy are\n"
literal|"  based on the same revision.\n"
literal|"\n"
literal|"  If possible, you should have no local modifications in the merge's target\n"
literal|"  working copy prior to the merge, to keep things simpler. It will be\n"
literal|"  easier to revert the merge and to understand the branch's history.\n"
literal|"\n"
literal|"  Switched sub-paths should also be avoided during merging, as they may\n"
literal|"  cause incomplete merges and create subtree mergeinfo.\n"
literal|"\n"
literal|"  For each merged item a line will be printed with characters reporting the\n"
literal|"  action taken. These characters have the following meaning:\n"
literal|"\n"
literal|"    A  Added\n"
literal|"    D  Deleted\n"
literal|"    U  Updated\n"
literal|"    C  Conflict\n"
literal|"    G  Merged\n"
literal|"    E  Existed\n"
literal|"    R  Replaced\n"
literal|"\n"
literal|"  Characters in the first column report about the item itself.\n"
literal|"  Characters in the second column report about properties of the item.\n"
literal|"  A 'C' in the third column indicates a tree conflict, while a 'C' in\n"
literal|"  the first and second columns indicate textual conflicts in files\n"
literal|"  and in property values, respectively.\n"
literal|"\n"
literal|"    - Merge Tracking -\n"
literal|"\n"
literal|"  Subversion uses the svn:mergeinfo property to track merge history. This\n"
literal|"  property is considered at the start of a merge to determine what to merge\n"
literal|"  and it is updated at the conclusion of the merge to describe the merge\n"
literal|"  that took place. Mergeinfo is used only if the two sources are on the\n"
literal|"  same line of history -- if the first source is an ancestor of the second,\n"
literal|"  or vice-versa (i.e. if one has originally been created by copying the\n"
literal|"  other). This is verified and enforced when using sync merges and\n"
literal|"  reintegrate merges.\n"
literal|"\n"
literal|"  The --ignore-ancestry option prevents merge tracking and thus ignores\n"
literal|"  mergeinfo, neither considering it nor recording it.\n"
literal|"\n"
literal|"    - Merging from foreign repositories -\n"
literal|"\n"
literal|"  Subversion does support merging from foreign repositories.\n"
literal|"  While all merge source URLs must point to the same repository, the merge\n"
literal|"  target working copy may come from a different repository than the source.\n"
literal|"  However, there are some caveats. Most notably, copies made in the\n"
literal|"  merge source will be transformed into plain additions in the merge\n"
literal|"  target. Also, merge-tracking is not supported for merges from foreign\n"
literal|"  repositories.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'c'
block|,
literal|'N'
block|,
name|opt_depth
block|,
literal|'q'
block|,
name|opt_force
block|,
name|opt_dry_run
block|,
name|opt_merge_cmd
block|,
name|opt_record_only
block|,
literal|'x'
block|,
name|opt_ignore_ancestry
block|,
name|opt_accept
block|,
name|opt_reintegrate
block|,
name|opt_allow_mixed_revisions
block|,
literal|'v'
block|}
block|}
block|,
block|{
literal|"mergeinfo"
block|,
name|svn_cl__mergeinfo
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Display merge-related information.\n"
literal|"usage: 1. mergeinfo SOURCE[@REV] [TARGET[@REV]]\n"
literal|"       2. mergeinfo --show-revs=WHICH SOURCE[@REV] [TARGET[@REV]]\n"
literal|"\n"
literal|"  1. Summarize the history of merging between SOURCE and TARGET. The graph\n"
literal|"     shows, from left to right:\n"
literal|"       the youngest common ancestor of the branches;\n"
literal|"       the latest full merge in either direction, and thus the common base\n"
literal|"         that will be used for the next complete merge;\n"
literal|"       the repository path and revision number of the tip of each branch.\n"
literal|"\n"
literal|"  2. Print the revision numbers on SOURCE that have been merged to TARGET\n"
literal|"     (with --show-revs=merged), or that have not been merged to TARGET\n"
literal|"     (with --show-revs=eligible). Print only revisions in which there was\n"
literal|"     at least one change in SOURCE.\n"
literal|"\n"
literal|"     If --revision (-r) is provided, filter the displayed information to\n"
literal|"     show only that which is associated with the revisions within the\n"
literal|"     specified range.  Revision numbers, dates, and the 'HEAD' keyword are\n"
literal|"     valid range values.\n"
literal|"\n"
literal|"  SOURCE and TARGET are the source and target branch URLs, respectively.\n"
literal|"  (If a WC path is given, the corresponding base URL is used.) The default\n"
literal|"  TARGET is the current working directory ('.'). REV specifies the revision\n"
literal|"  to be considered the tip of the branch; the default for SOURCE is HEAD,\n"
literal|"  and the default for TARGET is HEAD for a URL or BASE for a WC path.\n"
literal|"\n"
literal|"  The depth can be 'empty' or 'infinity'; the default is 'empty'.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'R'
block|,
name|opt_depth
block|,
name|opt_show_revs
block|}
block|}
block|,
block|{
literal|"mkdir"
block|,
name|svn_cl__mkdir
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Create a new directory under version control.\n"
literal|"usage: 1. mkdir PATH...\n"
literal|"       2. mkdir URL...\n"
literal|"\n"
literal|"  Create version controlled directories.\n"
literal|"\n"
literal|"  1. Each directory specified by a working copy PATH is created locally\n"
literal|"    and scheduled for addition upon the next commit.\n"
literal|"\n"
literal|"  2. Each directory specified by a URL is created in the repository via\n"
literal|"    an immediate commit.\n"
literal|"\n"
literal|"  In both cases, all the intermediate directories must already exist,\n"
literal|"  unless the --parents option is given.\n"
argument_list|)
block|,
block|{
literal|'q'
block|,
name|opt_parents
block|,
name|SVN_CL__LOG_MSG_OPTIONS
block|}
block|}
block|,
block|{
literal|"move"
block|,
name|svn_cl__move
block|,
block|{
literal|"mv"
block|,
literal|"rename"
block|,
literal|"ren"
block|}
block|,
name|N_
argument_list|(
literal|"Move (rename) an item in a working copy or repository.\n"
literal|"usage: move SRC... DST\n"
literal|"\n"
literal|"  SRC and DST can both be working copy (WC) paths or URLs:\n"
literal|"    WC  -> WC:  move an item in a working copy, as a local change to\n"
literal|"                be committed later (with or without further changes)\n"
literal|"    URL -> URL: move an item in the repository directly, immediately\n"
literal|"                creating a new revision in the repository\n"
literal|"  All the SRCs must be of the same type. When moving multiple sources,\n"
literal|"  they will be added as children of DST, which must be a directory.\n"
literal|"\n"
literal|"  SRC and DST of WC -> WC moves must be committed in the same revision.\n"
literal|"  Furthermore, WC -> WC moves will refuse to move a mixed-revision subtree.\n"
literal|"  To avoid unnecessary conflicts, it is recommended to run 'svn update'\n"
literal|"  to update the subtree to a single revision before moving it.\n"
literal|"  The --allow-mixed-revisions option is provided for backward compatibility.\n"
literal|"\n"
literal|"  The --revision option has no use and is deprecated.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'q'
block|,
name|opt_force
block|,
name|opt_parents
block|,
name|opt_allow_mixed_revisions
block|,
name|SVN_CL__LOG_MSG_OPTIONS
block|}
block|}
block|,
block|{
literal|"patch"
block|,
name|svn_cl__patch
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Apply a patch to a working copy.\n"
literal|"usage: patch PATCHFILE [WCPATH]\n"
literal|"\n"
literal|"  Apply a unidiff patch in PATCHFILE to the working copy WCPATH.\n"
literal|"  If WCPATH is omitted, '.' is assumed.\n"
literal|"\n"
literal|"  A unidiff patch suitable for application to a working copy can be\n"
literal|"  produced with the 'svn diff' command or third-party diffing tools.\n"
literal|"  Any non-unidiff content of PATCHFILE is ignored, except for Subversion\n"
literal|"  property diffs as produced by 'svn diff'.\n"
literal|"\n"
literal|"  Changes listed in the patch will either be applied or rejected.\n"
literal|"  If a change does not match at its exact line offset, it may be applied\n"
literal|"  earlier or later in the file if a match is found elsewhere for the\n"
literal|"  surrounding lines of context provided by the patch.\n"
literal|"  A change may also be applied with fuzz, which means that one\n"
literal|"  or more lines of context are ignored when matching the change.\n"
literal|"  If no matching context can be found for a change, the change conflicts\n"
literal|"  and will be written to a reject file with the extension .svnpatch.rej.\n"
literal|"\n"
literal|"  For each patched file a line will be printed with characters reporting\n"
literal|"  the action taken. These characters have the following meaning:\n"
literal|"\n"
literal|"    A  Added\n"
literal|"    D  Deleted\n"
literal|"    U  Updated\n"
literal|"    C  Conflict\n"
literal|"    G  Merged (with local uncommitted changes)\n"
literal|"\n"
literal|"  Changes applied with an offset or fuzz are reported on lines starting\n"
literal|"  with the '>' symbol. You should review such changes carefully.\n"
literal|"\n"
literal|"  If the patch removes all content from a file, that file is scheduled\n"
literal|"  for deletion. If the patch creates a new file, that file is scheduled\n"
literal|"  for addition. Use 'svn revert' to undo deletions and additions you\n"
literal|"  do not agree with.\n"
literal|"\n"
literal|"  Hint: If the patch file was created with Subversion, it will contain\n"
literal|"        the number of a revision N the patch will cleanly apply to\n"
literal|"        (look for lines like '--- foo/bar.txt        (revision N)').\n"
literal|"        To avoid rejects, first update to the revision N using\n"
literal|"        'svn update -r N', apply the patch, and then update back to the\n"
literal|"        HEAD revision. This way, conflicts can be resolved interactively.\n"
argument_list|)
block|,
block|{
literal|'q'
block|,
name|opt_dry_run
block|,
name|opt_strip
block|,
name|opt_reverse_diff
block|,
name|opt_ignore_whitespace
block|}
block|}
block|,
block|{
literal|"propdel"
block|,
name|svn_cl__propdel
block|,
block|{
literal|"pdel"
block|,
literal|"pd"
block|}
block|,
name|N_
argument_list|(
literal|"Remove a property from files, dirs, or revisions.\n"
literal|"usage: 1. propdel PROPNAME [PATH...]\n"
literal|"       2. propdel PROPNAME --revprop -r REV [TARGET]\n"
literal|"\n"
literal|"  1. Removes versioned props in working copy.\n"
literal|"  2. Removes unversioned remote prop on repos revision.\n"
literal|"     TARGET only determines which repository to access.\n"
argument_list|)
block|,
block|{
literal|'q'
block|,
literal|'R'
block|,
name|opt_depth
block|,
literal|'r'
block|,
name|opt_revprop
block|,
name|opt_changelist
block|}
block|}
block|,
block|{
literal|"propedit"
block|,
name|svn_cl__propedit
block|,
block|{
literal|"pedit"
block|,
literal|"pe"
block|}
block|,
name|N_
argument_list|(
literal|"Edit a property with an external editor.\n"
literal|"usage: 1. propedit PROPNAME TARGET...\n"
literal|"       2. propedit PROPNAME --revprop -r REV [TARGET]\n"
literal|"\n"
literal|"  1. Edits versioned prop in working copy or repository.\n"
literal|"  2. Edits unversioned remote prop on repos revision.\n"
literal|"     TARGET only determines which repository to access.\n"
literal|"\n"
literal|"  See 'svn help propset' for more on setting properties.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
name|opt_revprop
block|,
name|SVN_CL__LOG_MSG_OPTIONS
block|,
name|opt_force
block|}
block|}
block|,
block|{
literal|"propget"
block|,
name|svn_cl__propget
block|,
block|{
literal|"pget"
block|,
literal|"pg"
block|}
block|,
name|N_
argument_list|(
literal|"Print the value of a property on files, dirs, or revisions.\n"
literal|"usage: 1. propget PROPNAME [TARGET[@REV]...]\n"
literal|"       2. propget PROPNAME --revprop -r REV [TARGET]\n"
literal|"\n"
literal|"  1. Prints versioned props. If specified, REV determines in which\n"
literal|"     revision the target is first looked up.\n"
literal|"  2. Prints unversioned remote prop on repos revision.\n"
literal|"     TARGET only determines which repository to access.\n"
literal|"\n"
literal|"  With --verbose, the target path and the property name are printed on\n"
literal|"  separate lines before each value, like 'svn proplist --verbose'.\n"
literal|"  Otherwise, if there is more than one TARGET or a depth other than\n"
literal|"  'empty', the target path is printed on the same line before each value.\n"
literal|"\n"
literal|"  By default, an extra newline is printed after the property value so that\n"
literal|"  the output looks pretty.  With a single TARGET and depth 'empty', you can\n"
literal|"  use the --strict option to disable this (useful when redirecting a binary\n"
literal|"  property value to a file, for example).\n"
argument_list|)
block|,
block|{
literal|'v'
block|,
literal|'R'
block|,
name|opt_depth
block|,
literal|'r'
block|,
name|opt_revprop
block|,
name|opt_strict
block|,
name|opt_xml
block|,
name|opt_changelist
block|,
name|opt_show_inherited_props
block|}
block|,
block|{
block|{
literal|'v'
block|,
name|N_
argument_list|(
literal|"print path, name and value on separate lines"
argument_list|)
block|}
block|,
block|{
name|opt_strict
block|,
name|N_
argument_list|(
literal|"don't print an extra newline"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"proplist"
block|,
name|svn_cl__proplist
block|,
block|{
literal|"plist"
block|,
literal|"pl"
block|}
block|,
name|N_
argument_list|(
literal|"List all properties on files, dirs, or revisions.\n"
literal|"usage: 1. proplist [TARGET[@REV]...]\n"
literal|"       2. proplist --revprop -r REV [TARGET]\n"
literal|"\n"
literal|"  1. Lists versioned props. If specified, REV determines in which\n"
literal|"     revision the target is first looked up.\n"
literal|"  2. Lists unversioned remote props on repos revision.\n"
literal|"     TARGET only determines which repository to access.\n"
literal|"\n"
literal|"  With --verbose, the property values are printed as well, like 'svn propget\n"
literal|"  --verbose'.  With --quiet, the paths are not printed.\n"
argument_list|)
block|,
block|{
literal|'v'
block|,
literal|'R'
block|,
name|opt_depth
block|,
literal|'r'
block|,
literal|'q'
block|,
name|opt_revprop
block|,
name|opt_xml
block|,
name|opt_changelist
block|,
name|opt_show_inherited_props
block|}
block|,
block|{
block|{
literal|'v'
block|,
name|N_
argument_list|(
literal|"print path, name and value on separate lines"
argument_list|)
block|}
block|,
block|{
literal|'q'
block|,
name|N_
argument_list|(
literal|"don't print the path"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"propset"
block|,
name|svn_cl__propset
block|,
block|{
literal|"pset"
block|,
literal|"ps"
block|}
block|,
name|N_
argument_list|(
literal|"Set the value of a property on files, dirs, or revisions.\n"
literal|"usage: 1. propset PROPNAME PROPVAL PATH...\n"
literal|"       2. propset PROPNAME --revprop -r REV PROPVAL [TARGET]\n"
literal|"\n"
literal|"  1. Changes a versioned file or directory property in a working copy.\n"
literal|"  2. Changes an unversioned property on a repository revision.\n"
literal|"     (TARGET only determines which repository to access.)\n"
literal|"\n"
literal|"  The value may be provided with the --file option instead of PROPVAL.\n"
literal|"\n"
literal|"  Property names starting with 'svn:' are reserved.  Subversion recognizes\n"
literal|"  the following special versioned properties on a file:\n"
literal|"    svn:keywords   - Keywords to be expanded.  Valid keywords are:\n"
literal|"      URL, HeadURL             - The URL for the head version of the file.\n"
literal|"      Author, LastChangedBy    - The last person to modify the file.\n"
literal|"      Date, LastChangedDate    - The date/time the file was last modified.\n"
literal|"      Rev, Revision,           - The last revision the file changed.\n"
literal|"        LastChangedRevision\n"
literal|"      Id                       - A compressed summary of the previous four.\n"
literal|"      Header                   - Similar to Id but includes the full URL.\n"
literal|"\n"
literal|"      Custom keywords can be defined with a format string separated from\n"
literal|"      the keyword name with '='. Valid format substitutions are:\n"
literal|"        %a   - The author of the revision given by %r.\n"
literal|"        %b   - The basename of the URL of the file.\n"
literal|"        %d   - Short format of the date of the revision given by %r.\n"
literal|"        %D   - Long format of the date of the revision given by %r.\n"
literal|"        %P   - The file's path, relative to the repository root.\n"
literal|"        %r   - The number of the revision which last changed the file.\n"
literal|"        %R   - The URL to the root of the repository.\n"
literal|"        %u   - The URL of the file.\n"
literal|"        %_   - A space (keyword definitions cannot contain a literal space).\n"
literal|"        %%   - A literal '%'.\n"
literal|"        %H   - Equivalent to %P%_%r%_%d%_%a.\n"
literal|"        %I   - Equivalent to %b%_%r%_%d%_%a.\n"
literal|"      Example custom keyword definition: MyKeyword=%r%_%a%_%P\n"
literal|"      Once a custom keyword has been defined for a file, it can be used\n"
literal|"      within the file like any other keyword: $MyKeyword$\n"
literal|"\n"
literal|"    svn:executable - If present, make the file executable.  Use\n"
literal|"      'svn propdel svn:executable PATH...' to clear.\n"
literal|"    svn:eol-style  - One of 'native', 'LF', 'CR', 'CRLF'.\n"
literal|"    svn:mime-type  - The mimetype of the file.  Used to determine\n"
literal|"      whether to merge the file, and how to serve it from Apache.\n"
literal|"      A mimetype beginning with 'text/' (or an absent mimetype) is\n"
literal|"      treated as text.  Anything else is treated as binary.\n"
literal|"    svn:needs-lock - If present, indicates that the file should be locked\n"
literal|"      before it is modified.  Makes the working copy file read-only\n"
literal|"      when it is not locked.  Use 'svn propdel svn:needs-lock PATH...'\n"
literal|"      to clear.\n"
literal|"\n"
literal|"  Subversion recognizes the following special versioned properties on a\n"
literal|"  directory:\n"
literal|"    svn:ignore         - A list of file glob patterns to ignore, one per line.\n"
literal|"    svn:global-ignores - Like svn:ignore, but inheritable.\n"
literal|"    svn:externals      - A list of module specifiers, one per line, in the\n"
literal|"      following format similar to the syntax of 'svn checkout':\n"
literal|"        [-r REV] URL[@PEG] LOCALPATH\n"
literal|"      Example:\n"
literal|"        http://example.com/repos/zig foo/bar\n"
literal|"      The LOCALPATH is relative to the directory having this property.\n"
literal|"      To pin the external to a known revision, specify the optional REV:\n"
literal|"        -r25 http://example.com/repos/zig foo/bar\n"
literal|"      To unambiguously identify an element at a path which may have been\n"
literal|"      subsequently deleted or renamed, specify the optional PEG revision:\n"
literal|"        -r25 http://example.com/repos/zig@42 foo/bar\n"
literal|"      The URL may be a full URL or a relative URL starting with one of:\n"
literal|"        ../  to the parent directory of the extracted external\n"
literal|"        ^/   to the repository root\n"
literal|"        /    to the server root\n"
literal|"        //   to the URL scheme\n"
literal|"      Use of the following format is discouraged but is supported for\n"
literal|"      interoperability with Subversion 1.4 and earlier clients:\n"
literal|"        LOCALPATH [-r PEG] URL\n"
literal|"      The ambiguous format 'relative_path relative_path' is taken as\n"
literal|"      'relative_url relative_path' with peg revision support.\n"
literal|"      Lines starting with a '#' character are ignored.\n"
argument_list|)
block|,
block|{
literal|'F'
block|,
name|opt_encoding
block|,
literal|'q'
block|,
literal|'r'
block|,
name|opt_targets
block|,
literal|'R'
block|,
name|opt_depth
block|,
name|opt_revprop
block|,
name|opt_force
block|,
name|opt_changelist
block|}
block|,
block|{
block|{
literal|'F'
block|,
name|N_
argument_list|(
literal|"read property value from file ARG"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"relocate"
block|,
name|svn_cl__relocate
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Relocate the working copy to point to a different repository root URL.\n"
literal|"usage: 1. relocate FROM-PREFIX TO-PREFIX [PATH...]\n"
literal|"       2. relocate TO-URL [PATH]\n"
literal|"\n"
literal|"  Rewrite working copy URL metadata to reflect a syntactic change only.\n"
literal|"  This is used when a repository's root URL changes (such as a scheme\n"
literal|"  or hostname change) but your working copy still reflects the same\n"
literal|"  directory within the same repository.\n"
literal|"\n"
literal|"  1. FROM-PREFIX and TO-PREFIX are initial substrings of the working\n"
literal|"     copy's current and new URLs, respectively.  (You may specify the\n"
literal|"     complete old and new URLs if you wish.)  Use 'svn info' to determine\n"
literal|"     the current working copy URL.\n"
literal|"\n"
literal|"  2. TO-URL is the (complete) new repository URL to use for PATH.\n"
literal|"\n"
literal|"  Examples:\n"
literal|"    svn relocate http:// svn:// project1 project2\n"
literal|"    svn relocate http://www.example.com/repo/project \\\n"
literal|"                 svn://svn.example.com/repo/project\n"
argument_list|)
block|,
block|{
name|opt_ignore_externals
block|}
block|}
block|,
block|{
literal|"resolve"
block|,
name|svn_cl__resolve
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Resolve conflicts on working copy files or directories.\n"
literal|"usage: resolve [PATH...]\n"
literal|"\n"
literal|"  By default, perform interactive conflict resolution on PATH.\n"
literal|"  In this mode, the command is recursive by default (depth 'infinity').\n"
literal|"\n"
literal|"  The --accept=ARG option prevents interactive prompting and forces\n"
literal|"  conflicts on PATH to be resolved in the manner specified by ARG.\n"
literal|"  In this mode, the command is not recursive by default (depth 'empty').\n"
argument_list|)
block|,
block|{
name|opt_targets
block|,
literal|'R'
block|,
name|opt_depth
block|,
literal|'q'
block|,
name|opt_accept
block|}
block|,
block|{
block|{
name|opt_accept
block|,
name|N_
argument_list|(
literal|"specify automatic conflict resolution source\n"
literal|"                             "
literal|"('base', 'working', 'mine-conflict',\n"
literal|"                             "
literal|"'theirs-conflict', 'mine-full', 'theirs-full')"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"resolved"
block|,
name|svn_cl__resolved
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Remove 'conflicted' state on working copy files or directories.\n"
literal|"usage: resolved PATH...\n"
literal|"\n"
literal|"  Note:  this subcommand does not semantically resolve conflicts or\n"
literal|"  remove conflict markers; it merely removes the conflict-related\n"
literal|"  artifact files and allows PATH to be committed again.  It has been\n"
literal|"  deprecated in favor of running 'svn resolve --accept working'.\n"
argument_list|)
block|,
block|{
name|opt_targets
block|,
literal|'R'
block|,
name|opt_depth
block|,
literal|'q'
block|}
block|}
block|,
block|{
literal|"revert"
block|,
name|svn_cl__revert
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Restore pristine working copy state (undo local changes).\n"
literal|"usage: revert PATH...\n"
literal|"\n"
literal|"  Revert changes in the working copy at or within PATH, and remove\n"
literal|"  conflict markers as well, if any.\n"
literal|"\n"
literal|"  This subcommand does not revert already committed changes.\n"
literal|"  For information about undoing already committed changes, search\n"
literal|"  the output of 'svn help merge' for 'undo'.\n"
argument_list|)
block|,
block|{
name|opt_targets
block|,
literal|'R'
block|,
name|opt_depth
block|,
literal|'q'
block|,
name|opt_changelist
block|}
block|}
block|,
block|{
literal|"status"
block|,
name|svn_cl__status
block|,
block|{
literal|"stat"
block|,
literal|"st"
block|}
block|,
name|N_
argument_list|(
literal|"Print the status of working copy files and directories.\n"
literal|"usage: status [PATH...]\n"
literal|"\n"
literal|"  With no args, print only locally modified items (no network access).\n"
literal|"  With -q, print only summary information about locally modified items.\n"
literal|"  With -u, add working revision and server out-of-date information.\n"
literal|"  With -v, print full revision information on every item.\n"
literal|"\n"
literal|"  The first seven columns in the output are each one character wide:\n"
literal|"    First column: Says if item was added, deleted, or otherwise changed\n"
literal|"      ' ' no modifications\n"
literal|"      'A' Added\n"
literal|"      'C' Conflicted\n"
literal|"      'D' Deleted\n"
literal|"      'I' Ignored\n"
literal|"      'M' Modified\n"
literal|"      'R' Replaced\n"
literal|"      'X' an unversioned directory created by an externals definition\n"
literal|"      '?' item is not under version control\n"
literal|"      '!' item is missing (removed by non-svn command) or incomplete\n"
literal|"      '~' versioned item obstructed by some item of a different kind\n"
literal|"    Second column: Modifications of a file's or directory's properties\n"
literal|"      ' ' no modifications\n"
literal|"      'C' Conflicted\n"
literal|"      'M' Modified\n"
literal|"    Third column: Whether the working copy is locked for writing by\n"
literal|"                  another Subversion client modifying the working copy\n"
literal|"      ' ' not locked for writing\n"
literal|"      'L' locked for writing\n"
literal|"    Fourth column: Scheduled commit will contain addition-with-history\n"
literal|"      ' ' no history scheduled with commit\n"
literal|"      '+' history scheduled with commit\n"
literal|"    Fifth column: Whether the item is switched or a file external\n"
literal|"      ' ' normal\n"
literal|"      'S' the item has a Switched URL relative to the parent\n"
literal|"      'X' a versioned file created by an eXternals definition\n"
literal|"    Sixth column: Whether the item is locked in repository for exclusive commit\n"
literal|"      (without -u)\n"
literal|"      ' ' not locked by this working copy\n"
literal|"      'K' locked by this working copy, but lock might be stolen or broken\n"
literal|"      (with -u)\n"
literal|"      ' ' not locked in repository, not locked by this working copy\n"
literal|"      'K' locked in repository, lock owned by this working copy\n"
literal|"      'O' locked in repository, lock owned by another working copy\n"
literal|"      'T' locked in repository, lock owned by this working copy was stolen\n"
literal|"      'B' not locked in repository, lock owned by this working copy is broken\n"
literal|"    Seventh column: Whether the item is the victim of a tree conflict\n"
literal|"      ' ' normal\n"
literal|"      'C' tree-Conflicted\n"
literal|"    If the item is a tree conflict victim, an additional line is printed\n"
literal|"    after the item's status line, explaining the nature of the conflict.\n"
literal|"\n"
literal|"  The out-of-date information appears in the ninth column (with -u):\n"
literal|"      '*' a newer revision exists on the server\n"
literal|"      ' ' the working copy is up to date\n"
literal|"\n"
literal|"  Remaining fields are variable width and delimited by spaces:\n"
literal|"    The working revision (with -u or -v; '-' if the item is copied)\n"
literal|"    The last committed revision and last committed author (with -v)\n"
literal|"    The working copy path is always the final field, so it can\n"
literal|"      include spaces.\n"
literal|"\n"
literal|"  The presence of a question mark ('?') where a working revision, last\n"
literal|"  committed revision, or last committed author was expected indicates\n"
literal|"  that the information is unknown or irrelevant given the state of the\n"
literal|"  item (for example, when the item is the result of a copy operation).\n"
literal|"  The question mark serves as a visual placeholder to facilitate parsing.\n"
literal|"\n"
literal|"  Example output:\n"
literal|"    svn status wc\n"
literal|"     M      wc/bar.c\n"
literal|"    A  +    wc/qax.c\n"
literal|"\n"
literal|"    svn status -u wc\n"
literal|"     M             965   wc/bar.c\n"
literal|"            *      965   wc/foo.c\n"
literal|"    A  +             -   wc/qax.c\n"
literal|"    Status against revision:   981\n"
literal|"\n"
literal|"    svn status --show-updates --verbose wc\n"
literal|"     M             965      938 kfogel       wc/bar.c\n"
literal|"            *      965      922 sussman      wc/foo.c\n"
literal|"    A  +             -      687 joe          wc/qax.c\n"
literal|"                   965      687 joe          wc/zig.c\n"
literal|"    Status against revision:   981\n"
literal|"\n"
literal|"    svn status\n"
literal|"     M      wc/bar.c\n"
literal|"    !     C wc/qaz.c\n"
literal|">   local missing, incoming edit upon update\n"
literal|"    D       wc/qax.c\n"
argument_list|)
block|,
block|{
literal|'u'
block|,
literal|'v'
block|,
literal|'N'
block|,
name|opt_depth
block|,
literal|'q'
block|,
name|opt_no_ignore
block|,
name|opt_incremental
block|,
name|opt_xml
block|,
name|opt_ignore_externals
block|,
name|opt_changelist
block|}
block|,
block|{
block|{
literal|'q'
block|,
name|N_
argument_list|(
literal|"don't print unversioned items"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"switch"
block|,
name|svn_cl__switch
block|,
block|{
literal|"sw"
block|}
block|,
name|N_
argument_list|(
literal|"Update the working copy to a different URL within the same repository.\n"
literal|"usage: 1. switch URL[@PEGREV] [PATH]\n"
literal|"       2. switch --relocate FROM-PREFIX TO-PREFIX [PATH...]\n"
literal|"\n"
literal|"  1. Update the working copy to mirror a new URL within the repository.\n"
literal|"     This behavior is similar to 'svn update', and is the way to\n"
literal|"     move a working copy to a branch or tag within the same repository.\n"
literal|"     If specified, PEGREV determines in which revision the target is first\n"
literal|"     looked up.\n"
literal|"\n"
literal|"     If --force is used, unversioned obstructing paths in the working\n"
literal|"     copy do not automatically cause a failure if the switch attempts to\n"
literal|"     add the same path.  If the obstructing path is the same type (file\n"
literal|"     or directory) as the corresponding path in the repository it becomes\n"
literal|"     versioned but its contents are left 'as-is' in the working copy.\n"
literal|"     This means that an obstructing directory's unversioned children may\n"
literal|"     also obstruct and become versioned.  For files, any content differences\n"
literal|"     between the obstruction and the repository are treated like a local\n"
literal|"     modification to the working copy.  All properties from the repository\n"
literal|"     are applied to the obstructing path.\n"
literal|"\n"
literal|"     Use the --set-depth option to set a new working copy depth on the\n"
literal|"     targets of this operation.\n"
literal|"\n"
literal|"     By default, Subversion will refuse to switch a working copy path to\n"
literal|"     a new URL with which it shares no common version control ancestry.\n"
literal|"     Use the '--ignore-ancestry' option to override this sanity check.\n"
literal|"\n"
literal|"  2. The '--relocate' option is deprecated. This syntax is equivalent to\n"
literal|"     'svn relocate FROM-PREFIX TO-PREFIX [PATH]'.\n"
literal|"\n"
literal|"  See also 'svn help update' for a list of possible characters\n"
literal|"  reporting the action taken.\n"
literal|"\n"
literal|"  Examples:\n"
literal|"    svn switch ^/branches/1.x-release\n"
literal|"    svn switch --relocate http:// svn://\n"
literal|"    svn switch --relocate http://www.example.com/repo/project \\\n"
literal|"                          svn://svn.example.com/repo/project\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'N'
block|,
name|opt_depth
block|,
name|opt_set_depth
block|,
literal|'q'
block|,
name|opt_merge_cmd
block|,
name|opt_relocate
block|,
name|opt_ignore_externals
block|,
name|opt_ignore_ancestry
block|,
name|opt_force
block|,
name|opt_accept
block|}
block|,
block|{
block|{
name|opt_ignore_ancestry
block|,
name|N_
argument_list|(
literal|"allow switching to a node with no common ancestor"
argument_list|)
block|}
block|}
block|}
block|,
block|{
literal|"unlock"
block|,
name|svn_cl__unlock
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Unlock working copy paths or URLs.\n"
literal|"usage: unlock TARGET...\n"
literal|"\n"
literal|"  Use --force to break the lock.\n"
argument_list|)
block|,
block|{
name|opt_targets
block|,
name|opt_force
block|}
block|}
block|,
block|{
literal|"update"
block|,
name|svn_cl__update
block|,
block|{
literal|"up"
block|}
block|,
name|N_
argument_list|(
literal|"Bring changes from the repository into the working copy.\n"
literal|"usage: update [PATH...]\n"
literal|"\n"
literal|"  If no revision is given, bring working copy up-to-date with HEAD rev.\n"
literal|"  Else synchronize working copy to revision given by -r.\n"
literal|"\n"
literal|"  For each updated item a line will be printed with characters reporting\n"
literal|"  the action taken. These characters have the following meaning:\n"
literal|"\n"
literal|"    A  Added\n"
literal|"    D  Deleted\n"
literal|"    U  Updated\n"
literal|"    C  Conflict\n"
literal|"    G  Merged\n"
literal|"    E  Existed\n"
literal|"    R  Replaced\n"
literal|"\n"
literal|"  Characters in the first column report about the item itself.\n"
literal|"  Characters in the second column report about properties of the item.\n"
literal|"  A 'B' in the third column signifies that the lock for the file has\n"
literal|"  been broken or stolen.\n"
literal|"  A 'C' in the fourth column indicates a tree conflict, while a 'C' in\n"
literal|"  the first and second columns indicate textual conflicts in files\n"
literal|"  and in property values, respectively.\n"
literal|"\n"
literal|"  If --force is used, unversioned obstructing paths in the working\n"
literal|"  copy do not automatically cause a failure if the update attempts to\n"
literal|"  add the same path.  If the obstructing path is the same type (file\n"
literal|"  or directory) as the corresponding path in the repository it becomes\n"
literal|"  versioned but its contents are left 'as-is' in the working copy.\n"
literal|"  This means that an obstructing directory's unversioned children may\n"
literal|"  also obstruct and become versioned.  For files, any content differences\n"
literal|"  between the obstruction and the repository are treated like a local\n"
literal|"  modification to the working copy.  All properties from the repository\n"
literal|"  are applied to the obstructing path.  Obstructing paths are reported\n"
literal|"  in the first column with code 'E'.\n"
literal|"\n"
literal|"  If the specified update target is missing from the working copy but its\n"
literal|"  immediate parent directory is present, checkout the target into its\n"
literal|"  parent directory at the specified depth.  If --parents is specified,\n"
literal|"  create any missing parent directories of the target by checking them\n"
literal|"  out, too, at depth=empty.\n"
literal|"\n"
literal|"  Use the --set-depth option to set a new working copy depth on the\n"
literal|"  targets of this operation.\n"
argument_list|)
block|,
block|{
literal|'r'
block|,
literal|'N'
block|,
name|opt_depth
block|,
name|opt_set_depth
block|,
literal|'q'
block|,
name|opt_merge_cmd
block|,
name|opt_force
block|,
name|opt_ignore_externals
block|,
name|opt_changelist
block|,
name|opt_editor_cmd
block|,
name|opt_accept
block|,
name|opt_parents
block|}
block|}
block|,
block|{
literal|"upgrade"
block|,
name|svn_cl__upgrade
block|,
block|{
literal|0
block|}
block|,
name|N_
argument_list|(
literal|"Upgrade the metadata storage format for a working copy.\n"
literal|"usage: upgrade [WCPATH...]\n"
literal|"\n"
literal|"  Local modifications are preserved.\n"
argument_list|)
block|,
block|{
literal|'q'
block|}
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
block|{
literal|0
block|}
block|,
name|NULL
block|,
block|{
literal|0
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Version compatibility check */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|check_lib_versions
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
specifier|const
name|svn_version_checklist_t
name|checklist
index|[]
init|=
block|{
block|{
literal|"svn_subr"
block|,
name|svn_subr_version
block|}
block|,
block|{
literal|"svn_client"
block|,
name|svn_client_version
block|}
block|,
block|{
literal|"svn_wc"
block|,
name|svn_wc_version
block|}
block|,
block|{
literal|"svn_ra"
block|,
name|svn_ra_version
block|}
block|,
block|{
literal|"svn_delta"
block|,
name|svn_delta_version
block|}
block|,
block|{
literal|"svn_diff"
block|,
name|svn_diff_version
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
name|SVN_VERSION_DEFINE
argument_list|(
name|my_version
argument_list|)
expr_stmt|;
return|return
name|svn_ver_check_list2
argument_list|(
operator|&
name|my_version
argument_list|,
name|checklist
argument_list|,
name|svn_ver_equal
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* A flag to see if we've been cancelled by the client or not. */
end_comment

begin_decl_stmt
specifier|static
specifier|volatile
name|sig_atomic_t
name|cancelled
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A signal handler to support cancellation. */
end_comment

begin_function
specifier|static
name|void
name|signal_handler
parameter_list|(
name|int
name|signum
parameter_list|)
block|{
name|apr_signal
argument_list|(
name|signum
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|cancelled
operator|=
name|TRUE
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Our cancellation callback. */
end_comment

begin_function
name|svn_error_t
modifier|*
name|svn_cl__check_cancel
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|)
block|{
if|if
condition|(
name|cancelled
condition|)
return|return
name|svn_error_create
argument_list|(
name|SVN_ERR_CANCELLED
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Caught signal"
argument_list|)
argument_list|)
return|;
else|else
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Add a --search argument to OPT_STATE.  * These options start a new search pattern group. */
end_comment

begin_function
specifier|static
name|void
name|add_search_pattern_group
parameter_list|(
name|svn_cl__opt_state_t
modifier|*
name|opt_state
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
block|{
name|apr_array_header_t
modifier|*
name|group
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|opt_state
operator|->
name|search_patterns
operator|==
name|NULL
condition|)
name|opt_state
operator|->
name|search_patterns
operator|=
name|apr_array_make
argument_list|(
name|result_pool
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_array_header_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|group
operator|=
name|apr_array_make
argument_list|(
name|result_pool
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|APR_ARRAY_PUSH
argument_list|(
name|group
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
operator|=
name|pattern
expr_stmt|;
name|APR_ARRAY_PUSH
argument_list|(
name|opt_state
operator|->
name|search_patterns
argument_list|,
name|apr_array_header_t
operator|*
argument_list|)
operator|=
name|group
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Add a --search-and argument to OPT_STATE.  * These patterns are added to an existing pattern group, if any. */
end_comment

begin_function
specifier|static
name|void
name|add_search_pattern_to_latest_group
parameter_list|(
name|svn_cl__opt_state_t
modifier|*
name|opt_state
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
block|{
name|apr_array_header_t
modifier|*
name|group
decl_stmt|;
if|if
condition|(
name|opt_state
operator|->
name|search_patterns
operator|==
name|NULL
condition|)
block|{
name|add_search_pattern_group
argument_list|(
name|opt_state
argument_list|,
name|pattern
argument_list|,
name|result_pool
argument_list|)
expr_stmt|;
return|return;
block|}
name|group
operator|=
name|APR_ARRAY_IDX
argument_list|(
name|opt_state
operator|->
name|search_patterns
argument_list|,
name|opt_state
operator|->
name|search_patterns
operator|->
name|nelts
operator|-
literal|1
argument_list|,
name|apr_array_header_t
operator|*
argument_list|)
expr_stmt|;
name|APR_ARRAY_PUSH
argument_list|(
name|group
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
operator|=
name|pattern
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*** Main. ***/
end_comment

begin_comment
comment|/* Report and clear the error ERR, and return EXIT_FAILURE. Suppress the  * error message if it is SVN_ERR_IO_PIPE_WRITE_ERROR. */
end_comment

begin_define
define|#
directive|define
name|EXIT_ERROR
parameter_list|(
name|err
parameter_list|)
define|\
value|svn_cmdline_handle_exit_error(err, NULL, "svn: ")
end_define

begin_comment
comment|/* A redefinition of the public SVN_INT_ERR macro, that suppresses the  * error message if it is SVN_ERR_IO_PIPE_WRITE_ERROR. */
end_comment

begin_undef
undef|#
directive|undef
name|SVN_INT_ERR
end_undef

begin_define
define|#
directive|define
name|SVN_INT_ERR
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {                                                           \     svn_error_t *svn_err__temp = (expr);                         \     if (svn_err__temp)                                           \       return EXIT_ERROR(svn_err__temp);                          \   } while (0)
end_define

begin_function
specifier|static
name|int
name|sub_main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
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
name|int
name|opt_id
decl_stmt|;
name|apr_getopt_t
modifier|*
name|os
decl_stmt|;
name|svn_cl__opt_state_t
name|opt_state
init|=
block|{
literal|0
block|,
block|{
literal|0
block|}
block|}
decl_stmt|;
name|svn_client_ctx_t
modifier|*
name|ctx
decl_stmt|;
name|apr_array_header_t
modifier|*
name|received_opts
decl_stmt|;
name|int
name|i
decl_stmt|;
specifier|const
name|svn_opt_subcommand_desc2_t
modifier|*
name|subcommand
init|=
name|NULL
decl_stmt|;
specifier|const
name|char
modifier|*
name|dash_m_arg
init|=
name|NULL
decl_stmt|,
modifier|*
name|dash_F_arg
init|=
name|NULL
decl_stmt|;
name|svn_cl__cmd_baton_t
name|command_baton
decl_stmt|;
name|svn_auth_baton_t
modifier|*
name|ab
decl_stmt|;
name|svn_config_t
modifier|*
name|cfg_config
decl_stmt|;
name|svn_boolean_t
name|descend
init|=
name|TRUE
decl_stmt|;
name|svn_boolean_t
name|interactive_conflicts
init|=
name|FALSE
decl_stmt|;
name|svn_boolean_t
name|force_interactive
init|=
name|FALSE
decl_stmt|;
name|svn_cl__conflict_stats_t
modifier|*
name|conflict_stats
init|=
name|svn_cl__conflict_stats_create
argument_list|(
name|pool
argument_list|)
decl_stmt|;
name|svn_boolean_t
name|use_notifier
init|=
name|TRUE
decl_stmt|;
name|svn_boolean_t
name|reading_file_from_stdin
init|=
name|FALSE
decl_stmt|;
name|apr_hash_t
modifier|*
name|changelists
decl_stmt|;
name|apr_hash_t
modifier|*
name|cfg_hash
decl_stmt|;
name|received_opts
operator|=
name|apr_array_make
argument_list|(
name|pool
argument_list|,
name|SVN_OPT_MAX_OPTIONS
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Check library versions */
name|SVN_INT_ERR
argument_list|(
name|check_lib_versions
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
comment|/* Set the working copy administrative directory name. */
if|if
condition|(
name|getenv
argument_list|(
literal|"SVN_ASP_DOT_NET_HACK"
argument_list|)
condition|)
block|{
name|SVN_INT_ERR
argument_list|(
name|svn_wc_set_adm_dir
argument_list|(
literal|"_svn"
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* Initialize the RA library. */
name|SVN_INT_ERR
argument_list|(
name|svn_ra_initialize
argument_list|(
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Init our changelists hash. */
name|changelists
operator|=
name|apr_hash_make
argument_list|(
name|pool
argument_list|)
expr_stmt|;
comment|/* Begin processing arguments. */
name|opt_state
operator|.
name|start_revision
operator|.
name|kind
operator|=
name|svn_opt_revision_unspecified
expr_stmt|;
name|opt_state
operator|.
name|end_revision
operator|.
name|kind
operator|=
name|svn_opt_revision_unspecified
expr_stmt|;
name|opt_state
operator|.
name|revision_ranges
operator|=
name|apr_array_make
argument_list|(
name|pool
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|svn_opt_revision_range_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|opt_state
operator|.
name|depth
operator|=
name|svn_depth_unknown
expr_stmt|;
name|opt_state
operator|.
name|set_depth
operator|=
name|svn_depth_unknown
expr_stmt|;
name|opt_state
operator|.
name|accept_which
operator|=
name|svn_cl__accept_unspecified
expr_stmt|;
name|opt_state
operator|.
name|show_revs
operator|=
name|svn_cl__show_revs_invalid
expr_stmt|;
comment|/* No args?  Show usage. */
if|if
condition|(
name|argc
operator|<=
literal|1
condition|)
block|{
name|SVN_INT_ERR
argument_list|(
name|svn_cl__help
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
comment|/* Else, parse options. */
name|SVN_INT_ERR
argument_list|(
name|svn_cmdline__getopt_init
argument_list|(
operator|&
name|os
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|os
operator|->
name|interleave
operator|=
literal|1
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
specifier|const
name|char
modifier|*
name|opt_arg
decl_stmt|;
specifier|const
name|char
modifier|*
name|utf8_opt_arg
decl_stmt|;
comment|/* Parse the next option. */
name|apr_status_t
name|apr_err
init|=
name|apr_getopt_long
argument_list|(
name|os
argument_list|,
name|svn_cl__options
argument_list|,
operator|&
name|opt_id
argument_list|,
operator|&
name|opt_arg
argument_list|)
decl_stmt|;
if|if
condition|(
name|APR_STATUS_IS_EOF
argument_list|(
name|apr_err
argument_list|)
condition|)
break|break;
elseif|else
if|if
condition|(
name|apr_err
condition|)
block|{
name|SVN_INT_ERR
argument_list|(
name|svn_cl__help
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
comment|/* Stash the option code in an array before parsing it. */
name|APR_ARRAY_PUSH
argument_list|(
name|received_opts
argument_list|,
name|int
argument_list|)
operator|=
name|opt_id
expr_stmt|;
switch|switch
condition|(
name|opt_id
condition|)
block|{
case|case
literal|'l'
case|:
block|{
name|err
operator|=
name|svn_cstring_atoi
argument_list|(
operator|&
name|opt_state
operator|.
name|limit
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|err
argument_list|,
name|_
argument_list|(
literal|"Non-numeric limit argument given"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
if|if
condition|(
name|opt_state
operator|.
name|limit
operator|<=
literal|0
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_INCORRECT_PARAMS
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Argument to --limit must be positive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
block|}
break|break;
case|case
literal|'m'
case|:
comment|/* Note that there's no way here to detect if the log message            contains a zero byte -- if it does, then opt_arg will just            be shorter than the user intended.  Oh well. */
name|opt_state
operator|.
name|message
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
name|dash_m_arg
operator|=
name|opt_arg
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
block|{
name|apr_array_header_t
modifier|*
name|change_revs
init|=
name|svn_cstring_split
argument_list|(
name|opt_arg
argument_list|,
literal|", \n\r\t\v"
argument_list|,
name|TRUE
argument_list|,
name|pool
argument_list|)
decl_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|old_target
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Can't specify -c with --old"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|change_revs
operator|->
name|nelts
condition|;
name|i
operator|++
control|)
block|{
name|char
modifier|*
name|end
decl_stmt|;
name|svn_revnum_t
name|changeno
decl_stmt|,
name|changeno_end
decl_stmt|;
specifier|const
name|char
modifier|*
name|change_str
init|=
name|APR_ARRAY_IDX
argument_list|(
name|change_revs
argument_list|,
name|i
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
init|=
name|change_str
decl_stmt|;
name|svn_boolean_t
name|is_negative
decl_stmt|;
comment|/* Check for a leading minus to allow "-c -r42".                * The is_negative flag is used to handle "-c -42" and "-c -r42".                * The "-c r-42" case is handled by strtol() returning a                * negative number. */
name|is_negative
operator|=
operator|(
operator|*
name|s
operator|==
literal|'-'
operator|)
expr_stmt|;
if|if
condition|(
name|is_negative
condition|)
name|s
operator|++
expr_stmt|;
comment|/* Allow any number of 'r's to prefix a revision number. */
while|while
condition|(
operator|*
name|s
operator|==
literal|'r'
condition|)
name|s
operator|++
expr_stmt|;
name|changeno
operator|=
name|changeno_end
operator|=
name|strtol
argument_list|(
name|s
argument_list|,
operator|&
name|end
argument_list|,
literal|10
argument_list|)
expr_stmt|;
if|if
condition|(
name|end
operator|!=
name|s
operator|&&
operator|*
name|end
operator|==
literal|'-'
condition|)
block|{
if|if
condition|(
name|changeno
operator|<
literal|0
operator|||
name|is_negative
condition|)
block|{
name|err
operator|=
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Negative number in range (%s)"
literal|" not supported with -c"
argument_list|)
argument_list|,
name|change_str
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
name|s
operator|=
name|end
operator|+
literal|1
expr_stmt|;
while|while
condition|(
operator|*
name|s
operator|==
literal|'r'
condition|)
name|s
operator|++
expr_stmt|;
name|changeno_end
operator|=
name|strtol
argument_list|(
name|s
argument_list|,
operator|&
name|end
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|end
operator|==
name|change_str
operator|||
operator|*
name|end
operator|!=
literal|'\0'
condition|)
block|{
name|err
operator|=
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Non-numeric change argument (%s) "
literal|"given to -c"
argument_list|)
argument_list|,
name|change_str
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
if|if
condition|(
name|changeno
operator|==
literal|0
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"There is no change 0"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
if|if
condition|(
name|is_negative
condition|)
name|changeno
operator|=
operator|-
name|changeno
expr_stmt|;
comment|/* Figure out the range:                     -c N  -> -r N-1:N                     -c -N -> -r N:N-1                     -c M-N -> -r M-1:N for M< N                     -c M-N -> -r M:N-1 for M> N                     -c -M-N -> error (too confusing/no valid use case)               */
if|if
condition|(
name|changeno
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|changeno
operator|<=
name|changeno_end
condition|)
name|changeno
operator|--
expr_stmt|;
else|else
name|changeno_end
operator|--
expr_stmt|;
block|}
else|else
block|{
name|changeno
operator|=
operator|-
name|changeno
expr_stmt|;
name|changeno_end
operator|=
name|changeno
operator|-
literal|1
expr_stmt|;
block|}
name|opt_state
operator|.
name|used_change_arg
operator|=
name|TRUE
expr_stmt|;
name|APR_ARRAY_PUSH
argument_list|(
name|opt_state
operator|.
name|revision_ranges
argument_list|,
name|svn_opt_revision_range_t
operator|*
argument_list|)
operator|=
name|svn_opt__revision_range_from_revnums
argument_list|(
name|changeno
argument_list|,
name|changeno_end
argument_list|,
name|pool
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|'r'
case|:
name|opt_state
operator|.
name|used_revision_arg
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|svn_opt_parse_revision_to_range
argument_list|(
name|opt_state
operator|.
name|revision_ranges
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|utf8_opt_arg
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|err
operator|=
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Syntax error in revision argument '%s'"
argument_list|)
argument_list|,
name|utf8_opt_arg
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
break|break;
case|case
literal|'v'
case|:
name|opt_state
operator|.
name|verbose
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|opt_state
operator|.
name|update
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
case|case
literal|'?'
case|:
name|opt_state
operator|.
name|help
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'q'
case|:
name|opt_state
operator|.
name|quiet
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_incremental
case|:
name|opt_state
operator|.
name|incremental
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'F'
case|:
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|utf8_opt_arg
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_stringbuf_from_file2
argument_list|(
operator|&
operator|(
name|opt_state
operator|.
name|filedata
operator|)
argument_list|,
name|utf8_opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|reading_file_from_stdin
operator|=
operator|(
name|strcmp
argument_list|(
name|utf8_opt_arg
argument_list|,
literal|"-"
argument_list|)
operator|==
literal|0
operator|)
expr_stmt|;
name|dash_F_arg
operator|=
name|opt_arg
expr_stmt|;
break|break;
case|case
name|opt_targets
case|:
block|{
name|svn_stringbuf_t
modifier|*
name|buffer
decl_stmt|,
modifier|*
name|buffer_utf8
decl_stmt|;
comment|/* We need to convert to UTF-8 now, even before we divide              the targets into an array, because otherwise we wouldn't              know what delimiter to use for svn_cstring_split().  */
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|utf8_opt_arg
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_stringbuf_from_file2
argument_list|(
operator|&
name|buffer
argument_list|,
name|utf8_opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_utf_stringbuf_to_utf8
argument_list|(
operator|&
name|buffer_utf8
argument_list|,
name|buffer
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|opt_state
operator|.
name|targets
operator|=
name|svn_cstring_split
argument_list|(
name|buffer_utf8
operator|->
name|data
argument_list|,
literal|"\n\r"
argument_list|,
name|TRUE
argument_list|,
name|pool
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|opt_force
case|:
name|opt_state
operator|.
name|force
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_force_log
case|:
name|opt_state
operator|.
name|force_log
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_dry_run
case|:
name|opt_state
operator|.
name|dry_run
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_revprop
case|:
name|opt_state
operator|.
name|revprop
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'R'
case|:
name|opt_state
operator|.
name|depth
operator|=
name|svn_depth_infinity
expr_stmt|;
break|break;
case|case
literal|'N'
case|:
name|descend
operator|=
name|FALSE
expr_stmt|;
break|break;
case|case
name|opt_depth
case|:
name|err
operator|=
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|utf8_opt_arg
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
return|return
name|EXIT_ERROR
argument_list|(
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|err
argument_list|,
name|_
argument_list|(
literal|"Error converting depth "
literal|"from locale to UTF-8"
argument_list|)
argument_list|)
argument_list|)
return|;
name|opt_state
operator|.
name|depth
operator|=
name|svn_depth_from_word
argument_list|(
name|utf8_opt_arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|depth
operator|==
name|svn_depth_unknown
operator|||
name|opt_state
operator|.
name|depth
operator|==
name|svn_depth_exclude
condition|)
block|{
return|return
name|EXIT_ERROR
argument_list|(
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"'%s' is not a valid depth; try "
literal|"'empty', 'files', 'immediates', "
literal|"or 'infinity'"
argument_list|)
argument_list|,
name|utf8_opt_arg
argument_list|)
argument_list|)
return|;
block|}
break|break;
case|case
name|opt_set_depth
case|:
name|err
operator|=
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|utf8_opt_arg
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
return|return
name|EXIT_ERROR
argument_list|(
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|err
argument_list|,
name|_
argument_list|(
literal|"Error converting depth "
literal|"from locale to UTF-8"
argument_list|)
argument_list|)
argument_list|)
return|;
name|opt_state
operator|.
name|set_depth
operator|=
name|svn_depth_from_word
argument_list|(
name|utf8_opt_arg
argument_list|)
expr_stmt|;
comment|/* svn_depth_exclude is okay for --set-depth. */
if|if
condition|(
name|opt_state
operator|.
name|set_depth
operator|==
name|svn_depth_unknown
condition|)
block|{
return|return
name|EXIT_ERROR
argument_list|(
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"'%s' is not a valid depth; try "
literal|"'exclude', 'empty', 'files', "
literal|"'immediates', or 'infinity'"
argument_list|)
argument_list|,
name|utf8_opt_arg
argument_list|)
argument_list|)
return|;
block|}
break|break;
case|case
name|opt_version
case|:
name|opt_state
operator|.
name|version
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_auth_username
case|:
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|opt_state
operator|.
name|auth_username
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_auth_password
case|:
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|opt_state
operator|.
name|auth_password
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_encoding
case|:
name|opt_state
operator|.
name|encoding
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_xml
case|:
name|opt_state
operator|.
name|xml
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_stop_on_copy
case|:
name|opt_state
operator|.
name|stop_on_copy
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_strict
case|:
name|opt_state
operator|.
name|strict
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_no_ignore
case|:
name|opt_state
operator|.
name|no_ignore
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_no_auth_cache
case|:
name|opt_state
operator|.
name|no_auth_cache
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_non_interactive
case|:
name|opt_state
operator|.
name|non_interactive
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_force_interactive
case|:
name|force_interactive
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_trust_server_cert
case|:
name|opt_state
operator|.
name|trust_server_cert
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_no_diff_added
case|:
name|opt_state
operator|.
name|diff
operator|.
name|no_diff_added
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_no_diff_deleted
case|:
name|opt_state
operator|.
name|diff
operator|.
name|no_diff_deleted
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_ignore_properties
case|:
name|opt_state
operator|.
name|diff
operator|.
name|ignore_properties
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_show_copies_as_adds
case|:
name|opt_state
operator|.
name|diff
operator|.
name|show_copies_as_adds
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_notice_ancestry
case|:
name|opt_state
operator|.
name|diff
operator|.
name|notice_ancestry
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_ignore_ancestry
case|:
name|opt_state
operator|.
name|ignore_ancestry
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_ignore_externals
case|:
name|opt_state
operator|.
name|ignore_externals
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_relocate
case|:
name|opt_state
operator|.
name|relocate
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|opt_state
operator|.
name|extensions
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_diff_cmd
case|:
name|opt_state
operator|.
name|diff
operator|.
name|diff_cmd
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_merge_cmd
case|:
name|opt_state
operator|.
name|merge_cmd
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_record_only
case|:
name|opt_state
operator|.
name|record_only
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_editor_cmd
case|:
name|opt_state
operator|.
name|editor_cmd
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_old_cmd
case|:
if|if
condition|(
name|opt_state
operator|.
name|used_change_arg
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Can't specify -c with --old"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
name|opt_state
operator|.
name|old_target
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_new_cmd
case|:
name|opt_state
operator|.
name|new_target
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_config_dir
case|:
block|{
specifier|const
name|char
modifier|*
name|path_utf8
decl_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|path_utf8
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|opt_state
operator|.
name|config_dir
operator|=
name|svn_dirent_internal_style
argument_list|(
name|path_utf8
argument_list|,
name|pool
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|opt_config_options
case|:
if|if
condition|(
operator|!
name|opt_state
operator|.
name|config_options
condition|)
name|opt_state
operator|.
name|config_options
operator|=
name|apr_array_make
argument_list|(
name|pool
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|svn_cmdline__config_argument_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|opt_arg
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_cmdline__parse_config_option
argument_list|(
name|opt_state
operator|.
name|config_options
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_autoprops
case|:
name|opt_state
operator|.
name|autoprops
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_no_autoprops
case|:
name|opt_state
operator|.
name|no_autoprops
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_native_eol
case|:
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"LF"
argument_list|,
name|opt_arg
argument_list|)
operator|||
operator|!
name|strcmp
argument_list|(
literal|"CR"
argument_list|,
name|opt_arg
argument_list|)
operator|||
operator|!
name|strcmp
argument_list|(
literal|"CRLF"
argument_list|,
name|opt_arg
argument_list|)
condition|)
name|opt_state
operator|.
name|native_eol
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
else|else
block|{
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|utf8_opt_arg
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|err
operator|=
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Syntax error in native-eol argument '%s'"
argument_list|)
argument_list|,
name|utf8_opt_arg
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
break|break;
case|case
name|opt_no_unlock
case|:
name|opt_state
operator|.
name|no_unlock
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_summarize
case|:
name|opt_state
operator|.
name|diff
operator|.
name|summarize
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_remove
case|:
name|opt_state
operator|.
name|remove
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_changelist
case|:
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|utf8_opt_arg
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|opt_state
operator|.
name|changelist
operator|=
name|utf8_opt_arg
expr_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|changelist
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Changelist names must not be empty"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
name|svn_hash_sets
argument_list|(
name|changelists
argument_list|,
name|opt_state
operator|.
name|changelist
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_keep_changelists
case|:
name|opt_state
operator|.
name|keep_changelists
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_keep_local
case|:
name|opt_state
operator|.
name|keep_local
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_with_all_revprops
case|:
comment|/* If --with-all-revprops is specified along with one or more          * --with-revprops options, --with-all-revprops takes precedence. */
name|opt_state
operator|.
name|all_revprops
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_with_no_revprops
case|:
name|opt_state
operator|.
name|no_revprops
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_with_revprop
case|:
name|SVN_INT_ERR
argument_list|(
name|svn_opt_parse_revprop
argument_list|(
operator|&
name|opt_state
operator|.
name|revprop_table
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_parents
case|:
name|opt_state
operator|.
name|parents
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'g'
case|:
name|opt_state
operator|.
name|use_merge_history
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_accept
case|:
name|opt_state
operator|.
name|accept_which
operator|=
name|svn_cl__accept_from_word
argument_list|(
name|opt_arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|accept_which
operator|==
name|svn_cl__accept_invalid
condition|)
return|return
name|EXIT_ERROR
argument_list|(
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"'%s' is not a valid --accept value"
argument_list|)
argument_list|,
name|opt_arg
argument_list|)
argument_list|)
return|;
break|break;
case|case
name|opt_show_revs
case|:
name|opt_state
operator|.
name|show_revs
operator|=
name|svn_cl__show_revs_from_word
argument_list|(
name|opt_arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|show_revs
operator|==
name|svn_cl__show_revs_invalid
condition|)
return|return
name|EXIT_ERROR
argument_list|(
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"'%s' is not a valid --show-revs value"
argument_list|)
argument_list|,
name|opt_arg
argument_list|)
argument_list|)
return|;
break|break;
case|case
name|opt_reintegrate
case|:
name|opt_state
operator|.
name|reintegrate
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_strip
case|:
block|{
name|err
operator|=
name|svn_cstring_atoi
argument_list|(
operator|&
name|opt_state
operator|.
name|strip
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|err
operator|=
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|err
argument_list|,
name|_
argument_list|(
literal|"Invalid strip count '%s'"
argument_list|)
argument_list|,
name|opt_arg
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
if|if
condition|(
name|opt_state
operator|.
name|strip
operator|<
literal|0
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_INCORRECT_PARAMS
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Argument to --strip must be positive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
block|}
break|break;
case|case
name|opt_ignore_keywords
case|:
name|opt_state
operator|.
name|ignore_keywords
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_reverse_diff
case|:
name|opt_state
operator|.
name|reverse_diff
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_ignore_whitespace
case|:
name|opt_state
operator|.
name|ignore_whitespace
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_diff
case|:
name|opt_state
operator|.
name|show_diff
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_internal_diff
case|:
name|opt_state
operator|.
name|diff
operator|.
name|internal_diff
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_patch_compatible
case|:
name|opt_state
operator|.
name|diff
operator|.
name|patch_compatible
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_use_git_diff_format
case|:
name|opt_state
operator|.
name|diff
operator|.
name|use_git_diff_format
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_allow_mixed_revisions
case|:
name|opt_state
operator|.
name|allow_mixed_rev
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_include_externals
case|:
name|opt_state
operator|.
name|include_externals
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_show_inherited_props
case|:
name|opt_state
operator|.
name|show_inherited_props
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_properties_only
case|:
name|opt_state
operator|.
name|diff
operator|.
name|properties_only
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|opt_search
case|:
name|add_search_pattern_group
argument_list|(
operator|&
name|opt_state
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
expr_stmt|;
break|break;
case|case
name|opt_search_and
case|:
name|add_search_pattern_to_latest_group
argument_list|(
operator|&
name|opt_state
argument_list|,
name|opt_arg
argument_list|,
name|pool
argument_list|)
expr_stmt|;
default|default:
comment|/* Hmmm. Perhaps this would be a good place to squirrel away            opts that commands like svn diff might need. Hmmm indeed. */
break|break;
block|}
block|}
comment|/* The --non-interactive and --force-interactive options are mutually    * exclusive. */
if|if
condition|(
name|opt_state
operator|.
name|non_interactive
operator|&&
name|force_interactive
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--non-interactive and --force-interactive "
literal|"are mutually exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
else|else
name|opt_state
operator|.
name|non_interactive
operator|=
operator|!
name|svn_cmdline__be_interactive
argument_list|(
name|opt_state
operator|.
name|non_interactive
argument_list|,
name|force_interactive
argument_list|)
expr_stmt|;
comment|/* Turn our hash of changelists into an array of unique ones. */
name|SVN_INT_ERR
argument_list|(
name|svn_hash_keys
argument_list|(
operator|&
operator|(
name|opt_state
operator|.
name|changelists
operator|)
argument_list|,
name|changelists
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* ### This really belongs in libsvn_client.  The trouble is,      there's no one place there to run it from, no      svn_client_init().  We'd have to add it to all the public      functions that a client might call.  It's unmaintainable to do      initialization from within libsvn_client itself, but it seems      burdensome to demand that all clients call svn_client_init()      before calling any other libsvn_client function... On the other      hand, the alternative is effectively to demand that they call      svn_config_ensure() instead, so maybe we should have a generic      init function anyway.  Thoughts?  */
name|SVN_INT_ERR
argument_list|(
name|svn_config_ensure
argument_list|(
name|opt_state
operator|.
name|config_dir
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* If the user asked for help, then the rest of the arguments are      the names of subcommands to get help on (if any), or else they're      just typos/mistakes.  Whatever the case, the subcommand to      actually run is svn_cl__help(). */
if|if
condition|(
name|opt_state
operator|.
name|help
condition|)
name|subcommand
operator|=
name|svn_opt_get_canonical_subcommand2
argument_list|(
name|svn_cl__cmd_table
argument_list|,
literal|"help"
argument_list|)
expr_stmt|;
comment|/* If we're not running the `help' subcommand, then look for a      subcommand in the first argument. */
if|if
condition|(
name|subcommand
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|os
operator|->
name|ind
operator|>=
name|os
operator|->
name|argc
condition|)
block|{
if|if
condition|(
name|opt_state
operator|.
name|version
condition|)
block|{
comment|/* Use the "help" subcommand to handle the "--version" option. */
specifier|static
specifier|const
name|svn_opt_subcommand_desc2_t
name|pseudo_cmd
init|=
block|{
literal|"--version"
block|,
name|svn_cl__help
block|,
block|{
literal|0
block|}
block|,
literal|""
block|,
block|{
name|opt_version
block|,
comment|/* must accept its own option */
literal|'q'
block|,
comment|/* brief output */
literal|'v'
block|,
comment|/* verbose output */
name|opt_config_dir
comment|/* all commands accept this */
block|}
block|}
decl_stmt|;
name|subcommand
operator|=
operator|&
name|pseudo_cmd
expr_stmt|;
block|}
else|else
block|{
name|svn_error_clear
argument_list|(
name|svn_cmdline_fprintf
argument_list|(
name|stderr
argument_list|,
name|pool
argument_list|,
name|_
argument_list|(
literal|"Subcommand argument required\n"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|svn_error_clear
argument_list|(
name|svn_cl__help
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
block|}
else|else
block|{
specifier|const
name|char
modifier|*
name|first_arg
init|=
name|os
operator|->
name|argv
index|[
name|os
operator|->
name|ind
operator|++
index|]
decl_stmt|;
name|subcommand
operator|=
name|svn_opt_get_canonical_subcommand2
argument_list|(
name|svn_cl__cmd_table
argument_list|,
name|first_arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|subcommand
operator|==
name|NULL
condition|)
block|{
specifier|const
name|char
modifier|*
name|first_arg_utf8
decl_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_utf_cstring_to_utf8
argument_list|(
operator|&
name|first_arg_utf8
argument_list|,
name|first_arg
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|svn_error_clear
argument_list|(
name|svn_cmdline_fprintf
argument_list|(
name|stderr
argument_list|,
name|pool
argument_list|,
name|_
argument_list|(
literal|"Unknown subcommand: '%s'\n"
argument_list|)
argument_list|,
name|first_arg_utf8
argument_list|)
argument_list|)
expr_stmt|;
name|svn_error_clear
argument_list|(
name|svn_cl__help
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Be kind to people who try 'svn undo'. */
if|if
condition|(
name|strcmp
argument_list|(
name|first_arg_utf8
argument_list|,
literal|"undo"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|svn_error_clear
argument_list|(
name|svn_cmdline_fprintf
argument_list|(
name|stderr
argument_list|,
name|pool
argument_list|,
name|_
argument_list|(
literal|"Undo is done using either the "
literal|"'svn revert' or the 'svn merge' "
literal|"command.\n"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|EXIT_FAILURE
return|;
block|}
block|}
block|}
comment|/* Check that the subcommand wasn't passed any inappropriate options. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|received_opts
operator|->
name|nelts
condition|;
name|i
operator|++
control|)
block|{
name|opt_id
operator|=
name|APR_ARRAY_IDX
argument_list|(
name|received_opts
argument_list|,
name|i
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|/* All commands implicitly accept --help, so just skip over this          when we see it. Note that we don't want to include this option          in their "accepted options" list because it would be awfully          redundant to display it in every commands' help text. */
if|if
condition|(
name|opt_id
operator|==
literal|'h'
operator|||
name|opt_id
operator|==
literal|'?'
condition|)
continue|continue;
if|if
condition|(
operator|!
name|svn_opt_subcommand_takes_option3
argument_list|(
name|subcommand
argument_list|,
name|opt_id
argument_list|,
name|svn_cl__global_options
argument_list|)
condition|)
block|{
specifier|const
name|char
modifier|*
name|optstr
decl_stmt|;
specifier|const
name|apr_getopt_option_t
modifier|*
name|badopt
init|=
name|svn_opt_get_option_from_code2
argument_list|(
name|opt_id
argument_list|,
name|svn_cl__options
argument_list|,
name|subcommand
argument_list|,
name|pool
argument_list|)
decl_stmt|;
name|svn_opt_format_option
argument_list|(
operator|&
name|optstr
argument_list|,
name|badopt
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|subcommand
operator|->
name|name
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
name|svn_error_clear
argument_list|(
name|svn_cl__help
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|svn_error_clear
argument_list|(
name|svn_cmdline_fprintf
argument_list|(
name|stderr
argument_list|,
name|pool
argument_list|,
name|_
argument_list|(
literal|"Subcommand '%s' doesn't accept option '%s'\n"
literal|"Type 'svn help %s' for usage.\n"
argument_list|)
argument_list|,
name|subcommand
operator|->
name|name
argument_list|,
name|optstr
argument_list|,
name|subcommand
operator|->
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
block|}
comment|/* Only merge and log support multiple revisions/revision ranges. */
if|if
condition|(
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__merge
operator|&&
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__log
condition|)
block|{
if|if
condition|(
name|opt_state
operator|.
name|revision_ranges
operator|->
name|nelts
operator|>
literal|1
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Multiple revision arguments "
literal|"encountered; can't specify -c twice, "
literal|"or both -c and -r"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
block|}
comment|/* Disallow simultaneous use of both --depth and --set-depth. */
if|if
condition|(
operator|(
name|opt_state
operator|.
name|depth
operator|!=
name|svn_depth_unknown
operator|)
operator|&&
operator|(
name|opt_state
operator|.
name|set_depth
operator|!=
name|svn_depth_unknown
operator|)
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--depth and --set-depth are mutually "
literal|"exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* Disallow simultaneous use of both --with-all-revprops and      --with-no-revprops.  */
if|if
condition|(
name|opt_state
operator|.
name|all_revprops
operator|&&
name|opt_state
operator|.
name|no_revprops
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--with-all-revprops and --with-no-revprops "
literal|"are mutually exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* Disallow simultaneous use of both --with-revprop and      --with-no-revprops.  */
if|if
condition|(
name|opt_state
operator|.
name|revprop_table
operator|&&
name|opt_state
operator|.
name|no_revprops
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--with-revprop and --with-no-revprops "
literal|"are mutually exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* Disallow simultaneous use of both -m and -F, when they are      both used to pass a commit message or lock comment.  ('propset'      takes the property value, not a commit message, from -F.)    */
if|if
condition|(
name|opt_state
operator|.
name|filedata
operator|&&
name|opt_state
operator|.
name|message
operator|&&
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__propset
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--message (-m) and --file (-F) "
literal|"are mutually exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* --trust-server-cert can only be used with --non-interactive */
if|if
condition|(
name|opt_state
operator|.
name|trust_server_cert
operator|&&
operator|!
name|opt_state
operator|.
name|non_interactive
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--trust-server-cert requires "
literal|"--non-interactive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* Disallow simultaneous use of both --diff-cmd and      --internal-diff.  */
if|if
condition|(
name|opt_state
operator|.
name|diff
operator|.
name|diff_cmd
operator|&&
name|opt_state
operator|.
name|diff
operator|.
name|internal_diff
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--diff-cmd and --internal-diff "
literal|"are mutually exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* Ensure that 'revision_ranges' has at least one item, and make      'start_revision' and 'end_revision' match that item. */
if|if
condition|(
name|opt_state
operator|.
name|revision_ranges
operator|->
name|nelts
operator|==
literal|0
condition|)
block|{
name|svn_opt_revision_range_t
modifier|*
name|range
init|=
name|apr_palloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|range
argument_list|)
argument_list|)
decl_stmt|;
name|range
operator|->
name|start
operator|.
name|kind
operator|=
name|svn_opt_revision_unspecified
expr_stmt|;
name|range
operator|->
name|end
operator|.
name|kind
operator|=
name|svn_opt_revision_unspecified
expr_stmt|;
name|APR_ARRAY_PUSH
argument_list|(
name|opt_state
operator|.
name|revision_ranges
argument_list|,
name|svn_opt_revision_range_t
operator|*
argument_list|)
operator|=
name|range
expr_stmt|;
block|}
name|opt_state
operator|.
name|start_revision
operator|=
name|APR_ARRAY_IDX
argument_list|(
name|opt_state
operator|.
name|revision_ranges
argument_list|,
literal|0
argument_list|,
name|svn_opt_revision_range_t
operator|*
argument_list|)
operator|->
name|start
expr_stmt|;
name|opt_state
operator|.
name|end_revision
operator|=
name|APR_ARRAY_IDX
argument_list|(
name|opt_state
operator|.
name|revision_ranges
argument_list|,
literal|0
argument_list|,
name|svn_opt_revision_range_t
operator|*
argument_list|)
operator|->
name|end
expr_stmt|;
name|err
operator|=
name|svn_config_get_config
argument_list|(
operator|&
name|cfg_hash
argument_list|,
name|opt_state
operator|.
name|config_dir
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* Fallback to default config if the config directory isn't readable          or is not a directory. */
if|if
condition|(
name|APR_STATUS_IS_EACCES
argument_list|(
name|err
operator|->
name|apr_err
argument_list|)
operator|||
name|SVN__APR_STATUS_IS_ENOTDIR
argument_list|(
name|err
operator|->
name|apr_err
argument_list|)
condition|)
block|{
name|svn_handle_warning2
argument_list|(
name|stderr
argument_list|,
name|err
argument_list|,
literal|"svn: "
argument_list|)
expr_stmt|;
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|cfg_hash
operator|=
name|NULL
expr_stmt|;
block|}
else|else
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* Relocation is infinite-depth only. */
if|if
condition|(
name|opt_state
operator|.
name|relocate
condition|)
block|{
if|if
condition|(
name|opt_state
operator|.
name|depth
operator|!=
name|svn_depth_unknown
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_MUTUALLY_EXCLUSIVE_ARGS
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--relocate and --depth are mutually "
literal|"exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
if|if
condition|(
operator|!
name|descend
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_MUTUALLY_EXCLUSIVE_ARGS
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--relocate and --non-recursive (-N) are mutually "
literal|"exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
block|}
comment|/* Only a few commands can accept a revision range; the rest can take at      most one revision number. */
if|if
condition|(
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__blame
operator|&&
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__diff
operator|&&
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__log
operator|&&
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__mergeinfo
operator|&&
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__merge
condition|)
block|{
if|if
condition|(
name|opt_state
operator|.
name|end_revision
operator|.
name|kind
operator|!=
name|svn_opt_revision_unspecified
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CLIENT_REVISION_RANGE
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
block|}
comment|/* -N has a different meaning depending on the command */
if|if
condition|(
operator|!
name|descend
condition|)
block|{
if|if
condition|(
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__status
condition|)
block|{
name|opt_state
operator|.
name|depth
operator|=
name|svn_depth_immediates
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__revert
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__add
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__commit
condition|)
block|{
comment|/* In pre-1.5 Subversion, some commands treated -N like              --depth=empty, so force that mapping here.  Anyway, with              revert it makes sense to be especially conservative,              since revert can lose data. */
name|opt_state
operator|.
name|depth
operator|=
name|svn_depth_empty
expr_stmt|;
block|}
else|else
block|{
name|opt_state
operator|.
name|depth
operator|=
name|svn_depth_files
expr_stmt|;
block|}
block|}
name|cfg_config
operator|=
name|svn_hash_gets
argument_list|(
name|cfg_hash
argument_list|,
name|SVN_CONFIG_CATEGORY_CONFIG
argument_list|)
expr_stmt|;
comment|/* Update the options in the config */
if|if
condition|(
name|opt_state
operator|.
name|config_options
condition|)
block|{
name|svn_error_clear
argument_list|(
name|svn_cmdline__apply_config_options
argument_list|(
name|cfg_hash
argument_list|,
name|opt_state
operator|.
name|config_options
argument_list|,
literal|"svn: "
argument_list|,
literal|"--config-option"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SVN_CL_NO_EXCLUSIVE_LOCK
argument_list|)
block|{
specifier|const
name|char
modifier|*
name|exclusive_clients_option
decl_stmt|;
name|apr_array_header_t
modifier|*
name|exclusive_clients
decl_stmt|;
name|svn_config_get
argument_list|(
name|cfg_config
argument_list|,
operator|&
name|exclusive_clients_option
argument_list|,
name|SVN_CONFIG_SECTION_WORKING_COPY
argument_list|,
name|SVN_CONFIG_OPTION_SQLITE_EXCLUSIVE_CLIENTS
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|exclusive_clients
operator|=
name|svn_cstring_split
argument_list|(
name|exclusive_clients_option
argument_list|,
literal|" ,"
argument_list|,
name|TRUE
argument_list|,
name|pool
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|exclusive_clients
operator|->
name|nelts
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|exclusive_client
init|=
name|APR_ARRAY_IDX
argument_list|(
name|exclusive_clients
argument_list|,
name|i
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|;
comment|/* This blocks other clients from accessing the wc.db so it must            be explicitly enabled.*/
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|exclusive_client
argument_list|,
literal|"svn"
argument_list|)
condition|)
name|svn_config_set
argument_list|(
name|cfg_config
argument_list|,
name|SVN_CONFIG_SECTION_WORKING_COPY
argument_list|,
name|SVN_CONFIG_OPTION_SQLITE_EXCLUSIVE
argument_list|,
literal|"true"
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* Create a client context object. */
name|command_baton
operator|.
name|opt_state
operator|=
operator|&
name|opt_state
expr_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_client_create_context2
argument_list|(
operator|&
name|ctx
argument_list|,
name|cfg_hash
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|command_baton
operator|.
name|ctx
operator|=
name|ctx
expr_stmt|;
comment|/* If we're running a command that could result in a commit, verify      that any log message we were given on the command line makes      sense (unless we've also been instructed not to care).  This may      access the working copy so do it after setting the locking mode. */
if|if
condition|(
operator|(
operator|!
name|opt_state
operator|.
name|force_log
operator|)
operator|&&
operator|(
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__commit
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__copy
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__delete
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__import
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__mkdir
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__move
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__lock
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__propedit
operator|)
condition|)
block|{
comment|/* If the -F argument is a file that's under revision control,          that's probably not what the user intended. */
if|if
condition|(
name|dash_F_arg
condition|)
block|{
name|svn_node_kind_t
name|kind
decl_stmt|;
specifier|const
name|char
modifier|*
name|local_abspath
decl_stmt|;
specifier|const
name|char
modifier|*
name|fname_utf8
init|=
name|svn_dirent_internal_style
argument_list|(
name|dash_F_arg
argument_list|,
name|pool
argument_list|)
decl_stmt|;
name|err
operator|=
name|svn_dirent_get_absolute
argument_list|(
operator|&
name|local_abspath
argument_list|,
name|fname_utf8
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
block|{
name|err
operator|=
name|svn_wc_read_kind2
argument_list|(
operator|&
name|kind
argument_list|,
name|ctx
operator|->
name|wc_ctx
argument_list|,
name|local_abspath
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
operator|&&
name|kind
operator|!=
name|svn_node_none
operator|&&
name|kind
operator|!=
name|svn_node_unknown
condition|)
block|{
if|if
condition|(
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__lock
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_LOG_MESSAGE_IS_VERSIONED_FILE
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Log message file is a versioned file; "
literal|"use '--force-log' to override"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_LOG_MESSAGE_IS_VERSIONED_FILE
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"Lock comment file is a versioned file; "
literal|"use '--force-log' to override"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
block|}
name|svn_error_clear
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
comment|/* If the -m argument is a file at all, that's probably not what          the user intended. */
if|if
condition|(
name|dash_m_arg
condition|)
block|{
name|apr_finfo_t
name|finfo
decl_stmt|;
if|if
condition|(
name|apr_stat
argument_list|(
operator|&
name|finfo
argument_list|,
name|dash_m_arg
argument_list|,
name|APR_FINFO_MIN
argument_list|,
name|pool
argument_list|)
operator|==
name|APR_SUCCESS
condition|)
block|{
if|if
condition|(
name|subcommand
operator|->
name|cmd_func
operator|!=
name|svn_cl__lock
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_LOG_MESSAGE_IS_PATHNAME
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"The log message is a pathname "
literal|"(was -F intended?); use '--force-log' to override"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_LOG_MESSAGE_IS_PATHNAME
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"The lock comment is a pathname "
literal|"(was -F intended?); use '--force-log' to override"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
block|}
block|}
comment|/* XXX: Only diff_cmd for now, overlay rest later and stop passing      opt_state altogether? */
if|if
condition|(
name|opt_state
operator|.
name|diff
operator|.
name|diff_cmd
condition|)
name|svn_config_set
argument_list|(
name|cfg_config
argument_list|,
name|SVN_CONFIG_SECTION_HELPERS
argument_list|,
name|SVN_CONFIG_OPTION_DIFF_CMD
argument_list|,
name|opt_state
operator|.
name|diff
operator|.
name|diff_cmd
argument_list|)
expr_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|merge_cmd
condition|)
name|svn_config_set
argument_list|(
name|cfg_config
argument_list|,
name|SVN_CONFIG_SECTION_HELPERS
argument_list|,
name|SVN_CONFIG_OPTION_DIFF3_CMD
argument_list|,
name|opt_state
operator|.
name|merge_cmd
argument_list|)
expr_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|diff
operator|.
name|internal_diff
condition|)
name|svn_config_set
argument_list|(
name|cfg_config
argument_list|,
name|SVN_CONFIG_SECTION_HELPERS
argument_list|,
name|SVN_CONFIG_OPTION_DIFF_CMD
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* Check for mutually exclusive args --auto-props and --no-auto-props */
if|if
condition|(
name|opt_state
operator|.
name|autoprops
operator|&&
name|opt_state
operator|.
name|no_autoprops
condition|)
block|{
name|err
operator|=
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_MUTUALLY_EXCLUSIVE_ARGS
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--auto-props and --no-auto-props are "
literal|"mutually exclusive"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
comment|/* Update auto-props-enable option, and populate the MIME types map,      for add/import commands */
if|if
condition|(
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__add
operator|||
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__import
condition|)
block|{
specifier|const
name|char
modifier|*
name|mimetypes_file
decl_stmt|;
name|svn_config_get
argument_list|(
name|cfg_config
argument_list|,
operator|&
name|mimetypes_file
argument_list|,
name|SVN_CONFIG_SECTION_MISCELLANY
argument_list|,
name|SVN_CONFIG_OPTION_MIMETYPES_FILE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|mimetypes_file
operator|&&
operator|*
name|mimetypes_file
condition|)
block|{
name|SVN_INT_ERR
argument_list|(
name|svn_io_parse_mimetypes_file
argument_list|(
operator|&
operator|(
name|ctx
operator|->
name|mimetypes_map
operator|)
argument_list|,
name|mimetypes_file
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|opt_state
operator|.
name|autoprops
condition|)
block|{
name|svn_config_set_bool
argument_list|(
name|cfg_config
argument_list|,
name|SVN_CONFIG_SECTION_MISCELLANY
argument_list|,
name|SVN_CONFIG_OPTION_ENABLE_AUTO_PROPS
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|opt_state
operator|.
name|no_autoprops
condition|)
block|{
name|svn_config_set_bool
argument_list|(
name|cfg_config
argument_list|,
name|SVN_CONFIG_SECTION_MISCELLANY
argument_list|,
name|SVN_CONFIG_OPTION_ENABLE_AUTO_PROPS
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Update the 'keep-locks' runtime option */
if|if
condition|(
name|opt_state
operator|.
name|no_unlock
condition|)
name|svn_config_set_bool
argument_list|(
name|cfg_config
argument_list|,
name|SVN_CONFIG_SECTION_MISCELLANY
argument_list|,
name|SVN_CONFIG_OPTION_NO_UNLOCK
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
comment|/* Set the log message callback function.  Note that individual      subcommands will populate the ctx->log_msg_baton3. */
name|ctx
operator|->
name|log_msg_func3
operator|=
name|svn_cl__get_log_message
expr_stmt|;
comment|/* Set up the notifier.       In general, we use it any time we aren't in --quiet mode.  'svn      status' is unique, though, in that we don't want it in --quiet mode      unless we're also in --verbose mode.  When in --xml mode,      though, we never want it.  */
if|if
condition|(
name|opt_state
operator|.
name|quiet
condition|)
name|use_notifier
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
operator|(
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__status
operator|)
operator|&&
name|opt_state
operator|.
name|verbose
condition|)
name|use_notifier
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|xml
condition|)
name|use_notifier
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
name|use_notifier
condition|)
block|{
name|SVN_INT_ERR
argument_list|(
name|svn_cl__get_notifier
argument_list|(
operator|&
name|ctx
operator|->
name|notify_func2
argument_list|,
operator|&
name|ctx
operator|->
name|notify_baton2
argument_list|,
name|conflict_stats
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Set up our cancellation support. */
name|ctx
operator|->
name|cancel_func
operator|=
name|svn_cl__check_cancel
expr_stmt|;
name|apr_signal
argument_list|(
name|SIGINT
argument_list|,
name|signal_handler
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGBREAK
comment|/* SIGBREAK is a Win32 specific signal generated by ctrl-break. */
name|apr_signal
argument_list|(
name|SIGBREAK
argument_list|,
name|signal_handler
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGHUP
name|apr_signal
argument_list|(
name|SIGHUP
argument_list|,
name|signal_handler
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGTERM
name|apr_signal
argument_list|(
name|SIGTERM
argument_list|,
name|signal_handler
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGPIPE
comment|/* Disable SIGPIPE generation for the platforms that have it. */
name|apr_signal
argument_list|(
name|SIGPIPE
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGXFSZ
comment|/* Disable SIGXFSZ generation for the platforms that have it, otherwise    * working with large files when compiled against an APR that doesn't have    * large file support will crash the program, which is uncool. */
name|apr_signal
argument_list|(
name|SIGXFSZ
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Set up Authentication stuff. */
name|SVN_INT_ERR
argument_list|(
name|svn_cmdline_create_auth_baton
argument_list|(
operator|&
name|ab
argument_list|,
name|opt_state
operator|.
name|non_interactive
argument_list|,
name|opt_state
operator|.
name|auth_username
argument_list|,
name|opt_state
operator|.
name|auth_password
argument_list|,
name|opt_state
operator|.
name|config_dir
argument_list|,
name|opt_state
operator|.
name|no_auth_cache
argument_list|,
name|opt_state
operator|.
name|trust_server_cert
argument_list|,
name|cfg_config
argument_list|,
name|ctx
operator|->
name|cancel_func
argument_list|,
name|ctx
operator|->
name|cancel_baton
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|auth_baton
operator|=
name|ab
expr_stmt|;
if|if
condition|(
name|opt_state
operator|.
name|non_interactive
condition|)
block|{
if|if
condition|(
name|opt_state
operator|.
name|accept_which
operator|==
name|svn_cl__accept_edit
condition|)
return|return
name|EXIT_ERROR
argument_list|(
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--accept=%s incompatible with"
literal|" --non-interactive"
argument_list|)
argument_list|,
name|SVN_CL__ACCEPT_EDIT
argument_list|)
argument_list|)
return|;
if|if
condition|(
name|opt_state
operator|.
name|accept_which
operator|==
name|svn_cl__accept_launch
condition|)
return|return
name|EXIT_ERROR
argument_list|(
name|svn_error_createf
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"--accept=%s incompatible with"
literal|" --non-interactive"
argument_list|)
argument_list|,
name|SVN_CL__ACCEPT_LAUNCH
argument_list|)
argument_list|)
return|;
comment|/* The default action when we're non-interactive is to postpone        * conflict resolution. */
if|if
condition|(
name|opt_state
operator|.
name|accept_which
operator|==
name|svn_cl__accept_unspecified
condition|)
name|opt_state
operator|.
name|accept_which
operator|=
name|svn_cl__accept_postpone
expr_stmt|;
block|}
comment|/* Check whether interactive conflict resolution is disabled by    * the configuration file. If no --accept option was specified    * we postpone all conflicts in this case. */
name|SVN_INT_ERR
argument_list|(
name|svn_config_get_bool
argument_list|(
name|cfg_config
argument_list|,
operator|&
name|interactive_conflicts
argument_list|,
name|SVN_CONFIG_SECTION_MISCELLANY
argument_list|,
name|SVN_CONFIG_OPTION_INTERACTIVE_CONFLICTS
argument_list|,
name|TRUE
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|interactive_conflicts
condition|)
block|{
comment|/* Make 'svn resolve' non-interactive. */
if|if
condition|(
name|subcommand
operator|->
name|cmd_func
operator|==
name|svn_cl__resolve
condition|)
name|opt_state
operator|.
name|non_interactive
operator|=
name|TRUE
expr_stmt|;
comment|/* We're not resolving conflicts interactively. If no --accept option        * was provided the default behaviour is to postpone all conflicts. */
if|if
condition|(
name|opt_state
operator|.
name|accept_which
operator|==
name|svn_cl__accept_unspecified
condition|)
name|opt_state
operator|.
name|accept_which
operator|=
name|svn_cl__accept_postpone
expr_stmt|;
block|}
comment|/* Install the default conflict handler. */
block|{
name|svn_cl__interactive_conflict_baton_t
modifier|*
name|b
decl_stmt|;
name|ctx
operator|->
name|conflict_func
operator|=
name|NULL
expr_stmt|;
name|ctx
operator|->
name|conflict_baton
operator|=
name|NULL
expr_stmt|;
name|ctx
operator|->
name|conflict_func2
operator|=
name|svn_cl__conflict_func_interactive
expr_stmt|;
name|SVN_INT_ERR
argument_list|(
name|svn_cl__get_conflict_func_interactive_baton
argument_list|(
operator|&
name|b
argument_list|,
name|opt_state
operator|.
name|accept_which
argument_list|,
name|ctx
operator|->
name|config
argument_list|,
name|opt_state
operator|.
name|editor_cmd
argument_list|,
name|conflict_stats
argument_list|,
name|ctx
operator|->
name|cancel_func
argument_list|,
name|ctx
operator|->
name|cancel_baton
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|conflict_baton2
operator|=
name|b
expr_stmt|;
block|}
comment|/* And now we finally run the subcommand. */
name|err
operator|=
call|(
modifier|*
name|subcommand
operator|->
name|cmd_func
call|)
argument_list|(
name|os
argument_list|,
operator|&
name|command_baton
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* For argument-related problems, suggest using the 'help'          subcommand. */
if|if
condition|(
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_CL_INSUFFICIENT_ARGS
operator|||
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_CL_ARG_PARSING_ERROR
condition|)
block|{
name|err
operator|=
name|svn_error_quick_wrap
argument_list|(
name|err
argument_list|,
name|apr_psprintf
argument_list|(
name|pool
argument_list|,
name|_
argument_list|(
literal|"Try 'svn help %s' for more information"
argument_list|)
argument_list|,
name|subcommand
operator|->
name|name
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_WC_UPGRADE_REQUIRED
condition|)
block|{
name|err
operator|=
name|svn_error_quick_wrap
argument_list|(
name|err
argument_list|,
name|_
argument_list|(
literal|"Please see the 'svn upgrade' command"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_AUTHN_FAILED
operator|&&
name|opt_state
operator|.
name|non_interactive
condition|)
block|{
name|err
operator|=
name|svn_error_quick_wrap
argument_list|(
name|err
argument_list|,
name|_
argument_list|(
literal|"Authentication failed and interactive"
literal|" prompting is disabled; see the"
literal|" --force-interactive option"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|reading_file_from_stdin
condition|)
name|err
operator|=
name|svn_error_quick_wrap
argument_list|(
name|err
argument_list|,
name|_
argument_list|(
literal|"Reading file from standard input "
literal|"because of -F option; this can "
literal|"interfere with interactive "
literal|"prompting"
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Tell the user about 'svn cleanup' if any error on the stack          was about locked working copies. */
if|if
condition|(
name|svn_error_find_cause
argument_list|(
name|err
argument_list|,
name|SVN_ERR_WC_LOCKED
argument_list|)
condition|)
block|{
name|err
operator|=
name|svn_error_quick_wrap
argument_list|(
name|err
argument_list|,
name|_
argument_list|(
literal|"Run 'svn cleanup' to remove locks "
literal|"(type 'svn help cleanup' for details)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|err
operator|->
name|apr_err
operator|==
name|SVN_ERR_SQLITE_BUSY
condition|)
block|{
name|err
operator|=
name|svn_error_quick_wrap
argument_list|(
name|err
argument_list|,
name|_
argument_list|(
literal|"Another process is blocking the "
literal|"working copy database, or the "
literal|"underlying filesystem does not "
literal|"support file locking; if the working "
literal|"copy is on a network filesystem, make "
literal|"sure file locking has been enabled "
literal|"on the file server"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|svn_error_find_cause
argument_list|(
name|err
argument_list|,
name|SVN_ERR_RA_CANNOT_CREATE_TUNNEL
argument_list|)
operator|&&
operator|(
name|opt_state
operator|.
name|auth_username
operator|||
name|opt_state
operator|.
name|auth_password
operator|)
condition|)
block|{
name|err
operator|=
name|svn_error_quick_wrap
argument_list|(
name|err
argument_list|,
name|_
argument_list|(
literal|"When using svn+ssh:// URLs, keep in mind that the "
literal|"--username and --password options are ignored "
literal|"because authentication is performed by SSH, not "
literal|"Subversion"
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Ensure that stdout is flushed, so the user will see any write errors.          This makes sure that output is not silently lost. */
name|err
operator|=
name|svn_error_compose_create
argument_list|(
name|err
argument_list|,
name|svn_cmdline_fflush
argument_list|(
name|stdout
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_ERROR
argument_list|(
name|err
argument_list|)
return|;
block|}
else|else
block|{
comment|/* Ensure that stdout is flushed, so the user will see any write errors.          This makes sure that output is not silently lost. */
name|SVN_INT_ERR
argument_list|(
name|svn_cmdline_fflush
argument_list|(
name|stdout
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EXIT_SUCCESS
return|;
block|}
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|int
name|exit_code
decl_stmt|;
comment|/* Initialize the app. */
if|if
condition|(
name|svn_cmdline_init
argument_list|(
literal|"svn"
argument_list|,
name|stderr
argument_list|)
operator|!=
name|EXIT_SUCCESS
condition|)
return|return
name|EXIT_FAILURE
return|;
comment|/* Create our top-level pool.  Use a separate mutexless allocator,    * given this application is single threaded.    */
name|pool
operator|=
name|apr_allocator_owner_get
argument_list|(
name|svn_pool_create_allocator
argument_list|(
name|FALSE
argument_list|)
argument_list|)
expr_stmt|;
name|exit_code
operator|=
name|sub_main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|svn_pool_destroy
argument_list|(
name|pool
argument_list|)
expr_stmt|;
return|return
name|exit_code
return|;
block|}
end_function

end_unit

