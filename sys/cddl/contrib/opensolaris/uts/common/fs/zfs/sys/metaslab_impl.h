begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011, 2014 by Delphix. All rights reserved.  */
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
comment|/*  * A metaslab class encompasses a category of allocatable top-level vdevs.  * Each top-level vdev is associated with a metaslab group which defines  * the allocatable region for that vdev. Examples of these categories include  * "normal" for data block allocations (i.e. main pool allocations) or "log"  * for allocations designated for intent log devices (i.e. slog devices).  * When a block allocation is requested from the SPA it is associated with a  * metaslab_class_t, and only top-level vdevs (i.e. metaslab groups) belonging  * to the class can be used to satisfy that request. Allocations are done  * by traversing the metaslab groups that are linked off of the mc_rotor field.  * This rotor points to the next metaslab group where allocations will be  * attempted. Allocating a block is a 3 step process -- select the metaslab  * group, select the metaslab, and then allocate the block. The metaslab  * class defines the low-level block allocator that will be used as the  * final step in allocation. These allocators are pluggable allowing each class  * to use a block allocator that best suits that class.  */
struct|struct
name|metaslab_class
block|{
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
name|mc_minblocksize
decl_stmt|;
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
comment|/*  * Each metaslab maintains a set of in-core trees to track metaslab operations.  * The in-core free tree (ms_tree) contains the current list of free segments.  * As blocks are allocated, the allocated segment are removed from the ms_tree  * and added to a per txg allocation tree (ms_alloctree). As blocks are freed,  * they are added to the per txg free tree (ms_freetree). These per txg  * trees allow us to process all allocations and frees in syncing context  * where it is safe to update the on-disk space maps. One additional in-core  * tree is maintained to track deferred frees (ms_defertree). Once a block  * is freed it will move from the ms_freetree to the ms_defertree. A deferred  * free means that a block has been freed but cannot be used by the pool  * until TXG_DEFER_SIZE transactions groups later. For example, a block  * that is freed in txg 50 will not be available for reallocation until  * txg 52 (50 + TXG_DEFER_SIZE).  This provides a safety net for uberblock  * rollback. A pool could be safely rolled back TXG_DEFERS_SIZE  * transactions groups and ensure that no block has been reallocated.  *  * The simplified transition diagram looks like this:  *  *  *      ALLOCATE  *         |  *         V  *    free segment (ms_tree) --------> ms_alloctree ----> (write to space map)  *         ^  *         |  *         |                           ms_freetree<--- FREE  *         |                                 |  *         |                                 |  *         |                                 |  *         +----------- ms_defertree<-------+---------> (write to space map)  *  *  * Each metaslab's space is tracked in a single space map in the MOS,  * which is only updated in syncing context. Each time we sync a txg,  * we append the allocs and frees from that txg to the space map.  * The pool space is only updated once all metaslabs have finished syncing.  *  * To load the in-core free tree we read the space map from disk.  * This object contains a series of alloc and free records that are  * combined to make up the list of all free segments in this metaslab. These  * segments are represented in-core by the ms_tree and are stored in an  * AVL tree.  *  * As the space map grows (as a result of the appends) it will  * eventually become space-inefficient. When the metaslab's in-core free tree  * is zfs_condense_pct/100 times the size of the minimal on-disk  * representation, we rewrite it in its minimized form. If a metaslab  * needs to condense then we must set the ms_condensing flag to ensure  * that allocations are not performed on the metaslab that is being written.  */
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
name|metaslab_ops_t
modifier|*
name|ms_ops
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
name|ms_freetree
index|[
name|TXG_SIZE
index|]
decl_stmt|;
name|range_tree_t
modifier|*
name|ms_defertree
index|[
name|TXG_DEFER_SIZE
index|]
decl_stmt|;
name|range_tree_t
modifier|*
name|ms_tree
decl_stmt|;
name|boolean_t
name|ms_condensing
decl_stmt|;
comment|/* condensing? */
name|boolean_t
name|ms_condense_wanted
decl_stmt|;
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
name|ms_access_txg
decl_stmt|;
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

