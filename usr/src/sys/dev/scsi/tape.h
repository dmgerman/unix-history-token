begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)tape.h	5.1 (Berkeley) %G%  *  * from: $Header: tape.h,v 1.2 92/05/15 11:24:06 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI definitions for Sequential Access Devices (tapes).  */
end_comment

begin_define
define|#
directive|define
name|CMD_REWIND
value|0x01
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|CMD_READ_BLOCK_LIMITS
value|0x05
end_define

begin_comment
comment|/* read block limits */
end_comment

begin_define
define|#
directive|define
name|CMD_READ
value|0x08
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE
value|0x0a
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|CMD_TRACK_SELECT
value|0x0b
end_define

begin_comment
comment|/* track select */
end_comment

begin_define
define|#
directive|define
name|CMD_READ_REVERSE
value|0x0f
end_define

begin_comment
comment|/* read reverse */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE_FILEMARK
value|0x10
end_define

begin_comment
comment|/* write file marks */
end_comment

begin_define
define|#
directive|define
name|CMD_SPACE
value|0x11
end_define

begin_comment
comment|/* space */
end_comment

begin_define
define|#
directive|define
name|CMD_VERIFY
value|0x13
end_define

begin_comment
comment|/* verify */
end_comment

begin_define
define|#
directive|define
name|CMD_RBD
value|0x14
end_define

begin_comment
comment|/* recover buffered data */
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
name|CMD_RESERVE_UNIT
value|0x16
end_define

begin_comment
comment|/* reserve unit */
end_comment

begin_define
define|#
directive|define
name|CMD_RELEASE_UNIT
value|0x17
end_define

begin_comment
comment|/* release unit */
end_comment

begin_comment
comment|/*	CMD_COPY		0x18	   copy (common to all scsi devs) */
end_comment

begin_define
define|#
directive|define
name|CMD_ERASE
value|0x19
end_define

begin_comment
comment|/* erase */
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
name|CMD_LOAD_UNLOAD
value|0x1b
end_define

begin_comment
comment|/* load/unload */
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
comment|/*  * Structure of READ, WRITE, READ REVERSE, RECOVER BUFFERED DATA  * commands (i.e., the cdb).  * Also used for VERIFY commands.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_rw
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x08 or 0x0a or 0x0f or 0x13 or 0x14 */
name|cdb_lun
range|:
literal|3
decl_stmt|,
comment|/* logical unit number */
name|cdb_xxx
range|:
literal|3
decl_stmt|,
comment|/* reserved */
name|cdb_bytecmp
range|:
literal|1
decl_stmt|,
comment|/* byte-by-byte comparison (VERIFY only) */
name|cdb_fixed
range|:
literal|1
decl_stmt|,
comment|/* fixed length blocks */
name|cdb_lenh
decl_stmt|,
comment|/* transfer length (MSB) */
name|cdb_lenm
decl_stmt|,
comment|/* transfer length */
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
comment|/*  * Structure of a TRACK SELECT command.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_ts
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x0b */
name|cdb_lun
range|:
literal|3
decl_stmt|,
comment|/* logical unit number */
name|cdb_xxx0
range|:
literal|5
decl_stmt|,
comment|/* reserved */
name|cdb_xxx1
decl_stmt|,
comment|/* reserved */
name|cdb_xxx2
decl_stmt|,
comment|/* reserved */
name|cdb_track
decl_stmt|,
comment|/* track value */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a WRITE FILEMARKS command.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_wfm
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x0b */
name|cdb_lun
range|:
literal|3
decl_stmt|,
comment|/* logical unit number */
name|cdb_xxx0
range|:
literal|5
decl_stmt|,
comment|/* reserved */
name|cdb_nfh
decl_stmt|,
comment|/* number of filemarks (MSB) */
name|cdb_nfm
decl_stmt|,
comment|/* number of filemarks */
name|cdb_nfl
decl_stmt|,
comment|/* number of filemarks (LSB) */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a SPACE command.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_space
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x0b */
name|cdb_lun
range|:
literal|3
decl_stmt|,
comment|/* logical unit number */
name|cdb_xxx0
range|:
literal|3
decl_stmt|,
comment|/* reserved */
name|cdb_code
range|:
literal|2
decl_stmt|,
comment|/* code (see below) */
name|cdb_counth
decl_stmt|,
comment|/* count (MSB) */
name|cdb_countm
decl_stmt|,
comment|/* count */
name|cdb_countl
decl_stmt|,
comment|/* count (LSB) */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSI_CMD_SPACE_BLOCKS
value|0
end_define

begin_comment
comment|/* skip blocks */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_SPACE_FMS
value|1
end_define

begin_comment
comment|/* skip file marks */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_SPACE_SFMS
value|2
end_define

begin_comment
comment|/* skip sequential file marks */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_SPACE_PEOD
value|3
end_define

begin_comment
comment|/* skip to physical end of data */
end_comment

begin_comment
comment|/*  * Mode Select parameters (data).  */
end_comment

begin_struct
struct|struct
name|scsi_msel
block|{
name|u_short
name|msel_xxx0
decl_stmt|;
comment|/* reserved */
name|u_char
name|msel_xxx1
range|:
literal|1
decl_stmt|,
comment|/* reserved */
name|msel_bm
range|:
literal|3
decl_stmt|,
comment|/* buffered mode */
name|msel_speed
range|:
literal|4
decl_stmt|,
comment|/* speed */
name|msel_bdl
decl_stmt|;
comment|/* block descriptor length */
struct|struct
name|scsi_msel_bdesc
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
name|msel_bd
index|[
literal|1
index|]
struct|;
comment|/* actually longer */
comment|/* followed by Vendor Unique bytes */
block|}
struct|;
end_struct

begin_comment
comment|/* buffered mode and speed */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_BM_UNBUFFERED
value|0
end_define

begin_comment
comment|/* unbuffered writes */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_BM_BUFFERED
value|1
end_define

begin_comment
comment|/* buffered writes allowed */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_SPEED_DEFAULT
value|0
end_define

begin_comment
comment|/* use device default speed */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_SPEED_LOW
value|1
end_define

begin_comment
comment|/* use lowest speed */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_SPEED_HIGH
value|15
end_define

begin_comment
comment|/* use highest speed */
end_comment

begin_comment
comment|/* density codes */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_DEFAULT
value|0
end_define

begin_comment
comment|/* use device default density */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_9T_800BPI
value|1
end_define

begin_comment
comment|/* 9 track, 800 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_9T_1600BPI
value|2
end_define

begin_comment
comment|/* 9 track, 1600 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_9T_6250BPI
value|3
end_define

begin_comment
comment|/* 9 track, 6250 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_QIC_XX1
value|4
end_define

begin_comment
comment|/* QIC-11? 4 or 9 track, 8000 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_QIC_XX2
value|5
end_define

begin_comment
comment|/* QIC-11? 4 or 9 track, 8000 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_9T_3200BPI
value|6
end_define

begin_comment
comment|/* 9 track, 3200 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_QIC_XX3
value|7
end_define

begin_comment
comment|/* QIC, 4 track, 6400 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_CS_XX4
value|8
end_define

begin_comment
comment|/* cassette 4 track, 8000 bpi 8/ #define	SCSI_MSEL_DC_HIC_XX5	9	/* half inch cartridge, 18 track */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_HIC_XX6
value|10
end_define

begin_comment
comment|/* HIC, 22 track, 6667 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_QIC_XX7
value|11
end_define

begin_comment
comment|/* QIC, 4 track, 1600 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_HIC_XX8
value|12
end_define

begin_comment
comment|/* HIC, 24 track, 12690 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DC_HIC_XX9
value|13
end_define

begin_comment
comment|/* HIC, 24 track, 25380 bpi */
end_comment

begin_comment
comment|/*  * Structure of an ERASE command.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_erase
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x0b */
name|cdb_lun
range|:
literal|3
decl_stmt|,
comment|/* logical unit number */
name|cdb_xxx0
range|:
literal|4
decl_stmt|,
comment|/* reserved */
name|cdb_long
range|:
literal|1
decl_stmt|,
comment|/* long erase */
name|cdb_xxx1
decl_stmt|,
comment|/* reserved */
name|cdb_xxx2
decl_stmt|,
comment|/* reserved */
name|cdb_xxx3
decl_stmt|,
comment|/* reserved */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a LOAD/UNLOAD command.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_lu
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x1b */
name|cdb_lun
range|:
literal|3
decl_stmt|,
comment|/* logical unit number */
name|cdb_xxx0
range|:
literal|4
decl_stmt|,
comment|/* reserved */
name|cdb_immed
range|:
literal|1
decl_stmt|,
comment|/* return status immediately */
name|cdb_xxx1
decl_stmt|,
comment|/* reserved */
name|cdb_xxx2
decl_stmt|,
comment|/* reserved */
name|cdb_xxx3
range|:
literal|6
decl_stmt|,
comment|/* reserved */
name|cdb_reten
range|:
literal|1
decl_stmt|,
comment|/* retension tape */
name|cdb_load
range|:
literal|1
decl_stmt|,
comment|/* load (else unload) */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

end_unit

