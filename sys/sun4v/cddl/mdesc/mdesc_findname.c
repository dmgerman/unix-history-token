begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/cddl/mdesc.h>
end_include

begin_include
include|#
directive|include
file|<machine/cddl/mdesc_impl.h>
end_include

begin_function
name|mde_str_cookie_t
name|md_find_name
parameter_list|(
name|md_t
modifier|*
name|ptr
parameter_list|,
name|char
modifier|*
name|namep
parameter_list|)
block|{
name|int
name|idx
decl_stmt|,
name|len
decl_stmt|;
name|md_impl_t
modifier|*
name|mdp
decl_stmt|;
name|mdp
operator|=
operator|(
name|md_impl_t
operator|*
operator|)
name|ptr
expr_stmt|;
comment|/* 	 * At some point init should build a local hash table to 	 * speed these name searches ... for now use brute force 	 * because the machien descriptions are so small anyway. 	 */
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|mdp
operator|->
name|name_blk_size
condition|;
name|idx
operator|+=
name|len
control|)
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
operator|&
operator|(
name|mdp
operator|->
name|namep
index|[
name|idx
index|]
operator|)
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|p
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|p
argument_list|,
name|namep
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
operator|(
name|mde_str_cookie_t
operator|)
name|idx
operator|)
return|;
block|}
return|return
operator|(
name|MDE_INVAL_STR_COOKIE
operator|)
return|;
block|}
end_function

end_unit

