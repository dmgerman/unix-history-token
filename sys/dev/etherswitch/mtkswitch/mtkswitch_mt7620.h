begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Stanislav Galabov.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MTKSWITCH_MT7620_H__
end_ifndef

begin_define
define|#
directive|define
name|__MTKSWITCH_MT7620_H__
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_ATC
value|0x0080
end_define

begin_define
define|#
directive|define
name|ATC_BUSY
value|(1u<<15)
end_define

begin_define
define|#
directive|define
name|ATC_AC_MAT_NON_STATIC_MACS
value|(4u<<8)
end_define

begin_define
define|#
directive|define
name|ATC_AC_CMD_CLEAN
value|(2u<<0)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VTCR
value|0x0090
end_define

begin_define
define|#
directive|define
name|VTCR_BUSY
value|(1u<<31)
end_define

begin_define
define|#
directive|define
name|VTCR_FUNC_VID_READ
value|(0u<<12)
end_define

begin_define
define|#
directive|define
name|VTCR_FUNC_VID_WRITE
value|(1u<<12)
end_define

begin_define
define|#
directive|define
name|VTCR_FUNC_VID_INVALID
value|(2u<<12)
end_define

begin_define
define|#
directive|define
name|VTCR_FUNC_VID_VALID
value|(3u<<12)
end_define

begin_define
define|#
directive|define
name|VTCR_IDX_INVALID
value|(1u<<16)
end_define

begin_define
define|#
directive|define
name|VTCR_VID_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VAWD1
value|0x0094
end_define

begin_define
define|#
directive|define
name|VAWD1_IVL_MAC
value|(1u<<30)
end_define

begin_define
define|#
directive|define
name|VAWD1_VTAG_EN
value|(1u<<28)
end_define

begin_define
define|#
directive|define
name|VAWD1_PORT_MEMBER
parameter_list|(
name|p
parameter_list|)
value|((1u<<16)<<(p))
end_define

begin_define
define|#
directive|define
name|VAWD1_MEMBER_OFF
value|16
end_define

begin_define
define|#
directive|define
name|VAWD1_MEMBER_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|VAWD1_FID_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|VAWD1_VALID
value|(1u<<0)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VAWD2
value|0x0098
end_define

begin_define
define|#
directive|define
name|VAWD2_PORT_UNTAGGED
parameter_list|(
name|p
parameter_list|)
value|(0u<<((p)*2))
end_define

begin_define
define|#
directive|define
name|VAWD2_PORT_TAGGED
parameter_list|(
name|p
parameter_list|)
value|(2u<<((p)*2))
end_define

begin_define
define|#
directive|define
name|VAWD2_PORT_MASK
parameter_list|(
name|p
parameter_list|)
value|(3u<<((p)*2))
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VTIM
parameter_list|(
name|v
parameter_list|)
value|((((v)>> 1) * 4) + 0x100)
end_define

begin_define
define|#
directive|define
name|VTIM_OFF
parameter_list|(
name|v
parameter_list|)
value|(((v)& 1) ? 12 : 0)
end_define

begin_define
define|#
directive|define
name|VTIM_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PIAC
value|0x7004
end_define

begin_define
define|#
directive|define
name|PIAC_PHY_ACS_ST
value|(1u<<31)
end_define

begin_define
define|#
directive|define
name|PIAC_MDIO_REG_ADDR_OFF
value|25
end_define

begin_define
define|#
directive|define
name|PIAC_MDIO_PHY_ADDR_OFF
value|20
end_define

begin_define
define|#
directive|define
name|PIAC_MDIO_CMD_WRITE
value|(1u<<18)
end_define

begin_define
define|#
directive|define
name|PIAC_MDIO_CMD_READ
value|(2u<<18)
end_define

begin_define
define|#
directive|define
name|PIAC_MDIO_ST
value|(1u<<16)
end_define

begin_define
define|#
directive|define
name|PIAC_MDIO_RW_DATA_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PORTREG
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|)
value|((r) + ((p) * 0x100))
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PCR
parameter_list|(
name|x
parameter_list|)
value|MTKSWITCH_PORTREG(0x2004, (x))
end_define

begin_define
define|#
directive|define
name|PCR_PORT_VLAN_SECURE
value|(3u<<0)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PVC
parameter_list|(
name|x
parameter_list|)
value|MTKSWITCH_PORTREG(0x2010, (x))
end_define

begin_define
define|#
directive|define
name|PVC_VLAN_ATTR_MASK
value|(3u<<6)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PPBV1
parameter_list|(
name|x
parameter_list|)
value|MTKSWITCH_PORTREG(0x2014, (x))
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PPBV2
parameter_list|(
name|x
parameter_list|)
value|MTKSWITCH_PORTREG(0x2018, (x))
end_define

begin_define
define|#
directive|define
name|PPBV_VID
parameter_list|(
name|v
parameter_list|)
value|(((v)<<16) | (v))
end_define

begin_define
define|#
directive|define
name|PPBV_VID_FROM_REG
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfff)
end_define

begin_define
define|#
directive|define
name|PPBV_VID_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PMCR
parameter_list|(
name|x
parameter_list|)
value|MTKSWITCH_PORTREG(0x3000, (x))
end_define

begin_define
define|#
directive|define
name|PMCR_FORCE_LINK
value|(1u<<0)
end_define

begin_define
define|#
directive|define
name|PMCR_FORCE_DPX
value|(1u<<1)
end_define

begin_define
define|#
directive|define
name|PMCR_FORCE_SPD_1000
value|(2u<<2)
end_define

begin_define
define|#
directive|define
name|PMCR_FORCE_TX_FC
value|(1u<<4)
end_define

begin_define
define|#
directive|define
name|PMCR_FORCE_RX_FC
value|(1u<<5)
end_define

begin_define
define|#
directive|define
name|PMCR_BACKPR_EN
value|(1u<<8)
end_define

begin_define
define|#
directive|define
name|PMCR_BKOFF_EN
value|(1u<<9)
end_define

begin_define
define|#
directive|define
name|PMCR_MAC_RX_EN
value|(1u<<13)
end_define

begin_define
define|#
directive|define
name|PMCR_MAC_TX_EN
value|(1u<<14)
end_define

begin_define
define|#
directive|define
name|PMCR_FORCE_MODE
value|(1u<<15)
end_define

begin_define
define|#
directive|define
name|PMCR_RES_1
value|(1u<<16)
end_define

begin_define
define|#
directive|define
name|PMCR_IPG_CFG_RND
value|(1u<<18)
end_define

begin_define
define|#
directive|define
name|PMCR_CFG_DEFAULT
value|(PMCR_BACKPR_EN | PMCR_BKOFF_EN | \ 		    PMCR_MAC_RX_EN | PMCR_MAC_TX_EN | PMCR_IPG_CFG_RND |  \ 		    PMCR_FORCE_RX_FC | PMCR_FORCE_TX_FC | PMCR_RES_1)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PMSR
parameter_list|(
name|x
parameter_list|)
value|MTKSWITCH_PORTREG(0x3008, (x))
end_define

begin_define
define|#
directive|define
name|PMSR_MAC_LINK_STS
value|(1u<<0)
end_define

begin_define
define|#
directive|define
name|PMSR_MAC_DPX_STS
value|(1u<<1)
end_define

begin_define
define|#
directive|define
name|PMSR_MAC_SPD_STS
value|(3u<<2)
end_define

begin_define
define|#
directive|define
name|PMSR_MAC_SPD
parameter_list|(
name|x
parameter_list|)
value|(((x)>>2)& 0x3)
end_define

begin_define
define|#
directive|define
name|PMSR_MAC_SPD_10
value|0
end_define

begin_define
define|#
directive|define
name|PMSR_MAC_SPD_100
value|1
end_define

begin_define
define|#
directive|define
name|PMSR_MAC_SPD_1000
value|2
end_define

begin_define
define|#
directive|define
name|PMSR_TX_FC_STS
value|(1u<<4)
end_define

begin_define
define|#
directive|define
name|PMSR_RX_FC_STS
value|(1u<<5)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_REG_ADDR
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 6)& 0x3ff)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_REG_LO
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 2)& 0xf)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_REG_HI
parameter_list|(
name|r
parameter_list|)
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VAL_LO
parameter_list|(
name|v
parameter_list|)
value|((v)& 0xffff)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VAL_HI
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_GLOBAL_PHY
value|31
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_GLOBAL_REG
value|31
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_LAN_VID
value|0x001
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_WAN_VID
value|0x002
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_INVALID_VID
value|0xfff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_LAN_FID
value|1
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_WAN_FID
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MTKSWITCH_MT7620_H__ */
end_comment

end_unit

