begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Daniel Boulet  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  */
end_comment

begin_comment
comment|/*  * Format of an IP firewall descriptor  *  * src, dst, src_mask, dst_mask are always stored in network byte order.  * flags and num_*_ports are stored in host byte order (of course).  * Port numbers are stored in HOST byte order.  */
end_comment

begin_struct
struct|struct
name|ip_firewall
block|{
name|struct
name|ip_firewall
modifier|*
name|next
decl_stmt|;
comment|/* Next firewall on chain */
name|struct
name|in_addr
name|src
decl_stmt|,
name|dst
decl_stmt|;
comment|/* Source and destination IP addr */
name|struct
name|in_addr
name|src_mask
decl_stmt|,
name|dst_mask
decl_stmt|;
comment|/* Mask for src and dest IP addr */
name|u_short
name|flags
decl_stmt|;
define|#
directive|define
name|IP_FIREWALL_UNIVERSAL
value|0
comment|/* This is a universal packet firewall*/
define|#
directive|define
name|IP_FIREWALL_TCP
value|1
comment|/* This is a TCP packet firewall */
define|#
directive|define
name|IP_FIREWALL_UDP
value|2
comment|/* This is a UDP packet firewall */
define|#
directive|define
name|IP_FIREWALL_ICMP
value|3
comment|/* This is a ICMP packet firewall */
define|#
directive|define
name|IP_FIREWALL_KIND
value|3
comment|/* Mask to isolate firewall kind */
define|#
directive|define
name|IP_FIREWALL_ACCEPT
value|4
comment|/* This is an accept firewall (as */
comment|/* opposed to a deny firewall) */
define|#
directive|define
name|IP_FIREWALL_SRC_RANGE
value|8
comment|/* The first two src ports are a min  					 * and max range (stored in host byte  					 * order).  					 */
define|#
directive|define
name|IP_FIREWALL_DST_RANGE
value|16
comment|/* The first two dst ports are a min  					 * and max range (stored in host byte  					 * order).  					 * (ports[0]<= port<= ports[1])  					 */
define|#
directive|define
name|IP_FIREWALL_FLAG_BITS
value|0x1f
comment|/* All possible flag bits */
name|u_short
name|num_src_ports
decl_stmt|,
name|num_dst_ports
decl_stmt|;
comment|/* # of src ports and # of dst ports */
comment|/* in ports array (dst ports follow */
comment|/* src ports; max of 10 ports in all; */
comment|/* count of 0 means match all ports) */
define|#
directive|define
name|IP_FIREWALL_MAX_PORTS
value|10
comment|/* A reasonable maximum */
name|u_short
name|ports
index|[
name|IP_FIREWALL_MAX_PORTS
index|]
decl_stmt|;
comment|/* Array of port numbers to match */
block|}
struct|;
end_struct

begin_comment
comment|/*      * New IP firewall options for [gs]etsockopt at the RAW IP level.  */
end_comment

begin_define
define|#
directive|define
name|IP_FW_BASE_CTL
value|53
end_define

begin_define
define|#
directive|define
name|IP_FW_ADD_BLK
value|(IP_FW_BASE_CTL)
end_define

begin_define
define|#
directive|define
name|IP_FW_ADD_FWD
value|(IP_FW_BASE_CTL+1)
end_define

begin_define
define|#
directive|define
name|IP_FW_CHK_BLK
value|(IP_FW_BASE_CTL+2)
end_define

begin_define
define|#
directive|define
name|IP_FW_CHK_FWD
value|(IP_FW_BASE_CTL+3)
end_define

begin_define
define|#
directive|define
name|IP_FW_DEL_BLK
value|(IP_FW_BASE_CTL+4)
end_define

begin_define
define|#
directive|define
name|IP_FW_DEL_FWD
value|(IP_FW_BASE_CTL+5)
end_define

begin_define
define|#
directive|define
name|IP_FW_FLUSH
value|(IP_FW_BASE_CTL+6)
end_define

begin_define
define|#
directive|define
name|IP_FW_POLICY
value|(IP_FW_BASE_CTL+7)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ip_firewall
modifier|*
name|ip_fw_blk_chain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ip_firewall
modifier|*
name|ip_fw_fwd_chain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip_fw_policy
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|IPFIREWALL_VERBOSE
end_ifdef

begin_define
define|#
directive|define
name|ip_firewall_check
value|ip_firewall_check_print
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ip_firewall_check
value|ip_firewall_check_noprint
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

