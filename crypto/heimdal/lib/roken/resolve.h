begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: resolve.h,v 1.13 2001/06/09 01:35:04 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RESOLVE_H__
end_ifndef

begin_define
define|#
directive|define
name|__RESOLVE_H__
end_define

begin_comment
comment|/* We use these, but they are not always present in<arpa/nameser.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T_TXT
end_ifndef

begin_define
define|#
directive|define
name|T_TXT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_AFSDB
end_ifndef

begin_define
define|#
directive|define
name|T_AFSDB
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_SIG
end_ifndef

begin_define
define|#
directive|define
name|T_SIG
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_KEY
end_ifndef

begin_define
define|#
directive|define
name|T_KEY
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_SRV
end_ifndef

begin_define
define|#
directive|define
name|T_SRV
value|33
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_NAPTR
end_ifndef

begin_define
define|#
directive|define
name|T_NAPTR
value|35
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|T_CERT
end_ifndef

begin_define
define|#
directive|define
name|T_CERT
value|37
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|dns_query
block|{
name|char
modifier|*
name|domain
decl_stmt|;
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|class
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mx_record
block|{
name|unsigned
name|preference
decl_stmt|;
name|char
name|domain
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|srv_record
block|{
name|unsigned
name|priority
decl_stmt|;
name|unsigned
name|weight
decl_stmt|;
name|unsigned
name|port
decl_stmt|;
name|char
name|target
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|key_record
block|{
name|unsigned
name|flags
decl_stmt|;
name|unsigned
name|protocol
decl_stmt|;
name|unsigned
name|algorithm
decl_stmt|;
name|size_t
name|key_len
decl_stmt|;
name|u_char
name|key_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sig_record
block|{
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|algorithm
decl_stmt|;
name|unsigned
name|labels
decl_stmt|;
name|unsigned
name|orig_ttl
decl_stmt|;
name|unsigned
name|sig_expiration
decl_stmt|;
name|unsigned
name|sig_inception
decl_stmt|;
name|unsigned
name|key_tag
decl_stmt|;
name|char
modifier|*
name|signer
decl_stmt|;
name|unsigned
name|sig_len
decl_stmt|;
name|char
name|sig_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* also includes signer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cert_record
block|{
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|tag
decl_stmt|;
name|unsigned
name|algorithm
decl_stmt|;
name|size_t
name|cert_len
decl_stmt|;
name|u_char
name|cert_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|resource_record
block|{
name|char
modifier|*
name|domain
decl_stmt|;
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|class
decl_stmt|;
name|unsigned
name|ttl
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|struct
name|mx_record
modifier|*
name|mx
decl_stmt|;
name|struct
name|mx_record
modifier|*
name|afsdb
decl_stmt|;
comment|/* mx and afsdb are identical */
name|struct
name|srv_record
modifier|*
name|srv
decl_stmt|;
name|struct
name|in_addr
modifier|*
name|a
decl_stmt|;
name|char
modifier|*
name|txt
decl_stmt|;
name|struct
name|key_record
modifier|*
name|key
decl_stmt|;
name|struct
name|cert_record
modifier|*
name|cert
decl_stmt|;
name|struct
name|sig_record
modifier|*
name|sig
decl_stmt|;
block|}
name|u
union|;
name|struct
name|resource_record
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|T_A
end_ifndef

begin_comment
comment|/* XXX if<arpa/nameser.h> isn't included */
end_comment

begin_typedef
typedef|typedef
name|int
name|HEADER
typedef|;
end_typedef

begin_comment
comment|/* will never be used */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|dns_reply
block|{
name|HEADER
name|h
decl_stmt|;
name|struct
name|dns_query
name|q
decl_stmt|;
name|struct
name|resource_record
modifier|*
name|head
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|dns_reply
modifier|*
name|dns_lookup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_free_data
parameter_list|(
name|struct
name|dns_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dns_string_to_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|dns_type_to_string
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_srv_order
parameter_list|(
name|struct
name|dns_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RESOLVE_H__ */
end_comment

end_unit

