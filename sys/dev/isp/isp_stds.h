begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  *  Copyright (c) 1997-2009 by Matthew Jacob  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *   *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *   *  THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *  SUCH DAMAGE.  *   */
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
index|[
literal|3
index|]
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
name|FCP_CMND_TMF_QUERY_ASYNC_EVENT
value|0x08
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

begin_define
define|#
directive|define
name|FCP_CMND_TMF_QUERY_TASK_SET
value|0x01
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
comment|/*  * RFF_ID Requet CT_IU  *  * Source: INCITS 463-2010 Generic Services 6 Section 5.2.5.34  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ct_hdr_t
name|rffid_hdr
decl_stmt|;
name|uint8_t
name|rffid_reserved
decl_stmt|;
name|uint8_t
name|rffid_portid
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|rffid_reserved2
decl_stmt|;
name|uint8_t
name|rffid_fc4features
decl_stmt|;
name|uint8_t
name|rffid_fc4type
decl_stmt|;
block|}
name|rff_id_t
typedef|;
end_typedef

begin_comment
comment|/*  * FCP Response IU and bits of interest  * Source: NCITS T10, Project 1828D, Revision 02b (aka FCP4r02b)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|fcp_rsp_reserved
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|fcp_rsp_status_qualifier
decl_stmt|;
comment|/* SAM-5 Status Qualifier */
name|uint8_t
name|fcp_rsp_bits
decl_stmt|;
name|uint8_t
name|fcp_rsp_scsi_status
decl_stmt|;
comment|/* SAM-5 SCSI Status Byte */
name|uint32_t
name|fcp_rsp_resid
decl_stmt|;
name|uint32_t
name|fcp_rsp_snslen
decl_stmt|;
name|uint32_t
name|fcp_rsp_rsplen
decl_stmt|;
comment|/* 	 * In the bytes that follow, it's going to be 	 * FCP RESPONSE INFO (max 8 bytes, possibly 0) 	 * FCP SENSE INFO (if any) 	 * FCP BIDIRECTIONAL READ RESID (if any) 	 */
name|uint8_t
name|fcp_rsp_extra
index|[
literal|0
index|]
decl_stmt|;
block|}
name|fcp_rsp_iu_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MIN_FCP_RESPONSE_SIZE
value|24
end_define

begin_define
define|#
directive|define
name|FCP_BIDIR_RSP
value|0x80
end_define

begin_comment
comment|/* Bi-Directional response */
end_comment

begin_define
define|#
directive|define
name|FCP_BIDIR_RESID_UNDERFLOW
value|0x40
end_define

begin_define
define|#
directive|define
name|FCP_BIDIR_RESID_OVERFLOW
value|0x20
end_define

begin_define
define|#
directive|define
name|FCP_CONF_REQ
value|0x10
end_define

begin_define
define|#
directive|define
name|FCP_RESID_UNDERFLOW
value|0x08
end_define

begin_define
define|#
directive|define
name|FCP_RESID_OVERFLOW
value|0x04
end_define

begin_define
define|#
directive|define
name|FCP_SNSLEN_VALID
value|0x02
end_define

begin_define
define|#
directive|define
name|FCP_RSPLEN_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|FCP_MAX_RSPLEN
value|0x08
end_define

begin_comment
comment|/*  * FCP Response Code Definitions  * Source: NCITS T10, Project 1144D, Revision 08 (aka FCP2r08)  */
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

begin_define
define|#
directive|define
name|FCP_RSPNS_TMF_SUCCEEDED
value|8
end_define

begin_define
define|#
directive|define
name|FCP_RSPNS_TMF_INCORRECT_LUN
value|9
end_define

begin_comment
comment|/*  * R_CTL field definitions  *  * Bits 31-28 are ROUTING  * Bits 27-24 are INFORMATION  *  * These are nibble values, not bits  */
end_comment

begin_define
define|#
directive|define
name|R_CTL_ROUTE_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|R_CTL_ROUTE_ELS
value|0x02
end_define

begin_define
define|#
directive|define
name|R_CTL_ROUTE_FC4_LINK
value|0x03
end_define

begin_define
define|#
directive|define
name|R_CTL_ROUTE_VDATA
value|0x04
end_define

begin_define
define|#
directive|define
name|R_CTL_ROUTE_EXENDED
value|0x05
end_define

begin_define
define|#
directive|define
name|R_CTL_ROUTE_BASIC
value|0x08
end_define

begin_define
define|#
directive|define
name|R_CTL_ROUTE_LINK
value|0x0c
end_define

begin_define
define|#
directive|define
name|R_CTL_ROUTE_EXT_ROUTING
value|0x0f
end_define

begin_define
define|#
directive|define
name|R_CTL_INFO_UNCATEGORIZED
value|0x00
end_define

begin_define
define|#
directive|define
name|R_CTL_INFO_SOLICITED_DATA
value|0x01
end_define

begin_define
define|#
directive|define
name|R_CTL_INFO_UNSOLICITED_CONTROL
value|0x02
end_define

begin_define
define|#
directive|define
name|R_CTL_INFO_SOLICITED_CONTROL
value|0x03
end_define

begin_define
define|#
directive|define
name|R_CTL_INFO_UNSOLICITED_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|R_CTL_INFO_DATA_DESCRIPTOR
value|0x05
end_define

begin_define
define|#
directive|define
name|R_CTL_INFO_UNSOLICITED_COMMAND
value|0x06
end_define

begin_define
define|#
directive|define
name|R_CTL_INFO_COMMAND_STATUS
value|0x07
end_define

begin_define
define|#
directive|define
name|MAKE_RCTL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<< 4) | (b))
end_define

begin_comment
comment|/* unconverted miscellany */
end_comment

begin_comment
comment|/*  * Basic FC Link Service defines  */
end_comment

begin_comment
comment|/* #define	ABTS	MAKE_RCTL(R_CTL_ROUTE_BASIC, R_CTL_INFO_SOLICITED_DATA) */
end_comment

begin_define
define|#
directive|define
name|BA_ACC
value|MAKE_RCTL(R_CTL_ROUTE_BASIC, R_CTL_INFO_UNSOLICITED_DATA)
end_define

begin_comment
comment|/* of ABORT */
end_comment

begin_define
define|#
directive|define
name|BA_RJT
value|MAKE_RCTL(R_CTL_ROUTE_BASIC, R_CTL_INFO_DATA_DESCRIPTOR)
end_define

begin_comment
comment|/* of ABORT */
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
name|SCN
value|0x22
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
name|PDISC
value|0x50
end_define

begin_define
define|#
directive|define
name|ADISC
value|0x52
end_define

begin_define
define|#
directive|define
name|RNC
value|0x53
end_define

begin_comment
comment|/*  * PRLI Word 3 definitions  * FPC4-r02b January, 2011  */
end_comment

begin_define
define|#
directive|define
name|PRLI_WD3_ENHANCED_DISCOVERY
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PRLI_WD3_REC_SUPPORT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PRLI_WD3_TASK_RETRY_IDENTIFICATION_REQUESTED
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PRLI_WD3_RETRY
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PRLI_WD3_CONFIRMED_COMPLETION_ALLOWED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PRLI_WD3_DATA_OVERLAY_ALLOWED
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PRLI_WD3_INITIATOR_FUNCTION
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PRLI_WD3_TARGET_FUNCTION
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PRLI_WD3_READ_FCP_XFER_RDY_DISABLED
value|(1<< 1)
end_define

begin_comment
comment|/* definitely supposed to be set */
end_comment

begin_define
define|#
directive|define
name|PRLI_WD3_WRITE_FCP_XFER_RDY_DISABLED
value|(1<< 0)
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

