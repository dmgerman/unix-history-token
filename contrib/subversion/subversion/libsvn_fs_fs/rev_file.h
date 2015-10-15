begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rev_file.h --- revision file and index access data structure  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__REV_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__REV_FILE_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"id.h"
end_include

begin_comment
comment|/* In format 7, index files must be read in sync with the respective  * revision / pack file.  I.e. we must use packed index files for packed  * rev files and unpacked ones for non-packed rev files.  So, the whole  * point is to open them with matching "is packed" setting in case some  * background pack process was run.  */
end_comment

begin_comment
comment|/* Opaque index stream type.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|svn_fs_fs__packed_number_stream_t
name|svn_fs_fs__packed_number_stream_t
typedef|;
end_typedef

begin_comment
comment|/* Data file, including indexes data, and associated properties for  * START_REVISION.  As the FILE is kept open, background pack operations  * will not cause access to this file to fail.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_fs_fs__revision_file_t
block|{
comment|/* first (potentially only) revision in the rev / pack file.    * SVN_INVALID_REVNUM for txn proto-rev files. */
name|svn_revnum_t
name|start_revision
decl_stmt|;
comment|/* the revision was packed when the first file / stream got opened */
name|svn_boolean_t
name|is_packed
decl_stmt|;
comment|/* rev / pack file */
name|apr_file_t
modifier|*
name|file
decl_stmt|;
comment|/* stream based on FILE and not NULL exactly when FILE is not NULL */
name|svn_stream_t
modifier|*
name|stream
decl_stmt|;
comment|/* the opened P2L index stream or NULL.  Always NULL for txns. */
name|svn_fs_fs__packed_number_stream_t
modifier|*
name|p2l_stream
decl_stmt|;
comment|/* the opened L2P index stream or NULL.  Always NULL for txns. */
name|svn_fs_fs__packed_number_stream_t
modifier|*
name|l2p_stream
decl_stmt|;
comment|/* Copied from FS->FFD->BLOCK_SIZE upon creation.  It allows us to    * use aligned seek() without having the FS handy. */
name|apr_off_t
name|block_size
decl_stmt|;
comment|/* Offset within FILE at which the rev data ends and the L2P index    * data starts. Less than P2L_OFFSET. -1 if svn_fs_fs__auto_read_footer    * has not been called, yet. */
name|apr_off_t
name|l2p_offset
decl_stmt|;
comment|/* MD5 checksum on the whole on-disk representation of the L2P index.    * NULL if svn_fs_fs__auto_read_footer has not been called, yet. */
name|svn_checksum_t
modifier|*
name|l2p_checksum
decl_stmt|;
comment|/* Offset within FILE at which the L2P index ends and the P2L index    * data starts. Greater than L2P_OFFSET. -1 if svn_fs_fs__auto_read_footer    * has not been called, yet. */
name|apr_off_t
name|p2l_offset
decl_stmt|;
comment|/* MD5 checksum on the whole on-disk representation of the P2L index.    * NULL if svn_fs_fs__auto_read_footer has not been called, yet. */
name|svn_checksum_t
modifier|*
name|p2l_checksum
decl_stmt|;
comment|/* Offset within FILE at which the P2L index ends and the footer starts.    * Greater than P2L_OFFSET. -1 if svn_fs_fs__auto_read_footer has not    * been called, yet. */
name|apr_off_t
name|footer_offset
decl_stmt|;
comment|/* pool containing this object */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
block|}
name|svn_fs_fs__revision_file_t
typedef|;
end_typedef

begin_comment
comment|/* Open the correct revision file for REV.  If the filesystem FS has  * been packed, *FILE will be set to the packed file; otherwise, set *FILE  * to the revision file for REV.  Return SVN_ERR_FS_NO_SUCH_REVISION if the  * file doesn't exist.  Allocate *FILE in RESULT_POOL and use SCRATCH_POOL  * for temporaries. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__open_pack_or_rev_file
parameter_list|(
name|svn_fs_fs__revision_file_t
modifier|*
modifier|*
name|file
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
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
comment|/* Open the correct revision file for REV with read and write access.  * If necessary, temporarily reset the file's read-only state.  If the  * filesystem FS has been packed, *FILE will be set to the packed file;  * otherwise, set *FILE to the revision file for REV.  *  * Return SVN_ERR_FS_NO_SUCH_REVISION if the file doesn't exist.  * Allocate *FILE in RESULT_POOL and use SCRATCH_POOLfor temporaries. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__open_pack_or_rev_file_writable
parameter_list|(
name|svn_fs_fs__revision_file_t
modifier|*
modifier|*
name|file
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
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
comment|/* If the footer data in FILE has not been read, yet, do so now.  * Index locations will only be read upon request as we assume they get  * cached and the FILE is usually used for REP data access only.  * Hence, the separate step.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__auto_read_footer
parameter_list|(
name|svn_fs_fs__revision_file_t
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Open the proto-rev file of transaction TXN_ID in FS and return it in *FILE.  * Allocate *FILE in RESULT_POOL use and SCRATCH_POOL for temporaries.. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__open_proto_rev_file
parameter_list|(
name|svn_fs_fs__revision_file_t
modifier|*
modifier|*
name|file
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
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
comment|/* Close all files and streams in FILE.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__close_revision_file
parameter_list|(
name|svn_fs_fs__revision_file_t
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

