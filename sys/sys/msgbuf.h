begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1981, 1984, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)msgbuf.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MSGBUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MSGBUF_H_
end_define

begin_struct
struct|struct
name|msgbuf
block|{
name|char
modifier|*
name|msg_ptr
decl_stmt|;
comment|/* pointer to buffer */
define|#
directive|define
name|MSG_MAGIC
value|0x063062
name|u_int
name|msg_magic
decl_stmt|;
name|u_int
name|msg_size
decl_stmt|;
comment|/* size of buffer area */
name|u_int
name|msg_wseq
decl_stmt|;
comment|/* write sequence number */
name|u_int
name|msg_rseq
decl_stmt|;
comment|/* read sequence number */
name|u_int
name|msg_cksum
decl_stmt|;
comment|/* checksum of contents */
name|u_int
name|msg_seqmod
decl_stmt|;
comment|/* range for sequence numbers */
block|}
struct|;
end_struct

begin_comment
comment|/* Normalise a sequence number or a difference between sequence numbers. */
end_comment

begin_define
define|#
directive|define
name|MSGBUF_SEQNORM
parameter_list|(
name|mbp
parameter_list|,
name|seq
parameter_list|)
value|(((seq) + (mbp)->msg_seqmod) % \     (mbp)->msg_seqmod)
end_define

begin_define
define|#
directive|define
name|MSGBUF_SEQ_TO_POS
parameter_list|(
name|mbp
parameter_list|,
name|seq
parameter_list|)
value|((seq) % (mbp)->msg_size)
end_define

begin_comment
comment|/* Subtract sequence numbers.  Note that only positive values result. */
end_comment

begin_define
define|#
directive|define
name|MSGBUF_SEQSUB
parameter_list|(
name|mbp
parameter_list|,
name|seq1
parameter_list|,
name|seq2
parameter_list|)
value|(MSGBUF_SEQNORM((mbp), (seq1) - (seq2)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|msgbuftrigger
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|msgbuf
modifier|*
name|msgbufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|msgbuf_lock
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|msgbufinit
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msgbuf_addchar
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|mbp
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msgbuf_clear
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|mbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msgbuf_copy
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|src
parameter_list|,
name|struct
name|msgbuf
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgbuf_getbytes
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|mbp
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgbuf_getchar
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|mbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgbuf_getcount
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|mbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msgbuf_init
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|mbp
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgbuf_peekbytes
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|mbp
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|,
name|u_int
modifier|*
name|seqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msgbuf_reinit
parameter_list|(
name|struct
name|msgbuf
modifier|*
name|mbp
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|MSGBUF_SIZE
end_ifndef

begin_define
define|#
directive|define
name|MSGBUF_SIZE
value|(32768 * 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_MSGBUF_H_ */
end_comment

end_unit

