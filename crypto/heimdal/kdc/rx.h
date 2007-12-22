begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: rx.h,v 1.4 1999/12/02 17:05:00 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RX_H__
end_ifndef

begin_define
define|#
directive|define
name|__RX_H__
end_define

begin_comment
comment|/* header of a RPC packet */
end_comment

begin_enum
enum|enum
name|rx_header_type
block|{
name|HT_DATA
init|=
literal|1
block|,
name|HT_ACK
init|=
literal|2
block|,
name|HT_BUSY
init|=
literal|3
block|,
name|HT_ABORT
init|=
literal|4
block|,
name|HT_ACKALL
init|=
literal|5
block|,
name|HT_CHAL
init|=
literal|6
block|,
name|HT_RESP
init|=
literal|7
block|,
name|HT_DEBUG
init|=
literal|8
block|}
enum|;
end_enum

begin_comment
comment|/* For flags in header */
end_comment

begin_enum
enum|enum
name|rx_header_flag
block|{
name|HF_CLIENT_INITIATED
init|=
literal|1
block|,
name|HF_REQ_ACK
init|=
literal|2
block|,
name|HF_LAST
init|=
literal|4
block|,
name|HF_MORE
init|=
literal|8
block|}
enum|;
end_enum

begin_struct
struct|struct
name|rx_header
block|{
name|u_int32_t
name|epoch
decl_stmt|;
name|u_int32_t
name|connid
decl_stmt|;
comment|/* And channel ID */
name|u_int32_t
name|callid
decl_stmt|;
name|u_int32_t
name|seqno
decl_stmt|;
name|u_int32_t
name|serialno
decl_stmt|;
name|u_char
name|type
decl_stmt|;
name|u_char
name|flags
decl_stmt|;
name|u_char
name|status
decl_stmt|;
name|u_char
name|secindex
decl_stmt|;
name|u_int16_t
name|reserved
decl_stmt|;
comment|/* ??? verifier? */
name|u_int16_t
name|serviceid
decl_stmt|;
comment|/* This should be the other way around according to everything but */
comment|/* tcpdump */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RX_HEADER_SIZE
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RX_H__ */
end_comment

end_unit

