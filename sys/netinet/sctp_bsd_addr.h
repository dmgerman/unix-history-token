begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2001-2007, by Cisco Systems, Inc. All rights reserved.  * Copyright (c) 2008-2012, by Randall Stewart. All rights reserved.  * Copyright (c) 2008-2012, by Michael Tuexen. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_SCTP_BSD_ADDR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_SCTP_BSD_ADDR_H_
end_define

begin_include
include|#
directive|include
file|<netinet/sctp_pcb.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|__Userspace__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|iterator_control
name|sctp_it_ctl
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|sctp_wakeup_iterator
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_startup_iterator
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function_decl
name|void
name|sctp_gather_internal_ifa_flags
parameter_list|(
name|struct
name|sctp_ifa
modifier|*
name|ifa
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_PACKET_LOGGING
end_ifdef

begin_function_decl
name|void
name|sctp_packet_log
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_copy_out_packet_log
parameter_list|(
name|uint8_t
modifier|*
name|target
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|sctp_addr_change
parameter_list|(
name|struct
name|ifaddr
modifier|*
name|ifa
parameter_list|,
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_add_or_del_interfaces
parameter_list|(
name|int
function_decl|(
modifier|*
name|pred
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
parameter_list|,
name|int
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

