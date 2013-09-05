begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * unlock-cmd.c -- Unlock a working copy path.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
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
file|"svn_path.h"
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_client.h"
end_include

begin_include
include|#
directive|include
file|"svn_error_codes.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_cmdline.h"
end_include

begin_include
include|#
directive|include
file|"cl.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_escape
end_escape

begin_comment
comment|/*** Code. ***/
end_comment

begin_comment
comment|/* This implements the `svn_opt_subcommand_t' interface. */
end_comment

begin_function
name|svn_error_t
modifier|*
name|svn_cl__unlock
parameter_list|(
name|apr_getopt_t
modifier|*
name|os
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
block|{
name|svn_cl__opt_state_t
modifier|*
name|opt_state
init|=
operator|(
operator|(
name|svn_cl__cmd_baton_t
operator|*
operator|)
name|baton
operator|)
operator|->
name|opt_state
decl_stmt|;
name|svn_client_ctx_t
modifier|*
name|ctx
init|=
operator|(
operator|(
name|svn_cl__cmd_baton_t
operator|*
operator|)
name|baton
operator|)
operator|->
name|ctx
decl_stmt|;
name|apr_array_header_t
modifier|*
name|targets
decl_stmt|;
name|SVN_ERR
argument_list|(
name|svn_cl__args_to_target_array_print_reserved
argument_list|(
operator|&
name|targets
argument_list|,
name|os
argument_list|,
name|opt_state
operator|->
name|targets
argument_list|,
name|ctx
argument_list|,
name|FALSE
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* We don't support unlock on directories, so "." is not relevant. */
if|if
condition|(
operator|!
name|targets
operator|->
name|nelts
condition|)
return|return
name|svn_error_create
argument_list|(
name|SVN_ERR_CL_INSUFFICIENT_ARGS
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
return|;
name|SVN_ERR
argument_list|(
name|svn_cl__eat_peg_revisions
argument_list|(
operator|&
name|targets
argument_list|,
name|targets
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_cl__assert_homogeneous_target_type
argument_list|(
name|targets
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|svn_error_trace
argument_list|(
name|svn_client_unlock
argument_list|(
name|targets
argument_list|,
name|opt_state
operator|->
name|force
argument_list|,
name|ctx
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

