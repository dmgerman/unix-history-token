begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Luigi Rizzo, Universita` di Pisa  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPFW2_H
end_ifndef

begin_define
define|#
directive|define
name|_IPFW2_H
end_define

begin_comment
comment|/*  * The kernel representation of ipfw rules is made of a list of  * 'instructions' (for all practical purposes equivalent to BPF  * instructions), which specify which fields of the packet  * (or its metadata) should be analysed.  *  * Each instruction is stored in a structure which begins with  * "ipfw_insn", and can contain extra fields depending on the  * instruction type (listed below).  * Note that the code is written so that individual instructions  * have a size which is a multiple of 32 bits. This means that, if  * such structures contain pointers or other 64-bit entities,  * (there is just one instance now) they may end up unaligned on  * 64-bit architectures, so the must be handled with care.  *  * "enum ipfw_opcodes" are the opcodes supported. We can have up  * to 256 different opcodes.  */
end_comment

begin_enum
enum|enum
name|ipfw_opcodes
block|{
comment|/* arguments (4 byte each)	*/
name|O_NOP
block|,
name|O_IP_SRC
block|,
comment|/* u32 = IP			*/
name|O_IP_SRC_MASK
block|,
comment|/* ip = IP/mask			*/
name|O_IP_SRC_ME
block|,
comment|/* none				*/
name|O_IP_SRC_SET
block|,
comment|/* u32=base, arg1=len, bitmap	*/
name|O_IP_DST
block|,
comment|/* u32 = IP			*/
name|O_IP_DST_MASK
block|,
comment|/* ip = IP/mask			*/
name|O_IP_DST_ME
block|,
comment|/* none				*/
name|O_IP_DST_SET
block|,
comment|/* u32=base, arg1=len, bitmap	*/
name|O_IP_SRCPORT
block|,
comment|/* (n)port list:mask 4 byte ea	*/
name|O_IP_DSTPORT
block|,
comment|/* (n)port list:mask 4 byte ea	*/
name|O_PROTO
block|,
comment|/* arg1=protocol		*/
name|O_MACADDR2
block|,
comment|/* 2 mac addr:mask		*/
name|O_MAC_TYPE
block|,
comment|/* same as srcport		*/
name|O_LAYER2
block|,
comment|/* none				*/
name|O_IN
block|,
comment|/* none				*/
name|O_FRAG
block|,
comment|/* none				*/
name|O_RECV
block|,
comment|/* none				*/
name|O_XMIT
block|,
comment|/* none				*/
name|O_VIA
block|,
comment|/* none				*/
name|O_IPOPT
block|,
comment|/* arg1 = 2*u8 bitmap		*/
name|O_IPLEN
block|,
comment|/* arg1 = len			*/
name|O_IPID
block|,
comment|/* arg1 = id			*/
name|O_IPTOS
block|,
comment|/* arg1 = id			*/
name|O_IPPRECEDENCE
block|,
comment|/* arg1 = precedence<< 5	*/
name|O_IPTTL
block|,
comment|/* arg1 = TTL			*/
name|O_IPVER
block|,
comment|/* arg1 = version		*/
name|O_UID
block|,
comment|/* u32 = id			*/
name|O_GID
block|,
comment|/* u32 = id			*/
name|O_ESTAB
block|,
comment|/* none (tcp established)	*/
name|O_TCPFLAGS
block|,
comment|/* arg1 = 2*u8 bitmap		*/
name|O_TCPWIN
block|,
comment|/* arg1 = desired win		*/
name|O_TCPSEQ
block|,
comment|/* u32 = desired seq.		*/
name|O_TCPACK
block|,
comment|/* u32 = desired seq.		*/
name|O_ICMPTYPE
block|,
comment|/* u32 = icmp bitmap		*/
name|O_TCPOPTS
block|,
comment|/* arg1 = 2*u8 bitmap		*/
name|O_VERREVPATH
block|,
comment|/* none				*/
name|O_PROBE_STATE
block|,
comment|/* none				*/
name|O_KEEP_STATE
block|,
comment|/* none				*/
name|O_LIMIT
block|,
comment|/* ipfw_insn_limit		*/
name|O_LIMIT_PARENT
block|,
comment|/* dyn_type, not an opcode.	*/
comment|/* 	 * these are really 'actions', and must be last in the list. 	 */
name|O_LOG
block|,
comment|/* ipfw_insn_log		*/
name|O_PROB
block|,
comment|/* u32 = match probability	*/
name|O_CHECK_STATE
block|,
comment|/* none				*/
name|O_ACCEPT
block|,
comment|/* none				*/
name|O_DENY
block|,
comment|/* none 			*/
name|O_REJECT
block|,
comment|/* arg1=icmp arg (same as deny)	*/
name|O_COUNT
block|,
comment|/* none				*/
name|O_SKIPTO
block|,
comment|/* arg1=next rule number	*/
name|O_PIPE
block|,
comment|/* arg1=pipe number		*/
name|O_QUEUE
block|,
comment|/* arg1=queue number		*/
name|O_DIVERT
block|,
comment|/* arg1=port number		*/
name|O_TEE
block|,
comment|/* arg1=port number		*/
name|O_FORWARD_IP
block|,
comment|/* fwd sockaddr			*/
name|O_FORWARD_MAC
block|,
comment|/* fwd mac			*/
name|O_LAST_OPCODE
comment|/* not an opcode!		*/
block|}
enum|;
end_enum

begin_comment
comment|/*  * Template for instructions.  *  * ipfw_insn is used for all instructions which require no operands,  * a single 16-bit value (arg1), or a couple of 8-bit values.  *  * For other instructions which require different/larger arguments  * we have derived structures, ipfw_insn_*.  *  * The size of the instruction (in 32-bit words) is in the low  * 6 bits of "len". The 2 remaining bits are used to implement  * NOT and OR on individual instructions. Given a type, you can  * compute the length to be put in "len" using F_INSN_SIZE(t)  *  * F_NOT	negates the match result of the instruction.  *  * F_OR		is used to build or blocks. By default, instructions  *		are evaluated as part of a logical AND. An "or" block  *		{ X or Y or Z } contains F_OR set in all but the last  *		instruction of the block. A match will cause the code  *		to skip past the last instruction of the block.  *  * NOTA BENE: in a couple of places we assume that  *	sizeof(ipfw_insn) == sizeof(u_int32_t)  * this needs to be fixed.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn
block|{
comment|/* template for instructions */
name|enum
name|ipfw_opcodes
name|opcode
range|:
literal|8
decl_stmt|;
name|u_int8_t
name|len
decl_stmt|;
comment|/* numer of 32-byte words */
define|#
directive|define
name|F_NOT
value|0x80
define|#
directive|define
name|F_OR
value|0x40
define|#
directive|define
name|F_LEN_MASK
value|0x3f
define|#
directive|define
name|F_LEN
parameter_list|(
name|cmd
parameter_list|)
value|((cmd)->len& F_LEN_MASK)
name|u_int16_t
name|arg1
decl_stmt|;
block|}
name|ipfw_insn
typedef|;
end_typedef

begin_comment
comment|/*  * The F_INSN_SIZE(type) computes the size, in 4-byte words, of  * a given type.  */
end_comment

begin_define
define|#
directive|define
name|F_INSN_SIZE
parameter_list|(
name|t
parameter_list|)
value|((sizeof (t))/sizeof(u_int32_t))
end_define

begin_comment
comment|/*  * This is used to store an array of 16-bit entries (ports etc.)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_u16
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|u_int16_t
name|ports
index|[
literal|2
index|]
decl_stmt|;
comment|/* there may be more */
block|}
name|ipfw_insn_u16
typedef|;
end_typedef

begin_comment
comment|/*  * This is used to store an array of 32-bit entries  * (uid, single IPv4 addresses etc.)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_u32
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|u_int32_t
name|d
index|[
literal|1
index|]
decl_stmt|;
comment|/* one or more */
block|}
name|ipfw_insn_u32
typedef|;
end_typedef

begin_comment
comment|/*  * This is used to store IP addr-mask pairs.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_ip
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|struct
name|in_addr
name|addr
decl_stmt|;
name|struct
name|in_addr
name|mask
decl_stmt|;
block|}
name|ipfw_insn_ip
typedef|;
end_typedef

begin_comment
comment|/*  * This is used to forward to a given address (ip)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_sa
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|struct
name|sockaddr_in
name|sa
decl_stmt|;
block|}
name|ipfw_insn_sa
typedef|;
end_typedef

begin_comment
comment|/*  * This is used for MAC addr-mask pairs.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_mac
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|u_char
name|addr
index|[
literal|12
index|]
decl_stmt|;
comment|/* dst[6] + src[6] */
name|u_char
name|mask
index|[
literal|12
index|]
decl_stmt|;
comment|/* dst[6] + src[6] */
block|}
name|ipfw_insn_mac
typedef|;
end_typedef

begin_comment
comment|/*  * This is used for interface match rules (recv xx, xmit xx)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_if
block|{
name|ipfw_insn
name|o
decl_stmt|;
union|union
block|{
name|struct
name|in_addr
name|ip
decl_stmt|;
name|int32_t
name|unit
decl_stmt|;
block|}
name|p
union|;
name|char
name|name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
name|ipfw_insn_if
typedef|;
end_typedef

begin_comment
comment|/*  * This is used for pipe and queue actions, which need to store  * a single pointer (which can have different size on different  * architectures.  * Note that, because of previous instructions, pipe_ptr might  * be unaligned in the overall structure, so it needs to be  * manipulated with care.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_pipe
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|void
modifier|*
name|pipe_ptr
decl_stmt|;
comment|/* XXX */
block|}
name|ipfw_insn_pipe
typedef|;
end_typedef

begin_comment
comment|/*  * This is used for limit rules.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_limit
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|u_int8_t
name|_pad
decl_stmt|;
name|u_int8_t
name|limit_mask
decl_stmt|;
comment|/* combination of DYN_* below	*/
define|#
directive|define
name|DYN_SRC_ADDR
value|0x1
define|#
directive|define
name|DYN_SRC_PORT
value|0x2
define|#
directive|define
name|DYN_DST_ADDR
value|0x4
define|#
directive|define
name|DYN_DST_PORT
value|0x8
name|u_int16_t
name|conn_limit
decl_stmt|;
block|}
name|ipfw_insn_limit
typedef|;
end_typedef

begin_comment
comment|/*  * This is used for log instructions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_log
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|u_int32_t
name|max_log
decl_stmt|;
comment|/* how many do we log -- 0 = all */
name|u_int32_t
name|log_left
decl_stmt|;
comment|/* how many left to log 	*/
block|}
name|ipfw_insn_log
typedef|;
end_typedef

begin_comment
comment|/*  * Here we have the structure representing an ipfw rule.  *  * It starts with a general area (with link fields and counters)  * followed by an array of one or more instructions, which the code  * accesses as an array of 32-bit values.  *  * Given a rule pointer  r:  *  *  r->cmd		is the start of the first instruction.  *  ACTION_PTR(r)	is the start of the first action (things to do  *			once a rule matched).  *  * When assembling instruction, remember the following:  *  *  + if a rule has a "keep-state" (or "limit") option, then the  *	first instruction (at r->cmd) MUST BE an O_PROBE_STATE  *  + if a rule has a "log" option, then the first action  *	(at ACTION_PTR(r)) MUST be O_LOG  *  * NOTE: we use a simple linked list of rules because we never need  * 	to delete a rule without scanning the list. We do not use  *	queue(3) macros for portability and readability.  */
end_comment

begin_struct
struct|struct
name|ip_fw
block|{
name|struct
name|ip_fw
modifier|*
name|next
decl_stmt|;
comment|/* linked list of rules		*/
name|struct
name|ip_fw
modifier|*
name|next_rule
decl_stmt|;
comment|/* ptr to next [skipto] rule	*/
name|u_int16_t
name|act_ofs
decl_stmt|;
comment|/* offset of action in 32-bit units */
name|u_int16_t
name|cmd_len
decl_stmt|;
comment|/* # of 32-bit words in cmd	*/
name|u_int16_t
name|rulenum
decl_stmt|;
comment|/* rule number			*/
name|u_int8_t
name|set
decl_stmt|;
comment|/* rule set (0..31)		*/
name|u_int8_t
name|_pad
decl_stmt|;
comment|/* padding			*/
comment|/* These fields are present in all rules.			*/
name|u_int64_t
name|pcnt
decl_stmt|;
comment|/* Packet counter		*/
name|u_int64_t
name|bcnt
decl_stmt|;
comment|/* Byte counter			*/
name|u_int32_t
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

begin_define
define|#
directive|define
name|ACTION_PTR
parameter_list|(
name|rule
parameter_list|)
define|\
value|(ipfw_insn *)( (u_int32_t *)((rule)->cmd) + ((rule)->act_ofs) )
end_define

begin_define
define|#
directive|define
name|RULESIZE
parameter_list|(
name|rule
parameter_list|)
value|(sizeof(struct ip_fw) + \ 	((struct ip_fw *)(rule))->cmd_len * 4 - 4)
end_define

begin_comment
comment|/*  * This structure is used as a flow mask and a flow id for various  * parts of the code.  */
end_comment

begin_struct
struct|struct
name|ipfw_flow_id
block|{
name|u_int32_t
name|dst_ip
decl_stmt|;
name|u_int32_t
name|src_ip
decl_stmt|;
name|u_int16_t
name|dst_port
decl_stmt|;
name|u_int16_t
name|src_port
decl_stmt|;
name|u_int8_t
name|proto
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
comment|/* protocol-specific flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * dynamic ipfw rule  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ipfw_dyn_rule
name|ipfw_dyn_rule
typedef|;
end_typedef

begin_struct
struct|struct
name|_ipfw_dyn_rule
block|{
name|ipfw_dyn_rule
modifier|*
name|next
decl_stmt|;
comment|/* linked list of rules.	*/
name|struct
name|ip_fw
modifier|*
name|rule
decl_stmt|;
comment|/* pointer to rule		*/
name|ipfw_dyn_rule
modifier|*
name|parent
decl_stmt|;
comment|/* pointer to parent rule	*/
name|u_int64_t
name|pcnt
decl_stmt|;
comment|/* packet match counter		*/
name|u_int64_t
name|bcnt
decl_stmt|;
comment|/* byte match counter		*/
name|struct
name|ipfw_flow_id
name|id
decl_stmt|;
comment|/* (masked) flow id		*/
name|u_int32_t
name|expire
decl_stmt|;
comment|/* expire time			*/
name|u_int32_t
name|bucket
decl_stmt|;
comment|/* which bucket in hash table	*/
name|u_int32_t
name|state
decl_stmt|;
comment|/* state of this rule (typically a 					 * combination of TCP flags) 					 */
name|u_int32_t
name|ack_fwd
decl_stmt|;
comment|/* most recent ACKs in forward	*/
name|u_int32_t
name|ack_rev
decl_stmt|;
comment|/* and reverse directions (used	*/
comment|/* to generate keepalives)	*/
name|u_int16_t
name|dyn_type
decl_stmt|;
comment|/* rule type			*/
name|u_int16_t
name|count
decl_stmt|;
comment|/* refcount			*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for IP option names.  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_IPOPT_LSRR
value|0x01
end_define

begin_define
define|#
directive|define
name|IP_FW_IPOPT_SSRR
value|0x02
end_define

begin_define
define|#
directive|define
name|IP_FW_IPOPT_RR
value|0x04
end_define

begin_define
define|#
directive|define
name|IP_FW_IPOPT_TS
value|0x08
end_define

begin_comment
comment|/*  * Definitions for TCP option names.  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TCPOPT_MSS
value|0x01
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPOPT_WINDOW
value|0x02
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPOPT_SACK
value|0x04
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPOPT_TS
value|0x08
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPOPT_CC
value|0x10
end_define

begin_define
define|#
directive|define
name|ICMP_REJECT_RST
value|0x100
end_define

begin_comment
comment|/* fake ICMP code (send a TCP RST) */
end_comment

begin_comment
comment|/*  * Main firewall chains definitions and global var's definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IP_FW_PORT_DYNT_FLAG
value|0x10000
end_define

begin_define
define|#
directive|define
name|IP_FW_PORT_TEE_FLAG
value|0x20000
end_define

begin_define
define|#
directive|define
name|IP_FW_PORT_DENY_FLAG
value|0x40000
end_define

begin_comment
comment|/*  * arguments for calling ipfw_chk() and dummynet_io(). We put them  * all into a structure because this way it is easier and more  * efficient to pass variables around and extend the interface.  */
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
name|ip_fw
modifier|*
name|rule
decl_stmt|;
comment|/* matching rule		*/
name|struct
name|ether_header
modifier|*
name|eh
decl_stmt|;
comment|/* for bridged packets		*/
name|struct
name|route
modifier|*
name|ro
decl_stmt|;
comment|/* for dummynet			*/
name|struct
name|sockaddr_in
modifier|*
name|dst
decl_stmt|;
comment|/* for dummynet			*/
name|int
name|flags
decl_stmt|;
comment|/* for dummynet			*/
name|struct
name|ipfw_flow_id
name|f_id
decl_stmt|;
comment|/* grabbed from IP header	*/
name|u_int16_t
name|divert_rule
decl_stmt|;
comment|/* divert cookie		*/
name|u_int32_t
name|retval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function definitions.  */
end_comment

begin_comment
comment|/* Firewall hooks */
end_comment

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dn_flow_set
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|flush_pipe_ptrs
parameter_list|(
name|struct
name|dn_flow_set
modifier|*
name|match
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* used by dummynet */
end_comment

begin_typedef
typedef|typedef
name|int
name|ip_fw_chk_t
parameter_list|(
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ip_fw_ctl_t
parameter_list|(
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|ip_fw_chk_t
modifier|*
name|ip_fw_chk_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ip_fw_ctl_t
modifier|*
name|ip_fw_ctl_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fw_one_pass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fw_enable
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IPFW_LOADED
value|(ip_fw_chk_ptr != NULL)
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
comment|/* _IPFW2_H */
end_comment

end_unit

