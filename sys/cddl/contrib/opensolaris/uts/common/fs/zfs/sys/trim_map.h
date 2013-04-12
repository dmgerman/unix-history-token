begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 Pawel Jakub Dawidek<pawel@dawidek.net>.  * All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TRIM_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TRIM_MAP_H
end_define

begin_include
include|#
directive|include
file|<sys/avl.h>
end_include

begin_include
include|#
directive|include
file|<sys/list.h>
end_include

begin_include
include|#
directive|include
file|<sys/spa.h>
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
name|void
name|trim_map_create
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
specifier|extern
name|void
name|trim_map_destroy
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
specifier|extern
name|void
name|trim_map_free
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|uint64_t
name|offset
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|trim_map_write_start
parameter_list|(
name|zio_t
modifier|*
name|zio
parameter_list|)
function_decl|;
specifier|extern
name|void
name|trim_map_write_done
parameter_list|(
name|zio_t
modifier|*
name|zio
parameter_list|)
function_decl|;
specifier|extern
name|void
name|trim_thread_create
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|)
function_decl|;
specifier|extern
name|void
name|trim_thread_destroy
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|)
function_decl|;
specifier|extern
name|void
name|trim_thread_wakeup
parameter_list|(
name|spa_t
modifier|*
name|spa
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
comment|/* _SYS_TRIM_MAP_H */
end_comment

end_unit

