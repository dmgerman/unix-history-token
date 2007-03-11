begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Mailbox and Queue Entry Definitions for for Qlogic ISP SCSI adapters.  *  * Copyright (c) 1997-2006 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * Structures that derive directly from public standards.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISP_STDS_H
end_ifndef

begin_define
define|#
directive|define
name|_ISP_STDS_H
end_define

begin_comment
comment|/*  * FC Frame Header  *  * Source: dpANS-X3.xxx-199x, section 18 (AKA FC-PH-2)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|r_ctl
decl_stmt|;
name|uint8_t
name|d_id
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|cs_ctl
decl_stmt|;
name|uint8_t
name|s_id
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|f_ctl
decl_stmt|;
name|uint8_t
name|seq_id
decl_stmt|;
name|uint8_t
name|df_ctl
decl_stmt|;
name|uint16_t
name|seq_cnt
decl_stmt|;
name|uint16_t
name|ox_id
decl_stmt|;
name|uint16_t
name|rx_id
decl_stmt|;
name|uint32_t
name|parameter
decl_stmt|;
block|}
name|fc_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * FCP_CMND_IU Payload  *  * Source: NICTS T10, Project 1144D, Revision 07a, Section 9 (AKA fcp2-r07a)  *  * Notes:  *	When additional cdb length is defined in fcp_cmnd_alen_datadir,  * 	bits 2..7, the actual cdb length is 16 + ((fcp_cmnd_alen_datadir>>2)*4),  *	with the datalength following in MSB format just after.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|fcp_cmnd_lun
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|fcp_cmnd_crn
decl_stmt|;
name|uint8_t
name|fcp_cmnd_task_attribute
decl_stmt|;
name|uint8_t
name|fcp_cmnd_task_management
decl_stmt|;
name|uint8_t
name|fcp_cmnd_alen_datadir
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|fcp_cmnd_cdb
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|fcp_cmnd_dl
decl_stmt|;
block|}
name|sf
struct|;
struct|struct
block|{
name|uint8_t
name|fcp_cmnd_cdb
index|[
literal|1
index|]
decl_stmt|;
block|}
name|lf
struct|;
block|}
name|cdb_dl
union|;
block|}
name|fcp_cmnd_iu_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FCP_CMND_TASK_ATTR_SIMPLE
value|0x00
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TASK_ATTR_HEAD
value|0x01
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TASK_ATTR_ORDERED
value|0x02
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TASK_ATTR_ACA
value|0x04
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TASK_ATTR_UNTAGGED
value|0x05
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TASK_ATTR_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|FCP_CMND_ADDTL_CDBLEN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|FCP_CMND_DATA_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|FCP_CMND_DATA_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|FCP_CMND_DATA_DIR_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TMF_CLEAR_ACA
value|0x40
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TMF_TGT_RESET
value|0x20
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TMF_LUN_RESET
value|0x10
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TMF_CLEAR_TASK_SET
value|0x04
end_define

begin_define
define|#
directive|define
name|FCP_CMND_TMF_ABORT_TASK_SET
value|0x02
end_define

begin_comment
comment|/*  * Basic CT IU Header  *  * Source: X3.288-199x Generic Services 2 Rev 5.3 (FC-GS-2) Section 4.3.1  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|ct_revision
decl_stmt|;
name|uint8_t
name|ct_in_id
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|ct_fcs_type
decl_stmt|;
name|uint8_t
name|ct_fcs_subtype
decl_stmt|;
name|uint8_t
name|ct_options
decl_stmt|;
name|uint8_t
name|ct_reserved0
decl_stmt|;
name|uint16_t
name|ct_cmd_resp
decl_stmt|;
name|uint16_t
name|ct_bcnt_resid
decl_stmt|;
name|uint8_t
name|ct_reserved1
decl_stmt|;
name|uint8_t
name|ct_reason
decl_stmt|;
name|uint8_t
name|ct_explanation
decl_stmt|;
name|uint8_t
name|ct_vunique
decl_stmt|;
block|}
name|ct_hdr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CT_REVISION
value|1
end_define

begin_define
define|#
directive|define
name|CT_FC_TYPE_FC
value|0xFC
end_define

begin_define
define|#
directive|define
name|CT_FC_SUBTYPE_NS
value|0x02
end_define

begin_comment
comment|/*  * RFT_ID Requet CT_IU  *  * Source: NCITS xxx-200x Generic Services- 5 Rev 8.5 Section 5.2.5.30  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ct_hdr_t
name|rftid_hdr
decl_stmt|;
name|uint8_t
name|rftid_reserved
decl_stmt|;
name|uint8_t
name|rftid_portid
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|rftid_fc4types
index|[
literal|8
index|]
decl_stmt|;
block|}
name|rft_id_t
typedef|;
end_typedef

begin_comment
comment|/*  * FCP Response Code Definitions  * Source: NCITS T10, Project 1144D, Revision 07a (aka FCP2r07a)  */
end_comment

begin_define
define|#
directive|define
name|FCP_RSPNS_CODE_OFFSET
value|3
end_define

begin_define
define|#
directive|define
name|FCP_RSPNS_TMF_DONE
value|0
end_define

begin_define
define|#
directive|define
name|FCP_RSPNS_DLBRSTX
value|1
end_define

begin_define
define|#
directive|define
name|FCP_RSPNS_BADCMND
value|2
end_define

begin_define
define|#
directive|define
name|FCP_RSPNS_EROFS
value|3
end_define

begin_define
define|#
directive|define
name|FCP_RSPNS_TMF_REJECT
value|4
end_define

begin_define
define|#
directive|define
name|FCP_RSPNS_TMF_FAILED
value|5
end_define

begin_comment
comment|/* unconverted miscellany */
end_comment

begin_comment
comment|/*  * Basic FC Link Service defines  */
end_comment

begin_comment
comment|/*  * These are in the R_CTL field.  */
end_comment

begin_define
define|#
directive|define
name|ABTS
value|0x81
end_define

begin_define
define|#
directive|define
name|BA_ACC
value|0x84
end_define

begin_comment
comment|/* of ABORT SEQUENCE */
end_comment

begin_define
define|#
directive|define
name|BA_RJT
value|0x85
end_define

begin_comment
comment|/* of ABORT SEQUENCE */
end_comment

begin_comment
comment|/*  * Link Service Accept/Reject  */
end_comment

begin_define
define|#
directive|define
name|LS_ACC
value|0x8002
end_define

begin_define
define|#
directive|define
name|LS_RJT
value|0x8001
end_define

begin_comment
comment|/*  * FC ELS Codes- bits 31-24 of the first payload word of an ELS frame.  */
end_comment

begin_define
define|#
directive|define
name|PLOGI
value|0x03
end_define

begin_define
define|#
directive|define
name|FLOGI
value|0x04
end_define

begin_define
define|#
directive|define
name|LOGO
value|0x05
end_define

begin_define
define|#
directive|define
name|ABTX
value|0x06
end_define

begin_define
define|#
directive|define
name|PRLI
value|0x20
end_define

begin_define
define|#
directive|define
name|PRLO
value|0x21
end_define

begin_define
define|#
directive|define
name|TPRLO
value|0x24
end_define

begin_define
define|#
directive|define
name|RNC
value|0x53
end_define

begin_comment
comment|/*  * FC4 defines  */
end_comment

begin_define
define|#
directive|define
name|FC4_IP
value|5
end_define

begin_comment
comment|/* ISO/EEC 8802-2 LLC/SNAP */
end_comment

begin_define
define|#
directive|define
name|FC4_SCSI
value|8
end_define

begin_comment
comment|/* SCSI-3 via Fibre Channel Protocol (FCP) */
end_comment

begin_define
define|#
directive|define
name|FC4_FC_SVC
value|0x20
end_define

begin_comment
comment|/* Fibre Channel Services */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_ABORT
end_ifndef

begin_define
define|#
directive|define
name|MSG_ABORT
value|0x06
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
value|0x0c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_ABORT_TAG
end_ifndef

begin_define
define|#
directive|define
name|MSG_ABORT_TAG
value|0x0d
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

begin_ifndef
ifndef|#
directive|ifndef
name|MSG_LUN_RESET
end_ifndef

begin_define
define|#
directive|define
name|MSG_LUN_RESET
value|0x17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISP_STDS_H */
end_comment

end_unit

