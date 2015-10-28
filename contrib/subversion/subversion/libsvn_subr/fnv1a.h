begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * fnv1a.h :  routines to create checksums derived from FNV-1a  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_FNV1A_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_FNV1A_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/* Opaque FNV-1a checksum creation context type.  */
typedef|typedef
name|struct
name|svn_fnv1a_32__context_t
name|svn_fnv1a_32__context_t
typedef|;
comment|/* Return a new FNV-1a checksum creation context allocated in POOL.  */
name|svn_fnv1a_32__context_t
modifier|*
name|svn_fnv1a_32__context_create
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Feed LEN bytes from DATA into the FNV-1a checksum creation CONTEXT.  */
name|void
name|svn_fnv1a_32__update
parameter_list|(
name|svn_fnv1a_32__context_t
modifier|*
name|context
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/* Return the FNV-1a checksum over all data fed into  CONTEXT.  */
name|apr_uint32_t
name|svn_fnv1a_32__finalize
parameter_list|(
name|svn_fnv1a_32__context_t
modifier|*
name|context
parameter_list|)
function_decl|;
comment|/* Opaque modified FNV-1a checksum creation context type.  */
typedef|typedef
name|struct
name|svn_fnv1a_32x4__context_t
name|svn_fnv1a_32x4__context_t
typedef|;
comment|/* Return a new modified FNV-1a checksum creation context allocated in POOL.  */
name|svn_fnv1a_32x4__context_t
modifier|*
name|svn_fnv1a_32x4__context_create
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Feed LEN bytes from DATA into the modified FNV-1a checksum creation  * CONTEXT.  */
name|void
name|svn_fnv1a_32x4__update
parameter_list|(
name|svn_fnv1a_32x4__context_t
modifier|*
name|context
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/* Return the modified FNV-1a checksum over all data fed into  CONTEXT.  */
name|apr_uint32_t
name|svn_fnv1a_32x4__finalize
parameter_list|(
name|svn_fnv1a_32x4__context_t
modifier|*
name|context
parameter_list|)
function_decl|;
comment|/* Set HASHES to the 4 partial hash sums produced by the modified FVN-1a  * over INPUT of LEN bytes.  */
name|void
name|svn__fnv1a_32x4_raw
parameter_list|(
name|apr_uint32_t
name|hashes
index|[
literal|4
index|]
parameter_list|,
specifier|const
name|void
modifier|*
name|input
parameter_list|,
name|apr_size_t
name|len
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
comment|/* SVN_LIBSVN_SUBR_FNV1A_H */
end_comment

end_unit

