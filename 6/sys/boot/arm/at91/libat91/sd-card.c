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
name|BUFFER_SIZE_MCI_DEVICE
value|512
end_define

begin_define
define|#
directive|define
name|MASTER_CLOCK
value|60000000
end_define

begin_comment
comment|//Private functions
end_comment

begin_comment
comment|//static void initInts(void);
end_comment

begin_function_decl
specifier|static
name|void
name|AT91F_MCI_Handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//* Global Variables
end_comment

begin_decl_stmt
name|AT91S_MciDeviceFeatures
name|MCI_Device_Features
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AT91S_MciDeviceDesc
name|MCI_Device_Desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AT91S_MciDevice
name|MCI_Device
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Buffer
index|[
name|BUFFER_SIZE_MCI_DEVICE
index|]
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
comment|//* \fn    AT91F_MCIDeviceWaitReady
end_comment

begin_comment
comment|//* \brief Wait for MCI Device ready
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|void
name|AT91F_MCIDeviceWaitReady
parameter_list|(
name|unsigned
name|int
name|timeout
parameter_list|)
block|{
specifier|volatile
name|int
name|status
decl_stmt|;
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
name|AT91C_MCI_NOTBUSY
operator|)
operator|&&
operator|(
name|timeout
operator|>
literal|0
operator|)
condition|)
do|;
if|#
directive|if
name|IMP_DEBUG
if|if
condition|(
name|timeout
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"Timeout, status is 0x%x\r\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|//TODO: Make interrupts work!
name|AT91F_MCI_Handler
argument_list|()
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_if
unit|int MCI_write (unsigned dest, char* source, unsigned length) { 	unsigned sectorLength = MCI_Device.pMCI_DeviceFeatures->Max_Read_DataBlock_Lenfgth; 	unsigned offset = dest % sectorLength; 	AT91S_MCIDeviceStatus status; 	int sizeToWrite;
if|#
directive|if
name|IMP_DEBUG
end_if

begin_endif
unit|printf("\r\n");
endif|#
directive|endif
end_endif

begin_comment
comment|//See if we are requested to write partial sectors, and have the capability to do so
end_comment

begin_comment
unit|if ((length % sectorLength)&& !(MCI_Device_Features.Write_Partial))
comment|//Return error if appropriat
end_comment

begin_comment
unit|return MCI_UNSUPP_SIZE_ERROR;
comment|//See if we are requested to write to anywhere but a sectors' boundary
end_comment

begin_comment
comment|//and have the capability to do so
end_comment

begin_comment
unit|if ((offset)&& !(MCI_Device_Features.Write_Partial))
comment|//Return error if appropriat
end_comment

begin_comment
unit|return MCI_UNSUPP_OFFSET_ERROR;
comment|//If the address we're trying to write != sector boundary
end_comment

begin_comment
unit|if (offset) 	{
comment|//* Wait MCI Device Ready
end_comment

begin_comment
unit|AT91F_MCIDeviceWaitReady(AT91C_MCI_TIMEOUT);
comment|//Calculate the nr of bytes to write
end_comment

begin_comment
unit|sizeToWrite = sectorLength - offset;
comment|//Do the writing
end_comment

begin_comment
unit|status = AT91F_MCI_WriteBlock(&MCI_Device, dest, (unsigned int*)source, sizeToWrite);
comment|//TODO:Status checking
end_comment

begin_comment
comment|//Update counters& pointers
end_comment

begin_comment
unit|length -= sizeToWrite; 		dest += sizeToWrite; 		source += sizeToWrite; 	}
comment|//As long as there is data to write
end_comment

begin_comment
unit|while (length) 	{
comment|//See if we've got at least a sector to write
end_comment

begin_comment
unit|if (length> sectorLength)  			sizeToWrite = sectorLength;
comment|//Else just write the remainder
end_comment

begin_comment
unit|else 			sizeToWrite = length;  		AT91F_MCIDeviceWaitReady(AT91C_MCI_TIMEOUT);
comment|//Do the writing
end_comment

begin_comment
unit|status = AT91F_MCI_WriteBlock(&MCI_Device, dest, (unsigned int*)source, sizeToWrite);
comment|//TODO:Status checking
end_comment

begin_comment
comment|//Update counters& pointers
end_comment

begin_endif
unit|length -= sizeToWrite; 		dest += sizeToWrite; 		source += sizeToWrite; 	}  	return 0; }
endif|#
directive|endif
end_endif

begin_function
specifier|inline
specifier|static
name|unsigned
name|int
name|swap
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|a
operator|&
literal|0xff
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|a
operator|&
literal|0xff00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|a
operator|&
literal|0xff0000
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
operator|(
name|a
operator|&
literal|0xff000000
operator|)
operator|>>
literal|24
operator|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|MCI_read
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
name|unsigned
name|source
parameter_list|,
name|unsigned
name|length
parameter_list|)
block|{
name|unsigned
name|sectorLength
init|=
name|MCI_Device
operator|.
name|pMCI_DeviceFeatures
operator|->
name|Max_Read_DataBlock_Length
decl_stmt|;
name|unsigned
name|log2sl
init|=
name|MCI_Device
operator|.
name|pMCI_DeviceFeatures
operator|->
name|READ_BL_LEN
decl_stmt|;
name|unsigned
name|slmask
init|=
operator|(
operator|(
literal|1
operator|<<
name|log2sl
operator|)
operator|-
literal|1
operator|)
decl_stmt|;
comment|//	unsigned sector = (unsigned)source>> log2sl;
name|unsigned
name|offset
init|=
operator|(
name|unsigned
operator|)
name|source
operator|&
name|slmask
decl_stmt|;
name|AT91S_MCIDeviceStatus
name|status
decl_stmt|;
name|int
name|sizeToRead
decl_stmt|;
name|unsigned
name|int
modifier|*
name|walker
decl_stmt|;
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"Reading 0x%x bytes into ARM Addr 0x%x from card offset 0x%x\r\n"
argument_list|,
name|length
argument_list|,
name|dest
argument_list|,
name|source
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|//See if we are requested to read partial sectors, and have the capability to do so
if|if
condition|(
operator|(
name|length
operator|&
name|slmask
operator|)
operator|&&
operator|!
operator|(
name|MCI_Device_Features
operator|.
name|Read_Partial
operator|)
condition|)
comment|//Return error if appropriat
return|return
name|MCI_UNSUPP_SIZE_ERROR
return|;
comment|//See if we are requested to read from anywhere but a sectors' boundary
comment|//and have the capability to do so
if|if
condition|(
operator|(
name|offset
operator|)
operator|&&
operator|!
operator|(
name|MCI_Device_Features
operator|.
name|Read_Partial
operator|)
condition|)
comment|//Return error if appropriat
return|return
name|MCI_UNSUPP_OFFSET_ERROR
return|;
comment|//If the address we're trying to read != sector boundary
if|if
condition|(
name|offset
condition|)
block|{
comment|//* Wait MCI Device Ready
name|AT91F_MCIDeviceWaitReady
argument_list|(
name|AT91C_MCI_TIMEOUT
argument_list|)
expr_stmt|;
comment|//Calculate the nr of bytes to read
name|sizeToRead
operator|=
name|sectorLength
operator|-
name|offset
expr_stmt|;
comment|//Do the writing
name|status
operator|=
name|AT91F_MCI_ReadBlock
argument_list|(
operator|&
name|MCI_Device
argument_list|,
name|source
argument_list|,
operator|(
name|unsigned
name|int
operator|*
operator|)
name|dest
argument_list|,
name|sizeToRead
argument_list|)
expr_stmt|;
comment|//TODO:Status checking
if|if
condition|(
name|status
operator|!=
name|AT91C_READ_OK
condition|)
block|{
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"STATUS is 0x%x\r\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|-
literal|1
return|;
block|}
comment|//* Wait MCI Device Ready
name|AT91F_MCIDeviceWaitReady
argument_list|(
name|AT91C_MCI_TIMEOUT
argument_list|)
expr_stmt|;
comment|// Fix erratum in MCI part
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
name|sizeToRead
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
comment|//Update counters& pointers
name|length
operator|-=
name|sizeToRead
expr_stmt|;
name|dest
operator|+=
name|sizeToRead
expr_stmt|;
name|source
operator|+=
name|sizeToRead
expr_stmt|;
block|}
comment|//As long as there is data to read
while|while
condition|(
name|length
condition|)
block|{
comment|//See if we've got at least a sector to read
if|if
condition|(
name|length
operator|>
name|sectorLength
condition|)
name|sizeToRead
operator|=
name|sectorLength
expr_stmt|;
comment|//Else just write the remainder
else|else
name|sizeToRead
operator|=
name|length
expr_stmt|;
name|AT91F_MCIDeviceWaitReady
argument_list|(
name|AT91C_MCI_TIMEOUT
argument_list|)
expr_stmt|;
comment|//Do the writing
name|status
operator|=
name|AT91F_MCI_ReadBlock
argument_list|(
operator|&
name|MCI_Device
argument_list|,
name|source
argument_list|,
operator|(
name|unsigned
name|int
operator|*
operator|)
name|dest
argument_list|,
name|sizeToRead
argument_list|)
expr_stmt|;
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"Reading 0x%x Addr 0x%x card 0x%x\r\n"
argument_list|,
name|sizeToRead
argument_list|,
name|dest
argument_list|,
name|source
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|//TODO:Status checking
if|if
condition|(
name|status
operator|!=
name|AT91C_READ_OK
condition|)
block|{
if|#
directive|if
name|IMP_DEBUG
name|printf
argument_list|(
literal|"STATUS is 0x%x\r\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|-
literal|1
return|;
block|}
comment|//* Wait MCI Device Ready
name|AT91F_MCIDeviceWaitReady
argument_list|(
name|AT91C_MCI_TIMEOUT
argument_list|)
expr_stmt|;
comment|// Fix erratum in MCI part
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
name|sizeToRead
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
comment|//Update counters& pointers
name|length
operator|-=
name|sizeToRead
expr_stmt|;
name|dest
operator|+=
name|sizeToRead
expr_stmt|;
name|source
operator|+=
name|sizeToRead
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
comment|//* \fn    AT91F_CfgDevice
end_comment

begin_comment
comment|//* \brief This function is used to initialise MMC or SDCard Features
end_comment

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_function
specifier|static
name|void
name|AT91F_CfgDevice
parameter_list|(
name|void
parameter_list|)
block|{
comment|// Init Device Structure
name|MCI_Device_Features
operator|.
name|Relative_Card_Address
operator|=
literal|0
expr_stmt|;
name|MCI_Device_Features
operator|.
name|Card_Inserted
operator|=
name|AT91C_SD_CARD_INSERTED
expr_stmt|;
name|MCI_Device_Features
operator|.
name|Max_Read_DataBlock_Length
operator|=
literal|0
expr_stmt|;
name|MCI_Device_Features
operator|.
name|Max_Write_DataBlock_Length
operator|=
literal|0
expr_stmt|;
name|MCI_Device_Features
operator|.
name|Read_Partial
operator|=
literal|0
expr_stmt|;
name|MCI_Device_Features
operator|.
name|Write_Partial
operator|=
literal|0
expr_stmt|;
name|MCI_Device_Features
operator|.
name|Erase_Block_Enable
operator|=
literal|0
expr_stmt|;
name|MCI_Device_Features
operator|.
name|Sector_Size
operator|=
literal|0
expr_stmt|;
name|MCI_Device_Features
operator|.
name|Memory_Capacity
operator|=
literal|0
expr_stmt|;
name|MCI_Device_Desc
operator|.
name|state
operator|=
name|AT91C_MCI_IDLE
expr_stmt|;
name|MCI_Device_Desc
operator|.
name|SDCard_bus_width
operator|=
name|AT91C_MCI_SCDBUS
expr_stmt|;
name|MCI_Device
operator|.
name|pMCI_DeviceDesc
operator|=
operator|&
name|MCI_Device_Desc
expr_stmt|;
name|MCI_Device
operator|.
name|pMCI_DeviceFeatures
operator|=
operator|&
name|MCI_Device_Features
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|AT91F_MCI_Handler
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|status
decl_stmt|;
comment|//	status = ( AT91C_BASE_MCI->MCI_SR& AT91C_BASE_MCI->MCI_IMR );
name|status
operator|=
name|AT91C_BASE_MCI
operator|->
name|MCI_SR
expr_stmt|;
name|AT91F_MCI_Device_Handler
argument_list|(
operator|&
name|MCI_Device
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//*----------------------------------------------------------------------------
end_comment

begin_comment
comment|//* \fn    main
end_comment

begin_comment
comment|//* \brief main function
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
comment|///////////////////////////////////////////////////////////////////////////////
comment|//  MCI Init : common to MMC and SDCard
comment|///////////////////////////////////////////////////////////////////////////////
comment|//initInts();
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
comment|// Init MCI Device Structures
name|AT91F_CfgDevice
argument_list|()
expr_stmt|;
name|AT91F_MCI_Configure
argument_list|(
name|AT91C_BASE_MCI
argument_list|,
name|AT91C_MCI_DTOR_1MEGA_CYCLES
argument_list|,
name|AT91C_MCI_MR_PDCMODE
argument_list|,
comment|// 15MHz for MCK = 60MHz (CLKDIV = 1)
name|AT91C_MCI_SDCARD_4BITS_SLOTA
argument_list|)
expr_stmt|;
if|if
condition|(
name|AT91F_MCI_SDCard_Init
argument_list|(
operator|&
name|MCI_Device
argument_list|)
operator|!=
name|AT91C_INIT_OK
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

