begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Daniel Boulet  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_FW_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_FW_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * This union structure identifies an interface, either explicitly  * by name or implicitly by IP address. The flags IP_FW_F_IIFNAME  * and IP_FW_F_OIFNAME say how to interpret this structure. An  * interface unit number of -1 matches any unit number, while an  * IP address of 0.0.0.0 indicates matches any interface.  *  * The receive and transmit interfaces are only compared against the  * the packet if the corresponding bit (IP_FW_F_IIFACE or IP_FW_F_OIFACE)  * is set. Note some packets lack a receive or transmit interface  * (in which case the missing "interface" never matches).  */
end_comment

begin_union
union|union
name|ip_fw_if
block|{
name|struct
name|in_addr
name|fu_via_ip
decl_stmt|;
comment|/* Specified by IP address */
struct|struct
block|{
comment|/* Specified by interface name */
define|#
directive|define
name|FW_IFNLEN
value|10
comment|/* need room ! was IFNAMSIZ */
name|char
name|name
index|[
name|FW_IFNLEN
index|]
decl_stmt|;
name|short
name|unit
decl_stmt|;
comment|/* -1 means match any unit */
block|}
name|fu_via_if
struct|;
block|}
union|;
end_union

begin_comment
comment|/*  * Format of an IP firewall descriptor  *  * fw_src, fw_dst, fw_smsk, fw_dmsk are always stored in network byte order.  * fw_flg and fw_n*p are stored in host byte order (of course).  * Port numbers are stored in HOST byte order.  */
end_comment

begin_struct
struct|struct
name|ip_fw
block|{
name|u_int64_t
name|fw_pcnt
decl_stmt|,
name|fw_bcnt
decl_stmt|;
comment|/* Packet and byte counters */
name|struct
name|in_addr
name|fw_src
decl_stmt|,
name|fw_dst
decl_stmt|;
comment|/* Source and destination IP addr */
name|struct
name|in_addr
name|fw_smsk
decl_stmt|,
name|fw_dmsk
decl_stmt|;
comment|/* Mask for src and dest IP addr */
name|u_short
name|fw_number
decl_stmt|;
comment|/* Rule number */
name|u_int
name|fw_flg
decl_stmt|;
comment|/* Flags word */
define|#
directive|define
name|IP_FW_MAX_PORTS
value|10
comment|/* A reasonable maximum */
union|union
block|{
name|u_short
name|fw_pts
index|[
name|IP_FW_MAX_PORTS
index|]
decl_stmt|;
comment|/* Array of port numbers to match */
define|#
directive|define
name|IP_FW_ICMPTYPES_MAX
value|128
define|#
directive|define
name|IP_FW_ICMPTYPES_DIM
value|(IP_FW_ICMPTYPES_MAX / (sizeof(unsigned) * 8))
name|unsigned
name|fw_icmptypes
index|[
name|IP_FW_ICMPTYPES_DIM
index|]
decl_stmt|;
comment|/* ICMP types bitmap */
block|}
name|fw_uar
union|;
name|u_int
name|fw_ipflg
decl_stmt|;
comment|/* IP flags word */
name|u_char
name|fw_ipopt
decl_stmt|,
name|fw_ipnopt
decl_stmt|;
comment|/* IP options set/unset */
name|u_char
name|fw_tcpopt
decl_stmt|,
name|fw_tcpnopt
decl_stmt|;
comment|/* TCP options set/unset */
name|u_char
name|fw_tcpf
decl_stmt|,
name|fw_tcpnf
decl_stmt|;
comment|/* TCP flags set/unset */
name|long
name|timestamp
decl_stmt|;
comment|/* timestamp (tv_sec) of last match */
name|union
name|ip_fw_if
name|fw_in_if
decl_stmt|,
name|fw_out_if
decl_stmt|;
comment|/* Incoming and outgoing interfaces */
union|union
block|{
name|u_short
name|fu_divert_port
decl_stmt|;
comment|/* Divert/tee port (options IPDIVERT) */
name|u_short
name|fu_pipe_nr
decl_stmt|;
comment|/* queue number (option DUMMYNET) */
name|u_short
name|fu_skipto_rule
decl_stmt|;
comment|/* SKIPTO command rule number */
name|u_short
name|fu_reject_code
decl_stmt|;
comment|/* REJECT response code */
name|struct
name|sockaddr_in
name|fu_fwd_ip
decl_stmt|;
block|}
name|fw_un
union|;
name|u_char
name|fw_prot
decl_stmt|;
comment|/* IP protocol */
comment|/* 	 * N'of src ports and # of dst ports in ports array (dst ports 	 * follow src ports; max of 10 ports in all; count of 0 means 	 * match all ports) 	 */
name|u_char
name|fw_nports
decl_stmt|;
name|void
modifier|*
name|pipe_ptr
decl_stmt|;
comment|/* flow_set ptr for dummynet pipe */
name|void
modifier|*
name|next_rule_ptr
decl_stmt|;
comment|/* next rule in case of match */
name|uid_t
name|fw_uid
decl_stmt|;
comment|/* uid to match */
name|gid_t
name|fw_gid
decl_stmt|;
comment|/* gid to match */
name|int
name|fw_logamount
decl_stmt|;
comment|/* amount to log */
name|u_int64_t
name|fw_loghighest
decl_stmt|;
comment|/* highest number packet to log */
block|}
struct|;
end_struct

begin_comment
comment|/*  * extended ipfw structure... some fields in the original struct  * can be used to pass parameters up/down, namely pointers  *     void *pipe_ptr  *     void *next_rule_ptr   * some others can be used to pass parameters down, namely counters etc.  *     u_int64_t fw_pcnt,fw_bcnt;  *     long timestamp;  */
end_comment

begin_struct
struct|struct
name|ip_fw_ext
block|{
comment|/* extended structure */
name|struct
name|ip_fw
name|rule
decl_stmt|;
comment|/* must be at offset 0 */
name|long
name|dont_match_prob
decl_stmt|;
comment|/* 0x7fffffff means 1.0, always fail */
name|u_int
name|dyn_type
decl_stmt|;
comment|/* type for dynamic rule */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IP_FW_GETNSRCP
parameter_list|(
name|rule
parameter_list|)
value|((rule)->fw_nports& 0x0f)
end_define

begin_define
define|#
directive|define
name|IP_FW_SETNSRCP
parameter_list|(
name|rule
parameter_list|,
name|n
parameter_list|)
value|do {				\ 					  (rule)->fw_nports&= ~0x0f;	\ 					  (rule)->fw_nports |= (n);	\ 					} while (0)
end_define

begin_define
define|#
directive|define
name|IP_FW_GETNDSTP
parameter_list|(
name|rule
parameter_list|)
value|((rule)->fw_nports>> 4)
end_define

begin_define
define|#
directive|define
name|IP_FW_SETNDSTP
parameter_list|(
name|rule
parameter_list|,
name|n
parameter_list|)
value|do {				\ 					  (rule)->fw_nports&= ~0xf0;	\ 					  (rule)->fw_nports |= (n)<< 4;\ 					} while (0)
end_define

begin_define
define|#
directive|define
name|fw_divert_port
value|fw_un.fu_divert_port
end_define

begin_define
define|#
directive|define
name|fw_skipto_rule
value|fw_un.fu_skipto_rule
end_define

begin_define
define|#
directive|define
name|fw_reject_code
value|fw_un.fu_reject_code
end_define

begin_define
define|#
directive|define
name|fw_pipe_nr
value|fw_un.fu_pipe_nr
end_define

begin_define
define|#
directive|define
name|fw_fwd_ip
value|fw_un.fu_fwd_ip
end_define

begin_struct
struct|struct
name|ip_fw_chain
block|{
name|LIST_ENTRY
argument_list|(
argument|ip_fw_chain
argument_list|)
name|next
expr_stmt|;
name|struct
name|ip_fw
modifier|*
name|rule
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flow mask/flow id for each queue.  */
end_comment

begin_struct
struct|struct
name|ipfw_flow_id
block|{
name|u_int32_t
name|dst_ip
decl_stmt|,
name|src_ip
decl_stmt|;
name|u_int16_t
name|dst_port
decl_stmt|,
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

begin_struct
struct|struct
name|ipfw_dyn_rule
block|{
name|struct
name|ipfw_dyn_rule
modifier|*
name|next
decl_stmt|;
name|struct
name|ipfw_flow_id
name|id
decl_stmt|;
name|struct
name|ipfw_flow_id
name|mask
decl_stmt|;
name|struct
name|ip_fw_chain
modifier|*
name|chain
decl_stmt|;
comment|/* pointer to parent rule	*/
name|u_int32_t
name|type
decl_stmt|;
comment|/* rule type			*/
name|u_int32_t
name|expire
decl_stmt|;
comment|/* expire time			*/
name|u_int64_t
name|pcnt
decl_stmt|,
name|bcnt
decl_stmt|;
comment|/* match counters		*/
name|u_int32_t
name|bucket
decl_stmt|;
comment|/* which bucket in hash table	*/
name|u_int32_t
name|state
decl_stmt|;
comment|/* state of this rule (typ. a   */
comment|/* combination of TCP flags)	*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values for "flags" field .  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_COMMAND
value|0x000000ff
end_define

begin_comment
comment|/* Mask for type of chain entry:	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DENY
value|0x00000000
end_define

begin_comment
comment|/* This is a deny rule			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_REJECT
value|0x00000001
end_define

begin_comment
comment|/* Deny and send a response packet	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ACCEPT
value|0x00000002
end_define

begin_comment
comment|/* This is an accept rule		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_COUNT
value|0x00000003
end_define

begin_comment
comment|/* This is a count rule			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DIVERT
value|0x00000004
end_define

begin_comment
comment|/* This is a divert rule		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_TEE
value|0x00000005
end_define

begin_comment
comment|/* This is a tee rule			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_SKIPTO
value|0x00000006
end_define

begin_comment
comment|/* This is a skipto rule		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_FWD
value|0x00000007
end_define

begin_comment
comment|/* This is a "change forwarding address" rule */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_PIPE
value|0x00000008
end_define

begin_comment
comment|/* This is a dummynet rule */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_QUEUE
value|0x00000009
end_define

begin_comment
comment|/* This is a dummynet queue */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IN
value|0x00000100
end_define

begin_comment
comment|/* Check inbound packets		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_OUT
value|0x00000200
end_define

begin_comment
comment|/* Check outbound packets		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IIFACE
value|0x00000400
end_define

begin_comment
comment|/* Apply inbound interface test		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_OIFACE
value|0x00000800
end_define

begin_comment
comment|/* Apply outbound interface test	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_PRN
value|0x00001000
end_define

begin_comment
comment|/* Print if this rule matches		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_SRNG
value|0x00002000
end_define

begin_comment
comment|/* The first two src ports are a min	* 					 * and max range (stored in host byte	* 					 * order).				*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DRNG
value|0x00004000
end_define

begin_comment
comment|/* The first two dst ports are a min	* 					 * and max range (stored in host byte	* 					 * order).				*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_FRAG
value|0x00008000
end_define

begin_comment
comment|/* Fragment				*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IIFNAME
value|0x00010000
end_define

begin_comment
comment|/* In interface by name/unit (not IP)	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_OIFNAME
value|0x00020000
end_define

begin_comment
comment|/* Out interface by name/unit (not IP)	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_INVSRC
value|0x00040000
end_define

begin_comment
comment|/* Invert sense of src check		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_INVDST
value|0x00080000
end_define

begin_comment
comment|/* Invert sense of dst check		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ICMPBIT
value|0x00100000
end_define

begin_comment
comment|/* ICMP type bitmap is valid		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_UID
value|0x00200000
end_define

begin_comment
comment|/* filter by uid			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_GID
value|0x00400000
end_define

begin_comment
comment|/* filter by gid			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_RND_MATCH
value|0x00800000
end_define

begin_comment
comment|/* probabilistic rule match		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_SMSK
value|0x01000000
end_define

begin_comment
comment|/* src-port + mask 			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DMSK
value|0x02000000
end_define

begin_comment
comment|/* dst-port + mask 			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_BRIDGED
value|0x04000000
end_define

begin_comment
comment|/* only match bridged packets		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_KEEP_S
value|0x08000000
end_define

begin_comment
comment|/* keep state	 			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_CHECK_S
value|0x10000000
end_define

begin_comment
comment|/* check state	 			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_SME
value|0x20000000
end_define

begin_comment
comment|/* source = me				*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DME
value|0x40000000
end_define

begin_comment
comment|/* destination = me			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_MASK
value|0x7FFFFFFF
end_define

begin_comment
comment|/* All possible flag bits mask		*/
end_comment

begin_comment
comment|/*  * Flags for the 'fw_ipflg' field, for comparing values of ip and its protocols.  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_IF_TCPEST
value|0x00000020
end_define

begin_comment
comment|/* established TCP connection */
end_comment

begin_define
define|#
directive|define
name|IP_FW_IF_TCPMSK
value|0x00000020
end_define

begin_comment
comment|/* mask of all TCP values */
end_comment

begin_comment
comment|/*  * For backwards compatibility with rules specifying "via iface" but  * not restricted to only "in" or "out" packets, we define this combination  * of bits to represent this configuration.  */
end_comment

begin_define
define|#
directive|define
name|IF_FW_F_VIAHACK
value|(IP_FW_F_IN|IP_FW_F_OUT|IP_FW_F_IIFACE|IP_FW_F_OIFACE)
end_define

begin_comment
comment|/*  * Definitions for REJECT response codes.  * Values less than 256 correspond to ICMP unreachable codes.  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_REJECT_RST
value|0x0100
end_define

begin_comment
comment|/* TCP packets: send RST */
end_comment

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

begin_comment
comment|/*  * Definitions for TCP flags.  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_TCPF_FIN
value|TH_FIN
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPF_SYN
value|TH_SYN
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPF_RST
value|TH_RST
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPF_PSH
value|TH_PUSH
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPF_ACK
value|TH_ACK
end_define

begin_define
define|#
directive|define
name|IP_FW_TCPF_URG
value|TH_URG
end_define

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
comment|/*  * Function definitions.  */
end_comment

begin_decl_stmt
name|void
name|ip_fw_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Firewall hooks */
end_comment

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|ip_fw_chk_t
name|__P
typedef|((struct
name|ip
modifier|*
modifier|*
typedef|,
name|int
typedef|, struct
name|ifnet
modifier|*
typedef|,
name|u_int16_t
modifier|*
typedef|, 	     struct
name|mbuf
modifier|*
modifier|*
typedef|, struct
name|ip_fw_chain
modifier|*
modifier|*
typedef|, struct
name|sockaddr_in
modifier|*
modifier|*
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|ip_fw_ctl_t
name|__P
typedef|((struct
name|sockopt
modifier|*
typedef|));
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

begin_decl_stmt
specifier|extern
name|struct
name|ipfw_flow_id
name|last_pkt
decl_stmt|;
end_decl_stmt

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
comment|/* _IP_FW_H */
end_comment

end_unit

