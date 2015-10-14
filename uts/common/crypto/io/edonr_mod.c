begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://opensource.org/licenses/CDDL-1.0.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2013 Saso Kiselkov. All rights reserved.  */
end_comment

begin_include
include|#
directive|include
file|<sys/modctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/crypto/common.h>
end_include

begin_include
include|#
directive|include
file|<sys/crypto/spi.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/edonr.h>
end_include

begin_comment
comment|/*  * Unlike sha2 or skein, we won't expose edonr via the Kernel Cryptographic  * Framework (KCF), because Edon-R is *NOT* suitable for general-purpose  * cryptographic use. Users of Edon-R must interface directly to this module.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|modlmisc
name|modlmisc
init|=
block|{
operator|&
name|mod_miscops
block|,
literal|"Edon-R Message-Digest Algorithm"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|modlinkage
name|modlinkage
init|=
block|{
name|MODREV_1
block|,
operator|&
name|modlmisc
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|_init
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
operator|(
name|error
operator|=
name|mod_install
argument_list|(
operator|&
name|modlinkage
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|_info
parameter_list|(
name|struct
name|modinfo
modifier|*
name|modinfop
parameter_list|)
block|{
return|return
operator|(
name|mod_info
argument_list|(
operator|&
name|modlinkage
argument_list|,
name|modinfop
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

