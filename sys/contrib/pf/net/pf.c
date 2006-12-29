begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: pf.c,v 1.483 2005/03/15 17:38:43 dhartmei Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Daniel Hartmeier  * Copyright (c) 2002,2003 Henning Brauer  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *    - Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    - Redistributions in binary form must reproduce the above  *      copyright notice, this list of conditions and the following  *      disclaimer in the documentation and/or other materials provided  *      with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|"opt_mac.h"
end_include

begin_include
include|#
directive|include
file|"opt_bpf.h"
end_include

begin_include
include|#
directive|include
file|"opt_pf.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_BPF
end_ifdef

begin_define
define|#
directive|define
name|NBPFILTER
value|DEV_BPF
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NBPFILTER
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_PFLOG
end_ifdef

begin_define
define|#
directive|define
name|NPFLOG
value|DEV_PFLOG
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPFLOG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_PFSYNC
end_ifdef

begin_define
define|#
directive|define
name|NPFSYNC
value|DEV_PFSYNC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPFSYNC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"bpfilter.h"
end_include

begin_include
include|#
directive|include
file|"pflog.h"
end_include

begin_include
include|#
directive|include
file|"pfsync.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/pool.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_seq.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_icmp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_timer.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_include
include|#
directive|include
file|<dev/rndvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/pfvar.h>
end_include

begin_include
include|#
directive|include
file|<net/if_pflog.h>
end_include

begin_if
if|#
directive|if
name|NPFSYNC
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<net/if_pfsync.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NPFSYNC> 0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/nd6.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/ip6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/in6_pcb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/in_cksum.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<security/mac/mac_framework.h>
end_include

begin_function_decl
specifier|extern
name|int
name|ip_optcopy
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DPFPRINTF
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
value|if (pf_status.debug>= (n)) printf x
end_define

begin_comment
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
name|struct
name|pf_anchor_global
name|pf_anchors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_ruleset
name|pf_main_ruleset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_altqqueue
name|pf_altqs
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_palist
name|pf_pabuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_altqqueue
modifier|*
name|pf_altqs_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_altqqueue
modifier|*
name|pf_altqs_inactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_status
name|pf_status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|ticket_altqs_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|ticket_altqs_inactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|altqs_inactive_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|ticket_pabuf
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_decl_stmt
name|struct
name|callout
name|pf_expire_to
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expire timeout */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|timeout
name|pf_expire_to
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expire timeout */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|pf_anchor_stackframe
block|{
name|struct
name|pf_ruleset
modifier|*
name|rs
decl_stmt|;
name|struct
name|pf_rule
modifier|*
name|r
decl_stmt|;
name|struct
name|pf_anchor_node
modifier|*
name|parent
decl_stmt|;
name|struct
name|pf_anchor
modifier|*
name|child
decl_stmt|;
block|}
name|pf_anchor_stack
index|[
literal|64
index|]
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_decl_stmt
name|uma_zone_t
name|pf_src_tree_pl
decl_stmt|,
name|pf_rule_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uma_zone_t
name|pf_state_pl
decl_stmt|,
name|pf_altq_pl
decl_stmt|,
name|pf_pooladdr_pl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|pool
name|pf_src_tree_pl
decl_stmt|,
name|pf_rule_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pool
name|pf_state_pl
decl_stmt|,
name|pf_altq_pl
decl_stmt|,
name|pf_pooladdr_pl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|pf_print_host
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_init_threshold
parameter_list|(
name|struct
name|pf_threshold
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_add_threshold
parameter_list|(
name|struct
name|pf_threshold
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_check_threshold
parameter_list|(
name|struct
name|pf_threshold
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_change_ap
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|sa_family_t
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
name|pf_change_a6
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_function_decl
name|void
name|pf_change_icmp
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_decl_stmt
name|void
name|pf_send_tcp
argument_list|(
expr|struct
name|mbuf
operator|*
argument_list|,
specifier|const
expr|struct
name|pf_rule
operator|*
argument_list|,
name|sa_family_t
argument_list|,
else|#
directive|else
name|void
name|pf_send_tcp
argument_list|(
specifier|const
expr|struct
name|pf_rule
operator|*
argument_list|,
name|sa_family_t
argument_list|,
endif|#
directive|endif
specifier|const
expr|struct
name|pf_addr
operator|*
argument_list|,
specifier|const
expr|struct
name|pf_addr
operator|*
argument_list|,
name|u_int16_t
argument_list|,
name|u_int16_t
argument_list|,
name|u_int32_t
argument_list|,
name|u_int32_t
argument_list|,
name|u_int8_t
argument_list|,
name|u_int16_t
argument_list|,
name|u_int16_t
argument_list|,
name|u_int8_t
argument_list|,
name|int
argument_list|,
expr|struct
name|ether_header
operator|*
argument_list|,
expr|struct
name|ifnet
operator|*
argument_list|)
argument_list|;
name|void
name|pf_send_icmp
argument_list|(
expr|struct
name|mbuf
operator|*
argument_list|,
name|u_int8_t
argument_list|,
name|u_int8_t
argument_list|,
name|sa_family_t
argument_list|,
expr|struct
name|pf_rule
operator|*
argument_list|)
argument_list|;
expr|struct
name|pf_rule
operator|*
name|pf_match_translation
argument_list|(
expr|struct
name|pf_pdesc
operator|*
argument_list|,
expr|struct
name|mbuf
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
expr|struct
name|pfi_kif
operator|*
argument_list|,
expr|struct
name|pf_addr
operator|*
argument_list|,
name|u_int16_t
argument_list|,
expr|struct
name|pf_addr
operator|*
argument_list|,
name|u_int16_t
argument_list|,
name|int
argument_list|)
argument_list|;
expr|struct
name|pf_rule
operator|*
name|pf_get_translation
argument_list|(
expr|struct
name|pf_pdesc
operator|*
argument_list|,
expr|struct
name|mbuf
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
expr|struct
name|pfi_kif
operator|*
argument_list|,
expr|struct
name|pf_src_node
operator|*
operator|*
argument_list|,
expr|struct
name|pf_addr
operator|*
argument_list|,
name|u_int16_t
argument_list|,
expr|struct
name|pf_addr
operator|*
argument_list|,
name|u_int16_t
argument_list|,
expr|struct
name|pf_addr
operator|*
argument_list|,
name|u_int16_t
operator|*
argument_list|)
argument_list|;
name|int
name|pf_test_tcp
argument_list|(
expr|struct
name|pf_rule
operator|*
operator|*
argument_list|,
expr|struct
name|pf_state
operator|*
operator|*
argument_list|,
name|int
argument_list|,
expr|struct
name|pfi_kif
operator|*
argument_list|,
expr|struct
name|mbuf
operator|*
argument_list|,
name|int
argument_list|,
name|void
operator|*
argument_list|,
expr|struct
name|pf_pdesc
operator|*
argument_list|,
expr|struct
name|pf_rule
operator|*
operator|*
argument_list|,
ifdef|#
directive|ifdef
name|__FreeBSD__
expr|struct
name|pf_ruleset
operator|*
operator|*
argument_list|,
expr|struct
name|ifqueue
operator|*
argument_list|,
expr|struct
name|inpcb
operator|*
argument_list|)
argument_list|;
else|#
directive|else
expr|struct
name|pf_ruleset
operator|*
operator|*
argument_list|,
expr|struct
name|ifqueue
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pf_test_udp
parameter_list|(
name|struct
name|pf_rule
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
modifier|*
parameter_list|,
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|pf_ruleset
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifqueue
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|pf_ruleset
modifier|*
modifier|*
struct_decl|, struct ifqueue *
end_struct_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pf_test_icmp
parameter_list|(
name|struct
name|pf_rule
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_ruleset
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifqueue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_test_other
parameter_list|(
name|struct
name|pf_rule
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_ruleset
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifqueue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_test_fragment
parameter_list|(
name|struct
name|pf_rule
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_ruleset
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_test_state_tcp
parameter_list|(
name|struct
name|pf_state
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_test_state_udp
parameter_list|(
name|struct
name|pf_state
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_test_state_icmp
parameter_list|(
name|struct
name|pf_state
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_test_state_other
parameter_list|(
name|struct
name|pf_state
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pf_tag
modifier|*
name|pf_get_tag
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_match_tag
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pf_tag
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_hash
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_poolhashkey
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_map_addr
parameter_list|(
name|u_int8_t
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_src_node
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_get_sport
parameter_list|(
name|sa_family_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|struct
name|pf_src_node
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_route
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_route6
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|int
name|pf_socket_lookup
parameter_list|(
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|pf_socket_lookup
parameter_list|(
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|u_int8_t
name|pf_get_wscale
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int16_t
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|pf_get_mss
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int16_t
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|pf_calc_mss
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_set_rt_ifp
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_check_proto_cksum
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int8_t
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_addr_wrap_neq
parameter_list|(
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|,
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|pf_add_mbuf_tag
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pf_state
modifier|*
name|pf_find_state_recurse
parameter_list|(
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_src_connlimit
parameter_list|(
name|struct
name|pf_state
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_check_congestion
parameter_list|(
name|struct
name|ifqueue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|int
name|in4_cksum
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|u_int8_t
name|nxt
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|pf_pool_limit
name|pf_pool_limits
index|[
name|PF_LIMIT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|pf_pool_limit
name|pf_pool_limits
index|[
name|PF_LIMIT_MAX
index|]
init|=
block|{
block|{
operator|&
name|pf_state_pl
block|,
name|PFSTATE_HIWAT
block|}
block|,
block|{
operator|&
name|pf_src_tree_pl
block|,
name|PFSNODE_HIWAT
block|}
block|,
block|{
operator|&
name|pf_frent_pl
block|,
name|PFFRAG_FRENT_HIWAT
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STATE_LOOKUP
parameter_list|()
define|\
value|do {								\ 		if (direction == PF_IN)					\ 			*state = pf_find_state_recurse(			\ 			    kif,&key, PF_EXT_GWY);			\ 		else							\ 			*state = pf_find_state_recurse(			\ 			    kif,&key, PF_LAN_EXT);			\ 		if (*state == NULL || (*state)->timeout == PFTM_PURGE)	\ 			return (PF_DROP);				\ 		if (direction == PF_OUT&&				\ 		    (((*state)->rule.ptr->rt == PF_ROUTETO&&		\ 		    (*state)->rule.ptr->direction == PF_OUT) ||		\ 		    ((*state)->rule.ptr->rt == PF_REPLYTO&&		\ 		    (*state)->rule.ptr->direction == PF_IN))&&		\ 		    (*state)->rt_kif != NULL&&				\ 		    (*state)->rt_kif != kif)				\ 			return (PF_PASS);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|STATE_TRANSLATE
parameter_list|(
name|s
parameter_list|)
define|\
value|(s)->lan.addr.addr32[0] != (s)->gwy.addr.addr32[0] || \ 	((s)->af == AF_INET6&& \ 	((s)->lan.addr.addr32[1] != (s)->gwy.addr.addr32[1] || \ 	(s)->lan.addr.addr32[2] != (s)->gwy.addr.addr32[2] || \ 	(s)->lan.addr.addr32[3] != (s)->gwy.addr.addr32[3])) || \ 	(s)->lan.port != (s)->gwy.port
end_define

begin_define
define|#
directive|define
name|BOUND_IFACE
parameter_list|(
name|r
parameter_list|,
name|k
parameter_list|)
value|(((r)->rule_flag& PFRULE_IFBOUND) ? (k) :   \ 	((r)->rule_flag& PFRULE_GRBOUND) ? (k)->pfik_parent :	       \ 	(k)->pfik_parent->pfik_parent)
end_define

begin_define
define|#
directive|define
name|STATE_INC_COUNTERS
parameter_list|(
name|s
parameter_list|)
define|\
value|do {						\ 		s->rule.ptr->states++;			\ 		if (s->anchor.ptr != NULL)		\ 			s->anchor.ptr->states++;	\ 		if (s->nat_rule.ptr != NULL)		\ 			s->nat_rule.ptr->states++;	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|STATE_DEC_COUNTERS
parameter_list|(
name|s
parameter_list|)
define|\
value|do {						\ 		if (s->nat_rule.ptr != NULL)		\ 			s->nat_rule.ptr->states--;	\ 		if (s->anchor.ptr != NULL)		\ 			s->anchor.ptr->states--;	\ 		s->rule.ptr->states--;			\ 	} while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_function_decl
specifier|static
name|__inline
name|int
name|pf_src_compare
parameter_list|(
name|struct
name|pf_src_node
modifier|*
parameter_list|,
name|struct
name|pf_src_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|pf_state_compare_lan_ext
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|pf_state_compare_ext_gwy
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|pf_state_compare_id
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|pf_anchor_compare
parameter_list|(
name|struct
name|pf_anchor
modifier|*
parameter_list|,
name|struct
name|pf_anchor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|static
name|int
name|pf_src_compare
parameter_list|(
name|struct
name|pf_src_node
modifier|*
parameter_list|,
name|struct
name|pf_src_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|pf_state_compare_lan_ext
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|pf_state_compare_ext_gwy
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|pf_state_compare_id
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|pf_anchor_compare
parameter_list|(
name|struct
name|pf_anchor
modifier|*
parameter_list|,
name|struct
name|pf_anchor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|pf_src_tree
name|tree_src_tracking
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_state_tree_id
name|tree_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_state_queue
name|state_updates
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|RB_GENERATE
argument_list|(
name|pf_src_tree
argument_list|,
name|pf_src_node
argument_list|,
name|entry
argument_list|,
name|pf_src_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_GENERATE
argument_list|(
name|pf_state_tree_lan_ext
argument_list|,
name|pf_state
argument_list|,
name|u
operator|.
name|s
operator|.
name|entry_lan_ext
argument_list|,
name|pf_state_compare_lan_ext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_GENERATE
argument_list|(
name|pf_state_tree_ext_gwy
argument_list|,
name|pf_state
argument_list|,
name|u
operator|.
name|s
operator|.
name|entry_ext_gwy
argument_list|,
name|pf_state_compare_ext_gwy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_GENERATE
argument_list|(
name|pf_state_tree_id
argument_list|,
name|pf_state
argument_list|,
name|u
operator|.
name|s
operator|.
name|entry_id
argument_list|,
name|pf_state_compare_id
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_GENERATE
argument_list|(
name|pf_anchor_global
argument_list|,
name|pf_anchor
argument_list|,
name|entry_global
argument_list|,
name|pf_anchor_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_GENERATE
argument_list|(
name|pf_anchor_node
argument_list|,
name|pf_anchor
argument_list|,
name|entry_node
argument_list|,
name|pf_anchor_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
name|int
else|#
directive|else
specifier|static
name|__inline
name|int
endif|#
directive|endif
name|pf_src_compare
parameter_list|(
name|struct
name|pf_src_node
modifier|*
name|a
parameter_list|,
name|struct
name|pf_src_node
modifier|*
name|b
parameter_list|)
block|{
name|int
name|diff
decl_stmt|;
if|if
condition|(
name|a
operator|->
name|rule
operator|.
name|ptr
operator|>
name|b
operator|->
name|rule
operator|.
name|ptr
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|rule
operator|.
name|ptr
operator|<
name|b
operator|->
name|rule
operator|.
name|ptr
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|af
operator|-
name|b
operator|->
name|af
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
switch|switch
condition|(
name|a
operator|->
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|>
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|<
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|>
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|<
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|>
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|<
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
name|int
else|#
directive|else
specifier|static
name|__inline
name|int
endif|#
directive|endif
name|pf_state_compare_lan_ext
parameter_list|(
name|struct
name|pf_state
modifier|*
name|a
parameter_list|,
name|struct
name|pf_state
modifier|*
name|b
parameter_list|)
block|{
name|int
name|diff
decl_stmt|;
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|proto
operator|-
name|b
operator|->
name|proto
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|af
operator|-
name|b
operator|->
name|af
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
switch|switch
condition|(
name|a
operator|->
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|>
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|<
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|>
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|<
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|>
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|<
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|lan
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|lan
operator|.
name|port
operator|-
name|b
operator|->
name|lan
operator|.
name|port
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|ext
operator|.
name|port
operator|-
name|b
operator|->
name|ext
operator|.
name|port
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
name|int
else|#
directive|else
specifier|static
name|__inline
name|int
endif|#
directive|endif
name|pf_state_compare_ext_gwy
parameter_list|(
name|struct
name|pf_state
modifier|*
name|a
parameter_list|,
name|struct
name|pf_state
modifier|*
name|b
parameter_list|)
block|{
name|int
name|diff
decl_stmt|;
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|proto
operator|-
name|b
operator|->
name|proto
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|af
operator|-
name|b
operator|->
name|af
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
switch|switch
condition|(
name|a
operator|->
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|>
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
operator|<
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|3
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|>
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
operator|<
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|2
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|>
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
operator|<
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|1
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|ext
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|>
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
operator|<
name|b
operator|->
name|gwy
operator|.
name|addr
operator|.
name|addr32
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|ext
operator|.
name|port
operator|-
name|b
operator|->
name|ext
operator|.
name|port
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
if|if
condition|(
operator|(
name|diff
operator|=
name|a
operator|->
name|gwy
operator|.
name|port
operator|-
name|b
operator|->
name|gwy
operator|.
name|port
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|diff
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
name|int
else|#
directive|else
specifier|static
name|__inline
name|int
endif|#
directive|endif
name|pf_state_compare_id
parameter_list|(
name|struct
name|pf_state
modifier|*
name|a
parameter_list|,
name|struct
name|pf_state
modifier|*
name|b
parameter_list|)
block|{
if|if
condition|(
name|a
operator|->
name|id
operator|>
name|b
operator|->
name|id
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|id
operator|<
name|b
operator|->
name|id
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|creatorid
operator|>
name|b
operator|->
name|creatorid
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|a
operator|->
name|creatorid
operator|<
name|b
operator|->
name|creatorid
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
name|int
else|#
directive|else
specifier|static
name|__inline
name|int
endif|#
directive|endif
name|pf_anchor_compare
parameter_list|(
name|struct
name|pf_anchor
modifier|*
name|a
parameter_list|,
name|struct
name|pf_anchor
modifier|*
name|b
parameter_list|)
block|{
name|int
name|c
init|=
name|strcmp
argument_list|(
name|a
operator|->
name|path
argument_list|,
name|b
operator|->
name|path
argument_list|)
decl_stmt|;
return|return
operator|(
name|c
condition|?
operator|(
name|c
operator|<
literal|0
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function
name|void
name|pf_addrcpy
parameter_list|(
name|struct
name|pf_addr
modifier|*
name|dst
parameter_list|,
name|struct
name|pf_addr
modifier|*
name|src
parameter_list|,
name|sa_family_t
name|af
parameter_list|)
block|{
switch|switch
condition|(
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
name|dst
operator|->
name|addr32
index|[
literal|0
index|]
operator|=
name|src
operator|->
name|addr32
index|[
literal|0
index|]
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET */
case|case
name|AF_INET6
case|:
name|dst
operator|->
name|addr32
index|[
literal|0
index|]
operator|=
name|src
operator|->
name|addr32
index|[
literal|0
index|]
expr_stmt|;
name|dst
operator|->
name|addr32
index|[
literal|1
index|]
operator|=
name|src
operator|->
name|addr32
index|[
literal|1
index|]
expr_stmt|;
name|dst
operator|->
name|addr32
index|[
literal|2
index|]
operator|=
name|src
operator|->
name|addr32
index|[
literal|2
index|]
expr_stmt|;
name|dst
operator|->
name|addr32
index|[
literal|3
index|]
operator|=
name|src
operator|->
name|addr32
index|[
literal|3
index|]
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_function
name|struct
name|pf_state
modifier|*
name|pf_find_state_byid
parameter_list|(
name|struct
name|pf_state
modifier|*
name|key
parameter_list|)
block|{
name|pf_status
operator|.
name|fcounters
index|[
name|FCNT_STATE_SEARCH
index|]
operator|++
expr_stmt|;
return|return
operator|(
name|RB_FIND
argument_list|(
name|pf_state_tree_id
argument_list|,
operator|&
name|tree_id
argument_list|,
name|key
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|pf_state
modifier|*
name|pf_find_state_recurse
parameter_list|(
name|struct
name|pfi_kif
modifier|*
name|kif
parameter_list|,
name|struct
name|pf_state
modifier|*
name|key
parameter_list|,
name|u_int8_t
name|tree
parameter_list|)
block|{
name|struct
name|pf_state
modifier|*
name|s
decl_stmt|;
name|pf_status
operator|.
name|fcounters
index|[
name|FCNT_STATE_SEARCH
index|]
operator|++
expr_stmt|;
switch|switch
condition|(
name|tree
condition|)
block|{
case|case
name|PF_LAN_EXT
case|:
for|for
control|(
init|;
name|kif
operator|!=
name|NULL
condition|;
name|kif
operator|=
name|kif
operator|->
name|pfik_parent
control|)
block|{
name|s
operator|=
name|RB_FIND
argument_list|(
name|pf_state_tree_lan_ext
argument_list|,
operator|&
name|kif
operator|->
name|pfik_lan_ext
argument_list|,
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|!=
name|NULL
condition|)
return|return
operator|(
name|s
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
case|case
name|PF_EXT_GWY
case|:
for|for
control|(
init|;
name|kif
operator|!=
name|NULL
condition|;
name|kif
operator|=
name|kif
operator|->
name|pfik_parent
control|)
block|{
name|s
operator|=
name|RB_FIND
argument_list|(
name|pf_state_tree_ext_gwy
argument_list|,
operator|&
name|kif
operator|->
name|pfik_ext_gwy
argument_list|,
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|!=
name|NULL
condition|)
return|return
operator|(
name|s
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
default|default:
name|panic
argument_list|(
literal|"pf_find_state_recurse"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|struct
name|pf_state
modifier|*
name|pf_find_state_all
parameter_list|(
name|struct
name|pf_state
modifier|*
name|key
parameter_list|,
name|u_int8_t
name|tree
parameter_list|,
name|int
modifier|*
name|more
parameter_list|)
block|{
name|struct
name|pf_state
modifier|*
name|s
decl_stmt|,
modifier|*
name|ss
init|=
name|NULL
decl_stmt|;
name|struct
name|pfi_kif
modifier|*
name|kif
decl_stmt|;
name|pf_status
operator|.
name|fcounters
index|[
name|FCNT_STATE_SEARCH
index|]
operator|++
expr_stmt|;
switch|switch
condition|(
name|tree
condition|)
block|{
case|case
name|PF_LAN_EXT
case|:
name|TAILQ_FOREACH
argument_list|(
argument|kif
argument_list|,
argument|&pfi_statehead
argument_list|,
argument|pfik_w_states
argument_list|)
block|{
name|s
operator|=
name|RB_FIND
argument_list|(
name|pf_state_tree_lan_ext
argument_list|,
operator|&
name|kif
operator|->
name|pfik_lan_ext
argument_list|,
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
continue|continue;
if|if
condition|(
name|more
operator|==
name|NULL
condition|)
return|return
operator|(
name|s
operator|)
return|;
name|ss
operator|=
name|s
expr_stmt|;
operator|(
operator|*
name|more
operator|)
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|ss
operator|)
return|;
case|case
name|PF_EXT_GWY
case|:
name|TAILQ_FOREACH
argument_list|(
argument|kif
argument_list|,
argument|&pfi_statehead
argument_list|,
argument|pfik_w_states
argument_list|)
block|{
name|s
operator|=
name|RB_FIND
argument_list|(
name|pf_state_tree_ext_gwy
argument_list|,
operator|&
name|kif
operator|->
name|pfik_ext_gwy
argument_list|,
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
continue|continue;
if|if
condition|(
name|more
operator|==
name|NULL
condition|)
return|return
operator|(
name|s
operator|)
return|;
name|ss
operator|=
name|s
expr_stmt|;
operator|(
operator|*
name|more
operator|)
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|ss
operator|)
return|;
default|default:
name|panic
argument_list|(
literal|"pf_find_state_all"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|pf_init_threshold
parameter_list|(
name|struct
name|pf_threshold
modifier|*
name|threshold
parameter_list|,
name|u_int32_t
name|limit
parameter_list|,
name|u_int32_t
name|seconds
parameter_list|)
block|{
name|threshold
operator|->
name|limit
operator|=
name|limit
operator|*
name|PF_THRESHOLD_MULT
expr_stmt|;
name|threshold
operator|->
name|seconds
operator|=
name|seconds
expr_stmt|;
name|threshold
operator|->
name|count
operator|=
literal|0
expr_stmt|;
name|threshold
operator|->
name|last
operator|=
name|time_second
expr_stmt|;
block|}
end_function

begin_function
name|void
name|pf_add_threshold
parameter_list|(
name|struct
name|pf_threshold
modifier|*
name|threshold
parameter_list|)
block|{
name|u_int32_t
name|t
init|=
name|time_second
decl_stmt|,
name|diff
init|=
name|t
operator|-
name|threshold
operator|->
name|last
decl_stmt|;
if|if
condition|(
name|diff
operator|>=
name|threshold
operator|->
name|seconds
condition|)
name|threshold
operator|->
name|count
operator|=
literal|0
expr_stmt|;
else|else
name|threshold
operator|->
name|count
operator|-=
name|threshold
operator|->
name|count
operator|*
name|diff
operator|/
name|threshold
operator|->
name|seconds
expr_stmt|;
name|threshold
operator|->
name|count
operator|+=
name|PF_THRESHOLD_MULT
expr_stmt|;
name|threshold
operator|->
name|last
operator|=
name|t
expr_stmt|;
block|}
end_function

begin_function
name|int
name|pf_check_threshold
parameter_list|(
name|struct
name|pf_threshold
modifier|*
name|threshold
parameter_list|)
block|{
return|return
operator|(
name|threshold
operator|->
name|count
operator|>
name|threshold
operator|->
name|limit
operator|)
return|;
block|}
end_function

begin_function
name|int
name|pf_src_connlimit
parameter_list|(
name|struct
name|pf_state
modifier|*
modifier|*
name|state
parameter_list|)
block|{
name|struct
name|pf_state
modifier|*
name|s
decl_stmt|;
name|int
name|bad
init|=
literal|0
decl_stmt|;
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|conn
operator|++
expr_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
operator|(
operator|*
name|state
operator|)
operator|->
name|local_flags
operator||=
name|PFSTATE_SRC_CONN
expr_stmt|;
endif|#
directive|endif
name|pf_add_threshold
argument_list|(
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|conn_rate
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|state
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|->
name|max_src_conn
operator|&&
operator|(
operator|*
name|state
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|->
name|max_src_conn
operator|<
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|conn
condition|)
block|{
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_SRCCONN
index|]
operator|++
expr_stmt|;
name|bad
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|(
operator|*
name|state
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|->
name|max_src_conn_rate
operator|.
name|limit
operator|&&
name|pf_check_threshold
argument_list|(
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|conn_rate
argument_list|)
condition|)
block|{
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_SRCCONNRATE
index|]
operator|++
expr_stmt|;
name|bad
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|bad
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|(
operator|*
name|state
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|->
name|overload_tbl
condition|)
block|{
name|struct
name|pfr_addr
name|p
decl_stmt|;
name|u_int32_t
name|killed
init|=
literal|0
decl_stmt|;
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_OVERLOAD_TABLE
index|]
operator|++
expr_stmt|;
if|if
condition|(
name|pf_status
operator|.
name|debug
operator|>=
name|PF_DEBUG_MISC
condition|)
block|{
name|printf
argument_list|(
literal|"pf_src_connlimit: blocking address "
argument_list|)
expr_stmt|;
name|pf_print_host
argument_list|(
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|addr
argument_list|,
literal|0
argument_list|,
operator|(
operator|*
name|state
operator|)
operator|->
name|af
argument_list|)
expr_stmt|;
block|}
name|bzero
argument_list|(
operator|&
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|pfra_af
operator|=
operator|(
operator|*
name|state
operator|)
operator|->
name|af
expr_stmt|;
switch|switch
condition|(
operator|(
operator|*
name|state
operator|)
operator|->
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
name|p
operator|.
name|pfra_net
operator|=
literal|32
expr_stmt|;
name|p
operator|.
name|pfra_ip4addr
operator|=
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|addr
operator|.
name|v4
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
name|p
operator|.
name|pfra_net
operator|=
literal|128
expr_stmt|;
name|p
operator|.
name|pfra_ip6addr
operator|=
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|addr
operator|.
name|v6
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
name|pfr_insert_kentry
argument_list|(
operator|(
operator|*
name|state
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|->
name|overload_tbl
argument_list|,
operator|&
name|p
argument_list|,
name|time_second
argument_list|)
expr_stmt|;
comment|/* kill existing states if that's required. */
if|if
condition|(
operator|(
operator|*
name|state
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|->
name|flush
condition|)
block|{
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_OVERLOAD_FLUSH
index|]
operator|++
expr_stmt|;
name|RB_FOREACH
argument_list|(
argument|s
argument_list|,
argument|pf_state_tree_id
argument_list|,
argument|&tree_id
argument_list|)
block|{
comment|/* 				 * Kill states from this source.  (Only those 				 * from the same rule if PF_FLUSH_GLOBAL is not 				 * set) 				 */
if|if
condition|(
name|s
operator|->
name|af
operator|==
operator|(
operator|*
name|state
operator|)
operator|->
name|af
operator|&&
operator|(
operator|(
operator|(
operator|*
name|state
operator|)
operator|->
name|direction
operator|==
name|PF_OUT
operator|&&
name|PF_AEQ
argument_list|(
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|addr
argument_list|,
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|s
operator|->
name|af
argument_list|)
operator|)
operator|||
operator|(
operator|(
operator|*
name|state
operator|)
operator|->
name|direction
operator|==
name|PF_IN
operator|&&
name|PF_AEQ
argument_list|(
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|src_node
operator|->
name|addr
argument_list|,
operator|&
name|s
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|s
operator|->
name|af
argument_list|)
operator|)
operator|)
operator|&&
operator|(
operator|(
operator|*
name|state
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|->
name|flush
operator|&
name|PF_FLUSH_GLOBAL
operator|||
operator|(
operator|*
name|state
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|==
name|s
operator|->
name|rule
operator|.
name|ptr
operator|)
condition|)
block|{
name|s
operator|->
name|timeout
operator|=
name|PFTM_PURGE
expr_stmt|;
name|s
operator|->
name|src
operator|.
name|state
operator|=
name|s
operator|->
name|dst
operator|.
name|state
operator|=
name|TCPS_CLOSED
expr_stmt|;
name|killed
operator|++
expr_stmt|;
block|}
block|}
if|if
condition|(
name|pf_status
operator|.
name|debug
operator|>=
name|PF_DEBUG_MISC
condition|)
name|printf
argument_list|(
literal|", %u states killed"
argument_list|,
name|killed
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pf_status
operator|.
name|debug
operator|>=
name|PF_DEBUG_MISC
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
comment|/* kill this state */
operator|(
operator|*
name|state
operator|)
operator|->
name|timeout
operator|=
name|PFTM_PURGE
expr_stmt|;
operator|(
operator|*
name|state
operator|)
operator|->
name|src
operator|.
name|state
operator|=
operator|(
operator|*
name|state
operator|)
operator|->
name|dst
operator|.
name|state
operator|=
name|TCPS_CLOSED
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|int
name|pf_insert_src_node
parameter_list|(
name|struct
name|pf_src_node
modifier|*
modifier|*
name|sn
parameter_list|,
name|struct
name|pf_rule
modifier|*
name|rule
parameter_list|,
name|struct
name|pf_addr
modifier|*
name|src
parameter_list|,
name|sa_family_t
name|af
parameter_list|)
block|{
name|struct
name|pf_src_node
name|k
decl_stmt|;
if|if
condition|(
operator|*
name|sn
operator|==
name|NULL
condition|)
block|{
name|k
operator|.
name|af
operator|=
name|af
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|k
operator|.
name|addr
argument_list|,
name|src
argument_list|,
name|af
argument_list|)
expr_stmt|;
if|if
condition|(
name|rule
operator|->
name|rule_flag
operator|&
name|PFRULE_RULESRCTRACK
operator|||
name|rule
operator|->
name|rpool
operator|.
name|opts
operator|&
name|PF_POOL_STICKYADDR
condition|)
name|k
operator|.
name|rule
operator|.
name|ptr
operator|=
name|rule
expr_stmt|;
else|else
name|k
operator|.
name|rule
operator|.
name|ptr
operator|=
name|NULL
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_SEARCH
index|]
operator|++
expr_stmt|;
operator|*
name|sn
operator|=
name|RB_FIND
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
operator|&
name|k
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|sn
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|!
name|rule
operator|->
name|max_src_nodes
operator|||
name|rule
operator|->
name|src_nodes
operator|<
name|rule
operator|->
name|max_src_nodes
condition|)
operator|(
operator|*
name|sn
operator|)
operator|=
name|pool_get
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
name|PR_NOWAIT
argument_list|)
expr_stmt|;
else|else
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_SRCNODES
index|]
operator|++
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|sn
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|bzero
argument_list|(
operator|*
name|sn
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pf_src_node
argument_list|)
argument_list|)
expr_stmt|;
name|pf_init_threshold
argument_list|(
operator|&
operator|(
operator|*
name|sn
operator|)
operator|->
name|conn_rate
argument_list|,
name|rule
operator|->
name|max_src_conn_rate
operator|.
name|limit
argument_list|,
name|rule
operator|->
name|max_src_conn_rate
operator|.
name|seconds
argument_list|)
expr_stmt|;
operator|(
operator|*
name|sn
operator|)
operator|->
name|af
operator|=
name|af
expr_stmt|;
if|if
condition|(
name|rule
operator|->
name|rule_flag
operator|&
name|PFRULE_RULESRCTRACK
operator|||
name|rule
operator|->
name|rpool
operator|.
name|opts
operator|&
name|PF_POOL_STICKYADDR
condition|)
operator|(
operator|*
name|sn
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|=
name|rule
expr_stmt|;
else|else
operator|(
operator|*
name|sn
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|=
name|NULL
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
operator|(
operator|*
name|sn
operator|)
operator|->
name|addr
argument_list|,
name|src
argument_list|,
name|af
argument_list|)
expr_stmt|;
if|if
condition|(
name|RB_INSERT
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
operator|*
name|sn
argument_list|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|pf_status
operator|.
name|debug
operator|>=
name|PF_DEBUG_MISC
condition|)
block|{
name|printf
argument_list|(
literal|"pf: src_tree insert failed: "
argument_list|)
expr_stmt|;
name|pf_print_host
argument_list|(
operator|&
operator|(
operator|*
name|sn
operator|)
operator|->
name|addr
argument_list|,
literal|0
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|pool_put
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
operator|*
name|sn
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
operator|(
operator|*
name|sn
operator|)
operator|->
name|creation
operator|=
name|time_second
expr_stmt|;
operator|(
operator|*
name|sn
operator|)
operator|->
name|ruletype
operator|=
name|rule
operator|->
name|action
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|sn
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|!=
name|NULL
condition|)
operator|(
operator|*
name|sn
operator|)
operator|->
name|rule
operator|.
name|ptr
operator|->
name|src_nodes
operator|++
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_INSERT
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|src_nodes
operator|++
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|rule
operator|->
name|max_src_states
operator|&&
operator|(
operator|*
name|sn
operator|)
operator|->
name|states
operator|>=
name|rule
operator|->
name|max_src_states
condition|)
block|{
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_SRCSTATES
index|]
operator|++
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|pf_insert_state
parameter_list|(
name|struct
name|pfi_kif
modifier|*
name|kif
parameter_list|,
name|struct
name|pf_state
modifier|*
name|state
parameter_list|)
block|{
comment|/* Thou MUST NOT insert multiple duplicate keys */
name|state
operator|->
name|u
operator|.
name|s
operator|.
name|kif
operator|=
name|kif
expr_stmt|;
if|if
condition|(
name|RB_INSERT
argument_list|(
name|pf_state_tree_lan_ext
argument_list|,
operator|&
name|kif
operator|->
name|pfik_lan_ext
argument_list|,
name|state
argument_list|)
condition|)
block|{
if|if
condition|(
name|pf_status
operator|.
name|debug
operator|>=
name|PF_DEBUG_MISC
condition|)
block|{
name|printf
argument_list|(
literal|"pf: state insert failed: tree_lan_ext"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" lan: "
argument_list|)
expr_stmt|;
name|pf_print_host
argument_list|(
operator|&
name|state
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|state
operator|->
name|lan
operator|.
name|port
argument_list|,
name|state
operator|->
name|af
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" gwy: "
argument_list|)
expr_stmt|;
name|pf_print_host
argument_list|(
operator|&
name|state
operator|->
name|gwy
operator|.
name|addr
argument_list|,
name|state
operator|->
name|gwy
operator|.
name|port
argument_list|,
name|state
operator|->
name|af
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" ext: "
argument_list|)
expr_stmt|;
name|pf_print_host
argument_list|(
operator|&
name|state
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|state
operator|->
name|ext
operator|.
name|port
argument_list|,
name|state
operator|->
name|af
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|->
name|sync_flags
operator|&
name|PFSTATE_FROMSYNC
condition|)
name|printf
argument_list|(
literal|" (from sync)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|RB_INSERT
argument_list|(
name|pf_state_tree_ext_gwy
argument_list|,
operator|&
name|kif
operator|->
name|pfik_ext_gwy
argument_list|,
name|state
argument_list|)
condition|)
block|{
if|if
condition|(
name|pf_status
operator|.
name|debug
operator|>=
name|PF_DEBUG_MISC
condition|)
block|{
name|printf
argument_list|(
literal|"pf: state insert failed: tree_ext_gwy"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" lan: "
argument_list|)
expr_stmt|;
name|pf_print_host
argument_list|(
operator|&
name|state
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|state
operator|->
name|lan
operator|.
name|port
argument_list|,
name|state
operator|->
name|af
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" gwy: "
argument_list|)
expr_stmt|;
name|pf_print_host
argument_list|(
operator|&
name|state
operator|->
name|gwy
operator|.
name|addr
argument_list|,
name|state
operator|->
name|gwy
operator|.
name|port
argument_list|,
name|state
operator|->
name|af
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" ext: "
argument_list|)
expr_stmt|;
name|pf_print_host
argument_list|(
operator|&
name|state
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|state
operator|->
name|ext
operator|.
name|port
argument_list|,
name|state
operator|->
name|af
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|->
name|sync_flags
operator|&
name|PFSTATE_FROMSYNC
condition|)
name|printf
argument_list|(
literal|" (from sync)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|RB_REMOVE
argument_list|(
name|pf_state_tree_lan_ext
argument_list|,
operator|&
name|kif
operator|->
name|pfik_lan_ext
argument_list|,
name|state
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|state
operator|->
name|id
operator|==
literal|0
operator|&&
name|state
operator|->
name|creatorid
operator|==
literal|0
condition|)
block|{
name|state
operator|->
name|id
operator|=
name|htobe64
argument_list|(
name|pf_status
operator|.
name|stateid
operator|++
argument_list|)
expr_stmt|;
name|state
operator|->
name|creatorid
operator|=
name|pf_status
operator|.
name|hostid
expr_stmt|;
block|}
if|if
condition|(
name|RB_INSERT
argument_list|(
name|pf_state_tree_id
argument_list|,
operator|&
name|tree_id
argument_list|,
name|state
argument_list|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|pf_status
operator|.
name|debug
operator|>=
name|PF_DEBUG_MISC
condition|)
block|{
ifdef|#
directive|ifdef
name|__FreeBSD__
name|printf
argument_list|(
literal|"pf: state insert failed: "
literal|"id: %016llx creatorid: %08x"
argument_list|,
operator|(
name|long
name|long
operator|)
name|be64toh
argument_list|(
name|state
operator|->
name|id
argument_list|)
argument_list|,
name|ntohl
argument_list|(
name|state
operator|->
name|creatorid
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"pf: state insert failed: "
literal|"id: %016llx creatorid: %08x"
argument_list|,
name|betoh64
argument_list|(
name|state
operator|->
name|id
argument_list|)
argument_list|,
name|ntohl
argument_list|(
name|state
operator|->
name|creatorid
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|state
operator|->
name|sync_flags
operator|&
name|PFSTATE_FROMSYNC
condition|)
name|printf
argument_list|(
literal|" (from sync)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|RB_REMOVE
argument_list|(
name|pf_state_tree_lan_ext
argument_list|,
operator|&
name|kif
operator|->
name|pfik_lan_ext
argument_list|,
name|state
argument_list|)
expr_stmt|;
name|RB_REMOVE
argument_list|(
name|pf_state_tree_ext_gwy
argument_list|,
operator|&
name|kif
operator|->
name|pfik_ext_gwy
argument_list|,
name|state
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|state_updates
argument_list|,
name|state
argument_list|,
name|u
operator|.
name|s
operator|.
name|entry_updates
argument_list|)
expr_stmt|;
name|pf_status
operator|.
name|fcounters
index|[
name|FCNT_STATE_INSERT
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|states
operator|++
expr_stmt|;
name|pfi_attach_state
argument_list|(
name|kif
argument_list|)
expr_stmt|;
if|#
directive|if
name|NPFSYNC
name|pfsync_insert_state
argument_list|(
name|state
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|pf_purge_timeout
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|callout
modifier|*
name|to
init|=
name|arg
decl_stmt|;
else|#
directive|else
name|struct
name|timeout
modifier|*
name|to
init|=
name|arg
decl_stmt|;
endif|#
directive|endif
name|int
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|PF_LOCK
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|s
operator|=
name|splsoftnet
argument_list|()
expr_stmt|;
name|pf_purge_expired_states
argument_list|()
expr_stmt|;
name|pf_purge_expired_fragments
argument_list|()
expr_stmt|;
name|pf_purge_expired_src_nodes
argument_list|()
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|PF_UNLOCK
argument_list|()
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
name|callout_reset
argument_list|(
name|to
argument_list|,
name|pf_default_rule
operator|.
name|timeout
index|[
name|PFTM_INTERVAL
index|]
operator|*
name|hz
argument_list|,
name|pf_purge_timeout
argument_list|,
name|to
argument_list|)
expr_stmt|;
else|#
directive|else
name|timeout_add
argument_list|(
name|to
argument_list|,
name|pf_default_rule
operator|.
name|timeout
index|[
name|PFTM_INTERVAL
index|]
operator|*
name|hz
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|u_int32_t
name|pf_state_expires
parameter_list|(
specifier|const
name|struct
name|pf_state
modifier|*
name|state
parameter_list|)
block|{
name|u_int32_t
name|timeout
decl_stmt|;
name|u_int32_t
name|start
decl_stmt|;
name|u_int32_t
name|end
decl_stmt|;
name|u_int32_t
name|states
decl_stmt|;
comment|/* handle all PFTM_*> PFTM_MAX here */
if|if
condition|(
name|state
operator|->
name|timeout
operator|==
name|PFTM_PURGE
condition|)
return|return
operator|(
name|time_second
operator|)
return|;
if|if
condition|(
name|state
operator|->
name|timeout
operator|==
name|PFTM_UNTIL_PACKET
condition|)
return|return
operator|(
literal|0
operator|)
return|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|KASSERT
argument_list|(
operator|(
name|state
operator|->
name|timeout
operator|<
name|PFTM_MAX
operator|)
argument_list|,
operator|(
literal|"pf_state_expires: timeout> PFTM_MAX"
operator|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|KASSERT
argument_list|(
name|state
operator|->
name|timeout
operator|<
name|PFTM_MAX
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|timeout
operator|=
name|state
operator|->
name|rule
operator|.
name|ptr
operator|->
name|timeout
index|[
name|state
operator|->
name|timeout
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|timeout
condition|)
name|timeout
operator|=
name|pf_default_rule
operator|.
name|timeout
index|[
name|state
operator|->
name|timeout
index|]
expr_stmt|;
name|start
operator|=
name|state
operator|->
name|rule
operator|.
name|ptr
operator|->
name|timeout
index|[
name|PFTM_ADAPTIVE_START
index|]
expr_stmt|;
if|if
condition|(
name|start
condition|)
block|{
name|end
operator|=
name|state
operator|->
name|rule
operator|.
name|ptr
operator|->
name|timeout
index|[
name|PFTM_ADAPTIVE_END
index|]
expr_stmt|;
name|states
operator|=
name|state
operator|->
name|rule
operator|.
name|ptr
operator|->
name|states
expr_stmt|;
block|}
else|else
block|{
name|start
operator|=
name|pf_default_rule
operator|.
name|timeout
index|[
name|PFTM_ADAPTIVE_START
index|]
expr_stmt|;
name|end
operator|=
name|pf_default_rule
operator|.
name|timeout
index|[
name|PFTM_ADAPTIVE_END
index|]
expr_stmt|;
name|states
operator|=
name|pf_status
operator|.
name|states
expr_stmt|;
block|}
if|if
condition|(
name|end
operator|&&
name|states
operator|>
name|start
operator|&&
name|start
operator|<
name|end
condition|)
block|{
if|if
condition|(
name|states
operator|<
name|end
condition|)
return|return
operator|(
name|state
operator|->
name|expire
operator|+
name|timeout
operator|*
operator|(
name|end
operator|-
name|states
operator|)
operator|/
operator|(
name|end
operator|-
name|start
operator|)
operator|)
return|;
else|else
return|return
operator|(
name|time_second
operator|)
return|;
block|}
return|return
operator|(
name|state
operator|->
name|expire
operator|+
name|timeout
operator|)
return|;
block|}
end_function

begin_function
name|void
name|pf_purge_expired_src_nodes
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|pf_src_node
modifier|*
name|cur
decl_stmt|,
modifier|*
name|next
decl_stmt|;
for|for
control|(
name|cur
operator|=
name|RB_MIN
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|)
init|;
name|cur
condition|;
name|cur
operator|=
name|next
control|)
block|{
name|next
operator|=
name|RB_NEXT
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
name|cur
argument_list|)
expr_stmt|;
if|if
condition|(
name|cur
operator|->
name|states
operator|<=
literal|0
operator|&&
name|cur
operator|->
name|expire
operator|<=
name|time_second
condition|)
block|{
if|if
condition|(
name|cur
operator|->
name|rule
operator|.
name|ptr
operator|!=
name|NULL
condition|)
block|{
name|cur
operator|->
name|rule
operator|.
name|ptr
operator|->
name|src_nodes
operator|--
expr_stmt|;
if|if
condition|(
name|cur
operator|->
name|rule
operator|.
name|ptr
operator|->
name|states
operator|<=
literal|0
operator|&&
name|cur
operator|->
name|rule
operator|.
name|ptr
operator|->
name|max_src_nodes
operator|<=
literal|0
condition|)
name|pf_rm_rule
argument_list|(
name|NULL
argument_list|,
name|cur
operator|->
name|rule
operator|.
name|ptr
argument_list|)
expr_stmt|;
block|}
name|RB_REMOVE
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
name|cur
argument_list|)
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_REMOVALS
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|src_nodes
operator|--
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
name|cur
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function
name|void
name|pf_src_tree_remove_state
parameter_list|(
name|struct
name|pf_state
modifier|*
name|s
parameter_list|)
block|{
name|u_int32_t
name|timeout
decl_stmt|;
if|if
condition|(
name|s
operator|->
name|src_node
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|s
operator|->
name|proto
operator|==
name|IPPROTO_TCP
condition|)
block|{
ifdef|#
directive|ifdef
name|__FreeBSD__
if|if
condition|(
name|s
operator|->
name|local_flags
operator|&
name|PFSTATE_SRC_CONN
condition|)
else|#
directive|else
if|if
condition|(
name|s
operator|->
name|src
operator|.
name|state
operator|==
name|PF_TCPS_PROXY_DST
operator|||
name|s
operator|->
name|timeout
operator|>=
name|PFTM_TCP_ESTABLISHED
condition|)
endif|#
directive|endif
operator|--
name|s
operator|->
name|src_node
operator|->
name|conn
expr_stmt|;
block|}
if|if
condition|(
operator|--
name|s
operator|->
name|src_node
operator|->
name|states
operator|<=
literal|0
condition|)
block|{
name|timeout
operator|=
name|s
operator|->
name|rule
operator|.
name|ptr
operator|->
name|timeout
index|[
name|PFTM_SRC_NODE
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|timeout
condition|)
name|timeout
operator|=
name|pf_default_rule
operator|.
name|timeout
index|[
name|PFTM_SRC_NODE
index|]
expr_stmt|;
name|s
operator|->
name|src_node
operator|->
name|expire
operator|=
name|time_second
operator|+
name|timeout
expr_stmt|;
block|}
block|}
if|if
condition|(
name|s
operator|->
name|nat_src_node
operator|!=
name|s
operator|->
name|src_node
operator|&&
name|s
operator|->
name|nat_src_node
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|--
name|s
operator|->
name|nat_src_node
operator|->
name|states
operator|<=
literal|0
condition|)
block|{
name|timeout
operator|=
name|s
operator|->
name|rule
operator|.
name|ptr
operator|->
name|timeout
index|[
name|PFTM_SRC_NODE
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|timeout
condition|)
name|timeout
operator|=
name|pf_default_rule
operator|.
name|timeout
index|[
name|PFTM_SRC_NODE
index|]
expr_stmt|;
name|s
operator|->
name|nat_src_node
operator|->
name|expire
operator|=
name|time_second
operator|+
name|timeout
expr_stmt|;
block|}
block|}
name|s
operator|->
name|src_node
operator|=
name|s
operator|->
name|nat_src_node
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_function
name|void
name|pf_purge_expired_state
parameter_list|(
name|struct
name|pf_state
modifier|*
name|cur
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__FreeBSD__
if|if
condition|(
name|cur
operator|->
name|local_flags
operator|&
name|PFSTATE_EXPIRING
condition|)
return|return;
name|cur
operator|->
name|local_flags
operator||=
name|PFSTATE_EXPIRING
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|cur
operator|->
name|src
operator|.
name|state
operator|==
name|PF_TCPS_PROXY_DST
condition|)
ifdef|#
directive|ifdef
name|__FreeBSD__
name|pf_send_tcp
argument_list|(
argument|NULL
argument_list|,
argument|cur->rule.ptr
argument_list|,
argument|cur->af
argument_list|,
else|#
directive|else
argument|pf_send_tcp(cur->rule.ptr, cur->af,
endif|#
directive|endif
argument|&cur->ext.addr,&cur->lan.addr, 		    cur->ext.port, cur->lan.port, 		    cur->src.seqhi, cur->src.seqlo +
literal|1
argument|, 		    TH_RST|TH_ACK,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|,
literal|1
argument|, NULL, NULL); 	RB_REMOVE(pf_state_tree_ext_gwy,&cur->u.s.kif->pfik_ext_gwy, cur); 	RB_REMOVE(pf_state_tree_lan_ext,&cur->u.s.kif->pfik_lan_ext, cur); 	RB_REMOVE(pf_state_tree_id,&tree_id, cur);
if|#
directive|if
name|NPFSYNC
argument|pfsync_delete_state(cur);
endif|#
directive|endif
argument|pf_src_tree_remove_state(cur); 	if (--cur->rule.ptr->states<=
literal|0
argument|&& 	    cur->rule.ptr->src_nodes<=
literal|0
argument|) 		pf_rm_rule(NULL, cur->rule.ptr); 	if (cur->nat_rule.ptr != NULL) 		if (--cur->nat_rule.ptr->states<=
literal|0
argument|&& 			cur->nat_rule.ptr->src_nodes<=
literal|0
argument|) 			pf_rm_rule(NULL, cur->nat_rule.ptr); 	if (cur->anchor.ptr != NULL) 		if (--cur->anchor.ptr->states<=
literal|0
argument|) 			pf_rm_rule(NULL, cur->anchor.ptr); 	pf_normalize_tcp_cleanup(cur); 	pfi_detach_state(cur->u.s.kif); 	TAILQ_REMOVE(&state_updates, cur, u.s.entry_updates); 	if (cur->tag) 		pf_tag_unref(cur->tag); 	pool_put(&pf_state_pl, cur); 	pf_status.fcounters[FCNT_STATE_REMOVALS]++; 	pf_status.states--; }  void pf_purge_expired_states(void) { 	struct pf_state		*cur
argument_list|,
argument|*next;  	for (cur = RB_MIN(pf_state_tree_id,&tree_id); 	    cur; cur = next) { 		next = RB_NEXT(pf_state_tree_id,&tree_id, cur); 		if (pf_state_expires(cur)<= time_second) 			pf_purge_expired_state(cur); 	} }  int pf_tbladdr_setup(struct pf_ruleset *rs, struct pf_addr_wrap *aw) { 	if (aw->type != PF_ADDR_TABLE) 		return (
literal|0
argument|); 	if ((aw->p.tbl = pfr_attach_table(rs, aw->v.tblname)) == NULL) 		return (
literal|1
argument|); 	return (
literal|0
argument|); }  void pf_tbladdr_remove(struct pf_addr_wrap *aw) { 	if (aw->type != PF_ADDR_TABLE || aw->p.tbl == NULL) 		return; 	pfr_detach_table(aw->p.tbl); 	aw->p.tbl = NULL; }  void pf_tbladdr_copyout(struct pf_addr_wrap *aw) { 	struct pfr_ktable *kt = aw->p.tbl;  	if (aw->type != PF_ADDR_TABLE || kt == NULL) 		return; 	if (!(kt->pfrkt_flags& PFR_TFLAG_ACTIVE)&& kt->pfrkt_root != NULL) 		kt = kt->pfrkt_root; 	aw->p.tbl = NULL; 	aw->p.tblcnt = (kt->pfrkt_flags& PFR_TFLAG_ACTIVE) ? 		kt->pfrkt_cnt : -
literal|1
argument|; }  void pf_print_host(struct pf_addr *addr, u_int16_t p, sa_family_t af) { 	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: { 		u_int32_t a = ntohl(addr->addr32[
literal|0
argument|]); 		printf(
literal|"%u.%u.%u.%u"
argument|, (a>>
literal|24
argument|)&
literal|255
argument|, (a>>
literal|16
argument|)&
literal|255
argument|, 		    (a>>
literal|8
argument|)&
literal|255
argument|, a&
literal|255
argument|); 		if (p) { 			p = ntohs(p); 			printf(
literal|":%u"
argument|, p); 		} 		break; 	}
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: { 		u_int16_t b; 		u_int8_t i
argument_list|,
argument|curstart =
literal|255
argument_list|,
argument|curend =
literal|0
argument_list|,
argument|maxstart =
literal|0
argument_list|,
argument|maxend =
literal|0
argument|; 		for (i =
literal|0
argument|; i<
literal|8
argument|; i++) { 			if (!addr->addr16[i]) { 				if (curstart ==
literal|255
argument|) 					curstart = i; 				else 					curend = i; 			} else { 				if (curstart) { 					if ((curend - curstart)> 					    (maxend - maxstart)) { 						maxstart = curstart; 						maxend = curend; 						curstart =
literal|255
argument|; 					} 				} 			} 		} 		for (i =
literal|0
argument|; i<
literal|8
argument|; i++) { 			if (i>= maxstart&& i<= maxend) { 				if (maxend !=
literal|7
argument|) { 					if (i == maxstart) 						printf(
literal|":"
argument|); 				} else { 					if (i == maxend) 						printf(
literal|":"
argument|); 				} 			} else { 				b = ntohs(addr->addr16[i]); 				printf(
literal|"%x"
argument|, b); 				if (i<
literal|7
argument|) 					printf(
literal|":"
argument|); 			} 		} 		if (p) { 			p = ntohs(p); 			printf(
literal|"[%u]"
argument|, p); 		} 		break; 	}
endif|#
directive|endif
comment|/* INET6 */
argument|} }  void pf_print_state(struct pf_state *s) { 	switch (s->proto) { 	case IPPROTO_TCP: 		printf(
literal|"TCP "
argument|); 		break; 	case IPPROTO_UDP: 		printf(
literal|"UDP "
argument|); 		break; 	case IPPROTO_ICMP: 		printf(
literal|"ICMP "
argument|); 		break; 	case IPPROTO_ICMPV6: 		printf(
literal|"ICMPV6 "
argument|); 		break; 	default: 		printf(
literal|"%u "
argument|, s->proto); 		break; 	} 	pf_print_host(&s->lan.addr, s->lan.port, s->af); 	printf(
literal|" "
argument|); 	pf_print_host(&s->gwy.addr, s->gwy.port, s->af); 	printf(
literal|" "
argument|); 	pf_print_host(&s->ext.addr, s->ext.port, s->af); 	printf(
literal|" [lo=%u high=%u win=%u modulator=%u"
argument|, s->src.seqlo, 	    s->src.seqhi, s->src.max_win, s->src.seqdiff); 	if (s->src.wscale&& s->dst.wscale) 		printf(
literal|" wscale=%u"
argument|, s->src.wscale& PF_WSCALE_MASK); 	printf(
literal|"]"
argument|); 	printf(
literal|" [lo=%u high=%u win=%u modulator=%u"
argument|, s->dst.seqlo, 	    s->dst.seqhi, s->dst.max_win, s->dst.seqdiff); 	if (s->src.wscale&& s->dst.wscale) 		printf(
literal|" wscale=%u"
argument|, s->dst.wscale& PF_WSCALE_MASK); 	printf(
literal|"]"
argument|); 	printf(
literal|" %u:%u"
argument|, s->src.state, s->dst.state); }  void pf_print_flags(u_int8_t f) { 	if (f) 		printf(
literal|" "
argument|); 	if (f& TH_FIN) 		printf(
literal|"F"
argument|); 	if (f& TH_SYN) 		printf(
literal|"S"
argument|); 	if (f& TH_RST) 		printf(
literal|"R"
argument|); 	if (f& TH_PUSH) 		printf(
literal|"P"
argument|); 	if (f& TH_ACK) 		printf(
literal|"A"
argument|); 	if (f& TH_URG) 		printf(
literal|"U"
argument|); 	if (f& TH_ECE) 		printf(
literal|"E"
argument|); 	if (f& TH_CWR) 		printf(
literal|"W"
argument|); }
define|#
directive|define
name|PF_SET_SKIP_STEPS
parameter_list|(
name|i
parameter_list|)
define|\
value|do {							\ 		while (head[i] != cur) {			\ 			head[i]->skip[i].ptr = cur;		\ 			head[i] = TAILQ_NEXT(head[i], entries);	\ 		}						\ 	} while (0)
argument|void pf_calc_skip_steps(struct pf_rulequeue *rules) { 	struct pf_rule *cur
argument_list|,
argument|*prev
argument_list|,
argument|*head[PF_SKIP_COUNT]; 	int i;  	cur = TAILQ_FIRST(rules); 	prev = cur; 	for (i =
literal|0
argument|; i< PF_SKIP_COUNT; ++i) 		head[i] = cur; 	while (cur != NULL) {  		if (cur->kif != prev->kif || cur->ifnot != prev->ifnot) 			PF_SET_SKIP_STEPS(PF_SKIP_IFP); 		if (cur->direction != prev->direction) 			PF_SET_SKIP_STEPS(PF_SKIP_DIR); 		if (cur->af != prev->af) 			PF_SET_SKIP_STEPS(PF_SKIP_AF); 		if (cur->proto != prev->proto) 			PF_SET_SKIP_STEPS(PF_SKIP_PROTO); 		if (cur->src.neg != prev->src.neg || 		    pf_addr_wrap_neq(&cur->src.addr,&prev->src.addr)) 			PF_SET_SKIP_STEPS(PF_SKIP_SRC_ADDR); 		if (cur->src.port[
literal|0
argument|] != prev->src.port[
literal|0
argument|] || 		    cur->src.port[
literal|1
argument|] != prev->src.port[
literal|1
argument|] || 		    cur->src.port_op != prev->src.port_op) 			PF_SET_SKIP_STEPS(PF_SKIP_SRC_PORT); 		if (cur->dst.neg != prev->dst.neg || 		    pf_addr_wrap_neq(&cur->dst.addr,&prev->dst.addr)) 			PF_SET_SKIP_STEPS(PF_SKIP_DST_ADDR); 		if (cur->dst.port[
literal|0
argument|] != prev->dst.port[
literal|0
argument|] || 		    cur->dst.port[
literal|1
argument|] != prev->dst.port[
literal|1
argument|] || 		    cur->dst.port_op != prev->dst.port_op) 			PF_SET_SKIP_STEPS(PF_SKIP_DST_PORT);  		prev = cur; 		cur = TAILQ_NEXT(cur, entries); 	} 	for (i =
literal|0
argument|; i< PF_SKIP_COUNT; ++i) 		PF_SET_SKIP_STEPS(i); }  int pf_addr_wrap_neq(struct pf_addr_wrap *aw1, struct pf_addr_wrap *aw2) { 	if (aw1->type != aw2->type) 		return (
literal|1
argument|); 	switch (aw1->type) { 	case PF_ADDR_ADDRMASK: 		if (PF_ANEQ(&aw1->v.a.addr,&aw2->v.a.addr,
literal|0
argument|)) 			return (
literal|1
argument|); 		if (PF_ANEQ(&aw1->v.a.mask,&aw2->v.a.mask,
literal|0
argument|)) 			return (
literal|1
argument|); 		return (
literal|0
argument|); 	case PF_ADDR_DYNIFTL: 		return (aw1->p.dyn->pfid_kt != aw2->p.dyn->pfid_kt); 	case PF_ADDR_NOROUTE: 		return (
literal|0
argument|); 	case PF_ADDR_TABLE: 		return (aw1->p.tbl != aw2->p.tbl); 	default: 		printf(
literal|"invalid address type: %d\n"
argument|, aw1->type); 		return (
literal|1
argument|); 	} }  u_int16_t pf_cksum_fixup(u_int16_t cksum, u_int16_t old, u_int16_t new, u_int8_t udp) { 	u_int32_t	l;  	if (udp&& !cksum) 		return (
literal|0x0000
argument|); 	l = cksum + old - new; 	l = (l>>
literal|16
argument|) + (l&
literal|65535
argument|); 	l = l&
literal|65535
argument|; 	if (udp&& !l) 		return (
literal|0xFFFF
argument|); 	return (l); }  void pf_change_ap(struct pf_addr *a, u_int16_t *p, u_int16_t *ic, u_int16_t *pc,     struct pf_addr *an, u_int16_t pn, u_int8_t u, sa_family_t af) { 	struct pf_addr	ao; 	u_int16_t	po = *p;  	PF_ACPY(&ao, a, af); 	PF_ACPY(a, an, af);  	*p = pn;  	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		*ic = pf_cksum_fixup(pf_cksum_fixup(*ic, 		    ao.addr16[
literal|0
argument|], an->addr16[
literal|0
argument|],
literal|0
argument|), 		    ao.addr16[
literal|1
argument|], an->addr16[
literal|1
argument|],
literal|0
argument|); 		*p = pn; 		*pc = pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup(*pc, 		    ao.addr16[
literal|0
argument|], an->addr16[
literal|0
argument|], u), 		    ao.addr16[
literal|1
argument|], an->addr16[
literal|1
argument|], u), 		    po, pn, u); 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		*pc = pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup( 		    pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup( 		    pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup(*pc, 		    ao.addr16[
literal|0
argument|], an->addr16[
literal|0
argument|], u), 		    ao.addr16[
literal|1
argument|], an->addr16[
literal|1
argument|], u), 		    ao.addr16[
literal|2
argument|], an->addr16[
literal|2
argument|], u), 		    ao.addr16[
literal|3
argument|], an->addr16[
literal|3
argument|], u), 		    ao.addr16[
literal|4
argument|], an->addr16[
literal|4
argument|], u), 		    ao.addr16[
literal|5
argument|], an->addr16[
literal|5
argument|], u), 		    ao.addr16[
literal|6
argument|], an->addr16[
literal|6
argument|], u), 		    ao.addr16[
literal|7
argument|], an->addr16[
literal|7
argument|], u), 		    po, pn, u); 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|} }
comment|/* Changes a u_int32_t.  Uses a void * so there are no align restrictions */
argument|void pf_change_a(void *a, u_int16_t *c, u_int32_t an, u_int8_t u) { 	u_int32_t	ao;  	memcpy(&ao, a, sizeof(ao)); 	memcpy(a,&an, sizeof(u_int32_t)); 	*c = pf_cksum_fixup(pf_cksum_fixup(*c, ao /
literal|65536
argument|, an /
literal|65536
argument|, u), 	    ao %
literal|65536
argument|, an %
literal|65536
argument|, u); }
ifdef|#
directive|ifdef
name|INET6
argument|void pf_change_a6(struct pf_addr *a, u_int16_t *c, struct pf_addr *an, u_int8_t u) { 	struct pf_addr	ao;  	PF_ACPY(&ao, a, AF_INET6); 	PF_ACPY(a, an, AF_INET6);  	*c = pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup( 	    pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup( 	    pf_cksum_fixup(pf_cksum_fixup(*c, 	    ao.addr16[
literal|0
argument|], an->addr16[
literal|0
argument|], u), 	    ao.addr16[
literal|1
argument|], an->addr16[
literal|1
argument|], u), 	    ao.addr16[
literal|2
argument|], an->addr16[
literal|2
argument|], u), 	    ao.addr16[
literal|3
argument|], an->addr16[
literal|3
argument|], u), 	    ao.addr16[
literal|4
argument|], an->addr16[
literal|4
argument|], u), 	    ao.addr16[
literal|5
argument|], an->addr16[
literal|5
argument|], u), 	    ao.addr16[
literal|6
argument|], an->addr16[
literal|6
argument|], u), 	    ao.addr16[
literal|7
argument|], an->addr16[
literal|7
argument|], u); }
endif|#
directive|endif
comment|/* INET6 */
argument|void pf_change_icmp(struct pf_addr *ia, u_int16_t *ip, struct pf_addr *oa,     struct pf_addr *na, u_int16_t np, u_int16_t *pc, u_int16_t *h2c,     u_int16_t *ic, u_int16_t *hc, u_int8_t u, sa_family_t af) { 	struct pf_addr	oia
argument_list|,
argument|ooa;  	PF_ACPY(&oia, ia, af); 	PF_ACPY(&ooa, oa, af);
comment|/* Change inner protocol port, fix inner protocol checksum. */
argument|if (ip != NULL) { 		u_int16_t	oip = *ip; 		u_int32_t	opc =
literal|0
argument|;
comment|/* make the compiler happy */
argument|if (pc != NULL) 			opc = *pc; 		*ip = np; 		if (pc != NULL) 			*pc = pf_cksum_fixup(*pc, oip, *ip, u); 		*ic = pf_cksum_fixup(*ic, oip, *ip,
literal|0
argument|); 		if (pc != NULL) 			*ic = pf_cksum_fixup(*ic, opc, *pc,
literal|0
argument|); 	}
comment|/* Change inner ip address, fix inner ip and icmp checksums. */
argument|PF_ACPY(ia, na, af); 	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: { 		u_int32_t	 oh2c = *h2c;  		*h2c = pf_cksum_fixup(pf_cksum_fixup(*h2c, 		    oia.addr16[
literal|0
argument|], ia->addr16[
literal|0
argument|],
literal|0
argument|), 		    oia.addr16[
literal|1
argument|], ia->addr16[
literal|1
argument|],
literal|0
argument|); 		*ic = pf_cksum_fixup(pf_cksum_fixup(*ic, 		    oia.addr16[
literal|0
argument|], ia->addr16[
literal|0
argument|],
literal|0
argument|), 		    oia.addr16[
literal|1
argument|], ia->addr16[
literal|1
argument|],
literal|0
argument|); 		*ic = pf_cksum_fixup(*ic, oh2c, *h2c,
literal|0
argument|); 		break; 	}
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		*ic = pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup( 		    pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup( 		    pf_cksum_fixup(pf_cksum_fixup(*ic, 		    oia.addr16[
literal|0
argument|], ia->addr16[
literal|0
argument|], u), 		    oia.addr16[
literal|1
argument|], ia->addr16[
literal|1
argument|], u), 		    oia.addr16[
literal|2
argument|], ia->addr16[
literal|2
argument|], u), 		    oia.addr16[
literal|3
argument|], ia->addr16[
literal|3
argument|], u), 		    oia.addr16[
literal|4
argument|], ia->addr16[
literal|4
argument|], u), 		    oia.addr16[
literal|5
argument|], ia->addr16[
literal|5
argument|], u), 		    oia.addr16[
literal|6
argument|], ia->addr16[
literal|6
argument|], u), 		    oia.addr16[
literal|7
argument|], ia->addr16[
literal|7
argument|], u); 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|}
comment|/* Change outer ip address, fix outer ip or icmpv6 checksum. */
argument|PF_ACPY(oa, na, af); 	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		*hc = pf_cksum_fixup(pf_cksum_fixup(*hc, 		    ooa.addr16[
literal|0
argument|], oa->addr16[
literal|0
argument|],
literal|0
argument|), 		    ooa.addr16[
literal|1
argument|], oa->addr16[
literal|1
argument|],
literal|0
argument|); 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		*ic = pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup( 		    pf_cksum_fixup(pf_cksum_fixup(pf_cksum_fixup( 		    pf_cksum_fixup(pf_cksum_fixup(*ic, 		    ooa.addr16[
literal|0
argument|], oa->addr16[
literal|0
argument|], u), 		    ooa.addr16[
literal|1
argument|], oa->addr16[
literal|1
argument|], u), 		    ooa.addr16[
literal|2
argument|], oa->addr16[
literal|2
argument|], u), 		    ooa.addr16[
literal|3
argument|], oa->addr16[
literal|3
argument|], u), 		    ooa.addr16[
literal|4
argument|], oa->addr16[
literal|4
argument|], u), 		    ooa.addr16[
literal|5
argument|], oa->addr16[
literal|5
argument|], u), 		    ooa.addr16[
literal|6
argument|], oa->addr16[
literal|6
argument|], u), 		    ooa.addr16[
literal|7
argument|], oa->addr16[
literal|7
argument|], u); 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|} }  void
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_send_tcp(struct mbuf *replyto, const struct pf_rule *r, sa_family_t af,
else|#
directive|else
argument|pf_send_tcp(const struct pf_rule *r, sa_family_t af,
endif|#
directive|endif
argument|const struct pf_addr *saddr, const struct pf_addr *daddr,     u_int16_t sport, u_int16_t dport, u_int32_t seq, u_int32_t ack,     u_int8_t flags, u_int16_t win, u_int16_t mss, u_int8_t ttl, int tag,     struct ether_header *eh, struct ifnet *ifp) { 	struct mbuf	*m; 	int		 len =
literal|0
argument|, tlen;
comment|/* make the compiler happy */
ifdef|#
directive|ifdef
name|INET
argument|struct ip	*h = NULL;
comment|/* make the compiler happy */
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|struct ip6_hdr	*h6 = NULL;
comment|/* make the compiler happy */
endif|#
directive|endif
comment|/* INET6 */
argument|struct tcphdr	*th = NULL;
comment|/* make the compiler happy */
argument|char *opt;
comment|/* maximum segment size tcp option */
argument|tlen = sizeof(struct tcphdr); 	if (mss) 		tlen +=
literal|4
argument|;  	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		len = sizeof(struct ip) + tlen; 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		len = sizeof(struct ip6_hdr) + tlen; 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|}
comment|/* create outgoing mbuf */
argument|m = m_gethdr(M_DONTWAIT, MT_HEADER); 	if (m == NULL) 		return;
ifdef|#
directive|ifdef
name|__FreeBSD__
ifdef|#
directive|ifdef
name|MAC
argument|if (replyto) 		mac_create_mbuf_netlayer(replyto, m); 	else 		mac_create_mbuf_from_firewall(m);
else|#
directive|else
argument|(void)replyto;
endif|#
directive|endif
endif|#
directive|endif
argument|if (tag) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|m->m_flags |= M_SKIP_FIREWALL;
else|#
directive|else
argument|struct m_tag	*mtag;  		mtag = m_tag_get(PACKET_TAG_PF_GENERATED,
literal|0
argument|, M_NOWAIT); 		if (mtag == NULL) { 			m_freem(m); 			return; 		} 		m_tag_prepend(m, mtag);
endif|#
directive|endif
argument|}
ifdef|#
directive|ifdef
name|ALTQ
argument|if (r != NULL&& r->qid) { 		struct m_tag	*mtag; 		struct altq_tag *atag;  		mtag = m_tag_get(PACKET_TAG_PF_QID, sizeof(*atag), M_NOWAIT); 		if (mtag != NULL) { 			atag = (struct altq_tag *)(mtag +
literal|1
argument|); 			atag->qid = r->qid;
comment|/* add hints for ecn */
argument|atag->af = af; 			atag->hdr = mtod(m, struct ip *); 			m_tag_prepend(m, mtag); 		} 	}
endif|#
directive|endif
comment|/* ALTQ */
argument|m->m_data += max_linkhdr; 	m->m_pkthdr.len = m->m_len = len; 	m->m_pkthdr.rcvif = NULL; 	bzero(m->m_data, len); 	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		h = mtod(m, struct ip *);
comment|/* IP header fields included in the TCP checksum */
argument|h->ip_p = IPPROTO_TCP; 		h->ip_len = htons(tlen); 		h->ip_src.s_addr = saddr->v4.s_addr; 		h->ip_dst.s_addr = daddr->v4.s_addr;  		th = (struct tcphdr *)((caddr_t)h + sizeof(struct ip)); 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		h6 = mtod(m, struct ip6_hdr *);
comment|/* IP header fields included in the TCP checksum */
argument|h6->ip6_nxt = IPPROTO_TCP; 		h6->ip6_plen = htons(tlen); 		memcpy(&h6->ip6_src,&saddr->v6, sizeof(struct in6_addr)); 		memcpy(&h6->ip6_dst,&daddr->v6, sizeof(struct in6_addr));  		th = (struct tcphdr *)((caddr_t)h6 + sizeof(struct ip6_hdr)); 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|}
comment|/* TCP header */
argument|th->th_sport = sport; 	th->th_dport = dport; 	th->th_seq = htonl(seq); 	th->th_ack = htonl(ack); 	th->th_off = tlen>>
literal|2
argument|; 	th->th_flags = flags; 	th->th_win = htons(win);  	if (mss) { 		opt = (char *)(th +
literal|1
argument|); 		opt[
literal|0
argument|] = TCPOPT_MAXSEG; 		opt[
literal|1
argument|] =
literal|4
argument|; 		HTONS(mss); 		bcopy((caddr_t)&mss, (caddr_t)(opt +
literal|2
argument|),
literal|2
argument|); 	}  	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET:
comment|/* TCP checksum */
argument|th->th_sum = in_cksum(m, len);
comment|/* Finish the IP header */
argument|h->ip_v =
literal|4
argument|; 		h->ip_hl = sizeof(*h)>>
literal|2
argument|; 		h->ip_tos = IPTOS_LOWDELAY;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|h->ip_off = path_mtu_discovery ? IP_DF :
literal|0
argument|; 		h->ip_len = len;
else|#
directive|else
argument|h->ip_off = htons(ip_mtudisc ? IP_DF :
literal|0
argument|); 		h->ip_len = htons(len);
endif|#
directive|endif
argument|h->ip_ttl = ttl ? ttl : ip_defttl; 		h->ip_sum =
literal|0
argument|; 		if (eh == NULL) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK(); 			ip_output(m, (void *)NULL, (void *)NULL,
literal|0
argument|, 			    (void *)NULL, (void *)NULL); 			PF_LOCK();
else|#
directive|else
comment|/* ! __FreeBSD__ */
argument|ip_output(m, (void *)NULL, (void *)NULL,
literal|0
argument|, 			    (void *)NULL, (void *)NULL);
endif|#
directive|endif
argument|} else { 			struct route		 ro; 			struct rtentry		 rt; 			struct ether_header	*e = (void *)ro.ro_dst.sa_data;  			if (ifp == NULL) { 				m_freem(m); 				return; 			} 			rt.rt_ifp = ifp; 			ro.ro_rt =&rt; 			ro.ro_dst.sa_len = sizeof(ro.ro_dst); 			ro.ro_dst.sa_family = pseudo_AF_HDRCMPLT; 			bcopy(eh->ether_dhost, e->ether_shost, ETHER_ADDR_LEN); 			bcopy(eh->ether_shost, e->ether_dhost, ETHER_ADDR_LEN); 			e->ether_type = eh->ether_type;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
comment|/* XXX_IMPORT: later */
argument|ip_output(m, (void *)NULL,&ro,
literal|0
argument|, 			    (void *)NULL, (void *)NULL); 			PF_LOCK();
else|#
directive|else
comment|/* ! __FreeBSD__ */
argument|ip_output(m, (void *)NULL,&ro, IP_ROUTETOETHER, 			    (void *)NULL, (void *)NULL);
endif|#
directive|endif
argument|} 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6:
comment|/* TCP checksum */
argument|th->th_sum = in6_cksum(m, IPPROTO_TCP, 		    sizeof(struct ip6_hdr), tlen);  		h6->ip6_vfc |= IPV6_VERSION; 		h6->ip6_hlim = IPV6_DEFHLIM;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK(); 		ip6_output(m, NULL, NULL,
literal|0
argument|, NULL, NULL, NULL); 		PF_LOCK();
else|#
directive|else
argument|ip6_output(m, NULL, NULL,
literal|0
argument|, NULL, NULL);
endif|#
directive|endif
argument|break;
endif|#
directive|endif
comment|/* INET6 */
argument|} }  void pf_send_icmp(struct mbuf *m, u_int8_t type, u_int8_t code, sa_family_t af,     struct pf_rule *r) {
ifdef|#
directive|ifdef
name|ALTQ
argument|struct m_tag	*mtag;
endif|#
directive|endif
argument|struct mbuf	*m0;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|struct ip *ip;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|m0 = m_copypacket(m, M_DONTWAIT); 	if (m0 == NULL) 		return; 	m0->m_flags |= M_SKIP_FIREWALL;
else|#
directive|else
argument|mtag = m_tag_get(PACKET_TAG_PF_GENERATED,
literal|0
argument|, M_NOWAIT); 	if (mtag == NULL) 		return; 	m0 = m_copy(m,
literal|0
argument|, M_COPYALL); 	if (m0 == NULL) { 		m_tag_free(mtag); 		return; 	} 	m_tag_prepend(m0, mtag);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ALTQ
argument|if (r->qid) { 		struct altq_tag *atag;  		mtag = m_tag_get(PACKET_TAG_PF_QID, sizeof(*atag), M_NOWAIT); 		if (mtag != NULL) { 			atag = (struct altq_tag *)(mtag +
literal|1
argument|); 			atag->qid = r->qid;
comment|/* add hints for ecn */
argument|atag->af = af; 			atag->hdr = mtod(m0, struct ip *); 			m_tag_prepend(m0, mtag); 		} 	}
endif|#
directive|endif
comment|/* ALTQ */
argument|switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET:
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* icmp_error() expects host byte ordering */
argument|ip = mtod(m0, struct ip *); 		NTOHS(ip->ip_len); 		NTOHS(ip->ip_off); 		PF_UNLOCK(); 		icmp_error(m0, type, code,
literal|0
argument|,
literal|0
argument|); 		PF_LOCK();
else|#
directive|else
argument|icmp_error(m0, type, code,
literal|0
argument|, (void *)NULL);
endif|#
directive|endif
argument|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6:
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
endif|#
directive|endif
argument|icmp6_error(m0, type, code,
literal|0
argument|);
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_LOCK();
endif|#
directive|endif
argument|break;
endif|#
directive|endif
comment|/* INET6 */
argument|} }
comment|/*  * Return 1 if the addresses a and b match (with mask m), otherwise return 0.  * If n is 0, they match if they are equal. If n is != 0, they match if they  * are different.  */
argument|int pf_match_addr(u_int8_t n, struct pf_addr *a, struct pf_addr *m,     struct pf_addr *b, sa_family_t af) { 	int	match =
literal|0
argument|;  	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		if ((a->addr32[
literal|0
argument|]& m->addr32[
literal|0
argument|]) == 		    (b->addr32[
literal|0
argument|]& m->addr32[
literal|0
argument|])) 			match++; 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		if (((a->addr32[
literal|0
argument|]& m->addr32[
literal|0
argument|]) == 		     (b->addr32[
literal|0
argument|]& m->addr32[
literal|0
argument|]))&& 		    ((a->addr32[
literal|1
argument|]& m->addr32[
literal|1
argument|]) == 		     (b->addr32[
literal|1
argument|]& m->addr32[
literal|1
argument|]))&& 		    ((a->addr32[
literal|2
argument|]& m->addr32[
literal|2
argument|]) == 		     (b->addr32[
literal|2
argument|]& m->addr32[
literal|2
argument|]))&& 		    ((a->addr32[
literal|3
argument|]& m->addr32[
literal|3
argument|]) == 		     (b->addr32[
literal|3
argument|]& m->addr32[
literal|3
argument|]))) 			match++; 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 	if (match) { 		if (n) 			return (
literal|0
argument|); 		else 			return (
literal|1
argument|); 	} else { 		if (n) 			return (
literal|1
argument|); 		else 			return (
literal|0
argument|); 	} }  int pf_match(u_int8_t op, u_int32_t a1, u_int32_t a2, u_int32_t p) { 	switch (op) { 	case PF_OP_IRG: 		return ((p> a1)&& (p< a2)); 	case PF_OP_XRG: 		return ((p< a1) || (p> a2)); 	case PF_OP_RRG: 		return ((p>= a1)&& (p<= a2)); 	case PF_OP_EQ: 		return (p == a1); 	case PF_OP_NE: 		return (p != a1); 	case PF_OP_LT: 		return (p< a1); 	case PF_OP_LE: 		return (p<= a1); 	case PF_OP_GT: 		return (p> a1); 	case PF_OP_GE: 		return (p>= a1); 	} 	return (
literal|0
argument|);
comment|/* never reached */
argument|}  int pf_match_port(u_int8_t op, u_int16_t a1, u_int16_t a2, u_int16_t p) { 	NTOHS(a1); 	NTOHS(a2); 	NTOHS(p); 	return (pf_match(op, a1, a2, p)); }  int pf_match_uid(u_int8_t op, uid_t a1, uid_t a2, uid_t u) { 	if (u == UID_MAX&& op != PF_OP_EQ&& op != PF_OP_NE) 		return (
literal|0
argument|); 	return (pf_match(op, a1, a2, u)); }  int pf_match_gid(u_int8_t op, gid_t a1, gid_t a2, gid_t g) { 	if (g == GID_MAX&& op != PF_OP_EQ&& op != PF_OP_NE) 		return (
literal|0
argument|); 	return (pf_match(op, a1, a2, g)); }  struct pf_tag * pf_get_tag(struct mbuf *m) { 	struct m_tag	*mtag;  	if ((mtag = m_tag_find(m, PACKET_TAG_PF_TAG, NULL)) != NULL) 		return ((struct pf_tag *)(mtag +
literal|1
argument|)); 	else 		return (NULL); }  int pf_match_tag(struct mbuf *m, struct pf_rule *r, struct pf_tag **pftag, int *tag) { 	if (*tag == -
literal|1
argument|) {
comment|/* find mbuf tag */
argument|*pftag = pf_get_tag(m); 		if (*pftag != NULL) 			*tag = (*pftag)->tag; 		else 			*tag =
literal|0
argument|; 	}  	return ((!r->match_tag_not&& r->match_tag == *tag) || 	    (r->match_tag_not&& r->match_tag != *tag)); }  int pf_tag_packet(struct mbuf *m, struct pf_tag *pftag, int tag) { 	struct m_tag	*mtag;  	if (tag<=
literal|0
argument|) 		return (
literal|0
argument|);  	if (pftag == NULL) { 		mtag = m_tag_get(PACKET_TAG_PF_TAG, sizeof(*pftag), M_NOWAIT); 		if (mtag == NULL) 			return (
literal|1
argument|); 		((struct pf_tag *)(mtag +
literal|1
argument|))->tag = tag; 		m_tag_prepend(m, mtag); 	} else 		pftag->tag = tag;  	return (
literal|0
argument|); }  static void pf_step_into_anchor(int *depth, struct pf_ruleset **rs, int n,     struct pf_rule **r, struct pf_rule **a) { 	struct pf_anchor_stackframe	*f;  	if (*depth>= sizeof(pf_anchor_stack) / 	    sizeof(pf_anchor_stack[
literal|0
argument|])) { 		printf(
literal|"pf_step_into_anchor: stack overflow\n"
argument|); 		*r = TAILQ_NEXT(*r, entries); 		return; 	} else if (*depth ==
literal|0
argument|&& a != NULL) 		*a = *r; 	f = pf_anchor_stack + (*depth)++; 	f->rs = *rs; 	f->r = *r; 	if ((*r)->anchor_wildcard) { 		f->parent =&(*r)->anchor->children; 		if ((f->child = RB_MIN(pf_anchor_node, f->parent)) == 		    NULL) { 			*r = NULL; 			return; 		} 		*rs =&f->child->ruleset; 	} else { 		f->parent = NULL; 		f->child = NULL; 		*rs =&(*r)->anchor->ruleset; 	} 	*r = TAILQ_FIRST((*rs)->rules[n].active.ptr); }  static void pf_step_out_of_anchor(int *depth, struct pf_ruleset **rs, int n,     struct pf_rule **r, struct pf_rule **a) { 	struct pf_anchor_stackframe	*f;  	do { 		if (*depth<=
literal|0
argument|) 			break; 		f = pf_anchor_stack + *depth -
literal|1
argument|; 		if (f->parent != NULL&& f->child != NULL) { 			f->child = RB_NEXT(pf_anchor_node, f->parent, f->child); 			if (f->child != NULL) { 				*rs =&f->child->ruleset; 				*r = TAILQ_FIRST((*rs)->rules[n].active.ptr); 				if (*r == NULL) 					continue; 				else 					break; 			} 		} 		(*depth)--; 		if (*depth ==
literal|0
argument|&& a != NULL) 			*a = NULL; 		*rs = f->rs; 		*r = TAILQ_NEXT(f->r, entries); 	} while (*r == NULL); }
ifdef|#
directive|ifdef
name|INET6
argument|void pf_poolmask(struct pf_addr *naddr, struct pf_addr *raddr,     struct pf_addr *rmask, struct pf_addr *saddr, sa_family_t af) { 	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		naddr->addr32[
literal|0
argument|] = (raddr->addr32[
literal|0
argument|]& rmask->addr32[
literal|0
argument|]) | 		((rmask->addr32[
literal|0
argument|] ^
literal|0xffffffff
argument|)& saddr->addr32[
literal|0
argument|]); 		break;
endif|#
directive|endif
comment|/* INET */
argument|case AF_INET6: 		naddr->addr32[
literal|0
argument|] = (raddr->addr32[
literal|0
argument|]& rmask->addr32[
literal|0
argument|]) | 		((rmask->addr32[
literal|0
argument|] ^
literal|0xffffffff
argument|)& saddr->addr32[
literal|0
argument|]); 		naddr->addr32[
literal|1
argument|] = (raddr->addr32[
literal|1
argument|]& rmask->addr32[
literal|1
argument|]) | 		((rmask->addr32[
literal|1
argument|] ^
literal|0xffffffff
argument|)& saddr->addr32[
literal|1
argument|]); 		naddr->addr32[
literal|2
argument|] = (raddr->addr32[
literal|2
argument|]& rmask->addr32[
literal|2
argument|]) | 		((rmask->addr32[
literal|2
argument|] ^
literal|0xffffffff
argument|)& saddr->addr32[
literal|2
argument|]); 		naddr->addr32[
literal|3
argument|] = (raddr->addr32[
literal|3
argument|]& rmask->addr32[
literal|3
argument|]) | 		((rmask->addr32[
literal|3
argument|] ^
literal|0xffffffff
argument|)& saddr->addr32[
literal|3
argument|]); 		break; 	} }  void pf_addr_inc(struct pf_addr *addr, sa_family_t af) { 	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		addr->addr32[
literal|0
argument|] = htonl(ntohl(addr->addr32[
literal|0
argument|]) +
literal|1
argument|); 		break;
endif|#
directive|endif
comment|/* INET */
argument|case AF_INET6: 		if (addr->addr32[
literal|3
argument|] ==
literal|0xffffffff
argument|) { 			addr->addr32[
literal|3
argument|] =
literal|0
argument|; 			if (addr->addr32[
literal|2
argument|] ==
literal|0xffffffff
argument|) { 				addr->addr32[
literal|2
argument|] =
literal|0
argument|; 				if (addr->addr32[
literal|1
argument|] ==
literal|0xffffffff
argument|) { 					addr->addr32[
literal|1
argument|] =
literal|0
argument|; 					addr->addr32[
literal|0
argument|] = 					    htonl(ntohl(addr->addr32[
literal|0
argument|]) +
literal|1
argument|); 				} else 					addr->addr32[
literal|1
argument|] = 					    htonl(ntohl(addr->addr32[
literal|1
argument|]) +
literal|1
argument|); 			} else 				addr->addr32[
literal|2
argument|] = 				    htonl(ntohl(addr->addr32[
literal|2
argument|]) +
literal|1
argument|); 		} else 			addr->addr32[
literal|3
argument|] = 			    htonl(ntohl(addr->addr32[
literal|3
argument|]) +
literal|1
argument|); 		break; 	} }
endif|#
directive|endif
comment|/* INET6 */
define|#
directive|define
name|mix
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|do {					\ 		a -= b; a -= c; a ^= (c>> 13);	\ 		b -= c; b -= a; b ^= (a<< 8);	\ 		c -= a; c -= b; c ^= (b>> 13);	\ 		a -= b; a -= c; a ^= (c>> 12);	\ 		b -= c; b -= a; b ^= (a<< 16);	\ 		c -= a; c -= b; c ^= (b>> 5);	\ 		a -= b; a -= c; a ^= (c>> 3);	\ 		b -= c; b -= a; b ^= (a<< 10);	\ 		c -= a; c -= b; c ^= (b>> 15);	\ 	} while (0)
comment|/*  * hash function based on bridge_hash in if_bridge.c  */
argument|void pf_hash(struct pf_addr *inaddr, struct pf_addr *hash,     struct pf_poolhashkey *key, sa_family_t af) { 	u_int32_t	a =
literal|0x9e3779b9
argument|, b =
literal|0x9e3779b9
argument|, c = key->key32[
literal|0
argument|];  	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		a += inaddr->addr32[
literal|0
argument|]; 		b += key->key32[
literal|1
argument|]; 		mix(a, b, c); 		hash->addr32[
literal|0
argument|] = c + key->key32[
literal|2
argument|]; 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		a += inaddr->addr32[
literal|0
argument|]; 		b += inaddr->addr32[
literal|2
argument|]; 		mix(a, b, c); 		hash->addr32[
literal|0
argument|] = c; 		a += inaddr->addr32[
literal|1
argument|]; 		b += inaddr->addr32[
literal|3
argument|]; 		c += key->key32[
literal|1
argument|]; 		mix(a, b, c); 		hash->addr32[
literal|1
argument|] = c; 		a += inaddr->addr32[
literal|2
argument|]; 		b += inaddr->addr32[
literal|1
argument|]; 		c += key->key32[
literal|2
argument|]; 		mix(a, b, c); 		hash->addr32[
literal|2
argument|] = c; 		a += inaddr->addr32[
literal|3
argument|]; 		b += inaddr->addr32[
literal|0
argument|]; 		c += key->key32[
literal|3
argument|]; 		mix(a, b, c); 		hash->addr32[
literal|3
argument|] = c; 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|} }  int pf_map_addr(sa_family_t af, struct pf_rule *r, struct pf_addr *saddr,     struct pf_addr *naddr, struct pf_addr *init_addr, struct pf_src_node **sn) { 	unsigned char		 hash[
literal|16
argument|]; 	struct pf_pool		*rpool =&r->rpool; 	struct pf_addr		*raddr =&rpool->cur->addr.v.a.addr; 	struct pf_addr		*rmask =&rpool->cur->addr.v.a.mask; 	struct pf_pooladdr	*acur = rpool->cur; 	struct pf_src_node	 k;  	if (*sn == NULL&& r->rpool.opts& PF_POOL_STICKYADDR&& 	    (r->rpool.opts& PF_POOL_TYPEMASK) != PF_POOL_NONE) { 		k.af = af; 		PF_ACPY(&k.addr, saddr, af); 		if (r->rule_flag& PFRULE_RULESRCTRACK || 		    r->rpool.opts& PF_POOL_STICKYADDR) 			k.rule.ptr = r; 		else 			k.rule.ptr = NULL; 		pf_status.scounters[SCNT_SRC_NODE_SEARCH]++; 		*sn = RB_FIND(pf_src_tree,&tree_src_tracking,&k); 		if (*sn != NULL&& !PF_AZERO(&(*sn)->raddr, af)) { 			PF_ACPY(naddr,&(*sn)->raddr, af); 			if (pf_status.debug>= PF_DEBUG_MISC) { 				printf(
literal|"pf_map_addr: src tracking maps "
argument|); 				pf_print_host(&k.addr,
literal|0
argument|, af); 				printf(
literal|" to "
argument|); 				pf_print_host(naddr,
literal|0
argument|, af); 				printf(
literal|"\n"
argument|); 			} 			return (
literal|0
argument|); 		} 	}  	if (rpool->cur->addr.type == PF_ADDR_NOROUTE) 		return (
literal|1
argument|); 	if (rpool->cur->addr.type == PF_ADDR_DYNIFTL) { 		switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 			if (rpool->cur->addr.p.dyn->pfid_acnt4<
literal|1
argument|&& 			    (rpool->opts& PF_POOL_TYPEMASK) != 			    PF_POOL_ROUNDROBIN) 				return (
literal|1
argument|); 			 raddr =&rpool->cur->addr.p.dyn->pfid_addr4; 			 rmask =&rpool->cur->addr.p.dyn->pfid_mask4; 			break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 			if (rpool->cur->addr.p.dyn->pfid_acnt6<
literal|1
argument|&& 			    (rpool->opts& PF_POOL_TYPEMASK) != 			    PF_POOL_ROUNDROBIN) 				return (
literal|1
argument|); 			raddr =&rpool->cur->addr.p.dyn->pfid_addr6; 			rmask =&rpool->cur->addr.p.dyn->pfid_mask6; 			break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 	} else if (rpool->cur->addr.type == PF_ADDR_TABLE) { 		if ((rpool->opts& PF_POOL_TYPEMASK) != PF_POOL_ROUNDROBIN) 			return (
literal|1
argument|);
comment|/* unsupported */
argument|} else { 		raddr =&rpool->cur->addr.v.a.addr; 		rmask =&rpool->cur->addr.v.a.mask; 	}  	switch (rpool->opts& PF_POOL_TYPEMASK) { 	case PF_POOL_NONE: 		PF_ACPY(naddr, raddr, af); 		break; 	case PF_POOL_BITMASK: 		PF_POOLMASK(naddr, raddr, rmask, saddr, af); 		break; 	case PF_POOL_RANDOM: 		if (init_addr != NULL&& PF_AZERO(init_addr, af)) { 			switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 				rpool->counter.addr32[
literal|0
argument|] = htonl(arc4random()); 				break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 				if (rmask->addr32[
literal|3
argument|] !=
literal|0xffffffff
argument|) 					rpool->counter.addr32[
literal|3
argument|] = 					    htonl(arc4random()); 				else 					break; 				if (rmask->addr32[
literal|2
argument|] !=
literal|0xffffffff
argument|) 					rpool->counter.addr32[
literal|2
argument|] = 					    htonl(arc4random()); 				else 					break; 				if (rmask->addr32[
literal|1
argument|] !=
literal|0xffffffff
argument|) 					rpool->counter.addr32[
literal|1
argument|] = 					    htonl(arc4random()); 				else 					break; 				if (rmask->addr32[
literal|0
argument|] !=
literal|0xffffffff
argument|) 					rpool->counter.addr32[
literal|0
argument|] = 					    htonl(arc4random()); 				break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 			PF_POOLMASK(naddr, raddr, rmask,&rpool->counter, af); 			PF_ACPY(init_addr, naddr, af);  		} else { 			PF_AINC(&rpool->counter, af); 			PF_POOLMASK(naddr, raddr, rmask,&rpool->counter, af); 		} 		break; 	case PF_POOL_SRCHASH: 		pf_hash(saddr, (struct pf_addr *)&hash,&rpool->key, af); 		PF_POOLMASK(naddr, raddr, rmask, (struct pf_addr *)&hash, af); 		break; 	case PF_POOL_ROUNDROBIN: 		if (rpool->cur->addr.type == PF_ADDR_TABLE) { 			if (!pfr_pool_get(rpool->cur->addr.p.tbl,&rpool->tblidx,&rpool->counter,&raddr,&rmask, af)) 				goto get_addr; 		} else if (rpool->cur->addr.type == PF_ADDR_DYNIFTL) { 			if (!pfr_pool_get(rpool->cur->addr.p.dyn->pfid_kt,&rpool->tblidx,&rpool->counter,&raddr,&rmask, af)) 				goto get_addr; 		} else if (pf_match_addr(
literal|0
argument|, raddr, rmask,&rpool->counter, af)) 			goto get_addr;  	try_next: 		if ((rpool->cur = TAILQ_NEXT(rpool->cur, entries)) == NULL) 			rpool->cur = TAILQ_FIRST(&rpool->list); 		if (rpool->cur->addr.type == PF_ADDR_TABLE) { 			rpool->tblidx = -
literal|1
argument|; 			if (pfr_pool_get(rpool->cur->addr.p.tbl,&rpool->tblidx,&rpool->counter,&raddr,&rmask, af)) {
comment|/* table contains no address of type 'af' */
argument|if (rpool->cur != acur) 					goto try_next; 				return (
literal|1
argument|); 			} 		} else if (rpool->cur->addr.type == PF_ADDR_DYNIFTL) { 			rpool->tblidx = -
literal|1
argument|; 			if (pfr_pool_get(rpool->cur->addr.p.dyn->pfid_kt,&rpool->tblidx,&rpool->counter,&raddr,&rmask, af)) {
comment|/* table contains no address of type 'af' */
argument|if (rpool->cur != acur) 					goto try_next; 				return (
literal|1
argument|); 			} 		} else { 			raddr =&rpool->cur->addr.v.a.addr; 			rmask =&rpool->cur->addr.v.a.mask; 			PF_ACPY(&rpool->counter, raddr, af); 		}  	get_addr: 		PF_ACPY(naddr,&rpool->counter, af); 		if (init_addr != NULL&& PF_AZERO(init_addr, af)) 			PF_ACPY(init_addr, naddr, af); 		PF_AINC(&rpool->counter, af); 		break; 	} 	if (*sn != NULL) 		PF_ACPY(&(*sn)->raddr, naddr, af);  	if (pf_status.debug>= PF_DEBUG_MISC&& 	    (rpool->opts& PF_POOL_TYPEMASK) != PF_POOL_NONE) { 		printf(
literal|"pf_map_addr: selected address "
argument|); 		pf_print_host(naddr,
literal|0
argument|, af); 		printf(
literal|"\n"
argument|); 	}  	return (
literal|0
argument|); }  int pf_get_sport(sa_family_t af, u_int8_t proto, struct pf_rule *r,     struct pf_addr *saddr, struct pf_addr *daddr, u_int16_t dport,     struct pf_addr *naddr, u_int16_t *nport, u_int16_t low, u_int16_t high,     struct pf_src_node **sn) { 	struct pf_state		key; 	struct pf_addr		init_addr; 	u_int16_t		cut;  	bzero(&init_addr, sizeof(init_addr)); 	if (pf_map_addr(af, r, saddr, naddr,&init_addr, sn)) 		return (
literal|1
argument|);  	if (proto == IPPROTO_ICMP) { 		low =
literal|1
argument|; 		high =
literal|65535
argument|; 	}  	do { 		key.af = af; 		key.proto = proto; 		PF_ACPY(&key.ext.addr, daddr, key.af); 		PF_ACPY(&key.gwy.addr, naddr, key.af); 		key.ext.port = dport;
comment|/* 		 * port search; start random, step; 		 * similar 2 portloop in in_pcbbind 		 */
argument|if (!(proto == IPPROTO_TCP || proto == IPPROTO_UDP || 		    proto == IPPROTO_ICMP)) { 			key.gwy.port = dport; 			if (pf_find_state_all(&key, PF_EXT_GWY, NULL) == NULL) 				return (
literal|0
argument|); 		} else if (low ==
literal|0
argument|&& high ==
literal|0
argument|) { 			key.gwy.port = *nport; 			if (pf_find_state_all(&key, PF_EXT_GWY, NULL) == NULL) 				return (
literal|0
argument|); 		} else if (low == high) { 			key.gwy.port = htons(low); 			if (pf_find_state_all(&key, PF_EXT_GWY, NULL) == NULL) { 				*nport = htons(low); 				return (
literal|0
argument|); 			} 		} else { 			u_int16_t tmp;  			if (low> high) { 				tmp = low; 				low = high; 				high = tmp; 			}
comment|/* low< high */
argument|cut = htonl(arc4random()) % (
literal|1
argument|+ high - low) + low;
comment|/* low<= cut<= high */
argument|for (tmp = cut; tmp<= high; ++(tmp)) { 				key.gwy.port = htons(tmp); 				if (pf_find_state_all(&key, PF_EXT_GWY, NULL) == 				    NULL) { 					*nport = htons(tmp); 					return (
literal|0
argument|); 				} 			} 			for (tmp = cut -
literal|1
argument|; tmp>= low; --(tmp)) { 				key.gwy.port = htons(tmp); 				if (pf_find_state_all(&key, PF_EXT_GWY, NULL) == 				    NULL) { 					*nport = htons(tmp); 					return (
literal|0
argument|); 				} 			} 		}  		switch (r->rpool.opts& PF_POOL_TYPEMASK) { 		case PF_POOL_RANDOM: 		case PF_POOL_ROUNDROBIN: 			if (pf_map_addr(af, r, saddr, naddr,&init_addr, sn)) 				return (
literal|1
argument|); 			break; 		case PF_POOL_NONE: 		case PF_POOL_SRCHASH: 		case PF_POOL_BITMASK: 		default: 			return (
literal|1
argument|); 		} 	} while (! PF_AEQ(&init_addr, naddr, af) );  	return (
literal|1
argument|);
comment|/* none available */
argument|}  struct pf_rule * pf_match_translation(struct pf_pdesc *pd, struct mbuf *m, int off,     int direction, struct pfi_kif *kif, struct pf_addr *saddr, u_int16_t sport,     struct pf_addr *daddr, u_int16_t dport, int rs_num) { 	struct pf_rule		*r, *rm = NULL; 	struct pf_ruleset	*ruleset = NULL; 	struct pf_tag		*pftag = NULL; 	int			 tag = -
literal|1
argument|; 	int			 asd =
literal|0
argument|;  	r = TAILQ_FIRST(pf_main_ruleset.rules[rs_num].active.ptr); 	while (r&& rm == NULL) { 		struct pf_rule_addr	*src = NULL, *dst = NULL; 		struct pf_addr_wrap	*xdst = NULL;  		if (r->action == PF_BINAT&& direction == PF_IN) { 			src =&r->dst; 			if (r->rpool.cur != NULL) 				xdst =&r->rpool.cur->addr; 		} else { 			src =&r->src; 			dst =&r->dst; 		}  		r->evaluations++; 		if (r->kif != NULL&& 		    (r->kif != kif&& r->kif != kif->pfik_parent) == !r->ifnot) 			r = r->skip[PF_SKIP_IFP].ptr; 		else if (r->direction&& r->direction != direction) 			r = r->skip[PF_SKIP_DIR].ptr; 		else if (r->af&& r->af != pd->af) 			r = r->skip[PF_SKIP_AF].ptr; 		else if (r->proto&& r->proto != pd->proto) 			r = r->skip[PF_SKIP_PROTO].ptr; 		else if (PF_MISMATCHAW(&src->addr, saddr, pd->af, src->neg)) 			r = r->skip[src ==&r->src ? PF_SKIP_SRC_ADDR : 			    PF_SKIP_DST_ADDR].ptr; 		else if (src->port_op&& !pf_match_port(src->port_op, 		    src->port[
literal|0
argument|], src->port[
literal|1
argument|], sport)) 			r = r->skip[src ==&r->src ? PF_SKIP_SRC_PORT : 			    PF_SKIP_DST_PORT].ptr; 		else if (dst != NULL&& 		    PF_MISMATCHAW(&dst->addr, daddr, pd->af, dst->neg)) 			r = r->skip[PF_SKIP_DST_ADDR].ptr; 		else if (xdst != NULL&& PF_MISMATCHAW(xdst, daddr, pd->af,
literal|0
argument|)) 			r = TAILQ_NEXT(r, entries); 		else if (dst != NULL&& dst->port_op&& 		    !pf_match_port(dst->port_op, dst->port[
literal|0
argument|], 		    dst->port[
literal|1
argument|], dport)) 			r = r->skip[PF_SKIP_DST_PORT].ptr; 		else if (r->match_tag&& !pf_match_tag(m, r,&pftag,&tag)) 			r = TAILQ_NEXT(r, entries); 		else if (r->os_fingerprint != PF_OSFP_ANY&& (pd->proto != 		    IPPROTO_TCP || !pf_osfp_match(pf_osfp_fingerprint(pd, m, 		    off, pd->hdr.tcp), r->os_fingerprint))) 			r = TAILQ_NEXT(r, entries); 		else { 			if (r->tag) 				tag = r->tag; 			if (r->anchor == NULL) { 				rm = r; 			} else 				pf_step_into_anchor(&asd,&ruleset, rs_num,&r, NULL); 		} 		if (r == NULL) 			pf_step_out_of_anchor(&asd,&ruleset, rs_num,&r, NULL); 	} 	if (pf_tag_packet(m, pftag, tag)) 		return (NULL); 	if (rm != NULL&& (rm->action == PF_NONAT || 	    rm->action == PF_NORDR || rm->action == PF_NOBINAT)) 		return (NULL); 	return (rm); }  struct pf_rule * pf_get_translation(struct pf_pdesc *pd, struct mbuf *m, int off, int direction,     struct pfi_kif *kif, struct pf_src_node **sn,     struct pf_addr *saddr, u_int16_t sport,     struct pf_addr *daddr, u_int16_t dport,     struct pf_addr *naddr, u_int16_t *nport) { 	struct pf_rule	*r = NULL;  	if (direction == PF_OUT) { 		r = pf_match_translation(pd, m, off, direction, kif, saddr, 		    sport, daddr, dport, PF_RULESET_BINAT); 		if (r == NULL) 			r = pf_match_translation(pd, m, off, direction, kif, 			    saddr, sport, daddr, dport, PF_RULESET_NAT); 	} else { 		r = pf_match_translation(pd, m, off, direction, kif, saddr, 		    sport, daddr, dport, PF_RULESET_RDR); 		if (r == NULL) 			r = pf_match_translation(pd, m, off, direction, kif, 			    saddr, sport, daddr, dport, PF_RULESET_BINAT); 	}  	if (r != NULL) { 		switch (r->action) { 		case PF_NONAT: 		case PF_NOBINAT: 		case PF_NORDR: 			return (NULL); 		case PF_NAT: 			if (pf_get_sport(pd->af, pd->proto, r, saddr, 			    daddr, dport, naddr, nport, r->rpool.proxy_port[
literal|0
argument|], 			    r->rpool.proxy_port[
literal|1
argument|], sn)) { 				DPFPRINTF(PF_DEBUG_MISC, 				    (
literal|"pf: NAT proxy port allocation "
literal|"(%u-%u) failed\n"
argument|, 				    r->rpool.proxy_port[
literal|0
argument|], 				    r->rpool.proxy_port[
literal|1
argument|])); 				return (NULL); 			} 			break; 		case PF_BINAT: 			switch (direction) { 			case PF_OUT: 				if (r->rpool.cur->addr.type == PF_ADDR_DYNIFTL){ 					switch (pd->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 						if (r->rpool.cur->addr.p.dyn-> 						    pfid_acnt4<
literal|1
argument|) 							return (NULL); 						PF_POOLMASK(naddr,&r->rpool.cur->addr.p.dyn-> 						    pfid_addr4,&r->rpool.cur->addr.p.dyn-> 						    pfid_mask4, 						    saddr, AF_INET); 						break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 						if (r->rpool.cur->addr.p.dyn-> 						    pfid_acnt6<
literal|1
argument|) 							return (NULL); 						PF_POOLMASK(naddr,&r->rpool.cur->addr.p.dyn-> 						    pfid_addr6,&r->rpool.cur->addr.p.dyn-> 						    pfid_mask6, 						    saddr, AF_INET6); 						break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 				} else 					PF_POOLMASK(naddr,&r->rpool.cur->addr.v.a.addr,&r->rpool.cur->addr.v.a.mask, 					    saddr, pd->af); 				break; 			case PF_IN: 				if (r->src.addr.type == PF_ADDR_DYNIFTL) { 					switch (pd->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 						if (r->src.addr.p.dyn-> 						    pfid_acnt4<
literal|1
argument|) 							return (NULL); 						PF_POOLMASK(naddr,&r->src.addr.p.dyn-> 						    pfid_addr4,&r->src.addr.p.dyn-> 						    pfid_mask4, 						    daddr, AF_INET); 						break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 						if (r->src.addr.p.dyn-> 						    pfid_acnt6<
literal|1
argument|) 							return (NULL); 						PF_POOLMASK(naddr,&r->src.addr.p.dyn-> 						    pfid_addr6,&r->src.addr.p.dyn-> 						    pfid_mask6, 						    daddr, AF_INET6); 						break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 				} else 					PF_POOLMASK(naddr,&r->src.addr.v.a.addr,&r->src.addr.v.a.mask, daddr, 					    pd->af); 				break; 			} 			break; 		case PF_RDR: { 			if (pf_map_addr(pd->af, r, saddr, naddr, NULL, sn)) 				return (NULL); 			if ((r->rpool.opts& PF_POOL_TYPEMASK) == 			    PF_POOL_BITMASK) 				PF_POOLMASK(naddr, naddr,&r->rpool.cur->addr.v.a.mask, daddr, 				    pd->af);  			if (r->rpool.proxy_port[
literal|1
argument|]) { 				u_int32_t	tmp_nport;  				tmp_nport = ((ntohs(dport) - 				    ntohs(r->dst.port[
literal|0
argument|])) % 				    (r->rpool.proxy_port[
literal|1
argument|] - 				    r->rpool.proxy_port[
literal|0
argument|] +
literal|1
argument|)) + 				    r->rpool.proxy_port[
literal|0
argument|];
comment|/* wrap around if necessary */
argument|if (tmp_nport>
literal|65535
argument|) 					tmp_nport -=
literal|65535
argument|; 				*nport = htons((u_int16_t)tmp_nport); 			} else if (r->rpool.proxy_port[
literal|0
argument|]) 				*nport = htons(r->rpool.proxy_port[
literal|0
argument|]); 			break; 		} 		default: 			return (NULL); 		} 	}  	return (r); }  int
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_socket_lookup(uid_t *uid, gid_t *gid, int direction, struct pf_pdesc *pd,     struct inpcb *inp_arg)
else|#
directive|else
argument|pf_socket_lookup(uid_t *uid, gid_t *gid, int direction, struct pf_pdesc *pd)
endif|#
directive|endif
argument|{ 	struct pf_addr		*saddr, *daddr; 	u_int16_t		 sport, dport;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|struct inpcbinfo	*pi;
else|#
directive|else
argument|struct inpcbtable	*tb;
endif|#
directive|endif
argument|struct inpcb		*inp;  	*uid = UID_MAX; 	*gid = GID_MAX;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|if (inp_arg != NULL) { 		INP_LOCK_ASSERT(inp_arg); 		if (inp_arg->inp_socket) { 			*uid = inp_arg->inp_socket->so_cred->cr_uid; 			*gid = inp_arg->inp_socket->so_cred->cr_groups[
literal|0
argument|]; 			return (
literal|1
argument|); 		} else 			return (
literal|0
argument|); 	}
endif|#
directive|endif
argument|switch (pd->proto) { 	case IPPROTO_TCP: 		sport = pd->hdr.tcp->th_sport; 		dport = pd->hdr.tcp->th_dport;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pi =&tcbinfo;
else|#
directive|else
argument|tb =&tcbtable;
endif|#
directive|endif
argument|break; 	case IPPROTO_UDP: 		sport = pd->hdr.udp->uh_sport; 		dport = pd->hdr.udp->uh_dport;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pi =&udbinfo;
else|#
directive|else
argument|tb =&udbtable;
endif|#
directive|endif
argument|break; 	default: 		return (
literal|0
argument|); 	} 	if (direction == PF_IN) { 		saddr = pd->src; 		daddr = pd->dst; 	} else { 		u_int16_t	p;  		p = sport; 		sport = dport; 		dport = p; 		saddr = pd->dst; 		daddr = pd->src; 	} 	switch (pd->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET:
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|INP_INFO_RLOCK(pi);
comment|/* XXX LOR */
argument|inp = in_pcblookup_hash(pi, saddr->v4, sport, daddr->v4, 			dport,
literal|0
argument|, NULL); 		if (inp == NULL) { 			inp = in_pcblookup_hash(pi, saddr->v4, sport, 			   daddr->v4, dport, INPLOOKUP_WILDCARD, NULL); 			if(inp == NULL) { 				INP_INFO_RUNLOCK(pi); 				return (
literal|0
argument|); 			} 		}
else|#
directive|else
argument|inp = in_pcbhashlookup(tb, saddr->v4, sport, daddr->v4, dport); 		if (inp == NULL) { 			inp = in_pcblookup_listen(tb, daddr->v4, dport,
literal|0
argument|); 			if (inp == NULL) 				return (
literal|0
argument|); 		}
endif|#
directive|endif
argument|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6:
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|INP_INFO_RLOCK(pi); 		inp = in6_pcblookup_hash(pi,&saddr->v6, sport,&daddr->v6, dport,
literal|0
argument|, NULL); 		if (inp == NULL) { 			inp = in6_pcblookup_hash(pi,&saddr->v6, sport,&daddr->v6, dport, INPLOOKUP_WILDCARD, NULL); 			if (inp == NULL) { 				INP_INFO_RUNLOCK(pi); 				return (
literal|0
argument|); 			} 		}
else|#
directive|else
argument|inp = in6_pcbhashlookup(tb,&saddr->v6, sport,&daddr->v6, 		    dport); 		if (inp == NULL) { 			inp = in6_pcblookup_listen(tb,&daddr->v6, dport,
literal|0
argument|); 			if (inp == NULL) 				return (
literal|0
argument|); 		}
endif|#
directive|endif
argument|break;
endif|#
directive|endif
comment|/* INET6 */
argument|default: 		return (
literal|0
argument|); 	}
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|INP_LOCK(inp); 	if ((inp->inp_socket == NULL) || (inp->inp_socket->so_cred == NULL)) { 		INP_UNLOCK(inp); 		INP_INFO_RUNLOCK(pi); 		return (
literal|0
argument|); 	} 	*uid = inp->inp_socket->so_cred->cr_uid; 	*gid = inp->inp_socket->so_cred->cr_groups[
literal|0
argument|]; 	INP_UNLOCK(inp); 	INP_INFO_RUNLOCK(pi);
else|#
directive|else
argument|*uid = inp->inp_socket->so_euid; 	*gid = inp->inp_socket->so_egid;
endif|#
directive|endif
argument|return (
literal|1
argument|); }  u_int8_t pf_get_wscale(struct mbuf *m, int off, u_int16_t th_off, sa_family_t af) { 	int		 hlen; 	u_int8_t	 hdr[
literal|60
argument|]; 	u_int8_t	*opt, optlen; 	u_int8_t	 wscale =
literal|0
argument|;  	hlen = th_off<<
literal|2
argument|;
comment|/* hlen<= sizeof(hdr) */
argument|if (hlen<= sizeof(struct tcphdr)) 		return (
literal|0
argument|); 	if (!pf_pull_hdr(m, off, hdr, hlen, NULL, NULL, af)) 		return (
literal|0
argument|); 	opt = hdr + sizeof(struct tcphdr); 	hlen -= sizeof(struct tcphdr); 	while (hlen>=
literal|3
argument|) { 		switch (*opt) { 		case TCPOPT_EOL: 		case TCPOPT_NOP: 			++opt; 			--hlen; 			break; 		case TCPOPT_WINDOW: 			wscale = opt[
literal|2
argument|]; 			if (wscale> TCP_MAX_WINSHIFT) 				wscale = TCP_MAX_WINSHIFT; 			wscale |= PF_WSCALE_FLAG;
comment|/* FALLTHROUGH */
argument|default: 			optlen = opt[
literal|1
argument|]; 			if (optlen<
literal|2
argument|) 				optlen =
literal|2
argument|; 			hlen -= optlen; 			opt += optlen; 			break; 		} 	} 	return (wscale); }  u_int16_t pf_get_mss(struct mbuf *m, int off, u_int16_t th_off, sa_family_t af) { 	int		 hlen; 	u_int8_t	 hdr[
literal|60
argument|]; 	u_int8_t	*opt, optlen; 	u_int16_t	 mss = tcp_mssdflt;  	hlen = th_off<<
literal|2
argument|;
comment|/* hlen<= sizeof(hdr) */
argument|if (hlen<= sizeof(struct tcphdr)) 		return (
literal|0
argument|); 	if (!pf_pull_hdr(m, off, hdr, hlen, NULL, NULL, af)) 		return (
literal|0
argument|); 	opt = hdr + sizeof(struct tcphdr); 	hlen -= sizeof(struct tcphdr); 	while (hlen>= TCPOLEN_MAXSEG) { 		switch (*opt) { 		case TCPOPT_EOL: 		case TCPOPT_NOP: 			++opt; 			--hlen; 			break; 		case TCPOPT_MAXSEG: 			bcopy((caddr_t)(opt +
literal|2
argument|), (caddr_t)&mss,
literal|2
argument|); 			NTOHS(mss);
comment|/* FALLTHROUGH */
argument|default: 			optlen = opt[
literal|1
argument|]; 			if (optlen<
literal|2
argument|) 				optlen =
literal|2
argument|; 			hlen -= optlen; 			opt += optlen; 			break; 		} 	} 	return (mss); }  u_int16_t pf_calc_mss(struct pf_addr *addr, sa_family_t af, u_int16_t offer) {
ifdef|#
directive|ifdef
name|INET
argument|struct sockaddr_in	*dst; 	struct route		 ro;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|struct sockaddr_in6	*dst6; 	struct route_in6	 ro6;
endif|#
directive|endif
comment|/* INET6 */
argument|struct rtentry		*rt = NULL; 	int			 hlen =
literal|0
argument|;
comment|/* make the compiler happy */
argument|u_int16_t		 mss = tcp_mssdflt;  	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		hlen = sizeof(struct ip); 		bzero(&ro, sizeof(ro)); 		dst = (struct sockaddr_in *)&ro.ro_dst; 		dst->sin_family = AF_INET; 		dst->sin_len = sizeof(*dst); 		dst->sin_addr = addr->v4;
ifdef|#
directive|ifdef
name|__FreeBSD__
ifdef|#
directive|ifdef
name|RTF_PRCLONING
argument|rtalloc_ign(&ro, (RTF_CLONING | RTF_PRCLONING));
else|#
directive|else
comment|/* !RTF_PRCLONING */
argument|rtalloc_ign(&ro, RTF_CLONING);
endif|#
directive|endif
else|#
directive|else
comment|/* ! __FreeBSD__ */
argument|rtalloc_noclone(&ro, NO_CLONING);
endif|#
directive|endif
argument|rt = ro.ro_rt; 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		hlen = sizeof(struct ip6_hdr); 		bzero(&ro6, sizeof(ro6)); 		dst6 = (struct sockaddr_in6 *)&ro6.ro_dst; 		dst6->sin6_family = AF_INET6; 		dst6->sin6_len = sizeof(*dst6); 		dst6->sin6_addr = addr->v6;
ifdef|#
directive|ifdef
name|__FreeBSD__
ifdef|#
directive|ifdef
name|RTF_PRCLONING
argument|rtalloc_ign((struct route *)&ro6, 		    (RTF_CLONING | RTF_PRCLONING));
else|#
directive|else
comment|/* !RTF_PRCLONING */
argument|rtalloc_ign((struct route *)&ro6, RTF_CLONING);
endif|#
directive|endif
else|#
directive|else
comment|/* ! __FreeBSD__ */
argument|rtalloc_noclone((struct route *)&ro6, NO_CLONING);
endif|#
directive|endif
argument|rt = ro6.ro_rt; 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|}  	if (rt&& rt->rt_ifp) { 		mss = rt->rt_ifp->if_mtu - hlen - sizeof(struct tcphdr); 		mss = max(tcp_mssdflt, mss); 		RTFREE(rt); 	} 	mss = min(mss, offer); 	mss = max(mss,
literal|64
argument|);
comment|/* sanity - at least max opt space */
argument|return (mss); }  void pf_set_rt_ifp(struct pf_state *s, struct pf_addr *saddr) { 	struct pf_rule *r = s->rule.ptr;  	s->rt_kif = NULL; 	if (!r->rt || r->rt == PF_FASTROUTE) 		return; 	switch (s->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		pf_map_addr(AF_INET, r, saddr,&s->rt_addr, NULL,&s->nat_src_node); 		s->rt_kif = r->rpool.cur->kif; 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		pf_map_addr(AF_INET6, r, saddr,&s->rt_addr, NULL,&s->nat_src_node); 		s->rt_kif = r->rpool.cur->kif; 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|} }  int pf_test_tcp(struct pf_rule **rm, struct pf_state **sm, int direction,     struct pfi_kif *kif, struct mbuf *m, int off, void *h,
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|struct pf_pdesc *pd, struct pf_rule **am, struct pf_ruleset **rsm,     struct ifqueue *ifq, struct inpcb *inp)
else|#
directive|else
argument|struct pf_pdesc *pd, struct pf_rule **am, struct pf_ruleset **rsm,     struct ifqueue *ifq)
endif|#
directive|endif
argument|{ 	struct pf_rule		*nr = NULL; 	struct pf_addr		*saddr = pd->src
argument_list|,
argument|*daddr = pd->dst; 	struct tcphdr		*th = pd->hdr.tcp; 	u_int16_t		 bport
argument_list|,
argument|nport =
literal|0
argument|; 	sa_family_t		 af = pd->af; 	int			 lookup = -
literal|1
argument|; 	uid_t			 uid; 	gid_t			 gid; 	struct pf_rule		*r
argument_list|,
argument|*a = NULL; 	struct pf_ruleset	*ruleset = NULL; 	struct pf_src_node	*nsn = NULL; 	u_short			 reason; 	int			 rewrite =
literal|0
argument|; 	struct pf_tag		*pftag = NULL; 	int			 tag = -
literal|1
argument|; 	u_int16_t		 mss = tcp_mssdflt; 	int			 asd =
literal|0
argument|;  	if (pf_check_congestion(ifq)) { 		REASON_SET(&reason, PFRES_CONGEST); 		return (PF_DROP); 	}
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|PF_MPSAFE_UGID
argument_list|)
argument|PF_UNLOCK(); 	lookup = pf_socket_lookup(&uid,&gid, direction, pd, inp); 	PF_LOCK();
endif|#
directive|endif
argument|r = TAILQ_FIRST(pf_main_ruleset.rules[PF_RULESET_FILTER].active.ptr);  	if (direction == PF_OUT) { 		bport = nport = th->th_sport;
comment|/* check outgoing packet for BINAT/NAT */
argument|if ((nr = pf_get_translation(pd, m, off, PF_OUT, kif,&nsn, 		    saddr, th->th_sport, daddr, th->th_dport,&pd->naddr,&nport)) != NULL) { 			PF_ACPY(&pd->baddr, saddr, af); 			pf_change_ap(saddr,&th->th_sport, pd->ip_sum,&th->th_sum,&pd->naddr, nport,
literal|0
argument|, af); 			rewrite++; 			if (nr->natpass) 				r = NULL; 			pd->nat_rule = nr; 		} 	} else { 		bport = nport = th->th_dport;
comment|/* check incoming packet for BINAT/RDR */
argument|if ((nr = pf_get_translation(pd, m, off, PF_IN, kif,&nsn, 		    saddr, th->th_sport, daddr, th->th_dport,&pd->naddr,&nport)) != NULL) { 			PF_ACPY(&pd->baddr, daddr, af); 			pf_change_ap(daddr,&th->th_dport, pd->ip_sum,&th->th_sum,&pd->naddr, nport,
literal|0
argument|, af); 			rewrite++; 			if (nr->natpass) 				r = NULL; 			pd->nat_rule = nr; 		} 	}  	while (r != NULL) { 		r->evaluations++; 		if (r->kif != NULL&& 		    (r->kif != kif&& r->kif != kif->pfik_parent) == !r->ifnot) 			r = r->skip[PF_SKIP_IFP].ptr; 		else if (r->direction&& r->direction != direction) 			r = r->skip[PF_SKIP_DIR].ptr; 		else if (r->af&& r->af != af) 			r = r->skip[PF_SKIP_AF].ptr; 		else if (r->proto&& r->proto != IPPROTO_TCP) 			r = r->skip[PF_SKIP_PROTO].ptr; 		else if (PF_MISMATCHAW(&r->src.addr, saddr, af, r->src.neg)) 			r = r->skip[PF_SKIP_SRC_ADDR].ptr; 		else if (r->src.port_op&& !pf_match_port(r->src.port_op, 		    r->src.port[
literal|0
argument|], r->src.port[
literal|1
argument|], th->th_sport)) 			r = r->skip[PF_SKIP_SRC_PORT].ptr; 		else if (PF_MISMATCHAW(&r->dst.addr, daddr, af, r->dst.neg)) 			r = r->skip[PF_SKIP_DST_ADDR].ptr; 		else if (r->dst.port_op&& !pf_match_port(r->dst.port_op, 		    r->dst.port[
literal|0
argument|], r->dst.port[
literal|1
argument|], th->th_dport)) 			r = r->skip[PF_SKIP_DST_PORT].ptr; 		else if (r->tos&& !(r->tos& pd->tos)) 			r = TAILQ_NEXT(r, entries); 		else if (r->rule_flag& PFRULE_FRAGMENT) 			r = TAILQ_NEXT(r, entries); 		else if ((r->flagset& th->th_flags) != r->flags) 			r = TAILQ_NEXT(r, entries); 		else if (r->uid.op&& (lookup != -
literal|1
argument||| (lookup =
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_socket_lookup(&uid,&gid, direction, pd, inp),
literal|1
argument|))&&
else|#
directive|else
argument|pf_socket_lookup(&uid,&gid, direction, pd),
literal|1
argument|)
argument_list|)
operator|&&
endif|#
directive|endif
operator|!
name|pf_match_uid
argument_list|(
name|r
operator|->
name|uid
operator|.
name|op
argument_list|,
name|r
operator|->
name|uid
operator|.
name|uid
index|[
literal|0
index|]
argument_list|,
name|r
operator|->
name|uid
operator|.
name|uid
index|[
literal|1
index|]
argument_list|,
name|uid
argument_list|)
block|)
function|r
init|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
function|;
end_function

begin_elseif
elseif|else
if|if
condition|(
name|r
operator|->
name|gid
operator|.
name|op
operator|&&
operator|(
name|lookup
operator|!=
operator|-
literal|1
operator|||
operator|(
name|lookup
operator|=
ifdef|#
directive|ifdef
name|__FreeBSD__
name|pf_socket_lookup
argument_list|(
operator|&
name|uid
argument_list|,
operator|&
name|gid
argument_list|,
name|direction
argument_list|,
name|pd
argument_list|,
name|inp
argument_list|)
operator|,
literal|1
operator|)
operator|)
operator|&&
else|#
directive|else
name|pf_socket_lookup
argument_list|(
operator|&
name|uid
argument_list|,
operator|&
name|gid
argument_list|,
name|direction
argument_list|,
name|pd
argument_list|)
operator|,
literal|1
condition|)
end_elseif

begin_expr_stmt
unit|)
operator|&&
endif|#
directive|endif
operator|!
name|pf_match_gid
argument_list|(
name|r
operator|->
name|gid
operator|.
name|op
argument_list|,
name|r
operator|->
name|gid
operator|.
name|gid
index|[
literal|0
index|]
argument_list|,
name|r
operator|->
name|gid
operator|.
name|gid
index|[
literal|1
index|]
argument_list|,
name|gid
argument_list|)
end_expr_stmt

begin_expr_stmt
unit|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|r
operator|->
name|prob
operator|&&
name|r
operator|->
name|prob
operator|<=
name|arc4random
argument_list|()
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
end_elseif

begin_elseif
elseif|else
if|if
condition|(
name|r
operator|->
name|match_tag
operator|&&
operator|!
name|pf_match_tag
argument_list|(
name|m
argument_list|,
name|r
argument_list|,
operator|&
name|pftag
argument_list|,
operator|&
name|tag
argument_list|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
end_elseif

begin_elseif
elseif|else
if|if
condition|(
name|r
operator|->
name|os_fingerprint
operator|!=
name|PF_OSFP_ANY
operator|&&
operator|!
name|pf_osfp_match
argument_list|(
name|pf_osfp_fingerprint
argument_list|(
name|pd
argument_list|,
name|m
argument_list|,
name|off
argument_list|,
name|th
argument_list|)
argument_list|,
name|r
operator|->
name|os_fingerprint
argument_list|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
end_elseif

begin_else
else|else
block|{
if|if
condition|(
name|r
operator|->
name|tag
condition|)
name|tag
operator|=
name|r
operator|->
name|tag
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|anchor
operator|==
name|NULL
condition|)
block|{
operator|*
name|rm
operator|=
name|r
expr_stmt|;
operator|*
name|am
operator|=
name|a
expr_stmt|;
operator|*
name|rsm
operator|=
name|ruleset
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|rm
operator|)
operator|->
name|quick
condition|)
break|break;
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
block|}
else|else
name|pf_step_into_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
end_else

begin_if
if|if
condition|(
name|r
operator|==
name|NULL
condition|)
name|pf_step_out_of_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
unit|} 	r
operator|=
operator|*
name|rm
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|a
operator|=
operator|*
name|am
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ruleset
operator|=
operator|*
name|rsm
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MATCH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|r
operator|->
name|log
condition|)
block|{
if|if
condition|(
name|rewrite
condition|)
name|m_copyback
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|th
argument_list|)
argument_list|,
operator|(
name|caddr_t
operator|)
name|th
argument_list|)
expr_stmt|;
name|PFLOG_PACKET
argument_list|(
name|kif
argument_list|,
name|h
argument_list|,
name|m
argument_list|,
name|af
argument_list|,
name|direction
argument_list|,
name|reason
argument_list|,
name|r
argument_list|,
name|a
argument_list|,
name|ruleset
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
operator|(
name|r
operator|->
name|action
operator|==
name|PF_DROP
operator|)
operator|&&
operator|(
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURNRST
operator|)
operator|||
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURNICMP
operator|)
operator|||
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURN
operator|)
operator|)
condition|)
block|{
comment|/* undo NAT changes, if they have taken place */
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|direction
operator|==
name|PF_OUT
condition|)
block|{
name|pf_change_ap
argument_list|(
name|saddr
argument_list|,
operator|&
name|th
operator|->
name|th_sport
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
operator|&
name|th
operator|->
name|th_sum
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|bport
argument_list|,
literal|0
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|rewrite
operator|++
expr_stmt|;
block|}
else|else
block|{
name|pf_change_ap
argument_list|(
name|daddr
argument_list|,
operator|&
name|th
operator|->
name|th_dport
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
operator|&
name|th
operator|->
name|th_sum
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|bport
argument_list|,
literal|0
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|rewrite
operator|++
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURNRST
operator|)
operator|||
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURN
operator|)
operator|)
operator|&&
operator|!
operator|(
name|th
operator|->
name|th_flags
operator|&
name|TH_RST
operator|)
condition|)
block|{
name|u_int32_t
name|ack
init|=
name|ntohl
argument_list|(
name|th
operator|->
name|th_seq
argument_list|)
operator|+
name|pd
operator|->
name|p_len
decl_stmt|;
if|if
condition|(
name|th
operator|->
name|th_flags
operator|&
name|TH_SYN
condition|)
name|ack
operator|++
expr_stmt|;
if|if
condition|(
name|th
operator|->
name|th_flags
operator|&
name|TH_FIN
condition|)
name|ack
operator|++
expr_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|pf_send_tcp
argument_list|(
argument|m
argument_list|,
argument|r
argument_list|,
argument|af
argument_list|,
argument|pd->dst
argument_list|,
else|#
directive|else
argument|pf_send_tcp(r, af, pd->dst,
endif|#
directive|endif
argument|pd->src, th->th_dport, th->th_sport, 			    ntohl(th->th_ack), ack, TH_RST|TH_ACK,
literal|0
argument|,
literal|0
argument|, 			    r->return_ttl,
literal|1
argument|, pd->eh, kif->pfik_ifp); 		} else if ((af == AF_INET)&& r->return_icmp) 			pf_send_icmp(m, r->return_icmp>>
literal|8
argument|, 			    r->return_icmp&
literal|255
argument|, af, r); 		else if ((af == AF_INET6)&& r->return_icmp6) 			pf_send_icmp(m, r->return_icmp6>>
literal|8
argument|, 			    r->return_icmp6&
literal|255
argument|, af, r); 	}  	if (r->action == PF_DROP) 		return (PF_DROP);  	if (pf_tag_packet(m, pftag, tag)) { 		REASON_SET(&reason, PFRES_MEMORY); 		return (PF_DROP); 	}  	if (r->keep_state || nr != NULL || 	    (pd->flags& PFDESC_TCP_NORM)) {
comment|/* create new state */
argument|u_int16_t	 len; 		struct pf_state	*s = NULL; 		struct pf_src_node *sn = NULL;  		len = pd->tot_len - off - (th->th_off<<
literal|2
argument|);
comment|/* check maximums */
argument|if (r->max_states&& (r->states>= r->max_states)) { 			pf_status.lcounters[LCNT_STATES]++; 			REASON_SET(&reason, PFRES_MAXSTATES); 			goto cleanup; 		}
comment|/* src node for flter rule */
argument|if ((r->rule_flag& PFRULE_SRCTRACK || 		    r->rpool.opts& PF_POOL_STICKYADDR)&& 		    pf_insert_src_node(&sn, r, saddr, af) !=
literal|0
argument|) { 			REASON_SET(&reason, PFRES_SRCLIMIT); 			goto cleanup; 		}
comment|/* src node for translation rule */
argument|if (nr != NULL&& (nr->rpool.opts& PF_POOL_STICKYADDR)&& 		    ((direction == PF_OUT&& 		    pf_insert_src_node(&nsn, nr,&pd->baddr, af) !=
literal|0
argument|) || 		    (pf_insert_src_node(&nsn, nr, saddr, af) !=
literal|0
argument|))) { 			REASON_SET(&reason, PFRES_SRCLIMIT); 			goto cleanup; 		} 		s = pool_get(&pf_state_pl, PR_NOWAIT); 		if (s == NULL) { 			REASON_SET(&reason, PFRES_MEMORY); cleanup: 			if (sn != NULL&& sn->states ==
literal|0
argument|&& sn->expire ==
literal|0
argument|) { 				RB_REMOVE(pf_src_tree,&tree_src_tracking, sn); 				pf_status.scounters[SCNT_SRC_NODE_REMOVALS]++; 				pf_status.src_nodes--; 				pool_put(&pf_src_tree_pl, sn); 			} 			if (nsn != sn&& nsn != NULL&& nsn->states ==
literal|0
argument|&& 			    nsn->expire ==
literal|0
argument|) { 				RB_REMOVE(pf_src_tree,&tree_src_tracking, nsn); 				pf_status.scounters[SCNT_SRC_NODE_REMOVALS]++; 				pf_status.src_nodes--; 				pool_put(&pf_src_tree_pl, nsn); 			} 			return (PF_DROP); 		} 		bzero(s, sizeof(*s)); 		s->rule.ptr = r; 		s->nat_rule.ptr = nr; 		s->anchor.ptr = a; 		STATE_INC_COUNTERS(s); 		s->allow_opts = r->allow_opts; 		s->log = r->log&
literal|2
argument|; 		s->proto = IPPROTO_TCP; 		s->direction = direction; 		s->af = af; 		if (direction == PF_OUT) { 			PF_ACPY(&s->gwy.addr, saddr, af); 			s->gwy.port = th->th_sport;
comment|/* sport */
argument|PF_ACPY(&s->ext.addr, daddr, af); 			s->ext.port = th->th_dport; 			if (nr != NULL) { 				PF_ACPY(&s->lan.addr,&pd->baddr, af); 				s->lan.port = bport; 			} else { 				PF_ACPY(&s->lan.addr,&s->gwy.addr, af); 				s->lan.port = s->gwy.port; 			} 		} else { 			PF_ACPY(&s->lan.addr, daddr, af); 			s->lan.port = th->th_dport; 			PF_ACPY(&s->ext.addr, saddr, af); 			s->ext.port = th->th_sport; 			if (nr != NULL) { 				PF_ACPY(&s->gwy.addr,&pd->baddr, af); 				s->gwy.port = bport; 			} else { 				PF_ACPY(&s->gwy.addr,&s->lan.addr, af); 				s->gwy.port = s->lan.port; 			} 		}  		s->src.seqlo = ntohl(th->th_seq); 		s->src.seqhi = s->src.seqlo + len +
literal|1
argument|; 		if ((th->th_flags& (TH_SYN|TH_ACK)) == TH_SYN&& 		    r->keep_state == PF_STATE_MODULATE) {
comment|/* Generate sequence number modulator */
argument|while ((s->src.seqdiff = htonl(arc4random())) ==
literal|0
argument|) 				; 			pf_change_a(&th->th_seq,&th->th_sum, 			    htonl(s->src.seqlo + s->src.seqdiff),
literal|0
argument|); 			rewrite =
literal|1
argument|; 		} else 			s->src.seqdiff =
literal|0
argument|; 		if (th->th_flags& TH_SYN) { 			s->src.seqhi++; 			s->src.wscale = pf_get_wscale(m, off, th->th_off, af); 		} 		s->src.max_win = MAX(ntohs(th->th_win),
literal|1
argument|); 		if (s->src.wscale& PF_WSCALE_MASK) {
comment|/* Remove scale factor from initial window */
argument|int win = s->src.max_win; 			win +=
literal|1
argument|<< (s->src.wscale& PF_WSCALE_MASK); 			s->src.max_win = (win -
literal|1
argument|)>> 			    (s->src.wscale& PF_WSCALE_MASK); 		} 		if (th->th_flags& TH_FIN) 			s->src.seqhi++; 		s->dst.seqhi =
literal|1
argument|; 		s->dst.max_win =
literal|1
argument|; 		s->src.state = TCPS_SYN_SENT; 		s->dst.state = TCPS_CLOSED; 		s->creation = time_second; 		s->expire = time_second; 		s->timeout = PFTM_TCP_FIRST_PACKET; 		pf_set_rt_ifp(s, saddr); 		if (sn != NULL) { 			s->src_node = sn; 			s->src_node->states++; 		} 		if (nsn != NULL) { 			PF_ACPY(&nsn->raddr,&pd->naddr, af); 			s->nat_src_node = nsn; 			s->nat_src_node->states++; 		} 		if ((pd->flags& PFDESC_TCP_NORM)&& pf_normalize_tcp_init(m, 		    off, pd, th,&s->src,&s->dst)) { 			REASON_SET(&reason, PFRES_MEMORY); 			pf_src_tree_remove_state(s); 			STATE_DEC_COUNTERS(s); 			pool_put(&pf_state_pl, s); 			return (PF_DROP); 		} 		if ((pd->flags& PFDESC_TCP_NORM)&& s->src.scrub&& 		    pf_normalize_tcp_stateful(m, off, pd,&reason, th, s,&s->src,&s->dst,&rewrite)) {
comment|/* This really shouldn't happen!!! */
argument|DPFPRINTF(PF_DEBUG_URGENT, 			    (
literal|"pf_normalize_tcp_stateful failed on first pkt"
argument|)); 			pf_normalize_tcp_cleanup(s); 			pf_src_tree_remove_state(s); 			STATE_DEC_COUNTERS(s); 			pool_put(&pf_state_pl, s); 			return (PF_DROP); 		} 		if (pf_insert_state(BOUND_IFACE(r, kif), s)) { 			pf_normalize_tcp_cleanup(s); 			REASON_SET(&reason, PFRES_STATEINS); 			pf_src_tree_remove_state(s); 			STATE_DEC_COUNTERS(s); 			pool_put(&pf_state_pl, s); 			return (PF_DROP); 		} else 			*sm = s; 		if (tag>
literal|0
argument|) { 			pf_tag_ref(tag); 			s->tag = tag; 		} 		if ((th->th_flags& (TH_SYN|TH_ACK)) == TH_SYN&& 		    r->keep_state == PF_STATE_SYNPROXY) { 			s->src.state = PF_TCPS_PROXY_SRC; 			if (nr != NULL) { 				if (direction == PF_OUT) { 					pf_change_ap(saddr,&th->th_sport, 					    pd->ip_sum,&th->th_sum,&pd->baddr, 					    bport,
literal|0
argument|, af); 				} else { 					pf_change_ap(daddr,&th->th_dport, 					    pd->ip_sum,&th->th_sum,&pd->baddr, 					    bport,
literal|0
argument|, af); 				} 			} 			s->src.seqhi = htonl(arc4random());
comment|/* Find mss option */
argument|mss = pf_get_mss(m, off, th->th_off, af); 			mss = pf_calc_mss(saddr, af, mss); 			mss = pf_calc_mss(daddr, af, mss); 			s->src.mss = mss;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_send_tcp(NULL, r, af, daddr, saddr, th->th_dport,
else|#
directive|else
argument|pf_send_tcp(r, af, daddr, saddr, th->th_dport,
endif|#
directive|endif
argument|th->th_sport, s->src.seqhi, ntohl(th->th_seq) +
literal|1
argument|, 			    TH_SYN|TH_ACK,
literal|0
argument|, s->src.mss,
literal|0
argument|,
literal|1
argument|, NULL, NULL); 			REASON_SET(&reason, PFRES_SYNPROXY); 			return (PF_SYNPROXY_DROP); 		} 	}
comment|/* copy back packet headers if we performed NAT operations */
argument|if (rewrite) 		m_copyback(m, off, sizeof(*th), (caddr_t)th);  	return (PF_PASS); }  int pf_test_udp(struct pf_rule **rm, struct pf_state **sm, int direction,     struct pfi_kif *kif, struct mbuf *m, int off, void *h,
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|struct pf_pdesc *pd, struct pf_rule **am, struct pf_ruleset **rsm,     struct ifqueue *ifq, struct inpcb *inp)
else|#
directive|else
argument|struct pf_pdesc *pd, struct pf_rule **am, struct pf_ruleset **rsm,     struct ifqueue *ifq)
endif|#
directive|endif
argument|{ 	struct pf_rule		*nr = NULL; 	struct pf_addr		*saddr = pd->src
argument_list|,
argument|*daddr = pd->dst; 	struct udphdr		*uh = pd->hdr.udp; 	u_int16_t		 bport
argument_list|,
argument|nport =
literal|0
argument|; 	sa_family_t		 af = pd->af; 	int			 lookup = -
literal|1
argument|; 	uid_t			 uid; 	gid_t			 gid; 	struct pf_rule		*r
argument_list|,
argument|*a = NULL; 	struct pf_ruleset	*ruleset = NULL; 	struct pf_src_node	*nsn = NULL; 	u_short			 reason; 	int			 rewrite =
literal|0
argument|; 	struct pf_tag		*pftag = NULL; 	int			 tag = -
literal|1
argument|; 	int			 asd =
literal|0
argument|;  	if (pf_check_congestion(ifq)) { 		REASON_SET(&reason, PFRES_CONGEST); 		return (PF_DROP); 	}
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|PF_MPSAFE_UGID
argument_list|)
argument|PF_UNLOCK(); 	lookup = pf_socket_lookup(&uid,&gid, direction, pd, inp); 	PF_LOCK();
endif|#
directive|endif
argument|r = TAILQ_FIRST(pf_main_ruleset.rules[PF_RULESET_FILTER].active.ptr);  	if (direction == PF_OUT) { 		bport = nport = uh->uh_sport;
comment|/* check outgoing packet for BINAT/NAT */
argument|if ((nr = pf_get_translation(pd, m, off, PF_OUT, kif,&nsn, 		    saddr, uh->uh_sport, daddr, uh->uh_dport,&pd->naddr,&nport)) != NULL) { 			PF_ACPY(&pd->baddr, saddr, af); 			pf_change_ap(saddr,&uh->uh_sport, pd->ip_sum,&uh->uh_sum,&pd->naddr, nport,
literal|1
argument|, af); 			rewrite++; 			if (nr->natpass) 				r = NULL; 			pd->nat_rule = nr; 		} 	} else { 		bport = nport = uh->uh_dport;
comment|/* check incoming packet for BINAT/RDR */
argument|if ((nr = pf_get_translation(pd, m, off, PF_IN, kif,&nsn, 		    saddr, uh->uh_sport, daddr, uh->uh_dport,&pd->naddr,&nport)) != NULL) { 			PF_ACPY(&pd->baddr, daddr, af); 			pf_change_ap(daddr,&uh->uh_dport, pd->ip_sum,&uh->uh_sum,&pd->naddr, nport,
literal|1
argument|, af); 			rewrite++; 			if (nr->natpass) 				r = NULL; 			pd->nat_rule = nr; 		} 	}  	while (r != NULL) { 		r->evaluations++; 		if (r->kif != NULL&& 		    (r->kif != kif&& r->kif != kif->pfik_parent) == !r->ifnot) 			r = r->skip[PF_SKIP_IFP].ptr; 		else if (r->direction&& r->direction != direction) 			r = r->skip[PF_SKIP_DIR].ptr; 		else if (r->af&& r->af != af) 			r = r->skip[PF_SKIP_AF].ptr; 		else if (r->proto&& r->proto != IPPROTO_UDP) 			r = r->skip[PF_SKIP_PROTO].ptr; 		else if (PF_MISMATCHAW(&r->src.addr, saddr, af, r->src.neg)) 			r = r->skip[PF_SKIP_SRC_ADDR].ptr; 		else if (r->src.port_op&& !pf_match_port(r->src.port_op, 		    r->src.port[
literal|0
argument|], r->src.port[
literal|1
argument|], uh->uh_sport)) 			r = r->skip[PF_SKIP_SRC_PORT].ptr; 		else if (PF_MISMATCHAW(&r->dst.addr, daddr, af, r->dst.neg)) 			r = r->skip[PF_SKIP_DST_ADDR].ptr; 		else if (r->dst.port_op&& !pf_match_port(r->dst.port_op, 		    r->dst.port[
literal|0
argument|], r->dst.port[
literal|1
argument|], uh->uh_dport)) 			r = r->skip[PF_SKIP_DST_PORT].ptr; 		else if (r->tos&& !(r->tos& pd->tos)) 			r = TAILQ_NEXT(r, entries); 		else if (r->rule_flag& PFRULE_FRAGMENT) 			r = TAILQ_NEXT(r, entries); 		else if (r->uid.op&& (lookup != -
literal|1
argument||| (lookup =
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_socket_lookup(&uid,&gid, direction, pd, inp),
literal|1
argument|))&&
else|#
directive|else
argument|pf_socket_lookup(&uid,&gid, direction, pd),
literal|1
argument|)
argument_list|)
operator|&&
endif|#
directive|endif
operator|!
name|pf_match_uid
argument_list|(
name|r
operator|->
name|uid
operator|.
name|op
argument_list|,
name|r
operator|->
name|uid
operator|.
name|uid
index|[
literal|0
index|]
argument_list|,
name|r
operator|->
name|uid
operator|.
name|uid
index|[
literal|1
index|]
argument_list|,
name|uid
argument_list|)
block|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|gid
operator|.
name|op
operator|&&
operator|(
name|lookup
operator|!=
operator|-
literal|1
operator|||
operator|(
name|lookup
operator|=
ifdef|#
directive|ifdef
name|__FreeBSD__
name|pf_socket_lookup
argument_list|(
operator|&
name|uid
argument_list|,
operator|&
name|gid
argument_list|,
name|direction
argument_list|,
name|pd
argument_list|,
name|inp
argument_list|)
operator|,
literal|1
operator|)
operator|)
operator|&&
else|#
directive|else
name|pf_socket_lookup
argument_list|(
operator|&
name|uid
argument_list|,
operator|&
name|gid
argument_list|,
name|direction
argument_list|,
name|pd
argument_list|)
operator|,
literal|1
condition|)
block|)
operator|&&
endif|#
directive|endif
operator|!
name|pf_match_gid
argument_list|(
name|r
operator|->
name|gid
operator|.
name|op
argument_list|,
name|r
operator|->
name|gid
operator|.
name|gid
index|[
literal|0
index|]
argument_list|,
name|r
operator|->
name|gid
operator|.
name|gid
index|[
literal|1
index|]
argument_list|,
name|gid
argument_list|)
end_if

begin_expr_stmt
unit|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|r
operator|->
name|prob
operator|&&
name|r
operator|->
name|prob
operator|<=
name|arc4random
argument_list|()
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
end_elseif

begin_elseif
elseif|else
if|if
condition|(
name|r
operator|->
name|match_tag
operator|&&
operator|!
name|pf_match_tag
argument_list|(
name|m
argument_list|,
name|r
argument_list|,
operator|&
name|pftag
argument_list|,
operator|&
name|tag
argument_list|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
end_elseif

begin_elseif
elseif|else
if|if
condition|(
name|r
operator|->
name|os_fingerprint
operator|!=
name|PF_OSFP_ANY
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
end_elseif

begin_else
else|else
block|{
if|if
condition|(
name|r
operator|->
name|tag
condition|)
name|tag
operator|=
name|r
operator|->
name|tag
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|anchor
operator|==
name|NULL
condition|)
block|{
operator|*
name|rm
operator|=
name|r
expr_stmt|;
operator|*
name|am
operator|=
name|a
expr_stmt|;
operator|*
name|rsm
operator|=
name|ruleset
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|rm
operator|)
operator|->
name|quick
condition|)
break|break;
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
block|}
else|else
name|pf_step_into_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
end_else

begin_if
if|if
condition|(
name|r
operator|==
name|NULL
condition|)
name|pf_step_out_of_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
unit|} 	r
operator|=
operator|*
name|rm
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|a
operator|=
operator|*
name|am
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ruleset
operator|=
operator|*
name|rsm
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MATCH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|r
operator|->
name|log
condition|)
block|{
if|if
condition|(
name|rewrite
condition|)
name|m_copyback
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|uh
argument_list|)
argument_list|,
operator|(
name|caddr_t
operator|)
name|uh
argument_list|)
expr_stmt|;
name|PFLOG_PACKET
argument_list|(
name|kif
argument_list|,
name|h
argument_list|,
name|m
argument_list|,
name|af
argument_list|,
name|direction
argument_list|,
name|reason
argument_list|,
name|r
argument_list|,
name|a
argument_list|,
name|ruleset
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
operator|(
name|r
operator|->
name|action
operator|==
name|PF_DROP
operator|)
operator|&&
operator|(
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURNICMP
operator|)
operator|||
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURN
operator|)
operator|)
condition|)
block|{
comment|/* undo NAT changes, if they have taken place */
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|direction
operator|==
name|PF_OUT
condition|)
block|{
name|pf_change_ap
argument_list|(
name|saddr
argument_list|,
operator|&
name|uh
operator|->
name|uh_sport
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
operator|&
name|uh
operator|->
name|uh_sum
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|bport
argument_list|,
literal|1
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|rewrite
operator|++
expr_stmt|;
block|}
else|else
block|{
name|pf_change_ap
argument_list|(
name|daddr
argument_list|,
operator|&
name|uh
operator|->
name|uh_dport
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
operator|&
name|uh
operator|->
name|uh_sum
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|bport
argument_list|,
literal|1
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|rewrite
operator|++
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|af
operator|==
name|AF_INET
operator|)
operator|&&
name|r
operator|->
name|return_icmp
condition|)
name|pf_send_icmp
argument_list|(
name|m
argument_list|,
name|r
operator|->
name|return_icmp
operator|>>
literal|8
argument_list|,
name|r
operator|->
name|return_icmp
operator|&
literal|255
argument_list|,
name|af
argument_list|,
name|r
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|af
operator|==
name|AF_INET6
operator|)
operator|&&
name|r
operator|->
name|return_icmp6
condition|)
name|pf_send_icmp
argument_list|(
name|m
argument_list|,
name|r
operator|->
name|return_icmp6
operator|>>
literal|8
argument_list|,
name|r
operator|->
name|return_icmp6
operator|&
literal|255
argument_list|,
name|af
argument_list|,
name|r
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|r
operator|->
name|action
operator|==
name|PF_DROP
condition|)
return|return
operator|(
name|PF_DROP
operator|)
return|;
end_if

begin_if
if|if
condition|(
name|pf_tag_packet
argument_list|(
name|m
argument_list|,
name|pftag
argument_list|,
name|tag
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MEMORY
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
end_if

begin_if
if|if
condition|(
name|r
operator|->
name|keep_state
operator|||
name|nr
operator|!=
name|NULL
condition|)
block|{
comment|/* create new state */
name|struct
name|pf_state
modifier|*
name|s
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_src_node
modifier|*
name|sn
init|=
name|NULL
decl_stmt|;
comment|/* check maximums */
if|if
condition|(
name|r
operator|->
name|max_states
operator|&&
operator|(
name|r
operator|->
name|states
operator|>=
name|r
operator|->
name|max_states
operator|)
condition|)
block|{
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_STATES
index|]
operator|++
expr_stmt|;
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MAXSTATES
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
comment|/* src node for flter rule */
if|if
condition|(
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_SRCTRACK
operator|||
name|r
operator|->
name|rpool
operator|.
name|opts
operator|&
name|PF_POOL_STICKYADDR
operator|)
operator|&&
name|pf_insert_src_node
argument_list|(
operator|&
name|sn
argument_list|,
name|r
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_SRCLIMIT
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
comment|/* src node for translation rule */
if|if
condition|(
name|nr
operator|!=
name|NULL
operator|&&
operator|(
name|nr
operator|->
name|rpool
operator|.
name|opts
operator|&
name|PF_POOL_STICKYADDR
operator|)
operator|&&
operator|(
operator|(
name|direction
operator|==
name|PF_OUT
operator|&&
name|pf_insert_src_node
argument_list|(
operator|&
name|nsn
argument_list|,
name|nr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
operator|)
operator|||
operator|(
name|pf_insert_src_node
argument_list|(
operator|&
name|nsn
argument_list|,
name|nr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
operator|)
operator|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_SRCLIMIT
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
name|s
operator|=
name|pool_get
argument_list|(
operator|&
name|pf_state_pl
argument_list|,
name|PR_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MEMORY
argument_list|)
expr_stmt|;
name|cleanup
label|:
if|if
condition|(
name|sn
operator|!=
name|NULL
operator|&&
name|sn
operator|->
name|states
operator|==
literal|0
operator|&&
name|sn
operator|->
name|expire
operator|==
literal|0
condition|)
block|{
name|RB_REMOVE
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
name|sn
argument_list|)
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_REMOVALS
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|src_nodes
operator|--
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
name|sn
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|nsn
operator|!=
name|sn
operator|&&
name|nsn
operator|!=
name|NULL
operator|&&
name|nsn
operator|->
name|states
operator|==
literal|0
operator|&&
name|nsn
operator|->
name|expire
operator|==
literal|0
condition|)
block|{
name|RB_REMOVE
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
name|nsn
argument_list|)
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_REMOVALS
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|src_nodes
operator|--
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
name|nsn
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
name|bzero
argument_list|(
name|s
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|s
operator|->
name|rule
operator|.
name|ptr
operator|=
name|r
expr_stmt|;
name|s
operator|->
name|nat_rule
operator|.
name|ptr
operator|=
name|nr
expr_stmt|;
name|s
operator|->
name|anchor
operator|.
name|ptr
operator|=
name|a
expr_stmt|;
name|STATE_INC_COUNTERS
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|s
operator|->
name|allow_opts
operator|=
name|r
operator|->
name|allow_opts
expr_stmt|;
name|s
operator|->
name|log
operator|=
name|r
operator|->
name|log
operator|&
literal|2
expr_stmt|;
name|s
operator|->
name|proto
operator|=
name|IPPROTO_UDP
expr_stmt|;
name|s
operator|->
name|direction
operator|=
name|direction
expr_stmt|;
name|s
operator|->
name|af
operator|=
name|af
expr_stmt|;
if|if
condition|(
name|direction
operator|==
name|PF_OUT
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|gwy
operator|.
name|port
operator|=
name|uh
operator|->
name|uh_sport
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|ext
operator|.
name|port
operator|=
name|uh
operator|->
name|uh_dport
expr_stmt|;
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|lan
operator|.
name|port
operator|=
name|bport
expr_stmt|;
block|}
else|else
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|lan
operator|.
name|port
operator|=
name|s
operator|->
name|gwy
operator|.
name|port
expr_stmt|;
block|}
block|}
else|else
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|lan
operator|.
name|port
operator|=
name|uh
operator|->
name|uh_dport
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|ext
operator|.
name|port
operator|=
name|uh
operator|->
name|uh_sport
expr_stmt|;
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|gwy
operator|.
name|port
operator|=
name|bport
expr_stmt|;
block|}
else|else
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|gwy
operator|.
name|port
operator|=
name|s
operator|->
name|lan
operator|.
name|port
expr_stmt|;
block|}
block|}
name|s
operator|->
name|src
operator|.
name|state
operator|=
name|PFUDPS_SINGLE
expr_stmt|;
name|s
operator|->
name|dst
operator|.
name|state
operator|=
name|PFUDPS_NO_TRAFFIC
expr_stmt|;
name|s
operator|->
name|creation
operator|=
name|time_second
expr_stmt|;
name|s
operator|->
name|expire
operator|=
name|time_second
expr_stmt|;
name|s
operator|->
name|timeout
operator|=
name|PFTM_UDP_FIRST_PACKET
expr_stmt|;
name|pf_set_rt_ifp
argument_list|(
name|s
argument_list|,
name|saddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|sn
operator|!=
name|NULL
condition|)
block|{
name|s
operator|->
name|src_node
operator|=
name|sn
expr_stmt|;
name|s
operator|->
name|src_node
operator|->
name|states
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|nsn
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|nsn
operator|->
name|raddr
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|nat_src_node
operator|=
name|nsn
expr_stmt|;
name|s
operator|->
name|nat_src_node
operator|->
name|states
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|pf_insert_state
argument_list|(
name|BOUND_IFACE
argument_list|(
name|r
argument_list|,
name|kif
argument_list|)
argument_list|,
name|s
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_STATEINS
argument_list|)
expr_stmt|;
name|pf_src_tree_remove_state
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|STATE_DEC_COUNTERS
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_state_pl
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
else|else
operator|*
name|sm
operator|=
name|s
expr_stmt|;
if|if
condition|(
name|tag
operator|>
literal|0
condition|)
block|{
name|pf_tag_ref
argument_list|(
name|tag
argument_list|)
expr_stmt|;
name|s
operator|->
name|tag
operator|=
name|tag
expr_stmt|;
block|}
block|}
end_if

begin_comment
comment|/* copy back packet headers if we performed NAT operations */
end_comment

begin_if
if|if
condition|(
name|rewrite
condition|)
name|m_copyback
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|uh
argument_list|)
argument_list|,
operator|(
name|caddr_t
operator|)
name|uh
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
operator|(
name|PF_PASS
operator|)
return|;
end_return

begin_macro
unit|}  int
name|pf_test_icmp
argument_list|(
argument|struct pf_rule **rm
argument_list|,
argument|struct pf_state **sm
argument_list|,
argument|int direction
argument_list|,
argument|struct pfi_kif *kif
argument_list|,
argument|struct mbuf *m
argument_list|,
argument|int off
argument_list|,
argument|void *h
argument_list|,
argument|struct pf_pdesc *pd
argument_list|,
argument|struct pf_rule **am
argument_list|,
argument|struct pf_ruleset **rsm
argument_list|,
argument|struct ifqueue *ifq
argument_list|)
end_macro

begin_block
block|{
name|struct
name|pf_rule
modifier|*
name|nr
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_addr
modifier|*
name|saddr
init|=
name|pd
operator|->
name|src
decl_stmt|,
modifier|*
name|daddr
init|=
name|pd
operator|->
name|dst
decl_stmt|;
name|struct
name|pf_rule
modifier|*
name|r
decl_stmt|,
modifier|*
name|a
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_ruleset
modifier|*
name|ruleset
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_src_node
modifier|*
name|nsn
init|=
name|NULL
decl_stmt|;
name|u_short
name|reason
decl_stmt|;
name|u_int16_t
name|icmpid
init|=
literal|0
decl_stmt|,
name|bport
decl_stmt|,
name|nport
init|=
literal|0
decl_stmt|;
name|sa_family_t
name|af
init|=
name|pd
operator|->
name|af
decl_stmt|;
name|u_int8_t
name|icmptype
init|=
literal|0
decl_stmt|;
comment|/* make the compiler happy */
name|u_int8_t
name|icmpcode
init|=
literal|0
decl_stmt|;
comment|/* make the compiler happy */
name|int
name|state_icmp
init|=
literal|0
decl_stmt|;
name|struct
name|pf_tag
modifier|*
name|pftag
init|=
name|NULL
decl_stmt|;
name|int
name|tag
init|=
operator|-
literal|1
decl_stmt|;
ifdef|#
directive|ifdef
name|INET6
name|int
name|rewrite
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
comment|/* INET6 */
name|int
name|asd
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|pf_check_congestion
argument_list|(
name|ifq
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_CONGEST
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
switch|switch
condition|(
name|pd
operator|->
name|proto
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|IPPROTO_ICMP
case|:
name|icmptype
operator|=
name|pd
operator|->
name|hdr
operator|.
name|icmp
operator|->
name|icmp_type
expr_stmt|;
name|icmpcode
operator|=
name|pd
operator|->
name|hdr
operator|.
name|icmp
operator|->
name|icmp_code
expr_stmt|;
name|icmpid
operator|=
name|pd
operator|->
name|hdr
operator|.
name|icmp
operator|->
name|icmp_id
expr_stmt|;
if|if
condition|(
name|icmptype
operator|==
name|ICMP_UNREACH
operator|||
name|icmptype
operator|==
name|ICMP_SOURCEQUENCH
operator|||
name|icmptype
operator|==
name|ICMP_REDIRECT
operator|||
name|icmptype
operator|==
name|ICMP_TIMXCEED
operator|||
name|icmptype
operator|==
name|ICMP_PARAMPROB
condition|)
name|state_icmp
operator|++
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|IPPROTO_ICMPV6
case|:
name|icmptype
operator|=
name|pd
operator|->
name|hdr
operator|.
name|icmp6
operator|->
name|icmp6_type
expr_stmt|;
name|icmpcode
operator|=
name|pd
operator|->
name|hdr
operator|.
name|icmp6
operator|->
name|icmp6_code
expr_stmt|;
name|icmpid
operator|=
name|pd
operator|->
name|hdr
operator|.
name|icmp6
operator|->
name|icmp6_id
expr_stmt|;
if|if
condition|(
name|icmptype
operator|==
name|ICMP6_DST_UNREACH
operator|||
name|icmptype
operator|==
name|ICMP6_PACKET_TOO_BIG
operator|||
name|icmptype
operator|==
name|ICMP6_TIME_EXCEEDED
operator|||
name|icmptype
operator|==
name|ICMP6_PARAM_PROB
condition|)
name|state_icmp
operator|++
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
name|r
operator|=
name|TAILQ_FIRST
argument_list|(
name|pf_main_ruleset
operator|.
name|rules
index|[
name|PF_RULESET_FILTER
index|]
operator|.
name|active
operator|.
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|direction
operator|==
name|PF_OUT
condition|)
block|{
name|bport
operator|=
name|nport
operator|=
name|icmpid
expr_stmt|;
comment|/* check outgoing packet for BINAT/NAT */
if|if
condition|(
operator|(
name|nr
operator|=
name|pf_get_translation
argument_list|(
name|pd
argument_list|,
name|m
argument_list|,
name|off
argument_list|,
name|PF_OUT
argument_list|,
name|kif
argument_list|,
operator|&
name|nsn
argument_list|,
name|saddr
argument_list|,
name|icmpid
argument_list|,
name|daddr
argument_list|,
name|icmpid
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
operator|&
name|nport
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
name|pf_change_a
argument_list|(
operator|&
name|saddr
operator|->
name|v4
operator|.
name|s_addr
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
name|pd
operator|->
name|naddr
operator|.
name|v4
operator|.
name|s_addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pd
operator|->
name|hdr
operator|.
name|icmp
operator|->
name|icmp_cksum
operator|=
name|pf_cksum_fixup
argument_list|(
name|pd
operator|->
name|hdr
operator|.
name|icmp
operator|->
name|icmp_cksum
argument_list|,
name|icmpid
argument_list|,
name|nport
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pd
operator|->
name|hdr
operator|.
name|icmp
operator|->
name|icmp_id
operator|=
name|nport
expr_stmt|;
name|m_copyback
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
name|ICMP_MINLEN
argument_list|,
operator|(
name|caddr_t
operator|)
name|pd
operator|->
name|hdr
operator|.
name|icmp
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
name|pf_change_a6
argument_list|(
name|saddr
argument_list|,
operator|&
name|pd
operator|->
name|hdr
operator|.
name|icmp6
operator|->
name|icmp6_cksum
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|rewrite
operator|++
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
if|if
condition|(
name|nr
operator|->
name|natpass
condition|)
name|r
operator|=
name|NULL
expr_stmt|;
name|pd
operator|->
name|nat_rule
operator|=
name|nr
expr_stmt|;
block|}
block|}
else|else
block|{
name|bport
operator|=
name|nport
operator|=
name|icmpid
expr_stmt|;
comment|/* check incoming packet for BINAT/RDR */
if|if
condition|(
operator|(
name|nr
operator|=
name|pf_get_translation
argument_list|(
name|pd
argument_list|,
name|m
argument_list|,
name|off
argument_list|,
name|PF_IN
argument_list|,
name|kif
argument_list|,
operator|&
name|nsn
argument_list|,
name|saddr
argument_list|,
name|icmpid
argument_list|,
name|daddr
argument_list|,
name|icmpid
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
operator|&
name|nport
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
name|pf_change_a
argument_list|(
operator|&
name|daddr
operator|->
name|v4
operator|.
name|s_addr
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
name|pd
operator|->
name|naddr
operator|.
name|v4
operator|.
name|s_addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
name|pf_change_a6
argument_list|(
name|daddr
argument_list|,
operator|&
name|pd
operator|->
name|hdr
operator|.
name|icmp6
operator|->
name|icmp6_cksum
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|rewrite
operator|++
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
if|if
condition|(
name|nr
operator|->
name|natpass
condition|)
name|r
operator|=
name|NULL
expr_stmt|;
name|pd
operator|->
name|nat_rule
operator|=
name|nr
expr_stmt|;
block|}
block|}
while|while
condition|(
name|r
operator|!=
name|NULL
condition|)
block|{
name|r
operator|->
name|evaluations
operator|++
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|kif
operator|!=
name|NULL
operator|&&
operator|(
name|r
operator|->
name|kif
operator|!=
name|kif
operator|&&
name|r
operator|->
name|kif
operator|!=
name|kif
operator|->
name|pfik_parent
operator|)
operator|==
operator|!
name|r
operator|->
name|ifnot
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_IFP
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|direction
operator|&&
name|r
operator|->
name|direction
operator|!=
name|direction
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_DIR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|af
operator|&&
name|r
operator|->
name|af
operator|!=
name|af
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_AF
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|proto
operator|&&
name|r
operator|->
name|proto
operator|!=
name|pd
operator|->
name|proto
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_PROTO
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|PF_MISMATCHAW
argument_list|(
operator|&
name|r
operator|->
name|src
operator|.
name|addr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|,
name|r
operator|->
name|src
operator|.
name|neg
argument_list|)
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_SRC_ADDR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|PF_MISMATCHAW
argument_list|(
operator|&
name|r
operator|->
name|dst
operator|.
name|addr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|,
name|r
operator|->
name|dst
operator|.
name|neg
argument_list|)
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_DST_ADDR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|type
operator|&&
name|r
operator|->
name|type
operator|!=
name|icmptype
operator|+
literal|1
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|code
operator|&&
name|r
operator|->
name|code
operator|!=
name|icmpcode
operator|+
literal|1
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|tos
operator|&&
operator|!
operator|(
name|r
operator|->
name|tos
operator|&
name|pd
operator|->
name|tos
operator|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_FRAGMENT
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|prob
operator|&&
name|r
operator|->
name|prob
operator|<=
name|arc4random
argument_list|()
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|match_tag
operator|&&
operator|!
name|pf_match_tag
argument_list|(
name|m
argument_list|,
name|r
argument_list|,
operator|&
name|pftag
argument_list|,
operator|&
name|tag
argument_list|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|os_fingerprint
operator|!=
name|PF_OSFP_ANY
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|r
operator|->
name|tag
condition|)
name|tag
operator|=
name|r
operator|->
name|tag
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|anchor
operator|==
name|NULL
condition|)
block|{
operator|*
name|rm
operator|=
name|r
expr_stmt|;
operator|*
name|am
operator|=
name|a
expr_stmt|;
operator|*
name|rsm
operator|=
name|ruleset
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|rm
operator|)
operator|->
name|quick
condition|)
break|break;
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
block|}
else|else
name|pf_step_into_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|r
operator|==
name|NULL
condition|)
name|pf_step_out_of_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
name|r
operator|=
operator|*
name|rm
expr_stmt|;
name|a
operator|=
operator|*
name|am
expr_stmt|;
name|ruleset
operator|=
operator|*
name|rsm
expr_stmt|;
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MATCH
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|log
condition|)
block|{
ifdef|#
directive|ifdef
name|INET6
if|if
condition|(
name|rewrite
condition|)
name|m_copyback
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|icmp6_hdr
argument_list|)
argument_list|,
operator|(
name|caddr_t
operator|)
name|pd
operator|->
name|hdr
operator|.
name|icmp6
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* INET6 */
name|PFLOG_PACKET
argument_list|(
name|kif
argument_list|,
name|h
argument_list|,
name|m
argument_list|,
name|af
argument_list|,
name|direction
argument_list|,
name|reason
argument_list|,
name|r
argument_list|,
name|a
argument_list|,
name|ruleset
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|r
operator|->
name|action
operator|!=
name|PF_PASS
condition|)
return|return
operator|(
name|PF_DROP
operator|)
return|;
if|if
condition|(
name|pf_tag_packet
argument_list|(
name|m
argument_list|,
name|pftag
argument_list|,
name|tag
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MEMORY
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
if|if
condition|(
operator|!
name|state_icmp
operator|&&
operator|(
name|r
operator|->
name|keep_state
operator|||
name|nr
operator|!=
name|NULL
operator|)
condition|)
block|{
comment|/* create new state */
name|struct
name|pf_state
modifier|*
name|s
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_src_node
modifier|*
name|sn
init|=
name|NULL
decl_stmt|;
comment|/* check maximums */
if|if
condition|(
name|r
operator|->
name|max_states
operator|&&
operator|(
name|r
operator|->
name|states
operator|>=
name|r
operator|->
name|max_states
operator|)
condition|)
block|{
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_STATES
index|]
operator|++
expr_stmt|;
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MAXSTATES
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
comment|/* src node for flter rule */
if|if
condition|(
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_SRCTRACK
operator|||
name|r
operator|->
name|rpool
operator|.
name|opts
operator|&
name|PF_POOL_STICKYADDR
operator|)
operator|&&
name|pf_insert_src_node
argument_list|(
operator|&
name|sn
argument_list|,
name|r
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_SRCLIMIT
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
comment|/* src node for translation rule */
if|if
condition|(
name|nr
operator|!=
name|NULL
operator|&&
operator|(
name|nr
operator|->
name|rpool
operator|.
name|opts
operator|&
name|PF_POOL_STICKYADDR
operator|)
operator|&&
operator|(
operator|(
name|direction
operator|==
name|PF_OUT
operator|&&
name|pf_insert_src_node
argument_list|(
operator|&
name|nsn
argument_list|,
name|nr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
operator|)
operator|||
operator|(
name|pf_insert_src_node
argument_list|(
operator|&
name|nsn
argument_list|,
name|nr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
operator|)
operator|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_SRCLIMIT
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
name|s
operator|=
name|pool_get
argument_list|(
operator|&
name|pf_state_pl
argument_list|,
name|PR_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MEMORY
argument_list|)
expr_stmt|;
name|cleanup
label|:
if|if
condition|(
name|sn
operator|!=
name|NULL
operator|&&
name|sn
operator|->
name|states
operator|==
literal|0
operator|&&
name|sn
operator|->
name|expire
operator|==
literal|0
condition|)
block|{
name|RB_REMOVE
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
name|sn
argument_list|)
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_REMOVALS
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|src_nodes
operator|--
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
name|sn
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|nsn
operator|!=
name|sn
operator|&&
name|nsn
operator|!=
name|NULL
operator|&&
name|nsn
operator|->
name|states
operator|==
literal|0
operator|&&
name|nsn
operator|->
name|expire
operator|==
literal|0
condition|)
block|{
name|RB_REMOVE
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
name|nsn
argument_list|)
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_REMOVALS
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|src_nodes
operator|--
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
name|nsn
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
name|bzero
argument_list|(
name|s
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|s
operator|->
name|rule
operator|.
name|ptr
operator|=
name|r
expr_stmt|;
name|s
operator|->
name|nat_rule
operator|.
name|ptr
operator|=
name|nr
expr_stmt|;
name|s
operator|->
name|anchor
operator|.
name|ptr
operator|=
name|a
expr_stmt|;
name|STATE_INC_COUNTERS
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|s
operator|->
name|allow_opts
operator|=
name|r
operator|->
name|allow_opts
expr_stmt|;
name|s
operator|->
name|log
operator|=
name|r
operator|->
name|log
operator|&
literal|2
expr_stmt|;
name|s
operator|->
name|proto
operator|=
name|pd
operator|->
name|proto
expr_stmt|;
name|s
operator|->
name|direction
operator|=
name|direction
expr_stmt|;
name|s
operator|->
name|af
operator|=
name|af
expr_stmt|;
if|if
condition|(
name|direction
operator|==
name|PF_OUT
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|gwy
operator|.
name|port
operator|=
name|nport
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|ext
operator|.
name|port
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|lan
operator|.
name|port
operator|=
name|bport
expr_stmt|;
block|}
else|else
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|lan
operator|.
name|port
operator|=
name|s
operator|->
name|gwy
operator|.
name|port
expr_stmt|;
block|}
block|}
else|else
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|lan
operator|.
name|port
operator|=
name|nport
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|ext
operator|.
name|port
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|gwy
operator|.
name|port
operator|=
name|bport
expr_stmt|;
block|}
else|else
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|gwy
operator|.
name|port
operator|=
name|s
operator|->
name|lan
operator|.
name|port
expr_stmt|;
block|}
block|}
name|s
operator|->
name|creation
operator|=
name|time_second
expr_stmt|;
name|s
operator|->
name|expire
operator|=
name|time_second
expr_stmt|;
name|s
operator|->
name|timeout
operator|=
name|PFTM_ICMP_FIRST_PACKET
expr_stmt|;
name|pf_set_rt_ifp
argument_list|(
name|s
argument_list|,
name|saddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|sn
operator|!=
name|NULL
condition|)
block|{
name|s
operator|->
name|src_node
operator|=
name|sn
expr_stmt|;
name|s
operator|->
name|src_node
operator|->
name|states
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|nsn
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|nsn
operator|->
name|raddr
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|nat_src_node
operator|=
name|nsn
expr_stmt|;
name|s
operator|->
name|nat_src_node
operator|->
name|states
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|pf_insert_state
argument_list|(
name|BOUND_IFACE
argument_list|(
name|r
argument_list|,
name|kif
argument_list|)
argument_list|,
name|s
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_STATEINS
argument_list|)
expr_stmt|;
name|pf_src_tree_remove_state
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|STATE_DEC_COUNTERS
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_state_pl
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
else|else
operator|*
name|sm
operator|=
name|s
expr_stmt|;
if|if
condition|(
name|tag
operator|>
literal|0
condition|)
block|{
name|pf_tag_ref
argument_list|(
name|tag
argument_list|)
expr_stmt|;
name|s
operator|->
name|tag
operator|=
name|tag
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|INET6
comment|/* copy back packet headers if we performed IPv6 NAT operations */
if|if
condition|(
name|rewrite
condition|)
name|m_copyback
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|icmp6_hdr
argument_list|)
argument_list|,
operator|(
name|caddr_t
operator|)
name|pd
operator|->
name|hdr
operator|.
name|icmp6
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* INET6 */
return|return
operator|(
name|PF_PASS
operator|)
return|;
block|}
end_block

begin_function
name|int
name|pf_test_other
parameter_list|(
name|struct
name|pf_rule
modifier|*
modifier|*
name|rm
parameter_list|,
name|struct
name|pf_state
modifier|*
modifier|*
name|sm
parameter_list|,
name|int
name|direction
parameter_list|,
name|struct
name|pfi_kif
modifier|*
name|kif
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|off
parameter_list|,
name|void
modifier|*
name|h
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
name|pd
parameter_list|,
name|struct
name|pf_rule
modifier|*
modifier|*
name|am
parameter_list|,
name|struct
name|pf_ruleset
modifier|*
modifier|*
name|rsm
parameter_list|,
name|struct
name|ifqueue
modifier|*
name|ifq
parameter_list|)
block|{
name|struct
name|pf_rule
modifier|*
name|nr
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_rule
modifier|*
name|r
decl_stmt|,
modifier|*
name|a
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_ruleset
modifier|*
name|ruleset
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_src_node
modifier|*
name|nsn
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_addr
modifier|*
name|saddr
init|=
name|pd
operator|->
name|src
decl_stmt|,
modifier|*
name|daddr
init|=
name|pd
operator|->
name|dst
decl_stmt|;
name|sa_family_t
name|af
init|=
name|pd
operator|->
name|af
decl_stmt|;
name|u_short
name|reason
decl_stmt|;
name|struct
name|pf_tag
modifier|*
name|pftag
init|=
name|NULL
decl_stmt|;
name|int
name|tag
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|asd
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|pf_check_congestion
argument_list|(
name|ifq
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_CONGEST
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
name|r
operator|=
name|TAILQ_FIRST
argument_list|(
name|pf_main_ruleset
operator|.
name|rules
index|[
name|PF_RULESET_FILTER
index|]
operator|.
name|active
operator|.
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|direction
operator|==
name|PF_OUT
condition|)
block|{
comment|/* check outgoing packet for BINAT/NAT */
if|if
condition|(
operator|(
name|nr
operator|=
name|pf_get_translation
argument_list|(
name|pd
argument_list|,
name|m
argument_list|,
name|off
argument_list|,
name|PF_OUT
argument_list|,
name|kif
argument_list|,
operator|&
name|nsn
argument_list|,
name|saddr
argument_list|,
literal|0
argument_list|,
name|daddr
argument_list|,
literal|0
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
name|NULL
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
name|pf_change_a
argument_list|(
operator|&
name|saddr
operator|->
name|v4
operator|.
name|s_addr
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
name|pd
operator|->
name|naddr
operator|.
name|v4
operator|.
name|s_addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
name|PF_ACPY
argument_list|(
name|saddr
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
if|if
condition|(
name|nr
operator|->
name|natpass
condition|)
name|r
operator|=
name|NULL
expr_stmt|;
name|pd
operator|->
name|nat_rule
operator|=
name|nr
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* check incoming packet for BINAT/RDR */
if|if
condition|(
operator|(
name|nr
operator|=
name|pf_get_translation
argument_list|(
name|pd
argument_list|,
name|m
argument_list|,
name|off
argument_list|,
name|PF_IN
argument_list|,
name|kif
argument_list|,
operator|&
name|nsn
argument_list|,
name|saddr
argument_list|,
literal|0
argument_list|,
name|daddr
argument_list|,
literal|0
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
name|NULL
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
name|pf_change_a
argument_list|(
operator|&
name|daddr
operator|->
name|v4
operator|.
name|s_addr
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
name|pd
operator|->
name|naddr
operator|.
name|v4
operator|.
name|s_addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
name|PF_ACPY
argument_list|(
name|daddr
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
if|if
condition|(
name|nr
operator|->
name|natpass
condition|)
name|r
operator|=
name|NULL
expr_stmt|;
name|pd
operator|->
name|nat_rule
operator|=
name|nr
expr_stmt|;
block|}
block|}
while|while
condition|(
name|r
operator|!=
name|NULL
condition|)
block|{
name|r
operator|->
name|evaluations
operator|++
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|kif
operator|!=
name|NULL
operator|&&
operator|(
name|r
operator|->
name|kif
operator|!=
name|kif
operator|&&
name|r
operator|->
name|kif
operator|!=
name|kif
operator|->
name|pfik_parent
operator|)
operator|==
operator|!
name|r
operator|->
name|ifnot
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_IFP
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|direction
operator|&&
name|r
operator|->
name|direction
operator|!=
name|direction
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_DIR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|af
operator|&&
name|r
operator|->
name|af
operator|!=
name|af
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_AF
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|proto
operator|&&
name|r
operator|->
name|proto
operator|!=
name|pd
operator|->
name|proto
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_PROTO
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|PF_MISMATCHAW
argument_list|(
operator|&
name|r
operator|->
name|src
operator|.
name|addr
argument_list|,
name|pd
operator|->
name|src
argument_list|,
name|af
argument_list|,
name|r
operator|->
name|src
operator|.
name|neg
argument_list|)
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_SRC_ADDR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|PF_MISMATCHAW
argument_list|(
operator|&
name|r
operator|->
name|dst
operator|.
name|addr
argument_list|,
name|pd
operator|->
name|dst
argument_list|,
name|af
argument_list|,
name|r
operator|->
name|dst
operator|.
name|neg
argument_list|)
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_DST_ADDR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|tos
operator|&&
operator|!
operator|(
name|r
operator|->
name|tos
operator|&
name|pd
operator|->
name|tos
operator|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_FRAGMENT
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|prob
operator|&&
name|r
operator|->
name|prob
operator|<=
name|arc4random
argument_list|()
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|match_tag
operator|&&
operator|!
name|pf_match_tag
argument_list|(
name|m
argument_list|,
name|r
argument_list|,
operator|&
name|pftag
argument_list|,
operator|&
name|tag
argument_list|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|os_fingerprint
operator|!=
name|PF_OSFP_ANY
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|r
operator|->
name|tag
condition|)
name|tag
operator|=
name|r
operator|->
name|tag
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|anchor
operator|==
name|NULL
condition|)
block|{
operator|*
name|rm
operator|=
name|r
expr_stmt|;
operator|*
name|am
operator|=
name|a
expr_stmt|;
operator|*
name|rsm
operator|=
name|ruleset
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|rm
operator|)
operator|->
name|quick
condition|)
break|break;
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
block|}
else|else
name|pf_step_into_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|r
operator|==
name|NULL
condition|)
name|pf_step_out_of_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
name|r
operator|=
operator|*
name|rm
expr_stmt|;
name|a
operator|=
operator|*
name|am
expr_stmt|;
name|ruleset
operator|=
operator|*
name|rsm
expr_stmt|;
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MATCH
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|log
condition|)
name|PFLOG_PACKET
argument_list|(
name|kif
argument_list|,
name|h
argument_list|,
name|m
argument_list|,
name|af
argument_list|,
name|direction
argument_list|,
name|reason
argument_list|,
name|r
argument_list|,
name|a
argument_list|,
name|ruleset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|r
operator|->
name|action
operator|==
name|PF_DROP
operator|)
operator|&&
operator|(
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURNICMP
operator|)
operator|||
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_RETURN
operator|)
operator|)
condition|)
block|{
name|struct
name|pf_addr
modifier|*
name|a
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|direction
operator|==
name|PF_OUT
condition|)
name|a
operator|=
name|saddr
expr_stmt|;
else|else
name|a
operator|=
name|daddr
expr_stmt|;
block|}
if|if
condition|(
name|a
operator|!=
name|NULL
condition|)
block|{
switch|switch
condition|(
name|af
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
name|pf_change_a
argument_list|(
operator|&
name|a
operator|->
name|v4
operator|.
name|s_addr
argument_list|,
name|pd
operator|->
name|ip_sum
argument_list|,
name|pd
operator|->
name|baddr
operator|.
name|v4
operator|.
name|s_addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
case|case
name|AF_INET6
case|:
name|PF_ACPY
argument_list|(
name|a
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* INET6 */
block|}
block|}
if|if
condition|(
operator|(
name|af
operator|==
name|AF_INET
operator|)
operator|&&
name|r
operator|->
name|return_icmp
condition|)
name|pf_send_icmp
argument_list|(
name|m
argument_list|,
name|r
operator|->
name|return_icmp
operator|>>
literal|8
argument_list|,
name|r
operator|->
name|return_icmp
operator|&
literal|255
argument_list|,
name|af
argument_list|,
name|r
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|af
operator|==
name|AF_INET6
operator|)
operator|&&
name|r
operator|->
name|return_icmp6
condition|)
name|pf_send_icmp
argument_list|(
name|m
argument_list|,
name|r
operator|->
name|return_icmp6
operator|>>
literal|8
argument_list|,
name|r
operator|->
name|return_icmp6
operator|&
literal|255
argument_list|,
name|af
argument_list|,
name|r
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|r
operator|->
name|action
operator|!=
name|PF_PASS
condition|)
return|return
operator|(
name|PF_DROP
operator|)
return|;
if|if
condition|(
name|pf_tag_packet
argument_list|(
name|m
argument_list|,
name|pftag
argument_list|,
name|tag
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MEMORY
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
if|if
condition|(
name|r
operator|->
name|keep_state
operator|||
name|nr
operator|!=
name|NULL
condition|)
block|{
comment|/* create new state */
name|struct
name|pf_state
modifier|*
name|s
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_src_node
modifier|*
name|sn
init|=
name|NULL
decl_stmt|;
comment|/* check maximums */
if|if
condition|(
name|r
operator|->
name|max_states
operator|&&
operator|(
name|r
operator|->
name|states
operator|>=
name|r
operator|->
name|max_states
operator|)
condition|)
block|{
name|pf_status
operator|.
name|lcounters
index|[
name|LCNT_STATES
index|]
operator|++
expr_stmt|;
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MAXSTATES
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
comment|/* src node for flter rule */
if|if
condition|(
operator|(
name|r
operator|->
name|rule_flag
operator|&
name|PFRULE_SRCTRACK
operator|||
name|r
operator|->
name|rpool
operator|.
name|opts
operator|&
name|PF_POOL_STICKYADDR
operator|)
operator|&&
name|pf_insert_src_node
argument_list|(
operator|&
name|sn
argument_list|,
name|r
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_SRCLIMIT
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
comment|/* src node for translation rule */
if|if
condition|(
name|nr
operator|!=
name|NULL
operator|&&
operator|(
name|nr
operator|->
name|rpool
operator|.
name|opts
operator|&
name|PF_POOL_STICKYADDR
operator|)
operator|&&
operator|(
operator|(
name|direction
operator|==
name|PF_OUT
operator|&&
name|pf_insert_src_node
argument_list|(
operator|&
name|nsn
argument_list|,
name|nr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
operator|)
operator|||
operator|(
name|pf_insert_src_node
argument_list|(
operator|&
name|nsn
argument_list|,
name|nr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
operator|!=
literal|0
operator|)
operator|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_SRCLIMIT
argument_list|)
expr_stmt|;
goto|goto
name|cleanup
goto|;
block|}
name|s
operator|=
name|pool_get
argument_list|(
operator|&
name|pf_state_pl
argument_list|,
name|PR_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MEMORY
argument_list|)
expr_stmt|;
name|cleanup
label|:
if|if
condition|(
name|sn
operator|!=
name|NULL
operator|&&
name|sn
operator|->
name|states
operator|==
literal|0
operator|&&
name|sn
operator|->
name|expire
operator|==
literal|0
condition|)
block|{
name|RB_REMOVE
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
name|sn
argument_list|)
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_REMOVALS
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|src_nodes
operator|--
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
name|sn
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|nsn
operator|!=
name|sn
operator|&&
name|nsn
operator|!=
name|NULL
operator|&&
name|nsn
operator|->
name|states
operator|==
literal|0
operator|&&
name|nsn
operator|->
name|expire
operator|==
literal|0
condition|)
block|{
name|RB_REMOVE
argument_list|(
name|pf_src_tree
argument_list|,
operator|&
name|tree_src_tracking
argument_list|,
name|nsn
argument_list|)
expr_stmt|;
name|pf_status
operator|.
name|scounters
index|[
name|SCNT_SRC_NODE_REMOVALS
index|]
operator|++
expr_stmt|;
name|pf_status
operator|.
name|src_nodes
operator|--
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_src_tree_pl
argument_list|,
name|nsn
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
name|bzero
argument_list|(
name|s
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|s
operator|->
name|rule
operator|.
name|ptr
operator|=
name|r
expr_stmt|;
name|s
operator|->
name|nat_rule
operator|.
name|ptr
operator|=
name|nr
expr_stmt|;
name|s
operator|->
name|anchor
operator|.
name|ptr
operator|=
name|a
expr_stmt|;
name|STATE_INC_COUNTERS
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|s
operator|->
name|allow_opts
operator|=
name|r
operator|->
name|allow_opts
expr_stmt|;
name|s
operator|->
name|log
operator|=
name|r
operator|->
name|log
operator|&
literal|2
expr_stmt|;
name|s
operator|->
name|proto
operator|=
name|pd
operator|->
name|proto
expr_stmt|;
name|s
operator|->
name|direction
operator|=
name|direction
expr_stmt|;
name|s
operator|->
name|af
operator|=
name|af
expr_stmt|;
if|if
condition|(
name|direction
operator|==
name|PF_OUT
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
else|else
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
name|af
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|daddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|ext
operator|.
name|addr
argument_list|,
name|saddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
if|if
condition|(
name|nr
operator|!=
name|NULL
condition|)
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
operator|&
name|pd
operator|->
name|baddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
else|else
name|PF_ACPY
argument_list|(
operator|&
name|s
operator|->
name|gwy
operator|.
name|addr
argument_list|,
operator|&
name|s
operator|->
name|lan
operator|.
name|addr
argument_list|,
name|af
argument_list|)
expr_stmt|;
block|}
name|s
operator|->
name|src
operator|.
name|state
operator|=
name|PFOTHERS_SINGLE
expr_stmt|;
name|s
operator|->
name|dst
operator|.
name|state
operator|=
name|PFOTHERS_NO_TRAFFIC
expr_stmt|;
name|s
operator|->
name|creation
operator|=
name|time_second
expr_stmt|;
name|s
operator|->
name|expire
operator|=
name|time_second
expr_stmt|;
name|s
operator|->
name|timeout
operator|=
name|PFTM_OTHER_FIRST_PACKET
expr_stmt|;
name|pf_set_rt_ifp
argument_list|(
name|s
argument_list|,
name|saddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|sn
operator|!=
name|NULL
condition|)
block|{
name|s
operator|->
name|src_node
operator|=
name|sn
expr_stmt|;
name|s
operator|->
name|src_node
operator|->
name|states
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|nsn
operator|!=
name|NULL
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|nsn
operator|->
name|raddr
argument_list|,
operator|&
name|pd
operator|->
name|naddr
argument_list|,
name|af
argument_list|)
expr_stmt|;
name|s
operator|->
name|nat_src_node
operator|=
name|nsn
expr_stmt|;
name|s
operator|->
name|nat_src_node
operator|->
name|states
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|pf_insert_state
argument_list|(
name|BOUND_IFACE
argument_list|(
name|r
argument_list|,
name|kif
argument_list|)
argument_list|,
name|s
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_STATEINS
argument_list|)
expr_stmt|;
name|pf_src_tree_remove_state
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|STATE_DEC_COUNTERS
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|pool_put
argument_list|(
operator|&
name|pf_state_pl
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
else|else
operator|*
name|sm
operator|=
name|s
expr_stmt|;
if|if
condition|(
name|tag
operator|>
literal|0
condition|)
block|{
name|pf_tag_ref
argument_list|(
name|tag
argument_list|)
expr_stmt|;
name|s
operator|->
name|tag
operator|=
name|tag
expr_stmt|;
block|}
block|}
return|return
operator|(
name|PF_PASS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|pf_test_fragment
parameter_list|(
name|struct
name|pf_rule
modifier|*
modifier|*
name|rm
parameter_list|,
name|int
name|direction
parameter_list|,
name|struct
name|pfi_kif
modifier|*
name|kif
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|void
modifier|*
name|h
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
name|pd
parameter_list|,
name|struct
name|pf_rule
modifier|*
modifier|*
name|am
parameter_list|,
name|struct
name|pf_ruleset
modifier|*
modifier|*
name|rsm
parameter_list|)
block|{
name|struct
name|pf_rule
modifier|*
name|r
decl_stmt|,
modifier|*
name|a
init|=
name|NULL
decl_stmt|;
name|struct
name|pf_ruleset
modifier|*
name|ruleset
init|=
name|NULL
decl_stmt|;
name|sa_family_t
name|af
init|=
name|pd
operator|->
name|af
decl_stmt|;
name|u_short
name|reason
decl_stmt|;
name|struct
name|pf_tag
modifier|*
name|pftag
init|=
name|NULL
decl_stmt|;
name|int
name|tag
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|asd
init|=
literal|0
decl_stmt|;
name|r
operator|=
name|TAILQ_FIRST
argument_list|(
name|pf_main_ruleset
operator|.
name|rules
index|[
name|PF_RULESET_FILTER
index|]
operator|.
name|active
operator|.
name|ptr
argument_list|)
expr_stmt|;
while|while
condition|(
name|r
operator|!=
name|NULL
condition|)
block|{
name|r
operator|->
name|evaluations
operator|++
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|kif
operator|!=
name|NULL
operator|&&
operator|(
name|r
operator|->
name|kif
operator|!=
name|kif
operator|&&
name|r
operator|->
name|kif
operator|!=
name|kif
operator|->
name|pfik_parent
operator|)
operator|==
operator|!
name|r
operator|->
name|ifnot
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_IFP
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|direction
operator|&&
name|r
operator|->
name|direction
operator|!=
name|direction
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_DIR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|af
operator|&&
name|r
operator|->
name|af
operator|!=
name|af
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_AF
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|proto
operator|&&
name|r
operator|->
name|proto
operator|!=
name|pd
operator|->
name|proto
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_PROTO
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|PF_MISMATCHAW
argument_list|(
operator|&
name|r
operator|->
name|src
operator|.
name|addr
argument_list|,
name|pd
operator|->
name|src
argument_list|,
name|af
argument_list|,
name|r
operator|->
name|src
operator|.
name|neg
argument_list|)
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_SRC_ADDR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|PF_MISMATCHAW
argument_list|(
operator|&
name|r
operator|->
name|dst
operator|.
name|addr
argument_list|,
name|pd
operator|->
name|dst
argument_list|,
name|af
argument_list|,
name|r
operator|->
name|dst
operator|.
name|neg
argument_list|)
condition|)
name|r
operator|=
name|r
operator|->
name|skip
index|[
name|PF_SKIP_DST_ADDR
index|]
operator|.
name|ptr
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|tos
operator|&&
operator|!
operator|(
name|r
operator|->
name|tos
operator|&
name|pd
operator|->
name|tos
operator|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|src
operator|.
name|port_op
operator|||
name|r
operator|->
name|dst
operator|.
name|port_op
operator|||
name|r
operator|->
name|flagset
operator|||
name|r
operator|->
name|type
operator|||
name|r
operator|->
name|code
operator|||
name|r
operator|->
name|os_fingerprint
operator|!=
name|PF_OSFP_ANY
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|prob
operator|&&
name|r
operator|->
name|prob
operator|<=
name|arc4random
argument_list|()
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|match_tag
operator|&&
operator|!
name|pf_match_tag
argument_list|(
name|m
argument_list|,
name|r
argument_list|,
operator|&
name|pftag
argument_list|,
operator|&
name|tag
argument_list|)
condition|)
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|r
operator|->
name|anchor
operator|==
name|NULL
condition|)
block|{
operator|*
name|rm
operator|=
name|r
expr_stmt|;
operator|*
name|am
operator|=
name|a
expr_stmt|;
operator|*
name|rsm
operator|=
name|ruleset
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|rm
operator|)
operator|->
name|quick
condition|)
break|break;
name|r
operator|=
name|TAILQ_NEXT
argument_list|(
name|r
argument_list|,
name|entries
argument_list|)
expr_stmt|;
block|}
else|else
name|pf_step_into_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|r
operator|==
name|NULL
condition|)
name|pf_step_out_of_anchor
argument_list|(
operator|&
name|asd
argument_list|,
operator|&
name|ruleset
argument_list|,
name|PF_RULESET_FILTER
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
name|r
operator|=
operator|*
name|rm
expr_stmt|;
name|a
operator|=
operator|*
name|am
expr_stmt|;
name|ruleset
operator|=
operator|*
name|rsm
expr_stmt|;
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MATCH
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|log
condition|)
name|PFLOG_PACKET
argument_list|(
name|kif
argument_list|,
name|h
argument_list|,
name|m
argument_list|,
name|af
argument_list|,
name|direction
argument_list|,
name|reason
argument_list|,
name|r
argument_list|,
name|a
argument_list|,
name|ruleset
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|action
operator|!=
name|PF_PASS
condition|)
return|return
operator|(
name|PF_DROP
operator|)
return|;
if|if
condition|(
name|pf_tag_packet
argument_list|(
name|m
argument_list|,
name|pftag
argument_list|,
name|tag
argument_list|)
condition|)
block|{
name|REASON_SET
argument_list|(
operator|&
name|reason
argument_list|,
name|PFRES_MEMORY
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
return|return
operator|(
name|PF_PASS
operator|)
return|;
block|}
end_function

begin_function
name|int
name|pf_test_state_tcp
parameter_list|(
name|struct
name|pf_state
modifier|*
modifier|*
name|state
parameter_list|,
name|int
name|direction
parameter_list|,
name|struct
name|pfi_kif
modifier|*
name|kif
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|off
parameter_list|,
name|void
modifier|*
name|h
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
name|pd
parameter_list|,
name|u_short
modifier|*
name|reason
parameter_list|)
block|{
name|struct
name|pf_state
name|key
decl_stmt|;
name|struct
name|tcphdr
modifier|*
name|th
init|=
name|pd
operator|->
name|hdr
operator|.
name|tcp
decl_stmt|;
name|u_int16_t
name|win
init|=
name|ntohs
argument_list|(
name|th
operator|->
name|th_win
argument_list|)
decl_stmt|;
name|u_int32_t
name|ack
decl_stmt|,
name|end
decl_stmt|,
name|seq
decl_stmt|,
name|orig_seq
decl_stmt|;
name|u_int8_t
name|sws
decl_stmt|,
name|dws
decl_stmt|;
name|int
name|ackskew
decl_stmt|;
name|int
name|copyback
init|=
literal|0
decl_stmt|;
name|struct
name|pf_state_peer
modifier|*
name|src
decl_stmt|,
modifier|*
name|dst
decl_stmt|;
name|key
operator|.
name|af
operator|=
name|pd
operator|->
name|af
expr_stmt|;
name|key
operator|.
name|proto
operator|=
name|IPPROTO_TCP
expr_stmt|;
if|if
condition|(
name|direction
operator|==
name|PF_IN
condition|)
block|{
name|PF_ACPY
argument_list|(
operator|&
name|key
operator|.
name|ext
operator|.
name|addr
argument_list|,
name|pd
operator|->
name|src
argument_list|,
name|key
operator|.
name|af
argument_list|)
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|key
operator|.
name|gwy
operator|.
name|addr
argument_list|,
name|pd
operator|->
name|dst
argument_list|,
name|key
operator|.
name|af
argument_list|)
expr_stmt|;
name|key
operator|.
name|ext
operator|.
name|port
operator|=
name|th
operator|->
name|th_sport
expr_stmt|;
name|key
operator|.
name|gwy
operator|.
name|port
operator|=
name|th
operator|->
name|th_dport
expr_stmt|;
block|}
else|else
block|{
name|PF_ACPY
argument_list|(
operator|&
name|key
operator|.
name|lan
operator|.
name|addr
argument_list|,
name|pd
operator|->
name|src
argument_list|,
name|key
operator|.
name|af
argument_list|)
expr_stmt|;
name|PF_ACPY
argument_list|(
operator|&
name|key
operator|.
name|ext
operator|.
name|addr
argument_list|,
name|pd
operator|->
name|dst
argument_list|,
name|key
operator|.
name|af
argument_list|)
expr_stmt|;
name|key
operator|.
name|lan
operator|.
name|port
operator|=
name|th
operator|->
name|th_sport
expr_stmt|;
name|key
operator|.
name|ext
operator|.
name|port
operator|=
name|th
operator|->
name|th_dport
expr_stmt|;
block|}
name|STATE_LOOKUP
argument_list|()
expr_stmt|;
if|if
condition|(
name|direction
operator|==
operator|(
operator|*
name|state
operator|)
operator|->
name|direction
condition|)
block|{
name|src
operator|=
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|src
expr_stmt|;
name|dst
operator|=
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|dst
expr_stmt|;
block|}
else|else
block|{
name|src
operator|=
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|dst
expr_stmt|;
name|dst
operator|=
operator|&
operator|(
operator|*
name|state
operator|)
operator|->
name|src
expr_stmt|;
block|}
if|if
condition|(
operator|(
operator|*
name|state
operator|)
operator|->
name|src
operator|.
name|state
operator|==
name|PF_TCPS_PROXY_SRC
condition|)
block|{
if|if
condition|(
name|direction
operator|!=
operator|(
operator|*
name|state
operator|)
operator|->
name|direction
condition|)
block|{
name|REASON_SET
argument_list|(
name|reason
argument_list|,
name|PFRES_SYNPROXY
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_SYNPROXY_DROP
operator|)
return|;
block|}
if|if
condition|(
name|th
operator|->
name|th_flags
operator|&
name|TH_SYN
condition|)
block|{
if|if
condition|(
name|ntohl
argument_list|(
name|th
operator|->
name|th_seq
argument_list|)
operator|!=
operator|(
operator|*
name|state
operator|)
operator|->
name|src
operator|.
name|seqlo
condition|)
block|{
name|REASON_SET
argument_list|(
name|reason
argument_list|,
name|PFRES_SYNPROXY
argument_list|)
expr_stmt|;
return|return
operator|(
name|PF_DROP
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|__FreeBSD__
name|pf_send_tcp
argument_list|(
argument|NULL
argument_list|,
argument|(*state)->rule.ptr
argument_list|,
argument|pd->af
argument_list|,
argument|pd->dst
argument_list|,
else|#
directive|else
argument|pf_send_tcp((*state)->rule.ptr, pd->af, pd->dst,
endif|#
directive|endif
argument|pd->src, th->th_dport, th->th_sport, 			    (*state)->src.seqhi, ntohl(th->th_seq) +
literal|1
argument|, 			    TH_SYN|TH_ACK,
literal|0
argument|, (*state)->src.mss,
literal|0
argument|,
literal|1
argument|, 			    NULL, NULL); 			REASON_SET(reason, PFRES_SYNPROXY); 			return (PF_SYNPROXY_DROP); 		} else if (!(th->th_flags& TH_ACK) || 		    (ntohl(th->th_ack) != (*state)->src.seqhi +
literal|1
argument|) || 		    (ntohl(th->th_seq) != (*state)->src.seqlo +
literal|1
argument|)) { 			REASON_SET(reason, PFRES_SYNPROXY); 			return (PF_DROP); 		} else if ((*state)->src_node != NULL&& 		    pf_src_connlimit(state)) { 			REASON_SET(reason, PFRES_SRCLIMIT); 			return (PF_DROP); 		} else 			(*state)->src.state = PF_TCPS_PROXY_DST; 	} 	if ((*state)->src.state == PF_TCPS_PROXY_DST) { 		struct pf_state_host *src
argument_list|,
argument|*dst;  		if (direction == PF_OUT) { 			src =&(*state)->gwy; 			dst =&(*state)->ext; 		} else { 			src =&(*state)->ext; 			dst =&(*state)->lan; 		} 		if (direction == (*state)->direction) { 			if (((th->th_flags& (TH_SYN|TH_ACK)) != TH_ACK) || 			    (ntohl(th->th_ack) != (*state)->src.seqhi +
literal|1
argument|) || 			    (ntohl(th->th_seq) != (*state)->src.seqlo +
literal|1
argument|)) { 				REASON_SET(reason, PFRES_SYNPROXY); 				return (PF_DROP); 			} 			(*state)->src.max_win = MAX(ntohs(th->th_win),
literal|1
argument|); 			if ((*state)->dst.seqhi ==
literal|1
argument|) 				(*state)->dst.seqhi = htonl(arc4random());
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_send_tcp(NULL, (*state)->rule.ptr, pd->af,&src->addr,
else|#
directive|else
argument|pf_send_tcp((*state)->rule.ptr, pd->af,&src->addr,
endif|#
directive|endif
argument|&dst->addr, src->port, dst->port, 			    (*state)->dst.seqhi,
literal|0
argument|, TH_SYN,
literal|0
argument|, 			    (*state)->src.mss,
literal|0
argument|,
literal|0
argument|, NULL, NULL); 			REASON_SET(reason, PFRES_SYNPROXY); 			return (PF_SYNPROXY_DROP); 		} else if (((th->th_flags& (TH_SYN|TH_ACK)) != 		    (TH_SYN|TH_ACK)) || 		    (ntohl(th->th_ack) != (*state)->dst.seqhi +
literal|1
argument|)) { 			REASON_SET(reason, PFRES_SYNPROXY); 			return (PF_DROP); 		} else { 			(*state)->dst.max_win = MAX(ntohs(th->th_win),
literal|1
argument|); 			(*state)->dst.seqlo = ntohl(th->th_seq);
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_send_tcp(NULL, (*state)->rule.ptr, pd->af, pd->dst,
else|#
directive|else
argument|pf_send_tcp((*state)->rule.ptr, pd->af, pd->dst,
endif|#
directive|endif
argument|pd->src, th->th_dport, th->th_sport, 			    ntohl(th->th_ack), ntohl(th->th_seq) +
literal|1
argument|, 			    TH_ACK, (*state)->src.max_win,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, 			    NULL, NULL);
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_send_tcp(NULL, (*state)->rule.ptr, pd->af,&src->addr,
else|#
directive|else
argument|pf_send_tcp((*state)->rule.ptr, pd->af,&src->addr,
endif|#
directive|endif
argument|&dst->addr, src->port, dst->port, 			    (*state)->src.seqhi +
literal|1
argument|, (*state)->src.seqlo +
literal|1
argument|, 			    TH_ACK, (*state)->dst.max_win,
literal|0
argument|,
literal|0
argument|,
literal|1
argument|, 			    NULL, NULL); 			(*state)->src.seqdiff = (*state)->dst.seqhi - 			    (*state)->src.seqlo; 			(*state)->dst.seqdiff = (*state)->src.seqhi - 			    (*state)->dst.seqlo; 			(*state)->src.seqhi = (*state)->src.seqlo + 			    (*state)->dst.max_win; 			(*state)->dst.seqhi = (*state)->dst.seqlo + 			    (*state)->src.max_win; 			(*state)->src.wscale = (*state)->dst.wscale =
literal|0
argument|; 			(*state)->src.state = (*state)->dst.state = 			    TCPS_ESTABLISHED; 			REASON_SET(reason, PFRES_SYNPROXY); 			return (PF_SYNPROXY_DROP); 		} 	}  	if (src->wscale&& dst->wscale&& !(th->th_flags& TH_SYN)) { 		sws = src->wscale& PF_WSCALE_MASK; 		dws = dst->wscale& PF_WSCALE_MASK; 	} else 		sws = dws =
literal|0
argument|;
comment|/* 	 * Sequence tracking algorithm from Guido van Rooij's paper: 	 *   http://www.madison-gurkha.com/publications/tcp_filtering/ 	 *	tcp_filtering.ps 	 */
argument|orig_seq = seq = ntohl(th->th_seq); 	if (src->seqlo ==
literal|0
argument|) {
comment|/* First packet from this end. Set its state */
argument|if ((pd->flags& PFDESC_TCP_NORM || dst->scrub)&& 		    src->scrub == NULL) { 			if (pf_normalize_tcp_init(m, off, pd, th, src, dst)) { 				REASON_SET(reason, PFRES_MEMORY); 				return (PF_DROP); 			} 		}
comment|/* Deferred generation of sequence number modulator */
argument|if (dst->seqdiff&& !src->seqdiff) { 			while ((src->seqdiff = htonl(arc4random())) ==
literal|0
argument|) 				; 			ack = ntohl(th->th_ack) - dst->seqdiff; 			pf_change_a(&th->th_seq,&th->th_sum, htonl(seq + 			    src->seqdiff),
literal|0
argument|); 			pf_change_a(&th->th_ack,&th->th_sum, htonl(ack),
literal|0
argument|); 			copyback =
literal|1
argument|; 		} else { 			ack = ntohl(th->th_ack); 		}  		end = seq + pd->p_len; 		if (th->th_flags& TH_SYN) { 			end++; 			if (dst->wscale& PF_WSCALE_FLAG) { 				src->wscale = pf_get_wscale(m, off, th->th_off, 				    pd->af); 				if (src->wscale& PF_WSCALE_FLAG) {
comment|/* Remove scale factor from initial 					 * window */
argument|sws = src->wscale& PF_WSCALE_MASK; 					win = ((u_int32_t)win + (
literal|1
argument|<< sws) -
literal|1
argument|)>> sws; 					dws = dst->wscale& PF_WSCALE_MASK; 				} else {
comment|/* fixup other window */
argument|dst->max_win<<= dst->wscale& 					    PF_WSCALE_MASK;
comment|/* in case of a retrans SYN|ACK */
argument|dst->wscale =
literal|0
argument|; 				} 			} 		} 		if (th->th_flags& TH_FIN) 			end++;  		src->seqlo = seq; 		if (src->state< TCPS_SYN_SENT) 			src->state = TCPS_SYN_SENT;
comment|/* 		 * May need to slide the window (seqhi may have been set by 		 * the crappy stack check or if we picked up the connection 		 * after establishment) 		 */
argument|if (src->seqhi ==
literal|1
argument||| 		    SEQ_GEQ(end + MAX(
literal|1
argument|, dst->max_win<< dws), src->seqhi)) 			src->seqhi = end + MAX(
literal|1
argument|, dst->max_win<< dws); 		if (win> src->max_win) 			src->max_win = win;  	} else { 		ack = ntohl(th->th_ack) - dst->seqdiff; 		if (src->seqdiff) {
comment|/* Modulate sequence numbers */
argument|pf_change_a(&th->th_seq,&th->th_sum, htonl(seq + 			    src->seqdiff),
literal|0
argument|); 			pf_change_a(&th->th_ack,&th->th_sum, htonl(ack),
literal|0
argument|); 			copyback =
literal|1
argument|; 		} 		end = seq + pd->p_len; 		if (th->th_flags& TH_SYN) 			end++; 		if (th->th_flags& TH_FIN) 			end++; 	}  	if ((th->th_flags& TH_ACK) ==
literal|0
argument|) {
comment|/* Let it pass through the ack skew check */
argument|ack = dst->seqlo; 	} else if ((ack ==
literal|0
argument|&& 	    (th->th_flags& (TH_ACK|TH_RST)) == (TH_ACK|TH_RST)) ||
comment|/* broken tcp stacks do not set ack */
argument|(dst->state< TCPS_SYN_SENT)) {
comment|/* 		 * Many stacks (ours included) will set the ACK number in an 		 * FIN|ACK if the SYN times out -- no sequence to ACK. 		 */
argument|ack = dst->seqlo; 	}  	if (seq == end) {
comment|/* Ease sequencing restrictions on no data packets */
argument|seq = src->seqlo; 		end = seq; 	}  	ackskew = dst->seqlo - ack;
define|#
directive|define
name|MAXACKWINDOW
value|(0xffff + 1500)
comment|/* 1500 is an arbitrary fudge factor */
argument|if (SEQ_GEQ(src->seqhi, end)&&
comment|/* Last octet inside other's window space */
argument|SEQ_GEQ(seq, src->seqlo - (dst->max_win<< dws))&&
comment|/* Retrans: not more than one window back */
argument|(ackskew>= -MAXACKWINDOW)&&
comment|/* Acking not more than one reassembled fragment backwards */
argument|(ackskew<= (MAXACKWINDOW<< sws))&&
comment|/* Acking not more than one window forward */
argument|((th->th_flags& TH_RST) ==
literal|0
argument||| orig_seq == src->seqlo || 	    (pd->flags& PFDESC_IP_REAS) ==
literal|0
argument|)) {
comment|/* Require an exact sequence match on resets when possible */
argument|if (dst->scrub || src->scrub) { 			if (pf_normalize_tcp_stateful(m, off, pd, reason, th, 			    *state, src, dst,&copyback)) 				return (PF_DROP); 		}
comment|/* update max window */
argument|if (src->max_win< win) 			src->max_win = win;
comment|/* synchronize sequencing */
argument|if (SEQ_GT(end, src->seqlo)) 			src->seqlo = end;
comment|/* slide the window of what the other end can send */
argument|if (SEQ_GEQ(ack + (win<< sws), dst->seqhi)) 			dst->seqhi = ack + MAX((win<< sws),
literal|1
argument|);
comment|/* update states */
argument|if (th->th_flags& TH_SYN) 			if (src->state< TCPS_SYN_SENT) 				src->state = TCPS_SYN_SENT; 		if (th->th_flags& TH_FIN) 			if (src->state< TCPS_CLOSING) 				src->state = TCPS_CLOSING; 		if (th->th_flags& TH_ACK) { 			if (dst->state == TCPS_SYN_SENT) { 				dst->state = TCPS_ESTABLISHED; 				if (src->state == TCPS_ESTABLISHED&& 				    (*state)->src_node != NULL&& 				    pf_src_connlimit(state)) { 					REASON_SET(reason, PFRES_SRCLIMIT); 					return (PF_DROP); 				} 			} else if (dst->state == TCPS_CLOSING) 				dst->state = TCPS_FIN_WAIT_2; 		} 		if (th->th_flags& TH_RST) 			src->state = dst->state = TCPS_TIME_WAIT;
comment|/* update expire time */
argument|(*state)->expire = time_second; 		if (src->state>= TCPS_FIN_WAIT_2&& 		    dst->state>= TCPS_FIN_WAIT_2) 			(*state)->timeout = PFTM_TCP_CLOSED; 		else if (src->state>= TCPS_FIN_WAIT_2 || 		    dst->state>= TCPS_FIN_WAIT_2) 			(*state)->timeout = PFTM_TCP_FIN_WAIT; 		else if (src->state< TCPS_ESTABLISHED || 		    dst->state< TCPS_ESTABLISHED) 			(*state)->timeout = PFTM_TCP_OPENING; 		else if (src->state>= TCPS_CLOSING || 		    dst->state>= TCPS_CLOSING) 			(*state)->timeout = PFTM_TCP_CLOSING; 		else 			(*state)->timeout = PFTM_TCP_ESTABLISHED;
comment|/* Fall through to PASS packet */
argument|} else if ((dst->state< TCPS_SYN_SENT || 		dst->state>= TCPS_FIN_WAIT_2 || 		src->state>= TCPS_FIN_WAIT_2)&& 	    SEQ_GEQ(src->seqhi + MAXACKWINDOW, end)&&
comment|/* Within a window forward of the originating packet */
argument|SEQ_GEQ(seq, src->seqlo - MAXACKWINDOW)) {
comment|/* Within a window backward of the originating packet */
comment|/* 		 * This currently handles three situations: 		 *  1) Stupid stacks will shotgun SYNs before their peer 		 *     replies. 		 *  2) When PF catches an already established stream (the 		 *     firewall rebooted, the state table was flushed, routes 		 *     changed...) 		 *  3) Packets get funky immediately after the connection 		 *     closes (this should catch Solaris spurious ACK|FINs 		 *     that web servers like to spew after a close) 		 * 		 * This must be a little more careful than the above code 		 * since packet floods will also be caught here. We don't 		 * update the TTL here to mitigate the damage of a packet 		 * flood and so the same code can handle awkward establishment 		 * and a loosened connection close. 		 * In the establishment case, a correct peer response will 		 * validate the connection, go through the normal state code 		 * and keep updating the state TTL. 		 */
argument|if (pf_status.debug>= PF_DEBUG_MISC) { 			printf(
literal|"pf: loose state match: "
argument|); 			pf_print_state(*state); 			pf_print_flags(th->th_flags); 			printf(
literal|" seq=%u ack=%u len=%u ackskew=%d pkts=%d:%d\n"
argument|, 			    seq, ack, pd->p_len, ackskew, 			    (*state)->packets[
literal|0
argument|], (*state)->packets[
literal|1
argument|]); 		}  		if (dst->scrub || src->scrub) { 			if (pf_normalize_tcp_stateful(m, off, pd, reason, th, 			    *state, src, dst,&copyback)) 				return (PF_DROP); 		}
comment|/* update max window */
argument|if (src->max_win< win) 			src->max_win = win;
comment|/* synchronize sequencing */
argument|if (SEQ_GT(end, src->seqlo)) 			src->seqlo = end;
comment|/* slide the window of what the other end can send */
argument|if (SEQ_GEQ(ack + (win<< sws), dst->seqhi)) 			dst->seqhi = ack + MAX((win<< sws),
literal|1
argument|);
comment|/* 		 * Cannot set dst->seqhi here since this could be a shotgunned 		 * SYN and not an already established connection. 		 */
argument|if (th->th_flags& TH_FIN) 			if (src->state< TCPS_CLOSING) 				src->state = TCPS_CLOSING; 		if (th->th_flags& TH_RST) 			src->state = dst->state = TCPS_TIME_WAIT;
comment|/* Fall through to PASS packet */
argument|} else { 		if ((*state)->dst.state == TCPS_SYN_SENT&& 		    (*state)->src.state == TCPS_SYN_SENT) {
comment|/* Send RST for state mismatches during handshake */
argument|if (!(th->th_flags& TH_RST))
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_send_tcp(m, (*state)->rule.ptr, pd->af,
else|#
directive|else
argument|pf_send_tcp((*state)->rule.ptr, pd->af,
endif|#
directive|endif
argument|pd->dst, pd->src, th->th_dport, 				    th->th_sport, ntohl(th->th_ack),
literal|0
argument|, 				    TH_RST,
literal|0
argument|,
literal|0
argument|, 				    (*state)->rule.ptr->return_ttl,
literal|1
argument|, 				    pd->eh, kif->pfik_ifp); 			src->seqlo =
literal|0
argument|; 			src->seqhi =
literal|1
argument|; 			src->max_win =
literal|1
argument|; 		} else if (pf_status.debug>= PF_DEBUG_MISC) { 			printf(
literal|"pf: BAD state: "
argument|); 			pf_print_state(*state); 			pf_print_flags(th->th_flags); 			printf(
literal|" seq=%u ack=%u len=%u ackskew=%d pkts=%d:%d "
literal|"dir=%s,%s\n"
argument|, seq, ack, pd->p_len, ackskew, 			    (*state)->packets[
literal|0
argument|], (*state)->packets[
literal|1
argument|], 			    direction == PF_IN ?
literal|"in"
argument|:
literal|"out"
argument|, 			    direction == (*state)->direction ?
literal|"fwd"
argument|:
literal|"rev"
argument|); 			printf(
literal|"pf: State failure on: %c %c %c %c | %c %c\n"
argument|, 			    SEQ_GEQ(src->seqhi, end) ?
literal|' '
argument|:
literal|'1'
argument|, 			    SEQ_GEQ(seq, src->seqlo - (dst->max_win<< dws)) ?
literal|' '
argument|:
literal|'2'
argument|, 			    (ackskew>= -MAXACKWINDOW) ?
literal|' '
argument|:
literal|'3'
argument|, 			    (ackskew<= (MAXACKWINDOW<< sws)) ?
literal|' '
argument|:
literal|'4'
argument|, 			    SEQ_GEQ(src->seqhi + MAXACKWINDOW, end) ?
literal|' '
argument|:
literal|'5'
argument|, 			    SEQ_GEQ(seq, src->seqlo - MAXACKWINDOW) ?
literal|' '
argument|:
literal|'6'
argument|); 		} 		REASON_SET(reason, PFRES_BADSTATE); 		return (PF_DROP); 	}
comment|/* Any packets which have gotten here are to be passed */
comment|/* translate source/destination address, if necessary */
argument|if (STATE_TRANSLATE(*state)) { 		if (direction == PF_OUT) 			pf_change_ap(pd->src,&th->th_sport, pd->ip_sum,&th->th_sum,&(*state)->gwy.addr, 			    (*state)->gwy.port,
literal|0
argument|, pd->af); 		else 			pf_change_ap(pd->dst,&th->th_dport, pd->ip_sum,&th->th_sum,&(*state)->lan.addr, 			    (*state)->lan.port,
literal|0
argument|, pd->af); 		m_copyback(m, off, sizeof(*th), (caddr_t)th); 	} else if (copyback) {
comment|/* Copyback sequence modulation or stateful scrub changes */
argument|m_copyback(m, off, sizeof(*th), (caddr_t)th); 	}  	return (PF_PASS); }  int pf_test_state_udp(struct pf_state **state, int direction, struct pfi_kif *kif,     struct mbuf *m, int off, void *h, struct pf_pdesc *pd) { 	struct pf_state_peer	*src, *dst; 	struct pf_state		 key; 	struct udphdr		*uh = pd->hdr.udp;  	key.af = pd->af; 	key.proto = IPPROTO_UDP; 	if (direction == PF_IN)	{ 		PF_ACPY(&key.ext.addr, pd->src, key.af); 		PF_ACPY(&key.gwy.addr, pd->dst, key.af); 		key.ext.port = uh->uh_sport; 		key.gwy.port = uh->uh_dport; 	} else { 		PF_ACPY(&key.lan.addr, pd->src, key.af); 		PF_ACPY(&key.ext.addr, pd->dst, key.af); 		key.lan.port = uh->uh_sport; 		key.ext.port = uh->uh_dport; 	}  	STATE_LOOKUP();  	if (direction == (*state)->direction) { 		src =&(*state)->src; 		dst =&(*state)->dst; 	} else { 		src =&(*state)->dst; 		dst =&(*state)->src; 	}
comment|/* update states */
argument|if (src->state< PFUDPS_SINGLE) 		src->state = PFUDPS_SINGLE; 	if (dst->state == PFUDPS_SINGLE) 		dst->state = PFUDPS_MULTIPLE;
comment|/* update expire time */
argument|(*state)->expire = time_second; 	if (src->state == PFUDPS_MULTIPLE&& dst->state == PFUDPS_MULTIPLE) 		(*state)->timeout = PFTM_UDP_MULTIPLE; 	else 		(*state)->timeout = PFTM_UDP_SINGLE;
comment|/* translate source/destination address, if necessary */
argument|if (STATE_TRANSLATE(*state)) { 		if (direction == PF_OUT) 			pf_change_ap(pd->src,&uh->uh_sport, pd->ip_sum,&uh->uh_sum,&(*state)->gwy.addr, 			    (*state)->gwy.port,
literal|1
argument|, pd->af); 		else 			pf_change_ap(pd->dst,&uh->uh_dport, pd->ip_sum,&uh->uh_sum,&(*state)->lan.addr, 			    (*state)->lan.port,
literal|1
argument|, pd->af); 		m_copyback(m, off, sizeof(*uh), (caddr_t)uh); 	}  	return (PF_PASS); }  int pf_test_state_icmp(struct pf_state **state, int direction, struct pfi_kif *kif,     struct mbuf *m, int off, void *h, struct pf_pdesc *pd, u_short *reason) { 	struct pf_addr	*saddr = pd->src, *daddr = pd->dst; 	u_int16_t	 icmpid =
literal|0
argument|;
comment|/* make the compiler happy */
argument|u_int16_t	*icmpsum = NULL;
comment|/* make the compiler happy */
argument|u_int8_t	 icmptype =
literal|0
argument|;
comment|/* make the compiler happy */
argument|int		 state_icmp =
literal|0
argument|;  	switch (pd->proto) {
ifdef|#
directive|ifdef
name|INET
argument|case IPPROTO_ICMP: 		icmptype = pd->hdr.icmp->icmp_type; 		icmpid = pd->hdr.icmp->icmp_id; 		icmpsum =&pd->hdr.icmp->icmp_cksum;  		if (icmptype == ICMP_UNREACH || 		    icmptype == ICMP_SOURCEQUENCH || 		    icmptype == ICMP_REDIRECT || 		    icmptype == ICMP_TIMXCEED || 		    icmptype == ICMP_PARAMPROB) 			state_icmp++; 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case IPPROTO_ICMPV6: 		icmptype = pd->hdr.icmp6->icmp6_type; 		icmpid = pd->hdr.icmp6->icmp6_id; 		icmpsum =&pd->hdr.icmp6->icmp6_cksum;  		if (icmptype == ICMP6_DST_UNREACH || 		    icmptype == ICMP6_PACKET_TOO_BIG || 		    icmptype == ICMP6_TIME_EXCEEDED || 		    icmptype == ICMP6_PARAM_PROB) 			state_icmp++; 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|}  	if (!state_icmp) {
comment|/* 		 * ICMP query/reply message not related to a TCP/UDP packet. 		 * Search for an ICMP state. 		 */
argument|struct pf_state		key;  		key.af = pd->af; 		key.proto = pd->proto; 		if (direction == PF_IN)	{ 			PF_ACPY(&key.ext.addr, pd->src, key.af); 			PF_ACPY(&key.gwy.addr, pd->dst, key.af); 			key.ext.port =
literal|0
argument|; 			key.gwy.port = icmpid; 		} else { 			PF_ACPY(&key.lan.addr, pd->src, key.af); 			PF_ACPY(&key.ext.addr, pd->dst, key.af); 			key.lan.port = icmpid; 			key.ext.port =
literal|0
argument|; 		}  		STATE_LOOKUP();  		(*state)->expire = time_second; 		(*state)->timeout = PFTM_ICMP_ERROR_REPLY;
comment|/* translate source/destination address, if necessary */
argument|if (STATE_TRANSLATE(*state)) { 			if (direction == PF_OUT) { 				switch (pd->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 					pf_change_a(&saddr->v4.s_addr, 					    pd->ip_sum, 					    (*state)->gwy.addr.v4.s_addr,
literal|0
argument|); 					pd->hdr.icmp->icmp_cksum = 					    pf_cksum_fixup( 					    pd->hdr.icmp->icmp_cksum, icmpid, 					    (*state)->gwy.port,
literal|0
argument|); 					pd->hdr.icmp->icmp_id = 					    (*state)->gwy.port; 					m_copyback(m, off, ICMP_MINLEN, 					    (caddr_t)pd->hdr.icmp); 					break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 					pf_change_a6(saddr,&pd->hdr.icmp6->icmp6_cksum,&(*state)->gwy.addr,
literal|0
argument|); 					m_copyback(m, off, 					    sizeof(struct icmp6_hdr), 					    (caddr_t)pd->hdr.icmp6); 					break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 			} else { 				switch (pd->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 					pf_change_a(&daddr->v4.s_addr, 					    pd->ip_sum, 					    (*state)->lan.addr.v4.s_addr,
literal|0
argument|); 					pd->hdr.icmp->icmp_cksum = 					    pf_cksum_fixup( 					    pd->hdr.icmp->icmp_cksum, icmpid, 					    (*state)->lan.port,
literal|0
argument|); 					pd->hdr.icmp->icmp_id = 					    (*state)->lan.port; 					m_copyback(m, off, ICMP_MINLEN, 					    (caddr_t)pd->hdr.icmp); 					break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 					pf_change_a6(daddr,&pd->hdr.icmp6->icmp6_cksum,&(*state)->lan.addr,
literal|0
argument|); 					m_copyback(m, off, 					    sizeof(struct icmp6_hdr), 					    (caddr_t)pd->hdr.icmp6); 					break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 			} 		}  		return (PF_PASS);  	} else {
comment|/* 		 * ICMP error message in response to a TCP/UDP packet. 		 * Extract the inner TCP/UDP header and search for that state. 		 */
argument|struct pf_pdesc	pd2;
ifdef|#
directive|ifdef
name|INET
argument|struct ip	h2;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|struct ip6_hdr	h2_6; 		int		terminal =
literal|0
argument|;
endif|#
directive|endif
comment|/* INET6 */
argument|int		ipoff2 =
literal|0
argument|;
comment|/* make the compiler happy */
argument|int		off2 =
literal|0
argument|;
comment|/* make the compiler happy */
argument|pd2.af = pd->af; 		switch (pd->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET:
comment|/* offset of h2 in mbuf chain */
argument|ipoff2 = off + ICMP_MINLEN;  			if (!pf_pull_hdr(m, ipoff2,&h2, sizeof(h2), 			    NULL, reason, pd2.af)) { 				DPFPRINTF(PF_DEBUG_MISC, 				    (
literal|"pf: ICMP error message too short "
literal|"(ip)\n"
argument|)); 				return (PF_DROP); 			}
comment|/* 			 * ICMP error messages don't refer to non-first 			 * fragments 			 */
argument|if (h2.ip_off& htons(IP_OFFMASK)) { 				REASON_SET(reason, PFRES_FRAG); 				return (PF_DROP); 			}
comment|/* offset of protocol header that follows h2 */
argument|off2 = ipoff2 + (h2.ip_hl<<
literal|2
argument|);  			pd2.proto = h2.ip_p; 			pd2.src = (struct pf_addr *)&h2.ip_src; 			pd2.dst = (struct pf_addr *)&h2.ip_dst; 			pd2.ip_sum =&h2.ip_sum; 			break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 			ipoff2 = off + sizeof(struct icmp6_hdr);  			if (!pf_pull_hdr(m, ipoff2,&h2_6, sizeof(h2_6), 			    NULL, reason, pd2.af)) { 				DPFPRINTF(PF_DEBUG_MISC, 				    (
literal|"pf: ICMP error message too short "
literal|"(ip6)\n"
argument|)); 				return (PF_DROP); 			} 			pd2.proto = h2_6.ip6_nxt; 			pd2.src = (struct pf_addr *)&h2_6.ip6_src; 			pd2.dst = (struct pf_addr *)&h2_6.ip6_dst; 			pd2.ip_sum = NULL; 			off2 = ipoff2 + sizeof(h2_6); 			do { 				switch (pd2.proto) { 				case IPPROTO_FRAGMENT:
comment|/* 					 * ICMPv6 error messages for 					 * non-first fragments 					 */
argument|REASON_SET(reason, PFRES_FRAG); 					return (PF_DROP); 				case IPPROTO_AH: 				case IPPROTO_HOPOPTS: 				case IPPROTO_ROUTING: 				case IPPROTO_DSTOPTS: {
comment|/* get next header and header length */
argument|struct ip6_ext opt6;  					if (!pf_pull_hdr(m, off2,&opt6, 					    sizeof(opt6), NULL, reason, 					    pd2.af)) { 						DPFPRINTF(PF_DEBUG_MISC, 						    (
literal|"pf: ICMPv6 short opt\n"
argument|)); 						return (PF_DROP); 					} 					if (pd2.proto == IPPROTO_AH) 						off2 += (opt6.ip6e_len +
literal|2
argument|) *
literal|4
argument|; 					else 						off2 += (opt6.ip6e_len +
literal|1
argument|) *
literal|8
argument|; 					pd2.proto = opt6.ip6e_nxt;
comment|/* goto the next header */
argument|break; 				} 				default: 					terminal++; 					break; 				} 			} while (!terminal); 			break;
endif|#
directive|endif
comment|/* INET6 */
argument|}  		switch (pd2.proto) { 		case IPPROTO_TCP: { 			struct tcphdr		 th; 			u_int32_t		 seq; 			struct pf_state		 key; 			struct pf_state_peer	*src, *dst; 			u_int8_t		 dws; 			int			 copyback =
literal|0
argument|;
comment|/* 			 * Only the first 8 bytes of the TCP header can be 			 * expected. Don't access any TCP header fields after 			 * th_seq, an ackskew test is not possible. 			 */
argument|if (!pf_pull_hdr(m, off2,&th,
literal|8
argument|, NULL, reason, 			    pd2.af)) { 				DPFPRINTF(PF_DEBUG_MISC, 				    (
literal|"pf: ICMP error message too short "
literal|"(tcp)\n"
argument|)); 				return (PF_DROP); 			}  			key.af = pd2.af; 			key.proto = IPPROTO_TCP; 			if (direction == PF_IN)	{ 				PF_ACPY(&key.ext.addr, pd2.dst, key.af); 				PF_ACPY(&key.gwy.addr, pd2.src, key.af); 				key.ext.port = th.th_dport; 				key.gwy.port = th.th_sport; 			} else { 				PF_ACPY(&key.lan.addr, pd2.dst, key.af); 				PF_ACPY(&key.ext.addr, pd2.src, key.af); 				key.lan.port = th.th_dport; 				key.ext.port = th.th_sport; 			}  			STATE_LOOKUP();  			if (direction == (*state)->direction) { 				src =&(*state)->dst; 				dst =&(*state)->src; 			} else { 				src =&(*state)->src; 				dst =&(*state)->dst; 			}  			if (src->wscale&& dst->wscale&& 			    !(th.th_flags& TH_SYN)) 				dws = dst->wscale& PF_WSCALE_MASK; 			else 				dws =
literal|0
argument|;
comment|/* Demodulate sequence number */
argument|seq = ntohl(th.th_seq) - src->seqdiff; 			if (src->seqdiff) { 				pf_change_a(&th.th_seq, icmpsum, 				    htonl(seq),
literal|0
argument|); 				copyback =
literal|1
argument|; 			}  			if (!SEQ_GEQ(src->seqhi, seq) || 			    !SEQ_GEQ(seq, src->seqlo - (dst->max_win<< dws))) { 				if (pf_status.debug>= PF_DEBUG_MISC) { 					printf(
literal|"pf: BAD ICMP %d:%d "
argument|, 					    icmptype, pd->hdr.icmp->icmp_code); 					pf_print_host(pd->src,
literal|0
argument|, pd->af); 					printf(
literal|" -> "
argument|); 					pf_print_host(pd->dst,
literal|0
argument|, pd->af); 					printf(
literal|" state: "
argument|); 					pf_print_state(*state); 					printf(
literal|" seq=%u\n"
argument|, seq); 				} 				REASON_SET(reason, PFRES_BADSTATE); 				return (PF_DROP); 			}  			if (STATE_TRANSLATE(*state)) { 				if (direction == PF_IN) { 					pf_change_icmp(pd2.src,&th.th_sport, 					    daddr,&(*state)->lan.addr, 					    (*state)->lan.port, NULL, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|0
argument|, pd2.af); 				} else { 					pf_change_icmp(pd2.dst,&th.th_dport, 					    saddr,&(*state)->gwy.addr, 					    (*state)->gwy.port, NULL, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|0
argument|, pd2.af); 				} 				copyback =
literal|1
argument|; 			}  			if (copyback) { 				switch (pd2.af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 					m_copyback(m, off, ICMP_MINLEN, 					    (caddr_t)pd->hdr.icmp); 					m_copyback(m, ipoff2, sizeof(h2), 					    (caddr_t)&h2); 					break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 					m_copyback(m, off, 					    sizeof(struct icmp6_hdr), 					    (caddr_t)pd->hdr.icmp6); 					m_copyback(m, ipoff2, sizeof(h2_6), 					    (caddr_t)&h2_6); 					break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 				m_copyback(m, off2,
literal|8
argument|, (caddr_t)&th); 			}  			return (PF_PASS); 			break; 		} 		case IPPROTO_UDP: { 			struct udphdr		uh; 			struct pf_state		key;  			if (!pf_pull_hdr(m, off2,&uh, sizeof(uh), 			    NULL, reason, pd2.af)) { 				DPFPRINTF(PF_DEBUG_MISC, 				    (
literal|"pf: ICMP error message too short "
literal|"(udp)\n"
argument|)); 				return (PF_DROP); 			}  			key.af = pd2.af; 			key.proto = IPPROTO_UDP; 			if (direction == PF_IN)	{ 				PF_ACPY(&key.ext.addr, pd2.dst, key.af); 				PF_ACPY(&key.gwy.addr, pd2.src, key.af); 				key.ext.port = uh.uh_dport; 				key.gwy.port = uh.uh_sport; 			} else { 				PF_ACPY(&key.lan.addr, pd2.dst, key.af); 				PF_ACPY(&key.ext.addr, pd2.src, key.af); 				key.lan.port = uh.uh_dport; 				key.ext.port = uh.uh_sport; 			}  			STATE_LOOKUP();  			if (STATE_TRANSLATE(*state)) { 				if (direction == PF_IN) { 					pf_change_icmp(pd2.src,&uh.uh_sport, 					    daddr,&(*state)->lan.addr, 					    (*state)->lan.port,&uh.uh_sum, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|1
argument|, pd2.af); 				} else { 					pf_change_icmp(pd2.dst,&uh.uh_dport, 					    saddr,&(*state)->gwy.addr, 					    (*state)->gwy.port,&uh.uh_sum, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|1
argument|, pd2.af); 				} 				switch (pd2.af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 					m_copyback(m, off, ICMP_MINLEN, 					    (caddr_t)pd->hdr.icmp); 					m_copyback(m, ipoff2, sizeof(h2), 					    (caddr_t)&h2); 					break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 					m_copyback(m, off, 					    sizeof(struct icmp6_hdr), 					    (caddr_t)pd->hdr.icmp6); 					m_copyback(m, ipoff2, sizeof(h2_6), 					    (caddr_t)&h2_6); 					break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 				m_copyback(m, off2, sizeof(uh), 				    (caddr_t)&uh); 			}  			return (PF_PASS); 			break; 		}
ifdef|#
directive|ifdef
name|INET
argument|case IPPROTO_ICMP: { 			struct icmp		iih; 			struct pf_state		key;  			if (!pf_pull_hdr(m, off2,&iih, ICMP_MINLEN, 			    NULL, reason, pd2.af)) { 				DPFPRINTF(PF_DEBUG_MISC, 				    (
literal|"pf: ICMP error message too short i"
literal|"(icmp)\n"
argument|)); 				return (PF_DROP); 			}  			key.af = pd2.af; 			key.proto = IPPROTO_ICMP; 			if (direction == PF_IN)	{ 				PF_ACPY(&key.ext.addr, pd2.dst, key.af); 				PF_ACPY(&key.gwy.addr, pd2.src, key.af); 				key.ext.port =
literal|0
argument|; 				key.gwy.port = iih.icmp_id; 			} else { 				PF_ACPY(&key.lan.addr, pd2.dst, key.af); 				PF_ACPY(&key.ext.addr, pd2.src, key.af); 				key.lan.port = iih.icmp_id; 				key.ext.port =
literal|0
argument|; 			}  			STATE_LOOKUP();  			if (STATE_TRANSLATE(*state)) { 				if (direction == PF_IN) { 					pf_change_icmp(pd2.src,&iih.icmp_id, 					    daddr,&(*state)->lan.addr, 					    (*state)->lan.port, NULL, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|0
argument|, AF_INET); 				} else { 					pf_change_icmp(pd2.dst,&iih.icmp_id, 					    saddr,&(*state)->gwy.addr, 					    (*state)->gwy.port, NULL, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|0
argument|, AF_INET); 				} 				m_copyback(m, off, ICMP_MINLEN, 				    (caddr_t)pd->hdr.icmp); 				m_copyback(m, ipoff2, sizeof(h2), 				    (caddr_t)&h2); 				m_copyback(m, off2, ICMP_MINLEN, 				    (caddr_t)&iih); 			}  			return (PF_PASS); 			break; 		}
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case IPPROTO_ICMPV6: { 			struct icmp6_hdr	iih; 			struct pf_state		key;  			if (!pf_pull_hdr(m, off2,&iih, 			    sizeof(struct icmp6_hdr), NULL, reason, pd2.af)) { 				DPFPRINTF(PF_DEBUG_MISC, 				    (
literal|"pf: ICMP error message too short "
literal|"(icmp6)\n"
argument|)); 				return (PF_DROP); 			}  			key.af = pd2.af; 			key.proto = IPPROTO_ICMPV6; 			if (direction == PF_IN)	{ 				PF_ACPY(&key.ext.addr, pd2.dst, key.af); 				PF_ACPY(&key.gwy.addr, pd2.src, key.af); 				key.ext.port =
literal|0
argument|; 				key.gwy.port = iih.icmp6_id; 			} else { 				PF_ACPY(&key.lan.addr, pd2.dst, key.af); 				PF_ACPY(&key.ext.addr, pd2.src, key.af); 				key.lan.port = iih.icmp6_id; 				key.ext.port =
literal|0
argument|; 			}  			STATE_LOOKUP();  			if (STATE_TRANSLATE(*state)) { 				if (direction == PF_IN) { 					pf_change_icmp(pd2.src,&iih.icmp6_id, 					    daddr,&(*state)->lan.addr, 					    (*state)->lan.port, NULL, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|0
argument|, AF_INET6); 				} else { 					pf_change_icmp(pd2.dst,&iih.icmp6_id, 					    saddr,&(*state)->gwy.addr, 					    (*state)->gwy.port, NULL, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|0
argument|, AF_INET6); 				} 				m_copyback(m, off, sizeof(struct icmp6_hdr), 				    (caddr_t)pd->hdr.icmp6); 				m_copyback(m, ipoff2, sizeof(h2_6), 				    (caddr_t)&h2_6); 				m_copyback(m, off2, sizeof(struct icmp6_hdr), 				    (caddr_t)&iih); 			}  			return (PF_PASS); 			break; 		}
endif|#
directive|endif
comment|/* INET6 */
argument|default: { 			struct pf_state		key;  			key.af = pd2.af; 			key.proto = pd2.proto; 			if (direction == PF_IN)	{ 				PF_ACPY(&key.ext.addr, pd2.dst, key.af); 				PF_ACPY(&key.gwy.addr, pd2.src, key.af); 				key.ext.port =
literal|0
argument|; 				key.gwy.port =
literal|0
argument|; 			} else { 				PF_ACPY(&key.lan.addr, pd2.dst, key.af); 				PF_ACPY(&key.ext.addr, pd2.src, key.af); 				key.lan.port =
literal|0
argument|; 				key.ext.port =
literal|0
argument|; 			}  			STATE_LOOKUP();  			if (STATE_TRANSLATE(*state)) { 				if (direction == PF_IN) { 					pf_change_icmp(pd2.src, NULL, 					    daddr,&(*state)->lan.addr,
literal|0
argument|, NULL, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|0
argument|, pd2.af); 				} else { 					pf_change_icmp(pd2.dst, NULL, 					    saddr,&(*state)->gwy.addr,
literal|0
argument|, NULL, 					    pd2.ip_sum, icmpsum, 					    pd->ip_sum,
literal|0
argument|, pd2.af); 				} 				switch (pd2.af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 					m_copyback(m, off, ICMP_MINLEN, 					    (caddr_t)pd->hdr.icmp); 					m_copyback(m, ipoff2, sizeof(h2), 					    (caddr_t)&h2); 					break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 					m_copyback(m, off, 					    sizeof(struct icmp6_hdr), 					    (caddr_t)pd->hdr.icmp6); 					m_copyback(m, ipoff2, sizeof(h2_6), 					    (caddr_t)&h2_6); 					break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 			}  			return (PF_PASS); 			break; 		} 		} 	} }  int pf_test_state_other(struct pf_state **state, int direction, struct pfi_kif *kif,     struct pf_pdesc *pd) { 	struct pf_state_peer	*src, *dst; 	struct pf_state		 key;  	key.af = pd->af; 	key.proto = pd->proto; 	if (direction == PF_IN)	{ 		PF_ACPY(&key.ext.addr, pd->src, key.af); 		PF_ACPY(&key.gwy.addr, pd->dst, key.af); 		key.ext.port =
literal|0
argument|; 		key.gwy.port =
literal|0
argument|; 	} else { 		PF_ACPY(&key.lan.addr, pd->src, key.af); 		PF_ACPY(&key.ext.addr, pd->dst, key.af); 		key.lan.port =
literal|0
argument|; 		key.ext.port =
literal|0
argument|; 	}  	STATE_LOOKUP();  	if (direction == (*state)->direction) { 		src =&(*state)->src; 		dst =&(*state)->dst; 	} else { 		src =&(*state)->dst; 		dst =&(*state)->src; 	}
comment|/* update states */
argument|if (src->state< PFOTHERS_SINGLE) 		src->state = PFOTHERS_SINGLE; 	if (dst->state == PFOTHERS_SINGLE) 		dst->state = PFOTHERS_MULTIPLE;
comment|/* update expire time */
argument|(*state)->expire = time_second; 	if (src->state == PFOTHERS_MULTIPLE&& dst->state == PFOTHERS_MULTIPLE) 		(*state)->timeout = PFTM_OTHER_MULTIPLE; 	else 		(*state)->timeout = PFTM_OTHER_SINGLE;
comment|/* translate source/destination address, if necessary */
argument|if (STATE_TRANSLATE(*state)) { 		if (direction == PF_OUT) 			switch (pd->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 				pf_change_a(&pd->src->v4.s_addr, 				    pd->ip_sum, (*state)->gwy.addr.v4.s_addr,
literal|0
argument|); 				break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 				PF_ACPY(pd->src,&(*state)->gwy.addr, pd->af); 				break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 		else 			switch (pd->af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 				pf_change_a(&pd->dst->v4.s_addr, 				    pd->ip_sum, (*state)->lan.addr.v4.s_addr,
literal|0
argument|); 				break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 				PF_ACPY(pd->dst,&(*state)->lan.addr, pd->af); 				break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 	}  	return (PF_PASS); }
comment|/*  * ipoff and off are measured from the start of the mbuf chain.  * h must be at "ipoff" on the mbuf chain.  */
argument|void * pf_pull_hdr(struct mbuf *m, int off, void *p, int len,     u_short *actionp, u_short *reasonp, sa_family_t af) { 	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: { 		struct ip	*h = mtod(m, struct ip *); 		u_int16_t	 fragoff = (ntohs(h->ip_off)& IP_OFFMASK)<<
literal|3
argument|;  		if (fragoff) { 			if (fragoff>= len) 				ACTION_SET(actionp, PF_PASS); 			else { 				ACTION_SET(actionp, PF_DROP); 				REASON_SET(reasonp, PFRES_FRAG); 			} 			return (NULL); 		} 		if (m->m_pkthdr.len< off + len || 		    ntohs(h->ip_len)< off + len) { 			ACTION_SET(actionp, PF_DROP); 			REASON_SET(reasonp, PFRES_SHORT); 			return (NULL); 		} 		break; 	}
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: { 		struct ip6_hdr	*h = mtod(m, struct ip6_hdr *);  		if (m->m_pkthdr.len< off + len || 		    (ntohs(h->ip6_plen) + sizeof(struct ip6_hdr))< 		    (unsigned)(off + len)) { 			ACTION_SET(actionp, PF_DROP); 			REASON_SET(reasonp, PFRES_SHORT); 			return (NULL); 		} 		break; 	}
endif|#
directive|endif
comment|/* INET6 */
argument|} 	m_copydata(m, off, len, p); 	return (p); }  int pf_routable(struct pf_addr *addr, sa_family_t af) { 	struct sockaddr_in	*dst;
ifdef|#
directive|ifdef
name|INET6
argument|struct sockaddr_in6	*dst6; 	struct route_in6	 ro;
else|#
directive|else
argument|struct route		 ro;
endif|#
directive|endif
argument|bzero(&ro, sizeof(ro)); 	switch (af) { 	case AF_INET: 		dst = satosin(&ro.ro_dst); 		dst->sin_family = AF_INET; 		dst->sin_len = sizeof(*dst); 		dst->sin_addr = addr->v4; 		break;
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		dst6 = (struct sockaddr_in6 *)&ro.ro_dst; 		dst6->sin6_family = AF_INET6; 		dst6->sin6_len = sizeof(*dst6); 		dst6->sin6_addr = addr->v6; 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|default: 		return (
literal|0
argument|); 	}
ifdef|#
directive|ifdef
name|__FreeBSD__
ifdef|#
directive|ifdef
name|RTF_PRCLONING
argument|rtalloc_ign((struct route *)&ro, (RTF_CLONING | RTF_PRCLONING));
else|#
directive|else
comment|/* !RTF_PRCLONING */
argument|rtalloc_ign((struct route *)&ro, RTF_CLONING);
endif|#
directive|endif
else|#
directive|else
comment|/* ! __FreeBSD__ */
argument|rtalloc_noclone((struct route *)&ro, NO_CLONING);
endif|#
directive|endif
argument|if (ro.ro_rt != NULL) { 		RTFREE(ro.ro_rt); 		return (
literal|1
argument|); 	}  	return (
literal|0
argument|); }  int pf_rtlabel_match(struct pf_addr *addr, sa_family_t af, struct pf_addr_wrap *aw) { 	struct sockaddr_in	*dst;
ifdef|#
directive|ifdef
name|INET6
argument|struct sockaddr_in6	*dst6; 	struct route_in6	 ro;
else|#
directive|else
argument|struct route		 ro;
endif|#
directive|endif
argument|int			 ret =
literal|0
argument|;  	bzero(&ro, sizeof(ro)); 	switch (af) { 	case AF_INET: 		dst = satosin(&ro.ro_dst); 		dst->sin_family = AF_INET; 		dst->sin_len = sizeof(*dst); 		dst->sin_addr = addr->v4; 		break;
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		dst6 = (struct sockaddr_in6 *)&ro.ro_dst; 		dst6->sin6_family = AF_INET6; 		dst6->sin6_len = sizeof(*dst6); 		dst6->sin6_addr = addr->v6; 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|default: 		return (
literal|0
argument|); 	}
ifdef|#
directive|ifdef
name|__FreeBSD__
ifdef|#
directive|ifdef
name|RTF_PRCLONING
argument|rtalloc_ign((struct route *)&ro, (RTF_CLONING|RTF_PRCLONING));
else|#
directive|else
comment|/* !RTF_PRCLONING */
argument|rtalloc_ign((struct route *)&ro, RTF_CLONING);
endif|#
directive|endif
else|#
directive|else
comment|/* ! __FreeBSD__ */
argument|rtalloc_noclone((struct route *)&ro, NO_CLONING);
endif|#
directive|endif
argument|if (ro.ro_rt != NULL) {
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* XXX_IMPORT: later */
else|#
directive|else
argument|if (ro.ro_rt->rt_labelid == aw->v.rtlabel) 			ret =
literal|1
argument|;
endif|#
directive|endif
argument|RTFREE(ro.ro_rt); 	}  	return (ret); }
ifdef|#
directive|ifdef
name|INET
argument|void pf_route(struct mbuf **m, struct pf_rule *r, int dir, struct ifnet *oifp,     struct pf_state *s) { 	struct mbuf		*m0, *m1; 	struct m_tag		*mtag; 	struct route		 iproute; 	struct route		*ro = NULL;
comment|/* XXX: was uninitialized */
argument|struct sockaddr_in	*dst; 	struct ip		*ip; 	struct ifnet		*ifp = NULL; 	struct pf_addr		 naddr; 	struct pf_src_node	*sn = NULL; 	int			 error =
literal|0
argument|;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|int sw_csum;
endif|#
directive|endif
argument|if (m == NULL || *m == NULL || r == NULL || 	    (dir != PF_IN&& dir != PF_OUT) || oifp == NULL) 		panic(
literal|"pf_route: invalid parameters"
argument|);  	if ((mtag = m_tag_find(*m, PACKET_TAG_PF_ROUTED, NULL)) == NULL) { 		if ((mtag = m_tag_get(PACKET_TAG_PF_ROUTED,
literal|1
argument|, M_NOWAIT)) == 		    NULL) { 			m0 = *m; 			*m = NULL; 			goto bad; 		} 		*(char *)(mtag +
literal|1
argument|) =
literal|1
argument|; 		m_tag_prepend(*m, mtag); 	} else { 		if (*(char *)(mtag +
literal|1
argument|)>
literal|3
argument|) { 			m0 = *m; 			*m = NULL; 			goto bad; 		} 		(*(char *)(mtag +
literal|1
argument|))++; 	}  	if (r->rt == PF_DUPTO) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|if ((m0 = m_dup(*m, M_DONTWAIT)) == NULL)
else|#
directive|else
argument|if ((m0 = m_copym2(*m,
literal|0
argument|, M_COPYALL, M_NOWAIT)) == NULL)
endif|#
directive|endif
argument|return; 	} else { 		if ((r->rt == PF_REPLYTO) == (r->direction == dir)) 			return; 		m0 = *m; 	}  	if (m0->m_len< sizeof(struct ip)) { 		DPFPRINTF(PF_DEBUG_URGENT, 		    (
literal|"pf_route: m0->m_len< sizeof(struct ip)\n"
argument|)); 		goto bad; 	}  	ip = mtod(m0, struct ip *);  	ro =&iproute; 	bzero((caddr_t)ro, sizeof(*ro)); 	dst = satosin(&ro->ro_dst); 	dst->sin_family = AF_INET; 	dst->sin_len = sizeof(*dst); 	dst->sin_addr = ip->ip_dst;  	if (r->rt == PF_FASTROUTE) { 		rtalloc(ro); 		if (ro->ro_rt ==
literal|0
argument|) { 			ipstat.ips_noroute++; 			goto bad; 		}  		ifp = ro->ro_rt->rt_ifp; 		ro->ro_rt->rt_use++;  		if (ro->ro_rt->rt_flags& RTF_GATEWAY) 			dst = satosin(ro->ro_rt->rt_gateway); 	} else { 		if (TAILQ_EMPTY(&r->rpool.list)) { 			DPFPRINTF(PF_DEBUG_URGENT, 			    (
literal|"pf_route: TAILQ_EMPTY(&r->rpool.list)\n"
argument|)); 			goto bad; 		} 		if (s == NULL) { 			pf_map_addr(AF_INET, r, (struct pf_addr *)&ip->ip_src,&naddr, NULL,&sn); 			if (!PF_AZERO(&naddr, AF_INET)) 				dst->sin_addr.s_addr = naddr.v4.s_addr; 			ifp = r->rpool.cur->kif ? 			    r->rpool.cur->kif->pfik_ifp : NULL; 		} else { 			if (!PF_AZERO(&s->rt_addr, AF_INET)) 				dst->sin_addr.s_addr = 				    s->rt_addr.v4.s_addr; 			ifp = s->rt_kif ? s->rt_kif->pfik_ifp : NULL; 		} 	} 	if (ifp == NULL) 		goto bad;  	if (oifp != ifp) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK(); 		if (pf_test(PF_OUT, ifp,&m0, NULL, NULL) != PF_PASS) { 			PF_LOCK(); 			goto bad; 		} else if (m0 == NULL) { 			PF_LOCK(); 			goto done; 		} 		PF_LOCK();
else|#
directive|else
argument|if (pf_test(PF_OUT, ifp,&m0, NULL) != PF_PASS) 			goto bad; 		else if (m0 == NULL) 			goto done;
endif|#
directive|endif
argument|if (m0->m_len< sizeof(struct ip)) { 			DPFPRINTF(PF_DEBUG_URGENT, 			    (
literal|"pf_route: m0->m_len< sizeof(struct ip)\n"
argument|)); 			goto bad; 		} 		ip = mtod(m0, struct ip *); 	}
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* Copied from FreeBSD 5.1-CURRENT ip_output. */
argument|m0->m_pkthdr.csum_flags |= CSUM_IP; 	sw_csum = m0->m_pkthdr.csum_flags& ~ifp->if_hwassist; 	if (sw_csum& CSUM_DELAY_DATA) {
comment|/* 		 * XXX: in_delayed_cksum assumes HBO for ip->ip_len (at least) 		 */
argument|NTOHS(ip->ip_len); 		NTOHS(ip->ip_off);
comment|/* XXX: needed? */
argument|in_delayed_cksum(m0); 		HTONS(ip->ip_len); 		HTONS(ip->ip_off); 		sw_csum&= ~CSUM_DELAY_DATA; 	} 	m0->m_pkthdr.csum_flags&= ifp->if_hwassist;  	if (ntohs(ip->ip_len)<= ifp->if_mtu || 	    (ifp->if_hwassist& CSUM_FRAGMENT&& 		((ip->ip_off& htons(IP_DF)) ==
literal|0
argument|))) {
comment|/* 		 * ip->ip_len = htons(ip->ip_len); 		 * ip->ip_off = htons(ip->ip_off); 		 */
argument|ip->ip_sum =
literal|0
argument|; 		if (sw_csum& CSUM_DELAY_IP) {
comment|/* From KAME */
argument|if (ip->ip_v == IPVERSION&& 			    (ip->ip_hl<<
literal|2
argument|) == sizeof(*ip)) { 				ip->ip_sum = in_cksum_hdr(ip); 			} else { 				ip->ip_sum = in_cksum(m0, ip->ip_hl<<
literal|2
argument|); 			} 		} 		PF_UNLOCK(); 		error = (*ifp->if_output)(ifp, m0, sintosa(dst), ro->ro_rt); 		PF_LOCK(); 		goto done; 	}
else|#
directive|else
comment|/* Copied from ip_output. */
ifdef|#
directive|ifdef
name|IPSEC
comment|/* 	 * If deferred crypto processing is needed, check that the 	 * interface supports it. 	 */
argument|if ((mtag = m_tag_find(m0, PACKET_TAG_IPSEC_OUT_CRYPTO_NEEDED, NULL)) 	    != NULL&& (ifp->if_capabilities& IFCAP_IPSEC) ==
literal|0
argument|) {
comment|/* Notify IPsec to do its own crypto. */
argument|ipsp_skipcrypto_unmark((struct tdb_ident *)(mtag +
literal|1
argument|)); 		goto bad; 	}
endif|#
directive|endif
comment|/* IPSEC */
comment|/* Catch routing changes wrt. hardware checksumming for TCP or UDP. */
argument|if (m0->m_pkthdr.csum& M_TCPV4_CSUM_OUT) { 		if (!(ifp->if_capabilities& IFCAP_CSUM_TCPv4) || 		    ifp->if_bridge != NULL) { 			in_delayed_cksum(m0); 			m0->m_pkthdr.csum&= ~M_TCPV4_CSUM_OUT;
comment|/* Clear */
argument|} 	} else if (m0->m_pkthdr.csum& M_UDPV4_CSUM_OUT) { 		if (!(ifp->if_capabilities& IFCAP_CSUM_UDPv4) || 		    ifp->if_bridge != NULL) { 			in_delayed_cksum(m0); 			m0->m_pkthdr.csum&= ~M_UDPV4_CSUM_OUT;
comment|/* Clear */
argument|} 	}  	if (ntohs(ip->ip_len)<= ifp->if_mtu) { 		if ((ifp->if_capabilities& IFCAP_CSUM_IPv4)&& 		    ifp->if_bridge == NULL) { 			m0->m_pkthdr.csum |= M_IPV4_CSUM_OUT; 			ipstat.ips_outhwcsum++; 		} else { 			ip->ip_sum =
literal|0
argument|; 			ip->ip_sum = in_cksum(m0, ip->ip_hl<<
literal|2
argument|); 		}
comment|/* Update relevant hardware checksum stats for TCP/UDP */
argument|if (m0->m_pkthdr.csum& M_TCPV4_CSUM_OUT) 			tcpstat.tcps_outhwcsum++; 		else if (m0->m_pkthdr.csum& M_UDPV4_CSUM_OUT) 			udpstat.udps_outhwcsum++; 		error = (*ifp->if_output)(ifp, m0, sintosa(dst), NULL); 		goto done; 	}
endif|#
directive|endif
comment|/* 	 * Too large for interface; fragment if possible. 	 * Must be able to put at least 8 bytes per fragment. 	 */
argument|if (ip->ip_off& htons(IP_DF)) { 		ipstat.ips_cantfrag++; 		if (r->rt != PF_DUPTO) {
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* icmp_error() expects host byte ordering */
argument|NTOHS(ip->ip_len); 			NTOHS(ip->ip_off); 			PF_UNLOCK(); 			icmp_error(m0, ICMP_UNREACH, ICMP_UNREACH_NEEDFRAG,
literal|0
argument|, 			    ifp->if_mtu); 			PF_LOCK();
else|#
directive|else
argument|icmp_error(m0, ICMP_UNREACH, ICMP_UNREACH_NEEDFRAG,
literal|0
argument|, 			    ifp);
endif|#
directive|endif
argument|goto done; 		} else 			goto bad; 	}  	m1 = m0;
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* 	 * XXX: is cheaper + less error prone than own function 	 */
argument|NTOHS(ip->ip_len); 	NTOHS(ip->ip_off); 	error = ip_fragment(ip,&m0, ifp->if_mtu, ifp->if_hwassist, sw_csum);
else|#
directive|else
argument|error = ip_fragment(m0, ifp, ifp->if_mtu);
endif|#
directive|endif
argument|if (error) {
ifndef|#
directive|ifndef
name|__FreeBSD__
comment|/* ip_fragment does not do m_freem() on FreeBSD */
argument|m0 = NULL;
endif|#
directive|endif
argument|goto bad; 	}  	for (m0 = m1; m0; m0 = m1) { 		m1 = m0->m_nextpkt; 		m0->m_nextpkt =
literal|0
argument|;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|if (error ==
literal|0
argument|) { 			PF_UNLOCK(); 			error = (*ifp->if_output)(ifp, m0, sintosa(dst), 			    NULL); 			PF_LOCK(); 		} else
else|#
directive|else
argument|if (error ==
literal|0
argument|) 			error = (*ifp->if_output)(ifp, m0, sintosa(dst), 			    NULL); 		else
endif|#
directive|endif
argument|m_freem(m0); 	}  	if (error ==
literal|0
argument|) 		ipstat.ips_fragmented++;  done: 	if (r->rt != PF_DUPTO) 		*m = NULL; 	if (ro ==&iproute&& ro->ro_rt) 		RTFREE(ro->ro_rt); 	return;  bad: 	m_freem(m0); 	goto done; }
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|void pf_route6(struct mbuf **m, struct pf_rule *r, int dir, struct ifnet *oifp,     struct pf_state *s) { 	struct mbuf		*m0; 	struct m_tag		*mtag; 	struct route_in6	 ip6route; 	struct route_in6	*ro; 	struct sockaddr_in6	*dst; 	struct ip6_hdr		*ip6; 	struct ifnet		*ifp = NULL; 	struct pf_addr		 naddr; 	struct pf_src_node	*sn = NULL; 	int			 error =
literal|0
argument|;  	if (m == NULL || *m == NULL || r == NULL || 	    (dir != PF_IN&& dir != PF_OUT) || oifp == NULL) 		panic(
literal|"pf_route6: invalid parameters"
argument|);  	if ((mtag = m_tag_find(*m, PACKET_TAG_PF_ROUTED, NULL)) == NULL) { 		if ((mtag = m_tag_get(PACKET_TAG_PF_ROUTED,
literal|1
argument|, M_NOWAIT)) == 		    NULL) { 			m0 = *m; 			*m = NULL; 			goto bad; 		} 		*(char *)(mtag +
literal|1
argument|) =
literal|1
argument|; 		m_tag_prepend(*m, mtag); 	} else { 		if (*(char *)(mtag +
literal|1
argument|)>
literal|3
argument|) { 			m0 = *m; 			*m = NULL; 			goto bad; 		} 		(*(char *)(mtag +
literal|1
argument|))++; 	}  	if (r->rt == PF_DUPTO) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|if ((m0 = m_dup(*m, M_DONTWAIT)) == NULL)
else|#
directive|else
argument|if ((m0 = m_copym2(*m,
literal|0
argument|, M_COPYALL, M_NOWAIT)) == NULL)
endif|#
directive|endif
argument|return; 	} else { 		if ((r->rt == PF_REPLYTO) == (r->direction == dir)) 			return; 		m0 = *m; 	}  	if (m0->m_len< sizeof(struct ip6_hdr)) { 		DPFPRINTF(PF_DEBUG_URGENT, 		    (
literal|"pf_route6: m0->m_len< sizeof(struct ip6_hdr)\n"
argument|)); 		goto bad; 	} 	ip6 = mtod(m0, struct ip6_hdr *);  	ro =&ip6route; 	bzero((caddr_t)ro, sizeof(*ro)); 	dst = (struct sockaddr_in6 *)&ro->ro_dst; 	dst->sin6_family = AF_INET6; 	dst->sin6_len = sizeof(*dst); 	dst->sin6_addr = ip6->ip6_dst;
comment|/* Cheat. */
argument|if (r->rt == PF_FASTROUTE) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|m0->m_flags |= M_SKIP_FIREWALL; 		PF_UNLOCK(); 		ip6_output(m0, NULL, NULL,
literal|0
argument|, NULL, NULL, NULL); 		PF_LOCK();
else|#
directive|else
argument|mtag = m_tag_get(PACKET_TAG_PF_GENERATED,
literal|0
argument|, M_NOWAIT); 		if (mtag == NULL) 			goto bad; 		m_tag_prepend(m0, mtag); 		ip6_output(m0, NULL, NULL,
literal|0
argument|, NULL, NULL);
endif|#
directive|endif
argument|return; 	}  	if (TAILQ_EMPTY(&r->rpool.list)) { 		DPFPRINTF(PF_DEBUG_URGENT, 		    (
literal|"pf_route6: TAILQ_EMPTY(&r->rpool.list)\n"
argument|)); 		goto bad; 	} 	if (s == NULL) { 		pf_map_addr(AF_INET6, r, (struct pf_addr *)&ip6->ip6_src,&naddr, NULL,&sn); 		if (!PF_AZERO(&naddr, AF_INET6)) 			PF_ACPY((struct pf_addr *)&dst->sin6_addr,&naddr, AF_INET6); 		ifp = r->rpool.cur->kif ? r->rpool.cur->kif->pfik_ifp : NULL; 	} else { 		if (!PF_AZERO(&s->rt_addr, AF_INET6)) 			PF_ACPY((struct pf_addr *)&dst->sin6_addr,&s->rt_addr, AF_INET6); 		ifp = s->rt_kif ? s->rt_kif->pfik_ifp : NULL; 	} 	if (ifp == NULL) 		goto bad;  	if (oifp != ifp) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK(); 		if (pf_test6(PF_OUT, ifp,&m0, NULL, NULL) != PF_PASS) { 			PF_LOCK(); 			goto bad; 		} else if (m0 == NULL) { 			PF_LOCK(); 			goto done; 		} 		PF_LOCK();
else|#
directive|else
argument|if (pf_test6(PF_OUT, ifp,&m0, NULL) != PF_PASS) 			goto bad; 		else if (m0 == NULL) 			goto done;
endif|#
directive|endif
argument|if (m0->m_len< sizeof(struct ip6_hdr)) { 			DPFPRINTF(PF_DEBUG_URGENT, 			    (
literal|"pf_route6: m0->m_len< sizeof(struct ip6_hdr)\n"
argument|)); 			goto bad; 		} 		ip6 = mtod(m0, struct ip6_hdr *); 	}
comment|/* 	 * If the packet is too large for the outgoing interface, 	 * send back an icmp6 error. 	 */
argument|if (IN6_IS_ADDR_LINKLOCAL(&dst->sin6_addr)) 		dst->sin6_addr.s6_addr16[
literal|1
argument|] = htons(ifp->if_index); 	if ((u_long)m0->m_pkthdr.len<= ifp->if_mtu) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
endif|#
directive|endif
argument|error = nd6_output(ifp, ifp, m0, dst, NULL);
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_LOCK();
endif|#
directive|endif
argument|} else { 		in6_ifstat_inc(ifp, ifs6_in_toobig);
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|if (r->rt != PF_DUPTO) { 			PF_UNLOCK(); 			icmp6_error(m0, ICMP6_PACKET_TOO_BIG,
literal|0
argument|, ifp->if_mtu); 			PF_LOCK(); 		 } else
else|#
directive|else
argument|if (r->rt != PF_DUPTO) 			icmp6_error(m0, ICMP6_PACKET_TOO_BIG,
literal|0
argument|, ifp->if_mtu); 		else
endif|#
directive|endif
argument|goto bad; 	}  done: 	if (r->rt != PF_DUPTO) 		*m = NULL; 	return;  bad: 	m_freem(m0); 	goto done; }
endif|#
directive|endif
comment|/* INET6 */
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/*  * FreeBSD supports cksum offloads for the following drivers.  *  em(4), fxp(4), ixgb(4), lge(4), ndis(4), nge(4), re(4),  *   ti(4), txp(4), xl(4)  *  * CSUM_DATA_VALID | CSUM_PSEUDO_HDR :  *  network driver performed cksum including pseudo header, need to verify  *   csum_data  * CSUM_DATA_VALID :  *  network driver performed cksum, needs to additional pseudo header  *  cksum computation with partial csum_data(i.e. lack of H/W support for  *  pseudo header, for instance hme(4), sk(4) and possibly gem(4))  *  * After validating the cksum of packet, set both flag CSUM_DATA_VALID and  * CSUM_PSEUDO_HDR in order to avoid recomputation of the cksum in upper  * TCP/UDP layer.  * Also, set csum_data to 0xffff to force cksum validation.  */
argument|int pf_check_proto_cksum(struct mbuf *m, int off, int len, u_int8_t p, sa_family_t af) { 	u_int16_t sum =
literal|0
argument|; 	int hw_assist =
literal|0
argument|; 	struct ip *ip;  	if (off< sizeof(struct ip) || len< sizeof(struct udphdr)) 		return (
literal|1
argument|); 	if (m->m_pkthdr.len< off + len) 		return (
literal|1
argument|);  	switch (p) { 	case IPPROTO_TCP: 		if (m->m_pkthdr.csum_flags& CSUM_DATA_VALID) { 			if (m->m_pkthdr.csum_flags& CSUM_PSEUDO_HDR) { 				sum = m->m_pkthdr.csum_data; 			} else { 				ip = mtod(m, struct ip *);	 				sum = in_pseudo(ip->ip_src.s_addr, 					ip->ip_dst.s_addr, htonl((u_short)len +  					m->m_pkthdr.csum_data + IPPROTO_TCP)); 			} 			sum ^=
literal|0xffff
argument|; 			++hw_assist; 		} 		break; 	case IPPROTO_UDP: 		if (m->m_pkthdr.csum_flags& CSUM_DATA_VALID) { 			if (m->m_pkthdr.csum_flags& CSUM_PSEUDO_HDR) { 				sum = m->m_pkthdr.csum_data; 			} else { 				ip = mtod(m, struct ip *);	 				sum = in_pseudo(ip->ip_src.s_addr, 					ip->ip_dst.s_addr, htonl((u_short)len + 					m->m_pkthdr.csum_data + IPPROTO_UDP)); 			} 			sum ^=
literal|0xffff
argument|; 			++hw_assist;                 } 		break; 	case IPPROTO_ICMP:
ifdef|#
directive|ifdef
name|INET6
argument|case IPPROTO_ICMPV6:
endif|#
directive|endif
comment|/* INET6 */
argument|break; 	default: 		return (
literal|1
argument|); 	}  	if (!hw_assist) { 		switch (af) { 		case AF_INET: 			if (p == IPPROTO_ICMP) { 				if (m->m_len< off) 					return (
literal|1
argument|); 				m->m_data += off; 				m->m_len -= off; 				sum = in_cksum(m, len); 				m->m_data -= off; 				m->m_len += off; 			} else { 				if (m->m_len< sizeof(struct ip)) 					return (
literal|1
argument|); 				sum = in4_cksum(m, p, off, len); 			} 			break;
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 			if (m->m_len< sizeof(struct ip6_hdr)) 				return (
literal|1
argument|); 			sum = in6_cksum(m, p, off, len); 			break;
endif|#
directive|endif
comment|/* INET6 */
argument|default: 			return (
literal|1
argument|); 		} 	} 	if (sum) { 		switch (p) { 		case IPPROTO_TCP: 			tcpstat.tcps_rcvbadsum++; 			break; 		case IPPROTO_UDP: 			udpstat.udps_badsum++; 			break; 		case IPPROTO_ICMP: 			icmpstat.icps_checksum++; 			break;
ifdef|#
directive|ifdef
name|INET6
argument|case IPPROTO_ICMPV6: 			icmp6stat.icp6s_checksum++; 			break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 		return (
literal|1
argument|); 	} else { 		if (p == IPPROTO_TCP || p == IPPROTO_UDP) { 			m->m_pkthdr.csum_flags |= 			    (CSUM_DATA_VALID | CSUM_PSEUDO_HDR); 			m->m_pkthdr.csum_data =
literal|0xffff
argument|; 		} 	} 	return (
literal|0
argument|); }
else|#
directive|else
comment|/*  * check protocol (tcp/udp/icmp/icmp6) checksum and set mbuf flag  *   off is the offset where the protocol header starts  *   len is the total length of protocol header plus payload  * returns 0 when the checksum is valid, otherwise returns 1.  */
argument|int pf_check_proto_cksum(struct mbuf *m, int off, int len, u_int8_t p,     sa_family_t af) { 	u_int16_t flag_ok, flag_bad; 	u_int16_t sum;  	switch (p) { 	case IPPROTO_TCP: 		flag_ok = M_TCP_CSUM_IN_OK; 		flag_bad = M_TCP_CSUM_IN_BAD; 		break; 	case IPPROTO_UDP: 		flag_ok = M_UDP_CSUM_IN_OK; 		flag_bad = M_UDP_CSUM_IN_BAD; 		break; 	case IPPROTO_ICMP:
ifdef|#
directive|ifdef
name|INET6
argument|case IPPROTO_ICMPV6:
endif|#
directive|endif
comment|/* INET6 */
argument|flag_ok = flag_bad =
literal|0
argument|; 		break; 	default: 		return (
literal|1
argument|); 	} 	if (m->m_pkthdr.csum& flag_ok) 		return (
literal|0
argument|); 	if (m->m_pkthdr.csum& flag_bad) 		return (
literal|1
argument|); 	if (off< sizeof(struct ip) || len< sizeof(struct udphdr)) 		return (
literal|1
argument|); 	if (m->m_pkthdr.len< off + len) 		return (
literal|1
argument|); 	switch (af) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		if (p == IPPROTO_ICMP) { 			if (m->m_len< off) 				return (
literal|1
argument|); 			m->m_data += off; 			m->m_len -= off; 			sum = in_cksum(m, len); 			m->m_data -= off; 			m->m_len += off; 		} else { 			if (m->m_len< sizeof(struct ip)) 				return (
literal|1
argument|); 			sum = in4_cksum(m, p, off, len); 		} 		break;
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|case AF_INET6: 		if (m->m_len< sizeof(struct ip6_hdr)) 			return (
literal|1
argument|); 		sum = in6_cksum(m, p, off, len); 		break;
endif|#
directive|endif
comment|/* INET6 */
argument|default: 		return (
literal|1
argument|); 	} 	if (sum) { 		m->m_pkthdr.csum |= flag_bad; 		switch (p) { 		case IPPROTO_TCP: 			tcpstat.tcps_rcvbadsum++; 			break; 		case IPPROTO_UDP: 			udpstat.udps_badsum++; 			break; 		case IPPROTO_ICMP: 			icmpstat.icps_checksum++; 			break;
ifdef|#
directive|ifdef
name|INET6
argument|case IPPROTO_ICMPV6: 			icmp6stat.icp6s_checksum++; 			break;
endif|#
directive|endif
comment|/* INET6 */
argument|} 		return (
literal|1
argument|); 	} 	m->m_pkthdr.csum |= flag_ok; 	return (
literal|0
argument|); }
endif|#
directive|endif
argument|static int pf_add_mbuf_tag(struct mbuf *m, u_int tag) { 	struct m_tag *mtag;  	if (m_tag_find(m, tag, NULL) != NULL) 		return (
literal|0
argument|); 	mtag = m_tag_get(tag,
literal|0
argument|, M_NOWAIT); 	if (mtag == NULL) 		return (
literal|1
argument|); 	m_tag_prepend(m, mtag); 	return (
literal|0
argument|); }
ifdef|#
directive|ifdef
name|INET
argument|int
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_test(int dir, struct ifnet *ifp, struct mbuf **m0,     struct ether_header *eh, struct inpcb *inp)
else|#
directive|else
argument|pf_test(int dir, struct ifnet *ifp, struct mbuf **m0,     struct ether_header *eh)
endif|#
directive|endif
argument|{ 	struct pfi_kif		*kif; 	u_short			 action, reason =
literal|0
argument|, log =
literal|0
argument|; 	struct mbuf		*m = *m0; 	struct ip		*h = NULL;
comment|/* make the compiler happy */
argument|struct pf_rule		*a = NULL, *r =&pf_default_rule, *tr, *nr; 	struct pf_state		*s = NULL; 	struct pf_ruleset	*ruleset = NULL; 	struct pf_pdesc		 pd; 	int			 off, dirndx, pqid =
literal|0
argument|;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_LOCK();
endif|#
directive|endif
argument|if (!pf_status.running ||
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|(m->m_flags& M_SKIP_FIREWALL)) { 		PF_UNLOCK();
else|#
directive|else
argument|(m_tag_find(m, PACKET_TAG_PF_GENERATED, NULL) != NULL)) {
endif|#
directive|endif
argument|return (PF_PASS); 	}
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* XXX_IMPORT: later */
else|#
directive|else
argument|if (ifp->if_type == IFT_CARP&& ifp->if_carpdev) 		ifp = ifp->if_carpdev;
endif|#
directive|endif
argument|kif = pfi_index2kif[ifp->if_index]; 	if (kif == NULL) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
endif|#
directive|endif
argument|DPFPRINTF(PF_DEBUG_URGENT, 		    (
literal|"pf_test: kif == NULL, if_xname %s\n"
argument|, ifp->if_xname)); 		return (PF_DROP); 	} 	if (kif->pfik_flags& PFI_IFLAG_SKIP) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
endif|#
directive|endif
argument|return (PF_PASS); 	}
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|M_ASSERTPKTHDR(m);
else|#
directive|else
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|if ((m->m_flags& M_PKTHDR) ==
literal|0
argument|) 		panic(
literal|"non-M_PKTHDR is passed to pf_test"
argument|);
endif|#
directive|endif
comment|/* DIAGNOSTIC */
endif|#
directive|endif
comment|/* __FreeBSD__ */
argument|memset(&pd,
literal|0
argument|, sizeof(pd)); 	if (m->m_pkthdr.len< (int)sizeof(*h)) { 		action = PF_DROP; 		REASON_SET(&reason, PFRES_SHORT); 		log =
literal|1
argument|; 		goto done; 	}
comment|/* We do IP header normalization and packet reassembly here */
argument|if (pf_normalize_ip(m0, dir, kif,&reason,&pd) != PF_PASS) { 		action = PF_DROP; 		goto done; 	} 	m = *m0; 	h = mtod(m, struct ip *);  	off = h->ip_hl<<
literal|2
argument|; 	if (off< (int)sizeof(*h)) { 		action = PF_DROP; 		REASON_SET(&reason, PFRES_SHORT); 		log =
literal|1
argument|; 		goto done; 	}  	pd.src = (struct pf_addr *)&h->ip_src; 	pd.dst = (struct pf_addr *)&h->ip_dst; 	PF_ACPY(&pd.baddr, dir == PF_OUT ? pd.src : pd.dst, AF_INET); 	pd.ip_sum =&h->ip_sum; 	pd.proto = h->ip_p; 	pd.af = AF_INET; 	pd.tos = h->ip_tos; 	pd.tot_len = ntohs(h->ip_len); 	pd.eh = eh;
comment|/* handle fragments that didn't get reassembled by normalization */
argument|if (h->ip_off& htons(IP_MF | IP_OFFMASK)) { 		action = pf_test_fragment(&r, dir, kif, m, h,&pd,&a,&ruleset); 		goto done; 	}  	switch (h->ip_p) {  	case IPPROTO_TCP: { 		struct tcphdr	th;  		pd.hdr.tcp =&th; 		if (!pf_pull_hdr(m, off,&th, sizeof(th),&action,&reason, AF_INET)) { 			log = action != PF_PASS; 			goto done; 		} 		if (dir == PF_IN&& pf_check_proto_cksum(m, off, 		    ntohs(h->ip_len) - off, IPPROTO_TCP, AF_INET)) { 			action = PF_DROP; 			goto done; 		} 		pd.p_len = pd.tot_len - off - (th.th_off<<
literal|2
argument|); 		if ((th.th_flags& TH_ACK)&& pd.p_len ==
literal|0
argument|) 			pqid =
literal|1
argument|; 		action = pf_normalize_tcp(dir, kif, m,
literal|0
argument|, off, h,&pd); 		if (action == PF_DROP) 			goto done; 		action = pf_test_state_tcp(&s, dir, kif, m, off, h,&pd,&reason); 		if (action == PF_PASS) {
if|#
directive|if
name|NPFSYNC
argument|pfsync_update_state(s);
endif|#
directive|endif
comment|/* NPFSYNC */
argument|r = s->rule.ptr; 			a = s->anchor.ptr; 			log = s->log; 		} else if (s == NULL)
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|action = pf_test_tcp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset, NULL, inp);
else|#
directive|else
argument|action = pf_test_tcp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset,&ipintrq);
endif|#
directive|endif
argument|break; 	}  	case IPPROTO_UDP: { 		struct udphdr	uh;  		pd.hdr.udp =&uh; 		if (!pf_pull_hdr(m, off,&uh, sizeof(uh),&action,&reason, AF_INET)) { 			log = action != PF_PASS; 			goto done; 		} 		if (dir == PF_IN&& uh.uh_sum&& pf_check_proto_cksum(m, 		    off, ntohs(h->ip_len) - off, IPPROTO_UDP, AF_INET)) { 			action = PF_DROP; 			goto done; 		} 		if (uh.uh_dport ==
literal|0
argument||| 		    ntohs(uh.uh_ulen)> m->m_pkthdr.len - off || 		    ntohs(uh.uh_ulen)< sizeof(struct udphdr)) { 			action = PF_DROP; 			goto done; 		} 		action = pf_test_state_udp(&s, dir, kif, m, off, h,&pd); 		if (action == PF_PASS) {
if|#
directive|if
name|NPFSYNC
argument|pfsync_update_state(s);
endif|#
directive|endif
comment|/* NPFSYNC */
argument|r = s->rule.ptr; 			a = s->anchor.ptr; 			log = s->log; 		} else if (s == NULL)
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|action = pf_test_udp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset, NULL, inp);
else|#
directive|else
argument|action = pf_test_udp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset,&ipintrq);
endif|#
directive|endif
argument|break; 	}  	case IPPROTO_ICMP: { 		struct icmp	ih;  		pd.hdr.icmp =&ih; 		if (!pf_pull_hdr(m, off,&ih, ICMP_MINLEN,&action,&reason, AF_INET)) { 			log = action != PF_PASS; 			goto done; 		} 		if (dir == PF_IN&& pf_check_proto_cksum(m, off, 		    ntohs(h->ip_len) - off, IPPROTO_ICMP, AF_INET)) { 			action = PF_DROP; 			goto done; 		} 		action = pf_test_state_icmp(&s, dir, kif, m, off, h,&pd,&reason); 		if (action == PF_PASS) {
if|#
directive|if
name|NPFSYNC
argument|pfsync_update_state(s);
endif|#
directive|endif
comment|/* NPFSYNC */
argument|r = s->rule.ptr; 			a = s->anchor.ptr; 			log = s->log; 		} else if (s == NULL)
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|action = pf_test_icmp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset, NULL);
else|#
directive|else
argument|action = pf_test_icmp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset,&ipintrq);
endif|#
directive|endif
argument|break; 	}  	default: 		action = pf_test_state_other(&s, dir, kif,&pd); 		if (action == PF_PASS) {
if|#
directive|if
name|NPFSYNC
argument|pfsync_update_state(s);
endif|#
directive|endif
comment|/* NPFSYNC */
argument|r = s->rule.ptr; 			a = s->anchor.ptr; 			log = s->log; 		} else if (s == NULL)
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|action = pf_test_other(&r,&s, dir, kif, m, off, h,&pd,&a,&ruleset, NULL);
else|#
directive|else
argument|action = pf_test_other(&r,&s, dir, kif, m, off, h,&pd,&a,&ruleset,&ipintrq);
endif|#
directive|endif
argument|break; 	}  done: 	if (action == PF_PASS&& h->ip_hl>
literal|5
argument|&& 	    !((s&& s->allow_opts) || r->allow_opts)) { 		action = PF_DROP; 		REASON_SET(&reason, PFRES_IPOPTIONS); 		log =
literal|1
argument|; 		DPFPRINTF(PF_DEBUG_MISC, 		    (
literal|"pf: dropping packet with ip options\n"
argument|)); 	}  	if (s&& s->tag) 		pf_tag_packet(m, pf_get_tag(m), s->tag);
ifdef|#
directive|ifdef
name|ALTQ
argument|if (action == PF_PASS&& r->qid) { 		struct m_tag	*mtag; 		struct altq_tag	*atag;  		mtag = m_tag_get(PACKET_TAG_PF_QID, sizeof(*atag), M_NOWAIT); 		if (mtag != NULL) { 			atag = (struct altq_tag *)(mtag +
literal|1
argument|); 			if (pqid || pd.tos == IPTOS_LOWDELAY) 				atag->qid = r->pqid; 			else 				atag->qid = r->qid;
comment|/* add hints for ecn */
argument|atag->af = AF_INET; 			atag->hdr = h; 			m_tag_prepend(m, mtag); 		} 	}
endif|#
directive|endif
comment|/* ALTQ */
comment|/* 	 * connections redirected to loopback should not match sockets 	 * bound specifically to loopback due to security implications, 	 * see tcp_input() and in_pcblookup_listen(). 	 */
argument|if (dir == PF_IN&& action == PF_PASS&& (pd.proto == IPPROTO_TCP || 	    pd.proto == IPPROTO_UDP)&& s != NULL&& s->nat_rule.ptr != NULL&& 	    (s->nat_rule.ptr->action == PF_RDR || 	    s->nat_rule.ptr->action == PF_BINAT)&& 	    (ntohl(pd.dst->v4.s_addr)>> IN_CLASSA_NSHIFT) == IN_LOOPBACKNET&& 	    pf_add_mbuf_tag(m, PACKET_TAG_PF_TRANSLATE_LOCALHOST)) { 		action = PF_DROP; 		REASON_SET(&reason, PFRES_MEMORY); 	}  	if (log) 		PFLOG_PACKET(kif, h, m, AF_INET, dir, reason, r, a, ruleset);  	kif->pfik_bytes[
literal|0
argument|][dir == PF_OUT][action != PF_PASS] += pd.tot_len; 	kif->pfik_packets[
literal|0
argument|][dir == PF_OUT][action != PF_PASS]++;  	if (action == PF_PASS || r->action == PF_DROP) { 		r->packets++; 		r->bytes += pd.tot_len; 		if (a != NULL) { 			a->packets++; 			a->bytes += pd.tot_len; 		} 		if (s != NULL) { 			dirndx = (dir == s->direction) ?
literal|0
argument|:
literal|1
argument|; 			s->packets[dirndx]++; 			s->bytes[dirndx] += pd.tot_len; 			if (s->nat_rule.ptr != NULL) { 				s->nat_rule.ptr->packets++; 				s->nat_rule.ptr->bytes += pd.tot_len; 			} 			if (s->src_node != NULL) { 				s->src_node->packets++; 				s->src_node->bytes += pd.tot_len; 			} 			if (s->nat_src_node != NULL) { 				s->nat_src_node->packets++; 				s->nat_src_node->bytes += pd.tot_len; 			} 		} 		tr = r; 		nr = (s != NULL) ? s->nat_rule.ptr : pd.nat_rule; 		if (nr != NULL) { 			struct pf_addr *x;
comment|/* 			 * XXX: we need to make sure that the addresses 			 * passed to pfr_update_stats() are the same than 			 * the addresses used during matching (pfr_match) 			 */
argument|if (r ==&pf_default_rule) { 				tr = nr; 				x = (s == NULL || s->direction == dir) ?&pd.baddr :&pd.naddr; 			} else 				x = (s == NULL || s->direction == dir) ?&pd.naddr :&pd.baddr; 			if (x ==&pd.baddr || s == NULL) {
comment|/* we need to change the address */
argument|if (dir == PF_OUT) 					pd.src = x; 				else 					pd.dst = x; 			} 		} 		if (tr->src.addr.type == PF_ADDR_TABLE) 			pfr_update_stats(tr->src.addr.p.tbl, (s == NULL || 			    s->direction == dir) ? pd.src : pd.dst, pd.af, 			    pd.tot_len, dir == PF_OUT, r->action == PF_PASS, 			    tr->src.neg); 		if (tr->dst.addr.type == PF_ADDR_TABLE) 			pfr_update_stats(tr->dst.addr.p.tbl, (s == NULL || 			    s->direction == dir) ? pd.dst : pd.src, pd.af, 			    pd.tot_len, dir == PF_OUT, r->action == PF_PASS, 			    tr->dst.neg); 	}   	if (action == PF_SYNPROXY_DROP) { 		m_freem(*m0); 		*m0 = NULL; 		action = PF_PASS; 	} else if (r->rt)
comment|/* pf_route can free the mbuf causing *m0 to become NULL */
argument|pf_route(m0, r, dir, ifp, s);
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
endif|#
directive|endif
argument|return (action); }
endif|#
directive|endif
comment|/* INET */
ifdef|#
directive|ifdef
name|INET6
argument|int
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|pf_test6(int dir, struct ifnet *ifp, struct mbuf **m0,     struct ether_header *eh, struct inpcb *inp)
else|#
directive|else
argument|pf_test6(int dir, struct ifnet *ifp, struct mbuf **m0,     struct ether_header *eh)
endif|#
directive|endif
argument|{ 	struct pfi_kif		*kif; 	u_short			 action, reason =
literal|0
argument|, log =
literal|0
argument|; 	struct mbuf		*m = *m0; 	struct ip6_hdr		*h = NULL;
comment|/* make the compiler happy */
argument|struct pf_rule		*a = NULL, *r =&pf_default_rule, *tr, *nr; 	struct pf_state		*s = NULL; 	struct pf_ruleset	*ruleset = NULL; 	struct pf_pdesc		 pd; 	int			 off, terminal =
literal|0
argument|, dirndx;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_LOCK();
endif|#
directive|endif
argument|if (!pf_status.running ||
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|(m->m_flags& M_SKIP_FIREWALL)) { 		PF_UNLOCK();
else|#
directive|else
argument|(m_tag_find(m, PACKET_TAG_PF_GENERATED, NULL) != NULL)) {
endif|#
directive|endif
argument|return (PF_PASS); 	}
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* XXX_IMPORT: later */
else|#
directive|else
argument|if (ifp->if_type == IFT_CARP&& ifp->if_carpdev) 		ifp = ifp->if_carpdev;
endif|#
directive|endif
argument|kif = pfi_index2kif[ifp->if_index]; 	if (kif == NULL) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
endif|#
directive|endif
argument|DPFPRINTF(PF_DEBUG_URGENT, 		    (
literal|"pf_test6: kif == NULL, if_xname %s\n"
argument|, ifp->if_xname)); 		return (PF_DROP); 	} 	if (kif->pfik_flags& PFI_IFLAG_SKIP) {
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
endif|#
directive|endif
argument|return (PF_PASS); 	}
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|M_ASSERTPKTHDR(m);
else|#
directive|else
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|if ((m->m_flags& M_PKTHDR) ==
literal|0
argument|) 		panic(
literal|"non-M_PKTHDR is passed to pf_test6"
argument|);
endif|#
directive|endif
comment|/* DIAGNOSTIC */
endif|#
directive|endif
argument|memset(&pd,
literal|0
argument|, sizeof(pd)); 	if (m->m_pkthdr.len< (int)sizeof(*h)) { 		action = PF_DROP; 		REASON_SET(&reason, PFRES_SHORT); 		log =
literal|1
argument|; 		goto done; 	}
comment|/* We do IP header normalization and packet reassembly here */
argument|if (pf_normalize_ip6(m0, dir, kif,&reason,&pd) != PF_PASS) { 		action = PF_DROP; 		goto done; 	} 	m = *m0; 	h = mtod(m, struct ip6_hdr *);  	pd.src = (struct pf_addr *)&h->ip6_src; 	pd.dst = (struct pf_addr *)&h->ip6_dst; 	PF_ACPY(&pd.baddr, dir == PF_OUT ? pd.src : pd.dst, AF_INET6); 	pd.ip_sum = NULL; 	pd.af = AF_INET6; 	pd.tos =
literal|0
argument|; 	pd.tot_len = ntohs(h->ip6_plen) + sizeof(struct ip6_hdr); 	pd.eh = eh;  	off = ((caddr_t)h - m->m_data) + sizeof(struct ip6_hdr); 	pd.proto = h->ip6_nxt; 	do { 		switch (pd.proto) { 		case IPPROTO_FRAGMENT: 			action = pf_test_fragment(&r, dir, kif, m, h,&pd,&a,&ruleset); 			if (action == PF_DROP) 				REASON_SET(&reason, PFRES_FRAG); 			goto done; 		case IPPROTO_AH: 		case IPPROTO_HOPOPTS: 		case IPPROTO_ROUTING: 		case IPPROTO_DSTOPTS: {
comment|/* get next header and header length */
argument|struct ip6_ext	opt6;  			if (!pf_pull_hdr(m, off,&opt6, sizeof(opt6), 			    NULL,&reason, pd.af)) { 				DPFPRINTF(PF_DEBUG_MISC, 				    (
literal|"pf: IPv6 short opt\n"
argument|)); 				action = PF_DROP; 				log =
literal|1
argument|; 				goto done; 			} 			if (pd.proto == IPPROTO_AH) 				off += (opt6.ip6e_len +
literal|2
argument|) *
literal|4
argument|; 			else 				off += (opt6.ip6e_len +
literal|1
argument|) *
literal|8
argument|; 			pd.proto = opt6.ip6e_nxt;
comment|/* goto the next header */
argument|break; 		} 		default: 			terminal++; 			break; 		} 	} while (!terminal);  	switch (pd.proto) {  	case IPPROTO_TCP: { 		struct tcphdr	th;  		pd.hdr.tcp =&th; 		if (!pf_pull_hdr(m, off,&th, sizeof(th),&action,&reason, AF_INET6)) { 			log = action != PF_PASS; 			goto done; 		} 		if (dir == PF_IN&& pf_check_proto_cksum(m, off, 		    ntohs(h->ip6_plen) - (off - sizeof(struct ip6_hdr)), 		    IPPROTO_TCP, AF_INET6)) { 			action = PF_DROP; 			REASON_SET(&reason, PFRES_PROTCKSUM); 			goto done; 		} 		pd.p_len = pd.tot_len - off - (th.th_off<<
literal|2
argument|); 		action = pf_normalize_tcp(dir, kif, m,
literal|0
argument|, off, h,&pd); 		if (action == PF_DROP) 			goto done; 		action = pf_test_state_tcp(&s, dir, kif, m, off, h,&pd,&reason); 		if (action == PF_PASS) {
if|#
directive|if
name|NPFSYNC
argument|pfsync_update_state(s);
endif|#
directive|endif
comment|/* NPFSYNC */
argument|r = s->rule.ptr; 			a = s->anchor.ptr; 			log = s->log; 		} else if (s == NULL)
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|action = pf_test_tcp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset, NULL, inp);
else|#
directive|else
argument|action = pf_test_tcp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset,&ip6intrq);
endif|#
directive|endif
argument|break; 	}  	case IPPROTO_UDP: { 		struct udphdr	uh;  		pd.hdr.udp =&uh; 		if (!pf_pull_hdr(m, off,&uh, sizeof(uh),&action,&reason, AF_INET6)) { 			log = action != PF_PASS; 			goto done; 		} 		if (dir == PF_IN&& uh.uh_sum&& pf_check_proto_cksum(m, 		    off, ntohs(h->ip6_plen) - (off - sizeof(struct ip6_hdr)), 		    IPPROTO_UDP, AF_INET6)) { 			action = PF_DROP; 			REASON_SET(&reason, PFRES_PROTCKSUM); 			goto done; 		} 		if (uh.uh_dport ==
literal|0
argument||| 		    ntohs(uh.uh_ulen)> m->m_pkthdr.len - off || 		    ntohs(uh.uh_ulen)< sizeof(struct udphdr)) { 			action = PF_DROP; 			goto done; 		} 		action = pf_test_state_udp(&s, dir, kif, m, off, h,&pd); 		if (action == PF_PASS) {
if|#
directive|if
name|NPFSYNC
argument|pfsync_update_state(s);
endif|#
directive|endif
comment|/* NPFSYNC */
argument|r = s->rule.ptr; 			a = s->anchor.ptr; 			log = s->log; 		} else if (s == NULL)
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|action = pf_test_udp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset, NULL, inp);
else|#
directive|else
argument|action = pf_test_udp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset,&ip6intrq);
endif|#
directive|endif
argument|break; 	}  	case IPPROTO_ICMPV6: { 		struct icmp6_hdr	ih;  		pd.hdr.icmp6 =&ih; 		if (!pf_pull_hdr(m, off,&ih, sizeof(ih),&action,&reason, AF_INET6)) { 			log = action != PF_PASS; 			goto done; 		} 		if (dir == PF_IN&& pf_check_proto_cksum(m, off, 		    ntohs(h->ip6_plen) - (off - sizeof(struct ip6_hdr)), 		    IPPROTO_ICMPV6, AF_INET6)) { 			action = PF_DROP; 			REASON_SET(&reason, PFRES_PROTCKSUM); 			goto done; 		} 		action = pf_test_state_icmp(&s, dir, kif, 		    m, off, h,&pd,&reason); 		if (action == PF_PASS) {
if|#
directive|if
name|NPFSYNC
argument|pfsync_update_state(s);
endif|#
directive|endif
comment|/* NPFSYNC */
argument|r = s->rule.ptr; 			a = s->anchor.ptr; 			log = s->log; 		} else if (s == NULL)
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|action = pf_test_icmp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset, NULL);
else|#
directive|else
argument|action = pf_test_icmp(&r,&s, dir, kif, 			    m, off, h,&pd,&a,&ruleset,&ip6intrq);
endif|#
directive|endif
argument|break; 	}  	default: 		action = pf_test_state_other(&s, dir, kif,&pd); 		if (action == PF_PASS) {
if|#
directive|if
name|NPFSYNC
argument|pfsync_update_state(s);
endif|#
directive|endif
comment|/* NPFSYNC */
argument|r = s->rule.ptr; 			a = s->anchor.ptr; 			log = s->log; 		} else if (s == NULL)
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|action = pf_test_other(&r,&s, dir, kif, m, off, h,&pd,&a,&ruleset, NULL);
else|#
directive|else
argument|action = pf_test_other(&r,&s, dir, kif, m, off, h,&pd,&a,&ruleset,&ip6intrq);
endif|#
directive|endif
argument|break; 	}  done:
comment|/* XXX handle IPv6 options, if not allowed. not implemented. */
argument|if (s&& s->tag) 		pf_tag_packet(m, pf_get_tag(m), s->tag);
ifdef|#
directive|ifdef
name|ALTQ
argument|if (action == PF_PASS&& r->qid) { 		struct m_tag	*mtag; 		struct altq_tag	*atag;  		mtag = m_tag_get(PACKET_TAG_PF_QID, sizeof(*atag), M_NOWAIT); 		if (mtag != NULL) { 			atag = (struct altq_tag *)(mtag +
literal|1
argument|); 			if (pd.tos == IPTOS_LOWDELAY) 				atag->qid = r->pqid; 			else 				atag->qid = r->qid;
comment|/* add hints for ecn */
argument|atag->af = AF_INET6; 			atag->hdr = h; 			m_tag_prepend(m, mtag); 		} 	}
endif|#
directive|endif
comment|/* ALTQ */
argument|if (dir == PF_IN&& action == PF_PASS&& (pd.proto == IPPROTO_TCP || 	    pd.proto == IPPROTO_UDP)&& s != NULL&& s->nat_rule.ptr != NULL&& 	    (s->nat_rule.ptr->action == PF_RDR || 	    s->nat_rule.ptr->action == PF_BINAT)&& 	    IN6_IS_ADDR_LOOPBACK(&pd.dst->v6)&& 	    pf_add_mbuf_tag(m, PACKET_TAG_PF_TRANSLATE_LOCALHOST)) { 		action = PF_DROP; 		REASON_SET(&reason, PFRES_MEMORY); 	}  	if (log) 		PFLOG_PACKET(kif, h, m, AF_INET6, dir, reason, r, a, ruleset);  	kif->pfik_bytes[
literal|1
argument|][dir == PF_OUT][action != PF_PASS] += pd.tot_len; 	kif->pfik_packets[
literal|1
argument|][dir == PF_OUT][action != PF_PASS]++;  	if (action == PF_PASS || r->action == PF_DROP) { 		r->packets++; 		r->bytes += pd.tot_len; 		if (a != NULL) { 			a->packets++; 			a->bytes += pd.tot_len; 		} 		if (s != NULL) { 			dirndx = (dir == s->direction) ?
literal|0
argument|:
literal|1
argument|; 			s->packets[dirndx]++; 			s->bytes[dirndx] += pd.tot_len; 			if (s->nat_rule.ptr != NULL) { 				s->nat_rule.ptr->packets++; 				s->nat_rule.ptr->bytes += pd.tot_len; 			} 			if (s->src_node != NULL) { 				s->src_node->packets++; 				s->src_node->bytes += pd.tot_len; 			} 			if (s->nat_src_node != NULL) { 				s->nat_src_node->packets++; 				s->nat_src_node->bytes += pd.tot_len; 			} 		} 		tr = r; 		nr = (s != NULL) ? s->nat_rule.ptr : pd.nat_rule; 		if (nr != NULL) { 			struct pf_addr *x;
comment|/* 			 * XXX: we need to make sure that the addresses 			 * passed to pfr_update_stats() are the same than 			 * the addresses used during matching (pfr_match) 			 */
argument|if (r ==&pf_default_rule) { 				tr = nr; 				x = (s == NULL || s->direction == dir) ?&pd.baddr :&pd.naddr; 			} else { 				x = (s == NULL || s->direction == dir) ?&pd.naddr :&pd.baddr; 			} 			if (x ==&pd.baddr || s == NULL) { 				if (dir == PF_OUT) 					pd.src = x; 				else 					pd.dst = x; 			} 		} 		if (tr->src.addr.type == PF_ADDR_TABLE) 			pfr_update_stats(tr->src.addr.p.tbl, (s == NULL || 			    s->direction == dir) ? pd.src : pd.dst, pd.af, 			    pd.tot_len, dir == PF_OUT, r->action == PF_PASS, 			    tr->src.neg); 		if (tr->dst.addr.type == PF_ADDR_TABLE) 			pfr_update_stats(tr->dst.addr.p.tbl, (s == NULL || 			    s->direction == dir) ? pd.dst : pd.src, pd.af, 			    pd.tot_len, dir == PF_OUT, r->action == PF_PASS, 			    tr->dst.neg); 	}   	if (action == PF_SYNPROXY_DROP) { 		m_freem(*m0); 		*m0 = NULL; 		action = PF_PASS; 	} else if (r->rt)
comment|/* pf_route6 can free the mbuf causing *m0 to become NULL */
argument|pf_route6(m0, r, dir, ifp, s);
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|PF_UNLOCK();
endif|#
directive|endif
argument|return (action); }
endif|#
directive|endif
comment|/* INET6 */
argument|int pf_check_congestion(struct ifqueue *ifq) {
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* XXX_IMPORT: later */
argument|return (
literal|0
argument|);
else|#
directive|else
argument|if (ifq->ifq_congestion) 		return (
literal|1
argument|); 	else 		return (
literal|0
argument|);
endif|#
directive|endif
argument|}
end_function

end_unit

