begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Daniel Boulet  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  *	$Id: ip_fw.h,v 1.30 1997/10/28 15:58:45 bde Exp $  */
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
value|IFNAMSIZ
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
comment|/*  * Format of an IP firewall descriptor  *  * fw_src, fw_dst, fw_smsk, fw_dmsk are always stored in network byte order.  * fw_flg and fw_n*p are stored in host byte order (of course).  * Port numbers are stored in HOST byte order.  * Warning: setsockopt() will fail if sizeof(struct ip_fw)> MLEN (108)  */
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
name|u_short
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
name|u_char
name|fw_ipopt
decl_stmt|,
name|fw_ipnopt
decl_stmt|;
comment|/* IP options set/unset */
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
comment|/* IP protocol */
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

begin_struct
struct|struct
name|ip_fw_chain
block|{
name|LIST_ENTRY
argument_list|(
argument|ip_fw_chain
argument_list|)
name|chain
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
comment|/*  * Values for "flags" field .  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IN
value|0x0001
end_define

begin_comment
comment|/* Check inbound packets		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_OUT
value|0x0002
end_define

begin_comment
comment|/* Check outbound packets		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IIFACE
value|0x0004
end_define

begin_comment
comment|/* Apply inbound interface test		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_OIFACE
value|0x0008
end_define

begin_comment
comment|/* Apply outbound interface test	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_COMMAND
value|0x0070
end_define

begin_comment
comment|/* Mask for type of chain entry:	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DENY
value|0x0000
end_define

begin_comment
comment|/* This is a deny rule			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_REJECT
value|0x0010
end_define

begin_comment
comment|/* Deny and send a response packet	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ACCEPT
value|0x0020
end_define

begin_comment
comment|/* This is an accept rule		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_COUNT
value|0x0030
end_define

begin_comment
comment|/* This is a count rule			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DIVERT
value|0x0040
end_define

begin_comment
comment|/* This is a divert rule		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_TEE
value|0x0050
end_define

begin_comment
comment|/* This is a tee rule			*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_SKIPTO
value|0x0060
end_define

begin_comment
comment|/* This is a skipto rule		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_PRN
value|0x0080
end_define

begin_comment
comment|/* Print if this rule matches		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_SRNG
value|0x0100
end_define

begin_comment
comment|/* The first two src ports are a min	* 				 * and max range (stored in host byte	* 				 * order).				*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DRNG
value|0x0200
end_define

begin_comment
comment|/* The first two dst ports are a min	* 				 * and max range (stored in host byte	* 				 * order).				*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IIFNAME
value|0x0400
end_define

begin_comment
comment|/* In interface by name/unit (not IP)	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_OIFNAME
value|0x0800
end_define

begin_comment
comment|/* Out interface by name/unit (not IP)	*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_INVSRC
value|0x1000
end_define

begin_comment
comment|/* Invert sense of src check		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_INVDST
value|0x2000
end_define

begin_comment
comment|/* Invert sense of dst check		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_FRAG
value|0x4000
end_define

begin_comment
comment|/* Fragment				*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ICMPBIT
value|0x8000
end_define

begin_comment
comment|/* ICMP type bitmap is valid		*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_MASK
value|0xFFFF
end_define

begin_comment
comment|/* All possible flag bits mask		*/
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

begin_define
define|#
directive|define
name|IP_FW_TCPF_ESTAB
value|0x40
end_define

begin_comment
comment|/*  * Main firewall chains definitions and global var's definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IP_FW_H */
end_comment

end_unit

