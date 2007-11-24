begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This software is derived from software provide by Kwikbyte who specifically  * disclaimed copyright on the code.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* The software is delivered "AS IS" without warranty or condition of any
end_comment

begin_comment
comment|//* kind, either express, implied or statutory. This includes without
end_comment

begin_comment
comment|//* limitation any warranty or condition with respect to merchantability or
end_comment

begin_comment
comment|//* fitness for any particular purpose, or against the infringements of
end_comment

begin_comment
comment|//* intellectual property rights of others.
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* File Name           : mci_device.c
end_comment

begin_comment
comment|//* Object              : TEST DataFlash Functions
end_comment

begin_comment
comment|//* Creation            : FB   26/11/2002
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_include
include|#
directive|include
file|"at91rm9200.h"
end_include

begin_include
include|#
directive|include
file|"lib_AT91RM9200.h"
end_include

begin_include
include|#
directive|include
file|"mci_device.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_SendCommand
end_comment

begin_comment
comment|//* \brief Generic function to send a command to the MMC or SDCard
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SendCommand
parameter_list|(
name|unsigned
name|int
name|Cmd
parameter_list|,
name|unsigned
name|int
name|Arg
parameter_list|)
block|{
name|unsigned
name|int
name|error
decl_stmt|,
name|status
decl_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_ARGR
operator|=
name|Arg
expr_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_CMDR
operator|=
name|Cmd
expr_stmt|;
comment|// wait for CMDRDY Status flag to read the response
do|do
block|{
name|status
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
expr_stmt|;
block|}
do|while
condition|(
operator|!
operator|(
name|status
operator|&
name|AT91C_MCI_CMDRDY
operator|)
condition|)
do|;
comment|// Test error  ==> if crc error and response R3 ==> don't check error
name|error
operator|=
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
operator|)
operator|&
name|AT91C_MCI_SR_ERROR
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
comment|// if the command is SEND_OP_COND the CRC error flag is always present (cf : R3 response)
if|if
condition|(
operator|(
name|Cmd
operator|!=
name|AT91C_SDCARD_APP_OP_COND_CMD
operator|)
operator|&&
operator|(
name|Cmd
operator|!=
name|AT91C_MMC_SEND_OP_COND_CMD
operator|)
condition|)
return|return
operator|(
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
operator|)
operator|&
name|AT91C_MCI_SR_ERROR
operator|)
return|;
if|if
condition|(
name|error
operator|!=
name|AT91C_MCI_RCRCE
condition|)
return|return
operator|(
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
operator|)
operator|&
name|AT91C_MCI_SR_ERROR
operator|)
return|;
block|}
return|return
name|AT91C_CMD_SEND_OK
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_SDCard_SendAppCommand
end_comment

begin_comment
comment|//* \brief Specific function to send a specific command to the SDCard
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SDCard_SendAppCommand
parameter_list|(
name|AT91PS_MciDevice
name|pMCI_Device
parameter_list|,
name|unsigned
name|int
name|Cmd_App
parameter_list|,
name|unsigned
name|int
name|Arg
parameter_list|)
block|{
name|unsigned
name|int
name|status
decl_stmt|;
comment|// Send the CMD55 for application specific command
name|AT91C_BASE_MCI
operator|->
name|MCI_ARGR
operator|=
operator|(
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Relative_Card_Address
operator|<<
literal|16
operator|)
expr_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_CMDR
operator|=
name|AT91C_APP_CMD
expr_stmt|;
comment|// wait for CMDRDY Status flag to read the response
do|do
block|{
name|status
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
expr_stmt|;
block|}
do|while
condition|(
operator|!
operator|(
name|status
operator|&
name|AT91C_MCI_CMDRDY
operator|)
condition|)
do|;
comment|// if an error occurs
if|if
condition|(
operator|(
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
operator|)
operator|&
name|AT91C_MCI_SR_ERROR
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
operator|)
operator|&
name|AT91C_MCI_SR_ERROR
operator|)
return|;
comment|// check if it is a specific command and then send the command
if|if
condition|(
operator|(
name|Cmd_App
operator|&&
name|AT91C_SDCARD_APP_ALL_CMD
operator|)
operator|==
literal|0
condition|)
return|return
name|AT91C_CMD_SEND_ERROR
return|;
return|return
operator|(
name|AT91F_MCI_SendCommand
argument_list|(
name|Cmd_App
argument_list|,
name|Arg
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_GetStatus
end_comment

begin_comment
comment|//* \brief Addressed card sends its status register
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_GetStatus
parameter_list|(
name|unsigned
name|int
name|relative_card_address
parameter_list|)
block|{
if|if
condition|(
name|AT91F_MCI_SendCommand
argument_list|(
name|AT91C_SEND_STATUS_CMD
argument_list|,
name|relative_card_address
operator|<<
literal|16
argument_list|)
operator|==
name|AT91C_CMD_SEND_OK
condition|)
return|return
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|0
index|]
operator|)
return|;
return|return
name|AT91C_CMD_SEND_ERROR
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_Device_Handler
end_comment

begin_comment
comment|//* \brief MCI C interrupt handler
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
name|void
name|AT91F_MCI_Device_Handler
parameter_list|(
name|AT91PS_MciDevice
name|pMCI_Device
parameter_list|,
name|unsigned
name|int
name|status
parameter_list|)
block|{
comment|// If End of Tx Buffer Empty interrupt occurred
if|if
condition|(
name|pMCI_Device
operator|->
name|pMCI_DeviceDesc
operator|->
name|state
operator|==
name|AT91C_MCI_TX_SINGLE_BLOCK
operator|&&
name|status
operator|&
name|AT91C_MCI_TXBUFE
condition|)
block|{
name|AT91C_BASE_MCI
operator|->
name|MCI_IDR
operator|=
name|AT91C_MCI_TXBUFE
expr_stmt|;
name|AT91C_BASE_PDC_MCI
operator|->
name|PDC_PTCR
operator|=
name|AT91C_PDC_TXTDIS
expr_stmt|;
name|pMCI_Device
operator|->
name|pMCI_DeviceDesc
operator|->
name|state
operator|=
name|AT91C_MCI_IDLE
expr_stmt|;
block|}
comment|// End of if AT91C_MCI_TXBUFF
comment|// If End of Rx Buffer Full interrupt occurred
if|if
condition|(
name|pMCI_Device
operator|->
name|pMCI_DeviceDesc
operator|->
name|state
operator|==
name|AT91C_MCI_RX_SINGLE_BLOCK
operator|&&
name|status
operator|&
name|AT91C_MCI_RXBUFF
condition|)
block|{
name|AT91C_BASE_MCI
operator|->
name|MCI_IDR
operator|=
name|AT91C_MCI_RXBUFF
expr_stmt|;
name|AT91C_BASE_PDC_MCI
operator|->
name|PDC_PTCR
operator|=
name|AT91C_PDC_RXTDIS
expr_stmt|;
name|pMCI_Device
operator|->
name|pMCI_DeviceDesc
operator|->
name|state
operator|=
name|AT91C_MCI_IDLE
expr_stmt|;
block|}
comment|// End of if AT91C_MCI_RXBUFF
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_ReadBlock
end_comment

begin_comment
comment|//* \brief Read an ENTIRE block or PARTIAL block
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_ReadBlock
parameter_list|(
name|AT91PS_MciDevice
name|pMCI_Device
parameter_list|,
name|int
name|src
parameter_list|,
name|unsigned
name|int
modifier|*
name|dataBuffer
parameter_list|,
name|int
name|sizeToRead
parameter_list|)
block|{
comment|///////////////////////////////////////////////////////////////////////
if|if
condition|(
name|pMCI_Device
operator|->
name|pMCI_DeviceDesc
operator|->
name|state
operator|!=
name|AT91C_MCI_IDLE
condition|)
block|{
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"1 state is 0x%x\r\n"
argument_list|,
name|pMCI_Device
operator|->
name|pMCI_DeviceDesc
operator|->
name|state
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|AT91C_READ_ERROR
return|;
block|}
if|if
condition|(
operator|(
name|AT91F_MCI_GetStatus
argument_list|(
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Relative_Card_Address
argument_list|)
operator|&
name|AT91C_SR_READY_FOR_DATA
operator|)
operator|!=
name|AT91C_SR_READY_FOR_DATA
condition|)
block|{
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"2\r\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|AT91C_READ_ERROR
return|;
block|}
if|if
condition|(
operator|(
name|src
operator|+
name|sizeToRead
operator|)
operator|>
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Memory_Capacity
condition|)
block|{
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"3\r\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|AT91C_READ_ERROR
return|;
block|}
comment|// If source does not fit a begin of a block
if|if
condition|(
operator|(
name|src
operator|&
operator|(
operator|(
literal|1
operator|<<
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|READ_BL_LEN
operator|)
operator|-
literal|1
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"4\r\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|AT91C_READ_ERROR
return|;
block|}
comment|// Test if the MMC supports Partial Read Block
comment|// ALWAYS SUPPORTED IN SD Memory Card
if|if
condition|(
operator|(
name|sizeToRead
operator|<
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Max_Read_DataBlock_Length
operator|)
operator|&&
operator|(
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Read_Partial
operator|==
literal|0x00
operator|)
condition|)
block|{
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"5\r\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|AT91C_READ_ERROR
return|;
block|}
if|if
condition|(
name|sizeToRead
operator|>
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Max_Read_DataBlock_Length
condition|)
block|{
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"6\r\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|AT91C_READ_ERROR
return|;
block|}
comment|///////////////////////////////////////////////////////////////////////
comment|// Init Mode Register
name|AT91C_BASE_MCI
operator|->
name|MCI_MR
operator||=
operator|(
operator|(
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Max_Read_DataBlock_Length
operator|<<
literal|16
operator|)
operator||
name|AT91C_MCI_PDCMODE
operator|)
expr_stmt|;
if|if
condition|(
name|sizeToRead
operator|%
literal|4
condition|)
name|sizeToRead
operator|=
operator|(
name|sizeToRead
operator|/
literal|4
operator|)
operator|+
literal|1
expr_stmt|;
else|else
name|sizeToRead
operator|=
name|sizeToRead
operator|/
literal|4
expr_stmt|;
name|AT91C_BASE_PDC_MCI
operator|->
name|PDC_PTCR
operator|=
operator|(
name|AT91C_PDC_TXTDIS
operator||
name|AT91C_PDC_RXTDIS
operator|)
expr_stmt|;
name|AT91C_BASE_PDC_MCI
operator|->
name|PDC_RPR
operator|=
operator|(
name|unsigned
name|int
operator|)
name|dataBuffer
expr_stmt|;
name|AT91C_BASE_PDC_MCI
operator|->
name|PDC_RCR
operator|=
name|sizeToRead
expr_stmt|;
comment|// Send the Read single block command
if|if
condition|(
name|AT91F_MCI_SendCommand
argument_list|(
name|AT91C_READ_SINGLE_BLOCK_CMD
argument_list|,
name|src
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_READ_ERROR
return|;
name|pMCI_Device
operator|->
name|pMCI_DeviceDesc
operator|->
name|state
operator|=
name|AT91C_MCI_RX_SINGLE_BLOCK
expr_stmt|;
comment|// Enable AT91C_MCI_RXBUFF Interrupt
name|AT91C_BASE_MCI
operator|->
name|MCI_IER
operator|=
name|AT91C_MCI_RXBUFF
expr_stmt|;
comment|// (PDC) Receiver Transfer Enable
name|AT91C_BASE_PDC_MCI
operator|->
name|PDC_PTCR
operator|=
name|AT91C_PDC_RXTEN
expr_stmt|;
return|return
name|AT91C_READ_OK
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_WriteBlock
end_comment

begin_comment
comment|//* \brief  Write an ENTIRE block but not always PARTIAL block !!!
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
unit|AT91S_MCIDeviceStatus AT91F_MCI_WriteBlock( 	AT91PS_MciDevice pMCI_Device, 	int dest, 	unsigned int *dataBuffer, 	int sizeToWrite ) {
comment|///////////////////////////////////////////////////////////////////////
end_comment

begin_comment
unit|if( pMCI_Device->pMCI_DeviceDesc->state != AT91C_MCI_IDLE) 		return AT91C_WRITE_ERROR;      	if( (AT91F_MCI_GetStatus(pMCI_Device->pMCI_DeviceFeatures->Relative_Card_Address)& AT91C_SR_READY_FOR_DATA) != AT91C_SR_READY_FOR_DATA) 		return AT91C_WRITE_ERROR;     	 	if ((dest + sizeToWrite)> pMCI_Device->pMCI_DeviceFeatures->Memory_Capacity) 		return AT91C_WRITE_ERROR;
comment|// If source does not fit a begin of a block
end_comment

begin_comment
unit|if ( (dest % pMCI_Device->pMCI_DeviceFeatures->Max_Read_DataBlock_Length) != 0 ) 		return AT91C_WRITE_ERROR;
comment|// Test if the MMC supports Partial Write Block
end_comment

begin_comment
unit|if( (sizeToWrite< pMCI_Device->pMCI_DeviceFeatures->Max_Write_DataBlock_Length)&& (pMCI_Device->pMCI_DeviceFeatures->Write_Partial == 0x00) )    		return AT91C_WRITE_ERROR;    		    	if( sizeToWrite> pMCI_Device->pMCI_DeviceFeatures->Max_Write_DataBlock_Length )    		return AT91C_WRITE_ERROR;
comment|///////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Init Mode Register
end_comment

begin_comment
unit|AT91C_BASE_MCI->MCI_MR |= ((pMCI_Device->pMCI_DeviceFeatures->Max_Write_DataBlock_Length<< 16) | AT91C_MCI_PDCMODE); 	 	if (sizeToWrite %4) 		sizeToWrite = (sizeToWrite /4)+1; 	else 		sizeToWrite = sizeToWrite/4;
comment|// Init PDC for write sequence
end_comment

begin_comment
unit|AT91C_BASE_PDC_MCI->PDC_PTCR = (AT91C_PDC_TXTDIS | AT91C_PDC_RXTDIS); 	AT91C_BASE_PDC_MCI->PDC_TPR = (unsigned int) dataBuffer; 	AT91C_BASE_PDC_MCI->PDC_TCR = sizeToWrite;
comment|// Send the write single block command
end_comment

begin_comment
unit|if ( AT91F_MCI_SendCommand(AT91C_WRITE_BLOCK_CMD, dest) != AT91C_CMD_SEND_OK) 		return AT91C_WRITE_ERROR;  	pMCI_Device->pMCI_DeviceDesc->state = AT91C_MCI_TX_SINGLE_BLOCK;
comment|// Enable AT91C_MCI_TXBUFE Interrupt
end_comment

begin_comment
unit|AT91C_BASE_MCI->MCI_IER = AT91C_MCI_TXBUFE;
comment|// Enables TX for PDC transfert requests
end_comment

begin_comment
unit|AT91C_BASE_PDC_MCI->PDC_PTCR = AT91C_PDC_TXTEN;    	return AT91C_WRITE_OK; }
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_MMC_SelectCard
end_comment

begin_comment
comment|//* \brief Toggles a card between the Stand_by and Transfer states or between Programming and Disconnect states
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
unit|AT91S_MCIDeviceStatus AT91F_MCI_MMC_SelectCard(AT91PS_MciDevice pMCI_Device, unsigned int relative_card_address) {     int status;
comment|//* Check if the MMC card chosen is already the selected one
end_comment

begin_comment
unit|status = AT91F_MCI_GetStatus(relative_card_address);  	if (status< 0) 		return AT91C_CARD_SELECTED_ERROR;  	if ((status& AT91C_SR_CARD_SELECTED) == AT91C_SR_CARD_SELECTED) 		return AT91C_CARD_SELECTED_OK;
comment|//* Search for the MMC Card to be selected, status = the Corresponding Device Number
end_comment

begin_endif
unit|status = 0; 	while( (pMCI_Device->pMCI_DeviceFeatures[status].Relative_Card_Address != relative_card_address)&& (status< AT91C_MAX_MCI_CARDS) ) 		status++;  	if (status> AT91C_MAX_MCI_CARDS)     	return AT91C_CARD_SELECTED_ERROR;      if (AT91F_MCI_SendCommand(AT91C_SEL_DESEL_CARD_CMD, 	  pMCI_Device->pMCI_DeviceFeatures[status].Relative_Card_Address<< 16) == AT91C_CMD_SEND_OK)     	return AT91C_CARD_SELECTED_OK;     return AT91C_CARD_SELECTED_ERROR; }
endif|#
directive|endif
end_endif

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_GetCSD
end_comment

begin_comment
comment|//* \brief Asks to the specified card to send its CSD
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_GetCSD
parameter_list|(
name|unsigned
name|int
name|relative_card_address
parameter_list|,
name|unsigned
name|int
modifier|*
name|response
parameter_list|)
block|{
if|if
condition|(
name|AT91F_MCI_SendCommand
argument_list|(
name|AT91C_SEND_CSD_CMD
argument_list|,
operator|(
name|relative_card_address
operator|<<
literal|16
operator|)
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_CMD_SEND_ERROR
return|;
name|response
index|[
literal|0
index|]
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|0
index|]
expr_stmt|;
name|response
index|[
literal|1
index|]
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|1
index|]
expr_stmt|;
name|response
index|[
literal|2
index|]
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|2
index|]
expr_stmt|;
name|response
index|[
literal|3
index|]
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|3
index|]
expr_stmt|;
return|return
name|AT91C_CMD_SEND_OK
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_SetBlocklength
end_comment

begin_comment
comment|//* \brief Select a block length for all following block commands (R/W)
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SetBlocklength
parameter_list|(
name|unsigned
name|int
name|length
parameter_list|)
block|{
return|return
operator|(
name|AT91F_MCI_SendCommand
argument_list|(
name|AT91C_SET_BLOCKLEN_CMD
argument_list|,
name|length
argument_list|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_MMC_GetAllOCR
end_comment

begin_comment
comment|//* \brief Asks to all cards to send their operations conditions
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
unit|static AT91S_MCIDeviceStatus AT91F_MCI_MMC_GetAllOCR() { 	unsigned int	response =0x0;  	  	while(1) { 		response = AT91F_MCI_SendCommand(AT91C_MMC_SEND_OP_COND_CMD, 		    AT91C_MMC_HOST_VOLTAGE_RANGE); 		if (response != AT91C_CMD_SEND_OK) 			return AT91C_INIT_ERROR; 		response = AT91C_BASE_MCI->MCI_RSPR[0]; 		if ( (response& AT91C_CARD_POWER_UP_BUSY) == AT91C_CARD_POWER_UP_BUSY) 			return(response);	 	} }
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_MMC_GetAllCID
end_comment

begin_comment
comment|//* \brief Asks to the MMC on the chosen slot to send its CID
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
unit|static AT91S_MCIDeviceStatus AT91F_MCI_MMC_GetAllCID(AT91PS_MciDevice pMCI_Device, unsigned int *response) { 	int Nb_Cards_Found=-1;    	while (1) { 	 	if(AT91F_MCI_SendCommand(AT91C_MMC_ALL_SEND_CID_CMD, 		       AT91C_NO_ARGUMENT) != AT91C_CMD_SEND_OK) 			return Nb_Cards_Found; 		else {		 			Nb_Cards_Found = 0;
comment|//* Assignation of the relative address to the MMC CARD
end_comment

begin_comment
unit|pMCI_Device->pMCI_DeviceFeatures[Nb_Cards_Found].Relative_Card_Address = Nb_Cards_Found + AT91C_FIRST_RCA;
comment|//* Set the insert flag
end_comment

begin_comment
unit|pMCI_Device->pMCI_DeviceFeatures[Nb_Cards_Found].Card_Inserted = AT91C_MMC_CARD_INSERTED; 	 			if (AT91F_MCI_SendCommand( 				AT91C_MMC_SET_RELATIVE_ADDR_CMD, 				(Nb_Cards_Found + AT91C_FIRST_RCA)<< 16) != AT91C_CMD_SEND_OK) 				return AT91C_CMD_SEND_ERROR;
comment|//* If no error during assignation address ==> Increment Nb_cards_Found
end_comment

begin_comment
unit|Nb_Cards_Found++ ; 		} 	} }
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_MMC_Init
end_comment

begin_comment
comment|//* \brief Return the MMC initialisation status
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
unit|AT91S_MCIDeviceStatus AT91F_MCI_MMC_Init (AT91PS_MciDevice pMCI_Device) { 	unsigned int	tab_response[4]; 	unsigned int	mult,blocknr; 	unsigned int 	i,Nb_Cards_Found=0; 	AT91PS_MciDeviceFeatures f;
comment|//* Resets all MMC Cards in Idle state
end_comment

begin_comment
unit|AT91F_MCI_SendCommand(AT91C_MMC_GO_IDLE_STATE_CMD, AT91C_NO_ARGUMENT);  	if (AT91F_MCI_MMC_GetAllOCR(pMCI_Device) == AT91C_INIT_ERROR) 		return AT91C_INIT_ERROR;  	Nb_Cards_Found = AT91F_MCI_MMC_GetAllCID(pMCI_Device,tab_response); 	if (Nb_Cards_Found == AT91C_CMD_SEND_ERROR) 		return AT91C_INIT_ERROR;
comment|//* Set the Mode Register
end_comment

begin_comment
unit|AT91C_BASE_MCI->MCI_MR = AT91C_MCI_MR_PDCMODE; 	for(i = 0; i< Nb_Cards_Found; i++) { 	    	f = pMCI_Device->pMCI_DeviceFeatures + i; 		if (AT91F_MCI_GetCSD(f->Relative_Card_Address, tab_response) != 		    AT91C_CMD_SEND_OK) { 			f->Relative_Card_Address = 0; 			continue; 		} 		f->READ_BL_LEN = ((tab_response[1]>> AT91C_CSD_RD_B_LEN_S)& AT91C_CSD_RD_B_LEN_M); 		f->WRITE_BL_LEN = ((tab_response[3]>> AT91C_CSD_WBLEN_S)& AT91C_CSD_WBLEN_M ); 		f->Max_Read_DataBlock_Length = 1<< f->READ_BL_LEN; 		f->Max_Write_DataBlock_Length = 1<< f->WRITE_BL_LEN; 		f->Sector_Size = 1 + ((tab_response[2]>> AT91C_CSD_v22_SECT_SIZE_S)& AT91C_CSD_v22_SECT_SIZE_M ); 		f->Read_Partial = (tab_response[1]>> AT91C_CSD_RD_B_PAR_S)& AT91C_CSD_RD_B_PAR_M; 		f->Write_Partial = (tab_response[3]>> AT91C_CSD_WBLOCK_P_S)& AT91C_CSD_WBLOCK_P_M;
comment|// None in MMC specification version 2.2
end_comment

begin_comment
unit|f->Erase_Block_Enable = 0; 		f->Read_Block_Misalignment = (tab_response[1]>> AT91C_CSD_RD_B_MIS_S)& AT91C_CSD_RD_B_MIS_M; 		f->Write_Block_Misalignment = (tab_response[1]>> AT91C_CSD_WR_B_MIS_S)& AT91C_CSD_WR_B_MIS_M;
comment|//// Compute Memory Capacity
end_comment

begin_comment
comment|// compute MULT
end_comment

begin_comment
unit|mult = 1<< ( ((tab_response[2]>> AT91C_CSD_C_SIZE_M_S)& AT91C_CSD_C_SIZE_M_M) + 2 );
comment|// compute MSB of C_SIZE
end_comment

begin_comment
unit|blocknr = ((tab_response[1]>> AT91C_CSD_CSIZE_H_S)& AT91C_CSD_CSIZE_H_M)<< 2;
comment|// compute MULT * (LSB of C-SIZE + MSB already computed + 1) = BLOCKNR
end_comment

begin_comment
unit|blocknr = mult * ( ( blocknr + ( (tab_response[2]>> AT91C_CSD_CSIZE_L_S)& AT91C_CSD_CSIZE_L_M) ) + 1 ); 		f->Memory_Capacity =  f->Max_Read_DataBlock_Length * blocknr;
comment|//// End of Compute Memory Capacity
end_comment

begin_comment
unit|}
comment|// XXX warner hacked this
end_comment

begin_endif
unit|return AT91C_INIT_OK; }
endif|#
directive|endif
end_endif

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_SDCard_GetOCR
end_comment

begin_comment
comment|//* \brief Asks to all cards to send their operations conditions
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SDCard_GetOCR
parameter_list|(
name|AT91PS_MciDevice
name|pMCI_Device
parameter_list|)
block|{
name|unsigned
name|int
name|response
init|=
literal|0x0
decl_stmt|;
comment|// The RCA to be used for CMD55 in Idle state shall be the card's default RCA=0x0000.
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Relative_Card_Address
operator|=
literal|0x0
expr_stmt|;
while|while
condition|(
operator|(
name|response
operator|&
name|AT91C_CARD_POWER_UP_BUSY
operator|)
operator|!=
name|AT91C_CARD_POWER_UP_BUSY
condition|)
block|{
name|response
operator|=
name|AT91F_MCI_SDCard_SendAppCommand
argument_list|(
name|pMCI_Device
argument_list|,
name|AT91C_SDCARD_APP_OP_COND_CMD
argument_list|,
name|AT91C_MMC_HOST_VOLTAGE_RANGE
argument_list|)
expr_stmt|;
if|if
condition|(
name|response
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_INIT_ERROR
return|;
name|response
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|0
index|]
expr_stmt|;
block|}
return|return
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|0
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_SDCard_GetCID
end_comment

begin_comment
comment|//* \brief Asks to the SDCard on the chosen slot to send its CID
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SDCard_GetCID
parameter_list|(
name|unsigned
name|int
modifier|*
name|response
parameter_list|)
block|{
if|if
condition|(
name|AT91F_MCI_SendCommand
argument_list|(
name|AT91C_ALL_SEND_CID_CMD
argument_list|,
name|AT91C_NO_ARGUMENT
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_CMD_SEND_ERROR
return|;
name|response
index|[
literal|0
index|]
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|0
index|]
expr_stmt|;
name|response
index|[
literal|1
index|]
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|1
index|]
expr_stmt|;
name|response
index|[
literal|2
index|]
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|2
index|]
expr_stmt|;
name|response
index|[
literal|3
index|]
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|3
index|]
expr_stmt|;
return|return
name|AT91C_CMD_SEND_OK
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_SDCard_SetBusWidth
end_comment

begin_comment
comment|//* \brief  Set bus width for SDCard
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SDCard_SetBusWidth
parameter_list|(
name|AT91PS_MciDevice
name|pMCI_Device
parameter_list|)
block|{
specifier|volatile
name|int
name|ret_value
decl_stmt|;
name|char
name|bus_width
decl_stmt|;
do|do
block|{
name|ret_value
operator|=
name|AT91F_MCI_GetStatus
argument_list|(
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Relative_Card_Address
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|ret_value
operator|>
literal|0
operator|)
operator|&&
operator|(
operator|(
name|ret_value
operator|&
name|AT91C_SR_READY_FOR_DATA
operator|)
operator|==
literal|0
operator|)
condition|)
do|;
comment|// Select Card
name|AT91F_MCI_SendCommand
argument_list|(
name|AT91C_SEL_DESEL_CARD_CMD
argument_list|,
operator|(
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
operator|->
name|Relative_Card_Address
operator|)
operator|<<
literal|16
argument_list|)
expr_stmt|;
comment|// Set bus width for Sdcard
if|if
condition|(
name|pMCI_Device
operator|->
name|pMCI_DeviceDesc
operator|->
name|SDCard_bus_width
operator|==
name|AT91C_MCI_SCDBUS
condition|)
name|bus_width
operator|=
name|AT91C_BUS_WIDTH_4BITS
expr_stmt|;
else|else
name|bus_width
operator|=
name|AT91C_BUS_WIDTH_1BIT
expr_stmt|;
if|if
condition|(
name|AT91F_MCI_SDCard_SendAppCommand
argument_list|(
name|pMCI_Device
argument_list|,
name|AT91C_SDCARD_SET_BUS_WIDTH_CMD
argument_list|,
name|bus_width
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_CMD_SEND_ERROR
return|;
return|return
name|AT91C_CMD_SEND_OK
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    AT91F_MCI_SDCard_Init
end_comment

begin_comment
comment|//* \brief Return the SDCard initialisation status
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SDCard_Init
parameter_list|(
name|AT91PS_MciDevice
name|pMCI_Device
parameter_list|)
block|{
name|unsigned
name|int
name|tab_response
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|int
name|mult
decl_stmt|,
name|blocknr
decl_stmt|;
name|AT91PS_MciDeviceFeatures
name|f
decl_stmt|;
name|AT91F_MCI_SendCommand
argument_list|(
name|AT91C_GO_IDLE_STATE_CMD
argument_list|,
name|AT91C_NO_ARGUMENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|AT91F_MCI_SDCard_GetOCR
argument_list|(
name|pMCI_Device
argument_list|)
operator|==
name|AT91C_INIT_ERROR
condition|)
return|return
name|AT91C_INIT_ERROR
return|;
name|f
operator|=
name|pMCI_Device
operator|->
name|pMCI_DeviceFeatures
expr_stmt|;
if|if
condition|(
name|AT91F_MCI_SDCard_GetCID
argument_list|(
name|tab_response
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_INIT_ERROR
return|;
name|f
operator|->
name|Card_Inserted
operator|=
name|AT91C_SD_CARD_INSERTED
expr_stmt|;
if|if
condition|(
name|AT91F_MCI_SendCommand
argument_list|(
name|AT91C_SET_RELATIVE_ADDR_CMD
argument_list|,
literal|0
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_INIT_ERROR
return|;
name|f
operator|->
name|Relative_Card_Address
operator|=
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|0
index|]
operator|>>
literal|16
operator|)
expr_stmt|;
if|if
condition|(
name|AT91F_MCI_GetCSD
argument_list|(
name|f
operator|->
name|Relative_Card_Address
argument_list|,
name|tab_response
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_INIT_ERROR
return|;
name|f
operator|->
name|READ_BL_LEN
operator|=
literal|1
operator|<<
operator|(
operator|(
name|tab_response
index|[
literal|1
index|]
operator|>>
name|AT91C_CSD_RD_B_LEN_S
operator|)
operator|&
name|AT91C_CSD_RD_B_LEN_M
operator|)
expr_stmt|;
name|f
operator|->
name|WRITE_BL_LEN
operator|=
literal|1
operator|<<
operator|(
operator|(
name|tab_response
index|[
literal|3
index|]
operator|>>
name|AT91C_CSD_WBLEN_S
operator|)
operator|&
name|AT91C_CSD_WBLEN_M
operator|)
expr_stmt|;
name|f
operator|->
name|Max_Read_DataBlock_Length
operator|=
literal|1
operator|<<
name|f
operator|->
name|READ_BL_LEN
expr_stmt|;
name|f
operator|->
name|Max_Write_DataBlock_Length
operator|=
literal|1
operator|<<
name|f
operator|->
name|WRITE_BL_LEN
expr_stmt|;
name|f
operator|->
name|Sector_Size
operator|=
literal|1
operator|+
operator|(
operator|(
name|tab_response
index|[
literal|2
index|]
operator|>>
name|AT91C_CSD_v21_SECT_SIZE_S
operator|)
operator|&
name|AT91C_CSD_v21_SECT_SIZE_M
operator|)
expr_stmt|;
name|f
operator|->
name|Read_Partial
operator|=
operator|(
name|tab_response
index|[
literal|1
index|]
operator|>>
name|AT91C_CSD_RD_B_PAR_S
operator|)
operator|&
name|AT91C_CSD_RD_B_PAR_M
expr_stmt|;
name|f
operator|->
name|Write_Partial
operator|=
operator|(
name|tab_response
index|[
literal|3
index|]
operator|>>
name|AT91C_CSD_WBLOCK_P_S
operator|)
operator|&
name|AT91C_CSD_WBLOCK_P_M
expr_stmt|;
name|f
operator|->
name|Erase_Block_Enable
operator|=
operator|(
name|tab_response
index|[
literal|3
index|]
operator|>>
name|AT91C_CSD_v21_ER_BLEN_EN_S
operator|)
operator|&
name|AT91C_CSD_v21_ER_BLEN_EN_M
expr_stmt|;
name|f
operator|->
name|Read_Block_Misalignment
operator|=
operator|(
name|tab_response
index|[
literal|1
index|]
operator|>>
name|AT91C_CSD_RD_B_MIS_S
operator|)
operator|&
name|AT91C_CSD_RD_B_MIS_M
expr_stmt|;
name|f
operator|->
name|Write_Block_Misalignment
operator|=
operator|(
name|tab_response
index|[
literal|1
index|]
operator|>>
name|AT91C_CSD_WR_B_MIS_S
operator|)
operator|&
name|AT91C_CSD_WR_B_MIS_M
expr_stmt|;
comment|//// Compute Memory Capacity
comment|// compute MULT
name|mult
operator|=
literal|1
operator|<<
operator|(
operator|(
operator|(
name|tab_response
index|[
literal|2
index|]
operator|>>
name|AT91C_CSD_C_SIZE_M_S
operator|)
operator|&
name|AT91C_CSD_C_SIZE_M_M
operator|)
operator|+
literal|2
operator|)
expr_stmt|;
comment|// compute MSB of C_SIZE
name|blocknr
operator|=
operator|(
operator|(
name|tab_response
index|[
literal|1
index|]
operator|>>
name|AT91C_CSD_CSIZE_H_S
operator|)
operator|&
name|AT91C_CSD_CSIZE_H_M
operator|)
operator|<<
literal|2
expr_stmt|;
comment|// compute MULT * (LSB of C-SIZE + MSB already computed + 1) = BLOCKNR
name|blocknr
operator|=
name|mult
operator|*
operator|(
operator|(
name|blocknr
operator|+
operator|(
operator|(
name|tab_response
index|[
literal|2
index|]
operator|>>
name|AT91C_CSD_CSIZE_L_S
operator|)
operator|&
name|AT91C_CSD_CSIZE_L_M
operator|)
operator|)
operator|+
literal|1
operator|)
expr_stmt|;
name|f
operator|->
name|Memory_Capacity
operator|=
name|f
operator|->
name|Max_Read_DataBlock_Length
operator|*
name|blocknr
expr_stmt|;
comment|//// End of Compute Memory Capacity
if|if
condition|(
name|AT91F_MCI_SDCard_SetBusWidth
argument_list|(
name|pMCI_Device
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_INIT_ERROR
return|;
if|if
condition|(
name|AT91F_MCI_SetBlocklength
argument_list|(
name|f
operator|->
name|Max_Read_DataBlock_Length
argument_list|)
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
name|AT91C_INIT_ERROR
return|;
return|return
name|AT91C_INIT_OK
return|;
block|}
end_function

end_unit

