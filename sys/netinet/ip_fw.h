begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Daniel Boulet  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Format of an IP firewall descriptor  *  * fw_src, fw_dst, fw_smsk, fw_dmsk are always stored in network byte order.  * fw_flg and fw_n*p are stored in host byte order (of course).  * Port numbers are stored in HOST byte order.  */
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

begin_struct
struct|struct
name|ip_fw
block|{
name|u_long
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
union|union
block|{
name|struct
name|in_addr
name|fu_via_ip
decl_stmt|;
struct|struct
block|{
define|#
directive|define
name|FW_IFNLEN
value|6
comment|/* To keep structure on 2^x boundary */
name|char
name|fu_via_name
index|[
name|FW_IFNLEN
index|]
decl_stmt|;
name|short
name|fu_via_unit
decl_stmt|;
block|}
name|fu_via_if
struct|;
block|}
name|fu_via_un
union|;
define|#
directive|define
name|fw_via_ip
value|fu_via_un.fu_via_ip
define|#
directive|define
name|fw_via_name
value|fu_via_un.fu_via_if.fu_via_name
define|#
directive|define
name|fw_via_unit
value|fu_via_un.fu_via_if.fu_via_unit
name|u_short
name|fw_number
decl_stmt|;
name|u_short
name|fw_flg
decl_stmt|;
comment|/* Flags word */
name|u_short
name|fw_nsp
decl_stmt|,
name|fw_ndp
decl_stmt|;
comment|/* N'of src ports and # of dst ports */
comment|/* in ports array (dst ports follow */
comment|/* src ports; max of 10 ports in all; */
comment|/* count of 0 means match all ports) */
define|#
directive|define
name|IP_FW_MAX_PORTS
value|10
comment|/* A reasonable maximum */
name|u_short
name|fw_pts
index|[
name|IP_FW_MAX_PORTS
index|]
decl_stmt|;
comment|/* Array of port numbers to match */
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
define|#
directive|define
name|IP_FW_ICMPTYPES_DIM
value|(256 / (sizeof(unsigned) * 8))
name|unsigned
name|fw_icmptypes
index|[
name|IP_FW_ICMPTYPES_DIM
index|]
decl_stmt|;
comment|/* ICMP types bitmap */
name|long
name|timestamp
decl_stmt|;
comment|/* timestamp (tv_sec) of last match */
block|}
struct|;
end_struct

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
name|IP_FW_F_ALL
value|0x0000
end_define

begin_comment
comment|/* This is a universal packet rule    */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_TCP
value|0x0001
end_define

begin_comment
comment|/* This is a TCP packet rule          */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_UDP
value|0x0002
end_define

begin_comment
comment|/* This is a UDP packet rule          */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ICMP
value|0x0003
end_define

begin_comment
comment|/* This is a ICMP packet rule         */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_KIND
value|0x0003
end_define

begin_comment
comment|/* Mask to isolate rule kind          */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IN
value|0x0004
end_define

begin_comment
comment|/* Inbound 			      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_OUT
value|0x0008
end_define

begin_comment
comment|/* Outbound			      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ACCEPT
value|0x0010
end_define

begin_comment
comment|/* This is an accept rule	      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_COUNT
value|0x0020
end_define

begin_comment
comment|/* This is an accept rule	      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_PRN
value|0x0040
end_define

begin_comment
comment|/* Print if this rule matches	      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ICMPRPL
value|0x0080
end_define

begin_comment
comment|/* Send back icmp unreachable packet  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_SRNG
value|0x0100
end_define

begin_comment
comment|/* The first two src ports are a min  * 				 * and max range (stored in host byte * 				 * order).                            */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DRNG
value|0x0200
end_define

begin_comment
comment|/* The first two dst ports are a min  * 				 * and max range (stored in host byte * 				 * order).                            */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IFNAME
value|0x0400
end_define

begin_comment
comment|/* Use interface name/unit (not IP)   */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_FRAG
value|0x0800
end_define

begin_comment
comment|/* Fragment			      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ICMPBIT
value|0x1000
end_define

begin_comment
comment|/* ICMP type bitmap is valid          */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_IFUWILD
value|0x2000
end_define

begin_comment
comment|/* Match all interface units          */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_MASK
value|0x3FFF
end_define

begin_comment
comment|/* All possible flag bits mask        */
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
comment|/*  * New IP firewall options for [gs]etsockopt at the RAW IP level.  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_BASE_CTL
value|50
end_define

begin_define
define|#
directive|define
name|IP_FW_ADD
value|(IP_FW_BASE_CTL+0)
end_define

begin_define
define|#
directive|define
name|IP_FW_DEL
value|(IP_FW_BASE_CTL+1)
end_define

begin_define
define|#
directive|define
name|IP_FW_FLUSH
value|(IP_FW_BASE_CTL+2)
end_define

begin_define
define|#
directive|define
name|IP_FW_ZERO
value|(IP_FW_BASE_CTL+3)
end_define

begin_define
define|#
directive|define
name|IP_FW_GET
value|(IP_FW_BASE_CTL+4)
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
comment|/*  * Function pointers.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_fw_chk_ptr
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ip_fw_ctl_ptr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Function definitions.  */
end_comment

begin_function_decl
name|void
name|ip_fw_init
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

