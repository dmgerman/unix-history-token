begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 by Delphix. All rights reserved.  */
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
comment|/*  * XXX -- Describe ZFS I/O pipeline here. Fill in as needed.  *  * The ZFS I/O pipeline is comprised of various stages which are defined  * in the zio_stage enum below. The individual stages are used to construct  * these basic I/O operations: Read, Write, Free, Claim, and Ioctl.  *  * I/O operations: (XXX - provide detail for each of the operations)  *  * Read:  * Write:  * Free:  * Claim:  * Ioctl:  *  * Although the most common pipeline are used by the basic I/O operations  * above, there are some helper pipelines (one could consider them  * sub-pipelines) which are used internally by the ZIO module and are  * explained below:  *  * Interlock Pipeline:  * The interlock pipeline is the most basic pipeline and is used by all  * of the I/O operations. The interlock pipeline does not perform any I/O  * and is used to coordinate the dependencies between I/Os that are being  * issued (i.e. the parent/child relationship).  *  * Vdev child Pipeline:  * The vdev child pipeline is responsible for performing the physical I/O.  * It is in this pipeline where the I/O are queued and possibly cached.  *  * In addition to performing I/O, the pipeline is also responsible for  * data transformations. The transformations performed are based on the  * specific properties that user may have selected and modify the  * behavior of the pipeline. Examples of supported transformations are  * compression, dedup, and nop writes. Transformations will either modify  * the data or the pipeline. This list below further describes each of  * the supported transformations:  *  * Compression:  * ZFS supports three different flavors of compression -- gzip, lzjb, and  * zle. Compression occurs as part of the write pipeline and is performed  * in the ZIO_STAGE_WRITE_BP_INIT stage.  *  * Dedup:  * Dedup reads are handled by the ZIO_STAGE_DDT_READ_START and  * ZIO_STAGE_DDT_READ_DONE stages. These stages are added to an existing  * read pipeline if the dedup bit is set on the block pointer.  * Writing a dedup block is performed by the ZIO_STAGE_DDT_WRITE stage  * and added to a write pipeline if a user has enabled dedup on that  * particular dataset.  *  * NOP Write:  * The NOP write feature is performed by the ZIO_STAGE_NOP_WRITE stage  * and is added to an existing write pipeline if a crypographically  * secure checksum (i.e. SHA256) is enabled and compression is turned on.  * The NOP write stage will compare the checksums of the current data  * on-disk (level-0 blocks only) and the data that is currently being written.  * If the checksum values are identical then the pipeline is converted to  * an interlock pipeline skipping block allocation and bypassing the  * physical I/O.  The nop write feature can handle writes in either  * syncing or open context (i.e. zil writes) and as a result is mutually  * exclusive with dedup.  */
comment|/*  * zio pipeline stage definitions  */
enum|enum
name|zio_stage
block|{
name|ZIO_STAGE_OPEN
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* RWFCI */
name|ZIO_STAGE_READ_BP_INIT
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* R---- */
name|ZIO_STAGE_FREE_BP_INIT
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* --F-- */
name|ZIO_STAGE_ISSUE_ASYNC
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* RWF-- */
name|ZIO_STAGE_WRITE_BP_INIT
init|=
literal|1
operator|<<
literal|4
block|,
comment|/* -W--- */
name|ZIO_STAGE_CHECKSUM_GENERATE
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* -W--- */
name|ZIO_STAGE_NOP_WRITE
init|=
literal|1
operator|<<
literal|6
block|,
comment|/* -W--- */
name|ZIO_STAGE_DDT_READ_START
init|=
literal|1
operator|<<
literal|7
block|,
comment|/* R---- */
name|ZIO_STAGE_DDT_READ_DONE
init|=
literal|1
operator|<<
literal|8
block|,
comment|/* R---- */
name|ZIO_STAGE_DDT_WRITE
init|=
literal|1
operator|<<
literal|9
block|,
comment|/* -W--- */
name|ZIO_STAGE_DDT_FREE
init|=
literal|1
operator|<<
literal|10
block|,
comment|/* --F-- */
name|ZIO_STAGE_GANG_ASSEMBLE
init|=
literal|1
operator|<<
literal|11
block|,
comment|/* RWFC- */
name|ZIO_STAGE_GANG_ISSUE
init|=
literal|1
operator|<<
literal|12
block|,
comment|/* RWFC- */
name|ZIO_STAGE_DVA_ALLOCATE
init|=
literal|1
operator|<<
literal|13
block|,
comment|/* -W--- */
name|ZIO_STAGE_DVA_FREE
init|=
literal|1
operator|<<
literal|14
block|,
comment|/* --F-- */
name|ZIO_STAGE_DVA_CLAIM
init|=
literal|1
operator|<<
literal|15
block|,
comment|/* ---C- */
name|ZIO_STAGE_READY
init|=
literal|1
operator|<<
literal|16
block|,
comment|/* RWFCI */
name|ZIO_STAGE_VDEV_IO_START
init|=
literal|1
operator|<<
literal|17
block|,
comment|/* RWF-I */
name|ZIO_STAGE_VDEV_IO_DONE
init|=
literal|1
operator|<<
literal|18
block|,
comment|/* RWF-- */
name|ZIO_STAGE_VDEV_IO_ASSESS
init|=
literal|1
operator|<<
literal|19
block|,
comment|/* RWF-I */
name|ZIO_STAGE_CHECKSUM_VERIFY
init|=
literal|1
operator|<<
literal|20
block|,
comment|/* R---- */
name|ZIO_STAGE_DONE
init|=
literal|1
operator|<<
literal|21
comment|/* RWFCI */
block|}
enum|;
define|#
directive|define
name|ZIO_INTERLOCK_STAGES
define|\
value|(ZIO_STAGE_READY |			\ 	ZIO_STAGE_DONE)
define|#
directive|define
name|ZIO_INTERLOCK_PIPELINE
define|\
value|ZIO_INTERLOCK_STAGES
define|#
directive|define
name|ZIO_VDEV_IO_STAGES
define|\
value|(ZIO_STAGE_VDEV_IO_START |		\ 	ZIO_STAGE_VDEV_IO_DONE |		\ 	ZIO_STAGE_VDEV_IO_ASSESS)
define|#
directive|define
name|ZIO_VDEV_CHILD_PIPELINE
define|\
value|(ZIO_VDEV_IO_STAGES |			\ 	ZIO_STAGE_DONE)
define|#
directive|define
name|ZIO_READ_COMMON_STAGES
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_VDEV_IO_STAGES |			\ 	ZIO_STAGE_CHECKSUM_VERIFY)
define|#
directive|define
name|ZIO_READ_PHYS_PIPELINE
define|\
value|ZIO_READ_COMMON_STAGES
define|#
directive|define
name|ZIO_READ_PIPELINE
define|\
value|(ZIO_READ_COMMON_STAGES |		\ 	ZIO_STAGE_READ_BP_INIT)
define|#
directive|define
name|ZIO_DDT_CHILD_READ_PIPELINE
define|\
value|ZIO_READ_COMMON_STAGES
define|#
directive|define
name|ZIO_DDT_READ_PIPELINE
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_STAGE_READ_BP_INIT |		\ 	ZIO_STAGE_DDT_READ_START |		\ 	ZIO_STAGE_DDT_READ_DONE)
define|#
directive|define
name|ZIO_WRITE_COMMON_STAGES
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_VDEV_IO_STAGES |			\ 	ZIO_STAGE_ISSUE_ASYNC |			\ 	ZIO_STAGE_CHECKSUM_GENERATE)
define|#
directive|define
name|ZIO_WRITE_PHYS_PIPELINE
define|\
value|ZIO_WRITE_COMMON_STAGES
define|#
directive|define
name|ZIO_REWRITE_PIPELINE
define|\
value|(ZIO_WRITE_COMMON_STAGES |		\ 	ZIO_STAGE_WRITE_BP_INIT)
define|#
directive|define
name|ZIO_WRITE_PIPELINE
define|\
value|(ZIO_WRITE_COMMON_STAGES |		\ 	ZIO_STAGE_WRITE_BP_INIT |		\ 	ZIO_STAGE_DVA_ALLOCATE)
define|#
directive|define
name|ZIO_DDT_CHILD_WRITE_PIPELINE
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_VDEV_IO_STAGES |			\ 	ZIO_STAGE_DVA_ALLOCATE)
define|#
directive|define
name|ZIO_DDT_WRITE_PIPELINE
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_STAGE_ISSUE_ASYNC |			\ 	ZIO_STAGE_WRITE_BP_INIT |		\ 	ZIO_STAGE_CHECKSUM_GENERATE |		\ 	ZIO_STAGE_DDT_WRITE)
define|#
directive|define
name|ZIO_GANG_STAGES
define|\
value|(ZIO_STAGE_GANG_ASSEMBLE |		\ 	ZIO_STAGE_GANG_ISSUE)
define|#
directive|define
name|ZIO_FREE_PIPELINE
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_STAGE_FREE_BP_INIT |		\ 	ZIO_STAGE_DVA_FREE)
define|#
directive|define
name|ZIO_FREE_PHYS_PIPELINE
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_VDEV_IO_STAGES)
define|#
directive|define
name|ZIO_DDT_FREE_PIPELINE
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_STAGE_FREE_BP_INIT |		\ 	ZIO_STAGE_ISSUE_ASYNC |			\ 	ZIO_STAGE_DDT_FREE)
define|#
directive|define
name|ZIO_CLAIM_PIPELINE
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_STAGE_DVA_CLAIM)
define|#
directive|define
name|ZIO_IOCTL_PIPELINE
define|\
value|(ZIO_INTERLOCK_STAGES |			\ 	ZIO_STAGE_VDEV_IO_START |		\ 	ZIO_STAGE_VDEV_IO_ASSESS)
define|#
directive|define
name|ZIO_BLOCKING_STAGES
define|\
value|(ZIO_STAGE_DVA_ALLOCATE |		\ 	ZIO_STAGE_DVA_CLAIM |			\ 	ZIO_STAGE_VDEV_IO_START)
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

