begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Qlogic Target Mode Structure and Flag Definitions  *  * Copyright (c) 1997, 1998  * Patrick Stirling  * pms@psconsult.com  * All rights reserved.  *  * Additional Copyright (c) 1999  * Matthew Jacob  * mjacob@feral.com  * All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISPTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|_ISPTARGET_H
end_define

begin_comment
comment|/*  * Defines for all entry types  */
end_comment

begin_define
define|#
directive|define
name|QLTM_SVALID
value|0x80
end_define

begin_define
define|#
directive|define
name|QLTM_SENSELEN
value|18
end_define

begin_comment
comment|/*  * Structure for Enable Lun and Modify Lun queue entries  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|le_header
decl_stmt|;
name|u_int32_t
name|le_reserved
decl_stmt|;
name|u_int8_t
name|le_lun
decl_stmt|;
name|u_int8_t
name|le_rsvd
decl_stmt|;
name|u_int8_t
name|le_ops
decl_stmt|;
comment|/* Modify LUN only */
name|u_int8_t
name|le_tgt
decl_stmt|;
comment|/* Not for FC */
name|u_int32_t
name|le_flags
decl_stmt|;
comment|/* Not for FC */
name|u_int8_t
name|le_status
decl_stmt|;
name|u_int8_t
name|le_reserved2
decl_stmt|;
name|u_int8_t
name|le_cmd_count
decl_stmt|;
name|u_int8_t
name|le_in_count
decl_stmt|;
name|u_int8_t
name|le_cdb6len
decl_stmt|;
comment|/* Not for FC */
name|u_int8_t
name|le_cdb7len
decl_stmt|;
comment|/* Not for FC */
name|u_int16_t
name|le_timeout
decl_stmt|;
name|u_int16_t
name|le_reserved3
index|[
literal|20
index|]
decl_stmt|;
block|}
name|lun_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * le_flags values  */
end_comment

begin_define
define|#
directive|define
name|LUN_TQAE
value|0x00000001
end_define

begin_comment
comment|/* bit1  Tagged Queue Action Enable */
end_comment

begin_define
define|#
directive|define
name|LUN_DSSM
value|0x01000000
end_define

begin_comment
comment|/* bit24 Disable Sending SDP Message */
end_comment

begin_define
define|#
directive|define
name|LUN_DM
value|0x40000000
end_define

begin_comment
comment|/* bit30 Disconnects Mandatory */
end_comment

begin_comment
comment|/*  * le_ops values  */
end_comment

begin_define
define|#
directive|define
name|LUN_CCINCR
value|0x01
end_define

begin_comment
comment|/* increment command count */
end_comment

begin_define
define|#
directive|define
name|LUN_CCDECR
value|0x02
end_define

begin_comment
comment|/* decrement command count */
end_comment

begin_define
define|#
directive|define
name|LUN_ININCR
value|0x40
end_define

begin_comment
comment|/* increment immed. notify count */
end_comment

begin_define
define|#
directive|define
name|LUN_INDECR
value|0x80
end_define

begin_comment
comment|/* decrement immed. notify count */
end_comment

begin_comment
comment|/*  * le_status values  */
end_comment

begin_define
define|#
directive|define
name|LUN_OK
value|0x01
end_define

begin_comment
comment|/* we be rockin' */
end_comment

begin_define
define|#
directive|define
name|LUN_ERR
value|0x04
end_define

begin_comment
comment|/* request completed with error */
end_comment

begin_define
define|#
directive|define
name|LUN_INVAL
value|0x06
end_define

begin_comment
comment|/* invalid request */
end_comment

begin_define
define|#
directive|define
name|LUN_NOCAP
value|0x16
end_define

begin_comment
comment|/* can't provide requested capability */
end_comment

begin_define
define|#
directive|define
name|LUN_ENABLED
value|0x3E
end_define

begin_comment
comment|/* LUN already enabled */
end_comment

begin_comment
comment|/*  * Immediate Notify Entry structure  */
end_comment

begin_define
define|#
directive|define
name|IN_MSGLEN
value|8
end_define

begin_comment
comment|/* 8 bytes */
end_comment

begin_define
define|#
directive|define
name|IN_RSVDLEN
value|8
end_define

begin_comment
comment|/* 8 words */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|in_header
decl_stmt|;
name|u_int32_t
name|in_reserved
decl_stmt|;
name|u_int8_t
name|in_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|u_int8_t
name|in_reserved2
decl_stmt|;
name|u_int8_t
name|in_tgt
decl_stmt|;
comment|/* target */
name|u_int32_t
name|in_flags
decl_stmt|;
name|u_int8_t
name|in_status
decl_stmt|;
name|u_int8_t
name|in_rsvd2
decl_stmt|;
name|u_int8_t
name|in_tag_val
decl_stmt|;
comment|/* tag value */
name|u_int8_t
name|in_tag_type
decl_stmt|;
comment|/* tag type */
name|u_int16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
name|u_int8_t
name|in_msg
index|[
name|IN_MSGLEN
index|]
decl_stmt|;
comment|/* SCSI message bytes */
name|u_int16_t
name|in_reserved3
index|[
name|IN_RSVDLEN
index|]
decl_stmt|;
name|u_int8_t
name|in_sense
index|[
name|QLTM_SENSELEN
index|]
decl_stmt|;
comment|/* suggested sense data */
block|}
name|in_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|in_header
decl_stmt|;
name|u_int32_t
name|in_reserved
decl_stmt|;
name|u_int8_t
name|in_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|u_int16_t
name|in_scclun
decl_stmt|;
name|u_int32_t
name|in_reserved2
decl_stmt|;
name|u_int16_t
name|in_status
decl_stmt|;
name|u_int16_t
name|in_task_flags
decl_stmt|;
name|u_int16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
block|}
name|in_fcentry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Values for the in_status field  */
end_comment

begin_define
define|#
directive|define
name|IN_RESET
value|0x0E
end_define

begin_comment
comment|/* Bus Reset occurred */
end_comment

begin_define
define|#
directive|define
name|IN_NO_RCAP
value|0x16
end_define

begin_comment
comment|/* requested capability not available */
end_comment

begin_define
define|#
directive|define
name|IN_IDE_RECEIVED
value|0x33
end_define

begin_comment
comment|/* Initiator Detected Error msg received */
end_comment

begin_define
define|#
directive|define
name|IN_RSRC_UNAVAIL
value|0x34
end_define

begin_comment
comment|/* resource unavailable */
end_comment

begin_define
define|#
directive|define
name|IN_MSG_RECEIVED
value|0x36
end_define

begin_comment
comment|/* SCSI message received */
end_comment

begin_define
define|#
directive|define
name|IN_ABORT_TASK
value|0x20
end_define

begin_comment
comment|/* task named in RX_ID is being aborted (FC) */
end_comment

begin_define
define|#
directive|define
name|IN_PORT_LOGOUT
value|0x29
end_define

begin_comment
comment|/* port has logged out (FC) */
end_comment

begin_define
define|#
directive|define
name|IN_PORT_CHANGED
value|0x2A
end_define

begin_comment
comment|/* port changed */
end_comment

begin_define
define|#
directive|define
name|IN_GLOBAL_LOGO
value|0x2E
end_define

begin_comment
comment|/* all ports logged out */
end_comment

begin_comment
comment|/*  * Values for the in_task_flags field- should only get one at a time!  */
end_comment

begin_define
define|#
directive|define
name|TASK_FLAGS_ABORT_TASK
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_CLEAR_TASK_SET
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_TARGET_RESET
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_CLEAR_ACA
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_TERMINATE_TASK
value|(1<<15)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_ABORT_TAG
end_ifndef

begin_define
define|#
directive|define
name|MSG_ABORT_TAG
value|0x06
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_CLEAR_QUEUE
end_ifndef

begin_define
define|#
directive|define
name|MSG_CLEAR_QUEUE
value|0x0e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_BUS_DEV_RESET
end_ifndef

begin_define
define|#
directive|define
name|MSG_BUS_DEV_RESET
value|0x0b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_REL_RECOVERY
end_ifndef

begin_define
define|#
directive|define
name|MSG_REL_RECOVERY
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_TERM_IO_PROC
end_ifndef

begin_define
define|#
directive|define
name|MSG_TERM_IO_PROC
value|0x11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Notify Acknowledge Entry structure  */
end_comment

begin_define
define|#
directive|define
name|NA_RSVDLEN
value|22
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|na_header
decl_stmt|;
name|u_int32_t
name|na_reserved
decl_stmt|;
name|u_int8_t
name|na_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|na_iid
decl_stmt|;
comment|/* initiator */
name|u_int8_t
name|na_reserved2
decl_stmt|;
name|u_int8_t
name|na_tgt
decl_stmt|;
comment|/* target */
name|u_int32_t
name|na_flags
decl_stmt|;
name|u_int8_t
name|na_status
decl_stmt|;
name|u_int8_t
name|na_event
decl_stmt|;
name|u_int16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|u_int16_t
name|na_reserved3
index|[
name|NA_RSVDLEN
index|]
decl_stmt|;
block|}
name|na_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Value for the na_event field  */
end_comment

begin_define
define|#
directive|define
name|NA_RST_CLRD
value|0x80
end_define

begin_comment
comment|/* Clear an async event notification */
end_comment

begin_define
define|#
directive|define
name|NA_OK
value|0x01
end_define

begin_comment
comment|/* Notify Acknowledge Succeeded */
end_comment

begin_define
define|#
directive|define
name|NA_INVALID
value|0x06
end_define

begin_comment
comment|/* Invalid Notify Acknowledge */
end_comment

begin_define
define|#
directive|define
name|NA2_RSVDLEN
value|21
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|na_header
decl_stmt|;
name|u_int32_t
name|na_reserved
decl_stmt|;
name|u_int8_t
name|na_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|na_iid
decl_stmt|;
comment|/* initiator */
name|u_int16_t
name|na_scclun
decl_stmt|;
name|u_int16_t
name|na_flags
decl_stmt|;
name|u_int16_t
name|na_reserved2
decl_stmt|;
name|u_int16_t
name|na_status
decl_stmt|;
name|u_int16_t
name|na_task_flags
decl_stmt|;
name|u_int16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|u_int16_t
name|na_reserved3
index|[
name|NA2_RSVDLEN
index|]
decl_stmt|;
block|}
name|na_fcentry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NAFC_RCOUNT
value|0x80
end_define

begin_comment
comment|/* increment resource count */
end_comment

begin_define
define|#
directive|define
name|NAFC_RST_CLRD
value|0x20
end_define

begin_comment
comment|/* Clear LIP Reset */
end_comment

begin_comment
comment|/*  * Accept Target I/O Entry structure  */
end_comment

begin_define
define|#
directive|define
name|ATIO_CDBLEN
value|26
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|at_header
decl_stmt|;
name|u_int32_t
name|at_reserved
decl_stmt|;
name|u_int8_t
name|at_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|u_int8_t
name|at_cdblen
decl_stmt|;
comment|/* cdb length */
name|u_int8_t
name|at_tgt
decl_stmt|;
comment|/* target */
name|u_int32_t
name|at_flags
decl_stmt|;
name|u_int8_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|u_int8_t
name|at_scsi_status
decl_stmt|;
comment|/* scsi status */
name|u_int8_t
name|at_tag_val
decl_stmt|;
comment|/* tag value */
name|u_int8_t
name|at_tag_type
decl_stmt|;
comment|/* tag type */
name|u_int8_t
name|at_cdb
index|[
name|ATIO_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|u_int8_t
name|at_sense
index|[
name|QLTM_SENSELEN
index|]
decl_stmt|;
comment|/* suggested sense data */
block|}
name|at_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * at_flags values  */
end_comment

begin_define
define|#
directive|define
name|AT_NODISC
value|0x00008000
end_define

begin_comment
comment|/* disconnect disabled */
end_comment

begin_define
define|#
directive|define
name|AT_TQAE
value|0x00000001
end_define

begin_comment
comment|/* Tagged Queue Action enabled */
end_comment

begin_comment
comment|/*  * at_status values  */
end_comment

begin_define
define|#
directive|define
name|AT_PATH_INVALID
value|0x07
end_define

begin_comment
comment|/* ATIO sent to firmware for disabled lun */
end_comment

begin_define
define|#
directive|define
name|AT_RESET
value|0x0E
end_define

begin_comment
comment|/* SCSI Bus Reset Occurred */
end_comment

begin_define
define|#
directive|define
name|AT_PHASE_ERROR
value|0x14
end_define

begin_comment
comment|/* Bus phase sequence error */
end_comment

begin_define
define|#
directive|define
name|AT_NOCAP
value|0x16
end_define

begin_comment
comment|/* Requested capability not available */
end_comment

begin_define
define|#
directive|define
name|AT_BDR_MSG
value|0x17
end_define

begin_comment
comment|/* Bus Device Reset msg received */
end_comment

begin_define
define|#
directive|define
name|AT_CDB
value|0x3D
end_define

begin_comment
comment|/* CDB received */
end_comment

begin_comment
comment|/*  * Accept Target I/O Entry structure, Type 2  */
end_comment

begin_define
define|#
directive|define
name|ATIO2_CDBLEN
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|at_header
decl_stmt|;
name|u_int32_t
name|at_reserved
decl_stmt|;
name|u_int8_t
name|at_lun
decl_stmt|;
comment|/* lun or reserved */
name|u_int8_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|u_int16_t
name|at_rxid
decl_stmt|;
comment|/* response ID */
name|u_int16_t
name|at_flags
decl_stmt|;
name|u_int16_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|u_int8_t
name|at_reserved1
decl_stmt|;
name|u_int8_t
name|at_taskcodes
decl_stmt|;
name|u_int8_t
name|at_taskflags
decl_stmt|;
name|u_int8_t
name|at_execodes
decl_stmt|;
name|u_int8_t
name|at_cdb
index|[
name|ATIO2_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|u_int32_t
name|at_datalen
decl_stmt|;
comment|/* allocated data len */
name|u_int16_t
name|at_scclun
decl_stmt|;
comment|/* SCC Lun or reserved */
name|u_int16_t
name|at_reserved2
decl_stmt|;
name|u_int16_t
name|at_scsi_status
decl_stmt|;
name|u_int8_t
name|at_sense
index|[
name|QLTM_SENSELEN
index|]
decl_stmt|;
block|}
name|at2_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_SIMPLEQ
value|0
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_HEADOFQ
value|1
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_ORDERED
value|2
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_ACAQ
value|4
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_UNTAGGED
value|5
end_define

begin_comment
comment|/*  * Continue Target I/O Entry structure  * Request from driver. The response from the  * ISP firmware is the same except that the last 18  * bytes are overwritten by suggested sense data if  * the 'autosense valid' bit is set in the status byte.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ct_header
decl_stmt|;
name|u_int32_t
name|ct_reserved
decl_stmt|;
name|u_int8_t
name|ct_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|u_int8_t
name|ct_reserved2
decl_stmt|;
name|u_int8_t
name|ct_tgt
decl_stmt|;
comment|/* our target id */
name|u_int32_t
name|ct_flags
decl_stmt|;
name|u_int8_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|u_int8_t
name|ct_scsi_status
decl_stmt|;
comment|/* scsi status */
name|u_int8_t
name|ct_tag_val
decl_stmt|;
comment|/* tag value */
name|u_int8_t
name|ct_tag_type
decl_stmt|;
comment|/* tag type */
name|u_int32_t
name|ct_xfrlen
decl_stmt|;
comment|/* transfer length */
name|u_int32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
name|u_int16_t
name|ct_timeout
decl_stmt|;
name|u_int16_t
name|ct_seg_count
decl_stmt|;
name|ispds_t
name|ct_dataseg
index|[
name|ISP_RQDSEG
index|]
decl_stmt|;
block|}
name|ct_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * For some of the dual port SCSI adapters, port (bus #) is reported  * in the MSbit of ct_iid. Bit fields are a bit too awkward here.  *  * Note that this does not apply to FC adapters at all which can and  * do report IIDs between 129&& 255 (these represent devices that have  * logged in across a SCSI fabric).  */
end_comment

begin_define
define|#
directive|define
name|GET_IID_VAL
parameter_list|(
name|x
parameter_list|)
value|(x& 0x3f)
end_define

begin_define
define|#
directive|define
name|GET_BUS_VAL
parameter_list|(
name|x
parameter_list|)
value|((x>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|SET_IID_VAL
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|(y | (x& 0x3f))
end_define

begin_define
define|#
directive|define
name|SET_BUS_VAL
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|(y | ((x& 0x1)<< 7))
end_define

begin_comment
comment|/*  * ct_flags values  */
end_comment

begin_define
define|#
directive|define
name|CT_TQAE
value|0x00000001
end_define

begin_comment
comment|/* bit  1, Tagged Queue Action enable */
end_comment

begin_define
define|#
directive|define
name|CT_DATA_IN
value|0x00000040
end_define

begin_comment
comment|/* bits 6&7, Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_DATA_OUT
value|0x00000080
end_define

begin_comment
comment|/* bits 6&7, Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_NO_DATA
value|0x000000C0
end_define

begin_comment
comment|/* bits 6&7, Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_CCINCR
value|0x00000100
end_define

begin_comment
comment|/* bit 8, autoincrement atio count */
end_comment

begin_define
define|#
directive|define
name|CT_DATAMASK
value|0x000000C0
end_define

begin_comment
comment|/* bits 6&7, Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_NODISC
value|0x00008000
end_define

begin_comment
comment|/* bit 15, Disconnects disabled */
end_comment

begin_define
define|#
directive|define
name|CT_DSDP
value|0x01000000
end_define

begin_comment
comment|/* bit 24, Disable Save Data Pointers */
end_comment

begin_define
define|#
directive|define
name|CT_SENDRDP
value|0x04000000
end_define

begin_comment
comment|/* bit 26, Send Restore Pointers msg */
end_comment

begin_define
define|#
directive|define
name|CT_SENDSTATUS
value|0x80000000
end_define

begin_comment
comment|/* bit 31, Send SCSI status byte */
end_comment

begin_comment
comment|/*  * ct_status values  * - set by the firmware when it returns the CTIO  */
end_comment

begin_define
define|#
directive|define
name|CT_OK
value|0x01
end_define

begin_comment
comment|/* completed without error */
end_comment

begin_define
define|#
directive|define
name|CT_ABORTED
value|0x02
end_define

begin_comment
comment|/* aborted by host */
end_comment

begin_define
define|#
directive|define
name|CT_ERR
value|0x04
end_define

begin_comment
comment|/* see sense data for error */
end_comment

begin_define
define|#
directive|define
name|CT_INVAL
value|0x06
end_define

begin_comment
comment|/* request for disabled lun */
end_comment

begin_define
define|#
directive|define
name|CT_NOPATH
value|0x07
end_define

begin_comment
comment|/* invalid ITL nexus */
end_comment

begin_define
define|#
directive|define
name|CT_INVRXID
value|0x08
end_define

begin_comment
comment|/* (FC only) Invalid RX_ID */
end_comment

begin_define
define|#
directive|define
name|CT_RSELTMO
value|0x0A
end_define

begin_comment
comment|/* reselection timeout after 2 tries */
end_comment

begin_define
define|#
directive|define
name|CT_TIMEOUT
value|0x0B
end_define

begin_comment
comment|/* timed out */
end_comment

begin_define
define|#
directive|define
name|CT_RESET
value|0x0E
end_define

begin_comment
comment|/* SCSI Bus Reset occurred */
end_comment

begin_define
define|#
directive|define
name|CT_PHASE_ERROR
value|0x14
end_define

begin_comment
comment|/* Bus phase sequence error */
end_comment

begin_define
define|#
directive|define
name|CT_BDR_MSG
value|0x17
end_define

begin_comment
comment|/* Bus Device Reset msg received */
end_comment

begin_define
define|#
directive|define
name|CT_TERMINATED
value|0x19
end_define

begin_comment
comment|/* due to Terminate Transfer mbox cmd */
end_comment

begin_define
define|#
directive|define
name|CT_PORTNOTAVAIL
value|0x28
end_define

begin_comment
comment|/* port not available */
end_comment

begin_define
define|#
directive|define
name|CT_LOGOUT
value|0x29
end_define

begin_comment
comment|/* port logout */
end_comment

begin_define
define|#
directive|define
name|CT_PORTCHANGED
value|0x2A
end_define

begin_comment
comment|/* port changed */
end_comment

begin_define
define|#
directive|define
name|CT_NOACK
value|0x35
end_define

begin_comment
comment|/* Outstanding Immed. Notify. entry */
end_comment

begin_comment
comment|/*  * When the firmware returns a CTIO entry, it may overwrite the last  * part of the structure with sense data. This starts at offset 0x2E  * into the entry, which is in the middle of ct_dataseg[1]. Rather  * than define a new struct for this, I'm just using the sense data  * offset.  */
end_comment

begin_define
define|#
directive|define
name|CTIO_SENSE_OFFSET
value|0x2E
end_define

begin_comment
comment|/*  * Entry length in u_longs. All entries are the same size so  * any one will do as the numerator.  */
end_comment

begin_define
define|#
directive|define
name|UINT32_ENTRY_SIZE
value|(sizeof(at_entry_t)/sizeof(u_int32_t))
end_define

begin_comment
comment|/*  * QLA2100 CTIO (type 2) entry  */
end_comment

begin_define
define|#
directive|define
name|MAXRESPLEN
value|26
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ct_header
decl_stmt|;
name|u_int32_t
name|ct_reserved
decl_stmt|;
name|u_int8_t
name|ct_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|u_int16_t
name|ct_rxid
decl_stmt|;
comment|/* response ID */
name|u_int16_t
name|ct_flags
decl_stmt|;
name|u_int16_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|u_int16_t
name|ct_timeout
decl_stmt|;
name|u_int16_t
name|ct_seg_count
decl_stmt|;
name|u_int32_t
name|ct_reloff
decl_stmt|;
comment|/* relative offset */
name|int32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
union|union
block|{
comment|/* 		 * The three different modes that the target driver 		 * can set the CTIO2 up as. 		 * 		 * The first is for sending FCP_DATA_IUs as well as 		 * (optionally) sending a terminal SCSI status FCP_RSP_IU. 		 * 		 * The second is for sending SCSI sense data in an FCP_RSP_IU. 		 * Note that no FCP_DATA_IUs will be sent. 		 * 		 * The third is for sending FCP_RSP_IUs as built specifically 		 * in system memory as located by the isp_dataseg. 		 */
struct|struct
block|{
name|u_int32_t
name|_reserved
decl_stmt|;
name|u_int16_t
name|_reserved2
decl_stmt|;
name|u_int16_t
name|ct_scsi_status
decl_stmt|;
name|u_int32_t
name|ct_xfrlen
decl_stmt|;
name|ispds_t
name|ct_dataseg
index|[
name|ISP_RQDSEG_T2
index|]
decl_stmt|;
block|}
name|m0
struct|;
struct|struct
block|{
name|u_int16_t
name|_reserved
decl_stmt|;
name|u_int16_t
name|_reserved2
decl_stmt|;
name|u_int16_t
name|ct_senselen
decl_stmt|;
name|u_int16_t
name|ct_scsi_status
decl_stmt|;
name|u_int16_t
name|ct_resplen
decl_stmt|;
name|u_int8_t
name|ct_resp
index|[
name|MAXRESPLEN
index|]
decl_stmt|;
block|}
name|m1
struct|;
struct|struct
block|{
name|u_int32_t
name|_reserved
decl_stmt|;
name|u_int16_t
name|_reserved2
decl_stmt|;
name|u_int16_t
name|_reserved3
decl_stmt|;
name|u_int32_t
name|ct_datalen
decl_stmt|;
name|ispds_t
name|ct_fcp_rsp_iudata
decl_stmt|;
block|}
name|m2
struct|;
comment|/* 		 * CTIO2 returned from F/W... 		 */
struct|struct
block|{
name|u_int32_t
name|_reserved
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|ct_scsi_status
decl_stmt|;
name|u_int8_t
name|ct_sense
index|[
name|QLTM_SENSELEN
index|]
decl_stmt|;
block|}
name|fw
struct|;
block|}
name|rsp
union|;
block|}
name|ct2_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * ct_flags values for CTIO2  */
end_comment

begin_define
define|#
directive|define
name|CT2_FLAG_MMASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|CT2_FLAG_MODE0
value|0x0000
end_define

begin_define
define|#
directive|define
name|CT2_FLAG_MODE1
value|0x0001
end_define

begin_define
define|#
directive|define
name|CT2_FLAG_MODE2
value|0x0002
end_define

begin_define
define|#
directive|define
name|CT2_DATA_IN
value|CT_DATA_IN
end_define

begin_define
define|#
directive|define
name|CT2_DATA_OUT
value|CT_DATA_OUT
end_define

begin_define
define|#
directive|define
name|CT2_NO_DATA
value|CT_NO_DATA
end_define

begin_define
define|#
directive|define
name|CT2_DATAMASK
value|CT_DATAMASK
end_define

begin_define
define|#
directive|define
name|CT2_CCINCR
value|0x0100
end_define

begin_define
define|#
directive|define
name|CT2_FASTPOST
value|0x0200
end_define

begin_define
define|#
directive|define
name|CT2_SENDSTATUS
value|0x8000
end_define

begin_comment
comment|/*  * ct_status values are (mostly) the same as that for ct_entry.  */
end_comment

begin_comment
comment|/*  * ct_scsi_status values- the low 8 bits are the normal SCSI status  * we know and love. The upper 8 bits are validity markers for FCP_RSP_IU  * fields.  */
end_comment

begin_define
define|#
directive|define
name|CT2_RSPLEN_VALID
value|0x0100
end_define

begin_define
define|#
directive|define
name|CT2_SNSLEN_VALID
value|0x0200
end_define

begin_define
define|#
directive|define
name|CT2_DATA_OVER
value|0x0400
end_define

begin_define
define|#
directive|define
name|CT2_DATA_UNDER
value|0x0800
end_define

begin_comment
comment|/*  * Macros for packing/unpacking the above structures  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_define
define|#
directive|define
name|ISP_SBUS_SWOZZLE
parameter_list|(
name|isp
parameter_list|,
name|src
parameter_list|,
name|dest
parameter_list|,
name|taga
parameter_list|,
name|tagb
parameter_list|)
define|\
value|if (isp->isp_bus == ISP_SBUS) {	\ 		source -> taga =  dest -> tagb;	\ 		source -> tagb =  dest -> taga;	\ 	} else { \ 		source -> taga =  dest -> taga;	\ 		source -> tagb =  dest -> taga;	\ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_SBUS_SWOZZLE
parameter_list|(
name|isp
parameter_list|,
name|src
parameter_list|,
name|dest
parameter_list|,
name|taga
parameter_list|,
name|tagb
parameter_list|)
define|\
value|source -> taga =  dest -> taga;	\ 		source -> tagb =  dest -> taga;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MCIDF
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|if ((void *) d != (void *)s) MEMCPY(d, s, QENTRY_LEN)
end_define

begin_comment
comment|/* This is really only for SBus cards on a sparc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_define
define|#
directive|define
name|ISP_SWIZ_ATIO
parameter_list|(
name|isp
parameter_list|,
name|dest
parameter_list|,
name|vsrc
parameter_list|)
define|\
value|{									\ 	at_entry_t *source = (at_entry_t *) vsrc;			\ 	at_entry_t local, *vdst;					\ 	if ((void *)dest == (void *)vsrc) {				\ 		MEMCPY(vsrc,&local, sizeof (at_entry_t));		\ 		vdst =&local;						\ 	} else {							\ 		vdst = dest;						\ 	}								\ 	vdst->at_header = source->at_header;				\ 	vdst->at_reserved2 = source->at_reserved2;			\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, at_lun, at_iid);		\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, at_cdblen, at_tgt);		\ 	vdst->at_flags = source->at_flags;				\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, at_status, at_scsi_status);	\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, at_tag_val, at_tag_type);	\ 	MEMCPY(vdst->at_cdb, source->at_cdb, ATIO_CDBLEN);		\ 	MEMCPY(vdst->at_sense, source->at_sense, QLTM_SENSELEN);	\ }
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_CTIO
parameter_list|(
name|isp
parameter_list|,
name|dest
parameter_list|,
name|vsrc
parameter_list|)
define|\
value|{									\ 	ct_entry_t *source = (ct_entry-t *) vsrc;			\ 	ct_entry_t *local, *vdst;					\ 	if ((void *)dest == (void *)vsrc) {				\ 		MEMCPY(vsrc,&local, sizeof (ct_entry_t));		\ 		vdst =&local;						\ 	} else {							\ 		vdst = dest;						\ 	}								\ 	vdst->ct_header = source->ct_header;				\ 	vdst->ct_reserved = source->ct_reserved;			\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, ct_lun, ct_iid);		\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, ct_rsvd, ct_tgt);		\ 	vdst->ct_flags = source->ct_flags;				\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, ct_status, ct_scsi_status);	\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, ct_tag_val, ct_tag_type);	\ 	vdst->ct_xfrlen = source->ct_xfrlen;				\ 	vdst->ct_resid = source->ct_resid;				\ 	vdst->ct_timeout = source->ct_timeout;				\ 	vdst->ct_seg_count = source->ct_seg_count;			\ 	MEMCPY(vdst->ct_cdb, source->ct_cdb, ATIO_CDBLEN);		\ 	MEMCPY(vdst->ct_sense, source->ct_sense, QLTM_SENSELEN);	\ 	vdst->ct_dataseg = source->ct_dataseg;				\ }
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_ENABLE_LUN
parameter_list|(
name|isp
parameter_list|,
name|dest
parameter_list|,
name|vsrc
parameter_list|)
define|\
value|{									\ 	lun_entry_t *source = (lun_entry_t *)vsrc;			\ 	lun_entry_t *local, *vdst;					\ 	if ((void *)dest == (void *)vsrc) {				\ 		MEMCPY(vsrc,&local, sizeof (lun_entry_t));		\ 		vdst =&local;						\ 	} else {							\ 		vdst = dest;						\ 	}								\ 	vdst->le_header = source->le_header;				\ 	vdst->le_reserved2 = source->le_reserved2;			\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, le_lun, le_rsvd);		\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, le_ops, le_tgt);		\ 	vdst->le_flags = source->le_flags;				\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, le_status, le_rsvd2);	\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, le_cmd_count, le_in_count);	\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, le_cdb6len, le_cdb7len);	\ 	vdst->le_timeout = source->le_timeout;				\ 	vdst->le_reserved = source->le_reserved;			\ }
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_NOTIFY
parameter_list|(
name|isp
parameter_list|,
name|dest
parameter_list|,
name|vsrc
parameter_list|)
define|\
value|{									\ 	in_entry_type *source = (in_entry_t *)vsrc;			\ 	in_entry_t *local, *vdst;					\ 	if ((void *)dest == (void *)vsrc) {				\ 		MEMCPY(vsrc,&local, sizeof (in_entry_t));		\ 		vdst =&local;						\ 	} else {							\ 		vdst = dest;						\ 	}								\ 	vdst->in_header = source->in_header;				\ 	vdst->in_reserved2 = source->in_reserved2;			\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, in_lun, in_iid);		\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, in_rsvd, in_tgt);		\ 	vdst->in_flags = source->in_flags;				\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, in_status, in_rsvd2);	\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, in_tag_val, in_tag_type);	\ 	vdst->in_seqid = source->in_seqid;				\ 	MEMCPY(vdst->in_msg, source->in_msg, IN_MSGLEN);		\ 	MEMCPY(vdst->in_reserved, source->in_reserved, IN_RESERVED);	\ 	MEMCPY(vdst->in_sense, source->in_sense, QLTM_SENSELEN);	\ }
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_NOT_ACK
parameter_list|(
name|isp
parameter_list|,
name|dest
parameter_list|)
define|\
value|{									\ 	na_entry_t *source = (na_entry_t *)vsrc;			\ 	na_entry_t *local, *vdst;					\ 	if ((void *)dest == (void *)vsrc) {				\ 		MEMCPY(vsrc,&local, sizeof (na_entry_t));		\ 		vdst =&local;						\ 	} else {							\ 		vdst = dest;						\ 	}								\ 	vdst->na_header = source->na_header;				\ 	vdst->na_reserved2 = source->na_reserved2;			\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, na_lun, na_iid);		\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, na_rsvd, na_tgt);		\ 	vdst->na_flags = source->na_flags;				\ 	ISP_SBUS_SWOZZLE(isp, source, vdst, na_status, na_event);	\ 	vdst->na_seqid = source->na_seqid;				\ 	MEMCPY(vdst->na_reserved, source->na_reserved, NA_RSVDLEN);	\ }
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_NOT_ACK_FC
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_ATIO2
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_CTIO2
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_SWIZ_ATIO
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_CTIO
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_ENABLE_LUN
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_NOTIFY
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_NOT_ACK
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_NOT_ACK_FC
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_ATIO2
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZ_CTIO2
parameter_list|(
name|isp
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|MCIDF(d, s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Debug macros  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|isp_tdebug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ISP_TDQE
parameter_list|(
name|isp
parameter_list|,
name|msg
parameter_list|,
name|idx
parameter_list|,
name|arg
parameter_list|)
define|\
value|if (isp_tdebug> 3) isp_print_qentry(isp, msg, idx, arg)
end_define

begin_define
define|#
directive|define
name|ITDEBUG
parameter_list|(
name|level
parameter_list|,
name|msg
parameter_list|)
value|if (isp_tdebug>= level) PRINTF msg
end_define

begin_comment
comment|/*  * The functions below are target mode functions that  * are generally internal to the Qlogic driver.  */
end_comment

begin_comment
comment|/*  * This function handles new response queue entry appropriate for target mode.  */
end_comment

begin_decl_stmt
name|int
name|isp_target_notify
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|void
operator|*
operator|,
name|u_int16_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Enable/Disable/Modify a logical unit.  */
end_comment

begin_define
define|#
directive|define
name|DFLT_CMD_CNT
value|(RESULT_QUEUE_LEN>> 1)
end_define

begin_define
define|#
directive|define
name|DFLT_INOTIFY
value|(4)
end_define

begin_decl_stmt
name|int
name|isp_lun_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * General request queue 'put' routine for target mode entries.  */
end_comment

begin_decl_stmt
name|int
name|isp_target_put_entry
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
name|isp
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * General routine to put back an ATIO entry-  * used for replenishing f/w resource counts.  */
end_comment

begin_decl_stmt
name|int
name|isp_target_put_atio
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * General routine to send a final CTIO for a command- used mostly for  * local responses.  */
end_comment

begin_decl_stmt
name|int
name|isp_endcmd
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|void
operator|*
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ECMD_SVALID
value|0x100
end_define

begin_comment
comment|/*  * Handle an asynchronous event  */
end_comment

begin_decl_stmt
name|void
name|isp_target_async
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPTARGET_H */
end_comment

end_unit

