begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Adrian Chadd, Xenion Lty Ltd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IEEE80211_ALQ_H__
end_ifndef

begin_define
define|#
directive|define
name|__IEEE80211_ALQ_H__
end_define

begin_define
define|#
directive|define
name|IEEE80211_ALQ_MAX_PAYLOAD
value|1024
end_define

begin_comment
comment|/*  * timestamp  * wlan interface  * operation  * sub-operation  * rest of structure - operation specific  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ALQ_SRC_NET80211
value|0x0001
end_define

begin_comment
comment|/* Drivers define their own numbers above 0xff */
end_comment

begin_struct
struct|struct
name|ieee80211_alq_rec
block|{
name|uint64_t
name|r_timestamp
decl_stmt|;
comment|/* XXX may wrap! */
name|uint32_t
name|r_threadid
decl_stmt|;
comment|/* current thread id */
name|uint16_t
name|r_wlan
decl_stmt|;
comment|/* wlan interface number */
name|uint16_t
name|r_src
decl_stmt|;
comment|/* source - driver, net80211 */
name|uint32_t
name|r_flags
decl_stmt|;
comment|/* flags */
name|uint32_t
name|r_op
decl_stmt|;
comment|/* top-level operation id */
name|uint32_t
name|r_len
decl_stmt|;
comment|/* length of hdr + payload */
comment|/* Operation payload follows here */
block|}
struct|;
end_struct

begin_comment
comment|/* General logging function */
end_comment

begin_function_decl
specifier|extern
name|int
name|ieee80211_alq_log
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|uint32_t
name|op
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|uint16_t
name|srcid
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IEEE80211_ALQ_H__ */
end_comment

end_unit

