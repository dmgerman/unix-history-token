begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Portions of this software were developed under sponsorship from Snow  * B.V., the Netherlands.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTYDISC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTYDISC_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTY_H_
end_ifndef

begin_error
error|#
directive|error
literal|"can only be included through<sys/tty.h>"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTY_H_ */
end_comment

begin_struct_decl
struct_decl|struct
name|cv
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tty
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/* Top half routines. */
end_comment

begin_function_decl
name|void
name|ttydisc_open
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ttydisc_close
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ttydisc_read
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ttydisc_write
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ttydisc_optimize
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Bottom half routines. */
end_comment

begin_function_decl
name|void
name|ttydisc_modem
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|open
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ttydisc_can_bypass
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_flags& TF_BYPASS)
end_define

begin_function_decl
name|int
name|ttydisc_rint
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|char
name|c
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ttydisc_rint_simple
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ttydisc_rint_bypass
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ttydisc_rint_done
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ttydisc_rint_poll
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ttydisc_getc
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ttydisc_getc_uio
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ttydisc_getc_poll
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Error codes for ttydisc_rint(). */
end_comment

begin_define
define|#
directive|define
name|TRE_FRAMING
value|0x01
end_define

begin_define
define|#
directive|define
name|TRE_PARITY
value|0x02
end_define

begin_define
define|#
directive|define
name|TRE_OVERRUN
value|0x04
end_define

begin_define
define|#
directive|define
name|TRE_BREAK
value|0x08
end_define

begin_function
specifier|static
name|__inline
name|size_t
name|ttydisc_read_poll
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
block|{
name|tty_lock_assert
argument_list|(
name|tp
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
return|return
name|ttyinq_bytescanonicalized
argument_list|(
operator|&
name|tp
operator|->
name|t_inq
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|size_t
name|ttydisc_write_poll
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
block|{
name|tty_lock_assert
argument_list|(
name|tp
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
return|return
name|ttyoutq_bytesleft
argument_list|(
operator|&
name|tp
operator|->
name|t_outq
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTYDISC_H_ */
end_comment

end_unit

