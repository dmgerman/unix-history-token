begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Luigi Rizzo, Universita` di Pisa  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/*  * The kernel representation of ipfw rules is made of a list of  * 'instructions' (for all practical purposes equivalent to BPF  * instructions), which specify which fields of the packet  * (or its metadata) should be analysed.  *  * Each instruction is stored in a structure which begins with  * "ipfw_insn", and can contain extra fields depending on the  * instruction type (listed below).  * Note that the code is written so that individual instructions  * have a size which is a multiple of 32 bits. This means that, if  * such structures contain pointers or other 64-bit entities,  * (there is just one instance now) they may end up unaligned on  * 64-bit architectures, so the must be handled with care.  *  * "enum ipfw_opcodes" are the opcodes supported. We can have up  * to 256 different opcodes. When adding new opcodes, they should  * be appended to the end of the opcode list before O_LAST_OPCODE,  * this will prevent the ABI from being broken, otherwise users  * will have to recompile ipfw(8) when they update the kernel.  */
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
name|O_VERSRCREACH
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
comment|/* 	 * These are really 'actions'. 	 */
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
comment|/* 	 * More opcodes. 	 */
name|O_IPSEC
block|,
comment|/* has ipsec history 		*/
name|O_IP_SRC_LOOKUP
block|,
comment|/* arg1=table number, u32=value	*/
name|O_IP_DST_LOOKUP
block|,
comment|/* arg1=table number, u32=value	*/
name|O_ANTISPOOF
block|,
comment|/* none				*/
name|O_JAIL
block|,
comment|/* u32 = id			*/
name|O_ALTQ
block|,
comment|/* u32 = altq classif. qid	*/
name|O_DIVERTED
block|,
comment|/* arg1=bitmap (1:loop, 2:out)	*/
name|O_TCPDATALEN
block|,
comment|/* arg1 = tcp data len		*/
name|O_IP6_SRC
block|,
comment|/* address without mask		*/
name|O_IP6_SRC_ME
block|,
comment|/* my addresses			*/
name|O_IP6_SRC_MASK
block|,
comment|/* address with the mask	*/
name|O_IP6_DST
block|,
name|O_IP6_DST_ME
block|,
name|O_IP6_DST_MASK
block|,
name|O_FLOW6ID
block|,
comment|/* for flow id tag in the ipv6 pkt */
name|O_ICMP6TYPE
block|,
comment|/* icmp6 packet type filtering	*/
name|O_EXT_HDR
block|,
comment|/* filtering for ipv6 extension header */
name|O_IP6
block|,
comment|/* 	 * actions for ng_ipfw 	 */
name|O_NETGRAPH
block|,
comment|/* send to ng_ipfw		*/
name|O_NGTEE
block|,
comment|/* copy to ng_ipfw		*/
name|O_IP4
block|,
name|O_UNREACH6
block|,
comment|/* arg1=icmpv6 code arg (deny)  */
name|O_TAG
block|,
comment|/* arg1=tag number */
name|O_TAGGED
block|,
comment|/* arg1=tag number */
name|O_LAST_OPCODE
comment|/* not an opcode!		*/
block|}
enum|;
end_enum

begin_comment
comment|/*  * The extension header are filtered only for presence using a bit  * vector with a flag for each header.  */
end_comment

begin_define
define|#
directive|define
name|EXT_FRAGMENT
value|0x1
end_define

begin_define
define|#
directive|define
name|EXT_HOPOPTS
value|0x2
end_define

begin_define
define|#
directive|define
name|EXT_ROUTING
value|0x4
end_define

begin_define
define|#
directive|define
name|EXT_AH
value|0x8
end_define

begin_define
define|#
directive|define
name|EXT_ESP
value|0x10
end_define

begin_define
define|#
directive|define
name|EXT_DSTOPTS
value|0x20
end_define

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

begin_define
define|#
directive|define
name|MTAG_IPFW
value|1148380143
end_define

begin_comment
comment|/* IPFW-tagged cookie */
end_comment

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
comment|/*  * This is used to forward to a given address (ip).  */
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
comment|/*  * This is used for interface match rules (recv xx, xmit xx).  */
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
name|int
name|glob
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
comment|/*  * This is used for storing an altq queue id number.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_altq
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|u_int32_t
name|qid
decl_stmt|;
block|}
name|ipfw_insn_altq
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
comment|/*  * This is used for log instructions.  */
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
comment|/* Apply ipv6 mask on ipv6 addr */
end_comment

begin_define
define|#
directive|define
name|APPLY_MASK
parameter_list|(
name|addr
parameter_list|,
name|mask
parameter_list|)
define|\
value|(addr)->__u6_addr.__u6_addr32[0]&= (mask)->__u6_addr.__u6_addr32[0]; \     (addr)->__u6_addr.__u6_addr32[1]&= (mask)->__u6_addr.__u6_addr32[1]; \     (addr)->__u6_addr.__u6_addr32[2]&= (mask)->__u6_addr.__u6_addr32[2]; \     (addr)->__u6_addr.__u6_addr32[3]&= (mask)->__u6_addr.__u6_addr32[3];
end_define

begin_comment
comment|/* Structure for ipv6 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_ip6
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|struct
name|in6_addr
name|addr6
decl_stmt|;
name|struct
name|in6_addr
name|mask6
decl_stmt|;
block|}
name|ipfw_insn_ip6
typedef|;
end_typedef

begin_comment
comment|/* Used to support icmp6 types */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_icmp6
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|uint32_t
name|d
index|[
literal|7
index|]
decl_stmt|;
comment|/* XXX This number si related to the netinet/icmp6.h                        *     define ICMP6_MAXTYPE                        *     as follows: n = ICMP6_MAXTYPE/32 + 1                         *     Actually is 203                         */
block|}
name|ipfw_insn_icmp6
typedef|;
end_typedef

begin_comment
comment|/*  * Here we have the structure representing an ipfw rule.  *  * It starts with a general area (with link fields and counters)  * followed by an array of one or more instructions, which the code  * accesses as an array of 32-bit values.  *  * Given a rule pointer  r:  *  *  r->cmd		is the start of the first instruction.  *  ACTION_PTR(r)	is the start of the first action (things to do  *			once a rule matched).  *  * When assembling instruction, remember the following:  *  *  + if a rule has a "keep-state" (or "limit") option, then the  *	first instruction (at r->cmd) MUST BE an O_PROBE_STATE  *  + if a rule has a "log" option, then the first action  *	(at ACTION_PTR(r)) MUST be O_LOG  *  + if a rule has an "altq" option, it comes after "log"  *  + if a rule has an O_TAG option, it comes after "log" and "altq"  *  * NOTE: we use a simple linked list of rules because we never need  * 	to delete a rule without scanning the list. We do not use  *	queue(3) macros for portability and readability.  */
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
comment|/* 'next_rule' is used to pass up 'set_disable' status		*/
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
define|#
directive|define
name|RESVD_SET
value|31
comment|/* set for default and persistent rules */
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
name|uint8_t
name|addr_type
decl_stmt|;
comment|/* 4 = ipv4, 6 = ipv6, 1=ether ? */
name|struct
name|in6_addr
name|dst_ip6
decl_stmt|;
comment|/* could also store MAC addr! */
name|struct
name|in6_addr
name|src_ip6
decl_stmt|;
name|u_int32_t
name|flow_id6
decl_stmt|;
name|u_int32_t
name|frag_id6
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IS_IP6_FLOW_ID
parameter_list|(
name|id
parameter_list|)
value|((id)->addr_type == 6)
end_define

begin_comment
comment|/*  * Dynamic ipfw rule.  */
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
comment|/* 'rule' is used to pass up the rule number (from the parent)	*/
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

begin_define
define|#
directive|define
name|ICMP6_UNREACH_RST
value|0x100
end_define

begin_comment
comment|/* fake ICMPv6 code (send a TCP RST) */
end_comment

begin_comment
comment|/*  * These are used for lookup tables.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_table_entry
block|{
name|in_addr_t
name|addr
decl_stmt|;
comment|/* network address		*/
name|u_int32_t
name|value
decl_stmt|;
comment|/* value			*/
name|u_int16_t
name|tbl
decl_stmt|;
comment|/* table number			*/
name|u_int8_t
name|masklen
decl_stmt|;
comment|/* mask length			*/
block|}
name|ipfw_table_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_table
block|{
name|u_int32_t
name|size
decl_stmt|;
comment|/* size of entries in bytes	*/
name|u_int32_t
name|cnt
decl_stmt|;
comment|/* # of entries			*/
name|u_int16_t
name|tbl
decl_stmt|;
comment|/* table number			*/
name|ipfw_table_entry
name|ent
index|[
literal|0
index|]
decl_stmt|;
comment|/* entries			*/
block|}
name|ipfw_table
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IP_FW_TABLEARG
value|65535
end_define

begin_comment
comment|/*  * Main firewall chains definitions and global var's definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
block|, }
enum|;
end_enum

begin_comment
comment|/* flags for divert mtag */
end_comment

begin_define
define|#
directive|define
name|IP_FW_DIVERT_LOOPBACK_FLAG
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IP_FW_DIVERT_OUTPUT_FLAG
value|0x00100000
end_define

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
name|ipfw_flow_id
name|f_id
decl_stmt|;
comment|/* grabbed from IP header	*/
name|u_int32_t
name|cookie
decl_stmt|;
comment|/* a cookie depending on rule action */
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
name|int
name|ipfw_check_in
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_check_out
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|inpcb
modifier|*
name|inp
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* For kernel ipfw_ether and ipfw_bridge. */
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

begin_decl_stmt
specifier|extern
name|ip_fw_chk_t
modifier|*
name|ip_fw_chk_ptr
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

