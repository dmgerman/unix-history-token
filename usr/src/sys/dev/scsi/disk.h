begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)disk.h	5.2 (Berkeley) %G%  *  * from: $Header: disk.h,v 1.2 92/05/15 11:23:58 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI definitions for Direct Access Devices (disks).  * This includes WORMs and CD-ROMs (although a few commands, such as  * format or write, are nonsensical on some).  *  * Commands defined in the common header (scsi.h) appear here as comments.  */
end_comment

begin_comment
comment|/* group 0 */
end_comment

begin_comment
comment|/*	CMD_TEST_UNIT_READY	0x00	   test unit ready */
end_comment

begin_define
define|#
directive|define
name|CMD_REZERO
value|0x01
end_define

begin_comment
comment|/* rezero unit */
end_comment

begin_comment
comment|/*	CMD_REQUEST_SENSE	0x03	/* request sense */
end_comment

begin_define
define|#
directive|define
name|CMD_FORMAT_UNIT
value|0x04
end_define

begin_comment
comment|/* format unit (disk) */
end_comment

begin_define
define|#
directive|define
name|CMD_REASSIGN_BLOCKS
value|0x07
end_define

begin_comment
comment|/* reassign blocks (disk, WORM) */
end_comment

begin_define
define|#
directive|define
name|CMD_READ6
value|0x08
end_define

begin_comment
comment|/* read (6 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE6
value|0x0a
end_define

begin_comment
comment|/* write (6 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_SEEK6
value|0x0b
end_define

begin_comment
comment|/* seek (6 byte cdb) */
end_comment

begin_comment
comment|/*	CMD_INQUIRY		0x12	   inquiry */
end_comment

begin_define
define|#
directive|define
name|CMD_MODE_SELECT
value|0x15
end_define

begin_comment
comment|/* mode select */
end_comment

begin_define
define|#
directive|define
name|CMD_RESERVE
value|0x16
end_define

begin_comment
comment|/* reserve */
end_comment

begin_define
define|#
directive|define
name|CMD_RELEASE
value|0x17
end_define

begin_comment
comment|/* release */
end_comment

begin_comment
comment|/*	CMD_COPY		0x18	   copy */
end_comment

begin_define
define|#
directive|define
name|CMD_MODE_SENSE
value|0x1a
end_define

begin_comment
comment|/* mode sense */
end_comment

begin_define
define|#
directive|define
name|CMD_SSU
value|0x1b
end_define

begin_comment
comment|/* start/stop unit */
end_comment

begin_comment
comment|/*	CMD_RECEIVE_DIAG	0x1c	   receive diagnostic results */
end_comment

begin_comment
comment|/*	CMD_SEND_DIAG		0x1d	   send diagnostic */
end_comment

begin_define
define|#
directive|define
name|CMD_PAMR
value|0x1e
end_define

begin_comment
comment|/* prevent/allow medium removal */
end_comment

begin_comment
comment|/* group 1 */
end_comment

begin_define
define|#
directive|define
name|CMD_READ_CAPACITY
value|0x25
end_define

begin_comment
comment|/* read capacity */
end_comment

begin_define
define|#
directive|define
name|CMD_READ10
value|0x28
end_define

begin_comment
comment|/* read (10 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE10
value|0x2a
end_define

begin_comment
comment|/* write (10 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_SEEK10
value|0x2b
end_define

begin_comment
comment|/* write (10 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE_VERIFY
value|0x2e
end_define

begin_comment
comment|/* write and verify */
end_comment

begin_define
define|#
directive|define
name|CMD_VERIFY
value|0x2f
end_define

begin_comment
comment|/* verify */
end_comment

begin_define
define|#
directive|define
name|CMD_SEARCH_H
value|0x30
end_define

begin_comment
comment|/* search data high */
end_comment

begin_define
define|#
directive|define
name|CMD_SEARCH_E
value|0x31
end_define

begin_comment
comment|/* search data equal */
end_comment

begin_define
define|#
directive|define
name|CMD_SEARCH_L
value|0x32
end_define

begin_comment
comment|/* search data low */
end_comment

begin_define
define|#
directive|define
name|CMD_SET_LIMITS
value|0x33
end_define

begin_comment
comment|/* set limits */
end_comment

begin_comment
comment|/*	CMD_COMPARE		0x39	   compare */
end_comment

begin_define
define|#
directive|define
name|CMD_COPY_VERIFY
value|0x3a
end_define

begin_comment
comment|/* copy and verify */
end_comment

begin_comment
comment|/* this one is in van's but not in my 17B documents */
end_comment

begin_define
define|#
directive|define
name|CMD_READ_DEFECT_DATA
value|0x37
end_define

begin_comment
comment|/* read defect data */
end_comment

begin_comment
comment|/* ??? */
end_comment

begin_comment
comment|/*  * Structure of a FORMAT UNIT command (i.e., the cdb):  *	byte 0: opcode<8>  *	byte 1: lun<3> format_data<1> complete_list<1> defect_list_format<3>  *	byte 2: vendor unique  *	byte 3: interleave (MSB)  *	byte 4: interleave (LSB)  *	byte 5: control  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_fu
block|{
name|u_char
name|cdb_cmd
decl_stmt|;
comment|/* SCSI_CMD_FU */
name|u_char
name|cdb_lun_etc
decl_stmt|;
comment|/* lun+FD+CL+DLF */
name|u_char
name|cdb_vu
decl_stmt|;
comment|/* vendor unique */
name|u_char
name|cdb_ilvh
decl_stmt|;
comment|/* interleave (MSB) */
name|u_char
name|cdb_ilvl
decl_stmt|;
comment|/* interleave (LSB) */
name|u_char
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * If format data are supplied, they give either additional (cl=0) or  * new (cl=1) defect list in one of the following formats.  * Formats 1, 2, and 3 are the same as 0; formats 6 and 7 are  * vendor unique and reserved, respectively.  (The `backwards'  * in `backwards compatible'...)  */
end_comment

begin_define
define|#
directive|define
name|SCSI_DLF_BLOCK
value|0
end_define

begin_comment
comment|/* dlf = blocks */
end_comment

begin_define
define|#
directive|define
name|SCSI_DLF_BFI
value|4
end_define

begin_comment
comment|/* dlf = bytes from index */
end_comment

begin_define
define|#
directive|define
name|SCSI_DLF_PS
value|5
end_define

begin_comment
comment|/* dlf = physical sectors */
end_comment

begin_comment
comment|/*  * Defect list header, block format (`defect block address').  *  * N.B.: this structure is also used for the Reassign Blocks command;  * there the `defect block address' becomes a `defect logical block address'.  */
end_comment

begin_struct
struct|struct
name|scsi_dlf_dba
block|{
name|u_short
name|dlf_xxx
decl_stmt|;
comment|/* reserved */
name|u_char
name|dlf_lenh
decl_stmt|,
comment|/* defect list length (MSB) */
name|dlf_lenl
decl_stmt|;
comment|/* defect list length (LSB) */
struct|struct
name|scsi_dlf_dba_desc
block|{
name|u_char
name|dbah
decl_stmt|,
comment|/* defect block address (MSB) */
name|dbahm
decl_stmt|,
comment|/* defect block address */
name|dbalm
decl_stmt|,
comment|/* defect block address */
name|dbal
decl_stmt|;
comment|/* defect block address (LSB) */
block|}
name|dlf_dba
index|[
literal|1
index|]
struct|;
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Defect list header, Bytes From Index format.  */
end_comment

begin_struct
struct|struct
name|scsi_dlf_bfi
block|{
name|u_short
name|dlf_xxx
decl_stmt|;
comment|/* reserved */
name|u_char
name|dlf_lenh
decl_stmt|,
comment|/* defect list length (MSB) */
name|dlf_lenl
decl_stmt|;
comment|/* defect list length (LSB) */
struct|struct
name|scsi_dlf_bfi_desc
block|{
name|u_char
name|cylh
decl_stmt|,
comment|/* cylinder number of defect (MSB) */
name|cylm
decl_stmt|,
comment|/* cylinder number of defect */
name|cyll
decl_stmt|,
comment|/* cylinder number of defect (LSB) */
name|head
decl_stmt|,
comment|/* head number of defect */
name|bfih
decl_stmt|,
comment|/* defect bytes from index (MSB) */
name|bfihm
decl_stmt|,
comment|/* defect bytes from index */
name|bfilm
decl_stmt|,
comment|/* defect bytes from index */
name|bfil
decl_stmt|;
comment|/* defect bytes from index (LSB) */
block|}
name|dlf_bfi
index|[
literal|1
index|]
struct|;
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Defect list header, Physical Sector format.  */
end_comment

begin_struct
struct|struct
name|scsi_dlf_ps
block|{
name|u_short
name|dlf_xxx
decl_stmt|;
comment|/* reserved */
name|u_char
name|dlf_lenh
decl_stmt|,
comment|/* defect list length (MSB) */
name|dlf_lenl
decl_stmt|;
comment|/* defect list length (LSB) */
struct|struct
name|scsi_dlf_ps_desc
block|{
name|u_char
name|cylh
decl_stmt|,
comment|/* cylinder number of defect (MSB) */
name|cylm
decl_stmt|,
comment|/* cylinder number of defect */
name|cyll
decl_stmt|,
comment|/* cylinder number of defect (LSB) */
name|head
decl_stmt|,
comment|/* head number of defect */
name|dsnh
decl_stmt|,
comment|/* defect sector number (MSB) */
name|dsnhm
decl_stmt|,
comment|/* defect sector number */
name|dsnlm
decl_stmt|,
comment|/* defect sector number */
name|dsnl
decl_stmt|;
comment|/* defect sector number (LSB) */
block|}
name|dlf_ps
index|[
literal|1
index|]
struct|;
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of data passed via a MODE SELECT command.  */
end_comment

begin_struct
struct|struct
name|scsi_ms
block|{
name|u_char
name|ms_xxx0
decl_stmt|,
comment|/* reserved */
name|ms_mt
decl_stmt|,
comment|/* medium type */
name|ms_xxx1
decl_stmt|,
comment|/* reserved */
name|ms_bdl
decl_stmt|;
comment|/* block descriptor length */
struct|struct
name|scsi_ms_b_desc
block|{
name|u_char
name|dc
decl_stmt|,
comment|/* density code */
name|nbh
decl_stmt|,
comment|/* number of blocks (MSB) */
name|nbm
decl_stmt|,
comment|/* number of blocks */
name|nbl
decl_stmt|,
comment|/* number of blocks (LSB) */
name|xxx
decl_stmt|,
comment|/* reserved */
name|blh
decl_stmt|,
comment|/* block length (MSB) */
name|blm
decl_stmt|,
comment|/* block length */
name|bll
decl_stmt|;
comment|/* block length (LSB) */
block|}
name|ms_bd
index|[
literal|1
index|]
struct|;
comment|/* actually longer */
comment|/* followed by vendor unique bytes */
block|}
struct|;
end_struct

begin_comment
comment|/* values for the Medium Type field - disks */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_DEFAULT
value|0x00
end_define

begin_comment
comment|/* whatever is current */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_SS
value|0x01
end_define

begin_comment
comment|/* single sided, unspecified medium */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_DS
value|0x02
end_define

begin_comment
comment|/* double sided, unspecified medium */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_8SSSD
value|0x05
end_define

begin_comment
comment|/* 8" floppy, SSSD (X3.73-1980) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_8DSSD
value|0x06
end_define

begin_comment
comment|/* 8" floppy, DSSD (X3B8-140) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_8SSDD
value|0x09
end_define

begin_comment
comment|/* 8" floppy, SSDD (X3B8/78-139) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_8DSDD
value|0x0a
end_define

begin_comment
comment|/* 8" floppy, DSDD (X3.121-1984) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_5SSSD
value|0x0d
end_define

begin_comment
comment|/* 5.25" floppy, SSSD (X3.82-1980) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_5DSDD
value|0x12
end_define

begin_comment
comment|/* 5.25" floppy, DSDD (X3.125-1984) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_5DSDD96
value|0x16
end_define

begin_comment
comment|/* 5.25", DSDD, 96tpi (X3.126-198X) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_5DSQD
value|0x1a
end_define

begin_comment
comment|/* 5.25", DSQD, 96tpi (DIS 8630) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_3DS
value|0x1e
end_define

begin_comment
comment|/* 3.5", double sided (X3.137-198X) */
end_comment

begin_comment
comment|/* values for the Medium Type field - tapes */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_QIC_12T
value|0x40
end_define

begin_comment
comment|/* 0.25", 12 tracks */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_MS_MT_QIC_24T
value|0x44
end_define

begin_comment
comment|/* 0.25", 24 tracks */
end_comment

begin_comment
comment|/*  * Bits in cdb_lenl for a READ CAPACITY command,  * and structure returned as data.  *  * If PMI is off, the lba in the cdb must be 0.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_RC_PMI
value|0x01
end_define

begin_comment
comment|/* Partial Medium Indicator */
end_comment

begin_struct
struct|struct
name|scsi_rc
block|{
name|u_char
name|rc_lbah
decl_stmt|;
comment|/* logical block address (MSB) */
name|u_char
name|rc_lbahm
decl_stmt|;
comment|/* logical block address */
name|u_char
name|rc_lbalm
decl_stmt|;
comment|/* logical block address */
name|u_char
name|rc_lbal
decl_stmt|;
comment|/* logical block address (LSB) */
name|u_char
name|rc_blh
decl_stmt|;
comment|/* block length (MSB) */
name|u_char
name|rc_blhm
decl_stmt|;
comment|/* block length */
name|u_char
name|rc_bllm
decl_stmt|;
comment|/* block length */
name|u_char
name|rc_bll
decl_stmt|;
comment|/* block length (LSB) */
block|}
struct|;
end_struct

end_unit

