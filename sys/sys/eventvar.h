begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000 Jonathan Lemon<jlemon@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EVENTVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EVENTVAR_H_
end_define

begin_define
define|#
directive|define
name|KQ_NEVENTS
value|8
end_define

begin_comment
comment|/* minimize copy{in,out} calls */
end_comment

begin_define
define|#
directive|define
name|KQEXTENT
value|256
end_define

begin_comment
comment|/* linear growth by this amount */
end_comment

begin_struct
struct|struct
name|kqueue
block|{
name|TAILQ_HEAD
argument_list|(
argument|kqlist
argument_list|,
argument|knote
argument_list|)
name|kq_head
expr_stmt|;
comment|/* list of pending event */
name|int
name|kq_count
decl_stmt|;
comment|/* number of pending events */
name|struct
name|selinfo
name|kq_sel
decl_stmt|;
name|struct
name|filedesc
modifier|*
name|kq_fdp
decl_stmt|;
name|int
name|kq_state
decl_stmt|;
define|#
directive|define
name|KQ_SEL
value|0x01
define|#
directive|define
name|KQ_SLEEP
value|0x02
name|struct
name|kevent
name|kq_kev
index|[
name|KQ_NEVENTS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_EVENTVAR_H_ */
end_comment

end_unit

