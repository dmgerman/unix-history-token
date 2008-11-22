begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This software is derived from software provide by Kwikbyte who specifically  * disclaimed copyright on the code.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBAT91RM9200_H
end_ifndef

begin_define
define|#
directive|define
name|__LIBAT91RM9200_H
end_define

begin_include
include|#
directive|include
file|"at91rm9200.h"
end_include

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PMC_EnablePeriphClock
end_comment

begin_comment
comment|//* \brief Enable peripheral clock
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PMC_EnablePeriphClock
parameter_list|(
name|AT91PS_PMC
name|pPMC
parameter_list|,
comment|// \arg pointer to PMC controller
name|unsigned
name|int
name|periphIds
parameter_list|)
comment|// \arg IDs of peripherals to enable
block|{
name|pPMC
operator|->
name|PMC_PCER
operator|=
name|periphIds
expr_stmt|;
block|}
end_function

begin_comment
comment|/* *****************************************************************************                 SOFTWARE API FOR PIO    ***************************************************************************** */
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PIO_CfgPeriph
end_comment

begin_comment
comment|//* \brief Enable pins to be drived by peripheral
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PIO_CfgPeriph
parameter_list|(
name|AT91PS_PIO
name|pPio
parameter_list|,
comment|// \arg pointer to a PIO controller
name|unsigned
name|int
name|periphAEnable
parameter_list|,
comment|// \arg PERIPH A to enable
name|unsigned
name|int
name|periphBEnable
parameter_list|)
comment|// \arg PERIPH B to enable
block|{
name|pPio
operator|->
name|PIO_ASR
operator|=
name|periphAEnable
expr_stmt|;
name|pPio
operator|->
name|PIO_BSR
operator|=
name|periphBEnable
expr_stmt|;
name|pPio
operator|->
name|PIO_PDR
operator|=
operator|(
name|periphAEnable
operator||
name|periphBEnable
operator|)
expr_stmt|;
comment|// Set in Periph mode
block|}
end_function

begin_comment
comment|/* *****************************************************************************                 SOFTWARE API FOR MCI    ***************************************************************************** */
end_comment

begin_comment
comment|//* Classic MCI Mode Register Configuration with PDC mode enabled and MCK = MCI Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_MR_PDCMODE
value|(AT91C_MCI_CLKDIV |\                                 AT91C_MCI_PWSDIV |\                                 (AT91C_MCI_PWSDIV<<1) |\                                 AT91C_MCI_PDCMODE)
end_define

begin_comment
comment|//* Classic MCI Data Timeout Register Configuration with 1048576 MCK cycles between 2 data transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOR_1MEGA_CYCLES
value|(AT91C_MCI_DTOCYC | AT91C_MCI_DTOMUL)
end_define

begin_comment
comment|//* Classic MCI SDCard Register Configuration with 1-bit data bus on slot A
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_MMC_SLOTA
value|(AT91C_MCI_SCDSEL& 0x0)
end_define

begin_comment
comment|//* Classic MCI SDCard Register Configuration with 1-bit data bus on slot B
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_MMC_SLOTB
value|(AT91C_MCI_SCDSEL)
end_define

begin_comment
comment|//* Classic MCI SDCard Register Configuration with 4-bit data bus on slot A
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SDCARD_4BITS_SLOTA
value|( (AT91C_MCI_SCDSEL& 0x0) | AT91C_MCI_SCDBUS )
end_define

begin_comment
comment|//* Classic MCI SDCard Register Configuration with 4-bit data bus on slot B
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SDCARD_4BITS_SLOTB
value|(AT91C_MCI_SCDSEL | AT91C_MCI_SCDBUS)
end_define

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_Configure
end_comment

begin_comment
comment|//* \brief Configure the MCI
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_MCI_Configure
parameter_list|(
name|AT91PS_MCI
name|pMCI
parameter_list|,
comment|// \arg pointer to a MCI controller
name|unsigned
name|int
name|DTOR_register
parameter_list|,
comment|// \arg Data Timeout Register to be programmed
name|unsigned
name|int
name|MR_register
parameter_list|,
comment|// \arg Mode Register to be programmed
name|unsigned
name|int
name|SDCR_register
parameter_list|)
comment|// \arg SDCard Register to be programmed
block|{
comment|//* Reset the MCI
name|pMCI
operator|->
name|MCI_CR
operator|=
name|AT91C_MCI_MCIEN
operator||
name|AT91C_MCI_PWSEN
expr_stmt|;
comment|//* Disable all the interrupts
name|pMCI
operator|->
name|MCI_IDR
operator|=
literal|0xFFFFFFFF
expr_stmt|;
comment|//* Set the Data Timeout Register
name|pMCI
operator|->
name|MCI_DTOR
operator|=
name|DTOR_register
expr_stmt|;
comment|//* Set the Mode Register
name|pMCI
operator|->
name|MCI_MR
operator|=
name|MR_register
expr_stmt|;
comment|//* Set the SDCard Register
name|pMCI
operator|->
name|MCI_SDCR
operator|=
name|SDCR_register
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_EnableIt
end_comment

begin_comment
comment|//* \brief Enable MCI IT
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_MCI_EnableIt
parameter_list|(
name|AT91PS_MCI
name|pMCI
parameter_list|,
comment|// \arg pointer to a MCI controller
name|unsigned
name|int
name|flag
parameter_list|)
comment|// \arg IT to be enabled
block|{
comment|//* Write to the IER register
name|pMCI
operator|->
name|MCI_IER
operator|=
name|flag
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_DisableIt
end_comment

begin_comment
comment|//* \brief Disable MCI IT
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_MCI_DisableIt
parameter_list|(
name|AT91PS_MCI
name|pMCI
parameter_list|,
comment|// \arg pointer to a MCI controller
name|unsigned
name|int
name|flag
parameter_list|)
comment|// \arg IT to be disabled
block|{
comment|//* Write to the IDR register
name|pMCI
operator|->
name|MCI_IDR
operator|=
name|flag
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_Enable_Interface
end_comment

begin_comment
comment|//* \brief Enable the MCI Interface
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_MCI_Enable_Interface
parameter_list|(
name|AT91PS_MCI
name|pMCI
parameter_list|)
comment|// \arg pointer to a MCI controller
block|{
comment|//* Enable the MCI
name|pMCI
operator|->
name|MCI_CR
operator|=
name|AT91C_MCI_MCIEN
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_Disable_Interface
end_comment

begin_comment
comment|//* \brief Disable the MCI Interface
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_MCI_Disable_Interface
parameter_list|(
name|AT91PS_MCI
name|pMCI
parameter_list|)
comment|// \arg pointer to a MCI controller
block|{
comment|//* Disable the MCI
name|pMCI
operator|->
name|MCI_CR
operator|=
name|AT91C_MCI_MCIDIS
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_Cfg_ModeRegister
end_comment

begin_comment
comment|//* \brief Configure the MCI Mode Register
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_MCI_Cfg_ModeRegister
parameter_list|(
name|AT91PS_MCI
name|pMCI
parameter_list|,
comment|// \arg pointer to a MCI controller
name|unsigned
name|int
name|mode_register
parameter_list|)
comment|// \arg value to set in the mode register
block|{
comment|//* Configure the MCI MR
name|pMCI
operator|->
name|MCI_MR
operator|=
name|mode_register
expr_stmt|;
block|}
end_function

begin_comment
comment|/* *****************************************************************************                 SOFTWARE API FOR AIC    ***************************************************************************** */
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_BRANCH_OPCODE
value|((void (*) ()) 0xE51FFF20)
end_define

begin_comment
comment|// ldr, pc, [pc, #-&F20]
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_ConfigureIt
end_comment

begin_comment
comment|//* \brief Interrupt Handler Initialization
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|AT91F_AIC_ConfigureIt
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|,
comment|// \arg pointer to the AIC registers
name|unsigned
name|int
name|irq_id
parameter_list|,
comment|// \arg interrupt number to initialize
name|unsigned
name|int
name|priority
parameter_list|,
comment|// \arg priority to give to the interrupt
name|unsigned
name|int
name|src_type
parameter_list|,
comment|// \arg activation and sense of activation
name|void
function_decl|(
modifier|*
name|newHandler
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
comment|// \arg address of the interrupt handler
block|{
name|unsigned
name|int
name|oldHandler
decl_stmt|;
name|unsigned
name|int
name|mask
decl_stmt|;
name|oldHandler
operator|=
name|pAic
operator|->
name|AIC_SVR
index|[
name|irq_id
index|]
expr_stmt|;
name|mask
operator|=
literal|0x1
operator|<<
name|irq_id
expr_stmt|;
comment|//* Disable the interrupt on the interrupt controller
name|pAic
operator|->
name|AIC_IDCR
operator|=
name|mask
expr_stmt|;
comment|//* Save the interrupt handler routine pointer and the interrupt priority
name|pAic
operator|->
name|AIC_SVR
index|[
name|irq_id
index|]
operator|=
operator|(
name|unsigned
name|int
operator|)
name|newHandler
expr_stmt|;
comment|//* Store the Source Mode Register
name|pAic
operator|->
name|AIC_SMR
index|[
name|irq_id
index|]
operator|=
name|src_type
operator||
name|priority
expr_stmt|;
comment|//* Clear the interrupt on the interrupt controller
name|pAic
operator|->
name|AIC_ICCR
operator|=
name|mask
expr_stmt|;
return|return
name|oldHandler
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_EnableIt
end_comment

begin_comment
comment|//* \brief Enable corresponding IT number
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_AIC_EnableIt
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|,
comment|// \arg pointer to the AIC registers
name|unsigned
name|int
name|irq_id
parameter_list|)
comment|// \arg interrupt number to initialize
block|{
comment|//* Enable the interrupt on the interrupt controller
name|pAic
operator|->
name|AIC_IECR
operator|=
literal|0x1
operator|<<
name|irq_id
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_DisableIt
end_comment

begin_comment
comment|//* \brief Disable corresponding IT number
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_AIC_DisableIt
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|,
comment|// \arg pointer to the AIC registers
name|unsigned
name|int
name|irq_id
parameter_list|)
comment|// \arg interrupt number to initialize
block|{
name|unsigned
name|int
name|mask
init|=
literal|0x1
operator|<<
name|irq_id
decl_stmt|;
comment|//* Disable the interrupt on the interrupt controller
name|pAic
operator|->
name|AIC_IDCR
operator|=
name|mask
expr_stmt|;
comment|//* Clear the interrupt on the Interrupt Controller ( if one is pending )
name|pAic
operator|->
name|AIC_ICCR
operator|=
name|mask
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_ClearIt
end_comment

begin_comment
comment|//* \brief Clear corresponding IT number
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_AIC_ClearIt
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|,
comment|// \arg pointer to the AIC registers
name|unsigned
name|int
name|irq_id
parameter_list|)
comment|// \arg interrupt number to initialize
block|{
comment|//* Clear the interrupt on the Interrupt Controller ( if one is pending )
name|pAic
operator|->
name|AIC_ICCR
operator|=
operator|(
literal|0x1
operator|<<
name|irq_id
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_AcknowledgeIt
end_comment

begin_comment
comment|//* \brief Acknowledge corresponding IT number
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_AIC_AcknowledgeIt
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|)
comment|// \arg pointer to the AIC registers
block|{
name|pAic
operator|->
name|AIC_EOICR
operator|=
name|pAic
operator|->
name|AIC_EOICR
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_SetExceptionVector
end_comment

begin_comment
comment|//* \brief Configure vector handler
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|AT91F_AIC_SetExceptionVector
parameter_list|(
name|unsigned
name|int
modifier|*
name|pVector
parameter_list|,
comment|// \arg pointer to the AIC registers
name|void
function_decl|(
modifier|*
name|Handler
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
comment|// \arg Interrupt Handler
block|{
name|unsigned
name|int
name|oldVector
init|=
operator|*
name|pVector
decl_stmt|;
if|if
condition|(
operator|(
name|unsigned
name|int
operator|)
name|Handler
operator|==
operator|(
name|unsigned
name|int
operator|)
name|AT91C_AIC_BRANCH_OPCODE
condition|)
operator|*
name|pVector
operator|=
operator|(
name|unsigned
name|int
operator|)
name|AT91C_AIC_BRANCH_OPCODE
expr_stmt|;
else|else
operator|*
name|pVector
operator|=
operator|(
operator|(
operator|(
operator|(
operator|(
name|unsigned
name|int
operator|)
name|Handler
operator|)
operator|-
operator|(
operator|(
name|unsigned
name|int
operator|)
name|pVector
operator|)
operator|-
literal|0x8
operator|)
operator|>>
literal|2
operator|)
operator|&
literal|0x00FFFFFF
operator|)
operator||
literal|0xEA000000
expr_stmt|;
return|return
name|oldVector
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_Trig
end_comment

begin_comment
comment|//* \brief Trig an IT
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_AIC_Trig
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|,
comment|// \arg pointer to the AIC registers
name|unsigned
name|int
name|irq_id
parameter_list|)
comment|// \arg interrupt number
block|{
name|pAic
operator|->
name|AIC_ISCR
operator|=
operator|(
literal|0x1
operator|<<
name|irq_id
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_IsActive
end_comment

begin_comment
comment|//* \brief Test if an IT is active
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|AT91F_AIC_IsActive
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|,
comment|// \arg pointer to the AIC registers
name|unsigned
name|int
name|irq_id
parameter_list|)
comment|// \arg Interrupt Number
block|{
return|return
operator|(
name|pAic
operator|->
name|AIC_ISR
operator|&
operator|(
literal|0x1
operator|<<
name|irq_id
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_IsPending
end_comment

begin_comment
comment|//* \brief Test if an IT is pending
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|AT91F_AIC_IsPending
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|,
comment|// \arg pointer to the AIC registers
name|unsigned
name|int
name|irq_id
parameter_list|)
comment|// \arg Interrupt Number
block|{
return|return
operator|(
name|pAic
operator|->
name|AIC_IPR
operator|&
operator|(
literal|0x1
operator|<<
name|irq_id
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_AIC_Open
end_comment

begin_comment
comment|//* \brief Set exception vectors and AIC registers to default values
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_AIC_Open
parameter_list|(
name|AT91PS_AIC
name|pAic
parameter_list|,
comment|// \arg pointer to the AIC registers
name|void
function_decl|(
modifier|*
name|IrqHandler
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
comment|// \arg Default IRQ vector exception
name|void
function_decl|(
modifier|*
name|FiqHandler
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
comment|// \arg Default FIQ vector exception
name|void
function_decl|(
modifier|*
name|DefaultHandler
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
comment|// \arg Default Handler set in ISR
name|void
function_decl|(
modifier|*
name|SpuriousHandler
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
comment|// \arg Default Spurious Handler
name|unsigned
name|int
name|protectMode
parameter_list|)
comment|// \arg Debug Control Register
block|{
name|int
name|i
decl_stmt|;
comment|// Disable all interrupts and set IVR to the default handler
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
operator|++
name|i
control|)
block|{
name|AT91F_AIC_DisableIt
argument_list|(
name|pAic
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|AT91F_AIC_ConfigureIt
argument_list|(
name|pAic
argument_list|,
name|i
argument_list|,
name|AT91C_AIC_PRIOR_LOWEST
argument_list|,
name|AT91C_AIC_SRCTYPE_INT_LEVEL_SENSITIVE
argument_list|,
name|DefaultHandler
argument_list|)
expr_stmt|;
block|}
comment|// Set the IRQ exception vector
name|AT91F_AIC_SetExceptionVector
argument_list|(
operator|(
name|unsigned
name|int
operator|*
operator|)
literal|0x18
argument_list|,
name|IrqHandler
argument_list|)
expr_stmt|;
comment|// Set the Fast Interrupt exception vector
name|AT91F_AIC_SetExceptionVector
argument_list|(
operator|(
name|unsigned
name|int
operator|*
operator|)
literal|0x1C
argument_list|,
name|FiqHandler
argument_list|)
expr_stmt|;
name|pAic
operator|->
name|AIC_SPU
operator|=
operator|(
name|unsigned
name|int
operator|)
name|SpuriousHandler
expr_stmt|;
name|pAic
operator|->
name|AIC_DCR
operator|=
name|protectMode
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_CfgPMC
end_comment

begin_comment
comment|//* \brief Enable Peripheral clock in PMC for  MCI
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_MCI_CfgPMC
parameter_list|(
name|void
parameter_list|)
block|{
name|AT91F_PMC_EnablePeriphClock
argument_list|(
name|AT91C_BASE_PMC
argument_list|,
comment|// PIO controller base address
operator|(
operator|(
name|unsigned
name|int
operator|)
literal|1
operator|<<
name|AT91C_ID_MCI
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_CfgPIO
end_comment

begin_comment
comment|//* \brief Configure PIO controllers to drive MCI signals
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_MCI_CfgPIO
parameter_list|(
name|void
parameter_list|)
block|{
comment|// Configure PIO controllers to periph mode
name|AT91F_PIO_CfgPeriph
argument_list|(
name|AT91C_BASE_PIOA
argument_list|,
comment|// PIO controller base address
operator|(
operator|(
name|unsigned
name|int
operator|)
name|AT91C_PA28_MCCDA
operator|)
operator||
operator|(
operator|(
name|unsigned
name|int
operator|)
name|AT91C_PA29_MCDA0
operator|)
operator||
operator|(
operator|(
name|unsigned
name|int
operator|)
name|AT91C_PA27_MCCK
operator|)
argument_list|,
comment|// Peripheral A
literal|0
argument_list|)
expr_stmt|;
comment|// Peripheral B
comment|// Configure PIO controllers to periph mode
name|AT91F_PIO_CfgPeriph
argument_list|(
name|AT91C_BASE_PIOB
argument_list|,
comment|// PIO controller base address
literal|0
argument_list|,
comment|// Peripheral A
operator|(
operator|(
name|unsigned
name|int
operator|)
name|AT91C_PB5_MCDA3
operator|)
operator||
operator|(
operator|(
name|unsigned
name|int
operator|)
name|AT91C_PB3_MCDA1
operator|)
operator||
operator|(
operator|(
name|unsigned
name|int
operator|)
name|AT91C_PB4_MCDA2
operator|)
argument_list|)
expr_stmt|;
comment|// Peripheral B
block|}
end_function

begin_comment
comment|/* *****************************************************************************                 SOFTWARE API FOR PDC    ***************************************************************************** */
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_SetNextRx
end_comment

begin_comment
comment|//* \brief Set the next receive transfer descriptor
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_SetNextRx
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|,
comment|// \arg pointer to a PDC controller
name|char
modifier|*
name|address
parameter_list|,
comment|// \arg address to the next bloc to be received
name|unsigned
name|int
name|bytes
parameter_list|)
comment|// \arg number of bytes to be received
block|{
name|pPDC
operator|->
name|PDC_RNPR
operator|=
operator|(
name|unsigned
name|int
operator|)
name|address
expr_stmt|;
name|pPDC
operator|->
name|PDC_RNCR
operator|=
name|bytes
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_SetNextTx
end_comment

begin_comment
comment|//* \brief Set the next transmit transfer descriptor
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_SetNextTx
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|,
comment|// \arg pointer to a PDC controller
name|char
modifier|*
name|address
parameter_list|,
comment|// \arg address to the next bloc to be transmitted
name|unsigned
name|int
name|bytes
parameter_list|)
comment|// \arg number of bytes to be transmitted
block|{
name|pPDC
operator|->
name|PDC_TNPR
operator|=
operator|(
name|unsigned
name|int
operator|)
name|address
expr_stmt|;
name|pPDC
operator|->
name|PDC_TNCR
operator|=
name|bytes
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_SetRx
end_comment

begin_comment
comment|//* \brief Set the receive transfer descriptor
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_SetRx
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|,
comment|// \arg pointer to a PDC controller
name|char
modifier|*
name|address
parameter_list|,
comment|// \arg address to the next bloc to be received
name|unsigned
name|int
name|bytes
parameter_list|)
comment|// \arg number of bytes to be received
block|{
name|pPDC
operator|->
name|PDC_RPR
operator|=
operator|(
name|unsigned
name|int
operator|)
name|address
expr_stmt|;
name|pPDC
operator|->
name|PDC_RCR
operator|=
name|bytes
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_SetTx
end_comment

begin_comment
comment|//* \brief Set the transmit transfer descriptor
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_SetTx
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|,
comment|// \arg pointer to a PDC controller
name|char
modifier|*
name|address
parameter_list|,
comment|// \arg address to the next bloc to be transmitted
name|unsigned
name|int
name|bytes
parameter_list|)
comment|// \arg number of bytes to be transmitted
block|{
name|pPDC
operator|->
name|PDC_TPR
operator|=
operator|(
name|unsigned
name|int
operator|)
name|address
expr_stmt|;
name|pPDC
operator|->
name|PDC_TCR
operator|=
name|bytes
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_EnableTx
end_comment

begin_comment
comment|//* \brief Enable transmit
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_EnableTx
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
name|pPDC
operator|->
name|PDC_PTCR
operator|=
name|AT91C_PDC_TXTEN
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_EnableRx
end_comment

begin_comment
comment|//* \brief Enable receive
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_EnableRx
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
name|pPDC
operator|->
name|PDC_PTCR
operator|=
name|AT91C_PDC_RXTEN
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_DisableTx
end_comment

begin_comment
comment|//* \brief Disable transmit
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_DisableTx
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
name|pPDC
operator|->
name|PDC_PTCR
operator|=
name|AT91C_PDC_TXTDIS
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_DisableRx
end_comment

begin_comment
comment|//* \brief Disable receive
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_DisableRx
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
name|pPDC
operator|->
name|PDC_PTCR
operator|=
name|AT91C_PDC_RXTDIS
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_IsTxEmpty
end_comment

begin_comment
comment|//* \brief Test if the current transfer descriptor has been sent
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|AT91F_PDC_IsTxEmpty
parameter_list|(
comment|// \return return 1 if transfer is complete
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
return|return
operator|!
operator|(
name|pPDC
operator|->
name|PDC_TCR
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_IsNextTxEmpty
end_comment

begin_comment
comment|//* \brief Test if the next transfer descriptor has been moved to the current td
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|AT91F_PDC_IsNextTxEmpty
parameter_list|(
comment|// \return return 1 if transfer is complete
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
return|return
operator|!
operator|(
name|pPDC
operator|->
name|PDC_TNCR
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_IsRxEmpty
end_comment

begin_comment
comment|//* \brief Test if the current transfer descriptor has been filled
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|AT91F_PDC_IsRxEmpty
parameter_list|(
comment|// \return return 1 if transfer is complete
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
return|return
operator|!
operator|(
name|pPDC
operator|->
name|PDC_RCR
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_IsNextRxEmpty
end_comment

begin_comment
comment|//* \brief Test if the next transfer descriptor has been moved to the current td
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|AT91F_PDC_IsNextRxEmpty
parameter_list|(
comment|// \return return 1 if transfer is complete
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
return|return
operator|!
operator|(
name|pPDC
operator|->
name|PDC_RNCR
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_Open
end_comment

begin_comment
comment|//* \brief Open PDC: disable TX and RX reset transfer descriptors, re-enable RX and TX
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_Open
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
comment|//* Disable the RX and TX PDC transfer requests
name|AT91F_PDC_DisableRx
argument_list|(
name|pPDC
argument_list|)
expr_stmt|;
name|AT91F_PDC_DisableTx
argument_list|(
name|pPDC
argument_list|)
expr_stmt|;
comment|//* Reset all Counter register Next buffer first
name|AT91F_PDC_SetNextTx
argument_list|(
name|pPDC
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|AT91F_PDC_SetNextRx
argument_list|(
name|pPDC
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|AT91F_PDC_SetTx
argument_list|(
name|pPDC
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|AT91F_PDC_SetRx
argument_list|(
name|pPDC
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|//* Enable the RX and TX PDC transfer requests
name|AT91F_PDC_EnableRx
argument_list|(
name|pPDC
argument_list|)
expr_stmt|;
name|AT91F_PDC_EnableTx
argument_list|(
name|pPDC
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_Close
end_comment

begin_comment
comment|//* \brief Close PDC: disable TX and RX reset transfer descriptors
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|AT91F_PDC_Close
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|)
comment|// \arg pointer to a PDC controller
block|{
comment|//* Disable the RX and TX PDC transfer requests
name|AT91F_PDC_DisableRx
argument_list|(
name|pPDC
argument_list|)
expr_stmt|;
name|AT91F_PDC_DisableTx
argument_list|(
name|pPDC
argument_list|)
expr_stmt|;
comment|//* Reset all Counter register Next buffer first
name|AT91F_PDC_SetNextTx
argument_list|(
name|pPDC
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|AT91F_PDC_SetNextRx
argument_list|(
name|pPDC
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|AT91F_PDC_SetTx
argument_list|(
name|pPDC
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|AT91F_PDC_SetRx
argument_list|(
name|pPDC
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_SendFrame
end_comment

begin_comment
comment|//* \brief Close PDC: disable TX and RX reset transfer descriptors
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|AT91F_PDC_SendFrame
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|,
name|char
modifier|*
name|pBuffer
parameter_list|,
name|unsigned
name|int
name|szBuffer
parameter_list|,
name|char
modifier|*
name|pNextBuffer
parameter_list|,
name|unsigned
name|int
name|szNextBuffer
parameter_list|)
block|{
if|if
condition|(
name|AT91F_PDC_IsTxEmpty
argument_list|(
name|pPDC
argument_list|)
condition|)
block|{
comment|//* Buffer and next buffer can be initialized
name|AT91F_PDC_SetTx
argument_list|(
name|pPDC
argument_list|,
name|pBuffer
argument_list|,
name|szBuffer
argument_list|)
expr_stmt|;
name|AT91F_PDC_SetNextTx
argument_list|(
name|pPDC
argument_list|,
name|pNextBuffer
argument_list|,
name|szNextBuffer
argument_list|)
expr_stmt|;
return|return
literal|2
return|;
block|}
elseif|else
if|if
condition|(
name|AT91F_PDC_IsNextTxEmpty
argument_list|(
name|pPDC
argument_list|)
condition|)
block|{
comment|//* Only one buffer can be initialized
name|AT91F_PDC_SetNextTx
argument_list|(
name|pPDC
argument_list|,
name|pBuffer
argument_list|,
name|szBuffer
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
else|else
block|{
comment|//* All buffer are in use...
return|return
literal|0
return|;
block|}
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_PDC_ReceiveFrame
end_comment

begin_comment
comment|//* \brief Close PDC: disable TX and RX reset transfer descriptors
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|AT91F_PDC_ReceiveFrame
parameter_list|(
name|AT91PS_PDC
name|pPDC
parameter_list|,
name|char
modifier|*
name|pBuffer
parameter_list|,
name|unsigned
name|int
name|szBuffer
parameter_list|,
name|char
modifier|*
name|pNextBuffer
parameter_list|,
name|unsigned
name|int
name|szNextBuffer
parameter_list|)
block|{
if|if
condition|(
name|AT91F_PDC_IsRxEmpty
argument_list|(
name|pPDC
argument_list|)
condition|)
block|{
comment|//* Buffer and next buffer can be initialized
name|AT91F_PDC_SetRx
argument_list|(
name|pPDC
argument_list|,
name|pBuffer
argument_list|,
name|szBuffer
argument_list|)
expr_stmt|;
name|AT91F_PDC_SetNextRx
argument_list|(
name|pPDC
argument_list|,
name|pNextBuffer
argument_list|,
name|szNextBuffer
argument_list|)
expr_stmt|;
return|return
literal|2
return|;
block|}
elseif|else
if|if
condition|(
name|AT91F_PDC_IsNextRxEmpty
argument_list|(
name|pPDC
argument_list|)
condition|)
block|{
comment|//* Only one buffer can be initialized
name|AT91F_PDC_SetNextRx
argument_list|(
name|pPDC
argument_list|,
name|pBuffer
argument_list|,
name|szBuffer
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
else|else
block|{
comment|//* All buffer are in use...
return|return
literal|0
return|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

