begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Lawrence Berkeley Laboratory,  * Berkeley, CA.  The name of the University may not be used to  * endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: kgdb_proto.h,v 1.1 91/01/10 16:49:43 mccanne Exp $ (LBL)  */
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

end_unit

