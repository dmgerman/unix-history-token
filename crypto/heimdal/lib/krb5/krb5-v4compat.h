begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2002 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: krb5-v4compat.h,v 1.2 2003/03/18 03:08:20 lha Exp $ */
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

begin_comment
comment|/*   * This file must only be included with v4 compat glue stuff in  * heimdal sources.  *  * It MUST NOT be installed.  */
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
name|u_int32_t
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
name|des_cblock
name|session
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

begin_function_decl
name|int
name|_krb5_krb_time_to_life
parameter_list|(
name|time_t
name|start
parameter_list|,
name|time_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|_krb5_krb_life_to_time
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|life_
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

