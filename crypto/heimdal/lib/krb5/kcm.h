begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005, PADL Software Pty Ltd.  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of PADL Software nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PADL SOFTWARE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PADL SOFTWARE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KCM_H__
end_ifndef

begin_define
define|#
directive|define
name|__KCM_H__
end_define

begin_comment
comment|/*  * KCM protocol definitions  */
end_comment

begin_define
define|#
directive|define
name|KCM_PROTOCOL_VERSION_MAJOR
value|2
end_define

begin_define
define|#
directive|define
name|KCM_PROTOCOL_VERSION_MINOR
value|0
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|kcmuuid_t
index|[
literal|16
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|kcm_operation
block|{
name|KCM_OP_NOOP
block|,
name|KCM_OP_GET_NAME
block|,
name|KCM_OP_RESOLVE
block|,
name|KCM_OP_GEN_NEW
block|,
name|KCM_OP_INITIALIZE
block|,
name|KCM_OP_DESTROY
block|,
name|KCM_OP_STORE
block|,
name|KCM_OP_RETRIEVE
block|,
name|KCM_OP_GET_PRINCIPAL
block|,
name|KCM_OP_GET_CRED_UUID_LIST
block|,
name|KCM_OP_GET_CRED_BY_UUID
block|,
name|KCM_OP_REMOVE_CRED
block|,
name|KCM_OP_SET_FLAGS
block|,
name|KCM_OP_CHOWN
block|,
name|KCM_OP_CHMOD
block|,
name|KCM_OP_GET_INITIAL_TICKET
block|,
name|KCM_OP_GET_TICKET
block|,
name|KCM_OP_MOVE_CACHE
block|,
name|KCM_OP_GET_CACHE_UUID_LIST
block|,
name|KCM_OP_GET_CACHE_BY_UUID
block|,
name|KCM_OP_GET_DEFAULT_CACHE
block|,
name|KCM_OP_SET_DEFAULT_CACHE
block|,
name|KCM_OP_GET_KDC_OFFSET
block|,
name|KCM_OP_SET_KDC_OFFSET
block|,
comment|/* NTLM operations */
name|KCM_OP_ADD_NTLM_CRED
block|,
name|KCM_OP_HAVE_NTLM_CRED
block|,
name|KCM_OP_DEL_NTLM_CRED
block|,
name|KCM_OP_DO_NTLM_AUTH
block|,
name|KCM_OP_GET_NTLM_USER_LIST
block|,
name|KCM_OP_MAX
block|}
name|kcm_operation
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PATH_KCM_SOCKET
value|"/var/run/.kcm_socket"
end_define

begin_define
define|#
directive|define
name|_PATH_KCM_DOOR
value|"/var/run/.kcm_door"
end_define

begin_define
define|#
directive|define
name|KCM_NTLM_FLAG_SESSIONKEY
value|1
end_define

begin_define
define|#
directive|define
name|KCM_NTLM_FLAG_NTLM2_SESSION
value|2
end_define

begin_define
define|#
directive|define
name|KCM_NTLM_FLAG_KEYEX
value|4
end_define

begin_define
define|#
directive|define
name|KCM_NTLM_FLAG_AV_GUEST
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KCM_H__ */
end_comment

end_unit

