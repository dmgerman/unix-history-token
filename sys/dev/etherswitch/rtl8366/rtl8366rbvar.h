begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Stefan Bethke.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ETHERSWITCH_RTL8366RBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ETHERSWITCH_RTL8366RBVAR_H_
end_define

begin_define
define|#
directive|define
name|RTL8366RB_IIC_ADDR
value|0xa8
end_define

begin_define
define|#
directive|define
name|RTL_IICBUS_TIMEOUT
value|100
end_define

begin_comment
comment|/* us */
end_comment

begin_define
define|#
directive|define
name|RTL_IICBUS_READ
value|1
end_define

begin_define
define|#
directive|define
name|RTL_IICBUS_WRITE
value|0
end_define

begin_comment
comment|/* number of times to try and select the chip on the I2C bus */
end_comment

begin_define
define|#
directive|define
name|RTL_IICBUS_RETRIES
value|3
end_define

begin_define
define|#
directive|define
name|RTL_IICBUS_RETRY_SLEEP
value|(hz/1000)
end_define

begin_comment
comment|/* Register definitions */
end_comment

begin_comment
comment|/* Switch Global Configuration */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_SGCR
value|0x0000
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_EN_BC_STORM_CTRL
value|0x0001
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_MAX_LENGTH_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_MAX_LENGTH_1522
value|0x0000
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_MAX_LENGTH_1536
value|0x0010
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_MAX_LENGTH_1552
value|0x0020
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_MAX_LENGTH_9216
value|0x0030
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_EN_VLAN
value|0x2000
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_EN_VLAN_4KTB
value|0x4000
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SGCR_EN_QOS
value|0x8000
end_define

begin_comment
comment|/* Port Enable Control: DISABLE_PORT[5:0] */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_PECR
value|0x0001
end_define

begin_comment
comment|/* Switch Security Control 0: DIS_LEARN[5:0] */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_SSCR0
value|0x0002
end_define

begin_comment
comment|/* Switch Security Control 1: DIS_AGE[5:0] */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_SSCR1
value|0x0003
end_define

begin_comment
comment|/* Switch Security Control 2 */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_SSCR2
value|0x0004
end_define

begin_define
define|#
directive|define
name|RTL8366RB_SSCR2_DROP_UNKNOWN_DA
value|0x0001
end_define

begin_comment
comment|/* Port Link Status: two ports per register */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_BASE
value|0x0014
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_SPEED_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_SPEED_10
value|0x00
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_SPEED_100
value|0x01
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_SPEED_1000
value|0x02
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_FULLDUPLEX
value|0x04
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_LINK
value|0x10
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_TXPAUSE
value|0x20
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_RXPAUSE
value|0x40
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PLSR_NO_AUTO
value|0x80
end_define

begin_comment
comment|/* VLAN Member Configuration, 3 registers per VLAN */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_BASE
value|0x0020
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_MULT
value|3
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_DOT1Q_REG
value|0
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_DOT1Q_VID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_DOT1Q_VID_MASK
value|0x0fff
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_DOT1Q_PCP_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_DOT1Q_PCP_MASK
value|0x7000
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_MU_REG
value|1
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_MU_MEMBER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_MU_MEMBER_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_MU_UNTAG_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_MU_UNTAG_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_FID_REG
value|2
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_FID_FID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_FID_FID_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|RTL8366RB_VMCR
parameter_list|(
name|_reg
parameter_list|,
name|_vlan
parameter_list|)
define|\
value|(RTL8366RB_VMCR_BASE + _reg + _vlan * RTL8366RB_VMCR_MULT)
end_define

begin_comment
comment|/* VLAN Identifier */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_VID
parameter_list|(
name|_r
parameter_list|)
define|\
value|(_r[RTL8366RB_VMCR_DOT1Q_REG]& RTL8366RB_VMCR_DOT1Q_VID_MASK)
end_define

begin_comment
comment|/* Priority Code Point */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_PCP
parameter_list|(
name|_r
parameter_list|)
define|\
value|((_r[RTL8366RB_VMCR_DOT1Q_REG]& RTL8366RB_VMCR_DOT1Q_PCP_MASK) \>> RTL8366RB_VMCR_DOT1Q_PCP_SHIFT)
end_define

begin_comment
comment|/* Member ports */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_MEMBER
parameter_list|(
name|_r
parameter_list|)
define|\
value|(_r[RTL8366RB_VMCR_MU_REG]& RTL8366RB_VMCR_MU_MEMBER_MASK)
end_define

begin_comment
comment|/* Untagged ports */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_UNTAG
parameter_list|(
name|_r
parameter_list|)
define|\
value|((_r[RTL8366RB_VMCR_MU_REG]& RTL8366RB_VMCR_MU_UNTAG_MASK) \>> RTL8366RB_VMCR_MU_UNTAG_SHIFT)
end_define

begin_comment
comment|/* Forwarding ID */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_VMCR_FID
parameter_list|(
name|_r
parameter_list|)
define|\
value|(_r[RTL8366RB_VMCR_FID_REG]& RTL8366RB_VMCR_FID_FID_MASK)
end_define

begin_comment
comment|/*  * Port VLAN Control, 4 ports per register  * Determines the VID for untagged ingress frames through  * index into VMC.  */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_PVCR_BASE
value|0x0063
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PVCR_PORT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PVCR_PORT_PERREG
value|(16 / RTL8366RB_PVCR_PORT_SHIFT)
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PVCR_PORT_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PVCR_REG
parameter_list|(
name|_port
parameter_list|)
define|\
value|(RTL8366RB_PVCR_BASE + _port / (RTL8366RB_PVCR_PORT_PERREG))
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PVCR_VAL
parameter_list|(
name|_port
parameter_list|,
name|_pvlan
parameter_list|)
define|\
value|((_pvlan& RTL8366RB_PVCR_PORT_MASK)<< \ 	((_port % RTL8366RB_PVCR_PORT_PERREG) * RTL8366RB_PVCR_PORT_SHIFT))
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PVCR_GET
parameter_list|(
name|_port
parameter_list|,
name|_val
parameter_list|)
define|\
value|(((_val)>> ((_port % RTL8366RB_PVCR_PORT_PERREG) * RTL8366RB_PVCR_PORT_SHIFT))& RTL8366RB_PVCR_PORT_MASK)
end_define

begin_comment
comment|/* Reset Control */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_RCR
value|0x0100
end_define

begin_define
define|#
directive|define
name|RTL8366RB_RCR_HARD_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|RTL8366RB_RCR_SOFT_RESET
value|0x0002
end_define

begin_comment
comment|/* Chip Version Control: CHIP_VER[3:0] */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_CVCR
value|0x050A
end_define

begin_comment
comment|/* Chip Identifier */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_CIR
value|0x0509
end_define

begin_define
define|#
directive|define
name|RTL8366RB_CIR_ID8366RB
value|0x5937
end_define

begin_comment
comment|/* VLAN Ingress Control 2: [5:0] */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_VIC2R
value|0x037f
end_define

begin_comment
comment|/* MIB registers */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_MCNT_BASE
value|0x1000
end_define

begin_define
define|#
directive|define
name|RTL8366RB_MCTLR
value|0x13f0
end_define

begin_define
define|#
directive|define
name|RTL8366RB_MCTLR_BUSY
value|0x0001
end_define

begin_define
define|#
directive|define
name|RTL8366RB_MCTLR_RESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|RTL8366RB_MCTLR_RESET_PORT_MASK
value|0x00fc
end_define

begin_define
define|#
directive|define
name|RTL8366RB_MCTLR_RESET_ALL
value|0x0800
end_define

begin_define
define|#
directive|define
name|RTL8366RB_MCNT
parameter_list|(
name|_port
parameter_list|,
name|_r
parameter_list|)
define|\
value|(RTL8366RB_MCNT_BASE + 0x50 * (_port) + (_r))
end_define

begin_define
define|#
directive|define
name|RTL8366RB_MCTLR_RESET_PORT
parameter_list|(
name|_p
parameter_list|)
define|\
value|(1<< ((_p) + 2))
end_define

begin_comment
comment|/* PHY Access Control */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_PACR
value|0x8000
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PACR_WRITE
value|0x0000
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PACR_READ
value|0x0001
end_define

begin_comment
comment|/* PHY Access Data */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_PADR
value|0x8002
end_define

begin_define
define|#
directive|define
name|RTL8366RB_PHYREG
parameter_list|(
name|phy
parameter_list|,
name|page
parameter_list|,
name|reg
parameter_list|)
define|\
value|(RTL8366RB_PACR | (1<< (((phy)& 0x1f) + 9)) | (((page)& 0xf)<< 5) | ((reg)& 0x1f))
end_define

begin_comment
comment|/* general characteristics of the chip */
end_comment

begin_define
define|#
directive|define
name|RTL8366RB_CPU_PORT
value|5
end_define

begin_define
define|#
directive|define
name|RTL8366RB_NUM_PORTS
value|6
end_define

begin_define
define|#
directive|define
name|RTL8366RB_NUM_PHYS
value|(RTL8366RB_NUM_PORTS-1)
end_define

begin_define
define|#
directive|define
name|RTL8366RB_NUM_VLANS
value|16
end_define

begin_define
define|#
directive|define
name|RTL8366RB_NUM_PHY_REG
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

