begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	uio.h	6.1	83/07/29	*/
end_comment

begin_struct
struct|struct
name|iovec
block|{
name|caddr_t
name|iov_base
decl_stmt|;
name|int
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uio
block|{
name|struct
name|iovec
modifier|*
name|uio_iov
decl_stmt|;
name|int
name|uio_iovcnt
decl_stmt|;
name|int
name|uio_offset
decl_stmt|;
name|int
name|uio_segflg
decl_stmt|;
name|int
name|uio_resid
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|uio_rw
block|{
name|UIO_READ
block|,
name|UIO_WRITE
block|}
enum|;
end_enum

end_unit

