begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * deprecated.c:  holding file for all deprecated APIs.  *                "we can't lose 'em, but we can shun 'em!"  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_comment
comment|/* We define this here to remove any further warnings about the usage of    deprecated functions in this file. */
end_comment

begin_define
define|#
directive|define
name|SVN_DEPRECATED
end_define

begin_include
include|#
directive|include
file|"svn_delta.h"
end_include

begin_include
include|#
directive|include
file|"svn_sorts.h"
end_include

begin_function
name|svn_error_t
modifier|*
name|svn_delta_path_driver
parameter_list|(
specifier|const
name|svn_delta_editor_t
modifier|*
name|editor
parameter_list|,
name|void
modifier|*
name|edit_baton
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|paths
parameter_list|,
name|svn_delta_path_driver_cb_func_t
name|callback_func
parameter_list|,
name|void
modifier|*
name|callback_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
block|{
comment|/* REVISION is dropped on the floor.  */
return|return
name|svn_error_trace
argument_list|(
name|svn_delta_path_driver2
argument_list|(
name|editor
argument_list|,
name|edit_baton
argument_list|,
name|paths
argument_list|,
name|TRUE
argument_list|,
name|callback_func
argument_list|,
name|callback_baton
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

