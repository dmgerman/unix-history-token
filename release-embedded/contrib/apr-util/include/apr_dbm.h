begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_DBM_H
end_ifndef

begin_define
define|#
directive|define
name|APR_DBM_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

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
file|"apr_file_info.h"
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
comment|/**  * @file apr_dbm.h  * @brief APR-UTIL DBM library  */
comment|/**   * @defgroup APR_Util_DBM DBM routines  * @ingroup APR_Util  * @{  */
comment|/**  * Structure for referencing a dbm  */
typedef|typedef
name|struct
name|apr_dbm_t
name|apr_dbm_t
typedef|;
comment|/**  * Structure for referencing the datum record within a dbm  */
typedef|typedef
struct|struct
block|{
comment|/** pointer to the 'data' to retrieve/store in the DBM */
name|char
modifier|*
name|dptr
decl_stmt|;
comment|/** size of the 'data' to retrieve/store in the DBM */
name|apr_size_t
name|dsize
decl_stmt|;
block|}
name|apr_datum_t
typedef|;
comment|/* modes to open the DB */
define|#
directive|define
name|APR_DBM_READONLY
value|1
comment|/**< open for read-only access */
define|#
directive|define
name|APR_DBM_READWRITE
value|2
comment|/**< open for read-write access */
define|#
directive|define
name|APR_DBM_RWCREATE
value|3
comment|/**< open for r/w, create if needed */
define|#
directive|define
name|APR_DBM_RWTRUNC
value|4
comment|/**< open for r/w, truncating an existing                                           DB if present */
comment|/**  * Open a dbm file by file name and type of DBM  * @param dbm The newly opened database  * @param type The type of the DBM (not all may be available at run time)  *<pre>  *  db   for Berkeley DB files  *  gdbm for GDBM files  *  ndbm for NDBM files  *  sdbm for SDBM files (always available)  *  default for the default DBM type  *</pre>  * @param name The dbm file name to open  * @param mode The flag value  *<PRE>  *           APR_DBM_READONLY   open for read-only access  *           APR_DBM_READWRITE  open for read-write access  *           APR_DBM_RWCREATE   open for r/w, create if needed  *           APR_DBM_RWTRUNC    open for r/w, truncate if already there  *</PRE>  * @param perm Permissions to apply to if created  * @param cntxt The pool to use when creating the dbm  * @remark The dbm name may not be a true file name, as many dbm packages  * append suffixes for seperate data and index files.  * @bug In apr-util 0.9 and 1.x, the type arg was case insensitive.  This  * was highly inefficient, and as of 2.x the dbm name must be provided in  * the correct case (lower case for all bundled providers)  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbm_open_ex
argument_list|(
argument|apr_dbm_t **dbm
argument_list|,
argument|const char* type
argument_list|,
argument|const char *name
argument_list|,
argument|apr_int32_t mode
argument_list|,
argument|apr_fileperms_t perm
argument_list|,
argument|apr_pool_t *cntxt
argument_list|)
empty_stmt|;
comment|/**  * Open a dbm file by file name  * @param dbm The newly opened database  * @param name The dbm file name to open  * @param mode The flag value  *<PRE>  *           APR_DBM_READONLY   open for read-only access  *           APR_DBM_READWRITE  open for read-write access  *           APR_DBM_RWCREATE   open for r/w, create if needed  *           APR_DBM_RWTRUNC    open for r/w, truncate if already there  *</PRE>  * @param perm Permissions to apply to if created  * @param cntxt The pool to use when creating the dbm  * @remark The dbm name may not be a true file name, as many dbm packages  * append suffixes for seperate data and index files.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbm_open
argument_list|(
argument|apr_dbm_t **dbm
argument_list|,
argument|const char *name
argument_list|,
argument|apr_int32_t mode
argument_list|,
argument|apr_fileperms_t perm
argument_list|,
argument|apr_pool_t *cntxt
argument_list|)
empty_stmt|;
comment|/**  * Close a dbm file previously opened by apr_dbm_open  * @param dbm The database to close  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_dbm_close
argument_list|(
name|apr_dbm_t
operator|*
name|dbm
argument_list|)
expr_stmt|;
comment|/**  * Fetch a dbm record value by key  * @param dbm The database   * @param key The key datum to find this record  * @param pvalue The value datum retrieved for this record  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbm_fetch
argument_list|(
argument|apr_dbm_t *dbm
argument_list|,
argument|apr_datum_t key
argument_list|,
argument|apr_datum_t *pvalue
argument_list|)
empty_stmt|;
comment|/**  * Store a dbm record value by key  * @param dbm The database   * @param key The key datum to store this record by  * @param value The value datum to store in this record  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbm_store
argument_list|(
argument|apr_dbm_t *dbm
argument_list|,
argument|apr_datum_t key
argument_list|,
argument|apr_datum_t value
argument_list|)
empty_stmt|;
comment|/**  * Delete a dbm record value by key  * @param dbm The database   * @param key The key datum of the record to delete  * @remark It is not an error to delete a non-existent record.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbm_delete
argument_list|(
argument|apr_dbm_t *dbm
argument_list|,
argument|apr_datum_t key
argument_list|)
empty_stmt|;
comment|/**  * Search for a key within the dbm  * @param dbm The database   * @param key The datum describing a key to test  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbm_exists
argument_list|(
argument|apr_dbm_t *dbm
argument_list|,
argument|apr_datum_t key
argument_list|)
empty_stmt|;
comment|/**  * Retrieve the first record key from a dbm  * @param dbm The database   * @param pkey The key datum of the first record  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbm_firstkey
argument_list|(
name|apr_dbm_t
operator|*
name|dbm
argument_list|,
name|apr_datum_t
operator|*
name|pkey
argument_list|)
expr_stmt|;
comment|/**  * Retrieve the next record key from a dbm  * @param dbm The database   * @param pkey The key datum of the next record  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbm_nextkey
argument_list|(
name|apr_dbm_t
operator|*
name|dbm
argument_list|,
name|apr_datum_t
operator|*
name|pkey
argument_list|)
expr_stmt|;
comment|/**  * Proactively toss any memory associated with the apr_datum_t.  * @param dbm The database   * @param data The datum to free.  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_dbm_freedatum
argument_list|(
argument|apr_dbm_t *dbm
argument_list|,
argument|apr_datum_t data
argument_list|)
empty_stmt|;
comment|/**  * Report more information when an apr_dbm function fails.  * @param dbm The database  * @param errcode A DBM-specific value for the error (for logging). If this  *                isn't needed, it may be NULL.  * @param errbuf Location to store the error text  * @param errbufsize The size of the provided buffer  * @return The errbuf parameter, for convenience.  */
name|APU_DECLARE
argument_list|(
argument|char *
argument_list|)
name|apr_dbm_geterror
argument_list|(
argument|apr_dbm_t *dbm
argument_list|,
argument|int *errcode
argument_list|,
argument|char *errbuf
argument_list|,
argument|apr_size_t errbufsize
argument_list|)
empty_stmt|;
comment|/**  * If the specified file/path were passed to apr_dbm_open(), return the  * actual file/path names which would be (created and) used. At most, two  * files may be used; used2 may be NULL if only one file is used.  * @param pool The pool for allocating used1 and used2.  * @param type The type of DBM you require info on @see apr_dbm_open_ex  * @param pathname The path name to generate used-names from.  * @param used1 The first pathname used by the apr_dbm implementation.  * @param used2 The second pathname used by apr_dbm. If only one file is  *              used by the specific implementation, this will be set to NULL.  * @return An error if the specified type is invalid.  * @remark The dbm file(s) don't need to exist. This function only manipulates  *      the pathnames.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbm_get_usednames_ex
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
name|type
argument_list|,
specifier|const
name|char
operator|*
name|pathname
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|used1
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|used2
argument_list|)
expr_stmt|;
comment|/**  * If the specified file/path were passed to apr_dbm_open(), return the  * actual file/path names which would be (created and) used. At most, two  * files may be used; used2 may be NULL if only one file is used.  * @param pool The pool for allocating used1 and used2.  * @param pathname The path name to generate used-names from.  * @param used1 The first pathname used by the apr_dbm implementation.  * @param used2 The second pathname used by apr_dbm. If only one file is  *              used by the specific implementation, this will be set to NULL.  * @remark The dbm file(s) don't need to exist. This function only manipulates  *      the pathnames.  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_dbm_get_usednames
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
name|pathname
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|used1
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|used2
argument_list|)
expr_stmt|;
comment|/** @} */
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
comment|/* !APR_DBM_H */
end_comment

end_unit

