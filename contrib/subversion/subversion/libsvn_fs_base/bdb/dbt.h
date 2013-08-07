begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dbt.h --- interface to DBT-frobbing functions  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_DBT_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_DBT_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_define
define|#
directive|define
name|SVN_WANT_BDB
end_define

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_skel.h"
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
comment|/* Set all fields of DBT to zero.  Return DBT.  */
name|DBT
modifier|*
name|svn_fs_base__clear_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|)
function_decl|;
comment|/* Set DBT to retrieve no data.  This is useful when you're just    probing the table to see if an entry exists, or to find a key, but    don't care what the value is.  Return DBT.  */
name|DBT
modifier|*
name|svn_fs_base__nodata_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|)
function_decl|;
comment|/* Set DBT to refer to the SIZE bytes at DATA.  Return DBT.  */
name|DBT
modifier|*
name|svn_fs_base__set_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|size
parameter_list|)
function_decl|;
comment|/* Prepare DBT to hold data returned from Berkeley DB.  Return DBT.     Clear all its fields to zero, but set the DB_DBT_MALLOC flag,    requesting that Berkeley DB place the returned data in a freshly    malloc'd block.  If the database operation succeeds, the caller    then owns the data block, and is responsible for making sure it    gets freed.     You can use this with svn_fs_base__track_dbt:         svn_fs_base__result_dbt (&foo);        ... some Berkeley DB operation that puts data in foo ...        svn_fs_base__track_dbt (&foo, pool);     This arrangement is:    - thread-safe --- the returned data is allocated via malloc, and      won't be overwritten if some other thread performs an operation      on the same table.  See the explanation of ``Retrieved key/data      permanence'' in the section of the Berkeley DB manual on the DBT      type.    - pool-friendly --- the data returned by Berkeley DB is now guaranteed      to be freed when POOL is cleared.  */
name|DBT
modifier|*
name|svn_fs_base__result_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|)
function_decl|;
comment|/* Arrange for POOL to `track' DBT's data: when POOL is cleared,    DBT->data will be freed, using `free'.  If DBT->data is zero,    do nothing.     This is meant for use with svn_fs_base__result_dbt; see the explanation    there.  */
name|DBT
modifier|*
name|svn_fs_base__track_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Prepare DBT for use as a key into a RECNO table.  This call makes    DBT refer to the db_recno_t pointed to by RECNO as its buffer; the    record number you assign to *RECNO will be the table key.  */
name|DBT
modifier|*
name|svn_fs_base__recno_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|,
name|db_recno_t
modifier|*
name|recno
parameter_list|)
function_decl|;
comment|/* Compare two DBT values in byte-by-byte lexicographic order.  */
name|int
name|svn_fs_base__compare_dbt
parameter_list|(
specifier|const
name|DBT
modifier|*
name|a
parameter_list|,
specifier|const
name|DBT
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/* Set DBT to the unparsed form of ID; allocate memory from POOL.    Return DBT.  */
name|DBT
modifier|*
name|svn_fs_base__id_to_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set DBT to the unparsed form of SKEL; allocate memory from POOL.    Return DBT.  */
name|DBT
modifier|*
name|svn_fs_base__skel_to_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|,
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set DBT to the text of the null-terminated string STR.  DBT will    refer to STR's storage.  Return DBT.  */
name|DBT
modifier|*
name|svn_fs_base__str_to_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
comment|/* Set DBT to the bytes contained by CHECKSUM.   DBT will refer to CHECKSUM's    storage.  Return DBT.*/
name|DBT
modifier|*
name|svn_fs_base__checksum_to_dbt
parameter_list|(
name|DBT
modifier|*
name|dbt
parameter_list|,
name|svn_checksum_t
modifier|*
name|checksum
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
comment|/* SVN_LIBSVN_FS_DBT_H */
end_comment

end_unit

