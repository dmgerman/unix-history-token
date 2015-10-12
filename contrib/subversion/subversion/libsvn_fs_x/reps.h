begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* reps.h --- FSX representation container  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__REPS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__REPS_H
end_define

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_comment
comment|/* This container type implements the start-delta (aka pick lists) data  * structure plus functions to create it and read data from it.  The key  * point is to identify common sub-strings within a whole set of fulltexts  * instead of only two as in the classic txdelta code.  *  * Because it is relatively expensive to optimize the final in-memory  * layout, representation containers cannot be updated.  A builder object  * will do most of the space saving when adding fulltexts but the final  * data will only be created immediately before serializing everything to  * disk.  So, builders are write only and representation containers are  * read-only.  *  * Extracting data from a representation container is O(length) but it  * may require multiple iterations if base representations outside the  * container were used.  Therefore, you will first create an extractor  * object (this may happen while holding a cache lock) and the you need  * to "drive" the extractor outside any cache context.  */
end_comment

begin_comment
comment|/* A write-only constructor object for representation containers.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|svn_fs_x__reps_builder_t
name|svn_fs_x__reps_builder_t
typedef|;
end_typedef

begin_comment
comment|/* A read-only representation container -  * an opaque collection of fulltexts, i.e. byte strings.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|svn_fs_x__reps_t
name|svn_fs_x__reps_t
typedef|;
end_typedef

begin_comment
comment|/* The fulltext extractor utility object.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|svn_fs_x__rep_extractor_t
name|svn_fs_x__rep_extractor_t
typedef|;
end_typedef

begin_comment
comment|/* Baton type to be passed to svn_fs_x__reps_get_func.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_fs_x__reps_baton_t
block|{
comment|/* filesystem the resulting extractor shall operate on */
name|svn_fs_t
modifier|*
name|fs
decl_stmt|;
comment|/* element index of the item to extract from the container */
name|apr_size_t
name|idx
decl_stmt|;
block|}
name|svn_fs_x__reps_baton_t
typedef|;
end_typedef

begin_comment
comment|/* Create and populate noderev containers. */
end_comment

begin_comment
comment|/* Create and return a new builder object, allocated in RESULT_POOL.  */
end_comment

begin_function_decl
name|svn_fs_x__reps_builder_t
modifier|*
name|svn_fs_x__reps_builder_create
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* To BUILDER, add reference to the fulltext currently stored in  * representation REP.  Substrings matching with any of the base reps  * in BUILDER can be removed from the text base and be replaced by  * references to those base representations.  *  * The PRIORITY is a mere hint on which base representations should  * preferred in case we could re-use the same contents from multiple bases.  * Higher numerical value means higher priority / likelihood of being  * selected over others.  *  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__reps_add_base
parameter_list|(
name|svn_fs_x__reps_builder_t
modifier|*
name|builder
parameter_list|,
name|svn_fs_x__representation_t
modifier|*
name|rep
parameter_list|,
name|int
name|priority
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add the byte string CONTENTS to BUILDER.  Return the item index under  * which the fulltext can be retrieved from the final container in *REP_IDX.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__reps_add
parameter_list|(
name|apr_size_t
modifier|*
name|rep_idx
parameter_list|,
name|svn_fs_x__reps_builder_t
modifier|*
name|builder
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|contents
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a rough estimate in bytes for the serialized representation  * of BUILDER.  */
end_comment

begin_function_decl
name|apr_size_t
name|svn_fs_x__reps_estimate_size
parameter_list|(
specifier|const
name|svn_fs_x__reps_builder_t
modifier|*
name|builder
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read from representation containers. */
end_comment

begin_comment
comment|/* For fulltext IDX in CONTAINER in filesystem FS, create an extract object  * allocated in POOL and return it in *EXTRACTOR.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__reps_get
parameter_list|(
name|svn_fs_x__rep_extractor_t
modifier|*
modifier|*
name|extractor
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_x__reps_t
modifier|*
name|container
parameter_list|,
name|apr_size_t
name|idx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Let the EXTRACTOR object fetch all parts of the desired fulltext and  * return the latter in *CONTENTS.  If SIZE is not 0, return SIZE bytes  * starting at offset START_OFFSET of the full contents.  If that range  * lies partly or completely outside the content, clip it accordingly.  * Allocate the result in RESULT_POOL and use SCRATCH_POOL for temporary  * allocations.  *  * Note, you may not run this inside a cache access function.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__extractor_drive
parameter_list|(
name|svn_stringbuf_t
modifier|*
modifier|*
name|contents
parameter_list|,
name|svn_fs_x__rep_extractor_t
modifier|*
name|extractor
parameter_list|,
name|apr_size_t
name|start_offset
parameter_list|,
name|apr_size_t
name|size
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
end_function_decl

begin_comment
comment|/* I/O interface. */
end_comment

begin_comment
comment|/* Write a serialized representation of the final container described by  * BUILDER to STREAM.  Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__write_reps_container
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|svn_fs_x__reps_builder_t
modifier|*
name|builder
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a representations container from its serialized representation in  * STREAM.  Allocate the result in RESULT_POOL and return it in *CONTAINER.  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__read_reps_container
parameter_list|(
name|svn_fs_x__reps_t
modifier|*
modifier|*
name|container
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
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
end_function_decl

begin_comment
comment|/* Implements #svn_cache__serialize_func_t for svn_fs_x__reps_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_reps_container
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|apr_size_t
modifier|*
name|data_len
parameter_list|,
name|void
modifier|*
name|in
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implements #svn_cache__deserialize_func_t for svn_fs_x__reps_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_reps_container
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implements svn_cache__partial_getter_func_t for svn_fs_x__reps_t,  * setting *OUT to an svn_fs_x__rep_extractor_t object defined by the  * svn_fs_x__reps_baton_t passed in as *BATON.  This function is similar  * to svn_fs_x__reps_get but operates on the cache serialized  * representation of the container.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__reps_get_func
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
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
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

