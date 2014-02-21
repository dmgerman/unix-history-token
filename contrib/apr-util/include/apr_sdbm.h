begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * sdbm - ndbm work-alike hashed database library  * based on Per-Ake Larson's Dynamic Hashing algorithms. BIT 18 (1978).  * author: oz@nexus.yorku.ca  * status: ex-public domain  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_SDBM_H
end_ifndef

begin_define
define|#
directive|define
name|APR_SDBM_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_comment
comment|/* for apr_fileperms_t */
end_comment

begin_comment
comment|/**   * @file apr_sdbm.h  * @brief apr-util SDBM library  */
end_comment

begin_comment
comment|/**  * @defgroup APR_Util_DBM_SDBM SDBM library  * @ingroup APR_Util_DBM  * @{  */
end_comment

begin_comment
comment|/**  * Structure for referencing an sdbm  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|apr_sdbm_t
name|apr_sdbm_t
typedef|;
end_typedef

begin_comment
comment|/**  * Structure for referencing the datum record within an sdbm  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/** pointer to the data stored/retrieved */
name|char
modifier|*
name|dptr
decl_stmt|;
comment|/** size of data */
comment|/* apr_ssize_t for release 2.0??? */
name|int
name|dsize
decl_stmt|;
block|}
name|apr_sdbm_datum_t
typedef|;
end_typedef

begin_comment
comment|/* The extensions used for the database files */
end_comment

begin_comment
comment|/** SDBM Directory file extension */
end_comment

begin_define
define|#
directive|define
name|APR_SDBM_DIRFEXT
value|".dir"
end_define

begin_comment
comment|/** SDBM page file extension */
end_comment

begin_define
define|#
directive|define
name|APR_SDBM_PAGFEXT
value|".pag"
end_define

begin_comment
comment|/* flags to sdbm_store */
end_comment

begin_define
define|#
directive|define
name|APR_SDBM_INSERT
value|0
end_define

begin_comment
comment|/**< Insert */
end_comment

begin_define
define|#
directive|define
name|APR_SDBM_REPLACE
value|1
end_define

begin_comment
comment|/**< Replace */
end_comment

begin_define
define|#
directive|define
name|APR_SDBM_INSERTDUP
value|2
end_define

begin_comment
comment|/**< Insert with duplicates */
end_comment

begin_comment
comment|/**  * Open an sdbm database by file name  * @param db The newly opened database  * @param name The sdbm file to open  * @param mode The flag values (APR_READ and APR_BINARY flags are implicit)  *<PRE>  *           APR_WRITE          open for read-write access  *           APR_CREATE         create the sdbm if it does not exist  *           APR_TRUNCATE       empty the contents of the sdbm  *           APR_EXCL           fail for APR_CREATE if the file exists  *           APR_DELONCLOSE     delete the sdbm when closed  *           APR_SHARELOCK      support locking across process/machines  *</PRE>  * @param perms Permissions to apply to if created  * @param p The pool to use when creating the sdbm  * @remark The sdbm name is not a true file name, as sdbm appends suffixes   * for seperate data and index files.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_sdbm_open
argument_list|(
argument|apr_sdbm_t **db
argument_list|,
argument|const char *name
argument_list|,
argument|apr_int32_t mode
argument_list|,
argument|apr_fileperms_t perms
argument_list|,
argument|apr_pool_t *p
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Close an sdbm file previously opened by apr_sdbm_open  * @param db The database to close  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_expr_stmt
name|apr_sdbm_close
argument_list|(
name|apr_sdbm_t
operator|*
name|db
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * Lock an sdbm database for concurency of multiple operations  * @param db The database to lock  * @param type The lock type  *<PRE>  *           APR_FLOCK_SHARED  *           APR_FLOCK_EXCLUSIVE  *</PRE>  * @remark Calls to apr_sdbm_lock may be nested.  All apr_sdbm functions  * perform implicit locking.  Since an APR_FLOCK_SHARED lock cannot be   * portably promoted to an APR_FLOCK_EXCLUSIVE lock, apr_sdbm_store and   * apr_sdbm_delete calls will fail if an APR_FLOCK_SHARED lock is held.  * The apr_sdbm_lock call requires the database to be opened with the  * APR_SHARELOCK mode value.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_sdbm_lock
argument_list|(
argument|apr_sdbm_t *db
argument_list|,
argument|int type
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Release an sdbm lock previously aquired by apr_sdbm_lock  * @param db The database to unlock  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_expr_stmt
name|apr_sdbm_unlock
argument_list|(
name|apr_sdbm_t
operator|*
name|db
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * Fetch an sdbm record value by key  * @param db The database   * @param value The value datum retrieved for this record  * @param key The key datum to find this record  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_sdbm_fetch
argument_list|(
argument|apr_sdbm_t *db
argument_list|,
argument|apr_sdbm_datum_t *value
argument_list|,
argument|apr_sdbm_datum_t key
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Store an sdbm record value by key  * @param db The database   * @param key The key datum to store this record by  * @param value The value datum to store in this record  * @param opt The method used to store the record  *<PRE>  *           APR_SDBM_INSERT     return an error if the record exists  *           APR_SDBM_REPLACE    overwrite any existing record for key  *</PRE>  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_sdbm_store
argument_list|(
argument|apr_sdbm_t *db
argument_list|,
argument|apr_sdbm_datum_t key
argument_list|,
argument|apr_sdbm_datum_t value
argument_list|,
argument|int opt
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Delete an sdbm record value by key  * @param db The database   * @param key The key datum of the record to delete  * @remark It is not an error to delete a non-existent record.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_sdbm_delete
argument_list|(
argument|apr_sdbm_t *db
argument_list|,
argument|const apr_sdbm_datum_t key
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Retrieve the first record key from a dbm  * @param db The database   * @param key The key datum of the first record  * @remark The keys returned are not ordered.  To traverse the list of keys  * for an sdbm opened with APR_SHARELOCK, the caller must use apr_sdbm_lock  * prior to retrieving the first record, and hold the lock until after the  * last call to apr_sdbm_nextkey.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_expr_stmt
name|apr_sdbm_firstkey
argument_list|(
name|apr_sdbm_t
operator|*
name|db
argument_list|,
name|apr_sdbm_datum_t
operator|*
name|key
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * Retrieve the next record key from an sdbm  * @param db The database   * @param key The key datum of the next record  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_expr_stmt
name|apr_sdbm_nextkey
argument_list|(
name|apr_sdbm_t
operator|*
name|db
argument_list|,
name|apr_sdbm_datum_t
operator|*
name|key
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * Returns true if the sdbm database opened for read-only access  * @param db The database to test  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|apr_sdbm_rdonly
argument_list|(
name|apr_sdbm_t
operator|*
name|db
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_SDBM_H */
end_comment

end_unit

