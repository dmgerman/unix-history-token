begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)disktape.h	5.2 (Berkeley) %G%  *  * from: $Header: disktape.h,v 1.2 92/05/15 11:24:00 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Commands common to disk and tape devices, but not other SCSI devices.  */
end_comment

begin_comment
comment|/*  * Structure of a MODE SENSE command (i.e., the cdb).  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_modesense
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* command */
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
name|cdb_len
decl_stmt|,
comment|/* allocation length */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of returned mode sense data.  */
end_comment

begin_struct
struct|struct
name|scsi_modesense
block|{
name|u_char
name|ms_len
decl_stmt|,
comment|/* total sense data length */
name|ms_mt
decl_stmt|,
comment|/* medium type */
name|ms_wbs
decl_stmt|,
comment|/* write protect, buffered mode,& speed */
name|ms_bdl
decl_stmt|;
comment|/* block descriptor length */
struct|struct
name|scsi_ms_bdesc
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
comment|/* followed by Vendor Unique bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a PREVENT/ALLOW MEDIUM REMOVAL command.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_pamr
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x1e */
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
name|cdb_prevent
decl_stmt|,
comment|/* 1=prevent, 0=allow */
name|cdb_ctrl
decl_stmt|;
block|}
struct|;
end_struct

end_unit

