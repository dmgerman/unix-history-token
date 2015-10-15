begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* string_table.h : interface to string tables, private to libsvn_fs_x  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_X_STRING_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_X_STRING_TABLE_H
end_define

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_temp_serializer.h"
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
comment|/* A string table is a very space efficient, read-only representation for  * a set of strings with high degreed of prefix and postfix overhead.  *  * Creating a string table is a two-stage process:  Use a builder class,  * stuff all the strings in there and let it then do the heavy lifting of  * classification and compression to create the actual string table object.  *  * We will use this for the various path values in FSX change lists and  * node revision items.  */
comment|/* the string table builder */
typedef|typedef
name|struct
name|string_table_builder_t
name|string_table_builder_t
typedef|;
comment|/* the string table */
typedef|typedef
name|struct
name|string_table_t
name|string_table_t
typedef|;
comment|/* Returns a new string table builder object, allocated in RESULT_POOL.  */
name|string_table_builder_t
modifier|*
name|svn_fs_x__string_table_builder_create
parameter_list|(
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Add an arbitrary NUL-terminated C-string STRING of the given length LEN  * to BUILDER.  Return the index of that string in the future string table.  * If LEN is 0, determine the length of the C-string internally.  */
name|apr_size_t
name|svn_fs_x__string_table_builder_add
parameter_list|(
name|string_table_builder_t
modifier|*
name|builder
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/* Return an estimate for the on-disk size of the resulting string table.  * The estimate may err in both directions but tends to overestimate the  * space requirements for larger tables.  */
name|apr_size_t
name|svn_fs_x__string_table_builder_estimate_size
parameter_list|(
name|string_table_builder_t
modifier|*
name|builder
parameter_list|)
function_decl|;
comment|/* From the given BUILDER object, create a string table object allocated  * in POOL that contains all strings previously added to BUILDER.  */
name|string_table_t
modifier|*
name|svn_fs_x__string_table_create
parameter_list|(
specifier|const
name|string_table_builder_t
modifier|*
name|builder
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Extract string number INDEX from TABLE and return a copy of it allocated  * in POOL.  If LENGTH is not NULL, set *LENGTH to strlen() of the result  * string.  Returns an empty string for invalid indexes.  */
specifier|const
name|char
modifier|*
name|svn_fs_x__string_table_get
parameter_list|(
specifier|const
name|string_table_t
modifier|*
name|table
parameter_list|,
name|apr_size_t
name|index
parameter_list|,
name|apr_size_t
modifier|*
name|length
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Write a serialized representation of the string table TABLE to STREAM.  * Use SCRATCH_POOL for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_fs_x__write_string_table
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|string_table_t
modifier|*
name|table
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Read the serialized string table representation from STREAM and return  * the resulting runtime representation in *TABLE_P.  Allocate it in  * RESULT_POOL and use SCRATCH_POOL for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_fs_x__read_string_table
parameter_list|(
name|string_table_t
modifier|*
modifier|*
name|table_p
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
comment|/* Serialize string table *ST within the serialization CONTEXT.  */
name|void
name|svn_fs_x__serialize_string_table
parameter_list|(
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|,
name|string_table_t
modifier|*
modifier|*
name|st
parameter_list|)
function_decl|;
comment|/* Deserialize string table *TABLE within the BUFFER.  */
name|void
name|svn_fs_x__deserialize_string_table
parameter_list|(
name|void
modifier|*
name|buffer
parameter_list|,
name|string_table_t
modifier|*
modifier|*
name|table
parameter_list|)
function_decl|;
comment|/* Extract string number INDEX from the cache serialized representation at  * TABLE and return a copy of it allocated in POOL.  If LENGTH is not NULL,  * set *LENGTH to strlen() of the result string.  Returns an empty string  * for invalid indexes.  */
specifier|const
name|char
modifier|*
name|svn_fs_x__string_table_get_func
parameter_list|(
specifier|const
name|string_table_t
modifier|*
name|table
parameter_list|,
name|apr_size_t
name|idx
parameter_list|,
name|apr_size_t
modifier|*
name|length
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
comment|/* SVN_LIBSVN_FS_X_STRING_TABLE_H */
end_comment

end_unit

