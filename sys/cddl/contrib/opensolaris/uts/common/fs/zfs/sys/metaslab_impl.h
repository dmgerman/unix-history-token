begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
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

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
struct|struct
name|metaslab_class
block|{
name|metaslab_group_t
modifier|*
name|mc_rotor
decl_stmt|;
name|uint64_t
name|mc_allocated
decl_stmt|;
block|}
struct|;
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
name|int64_t
name|mg_bias
decl_stmt|;
name|metaslab_class_t
modifier|*
name|mg_class
decl_stmt|;
name|vdev_t
modifier|*
name|mg_vd
decl_stmt|;
name|metaslab_group_t
modifier|*
name|mg_prev
decl_stmt|;
name|metaslab_group_t
modifier|*
name|mg_next
decl_stmt|;
block|}
struct|;
comment|/*  * Each metaslab's free space is tracked in space map object in the MOS,  * which is only updated in syncing context.  Each time we sync a txg,  * we append the allocs and frees from that txg to the space map object.  * When the txg is done syncing, metaslab_sync_done() updates ms_smo  * to ms_smo_syncing.  Everything in ms_smo is always safe to allocate.  */
struct|struct
name|metaslab
block|{
name|kmutex_t
name|ms_lock
decl_stmt|;
comment|/* metaslab lock		*/
name|space_map_obj_t
name|ms_smo
decl_stmt|;
comment|/* synced space map object	*/
name|space_map_obj_t
name|ms_smo_syncing
decl_stmt|;
comment|/* syncing space map object	*/
name|space_map_t
name|ms_allocmap
index|[
name|TXG_SIZE
index|]
decl_stmt|;
comment|/* allocated this txg	*/
name|space_map_t
name|ms_freemap
index|[
name|TXG_SIZE
index|]
decl_stmt|;
comment|/* freed this txg	*/
name|space_map_t
name|ms_map
decl_stmt|;
comment|/* in-core free space map	*/
name|uint64_t
name|ms_weight
decl_stmt|;
comment|/* weight vs. others in group	*/
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

