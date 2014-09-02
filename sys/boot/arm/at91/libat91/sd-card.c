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
comment|//* File Name           : main.c
end_comment

begin_comment
comment|//* Object              : main application written in C
end_comment

begin_comment
comment|//* Creation            : FB   21/11/2002
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

begin_include
include|#
directive|include
file|"sd-card.h"
end_include

begin_define
define|#
directive|define
name|AT91C_MCI_TIMEOUT
value|1000000
end_define

begin_comment
comment|/* For AT91F_MCIDeviceWaitReady */
end_comment

begin_define
define|#
directive|define
name|SD_BLOCK_SIZE
value|512
end_define

begin_comment
comment|//* Global Variables
end_comment

begin_decl_stmt
specifier|static
name|AT91S_MciDevice
name|MCI_Device
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****************************************************************************** **Error return codes ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MCI_UNSUPP_SIZE_ERROR
value|5
end_define

begin_define
define|#
directive|define
name|MCI_UNSUPP_OFFSET_ERROR
value|6
end_define

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCIDeviceWaitReady
end_comment

begin_comment
comment|//* \brief Wait for MCI Device ready
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|MCIDeviceWaitReady
parameter_list|(
name|unsigned
name|int
name|timeout
parameter_list|)
block|{
specifier|volatile
name|unsigned
name|int
name|status
decl_stmt|;
name|int
name|waitfor
decl_stmt|;
if|if
condition|(
name|MCI_Device
operator|.
name|state
operator|==
name|AT91C_MCI_RX_SINGLE_BLOCK
condition|)
name|waitfor
operator|=
name|AT91C_MCI_RXBUFF
expr_stmt|;
else|else
name|waitfor
operator|=
name|AT91C_MCI_NOTBUSY
expr_stmt|;
do|do
block|{
name|status
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
expr_stmt|;
name|timeout
operator|--
expr_stmt|;
block|}
do|while
condition|(
operator|!
operator|(
name|status
operator|&
name|waitfor
operator|)
operator|&&
operator|(
name|timeout
operator|>
literal|0
operator|)
condition|)
do|;
name|status
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
expr_stmt|;
comment|// If End of Tx Buffer Empty interrupt occurred
if|if
condition|(
name|MCI_Device
operator|.
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
name|MCI_Device
operator|.
name|state
operator|=
name|AT91C_MCI_IDLE
expr_stmt|;
block|}
comment|// End of if AT91C_MCI_TXBUFF
comment|// If End of Rx Buffer Full interrupt occurred
if|if
condition|(
name|MCI_Device
operator|.
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
name|MCI_Device
operator|.
name|state
operator|=
name|AT91C_MCI_IDLE
expr_stmt|;
block|}
comment|// End of if AT91C_MCI_RXBUFF
comment|//printf("WaitReady returning status %x\n", status);
return|return
name|status
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|swap
parameter_list|(
name|unsigned
name|int
name|v
parameter_list|)
block|{
name|unsigned
name|int
name|t1
decl_stmt|;
asm|__asm __volatile("eor %1, %0, %0, ror #16\n"
literal|"bic %1, %1, #0x00ff0000\n"
literal|"mov %0, %0, ror #8\n"
literal|"eor %0, %0, %1, lsr #8\n"
operator|:
literal|"+r"
operator|(
name|v
operator|)
operator|,
literal|"=r"
operator|(
name|t1
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|v
operator|)
return|;
end_return

begin_function
unit|}  inline
specifier|static
name|unsigned
name|int
name|wait_ready
parameter_list|()
block|{
name|int
name|status
decl_stmt|;
name|int
name|timeout
init|=
name|AT91C_MCI_TIMEOUT
decl_stmt|;
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
operator|&&
operator|(
operator|--
name|timeout
operator|>
literal|0
operator|)
condition|)
do|;
return|return
name|status
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCI_SendCommand
end_comment

begin_comment
comment|//* \brief Generic function to send a command to the MMC or SDCard
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|int
name|MCI_SendCommand
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
decl_stmt|;
name|unsigned
name|int
name|errorMask
init|=
name|AT91C_MCI_SR_ERROR
decl_stmt|;
name|unsigned
name|int
name|opcode
init|=
name|Cmd
operator|&
literal|0x3F
decl_stmt|;
comment|//printf("SendCmd %d (%x) arg %x\n", opcode, Cmd, Arg);
comment|// Don't check response CRC on ACMD41 (R3 response type).
if|if
condition|(
name|opcode
operator|==
literal|41
condition|)
name|errorMask
operator|&=
operator|~
name|AT91C_MCI_RCRCE
expr_stmt|;
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
name|error
operator|=
name|wait_ready
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|error
operator|&
name|errorMask
operator|)
operator|!=
literal|0
condition|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCI_GetStatus
end_comment

begin_comment
comment|//* \brief Addressed card sends its status register
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|MCI_GetStatus
parameter_list|()
block|{
if|if
condition|(
name|MCI_SendCommand
argument_list|(
name|SEND_STATUS_CMD
argument_list|,
name|MCI_Device
operator|.
name|RCA
operator|<<
literal|16
argument_list|)
condition|)
return|return
literal|0
return|;
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
comment|//* \fn    MCI_ReadBlock
end_comment

begin_comment
comment|//* \brief Start the read for a single 512-byte block
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|int
name|MCI_StartReadBlock
parameter_list|(
name|unsigned
name|blknum
parameter_list|,
name|void
modifier|*
name|dataBuffer
parameter_list|)
block|{
comment|// Init Mode Register
name|AT91C_BASE_MCI
operator|->
name|MCI_MR
operator||=
operator|(
operator|(
name|SD_BLOCK_SIZE
operator|<<
literal|16
operator|)
operator||
name|AT91C_MCI_PDCMODE
operator|)
expr_stmt|;
comment|// (PDC) Receiver Transfer Enable
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
name|SD_BLOCK_SIZE
operator|/
literal|4
expr_stmt|;
empty_stmt|;
name|AT91C_BASE_PDC_MCI
operator|->
name|PDC_PTCR
operator|=
name|AT91C_PDC_RXTEN
expr_stmt|;
comment|// SDHC wants block offset, non-HC wants byte offset.
if|if
condition|(
operator|!
name|MCI_Device
operator|.
name|IsSDHC
condition|)
name|blknum
operator|*=
name|SD_BLOCK_SIZE
expr_stmt|;
comment|// Send the Read single block command
if|if
condition|(
name|MCI_SendCommand
argument_list|(
name|READ_SINGLE_BLOCK_CMD
argument_list|,
name|blknum
argument_list|)
condition|)
block|{
return|return
name|AT91C_READ_ERROR
return|;
block|}
name|MCI_Device
operator|.
name|state
operator|=
name|AT91C_MCI_RX_SINGLE_BLOCK
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCI_readblocks
end_comment

begin_comment
comment|//* \brief Read one or more blocks
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
name|int
name|MCI_readblocks
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
name|unsigned
name|blknum
parameter_list|,
name|unsigned
name|blkcount
parameter_list|)
block|{
name|unsigned
name|int
name|status
decl_stmt|;
name|unsigned
name|int
modifier|*
name|walker
decl_stmt|;
if|if
condition|(
name|MCI_Device
operator|.
name|state
operator|!=
name|AT91C_MCI_IDLE
condition|)
block|{
return|return
literal|1
return|;
block|}
if|if
condition|(
operator|(
name|MCI_GetStatus
argument_list|()
operator|&
name|AT91C_SR_READY_FOR_DATA
operator|)
operator|==
literal|0
condition|)
block|{
return|return
literal|1
return|;
block|}
comment|// As long as there is data to read
while|while
condition|(
name|blkcount
condition|)
block|{
comment|//Do the reading
if|if
condition|(
name|MCI_StartReadBlock
argument_list|(
name|blknum
argument_list|,
name|dest
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
comment|// Wait MCI Device Ready
name|status
operator|=
name|MCIDeviceWaitReady
argument_list|(
name|AT91C_MCI_TIMEOUT
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|&
name|AT91C_MCI_SR_ERROR
condition|)
return|return
literal|1
return|;
comment|// Fix erratum in MCI part - endian-swap all data.
for|for
control|(
name|walker
operator|=
operator|(
name|unsigned
name|int
operator|*
operator|)
name|dest
init|;
name|walker
operator|<
operator|(
name|unsigned
name|int
operator|*
operator|)
operator|(
name|dest
operator|+
name|SD_BLOCK_SIZE
operator|)
condition|;
name|walker
operator|++
control|)
operator|*
name|walker
operator|=
name|swap
argument_list|(
operator|*
name|walker
argument_list|)
expr_stmt|;
comment|// Update counters& pointers
operator|++
name|blknum
expr_stmt|;
operator|--
name|blkcount
expr_stmt|;
name|dest
operator|+=
name|SD_BLOCK_SIZE
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCI_read
end_comment

begin_comment
comment|//* \brief Legacy read function, takes byte offset and length but was always
end_comment

begin_comment
comment|//*  used to read full blocks; interface preserved for existing boot code.
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
name|int
name|MCI_read
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
name|unsigned
name|byteoffset
parameter_list|,
name|unsigned
name|length
parameter_list|)
block|{
return|return
name|MCI_readblocks
argument_list|(
name|dest
argument_list|,
name|byteoffset
operator|/
name|SD_BLOCK_SIZE
argument_list|,
name|length
operator|/
name|SD_BLOCK_SIZE
argument_list|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCI_SDCard_SendAppCommand
end_comment

begin_comment
comment|//* \brief Specific function to send a specific command to the SDCard
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|int
name|MCI_SDCard_SendAppCommand
parameter_list|(
name|unsigned
name|int
name|Cmd_App
parameter_list|,
name|unsigned
name|int
name|Arg
parameter_list|)
block|{
name|int
name|status
decl_stmt|;
if|if
condition|(
operator|(
name|status
operator|=
name|MCI_SendCommand
argument_list|(
name|APP_CMD
argument_list|,
operator|(
name|MCI_Device
operator|.
name|RCA
operator|<<
literal|16
operator|)
argument_list|)
operator|)
operator|==
literal|0
condition|)
name|status
operator|=
name|MCI_SendCommand
argument_list|(
name|Cmd_App
argument_list|,
name|Arg
argument_list|)
expr_stmt|;
return|return
name|status
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCI_GetCSD
end_comment

begin_comment
comment|//* \brief Asks to the specified card to send its CSD
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|int
name|MCI_GetCSD
parameter_list|(
name|unsigned
name|int
name|rca
parameter_list|,
name|unsigned
name|int
modifier|*
name|response
parameter_list|)
block|{
if|if
condition|(
name|MCI_SendCommand
argument_list|(
name|SEND_CSD_CMD
argument_list|,
operator|(
name|rca
operator|<<
literal|16
operator|)
argument_list|)
condition|)
return|return
literal|1
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
literal|0
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCI_SDCard_GetOCR
end_comment

begin_comment
comment|//* \brief Wait for card to power up and determine whether it's SDHC or not.
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|int
name|MCI_SDCard_GetOCR
parameter_list|()
block|{
name|unsigned
name|int
name|response
decl_stmt|;
name|unsigned
name|int
name|arg
init|=
name|AT91C_MMC_HOST_VOLTAGE_RANGE
decl_stmt|;
name|int
name|timeout
init|=
name|AT91C_MCI_TIMEOUT
decl_stmt|;
comment|// Force card to idle state.
name|MCI_SendCommand
argument_list|(
name|GO_IDLE_STATE_CMD
argument_list|,
name|AT91C_NO_ARGUMENT
argument_list|)
expr_stmt|;
comment|// Begin probe for SDHC by sending CMD8; only v2.0 cards respond to it.
comment|//
comment|// Arg is vvpp where vv is voltage range and pp is an arbitrary bit
comment|// pattern that gets echoed back in the response. The only voltage
comment|// ranges defined are:
comment|//   0x01 = 2.7 - 3.6
comment|//   0x02 = "reserved for low voltage" whatever that means.
comment|//
comment|// If the card fails to respond then it's not v2.0. If it responds by
comment|// echoing back exactly the arg we sent, then it's a v2.0 card and can
comment|// run at our voltage.  That means that when we send the ACMD41 (in
comment|// MCI_SDCard_GetOCR) we can include the HCS bit to inquire about SDHC.
if|if
condition|(
name|MCI_SendCommand
argument_list|(
name|SD_SEND_IF_COND_CMD
argument_list|,
literal|0x01AA
argument_list|)
operator|==
literal|0
condition|)
block|{
name|MCI_Device
operator|.
name|IsSDv2
operator|=
operator|(
name|AT91C_BASE_MCI
operator|->
name|MCI_RSPR
index|[
literal|0
index|]
operator|==
literal|0x01AA
operator|)
expr_stmt|;
block|}
comment|// If we've determined the card supports v2.0 functionality, set the
comment|// HCS/CCS bit to indicate that we support SDHC.  This will cause a
comment|// v2.0 card to report whether it is SDHC in the ACMD41 response.
if|if
condition|(
name|MCI_Device
operator|.
name|IsSDv2
condition|)
block|{
name|arg
operator||=
name|AT91C_CCS
expr_stmt|;
block|}
comment|// The RCA to be used for CMD55 in Idle state shall be the card's
comment|// default RCA=0x0000.
name|MCI_Device
operator|.
name|RCA
operator|=
literal|0x0
expr_stmt|;
comment|// Repeat ACMD41 until the card comes out of power-up-busy state.
do|do
block|{
if|if
condition|(
name|MCI_SDCard_SendAppCommand
argument_list|(
name|SDCARD_APP_OP_COND_CMD
argument_list|,
name|arg
argument_list|)
condition|)
block|{
return|return
literal|1
return|;
block|}
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
do|while
condition|(
operator|!
operator|(
name|response
operator|&
name|AT91C_CARD_POWER_UP_DONE
operator|)
operator|&&
operator|(
operator|--
name|timeout
operator|>
literal|0
operator|)
condition|)
do|;
comment|// A v2.0 card sets CCS (card capacity status) in the response if it's SDHC.
if|if
condition|(
name|MCI_Device
operator|.
name|IsSDv2
condition|)
block|{
name|MCI_Device
operator|.
name|IsSDHC
operator|=
operator|(
operator|(
name|response
operator|&
name|AT91C_CCS
operator|)
operator|==
name|AT91C_CCS
operator|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    MCI_SDCard_GetCID
end_comment

begin_comment
comment|//* \brief Asks to the SDCard on the chosen slot to send its CID
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|int
name|MCI_SDCard_GetCID
parameter_list|(
name|unsigned
name|int
modifier|*
name|response
parameter_list|)
block|{
if|if
condition|(
name|MCI_SendCommand
argument_list|(
name|ALL_SEND_CID_CMD
argument_list|,
name|AT91C_NO_ARGUMENT
argument_list|)
condition|)
return|return
literal|1
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
literal|0
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    sdcard_4wire
end_comment

begin_comment
comment|//* \brief  Set bus width to 1-bit or 4-bit according to the parm.
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//* Unlike most functions in this file, the return value from this one is
end_comment

begin_comment
comment|//* bool-ish; returns 0 on failure, 1 on success.
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
name|int
name|sdcard_use4wire
parameter_list|(
name|int
name|use4wire
parameter_list|)
block|{
specifier|volatile
name|int
name|ret_value
decl_stmt|;
do|do
block|{
name|ret_value
operator|=
name|MCI_GetStatus
argument_list|()
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
comment|// If going to 4-wire mode, ask the card to turn off the DAT3 card detect
comment|// pullup resistor, if going to 1-wire ask it to turn it back on.
name|ret_value
operator|=
name|MCI_SDCard_SendAppCommand
argument_list|(
name|SDCARD_SET_CLR_CARD_DETECT_CMD
argument_list|,
name|use4wire
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret_value
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
literal|0
return|;
comment|// Ask the card to go into the requested mode.
name|ret_value
operator|=
name|MCI_SDCard_SendAppCommand
argument_list|(
name|SDCARD_SET_BUS_WIDTH_CMD
argument_list|,
name|use4wire
condition|?
name|AT91C_BUS_WIDTH_4BITS
else|:
name|AT91C_BUS_WIDTH_1BIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret_value
operator|!=
name|AT91C_CMD_SEND_OK
condition|)
return|return
literal|0
return|;
comment|// Set the MCI device to match the mode we set in the card.
if|if
condition|(
name|use4wire
condition|)
block|{
name|MCI_Device
operator|.
name|SDCard_bus_width
operator|=
name|AT91C_BUS_WIDTH_4BITS
expr_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_SDCR
operator||=
name|AT91C_MCI_SCDBUS
expr_stmt|;
block|}
else|else
block|{
name|MCI_Device
operator|.
name|SDCard_bus_width
operator|=
name|AT91C_BUS_WIDTH_1BIT
expr_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_SDCR
operator|&=
operator|~
name|AT91C_MCI_SCDBUS
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    sdcard_init
end_comment

begin_comment
comment|//* \brief get the mci device ready to read from an SD or SDHC card.
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//* Unlike most functions in this file, the return value from this one is
end_comment

begin_comment
comment|//* bool-ish; returns 0 on failure, 1 on success.
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
name|int
name|sdcard_init
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|int
name|tab_response
index|[
literal|4
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|// Init MCI for MMC and SDCard interface
name|AT91F_MCI_CfgPIO
argument_list|()
expr_stmt|;
name|AT91F_MCI_CfgPMC
argument_list|()
expr_stmt|;
name|AT91F_PDC_Open
argument_list|(
name|AT91C_BASE_PDC_MCI
argument_list|)
expr_stmt|;
comment|// Init Device Structure
name|MCI_Device
operator|.
name|state
operator|=
name|AT91C_MCI_IDLE
expr_stmt|;
name|MCI_Device
operator|.
name|SDCard_bus_width
operator|=
literal|0
expr_stmt|;
name|MCI_Device
operator|.
name|IsSDv2
operator|=
literal|0
expr_stmt|;
name|MCI_Device
operator|.
name|IsSDHC
operator|=
literal|0
expr_stmt|;
comment|// Reset the MCI and set the bus speed.
comment|// Using MCK/230 gives a legal (under 400khz) bus speed for the card id
comment|// sequence for all reasonable master clock speeds.
name|AT91C_BASE_MCI
operator|->
name|MCI_CR
operator|=
name|AT91C_MCI_MCIDIS
operator||
literal|0x80
expr_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_IDR
operator|=
literal|0xFFFFFFFF
expr_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_DTOR
operator|=
name|AT91C_MCI_DTOR_1MEGA_CYCLES
expr_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_MR
operator|=
name|AT91C_MCI_PDCMODE
operator||
literal|114
expr_stmt|;
comment|/* clkdiv 114 = MCK/230 */
name|AT91C_BASE_MCI
operator|->
name|MCI_SDCR
operator|=
name|AT91C_MCI_MMC_SLOTA
expr_stmt|;
name|AT91C_BASE_MCI
operator|->
name|MCI_CR
operator|=
name|AT91C_MCI_MCIEN
operator||
name|AT91C_MCI_PWSEN
expr_stmt|;
comment|// Wait for the card to come out of power-up-busy state by repeatedly
comment|// sending ACMD41.  This also probes for SDHC versus standard cards.
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|MCI_SDCard_GetOCR
argument_list|()
operator|==
literal|0
condition|)
break|break;
if|if
condition|(
operator|(
name|i
operator|&
literal|0x01
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"."
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|i
operator|>=
literal|100
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|MCI_SDCard_GetCID
argument_list|(
name|tab_response
argument_list|)
condition|)
return|return
literal|0
return|;
comment|// Tell the card to set its address, and remember the result.
if|if
condition|(
name|MCI_SendCommand
argument_list|(
name|SET_RELATIVE_ADDR_CMD
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|0
return|;
name|MCI_Device
operator|.
name|RCA
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
comment|// After sending CMD3 (set addr) we can increase the clock to full speed.
comment|// Using MCK/4 gives a legal (under 25mhz) bus speed for all reasonable
comment|// master clock speeds.
name|AT91C_BASE_MCI
operator|->
name|MCI_MR
operator|=
name|AT91C_MCI_PDCMODE
operator||
literal|1
expr_stmt|;
comment|/* clkdiv 1 = MCK/4 */
if|if
condition|(
name|MCI_GetCSD
argument_list|(
name|MCI_Device
operator|.
name|RCA
argument_list|,
name|tab_response
argument_list|)
condition|)
return|return
literal|0
return|;
name|MCI_Device
operator|.
name|READ_BL_LEN
operator|=
operator|(
name|tab_response
index|[
literal|1
index|]
operator|>>
name|CSD_1_RD_B_LEN_S
operator|)
operator|&
name|CSD_1_RD_B_LEN_M
expr_stmt|;
ifdef|#
directive|ifdef
name|REPORT_SIZE
block|{
name|unsigned
name|int
name|mult
decl_stmt|,
name|blocknr
decl_stmt|;
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
name|CSD_2_C_SIZE_M_S
operator|)
operator|&
name|CSD_2_C_SIZE_M_M
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
name|CSD_1_CSIZE_H_S
operator|)
operator|&
name|CSD_1_CSIZE_H_M
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
name|CSD_2_CSIZE_L_S
operator|)
operator|&
name|CSD_2_CSIZE_L_M
operator|)
operator|)
operator|+
literal|1
operator|)
expr_stmt|;
name|MCI_Device
operator|.
name|Memory_Capacity
operator|=
operator|(
literal|1
operator|<<
name|MCI_Device
operator|.
name|READ_BL_LEN
operator|)
operator|*
name|blocknr
expr_stmt|;
name|printf
argument_list|(
literal|"Found SD card %u bytes\n"
argument_list|,
name|MCI_Device
operator|.
name|Memory_Capacity
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Select card and set block length for following transfers.
if|if
condition|(
name|MCI_SendCommand
argument_list|(
name|SEL_DESEL_CARD_CMD
argument_list|,
operator|(
name|MCI_Device
operator|.
name|RCA
operator|)
operator|<<
literal|16
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|MCI_SendCommand
argument_list|(
name|SET_BLOCKLEN_CMD
argument_list|,
name|SD_BLOCK_SIZE
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

end_unit

