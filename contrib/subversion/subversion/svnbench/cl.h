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
file|"svn_client.h"
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
name|strict
decl_stmt|;
comment|/* do strictly what was requested */
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
name|apr_array_header_t
modifier|*
name|targets
decl_stmt|;
comment|/* target list from file */
comment|/* UTF-8! */
name|svn_boolean_t
name|no_auth_cache
decl_stmt|;
comment|/* do not cache authentication information */
name|svn_boolean_t
name|stop_on_copy
decl_stmt|;
comment|/* don't cross copies during processing */
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
name|use_merge_history
decl_stmt|;
comment|/* use/display extra merge information */
comment|/* trust server SSL certs that would otherwise be rejected as "untrusted" */
name|svn_boolean_t
name|trust_server_cert_unknown_ca
decl_stmt|;
name|svn_boolean_t
name|trust_server_cert_cn_mismatch
decl_stmt|;
name|svn_boolean_t
name|trust_server_cert_expired
decl_stmt|;
name|svn_boolean_t
name|trust_server_cert_not_yet_valid
decl_stmt|;
name|svn_boolean_t
name|trust_server_cert_other_failure
decl_stmt|;
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
name|svn_cl__help
decl_stmt|,
name|svn_cl__null_blame
decl_stmt|,
name|svn_cl__null_export
decl_stmt|,
name|svn_cl__null_list
decl_stmt|,
name|svn_cl__null_log
decl_stmt|,
name|svn_cl__null_info
decl_stmt|;
comment|/* See definition in main.c for documentation. */
specifier|extern
specifier|const
name|svn_opt_subcommand_desc2_t
name|svn_cl__cmd_table
index|[]
decl_stmt|;
comment|/* See definition in main.c for documentation. */
specifier|extern
specifier|const
name|int
name|svn_cl__global_options
index|[]
decl_stmt|;
comment|/* See definition in main.c for documentation. */
specifier|extern
specifier|const
name|apr_getopt_option_t
name|svn_cl__options
index|[]
decl_stmt|;
comment|/* A helper for the many subcommands that wish to merely warn when  * invoked on an unversioned, nonexistent, or otherwise innocuously  * errorful resource.  Meant to be wrapped with SVN_ERR().  *  * If ERR is null, return SVN_NO_ERROR.  *  * Else if ERR->apr_err is one of the error codes supplied in varargs,  * then handle ERR as a warning (unless QUIET is true), clear ERR, and  * return SVN_NO_ERROR, and push the value of ERR->apr_err into the  * ERRORS_SEEN array, if ERRORS_SEEN is not NULL.  *  * Else return ERR.  *  * Typically, error codes like SVN_ERR_UNVERSIONED_RESOURCE,  * SVN_ERR_ENTRY_NOT_FOUND, etc, are supplied in varargs.  Don't  * forget to terminate the argument list with 0 (or APR_SUCCESS).  */
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
name|apr_pool_t
modifier|*
name|pool
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

