begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cl.h:  shared stuff in the command line program  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_comment
comment|/* ==================================================================== */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CL_H
end_define

begin_comment
comment|/*** Includes. ***/
end_comment

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_include
include|#
directive|include
file|<apr_getopt.h>
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
file|"svn_string.h"
end_include

begin_include
include|#
directive|include
file|"svn_opt.h"
end_include

begin_include
include|#
directive|include
file|"svn_auth.h"
end_include

begin_include
include|#
directive|include
file|"svn_cmdline.h"
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
comment|/*** Option processing ***/
comment|/* --accept actions */
typedef|typedef
enum|enum
name|svn_cl__accept_t
block|{
comment|/* invalid accept action */
name|svn_cl__accept_invalid
init|=
operator|-
literal|2
block|,
comment|/* unspecified accept action */
name|svn_cl__accept_unspecified
init|=
operator|-
literal|1
block|,
comment|/* Leave conflicts alone, for later resolution. */
name|svn_cl__accept_postpone
block|,
comment|/* Resolve the conflict with the pre-conflict base file. */
name|svn_cl__accept_base
block|,
comment|/* Resolve the conflict with the current working file. */
name|svn_cl__accept_working
block|,
comment|/* Resolve the conflicted hunks by choosing the corresponding text      from the pre-conflict working copy file. */
name|svn_cl__accept_mine_conflict
block|,
comment|/* Resolve the conflicted hunks by choosing the corresponding text      from the post-conflict base copy file. */
name|svn_cl__accept_theirs_conflict
block|,
comment|/* Resolve the conflict by taking the entire pre-conflict working      copy file. */
name|svn_cl__accept_mine_full
block|,
comment|/* Resolve the conflict by taking the entire post-conflict base file. */
name|svn_cl__accept_theirs_full
block|,
comment|/* Launch user's editor and resolve conflict with edited file. */
name|svn_cl__accept_edit
block|,
comment|/* Launch user's resolver and resolve conflict with edited file. */
name|svn_cl__accept_launch
block|}
name|svn_cl__accept_t
typedef|;
comment|/* --accept action user input words */
define|#
directive|define
name|SVN_CL__ACCEPT_POSTPONE
value|"postpone"
define|#
directive|define
name|SVN_CL__ACCEPT_BASE
value|"base"
define|#
directive|define
name|SVN_CL__ACCEPT_WORKING
value|"working"
define|#
directive|define
name|SVN_CL__ACCEPT_MINE_CONFLICT
value|"mine-conflict"
define|#
directive|define
name|SVN_CL__ACCEPT_THEIRS_CONFLICT
value|"theirs-conflict"
define|#
directive|define
name|SVN_CL__ACCEPT_MINE_FULL
value|"mine-full"
define|#
directive|define
name|SVN_CL__ACCEPT_THEIRS_FULL
value|"theirs-full"
define|#
directive|define
name|SVN_CL__ACCEPT_EDIT
value|"edit"
define|#
directive|define
name|SVN_CL__ACCEPT_LAUNCH
value|"launch"
comment|/* Return the svn_cl__accept_t value corresponding to WORD, using exact  * case-sensitive string comparison. Return svn_cl__accept_invalid if WORD  * is empty or is not one of the known values. */
name|svn_cl__accept_t
name|svn_cl__accept_from_word
parameter_list|(
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
comment|/*** Mergeinfo flavors. ***/
comment|/* --show-revs values */
typedef|typedef
enum|enum
name|svn_cl__show_revs_t
block|{
name|svn_cl__show_revs_invalid
init|=
operator|-
literal|1
block|,
name|svn_cl__show_revs_merged
block|,
name|svn_cl__show_revs_eligible
block|}
name|svn_cl__show_revs_t
typedef|;
comment|/* --show-revs user input words */
define|#
directive|define
name|SVN_CL__SHOW_REVS_MERGED
value|"merged"
define|#
directive|define
name|SVN_CL__SHOW_REVS_ELIGIBLE
value|"eligible"
comment|/* Return svn_cl__show_revs_t value corresponding to word. */
name|svn_cl__show_revs_t
name|svn_cl__show_revs_from_word
parameter_list|(
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
comment|/*** Command dispatch. ***/
comment|/* Hold results of option processing that are shared by multiple    commands. */
typedef|typedef
struct|struct
name|svn_cl__opt_state_t
block|{
comment|/* An array of svn_opt_revision_range_t *'s representing revisions      ranges indicated on the command-line via the -r and -c options.      For each range in the list, if only one revision was provided      (-rN), its 'end' member remains 'svn_opt_revision_unspecified'.      This array always has at least one element, even if that is a      null range in which both ends are 'svn_opt_revision_unspecified'. */
name|apr_array_header_t
modifier|*
name|revision_ranges
decl_stmt|;
comment|/* These are simply a copy of the range start and end values present      in the first item of the revision_ranges list. */
name|svn_opt_revision_t
name|start_revision
decl_stmt|;
name|svn_opt_revision_t
name|end_revision
decl_stmt|;
comment|/* Flag which is only set if the '-c' option was used. */
name|svn_boolean_t
name|used_change_arg
decl_stmt|;
comment|/* Flag which is only set if the '-r' option was used. */
name|svn_boolean_t
name|used_revision_arg
decl_stmt|;
comment|/* Max number of log messages to get back from svn_client_log2. */
name|int
name|limit
decl_stmt|;
comment|/* After option processing is done, reflects the switch actually      given on the command line, or svn_depth_unknown if none. */
name|svn_depth_t
name|depth
decl_stmt|;
comment|/* Was --no-unlock specified? */
name|svn_boolean_t
name|no_unlock
decl_stmt|;
specifier|const
name|char
modifier|*
name|message
decl_stmt|;
comment|/* log message */
name|svn_boolean_t
name|force
decl_stmt|;
comment|/* be more forceful, as in "svn rm -f ..." */
name|svn_boolean_t
name|force_log
decl_stmt|;
comment|/* force validity of a suspect log msg file */
name|svn_boolean_t
name|incremental
decl_stmt|;
comment|/* yield output suitable for concatenation */
name|svn_boolean_t
name|quiet
decl_stmt|;
comment|/* sssh...avoid unnecessary output */
name|svn_boolean_t
name|non_interactive
decl_stmt|;
comment|/* do no interactive prompting */
name|svn_boolean_t
name|version
decl_stmt|;
comment|/* print version information */
name|svn_boolean_t
name|verbose
decl_stmt|;
comment|/* be verbose */
name|svn_boolean_t
name|update
decl_stmt|;
comment|/* contact the server for the full story */
name|svn_boolean_t
name|strict
decl_stmt|;
comment|/* do strictly what was requested */
name|svn_stringbuf_t
modifier|*
name|filedata
decl_stmt|;
comment|/* contents of file used as option data */
specifier|const
name|char
modifier|*
name|encoding
decl_stmt|;
comment|/* the locale/encoding of the data*/
name|svn_boolean_t
name|help
decl_stmt|;
comment|/* print usage message */
specifier|const
name|char
modifier|*
name|auth_username
decl_stmt|;
comment|/* auth username */
comment|/* UTF-8! */
specifier|const
name|char
modifier|*
name|auth_password
decl_stmt|;
comment|/* auth password */
comment|/* UTF-8! */
specifier|const
name|char
modifier|*
name|extensions
decl_stmt|;
comment|/* subprocess extension args */
comment|/* UTF-8! */
name|apr_array_header_t
modifier|*
name|targets
decl_stmt|;
comment|/* target list from file */
comment|/* UTF-8! */
name|svn_boolean_t
name|xml
decl_stmt|;
comment|/* output in xml, e.g., "svn log --xml" */
name|svn_boolean_t
name|no_ignore
decl_stmt|;
comment|/* disregard default ignores& svn:ignore's */
name|svn_boolean_t
name|no_auth_cache
decl_stmt|;
comment|/* do not cache authentication information */
struct|struct
block|{
specifier|const
name|char
modifier|*
name|diff_cmd
decl_stmt|;
comment|/* the external diff command to use */
name|svn_boolean_t
name|internal_diff
decl_stmt|;
comment|/* override diff_cmd in config file */
name|svn_boolean_t
name|no_diff_added
decl_stmt|;
comment|/* do not show diffs for deleted files */
name|svn_boolean_t
name|no_diff_deleted
decl_stmt|;
comment|/* do not show diffs for deleted files */
name|svn_boolean_t
name|show_copies_as_adds
decl_stmt|;
comment|/* do not diff copies with their source */
name|svn_boolean_t
name|notice_ancestry
decl_stmt|;
comment|/* notice ancestry for diff-y operations */
name|svn_boolean_t
name|summarize
decl_stmt|;
comment|/* create a summary of a diff */
name|svn_boolean_t
name|use_git_diff_format
decl_stmt|;
comment|/* Use git's extended diff format */
name|svn_boolean_t
name|ignore_properties
decl_stmt|;
comment|/* ignore properties */
name|svn_boolean_t
name|properties_only
decl_stmt|;
comment|/* Show properties only */
name|svn_boolean_t
name|patch_compatible
decl_stmt|;
comment|/* Output compatible with GNU patch */
block|}
name|diff
struct|;
name|svn_boolean_t
name|ignore_ancestry
decl_stmt|;
comment|/* ignore ancestry for merge-y operations */
name|svn_boolean_t
name|ignore_externals
decl_stmt|;
comment|/* ignore externals definitions */
name|svn_boolean_t
name|stop_on_copy
decl_stmt|;
comment|/* don't cross copies during processing */
name|svn_boolean_t
name|dry_run
decl_stmt|;
comment|/* try operation but make no changes */
name|svn_boolean_t
name|revprop
decl_stmt|;
comment|/* operate on a revision property */
specifier|const
name|char
modifier|*
name|merge_cmd
decl_stmt|;
comment|/* the external merge command to use */
specifier|const
name|char
modifier|*
name|editor_cmd
decl_stmt|;
comment|/* the external editor command to use */
name|svn_boolean_t
name|record_only
decl_stmt|;
comment|/* whether to record mergeinfo */
specifier|const
name|char
modifier|*
name|old_target
decl_stmt|;
comment|/* diff target */
specifier|const
name|char
modifier|*
name|new_target
decl_stmt|;
comment|/* diff target */
name|svn_boolean_t
name|relocate
decl_stmt|;
comment|/* rewrite urls (svn switch) */
specifier|const
name|char
modifier|*
name|config_dir
decl_stmt|;
comment|/* over-riding configuration directory */
name|apr_array_header_t
modifier|*
name|config_options
decl_stmt|;
comment|/* over-riding configuration options */
name|svn_boolean_t
name|autoprops
decl_stmt|;
comment|/* enable automatic properties */
name|svn_boolean_t
name|no_autoprops
decl_stmt|;
comment|/* disable automatic properties */
specifier|const
name|char
modifier|*
name|native_eol
decl_stmt|;
comment|/* override system standard eol marker */
name|svn_boolean_t
name|remove
decl_stmt|;
comment|/* deassociate a changelist */
name|apr_array_header_t
modifier|*
name|changelists
decl_stmt|;
comment|/* changelist filters */
specifier|const
name|char
modifier|*
name|changelist
decl_stmt|;
comment|/* operate on this changelist                                     THIS IS TEMPORARY (LAST OF CHANGELISTS) */
name|svn_boolean_t
name|keep_changelists
decl_stmt|;
comment|/* don't remove changelists after commit */
name|svn_boolean_t
name|keep_local
decl_stmt|;
comment|/* delete path only from repository */
name|svn_boolean_t
name|all_revprops
decl_stmt|;
comment|/* retrieve all revprops */
name|svn_boolean_t
name|no_revprops
decl_stmt|;
comment|/* retrieve no revprops */
name|apr_hash_t
modifier|*
name|revprop_table
decl_stmt|;
comment|/* table of revision properties to get/set */
name|svn_boolean_t
name|parents
decl_stmt|;
comment|/* create intermediate directories */
name|svn_boolean_t
name|use_merge_history
decl_stmt|;
comment|/* use/display extra merge information */
name|svn_cl__accept_t
name|accept_which
decl_stmt|;
comment|/* how to handle conflicts */
name|svn_cl__show_revs_t
name|show_revs
decl_stmt|;
comment|/* mergeinfo flavor */
name|svn_depth_t
name|set_depth
decl_stmt|;
comment|/* new sticky ambient depth value */
name|svn_boolean_t
name|reintegrate
decl_stmt|;
comment|/* use "reintegrate" merge-source heuristic */
name|svn_boolean_t
name|trust_server_cert
decl_stmt|;
comment|/* trust server SSL certs that would                                       otherwise be rejected as "untrusted" */
name|int
name|strip
decl_stmt|;
comment|/* number of leading path components to strip */
name|svn_boolean_t
name|ignore_keywords
decl_stmt|;
comment|/* do not expand keywords */
name|svn_boolean_t
name|reverse_diff
decl_stmt|;
comment|/* reverse a diff (e.g. when patching) */
name|svn_boolean_t
name|ignore_whitespace
decl_stmt|;
comment|/* don't account for whitespace when                                       patching */
name|svn_boolean_t
name|show_diff
decl_stmt|;
comment|/* produce diff output (maps to --diff) */
name|svn_boolean_t
name|allow_mixed_rev
decl_stmt|;
comment|/* Allow operation on mixed-revision WC */
name|svn_boolean_t
name|include_externals
decl_stmt|;
comment|/* Recurses (in)to file& dir externals */
name|svn_boolean_t
name|show_inherited_props
decl_stmt|;
comment|/* get inherited properties */
name|apr_array_header_t
modifier|*
name|search_patterns
decl_stmt|;
comment|/* pattern arguments for --search */
block|}
name|svn_cl__opt_state_t
typedef|;
typedef|typedef
struct|struct
name|svn_cl__cmd_baton_t
block|{
name|svn_cl__opt_state_t
modifier|*
name|opt_state
decl_stmt|;
name|svn_client_ctx_t
modifier|*
name|ctx
decl_stmt|;
block|}
name|svn_cl__cmd_baton_t
typedef|;
comment|/* Declare all the command procedures */
name|svn_opt_subcommand_t
name|svn_cl__add
decl_stmt|,
name|svn_cl__blame
decl_stmt|,
name|svn_cl__cat
decl_stmt|,
name|svn_cl__changelist
decl_stmt|,
name|svn_cl__checkout
decl_stmt|,
name|svn_cl__cleanup
decl_stmt|,
name|svn_cl__commit
decl_stmt|,
name|svn_cl__copy
decl_stmt|,
name|svn_cl__delete
decl_stmt|,
name|svn_cl__diff
decl_stmt|,
name|svn_cl__export
decl_stmt|,
name|svn_cl__help
decl_stmt|,
name|svn_cl__import
decl_stmt|,
name|svn_cl__info
decl_stmt|,
name|svn_cl__lock
decl_stmt|,
name|svn_cl__log
decl_stmt|,
name|svn_cl__list
decl_stmt|,
name|svn_cl__merge
decl_stmt|,
name|svn_cl__mergeinfo
decl_stmt|,
name|svn_cl__mkdir
decl_stmt|,
name|svn_cl__move
decl_stmt|,
name|svn_cl__patch
decl_stmt|,
name|svn_cl__propdel
decl_stmt|,
name|svn_cl__propedit
decl_stmt|,
name|svn_cl__propget
decl_stmt|,
name|svn_cl__proplist
decl_stmt|,
name|svn_cl__propset
decl_stmt|,
name|svn_cl__relocate
decl_stmt|,
name|svn_cl__revert
decl_stmt|,
name|svn_cl__resolve
decl_stmt|,
name|svn_cl__resolved
decl_stmt|,
name|svn_cl__status
decl_stmt|,
name|svn_cl__switch
decl_stmt|,
name|svn_cl__unlock
decl_stmt|,
name|svn_cl__update
decl_stmt|,
name|svn_cl__upgrade
decl_stmt|;
comment|/* See definition in svn.c for documentation. */
specifier|extern
specifier|const
name|svn_opt_subcommand_desc2_t
name|svn_cl__cmd_table
index|[]
decl_stmt|;
comment|/* See definition in svn.c for documentation. */
specifier|extern
specifier|const
name|int
name|svn_cl__global_options
index|[]
decl_stmt|;
comment|/* See definition in svn.c for documentation. */
specifier|extern
specifier|const
name|apr_getopt_option_t
name|svn_cl__options
index|[]
decl_stmt|;
comment|/* A helper for the many subcommands that wish to merely warn when  * invoked on an unversioned, nonexistent, or otherwise innocuously  * errorful resource.  Meant to be wrapped with SVN_ERR().  *  * If ERR is null, return SVN_NO_ERROR.  *  * Else if ERR->apr_err is one of the error codes supplied in varargs,  * then handle ERR as a warning (unless QUIET is true), clear ERR, and  * return SVN_NO_ERROR, and push the value of ERR->apr_err into the  * ERRORS_SEEN array, if ERRORS_SEEN is not NULL.  *  * Else return ERR.  *  * Typically, error codes like SVN_ERR_UNVERSIONED_RESOURCE,  * SVN_ERR_ENTRY_NOT_FOUND, etc, are supplied in varargs.  Don't  * forget to terminate the argument list with SVN_NO_ERROR.  */
name|svn_error_t
modifier|*
name|svn_cl__try
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|,
name|apr_array_header_t
modifier|*
name|errors_seen
parameter_list|,
name|svn_boolean_t
name|quiet
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/* Our cancellation callback. */
name|svn_error_t
modifier|*
name|svn_cl__check_cancel
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/* Various conflict-resolution callbacks. */
comment|/* Opaque baton type for svn_cl__conflict_func_interactive(). */
typedef|typedef
name|struct
name|svn_cl__interactive_conflict_baton_t
name|svn_cl__interactive_conflict_baton_t
typedef|;
comment|/* Conflict stats for operations such as update and merge. */
typedef|typedef
name|struct
name|svn_cl__conflict_stats_t
name|svn_cl__conflict_stats_t
typedef|;
comment|/* Return a new, initialized, conflict stats structure, allocated in  * POOL. */
name|svn_cl__conflict_stats_t
modifier|*
name|svn_cl__conflict_stats_create
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Update CONFLICT_STATS to reflect that a conflict on PATH_LOCAL of kind  * CONFLICT_KIND is resolved.  (There is no support for updating the  * 'skipped paths' stats, since skips cannot be 'resolved'.) */
name|void
name|svn_cl__conflict_stats_resolved
parameter_list|(
name|svn_cl__conflict_stats_t
modifier|*
name|conflict_stats
parameter_list|,
specifier|const
name|char
modifier|*
name|path_local
parameter_list|,
name|svn_wc_conflict_kind_t
name|conflict_kind
parameter_list|)
function_decl|;
comment|/* Create and return an baton for use with svn_cl__conflict_func_interactive  * in *B, allocated from RESULT_POOL, and initialised with the values  * ACCEPT_WHICH, CONFIG, EDITOR_CMD, CANCEL_FUNC and CANCEL_BATON. */
name|svn_error_t
modifier|*
name|svn_cl__get_conflict_func_interactive_baton
parameter_list|(
name|svn_cl__interactive_conflict_baton_t
modifier|*
modifier|*
name|b
parameter_list|,
name|svn_cl__accept_t
name|accept_which
parameter_list|,
name|apr_hash_t
modifier|*
name|config
parameter_list|,
specifier|const
name|char
modifier|*
name|editor_cmd
parameter_list|,
name|svn_cl__conflict_stats_t
modifier|*
name|conflict_stats
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
name|result_pool
parameter_list|)
function_decl|;
comment|/* A callback capable of doing interactive conflict resolution.     The BATON must come from svn_cl__get_conflict_func_interactive_baton().    Resolves based on the --accept option if one was given to that function,    otherwise prompts the user to choose one of the three fulltexts, edit    the merged file on the spot, or just skip the conflict (to be resolved    later), among other options.     Implements svn_wc_conflict_resolver_func2_t.  */
name|svn_error_t
modifier|*
name|svn_cl__conflict_func_interactive
parameter_list|(
name|svn_wc_conflict_result_t
modifier|*
modifier|*
name|result
parameter_list|,
specifier|const
name|svn_wc_conflict_description2_t
modifier|*
name|desc
parameter_list|,
name|void
modifier|*
name|baton
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
comment|/*** Command-line output functions -- printing to the user. ***/
comment|/* Print out commit information found in COMMIT_INFO to the console.  * POOL is used for temporay allocations.  * COMMIT_INFO should not be NULL.  *  * This function implements svn_commit_callback2_t.  */
name|svn_error_t
modifier|*
name|svn_cl__print_commit_info
parameter_list|(
specifier|const
name|svn_commit_info_t
modifier|*
name|commit_info
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
comment|/* Convert the date in DATA to a human-readable UTF-8-encoded string  * *HUMAN_CSTRING, or set the latter to "(invalid date)" if DATA is not  * a valid date.  DATA should be as expected by svn_time_from_cstring().  *  * Do all allocations in POOL.  */
name|svn_error_t
modifier|*
name|svn_cl__time_cstring_to_human_cstring
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|human_cstring
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Print STATUS for PATH to stdout for human consumption.  Prints in    abbreviated format by default, or DETAILED format if flag is set.     When SUPPRESS_EXTERNALS_PLACEHOLDERS is set, avoid printing    externals placeholder lines ("X lines").     When DETAILED is set, use SHOW_LAST_COMMITTED to toggle display of    the last-committed-revision and last-committed-author.     If SKIP_UNRECOGNIZED is TRUE, this function will not print out    unversioned items found in the working copy.     When DETAILED is set, and REPOS_LOCKS is set, treat missing repository locks    as broken WC locks.     Increment *TEXT_CONFLICTS, *PROP_CONFLICTS, or *TREE_CONFLICTS if    a conflict was encountered.     Use TARGET_ABSPATH and TARGET_PATH to shorten PATH into something    relative to the target as necessary. */
name|svn_error_t
modifier|*
name|svn_cl__print_status
parameter_list|(
specifier|const
name|char
modifier|*
name|target_abspath
parameter_list|,
specifier|const
name|char
modifier|*
name|target_path
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|svn_client_status_t
modifier|*
name|status
parameter_list|,
name|svn_boolean_t
name|suppress_externals_placeholders
parameter_list|,
name|svn_boolean_t
name|detailed
parameter_list|,
name|svn_boolean_t
name|show_last_committed
parameter_list|,
name|svn_boolean_t
name|skip_unrecognized
parameter_list|,
name|svn_boolean_t
name|repos_locks
parameter_list|,
name|unsigned
name|int
modifier|*
name|text_conflicts
parameter_list|,
name|unsigned
name|int
modifier|*
name|prop_conflicts
parameter_list|,
name|unsigned
name|int
modifier|*
name|tree_conflicts
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Print STATUS for PATH in XML to stdout.  Use POOL for temporary    allocations.     Use TARGET_ABSPATH and TARGET_PATH to shorten PATH into something    relative to the target as necessary.  */
name|svn_error_t
modifier|*
name|svn_cl__print_status_xml
parameter_list|(
specifier|const
name|char
modifier|*
name|target_abspath
parameter_list|,
specifier|const
name|char
modifier|*
name|target_path
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|svn_client_status_t
modifier|*
name|status
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Output a commit xml element to *OUTSTR.  If *OUTSTR is NULL, allocate it    first from POOL, otherwise append to it.  If AUTHOR or DATE is    NULL, it will be omitted. */
name|void
name|svn_cl__print_xml_commit
parameter_list|(
name|svn_stringbuf_t
modifier|*
modifier|*
name|outstr
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
specifier|const
name|char
modifier|*
name|author
parameter_list|,
specifier|const
name|char
modifier|*
name|date
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Output an XML "<lock>" element describing LOCK to *OUTSTR.  If *OUTSTR is    NULL, allocate it first from POOL, otherwise append to it. */
name|void
name|svn_cl__print_xml_lock
parameter_list|(
name|svn_stringbuf_t
modifier|*
modifier|*
name|outstr
parameter_list|,
specifier|const
name|svn_lock_t
modifier|*
name|lock
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Do the following things that are commonly required before accessing revision    properties.  Ensure that REVISION is specified explicitly and is not    relative to a working-copy item.  Ensure that exactly one target is    specified in TARGETS.  Set *URL to the URL of the target.  Return an    appropriate error if any of those checks or operations fail. Use CTX for    accessing the working copy  */
name|svn_error_t
modifier|*
name|svn_cl__revprop_prepare
parameter_list|(
specifier|const
name|svn_opt_revision_t
modifier|*
name|revision
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|targets
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|URL
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Search for a merge tool command in environment variables,    and use it to perform the merge of the four given files.    WC_PATH is the path of the file that is in conflict, relative    to the merge target.    Use POOL for all allocations.     CONFIG is a hash of svn_config_t * items keyed on a configuration    category (SVN_CONFIG_CATEGORY_CONFIG et al), and may be NULL.     Upon success, set *REMAINS_IN_CONFLICT to indicate whether the    merge result contains conflict markers.    */
name|svn_error_t
modifier|*
name|svn_cl__merge_file_externally
parameter_list|(
specifier|const
name|char
modifier|*
name|base_path
parameter_list|,
specifier|const
name|char
modifier|*
name|their_path
parameter_list|,
specifier|const
name|char
modifier|*
name|my_path
parameter_list|,
specifier|const
name|char
modifier|*
name|merged_path
parameter_list|,
specifier|const
name|char
modifier|*
name|wc_path
parameter_list|,
name|apr_hash_t
modifier|*
name|config
parameter_list|,
name|svn_boolean_t
modifier|*
name|remains_in_conflict
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Like svn_cl__merge_file_externally, but using a built-in merge tool  * with help from an external editor specified by EDITOR_CMD. */
name|svn_error_t
modifier|*
name|svn_cl__merge_file
parameter_list|(
specifier|const
name|char
modifier|*
name|base_path
parameter_list|,
specifier|const
name|char
modifier|*
name|their_path
parameter_list|,
specifier|const
name|char
modifier|*
name|my_path
parameter_list|,
specifier|const
name|char
modifier|*
name|merged_path
parameter_list|,
specifier|const
name|char
modifier|*
name|wc_path
parameter_list|,
specifier|const
name|char
modifier|*
name|path_prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|editor_cmd
parameter_list|,
name|apr_hash_t
modifier|*
name|config
parameter_list|,
name|svn_boolean_t
modifier|*
name|remains_in_conflict
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/*** Notification functions to display results on the terminal. */
comment|/* Set *NOTIFY_FUNC_P and *NOTIFY_BATON_P to a notifier/baton for all  * operations, allocated in POOL.  */
name|svn_error_t
modifier|*
name|svn_cl__get_notifier
parameter_list|(
name|svn_wc_notify_func2_t
modifier|*
name|notify_func_p
parameter_list|,
name|void
modifier|*
modifier|*
name|notify_baton_p
parameter_list|,
name|svn_cl__conflict_stats_t
modifier|*
name|conflict_stats
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Make the notifier for use with BATON print the appropriate summary  * line at the end of the output.  */
name|svn_error_t
modifier|*
name|svn_cl__notifier_mark_checkout
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/* Make the notifier for use with BATON print the appropriate summary  * line at the end of the output.  */
name|svn_error_t
modifier|*
name|svn_cl__notifier_mark_export
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/* Make the notifier for use with BATON print the appropriate notifications  * for a wc to repository copy  */
name|svn_error_t
modifier|*
name|svn_cl__notifier_mark_wc_to_repos_copy
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/* Baton for use with svn_cl__check_externals_failed_notify_wrapper(). */
struct|struct
name|svn_cl__check_externals_failed_notify_baton
block|{
name|svn_wc_notify_func2_t
name|wrapped_func
decl_stmt|;
comment|/* The "real" notify_func2. */
name|void
modifier|*
name|wrapped_baton
decl_stmt|;
comment|/* The "real" notify_func2 baton. */
name|svn_boolean_t
name|had_externals_error
decl_stmt|;
comment|/* Did something fail in an external? */
block|}
struct|;
comment|/* Notification function wrapper (implements `svn_wc_notify_func2_t').    Use with an svn_cl__check_externals_failed_notify_baton BATON. */
name|void
name|svn_cl__check_externals_failed_notify_wrapper
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|svn_wc_notify_t
modifier|*
name|n
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Print the conflict stats accumulated in BATON, which is the  * notifier baton from svn_cl__get_notifier().  * Return any error encountered during printing.  */
name|svn_error_t
modifier|*
name|svn_cl__notifier_print_conflict_stats
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/*** Log message callback stuffs. ***/
comment|/* Allocate in POOL a baton for use with svn_cl__get_log_message().     OPT_STATE is the set of command-line options given.     BASE_DIR is a directory in which to create temporary files if an    external editor is used to edit the log message.  If BASE_DIR is    NULL, the current working directory (`.') will be used, and    therefore the user must have the proper permissions on that    directory.  ### todo: What *should* happen in the NULL case is that    we ask APR to tell us where a suitable tmp directory is (like, /tmp    on Unix and C:\Windows\Temp on Win32 or something), and use it.    But APR doesn't yet have that capability.     CONFIG is a client configuration hash of svn_config_t * items keyed    on config categories, and may be NULL.     NOTE: While the baton itself will be allocated from POOL, the items    add to it are added by reference, not duped into POOL!*/
name|svn_error_t
modifier|*
name|svn_cl__make_log_msg_baton
parameter_list|(
name|void
modifier|*
modifier|*
name|baton
parameter_list|,
name|svn_cl__opt_state_t
modifier|*
name|opt_state
parameter_list|,
specifier|const
name|char
modifier|*
name|base_dir
parameter_list|,
name|apr_hash_t
modifier|*
name|config
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* A function of type svn_client_get_commit_log3_t. */
name|svn_error_t
modifier|*
name|svn_cl__get_log_message
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|log_msg
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|tmp_file
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|commit_items
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
comment|/* Handle the cleanup of a log message, using the data in the    LOG_MSG_BATON, in the face of COMMIT_ERR.  This may mean removing a    temporary file left by an external editor, or it may be a complete    no-op.  COMMIT_ERR may be NULL to indicate to indicate that the    function should act as though no commit error occurred. Use POOL    for temporary allocations.     All error returns from this function are guaranteed to at least    include COMMIT_ERR, and perhaps additional errors attached to the    end of COMMIT_ERR's chain.  */
name|svn_error_t
modifier|*
name|svn_cl__cleanup_log_msg
parameter_list|(
name|void
modifier|*
name|log_msg_baton
parameter_list|,
name|svn_error_t
modifier|*
name|commit_err
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Add a message about --force if appropriate */
name|svn_error_t
modifier|*
name|svn_cl__may_need_force
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|)
function_decl|;
comment|/* Write the STRING to the stdio STREAM, returning an error if it fails.     This function is equal to svn_cmdline_fputs() minus the utf8->local    encoding translation.  */
name|svn_error_t
modifier|*
name|svn_cl__error_checked_fputs
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* If STRING is non-null, append it, wrapped in a simple XML CDATA element    named TAGNAME, to the string SB.  Use POOL for temporary allocations. */
name|void
name|svn_cl__xml_tagged_cdata
parameter_list|(
name|svn_stringbuf_t
modifier|*
modifier|*
name|sb
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
specifier|const
name|char
modifier|*
name|tagname
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
comment|/* Print the XML prolog and document root element start-tag to stdout, using    TAGNAME as the root element name.  Use POOL for temporary allocations. */
name|svn_error_t
modifier|*
name|svn_cl__xml_print_header
parameter_list|(
specifier|const
name|char
modifier|*
name|tagname
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Print the XML document root element end-tag to stdout, using TAGNAME as the    root element name.  Use POOL for temporary allocations. */
name|svn_error_t
modifier|*
name|svn_cl__xml_print_footer
parameter_list|(
specifier|const
name|char
modifier|*
name|tagname
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* For use in XML output, return a non-localised string representation  * of KIND, being "none" or "dir" or "file" or, in any other case,  * the empty string. */
specifier|const
name|char
modifier|*
name|svn_cl__node_kind_str_xml
parameter_list|(
name|svn_node_kind_t
name|kind
parameter_list|)
function_decl|;
comment|/* Return a (possibly localised) string representation of KIND, being "none" or    "dir" or "file" or, in any other case, the empty string. */
specifier|const
name|char
modifier|*
name|svn_cl__node_kind_str_human_readable
parameter_list|(
name|svn_node_kind_t
name|kind
parameter_list|)
function_decl|;
comment|/** Provides an XML name for a given OPERATION.  * Note: POOL is currently not used.  */
specifier|const
name|char
modifier|*
name|svn_cl__operation_str_xml
parameter_list|(
name|svn_wc_operation_t
name|operation
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return a possibly localized human readable string for  * a given OPERATION.  * Note: POOL is currently not used.  */
specifier|const
name|char
modifier|*
name|svn_cl__operation_str_human_readable
parameter_list|(
name|svn_wc_operation_t
name|operation
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* What use is a property name intended for.    Used by svn_cl__check_svn_prop_name to customize error messages. */
typedef|typedef
enum|enum
name|svn_cl__prop_use_e
block|{
name|svn_cl__prop_use_set
block|,
comment|/* setting the property */
name|svn_cl__prop_use_edit
block|,
comment|/* editing the property */
name|svn_cl__prop_use_use
comment|/* using the property name */
block|}
name|svn_cl__prop_use_t
typedef|;
comment|/* If PROPNAME looks like but is not identical to one of the svn:  * poperties, raise an error and suggest a better spelling. Names that  * raise errors look like this:  *  *   - start with svn: but do not exactly match a known property; or,  *   - start with a 3-letter prefix that differs in only one letter  *     from "svn:", and the rest exactly matches a known propery.  *  * If REVPROP is TRUE, only check revision property names; otherwise  * only check node property names.  *  * Use SCRATCH_POOL for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_cl__check_svn_prop_name
parameter_list|(
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
name|svn_boolean_t
name|revprop
parameter_list|,
name|svn_cl__prop_use_t
name|prop_use
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* If PROPNAME is one of the svn: properties with a boolean value, and  * PROPVAL looks like an attempt to turn the property off (i.e., it's  * "off", "no", "false", or ""), then print a warning to the user that  * setting the property to this value might not do what they expect.  * Perform temporary allocations in POOL.  */
name|void
name|svn_cl__check_boolean_prop_val
parameter_list|(
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
specifier|const
name|char
modifier|*
name|propval
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* De-streamifying wrapper around svn_client_get_changelists(), which    is called for each target in TARGETS to populate *PATHS (a list of    paths assigned to one of the CHANGELISTS.    If all targets are to be included, may set *PATHS to TARGETS without    reallocating. */
name|svn_error_t
modifier|*
name|svn_cl__changelist_paths
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|paths
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|changelists
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|targets
parameter_list|,
name|svn_depth_t
name|depth
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
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
comment|/* Like svn_client_args_to_target_array() but, if the only error is that some  * arguments are reserved file names, then print warning messages for those  * targets, store the rest of the targets in TARGETS_P and return success. */
name|svn_error_t
modifier|*
name|svn_cl__args_to_target_array_print_reserved
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|targets_p
parameter_list|,
name|apr_getopt_t
modifier|*
name|os
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|known_targets
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|svn_boolean_t
name|keep_dest_origpath_on_truepath_collision
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return a string showing NODE's kind, URL and revision, to the extent that  * that information is available in NODE. If NODE itself is NULL, this prints  * just a 'none' node kind.  * WC_REPOS_ROOT_URL should reflect the target working copy's repository  * root URL. If NODE is from that same URL, the printed URL is abbreviated  * to caret notation (^/). WC_REPOS_ROOT_URL may be NULL, in which case  * this function tries to print the conflicted node's complete URL. */
specifier|const
name|char
modifier|*
name|svn_cl__node_description
parameter_list|(
specifier|const
name|svn_wc_conflict_version_t
modifier|*
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|wc_repos_root_URL
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return, in @a *true_targets_p, a shallow copy of @a targets with any  * empty peg revision specifier snipped off the end of each element.  If any  * target has a non-empty peg revision specifier, throw an error.  The user  * may have specified a peg revision where it doesn't make sense to do so,  * or may have forgotten to escape an '@' character in a filename.  *  * This function is useful for subcommands for which peg revisions  * do not make any sense. Such subcommands still need to allow an empty  * peg revision to be specified on the command line so that users of  * the command line client can consistently escape '@' characters  * in filenames by appending an '@' character, regardless of the  * subcommand being used.  *  * It is safe to pass the address of @a targets as @a true_targets_p.  *  * Do all allocations in @a pool. */
name|svn_error_t
modifier|*
name|svn_cl__eat_peg_revisions
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|true_targets_p
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|targets
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return an error if TARGETS contains a mixture of URLs and paths; otherwise  * return SVN_NO_ERROR. */
name|svn_error_t
modifier|*
name|svn_cl__assert_homogeneous_target_type
parameter_list|(
specifier|const
name|apr_array_header_t
modifier|*
name|targets
parameter_list|)
function_decl|;
comment|/* Return an error if TARGETS contains a URL; otherwise return SVN_NO_ERROR. */
name|svn_error_t
modifier|*
name|svn_cl__check_targets_are_local_paths
parameter_list|(
specifier|const
name|apr_array_header_t
modifier|*
name|targets
parameter_list|)
function_decl|;
comment|/* Return an error if TARGET is a URL; otherwise return SVN_NO_ERROR. */
name|svn_error_t
modifier|*
name|svn_cl__check_target_is_local_path
parameter_list|(
specifier|const
name|char
modifier|*
name|target
parameter_list|)
function_decl|;
comment|/* Return a copy of PATH, converted to the local path style, skipping  * PARENT_PATH if it is non-null and is a parent of or equal to PATH.  *  * This function assumes PARENT_PATH and PATH are both absolute "dirents"  * or both relative "dirents". */
specifier|const
name|char
modifier|*
name|svn_cl__local_style_skip_ancestor
parameter_list|(
specifier|const
name|char
modifier|*
name|parent_path
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
function_decl|;
comment|/* If the user is setting a mime-type to mark one of the TARGETS as binary,  * as determined by property name PROPNAME and value PROPVAL, then check  * whether Subversion's own binary-file detection recognizes the target as  * a binary file. If Subversion doesn't consider the target to be a binary  * file, assume the user is making an error and print a warning to inform  * the user that some operations might fail on the file in the future. */
name|svn_error_t
modifier|*
name|svn_cl__propset_print_binary_mime_type_warning
parameter_list|(
name|apr_array_header_t
modifier|*
name|targets
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|propval
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* A wrapper around the deprecated svn_client_merge_reintegrate. */
name|svn_error_t
modifier|*
name|svn_cl__deprecated_merge_reintegrate
parameter_list|(
specifier|const
name|char
modifier|*
name|source_path_or_url
parameter_list|,
specifier|const
name|svn_opt_revision_t
modifier|*
name|src_peg_revision
parameter_list|,
specifier|const
name|char
modifier|*
name|target_wcpath
parameter_list|,
name|svn_boolean_t
name|dry_run
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|merge_options
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
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
comment|/* SVN_CL_H */
end_comment

end_unit

