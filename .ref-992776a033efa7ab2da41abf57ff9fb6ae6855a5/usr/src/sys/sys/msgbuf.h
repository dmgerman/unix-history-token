begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	msgbuf.h	4.5	81/08/31	*/
end_comment

begin_define
define|#
directive|define
name|MSG_MAGIC
value|0x063060
end_define

begin_define
define|#
directive|define
name|MSG_BSIZE
value|(4096 - 2 * sizeof (long))
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

