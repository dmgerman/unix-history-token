begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)printer.h	5.3 (Berkeley) %G%  *  * from: $Header: printer.h,v 1.3 92/12/02 03:52:03 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI definitions for Printer Devices.  */
end_comment

begin_define
define|#
directive|define
name|CMD_FORMAT
value|0x04
end_define

begin_comment
comment|/* (set) format */
end_comment

begin_define
define|#
directive|define
name|CMD_PRINT
value|0x0a
end_define

begin_comment
comment|/* print */
end_comment

begin_define
define|#
directive|define
name|CMD_SLEW_PRINT
value|0x0b
end_define

begin_comment
comment|/* slew and print */
end_comment

begin_define
define|#
directive|define
name|CMD_FLUSH_BUFFER
value|0x10
end_define

begin_comment
comment|/* flush buffer */
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
name|CMD_STOP_PRINT
value|0x1b
end_define

begin_comment
comment|/* stop print */
end_comment

end_unit

