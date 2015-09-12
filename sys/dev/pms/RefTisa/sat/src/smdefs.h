begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMDEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMDEFS_H__
end_define

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/ossa.h>
end_include

begin_comment
comment|/* the index for memory requirement, must be continious */
end_comment

begin_define
define|#
directive|define
name|SM_ROOT_MEM_INDEX
value|0
end_define

begin_comment
comment|/**< the index of dm root memory */
end_comment

begin_define
define|#
directive|define
name|SM_DEVICE_MEM_INDEX
value|1
end_define

begin_comment
comment|/**< the index of Device descriptors memory */
end_comment

begin_define
define|#
directive|define
name|SM_IO_MEM_INDEX
value|2
end_define

begin_comment
comment|/**< the index of IO command descriptors memory */
end_comment

begin_define
define|#
directive|define
name|SM_MAX_DEV
value|256
end_define

begin_define
define|#
directive|define
name|SM_MAX_IO
value|1024
end_define

begin_define
define|#
directive|define
name|SM_USECS_PER_TICK
value|1000000
end_define

begin_comment
comment|/**< defines the heart beat of the LL layer 10ms */
end_comment

begin_enum
enum|enum
name|sm_locks_e
block|{
name|SM_TIMER_LOCK
init|=
literal|0
block|,
name|SM_DEVICE_LOCK
block|,
name|SM_INTERNAL_IO_LOCK
block|,
name|SM_EXTERNAL_IO_LOCK
block|,
name|SM_NCQ_TAG_LOCK
block|,
name|SM_TBD_LOCK
block|,
name|SM_MAX_LOCKS
block|}
enum|;
end_enum

begin_comment
comment|/* ATA device type */
end_comment

begin_define
define|#
directive|define
name|SATA_ATA_DEVICE
value|0x01
end_define

begin_comment
comment|/**< ATA ATA device type */
end_comment

begin_define
define|#
directive|define
name|SATA_ATAPI_DEVICE
value|0x02
end_define

begin_comment
comment|/**< ATA ATAPI device type */
end_comment

begin_define
define|#
directive|define
name|SATA_PM_DEVICE
value|0x03
end_define

begin_comment
comment|/**< ATA PM device type */
end_comment

begin_define
define|#
directive|define
name|SATA_SEMB_DEVICE
value|0x04
end_define

begin_comment
comment|/**< ATA SEMB device type */
end_comment

begin_define
define|#
directive|define
name|SATA_SEMB_WO_SEP_DEVICE
value|0x05
end_define

begin_comment
comment|/**< ATA SEMB without SEP device type */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_DEVICE
value|0xFF
end_define

begin_comment
comment|/*  *  FIS type   */
end_comment

begin_define
define|#
directive|define
name|PIO_SETUP_DEV_TO_HOST_FIS
value|0x5F
end_define

begin_define
define|#
directive|define
name|REG_DEV_TO_HOST_FIS
value|0x34
end_define

begin_define
define|#
directive|define
name|SET_DEV_BITS_FIS
value|0xA1
end_define

begin_comment
comment|/*   * ATA Command code   */
end_comment

begin_define
define|#
directive|define
name|SAT_READ_FPDMA_QUEUED
value|0x60
end_define

begin_define
define|#
directive|define
name|SAT_READ_DMA_EXT
value|0x25
end_define

begin_define
define|#
directive|define
name|SAT_READ_DMA
value|0xC8
end_define

begin_define
define|#
directive|define
name|SAT_WRITE_FPDMA_QUEUED
value|0x61
end_define

begin_define
define|#
directive|define
name|SAT_WRITE_DMA_EXT
value|0x35
end_define

begin_define
define|#
directive|define
name|SAT_WRITE_DMA_FUA_EXT
value|0x3D
end_define

begin_define
define|#
directive|define
name|SAT_WRITE_DMA
value|0xCA
end_define

begin_define
define|#
directive|define
name|SAT_CHECK_POWER_MODE
value|0xE5
end_define

begin_define
define|#
directive|define
name|SAT_READ_LOG_EXT
value|0x2F
end_define

begin_define
define|#
directive|define
name|SAT_READ_VERIFY_SECTORS
value|0x40
end_define

begin_define
define|#
directive|define
name|SAT_READ_VERIFY_SECTORS_EXT
value|0x42
end_define

begin_define
define|#
directive|define
name|SAT_SMART
value|0xB0
end_define

begin_define
define|#
directive|define
name|SAT_SMART_EXEUTE_OFF_LINE_IMMEDIATE
value|0xD4
end_define

begin_define
define|#
directive|define
name|SAT_SMART_RETURN_STATUS
value|0xDA
end_define

begin_define
define|#
directive|define
name|SAT_SMART_READ_LOG
value|0xD5
end_define

begin_define
define|#
directive|define
name|SAT_SMART_ENABLE_OPERATIONS
value|0xD8
end_define

begin_define
define|#
directive|define
name|SAT_SMART_DISABLE_OPERATIONS
value|0xD9
end_define

begin_define
define|#
directive|define
name|SAT_FLUSH_CACHE
value|0xE7
end_define

begin_define
define|#
directive|define
name|SAT_FLUSH_CACHE_EXT
value|0xEA
end_define

begin_define
define|#
directive|define
name|SAT_STANDBY
value|0xE2
end_define

begin_define
define|#
directive|define
name|SAT_MEDIA_EJECT
value|0xED
end_define

begin_define
define|#
directive|define
name|SAT_WRITE_SECTORS
value|0x30
end_define

begin_define
define|#
directive|define
name|SAT_WRITE_SECTORS_EXT
value|0x34
end_define

begin_define
define|#
directive|define
name|SAT_READ_SECTORS
value|0x20
end_define

begin_define
define|#
directive|define
name|SAT_READ_SECTORS_EXT
value|0x24
end_define

begin_define
define|#
directive|define
name|SAT_GET_MEDIA_STATUS
value|0xDA
end_define

begin_define
define|#
directive|define
name|SAT_SET_FEATURES
value|0xEF
end_define

begin_define
define|#
directive|define
name|SAT_IDENTIFY_DEVICE
value|0xEC
end_define

begin_define
define|#
directive|define
name|SAT_READ_BUFFER
value|0xE4
end_define

begin_define
define|#
directive|define
name|SAT_WRITE_BUFFER
value|0xE8
end_define

begin_comment
comment|/*   * ATAPI Command code  */
end_comment

begin_define
define|#
directive|define
name|SAT_IDENTIFY_PACKET_DEVICE
value|0xA1
end_define

begin_define
define|#
directive|define
name|SAT_PACKET
value|0xA0
end_define

begin_define
define|#
directive|define
name|SAT_DEVICE_RESET
value|0x08
end_define

begin_define
define|#
directive|define
name|SAT_EXECUTE_DEVICE_DIAGNOSTIC
value|0x90
end_define

begin_comment
comment|/*   * ATA Status Register Mask   */
end_comment

begin_define
define|#
directive|define
name|ERR_ATA_STATUS_MASK
value|0x01
end_define

begin_comment
comment|/* Error/check bit  */
end_comment

begin_define
define|#
directive|define
name|DRQ_ATA_STATUS_MASK
value|0x08
end_define

begin_comment
comment|/* Data Request bit */
end_comment

begin_define
define|#
directive|define
name|DF_ATA_STATUS_MASK
value|0x20
end_define

begin_comment
comment|/* Device Fault bit */
end_comment

begin_define
define|#
directive|define
name|DRDY_ATA_STATUS_MASK
value|0x40
end_define

begin_comment
comment|/* Device Ready bit */
end_comment

begin_define
define|#
directive|define
name|BSY_ATA_STATUS_MASK
value|0x80
end_define

begin_comment
comment|/* Busy bit         */
end_comment

begin_comment
comment|/*   * ATA Error Register Mask   */
end_comment

begin_define
define|#
directive|define
name|NM_ATA_ERROR_MASK
value|0x02
end_define

begin_comment
comment|/* No media present bit         */
end_comment

begin_define
define|#
directive|define
name|ABRT_ATA_ERROR_MASK
value|0x04
end_define

begin_comment
comment|/* Command aborted bit          */
end_comment

begin_define
define|#
directive|define
name|MCR_ATA_ERROR_MASK
value|0x08
end_define

begin_comment
comment|/* Media change request bit     */
end_comment

begin_define
define|#
directive|define
name|IDNF_ATA_ERROR_MASK
value|0x10
end_define

begin_comment
comment|/* Address not found bit        */
end_comment

begin_define
define|#
directive|define
name|MC_ATA_ERROR_MASK
value|0x20
end_define

begin_comment
comment|/* Media has changed bit        */
end_comment

begin_define
define|#
directive|define
name|UNC_ATA_ERROR_MASK
value|0x40
end_define

begin_comment
comment|/* Uncorrectable data error bit */
end_comment

begin_define
define|#
directive|define
name|ICRC_ATA_ERROR_MASK
value|0x80
end_define

begin_comment
comment|/* Interface CRC error bit      */
end_comment

begin_comment
comment|/*  *  transfer length and LBA limit 2^28 See identify device data word 61:60  *  ATA spec p125  *  7 zeros  */
end_comment

begin_define
define|#
directive|define
name|SAT_TR_LBA_LIMIT
value|0x10000000
end_define

begin_comment
comment|/*  *  transfer length and LBA limit 2^48 See identify device data word 61:60  *  ATA spec p125  *  12 zeros  */
end_comment

begin_define
define|#
directive|define
name|SAT_EXT_TR_LBA_LIMIT
value|0x1000000000000
end_define

begin_comment
comment|/*  * ATA command type. This is for setting LBA, Sector Count  */
end_comment

begin_define
define|#
directive|define
name|SAT_NON_EXT_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|SAT_EXT_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|SAT_FP_TYPE
value|2
end_define

begin_comment
comment|/*  * Report LUNs response data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smScsiReportLun_s
block|{
name|bit8
name|len
index|[
literal|4
index|]
decl_stmt|;
name|bit32
name|reserved
decl_stmt|;
name|tiLUN_t
name|lunList
index|[
literal|1
index|]
decl_stmt|;
block|}
name|smScsiReportLun_t
typedef|;
end_typedef

begin_comment
comment|/* Inquiry vendor string */
end_comment

begin_define
define|#
directive|define
name|AG_SAT_VENDOR_ID_STRING
value|"ATA     "
end_define

begin_comment
comment|/*  * Simple form of SATA Identify Device Data, similar definition is defined by  * LL Layer as agsaSATAIdentifyData_t.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|satSimpleSATAIdentifyData_s
block|{
name|bit16
name|word
index|[
literal|256
index|]
decl_stmt|;
block|}
name|satSimpleSATAIdentifyData_t
typedef|;
end_typedef

begin_comment
comment|/*  * READ LOG EXT page 10h  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|satReadLogExtPage10h_s
block|{
name|bit8
name|byte
index|[
literal|512
index|]
decl_stmt|;
block|}
name|satReadLogExtPage10h_t
typedef|;
end_typedef

begin_comment
comment|/*  * READ LOG EXT Extended Self-test log  * ATA Table27 p196  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|satReadLogExtSelfTest_s
block|{
name|bit8
name|byte
index|[
literal|512
index|]
decl_stmt|;
block|}
name|satReadLogExtSelfTest_t
typedef|;
end_typedef

begin_comment
comment|/*  * SMART READ LOG Self-test log   * ATA Table60 p296  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|satSmartReadLogSelfTest_s
block|{
name|bit8
name|byte
index|[
literal|512
index|]
decl_stmt|;
block|}
name|satSmartReadLogSelfTest_t
typedef|;
end_typedef

begin_comment
comment|/*   * Flag definition for satIntFlag field in smSatInternalIo_t.  */
end_comment

begin_comment
comment|/* Original NCQ I/O already completed, so at the completion of READ LOG EXT  *  page 10h, ignore the TAG tranaltion to get the failed I/O  */
end_comment

begin_define
define|#
directive|define
name|AG_SAT_INT_IO_FLAG_ORG_IO_COMPLETED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INQUIRY_SUPPORTED_VPD_PAGE
value|0x00
end_define

begin_define
define|#
directive|define
name|INQUIRY_UNIT_SERIAL_NUMBER_VPD_PAGE
value|0x80
end_define

begin_define
define|#
directive|define
name|INQUIRY_DEVICE_IDENTIFICATION_VPD_PAGE
value|0x83
end_define

begin_define
define|#
directive|define
name|INQUIRY_ATA_INFORMATION_VPD_PAGE
value|0x89
end_define

begin_define
define|#
directive|define
name|INQUIRY_BLOCK_DEVICE_CHARACTERISTICS_VPD_PAGE
value|0xB1
end_define

begin_define
define|#
directive|define
name|MODESENSE_CONTROL_PAGE
value|0x0A
end_define

begin_define
define|#
directive|define
name|MODESENSE_READ_WRITE_ERROR_RECOVERY_PAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|MODESENSE_CACHING
value|0x08
end_define

begin_define
define|#
directive|define
name|MODESENSE_INFORMATION_EXCEPTION_CONTROL_PAGE
value|0x1C
end_define

begin_define
define|#
directive|define
name|MODESENSE_RETURN_ALL_PAGES
value|0x3F
end_define

begin_define
define|#
directive|define
name|MODESENSE_VENDOR_SPECIFIC_PAGE
value|0x00
end_define

begin_define
define|#
directive|define
name|MODESELECT_CONTROL_PAGE
value|0x0A
end_define

begin_define
define|#
directive|define
name|MODESELECT_READ_WRITE_ERROR_RECOVERY_PAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|MODESELECT_CACHING
value|0x08
end_define

begin_define
define|#
directive|define
name|MODESELECT_INFORMATION_EXCEPTION_CONTROL_PAGE
value|0x1C
end_define

begin_define
define|#
directive|define
name|MODESELECT_RETURN_ALL_PAGES
value|0x3F
end_define

begin_define
define|#
directive|define
name|MODESELECT_VENDOR_SPECIFIC_PAGE
value|0x00
end_define

begin_define
define|#
directive|define
name|LOGSENSE_SUPPORTED_LOG_PAGES
value|0x00
end_define

begin_define
define|#
directive|define
name|LOGSENSE_SELFTEST_RESULTS_PAGE
value|0x10
end_define

begin_define
define|#
directive|define
name|LOGSENSE_INFORMATION_EXCEPTIONS_PAGE
value|0x2F
end_define

begin_comment
comment|/*  *  Bit mask definition  */
end_comment

begin_define
define|#
directive|define
name|SCSI_EVPD_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_IMMED_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_NACA_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_LINK_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_PF_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_DEVOFFL_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_UNITOFFL_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_START_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_LOEJ_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_NM_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_FLUSH_CACHE_IMMED_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_FUA_NV_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_VERIFY_BYTCHK_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_IMMED_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_FOV_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_DCRT_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_IP_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_SAME_LBDATA_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_SAME_PBDATA_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_SYNC_CACHE_IMMED_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_N_VERIFY_BYTCHK_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_SEND_DIAGNOSTIC_SELFTEST_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_DEFECT_LIST_FORMAT_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_FMTDATA_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_DCRT_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_CMPLIST_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT_LONGLIST_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_READ10_FUA_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_READ12_FUA_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_READ16_FUA_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE10_FUA_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE12_FUA_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE16_FUA_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_READ_CAPACITY10_PMI_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_READ_CAPACITY16_PMI_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE6_PC_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE6_PAGE_CODE_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE10_PC_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE10_LLBAA_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE10_PAGE_CODE_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|SCSI_SEND_DIAGNOSTIC_TEST_CODE_MASK
value|0xE0
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_SENSE_PAGE_CODE_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_PF_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_AWRE_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_RC_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_EER_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_PER_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_DTE_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_DCR_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_WCE_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_DRA_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_PERF_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_TEST_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT6_DEXCPT_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_PF_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_LONGLBA_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_AWRE_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_RC_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_EER_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_PER_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_DTE_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_DCR_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_WCE_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_DRA_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_PERF_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_TEST_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT10_DEXCPT_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_N_VERIFY10_FUA_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_REQUEST_SENSE_DESC_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_READ_BUFFER_MODE_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|ATA_REMOVABLE_MEDIA_DEVICE_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_REASSIGN_BLOCKS_LONGLIST_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_REASSIGN_BLOCKS_LONGLBA_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|SENSE_DATA_LENGTH
value|0x12
end_define

begin_comment
comment|/* 18 */
end_comment

begin_define
define|#
directive|define
name|SELFTEST_RESULTS_LOG_PAGE_LENGTH
value|404
end_define

begin_define
define|#
directive|define
name|INFORMATION_EXCEPTIONS_LOG_PAGE_LENGTH
value|11
end_define

begin_define
define|#
directive|define
name|ZERO_MEDIA_SERIAL_NUMBER_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|LOG_SENSE_0
value|0
end_define

begin_define
define|#
directive|define
name|LOG_SENSE_1
value|1
end_define

begin_define
define|#
directive|define
name|LOG_SENSE_2
value|2
end_define

begin_define
define|#
directive|define
name|READ_BUFFER_DATA_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|READ_BUFFER_DESCRIPTOR_MODE
value|0x03
end_define

begin_define
define|#
directive|define
name|READ_BUFFER_DESCRIPTOR_MODE_DATA_LEN
value|0x04
end_define

begin_define
define|#
directive|define
name|WRITE_BUFFER_DATA_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|WRITE_BUFFER_DL_MICROCODE_SAVE_MODE
value|0x05
end_define

begin_comment
comment|/* bit mask */
end_comment

begin_define
define|#
directive|define
name|BIT0_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|BIT1_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|BIT2_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|BIT3_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|BIT4_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|BIT5_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|BIT6_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|BIT7_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|MODE_SENSE6_RETURN_ALL_PAGES_LEN
value|68
end_define

begin_define
define|#
directive|define
name|MODE_SENSE6_CONTROL_PAGE_LEN
value|24
end_define

begin_define
define|#
directive|define
name|MODE_SENSE6_READ_WRITE_ERROR_RECOVERY_PAGE_LEN
value|24
end_define

begin_define
define|#
directive|define
name|MODE_SENSE6_CACHING_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MODE_SENSE6_INFORMATION_EXCEPTION_CONTROL_PAGE_LEN
value|24
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_RETURN_ALL_PAGES_LEN
value|68 + 4
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_CONTROL_PAGE_LEN
value|24 + 4
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_READ_WRITE_ERROR_RECOVERY_PAGE_LEN
value|24 + 4
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_CACHING_LEN
value|32 + 4
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_INFORMATION_EXCEPTION_CONTROL_PAGE_LEN
value|24 + 4
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_RETURN_ALL_PAGES_LLBAA_LEN
value|68 + 4 + 8
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_CONTROL_PAGE_LLBAA_LEN
value|24 + 4 + 8
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_READ_WRITE_ERROR_RECOVERY_PAGE_LLBAA_LEN
value|24 + 4 + 8
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_CACHING_LLBAA_LEN
value|32 + 4 + 8
end_define

begin_define
define|#
directive|define
name|MODE_SENSE10_INFORMATION_EXCEPTION_CONTROL_PAGE_LLBAA_LEN
value|24 + 4 + 8
end_define

begin_comment
comment|/***************************************************************************** ** SCSI SENSE KEY VALUES *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSI_SNSKEY_NO_SENSE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_RECOVERED_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_NOT_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_MEDIUM_ERROR
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_HARDWARE_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_ILLEGAL_REQUEST
value|0x05
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_UNIT_ATTENTION
value|0x06
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_DATA_PROTECT
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_ABORTED_COMMAND
value|0x0B
end_define

begin_define
define|#
directive|define
name|SCSI_SNSKEY_MISCOMPARE
value|0x0E
end_define

begin_comment
comment|/***************************************************************************** ** SCSI Additional Sense Codes and Qualifiers combo two-bytes *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSI_SNSCODE_NO_ADDITIONAL_INFO
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LUN_CRC_ERROR_DETECTED
value|0x0803
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INVALID_COMMAND
value|0x2000
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_BLOCK_OUT
value|0x2100
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INVALID_FIELD_IN_CDB
value|0x2400
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_NOT_SUPPORTED
value|0x2500
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_POWERON_RESET
value|0x2900
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_EVERLAPPED_CMDS
value|0x4e00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INTERNAL_TARGET_FAILURE
value|0x4400
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_MEDIUM_NOT_PRESENT
value|0x3a00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_UNRECOVERED_READ_ERROR
value|0x1100
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_RECORD_NOT_FOUND
value|0x1401
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_NOT_READY_TO_READY_CHANGE
value|0x2800
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_OPERATOR_MEDIUM_REMOVAL_REQUEST
value|0x5a01
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INFORMATION_UNIT_CRC_ERROR
value|0x4703
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_NOT_READY_FORMAT_IN_PROGRESS
value|0x0404
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_HARDWARE_IMPENDING_FAILURE
value|0x5d10
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOW_POWER_CONDITION_ON
value|0x5e00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_NOT_READY_INIT_REQUIRED
value|0x0402
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_INVALID_FIELD_PARAMETER_LIST
value|0x2600
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_ATA_DEVICE_FAILED_SET_FEATURES
value|0x4471
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_ATA_DEVICE_FEATURE_NOT_ENABLED
value|0x670B
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_FAILED_SELF_TEST
value|0x3E03
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_COMMAND_SEQUENCE_ERROR
value|0x2C00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE
value|0x2100
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_FAILURE
value|0x3E01
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_MEDIA_LOAD_OR_EJECT_FAILED
value|0x5300
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_NOT_READY_INITIALIZING_COMMAND_REQUIRED
value|0x0402
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_NOT_READY_CAUSE_NOT_REPORTABLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_LOGICAL_UNIT_DOES_NOT_RESPOND_TO_SELECTION
value|0x0500
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_DIAGNOSTIC_FAILURE_ON_COMPONENT_NN
value|0x4000
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_COMMANDS_CLEARED_BY_ANOTHER_INITIATOR
value|0x2F00
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_WRITE_ERROR_AUTO_REALLOCATION_FAILED
value|0x0C02
end_define

begin_define
define|#
directive|define
name|SCSI_SNSCODE_ATA_PASS_THROUGH_INFORMATION_AVAILABLE
value|0x001D
end_define

begin_comment
comment|/***************************************************************************** ** SCSI Additional Sense Codes and Qualifiers saparate bytes *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSI_ASC_NOTREADY_INIT_CMD_REQ
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_NOTREADY_INIT_CMD_REQ
value|0x02
end_define

begin_comment
comment|/***************************************************************************** ** Inquiry command fields and response sizes *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSIOP_INQUIRY_CMDDT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSIOP_INQUIRY_EVPD
value|0x01
end_define

begin_define
define|#
directive|define
name|STANDARD_INQUIRY_SIZE
value|36
end_define

begin_define
define|#
directive|define
name|SATA_PAGE83_INQUIRY_WWN_SIZE
value|16
end_define

begin_comment
comment|/* SAT, revision8, Table81, p78, 12 + 4 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGE83_INQUIRY_NO_WWN_SIZE
value|76
end_define

begin_comment
comment|/* SAT, revision8, Table81, p78, 72 + 4 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGE89_INQUIRY_SIZE
value|572
end_define

begin_comment
comment|/* SAT, revision8, Table87, p84 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGE0_INQUIRY_SIZE
value|9
end_define

begin_comment
comment|/* SPC-4, 7.6.9   Table331, p345 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGE80_INQUIRY_SIZE
value|24
end_define

begin_comment
comment|/* SAT, revision8, Table79, p77 */
end_comment

begin_define
define|#
directive|define
name|SATA_PAGEB1_INQUIRY_SIZE
value|64
end_define

begin_comment
comment|/* SBC-3, revision31, Table193, p273 */
end_comment

begin_comment
comment|/***************************************************************************** ** SCSI Operation Codes (first byte in CDB) *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SCSIOPC_TEST_UNIT_READY
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSIOPC_INQUIRY
value|0x12
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SENSE_6
value|0x1A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SENSE_10
value|0x5A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SELECT_6
value|0x15
end_define

begin_define
define|#
directive|define
name|SCSIOPC_START_STOP_UNIT
value|0x1B
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_CAPACITY_10
value|0x25
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_CAPACITY_16
value|0x9E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_6
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_10
value|0x28
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_12
value|0xA8
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_16
value|0x88
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_6
value|0x0A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_10
value|0x2A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_12
value|0xAA
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_16
value|0x8A
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_VERIFY
value|0x2E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_VERIFY_10
value|0x2F
end_define

begin_define
define|#
directive|define
name|SCSIOPC_VERIFY_12
value|0xAF
end_define

begin_define
define|#
directive|define
name|SCSIOPC_VERIFY_16
value|0x8F
end_define

begin_define
define|#
directive|define
name|SCSIOPC_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSIOPC_REPORT_LUN
value|0xA0
end_define

begin_define
define|#
directive|define
name|SCSIOPC_FORMAT_UNIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSIOPC_SEND_DIAGNOSTIC
value|0x1D
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_SAME_10
value|0x41
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_SAME_16
value|0x93
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_BUFFER
value|0x3C
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_BUFFER
value|0x3B
end_define

begin_define
define|#
directive|define
name|SCSIOPC_LOG_SENSE
value|0x4D
end_define

begin_define
define|#
directive|define
name|SCSIOPC_LOG_SELECT
value|0x4C
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SELECT_6
value|0x15
end_define

begin_define
define|#
directive|define
name|SCSIOPC_MODE_SELECT_10
value|0x55
end_define

begin_define
define|#
directive|define
name|SCSIOPC_SYNCHRONIZE_CACHE_10
value|0x35
end_define

begin_define
define|#
directive|define
name|SCSIOPC_SYNCHRONIZE_CACHE_16
value|0x91
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_AND_VERIFY_10
value|0x2E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_AND_VERIFY_12
value|0xAE
end_define

begin_define
define|#
directive|define
name|SCSIOPC_WRITE_AND_VERIFY_16
value|0x8E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_MEDIA_SERIAL_NUMBER
value|0xAB
end_define

begin_define
define|#
directive|define
name|SCSIOPC_REASSIGN_BLOCKS
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSIOPC_GET_CONFIG
value|0x46
end_define

begin_define
define|#
directive|define
name|SCSIOPC_GET_EVENT_STATUS_NOTIFICATION
value|0x4a
end_define

begin_define
define|#
directive|define
name|SCSIOPC_REPORT_KEY
value|0xA4
end_define

begin_define
define|#
directive|define
name|SCSIOPC_SEND_KEY
value|0xA3
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_DVD_STRUCTURE
value|0xAD
end_define

begin_define
define|#
directive|define
name|SCSIOPC_TOC
value|0x43
end_define

begin_define
define|#
directive|define
name|SCSIOPC_PREVENT_ALLOW_MEDIUM_REMOVAL
value|0x1E
end_define

begin_define
define|#
directive|define
name|SCSIOPC_READ_VERIFY
value|0x42
end_define

begin_define
define|#
directive|define
name|SCSIOPC_ATA_PASS_THROUGH12
value|0xA1
end_define

begin_define
define|#
directive|define
name|SCSIOPC_ATA_PASS_THROUGH16
value|0x85
end_define

begin_comment
comment|/*! \def MIN(a,b) * \brief MIN macro * * use to find MIN of two values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def MAX(a,b) * \brief MAX macro * * use to find MAX of two values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for debugging print */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SM_DEBUG
argument_list|)
end_if

begin_comment
comment|/* * for debugging purposes.   */
end_comment

begin_decl_stmt
specifier|extern
name|bit32
name|gSMDebugLevel
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SM_DBG0
parameter_list|(
name|format
parameter_list|)
value|tdsmLogDebugString(gSMDebugLevel, 0, format)
end_define

begin_define
define|#
directive|define
name|SM_DBG1
parameter_list|(
name|format
parameter_list|)
value|tdsmLogDebugString(gSMDebugLevel, 1, format)
end_define

begin_define
define|#
directive|define
name|SM_DBG2
parameter_list|(
name|format
parameter_list|)
value|tdsmLogDebugString(gSMDebugLevel, 2, format)
end_define

begin_define
define|#
directive|define
name|SM_DBG3
parameter_list|(
name|format
parameter_list|)
value|tdsmLogDebugString(gSMDebugLevel, 3, format)
end_define

begin_define
define|#
directive|define
name|SM_DBG4
parameter_list|(
name|format
parameter_list|)
value|tdsmLogDebugString(gSMDebugLevel, 4, format)
end_define

begin_define
define|#
directive|define
name|SM_DBG5
parameter_list|(
name|format
parameter_list|)
value|tdsmLogDebugString(gSMDebugLevel, 5, format)
end_define

begin_define
define|#
directive|define
name|SM_DBG6
parameter_list|(
name|format
parameter_list|)
value|tdsmLogDebugString(gSMDebugLevel, 6, format)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SM_DBG0
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SM_DBG1
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SM_DBG2
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SM_DBG3
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SM_DBG4
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SM_DBG5
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SM_DBG6
parameter_list|(
name|format
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_DEBUG */
end_comment

begin_comment
comment|//#define SM_ASSERT OS_ASSERT
end_comment

begin_comment
comment|//#define tdsmLogDebugString TIDEBUG_MSG
end_comment

begin_comment
comment|/*  * SAT specific structure per SATA drive   */
end_comment

begin_define
define|#
directive|define
name|SAT_NONNCQ_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SAT_NCQ_MAX
value|32
end_define

begin_define
define|#
directive|define
name|SAT_MAX_INT_IO
value|16
end_define

begin_define
define|#
directive|define
name|SAT_APAPI_CMDQ_MAX
value|2
end_define

begin_comment
comment|/* Device state */
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_NORMAL
value|0
end_define

begin_comment
comment|/* Normal */
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_IN_RECOVERY
value|1
end_define

begin_comment
comment|/* SAT in recovery mode */
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_FORMAT_IN_PROGRESS
value|2
end_define

begin_comment
comment|/* Format unit in progress */
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_SMART_THRESHOLD
value|3
end_define

begin_comment
comment|/* SMART Threshold Exceeded Condition*/
end_comment

begin_define
define|#
directive|define
name|SAT_DEV_STATE_LOW_POWER
value|4
end_define

begin_comment
comment|/* Low Power State*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|agNULL
end_ifndef

begin_define
define|#
directive|define
name|agNULL
value|((void *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SM_SET_ESGL_EXTEND
parameter_list|(
name|val
parameter_list|)
define|\
value|((val) = (val) | 0x80000000)
end_define

begin_define
define|#
directive|define
name|SM_CLEAR_ESGL_EXTEND
parameter_list|(
name|val
parameter_list|)
define|\
value|((val) = (val)& 0x7FFFFFFF)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|OPEN_RETRY_RETRIES
end_ifndef

begin_define
define|#
directive|define
name|OPEN_RETRY_RETRIES
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************************************************************* * CPU buffer access macro                                            * *                                                                    * */
end_comment

begin_define
define|#
directive|define
name|OSSA_OFFSET_OF
parameter_list|(
name|STRUCT_TYPE
parameter_list|,
name|FEILD
parameter_list|)
define|\
value|(bitptr)&(((STRUCT_TYPE *)0)->FEILD)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_CPU_LITTLE_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit16)(VALUE16);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit32)(VALUE32);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit16 *)ADDR16)) = (*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET))))
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit32 *)ADDR32)) = (*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET))))
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)((((bit16)VALUE16)>>8)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)(((bit16)VALUE16)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)((((bit32)VALUE32)>>24)&0xFF); \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit32)VALUE32)>>16)&0xFF); \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))) = (bit8)((((bit32)VALUE32)>>8)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3))) = (bit8)(((bit32)VALUE32)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR16)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR16)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1)));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR32)+3)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR32)+2)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))); \         (*(bit8 *)(((bit8 *)ADDR32)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))); \         (*(bit8 *)(((bit8 *)ADDR32)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3)));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BYTE_STRING
parameter_list|(
name|AGROOT
parameter_list|,
name|DEST_ADDR
parameter_list|,
name|SRC_ADDR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|si_memcpy(DEST_ADDR, SRC_ADDR, LEN);
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SA_CPU_BIG_ENDIAN
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit16)VALUE16)>>8)&0xFF);   \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)(((bit16)VALUE16)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3))) = (bit8)((((bit32)VALUE32)>>24)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))) = (bit8)((((bit32)VALUE32)>>16)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit32)VALUE32)>>8)&0xFF);   \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)(((bit32)VALUE32)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR16)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR16)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1)));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)ADDR32)+3))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*((bit8 *)(((bit8 *)ADDR32)+2))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))); \         (*((bit8 *)(((bit8 *)ADDR32)+1))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))); \         (*((bit8 *)(((bit8 *)ADDR32))))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3)));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit16)(VALUE16);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit32)(VALUE32);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit16 *)ADDR16)) = (*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET))));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit32 *)ADDR32)) = (*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET))));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BYTE_STRING
parameter_list|(
name|AGROOT
parameter_list|,
name|DEST_ADDR
parameter_list|,
name|SRC_ADDR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|si_memcpy(DEST_ADDR, SRC_ADDR, LEN);
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|(Host CPU endianess undefined!!)
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_CPU_LITTLE_ENDIAN
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SA_CPU_BIG_ENDIAN
argument_list|)
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|No definition of SA_CPU_BIG_ENDIAN or SA_CPU_LITTLE_ENDIAN
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * Task Management task used in tiINITaskManagement()  *  * 1 SM_ABORT TASK - aborts the task identified by the Referenced  Task Tag field.  * 2 SM_ABORT TASK SET - aborts all Tasks issued by this initiator on the Logical Unit   * 3 SM_CLEAR ACA - clears the Auto Contingent Allegiance condition.  * 4 SM_CLEAR TASK SET - Aborts all Tasks (from all initiators) for the Logical Unit.  * 5 SM_LOGICAL UNIT RESET   * 6 SM_TARGET WARM RESET  - iSCSI only  * 7 SM_TARGET_COLD_RESET  - iSCSI only  * 8 SM_TASK_REASSIGN      - iSCSI only  * 9 SM_QUERY_TASK         - SAS only  */
end_comment

begin_define
define|#
directive|define
name|SM_ABORT_TASK
value|1
end_define

begin_define
define|#
directive|define
name|SM_ABORT_TASK_SET
value|2
end_define

begin_define
define|#
directive|define
name|SM_CLEAR_ACA
value|3
end_define

begin_define
define|#
directive|define
name|SM_CLEAR_TASK_SET
value|4
end_define

begin_define
define|#
directive|define
name|SM_LOGICAL_UNIT_RESET
value|5
end_define

begin_define
define|#
directive|define
name|SM_TARGET_WARM_RESET
value|6
end_define

begin_comment
comment|/* iSCSI only */
end_comment

begin_define
define|#
directive|define
name|SM_TARGET_COLD_RESET
value|7
end_define

begin_comment
comment|/* iSCSI only */
end_comment

begin_define
define|#
directive|define
name|SM_TASK_REASSIGN
value|8
end_define

begin_comment
comment|/* iSCSI only */
end_comment

begin_define
define|#
directive|define
name|SM_QUERY_TASK
value|9
end_define

begin_comment
comment|/* SAS only   */
end_comment

begin_comment
comment|/* SMP PHY CONTROL OPERATION */
end_comment

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_LINK_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_HARD_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_DISABLE
value|0x03
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_CLEAR_ERROR_LOG
value|0x05
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_CLEAR_AFFILIATION
value|0x06
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_XMIT_SATA_PS_SIGNAL
value|0x07
end_define

begin_comment
comment|/****************************************************************  *            Phy Control request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqPhyControl_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|phyOperation
decl_stmt|;
name|bit8
name|updatePartialPathwayTOValue
decl_stmt|;
comment|/* b7-1 : reserved */
comment|/* b0   : update partial pathway timeout value */
name|bit8
name|reserved3
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|programmedMinPhysicalLinkRate
decl_stmt|;
comment|/* b7-4 : programmed Minimum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|programmedMaxPhysicalLinkRate
decl_stmt|;
comment|/* b7-4 : programmed Maximum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|partialPathwayTOValue
decl_stmt|;
comment|/* b7-4 : reserved */
comment|/* b3-0 : partial Pathway TO Value */
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
block|}
name|smpReqPhyControl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smSMPFrameHeader_s
block|{
name|bit8
name|smpFrameType
decl_stmt|;
comment|/* The first byte of SMP frame represents the SMP FRAME TYPE */
name|bit8
name|smpFunction
decl_stmt|;
comment|/* The second byte of the SMP frame represents the SMP FUNCTION */
name|bit8
name|smpFunctionResult
decl_stmt|;
comment|/* The third byte of SMP frame represents FUNCTION RESULT of the SMP response. */
name|bit8
name|smpReserved
decl_stmt|;
comment|/* reserved */
block|}
name|smSMPFrameHeader_t
typedef|;
end_typedef

begin_comment
comment|/* SMP direct payload size limit: IOMB direct payload size = 48 */
end_comment

begin_define
define|#
directive|define
name|SMP_DIRECT_PAYLOAD_LIMIT
value|44
end_define

begin_define
define|#
directive|define
name|SMP_REQUEST
value|0x40
end_define

begin_define
define|#
directive|define
name|SMP_RESPONSE
value|0x41
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL
value|0x91
end_define

begin_comment
comment|/* SMP function results */
end_comment

begin_define
define|#
directive|define
name|SMP_FUNCTION_ACCEPTED
value|0x00
end_define

begin_comment
comment|/* bit8 array[4] -> bit32 */
end_comment

begin_define
define|#
directive|define
name|SM_GET_SAS_ADDRESSLO
parameter_list|(
name|sasAddressLo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)sasAddressLo)
end_define

begin_define
define|#
directive|define
name|SM_GET_SAS_ADDRESSHI
parameter_list|(
name|sasAddressHi
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)sasAddressHi)
end_define

begin_comment
comment|/* SATA sector size 512 bytes = 0x200 bytes */
end_comment

begin_define
define|#
directive|define
name|SATA_SECTOR_SIZE
value|0x200
end_define

begin_comment
comment|/* TL limit in sector */
end_comment

begin_comment
comment|/* for SAT_READ/WRITE_DMA and SAT_READ/WRITE_SECTORS ATA command */
end_comment

begin_define
define|#
directive|define
name|NON_BIT48_ADDRESS_TL_LIMIT
value|0x100
end_define

begin_comment
comment|/* for SAT_READ/WRITE_DMA_EXT and SAT_READ/WRITE_SECTORS_EXT and  SAT_READ/WRITE_FPDMA_QUEUEDATA command */
end_comment

begin_define
define|#
directive|define
name|BIT48_ADDRESS_TL_LIMIT
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPC
value|0x800111f8
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPCv
value|0x800811f8
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPCve
value|0x800911f8
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPCvplus
value|0x801811f8
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPCveplus
value|0x801911f8
end_define

begin_define
define|#
directive|define
name|SMIsSPC
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC  == ossaHwRegReadConfig32(agr,0 ) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC */
end_comment

begin_define
define|#
directive|define
name|SMIsSPCv
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPCv == ossaHwRegReadConfig32(agr,0 ) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|SMIsSPCve
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPCve  == ossaHwRegReadConfig32(agr,0 ) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCve */
end_comment

begin_define
define|#
directive|define
name|SMIsSPCvplus
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPCvplus == ossaHwRegReadConfig32(agr,0 ) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv+ */
end_comment

begin_define
define|#
directive|define
name|SMIsSPCveplus
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPCveplus == ossaHwRegReadConfig32(agr,0 ) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCve+ */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_KEY_BUFFER_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SMDEFS_H__ */
end_comment

end_unit

