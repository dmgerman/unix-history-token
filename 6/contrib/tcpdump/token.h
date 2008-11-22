begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/token.h,v 1.6 2002/12/11 07:14:12 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998, Larry Lile  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|TOKEN_HDRLEN
value|14
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

begin_define
define|#
directive|define
name|IS_SOURCE_ROUTED
parameter_list|(
name|trp
parameter_list|)
value|((trp)->token_shost[0]& 0x80)
end_define

begin_define
define|#
directive|define
name|FRAME_TYPE
parameter_list|(
name|trp
parameter_list|)
value|(((trp)->token_fc& 0xC0)>> 6)
end_define

begin_define
define|#
directive|define
name|TOKEN_FC_LLC
value|1
end_define

begin_define
define|#
directive|define
name|BROADCAST
parameter_list|(
name|trp
parameter_list|)
value|((ntohs((trp)->token_rcf)& 0xE000)>> 13)
end_define

begin_define
define|#
directive|define
name|RIF_LENGTH
parameter_list|(
name|trp
parameter_list|)
value|((ntohs((trp)->token_rcf)& 0x1f00)>> 8)
end_define

begin_define
define|#
directive|define
name|DIRECTION
parameter_list|(
name|trp
parameter_list|)
value|((ntohs((trp)->token_rcf)& 0x0080)>> 7)
end_define

begin_define
define|#
directive|define
name|LARGEST_FRAME
parameter_list|(
name|trp
parameter_list|)
value|((ntohs((trp)->token_rcf)& 0x0070)>> 4)
end_define

begin_define
define|#
directive|define
name|RING_NUMBER
parameter_list|(
name|trp
parameter_list|,
name|x
parameter_list|)
value|((ntohs((trp)->token_rseg[x])& 0xfff0)>> 4)
end_define

begin_define
define|#
directive|define
name|BRIDGE_NUMBER
parameter_list|(
name|trp
parameter_list|,
name|x
parameter_list|)
value|((ntohs((trp)->token_rseg[x])& 0x000f))
end_define

begin_define
define|#
directive|define
name|SEGMENT_COUNT
parameter_list|(
name|trp
parameter_list|)
value|((int)((RIF_LENGTH(trp) - 2) / 2))
end_define

begin_struct
struct|struct
name|token_header
block|{
name|u_int8_t
name|token_ac
decl_stmt|;
name|u_int8_t
name|token_fc
decl_stmt|;
name|u_int8_t
name|token_dhost
index|[
name|TOKEN_RING_MAC_LEN
index|]
decl_stmt|;
name|u_int8_t
name|token_shost
index|[
name|TOKEN_RING_MAC_LEN
index|]
decl_stmt|;
name|u_int16_t
name|token_rcf
decl_stmt|;
name|u_int16_t
name|token_rseg
index|[
name|ROUTING_SEGMENT_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

