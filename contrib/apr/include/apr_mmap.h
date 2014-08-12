begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_MMAP_H
end_ifndef

begin_define
define|#
directive|define
name|APR_MMAP_H
end_define

begin_comment
comment|/**  * @file apr_mmap.h  * @brief APR MMAP routines  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_ring.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_comment
comment|/* for apr_file_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BEOS
end_ifdef

begin_include
include|#
directive|include
file|<kernel/OS.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * @defgroup apr_mmap MMAP (Memory Map) Routines  * @ingroup APR   * @{  */
comment|/** MMap opened for reading */
define|#
directive|define
name|APR_MMAP_READ
value|1
comment|/** MMap opened for writing */
define|#
directive|define
name|APR_MMAP_WRITE
value|2
comment|/** @see apr_mmap_t */
typedef|typedef
name|struct
name|apr_mmap_t
name|apr_mmap_t
typedef|;
comment|/**  * @remark  * As far as I can tell the only really sane way to store an MMAP is as a  * void * and a length.  BeOS requires this area_id, but that's just a little  * something extra.  I am exposing this type, because it doesn't make much  * sense to keep it private, and opening it up makes some stuff easier in  * Apache.  */
comment|/** The MMAP structure */
struct|struct
name|apr_mmap_t
block|{
comment|/** The pool the mmap structure was allocated out of. */
name|apr_pool_t
modifier|*
name|cntxt
decl_stmt|;
ifdef|#
directive|ifdef
name|BEOS
comment|/** An area ID.  Only valid on BeOS */
name|area_id
name|area
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WIN32
comment|/** The handle of the file mapping */
name|HANDLE
name|mhandle
decl_stmt|;
comment|/** The start of the real memory page area (mapped view) */
name|void
modifier|*
name|mv
decl_stmt|;
comment|/** The physical start, size and offset */
name|apr_off_t
name|pstart
decl_stmt|;
name|apr_size_t
name|psize
decl_stmt|;
name|apr_off_t
name|poffset
decl_stmt|;
endif|#
directive|endif
comment|/** The start of the memory mapped area */
name|void
modifier|*
name|mm
decl_stmt|;
comment|/** The amount of data in the mmap */
name|apr_size_t
name|size
decl_stmt|;
comment|/** ring of apr_mmap_t's that reference the same      * mmap'ed region; acts in place of a reference count */
name|APR_RING_ENTRY
argument_list|(
argument|apr_mmap_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
if|#
directive|if
name|APR_HAS_MMAP
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/** @def APR_MMAP_THRESHOLD   * Files have to be at least this big before they're mmap()d.  This is to deal  * with systems where the expense of doing an mmap() and an munmap() outweighs  * the benefit for small files.  It shouldn't be set lower than 1.  */
ifdef|#
directive|ifdef
name|MMAP_THRESHOLD
define|#
directive|define
name|APR_MMAP_THRESHOLD
value|MMAP_THRESHOLD
else|#
directive|else
ifdef|#
directive|ifdef
name|SUNOS4
define|#
directive|define
name|APR_MMAP_THRESHOLD
value|(8*1024)
else|#
directive|else
define|#
directive|define
name|APR_MMAP_THRESHOLD
value|1
endif|#
directive|endif
comment|/* SUNOS4 */
endif|#
directive|endif
comment|/* MMAP_THRESHOLD */
comment|/** @def APR_MMAP_LIMIT  * Maximum size of MMap region  */
ifdef|#
directive|ifdef
name|MMAP_LIMIT
define|#
directive|define
name|APR_MMAP_LIMIT
value|MMAP_LIMIT
else|#
directive|else
define|#
directive|define
name|APR_MMAP_LIMIT
value|(4*1024*1024)
endif|#
directive|endif
comment|/* MMAP_LIMIT */
comment|/** Can this file be MMaped */
define|#
directive|define
name|APR_MMAP_CANDIDATE
parameter_list|(
name|filelength
parameter_list|)
define|\
value|((filelength>= APR_MMAP_THRESHOLD)&& (filelength< APR_MMAP_LIMIT))
comment|/*   Function definitions */
comment|/**   * Create a new mmap'ed file out of an existing APR file.  * @param newmmap The newly created mmap'ed file.  * @param file The file to turn into an mmap.  * @param offset The offset into the file to start the data pointer at.  * @param size The size of the file  * @param flag bit-wise or of:  *<PRE>  *          APR_MMAP_READ       MMap opened for reading  *          APR_MMAP_WRITE      MMap opened for writing  *</PRE>  * @param cntxt The pool to use when creating the mmap.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mmap_create
argument_list|(
argument|apr_mmap_t **newmmap
argument_list|,
argument|apr_file_t *file
argument_list|,
argument|apr_off_t offset
argument_list|,
argument|apr_size_t size
argument_list|,
argument|apr_int32_t flag
argument_list|,
argument|apr_pool_t *cntxt
argument_list|)
empty_stmt|;
comment|/**  * Duplicate the specified MMAP.  * @param new_mmap The structure to duplicate into.   * @param old_mmap The mmap to duplicate.  * @param p The pool to use for new_mmap.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mmap_dup
argument_list|(
name|apr_mmap_t
operator|*
operator|*
name|new_mmap
argument_list|,
name|apr_mmap_t
operator|*
name|old_mmap
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Remove a mmap'ed.  * @param mm The mmap'ed file.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mmap_delete
argument_list|(
name|apr_mmap_t
operator|*
name|mm
argument_list|)
expr_stmt|;
comment|/**   * Move the pointer into the mmap'ed file to the specified offset.  * @param addr The pointer to the offset specified.  * @param mm The mmap'ed file.  * @param offset The offset to move to.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mmap_offset
argument_list|(
argument|void **addr
argument_list|,
argument|apr_mmap_t *mm
argument_list|,
argument|apr_off_t offset
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|/* APR_HAS_MMAP */
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
comment|/* ! APR_MMAP_H */
end_comment

end_unit

