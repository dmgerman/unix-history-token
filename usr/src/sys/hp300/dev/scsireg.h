begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson of Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)scsireg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * HP 98265A SCSI Interface Hardware Description.  */
end_comment

begin_struct
struct|struct
name|scsidevice
block|{
name|u_char
name|p0
decl_stmt|,
name|scsi_id
decl_stmt|;
define|#
directive|define
name|ID_MASK
value|0x1f
define|#
directive|define
name|SCSI_ID
value|0x07
define|#
directive|define
name|ID_WORD_DMA
value|0x20
name|u_char
name|p2
decl_stmt|,
name|scsi_csr
decl_stmt|;
define|#
directive|define
name|CSR_IE
value|0x80
define|#
directive|define
name|CSR_IR
value|0x40
define|#
directive|define
name|SCSI_IPL
parameter_list|(
name|csr
parameter_list|)
value|((((csr)>>4)&3)+3)
define|#
directive|define
name|CSR_DMA32
value|0x08
define|#
directive|define
name|CSR_DMAIN
value|0x04
define|#
directive|define
name|CSR_DE1
value|0x02
define|#
directive|define
name|CSR_DE0
value|0x01
name|u_char
name|p4
decl_stmt|,
name|scsi_wrap
decl_stmt|;
define|#
directive|define
name|WRAP_REQ
value|0x80
define|#
directive|define
name|WRAP_ACK
value|0x40
define|#
directive|define
name|WRAP_BSY
value|0x08
define|#
directive|define
name|WRAP_MSG
value|0x04
define|#
directive|define
name|WRAP_CD
value|0x02
define|#
directive|define
name|WRAP_IO
value|0x01
name|u_char
name|p6
decl_stmt|,
name|scsi_hconf
decl_stmt|;
define|#
directive|define
name|HCONF_TP
value|0x80
define|#
directive|define
name|SCSI_SYNC_XFER
parameter_list|(
name|hconf
parameter_list|)
value|(((hconf)>>5)&3)
define|#
directive|define
name|HCONF_SD
value|0x10
define|#
directive|define
name|HCONF_PARITY
value|0x08
name|u_char
name|p8
index|[
literal|24
index|]
decl_stmt|;
name|u_char
name|p32
decl_stmt|,
name|scsi_bdid
decl_stmt|;
name|u_char
name|p34
decl_stmt|,
name|scsi_sctl
decl_stmt|;
define|#
directive|define
name|SCTL_DISABLE
value|0x80
define|#
directive|define
name|SCTL_CTRLRST
value|0x40
define|#
directive|define
name|SCTL_DIAG
value|0x20
define|#
directive|define
name|SCTL_ABRT_ENAB
value|0x10
define|#
directive|define
name|SCTL_PARITY_ENAB
value|0x08
define|#
directive|define
name|SCTL_SEL_ENAB
value|0x04
define|#
directive|define
name|SCTL_RESEL_ENAB
value|0x02
define|#
directive|define
name|SCTL_INTR_ENAB
value|0x01
name|u_char
name|p36
decl_stmt|,
name|scsi_scmd
decl_stmt|;
define|#
directive|define
name|SCMD_RST
value|0x10
define|#
directive|define
name|SCMD_ICPT_XFR
value|0x08
define|#
directive|define
name|SCMD_PROG_XFR
value|0x04
define|#
directive|define
name|SCMD_PAD
value|0x01
comment|/* if initiator */
define|#
directive|define
name|SCMD_PERR_STOP
value|0x01
comment|/* if target */
comment|/* command codes */
define|#
directive|define
name|SCMD_BUS_REL
value|0x00
define|#
directive|define
name|SCMD_SELECT
value|0x20
define|#
directive|define
name|SCMD_RST_ATN
value|0x40
define|#
directive|define
name|SCMD_SET_ATN
value|0x60
define|#
directive|define
name|SCMD_XFR
value|0x80
define|#
directive|define
name|SCMD_XFR_PAUSE
value|0xa0
define|#
directive|define
name|SCMD_RST_ACK
value|0xc0
define|#
directive|define
name|SCMD_SET_ACK
value|0xe0
name|u_char
name|p38
decl_stmt|,
name|scsi_tmod
decl_stmt|;
define|#
directive|define
name|TMOD_SYNC
value|0x80
name|u_char
name|p40
decl_stmt|,
name|scsi_ints
decl_stmt|;
define|#
directive|define
name|INTS_SEL
value|0x80
define|#
directive|define
name|INTS_RESEL
value|0x40
define|#
directive|define
name|INTS_DISCON
value|0x20
define|#
directive|define
name|INTS_CMD_DONE
value|0x10
define|#
directive|define
name|INTS_SRV_REQ
value|0x08
define|#
directive|define
name|INTS_TIMEOUT
value|0x04
define|#
directive|define
name|INTS_HARD_ERR
value|0x02
define|#
directive|define
name|INTS_RST
value|0x01
name|u_char
name|p42
decl_stmt|,
name|scsi_psns
decl_stmt|;
define|#
directive|define
name|PSNS_REQ
value|0x80
define|#
directive|define
name|PSNS_ACK
value|0x40
define|#
directive|define
name|PSNS_ATN
value|0x20
define|#
directive|define
name|PSNS_SEL
value|0x10
define|#
directive|define
name|PSNS_BSY
value|0x08
name|u_char
name|p44
decl_stmt|,
name|scsi_ssts
decl_stmt|;
define|#
directive|define
name|SSTS_INITIATOR
value|0x80
define|#
directive|define
name|SSTS_TARGET
value|0x40
define|#
directive|define
name|SSTS_BUSY
value|0x20
define|#
directive|define
name|SSTS_XFR
value|0x10
define|#
directive|define
name|SSTS_ACTIVE
value|(SSTS_INITIATOR|SSTS_XFR)
define|#
directive|define
name|SSTS_RST
value|0x08
define|#
directive|define
name|SSTS_TCZERO
value|0x04
define|#
directive|define
name|SSTS_DREG_FULL
value|0x02
define|#
directive|define
name|SSTS_DREG_EMPTY
value|0x01
name|u_char
name|p46
decl_stmt|,
name|scsi_serr
decl_stmt|;
define|#
directive|define
name|SERR_SCSI_PAR
value|0x80
define|#
directive|define
name|SERR_SPC_PAR
value|0x40
define|#
directive|define
name|SERR_TC_PAR
value|0x08
define|#
directive|define
name|SERR_PHASE_ERR
value|0x04
define|#
directive|define
name|SERR_SHORT_XFR
value|0x02
define|#
directive|define
name|SERR_OFFSET
value|0x01
name|u_char
name|p48
decl_stmt|,
name|scsi_pctl
decl_stmt|;
define|#
directive|define
name|PCTL_BFINT_ENAB
value|0x80
name|u_char
name|p50
decl_stmt|,
name|scsi_mbc
decl_stmt|;
name|u_char
name|p52
decl_stmt|,
name|scsi_dreg
decl_stmt|;
name|u_char
name|p54
decl_stmt|,
name|scsi_temp
decl_stmt|;
name|u_char
name|p56
decl_stmt|,
name|scsi_tch
decl_stmt|;
name|u_char
name|p58
decl_stmt|,
name|scsi_tcm
decl_stmt|;
name|u_char
name|p60
decl_stmt|,
name|scsi_tcl
decl_stmt|;
name|u_char
name|p62
decl_stmt|,
name|scsi_exbf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* psns/pctl phase lines as bits */
end_comment

begin_define
define|#
directive|define
name|PHASE_MSG
value|0x04
end_define

begin_define
define|#
directive|define
name|PHASE_CD
value|0x02
end_define

begin_comment
comment|/* =1 if 'command' */
end_comment

begin_define
define|#
directive|define
name|PHASE_IO
value|0x01
end_define

begin_comment
comment|/* =1 if data inbound */
end_comment

begin_comment
comment|/* Phase lines as values */
end_comment

begin_define
define|#
directive|define
name|PHASE
value|0x07
end_define

begin_comment
comment|/* mask for psns/pctl phase */
end_comment

begin_define
define|#
directive|define
name|DATA_OUT_PHASE
value|0x00
end_define

begin_define
define|#
directive|define
name|DATA_IN_PHASE
value|0x01
end_define

begin_define
define|#
directive|define
name|CMD_PHASE
value|0x02
end_define

begin_define
define|#
directive|define
name|STATUS_PHASE
value|0x03
end_define

begin_define
define|#
directive|define
name|BUS_FREE_PHASE
value|0x04
end_define

begin_define
define|#
directive|define
name|ARB_SEL_PHASE
value|0x05
end_define

begin_comment
comment|/* Fuji chip combines arbitration with sel. */
end_comment

begin_define
define|#
directive|define
name|MESG_OUT_PHASE
value|0x06
end_define

begin_define
define|#
directive|define
name|MESG_IN_PHASE
value|0x07
end_define

begin_comment
comment|/* SCSI Messages */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_COMPLETE
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG_EXT_MESSAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG_SAVE_DATA_PTR
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG_RESTORE_PTR
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_DISCONNECT
value|0x04
end_define

begin_define
define|#
directive|define
name|MSG_INIT_DETECT_ERROR
value|0x05
end_define

begin_define
define|#
directive|define
name|MSG_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|MSG_REJECT
value|0x07
end_define

begin_define
define|#
directive|define
name|MSG_NOOP
value|0x08
end_define

begin_define
define|#
directive|define
name|MSG_PARITY_ERROR
value|0x09
end_define

begin_define
define|#
directive|define
name|MSG_BUS_DEVICE_RESET
value|0x0C
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY
value|0x80
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY_DR
value|0xc0
end_define

begin_comment
comment|/* (disconnect/reconnect allowed) */
end_comment

begin_define
define|#
directive|define
name|MSG_SYNC_REQ
value|0x01
end_define

begin_comment
comment|/* SCSI Commands */
end_comment

begin_define
define|#
directive|define
name|CMD_TEST_UNIT_READY
value|0x00
end_define

begin_define
define|#
directive|define
name|CMD_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|CMD_INQUIRY
value|0x12
end_define

begin_define
define|#
directive|define
name|CMD_SEND_DIAGNOSTIC
value|0x1D
end_define

begin_define
define|#
directive|define
name|CMD_FORMAT_UNIT
value|0x04
end_define

begin_define
define|#
directive|define
name|CMD_REASSIGN_BLOCKS
value|0x07
end_define

begin_define
define|#
directive|define
name|CMD_READ
value|0x08
end_define

begin_define
define|#
directive|define
name|CMD_WRITE
value|0x0A
end_define

begin_define
define|#
directive|define
name|CMD_MODE_SELECT
value|0x15
end_define

begin_define
define|#
directive|define
name|CMD_RELEASE_UNIT
value|0x17
end_define

begin_define
define|#
directive|define
name|CMD_MODE_SENSE
value|0x1A
end_define

begin_define
define|#
directive|define
name|CMD_SEND_DIAG
value|0x1D
end_define

begin_define
define|#
directive|define
name|CMD_READ_CAPACITY
value|0x25
end_define

begin_define
define|#
directive|define
name|CMD_READ_EXT
value|0x28
end_define

begin_define
define|#
directive|define
name|CMD_WRITE_EXT
value|0x2A
end_define

begin_define
define|#
directive|define
name|CMD_READ_DEFECT_DATA
value|0x37
end_define

begin_define
define|#
directive|define
name|SD_MANUFAC_DEFECTS
value|0x14000000
end_define

begin_define
define|#
directive|define
name|SD_GROWN_DEFECTS
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|CMD_READ_BUFFER
value|0x3B
end_define

begin_define
define|#
directive|define
name|CMD_WRITE_BUFFER
value|0x3C
end_define

begin_define
define|#
directive|define
name|CMD_READ_FULL
value|0xF0
end_define

begin_define
define|#
directive|define
name|CMD_MEDIA_TEST
value|0xF1
end_define

begin_define
define|#
directive|define
name|CMD_ACCESS_LOG
value|0xF2
end_define

begin_define
define|#
directive|define
name|CMD_WRITE_FULL
value|0xFC
end_define

begin_define
define|#
directive|define
name|CMD_MANAGE_PRIMARY
value|0xFD
end_define

begin_define
define|#
directive|define
name|CMD_EXECUTE_DATA
value|0xFE
end_define

begin_comment
comment|/* SCSI status bits */
end_comment

begin_define
define|#
directive|define
name|STS_CHECKCOND
value|0x02
end_define

begin_comment
comment|/* Check Condition (ie., read sense) */
end_comment

begin_define
define|#
directive|define
name|STS_CONDMET
value|0x04
end_define

begin_comment
comment|/* Condition Met (ie., search worked) */
end_comment

begin_define
define|#
directive|define
name|STS_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|STS_INTERMED
value|0x10
end_define

begin_comment
comment|/* Intermediate status sent */
end_comment

begin_define
define|#
directive|define
name|STS_EXT
value|0x80
end_define

begin_comment
comment|/* Extended status valid */
end_comment

begin_comment
comment|/* command descriptor blocks */
end_comment

begin_struct
struct|struct
name|scsi_cdb6
block|{
name|u_char
name|cmd
decl_stmt|;
comment|/* command code */
name|u_char
name|lun
range|:
literal|3
decl_stmt|,
comment|/* logical unit on ctlr */
name|lbah
range|:
literal|5
decl_stmt|;
comment|/* msb of read/write logical block addr */
name|u_char
name|lbam
decl_stmt|;
comment|/* middle byte of l.b.a. */
name|u_char
name|lbal
decl_stmt|;
comment|/* lsb of l.b.a. */
name|u_char
name|len
decl_stmt|;
comment|/* transfer length */
name|u_char
name|xtra
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_cdb10
block|{
name|u_char
name|cmd
decl_stmt|;
comment|/* command code */
name|u_char
name|lun
range|:
literal|3
decl_stmt|,
comment|/* logical unit on ctlr */
range|:
literal|4
decl_stmt|,
name|rel
range|:
literal|1
decl_stmt|;
comment|/* l.b.a. is relative addr if =1 */
name|u_char
name|lbah
decl_stmt|;
comment|/* msb of read/write logical block addr */
name|u_char
name|lbahm
decl_stmt|;
comment|/* high middle byte of l.b.a. */
name|u_char
name|lbalm
decl_stmt|;
comment|/* low middle byte of l.b.a. */
name|u_char
name|lbal
decl_stmt|;
comment|/* lsb of l.b.a. */
name|u_char
name|reserved
decl_stmt|;
name|u_char
name|lenh
decl_stmt|;
comment|/* msb transfer length */
name|u_char
name|lenl
decl_stmt|;
comment|/* lsb transfer length */
name|u_char
name|xtra
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* basic sense data */
end_comment

begin_struct
struct|struct
name|scsi_sense
block|{
name|u_char
name|valid
range|:
literal|1
decl_stmt|,
comment|/* l.b.a. is valid */
name|class
range|:
literal|3
decl_stmt|,
name|code
range|:
literal|4
decl_stmt|;
name|u_char
name|vu
range|:
literal|4
decl_stmt|,
comment|/* vendor unique */
name|lbah
range|:
literal|4
decl_stmt|;
name|u_char
name|lbam
decl_stmt|;
name|u_char
name|lbal
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_xsense
block|{
name|u_char
name|valid
range|:
literal|1
decl_stmt|,
comment|/* l.b.a. is valid */
name|class
range|:
literal|3
decl_stmt|,
name|code
range|:
literal|4
decl_stmt|;
name|u_char
name|segment
decl_stmt|;
name|u_char
name|filemark
range|:
literal|1
decl_stmt|,
name|eom
range|:
literal|1
decl_stmt|,
name|ili
range|:
literal|1
decl_stmt|,
comment|/* illegal length indicator */
name|rsvd
range|:
literal|1
decl_stmt|,
name|key
range|:
literal|4
decl_stmt|;
name|u_char
name|info1
decl_stmt|;
name|u_char
name|info2
decl_stmt|;
name|u_char
name|info3
decl_stmt|;
name|u_char
name|info4
decl_stmt|;
name|u_char
name|len
decl_stmt|;
comment|/* additional sense length */
block|}
struct|;
end_struct

begin_comment
comment|/* inquiry data */
end_comment

begin_struct
struct|struct
name|scsi_inquiry
block|{
name|u_char
name|type
decl_stmt|;
name|u_char
name|qual
decl_stmt|;
name|u_char
name|version
decl_stmt|;
name|u_char
name|rsvd
decl_stmt|;
name|u_char
name|len
decl_stmt|;
name|char
name|class
index|[
literal|3
index|]
decl_stmt|;
name|char
name|vendor_id
index|[
literal|8
index|]
decl_stmt|;
name|char
name|product_id
index|[
literal|16
index|]
decl_stmt|;
name|char
name|rev
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_format_parms
block|{
comment|/* physical BFI format */
name|u_short
name|reserved
decl_stmt|;
name|u_short
name|list_len
decl_stmt|;
struct|struct
name|defect
block|{
name|unsigned
name|cyl
range|:
literal|24
decl_stmt|;
name|unsigned
name|head
range|:
literal|8
decl_stmt|;
name|long
name|bytes_from_index
decl_stmt|;
block|}
name|defect
index|[
literal|127
index|]
struct|;
block|}
name|format_parms
struct|;
end_struct

begin_struct
struct|struct
name|scsi_reassign_parms
block|{
name|u_short
name|reserved
decl_stmt|;
name|u_short
name|list_len
decl_stmt|;
comment|/* length in bytes of defects only */
struct|struct
name|new_defect
block|{
name|unsigned
name|lba
decl_stmt|;
comment|/* logical block address */
block|}
name|new_defect
index|[
literal|2
index|]
struct|;
block|}
name|reassign_parms
struct|;
end_struct

begin_struct
struct|struct
name|scsi_modesel_hdr
block|{
name|u_char
name|rsvd1
decl_stmt|;
name|u_char
name|media_type
decl_stmt|;
name|u_char
name|rsvd2
decl_stmt|;
name|u_char
name|block_desc_len
decl_stmt|;
name|u_int
name|density
range|:
literal|8
decl_stmt|;
name|u_int
name|number_blocks
range|:
literal|24
decl_stmt|;
name|u_int
name|rsvd3
range|:
literal|8
decl_stmt|;
name|u_int
name|block_length
range|:
literal|24
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_modesense_hdr
block|{
name|u_char
name|len
decl_stmt|;
name|u_char
name|media_type
decl_stmt|;
name|u_char
name|wp
range|:
literal|1
decl_stmt|;
name|u_char
name|rsvd1
range|:
literal|7
decl_stmt|;
name|u_char
name|block_desc_len
decl_stmt|;
name|u_int
name|density
range|:
literal|8
decl_stmt|;
name|u_int
name|number_blocks
range|:
literal|24
decl_stmt|;
name|u_int
name|rsvd2
range|:
literal|8
decl_stmt|;
name|u_int
name|block_length
range|:
literal|24
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mode Select / Mode sense "pages"  */
end_comment

begin_comment
comment|/*  * Page One - Error Recovery Parameters   */
end_comment

begin_struct
struct|struct
name|scsi_err_recovery
block|{
name|u_char
name|page_savable
range|:
literal|1
decl_stmt|;
comment|/* save parameters */
name|u_char
name|reserved
range|:
literal|1
decl_stmt|;
name|u_char
name|page_code
range|:
literal|6
decl_stmt|;
comment|/* = 0x01 */
name|u_char
name|page_length
decl_stmt|;
comment|/* = 6 */
name|u_char
name|awre
range|:
literal|1
decl_stmt|;
comment|/* auto write realloc enabled */
name|u_char
name|arre
range|:
literal|1
decl_stmt|;
comment|/* auto read realloc enabled */
name|u_char
name|tb
range|:
literal|1
decl_stmt|;
comment|/* transfer block */
name|u_char
name|rc
range|:
literal|1
decl_stmt|;
comment|/* read continuous */
name|u_char
name|eec
range|:
literal|1
decl_stmt|;
comment|/* enable early correction */
name|u_char
name|per
range|:
literal|1
decl_stmt|;
comment|/* post error */
name|u_char
name|dte
range|:
literal|1
decl_stmt|;
comment|/* disable transfer on error */
name|u_char
name|dcr
range|:
literal|1
decl_stmt|;
comment|/* disable correction */
name|u_char
name|retry_count
decl_stmt|;
name|u_char
name|correction_span
decl_stmt|;
name|u_char
name|head_offset_count
decl_stmt|;
name|u_char
name|strobe_offset_count
decl_stmt|;
name|u_char
name|recovery_time_limit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Page Two - Disconnect / Reconnect Control Parameters  */
end_comment

begin_struct
struct|struct
name|scsi_disco_reco
block|{
name|u_char
name|page_savable
range|:
literal|1
decl_stmt|;
comment|/* save parameters */
name|u_char
name|rsvd
range|:
literal|1
decl_stmt|;
name|u_char
name|page_code
range|:
literal|6
decl_stmt|;
comment|/* = 0x02 */
name|u_char
name|page_length
decl_stmt|;
comment|/* = 10 */
name|u_char
name|buffer_full_ratio
decl_stmt|;
comment|/* write, how full before reconnect? */
name|u_char
name|buffer_empty_ratio
decl_stmt|;
comment|/* read, how full before reconnect? */
name|u_short
name|bus_inactivity_limit
decl_stmt|;
comment|/* how much bus time for busy */
name|u_short
name|disconnect_time_limit
decl_stmt|;
comment|/* min to remain disconnected */
name|u_short
name|connect_time_limit
decl_stmt|;
comment|/* min to remain connected */
name|u_short
name|reserved_1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Page Three - Direct Access Device Format Parameters  */
end_comment

begin_struct
struct|struct
name|scsi_format
block|{
name|u_char
name|page_savable
range|:
literal|1
decl_stmt|;
comment|/* save parameters */
name|u_char
name|rsvd
range|:
literal|1
decl_stmt|;
name|u_char
name|page_code
range|:
literal|6
decl_stmt|;
comment|/* = 0x03 */
name|u_char
name|page_length
decl_stmt|;
comment|/* = 22 */
name|u_short
name|tracks_per_zone
decl_stmt|;
comment|/*  Handling of Defects Fields */
name|u_short
name|alt_sect_zone
decl_stmt|;
name|u_short
name|alt_tracks_zone
decl_stmt|;
name|u_short
name|alt_tracks_vol
decl_stmt|;
name|u_short
name|sect_track
decl_stmt|;
comment|/* Track Format Field */
name|u_short
name|data_sect
decl_stmt|;
comment|/* Sector Format Fields */
name|u_short
name|interleave
decl_stmt|;
name|u_short
name|track_skew_factor
decl_stmt|;
name|u_short
name|cyl_skew_factor
decl_stmt|;
name|u_char
name|ssec
range|:
literal|1
decl_stmt|;
comment|/* Drive Type Field */
name|u_char
name|hsec
range|:
literal|1
decl_stmt|;
name|u_char
name|rmb
range|:
literal|1
decl_stmt|;
name|u_char
name|surf
range|:
literal|1
decl_stmt|;
name|u_char
name|ins
range|:
literal|1
decl_stmt|;
name|u_char
name|reserved_1
range|:
literal|3
decl_stmt|;
name|u_char
name|reserved_2
decl_stmt|;
name|u_char
name|reserved_3
decl_stmt|;
name|u_char
name|reserved_4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Page Four - Rigid Disk Drive Geometry Parameters   */
end_comment

begin_struct
struct|struct
name|scsi_geometry
block|{
name|u_char
name|page_savable
range|:
literal|1
decl_stmt|;
comment|/* save parameters */
name|u_char
name|rsvd
range|:
literal|1
decl_stmt|;
name|u_char
name|page_code
range|:
literal|6
decl_stmt|;
comment|/* = 0x04 */
name|u_char
name|page_length
decl_stmt|;
comment|/* = 18 */
name|u_char
name|cyl_ub
decl_stmt|;
comment|/* number of cylinders */
name|u_char
name|cyl_mb
decl_stmt|;
name|u_char
name|cyl_lb
decl_stmt|;
name|u_char
name|heads
decl_stmt|;
comment|/* number of heads */
name|u_char
name|precomp_cyl_ub
decl_stmt|;
comment|/* cylinder to start precomp */
name|u_char
name|precomp_cyl_mb
decl_stmt|;
name|u_char
name|precomp_cyl_lb
decl_stmt|;
name|u_char
name|current_cyl_ub
decl_stmt|;
comment|/* cyl to start reduced current */
name|u_char
name|current_cyl_mb
decl_stmt|;
name|u_char
name|current_cyl_lb
decl_stmt|;
name|u_short
name|step_rate
decl_stmt|;
comment|/* drive step rate */
name|u_char
name|landing_cyl_ub
decl_stmt|;
comment|/* landing zone cylinder */
name|u_char
name|landing_cyl_mb
decl_stmt|;
name|u_char
name|landing_cyl_lb
decl_stmt|;
name|u_char
name|reserved_1
decl_stmt|;
name|u_char
name|reserved_2
decl_stmt|;
name|u_char
name|reserved_3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Page 0x38 - Cache Control Parameters  */
end_comment

begin_struct
struct|struct
name|scsi_cache
block|{
name|u_char
name|page_savable
range|:
literal|1
decl_stmt|;
comment|/* save parameters */
name|u_char
name|rsvd
range|:
literal|1
decl_stmt|;
name|u_char
name|page_code
range|:
literal|6
decl_stmt|;
comment|/* = 0x38 */
name|u_char
name|page_length
decl_stmt|;
comment|/* = 14 */
name|u_char
name|rsvd_1
range|:
literal|1
decl_stmt|;
name|u_char
name|wie
range|:
literal|1
decl_stmt|;
comment|/* write index enable */
name|u_char
name|rsvd_2
range|:
literal|1
decl_stmt|;
name|u_char
name|ce
range|:
literal|1
decl_stmt|;
comment|/* cache enable */
name|u_char
name|table_size
range|:
literal|4
decl_stmt|;
name|u_char
name|prefetch_threshold
decl_stmt|;
name|u_char
name|maximum_threshold
decl_stmt|;
name|u_char
name|maximumprefetch_multiplier
decl_stmt|;
name|u_char
name|minimum_threshold
decl_stmt|;
name|u_char
name|minimum_prefetch_multiplier
decl_stmt|;
name|u_char
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Driver ioctl's for various scsi operations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Control for SCSI "format" mode.  *  * "Format" mode allows a privileged process to issue direct SCSI  * commands to a drive (it is intended primarily to allow on-line  * formatting).  SDIOCSFORMAT with a non-zero arg will put the drive  * into format mode; a zero arg will take it out.  When in format  * mode, only the process that issued the SDIOCFORMAT can read or  * write the drive.  *  * In format mode, process is expected to  *	- do SDIOCSCSICOMMAND to supply cdb for next SCSI op  *	- do read or write as appropriate for cdb  *	- if i/o error, optionally do SDIOCSENSE to get completion  *	  status and sense data from last scsi operation.  */
end_comment

begin_struct
struct|struct
name|scsi_fmt_cdb
block|{
name|int
name|len
decl_stmt|;
comment|/* cdb length (in bytes) */
name|u_char
name|cdb
index|[
literal|28
index|]
decl_stmt|;
comment|/* cdb to use on next read/write */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_fmt_sense
block|{
name|u_int
name|status
decl_stmt|;
comment|/* completion status of last op */
name|u_char
name|sense
index|[
literal|28
index|]
decl_stmt|;
comment|/* sense data (if any) from last op */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDIOCSFORMAT
value|_IOW('S', 0x1, int)
end_define

begin_define
define|#
directive|define
name|SDIOCGFORMAT
value|_IOR('S', 0x2, int)
end_define

begin_define
define|#
directive|define
name|SDIOCSCSICOMMAND
value|_IOW('S', 0x3, struct scsi_fmt_cdb)
end_define

begin_define
define|#
directive|define
name|SDIOCSENSE
value|_IOR('S', 0x4, struct scsi_fmt_sense)
end_define

end_unit

