begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999-2000 by Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * BASED ON:  * -------------------------------------------------------------------------  *  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Copyright (c) 1988, Julian Onions<jpo@cs.nott.ac.uk>  * Nottingham University 1987.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  * $Id: if_tapvar.h,v 0.6 2000/07/11 02:16:08 max Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_TAPVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_TAPVAR_H_
end_define

begin_struct
struct|struct
name|tap_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* ethernet common data      */
define|#
directive|define
name|tap_if
value|arpcom.ac_if
name|dev_t
name|tap_dev
decl_stmt|;
comment|/* device                    */
name|u_short
name|tap_flags
decl_stmt|;
comment|/* misc flags                */
define|#
directive|define
name|TAP_OPEN
value|(1<< 0)
define|#
directive|define
name|TAP_INITED
value|(1<< 1)
define|#
directive|define
name|TAP_RWAIT
value|(1<< 2)
define|#
directive|define
name|TAP_ASYNC
value|(1<< 3)
define|#
directive|define
name|TAP_READY
value|(TAP_OPEN|TAP_INITED)
define|#
directive|define
name|TAP_VMNET
value|(1<< 4)
name|u_int8_t
name|ether_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* ether addr of the remote side */
name|pid_t
name|tap_pid
decl_stmt|;
comment|/* PID of process to open    */
name|struct
name|sigio
modifier|*
name|tap_sigio
decl_stmt|;
comment|/* information for async I/O */
name|struct
name|selinfo
name|tap_rsel
decl_stmt|;
comment|/* read select               */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_TAPVAR_H_ */
end_comment

end_unit

