begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2003 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KRB5_V4COMPAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__KRB5_V4COMPAT_H__
end_define

begin_include
include|#
directive|include
file|"krb_err.h"
end_include

begin_comment
comment|/*  * This file must only be included with v4 compat glue stuff in  * heimdal sources.  *  * It MUST NOT be installed.  */
end_comment

begin_define
define|#
directive|define
name|KRB_PROT_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_REQUEST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_REPLY
value|(2<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_REQUEST
value|(3<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_REQUEST_MUTUAL
value|(4<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_ERR_REPLY
value|(5<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_PRIVATE
value|(6<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_SAFE
value|(7<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_ERR
value|(8<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_FORWARD
value|(9<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_RENEW
value|(10<<1)
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_DIE
value|(63<<1)
end_define

begin_comment
comment|/* General definitions */
end_comment

begin_define
define|#
directive|define
name|KSUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|KFAILURE
value|255
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|MAX_KTXT_LEN
value|1250
end_define

begin_define
define|#
directive|define
name|ANAME_SZ
value|40
end_define

begin_define
define|#
directive|define
name|REALM_SZ
value|40
end_define

begin_define
define|#
directive|define
name|SNAME_SZ
value|40
end_define

begin_define
define|#
directive|define
name|INST_SZ
value|40
end_define

begin_struct
struct|struct
name|ktext
block|{
name|unsigned
name|int
name|length
decl_stmt|;
comment|/* Length of the text */
name|unsigned
name|char
name|dat
index|[
name|MAX_KTXT_LEN
index|]
decl_stmt|;
comment|/* The data itself */
name|uint32_t
name|mbz
decl_stmt|;
comment|/* zero to catch runaway strings */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|credentials
block|{
name|char
name|service
index|[
name|ANAME_SZ
index|]
decl_stmt|;
comment|/* Service name */
name|char
name|instance
index|[
name|INST_SZ
index|]
decl_stmt|;
comment|/* Instance */
name|char
name|realm
index|[
name|REALM_SZ
index|]
decl_stmt|;
comment|/* Auth domain */
name|char
name|session
index|[
literal|8
index|]
decl_stmt|;
comment|/* Session key */
name|int
name|lifetime
decl_stmt|;
comment|/* Lifetime */
name|int
name|kvno
decl_stmt|;
comment|/* Key version number */
name|struct
name|ktext
name|ticket_st
decl_stmt|;
comment|/* The ticket itself */
name|int32_t
name|issue_date
decl_stmt|;
comment|/* The issue time */
name|char
name|pname
index|[
name|ANAME_SZ
index|]
decl_stmt|;
comment|/* Principal's name */
name|char
name|pinst
index|[
name|INST_SZ
index|]
decl_stmt|;
comment|/* Principal's instance */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TKTLIFENUMFIXED
value|64
end_define

begin_define
define|#
directive|define
name|TKTLIFEMINFIXED
value|0x80
end_define

begin_define
define|#
directive|define
name|TKTLIFEMAXFIXED
value|0xBF
end_define

begin_define
define|#
directive|define
name|TKTLIFENOEXPIRE
value|0xFF
end_define

begin_define
define|#
directive|define
name|MAXTKTLIFETIME
value|(30*24*3600)
end_define

begin_comment
comment|/* 30 days */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEVERDATE
end_ifndef

begin_define
define|#
directive|define
name|NEVERDATE
value|((time_t)0x7fffffffL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KERB_ERR_NULL_KEY
value|10
end_define

begin_define
define|#
directive|define
name|CLOCK_SKEW
value|5*60
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TKT_ROOT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5_USE_PATH_TOKENS
end_ifdef

begin_define
define|#
directive|define
name|TKT_ROOT
value|"%{TEMP}/tkt"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TKT_ROOT
value|"/tmp/tkt"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|_krb5_krb_auth_data
block|{
name|int8_t
name|k_flags
decl_stmt|;
comment|/* Flags from ticket */
name|char
modifier|*
name|pname
decl_stmt|;
comment|/* Principal's name */
name|char
modifier|*
name|pinst
decl_stmt|;
comment|/* His Instance */
name|char
modifier|*
name|prealm
decl_stmt|;
comment|/* His Realm */
name|uint32_t
name|checksum
decl_stmt|;
comment|/* Data checksum (opt) */
name|krb5_keyblock
name|session
decl_stmt|;
comment|/* Session Key */
name|unsigned
name|char
name|life
decl_stmt|;
comment|/* Life of ticket */
name|uint32_t
name|time_sec
decl_stmt|;
comment|/* Time ticket issued */
name|uint32_t
name|address
decl_stmt|;
comment|/* Address in ticket */
block|}
struct|;
end_struct

begin_function_decl
name|KRB5_LIB_FUNCTION
name|time_t
name|KRB5_LIB_CALL
name|_krb5_krb_life_to_time
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|int
name|KRB5_LIB_CALL
name|_krb5_krb_time_to_life
parameter_list|(
name|time_t
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|krb5_error_code
name|KRB5_LIB_CALL
name|_krb5_krb_tf_setup
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|credentials
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|krb5_error_code
name|KRB5_LIB_CALL
name|_krb5_krb_dest_tkt
parameter_list|(
name|krb5_context
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|krb_time_to_life
value|_krb5_krb_time_to_life
end_define

begin_define
define|#
directive|define
name|krb_life_to_time
value|_krb5_krb_life_to_time
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __KRB5_V4COMPAT_H__ */
end_comment

end_unit

