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
name|_DFETCH_H
end_ifndef

begin_define
define|#
directive|define
name|_DFETCH_H
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
file|<sys/zfs_context.h>
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
specifier|extern
name|uint64_t
name|zfetch_array_rd_sz
decl_stmt|;
struct_decl|struct
name|dnode
struct_decl|;
comment|/* so we can reference dnode */
typedef|typedef
enum|enum
name|zfetch_dirn
block|{
name|ZFETCH_FORWARD
init|=
literal|1
block|,
comment|/* prefetch increasing block numbers */
name|ZFETCH_BACKWARD
init|=
operator|-
literal|1
comment|/* prefetch decreasing block numbers */
block|}
name|zfetch_dirn_t
typedef|;
typedef|typedef
struct|struct
name|zstream
block|{
name|uint64_t
name|zst_offset
decl_stmt|;
comment|/* offset of starting block in range */
name|uint64_t
name|zst_len
decl_stmt|;
comment|/* length of range, in blocks */
name|zfetch_dirn_t
name|zst_direction
decl_stmt|;
comment|/* direction of prefetch */
name|uint64_t
name|zst_stride
decl_stmt|;
comment|/* length of stride, in blocks */
name|uint64_t
name|zst_ph_offset
decl_stmt|;
comment|/* prefetch offset, in blocks */
name|uint64_t
name|zst_cap
decl_stmt|;
comment|/* prefetch limit (cap), in blocks */
name|kmutex_t
name|zst_lock
decl_stmt|;
comment|/* protects stream */
name|clock_t
name|zst_last
decl_stmt|;
comment|/* lbolt of last prefetch */
name|avl_node_t
name|zst_node
decl_stmt|;
comment|/* embed avl node here */
block|}
name|zstream_t
typedef|;
typedef|typedef
struct|struct
name|zfetch
block|{
name|krwlock_t
name|zf_rwlock
decl_stmt|;
comment|/* protects zfetch structure */
name|list_t
name|zf_stream
decl_stmt|;
comment|/* AVL tree of zstream_t's */
name|struct
name|dnode
modifier|*
name|zf_dnode
decl_stmt|;
comment|/* dnode that owns this zfetch */
name|uint32_t
name|zf_stream_cnt
decl_stmt|;
comment|/* # of active streams */
name|uint64_t
name|zf_alloc_fail
decl_stmt|;
comment|/* # of failed attempts to alloc strm */
block|}
name|zfetch_t
typedef|;
name|void
name|dmu_zfetch_init
parameter_list|(
name|zfetch_t
modifier|*
parameter_list|,
name|struct
name|dnode
modifier|*
parameter_list|)
function_decl|;
name|void
name|dmu_zfetch_rele
parameter_list|(
name|zfetch_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|dmu_zfetch
parameter_list|(
name|zfetch_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|int
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
comment|/* _DFETCH_H */
end_comment

end_unit

