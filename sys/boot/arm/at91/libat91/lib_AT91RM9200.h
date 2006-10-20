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
if|if
condition|(
name|periphAEnable
condition|)
name|pPio
operator|->
name|PIO_ASR
operator|=
name|periphAEnable
expr_stmt|;
if|if
condition|(
name|periphBEnable
condition|)
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

