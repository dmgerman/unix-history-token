begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ioctl definitions for the Target Mode SCSI Proccessor Target driver for CAM.  *  * Copyright (c) 1998 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ccb_queue
argument_list|,
name|ccb_hdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Determine and clear exception state in the driver */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TARG_EXCEPT_NONE
init|=
literal|0x00
block|,
name|TARG_EXCEPT_DEVICE_INVALID
init|=
literal|0x01
block|,
name|TARG_EXCEPT_BDR_RECEIVED
init|=
literal|0x02
block|,
name|TARG_EXCEPT_BUS_RESET_SEEN
init|=
literal|0x04
block|,
name|TARG_EXCEPT_ABORT_SEEN
init|=
literal|0x08
block|,
name|TARG_EXCEPT_ABORT_TAG_SEEN
init|=
literal|0x10
block|,
name|TARG_EXCEPT_UNKNOWN_ATIO
init|=
literal|0x80
block|}
name|targ_exception
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TARGIOCFETCHEXCEPTION
value|_IOR('C', 1, targ_exception)
end_define

begin_define
define|#
directive|define
name|TARGIOCCLEAREXCEPTION
value|_IOW('C', 2, targ_exception)
end_define

begin_comment
comment|/*  * Retreive an Accept Target I/O CCB for a command that is not handled  * directly by the kernel target driver.  */
end_comment

begin_define
define|#
directive|define
name|TARGIOCFETCHATIO
value|_IOR('C', 3, struct ccb_accept_tio)
end_define

begin_comment
comment|/*  * Used for responding to incoming ATIO requests.  XPT_CONTINUE_TARG_IO  * operations are the norm, but ccb types for manipulating the device  * queue, etc. can also be used if error handling is to be performed by the  * user land process.  */
end_comment

begin_define
define|#
directive|define
name|TARGIOCCOMMAND
value|_IOWR('C', 4, union ccb)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|UA_NONE
init|=
literal|0x00
block|,
name|UA_POWER_ON
init|=
literal|0x01
block|,
name|UA_BUS_RESET
init|=
literal|0x02
block|,
name|UA_BDR
init|=
literal|0x04
block|}
name|ua_types
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CA_NONE
init|=
literal|0x00
block|,
name|CA_UNIT_ATTN
init|=
literal|0x01
block|,
name|CA_CMD_SENSE
init|=
literal|0x02
block|}
name|ca_types
typedef|;
end_typedef

begin_struct
struct|struct
name|initiator_state
block|{
name|ua_types
name|pending_ua
decl_stmt|;
name|ca_types
name|pending_ca
decl_stmt|;
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
name|struct
name|ccb_queue
name|held_queue
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ioc_initiator_state
block|{
name|u_int
name|initiator_id
decl_stmt|;
name|struct
name|initiator_state
name|istate
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get and Set Contingent Allegiance and Unit Attention state   * presented by the target driver.  This is usually used to  * properly report and error condition in response to an incoming  * ATIO request handled by the userland process.  *  * The initiator_id must be properly initialized in the ioc_initiator_state  * structure before calling TARGIOCGETISTATE.  */
end_comment

begin_define
define|#
directive|define
name|TARGIOCGETISTATE
value|_IOWR('C', 6, struct ioc_initiator_state)
end_define

begin_define
define|#
directive|define
name|TARGIOCSETISTATE
value|_IOW('C', 5, struct ioc_initiator_state)
end_define

begin_struct
struct|struct
name|ioc_alloc_unit
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
name|u_int
name|unit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Allocate and Free a target mode instance.  For allocation, the path_id,  * target_id, and lun_id fields must be set.  On successful completion  * of the ioctl, the unit field will indicate the unit number of the  * newly created instance.  For de-allocation, all fields must match  * an instance in the inactive (i.e. closed) state.  */
end_comment

begin_define
define|#
directive|define
name|TARGCTLIOALLOCUNIT
value|_IOWR('C', 7, struct ioc_alloc_unit)
end_define

begin_define
define|#
directive|define
name|TARGCTLIOFREEUNIT
value|_IOW('C', 8, struct ioc_alloc_unit)
end_define

begin_comment
comment|/*  * Set/clear debugging for this target mode instance  */
end_comment

begin_define
define|#
directive|define
name|TARGIODEBUG
value|_IOW('C', 9, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_SCSI_SCSI_TARGETIO_H_ */
end_comment

end_unit

