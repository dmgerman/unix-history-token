begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)msgbuf.h	7.1 (Berkeley) 6/4/86  */
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
value|(4096 - 3 * sizeof (long))
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

