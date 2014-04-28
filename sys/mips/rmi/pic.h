begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMI_PIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMI_PIC_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<mips/rmi/iomap.h>
end_include

begin_define
define|#
directive|define
name|PIC_IRT_WD_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_INDEX
parameter_list|(
name|i
parameter_list|)
value|(1 + (i))
end_define

begin_define
define|#
directive|define
name|PIC_IRT_UART_0_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|PIC_IRT_UART_1_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|PIC_IRT_I2C_0_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|PIC_IRT_I2C_1_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCMCIA_INDEX
value|13
end_define

begin_define
define|#
directive|define
name|PIC_IRT_GPIO_INDEX
value|14
end_define

begin_define
define|#
directive|define
name|PIC_IRT_HYPER_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIX_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|PIC_IRT_GMAC0_INDEX
value|17
end_define

begin_define
define|#
directive|define
name|PIC_IRT_GMAC1_INDEX
value|18
end_define

begin_define
define|#
directive|define
name|PIC_IRT_GMAC2_INDEX
value|19
end_define

begin_define
define|#
directive|define
name|PIC_IRT_GMAC3_INDEX
value|20
end_define

begin_define
define|#
directive|define
name|PIC_IRT_XGS0_INDEX
value|21
end_define

begin_define
define|#
directive|define
name|PIC_IRT_XGS1_INDEX
value|22
end_define

begin_define
define|#
directive|define
name|PIC_IRT_HYPER_FATAL_INDEX
value|23
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIX_FATAL_INDEX
value|24
end_define

begin_define
define|#
directive|define
name|PIC_IRT_BRIDGE_AERR_INDEX
value|25
end_define

begin_define
define|#
directive|define
name|PIC_IRT_BRIDGE_BERR_INDEX
value|26
end_define

begin_define
define|#
directive|define
name|PIC_IRT_BRIDGE_TB_INDEX
value|27
end_define

begin_define
define|#
directive|define
name|PIC_IRT_BRIDGE_AERR_NMI_INDEX
value|28
end_define

begin_comment
comment|/* numbering for XLS */
end_comment

begin_define
define|#
directive|define
name|PIC_IRT_BRIDGE_ERR_INDEX
value|25
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIE_LINK0_INDEX
value|26
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIE_LINK1_INDEX
value|27
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIE_LINK2_INDEX
value|23
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIE_LINK3_INDEX
value|24
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIE_B0_LINK2_INDEX
value|28
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIE_B0_LINK3_INDEX
value|29
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIE_INT_INDEX
value|28
end_define

begin_define
define|#
directive|define
name|PIC_IRT_PCIE_FATAL_INDEX
value|29
end_define

begin_define
define|#
directive|define
name|PIC_IRT_GPIO_B_INDEX
value|30
end_define

begin_define
define|#
directive|define
name|PIC_IRT_USB_INDEX
value|31
end_define

begin_define
define|#
directive|define
name|PIC_NUM_IRTS
value|32
end_define

begin_define
define|#
directive|define
name|PIC_CLOCK_TIMER
value|7
end_define

begin_define
define|#
directive|define
name|PIC_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|PIC_IPI
value|0x04
end_define

begin_define
define|#
directive|define
name|PIC_INT_ACK
value|0x06
end_define

begin_define
define|#
directive|define
name|WD_MAX_VAL_0
value|0x08
end_define

begin_define
define|#
directive|define
name|WD_MAX_VAL_1
value|0x09
end_define

begin_define
define|#
directive|define
name|WD_MASK_0
value|0x0a
end_define

begin_define
define|#
directive|define
name|WD_MASK_1
value|0x0b
end_define

begin_define
define|#
directive|define
name|WD_HEARBEAT_0
value|0x0c
end_define

begin_define
define|#
directive|define
name|WD_HEARBEAT_1
value|0x0d
end_define

begin_define
define|#
directive|define
name|PIC_IRT_0_BASE
value|0x40
end_define

begin_define
define|#
directive|define
name|PIC_IRT_1_BASE
value|0x80
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_MAXVAL_0_BASE
value|0x100
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_MAXVAL_1_BASE
value|0x110
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_COUNT_0_BASE
value|0x120
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_COUNT_1_BASE
value|0x130
end_define

begin_define
define|#
directive|define
name|PIC_IRT_0
parameter_list|(
name|picintr
parameter_list|)
value|(PIC_IRT_0_BASE + (picintr))
end_define

begin_define
define|#
directive|define
name|PIC_IRT_1
parameter_list|(
name|picintr
parameter_list|)
value|(PIC_IRT_1_BASE + (picintr))
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_MAXVAL_0
parameter_list|(
name|i
parameter_list|)
value|(PIC_TIMER_MAXVAL_0_BASE + (i))
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_MAXVAL_1
parameter_list|(
name|i
parameter_list|)
value|(PIC_TIMER_MAXVAL_1_BASE + (i))
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_COUNT_0
parameter_list|(
name|i
parameter_list|)
value|(PIC_TIMER_COUNT_0_BASE + (i))
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_COUNT_1
parameter_list|(
name|i
parameter_list|)
value|(PIC_TIMER_COUNT_0_BASE + (i))
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_HZ
value|66000000U
end_define

begin_comment
comment|/*  * We use a simple mapping form PIC interrupts to CPU IRQs.  * The PIC interrupts 0-31 are mapped to CPU irq's 8-39.  * this leaves the lower 0-7 for the cpu interrupts (like   * count/compare, msgrng) and 40-63 for IPIs  */
end_comment

begin_define
define|#
directive|define
name|PIC_IRQ_BASE
value|8
end_define

begin_define
define|#
directive|define
name|PIC_INTR_TO_IRQ
parameter_list|(
name|i
parameter_list|)
value|(PIC_IRQ_BASE + (i))
end_define

begin_define
define|#
directive|define
name|PIC_IRQ_TO_INTR
parameter_list|(
name|i
parameter_list|)
value|((i) - PIC_IRQ_BASE)
end_define

begin_define
define|#
directive|define
name|PIC_WD_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_WD_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_IRQ
parameter_list|(
name|i
parameter_list|)
value|(PIC_IRQ_BASE + PIC_IRT_TIMER_INDEX(i))
end_define

begin_define
define|#
directive|define
name|PIC_CLOCK_IRQ
value|PIC_TIMER_IRQ(PIC_CLOCK_TIMER)
end_define

begin_define
define|#
directive|define
name|PIC_UART_0_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_UART_0_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_UART_1_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_UART_1_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_I2C_0_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_I2C_0_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_I2C_1_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_I2C_1_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCMCIA_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCMCIA_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_GPIO_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_GPIO_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_HYPER_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_HYPER_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIX_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIX_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_GMAC_0_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_GMAC0_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_GMAC_1_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_GMAC1_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_GMAC_2_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_GMAC2_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_GMAC_3_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_GMAC3_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_XGS_0_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_XGS0_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_XGS_1_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_XGS1_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_HYPER_FATAL_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_HYPER_FATAL_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIX_FATAL_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIX_FATAL_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_BRIDGE_AERR_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_BRIDGE_AERR_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_BRIDGE_BERR_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_BRIDGE_BERR_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_BRIDGE_TB_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_BRIDGE_TB_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_BRIDGE_AERR_NMI_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_BRIDGE_AERR_NMI_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_BRIDGE_ERR_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_BRIDGE_ERR_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_LINK0_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIE_LINK0_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_LINK1_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIE_LINK1_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_LINK2_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIE_LINK2_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_LINK3_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIE_LINK3_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_B0_LINK2_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIE_B0_LINK2_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_B0_LINK3_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIE_B0_LINK3_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_INT_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIE_INT_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_FATAL_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_PCIE_FATAL_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_GPIO_B_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_GPIO_B_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_USB_IRQ
value|(PIC_IRQ_BASE + PIC_IRT_USB_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_IRQ_IS_PICINTR
parameter_list|(
name|irq
parameter_list|)
value|((irq)>= PIC_IRQ_BASE&& 		\ 				 (irq)< PIC_IRQ_BASE + PIC_NUM_IRTS)
end_define

begin_define
define|#
directive|define
name|PIC_IS_EDGE_TRIGGERED
parameter_list|(
name|i
parameter_list|)
value|((i)>= PIC_IRT_TIMER_INDEX(0)&&	\ 				  (i)<= PIC_IRT_TIMER_INDEX(7))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|xlr_pic_lock
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|uint32_t
name|pic_read_control
parameter_list|(
name|void
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
name|mtx_lock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
name|reg
operator|=
name|xlr_read_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_CTRL
argument_list|)
expr_stmt|;
name|mtx_unlock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
return|return
operator|(
name|reg
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pic_write_control
parameter_list|(
name|uint32_t
name|control
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|mtx_lock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_CTRL
argument_list|,
name|control
argument_list|)
expr_stmt|;
name|mtx_unlock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pic_update_control
parameter_list|(
name|uint32_t
name|control
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|mtx_lock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_CTRL
argument_list|,
operator|(
name|control
operator||
name|xlr_read_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_CTRL
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|mtx_unlock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pic_ack
parameter_list|(
name|int
name|picintr
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_INT_ACK
argument_list|,
literal|1U
operator|<<
name|picintr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pic_send_ipi
parameter_list|(
name|int
name|cpu
parameter_list|,
name|int
name|ipi
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|int
name|tid
decl_stmt|,
name|pid
decl_stmt|;
name|tid
operator|=
name|cpu
operator|&
literal|0x3
expr_stmt|;
name|pid
operator|=
operator|(
name|cpu
operator|>>
literal|2
operator|)
operator|&
literal|0x7
expr_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_IPI
argument_list|,
operator|(
name|pid
operator|<<
literal|20
operator|)
operator||
operator|(
name|tid
operator|<<
literal|16
operator|)
operator||
name|ipi
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pic_setup_intr
parameter_list|(
name|int
name|picintr
parameter_list|,
name|int
name|irq
parameter_list|,
name|uint32_t
name|cpumask
parameter_list|,
name|int
name|level
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|mtx_lock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_IRT_0
argument_list|(
name|picintr
argument_list|)
argument_list|,
name|cpumask
argument_list|)
expr_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_IRT_1
argument_list|(
name|picintr
argument_list|)
argument_list|,
operator|(
operator|(
literal|1U
operator|<<
literal|31
operator|)
operator||
operator|(
name|level
operator|<<
literal|30
operator|)
operator||
operator|(
literal|1
operator|<<
literal|6
operator|)
operator||
name|irq
operator|)
argument_list|)
expr_stmt|;
name|mtx_unlock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pic_init_timer
parameter_list|(
name|int
name|timer
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
name|mtx_lock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
name|val
operator|=
name|xlr_read_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_CTRL
argument_list|)
expr_stmt|;
name|val
operator||=
operator|(
literal|1
operator|<<
operator|(
literal|8
operator|+
name|timer
operator|)
operator|)
expr_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_CTRL
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|mtx_unlock_spin
argument_list|(
operator|&
name|xlr_pic_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pic_set_timer
parameter_list|(
name|int
name|timer
parameter_list|,
name|uint64_t
name|maxval
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_TIMER_MAXVAL_0
argument_list|(
name|timer
argument_list|)
argument_list|,
operator|(
name|maxval
operator|&
literal|0xffffffff
operator|)
argument_list|)
expr_stmt|;
name|xlr_write_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_TIMER_MAXVAL_1
argument_list|(
name|timer
argument_list|)
argument_list|,
operator|(
name|maxval
operator|>>
literal|32
operator|)
operator|&
literal|0xffffffff
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|pic_timer_count32
parameter_list|(
name|int
name|timer
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
return|return
operator|(
name|xlr_read_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_TIMER_COUNT_0
argument_list|(
name|timer
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The timer can wrap 32 bits between the two reads, so we  * need additional logic to detect that.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|pic_timer_count
parameter_list|(
name|int
name|timer
parameter_list|)
block|{
name|xlr_reg_t
modifier|*
name|mmio
init|=
name|xlr_io_mmio
argument_list|(
name|XLR_IO_PIC_OFFSET
argument_list|)
decl_stmt|;
name|uint32_t
name|tu1
decl_stmt|,
name|tu2
decl_stmt|,
name|tl
decl_stmt|;
name|tu1
operator|=
name|xlr_read_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_TIMER_COUNT_1
argument_list|(
name|timer
argument_list|)
argument_list|)
expr_stmt|;
name|tl
operator|=
name|xlr_read_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_TIMER_COUNT_0
argument_list|(
name|timer
argument_list|)
argument_list|)
expr_stmt|;
name|tu2
operator|=
name|xlr_read_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_TIMER_COUNT_1
argument_list|(
name|timer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tu2
operator|!=
name|tu1
condition|)
name|tl
operator|=
name|xlr_read_reg
argument_list|(
name|mmio
argument_list|,
name|PIC_TIMER_COUNT_0
argument_list|(
name|timer
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|tu2
operator|<<
literal|32
operator|)
operator||
name|tl
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RMI_PIC_H_ */
end_comment

end_unit

