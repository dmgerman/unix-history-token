begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012, 2014 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SPACE_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SPACE_MAP_H
end_define

begin_include
include|#
directive|include
file|<sys/avl.h>
end_include

begin_include
include|#
directive|include
file|<sys/range_tree.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmu.h>
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
comment|/*  * The size of the space map object has increased to include a histogram.  * The SPACE_MAP_SIZE_V0 designates the original size and is used to  * maintain backward compatibility.  */
define|#
directive|define
name|SPACE_MAP_SIZE_V0
value|(3 * sizeof (uint64_t))
define|#
directive|define
name|SPACE_MAP_HISTOGRAM_SIZE
value|32
comment|/*  * The space_map_phys is the on-disk representation of the space map.  * Consumers of space maps should never reference any of the members of this  * structure directly. These members may only be updated in syncing context.  *  * Note the smp_object is no longer used but remains in the structure  * for backward compatibility.  */
typedef|typedef
struct|struct
name|space_map_phys
block|{
name|uint64_t
name|smp_object
decl_stmt|;
comment|/* on-disk space map object */
name|uint64_t
name|smp_objsize
decl_stmt|;
comment|/* size of the object */
name|uint64_t
name|smp_alloc
decl_stmt|;
comment|/* space allocated from the map */
name|uint64_t
name|smp_pad
index|[
literal|5
index|]
decl_stmt|;
comment|/* reserved */
comment|/* 	 * The smp_histogram maintains a histogram of free regions. Each 	 * bucket, smp_histogram[i], contains the number of free regions 	 * whose size is: 	 * 2^(i+sm_shift)<= size of free region in bytes< 2^(i+sm_shift+1) 	 */
name|uint64_t
name|smp_histogram
index|[
name|SPACE_MAP_HISTOGRAM_SIZE
index|]
decl_stmt|;
block|}
name|space_map_phys_t
typedef|;
comment|/*  * The space map object defines a region of space, its size, how much is  * allocated, and the on-disk object that stores this information.  * Consumers of space maps may only access the members of this structure.  */
typedef|typedef
struct|struct
name|space_map
block|{
name|uint64_t
name|sm_start
decl_stmt|;
comment|/* start of map */
name|uint64_t
name|sm_size
decl_stmt|;
comment|/* size of map */
name|uint8_t
name|sm_shift
decl_stmt|;
comment|/* unit shift */
name|uint64_t
name|sm_length
decl_stmt|;
comment|/* synced length */
name|uint64_t
name|sm_alloc
decl_stmt|;
comment|/* synced space allocated */
name|objset_t
modifier|*
name|sm_os
decl_stmt|;
comment|/* objset for this map */
name|uint64_t
name|sm_object
decl_stmt|;
comment|/* object id for this map */
name|uint32_t
name|sm_blksz
decl_stmt|;
comment|/* block size for space map */
name|dmu_buf_t
modifier|*
name|sm_dbuf
decl_stmt|;
comment|/* space_map_phys_t dbuf */
name|space_map_phys_t
modifier|*
name|sm_phys
decl_stmt|;
comment|/* on-disk space map */
name|kmutex_t
modifier|*
name|sm_lock
decl_stmt|;
comment|/* pointer to lock that protects map */
block|}
name|space_map_t
typedef|;
comment|/*  * debug entry  *  *    1      3         10                     50  *  ,---+--------+------------+---------------------------------.  *  | 1 | action |  syncpass  |        txg (lower bits)         |  *  `---+--------+------------+---------------------------------'  *   63  62    60 59        50 49                               0  *  *  * non-debug entry  *  *    1               47                   1           15  *  ,-----------------------------------------------------------.  *  | 0 |   offset (sm_shift units)    | type |       run       |  *  `-----------------------------------------------------------'  *   63  62                          17   16   15               0  */
comment|/* All this stuff takes and returns bytes */
define|#
directive|define
name|SM_RUN_DECODE
parameter_list|(
name|x
parameter_list|)
value|(BF64_DECODE(x, 0, 15) + 1)
define|#
directive|define
name|SM_RUN_ENCODE
parameter_list|(
name|x
parameter_list|)
value|BF64_ENCODE((x) - 1, 0, 15)
define|#
directive|define
name|SM_TYPE_DECODE
parameter_list|(
name|x
parameter_list|)
value|BF64_DECODE(x, 15, 1)
define|#
directive|define
name|SM_TYPE_ENCODE
parameter_list|(
name|x
parameter_list|)
value|BF64_ENCODE(x, 15, 1)
define|#
directive|define
name|SM_OFFSET_DECODE
parameter_list|(
name|x
parameter_list|)
value|BF64_DECODE(x, 16, 47)
define|#
directive|define
name|SM_OFFSET_ENCODE
parameter_list|(
name|x
parameter_list|)
value|BF64_ENCODE(x, 16, 47)
define|#
directive|define
name|SM_DEBUG_DECODE
parameter_list|(
name|x
parameter_list|)
value|BF64_DECODE(x, 63, 1)
define|#
directive|define
name|SM_DEBUG_ENCODE
parameter_list|(
name|x
parameter_list|)
value|BF64_ENCODE(x, 63, 1)
define|#
directive|define
name|SM_DEBUG_ACTION_DECODE
parameter_list|(
name|x
parameter_list|)
value|BF64_DECODE(x, 60, 3)
define|#
directive|define
name|SM_DEBUG_ACTION_ENCODE
parameter_list|(
name|x
parameter_list|)
value|BF64_ENCODE(x, 60, 3)
define|#
directive|define
name|SM_DEBUG_SYNCPASS_DECODE
parameter_list|(
name|x
parameter_list|)
value|BF64_DECODE(x, 50, 10)
define|#
directive|define
name|SM_DEBUG_SYNCPASS_ENCODE
parameter_list|(
name|x
parameter_list|)
value|BF64_ENCODE(x, 50, 10)
define|#
directive|define
name|SM_DEBUG_TXG_DECODE
parameter_list|(
name|x
parameter_list|)
value|BF64_DECODE(x, 0, 50)
define|#
directive|define
name|SM_DEBUG_TXG_ENCODE
parameter_list|(
name|x
parameter_list|)
value|BF64_ENCODE(x, 0, 50)
define|#
directive|define
name|SM_RUN_MAX
value|SM_RUN_DECODE(~0ULL)
typedef|typedef
enum|enum
block|{
name|SM_ALLOC
block|,
name|SM_FREE
block|}
name|maptype_t
typedef|;
comment|/*  * The data for a given space map can be kept on blocks of any size.  * Larger blocks entail fewer i/o operations, but they also cause the  * DMU to keep more data in-core, and also to waste more i/o bandwidth  * when only a few blocks have changed since the last transaction group.  * Rather than having a fixed block size for all space maps the block size  * can adjust as needed (see space_map_max_blksz). Set the initial block  * size for the space map to 4k.  */
define|#
directive|define
name|SPACE_MAP_INITIAL_BLOCKSIZE
value|(1ULL<< 12)
name|int
name|space_map_load
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|,
name|range_tree_t
modifier|*
name|rt
parameter_list|,
name|maptype_t
name|maptype
parameter_list|)
function_decl|;
name|void
name|space_map_histogram_clear
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|)
function_decl|;
name|void
name|space_map_histogram_add
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|,
name|range_tree_t
modifier|*
name|rt
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
name|void
name|space_map_update
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|)
function_decl|;
name|uint64_t
name|space_map_object
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|)
function_decl|;
name|uint64_t
name|space_map_allocated
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|)
function_decl|;
name|uint64_t
name|space_map_length
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|)
function_decl|;
name|void
name|space_map_write
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|,
name|range_tree_t
modifier|*
name|rt
parameter_list|,
name|maptype_t
name|maptype
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
name|void
name|space_map_truncate
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
name|uint64_t
name|space_map_alloc
parameter_list|(
name|objset_t
modifier|*
name|os
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
name|void
name|space_map_free
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
name|int
name|space_map_open
parameter_list|(
name|space_map_t
modifier|*
modifier|*
name|smp
parameter_list|,
name|objset_t
modifier|*
name|os
parameter_list|,
name|uint64_t
name|object
parameter_list|,
name|uint64_t
name|start
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint8_t
name|shift
parameter_list|,
name|kmutex_t
modifier|*
name|lp
parameter_list|)
function_decl|;
name|void
name|space_map_close
parameter_list|(
name|space_map_t
modifier|*
name|sm
parameter_list|)
function_decl|;
name|int64_t
name|space_map_alloc_delta
parameter_list|(
name|space_map_t
modifier|*
name|sm
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SPACE_MAP_H */
end_comment

end_unit

