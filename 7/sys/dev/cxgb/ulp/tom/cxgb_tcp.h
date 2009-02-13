begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007, Chelsio Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * 2. Neither the name of the Chelsio Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CXGB_TCP_H_
end_ifndef

begin_define
define|#
directive|define
name|CXGB_TCP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TCP_USRREQS_OVERLOAD
end_ifdef

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|cxgb_tcp_drop
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|int
name|errno
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cxgb_tcp_drop
value|tcp_drop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|cxgb_tcp_ctlinput
parameter_list|(
name|int
name|cmd
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
name|void
modifier|*
name|vip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|cxgb_tcp_close
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|cxgb_tcp_usrreqs
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|cxgb_tcp6_usrreqs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_tcp_cxgb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CXGB_TCP_H_ */
end_comment

end_unit

