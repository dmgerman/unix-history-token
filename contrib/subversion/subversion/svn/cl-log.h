begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cl-log.h: Log entry receiver  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CL_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CL_LOG_H
end_define

begin_comment
comment|/*** Includes. ***/
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/* The separator between log messages. */
define|#
directive|define
name|SVN_CL__LOG_SEP_STRING
define|\
value|"------------------------------------------------------------------------\n"
comment|/* Baton for log_entry_receiver() and log_entry_receiver_xml(). */
typedef|typedef
struct|struct
name|svn_cl__log_receiver_baton
block|{
comment|/* Client context. */
name|svn_client_ctx_t
modifier|*
name|ctx
decl_stmt|;
comment|/* The target of the log operation. */
specifier|const
name|char
modifier|*
name|target_path_or_url
decl_stmt|;
name|svn_opt_revision_t
name|target_peg_revision
decl_stmt|;
comment|/* Don't print log message body nor its line count. */
name|svn_boolean_t
name|omit_log_message
decl_stmt|;
comment|/* Whether to show diffs in the log. (maps to --diff) */
name|svn_boolean_t
name|show_diff
decl_stmt|;
comment|/* Depth applied to diff output. */
name|svn_depth_t
name|depth
decl_stmt|;
comment|/* Diff arguments received from command line. */
specifier|const
name|char
modifier|*
name|diff_extensions
decl_stmt|;
comment|/* Stack which keeps track of merge revision nesting, using svn_revnum_t's */
name|apr_array_header_t
modifier|*
name|merge_stack
decl_stmt|;
comment|/* Log message search patterns. Log entries will only be shown if the author,    * the log message, or a changed path matches one of these patterns. */
name|apr_array_header_t
modifier|*
name|search_patterns
decl_stmt|;
comment|/* Pool for persistent allocations. */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
block|}
name|svn_cl__log_receiver_baton
typedef|;
comment|/* Implement `svn_log_entry_receiver_t', printing the logs in  * a human-readable and machine-parseable format.  *  * BATON is of type `struct svn_cl__log_receiver_baton'.  *  * First, print a header line.  Then if CHANGED_PATHS is non-null,  * print all affected paths in a list headed "Changed paths:\n",  * immediately following the header line.  Then print a newline  * followed by the message body, unless BATON->omit_log_message is true.  */
name|svn_error_t
modifier|*
name|svn_cl__log_entry_receiver
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|svn_log_entry_t
modifier|*
name|log_entry
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* This implements `svn_log_entry_receiver_t', printing the logs in XML.  *  * BATON is of type `struct svn_cl__log_receiver_baton'.  */
name|svn_error_t
modifier|*
name|svn_cl__log_entry_receiver_xml
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|svn_log_entry_t
modifier|*
name|log_entry
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
comment|/* SVN_CL_LOG_H */
end_comment

end_unit

