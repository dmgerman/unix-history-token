begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Ted Faber  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Ted Faber.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* PCI/CardBus Device IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6729
value|0x67291217ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6730
value|0x673A1217ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_CLPD6729
value|0x11001013ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_CLPD6832
value|0x11101013ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1130
value|0xac12104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1131
value|0xac15104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1220
value|0xac17104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1221
value|0xac19104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1250
value|0xac16104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1251
value|0xac1d104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1251B
value|0xac1f104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1225
value|0xac1c104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1410
value|0xac50104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1420
value|0xac51104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1450
value|0xac1b104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1451
value|0xac52104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_TOSHIBA_TOPIC95
value|0x060a1179ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_TOSHIBA_TOPIC97
value|0x060f1179ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C465
value|0x04651180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C475
value|0x04751180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C476
value|0x04761180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C478
value|0x04781180ul
end_define

begin_comment
comment|/* CL-PD6832 CardBus defines */
end_comment

begin_define
define|#
directive|define
name|CLPD6832_IO_BASE0
value|0x002c
end_define

begin_define
define|#
directive|define
name|CLPD6832_IO_LIMIT0
value|0x0030
end_define

begin_define
define|#
directive|define
name|CLPD6832_IO_BASE1
value|0x0034
end_define

begin_define
define|#
directive|define
name|CLPD6832_IO_LIMIT1
value|0x0038
end_define

begin_define
define|#
directive|define
name|CLPD6832_BRIDGE_CONTROL
value|0x003c
end_define

begin_define
define|#
directive|define
name|CLPD6832_LEGACY_16BIT_IOADDR
value|0x0044
end_define

begin_define
define|#
directive|define
name|CLPD6832_SOCKET
value|0x004c
end_define

begin_comment
comment|/* Configuration constants */
end_comment

begin_define
define|#
directive|define
name|CLPD6832_BCR_MGMT_IRQ_ENA
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CLPD6832_BCR_ISA_IRQ
value|0x00800000
end_define

begin_define
define|#
directive|define
name|CLPD6832_COMMAND_DEFAULTS
value|0x00000045
end_define

begin_define
define|#
directive|define
name|CLPD6832_NUM_REGS
value|2
end_define

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
comment|/* TI112X specific code */
end_comment

begin_define
define|#
directive|define
name|TI12XX_DEVCNTL_INTR_ALLSERIAL
value|0x06u
end_define

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
comment|/* sanpei */
end_comment

begin_comment
comment|/* For Bridge Control register (CB_PCI_BRIDGE_CTRL) */
end_comment

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

end_unit

