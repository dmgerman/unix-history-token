begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_DBM_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|APR_DBM_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_dbm.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_comment
comment|/* ### for now, include the DBM selection; this will go away once we start    ### building and linking all of the DBMs at once. */
end_comment

begin_include
include|#
directive|include
file|"apu_select_dbm.h"
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
comment|/** @internal */
comment|/**  * Most DBM libraries take a POSIX mode for creating files.  Don't trust  * the mode_t type, some platforms may not support it, int is safe.  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_posix_perms2mode
argument_list|(
argument|apr_fileperms_t perm
argument_list|)
empty_stmt|;
comment|/**  * Structure to describe the operations of the DBM  */
typedef|typedef
struct|struct
block|{
comment|/** The name of the DBM Type */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** Open the DBM */
name|apr_status_t
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
modifier|*
name|pdb
parameter_list|,
specifier|const
name|char
modifier|*
name|pathname
parameter_list|,
name|apr_int32_t
name|mode
parameter_list|,
name|apr_fileperms_t
name|perm
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Close the DBM */
name|void
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
name|dbm
parameter_list|)
function_decl|;
comment|/** Fetch a dbm record value by key */
name|apr_status_t
function_decl|(
modifier|*
name|fetch
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
name|dbm
parameter_list|,
name|apr_datum_t
name|key
parameter_list|,
name|apr_datum_t
modifier|*
name|pvalue
parameter_list|)
function_decl|;
comment|/** Store a dbm record value by key */
name|apr_status_t
function_decl|(
modifier|*
name|store
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
name|dbm
parameter_list|,
name|apr_datum_t
name|key
parameter_list|,
name|apr_datum_t
name|value
parameter_list|)
function_decl|;
comment|/** Delete a dbm record value by key */
name|apr_status_t
function_decl|(
modifier|*
name|del
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
name|dbm
parameter_list|,
name|apr_datum_t
name|key
parameter_list|)
function_decl|;
comment|/** Search for a key within the dbm */
name|int
function_decl|(
modifier|*
name|exists
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
name|dbm
parameter_list|,
name|apr_datum_t
name|key
parameter_list|)
function_decl|;
comment|/** Retrieve the first record key from a dbm */
name|apr_status_t
function_decl|(
modifier|*
name|firstkey
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
name|dbm
parameter_list|,
name|apr_datum_t
modifier|*
name|pkey
parameter_list|)
function_decl|;
comment|/** Retrieve the next record key from a dbm */
name|apr_status_t
function_decl|(
modifier|*
name|nextkey
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
name|dbm
parameter_list|,
name|apr_datum_t
modifier|*
name|pkey
parameter_list|)
function_decl|;
comment|/** Proactively toss any memory associated with the apr_datum_t. */
name|void
function_decl|(
modifier|*
name|freedatum
function_decl|)
parameter_list|(
name|apr_dbm_t
modifier|*
name|dbm
parameter_list|,
name|apr_datum_t
name|data
parameter_list|)
function_decl|;
comment|/** Get the names that the DBM will use for a given pathname. */
name|void
function_decl|(
modifier|*
name|getusednames
function_decl|)
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|,
specifier|const
name|char
modifier|*
name|pathname
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|used1
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|used2
parameter_list|)
function_decl|;
block|}
name|apr_dbm_type_t
typedef|;
comment|/**  * The actual DBM  */
struct|struct
name|apr_dbm_t
block|{
comment|/** Associated pool */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/** pointer to DB Implementation Specific data */
name|void
modifier|*
name|file
decl_stmt|;
comment|/** Current integer error code */
name|int
name|errcode
decl_stmt|;
comment|/** Current string error code */
specifier|const
name|char
modifier|*
name|errmsg
decl_stmt|;
comment|/** the type of DBM */
specifier|const
name|apr_dbm_type_t
modifier|*
name|type
decl_stmt|;
block|}
struct|;
comment|/* Declare all of the DBM provider tables */
name|APU_MODULE_DECLARE_DATA
specifier|extern
specifier|const
name|apr_dbm_type_t
name|apr_dbm_type_sdbm
decl_stmt|;
name|APU_MODULE_DECLARE_DATA
specifier|extern
specifier|const
name|apr_dbm_type_t
name|apr_dbm_type_gdbm
decl_stmt|;
name|APU_MODULE_DECLARE_DATA
specifier|extern
specifier|const
name|apr_dbm_type_t
name|apr_dbm_type_ndbm
decl_stmt|;
name|APU_MODULE_DECLARE_DATA
specifier|extern
specifier|const
name|apr_dbm_type_t
name|apr_dbm_type_db
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_DBM_PRIVATE_H */
end_comment

end_unit

