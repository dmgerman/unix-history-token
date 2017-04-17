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

begin_comment
comment|/*  * For platforms that do not have SYSCTL support, we wrap the  * SYSCTL_* into a function (one per file) to collect the values  * into an array at module initialization. The wrapping macros,  * SYSBEGIN() and SYSEND, are empty in the default case.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSBEGIN
end_ifndef

begin_define
define|#
directive|define
name|SYSBEGIN
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSEND
end_ifndef

begin_define
define|#
directive|define
name|SYSEND
end_define

begin_endif
endif|#
directive|endif
end_endif

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
block|}
struct|;
end_struct

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
name|struct
name|sockaddr_in6
modifier|*
name|next_hop6
decl_stmt|;
comment|/* ipv6 forward address		*/
comment|/* 	 * On return, it points to the matching rule. 	 * On entry, rule.slot> 0 means the info is valid and 	 * contains the starting rule for an ipfw search. 	 * If chain_id == chain->id&& slot>0 then jump to that slot. 	 * Otherwise, we locate the first rule>= rulenum:rule_id 	 */
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
union|union
block|{
comment|/* store here if cannot use a pointer */
name|struct
name|sockaddr_in
name|hopstore
decl_stmt|;
name|struct
name|sockaddr_in6
name|hopstore6
decl_stmt|;
block|}
union|;
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

begin_ifndef
ifndef|#
directive|ifndef
name|FREE_PKT
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|FREE_PKT
parameter_list|(
name|m
parameter_list|)
value|netisr_dispatch(-1, m)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FREE_PKT
parameter_list|(
name|m
parameter_list|)
value|m_freem(m)
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
comment|/* !FREE_PKT */
end_comment

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

begin_struct_decl
struct_decl|struct
name|ip_fw_chain
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ipfw_bpf_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_bpf_uninit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_bpf_mtap2
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_log
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
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

begin_struct_decl
struct_decl|struct
name|ip_fw_chain
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockopt_data
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ipfw_is_dyn_rule
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
name|ipfw_expire_dyn_rules
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
parameter_list|,
name|ipfw_range_tlv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_dyn_unlock
parameter_list|(
name|ipfw_dyn_rule
modifier|*
name|q
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
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
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
parameter_list|,
name|uint16_t
name|kidx
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
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
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
name|int
name|ipfw_dump_states
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
name|struct
name|sockopt_data
modifier|*
name|sd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_dyn_init
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
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

begin_function_decl
name|int
name|ipfw_dyn_get_count
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
name|int
argument_list|,
name|ipfw_vnet_ready
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ipfw_vnet_ready
value|VNET(ipfw_vnet_ready)
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

begin_macro
name|VNET_DECLARE
argument_list|(
argument|unsigned int
argument_list|,
argument|fw_tables_max
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|V_fw_tables_max
value|VNET(fw_tables_max)
end_define

begin_macro
name|VNET_DECLARE
argument_list|(
argument|unsigned int
argument_list|,
argument|fw_tables_sets
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|V_fw_tables_sets
value|VNET(fw_tables_sets)
end_define

begin_struct_decl
struct_decl|struct
name|tables_config
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Here we have the structure representing an ipfw rule.  *  * It starts with a general area   * followed by an array of one or more instructions, which the code  * accesses as an array of 32-bit values.  *  * Given a rule pointer  r:  *  *  r->cmd		is the start of the first instruction.  *  ACTION_PTR(r)	is the start of the first action (things to do  *			once a rule matched).  */
end_comment

begin_struct
struct|struct
name|ip_fw
block|{
name|uint16_t
name|act_ofs
decl_stmt|;
comment|/* offset of action in 32-bit units */
name|uint16_t
name|cmd_len
decl_stmt|;
comment|/* # of 32-bit words in cmd	*/
name|uint16_t
name|rulenum
decl_stmt|;
comment|/* rule number			*/
name|uint8_t
name|set
decl_stmt|;
comment|/* rule set (0..31)		*/
name|uint8_t
name|flags
decl_stmt|;
comment|/* currently unused		*/
name|counter_u64_t
name|cntr
decl_stmt|;
comment|/* Pointer to rule counters	*/
name|uint32_t
name|timestamp
decl_stmt|;
comment|/* tv_sec of last match		*/
name|uint32_t
name|id
decl_stmt|;
comment|/* rule id			*/
name|uint32_t
name|cached_id
decl_stmt|;
comment|/* used by jump_fast		*/
name|uint32_t
name|cached_pos
decl_stmt|;
comment|/* used by jump_fast		*/
name|ipfw_insn
name|cmd
index|[
literal|1
index|]
decl_stmt|;
comment|/* storage for commands		*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPFW_RULE_CNTR_SIZE
value|(2 * sizeof(uint64_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ip_fw_chain
block|{
name|struct
name|ip_fw
modifier|*
modifier|*
name|map
decl_stmt|;
comment|/* array of rule ptrs to ease lookup */
name|uint32_t
name|id
decl_stmt|;
comment|/* ruleset id */
name|int
name|n_rules
decl_stmt|;
comment|/* number of static rules */
name|void
modifier|*
name|tablestate
decl_stmt|;
comment|/* runtime table info */
name|void
modifier|*
name|valuestate
decl_stmt|;
comment|/* runtime table value info */
name|int
modifier|*
name|idxmap
decl_stmt|;
comment|/* skipto array of rules */
name|void
modifier|*
modifier|*
name|srvstate
decl_stmt|;
comment|/* runtime service mappings */
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
name|spinlock_t
name|rwmtx
decl_stmt|;
endif|#
directive|endif
name|int
name|static_len
decl_stmt|;
comment|/* total len of static rules (v0) */
name|uint32_t
name|gencnt
decl_stmt|;
comment|/* NAT generation count */
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
name|ip_fw
modifier|*
name|default_rule
decl_stmt|;
name|struct
name|tables_config
modifier|*
name|tblcfg
decl_stmt|;
comment|/* tables module data */
name|void
modifier|*
name|ifcfg
decl_stmt|;
comment|/* interface module data */
name|int
modifier|*
name|idxmap_back
decl_stmt|;
comment|/* standby skipto array of rules */
name|struct
name|namedobj_instance
modifier|*
name|srvmap
decl_stmt|;
comment|/* cfg name->number mappings */
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
name|spinlock_t
name|uh_lock
decl_stmt|;
else|#
directive|else
name|struct
name|rwlock
name|uh_lock
decl_stmt|;
comment|/* lock for upper half */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* 64-byte structure representing multi-field table value */
end_comment

begin_struct
struct|struct
name|table_value
block|{
name|uint32_t
name|tag
decl_stmt|;
comment|/* O_TAG/O_TAGGED */
name|uint32_t
name|pipe
decl_stmt|;
comment|/* O_PIPE/O_QUEUE */
name|uint16_t
name|divert
decl_stmt|;
comment|/* O_DIVERT/O_TEE */
name|uint16_t
name|skipto
decl_stmt|;
comment|/* skipto, CALLRET */
name|uint32_t
name|netgraph
decl_stmt|;
comment|/* O_NETGRAPH/O_NGTEE */
name|uint32_t
name|fib
decl_stmt|;
comment|/* O_SETFIB */
name|uint32_t
name|nat
decl_stmt|;
comment|/* O_NAT */
name|uint32_t
name|nh4
decl_stmt|;
name|uint8_t
name|dscp
decl_stmt|;
name|uint8_t
name|spare0
decl_stmt|;
name|uint16_t
name|spare1
decl_stmt|;
comment|/* -- 32 bytes -- */
name|struct
name|in6_addr
name|nh6
decl_stmt|;
name|uint32_t
name|limit
decl_stmt|;
comment|/* O_LIMIT */
name|uint32_t
name|zoneid
decl_stmt|;
comment|/* scope zone id for nh6 */
name|uint64_t
name|refcnt
decl_stmt|;
comment|/* Number of references */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|named_object
block|{
name|TAILQ_ENTRY
argument_list|(
argument|named_object
argument_list|)
name|nn_next
expr_stmt|;
comment|/* namehash */
name|TAILQ_ENTRY
argument_list|(
argument|named_object
argument_list|)
name|nv_next
expr_stmt|;
comment|/* valuehash */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* object name */
name|uint16_t
name|etlv
decl_stmt|;
comment|/* Export TLV id */
name|uint8_t
name|subtype
decl_stmt|;
comment|/* object subtype within class */
name|uint8_t
name|set
decl_stmt|;
comment|/* set object belongs to */
name|uint16_t
name|kidx
decl_stmt|;
comment|/* object kernel index */
name|uint16_t
name|spare
decl_stmt|;
name|uint32_t
name|ocnt
decl_stmt|;
comment|/* object counter for internal use */
name|uint32_t
name|refcnt
decl_stmt|;
comment|/* number of references */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|namedobjects_head
argument_list|,
name|named_object
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_comment
comment|/* used by tcp_var.h */
end_comment

begin_struct
struct|struct
name|sockopt_data
block|{
name|caddr_t
name|kbuf
decl_stmt|;
comment|/* allocated buffer */
name|size_t
name|ksize
decl_stmt|;
comment|/* given buffer size */
name|size_t
name|koff
decl_stmt|;
comment|/* data already used */
name|size_t
name|kavail
decl_stmt|;
comment|/* number of bytes available */
name|size_t
name|ktotal
decl_stmt|;
comment|/* total bytes pushed */
name|struct
name|sockopt
modifier|*
name|sopt
decl_stmt|;
comment|/* socket data */
name|caddr_t
name|sopt_val
decl_stmt|;
comment|/* sopt user buffer */
name|size_t
name|valsize
decl_stmt|;
comment|/* original data size */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ipfw_ifc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
name|ipfw_ifc_cb
function_decl|)
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|void
modifier|*
name|cbdata
parameter_list|,
name|uint16_t
name|ifindex
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ipfw_iface
block|{
name|struct
name|named_object
name|no
decl_stmt|;
name|char
name|ifname
index|[
literal|64
index|]
decl_stmt|;
name|int
name|resolved
decl_stmt|;
name|uint16_t
name|ifindex
decl_stmt|;
name|uint16_t
name|spare
decl_stmt|;
name|uint64_t
name|gencnt
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ipfw_ifc
argument_list|)
name|consumers
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipfw_ifc
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ipfw_ifc
argument_list|)
name|next
expr_stmt|;
name|struct
name|ipfw_iface
modifier|*
name|iface
decl_stmt|;
name|ipfw_ifc_cb
modifier|*
name|cb
decl_stmt|;
name|void
modifier|*
name|cbdata
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Macro for working with various counters */
end_comment

begin_define
define|#
directive|define
name|IPFW_INC_RULE_COUNTER
parameter_list|(
name|_cntr
parameter_list|,
name|_bytes
parameter_list|)
value|do {	\ 	counter_u64_add((_cntr)->cntr, 1);		\ 	counter_u64_add((_cntr)->cntr + 1, _bytes);	\ 	if ((_cntr)->timestamp != time_uptime)		\ 		(_cntr)->timestamp = time_uptime;	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IPFW_INC_DYN_COUNTER
parameter_list|(
name|_cntr
parameter_list|,
name|_bytes
parameter_list|)
value|do {		\ 	(_cntr)->pcnt++;				\ 	(_cntr)->bcnt += _bytes;			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IPFW_ZERO_RULE_COUNTER
parameter_list|(
name|_cntr
parameter_list|)
value|do {		\ 	counter_u64_zero((_cntr)->cntr);		\ 	counter_u64_zero((_cntr)->cntr + 1);		\ 	(_cntr)->timestamp = 0;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IPFW_ZERO_DYN_COUNTER
parameter_list|(
name|_cntr
parameter_list|)
value|do {		\ 	(_cntr)->pcnt = 0;				\ 	(_cntr)->bcnt = 0;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TARG_VAL
parameter_list|(
name|ch
parameter_list|,
name|k
parameter_list|,
name|f
parameter_list|)
value|((struct table_value *)((ch)->valuestate))[k].f
end_define

begin_define
define|#
directive|define
name|IP_FW_ARG_TABLEARG
parameter_list|(
name|ch
parameter_list|,
name|a
parameter_list|,
name|f
parameter_list|)
define|\
value|(((a) == IP_FW_TARG) ? TARG_VAL(ch, tablearg, f) : (a))
end_define

begin_comment
comment|/*  * The lock is heavily used by ip_fw2.c (the main file) and ip_fw_nat.c  * so the variable and the macros must be here.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

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
name|IPFW_RLOCK_ASSERT
parameter_list|(
name|_chain
parameter_list|)
value|rw_assert(&(_chain)->rwmtx, RA_RLOCKED)
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
name|IPFW_RLOCK_TRACKER
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
name|IPFW_PF_RLOCK
parameter_list|(
name|p
parameter_list|)
value|IPFW_RLOCK(p)
end_define

begin_define
define|#
directive|define
name|IPFW_PF_RUNLOCK
parameter_list|(
name|p
parameter_list|)
value|IPFW_RUNLOCK(p)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FreeBSD */
end_comment

begin_define
define|#
directive|define
name|IPFW_LOCK_INIT
parameter_list|(
name|_chain
parameter_list|)
value|do {			\ 	rw_init(&(_chain)->uh_lock, "IPFW UH lock");	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IPFW_LOCK_DESTROY
parameter_list|(
name|_chain
parameter_list|)
value|do {			\ 	rw_destroy(&(_chain)->uh_lock);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IPFW_RLOCK_ASSERT
parameter_list|(
name|_chain
parameter_list|)
value|rm_assert(&V_pfil_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|IPFW_WLOCK_ASSERT
parameter_list|(
name|_chain
parameter_list|)
value|rm_assert(&V_pfil_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|IPFW_RLOCK_TRACKER
value|struct rm_priotracker _tracker
end_define

begin_define
define|#
directive|define
name|IPFW_RLOCK
parameter_list|(
name|p
parameter_list|)
value|rm_rlock(&V_pfil_lock,&_tracker)
end_define

begin_define
define|#
directive|define
name|IPFW_RUNLOCK
parameter_list|(
name|p
parameter_list|)
value|rm_runlock(&V_pfil_lock,&_tracker)
end_define

begin_define
define|#
directive|define
name|IPFW_WLOCK
parameter_list|(
name|p
parameter_list|)
value|rm_wlock(&V_pfil_lock)
end_define

begin_define
define|#
directive|define
name|IPFW_WUNLOCK
parameter_list|(
name|p
parameter_list|)
value|rm_wunlock(&V_pfil_lock)
end_define

begin_define
define|#
directive|define
name|IPFW_PF_RLOCK
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IPFW_PF_RUNLOCK
parameter_list|(
name|p
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPFW_UH_RLOCK_ASSERT
parameter_list|(
name|_chain
parameter_list|)
value|rw_assert(&(_chain)->uh_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|IPFW_UH_WLOCK_ASSERT
parameter_list|(
name|_chain
parameter_list|)
value|rw_assert(&(_chain)->uh_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|IPFW_UH_UNLOCK_ASSERT
parameter_list|(
name|_chain
parameter_list|)
value|rw_assert(&(_chain)->uh_lock, RA_UNLOCKED)
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

begin_struct
struct|struct
name|obj_idx
block|{
name|uint16_t
name|uidx
decl_stmt|;
comment|/* internal index supplied by userland */
name|uint16_t
name|kidx
decl_stmt|;
comment|/* kernel object index */
name|uint16_t
name|off
decl_stmt|;
comment|/* tlv offset from rule end in 4-byte words */
name|uint8_t
name|spare
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
comment|/* object type within its category */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rule_check_info
block|{
name|uint16_t
name|flags
decl_stmt|;
comment|/* rule-specific check flags */
name|uint16_t
name|object_opcodes
decl_stmt|;
comment|/* num of opcodes referencing objects */
name|uint16_t
name|urule_numoff
decl_stmt|;
comment|/* offset of rulenum in bytes */
name|uint8_t
name|version
decl_stmt|;
comment|/* rule version */
name|uint8_t
name|spare
decl_stmt|;
name|ipfw_obj_ctlv
modifier|*
name|ctlv
decl_stmt|;
comment|/* name TLV containter */
name|struct
name|ip_fw
modifier|*
name|krule
decl_stmt|;
comment|/* resulting rule pointer */
name|caddr_t
name|urule
decl_stmt|;
comment|/* original rule pointer */
name|struct
name|obj_idx
name|obuf
index|[
literal|8
index|]
decl_stmt|;
comment|/* table references storage */
block|}
struct|;
end_struct

begin_comment
comment|/* Legacy interface support */
end_comment

begin_comment
comment|/*  * FreeBSD 8 export rule format  */
end_comment

begin_struct
struct|struct
name|ip_fw_rule0
block|{
name|struct
name|ip_fw
modifier|*
name|x_next
decl_stmt|;
comment|/* linked list of rules		*/
name|struct
name|ip_fw
modifier|*
name|next_rule
decl_stmt|;
comment|/* ptr to next [skipto] rule	*/
comment|/* 'next_rule' is used to pass up 'set_disable' status		*/
name|uint16_t
name|act_ofs
decl_stmt|;
comment|/* offset of action in 32-bit units */
name|uint16_t
name|cmd_len
decl_stmt|;
comment|/* # of 32-bit words in cmd	*/
name|uint16_t
name|rulenum
decl_stmt|;
comment|/* rule number			*/
name|uint8_t
name|set
decl_stmt|;
comment|/* rule set (0..31)		*/
name|uint8_t
name|_pad
decl_stmt|;
comment|/* padding			*/
name|uint32_t
name|id
decl_stmt|;
comment|/* rule id */
comment|/* These fields are present in all rules.			*/
name|uint64_t
name|pcnt
decl_stmt|;
comment|/* Packet counter		*/
name|uint64_t
name|bcnt
decl_stmt|;
comment|/* Byte counter			*/
name|uint32_t
name|timestamp
decl_stmt|;
comment|/* tv_sec of last match		*/
name|ipfw_insn
name|cmd
index|[
literal|1
index|]
decl_stmt|;
comment|/* storage for commands		*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ip_fw_bcounter0
block|{
name|uint64_t
name|pcnt
decl_stmt|;
comment|/* Packet counter		*/
name|uint64_t
name|bcnt
decl_stmt|;
comment|/* Byte counter			*/
name|uint32_t
name|timestamp
decl_stmt|;
comment|/* tv_sec of last match		*/
block|}
struct|;
end_struct

begin_comment
comment|/* Kernel rule length */
end_comment

begin_comment
comment|/*  * RULE _K_ SIZE _V_ ->  * get kernel size from userland rool version _V_.  * RULE _U_ SIZE _V_ ->  * get user size version _V_ from kernel rule  * RULESIZE _V_ ->  * get user size rule length   */
end_comment

begin_comment
comment|/* FreeBSD8<> current kernel format */
end_comment

begin_define
define|#
directive|define
name|RULEUSIZE0
parameter_list|(
name|r
parameter_list|)
value|(sizeof(struct ip_fw_rule0) + (r)->cmd_len * 4 - 4)
end_define

begin_define
define|#
directive|define
name|RULEKSIZE0
parameter_list|(
name|r
parameter_list|)
value|roundup2((sizeof(struct ip_fw) + (r)->cmd_len*4 - 4), 8)
end_define

begin_comment
comment|/* FreeBSD11<> current kernel format */
end_comment

begin_define
define|#
directive|define
name|RULEUSIZE1
parameter_list|(
name|r
parameter_list|)
value|(roundup2(sizeof(struct ip_fw_rule) + \     (r)->cmd_len * 4 - 4, 8))
end_define

begin_define
define|#
directive|define
name|RULEKSIZE1
parameter_list|(
name|r
parameter_list|)
value|roundup2((sizeof(struct ip_fw) + (r)->cmd_len*4 - 4), 8)
end_define

begin_comment
comment|/*  * Tables/Objects index rewriting code  */
end_comment

begin_comment
comment|/* Default and maximum number of ipfw tables/objects. */
end_comment

begin_define
define|#
directive|define
name|IPFW_TABLES_MAX
value|65536
end_define

begin_define
define|#
directive|define
name|IPFW_TABLES_DEFAULT
value|128
end_define

begin_define
define|#
directive|define
name|IPFW_OBJECTS_MAX
value|65536
end_define

begin_define
define|#
directive|define
name|IPFW_OBJECTS_DEFAULT
value|1024
end_define

begin_define
define|#
directive|define
name|CHAIN_TO_SRV
parameter_list|(
name|ch
parameter_list|)
value|((ch)->srvmap)
end_define

begin_define
define|#
directive|define
name|SRV_OBJECT
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|)
value|((ch)->srvstate[(idx)])
end_define

begin_struct
struct|struct
name|tid_info
block|{
name|uint32_t
name|set
decl_stmt|;
comment|/* table set */
name|uint16_t
name|uidx
decl_stmt|;
comment|/* table index */
name|uint8_t
name|type
decl_stmt|;
comment|/* table type */
name|uint8_t
name|atype
decl_stmt|;
name|uint8_t
name|spare
decl_stmt|;
name|int
name|tlen
decl_stmt|;
comment|/* Total TLV size block */
name|void
modifier|*
name|tlvs
decl_stmt|;
comment|/* Pointer to first TLV */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Classifier callback. Checks if @cmd opcode contains kernel object reference.  * If true, returns its index and type.  * Returns 0 if match is found, 1 overwise.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ipfw_obj_rw_cl
function_decl|)
parameter_list|(
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|uint16_t
modifier|*
name|puidx
parameter_list|,
name|uint8_t
modifier|*
name|ptype
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Updater callback. Sets kernel object reference index to @puidx  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|ipfw_obj_rw_upd
function_decl|)
parameter_list|(
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|uint16_t
name|puidx
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Finder callback. Tries to find named object by name (specified via @ti).  * Stores found named object pointer in @pno.  * If object was not found, NULL is stored.  *  * Return 0 if input data was valid.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ipfw_obj_fname_cb
function_decl|)
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|tid_info
modifier|*
name|ti
parameter_list|,
name|struct
name|named_object
modifier|*
modifier|*
name|pno
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Another finder callback. Tries to findex named object by kernel index.  *  * Returns pointer to named object or NULL.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|named_object
modifier|*
function_decl|(
name|ipfw_obj_fidx_cb
function_decl|)
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|kidx
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Object creator callback. Tries to create object specified by @ti.  * Stores newly-allocated object index in @pkidx.  *  * Returns 0 on success.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ipfw_obj_create_cb
function_decl|)
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|tid_info
modifier|*
name|ti
parameter_list|,
name|uint16_t
modifier|*
name|pkidx
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Object destroy callback. Intended to free resources allocated by  * create_object callback.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|ipfw_obj_destroy_cb
function_decl|)
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|named_object
modifier|*
name|no
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Sets handler callback. Handles moving and swaping set of named object.  *  SWAP_ALL moves all named objects from set `set' to `new_set' and vise versa;  *  TEST_ALL checks that there aren't any named object with conflicting names;  *  MOVE_ALL moves all named objects from set `set' to `new_set';  *  COUNT_ONE used to count number of references used by object with kidx `set';  *  TEST_ONE checks that named object with kidx `set' can be moved to `new_set`;  *  MOVE_ONE moves named object with kidx `set' to set `new_set'.  */
end_comment

begin_enum
enum|enum
name|ipfw_sets_cmd
block|{
name|SWAP_ALL
init|=
literal|0
block|,
name|TEST_ALL
block|,
name|MOVE_ALL
block|,
name|COUNT_ONE
block|,
name|TEST_ONE
block|,
name|MOVE_ONE
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ipfw_obj_sets_cb
function_decl|)
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|set
parameter_list|,
name|uint8_t
name|new_set
parameter_list|,
name|enum
name|ipfw_sets_cmd
name|cmd
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|opcode_obj_rewrite
block|{
name|uint32_t
name|opcode
decl_stmt|;
comment|/* Opcode to act upon */
name|uint32_t
name|etlv
decl_stmt|;
comment|/* Relevant export TLV id  */
name|ipfw_obj_rw_cl
modifier|*
name|classifier
decl_stmt|;
comment|/* Check if rewrite is needed */
name|ipfw_obj_rw_upd
modifier|*
name|update
decl_stmt|;
comment|/* update cmd with new value */
name|ipfw_obj_fname_cb
modifier|*
name|find_byname
decl_stmt|;
comment|/* Find named object by name */
name|ipfw_obj_fidx_cb
modifier|*
name|find_bykidx
decl_stmt|;
comment|/* Find named object by kidx */
name|ipfw_obj_create_cb
modifier|*
name|create_object
decl_stmt|;
comment|/* Create named object */
name|ipfw_obj_destroy_cb
modifier|*
name|destroy_object
decl_stmt|;
comment|/* Destroy named object */
name|ipfw_obj_sets_cb
modifier|*
name|manage_sets
decl_stmt|;
comment|/* Swap or move sets */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPFW_ADD_OBJ_REWRITER
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|do {	\ 	if ((f) != 0) 				\ 		ipfw_add_obj_rewriter(c,	\ 		    sizeof(c) / sizeof(c[0]));	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|IPFW_DEL_OBJ_REWRITER
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|do {	\ 	if ((l) != 0) 				\ 		ipfw_del_obj_rewriter(c,	\ 		    sizeof(c) / sizeof(c[0]));	\ 	} while(0)
end_define

begin_comment
comment|/* In ip_fw_iface.c */
end_comment

begin_function_decl
name|int
name|ipfw_iface_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_iface_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_ipfw_iface_destroy
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
name|ipfw_iface_ref
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|ipfw_ifc
modifier|*
name|ic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_iface_unref
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|ipfw_ifc
modifier|*
name|ic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_iface_add_notify
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|ipfw_ifc
modifier|*
name|ic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_iface_del_notify
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|ipfw_ifc
modifier|*
name|ic
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In ip_fw_sockopt.c */
end_comment

begin_function_decl
name|void
name|ipfw_init_skipto_cache
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_destroy_skipto_cache
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|)
function_decl|;
end_function_decl

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
name|ipfw_ctl3
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
name|ipfw_reap_add
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
name|struct
name|ip_fw
modifier|*
modifier|*
name|head
parameter_list|,
name|struct
name|ip_fw
modifier|*
name|rule
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

begin_function_decl
name|void
name|ipfw_init_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_destroy_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ip_fw
modifier|*
name|ipfw_alloc_rule
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
name|size_t
name|rulesize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_match_range
parameter_list|(
name|struct
name|ip_fw
modifier|*
name|rule
parameter_list|,
name|ipfw_range_tlv
modifier|*
name|rt
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
name|sopt_handler_f
function_decl|)
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|ip_fw3_opheader
modifier|*
name|op3
parameter_list|,
name|struct
name|sockopt_data
modifier|*
name|sd
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ipfw_sopt_handler
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint8_t
name|version
decl_stmt|;
name|uint8_t
name|dir
decl_stmt|;
name|sopt_handler_f
modifier|*
name|handler
decl_stmt|;
name|uint64_t
name|refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HDIR_SET
value|0x01
end_define

begin_comment
comment|/* Handler is used to set some data */
end_comment

begin_define
define|#
directive|define
name|HDIR_GET
value|0x02
end_define

begin_comment
comment|/* Handler is used to retrieve data */
end_comment

begin_define
define|#
directive|define
name|HDIR_BOTH
value|HDIR_GET|HDIR_SET
end_define

begin_function_decl
name|void
name|ipfw_init_sopt_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_destroy_sopt_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_add_sopt_handler
parameter_list|(
name|struct
name|ipfw_sopt_handler
modifier|*
name|sh
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_del_sopt_handler
parameter_list|(
name|struct
name|ipfw_sopt_handler
modifier|*
name|sh
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|ipfw_get_sopt_space
parameter_list|(
name|struct
name|sockopt_data
modifier|*
name|sd
parameter_list|,
name|size_t
name|needed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|ipfw_get_sopt_header
parameter_list|(
name|struct
name|sockopt_data
modifier|*
name|sd
parameter_list|,
name|size_t
name|needed
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IPFW_ADD_SOPT_HANDLER
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|do {	\ 	if ((f) != 0) 				\ 		ipfw_add_sopt_handler(c,	\ 		    sizeof(c) / sizeof(c[0]));	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|IPFW_DEL_SOPT_HANDLER
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|do {	\ 	if ((l) != 0) 				\ 		ipfw_del_sopt_handler(c,	\ 		    sizeof(c) / sizeof(c[0]));	\ 	} while(0)
end_define

begin_struct_decl
struct_decl|struct
name|namedobj_instance
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
name|objhash_cb_t
function_decl|)
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|struct
name|named_object
modifier|*
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
name|objhash_hash_f
function_decl|)
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|uint32_t
name|kopt
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|objhash_cmp_f
function_decl|)
parameter_list|(
name|struct
name|named_object
modifier|*
name|no
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|uint32_t
name|kopt
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|namedobj_instance
modifier|*
name|ipfw_objhash_create
parameter_list|(
name|uint32_t
name|items
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_destroy
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_bitmap_alloc
parameter_list|(
name|uint32_t
name|items
parameter_list|,
name|void
modifier|*
modifier|*
name|idx
parameter_list|,
name|int
modifier|*
name|pblocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_bitmap_merge
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|void
modifier|*
modifier|*
name|idx
parameter_list|,
name|int
modifier|*
name|blocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_bitmap_swap
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|void
modifier|*
modifier|*
name|idx
parameter_list|,
name|int
modifier|*
name|blocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_bitmap_free
parameter_list|(
name|void
modifier|*
name|idx
parameter_list|,
name|int
name|blocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_set_hashf
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|objhash_hash_f
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|named_object
modifier|*
name|ipfw_objhash_lookup_name
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|uint32_t
name|set
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|named_object
modifier|*
name|ipfw_objhash_lookup_name_type
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|uint32_t
name|set
parameter_list|,
name|uint32_t
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|named_object
modifier|*
name|ipfw_objhash_lookup_kidx
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|uint16_t
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_objhash_same_name
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|struct
name|named_object
modifier|*
name|a
parameter_list|,
name|struct
name|named_object
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_add
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|struct
name|named_object
modifier|*
name|no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_del
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|struct
name|named_object
modifier|*
name|no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ipfw_objhash_count
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ipfw_objhash_count_type
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|uint16_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_objhash_foreach
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|objhash_cb_t
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_objhash_foreach_type
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|objhash_cb_t
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|uint16_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_objhash_free_idx
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|uint16_t
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_objhash_alloc_idx
parameter_list|(
name|void
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|pidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_objhash_set_funcs
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|objhash_hash_f
modifier|*
name|hash_f
parameter_list|,
name|objhash_cmp_f
modifier|*
name|cmp_f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_objhash_find_type
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|struct
name|tid_info
modifier|*
name|ti
parameter_list|,
name|uint32_t
name|etlv
parameter_list|,
name|struct
name|named_object
modifier|*
modifier|*
name|pno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_export_obj_ntlv
parameter_list|(
name|struct
name|named_object
modifier|*
name|no
parameter_list|,
name|ipfw_obj_ntlv
modifier|*
name|ntlv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ipfw_obj_ntlv
modifier|*
name|ipfw_find_name_tlv_type
parameter_list|(
name|void
modifier|*
name|tlvs
parameter_list|,
name|int
name|len
parameter_list|,
name|uint16_t
name|uidx
parameter_list|,
name|uint32_t
name|etlv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_init_obj_rewriter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_destroy_obj_rewriter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_add_obj_rewriter
parameter_list|(
name|struct
name|opcode_obj_rewrite
modifier|*
name|rw
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_del_obj_rewriter
parameter_list|(
name|struct
name|opcode_obj_rewrite
modifier|*
name|rw
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|create_objects_compat
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|struct
name|obj_idx
modifier|*
name|oib
parameter_list|,
name|struct
name|obj_idx
modifier|*
name|pidx
parameter_list|,
name|struct
name|tid_info
modifier|*
name|ti
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_opcode_kidx
parameter_list|(
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|uint16_t
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|classify_opcode_kidx
parameter_list|(
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|uint16_t
modifier|*
name|puidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_init_srv
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_destroy_srv
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
name|ipfw_check_object_name_generic
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_obj_manage_sets
parameter_list|(
name|struct
name|namedobj_instance
modifier|*
name|ni
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|set
parameter_list|,
name|uint8_t
name|new_set
parameter_list|,
name|enum
name|ipfw_sets_cmd
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In ip_fw_eaction.c */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ipfw_eaction_t
function_decl|)
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|,
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|int
modifier|*
name|done
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|ipfw_eaction_init
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_eaction_uninit
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ipfw_add_eaction
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|ipfw_eaction_t
name|handler
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_del_eaction
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|eaction_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_run_eaction
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|,
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|int
modifier|*
name|done
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In ip_fw_table.c */
end_comment

begin_struct_decl
struct_decl|struct
name|table_info
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
name|table_lookup_t
function_decl|)
parameter_list|(
name|struct
name|table_info
modifier|*
name|ti
parameter_list|,
name|void
modifier|*
name|key
parameter_list|,
name|uint32_t
name|keylen
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_typedef

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
name|uint16_t
name|plen
parameter_list|,
name|void
modifier|*
name|paddr
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|named_object
modifier|*
name|ipfw_objhash_lookup_table_kidx
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|kidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_ref_table
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|ipfw_obj_ntlv
modifier|*
name|ntlv
parameter_list|,
name|uint16_t
modifier|*
name|kidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_unref_table
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|uint16_t
name|kidx
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
parameter_list|,
name|int
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_resize_tables
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|unsigned
name|int
name|ntables
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_switch_tables_namespace
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|unsigned
name|int
name|nsets
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_destroy_tables
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In ip_fw_nat.c -- XXX to be moved to ip_var.h */
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

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipfw_nat_ready
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ipfw_nat_ready
value|VNET(ipfw_nat_ready)
end_define

begin_define
define|#
directive|define
name|IPFW_NAT_LOADED
value|(V_ipfw_nat_ready)
end_define

begin_decl_stmt
specifier|extern
name|ipfw_nat_t
modifier|*
name|ipfw_nat_ptr
decl_stmt|;
end_decl_stmt

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
comment|/* Helper functions for IP checksum adjustment */
end_comment

begin_function
specifier|static
name|__inline
name|uint16_t
name|cksum_add
parameter_list|(
name|uint16_t
name|sum
parameter_list|,
name|uint16_t
name|a
parameter_list|)
block|{
name|uint16_t
name|res
decl_stmt|;
name|res
operator|=
name|sum
operator|+
name|a
expr_stmt|;
return|return
operator|(
name|res
operator|+
operator|(
name|res
operator|<
name|a
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint16_t
name|cksum_adjust
parameter_list|(
name|uint16_t
name|oldsum
parameter_list|,
name|uint16_t
name|old
parameter_list|,
name|uint16_t
name|new
parameter_list|)
block|{
return|return
operator|(
operator|~
name|cksum_add
argument_list|(
name|cksum_add
argument_list|(
operator|~
name|oldsum
argument_list|,
operator|~
name|old
argument_list|)
argument_list|,
name|new
argument_list|)
operator|)
return|;
block|}
end_function

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

