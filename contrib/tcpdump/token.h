begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998, Larry Lile  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_define
define|#
directive|define
name|TOKEN_HDR_LEN
value|14
end_define

begin_define
define|#
directive|define
name|IS_SOURCE_ROUTED
value|(tp->ether_shost[0]& 0x80)
end_define

begin_define
define|#
directive|define
name|RIF_LENGTH
value|((ntohs(tp->rcf)& 0x1f00)>> 8)
end_define

begin_define
define|#
directive|define
name|TOKEN_RING_MAC_LEN
value|6
end_define

begin_define
define|#
directive|define
name|ROUTING_SEGMENT_MAX
value|16
end_define

begin_struct
struct|struct
name|token_header
block|{
name|u_char
name|ac
decl_stmt|;
name|u_char
name|fc
decl_stmt|;
name|u_char
name|ether_dhost
index|[
name|TOKEN_RING_MAC_LEN
index|]
decl_stmt|;
name|u_char
name|ether_shost
index|[
name|TOKEN_RING_MAC_LEN
index|]
decl_stmt|;
name|u_short
name|rcf
decl_stmt|;
name|u_short
name|rseg
index|[
name|ROUTING_SEGMENT_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

