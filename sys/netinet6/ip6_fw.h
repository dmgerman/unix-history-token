begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ip6_fw.h,v 1.7 2001/01/24 01:25:33 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 Daniel Boulet  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP6_FW_H
end_ifndef

begin_define
define|#
directive|define
name|_IP6_FW_H
end_define

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/*  * This union structure identifies an interface, either explicitly  * by name or implicitly by IP address. The flags IP_FW_F_IIFNAME  * and IP_FW_F_OIFNAME say how to interpret this structure. An  * interface unit number of -1 matches any unit number, while an  * IP address of 0.0.0.0 indicates matches any interface.  *  * The receive and transmit interfaces are only compared against the  * the packet if the corresponding bit (IP_FW_F_IIFACE or IP_FW_F_OIFACE)  * is set. Note some packets lack a receive or transmit interface  * (in which case the missing "interface" never matches).  */
end_comment

begin_union
union|union
name|ip6_fw_if
block|{
name|struct
name|in6_addr
name|fu_via_ip6
decl_stmt|;
comment|/* Specified by IPv6 address */
struct|struct
block|{
comment|/* Specified by interface name */
define|#
directive|define
name|IP6FW_IFNLEN
value|IFNAMSIZ
name|char
name|name
index|[
name|IP6FW_IFNLEN
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
comment|/*  * Format of an IP firewall descriptor  *  * fw_src, fw_dst, fw_smsk, fw_dmsk are always stored in network byte order.  * fw_flg and fw_n*p are stored in host byte order (of course).  * Port numbers are stored in HOST byte order.  * Warning: setsockopt() will fail if sizeof(struct ip_fw)> MLEN (108)  */
end_comment

begin_struct
struct|struct
name|ip6_fw
block|{
name|u_long
name|fw_pcnt
decl_stmt|,
name|fw_bcnt
decl_stmt|;
comment|/* Packet and byte counters */
name|struct
name|in6_addr
name|fw_src
decl_stmt|,
name|fw_dst
decl_stmt|;
comment|/* Source and destination IPv6 addr */
name|struct
name|in6_addr
name|fw_smsk
decl_stmt|,
name|fw_dmsk
decl_stmt|;
comment|/* Mask for src and dest IPv6 addr */
name|u_short
name|fw_number
decl_stmt|;
comment|/* Rule number */
name|u_short
name|fw_flg
decl_stmt|;
comment|/* Flags word */
define|#
directive|define
name|IPV6_FW_MAX_PORTS
value|10
comment|/* A reasonable maximum */
name|u_int
name|fw_ipflg
decl_stmt|;
comment|/* IP flags word */
name|u_short
name|fw_pts
index|[
name|IPV6_FW_MAX_PORTS
index|]
decl_stmt|;
comment|/* Array of port numbers to match */
name|u_char
name|fw_ip6opt
decl_stmt|,
name|fw_ip6nopt
decl_stmt|;
comment|/* IPv6 options set/unset */
name|u_char
name|fw_tcpf
decl_stmt|,
name|fw_tcpnf
decl_stmt|;
comment|/* TCP flags set/unset */
define|#
directive|define
name|IPV6_FW_ICMPTYPES_DIM
value|(256 / (sizeof(unsigned) * 8))
name|unsigned
name|fw_icmp6types
index|[
name|IPV6_FW_ICMPTYPES_DIM
index|]
decl_stmt|;
comment|/* ICMP types bitmap */
name|long
name|timestamp
decl_stmt|;
comment|/* timestamp (tv_sec) of last match */
name|union
name|ip6_fw_if
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
comment|/* Divert/tee port (options IP6DIVERT) */
name|u_short
name|fu_skipto_rule
decl_stmt|;
comment|/* SKIPTO command rule number */
name|u_short
name|fu_reject_code
decl_stmt|;
comment|/* REJECT response code */
block|}
name|fw_un
union|;
name|u_char
name|fw_prot
decl_stmt|;
comment|/* IPv6 protocol */
name|u_char
name|fw_nports
decl_stmt|;
comment|/* N'of src ports and # of dst ports */
comment|/* in ports array (dst ports follow */
comment|/* src ports; max of 10 ports in all; */
comment|/* count of 0 means match all ports) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPV6_FW_GETNSRCP
parameter_list|(
name|rule
parameter_list|)
value|((rule)->fw_nports& 0x0f)
end_define

begin_define
define|#
directive|define
name|IPV6_FW_SETNSRCP
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
name|IPV6_FW_GETNDSTP
parameter_list|(
name|rule
parameter_list|)
value|((rule)->fw_nports>> 4)
end_define

begin_define
define|#
directive|define
name|IPV6_FW_SETNDSTP
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

begin_struct
struct|struct
name|ip6_fw_chain
block|{
name|LIST_ENTRY
argument_list|(
argument|ip6_fw_chain
argument_list|)
name|chain
expr_stmt|;
name|struct
name|ip6_fw
modifier|*
name|rule
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values for "flags" field .  */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_IN
value|0x0001
end_define

begin_comment
comment|/* Check inbound packets		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_OUT
value|0x0002
end_define

begin_comment
comment|/* Check outbound packets		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_IIFACE
value|0x0004
end_define

begin_comment
comment|/* Apply inbound interface test		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_OIFACE
value|0x0008
end_define

begin_comment
comment|/* Apply outbound interface test	*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_COMMAND
value|0x0070
end_define

begin_comment
comment|/* Mask for type of chain entry:	*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_DENY
value|0x0000
end_define

begin_comment
comment|/* This is a deny rule			*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_REJECT
value|0x0010
end_define

begin_comment
comment|/* Deny and send a response packet	*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_ACCEPT
value|0x0020
end_define

begin_comment
comment|/* This is an accept rule		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_COUNT
value|0x0030
end_define

begin_comment
comment|/* This is a count rule			*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_DIVERT
value|0x0040
end_define

begin_comment
comment|/* This is a divert rule		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_TEE
value|0x0050
end_define

begin_comment
comment|/* This is a tee rule			*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_SKIPTO
value|0x0060
end_define

begin_comment
comment|/* This is a skipto rule		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_PRN
value|0x0080
end_define

begin_comment
comment|/* Print if this rule matches		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_SRNG
value|0x0100
end_define

begin_comment
comment|/* The first two src ports are a min	* 				 * and max range (stored in host byte	* 				 * order).				*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_DRNG
value|0x0200
end_define

begin_comment
comment|/* The first two dst ports are a min	* 				 * and max range (stored in host byte	* 				 * order).				*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_IIFNAME
value|0x0400
end_define

begin_comment
comment|/* In interface by name/unit (not IP)	*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_OIFNAME
value|0x0800
end_define

begin_comment
comment|/* Out interface by name/unit (not IP)	*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_INVSRC
value|0x1000
end_define

begin_comment
comment|/* Invert sense of src check		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_INVDST
value|0x2000
end_define

begin_comment
comment|/* Invert sense of dst check		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_FRAG
value|0x4000
end_define

begin_comment
comment|/* Fragment				*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_ICMPBIT
value|0x8000
end_define

begin_comment
comment|/* ICMP type bitmap is valid		*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_F_MASK
value|0xFFFF
end_define

begin_comment
comment|/* All possible flag bits mask		*/
end_comment

begin_comment
comment|/*   * Flags for the 'fw_ipflg' field, for comparing values of ip and its protocols. */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_IF_TCPEST
value|0x00000020
end_define

begin_comment
comment|/* established TCP connection	*/
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_IF_TCPMSK
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
name|IF6_FW_F_VIAHACK
value|(IPV6_FW_F_IN|IPV6_FW_F_OUT|IPV6_FW_F_IIFACE|IPV6_FW_F_OIFACE)
end_define

begin_comment
comment|/*  * Definitions for REJECT response codes.  * Values less than 256 correspond to ICMP unreachable codes.  */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_REJECT_RST
value|0x0100
end_define

begin_comment
comment|/* TCP packets: send RST */
end_comment

begin_comment
comment|/*  * Definitions for IPv6 option names.  */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_IP6OPT_HOPOPT
value|0x01
end_define

begin_define
define|#
directive|define
name|IPV6_FW_IP6OPT_ROUTE
value|0x02
end_define

begin_define
define|#
directive|define
name|IPV6_FW_IP6OPT_FRAG
value|0x04
end_define

begin_define
define|#
directive|define
name|IPV6_FW_IP6OPT_ESP
value|0x08
end_define

begin_define
define|#
directive|define
name|IPV6_FW_IP6OPT_AH
value|0x10
end_define

begin_define
define|#
directive|define
name|IPV6_FW_IP6OPT_NONXT
value|0x20
end_define

begin_define
define|#
directive|define
name|IPV6_FW_IP6OPT_OPTS
value|0x40
end_define

begin_comment
comment|/*  * Definitions for TCP flags.  */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_TCPF_FIN
value|TH_FIN
end_define

begin_define
define|#
directive|define
name|IPV6_FW_TCPF_SYN
value|TH_SYN
end_define

begin_define
define|#
directive|define
name|IPV6_FW_TCPF_RST
value|TH_RST
end_define

begin_define
define|#
directive|define
name|IPV6_FW_TCPF_PSH
value|TH_PUSH
end_define

begin_define
define|#
directive|define
name|IPV6_FW_TCPF_ACK
value|TH_ACK
end_define

begin_define
define|#
directive|define
name|IPV6_FW_TCPF_URG
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

begin_comment
comment|/*  * Function definitions.  */
end_comment

begin_function_decl
name|void
name|ip6_fw_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Firewall hooks */
end_comment

begin_struct_decl
struct_decl|struct
name|ip6_hdr
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|ip6_fw_chk_t
name|__P
typedef|((struct
name|ip6_hdr
modifier|*
modifier|*
typedef|, struct
name|ifnet
modifier|*
typedef|,
name|u_short
modifier|*
typedef|, struct
name|mbuf
modifier|*
modifier|*
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|ip6_fw_ctl_t
name|__P
typedef|((
name|int
typedef|, struct
name|mbuf
modifier|*
modifier|*
typedef|));
end_typedef

begin_decl_stmt
specifier|extern
name|ip6_fw_chk_t
modifier|*
name|ip6_fw_chk_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ip6_fw_ctl_t
modifier|*
name|ip6_fw_ctl_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip6_fw_enable
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
comment|/* _IP6_FW_H */
end_comment

end_unit

