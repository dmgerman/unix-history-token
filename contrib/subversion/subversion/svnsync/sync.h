begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sync.h :  The synchronization editor for svnsync.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYNC_H
end_ifndef

begin_define
define|#
directive|define
name|SYNC_H
end_define

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
file|"svn_types.h"
include|#
directive|include
file|"svn_delta.h"
comment|/* Normalize the encoding and line ending style of the values of properties  * in REV_PROPS that "need translation" (according to  * svn_prop_needs_translation(), which is currently all svn:* props) so that  * they are encoded in UTF-8 and contain only LF (\n) line endings.  *  * The number of properties that needed line ending normalization is returned in  * *NORMALIZED_COUNT.  *  * No re-encoding is performed if SOURCE_PROP_ENCODING is NULL.  */
name|svn_error_t
modifier|*
name|svnsync_normalize_revprops
parameter_list|(
name|apr_hash_t
modifier|*
name|rev_props
parameter_list|,
name|int
modifier|*
name|normalized_count
parameter_list|,
specifier|const
name|char
modifier|*
name|source_prop_encoding
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set WRAPPED_EDITOR and WRAPPED_EDIT_BATON to an editor/baton pair  * that wraps our own commit EDITOR/EDIT_BATON.  BASE_REVISION is the  * revision on which the driver of this returned editor will be basing  * the commit.  TO_URL is the URL of the root of the repository into  * which the commit is being made.  *  * If SOURCE_PROP_ENCODING is NULL, then property values are presumed to be  * encoded in UTF-8 and are not re-encoded. Otherwise, the property values are  * presumed to be encoded in SOURCE_PROP_ENCODING, and are normalized to UTF-8.  *  * As the sync editor encounters property values, it might see the need to  * normalize them (re-encode and/or change to LF line endings). Each carried-out  * line ending normalization adds 1 to the *NORMALIZED_NODE_PROPS_COUNTER  * (for notification).  */
name|svn_error_t
modifier|*
name|svnsync_get_sync_editor
parameter_list|(
specifier|const
name|svn_delta_editor_t
modifier|*
name|wrapped_editor
parameter_list|,
name|void
modifier|*
name|wrapped_edit_baton
parameter_list|,
name|svn_revnum_t
name|base_revision
parameter_list|,
specifier|const
name|char
modifier|*
name|to_url
parameter_list|,
specifier|const
name|char
modifier|*
name|source_prop_encoding
parameter_list|,
name|svn_boolean_t
name|quiet
parameter_list|,
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
name|int
modifier|*
name|normalized_node_props_counter
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
comment|/* SYNC_H */
end_comment

end_unit

