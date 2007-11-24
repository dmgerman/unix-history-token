begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATAPI_H_
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/***************************************************************************  *            IDE IO Register File  ***************************************************************************/
end_comment

begin_comment
comment|/*  * IDE IO Port definition  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IDE_REGISTERS_1
block|{
name|USHORT
name|Data
decl_stmt|;
comment|/* RW: Data port feature register      */
name|UCHAR
name|BlockCount
decl_stmt|;
comment|/* RW: Sector count               */
name|UCHAR
name|BlockNumber
decl_stmt|;
comment|/* RW: Sector number& LBA 0-7    */
name|UCHAR
name|CylinderLow
decl_stmt|;
comment|/* RW: Cylinder low& LBA 8-15    */
name|UCHAR
name|CylinderHigh
decl_stmt|;
comment|/* RW: Cylinder hign& LBA 16-23  */
name|UCHAR
name|DriveSelect
decl_stmt|;
comment|/* RW: Drive/head& LBA 24-27     */
name|UCHAR
name|Command
decl_stmt|;
comment|/* RO: Status WR:Command          */
block|}
name|IDE_REGISTERS_1
operator|,
typedef|*
name|PIDE_REGISTERS_1
typedef|;
end_typedef

begin_comment
comment|/*  * IDE status definitions  */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_ERROR
value|0x01
end_define

begin_comment
comment|/* Error Occurred in Execution    */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_INDEX
value|0x02
end_define

begin_comment
comment|/* is vendor specific             */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_CORRECTED_ERROR
value|0x04
end_define

begin_comment
comment|/* Corrected Data                 */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_DRQ
value|0x08
end_define

begin_comment
comment|/* Ready to transfer data         */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_DSC
value|0x10
end_define

begin_comment
comment|/* not defined in ATA-2           */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_DWF
value|0x20
end_define

begin_comment
comment|/* Device Fault has been detected */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_DRDY
value|0x40
end_define

begin_comment
comment|/* Device Ready to accept command */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_IDLE
value|0x50
end_define

begin_comment
comment|/* Device is OK                   */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_BUSY
value|0x80
end_define

begin_comment
comment|/* Device Busy, must wait         */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_BAD_BLOCK
value|0x80
end_define

begin_comment
comment|/* Reserved now                   */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_DATA_ERROR
value|0x40
end_define

begin_comment
comment|/* Uncorreectable  Data Error     */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_MEDIA_CHANGE
value|0x20
end_define

begin_comment
comment|/* Media Changed                  */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_ID_NOT_FOUND
value|0x10
end_define

begin_comment
comment|/* ID Not Found                   */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_MEDIA_CHANGE_REQ
value|0x08
end_define

begin_comment
comment|/* Media Change Requested         */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_COMMAND_ABORTED
value|0x04
end_define

begin_comment
comment|/* Aborted Command                */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_TRACK0_NOT_FOUND
value|0x02
end_define

begin_comment
comment|/* Track 0 Not Found              */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_ADDRESS_NOT_FOUND
value|0x01
end_define

begin_comment
comment|/* Address Mark Not Found         */
end_comment

begin_define
define|#
directive|define
name|LBA_MODE
value|0x40
end_define

begin_comment
comment|/*  * IDE command definitions  */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_RECALIBRATE
value|0x10
end_define

begin_comment
comment|/* Recalibrate                    */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_READ
value|0x20
end_define

begin_comment
comment|/* Read Sectors with retry        */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_WRITE
value|0x30
end_define

begin_comment
comment|/* Write Sectors with retry       */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_VERIFY
value|0x40
end_define

begin_comment
comment|/* Read Verify Sectors with Retry */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_SEEK
value|0x70
end_define

begin_comment
comment|/* Seek                           */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_SET_DRIVE_PARAMETER
value|0x91
end_define

begin_comment
comment|/* Initialize Device Parmeters */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_GET_MEDIA_STATUS
value|0xDA
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_DOOR_LOCK
value|0xDE
end_define

begin_comment
comment|/* Door Lock                      */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_DOOR_UNLOCK
value|0xDF
end_define

begin_comment
comment|/* Door Unlock                          */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_ENABLE_MEDIA_STATUS
value|0xEF
end_define

begin_comment
comment|/* Set Features              */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_IDENTIFY
value|0xEC
end_define

begin_comment
comment|/* Identify Device                */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_MEDIA_EJECT
value|0xED
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_SET_FEATURES
value|0xEF
end_define

begin_comment
comment|/* IDE set features command       */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_FLUSH_CACHE
value|0xE7
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_STANDBY_IMMEDIATE
value|0xE0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_SUPPORT_MULTIPLE
end_ifndef

begin_define
define|#
directive|define
name|IDE_COMMAND_READ_MULTIPLE
value|0xC4
end_define

begin_comment
comment|/* Read Multiple                  */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_WRITE_MULTIPLE
value|0xC5
end_define

begin_comment
comment|/* Write Multiple                 */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_SET_MULTIPLE
value|0xC6
end_define

begin_comment
comment|/* Set Multiple Mode              */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_SUPPORT_DMA
end_ifndef

begin_define
define|#
directive|define
name|IDE_COMMAND_DMA_READ
value|0xc8
end_define

begin_comment
comment|/* IDE DMA read command           */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_DMA_WRITE
value|0xca
end_define

begin_comment
comment|/* IDE DMA write command          */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IDE_COMMAND_READ_DMA_QUEUE
value|0xc7
end_define

begin_comment
comment|/* IDE read DMA queue command     */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_WRITE_DMA_QUEUE
value|0xcc
end_define

begin_comment
comment|/* IDE write DMA queue command    */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_SERVICE
value|0xA2
end_define

begin_comment
comment|/* IDE service command command    */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_NOP
value|0x00
end_define

begin_comment
comment|/* IDE NOP command                */
end_comment

begin_define
define|#
directive|define
name|IDE_STATUS_SRV
value|0x10
end_define

begin_define
define|#
directive|define
name|IDE_RELEASE_BUS
value|4
end_define

begin_comment
comment|/*#define IDE_COMMAND_FLUSH_CACHE_EXT */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_READ_DMA_EXT
value|0x25
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_READ_QUEUE_EXT
value|0x26
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_READ_MULTIPLE_EXT
value|0x29
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_READ_MAX_ADDR
value|0x27
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_READ_EXT
value|0x24
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_VERIFY_EXT
value|0x42
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_SET_MULTIPLE_EXT
value|0x37
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_WRITE_DMA_EXT
value|0x35
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_WRITE_QUEUE_EXT
value|0x36
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_WRITE_EXT
value|0x34
end_define

begin_define
define|#
directive|define
name|IDE_COMMAND_WRITE_MULTIPLE_EXT
value|0x39
end_define

begin_comment
comment|/*  * IDE_COMMAND_SET_FEATURES  */
end_comment

begin_define
define|#
directive|define
name|FT_USE_ULTRA
value|0x40
end_define

begin_comment
comment|/* Set feature for Ultra DMA           */
end_comment

begin_define
define|#
directive|define
name|FT_USE_MWDMA
value|0x20
end_define

begin_comment
comment|/* Set feature for MW DMA              */
end_comment

begin_define
define|#
directive|define
name|FT_USE_SWDMA
value|0x10
end_define

begin_comment
comment|/* Set feature for SW DMA              */
end_comment

begin_define
define|#
directive|define
name|FT_USE_PIO
value|0x8
end_define

begin_comment
comment|/* Set feature for PIO                 */
end_comment

begin_define
define|#
directive|define
name|FT_DISABLE_IORDY
value|0x10
end_define

begin_comment
comment|/* Set feature for disabling IORDY     */
end_comment

begin_comment
comment|/*  * S.M.A.R.T. commands  */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_SMART
value|0xB0
end_define

begin_define
define|#
directive|define
name|SMART_READ_VALUES
value|0xd0
end_define

begin_define
define|#
directive|define
name|SMART_READ_THRESHOLDS
value|0xd1
end_define

begin_define
define|#
directive|define
name|SMART_AUTOSAVE
value|0xd2
end_define

begin_define
define|#
directive|define
name|SMART_SAVE
value|0xd3
end_define

begin_define
define|#
directive|define
name|SMART_IMMEDIATE_OFFLINE
value|0xd4
end_define

begin_define
define|#
directive|define
name|SMART_READ_LOG_SECTOR
value|0xd5
end_define

begin_define
define|#
directive|define
name|SMART_WRITE_LOG_SECTOR
value|0xd6
end_define

begin_define
define|#
directive|define
name|SMART_ENABLE
value|0xd8
end_define

begin_define
define|#
directive|define
name|SMART_DISABLE
value|0xd9
end_define

begin_define
define|#
directive|define
name|SMART_STATUS
value|0xda
end_define

begin_define
define|#
directive|define
name|SMART_AUTO_OFFLINE
value|0xdb
end_define

begin_comment
comment|/***************************************************************************  *            IDE Control Register File  ***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IDE_REGISTERS_2
block|{
name|UCHAR
name|AlternateStatus
decl_stmt|;
comment|/* RW: device control port        */
block|}
name|IDE_REGISTERS_2
operator|,
typedef|*
name|PIDE_REGISTERS_2
typedef|;
end_typedef

begin_comment
comment|/*  * IDE drive control definitions  */
end_comment

begin_define
define|#
directive|define
name|IDE_DC_DISABLE_INTERRUPTS
value|0x02
end_define

begin_define
define|#
directive|define
name|IDE_DC_RESET_CONTROLLER
value|0x04
end_define

begin_define
define|#
directive|define
name|IDE_DC_REENABLE_CONTROLLER
value|0x00
end_define

begin_comment
comment|/***************************************************************************  *   MSNS:   Removable device  ***************************************************************************/
end_comment

begin_comment
comment|/*  * Media syatus  */
end_comment

begin_define
define|#
directive|define
name|MSNS_NO_MEDIA
value|2
end_define

begin_define
define|#
directive|define
name|MSNS_MEDIA_CHANGE_REQUEST
value|8
end_define

begin_define
define|#
directive|define
name|MSNS_MIDIA_CHANGE
value|0x20
end_define

begin_define
define|#
directive|define
name|MSNS_WRITE_PROTECT
value|0x40
end_define

begin_define
define|#
directive|define
name|MSNS_READ_PROTECT
value|0x80
end_define

begin_comment
comment|/***************************************************************************  *            ATAPI IO Register File  ***************************************************************************/
end_comment

begin_comment
comment|/*  * ATAPI register definition  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATAPI_REGISTERS_1
block|{
name|USHORT
name|Data
decl_stmt|;
name|UCHAR
name|InterruptReason
decl_stmt|;
comment|/* Atapi Phase Port               */
name|UCHAR
name|Unused1
decl_stmt|;
name|UCHAR
name|ByteCountLow
decl_stmt|;
comment|/* Byte Count LSB                 */
name|UCHAR
name|ByteCountHigh
decl_stmt|;
comment|/* Byte Count MSB                 */
name|UCHAR
name|DriveSelect
decl_stmt|;
name|UCHAR
name|Command
decl_stmt|;
block|}
name|ATAPI_REGISTERS_1
operator|,
typedef|*
name|PATAPI_REGISTERS_1
typedef|;
end_typedef

begin_comment
comment|/*  *    Atapi Error Status  */
end_comment

begin_define
define|#
directive|define
name|IDE_ERROR_END_OF_MEDIA
value|IDE_ERROR_TRACK0_NOT_FOUND
end_define

begin_define
define|#
directive|define
name|IDE_ERROR_ILLEGAL_LENGTH
value|IDE_ERROR_ADDRESS_NOT_FOUND
end_define

begin_comment
comment|/*  * ATAPI interrupt reasons  */
end_comment

begin_define
define|#
directive|define
name|ATAPI_IR_COD
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_IR_IO
value|0x02
end_define

begin_comment
comment|/* sense key */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SENSE_NO_SENSE
value|0x00
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_RECOVERED_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_NOT_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_MEDIUM_ERROR
value|0x03
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_HARDWARE_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_ILLEGAL_REQUEST
value|0x05
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_UNIT_ATTENTION
value|0x06
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_DATA_PROTECT
value|0x07
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_BLANK_CHECK
value|0x08
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_UNIQUE
value|0x09
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_COPY_ABORTED
value|0x0A
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_ABORTED_COMMAND
value|0x0B
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_EQUAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_VOL_OVERFLOW
value|0x0D
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_MISCOMPARE
value|0x0E
end_define

begin_define
define|#
directive|define
name|ATAPI_SENSE_RESERVED
value|0x0F
end_define

begin_comment
comment|/* Additional Sense codes */
end_comment

begin_define
define|#
directive|define
name|ATAPI_ASC_NO_SENSE
value|0x00
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_LUN_NOT_READY
value|0x04
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_TRACK_ERROR
value|0x14
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_SEEK_ERROR
value|0x15
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_REC_DATA_NOECC
value|0x17
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_REC_DATA_ECC
value|0x18
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_ILLEGAL_COMMAND
value|0x20
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_ILLEGAL_BLOCK
value|0x21
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_INVALID_CDB
value|0x24
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_INVALID_LUN
value|0x25
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_PROTECT
value|0x27
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_MEDIUM_CHANGED
value|0x28
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_BUS_RESET
value|0x29
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_NO_MEDIA_IN_DEVICE
value|0x3a
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_MUSIC_AREA
value|0xA0
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_DATA_AREA
value|0xA1
end_define

begin_define
define|#
directive|define
name|ATAPI_ASC_VOLUME_OVERFLOW
value|0xA7
end_define

begin_comment
comment|/*  * IDE command definitions ( for ATAPI )  */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_ATAPI_RESET
value|0x08
end_define

begin_comment
comment|/* Atapi Software Reset command   */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_ATAPI_PACKET
value|0xA0
end_define

begin_comment
comment|/* Atapi Identify command         */
end_comment

begin_define
define|#
directive|define
name|IDE_COMMAND_ATAPI_IDENTIFY
value|0xA1
end_define

begin_comment
comment|/* Atapi Packet Command           */
end_comment

begin_comment
comment|/*  * ATAPI command definitions  */
end_comment

begin_define
define|#
directive|define
name|ATAPI_TEST_UNIT_READY
value|0x00
end_define

begin_define
define|#
directive|define
name|ATAPI_REZERO_UNIT
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|ATAPI_FORMAT_UNIT6
value|0x04
end_define

begin_define
define|#
directive|define
name|ATAPI_FORMAT_UNIT
value|0x24
end_define

begin_define
define|#
directive|define
name|ATAPI_INQUIRY
value|0x12
end_define

begin_define
define|#
directive|define
name|ATAPI_MODE_SELECT
value|0x15
end_define

begin_define
define|#
directive|define
name|ATAPI_RELEASE6
value|0x17
end_define

begin_define
define|#
directive|define
name|ATAPI_MODE_SENSE
value|0x1A
end_define

begin_define
define|#
directive|define
name|ATAPI_START_STOP_UNIT
value|0x1B
end_define

begin_define
define|#
directive|define
name|ATAPI_LOAD_UNLOAD
value|0x1B
end_define

begin_define
define|#
directive|define
name|ATAPI_RECEIVE_DIAGNOSTIC
value|0x1C
end_define

begin_define
define|#
directive|define
name|ATAPI_SEND_DIAGNOSTIC
value|0x1D
end_define

begin_define
define|#
directive|define
name|ATAPI_MEDIUM_REMOVAL
value|0x1E
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_FORMAT_CAPACITY
value|0x23
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_CAPACITY
value|0x25
end_define

begin_define
define|#
directive|define
name|ATAPI_READ
value|0x28
end_define

begin_define
define|#
directive|define
name|ATAPI_WRITE
value|0x2A
end_define

begin_define
define|#
directive|define
name|ATAPI_SEEK
value|0x2B
end_define

begin_define
define|#
directive|define
name|ATAPI_ERASE
value|0x2C
end_define

begin_define
define|#
directive|define
name|ATAPI_VERIFY
value|0x2F
end_define

begin_define
define|#
directive|define
name|ATAPI_WRITE_VERIFY
value|0x2E
end_define

begin_define
define|#
directive|define
name|ATAPI_SYNCHRONIZE_CACHE
value|0x35
end_define

begin_define
define|#
directive|define
name|ATAPI_LOCK_CACHE
value|0x36
end_define

begin_define
define|#
directive|define
name|ATAPI_COMPARE
value|0x39
end_define

begin_define
define|#
directive|define
name|ATAPI_WRITE_BUFFER
value|0x3B
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_DATA_BUFF
value|0x3C
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_SUB_CHANNEL
value|0x42
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_TOC
value|0x43
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_HEADER
value|0x44
end_define

begin_define
define|#
directive|define
name|ATAPI_PLAY_AUDIO10
value|0x45
end_define

begin_define
define|#
directive|define
name|ATAPI_GET_CONFIGURATION
value|0x46
end_define

begin_define
define|#
directive|define
name|ATAPI_PLAY_AUDIO_MSF
value|0x47
end_define

begin_define
define|#
directive|define
name|ATAPI_GET_EVENT_STATUS_NOTIFICATION
value|0x4A
end_define

begin_define
define|#
directive|define
name|ATAPI_PAUSE_RESUME
value|0x4B
end_define

begin_define
define|#
directive|define
name|ATAPI_LOG_SELECT
value|0x4C
end_define

begin_define
define|#
directive|define
name|ATAPI_LOG_SENSE
value|0x4D
end_define

begin_define
define|#
directive|define
name|ATAPI_STOP_PLAY_SCAN
value|0x4E
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_DISK_INFORMATION
value|0x51
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_TRACK_INFORMATION
value|0x52
end_define

begin_define
define|#
directive|define
name|ATAPI_RESERVE_TRACK_RZONE
value|0x53
end_define

begin_define
define|#
directive|define
name|ATAPI_SEND_OPC_INFORMATION
value|0x54
end_define

begin_define
define|#
directive|define
name|ATAPI_MODE_SELECT10
value|0x55
end_define

begin_define
define|#
directive|define
name|ATAPI_RELEASE10
value|0x57
end_define

begin_define
define|#
directive|define
name|ATAPI_REPAIR_ZONE
value|0x58
end_define

begin_define
define|#
directive|define
name|ATAPI_MODE_SENSE10
value|0x5A
end_define

begin_define
define|#
directive|define
name|ATAPI_CLOSE_TRACK_SESSION
value|0x5B
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_BUFFER_CAPACITY
value|0x5C
end_define

begin_define
define|#
directive|define
name|ATAPI_SEND_CUE_SHEET
value|0x5D
end_define

begin_define
define|#
directive|define
name|ATAPI_BLANK_COMMAND
value|0xA1
end_define

begin_comment
comment|/*Provide the ability to erase any part of a CD-RW disc.*/
end_comment

begin_define
define|#
directive|define
name|ATAPI_SEND_EVENT
value|0xA2
end_define

begin_comment
comment|/* add for DVD */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SEND_KEY
value|0xA3
end_define

begin_comment
comment|/* add for DVD  */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REPORT_KEY
value|0xA4
end_define

begin_define
define|#
directive|define
name|ATAPI_PLAY_AUDIO
value|0xA5
end_define

begin_define
define|#
directive|define
name|ATAPI_LOAD_UNLOAD_MEDIUM
value|0xA6
end_define

begin_define
define|#
directive|define
name|ATAPI_SET_READ_AHEAD
value|0xA7
end_define

begin_define
define|#
directive|define
name|ATAPI_READ12
value|0xA8
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_DVD_STRUCTURE
value|0xAD
end_define

begin_define
define|#
directive|define
name|ATAPI_WRITE12
value|0xAA
end_define

begin_define
define|#
directive|define
name|ATAPI_GET_PERFORM_NOTIFICATION
value|0xAC
end_define

begin_comment
comment|/* add for DVD-RW */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SET_STREAM
value|0xB6
end_define

begin_comment
comment|/* add for DVD-RW */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_CD_MSF
value|0xB9
end_define

begin_define
define|#
directive|define
name|ATAPI_SCAN
value|0xBA
end_define

begin_define
define|#
directive|define
name|ATAPI_SET_SPEED
value|0xBB
end_define

begin_comment
comment|/* no payload  */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MECHANISM_STATUS
value|0xBD
end_define

begin_define
define|#
directive|define
name|ATAPI_READ_CD
value|0xBE
end_define

begin_define
define|#
directive|define
name|ATAPI_SEND_DVD_STRUCTURE
value|0xBF
end_define

begin_define
define|#
directive|define
name|ATAPI_SET_CDRW_SPEED
value|0xDA
end_define

begin_comment
comment|/*WindowsXP need*/
end_comment

begin_define
define|#
directive|define
name|MODE_DSP_WRITE_PROTECT
value|0x80
end_define

begin_comment
comment|/***************************************************************************  *            ATAPI IO Register File  ***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATAPI_REGISTERS_2
block|{
name|UCHAR
name|AlternateStatus
decl_stmt|;
block|}
name|ATAPI_REGISTERS_2
operator|,
typedef|*
name|PATAPI_REGISTERS_2
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************  *            ATAPI packets  ***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATAPI_SENSE_DATA
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|UCHAR
name|Valid
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ErrorCode
range|:
literal|7
decl_stmt|;
name|UCHAR
name|SegmentNumber
decl_stmt|;
name|UCHAR
name|FileMark
range|:
literal|1
decl_stmt|;
name|UCHAR
name|EndOfMedia
range|:
literal|1
decl_stmt|;
name|UCHAR
name|IncorrectLength
range|:
literal|1
decl_stmt|;
name|UCHAR
name|Reserved
range|:
literal|1
decl_stmt|;
name|UCHAR
name|SenseKey
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|UCHAR
name|ErrorCode
range|:
literal|7
decl_stmt|;
name|UCHAR
name|Valid
range|:
literal|1
decl_stmt|;
name|UCHAR
name|SegmentNumber
decl_stmt|;
name|UCHAR
name|SenseKey
range|:
literal|4
decl_stmt|;
name|UCHAR
name|Reserved
range|:
literal|1
decl_stmt|;
name|UCHAR
name|IncorrectLength
range|:
literal|1
decl_stmt|;
name|UCHAR
name|EndOfMedia
range|:
literal|1
decl_stmt|;
name|UCHAR
name|FileMark
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
name|UCHAR
name|Information
index|[
literal|4
index|]
decl_stmt|;
name|UCHAR
name|AdditionalSenseLength
decl_stmt|;
name|UCHAR
name|CommandSpecificInformation
index|[
literal|4
index|]
decl_stmt|;
name|UCHAR
name|AdditionalSenseCode
decl_stmt|;
name|UCHAR
name|AdditionalSenseCodeQualifier
decl_stmt|;
name|UCHAR
name|FieldReplaceableUnitCode
decl_stmt|;
name|UCHAR
name|SenseKeySpecific
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ATAPI_SENSE_DATA
operator|,
typedef|*
name|PATAPI_SENSE_DATA
typedef|;
end_typedef

begin_comment
comment|/*  * IDENTIFY data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IDENTIFY_DATA
block|{
name|USHORT
name|GeneralConfiguration
decl_stmt|;
comment|/* 00 00 */
name|USHORT
name|NumberOfCylinders
decl_stmt|;
comment|/* 02  1 */
name|USHORT
name|Reserved1
decl_stmt|;
comment|/* 04  2 */
name|USHORT
name|NumberOfHeads
decl_stmt|;
comment|/* 06  3 */
name|USHORT
name|UnformattedBytesPerTrack
decl_stmt|;
comment|/* 08  4 */
name|USHORT
name|UnformattedBytesPerSector
decl_stmt|;
comment|/* 0A  5 */
name|USHORT
name|SectorsPerTrack
decl_stmt|;
comment|/* 0C  6 */
name|USHORT
name|VendorUnique1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0E  7-9 */
name|USHORT
name|SerialNumber
index|[
literal|10
index|]
decl_stmt|;
comment|/* 14  10-19 */
name|USHORT
name|BufferType
decl_stmt|;
comment|/* 28  20 */
name|USHORT
name|BufferSectorSize
decl_stmt|;
comment|/* 2A  21 */
name|USHORT
name|NumberOfEccBytes
decl_stmt|;
comment|/* 2C  22 */
name|USHORT
name|FirmwareRevision
index|[
literal|4
index|]
decl_stmt|;
comment|/* 2E  23-26 */
name|USHORT
name|ModelNumber
index|[
literal|20
index|]
decl_stmt|;
comment|/* 36  27-46 */
name|UCHAR
name|MaximumBlockTransfer
decl_stmt|;
comment|/* 5E  47 */
name|UCHAR
name|VendorUnique2
decl_stmt|;
comment|/* 5F */
name|USHORT
name|DoubleWordIo
decl_stmt|;
comment|/* 60  48 */
name|USHORT
name|Capabilities
decl_stmt|;
comment|/* 62  49 */
name|USHORT
name|Reserved2
decl_stmt|;
comment|/* 64  50 */
name|UCHAR
name|VendorUnique3
decl_stmt|;
comment|/* 66  51 */
name|UCHAR
name|PioCycleTimingMode
decl_stmt|;
comment|/* 67 */
name|UCHAR
name|VendorUnique4
decl_stmt|;
comment|/* 68  52 */
name|UCHAR
name|DmaCycleTimingMode
decl_stmt|;
comment|/* 69 */
name|USHORT
name|TranslationFieldsValid
decl_stmt|;
comment|/* 6A  53 */
name|USHORT
name|NumberOfCurrentCylinders
decl_stmt|;
comment|/* 6C  54 */
name|USHORT
name|NumberOfCurrentHeads
decl_stmt|;
comment|/* 6E  55 */
name|USHORT
name|CurrentSectorsPerTrack
decl_stmt|;
comment|/* 70  56 */
name|ULONG
name|CurrentSectorCapacity
decl_stmt|;
comment|/* 72  57-58 */
name|USHORT
name|CurrentMultiSectorSetting
decl_stmt|;
comment|/* 76  59 */
name|ULONG
name|UserAddressableSectors
decl_stmt|;
comment|/* 78  60-61 */
name|UCHAR
name|SingleWordDMASupport
decl_stmt|;
comment|/* 7C  62 */
name|UCHAR
name|SingleWordDMAActive
decl_stmt|;
comment|/* 7D */
name|UCHAR
name|MultiWordDMASupport
decl_stmt|;
comment|/* 7E  63 */
name|UCHAR
name|MultiWordDMAActive
decl_stmt|;
comment|/* 7F */
name|UCHAR
name|AdvancedPIOModes
decl_stmt|;
comment|/* 80  64 */
name|UCHAR
name|Reserved4
decl_stmt|;
comment|/* 81 */
name|USHORT
name|MinimumMWXferCycleTime
decl_stmt|;
comment|/* 82  65 */
name|USHORT
name|RecommendedMWXferCycleTime
decl_stmt|;
comment|/* 84  66 */
name|USHORT
name|MinimumPIOCycleTime
decl_stmt|;
comment|/* 86  67 */
name|USHORT
name|MinimumPIOCycleTimeIORDY
decl_stmt|;
comment|/* 88  68 */
name|USHORT
name|Reserved5
index|[
literal|2
index|]
decl_stmt|;
comment|/* 8A  69-70 */
name|USHORT
name|ReleaseTimeOverlapped
decl_stmt|;
comment|/* 8E  71 */
name|USHORT
name|ReleaseTimeServiceCommand
decl_stmt|;
comment|/* 90  72 */
name|USHORT
name|MajorRevision
decl_stmt|;
comment|/* 92  73 */
name|USHORT
name|MinorRevision
decl_stmt|;
comment|/* 94  74 */
name|USHORT
name|MaxQueueDepth
decl_stmt|;
comment|/* 96  75 */
name|USHORT
name|SataCapability
decl_stmt|;
comment|/*     76 */
name|USHORT
name|Reserved6
index|[
literal|9
index|]
decl_stmt|;
comment|/* 98   77-85 */
name|USHORT
name|CommandSupport
decl_stmt|;
comment|/*     86 */
name|USHORT
name|CommandEnable
decl_stmt|;
comment|/*     87 */
name|USHORT
name|UtralDmaMode
decl_stmt|;
comment|/*     88 */
name|USHORT
name|Reserved7
index|[
literal|11
index|]
decl_stmt|;
comment|/*     89-99 */
name|ULONG
name|Lba48BitLow
decl_stmt|;
comment|/*     101-100 */
name|ULONG
name|Lba48BitHigh
decl_stmt|;
comment|/*     103-102 */
name|USHORT
name|Reserved8
index|[
literal|23
index|]
decl_stmt|;
comment|/*     104-126 */
name|USHORT
name|SpecialFunctionsEnabled
decl_stmt|;
comment|/*     127 */
name|USHORT
name|Reserved9
index|[
literal|128
index|]
decl_stmt|;
comment|/*     128-255 */
block|}
name|IDENTIFY_DATA
operator|,
typedef|*
name|PIDENTIFY_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CONFIGURATION_IDENTIFY_DATA
block|{
name|USHORT
name|Revision
decl_stmt|;
name|USHORT
name|MWDMAModeSupported
decl_stmt|;
name|USHORT
name|UDMAModeSupported
decl_stmt|;
name|ULONG
name|MaximumLbaLow
decl_stmt|;
name|ULONG
name|MaximumLbaHigh
decl_stmt|;
name|USHORT
name|CommandSupport
decl_stmt|;
name|USHORT
name|Reserved
index|[
literal|247
index|]
decl_stmt|;
name|UCHAR
name|Signature
decl_stmt|;
comment|/* 0xA5 */
name|UCHAR
name|CheckSum
decl_stmt|;
block|}
name|CONFIGURATION_IDENTIFY_DATA
operator|,
typedef|*
name|PCONFIGURATION_IDENTIFY_DATA
typedef|;
end_typedef

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* Identify data without the Reserved4. */
end_comment

begin_comment
comment|/* */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IDENTIFY_DATA2
block|{
name|USHORT
name|GeneralConfiguration
decl_stmt|;
comment|/* 00 00 */
name|USHORT
name|NumberOfCylinders
decl_stmt|;
comment|/* 02  1 */
name|USHORT
name|Reserved1
decl_stmt|;
comment|/* 04  2 */
name|USHORT
name|NumberOfHeads
decl_stmt|;
comment|/* 06  3 */
name|USHORT
name|UnformattedBytesPerTrack
decl_stmt|;
comment|/* 08  4 */
name|USHORT
name|UnformattedBytesPerSector
decl_stmt|;
comment|/* 0A  5 */
name|USHORT
name|SectorsPerTrack
decl_stmt|;
comment|/* 0C  6 */
name|USHORT
name|VendorUnique1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0E  7-9 */
name|USHORT
name|SerialNumber
index|[
literal|10
index|]
decl_stmt|;
comment|/* 14  10-19 */
name|USHORT
name|BufferType
decl_stmt|;
comment|/* 28  20 */
name|USHORT
name|BufferSectorSize
decl_stmt|;
comment|/* 2A  21 */
name|USHORT
name|NumberOfEccBytes
decl_stmt|;
comment|/* 2C  22 */
name|USHORT
name|FirmwareRevision
index|[
literal|4
index|]
decl_stmt|;
comment|/* 2E  23-26 */
name|USHORT
name|ModelNumber
index|[
literal|20
index|]
decl_stmt|;
comment|/* 36  27-46 */
name|UCHAR
name|MaximumBlockTransfer
decl_stmt|;
comment|/* 5E  47 */
name|UCHAR
name|VendorUnique2
decl_stmt|;
comment|/* 5F */
name|USHORT
name|DoubleWordIo
decl_stmt|;
comment|/* 60  48 */
name|USHORT
name|Capabilities
decl_stmt|;
comment|/* 62  49 */
name|USHORT
name|Reserved2
decl_stmt|;
comment|/* 64  50 */
name|UCHAR
name|VendorUnique3
decl_stmt|;
comment|/* 66  51 */
name|UCHAR
name|PioCycleTimingMode
decl_stmt|;
comment|/* 67 */
name|UCHAR
name|VendorUnique4
decl_stmt|;
comment|/* 68  52 */
name|UCHAR
name|DmaCycleTimingMode
decl_stmt|;
comment|/* 69 */
name|USHORT
name|TranslationFieldsValid
decl_stmt|;
comment|/* 6A  53 */
name|USHORT
name|NumberOfCurrentCylinders
decl_stmt|;
comment|/* 6C  54 */
name|USHORT
name|NumberOfCurrentHeads
decl_stmt|;
comment|/* 6E  55 */
name|USHORT
name|CurrentSectorsPerTrack
decl_stmt|;
comment|/* 70  56 */
name|ULONG
name|CurrentSectorCapacity
decl_stmt|;
comment|/* 72  57-58 */
name|USHORT
name|CurrentMultiSectorSetting
decl_stmt|;
comment|/*     59 */
name|ULONG
name|UserAddressableSectors
decl_stmt|;
comment|/*     60-61 */
name|UCHAR
name|SingleWordDMASupport
decl_stmt|;
comment|/*     62 */
name|UCHAR
name|SingleWordDMAActive
decl_stmt|;
name|UCHAR
name|MultiWordDMASupport
decl_stmt|;
comment|/*     63 */
name|UCHAR
name|MultiWordDMAActive
decl_stmt|;
name|UCHAR
name|AdvancedPIOModes
decl_stmt|;
comment|/*     64 */
name|UCHAR
name|Reserved4
decl_stmt|;
name|USHORT
name|MinimumMWXferCycleTime
decl_stmt|;
comment|/*     65 */
name|USHORT
name|RecommendedMWXferCycleTime
decl_stmt|;
comment|/*     66 */
name|USHORT
name|MinimumPIOCycleTime
decl_stmt|;
comment|/*     67 */
name|USHORT
name|MinimumPIOCycleTimeIORDY
decl_stmt|;
comment|/*     68 */
name|USHORT
name|Reserved5
index|[
literal|2
index|]
decl_stmt|;
comment|/*     69-70 */
name|USHORT
name|ReleaseTimeOverlapped
decl_stmt|;
comment|/*     71 */
name|USHORT
name|ReleaseTimeServiceCommand
decl_stmt|;
comment|/*     72 */
name|USHORT
name|MajorRevision
decl_stmt|;
comment|/*     73 */
name|USHORT
name|MinorRevision
decl_stmt|;
comment|/*     74 */
comment|/*    USHORT Reserved6[14];                 //     75-88 */
block|}
name|IDENTIFY_DATA2
operator|,
typedef|*
name|PIDENTIFY_DATA2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IDENTIFY_DATA_SIZE
value|sizeof(IDENTIFY_DATA2)
end_define

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* IDENTIFY DMA timing cycle modes. */
end_comment

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|IDENTIFY_DMA_CYCLES_MODE_0
value|0x00
end_define

begin_define
define|#
directive|define
name|IDENTIFY_DMA_CYCLES_MODE_1
value|0x01
end_define

begin_define
define|#
directive|define
name|IDENTIFY_DMA_CYCLES_MODE_2
value|0x02
end_define

begin_comment
comment|/*  * Mode definitions  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_DISK_MODE
block|{
name|IDE_PIO_0
init|=
literal|0
block|,
name|IDE_PIO_1
block|,
name|IDE_PIO_2
block|,
name|IDE_PIO_3
block|,
name|IDE_PIO_4
block|,
name|IDE_MWDMA_0
block|,
name|IDE_MWDMA_1
block|,
name|IDE_MWDMA_2
block|,
name|IDE_UDMA_0
block|,
name|IDE_UDMA_1
block|,
name|IDE_UDMA_2
block|,
name|IDE_UDMA_3
block|,
name|IDE_UDMA_4
block|,
name|IDE_UDMA_5
block|,
name|IDE_UDMA_6
block|,
name|IDE_UDMA_7
block|, }
name|DISK_MODE
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************  *            IDE Macro  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_LBA_T
end_ifndef

begin_define
define|#
directive|define
name|MAX_LBA_T
value|((LBA_T)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SECTOR_TO_BYTE_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|SECTOR_TO_BYTE
parameter_list|(
name|x
parameter_list|)
value|((ULONG)(x)<< SECTOR_TO_BYTE_SHIFT)
end_define

begin_define
define|#
directive|define
name|mGetStatus
parameter_list|(
name|IOPort2
parameter_list|)
value|(UCHAR)InPort(&IOPort2->AlternateStatus)
end_define

begin_define
define|#
directive|define
name|mUnitControl
parameter_list|(
name|IOPort2
parameter_list|,
name|Value
parameter_list|)
value|OutPort(&IOPort2->AlternateStatus,(UCHAR)(Value))
end_define

begin_define
define|#
directive|define
name|mGetErrorCode
parameter_list|(
name|IOPort
parameter_list|)
value|(UCHAR)InPort((PUCHAR)&IOPort->Data+1)
end_define

begin_define
define|#
directive|define
name|mSetFeaturePort
parameter_list|(
name|IOPort
parameter_list|,
name|x
parameter_list|)
value|OutPort((PUCHAR)&IOPort->Data+1, x)
end_define

begin_define
define|#
directive|define
name|mSetBlockCount
parameter_list|(
name|IOPort
parameter_list|,
name|x
parameter_list|)
value|OutPort(&IOPort->BlockCount, x)
end_define

begin_define
define|#
directive|define
name|mGetBlockCount
parameter_list|(
name|IOPort
parameter_list|)
value|(UCHAR)InPort(&IOPort->BlockCount)
end_define

begin_define
define|#
directive|define
name|mGetInterruptReason
parameter_list|(
name|IOPort
parameter_list|)
value|(UCHAR)InPort(&IOPort->BlockCount)
end_define

begin_define
define|#
directive|define
name|mSetBlockNumber
parameter_list|(
name|IOPort
parameter_list|,
name|x
parameter_list|)
value|OutPort(&IOPort->BlockNumber, x)
end_define

begin_define
define|#
directive|define
name|mGetBlockNumber
parameter_list|(
name|IOPort
parameter_list|)
value|(UCHAR)InPort((PUCHAR)&IOPort->BlockNumber)
end_define

begin_define
define|#
directive|define
name|mGetByteLow
parameter_list|(
name|IOPort
parameter_list|)
value|(UCHAR)InPort(&IOPort->CylinderLow)
end_define

begin_define
define|#
directive|define
name|mSetCylinderLow
parameter_list|(
name|IOPort
parameter_list|,
name|x
parameter_list|)
value|OutPort(&IOPort->CylinderLow, x)
end_define

begin_define
define|#
directive|define
name|mGetByteHigh
parameter_list|(
name|IOPort
parameter_list|)
value|(UCHAR)InPort(&IOPort->CylinderHigh)
end_define

begin_define
define|#
directive|define
name|mSetCylinderHigh
parameter_list|(
name|IOPort
parameter_list|,
name|x
parameter_list|)
value|OutPort(&IOPort->CylinderHigh, x)
end_define

begin_define
define|#
directive|define
name|mGetBaseStatus
parameter_list|(
name|IOPort
parameter_list|)
value|(UCHAR)InPort(&IOPort->Command)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_HPT601
end_ifdef

begin_define
define|#
directive|define
name|mSelectUnit
parameter_list|(
name|IOPort
parameter_list|,
name|UnitId
parameter_list|)
value|do {\ 		OutPort(&IOPort->DriveSelect, (UCHAR)(UnitId));\ 		OutPort(&IOPort->DriveSelect, (UCHAR)(UnitId));\ 		} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mSelectUnit
parameter_list|(
name|IOPort
parameter_list|,
name|UnitId
parameter_list|)
value|OutPort(&IOPort->DriveSelect, (UCHAR)(UnitId))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mGetUnitNumber
parameter_list|(
name|IOPort
parameter_list|)
value|InPort(&IOPort->DriveSelect)
end_define

begin_define
define|#
directive|define
name|mIssueCommand
parameter_list|(
name|IOPort
parameter_list|,
name|Cmd
parameter_list|)
value|OutPort(&IOPort->Command, (UCHAR)(Cmd))
end_define

begin_comment
comment|/*  * WDC old disk, don't care right now  */
end_comment

begin_define
define|#
directive|define
name|WDC_MW1_FIX_FLAG_OFFSET
value|129
end_define

begin_define
define|#
directive|define
name|WDC_MW1_FIX_FLAG_VALUE
value|0x00005555
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

