begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)uio.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UIO_
end_ifndef

begin_define
define|#
directive|define
name|_UIO_
end_define

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
name|off_t
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

begin_comment
comment|/*  * Segment flag values (should be enum).  */
end_comment

begin_define
define|#
directive|define
name|UIO_USERSPACE
value|0
end_define

begin_comment
comment|/* from user data space */
end_comment

begin_define
define|#
directive|define
name|UIO_SYSSPACE
value|1
end_define

begin_comment
comment|/* from system space */
end_comment

begin_define
define|#
directive|define
name|UIO_USERISPACE
value|2
end_define

begin_comment
comment|/* from user I space */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

