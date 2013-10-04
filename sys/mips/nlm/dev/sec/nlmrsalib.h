begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NLMRSALIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NLMRSALIB_H_
end_define

begin_define
define|#
directive|define
name|XLP_RSA_SESSION
parameter_list|(
name|sid
parameter_list|)
value|((sid)& 0x000007ff)
end_define

begin_define
define|#
directive|define
name|XLP_RSA_SID
parameter_list|(
name|crd
parameter_list|,
name|ses
parameter_list|)
value|(((crd)<< 28) | ((ses)& 0x7ff))
end_define

begin_define
define|#
directive|define
name|RSA_ERROR
parameter_list|(
name|msg0
parameter_list|)
value|(((msg0)>> 53)& 0x1f)
end_define

begin_struct
struct|struct
name|xlp_rsa_session
block|{
name|uint32_t
name|sessionid
decl_stmt|;
name|int
name|hs_used
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xlp_rsa_command
block|{
name|uint16_t
name|session_num
decl_stmt|;
name|struct
name|xlp_rsa_session
modifier|*
name|ses
decl_stmt|;
name|struct
name|cryptkop
modifier|*
name|krp
decl_stmt|;
name|uint8_t
modifier|*
name|rsasrc
decl_stmt|;
name|uint32_t
name|rsaopsize
decl_stmt|;
name|uint32_t
name|rsatype
decl_stmt|;
name|uint32_t
name|rsafn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Holds data specific to nlm security accelerators  */
end_comment

begin_struct
struct|struct
name|xlp_rsa_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* device backpointer */
name|uint64_t
name|rsa_base
decl_stmt|;
name|int
name|sc_cid
decl_stmt|;
name|struct
name|xlp_rsa_session
modifier|*
name|sc_sessions
decl_stmt|;
name|int
name|sc_nsessions
decl_stmt|;
name|int
name|rsaecc_vc_start
decl_stmt|;
name|int
name|rsaecc_vc_end
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|nlm_xlprsaecc_msgring_handler
parameter_list|(
name|int
name|vc
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|code
parameter_list|,
name|int
name|src_id
parameter_list|,
name|struct
name|nlm_fmn_msg
modifier|*
name|msg
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NLMRSALIB_H_ */
end_comment

end_unit

