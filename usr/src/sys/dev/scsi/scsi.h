begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)scsi.h	5.3 (Berkeley) %G%  *  * from: $Header: scsi.h,v 1.5 93/02/01 19:19:15 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Machine independent SCSI defintions.  */
end_comment

begin_comment
comment|/*  * Mostly-generic command descriptor blocks (6 and 10 bytes).  * Note that no SCSI command uses the 12 byte variety, hence it  * is not defined here.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb6
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* command code */
name|cdb_lun_lbah
decl_stmt|,
comment|/* logical unit number,& lba (MSB) */
name|cdb_lbam
decl_stmt|,
comment|/* logical block address */
name|cdb_lbal
decl_stmt|,
comment|/* logical block address (LSB) */
name|cdb_len
decl_stmt|,
comment|/* transfer length */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_cdb10
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* command code */
name|cdb_lun_rel
decl_stmt|,
comment|/* logical unit number, rsvd,& reladr flag */
name|cdb_lbah
decl_stmt|,
comment|/* logical block address (MSB) */
name|cdb_lbahm
decl_stmt|,
comment|/* logical block address (high middle byte) */
name|cdb_lbalm
decl_stmt|,
comment|/* logical block address (low middle byte) */
name|cdb_lbal
decl_stmt|,
comment|/* logical block address (LSB) */
name|cdb_xxx
decl_stmt|,
comment|/* reserved */
name|cdb_lenh
decl_stmt|,
comment|/* transfer length (MSB) */
name|cdb_lenl
decl_stmt|,
comment|/* transfer length (LSB) */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI `generic' cdb.  * The length of the cdb is implicit in the first byte (see scsivar.h).  * This is 16 bytes, rather than 10 or 12, just to help out alignment.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb
block|{
name|u_char
name|cdb_bytes
index|[
literal|16
index|]
decl_stmt|;
comment|/* up to 16 bytes of command */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDB6
parameter_list|(
name|cdb
parameter_list|)
value|((struct scsi_cdb6 *)&(cdb)->cdb_bytes[0])
end_define

begin_define
define|#
directive|define
name|CDB10
parameter_list|(
name|cdb
parameter_list|)
value|((struct scsi_cdb10 *)&(cdb)->cdb_bytes[0])
end_define

begin_comment
comment|/*  * SCSI command (cdb_cmd/cdb_bytes[0]) byte definitions.  Only those  * that are common across all devices are actually defined here.  * (The SCSI standard defines six groups of devices: direct access,  * sequential access, printer, processor, WORM direct access, and  * ROM direct access.  DADs and SADs are basically `disk' and `tape';  * printers and processors are obvious; and WORMs and ROMs are really  * just disks that are missing one or two operations.  A few commands  * are required of all devices; these are defined here, and the others  * are defined in separate headers.)  *  * Letter flags in parentheses in the comment column indicate:  *	M = mandatory (command is implemented on all SCSI devices)  *	E = extended (command implemented if SCSI device does extended SCSI)  *	O = optional  *	R = reserved to future SCSI standard  *	V = vendor unique  *	* = depends on device type  *  * Note that SCSI commands are broken into 8 `groups' given by bits 7..5.  * Group 0 is 6-byte commands, 1 is 10-byte commands, and 5 is 12-byte  * commands (of which none exist); groups 6 and 7 are vendor unique.  * Commands are normally just treated as a simple 8-bit number,  * but the size of the associated cdb is implied by the group.  */
end_comment

begin_comment
comment|/* group 0 */
end_comment

begin_define
define|#
directive|define
name|CMD_TEST_UNIT_READY
value|0x00
end_define

begin_comment
comment|/* (O) test unit ready */
end_comment

begin_comment
comment|/*				0x01	   (*) */
end_comment

begin_comment
comment|/*				0x02	   (V) */
end_comment

begin_define
define|#
directive|define
name|CMD_REQUEST_SENSE
value|0x03
end_define

begin_comment
comment|/* (M) request sense */
end_comment

begin_comment
comment|/*				0x04..0x05 (*) */
end_comment

begin_comment
comment|/*				0x06	   (V) */
end_comment

begin_comment
comment|/*				0x07..0x08 (*) */
end_comment

begin_comment
comment|/*				0x09	   (V) */
end_comment

begin_comment
comment|/*				0x0a..0x0b (*) */
end_comment

begin_comment
comment|/*				0x0c..0x0e (V) */
end_comment

begin_comment
comment|/*				0x0f..0x11 (*) */
end_comment

begin_define
define|#
directive|define
name|CMD_INQUIRY
value|0x12
end_define

begin_comment
comment|/* (E) inquiry */
end_comment

begin_comment
comment|/*				0x13..0x17 (*) */
end_comment

begin_define
define|#
directive|define
name|CMD_COPY
value|0x18
end_define

begin_comment
comment|/* (O) copy */
end_comment

begin_comment
comment|/*				0x19..0x1b (*) */
end_comment

begin_define
define|#
directive|define
name|CMD_RECEIVE_DIAG
value|0x1c
end_define

begin_comment
comment|/* (O) receive diagnostic results */
end_comment

begin_define
define|#
directive|define
name|CMD_SEND_DIAG
value|0x1d
end_define

begin_comment
comment|/* (O) send diagnostic */
end_comment

begin_comment
comment|/*				0x1e	   (*) */
end_comment

begin_comment
comment|/*				0x1f	   (R) */
end_comment

begin_comment
comment|/* group 1 */
end_comment

begin_comment
comment|/*				0x20..0x24 (V) */
end_comment

begin_comment
comment|/*				0x25	   (*) */
end_comment

begin_comment
comment|/*				0x26..0x27 (V) */
end_comment

begin_comment
comment|/*				0x28	   (*) */
end_comment

begin_comment
comment|/*				0x29	   (V) */
end_comment

begin_comment
comment|/*				0x2a..0x2b (*) */
end_comment

begin_comment
comment|/*				0x2c..0x2d (V) */
end_comment

begin_comment
comment|/*				0x2e..0x33 (*) */
end_comment

begin_comment
comment|/*				0x34..0x37 (R) */
end_comment

begin_define
define|#
directive|define
name|CMD_COMPARE
value|0x38
end_define

begin_comment
comment|/* (O) compare */
end_comment

begin_define
define|#
directive|define
name|CMD_COMPARE_VERIFY
value|0x39
end_define

begin_comment
comment|/* (O) compare and verify */
end_comment

begin_comment
comment|/*				0x3a..0x3f (R) */
end_comment

begin_comment
comment|/* group 2 (40-5f) reserved */
end_comment

begin_comment
comment|/* group 3 (60-7f) reserved */
end_comment

begin_comment
comment|/* group 4 (80-9f) reserved */
end_comment

begin_comment
comment|/* group 5 (a0-bf) reserved */
end_comment

begin_comment
comment|/* group 6 (c0-df) vendor unique */
end_comment

begin_comment
comment|/* group 7 (e0-ff) vendor unique */
end_comment

begin_comment
comment|/*  * SCSI control byte.  * Bits 7 and 6 are vendor unique; bits 5, 4, 3, and 2 are reserved.  * Bit 1 may be 1 only if bit 0 is 1; if so, it tells the target to  * send a LINKED COMMAND COMPLETE (WITH FLAG) message.  If not, but  * bit 0 is set, this tells the target to send a LINKED COMMAND COMPLETE  * message.  */
end_comment

begin_define
define|#
directive|define
name|CTRL_VU_MASK
value|0xc0
end_define

begin_comment
comment|/* vendor unique */
end_comment

begin_define
define|#
directive|define
name|CTRL_RSVD
value|0x3c
end_define

begin_comment
comment|/* reserved, must be zero */
end_comment

begin_define
define|#
directive|define
name|CTRL_LCCF
value|0x02
end_define

begin_comment
comment|/* send LCCF if sending LCC */
end_comment

begin_define
define|#
directive|define
name|CTRL_LINK
value|0x01
end_define

begin_comment
comment|/* linked command */
end_comment

begin_comment
comment|/*  * Generic sense: regular and extended.  * A sense operation returned an extended sense iff the error class  * is 7.  The format is vendor unique unless the error code is 0.  * The regular and extended formats are completely different; we  * define macros to obtain values from them.  */
end_comment

begin_struct
struct|struct
name|scsi_sense
block|{
name|u_char
name|sn_vcc
decl_stmt|;
comment|/* valid bit, error class,& error code */
name|u_char
name|sn_var
index|[
literal|7
index|]
decl_stmt|;
comment|/* bytes 1-3, or 1-7; variant formats */
name|u_char
name|sn_addl
index|[
literal|32
operator|-
literal|8
index|]
decl_stmt|;
comment|/* additional sense data, if extended */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SENSE_ECLASS
parameter_list|(
name|sn
parameter_list|)
value|(((sn)->sn_vcc>> 4)& 7)
end_define

begin_define
define|#
directive|define
name|SENSE_ECODE
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_vcc& 0xf)
end_define

begin_define
define|#
directive|define
name|SENSE_ISXSENSE
parameter_list|(
name|sn
parameter_list|)
value|(SENSE_ECLASS(sn) == 7)
end_define

begin_comment
comment|/* for non-extended sense (`r'egular or `r'estricted sense) */
end_comment

begin_define
define|#
directive|define
name|RSENSE_LVALID
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_vcc& 0x80)
end_define

begin_define
define|#
directive|define
name|RSENSE_VU
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_var[0]>> 5)
end_define

begin_define
define|#
directive|define
name|RSENSE_LBA
parameter_list|(
name|sn
parameter_list|)
define|\
value|((((sn)->sn_var[0]& 0x1f)<< 16) | ((sn)->sn_var[1]<< 8) | (sn)->sn_var[2])
end_define

begin_comment
comment|/* for extended sense */
end_comment

begin_define
define|#
directive|define
name|XSENSE_ISSTD
parameter_list|(
name|sn
parameter_list|)
value|(SENSE_ECODE(sn) == 0)
end_define

begin_comment
comment|/* if not standard, cannot interpret it at all */
end_comment

begin_define
define|#
directive|define
name|XSENSE_IVALID
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_vcc& 0x80)
end_define

begin_define
define|#
directive|define
name|XSENSE_SEG
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_var[0])
end_define

begin_define
define|#
directive|define
name|XSENSE_FM
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_var[1]& 0x80)
end_define

begin_comment
comment|/* filemark */
end_comment

begin_define
define|#
directive|define
name|XSENSE_EOM
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_var[1]& 0x40)
end_define

begin_comment
comment|/* end of media */
end_comment

begin_define
define|#
directive|define
name|XSENSE_ILI
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_var[1]& 0x20)
end_define

begin_comment
comment|/* incor length ind */
end_comment

begin_define
define|#
directive|define
name|XSENSE_KEY
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_var[1]& 0x0f)
end_define

begin_comment
comment|/* sense key */
end_comment

begin_define
define|#
directive|define
name|XSENSE_INFO
parameter_list|(
name|sn
parameter_list|)
define|\
value|(((sn)->sn_var[2]<< 24) | ((sn)->sn_var[3]<< 16) | \ 	 ((sn)->sn_var[4]<< 8) | (sn)->sn_var[5])
end_define

begin_define
define|#
directive|define
name|XSENSE_ADDL
parameter_list|(
name|sn
parameter_list|)
value|((sn)->sn_var[6])
end_define

begin_comment
comment|/* add'l sense len */
end_comment

begin_comment
comment|/*  * SCSI INQUIRY data: general, and ANSI versions 1 and 2  * (including common command set).  */
end_comment

begin_struct
struct|struct
name|scsi_inquiry
block|{
name|u_char
name|si_type
decl_stmt|;
comment|/* peripheral device type (below) */
name|u_char
name|si_qual
decl_stmt|;
comment|/* qualifier (see below) */
name|u_char
name|si_version
decl_stmt|;
comment|/* version (see below) */
name|u_char
name|si_v2info
decl_stmt|;
comment|/* scsi version 2 stuff (see below) */
name|u_char
name|si_len
decl_stmt|;
comment|/* additional length */
name|u_char
name|si_more
index|[
literal|252
operator|-
literal|5
index|]
decl_stmt|;
comment|/* actually si_len bytes */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_inq_ansi
block|{
name|u_char
name|si_type
decl_stmt|;
comment|/* peripheral qualifier and device type */
name|u_char
name|si_qual
decl_stmt|;
comment|/* RMB and device type qualifier */
name|u_char
name|si_version
decl_stmt|;
comment|/* ISO, ECMA and ANSI-approved versions */
name|u_char
name|si_v2info
decl_stmt|;
comment|/* ? */
name|u_char
name|si_len
decl_stmt|;
comment|/* addition length */
name|char
name|si_xxx1
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved */
name|char
name|si_flags
decl_stmt|;
comment|/* (see below) */
name|char
name|si_vendor
index|[
literal|8
index|]
decl_stmt|;
comment|/* vendor (blank padded) */
name|char
name|si_product
index|[
literal|16
index|]
decl_stmt|;
comment|/* product (blank padded) */
name|char
name|si_rev
index|[
literal|4
index|]
decl_stmt|;
comment|/* revision (blank padded) */
comment|/* scsi version 2 stuff follows */
name|char
name|si_vend1
index|[
literal|20
index|]
decl_stmt|;
comment|/* vendor specific */
name|char
name|si_xxx2
index|[
literal|40
index|]
decl_stmt|;
comment|/* reserved */
name|char
name|si_vend2
index|[
literal|252
operator|-
literal|96
index|]
decl_stmt|;
comment|/* vendor specific parameters */
block|}
struct|;
end_struct

begin_comment
comment|/* peripheral device types */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_MASK
value|0xe0
end_define

begin_comment
comment|/* peripheral qualifer mask */
end_comment

begin_define
define|#
directive|define
name|TYPE_TYPE_MASK
value|0x1f
end_define

begin_comment
comment|/* peripheral device type mask */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_NORM
value|0x00
end_define

begin_comment
comment|/* device is normal */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_NOTCONN
value|0x20
end_define

begin_comment
comment|/* not connected */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_XXX
value|0x40
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_NOLUN
value|0x60
end_define

begin_comment
comment|/* logical unit not supported */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_VT4
value|0x80
end_define

begin_comment
comment|/* vendor specific type 4 */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_VT5
value|0xa0
end_define

begin_comment
comment|/* vendor specific type 5 */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_VT6
value|0xc0
end_define

begin_comment
comment|/* vendor specific type 6 */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUAL_VT7
value|0xe0
end_define

begin_comment
comment|/* vendor specific type 7 */
end_comment

begin_define
define|#
directive|define
name|TYPE_DAD
value|0x00
end_define

begin_comment
comment|/* direct access device (disk) */
end_comment

begin_define
define|#
directive|define
name|TYPE_SAD
value|0x01
end_define

begin_comment
comment|/* sequential access device (tape) */
end_comment

begin_define
define|#
directive|define
name|TYPE_PRINTER
value|0x02
end_define

begin_comment
comment|/* printer */
end_comment

begin_define
define|#
directive|define
name|TYPE_PROCESSOR
value|0x03
end_define

begin_comment
comment|/* processor */
end_comment

begin_define
define|#
directive|define
name|TYPE_WORM
value|0x04
end_define

begin_comment
comment|/* WORM disk */
end_comment

begin_define
define|#
directive|define
name|TYPE_ROM
value|0x05
end_define

begin_comment
comment|/* CD-ROM disk */
end_comment

begin_define
define|#
directive|define
name|TYPE_SCANNER
value|0x06
end_define

begin_comment
comment|/* scanner */
end_comment

begin_define
define|#
directive|define
name|TYPE_MO
value|0x07
end_define

begin_comment
comment|/* magneto-optical */
end_comment

begin_define
define|#
directive|define
name|TYPE_JUKEBOX
value|0x08
end_define

begin_comment
comment|/* medium changer */
end_comment

begin_define
define|#
directive|define
name|TYPE_LAN
value|0x09
end_define

begin_comment
comment|/* communications device */
end_comment

begin_define
define|#
directive|define
name|TYPE_NP
value|0x1f
end_define

begin_comment
comment|/* unknown or no device */
end_comment

begin_comment
comment|/* qualifiers */
end_comment

begin_define
define|#
directive|define
name|QUAL_RMB
value|0x80
end_define

begin_comment
comment|/* removable medium bit */
end_comment

begin_define
define|#
directive|define
name|QUAL_MASK
value|0x7f
end_define

begin_comment
comment|/* mask for `user' bits */
end_comment

begin_comment
comment|/* version (shifts and masks for subfields) */
end_comment

begin_define
define|#
directive|define
name|VER_ISO_SHIFT
value|6
end_define

begin_comment
comment|/* ISO version: top 2 bits */
end_comment

begin_define
define|#
directive|define
name|VER_ISO_MASK
value|3
end_define

begin_define
define|#
directive|define
name|VER_ECMA_SHIFT
value|3
end_define

begin_comment
comment|/* ECMA version: middle 3 bits */
end_comment

begin_define
define|#
directive|define
name|VER_ECMA_MASK
value|7
end_define

begin_define
define|#
directive|define
name|VER_ANSI_SHIFT
value|0
end_define

begin_comment
comment|/* ANSI version: bottom 3 bits */
end_comment

begin_define
define|#
directive|define
name|VER_ANSI_MASK
value|7
end_define

begin_comment
comment|/* v2 info */
end_comment

begin_define
define|#
directive|define
name|V2INFO_AENC
value|0x80
end_define

begin_comment
comment|/* device can accept AEN data */
end_comment

begin_define
define|#
directive|define
name|V2INFO_TRMIOP
value|0x40
end_define

begin_comment
comment|/* supports TERMINATE I/O PROC msg */
end_comment

begin_define
define|#
directive|define
name|V2INFO_XXX
value|0x30
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|V2INFO_RDF_MASK
value|0x0f
end_define

begin_comment
comment|/* response data format mask */
end_comment

begin_define
define|#
directive|define
name|V2INFO_RDF_SCSI1
value|0x00
end_define

begin_comment
comment|/* SCSI-1 standard INQUIRY data */
end_comment

begin_define
define|#
directive|define
name|V2INFO_RDF_CCS
value|0x01
end_define

begin_comment
comment|/* common command set INQUIRY data */
end_comment

begin_define
define|#
directive|define
name|V2INFO_RDF_SCSI2
value|0x02
end_define

begin_comment
comment|/* SCSI-2 standard INQUIRY data */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|V2FLAG_RELADR
value|0x80
end_define

begin_comment
comment|/* supports relative addressing */
end_comment

begin_define
define|#
directive|define
name|V2FLAG_WBUS32
value|0x40
end_define

begin_comment
comment|/* supports 32 bit data xfer */
end_comment

begin_define
define|#
directive|define
name|V2FLAG_WBUS16
value|0x20
end_define

begin_comment
comment|/* supports 32 bit data xfer */
end_comment

begin_define
define|#
directive|define
name|V2FLAG_SYNC
value|0x10
end_define

begin_comment
comment|/* supports synchronous data xfer */
end_comment

begin_define
define|#
directive|define
name|V2FLAG_LINKED
value|0x08
end_define

begin_comment
comment|/* supports linked commands */
end_comment

begin_define
define|#
directive|define
name|V2FLAG_XXX
value|0x04
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|V2FLAG_CMDQUE
value|0x02
end_define

begin_comment
comment|/* supports tagged command queueing */
end_comment

begin_define
define|#
directive|define
name|V2FLAG_SOFTRESET
value|0x01
end_define

begin_comment
comment|/* RST causes soft reset */
end_comment

begin_comment
comment|/*  * SCSI message codes bytes.  The `command complete' code is required;  * all others are optional.  `Identify' is a flag bit, not a code (thus  * codes are actually at most 7 bits).  */
end_comment

begin_define
define|#
directive|define
name|MSG_IDENTIFY
value|0x80
end_define

begin_comment
comment|/* flag => this is an identify msg */
end_comment

begin_define
define|#
directive|define
name|MSG_IDENTIFY_DR
value|0x40
end_define

begin_comment
comment|/* IDENTIFY: flag => discon/resel ok */
end_comment

begin_define
define|#
directive|define
name|MSG_IDENTIFY_RSVD
value|0x38
end_define

begin_comment
comment|/* IDENTIFY: these bits are reserved */
end_comment

begin_define
define|#
directive|define
name|MSG_IDENTIFY_LUN
value|0x07
end_define

begin_comment
comment|/* IDENTIFY: these bits give LUN */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_COMPLETE
value|0x00
end_define

begin_comment
comment|/* command complete */
end_comment

begin_define
define|#
directive|define
name|MSG_EXT_MESSAGE
value|0x01
end_define

begin_comment
comment|/* extended message */
end_comment

begin_define
define|#
directive|define
name|MSG_SAVE_DATA_PTR
value|0x02
end_define

begin_comment
comment|/* save data pointer */
end_comment

begin_define
define|#
directive|define
name|MSG_RESTORE_PTR
value|0x03
end_define

begin_comment
comment|/* restore pointers */
end_comment

begin_define
define|#
directive|define
name|MSG_DISCONNECT
value|0x04
end_define

begin_comment
comment|/* disconnect */
end_comment

begin_define
define|#
directive|define
name|MSG_INIT_DETECT_ERROR
value|0x05
end_define

begin_comment
comment|/* initiator detected error */
end_comment

begin_define
define|#
directive|define
name|MSG_ABORT
value|0x06
end_define

begin_comment
comment|/* abort */
end_comment

begin_define
define|#
directive|define
name|MSG_REJECT
value|0x07
end_define

begin_comment
comment|/* message reject */
end_comment

begin_define
define|#
directive|define
name|MSG_NOOP
value|0x08
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|MSG_PARITY_ERROR
value|0x09
end_define

begin_comment
comment|/* message parity error */
end_comment

begin_define
define|#
directive|define
name|MSG_LCC
value|0x0a
end_define

begin_comment
comment|/* linked command complete */
end_comment

begin_define
define|#
directive|define
name|MSG_LCCF
value|0x0b
end_define

begin_comment
comment|/* linked command complete (w/ flag) */
end_comment

begin_define
define|#
directive|define
name|MSG_BUS_DEVICE_RESET
value|0x0c
end_define

begin_comment
comment|/* bus device reset */
end_comment

begin_define
define|#
directive|define
name|MSG_ABORT_TAG
value|0x0d
end_define

begin_comment
comment|/* abort tagged msg */
end_comment

begin_define
define|#
directive|define
name|MSG_CLEAR_QUEUE
value|0x0e
end_define

begin_comment
comment|/* clear queue */
end_comment

begin_define
define|#
directive|define
name|MSG_INITIATE_RECOVERY
value|0x0f
end_define

begin_comment
comment|/* initiate recovery */
end_comment

begin_define
define|#
directive|define
name|MSG_RELEASE_RECOVERY
value|0x10
end_define

begin_comment
comment|/* release recovery */
end_comment

begin_define
define|#
directive|define
name|MSG_TERMINATE_PROCESS
value|0x11
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|MSG_SIMPLE_Q_TAG
value|0x20
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|MSG_HEAD_Q_TAG
value|0x21
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|MSG_ORDERED_Q_TAG
value|0x22
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|MSG_IGNORE_WIDE_RESID
value|0x23
end_define

begin_comment
comment|/* ? */
end_comment

begin_comment
comment|/*  * SCSI extended message format.  */
end_comment

begin_struct
struct|struct
name|scsi_xmsg
block|{
name|u_char
name|xm_xmsg
decl_stmt|,
comment|/* value 1, i.e., SMSG_EXT_MESSAGE */
name|xm_len
decl_stmt|,
comment|/* length of this extended message */
name|xm_code
decl_stmt|,
comment|/* actual code */
name|xm_args
index|[
literal|253
index|]
decl_stmt|;
comment|/* actualy xm_len-1 bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI extended message codes.  */
end_comment

begin_define
define|#
directive|define
name|XMSG_MDP
value|0x00
end_define

begin_comment
comment|/* modify data pointer */
end_comment

begin_define
define|#
directive|define
name|XMSG_SDTR
value|0x01
end_define

begin_comment
comment|/* synchronous data transfer request */
end_comment

begin_define
define|#
directive|define
name|XMSG_XID
value|0x02
end_define

begin_comment
comment|/* extended identify */
end_comment

begin_comment
comment|/*  * SCSI status byte values.  Bits 6, 5, and 0 are Vendor Unique.  */
end_comment

begin_define
define|#
directive|define
name|STS_EXT
value|0x80
end_define

begin_comment
comment|/* flag => extended status valid */
end_comment

begin_define
define|#
directive|define
name|STS_MASK
value|0x1e
end_define

begin_comment
comment|/* mask for non-VU bits */
end_comment

begin_define
define|#
directive|define
name|STS_VU
value|0x61
end_define

begin_comment
comment|/* mask for Vendor Unique bits */
end_comment

begin_define
define|#
directive|define
name|STS_GOOD
value|0x00
end_define

begin_comment
comment|/* success, command done */
end_comment

begin_define
define|#
directive|define
name|STS_CHECKCOND
value|0x02
end_define

begin_comment
comment|/* check condition (do a REQ SENSE) */
end_comment

begin_define
define|#
directive|define
name|STS_CONDMET
value|0x04
end_define

begin_comment
comment|/* condition met (search succeeded) */
end_comment

begin_comment
comment|/*	0x06	   reserved */
end_comment

begin_define
define|#
directive|define
name|STS_BUSY
value|0x08
end_define

begin_comment
comment|/* busy */
end_comment

begin_comment
comment|/*	0x0a	   reserved */
end_comment

begin_comment
comment|/*	0x0c	   reserved */
end_comment

begin_comment
comment|/*	0x0e	   reserved */
end_comment

begin_define
define|#
directive|define
name|STS_INTERMED
value|0x10
end_define

begin_comment
comment|/* succeeded, doing linked cmd */
end_comment

begin_comment
comment|/*	0x12	   reserved */
end_comment

begin_define
define|#
directive|define
name|STS_INTERMED_CONDMET
value|0x14
end_define

begin_comment
comment|/* condition met, doing linked cmd */
end_comment

begin_comment
comment|/*	0x16	   reserved */
end_comment

begin_define
define|#
directive|define
name|STS_RESERV_CONFLICT
value|0x18
end_define

begin_comment
comment|/* reservation conflict */
end_comment

begin_comment
comment|/*	0x1a	   reserved */
end_comment

begin_comment
comment|/*	0x1c	   reserved */
end_comment

begin_comment
comment|/*	0x1e	   reserved */
end_comment

end_unit

