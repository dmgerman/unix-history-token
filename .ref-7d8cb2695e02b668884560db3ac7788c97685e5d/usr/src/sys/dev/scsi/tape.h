begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)tape.h	5.3 (Berkeley) %G%  *  * from: $Header: tape.h,v 1.3 92/12/02 03:53:14 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI definitions for Sequential Access Devices (tapes).  *  * Commands defined in common headers (scsi.h or disktape.h) are omitted.  */
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
name|cdb_lun_bf
decl_stmt|,
comment|/* LUN + reserved + bytecmp + fixed */
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

begin_define
define|#
directive|define
name|SCSI_RW_BYTECMP
value|0x02
end_define

begin_comment
comment|/* byte compare flag if verify */
end_comment

begin_define
define|#
directive|define
name|SCSI_RW_FIXEDBLK
value|0x01
end_define

begin_comment
comment|/* fixed block size for read/write */
end_comment

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
name|cdb_lun_xxx
decl_stmt|,
comment|/* logical unit number + reserved */
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
name|cdb_lun_xxx
decl_stmt|,
comment|/* logical unit number + reserved */
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
name|cdb_lun_code
decl_stmt|,
comment|/* LUN + reserved + 2-bit code */
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
name|cdb_lun_long
decl_stmt|,
comment|/* LUN + reserved + long-erase flag */
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
name|cdb_lun_immed
decl_stmt|,
comment|/* LUN + reserved + immediate flag */
name|cdb_xxx1
decl_stmt|,
comment|/* reserved */
name|cdb_xxx2
decl_stmt|,
comment|/* reserved */
name|cdb_rl
decl_stmt|,
comment|/* reserved + retension flag + load flag */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSI_LU_RL_RETEN
value|0x02
end_define

begin_comment
comment|/* retension */
end_comment

begin_define
define|#
directive|define
name|SCSI_LU_RL_LOAD
value|0x01
end_define

begin_comment
comment|/* load */
end_comment

begin_define
define|#
directive|define
name|SCSI_LU_RL_UNLOAD
value|0x00
end_define

begin_comment
comment|/* unload (pseudo flag) */
end_comment

end_unit

