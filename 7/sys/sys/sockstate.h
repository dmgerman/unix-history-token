begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socketvar.h	8.3 (Berkeley) 2/19/95  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKTATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SOCKTATE_H_
end_define

begin_comment
comment|/*  * Socket state bits.  *  * Historically, this bits were all kept in the so_state field.  For  * locking reasons, they are now in multiple fields, as they are  * locked differently.  so_state maintains basic socket state protected  * by the socket lock.  so_qstate holds information about the socket  * accept queues.  Each socket buffer also has a state field holding  * information relevant to that socket buffer (can't send, rcv).  Many  * fields will be read without locks to improve performance and avoid  * lock order issues.  However, this approach must be used with caution.  */
end_comment

begin_define
define|#
directive|define
name|SS_NOFDREF
value|0x0001
end_define

begin_comment
comment|/* no file table ref any more */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTED
value|0x0002
end_define

begin_comment
comment|/* socket connected to a peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTING
value|0x0004
end_define

begin_comment
comment|/* in process of connecting to peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISDISCONNECTING
value|0x0008
end_define

begin_comment
comment|/* in process of disconnecting */
end_comment

begin_define
define|#
directive|define
name|SS_NBIO
value|0x0100
end_define

begin_comment
comment|/* non-blocking ops */
end_comment

begin_define
define|#
directive|define
name|SS_ASYNC
value|0x0200
end_define

begin_comment
comment|/* async i/o notify */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONFIRMING
value|0x0400
end_define

begin_comment
comment|/* deciding to accept connection req */
end_comment

begin_define
define|#
directive|define
name|SS_ISDISCONNECTED
value|0x2000
end_define

begin_comment
comment|/* socket disconnected from peer */
end_comment

begin_comment
comment|/*  * Protocols can mark a socket as SS_PROTOREF to indicate that, following  * pru_detach, they still want the socket to persist, and will free it  * themselves when they are done.  Protocols should only ever call sofree()  * following setting this flag in pru_detach(), and never otherwise, as  * sofree() bypasses socket reference counting.  */
end_comment

begin_define
define|#
directive|define
name|SS_PROTOREF
value|0x4000
end_define

begin_comment
comment|/* strong protocol reference */
end_comment

begin_comment
comment|/*  * Socket state bits now stored in the socket buffer state field.  */
end_comment

begin_define
define|#
directive|define
name|SBS_CANTSENDMORE
value|0x0010
end_define

begin_comment
comment|/* can't send more data to peer */
end_comment

begin_define
define|#
directive|define
name|SBS_CANTRCVMORE
value|0x0020
end_define

begin_comment
comment|/* can't receive more data from peer */
end_comment

begin_define
define|#
directive|define
name|SBS_RCVATMARK
value|0x0040
end_define

begin_comment
comment|/* at mark on input */
end_comment

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|soisconnected
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisconnecting
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisdisconnected
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisdisconnecting
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantrcvmore
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantrcvmore_locked
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantsendmore
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantsendmore_locked
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SOCKTATE_H_ */
end_comment

end_unit

