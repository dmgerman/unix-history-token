begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to the Mips interrupts.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_INTERRUPT_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_INTERRUPT_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * Enumeration of Interrupt numbers  */
typedef|typedef
enum|enum
block|{
comment|/* 0 - 7 represent the 8 MIPS standard interrupt sources */
name|CVMX_IRQ_SW0
init|=
literal|0
block|,
name|CVMX_IRQ_SW1
block|,
name|CVMX_IRQ_MIPS2
block|,
name|CVMX_IRQ_MIPS3
block|,
name|CVMX_IRQ_MIPS4
block|,
name|CVMX_IRQ_MIPS5
block|,
name|CVMX_IRQ_MIPS6
block|,
name|CVMX_IRQ_MIPS7
block|,
comment|/* 64 WORKQ interrupts. */
name|CVMX_IRQ_WORKQ0
block|,
comment|/* 16 GPIO interrupts. */
name|CVMX_IRQ_GPIO0
init|=
name|CVMX_IRQ_WORKQ0
operator|+
literal|64
block|,
comment|/* 4  MBOX interrupts. */
name|CVMX_IRQ_MBOX0
init|=
name|CVMX_IRQ_GPIO0
operator|+
literal|16
block|,
comment|/* 3  UART interrupts. */
name|CVMX_IRQ_UART0
init|=
name|CVMX_IRQ_MBOX0
operator|+
literal|4
block|,
name|CVMX_IRQ_PCI_INT0
init|=
name|CVMX_IRQ_UART0
operator|+
literal|3
block|,
name|CVMX_IRQ_PCI_INT1
block|,
name|CVMX_IRQ_PCI_INT2
block|,
name|CVMX_IRQ_PCI_INT3
block|,
name|CVMX_IRQ_PCI_MSI0
block|,
name|CVMX_IRQ_PCI_MSI1
block|,
name|CVMX_IRQ_PCI_MSI2
block|,
name|CVMX_IRQ_PCI_MSI3
block|,
comment|/* 2 TWSI interrupts */
name|CVMX_IRQ_TWSI0
block|,
name|CVMX_IRQ_RML
init|=
name|CVMX_IRQ_TWSI0
operator|+
literal|2
block|,
comment|/* 4 TRACE interrupts added in CN68XX */
name|CVMX_IRQ_TRACE0
block|,
comment|/* 5 GMX_DRP interrupts added in CN68XX */
name|CVMX_IRQ_GMX_DRP0
init|=
name|CVMX_IRQ_TRACE0
operator|+
literal|4
block|,
name|CVMX_IRQ_GMX_DRP1
block|,
comment|/* Doesn't apply on CN52XX or CN63XX */
name|CVMX_IRQ_IPD_DRP
init|=
name|CVMX_IRQ_GMX_DRP0
operator|+
literal|5
block|,
name|CVMX_IRQ_KEY_ZERO
block|,
comment|/* Doesn't apply on CN52XX or CN63XX */
comment|/* 4 TIMER interrupts. */
name|CVMX_IRQ_TIMER0
block|,
comment|/* 2 USB interrupts. */
name|CVMX_IRQ_USB0
init|=
name|CVMX_IRQ_TIMER0
operator|+
literal|4
block|,
comment|/* Doesn't apply on CN38XX or CN58XX */
name|CVMX_IRQ_PCM
init|=
name|CVMX_IRQ_USB0
operator|+
literal|2
block|,
comment|/* Doesn't apply on CN52XX or CN63XX */
name|CVMX_IRQ_MPI
block|,
comment|/* Doesn't apply on CN52XX or CN63XX */
name|CVMX_IRQ_POWIQ
block|,
comment|/* Added in CN56XX */
name|CVMX_IRQ_IPDPPTHR
block|,
comment|/* Added in CN56XX */
comment|/* 2 MII interrupts. */
name|CVMX_IRQ_MII0
block|,
comment|/* Added in CN56XX */
name|CVMX_IRQ_BOOTDMA
init|=
name|CVMX_IRQ_MII0
operator|+
literal|2
block|,
comment|/* Added in CN56XX */
comment|/* 32 WDOG interrupts. */
name|CVMX_IRQ_WDOG0
block|,
name|CVMX_IRQ_NAND
init|=
name|CVMX_IRQ_WDOG0
operator|+
literal|32
block|,
comment|/* Added in CN52XX */
name|CVMX_IRQ_MIO
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_IOB
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_FPA
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_POW
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_L2C
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_IPD
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_PIP
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_PKO
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_ZIP
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_TIM
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_RAD
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_KEY
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_DFA
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_USBCTL
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_SLI
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_DPI
block|,
comment|/* Added in CN63XX */
comment|/* 5 AGX interrupts added in CN68XX. */
name|CVMX_IRQ_AGX0
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_AGL
init|=
name|CVMX_IRQ_AGX0
operator|+
literal|5
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_PTP
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_PEM0
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_PEM1
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_SRIO0
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_SRIO1
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_LMC0
block|,
comment|/* Added in CN63XX */
comment|/* 4 LMC interrupts added in CN68XX. */
name|CVMX_IRQ_DFM
init|=
name|CVMX_IRQ_LMC0
operator|+
literal|4
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_RST
block|,
comment|/* Added in CN63XX */
name|CVMX_IRQ_ILK
block|,
comment|/* Added for CN68XX */
name|CVMX_IRQ_SRIO2
block|,
comment|/* Added in CN66XX */
name|CVMX_IRQ_DPI_DMA
block|,
comment|/* Added in CN61XX */
comment|/* 6 addition timers added in CN61XX */
name|CVMX_IRQ_TIMER4
block|,
comment|/* Added in CN61XX */
name|CVMX_IRQ_MAX
init|=
name|CVMX_IRQ_TIMER4
operator|+
literal|6
comment|/* One greater than the last valid number.*/
block|}
name|cvmx_irq_t
typedef|;
comment|/**  * Function prototype for the exception handler  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|cvmx_interrupt_exception_t
function_decl|)
parameter_list|(
name|uint64_t
modifier|*
name|registers
parameter_list|)
function_decl|;
comment|/**  * Function prototype for interrupt handlers  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|cvmx_interrupt_func_t
function_decl|)
parameter_list|(
name|int
name|irq_number
parameter_list|,
name|uint64_t
modifier|*
name|registers
parameter_list|,
name|void
modifier|*
name|user_arg
parameter_list|)
function_decl|;
comment|/**  * Register an interrupt handler for the specified interrupt number.  *  * @param irq_number Interrupt number to register for (0-135)  * @param func       Function to call on interrupt.  * @param user_arg   User data to pass to the interrupt handler  */
name|void
name|cvmx_interrupt_register
parameter_list|(
name|int
name|irq_number
parameter_list|,
name|cvmx_interrupt_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_arg
parameter_list|)
function_decl|;
comment|/**  * Set the exception handler for all non interrupt sources.  *  * @param handler New exception handler  * @return Old exception handler  */
name|cvmx_interrupt_exception_t
name|cvmx_interrupt_set_exception
parameter_list|(
name|cvmx_interrupt_exception_t
name|handler
parameter_list|)
function_decl|;
comment|/**  * Masks a given interrupt number.  *  * @param irq_number interrupt number to mask  */
specifier|extern
name|void
function_decl|(
modifier|*
name|cvmx_interrupt_mask_irq
function_decl|)
parameter_list|(
name|int
name|irq_number
parameter_list|)
function_decl|;
comment|/**  * Unmasks a given interrupt number  *  * @param irq_number interrupt number to unmask  */
specifier|extern
name|void
function_decl|(
modifier|*
name|cvmx_interrupt_unmask_irq
function_decl|)
parameter_list|(
name|int
name|irq_number
parameter_list|)
function_decl|;
comment|/* Disable interrupts by clearing bit 0 of the COP0 status register, ** and return the previous contents of the status register. ** Note: this is only used to track interrupt status. */
specifier|static
specifier|inline
name|uint32_t
name|cvmx_interrupt_disable_save
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|flags
decl_stmt|;
asm|asm
specifier|volatile
asm|(         "DI   %[flags]\n"         : [flags]"=r" (flags));
return|return
operator|(
name|flags
operator|)
return|;
block|}
comment|/* Restore the contents of the cop0 status register.  Used with ** cvmx_interrupt_disable_save to allow recursive interrupt disabling */
specifier|static
specifier|inline
name|void
name|cvmx_interrupt_restore
parameter_list|(
name|uint32_t
name|flags
parameter_list|)
block|{
comment|/* If flags value indicates interrupts should be enabled, then enable them */
if|if
condition|(
name|flags
operator|&
literal|1
condition|)
block|{
asm|asm
specifier|volatile
asm|(             "EI     \n"             ::);
block|}
block|}
define|#
directive|define
name|cvmx_local_irq_save
parameter_list|(
name|x
parameter_list|)
value|({x = cvmx_interrupt_disable_save();})
define|#
directive|define
name|cvmx_local_irq_restore
parameter_list|(
name|x
parameter_list|)
value|cvmx_interrupt_restore(x)
comment|/**  * Utility function to do interrupt safe printf  */
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
define|#
directive|define
name|cvmx_safe_printf
value|printk
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_USER
argument_list|)
define|#
directive|define
name|cvmx_safe_printf
value|printf
else|#
directive|else
specifier|extern
name|void
name|cvmx_safe_printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PRINT_ERROR
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
value|cvmx_safe_printf("ERROR " format, ##__VA_ARGS__)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

