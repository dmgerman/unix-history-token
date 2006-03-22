begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: dns.h,v 1.6 2005/10/17 14:13:35 stevesk Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2003 Wesley Griffin. All rights reserved.  * Copyright (c) 2003 Jakob Schlyter. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_H
end_define

begin_enum
enum|enum
name|sshfp_types
block|{
name|SSHFP_KEY_RESERVED
block|,
name|SSHFP_KEY_RSA
block|,
name|SSHFP_KEY_DSA
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sshfp_hashes
block|{
name|SSHFP_HASH_RESERVED
block|,
name|SSHFP_HASH_SHA1
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DNS_RDATACLASS_IN
value|1
end_define

begin_define
define|#
directive|define
name|DNS_RDATATYPE_SSHFP
value|44
end_define

begin_define
define|#
directive|define
name|DNS_VERIFY_FOUND
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DNS_VERIFY_MATCH
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DNS_VERIFY_SECURE
value|0x00000004
end_define

begin_function_decl
name|int
name|verify_host_key_dns
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
specifier|const
name|Key
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|export_dns_rr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|Key
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_H */
end_comment

end_unit

