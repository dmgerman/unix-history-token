begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)uio.h	6.4 (Berkeley) 2/23/86  */
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

begin_comment
comment|/*  * Description of an I/O operation which potentially  * involves scatter-gather, with individual sections  * described by iovec, below.  uio_resid is initially  * set to the total size of the operation, and is  * decremented as the operation proceeds.  uio_offset  * is incremented by the amount of each operation.  * uio_iov is incremented and uio_iovcnt is decremented  * after each vector is processed.  */
end_comment

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
name|uio_rw
name|uio_rw
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
comment|/*  * Description of a contiguous section of an I/O operation.  * If iov_op is non-null, it is called to implement the copy  * operation, possibly by remapping, with the call  *	(*iov_op)(from, to, count);  * where from and to are caddr_t and count is int.  * Otherwise, the copy is done in the normal way,  * treating base as a user or kernel virtual address  * according to iov_segflg.  */
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
name|enum
name|uio_seg
name|iov_segflg
decl_stmt|;
name|int
function_decl|(
modifier|*
name|iov_op
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

