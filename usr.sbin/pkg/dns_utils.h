begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Baptiste Daroussin<bapt@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_UTILS_H
end_define

begin_struct
struct|struct
name|dns_srvinfo
block|{
name|unsigned
name|int
name|type
decl_stmt|;
name|unsigned
name|int
name|class
decl_stmt|;
name|unsigned
name|int
name|ttl
decl_stmt|;
name|unsigned
name|int
name|priority
decl_stmt|;
name|unsigned
name|int
name|weight
decl_stmt|;
name|unsigned
name|int
name|port
decl_stmt|;
name|char
name|host
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|struct
name|dns_srvinfo
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|dns_srvinfo
modifier|*
name|dns_getsrvinfo
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

