begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  * NETLOGIC_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XLP_PIC_H__
end_ifndef

begin_define
define|#
directive|define
name|__XLP_PIC_H__
end_define

begin_comment
comment|/* PIC Specific registers */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_CTRL_REG
value|0x40
end_define

begin_define
define|#
directive|define
name|XLP_PIC_BYTESWAP_REG
value|0x42
end_define

begin_define
define|#
directive|define
name|XLP_PIC_STATUS_REG
value|0x44
end_define

begin_define
define|#
directive|define
name|XLP_PIC_INTR_TIMEOUT
value|0x46
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ICI0_INTR_TIMEOUT
value|0x48
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ICI1_INTR_TIMEOUT
value|0x4a
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ICI2_INTR_TIMEOUT
value|0x4c
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IPI_CTRL_REG
value|0x4e
end_define

begin_define
define|#
directive|define
name|XLP_PIC_INT_ACK_REG
value|0x50
end_define

begin_define
define|#
directive|define
name|XLP_PIC_INT_PENDING0_REG
value|0x52
end_define

begin_define
define|#
directive|define
name|XLP_PIC_INT_PENDING1_REG
value|0x54
end_define

begin_define
define|#
directive|define
name|XLP_PIC_INT_PENDING2_REG
value|0x56
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG0_MAXVAL_REG
value|0x58
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG0_COUNT_REG
value|0x5a
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG0_ENABLE0_REG
value|0x5c
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG0_ENABLE1_REG
value|0x5e
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG0_BEATCMD_REG
value|0x60
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG0_BEAT0_REG
value|0x62
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG0_BEAT1_REG
value|0x64
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG1_MAXVAL_REG
value|0x66
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG1_COUNT_REG
value|0x68
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG1_ENABLE0_REG
value|0x6a
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG1_ENABLE1_REG
value|0x6c
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG1_BEATCMD_REG
value|0x6e
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG1_BEAT0_REG
value|0x70
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG1_BEAT1_REG
value|0x72
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG_MAXVAL_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_WDOG0_MAXVAL_REG + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG_COUNT_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_WDOG0_COUNT_REG + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG_ENABLE0_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_WDOG0_ENABLE0_REG + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG_ENABLE1_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_WDOG0_ENABLE1_REG + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG_BEATCMD_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_WDOG0_BEATCMD_REG + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG_BEAT0_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_WDOG0_BEAT0_REG + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_WDOG_BEAT1_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_WDOG0_BEAT1_REG + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER0_MAXVAL_REG
value|0x74
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER1_MAXVAL_REG
value|0x76
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER2_MAXVAL_REG
value|0x78
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER3_MAXVAL_REG
value|0x7a
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER4_MAXVAL_REG
value|0x7c
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER5_MAXVAL_REG
value|0x7e
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER6_MAXVAL_REG
value|0x80
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER7_MAXVAL_REG
value|0x82
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER_MAXVAL_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_SYSTIMER0_MAXVAL_REG + ((i)*2))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER0_COUNT_REG
value|0x84
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER1_COUNT_REG
value|0x86
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER2_COUNT_REG
value|0x88
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER3_COUNT_REG
value|0x8a
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER4_COUNT_REG
value|0x8c
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER5_COUNT_REG
value|0x8e
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER6_COUNT_REG
value|0x90
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER7_COUNT_REG
value|0x92
end_define

begin_define
define|#
directive|define
name|XLP_PIC_SYSTIMER_COUNT_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_SYSTIMER0_COUNT_REG + ((i)*2))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE0_N0_N1_REG
value|0x94
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE1_N0_N1_REG
value|0x98
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE2_N0_N1_REG
value|0x9c
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE3_N0_N1_REG
value|0xa0
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE4_N0_N1_REG
value|0xa4
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE5_N0_N1_REG
value|0xa8
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE6_N0_N1_REG
value|0xac
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE7_N0_N1_REG
value|0xb0
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE_N0_N1_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_ITE0_N0_N1_REG + ((i)*4))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE0_N2_N3_REG
value|0x96
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE1_N2_N3_REG
value|0x9a
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE2_N2_N3_REG
value|0x9e
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE3_N2_N3_REG
value|0xa2
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE4_N2_N3_REG
value|0xa6
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE5_N2_N3_REG
value|0xaa
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE6_N2_N3_REG
value|0xae
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE7_N2_N3_REG
value|0xb2
end_define

begin_define
define|#
directive|define
name|XLP_PIC_ITE_N2_N3_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_ITE0_N2_N3_REG + ((i)*4))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT0_REG
value|0xb4
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_REG
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT0_REG + ((i)*2))
end_define

begin_comment
comment|/* PIC IRT indices */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_WD0_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_WD1_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_WD_NMI0_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_WD_NMI1_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER0_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER1_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER2_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER3_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER4_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER5_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER6_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER7_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TIMER_INDEX
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT_TIMER0_INDEX + (i))
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_MSGQ0_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_MSGQ_INDEX
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT_MSGQ0_INDEX + (i))
end_define

begin_comment
comment|/* 12 to 43 */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_MSG0_INDEX
value|44
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_MSG1_INDEX
value|45
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_PCIE_MSIX0_INDEX
value|46
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_PCIE_MSIX_INDEX
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT_PCIE_MSIX0_INDEX + (i))
end_define

begin_comment
comment|/* 46 to 77 */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_PCIE_LINK0_INDEX
value|78
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_PCIE_LINK1_INDEX
value|79
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_PCIE_LINK2_INDEX
value|80
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_PCIE_LINK3_INDEX
value|81
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_PCIE_LINK_INDEX
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT_PCIE_LINK0_INDEX + (i))
end_define

begin_comment
comment|/* 78 to 81 */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_NA0_INDEX
value|82
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_NA_INDEX
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT_NA0_INDEX + (i))
end_define

begin_comment
comment|/* 82 to 113 */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_POE_INDEX
value|114
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_USB0_INDEX
value|115
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_EHCI0_INDEX
value|115
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_EHCI1_INDEX
value|118
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_USB_INDEX
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT_USB0_INDEX + (i))
end_define

begin_comment
comment|/* 115 to 120 */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_GDX_INDEX
value|121
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_SEC_INDEX
value|122
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_RSA_INDEX
value|123
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_COMP0_INDEX
value|124
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_COMP_INDEX
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT_COMP0_INDEX + (i))
end_define

begin_comment
comment|/* 124 to 127 */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_GBU_INDEX
value|128
end_define

begin_comment
comment|/* coherent inter chip */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_CIC0_INDEX
value|129
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_CIC1_INDEX
value|130
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_CIC2_INDEX
value|131
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_CAM_INDEX
value|132
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_UART0_INDEX
value|133
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_UART1_INDEX
value|134
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_I2C0_INDEX
value|135
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_I2C1_INDEX
value|136
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_SYS0_INDEX
value|137
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_SYS1_INDEX
value|138
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_JTAG_INDEX
value|139
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_PIC_INDEX
value|140
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_NBU_INDEX
value|141
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_TCU_INDEX
value|142
end_define

begin_comment
comment|/* global coherency */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_GCU_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_DMC0_INDEX
value|144
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_DMC1_INDEX
value|145
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_GPIO0_INDEX
value|146
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_GPIO_INDEX
parameter_list|(
name|i
parameter_list|)
value|(XLP_PIC_IRT_GPIO0_INDEX + (i))
end_define

begin_comment
comment|/* 146 to 149 */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_NOR_INDEX
value|150
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_NAND_INDEX
value|151
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_SPI_INDEX
value|152
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_MMC_INDEX
value|153
end_define

begin_comment
comment|/* PIC control register defines */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_ITV_OFFSET
value|32
end_define

begin_comment
comment|/* interrupt timeout value */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_ICI_OFFSET
value|19
end_define

begin_comment
comment|/* ICI interrupt timeout enable */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_ITE_OFFSET
value|18
end_define

begin_comment
comment|/* interrupt timeout enable */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_STE_OFFSET
value|10
end_define

begin_comment
comment|/* system timer interrupt enable */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_WWR1_OFFSET
value|8
end_define

begin_comment
comment|/* watchdog timer 1 wraparound count for reset */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_WWR0_OFFSET
value|6
end_define

begin_comment
comment|/* watchdog timer 0 wraparound count for reset */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_WWN1_OFFSET
value|4
end_define

begin_comment
comment|/* watchdog timer 1 wraparound count for NMI */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_WWN0_OFFSET
value|2
end_define

begin_comment
comment|/* watchdog timer 0 wraparound count for NMI */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_WTE_OFFSET
value|0
end_define

begin_comment
comment|/* watchdog timer enable */
end_comment

begin_comment
comment|/* PIC Status register defines */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_ICI_STATUS_OFFSET
value|33
end_define

begin_comment
comment|/* ICI interrupt timeout interrupt status */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_ITE_STATUS_OFFSET
value|32
end_define

begin_comment
comment|/* interrupt timeout interrupt status */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_STS_STATUS_OFFSET
value|4
end_define

begin_comment
comment|/* System timer interrupt status */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_WNS_STATUS_OFFSET
value|2
end_define

begin_comment
comment|/* NMI interrupt status for watchdog timers */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_WIS_STATUS_OFFSET
value|0
end_define

begin_comment
comment|/* Interrupt status for watchdog timers */
end_comment

begin_comment
comment|/* PIC IPI control register offsets */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IPICTRL_NMI_OFFSET
value|32
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IPICTRL_RIV_OFFSET
value|20
end_define

begin_comment
comment|/* received interrupt vector */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IPICTRL_IDB_OFFSET
value|16
end_define

begin_comment
comment|/* interrupt destination base */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IPICTRL_DTE_OFFSET
value|16
end_define

begin_comment
comment|/* interrupt destination thread enables */
end_comment

begin_comment
comment|/* PIC IRT register offsets */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_ENABLE_OFFSET
value|31
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_NMI_OFFSET
value|29
end_define

begin_define
define|#
directive|define
name|XLP_PIC_IRT_SCH_OFFSET
value|28
end_define

begin_comment
comment|/* Scheduling scheme */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_RVEC_OFFSET
value|20
end_define

begin_comment
comment|/* Interrupt receive vectors */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_DT_OFFSET
value|19
end_define

begin_comment
comment|/* Destination type */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_DB_OFFSET
value|16
end_define

begin_comment
comment|/* Destination base */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_IRT_DTE_OFFSET
value|0
end_define

begin_comment
comment|/* Destination thread enables */
end_comment

begin_define
define|#
directive|define
name|XLP_PIC_MAX_IRQ
value|64
end_define

begin_define
define|#
directive|define
name|XLP_PIC_MAX_IRT
value|160
end_define

begin_define
define|#
directive|define
name|XLP_PIC_TIMER_FREQ
value|133000000
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_define
define|#
directive|define
name|nlm_rdreg_pic
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg64_kseg(b,r)
end_define

begin_define
define|#
directive|define
name|nlm_wreg_pic
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg64_kseg(b,r,v)
end_define

begin_define
define|#
directive|define
name|nlm_pcibase_pic
parameter_list|(
name|node
parameter_list|)
value|nlm_pcicfg_base(XLP_IO_PIC_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_regbase_pic
parameter_list|(
name|node
parameter_list|)
value|nlm_pcibase_pic(node)
end_define

begin_comment
comment|/* IRT and h/w interrupt routines */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|nlm_pic_get_numirts
parameter_list|(
name|uint64_t
name|pcibase
parameter_list|)
block|{
return|return
operator|(
name|nlm_pci_rdreg
argument_list|(
name|pcibase
argument_list|,
name|XLP_PCI_IRTINFO_REG
argument_list|)
operator|>>
literal|16
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_pic_get_startirt
parameter_list|(
name|uint64_t
name|base
parameter_list|)
block|{
return|return
operator|(
name|nlm_pci_rdreg
argument_list|(
name|base
argument_list|,
name|XLP_PCI_IRTINFO_REG
argument_list|)
operator|&
literal|0xff
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_pic_read_irt
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt_index
parameter_list|)
block|{
return|return
name|nlm_rdreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_IRT_REG
argument_list|(
name|irt_index
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* IRT's can be written into in two modes  * ITE mode - Here the destination of the interrupt is one of the  *   eight interrupt-thread-enable groups, allowing the interrupt  *   to be distributed to any thread on any node  * ID mode - In ID mode, the IRT has the DB and DTE fields.  *   DB[18:17] hold the node select and DB[16], if set to 0 selects  *   cpu-cores 0-3, and if set to 1 selects cpu-cores 4-7.  *   The DTE[15:0] field is a thread mask, allowing the PIC to broadcast  *   the interrupt to 1-16 threads selectable from that mask  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_write_irt_raw
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt_index
parameter_list|,
name|int
name|en
parameter_list|,
name|int
name|nmi
parameter_list|,
name|int
name|sch
parameter_list|,
name|int
name|vec
parameter_list|,
name|int
name|dt
parameter_list|,
name|int
name|db
parameter_list|,
name|int
name|dte
parameter_list|)
block|{
name|uint64_t
name|val
init|=
operator|(
operator|(
operator|(
name|en
operator|&
literal|0x1
operator|)
operator|<<
name|XLP_PIC_IRT_ENABLE_OFFSET
operator|)
operator||
operator|(
operator|(
name|nmi
operator|&
literal|0x1
operator|)
operator|<<
name|XLP_PIC_IRT_NMI_OFFSET
operator|)
operator||
operator|(
operator|(
name|sch
operator|&
literal|0x1
operator|)
operator|<<
name|XLP_PIC_IRT_SCH_OFFSET
operator|)
operator||
operator|(
operator|(
name|vec
operator|&
literal|0x3f
operator|)
operator|<<
name|XLP_PIC_IRT_RVEC_OFFSET
operator|)
operator||
operator|(
operator|(
name|dt
operator|&
literal|0x1
operator|)
operator|<<
name|XLP_PIC_IRT_DT_OFFSET
operator|)
operator||
operator|(
operator|(
name|db
operator|&
literal|0x7
operator|)
operator|<<
name|XLP_PIC_IRT_DB_OFFSET
operator|)
operator||
operator|(
name|dte
operator|&
literal|0xffff
operator|)
operator|)
decl_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_IRT_REG
argument_list|(
name|irt_index
argument_list|)
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* write IRT in ID mode */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_write_irt_id
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt_index
parameter_list|,
name|int
name|en
parameter_list|,
name|int
name|nmi
parameter_list|,
name|int
name|vec
parameter_list|,
name|int
name|node
parameter_list|,
name|int
name|cpugroup
parameter_list|,
name|uint32_t
name|cpu_mask
parameter_list|)
block|{
name|nlm_pic_write_irt_raw
argument_list|(
name|base
argument_list|,
name|irt_index
argument_list|,
name|en
argument_list|,
name|nmi
argument_list|,
literal|1
argument_list|,
name|vec
argument_list|,
literal|1
argument_list|,
operator|(
name|node
operator|<<
literal|1
operator|)
operator||
name|cpugroup
argument_list|,
name|cpu_mask
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* write IRT in ITE mode */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_write_ite
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|ite
parameter_list|,
name|uint32_t
name|node0_thrmask
parameter_list|,
name|uint32_t
name|node1_thrmask
parameter_list|,
name|uint32_t
name|node2_thrmask
parameter_list|,
name|uint32_t
name|node3_thrmask
parameter_list|)
block|{
name|uint64_t
name|tm10
init|=
operator|(
operator|(
name|uint64_t
operator|)
name|node1_thrmask
operator|<<
literal|32
operator|)
operator||
name|node0_thrmask
decl_stmt|;
name|uint64_t
name|tm32
init|=
operator|(
operator|(
name|uint64_t
operator|)
name|node1_thrmask
operator|<<
literal|32
operator|)
operator||
name|node0_thrmask
decl_stmt|;
comment|/* Enable the ITE register for all nodes */
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_ITE_N0_N1_REG
argument_list|(
name|ite
argument_list|)
argument_list|,
name|tm10
argument_list|)
expr_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_ITE_N2_N3_REG
argument_list|(
name|ite
argument_list|)
argument_list|,
name|tm32
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_write_irt_ite
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt_index
parameter_list|,
name|int
name|ite
parameter_list|,
name|int
name|en
parameter_list|,
name|int
name|nmi
parameter_list|,
name|int
name|sch
parameter_list|,
name|int
name|vec
parameter_list|)
block|{
name|nlm_pic_write_irt_raw
argument_list|(
name|base
argument_list|,
name|irt_index
argument_list|,
name|en
argument_list|,
name|nmi
argument_list|,
name|sch
argument_list|,
name|vec
argument_list|,
literal|0
argument_list|,
name|ite
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Goto PIC on that node, and ack the interrupt */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_ack
parameter_list|(
name|uint64_t
name|src_base
parameter_list|,
name|int
name|irt
parameter_list|)
block|{
name|nlm_wreg_pic
argument_list|(
name|src_base
argument_list|,
name|XLP_PIC_INT_ACK_REG
argument_list|,
name|irt
argument_list|)
expr_stmt|;
comment|/* ack in the status registers for watchdog and system timers */
if|if
condition|(
name|irt
operator|<
literal|12
condition|)
name|nlm_wreg_pic
argument_list|(
name|src_base
argument_list|,
name|XLP_PIC_STATUS_REG
argument_list|,
operator|(
literal|1
operator|<<
name|irt
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* IPI routines */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_send_ipi
parameter_list|(
name|uint64_t
name|local_base
parameter_list|,
name|int
name|target_node
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|int
name|vec
parameter_list|,
name|int
name|nmi
parameter_list|)
block|{
name|uint64_t
name|ipi
init|=
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|nmi
operator|<<
name|XLP_PIC_IPICTRL_NMI_OFFSET
operator|)
operator||
operator|(
name|vec
operator|<<
name|XLP_PIC_IPICTRL_RIV_OFFSET
operator|)
operator||
operator|(
name|target_node
operator|<<
literal|17
operator|)
operator||
operator|(
literal|1
operator|<<
operator|(
name|vcpu
operator|&
literal|0xf
operator|)
operator|)
operator|)
decl_stmt|;
if|if
condition|(
name|vcpu
operator|>
literal|15
condition|)
name|ipi
operator||=
literal|0x10000
expr_stmt|;
comment|/* set bit 16 to select cpus 16-31 */
name|nlm_wreg_pic
argument_list|(
name|local_base
argument_list|,
name|XLP_PIC_IPI_CTRL_REG
argument_list|,
name|ipi
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* System Timer routines -- broadcasts systemtimer to 16 vcpus defined in cpu_mask */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_set_systimer
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|timer
parameter_list|,
name|uint64_t
name|value
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|node
parameter_list|,
name|int
name|cpugroup
parameter_list|,
name|uint32_t
name|cpumask
parameter_list|)
block|{
name|uint64_t
name|pic_ctrl
init|=
name|nlm_rdreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_CTRL_REG
argument_list|)
decl_stmt|;
name|int
name|en
decl_stmt|;
name|en
operator|=
operator|(
name|cpumask
operator|!=
literal|0
operator|)
expr_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_SYSTIMER_MAXVAL_REG
argument_list|(
name|timer
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|nlm_pic_write_irt_id
argument_list|(
name|base
argument_list|,
name|XLP_PIC_IRT_TIMER_INDEX
argument_list|(
name|timer
argument_list|)
argument_list|,
name|en
argument_list|,
literal|0
argument_list|,
name|irq
argument_list|,
name|node
argument_list|,
name|cpugroup
argument_list|,
name|cpumask
argument_list|)
expr_stmt|;
comment|/* enable the timer */
name|pic_ctrl
operator||=
operator|(
literal|1
operator|<<
operator|(
name|XLP_PIC_STE_OFFSET
operator|+
name|timer
operator|)
operator|)
expr_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_CTRL_REG
argument_list|,
name|pic_ctrl
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_pic_read_systimer
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|timer
parameter_list|)
block|{
return|return
name|nlm_rdreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_SYSTIMER_COUNT_REG
argument_list|(
name|timer
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Watchdog timer routines */
end_comment

begin_comment
comment|/* node - XLP node  * timer - watchdog timer. valid values are 0 and 1  * wrap_around_count - defines the number of times the watchdog timer can wrap-around  *     after which the reset / NMI gets generated to the threads defined in thread-enable-masks.  * value - the vatchdog timer max value, upto which the timer will count down  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_set_wdogtimer
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|timer
parameter_list|,
name|int
name|wrap_around_count
parameter_list|,
name|int
name|nmi
parameter_list|,
name|uint32_t
name|node0_thrmask
parameter_list|,
name|uint32_t
name|node1_thrmask
parameter_list|,
name|uint32_t
name|node2_thrmask
parameter_list|,
name|uint32_t
name|node3_thrmask
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
name|uint64_t
name|pic_ctrl
init|=
name|nlm_rdreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_CTRL_REG
argument_list|)
decl_stmt|;
name|uint64_t
name|mask0
decl_stmt|,
name|mask1
decl_stmt|;
if|if
condition|(
name|timer
operator|>
literal|1
operator|||
name|wrap_around_count
operator|>
literal|3
condition|)
return|return;
comment|/* enable watchdog timer interrupt */
name|pic_ctrl
operator||=
operator|(
operator|(
operator|(
literal|1
operator|<<
name|timer
operator|)
operator|&
literal|0xf
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|timer
condition|)
block|{
if|if
condition|(
name|nmi
condition|)
name|pic_ctrl
operator||=
operator|(
name|wrap_around_count
operator|<<
name|XLP_PIC_WWN1_OFFSET
operator|)
expr_stmt|;
else|else
name|pic_ctrl
operator||=
operator|(
name|wrap_around_count
operator|<<
name|XLP_PIC_WWN0_OFFSET
operator|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|nmi
condition|)
name|pic_ctrl
operator||=
operator|(
name|wrap_around_count
operator|<<
name|XLP_PIC_WWR1_OFFSET
operator|)
expr_stmt|;
else|else
name|pic_ctrl
operator||=
operator|(
name|wrap_around_count
operator|<<
name|XLP_PIC_WWR0_OFFSET
operator|)
expr_stmt|;
block|}
name|mask0
operator|=
operator|(
operator|(
name|unsigned
name|long
name|long
operator|)
name|node1_thrmask
operator|<<
literal|32
operator|)
operator||
name|node0_thrmask
expr_stmt|;
name|mask1
operator|=
operator|(
operator|(
name|unsigned
name|long
name|long
operator|)
name|node3_thrmask
operator|<<
literal|32
operator|)
operator||
name|node2_thrmask
expr_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_WDOG_MAXVAL_REG
argument_list|(
name|timer
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_WDOG_ENABLE0_REG
argument_list|(
name|timer
argument_list|)
argument_list|,
name|mask0
argument_list|)
expr_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_WDOG_ENABLE1_REG
argument_list|(
name|timer
argument_list|)
argument_list|,
name|mask1
argument_list|)
expr_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_CTRL_REG
argument_list|,
name|pic_ctrl
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* watchdog's need to be "stroked" by heartbeats from vcpus.  * On XLP, the heartbeat bit for a specific cpu thread on a specific  * node is set according to the following formula:  * 32N + 4C + T  * where N = node, C=cpu-core number, T=thread number  *  * src_node = source node of watchdog timer interrupts. These interrupts  * get generated from the PIC on src_node.  * timer = watchdog timer 0 or 1  * node = node for which the hearbeat is being done  * cpu = cpu-core for which the hearbeat is being done  * thread = h/w thread for which the hearbeat is being done  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pic_set_wdog_heartbeat
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|timer
parameter_list|,
name|int
name|node
parameter_list|,
name|int
name|cpu
parameter_list|,
name|int
name|thread
parameter_list|)
block|{
name|int
name|val
init|=
literal|32
operator|*
name|node
operator|+
literal|4
operator|*
name|cpu
operator|+
name|thread
decl_stmt|;
name|nlm_wreg_pic
argument_list|(
name|base
argument_list|,
name|XLP_PIC_WDOG_BEATCMD_REG
argument_list|(
name|timer
argument_list|)
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE&& !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

