begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)kgdb_proto.h	7.3 (Berkeley) %G%  *  * from: $Header: kgdb_proto.h,v 1.5 92/11/26 03:04:54 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Message types.  */
end_comment

begin_define
define|#
directive|define
name|KGDB_MEM_R
value|0x01
end_define

begin_define
define|#
directive|define
name|KGDB_MEM_W
value|0x02
end_define

begin_define
define|#
directive|define
name|KGDB_REG_R
value|0x03
end_define

begin_define
define|#
directive|define
name|KGDB_REG_W
value|0x04
end_define

begin_define
define|#
directive|define
name|KGDB_CONT
value|0x05
end_define

begin_define
define|#
directive|define
name|KGDB_STEP
value|0x06
end_define

begin_define
define|#
directive|define
name|KGDB_KILL
value|0x07
end_define

begin_define
define|#
directive|define
name|KGDB_SIGNAL
value|0x08
end_define

begin_define
define|#
directive|define
name|KGDB_EXEC
value|0x09
end_define

begin_define
define|#
directive|define
name|KGDB_CMD
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0f)
end_define

begin_comment
comment|/*  * Message flags.  */
end_comment

begin_define
define|#
directive|define
name|KGDB_ACK
value|0x80
end_define

begin_define
define|#
directive|define
name|KGDB_DELTA
value|0x40
end_define

begin_define
define|#
directive|define
name|KGDB_MORE
value|0x20
end_define

begin_define
define|#
directive|define
name|KGDB_SEQ
value|0x10
end_define

end_unit

