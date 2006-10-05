begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)mdesc_fini.c	1.4	06/05/16 SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mdesc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mdesc_impl.h>
end_include

begin_comment
comment|/*  * Cleanup the internal MD structure. Does not  * deallocate the buffer holding the MD.  */
end_comment

begin_function
name|int
name|md_fini
parameter_list|(
name|md_t
modifier|*
name|ptr
parameter_list|)
block|{
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
name|mdp
operator|->
name|freep
argument_list|(
name|mdp
argument_list|,
sizeof|sizeof
argument_list|(
name|md_impl_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

