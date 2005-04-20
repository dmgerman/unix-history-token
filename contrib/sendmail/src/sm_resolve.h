begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997, 1998, 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: sm_resolve.h,v 8.8 2001/09/01 00:06:02 gshapiro Exp $ */
end_comment

begin_if
if|#
directive|if
name|DNSMAP
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__ROKEN_RESOLVE_H__
end_ifndef

begin_define
define|#
directive|define
name|__ROKEN_RESOLVE_H__
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

begin_comment
comment|/* ! T_TXT */
end_comment

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

begin_comment
comment|/* ! T_AFSDB */
end_comment

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

begin_comment
comment|/* ! T_SRV */
end_comment

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

begin_comment
comment|/* ! T_NAPTR */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dns_q_domain
decl_stmt|;
name|unsigned
name|int
name|dns_q_type
decl_stmt|;
name|unsigned
name|int
name|dns_q_class
decl_stmt|;
block|}
name|DNS_QUERY_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|mx_r_preference
decl_stmt|;
name|char
name|mx_r_domain
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MX_RECORD_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|srv_r_priority
decl_stmt|;
name|unsigned
name|int
name|srv_r_weight
decl_stmt|;
name|unsigned
name|int
name|srv_r_port
decl_stmt|;
name|char
name|srv_r_target
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SRV_RECORDT_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|resource_record
name|RESOURCE_RECORD_T
typedef|;
end_typedef

begin_struct
struct|struct
name|resource_record
block|{
name|char
modifier|*
name|rr_domain
decl_stmt|;
name|unsigned
name|int
name|rr_type
decl_stmt|;
name|unsigned
name|int
name|rr_class
decl_stmt|;
name|unsigned
name|int
name|rr_ttl
decl_stmt|;
name|unsigned
name|int
name|rr_size
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|rr_data
decl_stmt|;
name|MX_RECORD_T
modifier|*
name|rr_mx
decl_stmt|;
name|MX_RECORD_T
modifier|*
name|rr_afsdb
decl_stmt|;
comment|/* mx and afsdb are identical */
name|SRV_RECORDT_T
modifier|*
name|rr_srv
decl_stmt|;
if|#
directive|if
name|NETINET
name|struct
name|in_addr
modifier|*
name|rr_a
decl_stmt|;
endif|#
directive|endif
comment|/* NETINET */
if|#
directive|if
name|NETINET6
name|struct
name|in6_addr
modifier|*
name|rr_aaaa
decl_stmt|;
endif|#
directive|endif
comment|/* NETINET6 */
name|char
modifier|*
name|rr_txt
decl_stmt|;
block|}
name|rr_u
union|;
name|RESOURCE_RECORD_T
modifier|*
name|rr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|T_A
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|T_AAAA
argument_list|)
end_if

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

begin_comment
comment|/* !defined(T_A)&& !defined(T_AAAA)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|HEADER
name|dns_r_h
decl_stmt|;
name|DNS_QUERY_T
name|dns_r_q
decl_stmt|;
name|RESOURCE_RECORD_T
modifier|*
name|dns_r_head
decl_stmt|;
block|}
name|DNS_REPLY_T
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|dns_free_data
name|__P
argument_list|(
operator|(
name|DNS_REPLY_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dns_string_to_type
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|dns_type_to_string
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DNS_REPLY_T
modifier|*
name|dns_lookup_int
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|time_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern DNS_REPLY_T	*dns_lookup __P((const char *domain, 				const char *type_name, 				time_t retrans, 				int retry));
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __ROKEN_RESOLVE_H__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNSMAP */
end_comment

end_unit

