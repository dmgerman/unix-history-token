begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_temp_serializer.h  * @brief Helper API for serializing _temporarily_ data structures.  *  * @note This API is intended for efficient serialization and duplication  *       of temporary, e.g. cached, data structures ONLY. It is not  *       suitable for persistent data.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_TEMP_SERIALIZER_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_TEMP_SERIALIZER_H
end_define

begin_include
include|#
directive|include
file|"svn_string.h"
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
comment|/* forward declaration */
struct_decl|struct
name|svn_stringbuf_t
struct_decl|;
comment|/**  * The amount of extra memory allocated by #svn_temp_serializer__init for  * the internal buffer in addition to its suggested_buffer_size parameter.  * To allocate a 512 buffer, including overhead, just specify a size of  * 512 - SVN_TEMP_SERIALIZER__OVERHEAD.  */
define|#
directive|define
name|SVN_TEMP_SERIALIZER__OVERHEAD
value|(sizeof(svn_stringbuf_t) + 1)
comment|/**  * Opaque structure controlling the serialization process and holding the  * intermediate as well as final results.  */
typedef|typedef
name|struct
name|svn_temp_serializer__context_t
name|svn_temp_serializer__context_t
typedef|;
comment|/**  * Begin the serialization process for the @a source_struct and all objects  * referenced from it. @a struct_size must match the result of @c sizeof()  * of the actual structure. Due to the generic nature of the init function  * we can't determine the structure size as part of the function.  *  * It is possible to specify a @c NULL source_struct in which case the first  * call to svn_temp_serializer__push() will provide the root struct.  * Alternatively, one may even call svn_temp_serializer__add_string()  * but there is generally no point in doing so because the result will be  * simple string object in a #svn_stringbuf_t.  *  * You may suggest a larger initial buffer size in @a suggested_buffer_size  * to minimize the number of internal buffer re-allocations during the  * serialization process. All allocations will be made from @a pool.  *  * Pointers within the structure will be replaced by their serialized  * representation when the respective strings or sub-structures get  * serialized. This scheme allows only for tree-like, i.e. non-circular  * data structures.  *  * @return the serialization context.  */
name|svn_temp_serializer__context_t
modifier|*
name|svn_temp_serializer__init
parameter_list|(
specifier|const
name|void
modifier|*
name|source_struct
parameter_list|,
name|apr_size_t
name|struct_size
parameter_list|,
name|apr_size_t
name|suggested_buffer_size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Continue the serialization process of the @a source_struct that has  * already been serialized to @a buffer but contains references to new  * objects yet to serialize. I.e. this function allows you to append  * data to serialized structures returned by svn_temp_serializer__get().  *  * The current size of the serialized data is given in @a currently_used.  * If the allocated data buffer is actually larger, you may specifiy that  * size in @a currently_allocated to prevent unnecessary re-allocations.  * Otherwise, set it to 0.  *  * All allocations will be made from @a pool.  *  * Please note that only sub-structures of @a source_struct may be added.  * To add item referenced from other parts of the buffer, serialize from  * @a source_struct first, get the result from svn_temp_serializer__get()  * and call svn_temp_serializer__init_append for the next part.  *  * @return the serialization context.  */
name|svn_temp_serializer__context_t
modifier|*
name|svn_temp_serializer__init_append
parameter_list|(
name|void
modifier|*
name|buffer
parameter_list|,
name|void
modifier|*
name|source_struct
parameter_list|,
name|apr_size_t
name|currently_used
parameter_list|,
name|apr_size_t
name|currently_allocated
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Begin serialization of a referenced sub-structure within the  * serialization @a context. @a source_struct must be a reference to the  * pointer in the original parent structure so that the correspondence in  * the serialized structure can be established. @a struct_size must match  * the result of @c sizeof() of the actual structure.  *  * Only in case that svn_temp_serializer__init() has not been provided  * with a root structure and this is the first call after the initialization,  * @a source_struct will point to a reference to the root structure instead  * of being related to some other.  *  * Sub-structures and strings will be added in a FIFO fashion. If you need  * add further sub-structures on the same level, you need to call  * svn_serializer__pop() to realign the serialization context.  */
name|void
name|svn_temp_serializer__push
parameter_list|(
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|,
specifier|const
name|void
modifier|*
specifier|const
modifier|*
name|source_struct
parameter_list|,
name|apr_size_t
name|struct_size
parameter_list|)
function_decl|;
comment|/**  * End the serialization of the current sub-structure. The serialization  * @a context will be focused back on the parent structure. You may then  * add further sub-structures starting from that level.  *  * It is not necessary to call this function just for symmetry at the end  * of the serialization process.  */
name|void
name|svn_temp_serializer__pop
parameter_list|(
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|)
function_decl|;
comment|/**  * Serialize a string referenced from the current structure within the  * serialization @a context. @a s must be a reference to the @c char*  * pointer in the original structure so that the correspondence in the  * serialized structure can be established.  *  * Only in case that svn_temp_serializer__init() has not been provided  * with a root structure and this is the first call after the initialization,  * @a s will not be related to some struct.  */
name|void
name|svn_temp_serializer__add_string
parameter_list|(
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|s
parameter_list|)
function_decl|;
comment|/**  * Set the serialized representation of the pointer @a ptr inside the  * current structure within the serialization @a context to @c NULL.  * This is particularly useful if the pointer is not @c NULL in the  * source structure.  */
name|void
name|svn_temp_serializer__set_null
parameter_list|(
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|,
specifier|const
name|void
modifier|*
specifier|const
modifier|*
name|ptr
parameter_list|)
function_decl|;
comment|/**  * @return the number of bytes currently used in the serialization buffer  * of the given serialization @a context.  */
name|apr_size_t
name|svn_temp_serializer__get_length
parameter_list|(
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|)
function_decl|;
comment|/**  * @return a reference to the data buffer containing the data serialialized  * so far in the given serialization @a context.  */
name|struct
name|svn_stringbuf_t
modifier|*
name|svn_temp_serializer__get
parameter_list|(
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|)
function_decl|;
comment|/**  * Deserialization is straightforward: just copy the serialized buffer to  * a natively aligned memory location (APR pools will take care of that  * automatically) and resolve all pointers to sub-structures.  *  * To do the latter, call this function for each of these pointers, giving  * the start address of the copied buffer in @a buffer and a reference to  * the pointer to resolve in @a ptr.  */
name|void
name|svn_temp_deserializer__resolve
parameter_list|(
name|void
modifier|*
name|buffer
parameter_list|,
name|void
modifier|*
modifier|*
name|ptr
parameter_list|)
function_decl|;
comment|/**  * Similar to svn_temp_deserializer__resolve() but instead of modifying  * the buffer content, the resulting pointer is passed back to the caller  * as the return value.  */
specifier|const
name|void
modifier|*
name|svn_temp_deserializer__ptr
parameter_list|(
specifier|const
name|void
modifier|*
name|buffer
parameter_list|,
specifier|const
name|void
modifier|*
specifier|const
modifier|*
name|ptr
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
comment|/* SVN_TEMP_SERIALIZER_H */
end_comment

end_unit

