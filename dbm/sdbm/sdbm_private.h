begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * sdbm - ndbm work-alike hashed database library  * based on Per-Ake Larson's Dynamic Hashing algorithms. BIT 18 (1978).  * author: oz@nexus.yorku.ca  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDBM_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SDBM_PRIVATE_H
end_define

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
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_comment
comment|/* for apr_status_t */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* if the block/page size is increased, it breaks perl apr_sdbm_t compatibility */
end_comment

begin_define
define|#
directive|define
name|DBLKSIZ
value|16384
end_define

begin_define
define|#
directive|define
name|PBLKSIZ
value|8192
end_define

begin_define
define|#
directive|define
name|PAIRMAX
value|8008
end_define

begin_comment
comment|/* arbitrary on PBLKSIZ-N */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBLKSIZ
value|4096
end_define

begin_define
define|#
directive|define
name|PBLKSIZ
value|1024
end_define

begin_define
define|#
directive|define
name|PAIRMAX
value|1008
end_define

begin_comment
comment|/* arbitrary on PBLKSIZ-N */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPLTMAX
value|10
end_define

begin_comment
comment|/* maximum allowed splits */
end_comment

begin_comment
comment|/* for apr_sdbm_t.flags */
end_comment

begin_define
define|#
directive|define
name|SDBM_RDONLY
value|0x1
end_define

begin_comment
comment|/* data base open read-only */
end_comment

begin_define
define|#
directive|define
name|SDBM_SHARED
value|0x2
end_define

begin_comment
comment|/* data base open for sharing */
end_comment

begin_define
define|#
directive|define
name|SDBM_SHARED_LOCK
value|0x4
end_define

begin_comment
comment|/* data base locked for shared read */
end_comment

begin_define
define|#
directive|define
name|SDBM_EXCLUSIVE_LOCK
value|0x8
end_define

begin_comment
comment|/* data base locked for write */
end_comment

begin_struct
struct|struct
name|apr_sdbm_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_file_t
modifier|*
name|dirf
decl_stmt|;
comment|/* directory file descriptor */
name|apr_file_t
modifier|*
name|pagf
decl_stmt|;
comment|/* page file descriptor */
name|apr_int32_t
name|flags
decl_stmt|;
comment|/* status/error flags, see below */
name|long
name|maxbno
decl_stmt|;
comment|/* size of dirfile in bits */
name|long
name|curbit
decl_stmt|;
comment|/* current bit number */
name|long
name|hmask
decl_stmt|;
comment|/* current hash mask */
name|long
name|blkptr
decl_stmt|;
comment|/* current block for nextkey */
name|int
name|keyptr
decl_stmt|;
comment|/* current key for nextkey */
name|long
name|blkno
decl_stmt|;
comment|/* current page to read/write */
name|long
name|pagbno
decl_stmt|;
comment|/* current page in pagbuf */
name|char
name|pagbuf
index|[
name|PBLKSIZ
index|]
decl_stmt|;
comment|/* page file block buffer */
name|long
name|dirbno
decl_stmt|;
comment|/* current block in dirbuf */
name|char
name|dirbuf
index|[
name|DBLKSIZ
index|]
decl_stmt|;
comment|/* directory file block buffer */
name|int
name|lckcnt
decl_stmt|;
comment|/* number of calls to sdbm_lock */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sdbm_hash
value|apu__sdbm_hash
end_define

begin_define
define|#
directive|define
name|sdbm_nullitem
value|apu__sdbm_nullitem
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|apr_sdbm_datum_t
name|sdbm_nullitem
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|sdbm_hash
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * zero the cache  */
end_comment

begin_define
define|#
directive|define
name|SDBM_INVALIDATE_CACHE
parameter_list|(
name|db
parameter_list|,
name|finfo
parameter_list|)
define|\
value|do { db->dirbno = (!finfo.size) ? 0 : -1; \          db->pagbno = -1; \          db->maxbno = (long)(finfo.size * BYTESIZ); \     } while (0);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SDBM_PRIVATE_H */
end_comment

end_unit

