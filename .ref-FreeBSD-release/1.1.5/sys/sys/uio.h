begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)uio.h	7.8 (Berkeley) 4/15/91  *	$Id: uio.h,v 1.2 1993/10/16 17:18:15 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_UIO_H_
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|uiomove
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NB: argument cannot be properly declared because this function is often  * called with arguments not matching the appropriate type.  The actual  * type of the first argument is `int (*)(caddr_t, caddr_t, caddr_t, off_t,  * enum uio_rw, caddr_t, u_int *, struct proc *)'.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|uioapply_func_t
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|,
name|off_t
parameter_list|,
name|enum
name|uio_rw
parameter_list|,
name|caddr_t
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|uioapply
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ureadc
parameter_list|(
name|int
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not KERNEL */
end_comment

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
comment|/* !_UIO_H_ */
end_comment

end_unit

