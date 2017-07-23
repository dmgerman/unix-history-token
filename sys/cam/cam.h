begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Data structures and definitions for the CAM system.  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|"opt_cam.h"
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
name|u_int64_t
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
value|(~(u_int)0)
end_define

begin_define
define|#
directive|define
name|CAM_EXTLUN_BYTE_SWIZZLE
parameter_list|(
name|lun
parameter_list|)
value|(	\ 	((((u_int64_t)lun)& 0xffff000000000000L)>> 48) | \ 	((((u_int64_t)lun)& 0x0000ffff00000000L)>> 16) | \ 	((((u_int64_t)lun)& 0x00000000ffff0000L)<< 16) | \ 	((((u_int64_t)lun)& 0x000000000000ffffL)<< 48))
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
comment|/*  * Priority information for a CAM structure.   */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_RL_HOST
block|,
name|CAM_RL_BUS
block|,
name|CAM_RL_XPT
block|,
name|CAM_RL_DEV
block|,
name|CAM_RL_NORMAL
block|,
name|CAM_RL_VALUES
block|}
name|cam_rl
typedef|;
end_typedef

begin_comment
comment|/*  * The generation number is incremented every time a new entry is entered into  * the queue giving round robin per priority level scheduling.  */
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
name|CAM_PRIORITY_HOST
value|((CAM_RL_HOST<< 8) + 0x80)
define|#
directive|define
name|CAM_PRIORITY_BUS
value|((CAM_RL_BUS<< 8) + 0x80)
define|#
directive|define
name|CAM_PRIORITY_XPT
value|((CAM_RL_XPT<< 8) + 0x80)
define|#
directive|define
name|CAM_PRIORITY_DEV
value|((CAM_RL_DEV<< 8) + 0x80)
define|#
directive|define
name|CAM_PRIORITY_OOB
value|(CAM_RL_DEV<< 8)
define|#
directive|define
name|CAM_PRIORITY_NORMAL
value|((CAM_RL_NORMAL<< 8) + 0x80)
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
define|#
directive|define
name|CAM_EXTRAQ_INDEX
value|INT_MAX
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
comment|/* CAM flags XXX Move to cam_periph.h ??? */
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
block|,
name|CAM_RETRY_SELTO
init|=
literal|0x02
comment|/* Retry Selection Timeouts */
block|}
name|cam_flags
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|SF_RETRY_UA
init|=
literal|0x01
block|,
comment|/* Retry UNIT ATTENTION conditions. */
name|SF_NO_PRINT
init|=
literal|0x02
block|,
comment|/* Never print error status. */
name|SF_QUIET_IR
init|=
literal|0x04
block|,
comment|/* Be quiet about Illegal Request responses */
name|SF_PRINT_ALWAYS
init|=
literal|0x08
block|,
comment|/* Always print error status. */
name|SF_NO_RECOVERY
init|=
literal|0x10
block|,
comment|/* Don't do active error recovery. */
name|SF_NO_RETRY
init|=
literal|0x20
block|,
comment|/* Don't do any retries. */
name|SF_RETRY_BUSY
init|=
literal|0x40
comment|/* Retry BUSY status. */
block|}
enum|;
end_enum

begin_comment
comment|/* CAM  Status field values */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* CCB request is in progress */
name|CAM_REQ_INPROG
init|=
literal|0x00
block|,
comment|/* CCB request completed without error */
name|CAM_REQ_CMP
init|=
literal|0x01
block|,
comment|/* CCB request aborted by the host */
name|CAM_REQ_ABORTED
init|=
literal|0x02
block|,
comment|/* Unable to abort CCB request */
name|CAM_UA_ABORT
init|=
literal|0x03
block|,
comment|/* CCB request completed with an error */
name|CAM_REQ_CMP_ERR
init|=
literal|0x04
block|,
comment|/* CAM subsystem is busy */
name|CAM_BUSY
init|=
literal|0x05
block|,
comment|/* CCB request was invalid */
name|CAM_REQ_INVALID
init|=
literal|0x06
block|,
comment|/* Supplied Path ID is invalid */
name|CAM_PATH_INVALID
init|=
literal|0x07
block|,
comment|/* SCSI Device Not Installed/there */
name|CAM_DEV_NOT_THERE
init|=
literal|0x08
block|,
comment|/* Unable to terminate I/O CCB request */
name|CAM_UA_TERMIO
init|=
literal|0x09
block|,
comment|/* Target Selection Timeout */
name|CAM_SEL_TIMEOUT
init|=
literal|0x0a
block|,
comment|/* Command timeout */
name|CAM_CMD_TIMEOUT
init|=
literal|0x0b
block|,
comment|/* SCSI error, look at error code in CCB */
name|CAM_SCSI_STATUS_ERROR
init|=
literal|0x0c
block|,
comment|/* Message Reject Received */
name|CAM_MSG_REJECT_REC
init|=
literal|0x0d
block|,
comment|/* SCSI Bus Reset Sent/Received */
name|CAM_SCSI_BUS_RESET
init|=
literal|0x0e
block|,
comment|/* Uncorrectable parity error occurred */
name|CAM_UNCOR_PARITY
init|=
literal|0x0f
block|,
comment|/* Autosense: request sense cmd fail */
name|CAM_AUTOSENSE_FAIL
init|=
literal|0x10
block|,
comment|/* No HBA Detected error */
name|CAM_NO_HBA
init|=
literal|0x11
block|,
comment|/* Data Overrun error */
name|CAM_DATA_RUN_ERR
init|=
literal|0x12
block|,
comment|/* Unexpected Bus Free */
name|CAM_UNEXP_BUSFREE
init|=
literal|0x13
block|,
comment|/* Target Bus Phase Sequence Failure */
name|CAM_SEQUENCE_FAIL
init|=
literal|0x14
block|,
comment|/* CCB length supplied is inadequate */
name|CAM_CCB_LEN_ERR
init|=
literal|0x15
block|,
comment|/* Unable to provide requested capability*/
name|CAM_PROVIDE_FAIL
init|=
literal|0x16
block|,
comment|/* A SCSI BDR msg was sent to target */
name|CAM_BDR_SENT
init|=
literal|0x17
block|,
comment|/* CCB request terminated by the host */
name|CAM_REQ_TERMIO
init|=
literal|0x18
block|,
comment|/* Unrecoverable Host Bus Adapter Error */
name|CAM_UNREC_HBA_ERROR
init|=
literal|0x19
block|,
comment|/* Request was too large for this host */
name|CAM_REQ_TOO_BIG
init|=
literal|0x1a
block|,
comment|/* 	 * This request should be requeued to preserve 	 * transaction ordering.  This typically occurs 	 * when the SIM recognizes an error that should 	 * freeze the queue and must place additional 	 * requests for the target at the sim level 	 * back into the XPT queue. 	 */
name|CAM_REQUEUE_REQ
init|=
literal|0x1b
block|,
comment|/* ATA error, look at error code in CCB */
name|CAM_ATA_STATUS_ERROR
init|=
literal|0x1c
block|,
comment|/* Initiator/Target Nexus lost. */
name|CAM_SCSI_IT_NEXUS_LOST
init|=
literal|0x1d
block|,
comment|/* SMP error, look at error code in CCB */
name|CAM_SMP_STATUS_ERROR
init|=
literal|0x1e
block|,
comment|/* 	 * Command completed without error but  exceeded the soft 	 * timeout threshold. 	 */
name|CAM_REQ_SOFTTIMEOUT
init|=
literal|0x1f
block|,
comment|/* 	 * 0x20 - 0x32 are unassigned 	 */
comment|/* Initiator Detected Error */
name|CAM_IDE
init|=
literal|0x33
block|,
comment|/* Resource Unavailable */
name|CAM_RESRC_UNAVAIL
init|=
literal|0x34
block|,
comment|/* Unacknowledged Event by Host */
name|CAM_UNACKED_EVENT
init|=
literal|0x35
block|,
comment|/* Message Received in Host Target Mode */
name|CAM_MESSAGE_RECV
init|=
literal|0x36
block|,
comment|/* Invalid CDB received in Host Target Mode */
name|CAM_INVALID_CDB
init|=
literal|0x37
block|,
comment|/* Lun supplied is invalid */
name|CAM_LUN_INVALID
init|=
literal|0x38
block|,
comment|/* Target ID supplied is invalid */
name|CAM_TID_INVALID
init|=
literal|0x39
block|,
comment|/* The requested function is not available */
name|CAM_FUNC_NOTAVAIL
init|=
literal|0x3a
block|,
comment|/* Nexus is not established */
name|CAM_NO_NEXUS
init|=
literal|0x3b
block|,
comment|/* The initiator ID is invalid */
name|CAM_IID_INVALID
init|=
literal|0x3c
block|,
comment|/* The SCSI CDB has been received */
name|CAM_CDB_RECVD
init|=
literal|0x3d
block|,
comment|/* The LUN is already enabled for target mode */
name|CAM_LUN_ALRDY_ENA
init|=
literal|0x3e
block|,
comment|/* SCSI Bus Busy */
name|CAM_SCSI_BUSY
init|=
literal|0x3f
block|,
comment|/* 	 * Flags 	 */
comment|/* The DEV queue is frozen w/this err */
name|CAM_DEV_QFRZN
init|=
literal|0x40
block|,
comment|/* Autosense data valid for target */
name|CAM_AUTOSNS_VALID
init|=
literal|0x80
block|,
comment|/* SIM ready to take more commands */
name|CAM_RELEASE_SIMQ
init|=
literal|0x100
block|,
comment|/* SIM has this command in its queue */
name|CAM_SIM_QUEUED
init|=
literal|0x200
block|,
comment|/* Quality of service data is valid */
name|CAM_QOS_VALID
init|=
literal|0x400
block|,
comment|/* Mask bits for just the status # */
name|CAM_STATUS_MASK
init|=
literal|0x3F
block|,
comment|/* 	 * Target Specific Adjunct Status 	 */
comment|/* sent sense with status */
name|CAM_SENT_SENSE
init|=
literal|0x40000000
block|}
name|cam_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_ESF_NONE
init|=
literal|0x00
block|,
name|CAM_ESF_COMMAND
init|=
literal|0x01
block|,
name|CAM_ESF_CAM_STATUS
init|=
literal|0x02
block|,
name|CAM_ESF_PROTO_STATUS
init|=
literal|0x04
block|,
name|CAM_ESF_ALL
init|=
literal|0xff
block|}
name|cam_error_string_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_EPF_NONE
init|=
literal|0x00
block|,
name|CAM_EPF_MINIMAL
init|=
literal|0x01
block|,
name|CAM_EPF_NORMAL
init|=
literal|0x02
block|,
name|CAM_EPF_ALL
init|=
literal|0x03
block|,
name|CAM_EPF_LEVEL_MASK
init|=
literal|0x0f
comment|/* All bits above bit 3 are protocol-specific */
block|}
name|cam_error_proto_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_ESF_PRINT_NONE
init|=
literal|0x00
block|,
name|CAM_ESF_PRINT_STATUS
init|=
literal|0x10
block|,
name|CAM_ESF_PRINT_SENSE
init|=
literal|0x20
block|}
name|cam_error_scsi_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_ESMF_PRINT_NONE
init|=
literal|0x00
block|,
name|CAM_ESMF_PRINT_STATUS
init|=
literal|0x10
block|,
name|CAM_ESMF_PRINT_FULL_CMD
init|=
literal|0x20
block|, }
name|cam_error_smp_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_EAF_PRINT_NONE
init|=
literal|0x00
block|,
name|CAM_EAF_PRINT_STATUS
init|=
literal|0x10
block|,
name|CAM_EAF_PRINT_RESULT
init|=
literal|0x20
block|}
name|cam_error_ata_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_STRVIS_FLAG_NONE
init|=
literal|0x00
block|,
name|CAM_STRVIS_FLAG_NONASCII_MASK
init|=
literal|0x03
block|,
name|CAM_STRVIS_FLAG_NONASCII_TRIM
init|=
literal|0x00
block|,
name|CAM_STRVIS_FLAG_NONASCII_RAW
init|=
literal|0x01
block|,
name|CAM_STRVIS_FLAG_NONASCII_SPC
init|=
literal|0x02
block|,
name|CAM_STRVIS_FLAG_NONASCII_ESC
init|=
literal|0x03
block|}
name|cam_strvis_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|cam_status_entry
block|{
name|cam_status
name|status_code
decl_stmt|;
specifier|const
name|char
modifier|*
name|status_text
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cam_status_entry
name|cam_status_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|num_cam_status_entries
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|cam_sort_io_queues
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_union_decl
union_decl|union
name|ccb
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|sbuf
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_comment
comment|/* from sysctl.h */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_cam
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|void
name|cam_strvis_sbuf
parameter_list|(
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|src
parameter_list|,
name|int
name|srclen
parameter_list|,
name|uint32_t
name|flags
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
specifier|const
name|struct
name|cam_status_entry
modifier|*
name|cam_fetch_status_entry
parameter_list|(
name|cam_status
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|char
modifier|*
name|cam_error_string
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|int
name|str_len
parameter_list|,
name|cam_error_string_flags
name|flags
parameter_list|,
name|cam_error_proto_flags
name|proto_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_error_print
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|cam_error_string_flags
name|flags
parameter_list|,
name|cam_error_proto_flags
name|proto_flags
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct_decl
struct_decl|struct
name|cam_device
struct_decl|;
end_struct_decl

begin_function_decl
name|char
modifier|*
name|cam_error_string
parameter_list|(
name|struct
name|cam_device
modifier|*
name|device
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|int
name|str_len
parameter_list|,
name|cam_error_string_flags
name|flags
parameter_list|,
name|cam_error_proto_flags
name|proto_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_error_print
parameter_list|(
name|struct
name|cam_device
modifier|*
name|device
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|cam_error_string_flags
name|flags
parameter_list|,
name|cam_error_proto_flags
name|proto_flags
parameter_list|,
name|FILE
modifier|*
name|ofile
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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

