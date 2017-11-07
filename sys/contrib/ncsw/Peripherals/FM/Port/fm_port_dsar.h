begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_port_dsar.h   @Description   Deep Sleep Auto Response project - common module header file.                                 Author - Eyal Harari                   @Cautions      See the FMan Controller spec and design document for more information. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_PORT_DSAR_H_
end_ifndef

begin_define
define|#
directive|define
name|__FM_PORT_DSAR_H_
end_define

begin_define
define|#
directive|define
name|DSAR_GETSER_MASK
value|0xFF0000FF
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response VLAN-IPv4 Binding Table (for ARP/ICMPv4)                 Refer to the FMan Controller spec for more details. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|ipv4Addr
decl_stmt|;
comment|/*!< 32 bit IPv4 Address. */
name|uint16_t
name|vlanId
decl_stmt|;
comment|/*!< 12 bits VLAN ID. The 4 left-most bits should be cleared                      */
comment|/*!< This field should be 0x0000 for an entry with no VLAN tag or a null VLAN ID. */
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|_PackedType
name|t_DsarArpBindingEntry
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response Address Resolution Protocol Statistics Descriptor                 Refer to the FMan Controller spec for more details. 	            0x00 INVAL_CNT Invalid ARP IPv4-Ethernet counter 	            0x04 ECHO_CNT Echo counter 	            0x08 CD_CNT Conflict Detection counter 	            0x0C AR_CNT Auto-Response counter 	            0x10 RATM_CNT Replies Addressed To Me counter 	            0x14 UKOP_CNT Unknown Operation counter 	            0x18 NMTP_CNT Not my TPA counter 	            0x1C NMVLAN_CNT Not My VLAN counter */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|invalCnt
decl_stmt|;
comment|/**< Invalid ARP IPv4-Ethernet counter. */
name|uint32_t
name|echoCnt
decl_stmt|;
comment|/**< Echo counter. 						*/
name|uint32_t
name|cdCnt
decl_stmt|;
comment|/**< Conflict Detection counter.		*/
name|uint32_t
name|arCnt
decl_stmt|;
comment|/**< Auto-Response counter.				*/
name|uint32_t
name|ratmCnt
decl_stmt|;
comment|/**< Replies Addressed To Me counter.	*/
name|uint32_t
name|ukopCnt
decl_stmt|;
comment|/**< Unknown Operation counter.			*/
name|uint32_t
name|nmtpCnt
decl_stmt|;
comment|/**< Not my TPA counter.				*/
name|uint32_t
name|nmVlanCnt
decl_stmt|;
comment|/**< Not My VLAN counter				*/
block|}
name|_PackedType
name|t_DsarArpStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response Address Resolution Protocol Descriptor                 0x0 0-15 Control bits [0-15]. Bit 15  = CDEN.                 0x2 0-15 NumOfBindings Number of entries in the binding list.                 0x4 0-15 BindingsPointer Bindings Pointer. This points to an IPv4-MAC Addresses Bindings list.                 0x6 0-15                 0x8 0-15 StatisticsPointer Statistics Pointer. This field points to the ARP Descriptors statistics data structure.                 0xA 0-15                 0xC 0-15 Reserved Reserved. Must be cleared.                 0xE 015  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint16_t
name|control
decl_stmt|;
comment|/** Control bits [0-15]. Bit 15  = CDEN */
name|uint16_t
name|numOfBindings
decl_stmt|;
comment|/**< Number of VLAN-IPv4 */
name|uint32_t
name|p_Bindings
decl_stmt|;
comment|/**< VLAN-IPv4 Bindings table pointer. */
name|uint32_t
name|p_Statistics
decl_stmt|;
comment|/**< Statistics Data Structure pointer. */
name|uint32_t
name|reserved1
decl_stmt|;
comment|/**< Reserved. */
block|}
name|_PackedType
name|t_DsarArpDescriptor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response VLAN-IPv4 Binding Table (for ARP/ICMPv4)                 Refer to the FMan Controller spec for more details. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|ipv4Addr
decl_stmt|;
comment|/*!< 32 bit IPv4 Address. */
name|uint16_t
name|vlanId
decl_stmt|;
comment|/*!< 12 bits VLAN ID. The 4 left-most bits should be cleared                      */
comment|/*!< This field should be 0x0000 for an entry with no VLAN tag or a null VLAN ID. */
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|_PackedType
name|t_DsarIcmpV4BindingEntry
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response ICMPv4 Statistics Descriptor                 Refer to the FMan Controller spec for more details.                 0x00 INVAL_CNT Invalid ICMPv4 header counter                 0x04 NMVLAN_CNT Not My VLAN counter                 0x08 NMIP_CNT Not My IP counter                 0x0C AR_CNT Auto-Response counter                 0x10 CSERR_CNT Checksum Error counter                 0x14 Reserved Reserved                 0x18 Reserved Reserved                 0x1C Reserved Reserved  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|invalCnt
decl_stmt|;
comment|/**< Invalid ICMPv4 Echo counter. */
name|uint32_t
name|nmVlanCnt
decl_stmt|;
comment|/**< Not My VLAN counter          */
name|uint32_t
name|nmIpCnt
decl_stmt|;
comment|/**< Not My IP counter		      */
name|uint32_t
name|arCnt
decl_stmt|;
comment|/**< Auto-Response counter        */
name|uint32_t
name|cserrCnt
decl_stmt|;
comment|/**< Checksum Error counter       */
name|uint32_t
name|reserved0
decl_stmt|;
comment|/**< Reserved                     */
name|uint32_t
name|reserved1
decl_stmt|;
comment|/**< Reserved                     */
name|uint32_t
name|reserved2
decl_stmt|;
comment|/**< Reserved                     */
block|}
name|_PackedType
name|t_DsarIcmpV4Statistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response ICMPv4 Descriptor                 0x0 0-15 Control bits [0-15]                 0x2 0-15 NumOfBindings Number of entries in the binding list.                 0x4 0-15 BindingsPointer Bindings Pointer. This points to an VLAN-IPv4 Addresses Bindings list.                 0x6 0-15                 0x8 0-15 StatisticsPointer Statistics Pointer. This field points to the ICMPv4 statistics data structure.                 0xA 0-15                 0xC 0-15 Reserved Reserved. Must be cleared.                 0xE 015  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint16_t
name|control
decl_stmt|;
comment|/** Control bits [0-15].                */
name|uint16_t
name|numOfBindings
decl_stmt|;
comment|/**< Number of VLAN-IPv4                */
name|uint32_t
name|p_Bindings
decl_stmt|;
comment|/**< VLAN-IPv4 Bindings table pointer.  */
name|uint32_t
name|p_Statistics
decl_stmt|;
comment|/**< Statistics Data Structure pointer. */
name|uint32_t
name|reserved1
decl_stmt|;
comment|/**< Reserved.                          */
block|}
name|_PackedType
name|t_DsarIcmpV4Descriptor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response VLAN-IPv4 Binding Table (for ARP/ICMPv4)                 The 4 left-most bits (15:12) of the VlanId parameter are control flags.                 Flags[3:1] (VlanId[15:13]): Reserved, should be cleared.                 Flags[0] (VlanId[12]): Temporary address.                  0 - Assigned IP address.                  1- Temporary (tentative) IP address.                 Refer to the FMan Controller spec for more details. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|ipv6Addr
index|[
literal|4
index|]
decl_stmt|;
comment|/*!< 3 * 32 bit IPv4 Address.                                                    */
name|uint16_t
name|resFlags
range|:
literal|4
decl_stmt|;
comment|/*!< reserved flags. should be cleared                                           */
name|uint16_t
name|vlanId
range|:
literal|12
decl_stmt|;
comment|/*!< 12 bits VLAN ID.                                                            */
comment|/*!< This field should be 0x000 for an entry with no VLAN tag or a null VLAN ID. */
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|_PackedType
name|t_DsarIcmpV6BindingEntry
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response ICMPv4 Statistics Descriptor                 Refer to the FMan Controller spec for more details.                 0x00 INVAL_CNT Invalid ICMPv4 header counter                 0x04 NMVLAN_CNT Not My VLAN counter                 0x08 NMIP_CNT Not My IP counter                 0x0C AR_CNT Auto-Response counter                 0x10 CSERR_CNT Checksum Error counter                 0x14 MCAST_CNT Multicast counter                 0x18 Reserved Reserved                 0x1C Reserved Reserved  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|invalCnt
decl_stmt|;
comment|/**< Invalid ICMPv4 Echo counter. */
name|uint32_t
name|nmVlanCnt
decl_stmt|;
comment|/**< Not My VLAN counter          */
name|uint32_t
name|nmIpCnt
decl_stmt|;
comment|/**< Not My IP counter		      */
name|uint32_t
name|arCnt
decl_stmt|;
comment|/**< Auto-Response counter        */
name|uint32_t
name|reserved1
decl_stmt|;
comment|/**< Reserved                     */
name|uint32_t
name|reserved2
decl_stmt|;
comment|/**< Reserved                     */
name|uint32_t
name|reserved3
decl_stmt|;
comment|/**< Reserved                     */
name|uint32_t
name|reserved4
decl_stmt|;
comment|/**< Reserved                     */
block|}
name|_PackedType
name|t_DsarIcmpV6Statistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response Neighbor Discovery Statistics Descriptor                 0x00 INVAL_CNT Invalid Neighbor Discovery message counter                 0x04 NMVLAN_CNT Not My VLAN counter                 0x08 NMIP_CNT Not My IP counter                 0x0C AR_CNT Auto-Response counter                 0x10 CSERR_CNT Checksum Error counter                 0x14 USADVERT_CNT Unsolicited Neighbor Advertisements counter                 0x18 NMMCAST_CNT Not My Multicast group counter                 0x1C NSLLA_CNT No Source Link-Layer Address counter. Indicates that there was a match on a Target                      Address of a packet that its source IP address is a unicast address, but the ICMPv6                      Source Link-layer Address option is omitted */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|invalCnt
decl_stmt|;
comment|/**< Invalid ICMPv4 Echo counter.                */
name|uint32_t
name|nmVlanCnt
decl_stmt|;
comment|/**< Not My VLAN counter                         */
name|uint32_t
name|nmIpCnt
decl_stmt|;
comment|/**< Not My IP counter		                   */
name|uint32_t
name|arCnt
decl_stmt|;
comment|/**< Auto-Response counter                       */
name|uint32_t
name|reserved1
decl_stmt|;
comment|/**< Reserved                                    */
name|uint32_t
name|usadvertCnt
decl_stmt|;
comment|/**< Unsolicited Neighbor Advertisements counter */
name|uint32_t
name|nmmcastCnt
decl_stmt|;
comment|/**< Not My Multicast group counter              */
name|uint32_t
name|nsllaCnt
decl_stmt|;
comment|/**< No Source Link-Layer Address counter        */
block|}
name|_PackedType
name|t_NdStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response ICMPv6 Descriptor                 0x0 0-15 Control bits [0-15]                 0x2 0-15 NumOfBindings Number of entries in the binding list.                 0x4 0-15 BindingsPointer Bindings Pointer. This points to an VLAN-IPv4 Addresses Bindings list.                 0x6 0-15                 0x8 0-15 StatisticsPointer Statistics Pointer. This field points to the ICMPv4 statistics data structure.                 0xA 0-15                 0xC 0-15 Reserved Reserved. Must be cleared.                 0xE 015  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint16_t
name|control
decl_stmt|;
comment|/** Control bits [0-15].                */
name|uint16_t
name|numOfBindings
decl_stmt|;
comment|/**< Number of VLAN-IPv6                */
name|uint32_t
name|p_Bindings
decl_stmt|;
comment|/**< VLAN-IPv4 Bindings table pointer.  */
name|uint32_t
name|p_Statistics
decl_stmt|;
comment|/**< Statistics Data Structure pointer. */
name|uint32_t
name|reserved1
decl_stmt|;
comment|/**< Reserved.                          */
block|}
name|_PackedType
name|t_DsarIcmpV6Descriptor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Internet Control Message Protocol (ICMPv6) Echo message header                 The fields names are taken from RFC 4443. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* 0                   1                   2                   3     */
end_comment

begin_comment
comment|/* 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1   */
end_comment

begin_comment
comment|/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_comment
comment|/* |     Type      |     Code      |          Checksum             | */
end_comment

begin_comment
comment|/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_comment
comment|/* |           Identifier          |        Sequence Number        | */
end_comment

begin_comment
comment|/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_comment
comment|/* |     Data ...                                                    */
end_comment

begin_comment
comment|/* +-+-+-+-+-                                                        */
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|code
decl_stmt|;
name|uint16_t
name|checksum
decl_stmt|;
name|uint16_t
name|identifier
decl_stmt|;
name|uint16_t
name|sequenceNumber
decl_stmt|;
block|}
name|_PackedType
name|t_IcmpV6EchoHdr
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Internet Control Message Protocol (ICMPv6)                  Neighbor Solicitation/Advertisement header                 The fields names are taken from RFC 4861.                 The R/S/O fields are valid for Neighbor Advertisement only */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* 0                   1                   2                   3  * 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |     Type      |     Code      |          Checksum             |  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |R|S|O|                     Reserved                            |  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |                                                               |  * +                                                               +  * |                                                               |  * +                       Target Address                          +  * |                                                               |  * +                                                               +  * |                                                               |  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |   Options ...  * +-+-+-+-+-+-+-+-+-+-+-+-  *  * Options Format:  * 0                   1                   2                   3  * 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |     Type      |    Length     |   Link-Layer Address ...      |  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |                  Link-Layer Address                           |  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|code
decl_stmt|;
name|uint16_t
name|checksum
decl_stmt|;
name|uint32_t
name|router
range|:
literal|1
decl_stmt|;
name|uint32_t
name|solicited
range|:
literal|1
decl_stmt|;
name|uint32_t
name|override
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved
range|:
literal|29
decl_stmt|;
name|uint32_t
name|targetAddr
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|optionType
decl_stmt|;
name|uint8_t
name|optionLength
decl_stmt|;
name|uint8_t
name|linkLayerAddr
index|[
literal|6
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_IcmpV6NdHdr
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response ICMPv6 Descriptor                 0x0 0-15 Control bits [0-15]                 0x2 0-15 NumOfBindings Number of entries in the binding list.                 0x4 0-15 BindingsPointer Bindings Pointer. This points to an VLAN-IPv4 Addresses Bindings list.                 0x6 0-15                 0x8 0-15 StatisticsPointer Statistics Pointer. This field points to the ICMPv4 statistics data structure.                 0xA 0-15                 0xC 0-15 Reserved Reserved. Must be cleared.                 0xE 015  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint16_t
name|control
decl_stmt|;
comment|/** Control bits [0-15].                    */
name|uint16_t
name|numOfBindings
decl_stmt|;
comment|/**< Number of VLAN-IPv6                    */
name|uint32_t
name|p_Bindings
decl_stmt|;
comment|/**< VLAN-IPv4 Bindings table pointer.      */
name|uint32_t
name|p_Statistics
decl_stmt|;
comment|/**< Statistics Data Structure pointer.     */
name|uint32_t
name|solicitedAddr
decl_stmt|;
comment|/**< Solicited Node Multicast Group Address */
block|}
name|_PackedType
name|t_DsarNdDescriptor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** @Description    Deep Sleep Auto Response SNMP OIDs table entry                   */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|oidSize
decl_stmt|;
comment|/**< Size in octets of the OID. */
name|uint16_t
name|resSize
decl_stmt|;
comment|/**< Size in octets of the value that is attached to the OID. */
name|uint32_t
name|p_Oid
decl_stmt|;
comment|/**< Pointer to the OID. OID is encoded in BER but type and length are excluded. */
name|uint32_t
name|resValOrPtr
decl_stmt|;
comment|/**< Value (for up to 4 octets) or pointer to the Value. Encoded in BER. */
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|t_OidsTblEntry
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response SNMP IPv4 Addresses Table Entry                 Refer to the FMan Controller spec for more details. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|ipv4Addr
decl_stmt|;
comment|/*!< 32 bit IPv4 Address. */
name|uint16_t
name|vlanId
decl_stmt|;
comment|/*!< 12 bits VLAN ID. The 4 left-most bits should be cleared                      */
comment|/*!< This field should be 0x0000 for an entry with no VLAN tag or a null VLAN ID. */
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|t_DsarSnmpIpv4AddrTblEntry
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response SNMP IPv6 Addresses Table Entry                 Refer to the FMan Controller spec for more details. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|ipv6Addr
index|[
literal|4
index|]
decl_stmt|;
comment|/*!< 4 * 32 bit IPv6 Address.                                                     */
name|uint16_t
name|vlanId
decl_stmt|;
comment|/*!< 12 bits VLAN ID. The 4 left-most bits should be cleared                      */
comment|/*!< This field should be 0x0000 for an entry with no VLAN tag or a null VLAN ID. */
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|t_DsarSnmpIpv6AddrTblEntry
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** @Description    Deep Sleep Auto Response SNMP statistics table                   */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|snmpErrCnt
decl_stmt|;
comment|/**< Counts SNMP errors (wrong version, BER encoding, format). */
name|uint32_t
name|snmpCommunityErrCnt
decl_stmt|;
comment|/**< Counts messages that were dropped due to insufficient permission. */
name|uint32_t
name|snmpTotalDiscardCnt
decl_stmt|;
comment|/**< Counts any message that was dropped. */
name|uint32_t
name|snmpGetReqCnt
decl_stmt|;
comment|/**< Counts the number of get-request messages */
name|uint32_t
name|snmpGetNextReqCnt
decl_stmt|;
comment|/**< Counts the number of get-next-request messages */
block|}
name|t_DsarSnmpStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Deep Sleep Auto Response SNMP Descriptor  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|control
decl_stmt|;
comment|/**< Control bits [0-15]. */
name|uint16_t
name|maxSnmpMsgLength
decl_stmt|;
comment|/**< Maximal allowed SNMP message length. */
name|uint16_t
name|numOfIpv4Addresses
decl_stmt|;
comment|/**< Number of entries in IPv4 addresses table. */
name|uint16_t
name|numOfIpv6Addresses
decl_stmt|;
comment|/**< Number of entries in IPv6 addresses table. */
name|uint32_t
name|p_Ipv4AddrTbl
decl_stmt|;
comment|/**< Pointer to IPv4 addresses table. */
name|uint32_t
name|p_Ipv6AddrTbl
decl_stmt|;
comment|/**< Pointer to IPv6 addresses table. */
name|uint32_t
name|p_RdOnlyCommunityStr
decl_stmt|;
comment|/**< Pointer to the Read Only Community String. */
name|uint32_t
name|p_RdWrCommunityStr
decl_stmt|;
comment|/**< Pointer to the Read Write Community String. */
name|uint32_t
name|p_OidsTbl
decl_stmt|;
comment|/**< Pointer to OIDs table. */
name|uint32_t
name|oidsTblSize
decl_stmt|;
comment|/**< Number of entries in OIDs table. */
name|uint32_t
name|p_Statistics
decl_stmt|;
comment|/**< Pointer to SNMP statistics table. */
block|}
name|t_DsarSnmpDescriptor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** @Description    Deep Sleep Auto Response (Common) Statistics                   */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|dsarDiscarded
decl_stmt|;
name|uint32_t
name|dsarErrDiscarded
decl_stmt|;
name|uint32_t
name|dsarFragDiscarded
decl_stmt|;
name|uint32_t
name|dsarTunnelDiscarded
decl_stmt|;
name|uint32_t
name|dsarArpDiscarded
decl_stmt|;
name|uint32_t
name|dsarIpDiscarded
decl_stmt|;
name|uint32_t
name|dsarTcpDiscarded
decl_stmt|;
name|uint32_t
name|dsarUdpDiscarded
decl_stmt|;
name|uint32_t
name|dsarIcmpV6ChecksumErr
decl_stmt|;
comment|/* ICMPv6 Checksum Error counter */
name|uint32_t
name|dsarIcmpV6OtherType
decl_stmt|;
comment|/* ICMPv6 'Other' type (not Echo or Neighbor Solicitaion/Advertisement counter */
name|uint32_t
name|dsarIcmpV4OtherType
decl_stmt|;
comment|/* ICMPv4 'Other' type (not Echo) counter */
block|}
name|_PackedType
name|t_ArStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** @Description    Deep Sleep Auto Response TCP/UDP port filter table entry                   */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|Ports
decl_stmt|;
name|uint32_t
name|PortsMask
decl_stmt|;
block|}
name|_PackedType
name|t_PortTblEntry
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** @Description    Deep Sleep Auto Response Common Parameters Descriptor                   */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint8_t
name|arTxPort
decl_stmt|;
comment|/* 0x00 0-7 Auto Response Transmit Port number            */
name|uint8_t
name|controlBits
decl_stmt|;
comment|/* 0x00 8-15 Auto Response control bits                   */
name|uint16_t
name|res1
decl_stmt|;
comment|/* 0x00 16-31 Reserved                                    */
name|uint32_t
name|activeHPNIA
decl_stmt|;
comment|/* 0x04 0-31 Active mode Hardware Parser NIA              */
name|uint16_t
name|snmpPort
decl_stmt|;
comment|/* 0x08 0-15 SNMP Port.                                   */
name|uint8_t
name|macStationAddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x08 16-31 and 0x0C 0-31 MAC Station Address           */
name|uint8_t
name|res2
decl_stmt|;
comment|/* 0x10 0-7 Reserved				    					 */
name|uint8_t
name|filterControl
decl_stmt|;
comment|/* 0x10 8-15 Filtering Control Bits.                      */
name|uint16_t
name|tcpControlPass
decl_stmt|;
comment|/* 0x10 16-31 TCP control pass flags					     */
name|uint8_t
name|ipProtocolTblSize
decl_stmt|;
comment|/* 0x14 0-7 IP Protocol Table Size.                       */
name|uint8_t
name|udpPortTblSize
decl_stmt|;
comment|/* 0x14 8-15 UDP Port Table Size.                         */
name|uint8_t
name|tcpPortTblSize
decl_stmt|;
comment|/* 0x14 16-23 TCP Port Table Size.                        */
name|uint8_t
name|res3
decl_stmt|;
comment|/* 0x14 24-31 Reserved                                    */
name|uint32_t
name|p_IpProtocolFiltTbl
decl_stmt|;
comment|/* 0x18 0-31 Pointer to IP Protocol Filter Table          */
name|uint32_t
name|p_UdpPortFiltTbl
decl_stmt|;
comment|/* 0x1C 0-31 Pointer to UDP Port Filter Table          */
name|uint32_t
name|p_TcpPortFiltTbl
decl_stmt|;
comment|/* 0x20 0-31 Pointer to TCP Port Filter Table          */
name|uint32_t
name|res4
decl_stmt|;
comment|/* 0x24 Reserved                                          */
name|uint32_t
name|p_ArpDescriptor
decl_stmt|;
comment|/* 0x28 0-31 ARP Descriptor Pointer.                      */
name|uint32_t
name|p_NdDescriptor
decl_stmt|;
comment|/* 0x2C 0-31 Neighbor Discovery Descriptor.               */
name|uint32_t
name|p_IcmpV4Descriptor
decl_stmt|;
comment|/* 0x30 0-31 ICMPv4 Descriptor pointer.                   */
name|uint32_t
name|p_IcmpV6Descriptor
decl_stmt|;
comment|/* 0x34 0-31 ICMPv6 Descriptor pointer.                   */
name|uint32_t
name|p_SnmpDescriptor
decl_stmt|;
comment|/* 0x38 0-31 SNMP Descriptor pointer.                     */
name|uint32_t
name|p_ArStats
decl_stmt|;
comment|/* 0x3C 0-31 Pointer to Auto Response Statistics          */
block|}
name|_PackedType
name|t_ArCommonDesc
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_comment
comment|/* t_ArCommonDesc.filterControl bits */
end_comment

begin_define
define|#
directive|define
name|IP_PROT_TBL_PASS_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|UDP_PORT_TBL_PASS_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|TCP_PORT_TBL_PASS_MASK
value|0x02
end_define

begin_comment
comment|/* Offset of TCF flags within TCP packet */
end_comment

begin_define
define|#
directive|define
name|TCP_FLAGS_OFFSET
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_PORT_DSAR_H_ */
end_comment

end_unit

