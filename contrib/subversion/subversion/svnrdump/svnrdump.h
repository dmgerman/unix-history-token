begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  svnrdump.h: Internal header file for svnrdump.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVNRDUMP_H
end_ifndef

begin_define
define|#
directive|define
name|SVNRDUMP_H
end_define

begin_comment
comment|/*** Includes. ***/
end_comment

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_hash.h"
end_include

begin_include
include|#
directive|include
file|"svn_delta.h"
end_include

begin_include
include|#
directive|include
file|"svn_ra.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_editor.h"
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
comment|/**  * Get a dump editor @a editor along with a @a edit_baton allocated in  * @a pool.  The editor will write output to @a stream.  *  * @a update_anchor_relpath is the repository relative path of the  * anchor of the update-style drive which will happen on @a *editor;  * if a replay-style drive will instead be used, it should be passed  * as @c NULL.  *  * Use @a cancel_func and @a cancel_baton to check for user  * cancellation of the operation (for timely-but-safe termination).  */
name|svn_error_t
modifier|*
name|svn_rdump__get_dump_editor
parameter_list|(
specifier|const
name|svn_delta_editor_t
modifier|*
modifier|*
name|editor
parameter_list|,
name|void
modifier|*
modifier|*
name|edit_baton
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|svn_ra_session_t
modifier|*
name|ra_session
parameter_list|,
specifier|const
name|char
modifier|*
name|update_anchor_relpath
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
comment|/* Same as above, only returns an Ev2 editor. */
name|svn_error_t
modifier|*
name|svn_rdump__get_dump_editor_v2
parameter_list|(
name|svn_editor_t
modifier|*
modifier|*
name|editor
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|svn_ra_session_t
modifier|*
name|ra_session
parameter_list|,
specifier|const
name|char
modifier|*
name|edit_root_relpath
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
name|scratch_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/**  * Load the dumpstream carried in @a stream to the location described  * by @a session.  Use @a aux_session (which is opened to the same URL  * as @a session) for any secondary, out-of-band RA communications  * required.  If @a quiet is set, suppress notifications.  Use @a pool  * for all memory allocations.  Use @a cancel_func and @a cancel_baton  * to check for user cancellation of the operation (for  * timely-but-safe termination).  */
name|svn_error_t
modifier|*
name|svn_rdump__load_dumpstream
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|svn_ra_session_t
modifier|*
name|session
parameter_list|,
name|svn_ra_session_t
modifier|*
name|aux_session
parameter_list|,
name|svn_boolean_t
name|quiet
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
comment|/* Normalize the line ending style of the values of properties in PROPS  * that "need translation" (according to svn_prop_needs_translation(),  * currently all svn:* props) so that they contain only LF (\n) line endings.  *  * Put the normalized props into NORMAL_PROPS, allocated in RESULT_POOL.  *  * Note: this function does not do a deep copy; it is expected that PROPS has  * a longer lifetime than NORMAL_PROPS.  */
name|svn_error_t
modifier|*
name|svn_rdump__normalize_props
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|normal_props
parameter_list|,
name|apr_hash_t
modifier|*
name|props
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Normalize the line ending style of a single property that "needs  * translation" (according to svn_prop_needs_translation(),  * currently all svn:* props) so that they contain only LF (\n) line endings.  * "\r" characters found mid-line are replaced with "\n".  * "\r\n" sequences are replaced with "\n"  *  * NAME is used to check that VALUE should be normalized, and if this is the  * case, VALUE is then normalized, allocated from RESULT_POOL  */
name|svn_error_t
modifier|*
name|svn_rdump__normalize_prop
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
modifier|*
name|value
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
comment|/* SVNRDUMP_H */
end_comment

end_unit

