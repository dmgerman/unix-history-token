begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  BUF.H -- buffer definitions ** **	Version: **		@(#)buf.h	7.1	2/5/81 */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|256
end_define

begin_struct
struct|struct
name|buf
block|{
name|struct
name|buf
modifier|*
name|nextb
decl_stmt|;
name|char
name|buffer
index|[
name|BUFSIZE
index|]
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

