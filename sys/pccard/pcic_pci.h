begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 M. Warner Losh. All rights reserved.  * Copyright (c) 1997 Ted Faber. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Ted Faber.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Share the devid database with NEWCARD */
end_comment

begin_include
include|#
directive|include
file|<dev/pccbb/pccbbdevid.h>
end_include

begin_comment
comment|/* CL-PD683x CardBus defines */
end_comment

begin_define
define|#
directive|define
name|CLPD6833_CFG_MISC_1
value|0x98
end_define

begin_comment
comment|/* Configuration constants */
end_comment

begin_define
define|#
directive|define
name|CLPD6832_BCR_MGMT_IRQ_ENA
value|0x0800
end_define

begin_define
define|#
directive|define
name|CLPD6833_CM1_MGMT_EXCA_ENA
value|0x0001
end_define

begin_comment
comment|/* Set ExCA, Clr PCI */
end_comment

begin_comment
comment|/* End of CL-PD6832 defines */
end_comment

begin_comment
comment|/* Texas Instruments PCI-1130/1131 CardBus Controller */
end_comment

begin_define
define|#
directive|define
name|TI113X_PCI_SYSTEM_CONTROL
value|0x80
end_define

begin_comment
comment|/* System Control */
end_comment

begin_define
define|#
directive|define
name|TI12XX_PCI_MULTIMEDIA_CONTROL
value|0x84
end_define

begin_comment
comment|/* Zoom Video */
end_comment

begin_define
define|#
directive|define
name|TI113X_PCI_RETRY_STATUS
value|0x90
end_define

begin_comment
comment|/* Retry Status */
end_comment

begin_define
define|#
directive|define
name|TI113X_PCI_CARD_CONTROL
value|0x91
end_define

begin_comment
comment|/* Card Control */
end_comment

begin_define
define|#
directive|define
name|TI113X_PCI_DEVICE_CONTROL
value|0x92
end_define

begin_comment
comment|/* Device Control */
end_comment

begin_define
define|#
directive|define
name|TI113X_PCI_BUFFER_CONTROL
value|0x93
end_define

begin_comment
comment|/* Buffer Control */
end_comment

begin_define
define|#
directive|define
name|TI12XX_PCI_DIAGNOSTIC
value|0x93
end_define

begin_comment
comment|/* Diagnostic register */
end_comment

begin_define
define|#
directive|define
name|TI113X_PCI_SOCKET_DMA0
value|0x94
end_define

begin_comment
comment|/* Socket DMA Register 0 */
end_comment

begin_define
define|#
directive|define
name|TI113X_PCI_SOCKET_DMA1
value|0x98
end_define

begin_comment
comment|/* Socket DMA Register 1 */
end_comment

begin_comment
comment|/* Card control register (TI113X_SYSTEM_CONTROL == 0x80) */
end_comment

begin_define
define|#
directive|define
name|TI113X_SYSCNTL_INTRTIE
value|0x20000000u
end_define

begin_define
define|#
directive|define
name|TI113X_SYSCNTL_SMIENB
value|0x00800000u
end_define

begin_define
define|#
directive|define
name|TI113X_SYSCNTL_VCC_PROTECT
value|0x00200000u
end_define

begin_define
define|#
directive|define
name|TI113X_SYSCNTL_CLKRUN_SEL
value|0x00000080u
end_define

begin_define
define|#
directive|define
name|TI113X_SYSCNTL_PWRSAVINGS
value|0x00000040u
end_define

begin_define
define|#
directive|define
name|TI113X_SYSCNTL_KEEP_CLK
value|0x00000002u
end_define

begin_define
define|#
directive|define
name|TI113X_SYSCNTL_CLKRUN_ENA
value|0x00000001u
end_define

begin_comment
comment|/* Card control register (TI113X_CARD_CONTROL == 0x91) */
end_comment

begin_define
define|#
directive|define
name|TI113X_CARDCNTL_RING_ENA
value|0x80u
end_define

begin_define
define|#
directive|define
name|TI113X_CARDCNTL_ZOOM_VIDEO
value|0x40u
end_define

begin_define
define|#
directive|define
name|TI113X_CARDCNTL_PCI_IRQ_ENA
value|0x20u
end_define

begin_define
define|#
directive|define
name|TI113X_CARDCNTL_PCI_IREQ
value|0x10u
end_define

begin_define
define|#
directive|define
name|TI113X_CARDCNTL_PCI_CSC
value|0x08u
end_define

begin_define
define|#
directive|define
name|TI113X_CARDCNTL_MASK
value|(TI113X_CARDCNTL_PCI_IRQ_ENA | TI113X_CARDCNTL_PCI_IREQ | TI113X_CARDCNTL_PCI_CSC)
end_define

begin_define
define|#
directive|define
name|TI113X_FUNC0_VALID
value|TI113X_CARDCNTL_MASK
end_define

begin_define
define|#
directive|define
name|TI113X_FUNC1_VALID
value|(TI113X_CARDCNTL_PCI_IREQ | TI113X_CARDCNTL_PCI_CSC)
end_define

begin_comment
comment|/* Reserved bit				0x04u */
end_comment

begin_define
define|#
directive|define
name|TI113X_CARDCNTL_SPKR_ENA
value|0x02u
end_define

begin_define
define|#
directive|define
name|TI113X_CARDCNTL_INT
value|0x01u
end_define

begin_comment
comment|/* Device control register (TI113X_DEVICE_CONTROL == 0x92) */
end_comment

begin_define
define|#
directive|define
name|TI113X_DEVCNTL_5V_SOCKET
value|0x40u
end_define

begin_define
define|#
directive|define
name|TI113X_DEVCNTL_3V_SOCKET
value|0x20u
end_define

begin_define
define|#
directive|define
name|TI113X_DEVCNTL_INTR_MASK
value|0x06u
end_define

begin_define
define|#
directive|define
name|TI113X_DEVCNTL_INTR_NONE
value|0x00u
end_define

begin_define
define|#
directive|define
name|TI113X_DEVCNTL_INTR_ISA
value|0x02u
end_define

begin_define
define|#
directive|define
name|TI113X_DEVCNTL_INTR_SERIAL
value|0x04u
end_define

begin_comment
comment|/* TI12XX specific code */
end_comment

begin_define
define|#
directive|define
name|TI12XX_DEVCNTL_INTR_ALLSERIAL
value|0x06u
end_define

begin_comment
comment|/* Diagnostic register (misnamed) TI12XX_PCI_DIAGNOSTIC == 0x93 */
end_comment

begin_define
define|#
directive|define
name|TI12XX_DIAG_CSC_INTR
value|0x20
end_define

begin_comment
comment|/* see datasheet */
end_comment

begin_comment
comment|/* Texas Instruments PCI-1130/1131 CardBus Controller */
end_comment

begin_define
define|#
directive|define
name|TI113X_ExCA_IO_OFFSET0
value|0x36
end_define

begin_comment
comment|/* Offset of I/O window */
end_comment

begin_define
define|#
directive|define
name|TI113X_ExCA_IO_OFFSET1
value|0x38
end_define

begin_comment
comment|/* Offset of I/O window */
end_comment

begin_define
define|#
directive|define
name|TI113X_ExCA_MEM_WINDOW_PAGE
value|0x3C
end_define

begin_comment
comment|/* Memory Window Page */
end_comment

begin_comment
comment|/*  * Ricoh R5C47[5678] parts have these registers.  Maybe the 46x also use  * them, but I can't find out for sure without datasheets...  */
end_comment

begin_define
define|#
directive|define
name|R5C47X_MISC_CONTROL_REGISTER_2
value|0xa0
end_define

begin_define
define|#
directive|define
name|R5C47X_MCR2_CSC_TO_INTX_DISABLE
value|0x0010
end_define

begin_comment
comment|/* Bit 7 */
end_comment

begin_comment
comment|/*  * ToPIC specific stuff.  */
end_comment

begin_define
define|#
directive|define
name|TOPIC_INTERRUPT_CONTROL
value|0xa1
end_define

begin_define
define|#
directive|define
name|TOPIC_ICR_INTA
value|0x1
end_define

begin_comment
comment|/* sanpei */
end_comment

begin_comment
comment|/* For Bridge Control register (CB_PCI_BRIDGE_CTRL) */
end_comment

begin_define
define|#
directive|define
name|CB_BCR_MASTER_ABORT
value|0x0020
end_define

begin_define
define|#
directive|define
name|CB_BCR_CB_RESET
value|0x0040
end_define

begin_define
define|#
directive|define
name|CB_BCR_INT_EXCA
value|0x0080
end_define

begin_define
define|#
directive|define
name|CB_BCR_WRITE_POST_EN
value|0x0400
end_define

begin_comment
comment|/* additional bits for Ricoh's cardbus products */
end_comment

begin_define
define|#
directive|define
name|CB_BCR_RL_3E0_EN
value|0x0800
end_define

begin_define
define|#
directive|define
name|CB_BCR_RL_3E2_EN
value|0x1000
end_define

begin_comment
comment|/* PCI Configuration Registers (common) */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_VENDOR_ID
value|0x00
end_define

begin_comment
comment|/* vendor ID */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_DEVICE_ID
value|0x02
end_define

begin_comment
comment|/* device ID */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_COMMAND
value|0x04
end_define

begin_comment
comment|/* PCI command */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_STATUS
value|0x06
end_define

begin_comment
comment|/* PCI status */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_REVISION_ID
value|0x08
end_define

begin_comment
comment|/* PCI revision ID */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_CLASS
value|0x09
end_define

begin_comment
comment|/* PCI class code */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_CACHE_LINE_SIZE
value|0x0c
end_define

begin_comment
comment|/* Cache line size */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_LATENCY
value|0x0d
end_define

begin_comment
comment|/* PCI latency timer */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_HEADER_TYPE
value|0x0e
end_define

begin_comment
comment|/* PCI header type */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_BIST
value|0x0f
end_define

begin_comment
comment|/* Built-in self test */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_SOCKET_BASE
value|0x10
end_define

begin_comment
comment|/* Socket/ExCA base address reg. */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_CB_STATUS
value|0x16
end_define

begin_comment
comment|/* CardBus Status */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_PCI_BUS_NUM
value|0x18
end_define

begin_comment
comment|/* PCI bus number */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_CB_BUS_NUM
value|0x19
end_define

begin_comment
comment|/* CardBus bus number */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_CB_SUB_BUS_NUM
value|0x1A
end_define

begin_comment
comment|/* Subordinate CardBus bus number */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_CB_LATENCY
value|0x1A
end_define

begin_comment
comment|/* CardBus latency timer */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_MEMBASE0
value|0x1C
end_define

begin_comment
comment|/* Memory base register 0 */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_MEMLIMIT0
value|0x20
end_define

begin_comment
comment|/* Memory limit register 0 */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_MEMBASE1
value|0x24
end_define

begin_comment
comment|/* Memory base register 1 */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_MEMLIMIT1
value|0x28
end_define

begin_comment
comment|/* Memory limit register 1 */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_IOBASE0
value|0x2C
end_define

begin_comment
comment|/* I/O base register 0 */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_IOLIMIT0
value|0x30
end_define

begin_comment
comment|/* I/O limit register 0 */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_IOBASE1
value|0x34
end_define

begin_comment
comment|/* I/O base register 1 */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_IOLIMIT1
value|0x38
end_define

begin_comment
comment|/* I/O limit register 1 */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_INT_LINE
value|0x3C
end_define

begin_comment
comment|/* Interrupt Line */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_INT_PIN
value|0x3D
end_define

begin_comment
comment|/* Interrupt Pin */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_BRIDGE_CTRL
value|0x3E
end_define

begin_comment
comment|/* Bridge Control */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_SUBSYS_VENDOR_ID
value|0x40
end_define

begin_comment
comment|/* Subsystem Vendor ID */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_SUBSYS_ID
value|0x42
end_define

begin_comment
comment|/* Subsystem ID */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_LEGACY16_IOADDR
value|0x44
end_define

begin_comment
comment|/* Legacy 16bit I/O address */
end_comment

begin_define
define|#
directive|define
name|CB_PCI_LEGACY16_IOENABLE
value|0x01
end_define

begin_comment
comment|/* Enable Legacy 16bit I/O address */
end_comment

begin_comment
comment|/* PCI Memory register offsets for YENTA devices */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_EVENT
value|0x00
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_STATE
value|0x08
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_FORCE
value|0x0c
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_POWER
value|0x10
end_define

begin_define
define|#
directive|define
name|CB_EXCA_OFFSET
value|0x800
end_define

begin_comment
comment|/* Offset for ExCA registers */
end_comment

begin_define
define|#
directive|define
name|CB_SE_CD
value|0x6
end_define

begin_comment
comment|/* Socket Event Card detect */
end_comment

begin_define
define|#
directive|define
name|CB_SE_POWER
value|0x8
end_define

begin_define
define|#
directive|define
name|CB_SM_CD
value|0x6
end_define

begin_comment
comment|/* Socket MASK Card detect */
end_comment

begin_define
define|#
directive|define
name|CB_SM_POWER
value|0x8
end_define

begin_define
define|#
directive|define
name|CB_SS_CARDSTS
value|0x00000001
end_define

begin_comment
comment|/* Card Status Change */
end_comment

begin_define
define|#
directive|define
name|CB_SS_CD1
value|0x00000002
end_define

begin_comment
comment|/* Card Detect 1 */
end_comment

begin_define
define|#
directive|define
name|CB_SS_CD2
value|0x00000004
end_define

begin_comment
comment|/* Card Detect 2 */
end_comment

begin_define
define|#
directive|define
name|CB_SS_CD
value|0x00000006
end_define

begin_comment
comment|/* Card Detect all */
end_comment

begin_define
define|#
directive|define
name|CB_SS_PWRCYCLE
value|0x00000008
end_define

begin_comment
comment|/* Power Cycle */
end_comment

begin_define
define|#
directive|define
name|CB_SS_16BIT
value|0x00000010
end_define

begin_comment
comment|/* 16-bit Card */
end_comment

begin_define
define|#
directive|define
name|CB_SS_CB
value|0x00000020
end_define

begin_comment
comment|/* Cardbus Card */
end_comment

begin_define
define|#
directive|define
name|CB_SS_IREQ
value|0x00000040
end_define

begin_comment
comment|/* Ready */
end_comment

begin_define
define|#
directive|define
name|CB_SS_NOTCARD
value|0x00000080
end_define

begin_comment
comment|/* Unrecognized Card */
end_comment

begin_define
define|#
directive|define
name|CB_SS_DATALOST
value|0x00000100
end_define

begin_comment
comment|/* Data Lost */
end_comment

begin_define
define|#
directive|define
name|CB_SS_BADVCC
value|0x00000200
end_define

begin_comment
comment|/* Bad VccRequest */
end_comment

begin_define
define|#
directive|define
name|CB_SS_5VCARD
value|0x00000400
end_define

begin_comment
comment|/* 5 V Card */
end_comment

begin_define
define|#
directive|define
name|CB_SS_3VCARD
value|0x00000800
end_define

begin_comment
comment|/* 3.3 V Card */
end_comment

begin_define
define|#
directive|define
name|CB_SS_XVCARD
value|0x00001000
end_define

begin_comment
comment|/* X.X V Card */
end_comment

begin_define
define|#
directive|define
name|CB_SS_YVCARD
value|0x00002000
end_define

begin_comment
comment|/* Y.Y V Card */
end_comment

begin_define
define|#
directive|define
name|CB_SS_5VSOCK
value|0x10000000
end_define

begin_comment
comment|/* 5 V Socket */
end_comment

begin_define
define|#
directive|define
name|CB_SS_3VSOCK
value|0x20000000
end_define

begin_comment
comment|/* 3.3 V Socket */
end_comment

begin_define
define|#
directive|define
name|CB_SS_XVSOCK
value|0x40000000
end_define

begin_comment
comment|/* X.X V Socket */
end_comment

begin_define
define|#
directive|define
name|CB_SS_YVSOCK
value|0x80000000
end_define

begin_comment
comment|/* Y.Y V Socket */
end_comment

begin_define
define|#
directive|define
name|CB_SP_CLKSTOP
value|0x80
end_define

begin_comment
comment|/* Cardbus clock stop protocol */
end_comment

begin_define
define|#
directive|define
name|CB_SP_VCC_0V
value|0x00
end_define

begin_define
define|#
directive|define
name|CB_SP_VCC_5V
value|0x20
end_define

begin_define
define|#
directive|define
name|CB_SP_VCC_3V
value|0x30
end_define

begin_define
define|#
directive|define
name|CB_SP_VCC_XV
value|0x40
end_define

begin_define
define|#
directive|define
name|CB_SP_VCC_YV
value|0x50
end_define

begin_define
define|#
directive|define
name|CB_SP_VPP_0V
value|0x00
end_define

begin_define
define|#
directive|define
name|CB_SP_VPP_12V
value|0x01
end_define

begin_define
define|#
directive|define
name|CB_SP_VPP_5V
value|0x02
end_define

begin_define
define|#
directive|define
name|CB_SP_VPP_3V
value|0x03
end_define

begin_define
define|#
directive|define
name|CB_SP_VPP_XV
value|0x04
end_define

begin_define
define|#
directive|define
name|CB_SP_VPP_YV
value|0x05
end_define

end_unit

