begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1984 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)msgbuf.h	7.2 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|MSG_MAGIC
value|0x063061
end_define

begin_define
define|#
directive|define
name|MSG_BSIZE
value|(4096 - 3 * sizeof(long))
end_define

begin_struct
struct|struct
name|msgbuf
block|{
name|long
name|msg_magic
decl_stmt|;
name|long
name|msg_bufx
decl_stmt|;
name|long
name|msg_bufr
decl_stmt|;
name|char
name|msg_bufc
index|[
name|MSG_BSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|msgbuf
name|msgbuf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

