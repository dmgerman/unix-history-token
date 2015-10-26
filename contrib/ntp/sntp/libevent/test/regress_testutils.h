begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGRESS_TESTUTILS_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|REGRESS_TESTUTILS_H_INCLUDED_
end_define

begin_include
include|#
directive|include
file|"event2/dns.h"
end_include

begin_struct
struct|struct
name|regress_dns_server_table
block|{
specifier|const
name|char
modifier|*
name|q
decl_stmt|;
specifier|const
name|char
modifier|*
name|anstype
decl_stmt|;
specifier|const
name|char
modifier|*
name|ans
decl_stmt|;
name|int
name|seen
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|evdns_server_port
modifier|*
name|regress_get_dnsserver
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|ev_uint16_t
modifier|*
name|portnum
parameter_list|,
name|evutil_socket_t
modifier|*
name|psock
parameter_list|,
name|evdns_request_callback_fn_type
name|cb
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper: return the port that a socket is bound on, in host order. */
end_comment

begin_function_decl
name|int
name|regress_get_socket_port
parameter_list|(
name|evutil_socket_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* used to look up pre-canned responses in a search table */
end_comment

begin_function_decl
name|void
name|regress_dns_server_cb
parameter_list|(
name|struct
name|evdns_server_request
modifier|*
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* globally allocates a dns server that serves from a search table */
end_comment

begin_function_decl
name|int
name|regress_dnsserver
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|,
name|ev_uint16_t
modifier|*
name|port
parameter_list|,
name|struct
name|regress_dns_server_table
modifier|*
name|seach_table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* clean up the global dns server resources */
end_comment

begin_function_decl
name|void
name|regress_clean_dnsserver
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|evconnlistener
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|regress_get_listener_addr
parameter_list|(
name|struct
name|evconnlistener
modifier|*
name|lev
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
name|ev_socklen_t
modifier|*
name|socklen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REGRESS_TESTUTILS_H_INCLUDED_ */
end_comment

end_unit

