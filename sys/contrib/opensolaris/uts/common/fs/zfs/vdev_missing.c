begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/*  * The 'missing' vdev is a special vdev type used only during import.  It  * signifies a placeholder in the root vdev for some vdev that we know is  * missing.  We pass it down to the kernel to allow the rest of the  * configuration to parsed and an attempt made to open all available devices.  * Because its GUID is always 0, we know that the guid sum will mismatch and we  * won't be able to open the pool anyway.  */
end_comment

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
file|<sys/vdev_impl.h>
end_include

begin_include
include|#
directive|include
file|<sys/fs/zfs.h>
end_include

begin_include
include|#
directive|include
file|<sys/zio.h>
end_include

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|vdev_missing_open
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|uint64_t
modifier|*
name|psize
parameter_list|,
name|uint64_t
modifier|*
name|ashift
parameter_list|)
block|{
comment|/* 	 * Really this should just fail.  But then the root vdev will be in the 	 * faulted state with VDEV_AUX_NO_REPLICAS, when what we really want is 	 * VDEV_AUX_BAD_GUID_SUM.  So we pretend to succeed, knowing that we 	 * will fail the GUID sum check before ever trying to open the pool. 	 */
operator|*
name|psize
operator|=
name|SPA_MINDEVSIZE
expr_stmt|;
operator|*
name|ashift
operator|=
name|SPA_MINBLOCKSHIFT
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|vdev_missing_close
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|vdev_missing_io_start
parameter_list|(
name|zio_t
modifier|*
name|zio
parameter_list|)
block|{
name|zio
operator|->
name|io_error
operator|=
name|ENOTSUP
expr_stmt|;
name|zio_next_stage_async
argument_list|(
name|zio
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|vdev_missing_io_done
parameter_list|(
name|zio_t
modifier|*
name|zio
parameter_list|)
block|{
name|zio_next_stage
argument_list|(
name|zio
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|vdev_ops_t
name|vdev_missing_ops
init|=
block|{
name|vdev_missing_open
block|,
name|vdev_missing_close
block|,
name|vdev_default_asize
block|,
name|vdev_missing_io_start
block|,
name|vdev_missing_io_done
block|,
name|NULL
block|,
name|VDEV_TYPE_MISSING
block|,
comment|/* name of this vdev type */
name|B_TRUE
comment|/* leaf vdev */
block|}
decl_stmt|;
end_decl_stmt

end_unit

