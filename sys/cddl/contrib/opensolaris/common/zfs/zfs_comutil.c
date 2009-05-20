begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/*  * This file is intended for functions that ought to be common between user  * land (libzfs) and the kernel. When many common routines need to be shared  * then a separate file should to be created.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/fs/zfs.h>
end_include

begin_include
include|#
directive|include
file|<sys/nvpair.h>
end_include

begin_comment
comment|/*  * Are there allocatable vdevs?  */
end_comment

begin_function
name|boolean_t
name|zfs_allocatable_devs
parameter_list|(
name|nvlist_t
modifier|*
name|nv
parameter_list|)
block|{
name|uint64_t
name|is_log
decl_stmt|;
name|uint_t
name|c
decl_stmt|;
name|nvlist_t
modifier|*
modifier|*
name|child
decl_stmt|;
name|uint_t
name|children
decl_stmt|;
if|if
condition|(
name|nvlist_lookup_nvlist_array
argument_list|(
name|nv
argument_list|,
name|ZPOOL_CONFIG_CHILDREN
argument_list|,
operator|&
name|child
argument_list|,
operator|&
name|children
argument_list|)
operator|!=
literal|0
condition|)
block|{
return|return
operator|(
name|B_FALSE
operator|)
return|;
block|}
for|for
control|(
name|c
operator|=
literal|0
init|;
name|c
operator|<
name|children
condition|;
name|c
operator|++
control|)
block|{
name|is_log
operator|=
literal|0
expr_stmt|;
operator|(
name|void
operator|)
name|nvlist_lookup_uint64
argument_list|(
name|child
index|[
name|c
index|]
argument_list|,
name|ZPOOL_CONFIG_IS_LOG
argument_list|,
operator|&
name|is_log
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|is_log
condition|)
return|return
operator|(
name|B_TRUE
operator|)
return|;
block|}
return|return
operator|(
name|B_FALSE
operator|)
return|;
block|}
end_function

end_unit

