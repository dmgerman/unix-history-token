begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ah.h,v 1.12 2000/07/23 05:23:04 itojun Exp $	*/
end_comment

begin_comment
comment|/*	$KAME: ah.h,v 1.12 2000/07/20 17:41:01 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * RFC1826/2402 authentication header.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_AH_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_AH_H_
end_define

begin_struct
struct|struct
name|ah
block|{
name|u_int8_t
name|ah_nxt
decl_stmt|;
comment|/* Next Header */
name|u_int8_t
name|ah_len
decl_stmt|;
comment|/* Length of data, in 32bit */
name|u_int16_t
name|ah_reserve
decl_stmt|;
comment|/* Reserved for future use */
name|u_int32_t
name|ah_spi
decl_stmt|;
comment|/* Security parameter index */
comment|/* variable size, 32bit bound*/
comment|/* Authentication data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|newah
block|{
name|u_int8_t
name|ah_nxt
decl_stmt|;
comment|/* Next Header */
name|u_int8_t
name|ah_len
decl_stmt|;
comment|/* Length of data + 1, in 32bit */
name|u_int16_t
name|ah_reserve
decl_stmt|;
comment|/* Reserved for future use */
name|u_int32_t
name|ah_spi
decl_stmt|;
comment|/* Security parameter index */
name|u_int32_t
name|ah_seq
decl_stmt|;
comment|/* Sequence number field */
comment|/* variable size, 32bit bound*/
comment|/* Authentication data */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NETINET6_AH_H_*/
end_comment

end_unit

