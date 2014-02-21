begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2007 by Oleksandr Tymoshenko. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IDTREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IDTREG_H__
end_define

begin_comment
comment|/* Interrupt controller */
end_comment

begin_define
define|#
directive|define
name|IDT_BASE_ICU
value|0x18038000
end_define

begin_define
define|#
directive|define
name|ICU_IPEND2
value|0x00
end_define

begin_define
define|#
directive|define
name|ICU_ITEST2
value|0x04
end_define

begin_define
define|#
directive|define
name|ICU_IMASK2
value|0x08
end_define

begin_define
define|#
directive|define
name|ICU_IPEND3
value|0x0C
end_define

begin_define
define|#
directive|define
name|ICU_ITEST3
value|0x10
end_define

begin_define
define|#
directive|define
name|ICU_IMASK3
value|0x14
end_define

begin_define
define|#
directive|define
name|ICU_IPEND4
value|0x18
end_define

begin_define
define|#
directive|define
name|ICU_ITEST4
value|0x1c
end_define

begin_define
define|#
directive|define
name|ICU_IMASK4
value|0x20
end_define

begin_define
define|#
directive|define
name|ICU_IPEND5
value|0x24
end_define

begin_define
define|#
directive|define
name|ICU_ITEST5
value|0x28
end_define

begin_define
define|#
directive|define
name|ICU_IMASK5
value|0x2c
end_define

begin_define
define|#
directive|define
name|ICU_IPEND6
value|0x30
end_define

begin_define
define|#
directive|define
name|ICU_ITEST6
value|0x34
end_define

begin_define
define|#
directive|define
name|ICU_IMASK6
value|0x38
end_define

begin_define
define|#
directive|define
name|ICU_NMIPS
value|0x3c
end_define

begin_define
define|#
directive|define
name|IDT_BASE_GPIO
value|0x18050000
end_define

begin_define
define|#
directive|define
name|GPIO_FUNC
value|0x00
end_define

begin_define
define|#
directive|define
name|GPIO_CFG
value|0x04
end_define

begin_define
define|#
directive|define
name|GPIO_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|GPIO_ILEVEL
value|0x0C
end_define

begin_define
define|#
directive|define
name|GPIO_ISTAT
value|0x10
end_define

begin_define
define|#
directive|define
name|GPIO_NMIEN
value|0x14
end_define

begin_define
define|#
directive|define
name|IDT_BASE_UART0
value|0x18058000
end_define

begin_comment
comment|/* PCI controller */
end_comment

begin_define
define|#
directive|define
name|IDT_BASE_PCI
value|0x18080000
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CNTL
value|0x00
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CNTL_EN
value|0x001
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CNTL_TNR
value|0x002
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CNTL_SCE
value|0x004
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CNTL_IEN
value|0x008
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CNTL_AAA
value|0x010
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CNTL_EAP
value|0x020
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CNTL_IGM
value|0x200
end_define

begin_define
define|#
directive|define
name|IDT_PCI_STATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|IDT_PCI_STATUS_RIP
value|0x20000
end_define

begin_define
define|#
directive|define
name|IDT_PCI_STATUS_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CFG_ADDR
value|0x0C
end_define

begin_define
define|#
directive|define
name|IDT_PCI_CFG_DATA
value|0x10
end_define

begin_comment
comment|/* LBA stuff */
end_comment

begin_define
define|#
directive|define
name|IDT_PCI_LBA0
value|0x14
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA0_CNTL
value|0x18
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_MSI
value|0x01
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_1MB
value|(0x14<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_2MB
value|(0x15<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_4MB
value|(0x16<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_8MB
value|(0x17<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_16MB
value|(0x18<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_32MB
value|(0x19<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_64MB
value|(0x1A<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_128MB
value|(0x1B<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_SIZE_256MB
value|(0x1C<< 2)
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_FE
value|0x80
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA_RT
value|0x100
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA0_MAP
value|0x1C
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA1
value|0x20
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA1_CNTL
value|0x24
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA1_MAP
value|0x28
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA2
value|0x2C
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA2_CNTL
value|0x30
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA2_MAP
value|0x34
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA3
value|0x38
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA3_CNTL
value|0x3C
end_define

begin_define
define|#
directive|define
name|IDT_PCI_LBA3_MAP
value|0x40
end_define

begin_comment
comment|/* decoupled registers */
end_comment

begin_define
define|#
directive|define
name|IDT_PCI_DAC
value|0x44
end_define

begin_define
define|#
directive|define
name|IDT_PCI_DAS
value|0x48
end_define

begin_define
define|#
directive|define
name|IDT_PCI_DASM
value|0x4C
end_define

begin_define
define|#
directive|define
name|IDT_PCI_TC
value|0x5C
end_define

begin_define
define|#
directive|define
name|IDT_PCI_TC_RTIMER
value|0x10
end_define

begin_define
define|#
directive|define
name|IDT_PCI_TC_DTIMER
value|0x08
end_define

begin_comment
comment|/* Messaging unit of PCI controller */
end_comment

begin_define
define|#
directive|define
name|IDT_PCI_IIC
value|0x8024
end_define

begin_define
define|#
directive|define
name|IDT_PCI_IIM
value|0x8028
end_define

begin_define
define|#
directive|define
name|IDT_PCI_OIC
value|0x8030
end_define

begin_define
define|#
directive|define
name|IDT_PCI_OIM
value|0x8034
end_define

begin_comment
comment|/* PCI-related stuff */
end_comment

begin_define
define|#
directive|define
name|IDT_PCIMEM0_BASE
value|0x50000000
end_define

begin_define
define|#
directive|define
name|IDT_PCIMEM0_SIZE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IDT_PCIMEM1_BASE
value|0x60000000
end_define

begin_define
define|#
directive|define
name|IDT_PCIMEM1_SIZE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IDT_PCIMEM2_BASE
value|0x18C00000
end_define

begin_define
define|#
directive|define
name|IDT_PCIMEM2_SIZE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IDT_PCIMEM3_BASE
value|0x18800000
end_define

begin_define
define|#
directive|define
name|IDT_PCIMEM3_SIZE
value|0x00100000
end_define

begin_comment
comment|/* Interrupts-related stuff */
end_comment

begin_define
define|#
directive|define
name|IRQ_BASE
value|8
end_define

begin_comment
comment|/* Convert<IPbit, irq_offset> pair to IRQ number */
end_comment

begin_define
define|#
directive|define
name|IP_IRQ
parameter_list|(
name|IPbit
parameter_list|,
name|offset
parameter_list|)
value|((IPbit - 2) * 32 + (offset) + IRQ_BASE)
end_define

begin_comment
comment|/* The last one available IRQ */
end_comment

begin_define
define|#
directive|define
name|IRQ_END
value|IP_IRQ(6, 31)
end_define

begin_define
define|#
directive|define
name|ICU_GROUP_REG_OFFSET
value|0x0C
end_define

begin_define
define|#
directive|define
name|ICU_IP
parameter_list|(
name|irq
parameter_list|)
value|(((irq) - IRQ_BASE)& 0x1f)
end_define

begin_define
define|#
directive|define
name|ICU_IP_BIT
parameter_list|(
name|irq
parameter_list|)
value|(1<< ICU_IP(irq))
end_define

begin_define
define|#
directive|define
name|ICU_GROUP
parameter_list|(
name|irq
parameter_list|)
value|(((irq) - IRQ_BASE)>> 5)
end_define

begin_define
define|#
directive|define
name|ICU_GROUP_MASK_REG
parameter_list|(
name|group
parameter_list|)
define|\
value|(ICU_IMASK2 + ((((group) - 2) * ICU_GROUP_REG_OFFSET)))
end_define

begin_define
define|#
directive|define
name|ICU_GROUP_IPEND_REG
parameter_list|(
name|group
parameter_list|)
define|\
value|(ICU_IPEND2 + ((((group) - 2) * ICU_GROUP_REG_OFFSET)))
end_define

begin_define
define|#
directive|define
name|ICU_IRQ_MASK_REG
parameter_list|(
name|irq
parameter_list|)
define|\
value|(ICU_IMASK2 + ((ICU_GROUP(irq) * ICU_GROUP_REG_OFFSET)))
end_define

begin_define
define|#
directive|define
name|ICU_IRQ_IPEND_REG
parameter_list|(
name|irq
parameter_list|)
define|\
value|(ICU_IPEND2 + ((ICU_GROUP(irq) * ICU_GROUP_REG_OFFSET)))
end_define

begin_define
define|#
directive|define
name|PCI_IRQ_BASE
value|IP_IRQ(6, 4)
end_define

begin_define
define|#
directive|define
name|PCI_IRQ_END
value|IP_IRQ(6, 7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IDTREG_H__ */
end_comment

end_unit

