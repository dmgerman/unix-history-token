begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)uio.h	8.5 (Berkeley) 2/22/94  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/_iovec.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SSIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ssize_t
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SSIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_OFF_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__off_t
name|off_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_OFF_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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
name|UIO_NOCOPY
comment|/* don't copy, already in object */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* scatter/gather list */
name|int
name|uio_iovcnt
decl_stmt|;
comment|/* length of scatter/gather list */
name|off_t
name|uio_offset
decl_stmt|;
comment|/* offset in target object */
name|int
name|uio_resid
decl_stmt|;
comment|/* remaining bytes to process */
name|enum
name|uio_seg
name|uio_segflg
decl_stmt|;
comment|/* address space */
name|enum
name|uio_rw
name|uio_rw
decl_stmt|;
comment|/* operation */
name|struct
name|thread
modifier|*
name|uio_td
decl_stmt|;
comment|/* owner */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Limits  *  * N.B.: UIO_MAXIOV must be no less than IOV_MAX from<sys/syslimits.h>  * which in turn must be no less than _XOPEN_IOV_MAX from<limits.h>.  If  * we ever make this tunable (probably pointless), then IOV_MAX should be  * removed from<sys/syslimits.h> and applications would be expected to use  * sysconf(3) to find out the correct value, or else assume the worst  * (_XOPEN_IOV_MAX).  Perhaps UIO_MAXIOV should be simply defined as  * IOV_MAX.  */
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

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vm_page
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|uio
modifier|*
name|cloneuio
parameter_list|(
name|struct
name|uio
modifier|*
name|uiop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyinfrom
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
name|src
parameter_list|,
name|void
modifier|*
name|__restrict
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|seg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyiniov
parameter_list|(
name|struct
name|iovec
modifier|*
name|iovp
parameter_list|,
name|u_int
name|iovcnt
parameter_list|,
name|struct
name|iovec
modifier|*
modifier|*
name|iov
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyinstrfrom
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
name|src
parameter_list|,
name|void
modifier|*
name|__restrict
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
modifier|*
name|__restrict
name|copied
parameter_list|,
name|int
name|seg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copyinuio
parameter_list|(
name|struct
name|iovec
modifier|*
name|iovp
parameter_list|,
name|u_int
name|iovcnt
parameter_list|,
name|struct
name|uio
modifier|*
modifier|*
name|uiop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uio_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uiomove
parameter_list|(
name|void
modifier|*
name|cp
parameter_list|,
name|int
name|n
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uiomove_frombuf
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uiomove_fromphys
parameter_list|(
name|struct
name|vm_page
modifier|*
name|ma
index|[]
parameter_list|,
name|vm_offset_t
name|offset
parameter_list|,
name|int
name|n
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uiomoveco
parameter_list|(
name|void
modifier|*
name|cp
parameter_list|,
name|int
name|n
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|disposable
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|ssize_t
name|readv
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|writev
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|preadv
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|pwritev
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

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

