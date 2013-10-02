begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_REGSET_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_REGSET_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
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
name|dt_regset
block|{
name|ulong_t
name|dr_size
decl_stmt|;
comment|/* number of registers in set */
name|ulong_t
modifier|*
name|dr_bitmap
decl_stmt|;
comment|/* bitmap of active registers */
block|}
name|dt_regset_t
typedef|;
specifier|extern
name|dt_regset_t
modifier|*
name|dt_regset_create
parameter_list|(
name|ulong_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_regset_destroy
parameter_list|(
name|dt_regset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_regset_reset
parameter_list|(
name|dt_regset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_regset_alloc
parameter_list|(
name|dt_regset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_regset_free
parameter_list|(
name|dt_regset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_regset_assert_free
parameter_list|(
name|dt_regset_t
modifier|*
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
comment|/* _DT_REGSET_H */
end_comment

end_unit

