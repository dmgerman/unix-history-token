begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* YIPS @(#)$Id: var.h,v 1.1 1999/10/29 09:04:54 jinmei Exp $ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_VAR_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_define
define|#
directive|define
name|MAX3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a> b ? (a> c ? a : c) : (b> c ? b : c))
end_define

begin_define
define|#
directive|define
name|CALLOC
parameter_list|(
name|size
parameter_list|,
name|cast
parameter_list|)
value|(cast)calloc(1, (size))
end_define

begin_define
define|#
directive|define
name|ISSET
parameter_list|(
name|exp
parameter_list|,
name|bit
parameter_list|)
value|(((exp)& (bit)) == (bit))
end_define

begin_define
define|#
directive|define
name|ATOX
parameter_list|(
name|c
parameter_list|)
define|\
value|(isdigit(c) ? (c - '0') : (isupper(c) ? (c - 'A' + 10) : (c - 'a' + 10) ))
end_define

begin_define
define|#
directive|define
name|LALIGN
parameter_list|(
name|a
parameter_list|)
define|\
value|((a)> 0 ? ((a)&~ (sizeof(long) - 1)) : sizeof(long))
end_define

begin_define
define|#
directive|define
name|RNDUP
parameter_list|(
name|a
parameter_list|)
define|\
value|((a)> 0 ? (1 + (((a) - 1) | (sizeof(long) - 1))) : sizeof(long))
end_define

begin_define
define|#
directive|define
name|BUFADDRSIZE
value|128
end_define

begin_define
define|#
directive|define
name|INET_NTOP
parameter_list|(
name|addr
parameter_list|,
name|buf
parameter_list|)
define|\
value|inet_ntop(((struct sockaddr *)(addr))->sa_family, _INADDRBYSA(addr), buf, sizeof(buf))
end_define

begin_define
define|#
directive|define
name|GETNAMEINFO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|getnameinfo((x), (x)->sa_len, (y), sizeof(y), (z), sizeof(z), \ 		NI_NUMERICHOST | NI_NUMERICSERV)
end_define

begin_define
define|#
directive|define
name|ARRAYSIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a)/sizeof(a[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!defined(_VAR_H_)*/
end_comment

end_unit

