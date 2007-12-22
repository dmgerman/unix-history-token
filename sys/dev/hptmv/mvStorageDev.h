begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 MARVELL SEMICONDUCTOR ISRAEL, LTD.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__INCmvStorageDevh
end_ifndef

begin_define
define|#
directive|define
name|__INCmvStorageDevh
end_define

begin_comment
comment|/* Definitions */
end_comment

begin_comment
comment|/* ATA register on the ATA drive*/
end_comment

begin_define
define|#
directive|define
name|MV_EDMA_ATA_FEATURES_ADDR
value|0x11
end_define

begin_define
define|#
directive|define
name|MV_EDMA_ATA_SECTOR_COUNT_ADDR
value|0x12
end_define

begin_define
define|#
directive|define
name|MV_EDMA_ATA_LBA_LOW_ADDR
value|0x13
end_define

begin_define
define|#
directive|define
name|MV_EDMA_ATA_LBA_MID_ADDR
value|0x14
end_define

begin_define
define|#
directive|define
name|MV_EDMA_ATA_LBA_HIGH_ADDR
value|0x15
end_define

begin_define
define|#
directive|define
name|MV_EDMA_ATA_DEVICE_ADDR
value|0x16
end_define

begin_define
define|#
directive|define
name|MV_EDMA_ATA_COMMAND_ADDR
value|0x17
end_define

begin_define
define|#
directive|define
name|MV_ATA_ERROR_STATUS
value|0x00000001
end_define

begin_comment
comment|/* MV_BIT0 */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_DATA_REQUEST_STATUS
value|0x00000008
end_define

begin_comment
comment|/* MV_BIT3 */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SERVICE_STATUS
value|0x00000010
end_define

begin_comment
comment|/* MV_BIT4 */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_DEVICE_FAULT_STATUS
value|0x00000020
end_define

begin_comment
comment|/* MV_BIT5 */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_READY_STATUS
value|0x00000040
end_define

begin_comment
comment|/* MV_BIT6 */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_BUSY_STATUS
value|0x00000080
end_define

begin_comment
comment|/* MV_BIT7 */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_SECTORS
value|0x20
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_SECTORS_EXT
value|0x24
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_VERIFY_SECTORS
value|0x40
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_VERIFY_SECTORS_EXT
value|0x42
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_BUFFER
value|0xE4
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_BUFFER
value|0xE8
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_SECTORS
value|0x30
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_SECTORS_EXT
value|0x34
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_DIAGNOSTIC
value|0x90
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_SMART
value|0xb0
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_MULTIPLE
value|0xc4
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_MULTIPLE
value|0xc5
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_STANDBY_IMMEDIATE
value|0xe0
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_IDLE_IMMEDIATE
value|0xe1
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_STANDBY
value|0xe2
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_IDLE
value|0xe3
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_SLEEP
value|0xe6
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_IDENTIFY
value|0xec
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_DEVICE_CONFIG
value|0xb1
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_SET_FEATURES
value|0xef
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_DMA
value|0xca
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_DMA_EXT
value|0x35
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_DMA_QUEUED
value|0xcc
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_DMA_QUEUED_EXT
value|0x36
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_WRITE_FPDMA_QUEUED_EXT
value|0x61
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_DMA
value|0xc8
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_DMA_EXT
value|0x25
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_DMA_QUEUED
value|0xc7
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_DMA_QUEUED_EXT
value|0x26
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_READ_FPDMA_QUEUED_EXT
value|0x60
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_FLUSH_CACHE
value|0xe7
end_define

begin_define
define|#
directive|define
name|MV_ATA_COMMAND_FLUSH_CACHE_EXT
value|0xea
end_define

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_DISABLE_8_BIT_PIO
value|0x01
end_define

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_ENABLE_WCACHE
value|0x02
end_define

begin_comment
comment|/* Enable write cache */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_TRANSFER
value|0x03
end_define

begin_comment
comment|/* Set transfer mode	*/
end_comment

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_UDMA_0
value|0x40
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_UDMA_1
value|0x41
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_UDMA_2
value|0x42
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_UDMA_3
value|0x43
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_UDMA_4
value|0x44
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_UDMA_5
value|0x45
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_UDMA_6
value|0x46
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_UDMA_7
value|0x47
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_PIO_SLOW
value|0x00
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_PIO_0
value|0x08
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_PIO_1
value|0x09
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_PIO_2
value|0x0A
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_PIO_3
value|0x0B
end_define

begin_define
define|#
directive|define
name|MV_ATA_TRANSFER_PIO_4
value|0x0C
end_define

begin_comment
comment|/* Enable advanced power management */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_ENABLE_APM
value|0x05
end_define

begin_comment
comment|/* Disable media status notification*/
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_DISABLE_MSN
value|0x31
end_define

begin_comment
comment|/* Disable read look-ahead		    */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_DISABLE_RLA
value|0x55
end_define

begin_comment
comment|/* Enable release interrupt		    */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_ENABLE_RI
value|0x5D
end_define

begin_comment
comment|/* Enable SERVICE interrupt		    */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_ENABLE_SI
value|0x5E
end_define

begin_comment
comment|/* Disable revert power-on defaults */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_DISABLE_RPOD
value|0x66
end_define

begin_comment
comment|/* Disable write cache			    */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_DISABLE_WCACHE
value|0x82
end_define

begin_comment
comment|/* Disable advanced power management*/
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_DISABLE_APM
value|0x85
end_define

begin_comment
comment|/* Enable media status notification */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_ENABLE_MSN
value|0x95
end_define

begin_comment
comment|/* Enable read look-ahead		    */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_ENABLE_RLA
value|0xAA
end_define

begin_comment
comment|/* Enable revert power-on defaults  */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_ENABLE_RPOD
value|0xCC
end_define

begin_comment
comment|/* Disable release interrupt	    */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_DISABLE_RI
value|0xDD
end_define

begin_comment
comment|/* Disable SERVICE interrupt	    */
end_comment

begin_define
define|#
directive|define
name|MV_ATA_SET_FEATURES_DISABLE_SI
value|0xDE
end_define

begin_comment
comment|/* Defines for parsing the IDENTIFY command results*/
end_comment

begin_define
define|#
directive|define
name|IDEN_SERIAL_NUM_OFFSET
value|10
end_define

begin_define
define|#
directive|define
name|IDEN_SERIAL_NUM_SIZE
value|19-10
end_define

begin_define
define|#
directive|define
name|IDEN_FIRMWARE_OFFSET
value|23
end_define

begin_define
define|#
directive|define
name|IDEN_FIRMWARE_SIZE
value|26-23
end_define

begin_define
define|#
directive|define
name|IDEN_MODEL_OFFSET
value|27
end_define

begin_define
define|#
directive|define
name|IDEN_MODEL_SIZE
value|46-27
end_define

begin_define
define|#
directive|define
name|IDEN_CAPACITY_1_OFFSET
value|49
end_define

begin_define
define|#
directive|define
name|IDEN_VALID
value|53
end_define

begin_define
define|#
directive|define
name|IDEN_NUM_OF_ADDRESSABLE_SECTORS
value|60
end_define

begin_define
define|#
directive|define
name|IDEN_PIO_MODE_SPPORTED
value|64
end_define

begin_define
define|#
directive|define
name|IDEN_QUEUE_DEPTH
value|75
end_define

begin_define
define|#
directive|define
name|IDEN_SATA_CAPABILITIES
value|76
end_define

begin_define
define|#
directive|define
name|IDEN_SATA_FEATURES_SUPPORTED
value|78
end_define

begin_define
define|#
directive|define
name|IDEN_SATA_FEATURES_ENABLED
value|79
end_define

begin_define
define|#
directive|define
name|IDEN_ATA_VERSION
value|80
end_define

begin_define
define|#
directive|define
name|IDEN_SUPPORTED_COMMANDS1
value|82
end_define

begin_define
define|#
directive|define
name|IDEN_SUPPORTED_COMMANDS2
value|83
end_define

begin_define
define|#
directive|define
name|IDEN_ENABLED_COMMANDS1
value|85
end_define

begin_define
define|#
directive|define
name|IDEN_ENABLED_COMMANDS2
value|86
end_define

begin_define
define|#
directive|define
name|IDEN_UDMA_MODE
value|88
end_define

begin_define
define|#
directive|define
name|IDEN_SATA_CAPABILITY
value|76
end_define

begin_comment
comment|/* Typedefs    */
end_comment

begin_comment
comment|/* Structures  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mvStorageDevRegisters
block|{
comment|/* Fields set by CORE driver */
name|MV_U8
name|errorRegister
decl_stmt|;
name|MV_U16
name|sectorCountRegister
decl_stmt|;
name|MV_U16
name|lbaLowRegister
decl_stmt|;
name|MV_U16
name|lbaMidRegister
decl_stmt|;
name|MV_U16
name|lbaHighRegister
decl_stmt|;
name|MV_U8
name|deviceRegister
decl_stmt|;
name|MV_U8
name|statusRegister
decl_stmt|;
block|}
name|MV_STORAGE_DEVICE_REGISTERS
typedef|;
end_typedef

begin_comment
comment|/* Bits for HD_ERROR */
end_comment

begin_define
define|#
directive|define
name|NM_ERR
value|0x02
end_define

begin_comment
comment|/* media present */
end_comment

begin_define
define|#
directive|define
name|ABRT_ERR
value|0x04
end_define

begin_comment
comment|/* Command aborted */
end_comment

begin_define
define|#
directive|define
name|MCR_ERR
value|0x08
end_define

begin_comment
comment|/* media change request */
end_comment

begin_define
define|#
directive|define
name|IDNF_ERR
value|0x10
end_define

begin_comment
comment|/* ID field not found */
end_comment

begin_define
define|#
directive|define
name|MC_ERR
value|0x20
end_define

begin_comment
comment|/* media changed */
end_comment

begin_define
define|#
directive|define
name|UNC_ERR
value|0x40
end_define

begin_comment
comment|/* Uncorrect data */
end_comment

begin_define
define|#
directive|define
name|WP_ERR
value|0x40
end_define

begin_comment
comment|/* write protect */
end_comment

begin_define
define|#
directive|define
name|ICRC_ERR
value|0x80
end_define

begin_comment
comment|/* new meaning:  CRC error during transfer */
end_comment

begin_comment
comment|/* Function */
end_comment

begin_function_decl
name|MV_BOOLEAN
name|HPTLIBAPI
name|mvStorageDevATAExecuteNonUDMACommand
parameter_list|(
name|MV_SATA_ADAPTER
modifier|*
name|pAdapter
parameter_list|,
name|MV_U8
name|channelIndex
parameter_list|,
name|MV_NON_UDMA_PROTOCOL
name|protocolType
parameter_list|,
name|MV_BOOLEAN
name|isEXT
parameter_list|,
name|MV_U16
name|FAR
modifier|*
name|bufPtr
parameter_list|,
name|MV_U32
name|count
parameter_list|,
name|MV_U16
name|features
parameter_list|,
name|MV_U16
name|sectorCount
parameter_list|,
name|MV_U16
name|lbaLow
parameter_list|,
name|MV_U16
name|lbaMid
parameter_list|,
name|MV_U16
name|lbaHigh
parameter_list|,
name|MV_U8
name|device
parameter_list|,
name|MV_U8
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MV_BOOLEAN
name|HPTLIBAPI
name|mvStorageDevATAIdentifyDevice
parameter_list|(
name|MV_SATA_ADAPTER
modifier|*
name|pAdapter
parameter_list|,
name|MV_U8
name|channelIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MV_BOOLEAN
name|HPTLIBAPI
name|mvStorageDevATASetFeatures
parameter_list|(
name|MV_SATA_ADAPTER
modifier|*
name|pAdapter
parameter_list|,
name|MV_U8
name|channelIndex
parameter_list|,
name|MV_U8
name|subCommand
parameter_list|,
name|MV_U8
name|subCommandSpecific1
parameter_list|,
name|MV_U8
name|subCommandSpecific2
parameter_list|,
name|MV_U8
name|subCommandSpecific3
parameter_list|,
name|MV_U8
name|subCommandSpecific4
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MV_BOOLEAN
name|HPTLIBAPI
name|mvStorageDevATAIdleImmediate
parameter_list|(
name|MV_SATA_ADAPTER
modifier|*
name|pAdapter
parameter_list|,
name|MV_U8
name|channelIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MV_BOOLEAN
name|HPTLIBAPI
name|mvStorageDevATAFlushWriteCache
parameter_list|(
name|MV_SATA_ADAPTER
modifier|*
name|pAdapter
parameter_list|,
name|MV_U8
name|channelIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MV_BOOLEAN
name|HPTLIBAPI
name|mvStorageDevATASoftResetDevice
parameter_list|(
name|MV_SATA_ADAPTER
modifier|*
name|pAdapter
parameter_list|,
name|MV_U8
name|channelIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MV_BOOLEAN
name|HPTLIBAPI
name|mvReadWrite
parameter_list|(
name|MV_SATA_CHANNEL
modifier|*
name|pSataChannel
parameter_list|,
name|LBA_T
name|Lba
parameter_list|,
name|UCHAR
name|Cmd
parameter_list|,
name|void
modifier|*
name|tmpBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

