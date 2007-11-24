begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Ioctl definitions for the SCSI Target Driver  *  * Copyright (c) 2002 Nate Lawson.  * Copyright (c) 1998 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_SCSI_SCSI_TARGETIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_CAM_SCSI_SCSI_TARGETIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_comment
comment|/*  * CCBs (ATIO, CTIO, INOT, REL_SIMQ) are sent to the kernel driver  * by writing one or more pointers.  The user receives notification  * of CCB completion through poll/select/kqueue and then calls  * read(2) which outputs pointers to the completed CCBs.  */
end_comment

begin_comment
comment|/*  * Enable and disable a target mode instance.  For enabling, the path_id,  * target_id, and lun_id fields must be set.  The grp6/7_len fields  * specify the length of vendor-specific CDBs the target expects and  * should normally be set to 0.  On successful completion  * of enable, the specified target instance will answer selection.  * Disable causes the target instance to abort any outstanding commands  * and stop accepting new ones.  The aborted CCBs will be returned to  * the user via read(2) or discarded if the user closes the device.  * The user can then re-enable the device for a new path.  */
end_comment

begin_struct
struct|struct
name|ioc_enable_lun
block|{
name|path_id_t
name|path_id
decl_stmt|;
name|target_id_t
name|target_id
decl_stmt|;
name|lun_id_t
name|lun_id
decl_stmt|;
name|int
name|grp6_len
decl_stmt|;
name|int
name|grp7_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TARGIOCENABLE
value|_IOW('C', 5, struct ioc_enable_lun)
end_define

begin_define
define|#
directive|define
name|TARGIOCDISABLE
value|_IO('C', 6)
end_define

begin_comment
comment|/*  * Set/clear debugging for this target mode instance  */
end_comment

begin_define
define|#
directive|define
name|TARGIOCDEBUG
value|_IOW('C', 7, int)
end_define

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ccb_queue
argument_list|,
name|ccb_hdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_SCSI_SCSI_TARGETIO_H_ */
end_comment

end_unit

