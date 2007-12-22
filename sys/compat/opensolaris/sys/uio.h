begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_UIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_UIO_H_
end_define

begin_empty
empty|#include_next<sys/uio.h>
end_empty

begin_include
include|#
directive|include
file|<sys/debug.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|FOF_OFFSET
value|1
end_define

begin_comment
comment|/* Use the offset in uio argument */
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
name|uio_seg
name|uio_segflg
decl_stmt|;
name|enum
name|uio_rw
name|uio_rw
decl_stmt|;
name|void
modifier|*
name|uio_td
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|uio
name|uio_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|iovec
name|iovec_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|uio_loffset
value|uio_offset
end_define

begin_function
specifier|static
name|__inline
name|int
name|zfs_uiomove
parameter_list|(
name|void
modifier|*
name|cp
parameter_list|,
name|size_t
name|n
parameter_list|,
name|enum
name|uio_rw
name|dir
parameter_list|,
name|uio_t
modifier|*
name|uio
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|uio
operator|->
name|uio_rw
operator|==
name|dir
argument_list|)
expr_stmt|;
return|return
operator|(
name|uiomove
argument_list|(
name|cp
argument_list|,
operator|(
name|int
operator|)
name|n
argument_list|,
name|uio
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|uiomove
parameter_list|(
name|cp
parameter_list|,
name|n
parameter_list|,
name|dir
parameter_list|,
name|uio
parameter_list|)
value|zfs_uiomove((cp), (n), (dir), (uio))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_SYS_UIO_H_ */
end_comment

end_unit

