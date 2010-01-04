begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Luigi Rizzo, Universita` di Pisa  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPFW2_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|_IPFW2_PRIVATE_H
end_define

begin_comment
comment|/*  * Internal constants and data structures used by ipfw components  * and not meant to be exported outside the kernel.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MTAG_IPFW
value|1148380143
end_define

begin_comment
comment|/* IPFW-tagged cookie */
end_comment

begin_define
define|#
directive|define
name|MTAG_IPFW_RULE
value|1262273568
end_define

begin_comment
comment|/* rule reference */
end_comment

begin_comment
comment|/* Return values from ipfw_chk() */
end_comment

begin_enum
enum|enum
block|{
name|IP_FW_PASS
init|=
literal|0
block|,
name|IP_FW_DENY
block|,
name|IP_FW_DIVERT
block|,
name|IP_FW_TEE
block|,
name|IP_FW_DUMMYNET
block|,
name|IP_FW_NETGRAPH
block|,
name|IP_FW_NGTEE
block|,
name|IP_FW_NAT
block|,
name|IP_FW_REASS
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Structure for collecting parameters to dummynet for ip6_output forwarding  */
end_comment

begin_struct
struct|struct
name|_ip6dn_args
block|{
name|struct
name|ip6_pktopts
modifier|*
name|opt_or
decl_stmt|;
name|struct
name|route_in6
name|ro_or
decl_stmt|;
name|int
name|flags_or
decl_stmt|;
name|struct
name|ip6_moptions
modifier|*
name|im6o_or
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|origifp_or
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp_or
decl_stmt|;
name|struct
name|sockaddr_in6
name|dst_or
decl_stmt|;
name|u_long
name|mtu_or
decl_stmt|;
name|struct
name|route_in6
name|ro_pmtu_or
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reference to an ipfw rule that can be carried outside critical sections.  * A rule is identified by rulenum:rule_id which is ordered.  * In version chain_id the rule can be found in slot 'slot', so  * we don't need a lookup if chain_id == chain->id.  *  * On exit from the firewall this structure refers to the rule after  * the matching one (slot points to the new rule; rulenum:rule_id-1  * is the matching rule), and additional info (e.g. info often contains  * the insn argument or tablearg in the low 16 bits, in host format).  * On entry, the structure is valid if slot>0, and refers to the starting  * rules. 'info' contains the reason for reinject, e.g. divert port,  * divert direction, and so on.  */
end_comment

begin_struct
struct|struct
name|ipfw_rule_ref
block|{
name|uint32_t
name|slot
decl_stmt|;
comment|/* slot for matching rule	*/
name|uint32_t
name|rulenum
decl_stmt|;
comment|/* matching rule number		*/
name|uint32_t
name|rule_id
decl_stmt|;
comment|/* matching rule id		*/
name|uint32_t
name|chain_id
decl_stmt|;
comment|/* ruleset id			*/
name|uint32_t
name|info
decl_stmt|;
comment|/* see below			*/
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|IPFW_INFO_MASK
init|=
literal|0x0000ffff
block|,
name|IPFW_INFO_OUT
init|=
literal|0x00000000
block|,
comment|/* outgoing, just for convenience */
name|IPFW_INFO_IN
init|=
literal|0x80000000
block|,
comment|/* incoming, overloads dir */
name|IPFW_ONEPASS
init|=
literal|0x40000000
block|,
comment|/* One-pass, do not reinject */
name|IPFW_IS_MASK
init|=
literal|0x30000000
block|,
comment|/* which source ? */
name|IPFW_IS_DIVERT
init|=
literal|0x20000000
block|,
name|IPFW_IS_DUMMYNET
init|=
literal|0x10000000
block|,
name|IPFW_IS_PIPE
init|=
literal|0x08000000
block|,
comment|/* pip1=1, queue = 0 */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Arguments for calling ipfw_chk() and dummynet_io(). We put them  * all into a structure because this way it is easier and more  * efficient to pass variables around and extend the interface.  */
end_comment

begin_struct
struct|struct
name|ip_fw_args
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* the mbuf chain		*/
name|struct
name|ifnet
modifier|*
name|oif
decl_stmt|;
comment|/* output interface		*/
name|struct
name|sockaddr_in
modifier|*
name|next_hop
decl_stmt|;
comment|/* forward address		*/
comment|/* 	 * On return, it points to the matching rule. 	 * On entry, rule.slot> 0 means the info is valid and 	 * contains the the starting rule for an ipfw search. 	 * If chain_id == chain->id&& slot>0 then jump to that slot. 	 * Otherwise, we locate the first rule>= rulenum:rule_id 	 */
name|struct
name|ipfw_rule_ref
name|rule
decl_stmt|;
comment|/* match/restart info		*/
name|struct
name|ether_header
modifier|*
name|eh
decl_stmt|;
comment|/* for bridged packets		*/
name|struct
name|ipfw_flow_id
name|f_id
decl_stmt|;
comment|/* grabbed from IP header	*/
comment|//uint32_t	cookie;		/* a cookie depending on rule action */
name|struct
name|inpcb
modifier|*
name|inp
decl_stmt|;
name|struct
name|_ip6dn_args
name|dummypar
decl_stmt|;
comment|/* dummynet->ip6_output */
name|struct
name|sockaddr_in
name|hopstore
decl_stmt|;
comment|/* store here if cannot use a pointer */
block|}
struct|;
end_struct

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPFW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Hooks sometime need to know the direction of the packet  * (divert, dummynet, netgraph, ...)  * We use a generic definition here, with bit0-1 indicating the  * direction, bit 2 indicating layer2 or 3, bit 3-4 indicating the  * specific protocol  * indicating the protocol (if necessary)  */
end_comment

begin_enum
enum|enum
block|{
name|DIR_MASK
init|=
literal|0x3
block|,
name|DIR_OUT
init|=
literal|0
block|,
name|DIR_IN
init|=
literal|1
block|,
name|DIR_FWD
init|=
literal|2
block|,
name|DIR_DROP
init|=
literal|3
block|,
name|PROTO_LAYER2
init|=
literal|0x4
block|,
comment|/* set for layer 2 */
comment|/* PROTO_DEFAULT = 0, */
name|PROTO_IPV4
init|=
literal|0x08
block|,
name|PROTO_IPV6
init|=
literal|0x10
block|,
name|PROTO_IFB
init|=
literal|0x0c
block|,
comment|/* layer2 + ifbridge */
comment|/*	PROTO_OLDBDG =	0x14, unused, old bridge */
block|}
enum|;
end_enum

begin_comment
comment|/* wrapper for freeing a packet, in case we need to do more work */
end_comment

begin_define
define|#
directive|define
name|FREE_PKT
parameter_list|(
name|m
parameter_list|)
value|m_freem(m)
end_define

begin_comment
comment|/*  * Function definitions.  */
end_comment

begin_comment
comment|/* attach (arg = 1) or detach (arg = 0) hooks */
end_comment

begin_function_decl
name|int
name|ipfw_attach_hooks
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOTYET
end_ifdef

begin_function_decl
name|void
name|ipfw_nat_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In ip_fw_log.c */
end_comment

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ipfw_log_bpf
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_log
parameter_list|(
name|struct
name|ip_fw
modifier|*
name|f
parameter_list|,
name|u_int
name|hlen
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|ifnet
modifier|*
name|oif
parameter_list|,
name|u_short
name|offset
parameter_list|,
name|uint32_t
name|tablearg
parameter_list|,
name|struct
name|ip
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|u_int64_t
argument_list|,
name|norule_counter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_norule_counter
value|VNET(norule_counter)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|verbose_limit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_verbose_limit
value|VNET(verbose_limit)
end_define

begin_comment
comment|/* In ip_fw_dynamic.c */
end_comment

begin_enum
enum|enum
block|{
comment|/* result for matching dynamic rules */
name|MATCH_REVERSE
init|=
literal|0
block|,
name|MATCH_FORWARD
block|,
name|MATCH_NONE
block|,
name|MATCH_UNKNOWN
block|, }
enum|;
end_enum

begin_comment
comment|/*  * The lock for dynamic rules is only used once outside the file,  * and only to release the result of lookup_dyn_rule().  * Eventually we may implement it with a callback on the function.  */
end_comment

begin_function_decl
name|void
name|ipfw_dyn_unlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|tcphdr
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ipfw_send_pkt
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ipfw_flow_id
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_install_state
parameter_list|(
name|struct
name|ip_fw
modifier|*
name|rule
parameter_list|,
name|ipfw_insn_limit
modifier|*
name|cmd
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|,
name|uint32_t
name|tablearg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ipfw_dyn_rule
modifier|*
name|ipfw_lookup_dyn_rule
parameter_list|(
name|struct
name|ipfw_flow_id
modifier|*
name|pkt
parameter_list|,
name|int
modifier|*
name|match_direction
parameter_list|,
name|struct
name|tcphdr
modifier|*
name|tcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_remove_dyn_children
parameter_list|(
name|struct
name|ip_fw
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_get_dynamic
parameter_list|(
name|char
modifier|*
modifier|*
name|bp
parameter_list|,
specifier|const
name|char
modifier|*
name|ep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_dyn_attach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uma_zcreate .... */
end_comment

begin_function_decl
name|void
name|ipfw_dyn_detach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uma_zdestroy ... */
end_comment

begin_function_decl
name|void
name|ipfw_dyn_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* per-vnet initialization */
end_comment

begin_function_decl
name|void
name|ipfw_dyn_uninit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* per-vnet deinitialization */
end_comment

begin_function_decl
name|int
name|ipfw_dyn_len
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* common variables */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|fw_one_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_fw_one_pass
value|VNET(fw_one_pass)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|fw_verbose
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_fw_verbose
value|VNET(fw_verbose)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|ip_fw_chain
argument_list|,
name|layer3_chain
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_layer3_chain
value|VNET(layer3_chain)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|u_int32_t
argument_list|,
name|set_disable
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_set_disable
value|VNET(set_disable)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|autoinc_step
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_autoinc_step
value|VNET(autoinc_step)
end_define

begin_struct
struct|struct
name|ip_fw_chain
block|{
name|struct
name|ip_fw
modifier|*
name|rules
decl_stmt|;
comment|/* list of rules */
name|struct
name|ip_fw
modifier|*
name|reap
decl_stmt|;
comment|/* list of rules to reap */
name|struct
name|ip_fw
modifier|*
name|default_rule
decl_stmt|;
name|int
name|n_rules
decl_stmt|;
comment|/* number of static rules */
name|int
name|static_len
decl_stmt|;
comment|/* total len of static rules */
name|struct
name|ip_fw
modifier|*
modifier|*
name|map
decl_stmt|;
comment|/* array of rule ptrs to ease lookup */
name|LIST_HEAD
argument_list|(
argument|nat_list
argument_list|,
argument|cfg_nat
argument_list|)
name|nat
expr_stmt|;
comment|/* list of nat entries */
name|struct
name|radix_node_head
modifier|*
name|tables
index|[
name|IPFW_TABLES_MAX
index|]
decl_stmt|;
name|struct
name|rwlock
name|rwmtx
decl_stmt|;
name|struct
name|rwlock
name|uh_lock
decl_stmt|;
comment|/* lock for upper half */
name|uint32_t
name|id
decl_stmt|;
comment|/* ruleset id */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_comment
comment|/* used by tcp_var.h */
end_comment

begin_comment
comment|/*  * The lock is heavily used by ip_fw2.c (the main file) and ip_fw_nat.c  * so the variable and the macros must be here.  */
end_comment

begin_define
define|#
directive|define
name|IPFW_LOCK_INIT
parameter_list|(
name|_chain
parameter_list|)
value|do {			\ 	rw_init(&(_chain)->rwmtx, "IPFW static rules");	\ 	rw_init(&(_chain)->uh_lock, "IPFW UH lock");	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IPFW_LOCK_DESTROY
parameter_list|(
name|_chain
parameter_list|)
value|do {			\ 	rw_destroy(&(_chain)->rwmtx);			\ 	rw_destroy(&(_chain)->uh_lock);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IPFW_WLOCK_ASSERT
parameter_list|(
name|_chain
parameter_list|)
value|rw_assert(&(_chain)->rwmtx, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|IPFW_RLOCK
parameter_list|(
name|p
parameter_list|)
value|rw_rlock(&(p)->rwmtx)
end_define

begin_define
define|#
directive|define
name|IPFW_RUNLOCK
parameter_list|(
name|p
parameter_list|)
value|rw_runlock(&(p)->rwmtx)
end_define

begin_define
define|#
directive|define
name|IPFW_WLOCK
parameter_list|(
name|p
parameter_list|)
value|rw_wlock(&(p)->rwmtx)
end_define

begin_define
define|#
directive|define
name|IPFW_WUNLOCK
parameter_list|(
name|p
parameter_list|)
value|rw_wunlock(&(p)->rwmtx)
end_define

begin_define
define|#
directive|define
name|IPFW_UH_RLOCK
parameter_list|(
name|p
parameter_list|)
value|rw_rlock(&(p)->uh_lock)
end_define

begin_define
define|#
directive|define
name|IPFW_UH_RUNLOCK
parameter_list|(
name|p
parameter_list|)
value|rw_runlock(&(p)->uh_lock)
end_define

begin_define
define|#
directive|define
name|IPFW_UH_WLOCK
parameter_list|(
name|p
parameter_list|)
value|rw_wlock(&(p)->uh_lock)
end_define

begin_define
define|#
directive|define
name|IPFW_UH_WUNLOCK
parameter_list|(
name|p
parameter_list|)
value|rw_wunlock(&(p)->uh_lock)
end_define

begin_comment
comment|/* In ip_fw_sockopt.c */
end_comment

begin_function_decl
name|int
name|ipfw_find_rule
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
name|uint32_t
name|key
parameter_list|,
name|uint32_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_add_rule
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
name|struct
name|ip_fw
modifier|*
name|input_rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_ctl
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_chk
parameter_list|(
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_reap_rules
parameter_list|(
name|struct
name|ip_fw
modifier|*
name|head
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In ip_fw_table.c */
end_comment

begin_struct_decl
struct_decl|struct
name|radix_node
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ipfw_lookup_table
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|tbl
parameter_list|,
name|in_addr_t
name|addr
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_init_tables
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_flush_table
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|tbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_flush_tables
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_add_table_entry
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|tbl
parameter_list|,
name|in_addr_t
name|addr
parameter_list|,
name|uint8_t
name|mlen
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_dump_table_entry
parameter_list|(
name|struct
name|radix_node
modifier|*
name|rn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_del_table_entry
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|tbl
parameter_list|,
name|in_addr_t
name|addr
parameter_list|,
name|uint8_t
name|mlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_count_table
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint32_t
name|tbl
parameter_list|,
name|uint32_t
modifier|*
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_dump_table
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|ipfw_table
modifier|*
name|tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* hooks for divert */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|ip_divert_ptr
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|incoming
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In ip_fw_nat.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|cfg_nat
modifier|*
function_decl|(
modifier|*
name|lookup_nat_ptr
function_decl|)
parameter_list|(
name|struct
name|nat_list
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
name|ipfw_nat_t
parameter_list|(
name|struct
name|ip_fw_args
modifier|*
parameter_list|,
name|struct
name|cfg_nat
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ipfw_nat_cfg_t
parameter_list|(
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|ipfw_nat_t
modifier|*
name|ipfw_nat_ptr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IPFW_NAT_LOADED
value|(ipfw_nat_ptr != NULL)
end_define

begin_decl_stmt
specifier|extern
name|ipfw_nat_cfg_t
modifier|*
name|ipfw_nat_cfg_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipfw_nat_cfg_t
modifier|*
name|ipfw_nat_del_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipfw_nat_cfg_t
modifier|*
name|ipfw_nat_get_cfg_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipfw_nat_cfg_t
modifier|*
name|ipfw_nat_get_log_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* netgraph prototypes */
end_comment

begin_typedef
typedef|typedef
name|int
name|ng_ipfw_input_t
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|ng_ipfw_input_t
modifier|*
name|ng_ipfw_input_p
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NG_IPFW_LOADED
value|(ng_ipfw_input_p != NULL)
end_define

begin_define
define|#
directive|define
name|TAGSIZ
value|(sizeof(struct ng_ipfw_tag) - sizeof(struct m_tag))
end_define

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
comment|/* _IPFW2_PRIVATE_H */
end_comment

end_unit

