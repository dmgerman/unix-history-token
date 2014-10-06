begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_io.h#5 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CAM Target Layer data movement structures/interface.  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_IO_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_IO_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_CTL_C
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
parameter_list|(
name|__var
parameter_list|,
name|__val
parameter_list|)
value|__var = __val
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
parameter_list|(
name|__var
parameter_list|,
name|__val
parameter_list|)
value|extern __var
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CTL_MAX_CDBLEN
value|32
end_define

begin_comment
comment|/*  * Uncomment this next line to enable printing out times for I/Os  * that take longer than CTL_TIME_IO_SECS seconds to get to the datamove  * and/or done stage.  */
end_comment

begin_define
define|#
directive|define
name|CTL_TIME_IO
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CTL_TIME_IO
end_ifdef

begin_define
define|#
directive|define
name|CTL_TIME_IO_DEFAULT_SECS
value|90
end_define

begin_macro
name|EXTERN
argument_list|(
argument|int ctl_time_io_secs
argument_list|,
argument|CTL_TIME_IO_DEFAULT_SECS
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Uncomment these next two lines to enable the CTL I/O delay feature.  You  * can delay I/O at two different points -- datamove and done.  This is  * useful for diagnosing abort conditions (for hosts that send an abort on a  * timeout), and for determining how long a host's timeout is.  */
end_comment

begin_define
define|#
directive|define
name|CTL_IO_DELAY
end_define

begin_define
define|#
directive|define
name|CTL_TIMER_BYTES
value|sizeof(struct callout)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_STATUS_NONE
block|,
comment|/* No status */
name|CTL_SUCCESS
block|,
comment|/* Transaction completed successfully */
name|CTL_CMD_TIMEOUT
block|,
comment|/* Command timed out, shouldn't happen here */
name|CTL_SEL_TIMEOUT
block|,
comment|/* Selection timeout, shouldn't happen here */
name|CTL_ERROR
block|,
comment|/* General CTL error XXX expand on this? */
name|CTL_SCSI_ERROR
block|,
comment|/* SCSI error, look at status byte/sense data */
name|CTL_CMD_ABORTED
block|,
comment|/* Command aborted, don't return status */
name|CTL_STATUS_MASK
init|=
literal|0xfff
block|,
comment|/* Mask off any status flags */
name|CTL_AUTOSENSE
init|=
literal|0x1000
comment|/* Autosense performed */
block|}
name|ctl_io_status
typedef|;
end_typedef

begin_comment
comment|/*  * WARNING:  Keep the data in/out/none flags where they are.  They're used  * in conjuction with ctl_cmd_flags.  See comment above ctl_cmd_flags  * definition in ctl_private.h.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_FLAG_NONE
init|=
literal|0x00000000
block|,
comment|/* no flags */
name|CTL_FLAG_DATA_IN
init|=
literal|0x00000001
block|,
comment|/* DATA IN */
name|CTL_FLAG_DATA_OUT
init|=
literal|0x00000002
block|,
comment|/* DATA OUT */
name|CTL_FLAG_DATA_NONE
init|=
literal|0x00000003
block|,
comment|/* no data */
name|CTL_FLAG_DATA_MASK
init|=
literal|0x00000003
block|,
name|CTL_FLAG_KDPTR_SGLIST
init|=
literal|0x00000008
block|,
comment|/* kern_data_ptr is S/G list*/
name|CTL_FLAG_EDPTR_SGLIST
init|=
literal|0x00000010
block|,
comment|/* ext_data_ptr is S/G list */
name|CTL_FLAG_DO_AUTOSENSE
init|=
literal|0x00000020
block|,
comment|/* grab sense info */
name|CTL_FLAG_USER_REQ
init|=
literal|0x00000040
block|,
comment|/* request came from userland */
name|CTL_FLAG_CONTROL_DEV
init|=
literal|0x00000080
block|,
comment|/* processor device */
name|CTL_FLAG_ALLOCATED
init|=
literal|0x00000100
block|,
comment|/* data space allocated */
name|CTL_FLAG_BLOCKED
init|=
literal|0x00000200
block|,
comment|/* on the blocked queue */
name|CTL_FLAG_ABORT_STATUS
init|=
literal|0x00000400
block|,
comment|/* return TASK ABORTED status */
name|CTL_FLAG_ABORT
init|=
literal|0x00000800
block|,
comment|/* this I/O should be aborted */
name|CTL_FLAG_DMA_INPROG
init|=
literal|0x00001000
block|,
comment|/* DMA in progress */
name|CTL_FLAG_NO_DATASYNC
init|=
literal|0x00002000
block|,
comment|/* don't cache flush data */
name|CTL_FLAG_DELAY_DONE
init|=
literal|0x00004000
block|,
comment|/* delay injection done */
name|CTL_FLAG_INT_COPY
init|=
literal|0x00008000
block|,
comment|/* internal copy, no done call*/
name|CTL_FLAG_SENT_2OTHER_SC
init|=
literal|0x00010000
block|,
name|CTL_FLAG_FROM_OTHER_SC
init|=
literal|0x00020000
block|,
name|CTL_FLAG_IS_WAS_ON_RTR
init|=
literal|0x00040000
block|,
comment|/* Don't rerun cmd on failover*/
name|CTL_FLAG_BUS_ADDR
init|=
literal|0x00080000
block|,
comment|/* ctl_sglist contains BUS 						   addresses, not virtual ones*/
name|CTL_FLAG_IO_CONT
init|=
literal|0x00100000
block|,
comment|/* Continue I/O instead of 						   completing */
name|CTL_FLAG_AUTO_MIRROR
init|=
literal|0x00200000
block|,
comment|/* Automatically use memory 						   from the RC cache mirrored 						   address area. */
if|#
directive|if
literal|0
block|CTL_FLAG_ALREADY_DONE	= 0x00200000
comment|/* I/O already completed */
endif|#
directive|endif
name|CTL_FLAG_NO_DATAMOVE
init|=
literal|0x00400000
block|,
name|CTL_FLAG_DMA_QUEUED
init|=
literal|0x00800000
block|,
comment|/* DMA queued but not started*/
name|CTL_FLAG_STATUS_QUEUED
init|=
literal|0x01000000
block|,
comment|/* Status queued but not sent*/
name|CTL_FLAG_REDIR_DONE
init|=
literal|0x02000000
block|,
comment|/* Redirection has already 						   been done. */
name|CTL_FLAG_FAILOVER
init|=
literal|0x04000000
block|,
comment|/* Killed by a failover */
name|CTL_FLAG_IO_ACTIVE
init|=
literal|0x08000000
block|,
comment|/* I/O active on this SC */
name|CTL_FLAG_RDMA_MASK
init|=
name|CTL_FLAG_NO_DATASYNC
operator||
name|CTL_FLAG_BUS_ADDR
operator||
name|CTL_FLAG_AUTO_MIRROR
operator||
name|CTL_FLAG_REDIR_DONE
comment|/* Flags we care about for 						   remote DMA */
block|}
name|ctl_io_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_lba_len
block|{
name|uint64_t
name|lba
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_lba_len_flags
block|{
name|uint64_t
name|lba
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|CTL_LLF_FUA
value|0x04000000
define|#
directive|define
name|CTL_LLF_DPO
value|0x08000000
define|#
directive|define
name|CTL_LLF_READ
value|0x10000000
define|#
directive|define
name|CTL_LLF_WRITE
value|0x20000000
define|#
directive|define
name|CTL_LLF_VERIFY
value|0x40000000
define|#
directive|define
name|CTL_LLF_COMPARE
value|0x80000000
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_ptr_len_flags
block|{
name|uint8_t
modifier|*
name|ptr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ctl_priv
block|{
name|uint8_t
name|bytes
index|[
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|*
literal|2
index|]
decl_stmt|;
name|uint64_t
name|integer
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Number of CTL private areas.  */
end_comment

begin_define
define|#
directive|define
name|CTL_NUM_PRIV
value|6
end_define

begin_comment
comment|/*  * Which private area are we using for a particular piece of data?  */
end_comment

begin_define
define|#
directive|define
name|CTL_PRIV_LUN
value|0
end_define

begin_comment
comment|/* CTL LUN pointer goes here */
end_comment

begin_define
define|#
directive|define
name|CTL_PRIV_LBA_LEN
value|1
end_define

begin_comment
comment|/* Decoded LBA/len for read/write*/
end_comment

begin_define
define|#
directive|define
name|CTL_PRIV_MODEPAGE
value|1
end_define

begin_comment
comment|/* Modepage info for config write */
end_comment

begin_define
define|#
directive|define
name|CTL_PRIV_BACKEND
value|2
end_define

begin_comment
comment|/* Reserved for block, RAIDCore */
end_comment

begin_define
define|#
directive|define
name|CTL_PRIV_BACKEND_LUN
value|3
end_define

begin_comment
comment|/* Backend LUN pointer */
end_comment

begin_define
define|#
directive|define
name|CTL_PRIV_FRONTEND
value|4
end_define

begin_comment
comment|/* LSI driver, ioctl front end */
end_comment

begin_define
define|#
directive|define
name|CTL_PRIV_USER
value|5
end_define

begin_comment
comment|/* Userland use */
end_comment

begin_define
define|#
directive|define
name|CTL_INVALID_PORTNAME
value|0xFF
end_define

begin_define
define|#
directive|define
name|CTL_UNMAPPED_IID
value|0xFF
end_define

begin_comment
comment|/*  * XXX KDM this size is for the port_priv variable in struct ctl_io_hdr  * below.  This should be defined in terms of the size of struct  * ctlfe_lun_cmd_info at the moment:  * struct ctlfe_lun_cmd_info {  *	int cur_transfer_index;  * 	ctlfe_cmd_flags flags;  * 	bus_dma_segment_t cam_sglist[32];  * };  *  * This isn't really the way I'd prefer to do it, but it does make some  * sense, AS LONG AS we can guarantee that there will always only be one  * outstanding DMA request per ctl_io.  If that assumption isn't valid,  * then we've got problems.  *  * At some point it may be nice switch CTL over to using CCBs for  * everything.  At that point we can probably use the ATIO/CTIO model, so  * that multiple simultaneous DMAs per command will just work.  *  * Also note that the current size, 600, is appropriate for 64-bit  * architectures, but is overkill for 32-bit architectures.  Need a way to  * figure out the size at compile time, or just get rid of this altogether.  */
end_comment

begin_define
define|#
directive|define
name|CTL_PORT_PRIV_SIZE
value|600
end_define

begin_struct
struct|struct
name|ctl_sg_entry
block|{
name|void
modifier|*
name|addr
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_id
block|{
name|uint32_t
name|id
decl_stmt|;
name|uint64_t
name|wwid
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_IO_NONE
block|,
name|CTL_IO_SCSI
block|,
name|CTL_IO_TASK
block|, }
name|ctl_io_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_nexus
block|{
name|struct
name|ctl_id
name|initid
decl_stmt|;
comment|/* Initiator ID */
name|uint32_t
name|targ_port
decl_stmt|;
comment|/* Target port, filled in by PORT */
name|struct
name|ctl_id
name|targ_target
decl_stmt|;
comment|/* Destination target */
name|uint32_t
name|targ_lun
decl_stmt|;
comment|/* Destination lun */
name|uint32_t
name|targ_mapped_lun
decl_stmt|;
comment|/* Destination lun CTL-wide */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_MSG_SERIALIZE
block|,
name|CTL_MSG_R2R
block|,
name|CTL_MSG_FINISH_IO
block|,
name|CTL_MSG_BAD_JUJU
block|,
name|CTL_MSG_MANAGE_TASKS
block|,
name|CTL_MSG_PERS_ACTION
block|,
name|CTL_MSG_SYNC_FE
block|,
name|CTL_MSG_APS_LOCK
block|,
name|CTL_MSG_DATAMOVE
block|,
name|CTL_MSG_DATAMOVE_DONE
block|}
name|ctl_msg_type
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|ctl_scsiio
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|CTL_NUM_SG_ENTRIES
value|9
end_define

begin_struct
struct|struct
name|ctl_io_hdr
block|{
name|uint32_t
name|version
decl_stmt|;
comment|/* interface version XXX */
name|ctl_io_type
name|io_type
decl_stmt|;
comment|/* task I/O, SCSI I/O, etc. */
name|ctl_msg_type
name|msg_type
decl_stmt|;
name|struct
name|ctl_nexus
name|nexus
decl_stmt|;
comment|/* Initiator, port, target, lun */
name|uint32_t
name|iid_indx
decl_stmt|;
comment|/* the index into the iid mapping */
name|uint32_t
name|flags
decl_stmt|;
comment|/* transaction flags */
name|uint32_t
name|status
decl_stmt|;
comment|/* transaction status */
name|uint32_t
name|port_status
decl_stmt|;
comment|/* trans status, set by PORT, 0 = good*/
name|uint32_t
name|timeout
decl_stmt|;
comment|/* timeout in ms */
name|uint32_t
name|retries
decl_stmt|;
comment|/* retry count */
ifdef|#
directive|ifdef
name|CTL_IO_DELAY
name|uint8_t
name|timer_bytes
index|[
name|CTL_TIMER_BYTES
index|]
decl_stmt|;
comment|/* timer kludge */
endif|#
directive|endif
comment|/* CTL_IO_DELAY */
ifdef|#
directive|ifdef
name|CTL_TIME_IO
name|time_t
name|start_time
decl_stmt|;
comment|/* I/O start time */
name|struct
name|bintime
name|start_bt
decl_stmt|;
comment|/* Timer start ticks */
name|struct
name|bintime
name|dma_start_bt
decl_stmt|;
comment|/* DMA start ticks */
name|struct
name|bintime
name|dma_bt
decl_stmt|;
comment|/* DMA total ticks */
name|uint32_t
name|num_dmas
decl_stmt|;
comment|/* Number of DMAs */
endif|#
directive|endif
comment|/* CTL_TIME_IO */
name|union
name|ctl_io
modifier|*
name|original_sc
decl_stmt|;
name|union
name|ctl_io
modifier|*
name|serializing_sc
decl_stmt|;
name|void
modifier|*
name|pool
decl_stmt|;
comment|/* I/O pool */
name|union
name|ctl_priv
name|ctl_private
index|[
name|CTL_NUM_PRIV
index|]
decl_stmt|;
comment|/* CTL private area */
name|uint8_t
name|port_priv
index|[
name|CTL_PORT_PRIV_SIZE
index|]
decl_stmt|;
comment|/* PORT private area*/
name|struct
name|ctl_sg_entry
name|remote_sglist
index|[
name|CTL_NUM_SG_ENTRIES
index|]
decl_stmt|;
name|struct
name|ctl_sg_entry
name|remote_dma_sglist
index|[
name|CTL_NUM_SG_ENTRIES
index|]
decl_stmt|;
name|struct
name|ctl_sg_entry
name|local_sglist
index|[
name|CTL_NUM_SG_ENTRIES
index|]
decl_stmt|;
name|struct
name|ctl_sg_entry
name|local_dma_sglist
index|[
name|CTL_NUM_SG_ENTRIES
index|]
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|ctl_io_hdr
argument_list|)
name|links
expr_stmt|;
comment|/* linked list pointer */
name|TAILQ_ENTRY
argument_list|(
argument|ctl_io_hdr
argument_list|)
name|ooa_links
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ctl_io_hdr
argument_list|)
name|blocked_links
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_TAG_UNTAGGED
block|,
name|CTL_TAG_SIMPLE
block|,
name|CTL_TAG_ORDERED
block|,
name|CTL_TAG_HEAD_OF_QUEUE
block|,
name|CTL_TAG_ACA
block|}
name|ctl_tag_type
typedef|;
end_typedef

begin_union_decl
union_decl|union
name|ctl_io
union_decl|;
end_union_decl

begin_comment
comment|/*  * SCSI passthrough I/O structure for the CAM Target Layer.  Note  * that some of these fields are here for completeness, but they aren't  * used in the CTL implementation.  e.g., timeout and retries won't be  * used.  *  * Note:  Make sure the io_hdr is *always* the first element in this  * structure.  */
end_comment

begin_struct
struct|struct
name|ctl_scsiio
block|{
name|struct
name|ctl_io_hdr
name|io_hdr
decl_stmt|;
comment|/* common to all I/O types */
comment|/* 	 * The ext_* fields are generally intended for frontend use; CTL itself 	 * doesn't modify or use them. 	 */
name|uint32_t
name|ext_sg_entries
decl_stmt|;
comment|/* 0 = no S/G list,> 0 = num entries */
name|uint8_t
modifier|*
name|ext_data_ptr
decl_stmt|;
comment|/* data buffer or S/G list */
name|uint32_t
name|ext_data_len
decl_stmt|;
comment|/* Data transfer length */
name|uint32_t
name|ext_data_filled
decl_stmt|;
comment|/* Amount of data filled so far */
comment|/* 	 * The number of scatter/gather entries in the list pointed to 	 * by kern_data_ptr.  0 means there is no list, just a data pointer. 	 */
name|uint32_t
name|kern_sg_entries
decl_stmt|;
name|uint32_t
name|rem_sg_entries
decl_stmt|;
comment|/* Unused. */
comment|/* 	 * The data pointer or a pointer to the scatter/gather list. 	 */
name|uint8_t
modifier|*
name|kern_data_ptr
decl_stmt|;
comment|/* 	 * Length of the data buffer or scatter/gather list.  It's also 	 * the length of this particular piece of the data transfer, 	 * ie. number of bytes expected to be transferred by the current 	 * invocation of frontend's datamove() callback.  It's always 	 * less than or equal to kern_total_len. 	 */
name|uint32_t
name|kern_data_len
decl_stmt|;
comment|/* 	 * Total length of data to be transferred during this particular 	 * SCSI command, as decoded from SCSI CDB. 	 */
name|uint32_t
name|kern_total_len
decl_stmt|;
comment|/* 	 * Amount of data left after the current data transfer. 	 */
name|uint32_t
name|kern_data_resid
decl_stmt|;
comment|/* 	 * Byte offset of this transfer, equal to the amount of data 	 * already transferred for this SCSI command during previous 	 * datamove() invocations. 	 */
name|uint32_t
name|kern_rel_offset
decl_stmt|;
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
comment|/* sense data */
name|uint8_t
name|sense_len
decl_stmt|;
comment|/* Returned sense length */
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* SCSI status byte */
name|uint8_t
name|sense_residual
decl_stmt|;
comment|/* Unused. */
name|uint32_t
name|residual
decl_stmt|;
comment|/* data residual length */
name|uint32_t
name|tag_num
decl_stmt|;
comment|/* tag number */
name|ctl_tag_type
name|tag_type
decl_stmt|;
comment|/* simple, ordered, head of queue,etc.*/
name|uint8_t
name|cdb_len
decl_stmt|;
comment|/* CDB length */
name|uint8_t
name|cdb
index|[
name|CTL_MAX_CDBLEN
index|]
decl_stmt|;
comment|/* CDB */
name|int
function_decl|(
modifier|*
name|be_move_done
function_decl|)
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
comment|/* called by fe */
name|int
function_decl|(
modifier|*
name|io_cont
function_decl|)
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
comment|/* to continue processing */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_TASK_ABORT_TASK
block|,
name|CTL_TASK_ABORT_TASK_SET
block|,
name|CTL_TASK_CLEAR_ACA
block|,
name|CTL_TASK_CLEAR_TASK_SET
block|,
name|CTL_TASK_I_T_NEXUS_RESET
block|,
name|CTL_TASK_LUN_RESET
block|,
name|CTL_TASK_TARGET_RESET
block|,
name|CTL_TASK_BUS_RESET
block|,
name|CTL_TASK_PORT_LOGIN
block|,
name|CTL_TASK_PORT_LOGOUT
block|}
name|ctl_task_type
typedef|;
end_typedef

begin_comment
comment|/*  * Task management I/O structure.  Aborts, bus resets, etc., are sent using  * this structure.  *  * Note:  Make sure the io_hdr is *always* the first element in this  * structure.  */
end_comment

begin_struct
struct|struct
name|ctl_taskio
block|{
name|struct
name|ctl_io_hdr
name|io_hdr
decl_stmt|;
comment|/* common to all I/O types */
name|ctl_task_type
name|task_action
decl_stmt|;
comment|/* Target Reset, Abort, etc.  */
name|uint32_t
name|tag_num
decl_stmt|;
comment|/* tag number */
name|ctl_tag_type
name|tag_type
decl_stmt|;
comment|/* simple, ordered, etc. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_PR_REG_KEY
block|,
name|CTL_PR_UNREG_KEY
block|,
name|CTL_PR_PREEMPT
block|,
name|CTL_PR_CLEAR
block|,
name|CTL_PR_RESERVE
block|,
name|CTL_PR_RELEASE
block|}
name|ctl_pr_action
typedef|;
end_typedef

begin_comment
comment|/*  * The PR info is specifically for sending Persistent Reserve actions  * to the other SC which it must also act on.  *  * Note:  Make sure the io_hdr is *always* the first element in this  * structure.  */
end_comment

begin_struct
struct|struct
name|ctl_pr_info
block|{
name|ctl_pr_action
name|action
decl_stmt|;
name|uint8_t
name|sa_res_key
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|res_type
decl_stmt|;
name|uint32_t
name|residx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_ha_msg_hdr
block|{
name|ctl_msg_type
name|msg_type
decl_stmt|;
name|union
name|ctl_io
modifier|*
name|original_sc
decl_stmt|;
name|union
name|ctl_io
modifier|*
name|serializing_sc
decl_stmt|;
name|struct
name|ctl_nexus
name|nexus
decl_stmt|;
comment|/* Initiator, port, target, lun */
name|uint32_t
name|status
decl_stmt|;
comment|/* transaction status */
name|TAILQ_ENTRY
argument_list|(
argument|ctl_ha_msg_hdr
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTL_HA_MAX_SG_ENTRIES
value|16
end_define

begin_comment
comment|/*  * Used for CTL_MSG_APS_LOCK.  */
end_comment

begin_struct
struct|struct
name|ctl_ha_msg_aps
block|{
name|struct
name|ctl_ha_msg_hdr
name|hdr
decl_stmt|;
name|uint8_t
name|lock_flag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Used for CTL_MSG_PERS_ACTION.  */
end_comment

begin_struct
struct|struct
name|ctl_ha_msg_pr
block|{
name|struct
name|ctl_ha_msg_hdr
name|hdr
decl_stmt|;
name|struct
name|ctl_pr_info
name|pr_info
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The S/G handling here is a little different than the standard ctl_scsiio  * structure, because we can't pass data by reference in between controllers.  * The S/G list in the ctl_scsiio struct is normally passed in the  * kern_data_ptr field.  So kern_sg_entries here will always be non-zero,  * even if there is only one entry.  *  * Used for CTL_MSG_DATAMOVE.  */
end_comment

begin_struct
struct|struct
name|ctl_ha_msg_dt
block|{
name|struct
name|ctl_ha_msg_hdr
name|hdr
decl_stmt|;
name|ctl_io_flags
name|flags
decl_stmt|;
comment|/* Only I/O flags are used here */
name|uint32_t
name|sg_sequence
decl_stmt|;
comment|/* S/G portion number  */
name|uint8_t
name|sg_last
decl_stmt|;
comment|/* last S/G batch = 1 */
name|uint32_t
name|sent_sg_entries
decl_stmt|;
comment|/* previous S/G count */
name|uint32_t
name|cur_sg_entries
decl_stmt|;
comment|/* current S/G entries */
name|uint32_t
name|kern_sg_entries
decl_stmt|;
comment|/* total S/G entries */
name|uint32_t
name|kern_data_len
decl_stmt|;
comment|/* Length of this S/G list */
name|uint32_t
name|kern_total_len
decl_stmt|;
comment|/* Total length of this 						    transaction */
name|uint32_t
name|kern_data_resid
decl_stmt|;
comment|/* Length left to transfer 						    after this*/
name|uint32_t
name|kern_rel_offset
decl_stmt|;
comment|/* Byte Offset of this 						    transfer */
name|struct
name|ctl_sg_entry
name|sg_list
index|[
name|CTL_HA_MAX_SG_ENTRIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Used for CTL_MSG_SERIALIZE, CTL_MSG_FINISH_IO, CTL_MSG_BAD_JUJU.  */
end_comment

begin_struct
struct|struct
name|ctl_ha_msg_scsi
block|{
name|struct
name|ctl_ha_msg_hdr
name|hdr
decl_stmt|;
name|uint8_t
name|cdb
index|[
name|CTL_MAX_CDBLEN
index|]
decl_stmt|;
comment|/* CDB */
name|uint32_t
name|tag_num
decl_stmt|;
comment|/* tag number */
name|ctl_tag_type
name|tag_type
decl_stmt|;
comment|/* simple, ordered, etc. */
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* SCSI status byte */
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
comment|/* sense data */
name|uint8_t
name|sense_len
decl_stmt|;
comment|/* Returned sense length */
name|uint8_t
name|sense_residual
decl_stmt|;
comment|/* sense residual length */
name|uint32_t
name|residual
decl_stmt|;
comment|/* data residual length */
name|uint32_t
name|fetd_status
decl_stmt|;
comment|/* trans status, set by FETD, 						0 = good*/
name|struct
name|ctl_lba_len
name|lbalen
decl_stmt|;
comment|/* used for stats */
block|}
struct|;
end_struct

begin_comment
comment|/*   * Used for CTL_MSG_MANAGE_TASKS.  */
end_comment

begin_struct
struct|struct
name|ctl_ha_msg_task
block|{
name|struct
name|ctl_ha_msg_hdr
name|hdr
decl_stmt|;
name|ctl_task_type
name|task_action
decl_stmt|;
comment|/* Target Reset, Abort, etc.  */
name|uint32_t
name|tag_num
decl_stmt|;
comment|/* tag number */
name|ctl_tag_type
name|tag_type
decl_stmt|;
comment|/* simple, ordered, etc. */
block|}
struct|;
end_struct

begin_union
union|union
name|ctl_ha_msg
block|{
name|struct
name|ctl_ha_msg_hdr
name|hdr
decl_stmt|;
name|struct
name|ctl_ha_msg_task
name|task
decl_stmt|;
name|struct
name|ctl_ha_msg_scsi
name|scsi
decl_stmt|;
name|struct
name|ctl_ha_msg_dt
name|dt
decl_stmt|;
name|struct
name|ctl_ha_msg_pr
name|pr
decl_stmt|;
name|struct
name|ctl_ha_msg_aps
name|aps
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ctl_prio
block|{
name|struct
name|ctl_io_hdr
name|io_hdr
decl_stmt|;
name|struct
name|ctl_ha_msg_pr
name|pr_msg
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ctl_io
block|{
name|struct
name|ctl_io_hdr
name|io_hdr
decl_stmt|;
comment|/* common to all I/O types */
name|struct
name|ctl_scsiio
name|scsiio
decl_stmt|;
comment|/* Normal SCSI commands */
name|struct
name|ctl_taskio
name|taskio
decl_stmt|;
comment|/* SCSI task management/reset */
name|struct
name|ctl_prio
name|presio
decl_stmt|;
comment|/* update per. res info on other SC */
block|}
union|;
end_union

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|union
name|ctl_io
modifier|*
name|ctl_alloc_io
parameter_list|(
name|void
modifier|*
name|pool_ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_free_io
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_zero_io
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_copy_io
parameter_list|(
name|union
name|ctl_io
modifier|*
name|src
parameter_list|,
name|union
name|ctl_io
modifier|*
name|dest
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_IO_H_ */
end_comment

begin_comment
comment|/*  * vim: ts=8  */
end_comment

end_unit

