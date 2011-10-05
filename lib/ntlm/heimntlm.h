begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_NTLM_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_NTLM_H
end_define

begin_comment
comment|/**  * Buffer for storing data in the NTLM library. When filled in by the  * library it should be freed with heim_ntlm_free_buf().  */
end_comment

begin_struct
struct|struct
name|ntlm_buf
block|{
name|size_t
name|length
decl_stmt|;
comment|/**< length buffer data */
name|void
modifier|*
name|data
decl_stmt|;
comment|/**< pointer to the data itself */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTLM_NEG_UNICODE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_OEM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_TARGET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ9
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_SIGN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_SEAL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_DATAGRAM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_LM_KEY
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_NTLM
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_ANONYMOUS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ8
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_NTLM
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_NT_ONLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ7
value|0x00000800
end_define

begin_comment
comment|/* anon ? */
end_comment

begin_define
define|#
directive|define
name|NTLM_OEM_SUPPLIED_DOMAIN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NTLM_OEM_SUPPLIED_WORKSTATION
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ6
value|0x00004000
end_define

begin_comment
comment|/* local call ? */
end_comment

begin_define
define|#
directive|define
name|NTLM_NEG_ALWAYS_SIGN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NTLM_TARGET_DOMAIN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NTLM_TARGET_SERVER
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NTLM_TARGET_SHARE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_NTLM2_SESSION
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_NTLM2
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_IDENTIFY
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ5
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NTLM_NON_NT_SESSION_KEY
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_TARGET_INFO
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ4
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_VERSION
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ3
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ2
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NTLM_MBZ1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NTLM_ENC_128
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NTLM_NEG_KEYEX
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NTLM_ENC_56
value|0x80000000
end_define

begin_comment
comment|/**  * Struct for the NTLM target info, the strings is assumed to be in  * UTF8.  When filled in by the library it should be freed with  * heim_ntlm_free_targetinfo().  */
end_comment

begin_define
define|#
directive|define
name|NTLM_TI_AV_FLAG_GUEST
value|0x00000001
end_define

begin_struct
struct|struct
name|ntlm_targetinfo
block|{
name|char
modifier|*
name|servername
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|domainname
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|dnsdomainname
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|dnsservername
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|dnstreename
decl_stmt|;
comment|/**< */
name|uint32_t
name|avflags
decl_stmt|;
comment|/**< */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Struct for the NTLM type1 message info, the strings is assumed to  * be in UTF8.  When filled in by the library it should be freed with  * heim_ntlm_free_type1().  */
end_comment

begin_struct
struct|struct
name|ntlm_type1
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|domain
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/**< */
name|uint32_t
name|os
index|[
literal|2
index|]
decl_stmt|;
comment|/**< */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Struct for the NTLM type2 message info, the strings is assumed to  * be in UTF8.  When filled in by the library it should be freed with  * heim_ntlm_free_type2().  */
end_comment

begin_struct
struct|struct
name|ntlm_type2
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|targetname
decl_stmt|;
comment|/**< */
name|struct
name|ntlm_buf
name|targetinfo
decl_stmt|;
comment|/**< */
name|unsigned
name|char
name|challenge
index|[
literal|8
index|]
decl_stmt|;
comment|/**< */
name|uint32_t
name|context
index|[
literal|2
index|]
decl_stmt|;
comment|/**< */
name|uint32_t
name|os
index|[
literal|2
index|]
decl_stmt|;
comment|/**< */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Struct for the NTLM type3 message info, the strings is assumed to  * be in UTF8.  When filled in by the library it should be freed with  * heim_ntlm_free_type3().  */
end_comment

begin_struct
struct|struct
name|ntlm_type3
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|username
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|targetname
decl_stmt|;
comment|/**< */
name|struct
name|ntlm_buf
name|lm
decl_stmt|;
comment|/**< */
name|struct
name|ntlm_buf
name|ntlm
decl_stmt|;
comment|/**< */
name|struct
name|ntlm_buf
name|sessionkey
decl_stmt|;
comment|/**< */
name|char
modifier|*
name|ws
decl_stmt|;
comment|/**< */
name|uint32_t
name|os
index|[
literal|2
index|]
decl_stmt|;
comment|/**< */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<ntlm_err.h>
end_include

begin_include
include|#
directive|include
file|<heimntlm-protos.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTLM_NTLM_H */
end_comment

end_unit

