begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.2 $ ** **  Minimal<sys/uio.h> file for systems without one. */
end_comment

begin_struct
struct|struct
name|iovec
block|{
name|char
modifier|*
name|iov_base
decl_stmt|;
name|int
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

end_unit

