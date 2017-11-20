begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2003-2010  Cavium Networks (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Networks nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_IRQ_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_IRQ_H__
end_define

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * Enumeration of Interrupt numbers  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* 0 - 7 represent the 8 MIPS standard interrupt sources */
name|OCTEON_IRQ_SW0
init|=
literal|0
block|,
name|OCTEON_IRQ_SW1
init|=
literal|1
block|,
name|OCTEON_IRQ_CIU0
init|=
literal|2
block|,
name|OCTEON_IRQ_CIU1
init|=
literal|3
block|,
name|OCTEON_IRQ_4
init|=
literal|4
block|,
name|OCTEON_IRQ_5
init|=
literal|5
block|,
name|OCTEON_IRQ_6
init|=
literal|6
block|,
name|OCTEON_IRQ_7
init|=
literal|7
block|,
comment|/* 8 - 71 represent the sources in CIU_INTX_EN0 */
name|OCTEON_IRQ_WORKQ0
init|=
literal|8
block|,
name|OCTEON_IRQ_WORKQ1
init|=
literal|9
block|,
name|OCTEON_IRQ_WORKQ2
init|=
literal|10
block|,
name|OCTEON_IRQ_WORKQ3
init|=
literal|11
block|,
name|OCTEON_IRQ_WORKQ4
init|=
literal|12
block|,
name|OCTEON_IRQ_WORKQ5
init|=
literal|13
block|,
name|OCTEON_IRQ_WORKQ6
init|=
literal|14
block|,
name|OCTEON_IRQ_WORKQ7
init|=
literal|15
block|,
name|OCTEON_IRQ_WORKQ8
init|=
literal|16
block|,
name|OCTEON_IRQ_WORKQ9
init|=
literal|17
block|,
name|OCTEON_IRQ_WORKQ10
init|=
literal|18
block|,
name|OCTEON_IRQ_WORKQ11
init|=
literal|19
block|,
name|OCTEON_IRQ_WORKQ12
init|=
literal|20
block|,
name|OCTEON_IRQ_WORKQ13
init|=
literal|21
block|,
name|OCTEON_IRQ_WORKQ14
init|=
literal|22
block|,
name|OCTEON_IRQ_WORKQ15
init|=
literal|23
block|,
name|OCTEON_IRQ_GPIO0
init|=
literal|24
block|,
name|OCTEON_IRQ_GPIO1
init|=
literal|25
block|,
name|OCTEON_IRQ_GPIO2
init|=
literal|26
block|,
name|OCTEON_IRQ_GPIO3
init|=
literal|27
block|,
name|OCTEON_IRQ_GPIO4
init|=
literal|28
block|,
name|OCTEON_IRQ_GPIO5
init|=
literal|29
block|,
name|OCTEON_IRQ_GPIO6
init|=
literal|30
block|,
name|OCTEON_IRQ_GPIO7
init|=
literal|31
block|,
name|OCTEON_IRQ_GPIO8
init|=
literal|32
block|,
name|OCTEON_IRQ_GPIO9
init|=
literal|33
block|,
name|OCTEON_IRQ_GPIO10
init|=
literal|34
block|,
name|OCTEON_IRQ_GPIO11
init|=
literal|35
block|,
name|OCTEON_IRQ_GPIO12
init|=
literal|36
block|,
name|OCTEON_IRQ_GPIO13
init|=
literal|37
block|,
name|OCTEON_IRQ_GPIO14
init|=
literal|38
block|,
name|OCTEON_IRQ_GPIO15
init|=
literal|39
block|,
name|OCTEON_IRQ_MBOX0
init|=
literal|40
block|,
name|OCTEON_IRQ_MBOX1
init|=
literal|41
block|,
name|OCTEON_IRQ_UART0
init|=
literal|42
block|,
name|OCTEON_IRQ_UART1
init|=
literal|43
block|,
name|OCTEON_IRQ_PCI_INT0
init|=
literal|44
block|,
name|OCTEON_IRQ_PCI_INT1
init|=
literal|45
block|,
name|OCTEON_IRQ_PCI_INT2
init|=
literal|46
block|,
name|OCTEON_IRQ_PCI_INT3
init|=
literal|47
block|,
name|OCTEON_IRQ_PCI_MSI0
init|=
literal|48
block|,
name|OCTEON_IRQ_PCI_MSI1
init|=
literal|49
block|,
name|OCTEON_IRQ_PCI_MSI2
init|=
literal|50
block|,
name|OCTEON_IRQ_PCI_MSI3
init|=
literal|51
block|,
name|OCTEON_IRQ_RESERVED44
init|=
literal|52
block|,
name|OCTEON_IRQ_TWSI
init|=
literal|53
block|,
name|OCTEON_IRQ_RML
init|=
literal|54
block|,
name|OCTEON_IRQ_TRACE
init|=
literal|55
block|,
name|OCTEON_IRQ_GMX_DRP0
init|=
literal|56
block|,
name|OCTEON_IRQ_GMX_DRP1
init|=
literal|57
block|,
comment|/* Doesn't apply on CN52XX or CN63XX */
name|OCTEON_IRQ_IPD_DRP
init|=
literal|58
block|,
name|OCTEON_IRQ_KEY_ZERO
init|=
literal|59
block|,
comment|/* Doesn't apply on CN52XX or CN63XX */
name|OCTEON_IRQ_TIMER0
init|=
literal|60
block|,
name|OCTEON_IRQ_TIMER1
init|=
literal|61
block|,
name|OCTEON_IRQ_TIMER2
init|=
literal|62
block|,
name|OCTEON_IRQ_TIMER3
init|=
literal|63
block|,
name|OCTEON_IRQ_USB0
init|=
literal|64
block|,
comment|/* Doesn't apply on CN38XX or CN58XX */
name|OCTEON_IRQ_PCM
init|=
literal|65
block|,
comment|/* Doesn't apply on CN52XX or CN63XX */
name|OCTEON_IRQ_MPI
init|=
literal|66
block|,
comment|/* Doesn't apply on CN52XX or CN63XX */
name|OCTEON_IRQ_TWSI2
init|=
literal|67
block|,
comment|/* Added in CN56XX */
name|OCTEON_IRQ_POWIQ
init|=
literal|68
block|,
comment|/* Added in CN56XX */
name|OCTEON_IRQ_IPDPPTHR
init|=
literal|69
block|,
comment|/* Added in CN56XX */
name|OCTEON_IRQ_MII
init|=
literal|70
block|,
comment|/* Added in CN56XX */
name|OCTEON_IRQ_BOOTDMA
init|=
literal|71
block|,
comment|/* Added in CN56XX */
comment|/* 72 - 135 represent the sources in CIU_INTX_EN1 */
name|OCTEON_IRQ_WDOG0
init|=
literal|72
block|,
name|OCTEON_IRQ_WDOG1
init|=
literal|73
block|,
name|OCTEON_IRQ_WDOG2
init|=
literal|74
block|,
name|OCTEON_IRQ_WDOG3
init|=
literal|75
block|,
name|OCTEON_IRQ_WDOG4
init|=
literal|76
block|,
name|OCTEON_IRQ_WDOG5
init|=
literal|77
block|,
name|OCTEON_IRQ_WDOG6
init|=
literal|78
block|,
name|OCTEON_IRQ_WDOG7
init|=
literal|79
block|,
name|OCTEON_IRQ_WDOG8
init|=
literal|80
block|,
name|OCTEON_IRQ_WDOG9
init|=
literal|81
block|,
name|OCTEON_IRQ_WDOG10
init|=
literal|82
block|,
name|OCTEON_IRQ_WDOG11
init|=
literal|83
block|,
name|OCTEON_IRQ_WDOG12
init|=
literal|84
block|,
name|OCTEON_IRQ_WDOG13
init|=
literal|85
block|,
name|OCTEON_IRQ_WDOG14
init|=
literal|86
block|,
name|OCTEON_IRQ_WDOG15
init|=
literal|87
block|,
name|OCTEON_IRQ_UART2
init|=
literal|88
block|,
comment|/* Added in CN52XX */
name|OCTEON_IRQ_USB1
init|=
literal|89
block|,
comment|/* Added in CN52XX */
name|OCTEON_IRQ_MII1
init|=
literal|90
block|,
comment|/* Added in CN52XX */
name|OCTEON_IRQ_NAND
init|=
literal|91
block|,
comment|/* Added in CN52XX */
name|OCTEON_IRQ_MIO
init|=
literal|92
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_IOB
init|=
literal|93
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_FPA
init|=
literal|94
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_POW
init|=
literal|95
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_L2C
init|=
literal|96
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_IPD
init|=
literal|97
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_PIP
init|=
literal|98
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_PKO
init|=
literal|99
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_ZIP
init|=
literal|100
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_TIM
init|=
literal|101
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_RAD
init|=
literal|102
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_KEY
init|=
literal|103
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_DFA
init|=
literal|104
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_USB
init|=
literal|105
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_SLI
init|=
literal|106
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_DPI
init|=
literal|107
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_AGX0
init|=
literal|108
block|,
comment|/* Added in CN63XX */
comment|/* 109 - 117 are reserved */
name|OCTEON_IRQ_AGL
init|=
literal|118
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_PTP
init|=
literal|119
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_PEM0
init|=
literal|120
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_PEM1
init|=
literal|121
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_SRIO0
init|=
literal|122
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_SRIO1
init|=
literal|123
block|,
comment|/* Added in CN63XX */
name|OCTEON_IRQ_LMC0
init|=
literal|124
block|,
comment|/* Added in CN63XX */
comment|/* Interrupts 125 - 127 are reserved */
name|OCTEON_IRQ_DFM
init|=
literal|128
block|,
comment|/* Added in CN63XX */
comment|/* Interrupts 129 - 135 are reserved */
block|}
name|octeon_irq_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OCTEON_PMC_IRQ
value|OCTEON_IRQ_4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

