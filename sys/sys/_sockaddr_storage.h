begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1982, 1985, 1986, 1988, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socket.h	8.4 (Berkeley) 2/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__SOCKADDR_STORAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__SOCKADDR_STORAGE_H_
end_define

begin_comment
comment|/*  * RFC 2553: protocol-independent placeholder for socket addresses  */
end_comment

begin_define
define|#
directive|define
name|_SS_MAXSIZE
value|128U
end_define

begin_define
define|#
directive|define
name|_SS_ALIGNSIZE
value|(sizeof(__int64_t))
end_define

begin_define
define|#
directive|define
name|_SS_PAD1SIZE
value|(_SS_ALIGNSIZE - sizeof(unsigned char) - \ 			    sizeof(sa_family_t))
end_define

begin_define
define|#
directive|define
name|_SS_PAD2SIZE
value|(_SS_MAXSIZE - sizeof(unsigned char) - \ 			    sizeof(sa_family_t) - _SS_PAD1SIZE - _SS_ALIGNSIZE)
end_define

begin_struct
struct|struct
name|sockaddr_storage
block|{
name|unsigned
name|char
name|ss_len
decl_stmt|;
comment|/* address length */
name|sa_family_t
name|ss_family
decl_stmt|;
comment|/* address family */
name|char
name|__ss_pad1
index|[
name|_SS_PAD1SIZE
index|]
decl_stmt|;
name|__int64_t
name|__ss_align
decl_stmt|;
comment|/* force desired struct alignment */
name|char
name|__ss_pad2
index|[
name|_SS_PAD2SIZE
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
comment|/* !_SYS__SOCKADDR_STORAGE_H_ */
end_comment

end_unit

