begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dump-index-cmd.c -- implements the dump-index sub-command.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_define
define|#
directive|define
name|APR_WANT_BYTEFUNC
end_define

begin_include
include|#
directive|include
file|"svn_dirent_uri.h"
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_fs_fs_private.h"
end_include

begin_include
include|#
directive|include
file|"svnfsfs.h"
end_include

begin_comment
comment|/* Return the 8 digit hex string for FNVV1, allocated in POOL.  */
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|fnv1_to_string
parameter_list|(
name|apr_uint32_t
name|fnv1
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
comment|/* Construct a checksum object containing FNV1. */
name|svn_checksum_t
name|checksum
init|=
block|{
name|NULL
block|,
name|svn_checksum_fnv1a_32
block|}
decl_stmt|;
name|apr_uint32_t
name|digest
init|=
name|htonl
argument_list|(
name|fnv1
argument_list|)
decl_stmt|;
name|checksum
operator|.
name|digest
operator|=
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
operator|&
name|digest
expr_stmt|;
comment|/* Convert the digest to hex. */
return|return
name|svn_checksum_to_cstring_display
argument_list|(
operator|&
name|checksum
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Map svn_fs_fs__p2l_entry_t.type to C string. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|item_type_str
index|[]
init|=
block|{
literal|"none "
block|,
literal|"frep "
block|,
literal|"drep "
block|,
literal|"fprop"
block|,
literal|"dprop"
block|,
literal|"node "
block|,
literal|"chgs "
block|,
literal|"rep  "
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Implements svn_fs_fs__dump_index_func_t as printing one table row  * containing the fields of ENTRY to the console.  */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|dump_index_entry
parameter_list|(
specifier|const
name|svn_fs_fs__p2l_entry_t
modifier|*
name|entry
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
specifier|const
name|char
modifier|*
name|type_str
init|=
name|entry
operator|->
name|type
operator|<
operator|(
sizeof|sizeof
argument_list|(
name|item_type_str
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|item_type_str
index|[
literal|0
index|]
argument_list|)
operator|)
condition|?
name|item_type_str
index|[
name|entry
operator|->
name|type
index|]
else|:
literal|"???"
decl_stmt|;
name|printf
argument_list|(
literal|"%12"
name|APR_UINT64_T_HEX_FMT
literal|" %12"
name|APR_UINT64_T_HEX_FMT
literal|" %s %9ld %8"
name|APR_UINT64_T_FMT
literal|" %s\n"
argument_list|,
operator|(
name|apr_uint64_t
operator|)
name|entry
operator|->
name|offset
argument_list|,
operator|(
name|apr_uint64_t
operator|)
name|entry
operator|->
name|size
argument_list|,
name|type_str
argument_list|,
name|entry
operator|->
name|item
operator|.
name|revision
argument_list|,
name|entry
operator|->
name|item
operator|.
name|number
argument_list|,
name|fnv1_to_string
argument_list|(
name|entry
operator|->
name|fnv1_checksum
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* Read the repository at PATH beginning with revision START_REVISION and  * return the result in *FS.  Allocate caches with MEMSIZE bytes total  * capacity.  Use POOL for non-cache allocations.  */
end_comment

begin_function
specifier|static
name|svn_error_t
modifier|*
name|dump_index
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
block|{
name|svn_fs_t
modifier|*
name|fs
decl_stmt|;
comment|/* Check repository type and open it. */
name|SVN_ERR
argument_list|(
name|open_fs
argument_list|(
operator|&
name|fs
argument_list|,
name|path
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Write header line. */
name|printf
argument_list|(
literal|"       Start       Length Type   Revision     Item Checksum\n"
argument_list|)
expr_stmt|;
comment|/* Dump the whole index contents */
name|SVN_ERR
argument_list|(
name|svn_fs_fs__dump_index
argument_list|(
name|fs
argument_list|,
name|revision
argument_list|,
name|dump_index_entry
argument_list|,
name|NULL
argument_list|,
name|check_cancel
argument_list|,
name|NULL
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

begin_comment
comment|/* This implements `svn_opt_subcommand_t'. */
end_comment

begin_function
name|svn_error_t
modifier|*
name|subcommand__dump_index
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
name|svnfsfs__opt_state
modifier|*
name|opt_state
init|=
name|baton
decl_stmt|;
name|SVN_ERR
argument_list|(
name|dump_index
argument_list|(
name|opt_state
operator|->
name|repository_path
argument_list|,
name|opt_state
operator|->
name|start_revision
operator|.
name|value
operator|.
name|number
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

end_unit

