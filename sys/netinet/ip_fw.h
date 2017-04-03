begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Luigi Rizzo, Universita` di Pisa  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/*  * The default rule number.  By the design of ip_fw, the default rule  * is the last one, so its number can also serve as the highest number  * allowed for a rule.  The ip_fw code relies on both meanings of this  * constant.   */
end_comment

begin_define
define|#
directive|define
name|IPFW_DEFAULT_RULE
value|65535
end_define

begin_define
define|#
directive|define
name|RESVD_SET
value|31
end_define

begin_comment
comment|/*set for default and persistent rules*/
end_comment

begin_define
define|#
directive|define
name|IPFW_MAX_SETS
value|32
end_define

begin_comment
comment|/* Number of sets supported by ipfw*/
end_comment

begin_comment
comment|/*  * Compat values for old clients  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|IPFW_TABLES_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|IPFW_TABLES_DEFAULT
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Most commands (queue, pipe, tag, untag, limit...) can have a 16-bit  * argument between 1 and 65534. The value 0 (IP_FW_TARG) is used  * to represent 'tablearg' value, e.g.  indicate the use of a 'tablearg'  * result of the most recent table() lookup.  * Note that 16bit is only a historical limit, resulting from  * the use of a 16-bit fields for that value. In reality, we can have  * 2^32 pipes, queues, tag values and so on.  */
end_comment

begin_define
define|#
directive|define
name|IPFW_ARG_MIN
value|1
end_define

begin_define
define|#
directive|define
name|IPFW_ARG_MAX
value|65534
end_define

begin_define
define|#
directive|define
name|IP_FW_TABLEARG
value|65535
end_define

begin_comment
comment|/* Compat value for old clients */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TARG
value|0
end_define

begin_comment
comment|/* Current tablearg value */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT44_GLOBAL
value|65535
end_define

begin_comment
comment|/* arg1 value for "nat global" */
end_comment

begin_comment
comment|/*  * Number of entries in the call stack of the call/return commands.  * Call stack currently is an uint16_t array with rule numbers.  */
end_comment

begin_define
define|#
directive|define
name|IPFW_CALLSTACK_SIZE
value|16
end_define

begin_comment
comment|/* IP_FW3 header/opcodes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ip_fw3_opheader
block|{
name|uint16_t
name|opcode
decl_stmt|;
comment|/* Operation opcode */
name|uint16_t
name|version
decl_stmt|;
comment|/* Opcode version */
name|uint16_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* Align to 64-bit boundary */
block|}
name|ip_fw3_opheader
typedef|;
end_typedef

begin_comment
comment|/* IP_FW3 opcodes */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XADD
value|86
end_define

begin_comment
comment|/* add entry */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XDEL
value|87
end_define

begin_comment
comment|/* delete entry */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XGETSIZE
value|88
end_define

begin_comment
comment|/* get table size (deprecated) */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XLIST
value|89
end_define

begin_comment
comment|/* list table contents */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XDESTROY
value|90
end_define

begin_comment
comment|/* destroy table */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLES_XLIST
value|92
end_define

begin_comment
comment|/* list all tables  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XINFO
value|93
end_define

begin_comment
comment|/* request info for one table */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XFLUSH
value|94
end_define

begin_comment
comment|/* flush table data */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XCREATE
value|95
end_define

begin_comment
comment|/* create new table  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XMODIFY
value|96
end_define

begin_comment
comment|/* modify existing table */
end_comment

begin_define
define|#
directive|define
name|IP_FW_XGET
value|97
end_define

begin_comment
comment|/* Retrieve configuration */
end_comment

begin_define
define|#
directive|define
name|IP_FW_XADD
value|98
end_define

begin_comment
comment|/* add rule */
end_comment

begin_define
define|#
directive|define
name|IP_FW_XDEL
value|99
end_define

begin_comment
comment|/* del rule */
end_comment

begin_define
define|#
directive|define
name|IP_FW_XMOVE
value|100
end_define

begin_comment
comment|/* move rules to different set  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_XZERO
value|101
end_define

begin_comment
comment|/* clear accounting */
end_comment

begin_define
define|#
directive|define
name|IP_FW_XRESETLOG
value|102
end_define

begin_comment
comment|/* zero rules logs */
end_comment

begin_define
define|#
directive|define
name|IP_FW_SET_SWAP
value|103
end_define

begin_comment
comment|/* Swap between 2 sets */
end_comment

begin_define
define|#
directive|define
name|IP_FW_SET_MOVE
value|104
end_define

begin_comment
comment|/* Move one set to another one */
end_comment

begin_define
define|#
directive|define
name|IP_FW_SET_ENABLE
value|105
end_define

begin_comment
comment|/* Enable/disable sets */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XFIND
value|106
end_define

begin_comment
comment|/* finds an entry */
end_comment

begin_define
define|#
directive|define
name|IP_FW_XIFLIST
value|107
end_define

begin_comment
comment|/* list tracked interfaces */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLES_ALIST
value|108
end_define

begin_comment
comment|/* list table algorithms */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_XSWAP
value|109
end_define

begin_comment
comment|/* swap two tables */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TABLE_VLIST
value|110
end_define

begin_comment
comment|/* dump table value hash */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT44_XCONFIG
value|111
end_define

begin_comment
comment|/* Create/modify NAT44 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT44_DESTROY
value|112
end_define

begin_comment
comment|/* Destroys NAT44 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT44_XGETCONFIG
value|113
end_define

begin_comment
comment|/* Get NAT44 instance config */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT44_LIST_NAT
value|114
end_define

begin_comment
comment|/* List all NAT44 instances */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT44_XGETLOG
value|115
end_define

begin_comment
comment|/* Get log from NAT44 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_DUMP_SOPTCODES
value|116
end_define

begin_comment
comment|/* Dump available sopts/versions */
end_comment

begin_define
define|#
directive|define
name|IP_FW_DUMP_SRVOBJECTS
value|117
end_define

begin_comment
comment|/* Dump existing named objects */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64STL_CREATE
value|130
end_define

begin_comment
comment|/* Create stateless NAT64 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64STL_DESTROY
value|131
end_define

begin_comment
comment|/* Destroy stateless NAT64 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64STL_CONFIG
value|132
end_define

begin_comment
comment|/* Modify stateless NAT64 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64STL_LIST
value|133
end_define

begin_comment
comment|/* List stateless NAT64 instances */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64STL_STATS
value|134
end_define

begin_comment
comment|/* Get NAT64STL instance statistics */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64STL_RESET_STATS
value|135
end_define

begin_comment
comment|/* Reset NAT64STL instance statistics */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64LSN_CREATE
value|140
end_define

begin_comment
comment|/* Create stateful NAT64 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64LSN_DESTROY
value|141
end_define

begin_comment
comment|/* Destroy stateful NAT64 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64LSN_CONFIG
value|142
end_define

begin_comment
comment|/* Modify stateful NAT64 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64LSN_LIST
value|143
end_define

begin_comment
comment|/* List stateful NAT64 instances */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64LSN_STATS
value|144
end_define

begin_comment
comment|/* Get NAT64LSN instance statistics */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64LSN_LIST_STATES
value|145
end_define

begin_comment
comment|/* Get stateful NAT64 states */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NAT64LSN_RESET_STATS
value|146
end_define

begin_comment
comment|/* Reset NAT64LSN instance statistics */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NPTV6_CREATE
value|150
end_define

begin_comment
comment|/* Create NPTv6 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NPTV6_DESTROY
value|151
end_define

begin_comment
comment|/* Destroy NPTv6 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NPTV6_CONFIG
value|152
end_define

begin_comment
comment|/* Modify NPTv6 instance */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NPTV6_LIST
value|153
end_define

begin_comment
comment|/* List NPTv6 instances */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NPTV6_STATS
value|154
end_define

begin_comment
comment|/* Get NPTv6 instance statistics */
end_comment

begin_define
define|#
directive|define
name|IP_FW_NPTV6_RESET_STATS
value|155
end_define

begin_comment
comment|/* Reset NPTv6 instance statistics */
end_comment

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
name|O_NAT
block|,
comment|/* nope                         */
name|O_REASS
block|,
comment|/* none                         */
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
name|O_SETFIB
block|,
comment|/* arg1=FIB number */
name|O_FIB
block|,
comment|/* arg1=FIB desired fib number */
name|O_SOCKARG
block|,
comment|/* socket argument */
name|O_CALLRETURN
block|,
comment|/* arg1=called rule number */
name|O_FORWARD_IP6
block|,
comment|/* fwd sockaddr_in6             */
name|O_DSCP
block|,
comment|/* 2 u32 = DSCP mask */
name|O_SETDSCP
block|,
comment|/* arg1=DSCP value */
name|O_IP_FLOW_LOOKUP
block|,
comment|/* arg1=table number, u32=value	*/
name|O_EXTERNAL_ACTION
block|,
comment|/* arg1=id of external action handler */
name|O_EXTERNAL_INSTANCE
block|,
comment|/* arg1=id of eaction handler instance */
name|O_EXTERNAL_DATA
block|,
comment|/* variable length data */
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

begin_define
define|#
directive|define
name|EXT_RTHDR0
value|0x40
end_define

begin_define
define|#
directive|define
name|EXT_RTHDR2
value|0x80
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
name|u_int8_t
name|opcode
decl_stmt|;
name|u_int8_t
name|len
decl_stmt|;
comment|/* number of 32-bit words */
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
comment|/*  * This is used to forward to a given address (ipv6).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_sa6
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|struct
name|sockaddr_in6
name|sa
decl_stmt|;
block|}
name|ipfw_insn_sa6
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
name|uint16_t
name|kidx
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
comment|/* Legacy NAT structures, compat only */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * Data structures required by both ipfw(8) and ipfw(4) but not part of the  * management API are protected by IPFW_INTERNAL.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPFW_INTERNAL
end_ifdef

begin_comment
comment|/* Server pool support (LSNAT). */
end_comment

begin_struct
struct|struct
name|cfg_spool
block|{
name|LIST_ENTRY
argument_list|(
argument|cfg_spool
argument_list|)
name|_next
expr_stmt|;
comment|/* chain of spool instances */
name|struct
name|in_addr
name|addr
decl_stmt|;
name|u_short
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Redirect modes id. */
end_comment

begin_define
define|#
directive|define
name|REDIR_ADDR
value|0x01
end_define

begin_define
define|#
directive|define
name|REDIR_PORT
value|0x02
end_define

begin_define
define|#
directive|define
name|REDIR_PROTO
value|0x04
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IPFW_INTERNAL
end_ifdef

begin_comment
comment|/* Nat redirect configuration. */
end_comment

begin_struct
struct|struct
name|cfg_redir
block|{
name|LIST_ENTRY
argument_list|(
argument|cfg_redir
argument_list|)
name|_next
expr_stmt|;
comment|/* chain of redir instances */
name|u_int16_t
name|mode
decl_stmt|;
comment|/* type of redirect mode */
name|struct
name|in_addr
name|laddr
decl_stmt|;
comment|/* local ip address */
name|struct
name|in_addr
name|paddr
decl_stmt|;
comment|/* public ip address */
name|struct
name|in_addr
name|raddr
decl_stmt|;
comment|/* remote ip address */
name|u_short
name|lport
decl_stmt|;
comment|/* local port */
name|u_short
name|pport
decl_stmt|;
comment|/* public port */
name|u_short
name|rport
decl_stmt|;
comment|/* remote port  */
name|u_short
name|pport_cnt
decl_stmt|;
comment|/* number of public ports */
name|u_short
name|rport_cnt
decl_stmt|;
comment|/* number of remote ports */
name|int
name|proto
decl_stmt|;
comment|/* protocol: tcp/udp */
name|struct
name|alias_link
modifier|*
modifier|*
name|alink
decl_stmt|;
comment|/* num of entry in spool chain */
name|u_int16_t
name|spool_cnt
decl_stmt|;
comment|/* chain of spool instances */
name|LIST_HEAD
argument_list|(
argument|spool_chain
argument_list|,
argument|cfg_spool
argument_list|)
name|spool_chain
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPFW_INTERNAL
end_ifdef

begin_comment
comment|/* Nat configuration data struct. */
end_comment

begin_struct
struct|struct
name|cfg_nat
block|{
comment|/* chain of nat instances */
name|LIST_ENTRY
argument_list|(
argument|cfg_nat
argument_list|)
name|_next
expr_stmt|;
name|int
name|id
decl_stmt|;
comment|/* nat id */
name|struct
name|in_addr
name|ip
decl_stmt|;
comment|/* nat ip address */
name|char
name|if_name
index|[
name|IF_NAMESIZE
index|]
decl_stmt|;
comment|/* interface name */
name|int
name|mode
decl_stmt|;
comment|/* aliasing mode */
name|struct
name|libalias
modifier|*
name|lib
decl_stmt|;
comment|/* libalias instance */
comment|/* number of entry in spool chain */
name|int
name|redir_cnt
decl_stmt|;
comment|/* chain of redir instances */
name|LIST_HEAD
argument_list|(
argument|redir_chain
argument_list|,
argument|cfg_redir
argument_list|)
name|redir_chain
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SOF_NAT
value|sizeof(struct cfg_nat)
end_define

begin_define
define|#
directive|define
name|SOF_REDIR
value|sizeof(struct cfg_redir)
end_define

begin_define
define|#
directive|define
name|SOF_SPOOL
value|sizeof(struct cfg_spool)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef _KERNEL */
end_comment

begin_struct
struct|struct
name|nat44_cfg_spool
block|{
name|struct
name|in_addr
name|addr
decl_stmt|;
name|uint16_t
name|port
decl_stmt|;
name|uint16_t
name|spare
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NAT44_REDIR_ADDR
value|0x01
end_define

begin_define
define|#
directive|define
name|NAT44_REDIR_PORT
value|0x02
end_define

begin_define
define|#
directive|define
name|NAT44_REDIR_PROTO
value|0x04
end_define

begin_comment
comment|/* Nat redirect configuration. */
end_comment

begin_struct
struct|struct
name|nat44_cfg_redir
block|{
name|struct
name|in_addr
name|laddr
decl_stmt|;
comment|/* local ip address */
name|struct
name|in_addr
name|paddr
decl_stmt|;
comment|/* public ip address */
name|struct
name|in_addr
name|raddr
decl_stmt|;
comment|/* remote ip address */
name|uint16_t
name|lport
decl_stmt|;
comment|/* local port */
name|uint16_t
name|pport
decl_stmt|;
comment|/* public port */
name|uint16_t
name|rport
decl_stmt|;
comment|/* remote port  */
name|uint16_t
name|pport_cnt
decl_stmt|;
comment|/* number of public ports */
name|uint16_t
name|rport_cnt
decl_stmt|;
comment|/* number of remote ports */
name|uint16_t
name|mode
decl_stmt|;
comment|/* type of redirect mode */
name|uint16_t
name|spool_cnt
decl_stmt|;
comment|/* num of entry in spool chain */
name|uint16_t
name|spare
decl_stmt|;
name|uint32_t
name|proto
decl_stmt|;
comment|/* protocol: tcp/udp */
block|}
struct|;
end_struct

begin_comment
comment|/* Nat configuration data struct. */
end_comment

begin_struct
struct|struct
name|nat44_cfg_nat
block|{
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|/* nat name */
name|char
name|if_name
index|[
literal|64
index|]
decl_stmt|;
comment|/* interface name */
name|uint32_t
name|size
decl_stmt|;
comment|/* structure size incl. redirs */
name|struct
name|in_addr
name|ip
decl_stmt|;
comment|/* nat IPv4 address */
name|uint32_t
name|mode
decl_stmt|;
comment|/* aliasing mode */
name|uint32_t
name|redir_cnt
decl_stmt|;
comment|/* number of entry in spool chain */
block|}
struct|;
end_struct

begin_comment
comment|/* Nat command. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_insn_nat
block|{
name|ipfw_insn
name|o
decl_stmt|;
name|struct
name|cfg_nat
modifier|*
name|nat
decl_stmt|;
block|}
name|ipfw_insn_nat
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
comment|/*  * Here we have the structure representing an ipfw rule.  *  * Layout:  * struct ip_fw_rule  * [ counter block, size = rule->cntr_len ]  * [ one or more instructions, size = rule->cmd_len * 4 ]  *  * It starts with a general area (with link fields).  * Counter block may be next (if rule->cntr_len> 0),  * followed by an array of one or more instructions, which the code  * accesses as an array of 32-bit values. rule->cmd_len represents  * the total instructions legth in u32 worrd, while act_ofs represents  * rule action offset in u32 words.  *  * When assembling instruction, remember the following:  *  *  + if a rule has a "keep-state" (or "limit") option, then the  *	first instruction (at r->cmd) MUST BE an O_PROBE_STATE  *  + if a rule has a "log" option, then the first action  *	(at ACTION_PTR(r)) MUST be O_LOG  *  + if a rule has an "altq" option, it comes after "log"  *  + if a rule has an O_TAG option, it comes after "log" and "altq"  *  *  * All structures (excluding instructions) are u64-aligned.  * Please keep this.  */
end_comment

begin_struct
struct|struct
name|ip_fw_rule
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
name|spare
decl_stmt|;
name|uint8_t
name|set
decl_stmt|;
comment|/* rule set (0..31)		*/
name|uint8_t
name|flags
decl_stmt|;
comment|/* rule flags			*/
name|uint32_t
name|rulenum
decl_stmt|;
comment|/* rule number			*/
name|uint32_t
name|id
decl_stmt|;
comment|/* rule id			*/
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
name|IPFW_RULE_NOOPT
value|0x01
end_define

begin_comment
comment|/* Has no options in body	*/
end_comment

begin_comment
comment|/* Unaligned version */
end_comment

begin_comment
comment|/* Base ipfw rule counter block. */
end_comment

begin_struct
struct|struct
name|ip_fw_bcounter
block|{
name|uint16_t
name|size
decl_stmt|;
comment|/* Size of counter block, bytes	*/
name|uint8_t
name|flags
decl_stmt|;
comment|/* flags for given block	*/
name|uint8_t
name|spare
decl_stmt|;
name|uint32_t
name|timestamp
decl_stmt|;
comment|/* tv_sec of last match		*/
name|uint64_t
name|pcnt
decl_stmt|;
comment|/* Packet counter		*/
name|uint64_t
name|bcnt
decl_stmt|;
comment|/* Byte counter			*/
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * Legacy rule format  */
end_comment

begin_struct
struct|struct
name|ip_fw
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

begin_endif
endif|#
directive|endif
end_endif

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
value|(sizeof(*(rule)) + (rule)->cmd_len * 4 - 4)
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|// should be moved to in.h
end_comment

begin_comment
comment|/*  * This structure is used as a flow mask and a flow id for various  * parts of the code.  * addr_type is used in userland and kernel to mark the address type.  * fib is used in the kernel to record the fib in use.  * _flags is used in the kernel to store tcp flags for dynamic rules.  */
end_comment

begin_struct
struct|struct
name|ipfw_flow_id
block|{
name|uint32_t
name|dst_ip
decl_stmt|;
name|uint32_t
name|src_ip
decl_stmt|;
name|uint16_t
name|dst_port
decl_stmt|;
name|uint16_t
name|src_port
decl_stmt|;
name|uint8_t
name|fib
decl_stmt|;
name|uint8_t
name|proto
decl_stmt|;
name|uint8_t
name|_flags
decl_stmt|;
comment|/* protocol-specific flags */
name|uint8_t
name|addr_type
decl_stmt|;
comment|/* 4=ip4, 6=ip6, 1=ether ? */
name|struct
name|in6_addr
name|dst_ip6
decl_stmt|;
name|struct
name|in6_addr
name|src_ip6
decl_stmt|;
name|uint32_t
name|flow_id6
decl_stmt|;
name|uint32_t
name|extra
decl_stmt|;
comment|/* queue/pipe or frag_id */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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
name|u_int16_t
name|kidx
decl_stmt|;
comment|/* index of named object */
block|}
name|__packed
name|__aligned
argument_list|(
literal|8
argument_list|)
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

begin_define
define|#
directive|define
name|IPFW_TABLE_ADDR
value|1
end_define

begin_comment
comment|/* Table for holding IPv4/IPv6 prefixes */
end_comment

begin_define
define|#
directive|define
name|IPFW_TABLE_INTERFACE
value|2
end_define

begin_comment
comment|/* Table for holding interface names */
end_comment

begin_define
define|#
directive|define
name|IPFW_TABLE_NUMBER
value|3
end_define

begin_comment
comment|/* Table for holding ports/uid/gid/etc */
end_comment

begin_define
define|#
directive|define
name|IPFW_TABLE_FLOW
value|4
end_define

begin_comment
comment|/* Table for holding flow data */
end_comment

begin_define
define|#
directive|define
name|IPFW_TABLE_MAXTYPE
value|4
end_define

begin_comment
comment|/* Maximum valid number */
end_comment

begin_define
define|#
directive|define
name|IPFW_TABLE_CIDR
value|IPFW_TABLE_ADDR
end_define

begin_comment
comment|/* compat */
end_comment

begin_comment
comment|/* Value types */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_LEGACY
value|0xFFFFFFFF
end_define

begin_comment
comment|/* All data is filled in */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_SKIPTO
value|0x00000001
end_define

begin_comment
comment|/* skipto/call/callreturn */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_PIPE
value|0x00000002
end_define

begin_comment
comment|/* pipe/queue */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_FIB
value|0x00000004
end_define

begin_comment
comment|/* setfib */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_NAT
value|0x00000008
end_define

begin_comment
comment|/* nat */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_DSCP
value|0x00000010
end_define

begin_comment
comment|/* dscp */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_TAG
value|0x00000020
end_define

begin_comment
comment|/* tag/untag */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_DIVERT
value|0x00000040
end_define

begin_comment
comment|/* divert/tee */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_NETGRAPH
value|0x00000080
end_define

begin_comment
comment|/* netgraph/ngtee */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_LIMIT
value|0x00000100
end_define

begin_comment
comment|/* limit */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_NH4
value|0x00000200
end_define

begin_comment
comment|/* IPv4 nexthop */
end_comment

begin_define
define|#
directive|define
name|IPFW_VTYPE_NH6
value|0x00000400
end_define

begin_comment
comment|/* IPv6 nexthop */
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
name|_ipfw_table_xentry
block|{
name|uint16_t
name|len
decl_stmt|;
comment|/* Total entry length		*/
name|uint8_t
name|type
decl_stmt|;
comment|/* entry type			*/
name|uint8_t
name|masklen
decl_stmt|;
comment|/* mask length			*/
name|uint16_t
name|tbl
decl_stmt|;
comment|/* table number			*/
name|uint16_t
name|flags
decl_stmt|;
comment|/* record flags			*/
name|uint32_t
name|value
decl_stmt|;
comment|/* value			*/
union|union
block|{
comment|/* Longest field needs to be aligned by 4-byte boundary	*/
name|struct
name|in6_addr
name|addr6
decl_stmt|;
comment|/* IPv6 address 		*/
name|char
name|iface
index|[
name|IF_NAMESIZE
index|]
decl_stmt|;
comment|/* interface name	*/
block|}
name|k
union|;
block|}
name|ipfw_table_xentry
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFW_TCF_INET
value|0x01
end_define

begin_comment
comment|/* CIDR flags: IPv4 record	*/
end_comment

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

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_xtable
block|{
name|ip_fw3_opheader
name|opheader
decl_stmt|;
comment|/* IP_FW3 opcode */
name|uint32_t
name|size
decl_stmt|;
comment|/* size of entries in bytes	*/
name|uint32_t
name|cnt
decl_stmt|;
comment|/* # of entries			*/
name|uint16_t
name|tbl
decl_stmt|;
comment|/* table number			*/
name|uint8_t
name|type
decl_stmt|;
comment|/* table type			*/
name|ipfw_table_xentry
name|xent
index|[
literal|0
index|]
decl_stmt|;
comment|/* entries			*/
block|}
name|ipfw_xtable
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_obj_tlv
block|{
name|uint16_t
name|type
decl_stmt|;
comment|/* TLV type */
name|uint16_t
name|flags
decl_stmt|;
comment|/* TLV-specific flags		*/
name|uint32_t
name|length
decl_stmt|;
comment|/* Total length, aligned to u64	*/
block|}
name|ipfw_obj_tlv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFW_TLV_TBL_NAME
value|1
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_TBLNAME_LIST
value|2
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_RULE_LIST
value|3
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_DYNSTATE_LIST
value|4
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_TBL_ENT
value|5
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_DYN_ENT
value|6
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_RULE_ENT
value|7
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_TBLENT_LIST
value|8
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_RANGE
value|9
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_EACTION
value|10
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_COUNTERS
value|11
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_OBJDATA
value|12
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_STATE_NAME
value|14
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_EACTION_BASE
value|1000
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_EACTION_NAME
parameter_list|(
name|arg
parameter_list|)
value|(IPFW_TLV_EACTION_BASE + (arg))
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_obj_data
block|{
name|ipfw_obj_tlv
name|head
decl_stmt|;
name|void
modifier|*
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|ipfw_obj_data
typedef|;
end_typedef

begin_comment
comment|/* Object name TLV */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_obj_ntlv
block|{
name|ipfw_obj_tlv
name|head
decl_stmt|;
comment|/* TLV header			*/
name|uint16_t
name|idx
decl_stmt|;
comment|/* Name index			*/
name|uint8_t
name|set
decl_stmt|;
comment|/* set, if applicable		*/
name|uint8_t
name|type
decl_stmt|;
comment|/* object type, if applicable	*/
name|uint32_t
name|spare
decl_stmt|;
comment|/* unused			*/
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|/* Null-terminated name		*/
block|}
name|ipfw_obj_ntlv
typedef|;
end_typedef

begin_comment
comment|/* IPv4/IPv6 L4 flow description */
end_comment

begin_struct
struct|struct
name|tflow_entry
block|{
name|uint8_t
name|af
decl_stmt|;
name|uint8_t
name|proto
decl_stmt|;
name|uint16_t
name|spare
decl_stmt|;
name|uint16_t
name|sport
decl_stmt|;
name|uint16_t
name|dport
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|struct
name|in_addr
name|sip
decl_stmt|;
name|struct
name|in_addr
name|dip
decl_stmt|;
block|}
name|a4
struct|;
struct|struct
block|{
name|struct
name|in6_addr
name|sip6
decl_stmt|;
name|struct
name|in6_addr
name|dip6
decl_stmt|;
block|}
name|a6
struct|;
block|}
name|a
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_table_value
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
name|reserved
decl_stmt|;
block|}
name|ipfw_table_value
typedef|;
end_typedef

begin_comment
comment|/* Table entry TLV */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_obj_tentry
block|{
name|ipfw_obj_tlv
name|head
decl_stmt|;
comment|/* TLV header			*/
name|uint8_t
name|subtype
decl_stmt|;
comment|/* subtype (IPv4,IPv6)		*/
name|uint8_t
name|masklen
decl_stmt|;
comment|/* mask length			*/
name|uint8_t
name|result
decl_stmt|;
comment|/* request result		*/
name|uint8_t
name|spare0
decl_stmt|;
name|uint16_t
name|idx
decl_stmt|;
comment|/* Table name index		*/
name|uint16_t
name|spare1
decl_stmt|;
union|union
block|{
comment|/* Longest field needs to be aligned by 8-byte boundary	*/
name|struct
name|in_addr
name|addr
decl_stmt|;
comment|/* IPv4 address		*/
name|uint32_t
name|key
decl_stmt|;
comment|/* uid/gid/port	*/
name|struct
name|in6_addr
name|addr6
decl_stmt|;
comment|/* IPv6 address 	*/
name|char
name|iface
index|[
name|IF_NAMESIZE
index|]
decl_stmt|;
comment|/* interface name	*/
name|struct
name|tflow_entry
name|flow
decl_stmt|;
block|}
name|k
union|;
union|union
block|{
name|ipfw_table_value
name|value
decl_stmt|;
comment|/* value data */
name|uint32_t
name|kidx
decl_stmt|;
comment|/* value kernel index */
block|}
name|v
union|;
block|}
name|ipfw_obj_tentry
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFW_TF_UPDATE
value|0x01
end_define

begin_comment
comment|/* Update record if exists	*/
end_comment

begin_comment
comment|/* Container TLV */
end_comment

begin_define
define|#
directive|define
name|IPFW_CTF_ATOMIC
value|0x01
end_define

begin_comment
comment|/* Perform atomic operation	*/
end_comment

begin_comment
comment|/* Operation results */
end_comment

begin_define
define|#
directive|define
name|IPFW_TR_IGNORED
value|0
end_define

begin_comment
comment|/* Entry was ignored (rollback)	*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TR_ADDED
value|1
end_define

begin_comment
comment|/* Entry was successfully added	*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TR_UPDATED
value|2
end_define

begin_comment
comment|/* Entry was successfully updated*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TR_DELETED
value|3
end_define

begin_comment
comment|/* Entry was successfully deleted*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TR_LIMIT
value|4
end_define

begin_comment
comment|/* Entry was ignored (limit)	*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TR_NOTFOUND
value|5
end_define

begin_comment
comment|/* Entry was not found		*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TR_EXISTS
value|6
end_define

begin_comment
comment|/* Entry already exists		*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TR_ERROR
value|7
end_define

begin_comment
comment|/* Request has failed (unknown)	*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_obj_dyntlv
block|{
name|ipfw_obj_tlv
name|head
decl_stmt|;
name|ipfw_dyn_rule
name|state
decl_stmt|;
block|}
name|ipfw_obj_dyntlv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFW_DF_LAST
value|0x01
end_define

begin_comment
comment|/* Last state in chain		*/
end_comment

begin_comment
comment|/* Containter TLVs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_obj_ctlv
block|{
name|ipfw_obj_tlv
name|head
decl_stmt|;
comment|/* TLV header			*/
name|uint32_t
name|count
decl_stmt|;
comment|/* Number of sub-TLVs		*/
name|uint16_t
name|objsize
decl_stmt|;
comment|/* Single object size		*/
name|uint8_t
name|version
decl_stmt|;
comment|/* TLV version			*/
name|uint8_t
name|flags
decl_stmt|;
comment|/* TLV-specific flags		*/
block|}
name|ipfw_obj_ctlv
typedef|;
end_typedef

begin_comment
comment|/* Range TLV */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_range_tlv
block|{
name|ipfw_obj_tlv
name|head
decl_stmt|;
comment|/* TLV header			*/
name|uint32_t
name|flags
decl_stmt|;
comment|/* Range flags			*/
name|uint16_t
name|start_rule
decl_stmt|;
comment|/* Range start			*/
name|uint16_t
name|end_rule
decl_stmt|;
comment|/* Range end			*/
name|uint32_t
name|set
decl_stmt|;
comment|/* Range set to match		 */
name|uint32_t
name|new_set
decl_stmt|;
comment|/* New set to move/swap to	*/
block|}
name|ipfw_range_tlv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFW_RCFLAG_RANGE
value|0x01
end_define

begin_comment
comment|/* rule range is set		*/
end_comment

begin_define
define|#
directive|define
name|IPFW_RCFLAG_ALL
value|0x02
end_define

begin_comment
comment|/* match ALL rules		*/
end_comment

begin_define
define|#
directive|define
name|IPFW_RCFLAG_SET
value|0x04
end_define

begin_comment
comment|/* match rules in given set	*/
end_comment

begin_comment
comment|/* User-settable flags */
end_comment

begin_define
define|#
directive|define
name|IPFW_RCFLAG_USER
value|(IPFW_RCFLAG_RANGE | IPFW_RCFLAG_ALL | \ 	IPFW_RCFLAG_SET)
end_define

begin_comment
comment|/* Internally used flags */
end_comment

begin_define
define|#
directive|define
name|IPFW_RCFLAG_DEFAULT
value|0x0100
end_define

begin_comment
comment|/* Do not skip defaul rule	*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_ta_tinfo
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/* Format flags			*/
name|uint32_t
name|spare
decl_stmt|;
name|uint8_t
name|taclass4
decl_stmt|;
comment|/* algorithm class		*/
name|uint8_t
name|spare4
decl_stmt|;
name|uint16_t
name|itemsize4
decl_stmt|;
comment|/* item size in runtime		*/
name|uint32_t
name|size4
decl_stmt|;
comment|/* runtime structure size	*/
name|uint32_t
name|count4
decl_stmt|;
comment|/* number of items in runtime	*/
name|uint8_t
name|taclass6
decl_stmt|;
comment|/* algorithm class		*/
name|uint8_t
name|spare6
decl_stmt|;
name|uint16_t
name|itemsize6
decl_stmt|;
comment|/* item size in runtime		*/
name|uint32_t
name|size6
decl_stmt|;
comment|/* runtime structure size	*/
name|uint32_t
name|count6
decl_stmt|;
comment|/* number of items in runtime	*/
block|}
name|ipfw_ta_tinfo
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFW_TACLASS_HASH
value|1
end_define

begin_comment
comment|/* algo is based on hash	*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TACLASS_ARRAY
value|2
end_define

begin_comment
comment|/* algo is based on array	*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TACLASS_RADIX
value|3
end_define

begin_comment
comment|/* algo is based on radix tree	*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TATFLAGS_DATA
value|0x0001
end_define

begin_comment
comment|/* Has data filled in	*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TATFLAGS_AFDATA
value|0x0002
end_define

begin_comment
comment|/* Separate data per AF	*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TATFLAGS_AFITEM
value|0x0004
end_define

begin_comment
comment|/* diff. items per AF	*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_xtable_info
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* table type (addr,iface,..)	*/
name|uint8_t
name|tflags
decl_stmt|;
comment|/* type flags			*/
name|uint16_t
name|mflags
decl_stmt|;
comment|/* modification flags		*/
name|uint16_t
name|flags
decl_stmt|;
comment|/* generic table flags		*/
name|uint16_t
name|spare
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|vmask
decl_stmt|;
comment|/* bitmask with value types 	*/
name|uint32_t
name|set
decl_stmt|;
comment|/* set table is in		*/
name|uint32_t
name|kidx
decl_stmt|;
comment|/* kernel index			*/
name|uint32_t
name|refcnt
decl_stmt|;
comment|/* number of references		*/
name|uint32_t
name|count
decl_stmt|;
comment|/* Number of records		*/
name|uint32_t
name|size
decl_stmt|;
comment|/* Total size of records(export)*/
name|uint32_t
name|limit
decl_stmt|;
comment|/* Max number of records	*/
name|char
name|tablename
index|[
literal|64
index|]
decl_stmt|;
comment|/* table name */
name|char
name|algoname
index|[
literal|64
index|]
decl_stmt|;
comment|/* algorithm name		*/
name|ipfw_ta_tinfo
name|ta_info
decl_stmt|;
comment|/* additional algo stats	*/
block|}
name|ipfw_xtable_info
typedef|;
end_typedef

begin_comment
comment|/* Generic table flags */
end_comment

begin_define
define|#
directive|define
name|IPFW_TGFLAGS_LOCKED
value|0x01
end_define

begin_comment
comment|/* Tables is locked from changes*/
end_comment

begin_comment
comment|/* Table type-specific flags */
end_comment

begin_define
define|#
directive|define
name|IPFW_TFFLAG_SRCIP
value|0x01
end_define

begin_define
define|#
directive|define
name|IPFW_TFFLAG_DSTIP
value|0x02
end_define

begin_define
define|#
directive|define
name|IPFW_TFFLAG_SRCPORT
value|0x04
end_define

begin_define
define|#
directive|define
name|IPFW_TFFLAG_DSTPORT
value|0x08
end_define

begin_define
define|#
directive|define
name|IPFW_TFFLAG_PROTO
value|0x10
end_define

begin_comment
comment|/* Table modification flags */
end_comment

begin_define
define|#
directive|define
name|IPFW_TMFLAGS_LIMIT
value|0x0002
end_define

begin_comment
comment|/* Change limit value		*/
end_comment

begin_define
define|#
directive|define
name|IPFW_TMFLAGS_LOCK
value|0x0004
end_define

begin_comment
comment|/* Change table lock state	*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_iface_info
block|{
name|char
name|ifname
index|[
literal|64
index|]
decl_stmt|;
comment|/* interface name		*/
name|uint32_t
name|ifindex
decl_stmt|;
comment|/* interface index		*/
name|uint32_t
name|flags
decl_stmt|;
comment|/* flags			*/
name|uint32_t
name|refcnt
decl_stmt|;
comment|/* number of references		*/
name|uint32_t
name|gencnt
decl_stmt|;
comment|/* number of changes		*/
name|uint64_t
name|spare
decl_stmt|;
block|}
name|ipfw_iface_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFW_IFFLAG_RESOLVED
value|0x01
end_define

begin_comment
comment|/* Interface exists		*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_ta_info
block|{
name|char
name|algoname
index|[
literal|64
index|]
decl_stmt|;
comment|/* algorithm name		*/
name|uint32_t
name|type
decl_stmt|;
comment|/* lookup type			*/
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|refcnt
decl_stmt|;
name|uint32_t
name|spare0
decl_stmt|;
name|uint64_t
name|spare1
decl_stmt|;
block|}
name|ipfw_ta_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_obj_header
block|{
name|ip_fw3_opheader
name|opheader
decl_stmt|;
comment|/* IP_FW3 opcode		*/
name|uint32_t
name|spare
decl_stmt|;
name|uint16_t
name|idx
decl_stmt|;
comment|/* object name index		*/
name|uint8_t
name|objtype
decl_stmt|;
comment|/* object type			*/
name|uint8_t
name|objsubtype
decl_stmt|;
comment|/* object subtype		*/
name|ipfw_obj_ntlv
name|ntlv
decl_stmt|;
comment|/* object name tlv		*/
block|}
name|ipfw_obj_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_obj_lheader
block|{
name|ip_fw3_opheader
name|opheader
decl_stmt|;
comment|/* IP_FW3 opcode		*/
name|uint32_t
name|set_mask
decl_stmt|;
comment|/* disabled set mask		*/
name|uint32_t
name|count
decl_stmt|;
comment|/* Total objects count		*/
name|uint32_t
name|size
decl_stmt|;
comment|/* Total size (incl. header)	*/
name|uint32_t
name|objsize
decl_stmt|;
comment|/* Size of one object		*/
block|}
name|ipfw_obj_lheader
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFW_CFG_GET_STATIC
value|0x01
end_define

begin_define
define|#
directive|define
name|IPFW_CFG_GET_STATES
value|0x02
end_define

begin_define
define|#
directive|define
name|IPFW_CFG_GET_COUNTERS
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_cfg_lheader
block|{
name|ip_fw3_opheader
name|opheader
decl_stmt|;
comment|/* IP_FW3 opcode		*/
name|uint32_t
name|set_mask
decl_stmt|;
comment|/* enabled set mask		*/
name|uint32_t
name|spare
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* Request flags		*/
name|uint32_t
name|size
decl_stmt|;
comment|/* neded buffer size		*/
name|uint32_t
name|start_rule
decl_stmt|;
name|uint32_t
name|end_rule
decl_stmt|;
block|}
name|ipfw_cfg_lheader
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_range_header
block|{
name|ip_fw3_opheader
name|opheader
decl_stmt|;
comment|/* IP_FW3 opcode		*/
name|ipfw_range_tlv
name|range
decl_stmt|;
block|}
name|ipfw_range_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ipfw_sopt_info
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
name|uint8_t
name|spare
decl_stmt|;
name|uint64_t
name|refcnt
decl_stmt|;
block|}
name|ipfw_sopt_info
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IPFW2_H */
end_comment

end_unit

