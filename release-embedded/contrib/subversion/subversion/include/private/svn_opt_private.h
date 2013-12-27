begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_opt_private.h  * @brief Subversion-internal option parsing APIs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_OPT_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_OPT_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

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
file|"svn_error.h"
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
comment|/* Extract the peg revision, if any, from UTF8_TARGET.  *  * If PEG_REVISION is not NULL, return the peg revision in *PEG_REVISION.  * *PEG_REVISION will be an empty string if no peg revision is found.  * Return the true target portion in *TRUE_TARGET.  *  * UTF8_TARGET need not be canonical. *TRUE_TARGET will not be canonical  * unless UTF8_TARGET is.  *  * It is an error if *TRUE_TARGET results in the empty string after the  * split, which happens in case UTF8_TARGET has a leading '@' character  * with no additional '@' characters to escape the first '@'.  *  * Note that *PEG_REVISION will still contain the '@' symbol as the first  * character if a peg revision was found. If a trailing '@' symbol was  * used to escape other '@' characters in UTF8_TARGET, *PEG_REVISION will  * point to the string "@", containing only a single character.  *  * All allocations are done in POOL.  */
name|svn_error_t
modifier|*
name|svn_opt__split_arg_at_peg_revision
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|true_target
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|peg_revision
parameter_list|,
specifier|const
name|char
modifier|*
name|utf8_target
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Attempt to transform URL_IN, which is a URL-like user input, into a  * valid URL:  *   - escape IRI characters and some other non-URI characters  *   - check that no back-path ("..") components are present  *   - call svn_uri_canonicalize()  * URL_IN is in UTF-8 encoding and has no peg revision specifier.  * Set *URL_OUT to the result, allocated from POOL.  */
name|svn_error_t
modifier|*
name|svn_opt__arg_canonicalize_url
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|url_out
parameter_list|,
specifier|const
name|char
modifier|*
name|url_in
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/*  * Attempt to transform PATH_IN, which is a local path-like user input, into a  * valid local path:  *   - Attempt to get the correct capitalization by trying to actually find  *     the path specified.  *   - If the path does not exist (which is valid) the given capitalization  *     is used.  *   - canonicalize the separator ("/") characters  *   - call svn_dirent_canonicalize()  * PATH_IN is in UTF-8 encoding and has no peg revision specifier.  * Set *PATH_OUT to the result, allocated from POOL.  */
name|svn_error_t
modifier|*
name|svn_opt__arg_canonicalize_path
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|path_out
parameter_list|,
specifier|const
name|char
modifier|*
name|path_in
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/*  * Pull remaining target arguments from OS into *TARGETS_P,  * converting them to UTF-8, followed by targets from KNOWN_TARGETS  * (which might come from, for example, the "--targets" command line  * option), which are already in UTF-8.  *  * On each URL target, do some IRI-to-URI encoding and some  * auto-escaping.  On each local path, canonicalize case and path  * separators.  *  * Allocate *TARGETS_P and its elements in POOL.  *  * If a path has the same name as a Subversion working copy  * administrative directory, return SVN_ERR_RESERVED_FILENAME_SPECIFIED;  * if multiple reserved paths are encountered, return a chain of  * errors, all of which are SVN_ERR_RESERVED_FILENAME_SPECIFIED.  Do  * not return this type of error in a chain with any other type of  * error, and if this is the only type of error encountered, complete  * the operation before returning the error(s).  */
name|svn_error_t
modifier|*
name|svn_opt__args_to_target_array
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return a human-readable description of @a revision.  The result  * will be allocated statically or from @a result_pool.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_opt__revision_to_string
parameter_list|(
specifier|const
name|svn_opt_revision_t
modifier|*
name|revision
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/**  * Create a revision range structure from two revisions.  Return a new range  * allocated in @a result_pool with the start and end initialized to  * (deep copies of) @a *start_revision and @a *end_revision.  */
name|svn_opt_revision_range_t
modifier|*
name|svn_opt__revision_range_create
parameter_list|(
specifier|const
name|svn_opt_revision_t
modifier|*
name|start_revision
parameter_list|,
specifier|const
name|svn_opt_revision_t
modifier|*
name|end_revision
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/**  * Create a revision range structure from two revnums.  Return a new range  * allocated in @a result_pool with the start and end kinds initialized to  * #svn_opt_revision_number and values @a start_revnum and @a end_revnum.  */
name|svn_opt_revision_range_t
modifier|*
name|svn_opt__revision_range_from_revnums
parameter_list|(
name|svn_revnum_t
name|start_revnum
parameter_list|,
name|svn_revnum_t
name|end_revnum
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
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
comment|/* SVN_OPT_PRIVATE_H */
end_comment

end_unit

