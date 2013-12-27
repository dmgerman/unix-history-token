begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/nvpair.h>
end_include

begin_function
specifier|static
name|void
modifier|*
name|nv_alloc_sys
parameter_list|(
name|nv_alloc_t
modifier|*
name|nva
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
return|return
operator|(
name|kmem_alloc
argument_list|(
name|size
argument_list|,
operator|(
name|int
operator|)
operator|(
name|uintptr_t
operator|)
name|nva
operator|->
name|nva_arg
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|void
name|nv_free_sys
parameter_list|(
name|nv_alloc_t
modifier|*
name|nva
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|kmem_free
argument_list|(
name|buf
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|nv_alloc_ops_t
name|system_ops
init|=
block|{
name|NULL
block|,
comment|/* nv_ao_init() */
name|NULL
block|,
comment|/* nv_ao_fini() */
name|nv_alloc_sys
block|,
comment|/* nv_ao_alloc() */
name|nv_free_sys
block|,
comment|/* nv_ao_free() */
name|NULL
comment|/* nv_ao_reset() */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nv_alloc_t
name|nv_alloc_sleep_def
init|=
block|{
operator|&
name|system_ops
block|,
operator|(
name|void
operator|*
operator|)
name|KM_SLEEP
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nv_alloc_t
name|nv_alloc_nosleep_def
init|=
block|{
operator|&
name|system_ops
block|,
operator|(
name|void
operator|*
operator|)
name|KM_NOSLEEP
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nv_alloc_t
modifier|*
name|nv_alloc_sleep
init|=
operator|&
name|nv_alloc_sleep_def
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nv_alloc_t
modifier|*
name|nv_alloc_nosleep
init|=
operator|&
name|nv_alloc_nosleep_def
decl_stmt|;
end_decl_stmt

end_unit

