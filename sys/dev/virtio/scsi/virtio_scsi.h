begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_SCSI_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_SCSI_H
end_define

begin_comment
comment|/* Feature bits */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_SCSI_F_INOUT
value|0x0001
end_define

begin_comment
comment|/* Single request can contain both 					 * read and write buffers */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_SCSI_F_HOTPLUG
value|0x0002
end_define

begin_comment
comment|/* Host should enable hot plug/unplug 					 * of new LUNs and targets. 					 */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_SCSI_CDB_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_SENSE_SIZE
value|96
end_define

begin_comment
comment|/* SCSI command request, followed by data-out */
end_comment

begin_struct
struct|struct
name|virtio_scsi_cmd_req
block|{
name|uint8_t
name|lun
index|[
literal|8
index|]
decl_stmt|;
comment|/* Logical Unit Number */
name|uint64_t
name|tag
decl_stmt|;
comment|/* Command identifier */
name|uint8_t
name|task_attr
decl_stmt|;
comment|/* Task attribute */
name|uint8_t
name|prio
decl_stmt|;
name|uint8_t
name|crn
decl_stmt|;
name|uint8_t
name|cdb
index|[
name|VIRTIO_SCSI_CDB_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Response, followed by sense data and data-in */
end_comment

begin_struct
struct|struct
name|virtio_scsi_cmd_resp
block|{
name|uint32_t
name|sense_len
decl_stmt|;
comment|/* Sense data length */
name|uint32_t
name|resid
decl_stmt|;
comment|/* Residual bytes in data buffer */
name|uint16_t
name|status_qualifier
decl_stmt|;
comment|/* Status qualifier */
name|uint8_t
name|status
decl_stmt|;
comment|/* Command completion status */
name|uint8_t
name|response
decl_stmt|;
comment|/* Response values */
name|uint8_t
name|sense
index|[
name|VIRTIO_SCSI_SENSE_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Task Management Request */
end_comment

begin_struct
struct|struct
name|virtio_scsi_ctrl_tmf_req
block|{
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|subtype
decl_stmt|;
name|uint8_t
name|lun
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|tag
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|virtio_scsi_ctrl_tmf_resp
block|{
name|uint8_t
name|response
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Asynchronous notification query/subscription */
end_comment

begin_struct
struct|struct
name|virtio_scsi_ctrl_an_req
block|{
name|uint32_t
name|type
decl_stmt|;
name|uint8_t
name|lun
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|event_requested
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|virtio_scsi_ctrl_an_resp
block|{
name|uint32_t
name|event_actual
decl_stmt|;
name|uint8_t
name|response
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|virtio_scsi_event
block|{
name|uint32_t
name|event
decl_stmt|;
name|uint8_t
name|lun
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|reason
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|virtio_scsi_config
block|{
name|uint32_t
name|num_queues
decl_stmt|;
name|uint32_t
name|seg_max
decl_stmt|;
name|uint32_t
name|max_sectors
decl_stmt|;
name|uint32_t
name|cmd_per_lun
decl_stmt|;
name|uint32_t
name|event_info_size
decl_stmt|;
name|uint32_t
name|sense_size
decl_stmt|;
name|uint32_t
name|cdb_size
decl_stmt|;
name|uint16_t
name|max_channel
decl_stmt|;
name|uint16_t
name|max_target
decl_stmt|;
name|uint32_t
name|max_lun
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Response codes */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_OK
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_FUNCTION_COMPLETE
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_OVERRUN
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_ABORTED
value|2
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_BAD_TARGET
value|3
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_RESET
value|4
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_BUSY
value|5
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_TRANSPORT_FAILURE
value|6
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_TARGET_FAILURE
value|7
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_NEXUS_FAILURE
value|8
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_FAILURE
value|9
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_FUNCTION_SUCCEEDED
value|10
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_FUNCTION_REJECTED
value|11
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_INCORRECT_LUN
value|12
end_define

begin_comment
comment|/* Controlq type codes.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_AN_QUERY
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_AN_SUBSCRIBE
value|2
end_define

begin_comment
comment|/* Valid TMF subtypes.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF_ABORT_TASK
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF_ABORT_TASK_SET
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF_CLEAR_ACA
value|2
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF_CLEAR_TASK_SET
value|3
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF_I_T_NEXUS_RESET
value|4
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF_LOGICAL_UNIT_RESET
value|5
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF_QUERY_TASK
value|6
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TMF_QUERY_TASK_SET
value|7
end_define

begin_comment
comment|/* Events.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_EVENTS_MISSED
value|0x80000000
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_NO_EVENT
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_TRANSPORT_RESET
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_T_ASYNC_NOTIFY
value|2
end_define

begin_comment
comment|/* Reasons of transport reset event */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_SCSI_EVT_RESET_HARD
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_EVT_RESET_RESCAN
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_EVT_RESET_REMOVED
value|2
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_SIMPLE
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_ORDERED
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_HEAD
value|2
end_define

begin_define
define|#
directive|define
name|VIRTIO_SCSI_S_ACA
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_SCSI_H */
end_comment

end_unit

