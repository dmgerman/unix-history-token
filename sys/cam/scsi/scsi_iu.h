begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is in the public domain.  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_SCSI_IU_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_SCSI_IU_H
value|1
end_define

begin_struct
struct|struct
name|scsi_status_iu_header
block|{
name|u_int8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|SIU_SNSVALID
value|0x2
define|#
directive|define
name|SIU_RSPVALID
value|0x1
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|sense_length
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|pkt_failures_length
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|pkt_failures
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIU_PKTFAIL_OFFSET
parameter_list|(
name|siu
parameter_list|)
value|12
end_define

begin_define
define|#
directive|define
name|SIU_PKTFAIL_CODE
parameter_list|(
name|siu
parameter_list|)
value|(scsi_4btoul((siu)->pkt_failures)& 0xFF)
end_define

begin_define
define|#
directive|define
name|SIU_PFC_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SIU_PFC_CIU_FIELDS_INVALID
value|2
end_define

begin_define
define|#
directive|define
name|SIU_PFC_TMF_NOT_SUPPORTED
value|4
end_define

begin_define
define|#
directive|define
name|SIU_PFC_TMF_FAILED
value|5
end_define

begin_define
define|#
directive|define
name|SIU_PFC_INVALID_TYPE_CODE
value|6
end_define

begin_define
define|#
directive|define
name|SIU_PFC_ILLEGAL_REQUEST
value|7
end_define

begin_define
define|#
directive|define
name|SIU_SENSE_OFFSET
parameter_list|(
name|siu
parameter_list|)
define|\
value|(12 + (((siu)->flags& SIU_RSPVALID)		\ 	? scsi_4btoul((siu)->pkt_failures_length)	\ 	: 0))
end_define

begin_define
define|#
directive|define
name|SIU_TASKMGMT_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|SIU_TASKMGMT_ABORT_TASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SIU_TASKMGMT_ABORT_TASK_SET
value|0x02
end_define

begin_define
define|#
directive|define
name|SIU_TASKMGMT_CLEAR_TASK_SET
value|0x04
end_define

begin_define
define|#
directive|define
name|SIU_TASKMGMT_LUN_RESET
value|0x08
end_define

begin_define
define|#
directive|define
name|SIU_TASKMGMT_TARGET_RESET
value|0x20
end_define

begin_define
define|#
directive|define
name|SIU_TASKMGMT_CLEAR_ACA
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_SCSI_SCSI_IU_H*/
end_comment

end_unit

