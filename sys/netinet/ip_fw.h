begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Daniel Boulet  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  */
end_comment

begin_comment
comment|/*  * Format of an IP firewall descriptor  *  * src, dst, src_mask, dst_mask are always stored in network byte order.  * flags and num_*_ports are stored in host byte order (of course).  * Port numbers are stored in HOST byte order.  */
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
name|struct
name|ip_fw
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
comment|/* Flags word */
name|u_short
name|n_src_p
decl_stmt|,
name|n_dst_p
decl_stmt|;
comment|/* # of src ports and # of dst ports */
comment|/* in ports array (dst ports follow */
comment|/* src ports; max of 10 ports in all; */
comment|/* count of 0 means match all ports) */
define|#
directive|define
name|IP_FW_MAX_PORTS
value|10
comment|/* A reasonable maximum */
name|u_short
name|ports
index|[
name|IP_FW_MAX_PORTS
index|]
decl_stmt|;
comment|/* Array of port numbers to match */
name|u_long
name|p_cnt
decl_stmt|,
name|b_cnt
decl_stmt|;
comment|/* Packet and byte counters */
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
value|0x00
end_define

begin_comment
comment|/* This is a universal packet firewall*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_TCP
value|0x01
end_define

begin_comment
comment|/* This is a TCP packet firewall      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_UDP
value|0x02
end_define

begin_comment
comment|/* This is a UDP packet firewall      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ICMP
value|0x03
end_define

begin_comment
comment|/* This is a ICMP packet firewall     */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_KIND
value|0x03
end_define

begin_comment
comment|/* Mask to isolate firewall kind      */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_ACCEPT
value|0x04
end_define

begin_comment
comment|/* This is an accept firewall (as     * 				 *         opposed to a deny firewall)* 				 *                                    */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_SRNG
value|0x08
end_define

begin_comment
comment|/* The first two src ports are a min  * 				 * and max range (stored in host byte * 				 * order).                            * 				 *                                    */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_DRNG
value|0x10
end_define

begin_comment
comment|/* The first two dst ports are a min  * 				 * and max range (stored in host byte * 				 * order).                            * 				 * (ports[0]<= port<= ports[1])     * 				 *                                    */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_PRN
value|0x20
end_define

begin_comment
comment|/* In verbose mode print this firewall*/
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_BIDIR
value|0x40
end_define

begin_comment
comment|/* For accounting-count two way       */
end_comment

begin_define
define|#
directive|define
name|IP_FW_F_MASK
value|0x7F
end_define

begin_comment
comment|/* All possible flag bits mask        */
end_comment

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

begin_define
define|#
directive|define
name|IP_ACCT_ADD
value|(IP_FW_BASE_CTL+10)
end_define

begin_define
define|#
directive|define
name|IP_ACCT_DEL
value|(IP_FW_BASE_CTL+11)
end_define

begin_define
define|#
directive|define
name|IP_ACCT_FLUSH
value|(IP_FW_BASE_CTL+12)
end_define

begin_define
define|#
directive|define
name|IP_ACCT_ZERO
value|(IP_FW_BASE_CTL+13)
end_define

begin_comment
comment|/*  * Main firewall chains definitions and global var's definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|IPFIREWALL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ip_fw
modifier|*
name|ip_fw_blk_chain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ip_fw
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPACCT
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ip_fw
modifier|*
name|ip_acct_chain
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

