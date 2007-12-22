begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZIO_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_ZIO_IMPL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
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
comment|/*  * I/O Groups: pipeline stage definitions.  */
typedef|typedef
enum|enum
name|zio_stage
block|{
name|ZIO_STAGE_OPEN
init|=
literal|0
block|,
comment|/* RWFCI */
name|ZIO_STAGE_WAIT_CHILDREN_READY
block|,
comment|/* RWFCI */
name|ZIO_STAGE_WRITE_COMPRESS
block|,
comment|/* -W--- */
name|ZIO_STAGE_CHECKSUM_GENERATE
block|,
comment|/* -W--- */
name|ZIO_STAGE_GANG_PIPELINE
block|,
comment|/* -WFC- */
name|ZIO_STAGE_GET_GANG_HEADER
block|,
comment|/* -WFC- */
name|ZIO_STAGE_REWRITE_GANG_MEMBERS
block|,
comment|/* -W--- */
name|ZIO_STAGE_FREE_GANG_MEMBERS
block|,
comment|/* --F-- */
name|ZIO_STAGE_CLAIM_GANG_MEMBERS
block|,
comment|/* ---C- */
name|ZIO_STAGE_DVA_ALLOCATE
block|,
comment|/* -W--- */
name|ZIO_STAGE_DVA_FREE
block|,
comment|/* --F-- */
name|ZIO_STAGE_DVA_CLAIM
block|,
comment|/* ---C- */
name|ZIO_STAGE_GANG_CHECKSUM_GENERATE
block|,
comment|/* -W--- */
name|ZIO_STAGE_READY
block|,
comment|/* RWFCI */
name|ZIO_STAGE_VDEV_IO_START
block|,
comment|/* RW--I */
name|ZIO_STAGE_VDEV_IO_DONE
block|,
comment|/* RW--I */
name|ZIO_STAGE_VDEV_IO_ASSESS
block|,
comment|/* RW--I */
name|ZIO_STAGE_WAIT_CHILDREN_DONE
block|,
comment|/* RWFCI */
name|ZIO_STAGE_CHECKSUM_VERIFY
block|,
comment|/* R---- */
name|ZIO_STAGE_READ_GANG_MEMBERS
block|,
comment|/* R---- */
name|ZIO_STAGE_READ_DECOMPRESS
block|,
comment|/* R---- */
name|ZIO_STAGE_DONE
comment|/* RWFCI */
block|}
name|zio_stage_t
typedef|;
comment|/*  * The stages for which there's some performance value in going async.  * When compression is enabled, ZIO_STAGE_WRITE_COMPRESS is ORed in as well.  */
define|#
directive|define
name|ZIO_ASYNC_PIPELINE_STAGES
define|\
value|((1U<< ZIO_STAGE_CHECKSUM_GENERATE) |			\ 	(1U<< ZIO_STAGE_VDEV_IO_DONE) |			\ 	(1U<< ZIO_STAGE_CHECKSUM_VERIFY) |			\ 	(1U<< ZIO_STAGE_READ_DECOMPRESS))
define|#
directive|define
name|ZIO_VDEV_IO_PIPELINE
define|\
value|((1U<< ZIO_STAGE_VDEV_IO_START) |			\ 	(1U<< ZIO_STAGE_VDEV_IO_DONE) |			\ 	(1U<< ZIO_STAGE_VDEV_IO_ASSESS))
define|#
directive|define
name|ZIO_READ_PHYS_PIPELINE
define|\
value|((1U<< ZIO_STAGE_OPEN) |				\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_READY) |			\ 	(1U<< ZIO_STAGE_READY) |				\ 	ZIO_VDEV_IO_PIPELINE |					\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_DONE) |			\ 	(1U<< ZIO_STAGE_CHECKSUM_VERIFY) |			\ 	(1U<< ZIO_STAGE_DONE))
define|#
directive|define
name|ZIO_READ_PIPELINE
define|\
value|ZIO_READ_PHYS_PIPELINE
define|#
directive|define
name|ZIO_WRITE_PHYS_PIPELINE
define|\
value|((1U<< ZIO_STAGE_OPEN) |				\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_READY) |			\ 	(1U<< ZIO_STAGE_CHECKSUM_GENERATE) |			\ 	(1U<< ZIO_STAGE_READY) |				\ 	ZIO_VDEV_IO_PIPELINE |					\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_DONE) |			\ 	(1U<< ZIO_STAGE_DONE))
define|#
directive|define
name|ZIO_WRITE_COMMON_PIPELINE
define|\
value|ZIO_WRITE_PHYS_PIPELINE
define|#
directive|define
name|ZIO_WRITE_PIPELINE
define|\
value|((1U<< ZIO_STAGE_WRITE_COMPRESS) |			\ 	ZIO_WRITE_COMMON_PIPELINE)
define|#
directive|define
name|ZIO_GANG_STAGES
define|\
value|((1U<< ZIO_STAGE_GET_GANG_HEADER) |			\ 	(1U<< ZIO_STAGE_REWRITE_GANG_MEMBERS) |		\ 	(1U<< ZIO_STAGE_FREE_GANG_MEMBERS) |			\ 	(1U<< ZIO_STAGE_CLAIM_GANG_MEMBERS) |			\ 	(1U<< ZIO_STAGE_GANG_CHECKSUM_GENERATE) |		\ 	(1U<< ZIO_STAGE_READ_GANG_MEMBERS))
define|#
directive|define
name|ZIO_REWRITE_PIPELINE
define|\
value|((1U<< ZIO_STAGE_GANG_PIPELINE) |			\ 	(1U<< ZIO_STAGE_GET_GANG_HEADER) |			\ 	(1U<< ZIO_STAGE_REWRITE_GANG_MEMBERS) |		\ 	(1U<< ZIO_STAGE_GANG_CHECKSUM_GENERATE) |		\ 	ZIO_WRITE_COMMON_PIPELINE)
define|#
directive|define
name|ZIO_WRITE_ALLOCATE_PIPELINE
define|\
value|((1U<< ZIO_STAGE_DVA_ALLOCATE) |			\ 	ZIO_WRITE_COMMON_PIPELINE)
define|#
directive|define
name|ZIO_GANG_FREE_STAGES
define|\
value|((1U<< ZIO_STAGE_GET_GANG_HEADER) |			\ 	(1U<< ZIO_STAGE_FREE_GANG_MEMBERS))
define|#
directive|define
name|ZIO_FREE_PIPELINE
define|\
value|((1U<< ZIO_STAGE_OPEN) |				\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_READY) |			\ 	(1U<< ZIO_STAGE_GANG_PIPELINE) |			\ 	(1U<< ZIO_STAGE_GET_GANG_HEADER) |			\ 	(1U<< ZIO_STAGE_FREE_GANG_MEMBERS) |			\ 	(1U<< ZIO_STAGE_DVA_FREE) |				\ 	(1U<< ZIO_STAGE_READY) |				\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_DONE) |			\ 	(1U<< ZIO_STAGE_DONE))
define|#
directive|define
name|ZIO_CLAIM_PIPELINE
define|\
value|((1U<< ZIO_STAGE_OPEN) |				\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_READY) |			\ 	(1U<< ZIO_STAGE_GANG_PIPELINE) |			\ 	(1U<< ZIO_STAGE_GET_GANG_HEADER) |			\ 	(1U<< ZIO_STAGE_CLAIM_GANG_MEMBERS) |			\ 	(1U<< ZIO_STAGE_DVA_CLAIM) |				\ 	(1U<< ZIO_STAGE_READY) |				\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_DONE) |			\ 	(1U<< ZIO_STAGE_DONE))
define|#
directive|define
name|ZIO_IOCTL_PIPELINE
define|\
value|((1U<< ZIO_STAGE_OPEN) |				\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_READY) |			\ 	(1U<< ZIO_STAGE_READY) |				\ 	ZIO_VDEV_IO_PIPELINE |					\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_DONE) |			\ 	(1U<< ZIO_STAGE_DONE))
define|#
directive|define
name|ZIO_WAIT_FOR_CHILDREN_PIPELINE
define|\
value|((1U<< ZIO_STAGE_WAIT_CHILDREN_READY) |		\ 	(1U<< ZIO_STAGE_READY) |				\ 	(1U<< ZIO_STAGE_WAIT_CHILDREN_DONE) |			\ 	(1U<< ZIO_STAGE_DONE))
define|#
directive|define
name|ZIO_WAIT_FOR_CHILDREN_DONE_PIPELINE
define|\
value|((1U<< ZIO_STAGE_WAIT_CHILDREN_DONE) |			\ 	(1U<< ZIO_STAGE_DONE))
define|#
directive|define
name|ZIO_VDEV_CHILD_PIPELINE
define|\
value|(ZIO_WAIT_FOR_CHILDREN_DONE_PIPELINE |			\ 	ZIO_VDEV_IO_PIPELINE)
define|#
directive|define
name|ZIO_ERROR_PIPELINE_MASK
define|\
value|ZIO_WAIT_FOR_CHILDREN_PIPELINE
typedef|typedef
name|struct
name|zio_transform
name|zio_transform_t
typedef|;
struct|struct
name|zio_transform
block|{
name|void
modifier|*
name|zt_data
decl_stmt|;
name|uint64_t
name|zt_size
decl_stmt|;
name|uint64_t
name|zt_bufsize
decl_stmt|;
name|zio_transform_t
modifier|*
name|zt_next
decl_stmt|;
block|}
struct|;
specifier|extern
name|void
name|zio_inject_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zio_inject_fini
parameter_list|(
name|void
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
comment|/* _ZIO_IMPL_H */
end_comment

end_unit

