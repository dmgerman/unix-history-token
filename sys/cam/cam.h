begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Data structures and definitions for the CAM system.  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<opt_cam.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_typedef
typedef|typedef
name|u_int
name|path_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|target_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|lun_id_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CAM_XPT_PATH_ID
value|((path_id_t)~0)
end_define

begin_define
define|#
directive|define
name|CAM_BUS_WILDCARD
value|((path_id_t)~0)
end_define

begin_define
define|#
directive|define
name|CAM_TARGET_WILDCARD
value|((target_id_t)~0)
end_define

begin_define
define|#
directive|define
name|CAM_LUN_WILDCARD
value|((lun_id_t)~0)
end_define

begin_comment
comment|/*  * Maximum length for a CAM CDB.    */
end_comment

begin_define
define|#
directive|define
name|CAM_MAX_CDBLEN
value|16
end_define

begin_comment
comment|/*  * Definition of a CAM peripheral driver entry.  Peripheral drivers instantiate  * one of these for each device they wish to communicate with and pass it into  * the xpt layer when they wish to schedule work on that device via the  * xpt_schedule API.  */
end_comment

begin_struct_decl
struct_decl|struct
name|cam_periph
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Priority information for a CAM structure.  The generation number is  * incremented everytime a new entry is entered into the queue giving round  * robin per priority level scheduling.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|priority
decl_stmt|;
define|#
directive|define
name|CAM_PRIORITY_NONE
value|(u_int32_t)-1
name|u_int32_t
name|generation
decl_stmt|;
name|int
name|index
decl_stmt|;
define|#
directive|define
name|CAM_UNQUEUED_INDEX
value|-1
define|#
directive|define
name|CAM_ACTIVE_INDEX
value|-2
define|#
directive|define
name|CAM_DONEQ_INDEX
value|-3
block|}
name|cam_pinfo
typedef|;
end_typedef

begin_comment
comment|/*  * Macro to compare two generation numbers.  It is used like this:    *  *	if (GENERATIONCMP(a,>=, b))  *		...;  *  * GERERATIONCMP uses modular arithmetic to guard against wraps  * wraps in the generation number.  */
end_comment

begin_define
define|#
directive|define
name|GENERATIONCMP
parameter_list|(
name|x
parameter_list|,
name|op
parameter_list|,
name|y
parameter_list|)
value|((int32_t)((x) - (y)) op 0)
end_define

begin_comment
comment|/* CAM flags */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_FLAG_NONE
init|=
literal|0x00
block|,
name|CAM_EXPECT_INQ_CHANGE
init|=
literal|0x01
block|}
name|cam_flags
typedef|;
end_typedef

begin_comment
comment|/* CAM  Status field values */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_REQ_INPROG
block|,
comment|/* CCB request is in progress */
name|CAM_REQ_CMP
block|,
comment|/* CCB request completed without error */
name|CAM_REQ_ABORTED
block|,
comment|/* CCB request aborted by the host */
name|CAM_UA_ABORT
block|,
comment|/* Unable to abort CCB request */
name|CAM_REQ_CMP_ERR
block|,
comment|/* CCB request completed with an error */
name|CAM_BUSY
block|,
comment|/* CAM subsytem is busy */
name|CAM_REQ_INVALID
block|,
comment|/* CCB request was invalid */
name|CAM_PATH_INVALID
block|,
comment|/* Supplied Path ID is invalid */
name|CAM_DEV_NOT_THERE
block|,
comment|/* SCSI Device Not Installed/there */
name|CAM_UA_TERMIO
block|,
comment|/* Unable to terminate I/O CCB request */
name|CAM_SEL_TIMEOUT
block|,
comment|/* Target Selection Timeout */
name|CAM_CMD_TIMEOUT
block|,
comment|/* Command timeout */
name|CAM_SCSI_STATUS_ERROR
block|,
comment|/* SCSI error, look at error code in CCB */
name|CAM_MSG_REJECT_REC
block|,
comment|/* Message Reject Received */
name|CAM_SCSI_BUS_RESET
block|,
comment|/* SCSI Bus Reset Sent/Received */
name|CAM_UNCOR_PARITY
block|,
comment|/* Uncorrectable parity error occurred */
name|CAM_AUTOSENSE_FAIL
init|=
literal|0x10
block|,
comment|/* Autosense: request sense cmd fail */
name|CAM_NO_HBA
block|,
comment|/* No HBA Detected error */
name|CAM_DATA_RUN_ERR
block|,
comment|/* Data Overrun error */
name|CAM_UNEXP_BUSFREE
block|,
comment|/* Unexpected Bus Free */
name|CAM_SEQUENCE_FAIL
block|,
comment|/* Target Bus Phase Sequence Failure */
name|CAM_CCB_LEN_ERR
block|,
comment|/* CCB length supplied is inadequate */
name|CAM_PROVIDE_FAIL
block|,
comment|/* Unable to provide requested capability */
name|CAM_BDR_SENT
block|,
comment|/* A SCSI BDR msg was sent to target */
name|CAM_REQ_TERMIO
block|,
comment|/* CCB request terminated by the host */
name|CAM_UNREC_HBA_ERROR
block|,
comment|/* Unrecoverable Host Bus Adapter Error */
name|CAM_REQ_TOO_BIG
block|,
comment|/* The request was too large for this host */
name|CAM_REQUEUE_REQ
block|,
comment|/* 				 * This request should be requeued to preserve 				 * transaction ordering.  This typically occurs 				 * when the SIM recognizes an error that should 				 * freeze the queue and must place additional 				 * requests for the target at the sim level 				 * back into the XPT queue. 				 */
name|CAM_IDE
init|=
literal|0x33
block|,
comment|/* Initiator Detected Error */
name|CAM_RESRC_UNAVAIL
block|,
comment|/* Resource Unavailable */
name|CAM_UNACKED_EVENT
block|,
comment|/* Unacknowledged Event by Host */
name|CAM_MESSAGE_RECV
block|,
comment|/* Message Received in Host Target Mode */
name|CAM_INVALID_CDB
block|,
comment|/* Invalid CDB received in Host Target Mode */
name|CAM_LUN_INVALID
block|,
comment|/* Lun supplied is invalid */
name|CAM_TID_INVALID
block|,
comment|/* Target ID supplied is invalid */
name|CAM_FUNC_NOTAVAIL
block|,
comment|/* The requested function is not available */
name|CAM_NO_NEXUS
block|,
comment|/* Nexus is not established */
name|CAM_IID_INVALID
block|,
comment|/* The initiator ID is invalid */
name|CAM_CDB_RECVD
block|,
comment|/* The SCSI CDB has been received */
name|CAM_LUN_ALRDY_ENA
block|,
comment|/* The LUN is already eanbeld for target mode */
name|CAM_SCSI_BUSY
block|,
comment|/* SCSI Bus Busy */
name|CAM_DEV_QFRZN
init|=
literal|0x40
block|,
comment|/* The DEV queue is frozen w/this err */
comment|/* Autosense data valid for target */
name|CAM_AUTOSNS_VALID
init|=
literal|0x80
block|,
name|CAM_RELEASE_SIMQ
init|=
literal|0x100
block|,
comment|/* SIM ready to take more commands */
name|CAM_SIM_QUEUED
init|=
literal|0x200
block|,
comment|/* SIM has this command in it's queue */
name|CAM_STATUS_MASK
init|=
literal|0x3F
block|,
comment|/* Mask bits for just the status # */
comment|/* Target Specific Adjunct Status */
name|CAM_SENT_SENSE
init|=
literal|0x40000000
comment|/* sent sense with status */
block|}
name|cam_status
typedef|;
end_typedef

begin_macro
name|__BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
name|int
function_decl|(
name|cam_quirkmatch_t
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|caddr_t
name|cam_quirkmatch
parameter_list|(
name|caddr_t
name|target
parameter_list|,
name|caddr_t
name|quirk_table
parameter_list|,
name|int
name|num_entries
parameter_list|,
name|int
name|entry_size
parameter_list|,
name|cam_quirkmatch_t
modifier|*
name|comp_func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_strvis
parameter_list|(
name|u_int8_t
modifier|*
name|dst
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|src
parameter_list|,
name|int
name|srclen
parameter_list|,
name|int
name|dstlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cam_strmatch
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
name|str
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|pattern
parameter_list|,
name|int
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
ifdef|#
directive|ifdef
name|_KERNEL
specifier|static
name|__inline
name|void
name|cam_init_pinfo
parameter_list|(
name|cam_pinfo
modifier|*
name|pinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|cam_init_pinfo
parameter_list|(
name|cam_pinfo
modifier|*
name|pinfo
parameter_list|)
block|{
name|pinfo
operator|->
name|priority
operator|=
name|CAM_PRIORITY_NONE
expr_stmt|;
name|pinfo
operator|->
name|index
operator|=
name|CAM_UNQUEUED_INDEX
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_CAM_H */
end_comment

end_unit

