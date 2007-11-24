begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  *  Copyright (c) 1997-2007 by Matthew Jacob  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *   *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *   *  THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *  SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Qlogic Target Mode Structure and Flag Definitions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISP_TARGET_H
end_ifndef

begin_define
define|#
directive|define
name|_ISP_TARGET_H
end_define

begin_define
define|#
directive|define
name|QLTM_SENSELEN
value|18
end_define

begin_comment
comment|/* non-FC cards only */
end_comment

begin_define
define|#
directive|define
name|QLTM_SVALID
value|0x80
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
name|uint32_t
name|le_reserved
decl_stmt|;
name|uint8_t
name|le_lun
decl_stmt|;
name|uint8_t
name|le_rsvd
decl_stmt|;
name|uint8_t
name|le_ops
decl_stmt|;
comment|/* Modify LUN only */
name|uint8_t
name|le_tgt
decl_stmt|;
comment|/* Not for FC */
name|uint32_t
name|le_flags
decl_stmt|;
comment|/* Not for FC */
name|uint8_t
name|le_status
decl_stmt|;
name|uint8_t
name|le_reserved2
decl_stmt|;
name|uint8_t
name|le_cmd_count
decl_stmt|;
name|uint8_t
name|le_in_count
decl_stmt|;
name|uint8_t
name|le_cdb6len
decl_stmt|;
comment|/* Not for FC */
name|uint8_t
name|le_cdb7len
decl_stmt|;
comment|/* Not for FC */
name|uint16_t
name|le_timeout
decl_stmt|;
name|uint16_t
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
value|0x00000002
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
name|LUN_DISAD
value|0x02000000
end_define

begin_comment
comment|/* bit25 Disable autodisconnect */
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
name|uint32_t
name|in_reserved
decl_stmt|;
name|uint8_t
name|in_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|uint8_t
name|in_reserved2
decl_stmt|;
name|uint8_t
name|in_tgt
decl_stmt|;
comment|/* target */
name|uint32_t
name|in_flags
decl_stmt|;
name|uint8_t
name|in_status
decl_stmt|;
name|uint8_t
name|in_rsvd2
decl_stmt|;
name|uint8_t
name|in_tag_val
decl_stmt|;
comment|/* tag value */
name|uint8_t
name|in_tag_type
decl_stmt|;
comment|/* tag type */
name|uint16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
name|uint8_t
name|in_msg
index|[
name|IN_MSGLEN
index|]
decl_stmt|;
comment|/* SCSI message bytes */
name|uint16_t
name|in_reserved3
index|[
name|IN_RSVDLEN
index|]
decl_stmt|;
name|uint8_t
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
name|uint32_t
name|in_reserved
decl_stmt|;
name|uint8_t
name|in_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|uint16_t
name|in_scclun
decl_stmt|;
name|uint32_t
name|in_reserved2
decl_stmt|;
name|uint16_t
name|in_status
decl_stmt|;
name|uint16_t
name|in_task_flags
decl_stmt|;
name|uint16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
block|}
name|in_fcentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|in_header
decl_stmt|;
name|uint32_t
name|in_reserved
decl_stmt|;
name|uint16_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|uint16_t
name|in_scclun
decl_stmt|;
name|uint32_t
name|in_reserved2
decl_stmt|;
name|uint16_t
name|in_status
decl_stmt|;
name|uint16_t
name|in_task_flags
decl_stmt|;
name|uint16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
block|}
name|in_fcentry_e_t
typedef|;
end_typedef

begin_comment
comment|/*  * Values for the in_status field  */
end_comment

begin_define
define|#
directive|define
name|IN_REJECT
value|0x0D
end_define

begin_comment
comment|/* Message Reject message received */
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

begin_define
define|#
directive|define
name|IN_NO_NEXUS
value|0x3B
end_define

begin_comment
comment|/* Nexus not established */
end_comment

begin_comment
comment|/*  * Values for the in_task_flags field- should only get one at a time!  */
end_comment

begin_define
define|#
directive|define
name|TASK_FLAGS_RESERVED_MASK
value|(0xe700)
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
name|TASK_FLAGS_TARGET_RESET
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_LUN_RESET
value|(1<<12)
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
name|TASK_FLAGS_ABORT_TASK_SET
value|(1<<9)
end_define

begin_comment
comment|/*  * ISP24XX Immediate Notify  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|in_header
decl_stmt|;
name|uint32_t
name|in_reserved
decl_stmt|;
name|uint16_t
name|in_nphdl
decl_stmt|;
name|uint16_t
name|in_reserved1
decl_stmt|;
name|uint16_t
name|in_flags
decl_stmt|;
name|uint16_t
name|in_srr_rxid
decl_stmt|;
name|uint16_t
name|in_status
decl_stmt|;
name|uint8_t
name|in_status_subcode
decl_stmt|;
name|uint8_t
name|in_reserved2
decl_stmt|;
name|uint32_t
name|in_rxid
decl_stmt|;
name|uint16_t
name|in_srr_reloff_lo
decl_stmt|;
name|uint16_t
name|in_srr_reloff_hi
decl_stmt|;
name|uint16_t
name|in_srr_iu
decl_stmt|;
name|uint16_t
name|in_srr_oxid
decl_stmt|;
name|uint8_t
name|in_reserved3
index|[
literal|18
index|]
decl_stmt|;
name|uint8_t
name|in_reserved4
decl_stmt|;
name|uint8_t
name|in_vpindex
decl_stmt|;
name|uint32_t
name|in_reserved5
decl_stmt|;
name|uint16_t
name|in_portid_lo
decl_stmt|;
name|uint8_t
name|in_portid_hi
decl_stmt|;
name|uint8_t
name|in_reserved6
decl_stmt|;
name|uint16_t
name|in_reserved7
decl_stmt|;
name|uint16_t
name|in_oxid
decl_stmt|;
block|}
name|in_fcentry_24xx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IN24XX_FLAG_PUREX_IOCB
value|0x1
end_define

begin_define
define|#
directive|define
name|IN24XX_FLAG_GLOBAL_LOGOUT
value|0x2
end_define

begin_define
define|#
directive|define
name|IN24XX_LIP_RESET
value|0x0E
end_define

begin_define
define|#
directive|define
name|IN24XX_LINK_RESET
value|0x0F
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT
value|0x29
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_CHANGED
value|0x2A
end_define

begin_define
define|#
directive|define
name|IN24XX_LINK_FAILED
value|0x2E
end_define

begin_define
define|#
directive|define
name|IN24XX_SRR_RCVD
value|0x45
end_define

begin_define
define|#
directive|define
name|IN24XX_ELS_RCVD
value|0x46
end_define

begin_comment
comment|/* 					 * login-affectin ELS received- check 					 * subcode for specific opcode 					 */
end_comment

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
name|uint32_t
name|na_reserved
decl_stmt|;
name|uint8_t
name|na_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|na_iid
decl_stmt|;
comment|/* initiator */
name|uint8_t
name|na_reserved2
decl_stmt|;
name|uint8_t
name|na_tgt
decl_stmt|;
comment|/* target */
name|uint32_t
name|na_flags
decl_stmt|;
name|uint8_t
name|na_status
decl_stmt|;
name|uint8_t
name|na_event
decl_stmt|;
name|uint16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|uint16_t
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
name|uint32_t
name|na_reserved
decl_stmt|;
name|uint8_t
name|na_reserved1
decl_stmt|;
name|uint8_t
name|na_iid
decl_stmt|;
comment|/* initiator loop id */
name|uint16_t
name|na_response
decl_stmt|;
name|uint16_t
name|na_flags
decl_stmt|;
name|uint16_t
name|na_reserved2
decl_stmt|;
name|uint16_t
name|na_status
decl_stmt|;
name|uint16_t
name|na_task_flags
decl_stmt|;
name|uint16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|uint16_t
name|na_reserved3
index|[
name|NA2_RSVDLEN
index|]
decl_stmt|;
block|}
name|na_fcentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|na_header
decl_stmt|;
name|uint32_t
name|na_reserved
decl_stmt|;
name|uint16_t
name|na_iid
decl_stmt|;
comment|/* initiator loop id */
name|uint16_t
name|na_response
decl_stmt|;
comment|/* response code */
name|uint16_t
name|na_flags
decl_stmt|;
name|uint16_t
name|na_reserved2
decl_stmt|;
name|uint16_t
name|na_status
decl_stmt|;
name|uint16_t
name|na_task_flags
decl_stmt|;
name|uint16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|uint16_t
name|na_reserved3
index|[
name|NA2_RSVDLEN
index|]
decl_stmt|;
block|}
name|na_fcentry_e_t
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

begin_define
define|#
directive|define
name|NAFC_TVALID
value|0x10
end_define

begin_comment
comment|/* task mangement response code is valid */
end_comment

begin_comment
comment|/*  * ISP24XX Notify Acknowledge  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|na_header
decl_stmt|;
name|uint32_t
name|na_handle
decl_stmt|;
name|uint16_t
name|na_nphdl
decl_stmt|;
name|uint16_t
name|na_reserved1
decl_stmt|;
name|uint16_t
name|na_flags
decl_stmt|;
name|uint16_t
name|na_srr_rxid
decl_stmt|;
name|uint16_t
name|na_status
decl_stmt|;
name|uint8_t
name|na_status_subcode
decl_stmt|;
name|uint8_t
name|na_reserved2
decl_stmt|;
name|uint32_t
name|na_rxid
decl_stmt|;
name|uint16_t
name|na_srr_reloff_lo
decl_stmt|;
name|uint16_t
name|na_srr_reloff_hi
decl_stmt|;
name|uint16_t
name|na_srr_iu
decl_stmt|;
name|uint16_t
name|na_srr_flags
decl_stmt|;
name|uint8_t
name|na_reserved3
index|[
literal|18
index|]
decl_stmt|;
name|uint8_t
name|na_reserved4
decl_stmt|;
name|uint8_t
name|na_vpindex
decl_stmt|;
name|uint8_t
name|na_srr_reject_vunique
decl_stmt|;
name|uint8_t
name|na_srr_reject_explanation
decl_stmt|;
name|uint8_t
name|na_srr_reject_code
decl_stmt|;
name|uint8_t
name|na_reserved5
decl_stmt|;
name|uint8_t
name|na_reserved6
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|na_oxid
decl_stmt|;
block|}
name|na_fcentry_24xx_t
typedef|;
end_typedef

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
name|uint16_t
name|at_reserved
decl_stmt|;
name|uint16_t
name|at_handle
decl_stmt|;
name|uint8_t
name|at_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|uint8_t
name|at_cdblen
decl_stmt|;
comment|/* cdb length */
name|uint8_t
name|at_tgt
decl_stmt|;
comment|/* target */
name|uint32_t
name|at_flags
decl_stmt|;
name|uint8_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|uint8_t
name|at_scsi_status
decl_stmt|;
comment|/* scsi status */
name|uint8_t
name|at_tag_val
decl_stmt|;
comment|/* tag value */
name|uint8_t
name|at_tag_type
decl_stmt|;
comment|/* tag type */
name|uint8_t
name|at_cdb
index|[
name|ATIO_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|uint8_t
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
value|0x00000002
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
comment|/*  * Macros to create and fetch and test concatenated handle and tag value macros  */
end_comment

begin_define
define|#
directive|define
name|AT_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|aep
parameter_list|)
define|\
value|tid = aep->at_handle;						\ 	if (aep->at_flags& AT_TQAE) {					\ 		tid |= (aep->at_tag_val<< 16);				\ 		tid |= (1<< 24);					\ 	}								\ 	tid |= (bus<< 25);						\ 	tid |= (inst<< 26)
end_define

begin_define
define|#
directive|define
name|CT_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|ct
parameter_list|)
define|\
value|tid = ct->ct_fwhandle;						\ 	if (ct->ct_flags& CT_TQAE) {					\ 		tid |= (ct->ct_tag_val<< 16);				\ 		tid |= (1<< 24);					\ 	}								\ 	tid |= ((bus& 0x1)<< 25);					\ 	tid |= (inst<< 26)
end_define

begin_define
define|#
directive|define
name|AT_HAS_TAG
parameter_list|(
name|val
parameter_list|)
value|((val)& (1<< 24))
end_define

begin_define
define|#
directive|define
name|AT_GET_TAG
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|AT_GET_INST
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 26)& 0x3f)
end_define

begin_define
define|#
directive|define
name|AT_GET_BUS
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|AT_GET_HANDLE
parameter_list|(
name|val
parameter_list|)
value|((val)& 0xffff)
end_define

begin_define
define|#
directive|define
name|IN_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|inp
parameter_list|)
define|\
value|tid = inp->in_seqid;						\ 	tid |= (inp->in_tag_val<< 16);					\ 	tid |= (1<< 24);						\ 	tid |= (bus<< 25);						\ 	tid |= (inst<< 26)
end_define

begin_define
define|#
directive|define
name|TAG_INSERT_INST
parameter_list|(
name|tid
parameter_list|,
name|inst
parameter_list|)
define|\
value|tid&= ~(0x3ffffff);						\ 	tid |= (inst<< 26)
end_define

begin_define
define|#
directive|define
name|TAG_INSERT_BUS
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|)
define|\
value|tid&= ~(1<< 25);						\ 	tid |= (bus<< 25)
end_define

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
name|uint32_t
name|at_reserved
decl_stmt|;
name|uint8_t
name|at_lun
decl_stmt|;
comment|/* lun or reserved */
name|uint8_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|uint16_t
name|at_rxid
decl_stmt|;
comment|/* response ID */
name|uint16_t
name|at_flags
decl_stmt|;
name|uint16_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|uint8_t
name|at_crn
decl_stmt|;
comment|/* command reference number */
name|uint8_t
name|at_taskcodes
decl_stmt|;
name|uint8_t
name|at_taskflags
decl_stmt|;
name|uint8_t
name|at_execodes
decl_stmt|;
name|uint8_t
name|at_cdb
index|[
name|ATIO2_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|uint32_t
name|at_datalen
decl_stmt|;
comment|/* allocated data len */
name|uint16_t
name|at_scclun
decl_stmt|;
comment|/* SCC Lun or reserved */
name|uint16_t
name|at_wwpn
index|[
literal|4
index|]
decl_stmt|;
comment|/* WWPN of initiator */
name|uint16_t
name|at_reserved2
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|at_oxid
decl_stmt|;
block|}
name|at2_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|at_header
decl_stmt|;
name|uint32_t
name|at_reserved
decl_stmt|;
name|uint16_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|uint16_t
name|at_rxid
decl_stmt|;
comment|/* response ID */
name|uint16_t
name|at_flags
decl_stmt|;
name|uint16_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|uint8_t
name|at_crn
decl_stmt|;
comment|/* command reference number */
name|uint8_t
name|at_taskcodes
decl_stmt|;
name|uint8_t
name|at_taskflags
decl_stmt|;
name|uint8_t
name|at_execodes
decl_stmt|;
name|uint8_t
name|at_cdb
index|[
name|ATIO2_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|uint32_t
name|at_datalen
decl_stmt|;
comment|/* allocated data len */
name|uint16_t
name|at_scclun
decl_stmt|;
comment|/* SCC Lun or reserved */
name|uint16_t
name|at_wwpn
index|[
literal|4
index|]
decl_stmt|;
comment|/* WWPN of initiator */
name|uint16_t
name|at_reserved2
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|at_oxid
decl_stmt|;
block|}
name|at2e_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATIO2_WWPN_OFFSET
value|0x2A
end_define

begin_define
define|#
directive|define
name|ATIO2_OXID_OFFSET
value|0x3E
end_define

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

begin_define
define|#
directive|define
name|ATIO2_EX_WRITE
value|0x1
end_define

begin_define
define|#
directive|define
name|ATIO2_EX_READ
value|0x2
end_define

begin_comment
comment|/*  * Macros to create and fetch and test concatenated handle and tag value macros  */
end_comment

begin_define
define|#
directive|define
name|AT2_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|aep
parameter_list|)
define|\
value|tid = aep->at_rxid;						\ 	tid |= (((uint64_t)inst)<< 32);				\ 	tid |= (((uint64_t)bus)<< 48)
end_define

begin_define
define|#
directive|define
name|CT2_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|ct
parameter_list|)
define|\
value|tid = ct->ct_rxid;						\ 	tid |= (((uint64_t)inst)<< 32);				\ 	tid |= (((uint64_t)(bus& 0xff))<< 48)
end_define

begin_define
define|#
directive|define
name|AT2_HAS_TAG
parameter_list|(
name|val
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|AT2_GET_TAG
parameter_list|(
name|val
parameter_list|)
value|((val)& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|AT2_GET_INST
parameter_list|(
name|val
parameter_list|)
value|((val)>> 32)
end_define

begin_define
define|#
directive|define
name|AT2_GET_HANDLE
value|AT2_GET_TAG
end_define

begin_define
define|#
directive|define
name|AT2_GET_BUS
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 48)& 0xff)
end_define

begin_define
define|#
directive|define
name|FC_HAS_TAG
value|AT2_HAS_TAG
end_define

begin_define
define|#
directive|define
name|FC_GET_TAG
value|AT2_GET_TAG
end_define

begin_define
define|#
directive|define
name|FC_GET_INST
value|AT2_GET_INST
end_define

begin_define
define|#
directive|define
name|FC_GET_HANDLE
value|AT2_GET_HANDLE
end_define

begin_define
define|#
directive|define
name|IN_FC_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|seqid
parameter_list|)
define|\
value|tid = seqid;							\ 	tid |= (((uint64_t)inst)<< 32);				\ 	tid |= (((uint64_t)(bus& 0xff))<< 48)
end_define

begin_define
define|#
directive|define
name|FC_TAG_INSERT_INST
parameter_list|(
name|tid
parameter_list|,
name|inst
parameter_list|)
define|\
value|tid&= ~0xffff00000000ull;					\ 	tid |= (((uint64_t)inst)<< 32)
end_define

begin_comment
comment|/*  * 24XX ATIO Definition  *  * This is *quite* different from other entry types.  * First of all, it has its own queue it comes in on.  *  * Secondly, it doesn't have a normal header.  *  * Thirdly, it's just a passthru of the FCP CMND IU  * which is recorded in big endian mode.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|at_type
decl_stmt|;
name|uint8_t
name|at_count
decl_stmt|;
comment|/* 	 * Task attribute in high four bits, 	 * the rest is the FCP CMND IU Length. 	 * NB: the command can extend past the 	 * length for a single queue entry. 	 */
name|uint16_t
name|at_ta_len
decl_stmt|;
name|uint32_t
name|at_rxid
decl_stmt|;
name|fc_hdr_t
name|at_hdr
decl_stmt|;
name|fcp_cmnd_iu_t
name|at_cmnd
decl_stmt|;
block|}
name|at7_entry_t
typedef|;
end_typedef

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
name|uint16_t
name|ct_syshandle
decl_stmt|;
name|uint16_t
name|ct_fwhandle
decl_stmt|;
comment|/* required by f/w */
name|uint8_t
name|ct_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|uint8_t
name|ct_reserved2
decl_stmt|;
name|uint8_t
name|ct_tgt
decl_stmt|;
comment|/* our target id */
name|uint32_t
name|ct_flags
decl_stmt|;
name|uint8_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|uint8_t
name|ct_scsi_status
decl_stmt|;
comment|/* scsi status */
name|uint8_t
name|ct_tag_val
decl_stmt|;
comment|/* tag value */
name|uint8_t
name|ct_tag_type
decl_stmt|;
comment|/* tag type */
name|uint32_t
name|ct_xfrlen
decl_stmt|;
comment|/* transfer length */
name|uint32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
name|uint16_t
name|ct_timeout
decl_stmt|;
name|uint16_t
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
comment|/*  * For some of the dual port SCSI adapters, port (bus #) is reported  * in the MSbit of ct_iid. Bit fields are a bit too awkward here.  *  * Note that this does not apply to FC adapters at all which can and  * do report IIDs between 0x81&& 0xfe (or 0x7ff) which represent devices  * that have logged in across a SCSI fabric.  */
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
value|y = ((y& ~0x3f) | (x& 0x3f))
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
value|y = ((y& 0x3f) | ((x& 0x1)<< 7))
end_define

begin_comment
comment|/*  * ct_flags values  */
end_comment

begin_define
define|#
directive|define
name|CT_TQAE
value|0x00000002
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
name|CT_INISYNCWIDE
value|0x00004000
end_define

begin_comment
comment|/* bit 14, Do Sync/Wide Negotiation */
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
name|CT_DATA_OVER
value|0x09
end_define

begin_comment
comment|/* (FC only) Data Overrun */
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
name|CT_PARITY
value|0x0F
end_define

begin_comment
comment|/* Uncorrectable Parity Error */
end_comment

begin_define
define|#
directive|define
name|CT_BUS_ERROR
value|0x10
end_define

begin_comment
comment|/* (FC Only) DMA PCI Error */
end_comment

begin_define
define|#
directive|define
name|CT_PANIC
value|0x13
end_define

begin_comment
comment|/* Unrecoverable Error */
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
name|CT_DATA_UNDER
value|0x15
end_define

begin_comment
comment|/* (FC only) Data Underrun */
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
name|CT_PORTUNAVAIL
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
name|CT_IDE
value|0x33
end_define

begin_comment
comment|/* Initiator Detected Error */
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

begin_define
define|#
directive|define
name|CT_SRR
value|0x45
end_define

begin_comment
comment|/* SRR Received */
end_comment

begin_define
define|#
directive|define
name|CT_LUN_RESET
value|0x48
end_define

begin_comment
comment|/* Lun Reset Received */
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
value|(sizeof(at_entry_t)/sizeof(uint32_t))
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
name|uint32_t
name|ct_syshandle
decl_stmt|;
name|uint8_t
name|ct_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|uint16_t
name|ct_rxid
decl_stmt|;
comment|/* response ID */
name|uint16_t
name|ct_flags
decl_stmt|;
name|uint16_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|uint16_t
name|ct_timeout
decl_stmt|;
name|uint16_t
name|ct_seg_count
decl_stmt|;
name|uint32_t
name|ct_reloff
decl_stmt|;
comment|/* relative offset */
name|int32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
union|union
block|{
comment|/* 		 * The three different modes that the target driver 		 * can set the CTIO{2,3,4} up as. 		 * 		 * The first is for sending FCP_DATA_IUs as well as 		 * (optionally) sending a terminal SCSI status FCP_RSP_IU. 		 * 		 * The second is for sending SCSI sense data in an FCP_RSP_IU. 		 * Note that no FCP_DATA_IUs will be sent. 		 * 		 * The third is for sending FCP_RSP_IUs as built specifically 		 * in system memory as located by the isp_dataseg. 		 */
struct|struct
block|{
name|uint32_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
name|uint32_t
name|ct_xfrlen
decl_stmt|;
union|union
block|{
name|ispds_t
name|ct_dataseg
index|[
name|ISP_RQDSEG_T2
index|]
decl_stmt|;
name|ispds64_t
name|ct_dataseg64
index|[
name|ISP_RQDSEG_T3
index|]
decl_stmt|;
name|ispdslist_t
name|ct_dslist
decl_stmt|;
block|}
name|u
union|;
block|}
name|m0
struct|;
struct|struct
block|{
name|uint16_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|ct_senselen
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
name|uint16_t
name|ct_resplen
decl_stmt|;
name|uint8_t
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
name|uint32_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|_reserved3
decl_stmt|;
name|uint32_t
name|ct_datalen
decl_stmt|;
name|ispds_t
name|ct_fcp_rsp_iudata
decl_stmt|;
block|}
name|m2
struct|;
block|}
name|rsp
union|;
block|}
name|ct2_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ct_header
decl_stmt|;
name|uint32_t
name|ct_syshandle
decl_stmt|;
name|uint16_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|uint16_t
name|ct_rxid
decl_stmt|;
comment|/* response ID */
name|uint16_t
name|ct_flags
decl_stmt|;
name|uint16_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|uint16_t
name|ct_timeout
decl_stmt|;
name|uint16_t
name|ct_seg_count
decl_stmt|;
name|uint32_t
name|ct_reloff
decl_stmt|;
comment|/* relative offset */
name|int32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
name|uint32_t
name|ct_xfrlen
decl_stmt|;
union|union
block|{
name|ispds_t
name|ct_dataseg
index|[
name|ISP_RQDSEG_T2
index|]
decl_stmt|;
name|ispds64_t
name|ct_dataseg64
index|[
name|ISP_RQDSEG_T3
index|]
decl_stmt|;
name|ispdslist_t
name|ct_dslist
decl_stmt|;
block|}
name|u
union|;
block|}
name|m0
struct|;
struct|struct
block|{
name|uint16_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|ct_senselen
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
name|uint16_t
name|ct_resplen
decl_stmt|;
name|uint8_t
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
name|uint32_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|_reserved3
decl_stmt|;
name|uint32_t
name|ct_datalen
decl_stmt|;
name|ispds_t
name|ct_fcp_rsp_iudata
decl_stmt|;
block|}
name|m2
struct|;
block|}
name|rsp
union|;
block|}
name|ct2e_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * ct_flags values for CTIO2  */
end_comment

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
name|CT2_FLAG_MMASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|CT2_DATA_IN
value|0x0040
end_define

begin_define
define|#
directive|define
name|CT2_DATA_OUT
value|0x0080
end_define

begin_define
define|#
directive|define
name|CT2_NO_DATA
value|0x00C0
end_define

begin_define
define|#
directive|define
name|CT2_DATAMASK
value|0x00C0
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
name|CT2_CONFIRM
value|0x2000
end_define

begin_define
define|#
directive|define
name|CT2_TERMINATE
value|0x4000
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
comment|/*  * ISP24XX CTIO  */
end_comment

begin_define
define|#
directive|define
name|MAXRESPLEN_24XX
value|24
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ct_header
decl_stmt|;
name|uint32_t
name|ct_syshandle
decl_stmt|;
name|uint16_t
name|ct_nphdl
decl_stmt|;
comment|/* status on returned CTIOs */
name|uint16_t
name|ct_timeout
decl_stmt|;
name|uint16_t
name|ct_seg_count
decl_stmt|;
name|uint8_t
name|ct_vpindex
decl_stmt|;
name|uint8_t
name|ct_xflags
decl_stmt|;
name|uint16_t
name|ct_iid_lo
decl_stmt|;
comment|/* low 16 bits of portid */
name|uint8_t
name|ct_iid_hi
decl_stmt|;
comment|/* hi 8 bits of portid */
name|uint8_t
name|ct_reserved
decl_stmt|;
name|uint32_t
name|ct_rxid
decl_stmt|;
name|uint16_t
name|ct_senselen
decl_stmt|;
comment|/* mode 0 only */
name|uint16_t
name|ct_flags
decl_stmt|;
name|int32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
name|uint16_t
name|ct_oxid
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
comment|/* modes 0&& 1 only */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|reloff
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
name|uint32_t
name|ct_xfrlen
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|ispds64_t
name|ds
decl_stmt|;
block|}
name|m0
struct|;
struct|struct
block|{
name|uint16_t
name|ct_resplen
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|ct_resp
index|[
name|MAXRESPLEN_24XX
index|]
decl_stmt|;
block|}
name|m1
struct|;
struct|struct
block|{
name|uint32_t
name|reserved0
decl_stmt|;
name|uint32_t
name|ct_datalen
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|ispds64_t
name|ct_fcp_rsp_iudata
decl_stmt|;
block|}
name|m2
struct|;
block|}
name|rsp
union|;
block|}
name|ct7_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * ct_flags values for CTIO7  */
end_comment

begin_define
define|#
directive|define
name|CT7_DATA_IN
value|0x0002
end_define

begin_define
define|#
directive|define
name|CT7_DATA_OUT
value|0x0001
end_define

begin_define
define|#
directive|define
name|CT7_NO_DATA
value|0x0000
end_define

begin_define
define|#
directive|define
name|CT7_DATAMASK
value|0x003
end_define

begin_define
define|#
directive|define
name|CT7_DSD_ENABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|CT7_CONF_STSFD
value|0x0010
end_define

begin_define
define|#
directive|define
name|CT7_EXPLCT_CONF
value|0x0020
end_define

begin_define
define|#
directive|define
name|CT7_FLAG_MODE0
value|0x0000
end_define

begin_define
define|#
directive|define
name|CT7_FLAG_MODE1
value|0x0040
end_define

begin_define
define|#
directive|define
name|CT7_FLAG_MODE7
value|0x0080
end_define

begin_define
define|#
directive|define
name|CT7_FLAG_MMASK
value|0x00C0
end_define

begin_define
define|#
directive|define
name|CT7_FASTPOST
value|0x0100
end_define

begin_define
define|#
directive|define
name|CT7_ATTR_MASK
value|0x1e00
end_define

begin_comment
comment|/* task attributes from atio7 */
end_comment

begin_define
define|#
directive|define
name|CT7_CONFIRM
value|0x2000
end_define

begin_define
define|#
directive|define
name|CT7_TERMINATE
value|0x4000
end_define

begin_define
define|#
directive|define
name|CT7_SENDSTATUS
value|0x8000
end_define

begin_comment
comment|/*  * Type 7 CTIO status codes  */
end_comment

begin_define
define|#
directive|define
name|CT7_OK
value|0x01
end_define

begin_comment
comment|/* completed without error */
end_comment

begin_define
define|#
directive|define
name|CT7_ABORTED
value|0x02
end_define

begin_comment
comment|/* aborted by host */
end_comment

begin_define
define|#
directive|define
name|CT7_ERR
value|0x04
end_define

begin_comment
comment|/* see sense data for error */
end_comment

begin_define
define|#
directive|define
name|CT7_INVAL
value|0x06
end_define

begin_comment
comment|/* request for disabled lun */
end_comment

begin_define
define|#
directive|define
name|CT7_INVRXID
value|0x08
end_define

begin_comment
comment|/* (FC only) Invalid RX_ID */
end_comment

begin_define
define|#
directive|define
name|CT7_DATA_OVER
value|0x09
end_define

begin_comment
comment|/* (FC only) Data Overrun */
end_comment

begin_define
define|#
directive|define
name|CT7_TIMEOUT
value|0x0B
end_define

begin_comment
comment|/* timed out */
end_comment

begin_define
define|#
directive|define
name|CT7_RESET
value|0x0E
end_define

begin_comment
comment|/* LIP Rset Received */
end_comment

begin_define
define|#
directive|define
name|CT7_BUS_ERROR
value|0x10
end_define

begin_comment
comment|/* DMA PCI Error */
end_comment

begin_define
define|#
directive|define
name|CT7_REASSY_ERR
value|0x11
end_define

begin_comment
comment|/* DMA reassembly error */
end_comment

begin_define
define|#
directive|define
name|CT7_DATA_UNDER
value|0x15
end_define

begin_comment
comment|/* (FC only) Data Underrun */
end_comment

begin_define
define|#
directive|define
name|CT7_PORTUNAVAIL
value|0x28
end_define

begin_comment
comment|/* port not available */
end_comment

begin_define
define|#
directive|define
name|CT7_LOGOUT
value|0x29
end_define

begin_comment
comment|/* port logout */
end_comment

begin_define
define|#
directive|define
name|CT7_PORTCHANGED
value|0x2A
end_define

begin_comment
comment|/* port changed */
end_comment

begin_define
define|#
directive|define
name|CT7_SRR
value|0x45
end_define

begin_comment
comment|/* SRR Received */
end_comment

begin_comment
comment|/*  * Other 24XX related target IOCBs  */
end_comment

begin_comment
comment|/*  * ABTS Received  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|abts_header
decl_stmt|;
name|uint8_t
name|abts_reserved0
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|abts_nphdl
decl_stmt|;
name|uint16_t
name|abts_reserved1
decl_stmt|;
name|uint16_t
name|abts_sof
decl_stmt|;
name|uint32_t
name|abts_rxid_abts
decl_stmt|;
name|uint16_t
name|abts_did_lo
decl_stmt|;
name|uint8_t
name|abts_did_hi
decl_stmt|;
name|uint8_t
name|abts_r_ctl
decl_stmt|;
name|uint16_t
name|abts_sid_lo
decl_stmt|;
name|uint8_t
name|abts_sid_hi
decl_stmt|;
name|uint8_t
name|abts_cs_ctl
decl_stmt|;
name|uint16_t
name|abts_fs_ctl
decl_stmt|;
name|uint8_t
name|abts_f_ctl
decl_stmt|;
name|uint8_t
name|abts_type
decl_stmt|;
name|uint16_t
name|abts_seq_cnt
decl_stmt|;
name|uint8_t
name|abts_df_ctl
decl_stmt|;
name|uint8_t
name|abts_seq_id
decl_stmt|;
name|uint16_t
name|abts_rx_id
decl_stmt|;
name|uint16_t
name|abts_ox_id
decl_stmt|;
name|uint32_t
name|abts_param
decl_stmt|;
name|uint8_t
name|abts_reserved2
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|abts_rxid_task
decl_stmt|;
block|}
name|abts_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|abts_rsp_header
decl_stmt|;
name|uint32_t
name|abts_rsp_handle
decl_stmt|;
name|uint16_t
name|abts_rsp_status
decl_stmt|;
name|uint16_t
name|abts_rsp_nphdl
decl_stmt|;
name|uint16_t
name|abts_rsp_ctl_flags
decl_stmt|;
name|uint16_t
name|abts_rsp_sof
decl_stmt|;
name|uint32_t
name|abts_rsp_rxid_abts
decl_stmt|;
name|uint16_t
name|abts_rsp_did_lo
decl_stmt|;
name|uint8_t
name|abts_rsp_did_hi
decl_stmt|;
name|uint8_t
name|abts_rsp_r_ctl
decl_stmt|;
name|uint16_t
name|abts_rsp_sid_lo
decl_stmt|;
name|uint8_t
name|abts_rsp_sid_hi
decl_stmt|;
name|uint8_t
name|abts_rsp_cs_ctl
decl_stmt|;
name|uint16_t
name|abts_rsp_f_ctl_lo
decl_stmt|;
name|uint8_t
name|abts_rsp_f_ctl_hi
decl_stmt|;
name|uint8_t
name|abts_rsp_type
decl_stmt|;
name|uint16_t
name|abts_rsp_seq_cnt
decl_stmt|;
name|uint8_t
name|abts_rsp_df_ctl
decl_stmt|;
name|uint8_t
name|abts_rsp_seq_id
decl_stmt|;
name|uint16_t
name|abts_rsp_rx_id
decl_stmt|;
name|uint16_t
name|abts_rsp_ox_id
decl_stmt|;
name|uint32_t
name|abts_rsp_param
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|last_seq_id
decl_stmt|;
name|uint8_t
name|seq_id_valid
decl_stmt|;
name|uint16_t
name|aborted_rx_id
decl_stmt|;
name|uint16_t
name|aborted_ox_id
decl_stmt|;
name|uint16_t
name|high_seq_cnt
decl_stmt|;
name|uint16_t
name|low_seq_cnt
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|4
index|]
decl_stmt|;
block|}
name|ba_acc
struct|;
struct|struct
block|{
name|uint8_t
name|vendor_unique
decl_stmt|;
name|uint8_t
name|explanation
decl_stmt|;
name|uint8_t
name|reason
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|12
index|]
decl_stmt|;
block|}
name|ba_rjt
struct|;
struct|struct
block|{
name|uint8_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|subcode1
decl_stmt|;
name|uint32_t
name|subcode2
decl_stmt|;
block|}
name|rsp
struct|;
name|uint8_t
name|reserved
index|[
literal|16
index|]
decl_stmt|;
block|}
name|abts_rsp_payload
union|;
name|uint32_t
name|abts_rsp_rxid_task
decl_stmt|;
block|}
name|abts_rsp_t
typedef|;
end_typedef

begin_comment
comment|/* terminate this ABTS exchange */
end_comment

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_TERMINATE
value|0x01
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_COMPLETE
value|0x00
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_RESET
value|0x04
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_ABORTED
value|0x05
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_TIMEOUT
value|0x06
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_INVXID
value|0x08
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_LOGOUT
value|0x29
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_SUBCODE
value|0x31
end_define

begin_comment
comment|/*  * Debug macros  */
end_comment

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
value|if (isp->isp_dblev& ISP_LOGTDEBUG2) isp_print_qentry(isp, msg, idx, arg)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ISP_TOOLS
end_ifndef

begin_comment
comment|/*  * The functions below are for the publicly available  * target mode functions that are internal to the Qlogic driver.  */
end_comment

begin_comment
comment|/*  * This function handles new response queue entry appropriate for target mode.  */
end_comment

begin_function_decl
name|int
name|isp_target_notify
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function externalizes the ability to acknowledge an Immediate Notify  * request.  */
end_comment

begin_function_decl
name|void
name|isp_notify_ack
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable/Disable/Modify a logical unit.  * (softc, cmd, bus, tgt, lun, cmd_cnt, inotify_cnt, opaque)  */
end_comment

begin_define
define|#
directive|define
name|DFLT_CMND_CNT
value|0xfe
end_define

begin_comment
comment|/* unmonitored */
end_comment

begin_define
define|#
directive|define
name|DFLT_INOT_CNT
value|0xfe
end_define

begin_comment
comment|/* unmonitored */
end_comment

begin_function_decl
name|int
name|isp_lun_cmd
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * General request queue 'put' routine for target mode entries.  */
end_comment

begin_function_decl
name|int
name|isp_target_put_entry
parameter_list|(
name|ispsoftc_t
modifier|*
name|isp
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * General routine to put back an ATIO entry-  * used for replenishing f/w resource counts.  * The argument is a pointer to a source ATIO  * or ATIO2.  */
end_comment

begin_function_decl
name|int
name|isp_target_put_atio
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * General routine to send a final CTIO for a command- used mostly for  * local responses.  */
end_comment

begin_function_decl
name|int
name|isp_endcmd
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ECMD_SVALID
value|0x100
end_define

begin_comment
comment|/*  * Handle an asynchronous event  *  * Return nonzero if the interrupt that generated this event has been dismissed.  */
end_comment

begin_function_decl
name|int
name|isp_target_async
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISP_TARGET_H */
end_comment

end_unit

