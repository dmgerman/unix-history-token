begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          enet_ext.h   @Description   Ethernet generic definitions and enums. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ENET_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__ENET_EXT_H
end_define

begin_define
define|#
directive|define
name|ENET_NUM_OCTETS_PER_ADDRESS
value|6
end_define

begin_comment
comment|/**< Number of octets (8-bit bytes) in an ethernet address */
end_comment

begin_define
define|#
directive|define
name|ENET_GROUP_ADDR
value|0x01
end_define

begin_comment
comment|/**< Group address mask for ethernet addresses */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Ethernet Address */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|t_EnetAddr
index|[
name|ENET_NUM_OCTETS_PER_ADDRESS
index|]
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Ethernet Address Type. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_EnetAddrType
block|{
name|e_ENET_ADDR_TYPE_INDIVIDUAL
block|,
comment|/**< Individual (unicast) address */
name|e_ENET_ADDR_TYPE_GROUP
block|,
comment|/**< Group (multicast) address */
name|e_ENET_ADDR_TYPE_BROADCAST
comment|/**< Broadcast address */
block|}
name|e_EnetAddrType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Ethernet MAC-PHY Interface */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_EnetInterface
block|{
name|e_ENET_IF_MII
init|=
literal|0x00010000
block|,
comment|/**< MII interface */
name|e_ENET_IF_RMII
init|=
literal|0x00020000
block|,
comment|/**< RMII interface */
name|e_ENET_IF_SMII
init|=
literal|0x00030000
block|,
comment|/**< SMII interface */
name|e_ENET_IF_GMII
init|=
literal|0x00040000
block|,
comment|/**< GMII interface */
name|e_ENET_IF_RGMII
init|=
literal|0x00050000
block|,
comment|/**< RGMII interface */
name|e_ENET_IF_TBI
init|=
literal|0x00060000
block|,
comment|/**< TBI interface */
name|e_ENET_IF_RTBI
init|=
literal|0x00070000
block|,
comment|/**< RTBI interface */
name|e_ENET_IF_SGMII
init|=
literal|0x00080000
block|,
comment|/**< SGMII interface */
name|e_ENET_IF_XGMII
init|=
literal|0x00090000
block|,
comment|/**< XGMII interface */
name|e_ENET_IF_QSGMII
init|=
literal|0x000a0000
comment|/**< QSGMII interface */
block|}
name|e_EnetInterface
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Ethernet Duplex Mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_EnetDuplexMode
block|{
name|e_ENET_HALF_DUPLEX
block|,
comment|/**< Half-Duplex mode */
name|e_ENET_FULL_DUPLEX
comment|/**< Full-Duplex mode */
block|}
name|e_EnetDuplexMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Ethernet Speed (nominal data rate) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_EnetSpeed
block|{
name|e_ENET_SPEED_10
init|=
literal|10
block|,
comment|/**< 10 Mbps */
name|e_ENET_SPEED_100
init|=
literal|100
block|,
comment|/**< 100 Mbps */
name|e_ENET_SPEED_1000
init|=
literal|1000
block|,
comment|/**< 1000 Mbps = 1 Gbps */
name|e_ENET_SPEED_10000
init|=
literal|10000
comment|/**< 10000 Mbps = 10 Gbps */
block|}
name|e_EnetSpeed
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Ethernet mode (combination of MAC-PHY interface and speed) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_EnetMode
block|{
name|e_ENET_MODE_INVALID
init|=
literal|0
block|,
comment|/**< Invalid Ethernet mode */
name|e_ENET_MODE_MII_10
init|=
operator|(
name|e_ENET_IF_MII
operator||
name|e_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps MII   */
name|e_ENET_MODE_MII_100
init|=
operator|(
name|e_ENET_IF_MII
operator||
name|e_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps MII   */
name|e_ENET_MODE_RMII_10
init|=
operator|(
name|e_ENET_IF_RMII
operator||
name|e_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps RMII  */
name|e_ENET_MODE_RMII_100
init|=
operator|(
name|e_ENET_IF_RMII
operator||
name|e_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps RMII  */
name|e_ENET_MODE_SMII_10
init|=
operator|(
name|e_ENET_IF_SMII
operator||
name|e_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps SMII  */
name|e_ENET_MODE_SMII_100
init|=
operator|(
name|e_ENET_IF_SMII
operator||
name|e_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps SMII  */
name|e_ENET_MODE_GMII_1000
init|=
operator|(
name|e_ENET_IF_GMII
operator||
name|e_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps GMII  */
name|e_ENET_MODE_RGMII_10
init|=
operator|(
name|e_ENET_IF_RGMII
operator||
name|e_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps RGMII */
name|e_ENET_MODE_RGMII_100
init|=
operator|(
name|e_ENET_IF_RGMII
operator||
name|e_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps RGMII */
name|e_ENET_MODE_RGMII_1000
init|=
operator|(
name|e_ENET_IF_RGMII
operator||
name|e_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps RGMII */
name|e_ENET_MODE_TBI_1000
init|=
operator|(
name|e_ENET_IF_TBI
operator||
name|e_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps TBI   */
name|e_ENET_MODE_RTBI_1000
init|=
operator|(
name|e_ENET_IF_RTBI
operator||
name|e_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps RTBI  */
name|e_ENET_MODE_SGMII_10
init|=
operator|(
name|e_ENET_IF_SGMII
operator||
name|e_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps SGMII */
name|e_ENET_MODE_SGMII_100
init|=
operator|(
name|e_ENET_IF_SGMII
operator||
name|e_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps SGMII */
name|e_ENET_MODE_SGMII_1000
init|=
operator|(
name|e_ENET_IF_SGMII
operator||
name|e_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps SGMII */
name|e_ENET_MODE_XGMII_10000
init|=
operator|(
name|e_ENET_IF_XGMII
operator||
name|e_ENET_SPEED_10000
operator|)
block|,
comment|/**< 10000 Mbps XGMII */
name|e_ENET_MODE_QSGMII_1000
init|=
operator|(
name|e_ENET_IF_QSGMII
operator||
name|e_ENET_SPEED_1000
operator|)
comment|/**<  1000 Mbps QSGMII */
block|}
name|e_EnetMode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IS_ENET_MODE_VALID
parameter_list|(
name|mode
parameter_list|)
define|\
value|(((mode) == e_ENET_MODE_MII_10     ) || \          ((mode) == e_ENET_MODE_MII_100    ) || \          ((mode) == e_ENET_MODE_RMII_10    ) || \          ((mode) == e_ENET_MODE_RMII_100   ) || \          ((mode) == e_ENET_MODE_SMII_10    ) || \          ((mode) == e_ENET_MODE_SMII_100   ) || \          ((mode) == e_ENET_MODE_GMII_1000  ) || \          ((mode) == e_ENET_MODE_RGMII_10   ) || \          ((mode) == e_ENET_MODE_RGMII_100  ) || \          ((mode) == e_ENET_MODE_RGMII_1000 ) || \          ((mode) == e_ENET_MODE_TBI_1000   ) || \          ((mode) == e_ENET_MODE_RTBI_1000  ) || \          ((mode) == e_ENET_MODE_SGMII_10   ) || \          ((mode) == e_ENET_MODE_SGMII_100  ) || \          ((mode) == e_ENET_MODE_SGMII_1000 ) || \          ((mode) == e_ENET_MODE_XGMII_10000) || \          ((mode) == e_ENET_MODE_QSGMII_1000))
end_define

begin_define
define|#
directive|define
name|MAKE_ENET_MODE
parameter_list|(
name|_interface
parameter_list|,
name|_speed
parameter_list|)
value|(e_EnetMode)((_interface) | (_speed))
end_define

begin_define
define|#
directive|define
name|ENET_INTERFACE_FROM_MODE
parameter_list|(
name|mode
parameter_list|)
value|(e_EnetInterface)((mode)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|ENET_SPEED_FROM_MODE
parameter_list|(
name|mode
parameter_list|)
value|(e_EnetSpeed)((mode)& 0x0000FFFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ENET_EXT_H */
end_comment

end_unit

