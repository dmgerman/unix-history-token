begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_IPSEC_SUPPORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_IPSEC_SUPPORT_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IPSEC
argument_list|)
operator|||
name|defined
argument_list|(
name|IPSEC_SUPPORT
argument_list|)
end_if

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tcphdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipsec_support
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tcpmd5_support
struct_decl|;
end_struct_decl

begin_function_decl
name|size_t
name|ipsec_hdrsiz_inpcb
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_init_pcbpolicy
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_delete_pcbpolicy
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_copy_pcbpolicy
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ipsec_methods
block|{
name|int
function_decl|(
modifier|*
name|input
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|check_policy
function_decl|)
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|forward
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|output
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pcbctl
function_decl|)
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
name|size_t
function_decl|(
modifier|*
name|hdrsize
function_decl|)
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|capability
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ctlinput
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|udp_input
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|udp_pcbctl
function_decl|)
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPSEC_CAP_OPERABLE
value|1
end_define

begin_define
define|#
directive|define
name|IPSEC_CAP_BYPASS_FILTER
value|2
end_define

begin_struct
struct|struct
name|tcpmd5_methods
block|{
name|int
function_decl|(
modifier|*
name|input
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|output
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pcbctl
function_decl|)
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPSEC_MODULE_ENABLED
value|0x0001
end_define

begin_define
define|#
directive|define
name|IPSEC_ENABLED
parameter_list|(
name|proto
parameter_list|)
define|\
value|((proto ## _ipsec_support)->enabled& IPSEC_MODULE_ENABLED)
end_define

begin_define
define|#
directive|define
name|TCPMD5_ENABLED
parameter_list|()
value|IPSEC_ENABLED(tcp)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TCP_SIGNATURE
end_ifdef

begin_comment
comment|/* TCP-MD5 build in the kernel */
end_comment

begin_struct
struct|struct
name|tcpmd5_support
block|{
specifier|const
name|u_int
name|enabled
decl_stmt|;
specifier|const
name|struct
name|tcpmd5_methods
modifier|*
specifier|const
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tcpmd5_support
modifier|*
specifier|const
name|tcp_ipsec_support
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TCPMD5_INPUT
parameter_list|(
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(*tcp_ipsec_support->methods->input)(m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|TCPMD5_OUTPUT
parameter_list|(
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(*tcp_ipsec_support->methods->output)(m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|TCPMD5_PCBCTL
parameter_list|(
name|inp
parameter_list|,
name|sopt
parameter_list|)
define|\
value|(*tcp_ipsec_support->methods->pcbctl)(inp, sopt)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|IPSEC_SUPPORT
argument_list|)
end_elif

begin_comment
comment|/* TCP-MD5 build as module */
end_comment

begin_struct
struct|struct
name|tcpmd5_support
block|{
specifier|volatile
name|u_int
name|enabled
decl_stmt|;
specifier|const
name|struct
name|tcpmd5_methods
modifier|*
specifier|volatile
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|tcpmd5_support
modifier|*
specifier|const
name|tcp_ipsec_support
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|tcpmd5_support_enable
parameter_list|(
specifier|const
name|struct
name|tcpmd5_methods
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcpmd5_support_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcpmd5_kmod_pcbctl
parameter_list|(
name|struct
name|tcpmd5_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcpmd5_kmod_input
parameter_list|(
name|struct
name|tcpmd5_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcpmd5_kmod_output
parameter_list|(
name|struct
name|tcpmd5_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TCPMD5_INPUT
parameter_list|(
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|tcpmd5_kmod_input(tcp_ipsec_support, m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|TCPMD5_OUTPUT
parameter_list|(
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|tcpmd5_kmod_output(tcp_ipsec_support, m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|TCPMD5_PCBCTL
parameter_list|(
name|inp
parameter_list|,
name|sopt
parameter_list|)
define|\
value|tcpmd5_kmod_pcbctl(tcp_ipsec_support, inp, sopt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPSEC || IPSEC_SUPPORT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IPSEC
argument_list|)
end_if

begin_struct
struct|struct
name|ipsec_support
block|{
specifier|const
name|u_int
name|enabled
decl_stmt|;
specifier|const
name|struct
name|ipsec_methods
modifier|*
specifier|const
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ipsec_support
modifier|*
specifier|const
name|ipv4_ipsec_support
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ipsec_support
modifier|*
specifier|const
name|ipv6_ipsec_support
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IPSEC_INPUT
parameter_list|(
name|proto
parameter_list|,
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(*(proto ## _ipsec_support)->methods->input)(m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_CHECK_POLICY
parameter_list|(
name|proto
parameter_list|,
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(*(proto ## _ipsec_support)->methods->check_policy)(m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_FORWARD
parameter_list|(
name|proto
parameter_list|,
name|m
parameter_list|)
define|\
value|(*(proto ## _ipsec_support)->methods->forward)(m)
end_define

begin_define
define|#
directive|define
name|IPSEC_OUTPUT
parameter_list|(
name|proto
parameter_list|,
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(*(proto ## _ipsec_support)->methods->output)(m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_PCBCTL
parameter_list|(
name|proto
parameter_list|,
name|inp
parameter_list|,
name|sopt
parameter_list|)
define|\
value|(*(proto ## _ipsec_support)->methods->pcbctl)(inp, sopt)
end_define

begin_define
define|#
directive|define
name|IPSEC_CAPS
parameter_list|(
name|proto
parameter_list|,
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(*(proto ## _ipsec_support)->methods->capability)(m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_HDRSIZE
parameter_list|(
name|proto
parameter_list|,
name|inp
parameter_list|)
define|\
value|(*(proto ## _ipsec_support)->methods->hdrsize)(inp)
end_define

begin_define
define|#
directive|define
name|UDPENCAP_INPUT
parameter_list|(
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(*ipv4_ipsec_support->methods->udp_input)(m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|UDPENCAP_PCBCTL
parameter_list|(
name|inp
parameter_list|,
name|sopt
parameter_list|)
define|\
value|(*ipv4_ipsec_support->methods->udp_pcbctl)(inp, sopt)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|IPSEC_SUPPORT
argument_list|)
end_elif

begin_struct
struct|struct
name|ipsec_support
block|{
specifier|volatile
name|u_int
name|enabled
decl_stmt|;
specifier|const
name|struct
name|ipsec_methods
modifier|*
specifier|volatile
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ipsec_support
modifier|*
specifier|const
name|ipv4_ipsec_support
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipsec_support
modifier|*
specifier|const
name|ipv6_ipsec_support
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ipsec_support_enable
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
specifier|const
name|struct
name|ipsec_methods
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipsec_support_disable
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_kmod_input
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_kmod_check_policy
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_kmod_forward
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_kmod_output
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_kmod_pcbctl
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_kmod_capability
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ipsec_kmod_hdrsize
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_kmod_udp_input
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_kmod_udp_pcbctl
parameter_list|(
name|struct
name|ipsec_support
modifier|*
specifier|const
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UDPENCAP_INPUT
parameter_list|(
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ipsec_kmod_udp_input(ipv4_ipsec_support, m, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|UDPENCAP_PCBCTL
parameter_list|(
name|inp
parameter_list|,
name|sopt
parameter_list|)
define|\
value|ipsec_kmod_udp_pcbctl(ipv4_ipsec_support, inp, sopt)
end_define

begin_define
define|#
directive|define
name|IPSEC_INPUT
parameter_list|(
name|proto
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ipsec_kmod_input(proto ## _ipsec_support, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_CHECK_POLICY
parameter_list|(
name|proto
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ipsec_kmod_check_policy(proto ## _ipsec_support, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_FORWARD
parameter_list|(
name|proto
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ipsec_kmod_forward(proto ## _ipsec_support, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_OUTPUT
parameter_list|(
name|proto
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ipsec_kmod_output(proto ## _ipsec_support, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_PCBCTL
parameter_list|(
name|proto
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ipsec_kmod_pcbctl(proto ## _ipsec_support, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_CAPS
parameter_list|(
name|proto
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ipsec_kmod_capability(proto ## _ipsec_support, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IPSEC_HDRSIZE
parameter_list|(
name|proto
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ipsec_kmod_hdrsize(proto ## _ipsec_support, __VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPSEC_SUPPORT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETIPSEC_IPSEC_SUPPORT_H_ */
end_comment

end_unit

