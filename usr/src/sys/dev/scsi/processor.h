begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)processor.h	5.3 (Berkeley) %G%  *  * from: $Header: processor.h,v 1.3 92/12/02 03:52:27 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI definitions for Processor Devices.  */
end_comment

begin_define
define|#
directive|define
name|CMD_RECEIVE
value|0x08
end_define

begin_comment
comment|/* receive */
end_comment

begin_define
define|#
directive|define
name|CMD_SEND
value|0x0a
end_define

begin_comment
comment|/* send */
end_comment

begin_comment
comment|/*  * Structure of a RECEIVE or SEND command (i.e., the cdb).  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_rs
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x8 or 0xa */
name|cdb_lun_xxx
decl_stmt|,
comment|/* logical unit number + reserved */
name|cdb_lenh
decl_stmt|,
comment|/* buffer or data length (MSB) */
name|cdb_lenm
decl_stmt|,
comment|/* buffer or data length */
name|cdb_lenl
decl_stmt|,
comment|/* buffer or data length (LSB) */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

end_unit

