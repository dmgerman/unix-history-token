begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Networks (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Networks nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * This header file defines the work queue entry (wqe) data structure.  * Since this is a commonly used structure that depends on structures  * from several hardware blocks, those definitions have been placed  * in this file to create a single point of definition of the wqe  * format.  * Data structures are still named according to the block that they  * relate to.  *  * This file must not depend on any other header files, except for cvmx.h!!!  *  *  *<hr>$Revision: 49448 $<hr>  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_WQE_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_WQE_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|OCT_TAG_TYPE_STRING
parameter_list|(
name|x
parameter_list|)
value|(((x) == CVMX_POW_TAG_TYPE_ORDERED) ?  "ORDERED" : \                                 (((x) == CVMX_POW_TAG_TYPE_ATOMIC) ?  "ATOMIC" : \                                 (((x) == CVMX_POW_TAG_TYPE_NULL) ?  "NULL" : \                                 "NULL_NULL")))
comment|/**  * HW decode / err_code in work queue entry  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
comment|/** Use this struct if the hardware determines that the packet is IP */
struct|struct
block|{
name|uint64_t
name|bufs
range|:
literal|8
decl_stmt|;
comment|/**< HW sets this to the number of buffers used by this packet */
name|uint64_t
name|ip_offset
range|:
literal|8
decl_stmt|;
comment|/**< HW sets to the number of L2 bytes prior to the IP */
name|uint64_t
name|vlan_valid
range|:
literal|1
decl_stmt|;
comment|/**< set to 1 if we found DSA/VLAN in the L2 */
name|uint64_t
name|vlan_stacked
range|:
literal|1
decl_stmt|;
comment|/**< Set to 1 if the DSA/VLAN tag is stacked */
name|uint64_t
name|unassigned
range|:
literal|1
decl_stmt|;
name|uint64_t
name|vlan_cfi
range|:
literal|1
decl_stmt|;
comment|/**< HW sets to the DSA/VLAN CFI flag (valid when vlan_valid) */
name|uint64_t
name|vlan_id
range|:
literal|12
decl_stmt|;
comment|/**< HW sets to the DSA/VLAN_ID field (valid when vlan_valid) */
name|uint64_t
name|pr
range|:
literal|4
decl_stmt|;
comment|/**< Ring Identifier (if PCIe). Requires PIP_GBL_CTL[RING_EN]=1 */
name|uint64_t
name|unassigned2
range|:
literal|8
decl_stmt|;
name|uint64_t
name|dec_ipcomp
range|:
literal|1
decl_stmt|;
comment|/**< the packet needs to be decompressed */
name|uint64_t
name|tcp_or_udp
range|:
literal|1
decl_stmt|;
comment|/**< the packet is either TCP or UDP */
name|uint64_t
name|dec_ipsec
range|:
literal|1
decl_stmt|;
comment|/**< the packet needs to be decrypted (ESP or AH) */
name|uint64_t
name|is_v6
range|:
literal|1
decl_stmt|;
comment|/**< the packet is IPv6 */
comment|/* (rcv_error, not_IP, IP_exc, is_frag, L4_error, software, etc.) */
name|uint64_t
name|software
range|:
literal|1
decl_stmt|;
comment|/**< reserved for software use, hardware will clear on packet creation */
comment|/* exceptional conditions below */
name|uint64_t
name|L4_error
range|:
literal|1
decl_stmt|;
comment|/**< the receive interface hardware detected an L4 error (only applies if !is_frag)                                                     (only applies if !rcv_error&& !not_IP&& !IP_exc&& !is_frag)                                                     failure indicated in err_code below, decode:                                                     - 1 = Malformed L4                                                     - 2 = L4 Checksum Error: the L4 checksum value is                                                     - 3 = UDP Length Error: The UDP length field would make the UDP data longer than what                                                         remains in the IP packet (as defined by the IP header length field).                                                     - 4 = Bad L4 Port: either the source or destination TCP/UDP port is 0.                                                     - 8 = TCP FIN Only: the packet is TCP and only the FIN flag set.                                                     - 9 = TCP No Flags: the packet is TCP and no flags are set.                                                     - 10 = TCP FIN RST: the packet is TCP and both FIN and RST are set.                                                     - 11 = TCP SYN URG: the packet is TCP and both SYN and URG are set.                                                     - 12 = TCP SYN RST: the packet is TCP and both SYN and RST are set.                                                     - 13 = TCP SYN FIN: the packet is TCP and both SYN and FIN are set. */
name|uint64_t
name|is_frag
range|:
literal|1
decl_stmt|;
comment|/**< set if the packet is a fragment */
name|uint64_t
name|IP_exc
range|:
literal|1
decl_stmt|;
comment|/**< the receive interface hardware detected an IP error / exception                                                     (only applies if !rcv_error&& !not_IP) failure indicated in err_code below, decode:                                                     - 1 = Not IP: the IP version field is neither 4 nor 6.                                                     - 2 = IPv4 Header Checksum Error: the IPv4 header has a checksum violation.                                                     - 3 = IP Malformed Header: the packet is not long enough to contain the IP header.                                                     - 4 = IP Malformed: the packet is not long enough to contain the bytes indicated by the IP                                                         header. Pad is allowed.                                                     - 5 = IP TTL Hop: the IPv4 TTL field or the IPv6 Hop Count field are zero.                                                     - 6 = IP Options */
name|uint64_t
name|is_bcast
range|:
literal|1
decl_stmt|;
comment|/**< set if the hardware determined that the packet is a broadcast */
name|uint64_t
name|is_mcast
range|:
literal|1
decl_stmt|;
comment|/**< set if the hardware determined that the packet is a multi-cast */
name|uint64_t
name|not_IP
range|:
literal|1
decl_stmt|;
comment|/**< set if the packet may not be IP (must be zero in this case) */
name|uint64_t
name|rcv_error
range|:
literal|1
decl_stmt|;
comment|/**< the receive interface hardware detected a receive error (must be zero in this case) */
comment|/* lower err_code = first-level descriptor of the work */
comment|/* zero for packet submitted by hardware that isn't on the slow path */
name|uint64_t
name|err_code
range|:
literal|8
decl_stmt|;
comment|/**< type is cvmx_pip_err_t */
block|}
name|s
struct|;
comment|/**< use this to get at the 16 vlan bits */
struct|struct
block|{
name|uint64_t
name|unused1
range|:
literal|16
decl_stmt|;
name|uint64_t
name|vlan
range|:
literal|16
decl_stmt|;
name|uint64_t
name|unused2
range|:
literal|32
decl_stmt|;
block|}
name|svlan
struct|;
comment|/**< use this struct if the hardware could not determine that the packet is ip */
struct|struct
block|{
name|uint64_t
name|bufs
range|:
literal|8
decl_stmt|;
comment|/**< HW sets this to the number of buffers used by this packet */
name|uint64_t
name|unused
range|:
literal|8
decl_stmt|;
name|uint64_t
name|vlan_valid
range|:
literal|1
decl_stmt|;
comment|/**< set to 1 if we found DSA/VLAN in the L2 */
name|uint64_t
name|vlan_stacked
range|:
literal|1
decl_stmt|;
comment|/**< Set to 1 if the DSA/VLAN tag is stacked */
name|uint64_t
name|unassigned
range|:
literal|1
decl_stmt|;
name|uint64_t
name|vlan_cfi
range|:
literal|1
decl_stmt|;
comment|/**< HW sets to the DSA/VLAN CFI flag (valid when vlan_valid) */
name|uint64_t
name|vlan_id
range|:
literal|12
decl_stmt|;
comment|/**< HW sets to the DSA/VLAN_ID field (valid when vlan_valid) */
name|uint64_t
name|pr
range|:
literal|4
decl_stmt|;
comment|/**< Ring Identifier (if PCIe). Requires PIP_GBL_CTL[RING_EN]=1 */
name|uint64_t
name|unassigned2
range|:
literal|12
decl_stmt|;
name|uint64_t
name|software
range|:
literal|1
decl_stmt|;
comment|/**< reserved for software use, hardware will clear on packet creation */
name|uint64_t
name|unassigned3
range|:
literal|1
decl_stmt|;
name|uint64_t
name|is_rarp
range|:
literal|1
decl_stmt|;
comment|/**< set if the hardware determined that the packet is rarp */
name|uint64_t
name|is_arp
range|:
literal|1
decl_stmt|;
comment|/**< set if the hardware determined that the packet is arp */
name|uint64_t
name|is_bcast
range|:
literal|1
decl_stmt|;
comment|/**< set if the hardware determined that the packet is a broadcast */
name|uint64_t
name|is_mcast
range|:
literal|1
decl_stmt|;
comment|/**< set if the hardware determined that the packet is a multi-cast */
name|uint64_t
name|not_IP
range|:
literal|1
decl_stmt|;
comment|/**< set if the packet may not be IP (must be one in this case) */
name|uint64_t
name|rcv_error
range|:
literal|1
decl_stmt|;
comment|/**< the receive interface hardware detected a receive error.                                                     Failure indicated in err_code below, decode:                                                     - 1 = partial error: a packet was partially received, but internal                                                         buffering / bandwidth was not adequate to receive the entire packet.                                                     - 2 = jabber error: the RGMII packet was too large and is truncated.                                                     - 3 = overrun error: the RGMII packet is longer than allowed and had                                                         an FCS error.                                                     - 4 = oversize error: the RGMII packet is longer than allowed.                                                     - 5 = alignment error: the RGMII packet is not an integer number of bytes                                                         and had an FCS error (100M and 10M only).                                                     - 6 = fragment error: the RGMII packet is shorter than allowed and had an                                                         FCS error.                                                     - 7 = GMX FCS error: the RGMII packet had an FCS error.                                                     - 8 = undersize error: the RGMII packet is shorter than allowed.                                                     - 9 = extend error: the RGMII packet had an extend error.                                                     - 10 = length mismatch error: the RGMII packet had a length that did not                                                         match the length field in the L2 HDR.                                                     - 11 = RGMII RX error/SPI4 DIP4 Error: the RGMII packet had one or more                                                         data reception errors (RXERR) or the SPI4 packet had one or more DIP4                                                         errors.                                                     - 12 = RGMII skip error/SPI4 Abort Error: the RGMII packet was not large                                                         enough to cover the skipped bytes or the SPI4 packet was terminated                                                         with an About EOPS.                                                     - 13 = RGMII nibble error/SPI4 Port NXA Error: the RGMII packet had a                                                         studder error (data not repeated - 10/100M only) or the SPI4 packet                                                         was sent to an NXA.                                                     - 16 = FCS error: a SPI4.2 packet had an FCS error.                                                     - 17 = Skip error: a packet was not large enough to cover the skipped bytes.                                                     - 18 = L2 header malformed: the packet is not long enough to contain the L2 */
comment|/* lower err_code = first-level descriptor of the work */
comment|/* zero for packet submitted by hardware that isn't on the slow path */
name|uint64_t
name|err_code
range|:
literal|8
decl_stmt|;
comment|/* type is cvmx_pip_err_t (union, so can't use directly */
block|}
name|snoip
struct|;
block|}
name|cvmx_pip_wqe_word2
typedef|;
comment|/**  * Work queue entry format  *  * must be 8-byte aligned  */
typedef|typedef
struct|struct
block|{
comment|/*****************************************************************      * WORD 0      *  HW WRITE: the following 64 bits are filled by HW when a packet arrives      */
comment|/**      * raw chksum result generated by the HW      */
name|uint16_t
name|hw_chksum
decl_stmt|;
comment|/**      * Field unused by hardware - available for software      */
name|uint8_t
name|unused
decl_stmt|;
comment|/**      * Next pointer used by hardware for list maintenance.      * May be written/read by HW before the work queue      *           entry is scheduled to a PP      * (Only 36 bits used in Octeon 1)      */
name|uint64_t
name|next_ptr
range|:
literal|40
decl_stmt|;
comment|/*****************************************************************      * WORD 1      *  HW WRITE: the following 64 bits are filled by HW when a packet arrives      */
comment|/**      * HW sets to the total number of bytes in the packet      */
name|uint64_t
name|len
range|:
literal|16
decl_stmt|;
comment|/**      * HW sets this to input physical port      */
name|uint64_t
name|ipprt
range|:
literal|6
decl_stmt|;
comment|/**      * HW sets this to what it thought the priority of the input packet was      */
name|uint64_t
name|qos
range|:
literal|3
decl_stmt|;
comment|/**      * the group that the work queue entry will be scheduled to      */
name|uint64_t
name|grp
range|:
literal|4
decl_stmt|;
comment|/**      * the type of the tag (ORDERED, ATOMIC, NULL)      */
name|cvmx_pow_tag_type_t
name|tag_type
range|:
literal|3
decl_stmt|;
comment|/**      * the synchronization/ordering tag      */
name|uint64_t
name|tag
range|:
literal|32
decl_stmt|;
comment|/**      * WORD 2      *   HW WRITE: the following 64-bits are filled in by hardware when a packet arrives      *   This indicates a variety of status and error conditions.      */
name|cvmx_pip_wqe_word2
name|word2
decl_stmt|;
comment|/**      * Pointer to the first segment of the packet.      */
name|cvmx_buf_ptr_t
name|packet_ptr
decl_stmt|;
comment|/**      *   HW WRITE: octeon will fill in a programmable amount from the      *             packet, up to (at most, but perhaps less) the amount      *             needed to fill the work queue entry to 128 bytes      *   If the packet is recognized to be IP, the hardware starts (except that      *   the IPv4 header is padded for appropriate alignment) writing here where      *   the IP header starts.      *   If the packet is not recognized to be IP, the hardware starts writing      *   the beginning of the packet here.      */
name|uint8_t
name|packet_data
index|[
literal|96
index|]
decl_stmt|;
comment|/**      * If desired, SW can make the work Q entry any length. For the      * purposes of discussion here, Assume 128B always, as this is all that      * the hardware deals with.      *      */
block|}
name|CVMX_CACHE_LINE_ALIGNED
name|cvmx_wqe_t
typedef|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_WQE_H__ */
end_comment

end_unit

