begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1984, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)msgbuf.h	8.1 (Berkeley) %G%  */
end_comment

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
define|#
directive|define
name|MSG_MAGIC
value|0x063061
name|long
name|msg_magic
decl_stmt|;
name|long
name|msg_bufx
decl_stmt|;
comment|/* write pointer */
name|long
name|msg_bufr
decl_stmt|;
comment|/* read pointer */
name|char
name|msg_bufc
index|[
name|MSG_BSIZE
index|]
decl_stmt|;
comment|/* buffer */
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
modifier|*
name|msgbufp
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

