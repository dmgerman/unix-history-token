begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * octeon_pip.h		Packet Input Processing Block  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_PIP_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_PIP_H__
end_define

begin_comment
comment|/**   * Enumeration representing the amount of packet processing  * and validation performed by the input hardware.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|OCTEON_PIP_PORT_CFG_MODE_NONE
init|=
literal|0ull
block|,
comment|/**< Packet input doesn't perform any                                             processing of the input packet. */
name|OCTEON_PIP_PORT_CFG_MODE_SKIPL2
init|=
literal|1ull
block|,
comment|/**< Full packet processing is performed                                             with pointer starting at the L2                                             (ethernet MAC) header. */
name|OCTEON_PIP_PORT_CFG_MODE_SKIPIP
init|=
literal|2ull
comment|/**< Input packets are assumed to be IP.                                             Results from non IP packets is                                             undefined. Pointers reference the                                             beginning of the IP header. */
block|}
name|octeon_pip_port_parse_mode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OCTEON_PIP_PRT_CFGX
parameter_list|(
name|offset
parameter_list|)
value|(0x80011800A0000200ull+((offset)*8))
end_define

begin_define
define|#
directive|define
name|OCTEON_PIP_PRT_TAGX
parameter_list|(
name|offset
parameter_list|)
value|(0x80011800A0000400ull+((offset)*8))
end_define

begin_define
define|#
directive|define
name|OCTEON_PIP_STAT_INB_PKTS
parameter_list|(
name|port
parameter_list|)
value|(0x80011800A0001A00ull+((port) * 32))
end_define

begin_define
define|#
directive|define
name|OCTEON_PIP_STAT_INB_ERRS
parameter_list|(
name|port
parameter_list|)
value|(0x80011800A0001A10ull+((port) * 32))
end_define

begin_comment
comment|/*  * PIP Global Config  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved2
range|:
literal|45
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|tag_syn
range|:
literal|1
decl_stmt|;
comment|/* Not Include src_crc in TCP..*/
name|uint64_t
name|ip6_udp
range|:
literal|1
decl_stmt|;
comment|/* IPv6/UDP checksum is mandatory */
name|uint64_t
name|max_l2
range|:
literal|1
decl_stmt|;
comment|/* Largest L2 frame. 0/1 : 1500/1535 */
name|uint64_t
name|reserved1
range|:
literal|5
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|raw_shf
range|:
literal|3
decl_stmt|;
comment|/* PCI RAW Packet shift/pad amount */
name|uint64_t
name|reserved0
range|:
literal|5
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|nip_shf
range|:
literal|3
decl_stmt|;
comment|/* Non-IP shift/pad amount */
block|}
name|bits
struct|;
block|}
name|octeon_pip_gbl_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved4
range|:
literal|37
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|qos
range|:
literal|3
decl_stmt|;
comment|/* Default POW QoS queue */
name|uint64_t
name|qos_wat
range|:
literal|4
decl_stmt|;
comment|/* Bitfield to enable QoS watcher */
comment|/*  look up tables. 4 per port. */
name|uint64_t
name|reserved3
range|:
literal|1
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|spare
range|:
literal|1
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|qos_diff
range|:
literal|1
decl_stmt|;
comment|/* Use IP diffserv to determine */
comment|/*     the queue in the POW */
name|uint64_t
name|qos_vlan
range|:
literal|1
decl_stmt|;
comment|/* Use the VLAN tag to determine */
comment|/*     the queue in the POW */
name|uint64_t
name|reserved2
range|:
literal|3
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|crc_en
range|:
literal|1
decl_stmt|;
comment|/* Enable HW checksum */
name|uint64_t
name|reserved1
range|:
literal|2
decl_stmt|;
comment|/* Must be zero */
name|octeon_pip_port_parse_mode_t
name|mode
range|:
literal|2
decl_stmt|;
comment|/* Raw/Parsed/IP/etc */
name|uint64_t
name|reserved0
range|:
literal|1
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|skip
range|:
literal|7
decl_stmt|;
comment|/* 8 byte words to skip in the */
comment|/*   beginning of a packet buffer */
block|}
name|bits
struct|;
block|}
name|octeon_pip_port_cfg_t
typedef|;
end_typedef

begin_comment
comment|/*  * Packet input to POW interface. How input packets are tagged for  * the POW is controlled here.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|24
decl_stmt|;
comment|/**< Reserved */
name|uint64_t
name|grptagbase
range|:
literal|4
decl_stmt|;
comment|/**< Offset to use when computing group from tag bits                                                          when GRPTAG is set. Only applies to IP packets.                                                          (PASS2 only) */
name|uint64_t
name|grptagmask
range|:
literal|4
decl_stmt|;
comment|/**< Which bits of the tag to exclude when computing                                                          group when GRPTAG is set. Only applies to IP packets.                                                          (PASS2 only) */
name|uint64_t
name|grptag
range|:
literal|1
decl_stmt|;
comment|/**< When set, use the lower bit of the tag to compute                                                          the group in the work queue entry                                                          GRP = WQE[TAG[3:0]]& ~GRPTAGMASK + GRPTAGBASE.                                                          Only applies to IP packets. (PASS2 only) */
name|uint64_t
name|spare
range|:
literal|1
decl_stmt|;
comment|/**< Spare bit                                                          (PASS2 only) */
name|uint64_t
name|tag_mode
range|:
literal|2
decl_stmt|;
comment|/**< Which tag algorithm to use                                                          0 = always use tuple tag algorithm                                                          1 = always use mask tag algorithm                                                          2 = if packet is IP, use tuple else use mask                                                          3 = tuple XOR mask                                                          (PASS2 only) */
name|uint64_t
name|inc_vs
range|:
literal|2
decl_stmt|;
comment|/**< determines the VLAN ID (VID) to be included in                                                          tuple tag when VLAN stacking is detected                                                          0 = do not include VID in tuple tag generation                                                          1 = include VID (VLAN0) in hash                                                          2 = include VID (VLAN1) in hash                                                          3 = include VID ([VLAN0,VLAN1]) in hash                                                          (PASS2 only) */
name|uint64_t
name|inc_vlan
range|:
literal|1
decl_stmt|;
comment|/**< when set, the VLAN ID is included in tuple tag                                                          when VLAN stacking is not detected                                                          0 = do not include VID in tuple tag generation                                                          1 = include VID in hash                                                          (PASS2 only) */
name|uint64_t
name|inc_prt_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether the port is included in tuple tag */
name|uint64_t
name|ip6_dprt_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether the TCP/UDP dst port is                                                          included in tuple tag for IPv6 packets */
name|uint64_t
name|ip4_dprt_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether the TCP/UDP dst port is                                                          included in tuple tag for IPv4 */
name|uint64_t
name|ip6_sprt_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether the TCP/UDP src port is                                                  	included in tuple tag for IPv6 packets */
name|uint64_t
name|ip4_sprt_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether the TCP/UDP src port is                                                          included in tuple tag for IPv4 */
name|uint64_t
name|ip6_nxth_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether ipv6 includes next header in tuple                                                          tag hash */
name|uint64_t
name|ip4_pctl_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether ipv4 includes protocol in tuple                                                          tag hash */
name|uint64_t
name|ip6_dst_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether ipv6 includes dst address in tuple                                                          tag hash */
name|uint64_t
name|ip4_dst_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether ipv4 includes dst address in tuple                                                          tag hash */
name|uint64_t
name|ip6_src_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether ipv6 includes src address in tuple                                                          tag hash */
name|uint64_t
name|ip4_src_flag
range|:
literal|1
decl_stmt|;
comment|/**< sets whether ipv4 includes src address in tuple                                                          tag hash */
name|uint64_t
name|tcp6_tag_type
range|:
literal|2
decl_stmt|;
comment|/**< sets the tag_type of a TCP packet (IPv6)                                                          0 = ordered tags                                                          1 = atomic tags                                                          2 = Null tags */
name|uint64_t
name|tcp4_tag_type
range|:
literal|2
decl_stmt|;
comment|/**< sets the tag_type of a TCP packet (IPv4)                                                          0 = ordered tags                                                          1 = atomic tags                                                          2 = Null tags */
name|uint64_t
name|ip6_tag_type
range|:
literal|2
decl_stmt|;
comment|/**< sets whether IPv6 packet tag type                                                          0 = ordered tags                                                          1 = atomic tags                                                          2 = Null tags */
name|uint64_t
name|ip4_tag_type
range|:
literal|2
decl_stmt|;
comment|/**< sets whether IPv4 packet tag type                                                          0 = ordered tags                                                          1 = atomic tags                                                          2 = Null tags */
name|uint64_t
name|non_tag_type
range|:
literal|2
decl_stmt|;
comment|/**< sets whether non-IP packet tag type                                                          0 = ordered tags                                                          1 = atomic tags                                                          2 = Null tags */
name|uint64_t
name|grp
range|:
literal|4
decl_stmt|;
comment|/* POW group for input pkts */
block|}
name|bits
struct|;
block|}
name|octeon_pip_port_tag_cfg_t
typedef|;
end_typedef

begin_comment
comment|/**   * Configure an ethernet input port  *    * @param port_num Port number to configure  * @param port_cfg Port hardware configuration  * @param port_tag_cfg  *                 Port POW tagging configuration  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_pip_config_port
parameter_list|(
name|u_int
name|port_num
parameter_list|,
name|octeon_pip_port_cfg_t
name|port_cfg
parameter_list|,
name|octeon_pip_port_tag_cfg_t
name|port_tag_cfg
parameter_list|)
block|{
name|oct_write64
argument_list|(
name|OCTEON_PIP_PRT_CFGX
argument_list|(
name|port_num
argument_list|)
argument_list|,
name|port_cfg
operator|.
name|word64
argument_list|)
expr_stmt|;
name|oct_write64
argument_list|(
name|OCTEON_PIP_PRT_TAGX
argument_list|(
name|port_num
argument_list|)
argument_list|,
name|port_tag_cfg
operator|.
name|word64
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __OCTEON_PIP_H__ */
end_comment

end_unit

