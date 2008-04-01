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
name|_SYS_FS_ZFS_RLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FS_ZFS_RLOCK_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
ifdef|#
directive|ifdef
name|_KERNEL
include|#
directive|include
file|<sys/zfs_znode.h>
typedef|typedef
enum|enum
block|{
name|RL_READER
block|,
name|RL_WRITER
block|,
name|RL_APPEND
block|}
name|rl_type_t
typedef|;
typedef|typedef
struct|struct
name|rl
block|{
name|znode_t
modifier|*
name|r_zp
decl_stmt|;
comment|/* znode this lock applies to */
name|avl_node_t
name|r_node
decl_stmt|;
comment|/* avl node link */
name|uint64_t
name|r_off
decl_stmt|;
comment|/* file range offset */
name|uint64_t
name|r_len
decl_stmt|;
comment|/* file range length */
name|uint_t
name|r_cnt
decl_stmt|;
comment|/* range reference count in tree */
name|rl_type_t
name|r_type
decl_stmt|;
comment|/* range type */
name|kcondvar_t
name|r_wr_cv
decl_stmt|;
comment|/* cv for waiting writers */
name|kcondvar_t
name|r_rd_cv
decl_stmt|;
comment|/* cv for waiting readers */
name|uint8_t
name|r_proxy
decl_stmt|;
comment|/* acting for original range */
name|uint8_t
name|r_write_wanted
decl_stmt|;
comment|/* writer wants to lock this range */
name|uint8_t
name|r_read_wanted
decl_stmt|;
comment|/* reader wants to lock this range */
block|}
name|rl_t
typedef|;
comment|/*  * Lock a range (offset, length) as either shared (READER)  * or exclusive (WRITER or APPEND). APPEND is a special type that  * is converted to WRITER that specified to lock from the start of the  * end of file.  zfs_range_lock() returns the range lock structure.  */
name|rl_t
modifier|*
name|zfs_range_lock
parameter_list|(
name|znode_t
modifier|*
name|zp
parameter_list|,
name|uint64_t
name|off
parameter_list|,
name|uint64_t
name|len
parameter_list|,
name|rl_type_t
name|type
parameter_list|)
function_decl|;
comment|/*  * Unlock range and destroy range lock structure.  */
name|void
name|zfs_range_unlock
parameter_list|(
name|rl_t
modifier|*
name|rl
parameter_list|)
function_decl|;
comment|/*  * Reduce range locked as RW_WRITER from whole file to specified range.  * Asserts the whole file was previously locked.  */
name|void
name|zfs_range_reduce
parameter_list|(
name|rl_t
modifier|*
name|rl
parameter_list|,
name|uint64_t
name|off
parameter_list|,
name|uint64_t
name|len
parameter_list|)
function_decl|;
comment|/*  * AVL comparison function used to compare range locks  */
name|int
name|zfs_range_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|arg1
parameter_list|,
specifier|const
name|void
modifier|*
name|arg2
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
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
comment|/* _SYS_FS_ZFS_RLOCK_H */
end_comment

end_unit

