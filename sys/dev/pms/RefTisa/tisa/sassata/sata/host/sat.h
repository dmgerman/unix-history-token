begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  *  * The file defines the constants, data structure, and functions defined by SAT  * layer.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAT_H__
end_define

begin_comment
comment|/*  * ATA Command code  */
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
comment|/*  * ATAPI Command code */
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
comment|/*  * ATA Status Register Mask  */
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
comment|/*  * ATA Error Register Mask  */
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
name|scsiReportLun_s
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
name|scsiReportLun_t
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
comment|/*  * SMART READ LOG Self-test log  * ATA Table60 p296  */
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
comment|/*  * Flag definition for satIntFlag field in satInternalIo_t.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SAT_H__ */
end_comment

end_unit

