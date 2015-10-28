begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * help-cmd.c -- Provide help  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
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
file|"svn_string.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
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
name|svn_cl__help
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
name|pool
parameter_list|)
block|{
name|svn_cl__opt_state_t
modifier|*
name|opt_state
decl_stmt|;
name|char
name|help_header
index|[]
init|=
name|N_
argument_list|(
literal|"usage: svnbench<subcommand> [options] [args]\n"
literal|"Subversion benchmarking tool.\n"
literal|"Type 'svnbench help<subcommand>' for help on a specific subcommand.\n"
literal|"Type 'svnbench --version' to see the program version and RA modules\n"
literal|"  or 'svnbench --version --quiet' to see just the version number.\n"
literal|"\n"
literal|"Most subcommands take file and/or directory arguments, recursing\n"
literal|"on the directories.  If no arguments are supplied to such a\n"
literal|"command, it recurses on the current directory (inclusive) by default.\n"
literal|"\n"
literal|"Available subcommands:\n"
argument_list|)
decl_stmt|;
name|char
name|help_footer
index|[]
init|=
name|N_
argument_list|(
literal|"Subversion is a tool for version control.\n"
literal|"For additional information, see http://subversion.apache.org/\n"
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|ra_desc_start
init|=
name|_
argument_list|(
literal|"The following repository access (RA) modules are available:\n\n"
argument_list|)
decl_stmt|;
name|svn_stringbuf_t
modifier|*
name|version_footer
decl_stmt|;
if|if
condition|(
name|baton
condition|)
name|opt_state
operator|=
operator|(
operator|(
name|svn_cl__cmd_baton_t
operator|*
operator|)
name|baton
operator|)
operator|->
name|opt_state
expr_stmt|;
else|else
name|opt_state
operator|=
name|NULL
expr_stmt|;
name|version_footer
operator|=
name|svn_stringbuf_create
argument_list|(
name|ra_desc_start
argument_list|,
name|pool
argument_list|)
expr_stmt|;
name|SVN_ERR
argument_list|(
name|svn_ra_print_modules
argument_list|(
name|version_footer
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|svn_opt_print_help4
argument_list|(
name|os
argument_list|,
literal|"svnbench"
argument_list|,
comment|/* ### erm, derive somehow? */
name|opt_state
condition|?
name|opt_state
operator|->
name|version
else|:
name|FALSE
argument_list|,
name|opt_state
condition|?
name|opt_state
operator|->
name|quiet
else|:
name|FALSE
argument_list|,
name|opt_state
condition|?
name|opt_state
operator|->
name|verbose
else|:
name|FALSE
argument_list|,
name|version_footer
operator|->
name|data
argument_list|,
name|help_header
argument_list|,
comment|/* already gettext()'d */
name|svn_cl__cmd_table
argument_list|,
name|svn_cl__options
argument_list|,
name|svn_cl__global_options
argument_list|,
name|_
argument_list|(
name|help_footer
argument_list|)
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

end_unit

