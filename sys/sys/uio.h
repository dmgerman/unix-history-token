begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)uio.h	8.5 (Berkeley) 2/22/94  * $FreeBSD$  */
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

begin_comment
comment|/*  * XXX  * iov_base should be a void *.  */
end_comment

begin_struct
struct|struct
name|iovec
block|{
name|char
modifier|*
name|iov_base
decl_stmt|;
comment|/* Base address. */
name|size_t
name|iov_len
decl_stmt|;
comment|/* Length. */
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
comment|/* Segment flag values. */
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
block|,
comment|/* from user I space */
name|UIO_NOCOPY
comment|/* don't copy, already in object */
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
comment|/*  * Limits  */
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

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|uio_yield
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uiomove
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|uio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uiomoveco
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|uio
operator|*
operator|,
expr|struct
name|vm_object
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uioread
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|uio
operator|*
operator|,
expr|struct
name|vm_object
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|ssize_t
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
name|ssize_t
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UIO_H_ */
end_comment

end_unit

