begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: hprop.h,v 1.13 2001/01/26 15:54:19 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HPROP_H__
end_ifndef

begin_define
define|#
directive|define
name|__HPROP_H__
end_define

begin_include
include|#
directive|include
file|"headers.h"
end_include

begin_struct
struct|struct
name|prop_data
block|{
name|krb5_context
name|context
decl_stmt|;
name|krb5_auth_context
name|auth_context
decl_stmt|;
name|int
name|sock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HPROP_VERSION
value|"hprop-0.0"
end_define

begin_define
define|#
directive|define
name|HPROP_NAME
value|"hprop"
end_define

begin_define
define|#
directive|define
name|HPROP_KEYTAB
value|"HDB:"
end_define

begin_define
define|#
directive|define
name|HPROP_PORT
value|754
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NEVERDATE
end_ifndef

begin_define
define|#
directive|define
name|NEVERDATE
value|((1U<< 31) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|krb5_error_code
name|v5_prop
parameter_list|(
name|krb5_context
parameter_list|,
name|HDB
modifier|*
parameter_list|,
name|hdb_entry
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mit_prop_dump
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|v4_principal
block|{
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
name|char
name|instance
index|[
literal|64
index|]
decl_stmt|;
name|des_cblock
name|key
decl_stmt|;
name|int
name|kvno
decl_stmt|;
name|int
name|mkvno
decl_stmt|;
name|time_t
name|exp_date
decl_stmt|;
name|time_t
name|mod_date
decl_stmt|;
name|char
name|mod_name
index|[
literal|64
index|]
decl_stmt|;
name|char
name|mod_instance
index|[
literal|64
index|]
decl_stmt|;
name|int
name|max_life
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|v4_prop
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|v4_principal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|v4_prop_dump
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HPROP_H__ */
end_comment

end_unit

