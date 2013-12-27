begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sdp-int.h  *  * Copyright (c) 2001-2003 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: sdp-int.h,v 1.1 2003/09/01 23:01:07 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SDP_INT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SDP_INT_H_
end_define

begin_macro
name|__BEGIN_DECLS
end_macro

begin_comment
comment|/*  * SDP session  */
end_comment

begin_struct
struct|struct
name|sdp_session
block|{
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|SDP_SESSION_LOCAL
value|(1<< 0)
name|uint16_t
name|tid
decl_stmt|;
comment|/* current session transaction ID (tid) */
name|uint16_t
name|omtu
decl_stmt|;
comment|/* outgoing MTU (req buffer size) */
name|uint16_t
name|imtu
decl_stmt|;
comment|/* incoming MTU (rsp buffer size) */
name|uint8_t
modifier|*
name|req
decl_stmt|;
comment|/* request buffer (start) */
name|uint8_t
modifier|*
name|req_e
decl_stmt|;
comment|/* request buffer (end) */
name|uint8_t
modifier|*
name|rsp
decl_stmt|;
comment|/* response buffer (start) */
name|uint8_t
modifier|*
name|rsp_e
decl_stmt|;
comment|/* response buffer (end) */
name|uint32_t
name|cslen
decl_stmt|;
comment|/* continuation state length */
name|uint8_t
name|cs
index|[
literal|16
index|]
decl_stmt|;
comment|/* continuation state */
name|int32_t
name|s
decl_stmt|;
comment|/* L2CAP socket */
name|int32_t
name|error
decl_stmt|;
comment|/* last error code */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_session
name|sdp_session_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_session
modifier|*
name|sdp_session_p
typedef|;
end_typedef

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _SDP_INT_H_ */
end_comment

end_unit

