begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)uio.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UIO_H_
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
comment|/*  * Segment flag values.  */
end_comment

begin_enum
enum|enum
name|uio_seg
block|{
name|UIO_USERSPACE
block|,
comment|/* from user data space */
name|UIO_SYSSPACE
block|,
comment|/* from system space */
name|UIO_USERISPACE
comment|/* from user I space */
block|}
enum|;
end_enum

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
name|uio_resid
decl_stmt|;
name|enum
name|uio_seg
name|uio_segflg
decl_stmt|;
name|enum
name|uio_rw
name|uio_rw
decl_stmt|;
name|struct
name|proc
modifier|*
name|uio_procp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * Limits   */
end_comment

begin_define
define|#
directive|define
name|UIO_MAXIOV
value|1024
end_define

begin_comment
comment|/* max 1K of iov's */
end_comment

begin_define
define|#
directive|define
name|UIO_SMALLIOV
value|8
end_define

begin_comment
comment|/* 8 on stack, else malloc */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|readv
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|iovec
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|writev
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|iovec
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UIO_H_ */
end_comment

end_unit

