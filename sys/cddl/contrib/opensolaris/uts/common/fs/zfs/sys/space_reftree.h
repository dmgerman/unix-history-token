begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SPACE_REFTREE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SPACE_REFTREE_H
end_define

begin_include
include|#
directive|include
file|<sys/range_tree.h>
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
typedef|typedef
struct|struct
name|space_ref
block|{
name|avl_node_t
name|sr_node
decl_stmt|;
comment|/* AVL node */
name|uint64_t
name|sr_offset
decl_stmt|;
comment|/* range offset (start or end) */
name|int64_t
name|sr_refcnt
decl_stmt|;
comment|/* associated reference count */
block|}
name|space_ref_t
typedef|;
name|void
name|space_reftree_create
parameter_list|(
name|avl_tree_t
modifier|*
name|t
parameter_list|)
function_decl|;
name|void
name|space_reftree_destroy
parameter_list|(
name|avl_tree_t
modifier|*
name|t
parameter_list|)
function_decl|;
name|void
name|space_reftree_add_seg
parameter_list|(
name|avl_tree_t
modifier|*
name|t
parameter_list|,
name|uint64_t
name|start
parameter_list|,
name|uint64_t
name|end
parameter_list|,
name|int64_t
name|refcnt
parameter_list|)
function_decl|;
name|void
name|space_reftree_add_map
parameter_list|(
name|avl_tree_t
modifier|*
name|t
parameter_list|,
name|range_tree_t
modifier|*
name|rt
parameter_list|,
name|int64_t
name|refcnt
parameter_list|)
function_decl|;
name|void
name|space_reftree_generate_map
parameter_list|(
name|avl_tree_t
modifier|*
name|t
parameter_list|,
name|range_tree_t
modifier|*
name|rt
parameter_list|,
name|int64_t
name|minref
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
comment|/* _SYS_SPACE_REFTREE_H */
end_comment

end_unit

