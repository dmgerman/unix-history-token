begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1999-2001 by Sun Microsystems, Inc.  * All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_OPENSOLARIS_SYS_CYCLIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_OPENSOLARIS_SYS_CYCLIC_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_typedef
typedef|typedef
name|void
name|cpu_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ASM
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpuvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ASM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ASM
end_ifndef

begin_typedef
typedef|typedef
name|uintptr_t
name|cyclic_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|cyc_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|cyc_level_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cyc_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|cyb_arg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CYCLIC_NONE
value|((cyclic_id_t)0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|cyc_handler
block|{
name|cyc_func_t
name|cyh_func
decl_stmt|;
name|void
modifier|*
name|cyh_arg
decl_stmt|;
block|}
name|cyc_handler_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cyc_time
block|{
name|hrtime_t
name|cyt_when
decl_stmt|;
name|hrtime_t
name|cyt_interval
decl_stmt|;
block|}
name|cyc_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cyc_omni_handler
block|{
name|void
function_decl|(
modifier|*
name|cyo_online
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|cpu_t
modifier|*
parameter_list|,
name|cyc_handler_t
modifier|*
parameter_list|,
name|cyc_time_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cyo_offline
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|cpu_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|cyo_arg
decl_stmt|;
block|}
name|cyc_omni_handler_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|cyclic_id_t
name|cyclic_add
parameter_list|(
name|cyc_handler_t
modifier|*
parameter_list|,
name|cyc_time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cyclic_id_t
name|cyclic_add_omni
parameter_list|(
name|cyc_omni_handler_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cyclic_remove
parameter_list|(
name|cyclic_id_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ASM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

