begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ipcomp.h,v 1.8 2000/09/26 07:55:14 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * RFC2393 IP payload compression protocol (IPComp).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_IPCOMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_IPCOMP_H_
end_define

begin_struct
struct|struct
name|ipcomp
block|{
name|u_int8_t
name|comp_nxt
decl_stmt|;
comment|/* Next Header */
name|u_int8_t
name|comp_flags
decl_stmt|;
comment|/* reserved, must be zero */
name|u_int16_t
name|comp_cpi
decl_stmt|;
comment|/* Compression parameter index */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPCOMP_HLENGTH
value|4
end_define

begin_comment
comment|/* Length of IPCOMP header */
end_comment

begin_comment
comment|/* well-known algorithm number (in CPI), from RFC2409 */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_OUI
value|1
end_define

begin_comment
comment|/* vendor specific */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_DEFLATE
value|2
end_define

begin_comment
comment|/* RFC2394 */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_LZS
value|3
end_define

begin_comment
comment|/* RFC2395 */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_MAX
value|4
end_define

begin_define
define|#
directive|define
name|IPCOMP_CPI_NEGOTIATE_MIN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NETIPSEC_IPCOMP_H_*/
end_comment

end_unit

