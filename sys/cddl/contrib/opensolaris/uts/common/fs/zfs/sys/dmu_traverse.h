begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DMU_TRAVERSE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DMU_TRAVERSE_H
end_define

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
end_include

begin_include
include|#
directive|include
file|<sys/spa.h>
end_include

begin_include
include|#
directive|include
file|<sys/zio.h>
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
struct_decl|struct
name|dnode_phys
struct_decl|;
struct_decl|struct
name|dsl_dataset
struct_decl|;
typedef|typedef
name|int
function_decl|(
name|blkptr_cb_t
function_decl|)
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|,
name|blkptr_t
modifier|*
name|bp
parameter_list|,
specifier|const
name|zbookmark_t
modifier|*
name|zb
parameter_list|,
specifier|const
name|struct
name|dnode_phys
modifier|*
name|dnp
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
define|#
directive|define
name|TRAVERSE_PRE
value|(1<<0)
define|#
directive|define
name|TRAVERSE_POST
value|(1<<1)
define|#
directive|define
name|TRAVERSE_PREFETCH_METADATA
value|(1<<2)
define|#
directive|define
name|TRAVERSE_PREFETCH_DATA
value|(1<<3)
define|#
directive|define
name|TRAVERSE_PREFETCH
value|(TRAVERSE_PREFETCH_METADATA | TRAVERSE_PREFETCH_DATA)
name|int
name|traverse_dataset
parameter_list|(
name|struct
name|dsl_dataset
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|txg_start
parameter_list|,
name|int
name|flags
parameter_list|,
name|blkptr_cb_t
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|int
name|traverse_pool
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|,
name|blkptr_cb_t
name|func
parameter_list|,
name|void
modifier|*
name|arg
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
comment|/* _SYS_DMU_TRAVERSE_H */
end_comment

end_unit

