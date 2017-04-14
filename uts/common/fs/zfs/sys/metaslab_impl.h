begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011, 2015 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_METASLAB_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_METASLAB_IMPL_H
end_define

begin_include
include|#
directive|include
file|<sys/metaslab.h>
end_include

begin_include
include|#
directive|include
file|<sys/space_map.h>
end_include

begin_include
include|#
directive|include
file|<sys/range_tree.h>
end_include

begin_include
include|#
directive|include
file|<sys/vdev.h>
end_include

begin_include
include|#
directive|include
file|<sys/txg.h>
end_include

begin_include
include|#
directive|include
file|<sys/avl.h>
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
comment|/*  * Metaslab allocation tracing record.  */
typedef|typedef
struct|struct
name|metaslab_alloc_trace
block|{
name|list_node_t
name|mat_list_node
decl_stmt|;
name|metaslab_group_t
modifier|*
name|mat_mg
decl_stmt|;
name|metaslab_t
modifier|*
name|mat_msp
decl_stmt|;
name|uint64_t
name|mat_size
decl_stmt|;
name|uint64_t
name|mat_weight
decl_stmt|;
name|uint32_t
name|mat_dva_id
decl_stmt|;
name|uint64_t
name|mat_offset
decl_stmt|;
block|}
name|metaslab_alloc_trace_t
typedef|;
comment|/*  * Used by the metaslab allocation tracing facility to indicate  * error conditions. These errors are stored to the offset member  * of the metaslab_alloc_trace_t record and displayed by mdb.  */
typedef|typedef
enum|enum
name|trace_alloc_type
block|{
name|TRACE_ALLOC_FAILURE
init|=
operator|-
literal|1ULL
block|,
name|TRACE_TOO_SMALL
init|=
operator|-
literal|2ULL
block|,
name|TRACE_FORCE_GANG
init|=
operator|-
literal|3ULL
block|,
name|TRACE_NOT_ALLOCATABLE
init|=
operator|-
literal|4ULL
block|,
name|TRACE_GROUP_FAILURE
init|=
operator|-
literal|5ULL
block|,
name|TRACE_ENOSPC
init|=
operator|-
literal|6ULL
block|,
name|TRACE_CONDENSING
init|=
operator|-
literal|7ULL
block|,
name|TRACE_VDEV_ERROR
init|=
operator|-
literal|8ULL
block|}
name|trace_alloc_type_t
typedef|;
define|#
directive|define
name|METASLAB_WEIGHT_PRIMARY
value|(1ULL<< 63)
define|#
directive|define
name|METASLAB_WEIGHT_SECONDARY
value|(1ULL<< 62)
define|#
directive|define
name|METASLAB_WEIGHT_TYPE
value|(1ULL<< 61)
define|#
directive|define
name|METASLAB_ACTIVE_MASK
define|\
value|(METASLAB_WEIGHT_PRIMARY | METASLAB_WEIGHT_SECONDARY)
comment|/*  * The metaslab weight is used to encode the amount of free space in a  * metaslab, such that the "best" metaslab appears first when sorting the  * metaslabs by weight. The weight (and therefore the "best" metaslab) can  * be determined in two different ways: by computing a weighted sum of all  * the free space in the metaslab (a space based weight) or by counting only  * the free segments of the largest size (a segment based weight). We prefer  * the segment based weight because it reflects how the free space is  * comprised, but we cannot always use it -- legacy pools do not have the  * space map histogram information necessary to determine the largest  * contiguous regions. Pools that have the space map histogram determine  * the segment weight by looking at each bucket in the histogram and  * determining the free space whose size in bytes is in the range:  *	[2^i, 2^(i+1))  * We then encode the largest index, i, that contains regions into the  * segment-weighted value.  *  * Space-based weight:  *  *      64      56      48      40      32      24      16      8       0  *      +-------+-------+-------+-------+-------+-------+-------+-------+  *      |PS1|                   weighted-free space                     |  *      +-------+-------+-------+-------+-------+-------+-------+-------+  *  *	PS - indicates primary and secondary activation  *	space - the fragmentation-weighted space  *  * Segment-based weight:  *  *      64      56      48      40      32      24      16      8       0  *      +-------+-------+-------+-------+-------+-------+-------+-------+  *      |PS0| idx|             count of segments in region              |  *      +-------+-------+-------+-------+-------+-------+-------+-------+  *  *	PS - indicates primary and secondary activation  *	idx - index for the highest bucket in the histogram  *	count - number of segments in the specified bucket  */
define|#
directive|define
name|WEIGHT_GET_ACTIVE
parameter_list|(
name|weight
parameter_list|)
value|BF64_GET((weight), 62, 2)
define|#
directive|define
name|WEIGHT_SET_ACTIVE
parameter_list|(
name|weight
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((weight), 62, 2, x)
define|#
directive|define
name|WEIGHT_IS_SPACEBASED
parameter_list|(
name|weight
parameter_list|)
define|\
value|((weight) == 0 || BF64_GET((weight), 61, 1))
define|#
directive|define
name|WEIGHT_SET_SPACEBASED
parameter_list|(
name|weight
parameter_list|)
value|BF64_SET((weight), 61, 1, 1)
comment|/*  * These macros are only applicable to segment-based weighting.  */
define|#
directive|define
name|WEIGHT_GET_INDEX
parameter_list|(
name|weight
parameter_list|)
value|BF64_GET((weight), 55, 6)
define|#
directive|define
name|WEIGHT_SET_INDEX
parameter_list|(
name|weight
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((weight), 55, 6, x)
define|#
directive|define
name|WEIGHT_GET_COUNT
parameter_list|(
name|weight
parameter_list|)
value|BF64_GET((weight), 0, 55)
define|#
directive|define
name|WEIGHT_SET_COUNT
parameter_list|(
name|weight
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((weight), 0, 55, x)
comment|/*  * A metaslab class encompasses a category of allocatable top-level vdevs.  * Each top-level vdev is associated with a metaslab group which defines  * the allocatable region for that vdev. Examples of these categories include  * "normal" for data block allocations (i.e. main pool allocations) or "log"  * for allocations designated for intent log devices (i.e. slog devices).  * When a block allocation is requested from the SPA it is associated with a  * metaslab_class_t, and only top-level vdevs (i.e. metaslab groups) belonging  * to the class can be used to satisfy that request. Allocations are done  * by traversing the metaslab groups that are linked off of the mc_rotor field.  * This rotor points to the next metaslab group where allocations will be  * attempted. Allocating a block is a 3 step process -- select the metaslab  * group, select the metaslab, and then allocate the block. The metaslab  * class defines the low-level block allocator that will be used as the  * final step in allocation. These allocators are pluggable allowing each class  * to use a block allocator that best suits that class.  */
struct|struct
name|metaslab_class
block|{
name|kmutex_t
name|mc_lock
decl_stmt|;
name|spa_t
modifier|*
name|mc_spa
decl_stmt|;
name|metaslab_group_t
modifier|*
name|mc_rotor
decl_stmt|;
name|metaslab_ops_t
modifier|*
name|mc_ops
decl_stmt|;
name|uint64_t
name|mc_aliquot
decl_stmt|;
comment|/* 	 * Track the number of metaslab groups that have been initialized 	 * and can accept allocations. An initialized metaslab group is 	 * one has been completely added to the config (i.e. we have 	 * updated the MOS config and the space has been added to the pool). 	 */
name|uint64_t
name|mc_groups
decl_stmt|;
comment|/* 	 * Toggle to enable/disable the allocation throttle. 	 */
name|boolean_t
name|mc_alloc_throttle_enabled
decl_stmt|;
comment|/* 	 * The allocation throttle works on a reservation system. Whenever 	 * an asynchronous zio wants to perform an allocation it must 	 * first reserve the number of blocks that it wants to allocate. 	 * If there aren't sufficient slots available for the pending zio 	 * then that I/O is throttled until more slots free up. The current 	 * number of reserved allocations is maintained by the mc_alloc_slots 	 * refcount. The mc_alloc_max_slots value determines the maximum 	 * number of allocations that the system allows. Gang blocks are 	 * allowed to reserve slots even if we've reached the maximum 	 * number of allocations allowed. 	 */
name|uint64_t
name|mc_alloc_max_slots
decl_stmt|;
name|refcount_t
name|mc_alloc_slots
decl_stmt|;
name|uint64_t
name|mc_alloc_groups
decl_stmt|;
comment|/* # of allocatable groups */
name|uint64_t
name|mc_alloc
decl_stmt|;
comment|/* total allocated space */
name|uint64_t
name|mc_deferred
decl_stmt|;
comment|/* total deferred frees */
name|uint64_t
name|mc_space
decl_stmt|;
comment|/* total space (alloc + free) */
name|uint64_t
name|mc_dspace
decl_stmt|;
comment|/* total deflated space */
name|uint64_t
name|mc_histogram
index|[
name|RANGE_TREE_HISTOGRAM_SIZE
index|]
decl_stmt|;
block|}
struct|;
comment|/*  * Metaslab groups encapsulate all the allocatable regions (i.e. metaslabs)  * of a top-level vdev. They are linked togther to form a circular linked  * list and can belong to only one metaslab class. Metaslab groups may become  * ineligible for allocations for a number of reasons such as limited free  * space, fragmentation, or going offline. When this happens the allocator will  * simply find the next metaslab group in the linked list and attempt  * to allocate from that group instead.  */
struct|struct
name|metaslab_group
block|{
name|kmutex_t
name|mg_lock
decl_stmt|;
name|avl_tree_t
name|mg_metaslab_tree
decl_stmt|;
name|uint64_t
name|mg_aliquot
decl_stmt|;
name|boolean_t
name|mg_allocatable
decl_stmt|;
comment|/* can we allocate? */
comment|/* 	 * A metaslab group is considered to be initialized only after 	 * we have updated the MOS config and added the space to the pool. 	 * We only allow allocation attempts to a metaslab group if it 	 * has been initialized. 	 */
name|boolean_t
name|mg_initialized
decl_stmt|;
name|uint64_t
name|mg_free_capacity
decl_stmt|;
comment|/* percentage free */
name|int64_t
name|mg_bias
decl_stmt|;
name|int64_t
name|mg_activation_count
decl_stmt|;
name|metaslab_class_t
modifier|*
name|mg_class
decl_stmt|;
name|vdev_t
modifier|*
name|mg_vd
decl_stmt|;
name|taskq_t
modifier|*
name|mg_taskq
decl_stmt|;
name|metaslab_group_t
modifier|*
name|mg_prev
decl_stmt|;
name|metaslab_group_t
modifier|*
name|mg_next
decl_stmt|;
comment|/* 	 * Each metaslab group can handle mg_max_alloc_queue_depth allocations 	 * which are tracked by mg_alloc_queue_depth. It's possible for a 	 * metaslab group to handle more allocations than its max. This 	 * can occur when gang blocks are required or when other groups 	 * are unable to handle their share of allocations. 	 */
name|uint64_t
name|mg_max_alloc_queue_depth
decl_stmt|;
name|refcount_t
name|mg_alloc_queue_depth
decl_stmt|;
comment|/* 	 * A metalab group that can no longer allocate the minimum block 	 * size will set mg_no_free_space. Once a metaslab group is out 	 * of space then its share of work must be distributed to other 	 * groups. 	 */
name|boolean_t
name|mg_no_free_space
decl_stmt|;
name|uint64_t
name|mg_allocations
decl_stmt|;
name|uint64_t
name|mg_failed_allocations
decl_stmt|;
name|uint64_t
name|mg_fragmentation
decl_stmt|;
name|uint64_t
name|mg_histogram
index|[
name|RANGE_TREE_HISTOGRAM_SIZE
index|]
decl_stmt|;
block|}
struct|;
comment|/*  * This value defines the number of elements in the ms_lbas array. The value  * of 64 was chosen as it covers all power of 2 buckets up to UINT64_MAX.  * This is the equivalent of highbit(UINT64_MAX).  */
define|#
directive|define
name|MAX_LBAS
value|64
comment|/*  * Each metaslab maintains a set of in-core trees to track metaslab  * operations.  The in-core free tree (ms_tree) contains the list of  * free segments which are eligible for allocation.  As blocks are  * allocated, the allocated segments are removed from the ms_tree and  * added to a per txg allocation tree (ms_alloctree).  This allows us to  * process all allocations in syncing context where it is safe to update  * the on-disk space maps.  Frees are also processed in syncing context.  * Most frees are generated from syncing context, and those that are not  * are held in the spa_free_bplist for processing in syncing context.  * An additional set of in-core trees is maintained to track deferred  * frees (ms_defertree).  Once a block is freed it will move from the  * ms_freedtree to the ms_defertree.  A deferred free means that a block  * has been freed but cannot be used by the pool until TXG_DEFER_SIZE  * transactions groups later.  For example, a block that is freed in txg  * 50 will not be available for reallocation until txg 52 (50 +  * TXG_DEFER_SIZE).  This provides a safety net for uberblock rollback.  * A pool could be safely rolled back TXG_DEFERS_SIZE transactions  * groups and ensure that no block has been reallocated.  *  * The simplified transition diagram looks like this:  *  *  *      ALLOCATE  *         |  *         V  *    free segment (ms_tree) -----> ms_alloctree[4] ----> (write to space map)  *         ^  *         |                           ms_freeingtree<--- FREE  *         |                                 |  *         |                                 v  *         |                           ms_freedtree  *         |                                 |  *         +-------- ms_defertree[2]<-------+---------> (write to space map)  *  *  * Each metaslab's space is tracked in a single space map in the MOS,  * which is only updated in syncing context.  Each time we sync a txg,  * we append the allocs and frees from that txg to the space map.  The  * pool space is only updated once all metaslabs have finished syncing.  *  * To load the in-core free tree we read the space map from disk.  This  * object contains a series of alloc and free records that are combined  * to make up the list of all free segments in this metaslab.  These  * segments are represented in-core by the ms_tree and are stored in an  * AVL tree.  *  * As the space map grows (as a result of the appends) it will  * eventually become space-inefficient.  When the metaslab's in-core  * free tree is zfs_condense_pct/100 times the size of the minimal  * on-disk representation, we rewrite it in its minimized form.  If a  * metaslab needs to condense then we must set the ms_condensing flag to  * ensure that allocations are not performed on the metaslab that is  * being written.  */
struct|struct
name|metaslab
block|{
name|kmutex_t
name|ms_lock
decl_stmt|;
name|kcondvar_t
name|ms_load_cv
decl_stmt|;
name|space_map_t
modifier|*
name|ms_sm
decl_stmt|;
name|uint64_t
name|ms_id
decl_stmt|;
name|uint64_t
name|ms_start
decl_stmt|;
name|uint64_t
name|ms_size
decl_stmt|;
name|uint64_t
name|ms_fragmentation
decl_stmt|;
name|range_tree_t
modifier|*
name|ms_alloctree
index|[
name|TXG_SIZE
index|]
decl_stmt|;
name|range_tree_t
modifier|*
name|ms_tree
decl_stmt|;
comment|/* 	 * The following range trees are accessed only from syncing context. 	 * ms_free*tree only have entries while syncing, and are empty 	 * between syncs. 	 */
name|range_tree_t
modifier|*
name|ms_freeingtree
decl_stmt|;
comment|/* to free this syncing txg */
name|range_tree_t
modifier|*
name|ms_freedtree
decl_stmt|;
comment|/* already freed this syncing txg */
name|range_tree_t
modifier|*
name|ms_defertree
index|[
name|TXG_DEFER_SIZE
index|]
decl_stmt|;
name|boolean_t
name|ms_condensing
decl_stmt|;
comment|/* condensing? */
name|boolean_t
name|ms_condense_wanted
decl_stmt|;
comment|/* 	 * We must hold both ms_lock and ms_group->mg_lock in order to 	 * modify ms_loaded. 	 */
name|boolean_t
name|ms_loaded
decl_stmt|;
name|boolean_t
name|ms_loading
decl_stmt|;
name|int64_t
name|ms_deferspace
decl_stmt|;
comment|/* sum of ms_defermap[] space	*/
name|uint64_t
name|ms_weight
decl_stmt|;
comment|/* weight vs. others in group	*/
name|uint64_t
name|ms_activation_weight
decl_stmt|;
comment|/* activation weight	*/
comment|/* 	 * Track of whenever a metaslab is selected for loading or allocation. 	 * We use this value to determine how long the metaslab should 	 * stay cached. 	 */
name|uint64_t
name|ms_selected_txg
decl_stmt|;
name|uint64_t
name|ms_alloc_txg
decl_stmt|;
comment|/* last successful alloc (debug only) */
name|uint64_t
name|ms_max_size
decl_stmt|;
comment|/* maximum allocatable size	*/
comment|/* 	 * The metaslab block allocators can optionally use a size-ordered 	 * range tree and/or an array of LBAs. Not all allocators use 	 * this functionality. The ms_size_tree should always contain the 	 * same number of segments as the ms_tree. The only difference 	 * is that the ms_size_tree is ordered by segment sizes. 	 */
name|avl_tree_t
name|ms_size_tree
decl_stmt|;
name|uint64_t
name|ms_lbas
index|[
name|MAX_LBAS
index|]
decl_stmt|;
name|metaslab_group_t
modifier|*
name|ms_group
decl_stmt|;
comment|/* metaslab group		*/
name|avl_node_t
name|ms_group_node
decl_stmt|;
comment|/* node in metaslab group tree	*/
name|txg_node_t
name|ms_txg_node
decl_stmt|;
comment|/* per-txg dirty metaslab links	*/
block|}
struct|;
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
comment|/* _SYS_METASLAB_IMPL_H */
end_comment

end_unit

