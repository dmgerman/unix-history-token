begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__83265_H__
end_ifndef

begin_define
define|#
directive|define
name|__83265_H__
end_define

begin_comment
comment|/***********************************************************************  * 82365.h -- information necessary for direct manipulation of PCMCIA  * cards and controllers  *  * Support is included for Intel 82365SL PCIC controllers and clones  * thereof.  *  * originally by Barry Jaspan; hacked over by Keith Moore  *  * $FreeBSD$  ***********************************************************************/
end_comment

begin_comment
comment|/*  * PCIC Registers  *     Each register is given a name, and most of the bits are named too.  *     I should really name them all.  *  *     Finally, since the banks can be addressed with a regular syntax,  *     some macros are provided for that purpose.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_BASE
value|0x03e0
end_define

begin_comment
comment|/* base adddress of pcic register set */
end_comment

begin_comment
comment|/* First, all the registers */
end_comment

begin_define
define|#
directive|define
name|PCIC_ID_REV
value|0x00
end_define

begin_comment
comment|/* Identification and Revision */
end_comment

begin_define
define|#
directive|define
name|PCIC_STATUS
value|0x01
end_define

begin_comment
comment|/* Interface Status */
end_comment

begin_define
define|#
directive|define
name|PCIC_POWER
value|0x02
end_define

begin_comment
comment|/* Power and RESETDRV control */
end_comment

begin_define
define|#
directive|define
name|PCIC_INT_GEN
value|0x03
end_define

begin_comment
comment|/* Interrupt and General Control */
end_comment

begin_define
define|#
directive|define
name|PCIC_STAT_CHG
value|0x04
end_define

begin_comment
comment|/* Card Status Change */
end_comment

begin_define
define|#
directive|define
name|PCIC_STAT_INT
value|0x05
end_define

begin_comment
comment|/* Card Status Change Interrupt Config */
end_comment

begin_define
define|#
directive|define
name|PCIC_ADDRWINE
value|0x06
end_define

begin_comment
comment|/* Address Window Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_IOCTL
value|0x07
end_define

begin_comment
comment|/* I/O Control */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_STL
value|0x08
end_define

begin_comment
comment|/* I/O Address 0 Start Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_STH
value|0x09
end_define

begin_comment
comment|/* I/O Address 0 Start High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_SPL
value|0x0a
end_define

begin_comment
comment|/* I/O Address 0 Stop Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_SPH
value|0x0b
end_define

begin_comment
comment|/* I/O Address 0 Stop High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_STL
value|0x0c
end_define

begin_comment
comment|/* I/O Address 1 Start Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_STH
value|0x0d
end_define

begin_comment
comment|/* I/O Address 1 Start High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_SPL
value|0x0e
end_define

begin_comment
comment|/* I/O Address 1 Stop Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_SPH
value|0x0f
end_define

begin_comment
comment|/* I/O Address 1 Stop High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM0_STL
value|0x10
end_define

begin_comment
comment|/* System Memory Address 0 Mapping Start Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM0_STH
value|0x11
end_define

begin_comment
comment|/* System Memory Address 0 Mapping Start High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM0_SPL
value|0x12
end_define

begin_comment
comment|/* System Memory Address 0 Mapping Stop Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM0_SPH
value|0x13
end_define

begin_comment
comment|/* System Memory Address 0 Mapping Stop High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM0_L
value|0x14
end_define

begin_comment
comment|/* Card Memory Offset Address 0 Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM0_H
value|0x15
end_define

begin_comment
comment|/* Card Memory Offset Address 0 High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CDGC
value|0x16
end_define

begin_comment
comment|/* Card Detect and General Control */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES17
value|0x17
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM1_STL
value|0x18
end_define

begin_comment
comment|/* System Memory Address 1 Mapping Start Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM1_STH
value|0x19
end_define

begin_comment
comment|/* System Memory Address 1 Mapping Start High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM1_SPL
value|0x1a
end_define

begin_comment
comment|/* System Memory Address 1 Mapping Stop Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM1_SPH
value|0x1b
end_define

begin_comment
comment|/* System Memory Address 1 Mapping Stop High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM1_L
value|0x1c
end_define

begin_comment
comment|/* Card Memory Offset Address 1 Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM1_H
value|0x1d
end_define

begin_comment
comment|/* Card Memory Offset Address 1 High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_GLO_CTRL
value|0x1e
end_define

begin_comment
comment|/* Global Control Register */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES1F
value|0x1f
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM2_STL
value|0x20
end_define

begin_comment
comment|/* System Memory Address 2 Mapping Start Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM2_STH
value|0x21
end_define

begin_comment
comment|/* System Memory Address 2 Mapping Start High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM2_SPL
value|0x22
end_define

begin_comment
comment|/* System Memory Address 2 Mapping Stop Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM2_SPH
value|0x23
end_define

begin_comment
comment|/* System Memory Address 2 Mapping Stop High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM2_L
value|0x24
end_define

begin_comment
comment|/* Card Memory Offset Address 2 Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM2_H
value|0x25
end_define

begin_comment
comment|/* Card Memory Offset Address 2 High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES26
value|0x26
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES27
value|0x27
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM3_STL
value|0x28
end_define

begin_comment
comment|/* System Memory Address 3 Mapping Start Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM3_STH
value|0x29
end_define

begin_comment
comment|/* System Memory Address 3 Mapping Start High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM3_SPL
value|0x2a
end_define

begin_comment
comment|/* System Memory Address 3 Mapping Stop Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM3_SPH
value|0x2b
end_define

begin_comment
comment|/* System Memory Address 3 Mapping Stop High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM3_L
value|0x2c
end_define

begin_comment
comment|/* Card Memory Offset Address 3 Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM3_H
value|0x2d
end_define

begin_comment
comment|/* Card Memory Offset Address 3 High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES2E
value|0x2e
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES2F
value|0x2f
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM4_STL
value|0x30
end_define

begin_comment
comment|/* System Memory Address 4 Mapping Start Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM4_STH
value|0x31
end_define

begin_comment
comment|/* System Memory Address 4 Mapping Start High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM4_SPL
value|0x32
end_define

begin_comment
comment|/* System Memory Address 4 Mapping Stop Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM4_SPH
value|0x33
end_define

begin_comment
comment|/* System Memory Address 4 Mapping Stop High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM4_L
value|0x34
end_define

begin_comment
comment|/* Card Memory Offset Address 4 Low Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_CM4_H
value|0x35
end_define

begin_comment
comment|/* Card Memory Offset Address 4 High Byte */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES36
value|0x36
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES37
value|0x37
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES38
value|0x38
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES39
value|0x39
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES3A
value|0x3a
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES3B
value|0x3b
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES3C
value|0x3c
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES3D
value|0x3d
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES3E
value|0x3e
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PCIC_RES3F
value|0x3f
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/* Now register bits, ordered by reg # */
end_comment

begin_comment
comment|/* For Identification and Revision (PCIC_ID_REV) */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTEL0
value|0x82
end_define

begin_comment
comment|/* Intel 82365SL Rev. 0; Both Memory and I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTEL1
value|0x83
end_define

begin_comment
comment|/* Intel 82365SL Rev. 1; Both Memory and I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_IBM1
value|0x88
end_define

begin_comment
comment|/* IBM PCIC clone; Both Memory and I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_IBM2
value|0x89
end_define

begin_comment
comment|/* IBM PCIC clone; Both Memory and I/O */
end_comment

begin_comment
comment|/* For Interface Status register (PCIC_STATUS) */
end_comment

begin_define
define|#
directive|define
name|PCIC_VPPV
value|0x80
end_define

begin_comment
comment|/* Vpp_valid */
end_comment

begin_define
define|#
directive|define
name|PCIC_POW
value|0x40
end_define

begin_comment
comment|/* PC Card power active */
end_comment

begin_define
define|#
directive|define
name|PCIC_READY
value|0x20
end_define

begin_comment
comment|/* Ready/~Busy */
end_comment

begin_define
define|#
directive|define
name|PCIC_MWP
value|0x10
end_define

begin_comment
comment|/* Memory Write Protect */
end_comment

begin_define
define|#
directive|define
name|PCIC_CD
value|0x0C
end_define

begin_comment
comment|/* Both card detect bits */
end_comment

begin_define
define|#
directive|define
name|PCIC_BVD
value|0x03
end_define

begin_comment
comment|/* Both Battery Voltage Detect bits */
end_comment

begin_comment
comment|/* For the Power and RESETDRV register (PCIC_POWER) */
end_comment

begin_define
define|#
directive|define
name|PCIC_OUTENA
value|0x80
end_define

begin_comment
comment|/* Output Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_DISRST
value|0x40
end_define

begin_comment
comment|/* Disable RESETDRV */
end_comment

begin_define
define|#
directive|define
name|PCIC_APSENA
value|0x20
end_define

begin_comment
comment|/* Auto Pwer Switch Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_PCPWRE
value|0x10
end_define

begin_comment
comment|/* PC Card Power Enable */
end_comment

begin_comment
comment|/* For the Interrupt and General Control register (PCIC_INT_GEN) */
end_comment

begin_define
define|#
directive|define
name|PCIC_CARDTYPE
value|0x20
end_define

begin_comment
comment|/* Card Type 0 = memory, 1 = I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_IOCARD
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_MEMCARD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_CARDRESET
value|0x40
end_define

begin_comment
comment|/* Card reset 0 = Reset, 1 = Normal */
end_comment

begin_comment
comment|/* For the Card Status Change register (PCIC_STAT_CHG) */
end_comment

begin_define
define|#
directive|define
name|PCIC_CDTCH
value|0x08
end_define

begin_comment
comment|/* Card Detect Change */
end_comment

begin_define
define|#
directive|define
name|PCIC_RDYCH
value|0x04
end_define

begin_comment
comment|/* Ready Change */
end_comment

begin_define
define|#
directive|define
name|PCIC_BATWRN
value|0x02
end_define

begin_comment
comment|/* Battery Warning */
end_comment

begin_define
define|#
directive|define
name|PCIC_BATDED
value|0x01
end_define

begin_comment
comment|/* Battery Dead */
end_comment

begin_comment
comment|/* For the Address Window Enable Register (PCIC_ADDRWINE) */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM0_EN
value|0x01
end_define

begin_comment
comment|/* Memory Window 0 Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM1_EN
value|0x02
end_define

begin_comment
comment|/* Memory Window 1 Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM2_EN
value|0x04
end_define

begin_comment
comment|/* Memory Window 2 Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM3_EN
value|0x08
end_define

begin_comment
comment|/* Memory Window 3 Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM4_EN
value|0x10
end_define

begin_comment
comment|/* Memory Window 4 Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_MEMCS16
value|0x20
end_define

begin_comment
comment|/* ~MEMCS16 Decode A23-A12 */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_EN
value|0x40
end_define

begin_comment
comment|/* I/O Window 0 Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_EN
value|0x80
end_define

begin_comment
comment|/* I/O Window 1 Enable */
end_comment

begin_comment
comment|/* For the I/O Control Register (PCIC_IOCTL) */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_16BIT
value|0x01
end_define

begin_comment
comment|/* I/O to this segment is 16 bit */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_CS16
value|0x02
end_define

begin_comment
comment|/* I/O cs16 source is the card */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_0WS
value|0x04
end_define

begin_comment
comment|/* zero wait states added on 8 bit cycles */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_WS
value|0x08
end_define

begin_comment
comment|/* Wait states added for 16 bit cycles */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_16BIT
value|0x10
end_define

begin_comment
comment|/* I/O to this segment is 16 bit */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_CS16
value|0x20
end_define

begin_comment
comment|/* I/O cs16 source is the card */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_0WS
value|0x04
end_define

begin_comment
comment|/* zero wait states added on 8 bit cycles */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_WS
value|0x80
end_define

begin_comment
comment|/* Wait states added for 16 bit cycles */
end_comment

begin_comment
comment|/* For the various I/O and Memory windows */
end_comment

begin_define
define|#
directive|define
name|PCIC_ADDR_LOW
value|0
end_define

begin_define
define|#
directive|define
name|PCIC_ADDR_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|PCIC_START
value|0x00
end_define

begin_comment
comment|/* Start of mapping region */
end_comment

begin_define
define|#
directive|define
name|PCIC_END
value|0x02
end_define

begin_comment
comment|/* End of mapping region */
end_comment

begin_define
define|#
directive|define
name|PCIC_MOFF
value|0x04
end_define

begin_comment
comment|/* Card Memory Mapping region offset */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0
value|0x08
end_define

begin_comment
comment|/* I/O Address 0 */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1
value|0x0c
end_define

begin_comment
comment|/* I/O Address 1 */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM0
value|0x10
end_define

begin_comment
comment|/* System Memory Address 0 Mapping */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM1
value|0x18
end_define

begin_comment
comment|/* System Memory Address 1 Mapping */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM2
value|0x20
end_define

begin_comment
comment|/* System Memory Address 2 Mapping */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM3
value|0x28
end_define

begin_comment
comment|/* System Memory Address 3 Mapping */
end_comment

begin_define
define|#
directive|define
name|PCIC_SM4
value|0x30
end_define

begin_comment
comment|/* System Memory Address 4 Mapping */
end_comment

begin_comment
comment|/* For System Memory Window start registers    (PCIC_SMx|PCIC_START|PCIC_ADDR_HIGH) */
end_comment

begin_define
define|#
directive|define
name|PCIC_ZEROWS
value|0x40
end_define

begin_comment
comment|/* Zero wait states */
end_comment

begin_define
define|#
directive|define
name|PCIC_DATA16
value|0x80
end_define

begin_comment
comment|/* Data width is 16 bits */
end_comment

begin_comment
comment|/* For System Memory Window stop registers    (PCIC_SMx|PCIC_END|PCIC_ADDR_HIGH) */
end_comment

begin_define
define|#
directive|define
name|PCIC_MW0
value|0x40
end_define

begin_comment
comment|/* Wait state bit 0 */
end_comment

begin_define
define|#
directive|define
name|PCIC_MW1
value|0x80
end_define

begin_comment
comment|/* Wait state bit 1 */
end_comment

begin_comment
comment|/* For System Memory Window offset registers    (PCIC_SMx|PCIC_MOFF|PCIC_ADDR_HIGH) */
end_comment

begin_define
define|#
directive|define
name|PCIC_REG
value|0x40
end_define

begin_comment
comment|/* Attribute/Common select (why called Reg?) */
end_comment

begin_define
define|#
directive|define
name|PCIC_WP
value|0x80
end_define

begin_comment
comment|/* Write-protect this window */
end_comment

begin_comment
comment|/* For Card Detect and General Control register (PCIC_CDGC) */
end_comment

begin_define
define|#
directive|define
name|PCIC_16_DL_INH
value|0x01
end_define

begin_comment
comment|/* 16-bit memory delay inhibit */
end_comment

begin_define
define|#
directive|define
name|PCIC_CNFG_RST_EN
value|0x02
end_define

begin_comment
comment|/* configuration reset enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_GPI_EN
value|0x04
end_define

begin_comment
comment|/* GPI Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_GPI_TRANS
value|0x08
end_define

begin_comment
comment|/* GPI Transition Control */
end_comment

begin_define
define|#
directive|define
name|PCIC_CDRES_EN
value|0x10
end_define

begin_comment
comment|/* card detect resume enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_SW_CD_INT
value|0x20
end_define

begin_comment
comment|/* s/w card detect interrupt */
end_comment

begin_comment
comment|/* For Global Control register (PCIC_GLO_CTRL) */
end_comment

begin_define
define|#
directive|define
name|PCIC_PWR_DOWN
value|0x01
end_define

begin_comment
comment|/* power down */
end_comment

begin_define
define|#
directive|define
name|PCIC_LVL_MODE
value|0x02
end_define

begin_comment
comment|/* level mode interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_WB_CSCINT
value|0x04
end_define

begin_comment
comment|/* explicit write-back csc intr */
end_comment

begin_define
define|#
directive|define
name|PCIC_IRQ14_PULSE
value|0x08
end_define

begin_comment
comment|/* irq 14 pulse mode enable */
end_comment

begin_comment
comment|/* DON'T ADD ANYTHING AFTER THIS #endif */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __83265_H__ */
end_comment

end_unit

