begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/****************************************************************  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000 Adaptec Corporation.  * All rights reserved.  *  ****************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I2O_DPT_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|I2O_DPT_HDR
end_define

begin_define
define|#
directive|define
name|DPT_ORGANIZATION_ID
value|0x1B
end_define

begin_comment
comment|/* For Private Messages */
end_comment

begin_comment
comment|/*  *      PrivateMessageFrame.StdMessageFrame.Function = I2O_PRIVATE_MESSAGE  *      PrivateMessageFrame.XFunctionCode = I2O_SCSI_SCB_EXEC  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PRIVATE_SCSI_SCB_EXECUTE_MESSAGE
block|{
name|I2O_PRIVATE_MESSAGE_FRAME
name|PrivateMessageFrame
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|)
name|U32
name|TID
decl_stmt|;
comment|/* Upper four bits currently are zero */
else|#
directive|else
name|BF
name|TID
range|:
literal|16
decl_stmt|;
comment|/* Upper four bits currently are zero */
comment|/* Command is interpreted by the host */
name|BF
name|Interpret
range|:
literal|1
decl_stmt|;
comment|/* if TRUE, deal with Physical Firmware Array information */
name|BF
name|Physical
range|:
literal|1
decl_stmt|;
name|BF
name|Reserved1
range|:
literal|14
decl_stmt|;
endif|#
directive|endif
name|U8
name|CDBLength
decl_stmt|;
name|U8
name|Reserved
decl_stmt|;
name|I2O_SCB_FLAGS
name|SCBFlags
decl_stmt|;
name|U8
name|CDB
index|[
name|I2O_SCSI_CDB_LENGTH
index|]
decl_stmt|;
name|U32
name|ByteCount
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE
operator|,
typedef|*
name|PPRIVATE_SCSI_SCB_EXECUTE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/*  * Flash access and programming messages  *      PrivateMessageFrame.StdMessageFrame.Function = I2O_PRIVATE_MESSAGE  *      PrivateMessageFrame.XFunctionCode = PRIVATE_FLAGS_REGION_*  *  *      SIZE    returns the total size of a region of flash  *      READ    copies a region (or portion thereof) into the buffer specified  *              by the SGL  *      WRITE   writes a region (or portion thereof) using the data specified  *              by the SGL  *  * Flash regions  *  *      0               operational-mode firmware  *      1               software (bios/utility)  *      2               oem nvram defaults  *      3               hba serial number  *      4               boot-mode firmware  *  * Any combination of RegionOffset and ByteCount can be specified providing  * they fit within the size of the specified region.  *  * Flash messages should be targeted to the Executive TID 0x000  */
end_comment

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_SIZE
value|0x0100
end_define

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_READ
value|0x0101
end_define

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_WRITE
value|0x0102
end_define

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_CRC
value|0x0103
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PRIVATE_FLASH_REGION_MESSAGE
block|{
name|I2O_PRIVATE_MESSAGE_FRAME
name|PrivateMessageFrame
decl_stmt|;
name|U32
name|FlashRegion
decl_stmt|;
name|U32
name|RegionOffset
decl_stmt|;
name|U32
name|ByteCount
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|PRIVATE_FLASH_REGION_MESSAGE
operator|,
typedef|*
name|PPRIVATE_FLASH_REGION_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* DPT Driver Printf message */
end_comment

begin_define
define|#
directive|define
name|PRIVATE_DRIVER_PRINTF
value|0x0200
end_define

begin_comment
comment|/* FwPrintFlags */
end_comment

begin_define
define|#
directive|define
name|FW_FIRMWARE_FLAGS_NO_HEADER_B
value|0x00000001
end_define

begin_comment
comment|/* Remove date header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PRIVATE_DRIVER_PRINTF_MESSAGE
block|{
name|I2O_PRIVATE_MESSAGE_FRAME
name|PrivateMessageFrame
decl_stmt|;
comment|/* total bytes in PrintBuffer, including header */
name|U32
name|PrintBufferByteCount
decl_stmt|;
comment|/* exact data to be copied into the serial PrintBuffer */
name|U8
name|PrintBuffer
index|[
literal|1
index|]
decl_stmt|;
block|}
name|PRIVATE_DRIVER_PRINTF_MESSAGE
operator|,
typedef|*
name|PPRIVATE_DRIVER_PRINTF_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* DPT Enable Diagnostics message 0x0201 */
end_comment

begin_define
define|#
directive|define
name|PRIVATE_DIAG_ENABLE
value|0x0201
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PRIVATE_DIAG_ENABLE_MESSAGE
block|{
name|I2O_PRIVATE_MESSAGE_FRAME
name|PrivateMessageFrame
decl_stmt|;
block|}
name|PRIVATE_DIAG_MESSAGE_FRAME
operator|,
typedef|*
name|PPRIVATE_DIAG_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/* DPT Driver Get/Put message */
end_comment

begin_define
define|#
directive|define
name|PRIVATE_DRIVER_GET
value|0x300
end_define

begin_define
define|#
directive|define
name|PRIVATE_DRIVER_PUT
value|0x301
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PRIVATE_DRIVER_GETPUT_MESSAGE
block|{
name|I2O_PRIVATE_MESSAGE_FRAME
name|PrivateMessageFrame
decl_stmt|;
name|U32
name|Offset
decl_stmt|;
name|U32
name|ByteCount
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|PRIVATE_DRIVER_GETPUT_MESSAGE
operator|,
typedef|*
name|PPRIVATE_DRIVER_GETPUT_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* DPT Peripheral Device Parameter Groups */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* DPT Configuration and Operating Structures and Defines */
end_comment

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_GROUP_NO
value|0x8000
end_define

begin_comment
comment|/* - 8000h - DPT Device Information Parameters Group defines */
end_comment

begin_comment
comment|/* Device Type */
end_comment

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_DIRECT
value|I2O_SCSI_DEVICE_TYPE_DIRECT
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_SEQUENTIAL
value|I2O_SCSI_DEVICE_TYPE_SEQUENTIAL
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_PRINTER
value|I2O_SCSI_DEVICE_TYPE_PRINTER
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_PROCESSOR
value|I2O_SCSI_DEVICE_TYPE_PROCESSOR
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_WORM
value|I2O_SCSI_DEVICE_TYPE_WORM
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_CDROM
value|I2O_SCSI_DEVICE_TYPE_CDROM
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_SCANNER
value|I2O_SCSI_DEVICE_TYPE_SCANNER
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_OPTICAL
value|I2O_SCSI_DEVICE_TYPE_OPTICAL
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_MEDIA_CHANGER
value|I2O_SCSI_DEVICE_TYPE_MEDIA_CHANGER
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_COMM
value|I2O_SCSI_DEVICE_TYPE_COMM
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_GRAPHICS_1
value|I2O_SCSI_DEVICE_GRAPHICS_1
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_GRAPHICS_2
value|I2O_SCSI_DEVICE_GRAPHICS_2
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_ARRAY_CONT
value|I2O_SCSI_DEVICE_TYPE_ARRAY_CONT
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_TYPE_UNKNOWN
value|I2O_SCSI_DEVICE_TYPE_UNKNOWN
end_define

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|I2O_DPT_PERIPHERAL_TYPE_FLAG
value|I2O_SCSI_PERIPHERAL_TYPE_FLAG
end_define

begin_define
define|#
directive|define
name|I2O_DPT_PERIPHERAL_TYPE_PARALLEL
value|I2O_SCSI_PERIPHERAL_TYPE_PARALLEL
end_define

begin_define
define|#
directive|define
name|I2O_DPT_PERIPHERAL_TYPE_SERIAL
value|I2O_SCSI_PERIPHERAL_TYPE_SERIAL
end_define

begin_define
define|#
directive|define
name|I2O_DPT_RESERVED_FLAG
value|I2O_SCSI_RESERVED_FLAG
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DISCONNECT_FLAG
value|I2O_SCSI_DISCONNECT_FLAG
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DISABLE_DISCONNECT
value|I2O_SCSI_DISABLE_DISCONNECT
end_define

begin_define
define|#
directive|define
name|I2O_DPT_ENABLE_DISCONNECT
value|I2O_SCSI_ENABLE_DISCONNECT
end_define

begin_define
define|#
directive|define
name|I2O_DPT_MODE_MASK
value|I2O_SCSI_MODE_MASK
end_define

begin_define
define|#
directive|define
name|I2O_DPT_MODE_SET_DATA
value|I2O_SCSI_MODE_SET_DATA
end_define

begin_define
define|#
directive|define
name|I2O_DPT_MODE_SET_DEFAULT
value|I2O_SCSI_MODE_SET_DEFAULT
end_define

begin_define
define|#
directive|define
name|I2O_DPT_MODE_SET_SAFEST
value|I2O_SCSI_MODE_SET_SAFEST
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DATA_WIDTH_MASK
value|I2O_SCSI_DATA_WIDTH_MASK
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DATA_WIDTH_8
value|I2O_SCSI_DATA_WIDTH_8
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DATA_WIDTH_16
value|I2O_SCSI_DATA_WIDTH_16
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DATA_WIDTH_32
value|I2O_SCSI_DATA_WIDTH_32
end_define

begin_define
define|#
directive|define
name|I2O_DPT_SYNC_NEGOTIATION_FLAG
value|I2O_SCSI_SYNC_NEGOTIATION_FLAG
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DISABLE_SYNC_NEGOTIATION
value|I2O_SCSI_DISABLE_SYNC_NEGOTIATION
end_define

begin_define
define|#
directive|define
name|I2O_DPT_ENABLE_SYNC_NEGOTIATION
value|I2O_SCSI_ENABLE_SYNC_NEGOTIATION
end_define

begin_comment
comment|/* DPT Device Group 8000h - Device Information Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_DPT_DEVICE_INFO_SCALAR
block|{
name|U8
name|DeviceType
decl_stmt|;
comment|/* Identical to I2O_SCSI_DEVICE_INFO SCALAR */
name|U8
name|Flags
decl_stmt|;
comment|/* Identical to I2O_SCSI_DEVICE_INFO SCALAR */
name|U16
name|Bus
decl_stmt|;
name|U32
name|Identifier
decl_stmt|;
name|U8
name|LunInfo
index|[
literal|8
index|]
decl_stmt|;
comment|/* SCSI-2 8-bit scalar LUN goes into offset 1 */
block|}
name|I2O_DPT_DEVICE_INFO_SCALAR
operator|,
typedef|*
name|PI2O_DPT_DEVICE_INFO_SCALAR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I2O_DPT_EXEC_IOP_BUFFERS_GROUP_NO
value|0x8000
end_define

begin_comment
comment|/* DPT Exec Iop Buffers Group 8000h */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_DPT_EXEC_IOP_BUFFERS_SCALAR
block|{
name|U32
name|SerialOutputOffset
decl_stmt|;
comment|/* offset from base address to header   */
name|U32
name|SerialOutputSize
decl_stmt|;
comment|/* size of data buffer in bytes         */
name|U32
name|SerialHeaderSize
decl_stmt|;
comment|/* size of data buffer header in bytes  */
name|U32
name|SerialFlagsSupported
decl_stmt|;
comment|/* Mask of debug flags supported        */
block|}
name|I2O_DPT_EXEC_IOP_BUFFERS_SCALAR
operator|,
typedef|*
name|PI2O_DPT_EXEC_IOP_BUFFERS_SCALAR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I2O_DPT_HDR */
end_comment

end_unit

