begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************** ** ** Version Control Information: ** ** *******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************** ** **   titypes.h ** **   Abstract:   This module contains data structure definition used **               by the Transport Independent API (TIAPI) Layer. ** ********************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tidefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TITYPES_H
end_ifndef

begin_define
define|#
directive|define
name|TITYPES_H
end_define

begin_comment
comment|/*****************************************************************************  * SHARED TYPES  *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiPortalContext
block|{
name|void
modifier|*
name|osData
decl_stmt|;
name|void
modifier|*
name|tdData
decl_stmt|;
block|}
name|tiPortalContext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiDeviceHandle
block|{
name|void
modifier|*
name|osData
decl_stmt|;
name|void
modifier|*
name|tdData
decl_stmt|;
block|}
name|tiDeviceHandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiRoot
block|{
name|void
modifier|*
name|osData
decl_stmt|;
name|void
modifier|*
name|tdData
decl_stmt|;
block|}
name|tiRoot_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiMem
block|{
name|void
modifier|*
name|virtPtr
decl_stmt|;
name|void
modifier|*
name|osHandle
decl_stmt|;
name|bit32
name|physAddrUpper
decl_stmt|;
name|bit32
name|physAddrLower
decl_stmt|;
name|bit32
name|totalLength
decl_stmt|;
name|bit32
name|numElements
decl_stmt|;
name|bit32
name|singleElementLength
decl_stmt|;
name|bit32
name|alignment
decl_stmt|;
name|bit32
name|type
decl_stmt|;
name|bit32
name|reserved
decl_stmt|;
block|}
name|tiMem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiLoLevelMem
block|{
name|bit32
name|count
decl_stmt|;
name|tiMem_t
name|mem
index|[
name|MAX_LL_LAYER_MEM_DESCRIPTORS
index|]
decl_stmt|;
block|}
name|tiLoLevelMem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiLoLevelOption
block|{
name|bit32
name|usecsPerTick
decl_stmt|;
name|bit32
name|numOfQueuesPerPort
decl_stmt|;
name|bit32
name|mutexLockUsage
decl_stmt|;
name|bit32
name|pciFunctionNumber
decl_stmt|;
name|bit32
name|maxPortContext
decl_stmt|;
name|bit32
name|maxNumOSLocks
decl_stmt|;
name|agBOOLEAN
name|encryption
decl_stmt|;
name|bit32
name|maxInterruptVectors
decl_stmt|;
name|bit32
name|flag
decl_stmt|;
name|bit32
name|max_MSI_InterruptVectors
decl_stmt|;
ifdef|#
directive|ifdef
name|SA_ENABLE_PCI_TRIGGER
name|bit32
name|PCI_trigger
decl_stmt|;
endif|#
directive|endif
comment|/* SA_ENABLE_PCI_TRIGGER */
block|}
name|tiLoLevelOption_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiLoLevelResource
block|{
name|tiLoLevelOption_t
name|loLevelOption
decl_stmt|;
name|tiLoLevelMem_t
name|loLevelMem
decl_stmt|;
block|}
name|tiLoLevelResource_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiTdSharedMem
block|{
name|tiMem_t
name|tdSharedCachedMem1
decl_stmt|;
block|}
name|tiTdSharedMem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiIORequest
block|{
name|void
modifier|*
name|osData
decl_stmt|;
name|void
modifier|*
name|tdData
decl_stmt|;
block|}
name|tiIORequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiSgl_s
block|{
name|bit32
name|lower
decl_stmt|;
name|bit32
name|upper
decl_stmt|;
name|bit32
name|len
decl_stmt|;
name|bit32
name|type
decl_stmt|;
block|}
name|tiSgl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiSenseData
block|{
name|void
modifier|*
name|senseData
decl_stmt|;
name|bit8
name|senseLen
decl_stmt|;
block|}
name|tiSenseData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiIOCTLPayload
block|{
name|bit32
name|Signature
decl_stmt|;
name|bit16
name|MajorFunction
decl_stmt|;
name|bit16
name|MinorFunction
decl_stmt|;
name|bit16
name|Length
decl_stmt|;
name|bit16
name|Status
decl_stmt|;
name|bit32
name|Reserved
decl_stmt|;
comment|/* required for 64 bit alignment */
name|bit8
name|FunctionSpecificArea
index|[
literal|1
index|]
decl_stmt|;
block|}
name|tiIOCTLPayload_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiIOCTLPayload_wwn
block|{
name|bit32
name|Signature
decl_stmt|;
name|bit16
name|MajorFunction
decl_stmt|;
name|bit16
name|MinorFunction
decl_stmt|;
name|bit16
name|Length
decl_stmt|;
name|bit16
name|Status
decl_stmt|;
name|bit32
name|Reserved
decl_stmt|;
comment|/* required for 64 bit alignment */
name|bit8
name|FunctionSpecificArea
index|[
literal|8
index|]
decl_stmt|;
block|}
name|tiIOCTLPayload_wwn_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiPortInfo
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|address
decl_stmt|;
name|char
modifier|*
name|localName
decl_stmt|;
name|char
modifier|*
name|remoteName
decl_stmt|;
name|bit32
name|localNameLen
decl_stmt|;
name|bit32
name|remoteNameLen
decl_stmt|;
block|}
name|tiPortInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiDif_s
block|{
name|agBOOLEAN
name|enableDIFPerLA
decl_stmt|;
name|bit32
name|flags
decl_stmt|;
name|bit16
name|initialIOSeed
decl_stmt|;
name|bit16
name|reserved
decl_stmt|;
name|bit32
name|DIFPerLAAddrLo
decl_stmt|;
name|bit32
name|DIFPerLAAddrHi
decl_stmt|;
name|bit16
name|DIFPerLARegion0SecCount
decl_stmt|;
name|bit16
name|DIFPerLANumOfRegions
decl_stmt|;
name|bit8
name|udtArray
index|[
name|DIF_UDT_SIZE
index|]
decl_stmt|;
name|bit8
name|udtrArray
index|[
name|DIF_UDT_SIZE
index|]
decl_stmt|;
block|}
name|tiDif_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DIF_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|DIF_VERIFY_FORWARD
value|1
end_define

begin_define
define|#
directive|define
name|DIF_VERIFY_DELETE
value|2
end_define

begin_define
define|#
directive|define
name|DIF_VERIFY_REPLACE
value|3
end_define

begin_define
define|#
directive|define
name|DIF_VERIFY_UDT_REPLACE_CRC
value|5
end_define

begin_define
define|#
directive|define
name|DIF_REPLACE_UDT_REPLACE_CRC
value|7
end_define

begin_define
define|#
directive|define
name|DIF_BLOCK_SIZE_512
value|0x00
end_define

begin_define
define|#
directive|define
name|DIF_BLOCK_SIZE_520
value|0x01
end_define

begin_define
define|#
directive|define
name|DIF_BLOCK_SIZE_4096
value|0x02
end_define

begin_define
define|#
directive|define
name|DIF_BLOCK_SIZE_4160
value|0x03
end_define

begin_define
define|#
directive|define
name|DIF_ACTION_FLAG_MASK
value|0x00000007
end_define

begin_comment
comment|/* 0 - 2 */
end_comment

begin_define
define|#
directive|define
name|DIF_CRC_VERIFICATION
value|0x00000008
end_define

begin_comment
comment|/* 3 */
end_comment

begin_define
define|#
directive|define
name|DIF_CRC_INVERSION
value|0x00000010
end_define

begin_comment
comment|/* 4 */
end_comment

begin_define
define|#
directive|define
name|DIF_CRC_IO_SEED
value|0x00000020
end_define

begin_comment
comment|/* 5 */
end_comment

begin_define
define|#
directive|define
name|DIF_UDT_REF_BLOCK_COUNT
value|0x00000040
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|DIF_UDT_APP_BLOCK_COUNT
value|0x00000080
end_define

begin_comment
comment|/* 7 */
end_comment

begin_define
define|#
directive|define
name|DIF_UDTR_REF_BLOCK_COUNT
value|0x00000100
end_define

begin_comment
comment|/* 8 */
end_comment

begin_define
define|#
directive|define
name|DIF_UDTR_APP_BLOCK_COUNT
value|0x00000200
end_define

begin_comment
comment|/* 9 */
end_comment

begin_define
define|#
directive|define
name|DIF_CUST_APP_TAG
value|0x00000C00
end_define

begin_comment
comment|/* 10 - 11 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_RESERVED
value|0x0000F000
end_define

begin_comment
comment|/* 12 - 15 */
end_comment

begin_define
define|#
directive|define
name|DIF_DATA_BLOCK_SIZE_MASK
value|0x000F0000
end_define

begin_comment
comment|/* 16 - 19 */
end_comment

begin_define
define|#
directive|define
name|DIF_DATA_BLOCK_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DIF_TAG_VERIFY_MASK
value|0x03F00000
end_define

begin_comment
comment|/* 20 - 25 */
end_comment

begin_define
define|#
directive|define
name|DIF_TAG_UPDATE_MASK
value|0xFC000000
end_define

begin_comment
comment|/* 26 - 31 */
end_comment

begin_define
define|#
directive|define
name|NORMAL_BLOCK_SIZE_512
value|512
end_define

begin_define
define|#
directive|define
name|NORMAL_BLOCK_SIZE_4K
value|4096
end_define

begin_define
define|#
directive|define
name|DIF_PHY_BLOCK_SIZE_512
value|512
end_define

begin_define
define|#
directive|define
name|DIF_PHY_BLOCK_SIZE_520
value|520
end_define

begin_define
define|#
directive|define
name|DIF_PHY_BLOCK_SIZE_4096
value|4096
end_define

begin_define
define|#
directive|define
name|DIF_PHY_BLOCK_SIZE_4160
value|4160
end_define

begin_define
define|#
directive|define
name|DIF_LOGIC_BLOCK_SIZE_520
value|520
end_define

begin_define
define|#
directive|define
name|DIF_LOGIC_BLOCK_SIZE_528
value|528
end_define

begin_define
define|#
directive|define
name|DIF_LOGIC_BLOCK_SIZE_4104
value|4104
end_define

begin_define
define|#
directive|define
name|DIF_LOGIC_BLOCK_SIZE_4168
value|4168
end_define

begin_typedef
typedef|typedef
struct|struct
name|tiDetailedDeviceInfo
block|{
name|bit8
name|devType_S_Rate
decl_stmt|;
comment|/* Bit 6-7: reserved        Bit 4-5: Two bits flag to specify a SAS or SATA (STP) device:                 00: SATA or STP device                 01: SSP or SMP device                 10: Direct SATA device        Bit 0-3: Connection Rate field when opening the device.                 Code Description:         00h:  Device has not been registered                 08h:  1,5 Gbps                 09h:  3,0 Gbps                 0ah:  6.0 Gbps                 All others Reserved     */
name|bit8
name|reserved1
decl_stmt|;
name|bit16
name|reserved2
decl_stmt|;
block|}
name|tiDetailedDeviceInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiDeviceInfo
block|{
name|char
modifier|*
name|localName
decl_stmt|;
name|char
modifier|*
name|localAddress
decl_stmt|;
name|char
modifier|*
name|remoteName
decl_stmt|;
name|char
modifier|*
name|remoteAddress
decl_stmt|;
name|bit16
name|osAddress1
decl_stmt|;
name|bit16
name|osAddress2
decl_stmt|;
name|bit32
name|loginState
decl_stmt|;
name|tiDetailedDeviceInfo_t
name|info
decl_stmt|;
block|}
name|tiDeviceInfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KEK_BLOB_SIZE
value|48
end_define

begin_define
define|#
directive|define
name|KEK_AUTH_SIZE
value|40
end_define

begin_define
define|#
directive|define
name|KEK_MAX_TABLE_ENTRIES
value|8
end_define

begin_define
define|#
directive|define
name|DEK_MAX_TABLES
value|2
end_define

begin_define
define|#
directive|define
name|DEK_MAX_TABLE_ENTRIES
value|(1024*4)
end_define

begin_define
define|#
directive|define
name|DEK_BLOB_SIZE_07
value|72
end_define

begin_define
define|#
directive|define
name|DEK_BLOB_SIZE_08
value|80
end_define

begin_define
define|#
directive|define
name|OPERATOR_ROLE_ID_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|HMAC_SECRET_KEY_SIZE
value|72
end_define

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptKekBlob
block|{
name|bit8
name|kekBlob
index|[
name|KEK_BLOB_SIZE
index|]
decl_stmt|;
block|}
name|tiEncryptKekBlob_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptDekBlob
block|{
name|bit8
name|dekBlob
index|[
name|DEK_BLOB_SIZE_08
index|]
decl_stmt|;
block|}
name|tiEncryptDekBlob_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|DEK_Table_s
block|{
name|tiEncryptDekBlob_t
name|Dek
index|[
name|DEK_MAX_TABLE_ENTRIES
index|]
decl_stmt|;
block|}
name|tiDEK_Table_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|DEK_Tables_s
block|{
name|tiDEK_Table_t
name|DekTable
index|[
name|DEK_MAX_TABLES
index|]
decl_stmt|;
block|}
name|tiDEK_Tables_t
typedef|;
end_typedef

begin_comment
comment|/*sTSDK  4.38  */
end_comment

begin_define
define|#
directive|define
name|OPR_MGMT_ID_STRING_SIZE
value|31
end_define

begin_typedef
typedef|typedef
struct|struct
name|tiID_s
block|{
name|bit8
name|ID
index|[
name|OPR_MGMT_ID_STRING_SIZE
index|]
decl_stmt|;
block|}
name|tiID_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptInfo
block|{
name|bit32
name|securityCipherMode
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|sectorSize
index|[
literal|6
index|]
decl_stmt|;
block|}
name|tiEncryptInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptPort
block|{
name|bit32
name|encryptEvent
decl_stmt|;
name|bit32
name|subEvent
decl_stmt|;
name|void
modifier|*
name|pData
decl_stmt|;
block|}
name|tiEncryptPort_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptDek
block|{
name|bit32
name|dekTable
decl_stmt|;
name|bit32
name|dekIndex
decl_stmt|;
block|}
name|tiEncryptDek_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncrypt
block|{
name|tiEncryptDek_t
name|dekInfo
decl_stmt|;
name|bit32
name|kekIndex
decl_stmt|;
name|agBOOLEAN
name|keyTagCheck
decl_stmt|;
name|agBOOLEAN
name|enableEncryptionPerLA
decl_stmt|;
name|bit32
name|sectorSizeIndex
decl_stmt|;
name|bit32
name|encryptMode
decl_stmt|;
name|bit32
name|keyTag_W0
decl_stmt|;
name|bit32
name|keyTag_W1
decl_stmt|;
name|bit32
name|tweakVal_W0
decl_stmt|;
name|bit32
name|tweakVal_W1
decl_stmt|;
name|bit32
name|tweakVal_W2
decl_stmt|;
name|bit32
name|tweakVal_W3
decl_stmt|;
name|bit32
name|EncryptionPerLAAddrLo
decl_stmt|;
name|bit32
name|EncryptionPerLAAddrHi
decl_stmt|;
name|bit16
name|EncryptionPerLRegion0SecCount
decl_stmt|;
name|bit16
name|reserved
decl_stmt|;
block|}
name|tiEncrypt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiHWEventMode_s
block|{
name|bit32
name|modePageOperation
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|modePageLen
decl_stmt|;
name|void
modifier|*
name|modePage
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
block|}
name|tiHWEventMode_t
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  * INITIATOR TYPES  *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiInitiatorMem
block|{
name|bit32
name|count
decl_stmt|;
name|tiMem_t
name|tdCachedMem
index|[
literal|6
index|]
decl_stmt|;
block|}
name|tiInitiatorMem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiInitiatorOption
block|{
name|bit32
name|usecsPerTick
decl_stmt|;
name|bit32
name|pageSize
decl_stmt|;
name|tiMem_t
name|dynamicDmaMem
decl_stmt|;
name|tiMem_t
name|dynamicCachedMem
decl_stmt|;
name|bit32
name|ioRequestBodySize
decl_stmt|;
block|}
name|tiInitiatorOption_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiInitiatorResource
block|{
name|tiInitiatorOption_t
name|initiatorOption
decl_stmt|;
name|tiInitiatorMem_t
name|initiatorMem
decl_stmt|;
block|}
name|tiInitiatorResource_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiLUN
block|{
name|bit8
name|lun
index|[
literal|8
index|]
decl_stmt|;
block|}
name|tiLUN_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiIniScsiCmnd
block|{
name|tiLUN_t
name|lun
decl_stmt|;
name|bit32
name|expDataLength
decl_stmt|;
name|bit32
name|taskAttribute
decl_stmt|;
name|bit32
name|crn
decl_stmt|;
name|bit8
name|cdb
index|[
literal|16
index|]
decl_stmt|;
block|}
name|tiIniScsiCmnd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiScsiInitiatorRequest
block|{
name|void
modifier|*
name|sglVirtualAddr
decl_stmt|;
name|tiIniScsiCmnd_t
name|scsiCmnd
decl_stmt|;
name|tiSgl_t
name|agSgl1
decl_stmt|;
name|tiDataDirection_t
name|dataDirection
decl_stmt|;
block|}
name|tiScsiInitiatorRequest_t
typedef|;
end_typedef

begin_comment
comment|/* This is the standard request body for I/O that requires DIF or encryption. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiSuperScsiInitiatorRequest
block|{
name|void
modifier|*
name|sglVirtualAddr
decl_stmt|;
name|tiIniScsiCmnd_t
name|scsiCmnd
decl_stmt|;
name|tiSgl_t
name|agSgl1
decl_stmt|;
name|tiDataDirection_t
name|dataDirection
decl_stmt|;
name|bit32
name|flags
decl_stmt|;
ifdef|#
directive|ifdef
name|CCBUILD_INDIRECT_CDB
name|bit32
name|IndCDBLowAddr
decl_stmt|;
comment|/* The low physical address of indirect CDB buffer in host memory */
name|bit32
name|IndCDBHighAddr
decl_stmt|;
comment|/* The high physical address of indirect CDB buffer in host memory */
name|bit32
name|IndCDBLength
decl_stmt|;
comment|/* Indirect CDB length */
name|void
modifier|*
name|IndCDBBuffer
decl_stmt|;
comment|/* Indirect SSPIU buffer */
endif|#
directive|endif
name|tiDif_t
name|Dif
decl_stmt|;
name|tiEncrypt_t
name|Encrypt
decl_stmt|;
block|}
name|tiSuperScsiInitiatorRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiSMPFrame
block|{
name|void
modifier|*
name|outFrameBuf
decl_stmt|;
name|bit32
name|outFrameAddrUpper32
decl_stmt|;
name|bit32
name|outFrameAddrLower32
decl_stmt|;
name|bit32
name|outFrameLen
decl_stmt|;
name|bit32
name|inFrameAddrUpper32
decl_stmt|;
name|bit32
name|inFrameAddrLower32
decl_stmt|;
name|bit32
name|inFrameLen
decl_stmt|;
name|bit32
name|expectedRespLen
decl_stmt|;
name|bit32
name|flag
decl_stmt|;
block|}
name|tiSMPFrame_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEVTData
block|{
name|bit32
name|SequenceNo
decl_stmt|;
name|bit32
name|TimeStamp
decl_stmt|;
name|bit32
name|Source
decl_stmt|;
name|bit32
name|Code
decl_stmt|;
name|bit8
name|Reserved
decl_stmt|;
name|bit8
name|BinaryDataLength
decl_stmt|;
name|bit8
name|DataAndMessage
index|[
name|EVENTLOG_MAX_MSG_LEN
index|]
decl_stmt|;
block|}
name|tiEVTData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bit32
function_decl|(
modifier|*
name|IsrHandler_t
function_decl|)
parameter_list|(
name|tiRoot_t
modifier|*
name|tiRoot
parameter_list|,
name|bit32
name|channelNum
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|DeferedHandler_t
function_decl|)
parameter_list|(
name|tiRoot_t
modifier|*
name|tiRoot
parameter_list|,
name|bit32
name|channelNum
parameter_list|,
name|bit32
name|count
parameter_list|,
name|bit32
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*****************************************************************************  * TARGET TYPES  *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiTargetMem
block|{
name|bit32
name|count
decl_stmt|;
name|tiMem_t
name|tdMem
index|[
literal|10
index|]
decl_stmt|;
block|}
name|tiTargetMem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiTargetOption
block|{
name|bit32
name|usecsPerTick
decl_stmt|;
name|bit32
name|pageSize
decl_stmt|;
name|bit32
name|numLgns
decl_stmt|;
name|bit32
name|numSessions
decl_stmt|;
name|bit32
name|numXchgs
decl_stmt|;
name|tiMem_t
name|dynamicDmaMem
decl_stmt|;
name|tiMem_t
name|dynamicCachedMem
decl_stmt|;
block|}
name|tiTargetOption_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|tiTargetOption_t
name|targetOption
decl_stmt|;
name|tiTargetMem_t
name|targetMem
decl_stmt|;
block|}
name|tiTargetResource_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit8
modifier|*
name|reqCDB
decl_stmt|;
name|bit8
modifier|*
name|scsiLun
decl_stmt|;
name|bit32
name|taskAttribute
decl_stmt|;
name|bit32
name|taskId
decl_stmt|;
name|bit32
name|crn
decl_stmt|;
block|}
name|tiTargetScsiCmnd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiSuperScsiTargetRequest
block|{
name|bit32
name|flags
decl_stmt|;
name|tiDif_t
name|Dif
decl_stmt|;
name|tiEncrypt_t
name|Encrypt
decl_stmt|;
name|tiSgl_t
name|agSgl
decl_stmt|;
name|void
modifier|*
name|sglVirtualAddr
decl_stmt|;
name|tiSgl_t
name|agSglMirror
decl_stmt|;
name|void
modifier|*
name|sglVirtualAddrMirror
decl_stmt|;
name|bit32
name|Offset
decl_stmt|;
name|bit32
name|DataLength
decl_stmt|;
block|}
name|tiSuperScsiTargetRequest_t
typedef|;
end_typedef

begin_comment
comment|/* SPCv controller mode page definitions */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptGeneralPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
comment|/* 0x20 */
name|bit32
name|numberOfDeks
decl_stmt|;
block|}
name|tiEncryptGeneralPage_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TD_ENC_CONFIG_PAGE_KEK_NUMBER
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|TD_ENC_CONFIG_PAGE_KEK_SHIFT
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptDekConfigPage
block|{
name|bit32
name|pageCode
decl_stmt|;
comment|/* 0x21 */
name|bit32
name|table0AddrLo
decl_stmt|;
name|bit32
name|table0AddrHi
decl_stmt|;
name|bit32
name|table0Entries
decl_stmt|;
name|bit32
name|table0Config
decl_stmt|;
name|bit32
name|table1AddrLo
decl_stmt|;
name|bit32
name|table1AddrHi
decl_stmt|;
name|bit32
name|table1Entries
decl_stmt|;
name|bit32
name|table1Config
decl_stmt|;
block|}
name|tiEncryptDekConfigPage_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TD_ENC_DEK_CONFIG_PAGE_DEK_TABLE_NUMBER
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|TD_ENC_DEK_CONFIG_PAGE_DEK_CACHE_WAYS
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|TD_ENC_DEK_CONFIG_PAGE_DPR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TD_ENC_DEK_CONFIG_PAGE_DER
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TD_ENC_DEK_CONFIG_PAGE_DEK_CACHE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|TD_ENC_DEK_CONFIG_PAGE_DEK_TABLE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|TD_ENC_DEK_CONFIG_PAGE_DEK_HDP_SHIFT
value|8
end_define

begin_comment
comment|/* CCS (Current Crypto Services)  and NOPR (Number of Operators) are valid only in GET_CONTROLLER_CONFIG */
end_comment

begin_comment
comment|/* NAR, CORCAP and USRCAP are valid only when AUT==1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptControlParamPage_s
block|{
name|bit32
name|PageCode
decl_stmt|;
comment|/* 0x22 */
name|bit32
name|CORCAP
decl_stmt|;
comment|/* Crypto Officer Role Capabilities */
name|bit32
name|USRCAP
decl_stmt|;
comment|/* User Role Capabilities */
name|bit32
name|CCS
decl_stmt|;
comment|/* Current Crypto Services */
name|bit32
name|NOPR
decl_stmt|;
comment|/* Number of Operators */
block|}
name|tiEncryptControlParamPage_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptHMACConfigPage_s
block|{
name|bit32
name|PageCode
decl_stmt|;
name|bit32
name|CustomerTag
decl_stmt|;
name|bit32
name|KeyAddrLo
decl_stmt|;
name|bit32
name|KeyAddrHi
decl_stmt|;
block|}
name|tiEncryptHMACConfigPage_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiInterruptConfigPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
comment|/* 0x05 */
name|bit32
name|vectorMask
decl_stmt|;
name|bit32
name|reserved
decl_stmt|;
name|bit32
name|ICTC0
decl_stmt|;
name|bit32
name|ICTC1
decl_stmt|;
name|bit32
name|ICTC2
decl_stmt|;
name|bit32
name|ICTC3
decl_stmt|;
name|bit32
name|ICTC4
decl_stmt|;
name|bit32
name|ICTC5
decl_stmt|;
name|bit32
name|ICTC6
decl_stmt|;
name|bit32
name|ICTC7
decl_stmt|;
block|}
name|tiInterruptConfigPage_t
typedef|;
end_typedef

begin_comment
comment|/* brief data structure for SAS protocol timer configuration page. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiSASProtocolTimerConfigurationPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
comment|/* 0x04 */
name|bit32
name|MST_MSI
decl_stmt|;
name|bit32
name|STP_SSP_MCT_TMO
decl_stmt|;
name|bit32
name|STP_FRM_TMO
decl_stmt|;
name|bit32
name|STP_IDLE_TMO
decl_stmt|;
name|bit32
name|OPNRJT_RTRY_INTVL
decl_stmt|;
name|bit32
name|Data_Cmd_OPNRJT_RTRY_TMO
decl_stmt|;
name|bit32
name|Data_Cmd_OPNRJT_RTRY_THR
decl_stmt|;
block|}
name|tiSASProtocolTimerConfigurationPage_t
typedef|;
end_typedef

begin_comment
comment|/*sTSDK 4.19   */
end_comment

begin_comment
comment|/* The command is for an operator to login to/logout from SPCve. */
end_comment

begin_comment
comment|/* Only when all IOs are quiesced, can an operator logout. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiOperatorCommandSet_s
block|{
name|bit32
name|OPRIDX_PIN_ACS
decl_stmt|;
comment|/* Access type (ACS) [4 bits] */
comment|/* KEYopr pinned in the KEK RAM (PIN) [1 bit] */
comment|/* KEYopr Index in the KEK RAM (OPRIDX) [8 bits] */
name|bit8
name|cert
index|[
literal|40
index|]
decl_stmt|;
comment|/* Operator Certificate (CERT) [40 bytes] */
name|bit32
name|reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* reserved */
block|}
name|tiOperatorCommandSet_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FIPS_SELFTEST_MAX_MSG_LEN
value|(128*1024)
end_define

begin_define
define|#
directive|define
name|FIPS_SELFTEST_MAX_DIGEST_SIZE
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptSelfTestDescriptor_s
block|{
name|bit32
name|AESNTC_AESPTC
decl_stmt|;
comment|/* AES Negative/Positive Test Case Bit Map */
name|bit32
name|KWPNTC_PKWPPTC
decl_stmt|;
comment|/* Key Wrap Negative/Positive Test Case Bit Map */
name|bit32
name|HMACNTC_HMACPTC
decl_stmt|;
comment|/* HMAC Negative Test Case Bit Map */
block|}
name|tiEncryptSelfTestDescriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptSelfTestResult_s
block|{
name|bit32
name|AESNTCS_AESPTCS
decl_stmt|;
comment|/* AES Negative/Positive Test Case Status */
name|bit32
name|KWPNTCS_PKWPPTCS
decl_stmt|;
comment|/* Key Wrap Negative/Positive Test Case Status */
name|bit32
name|HMACNTCS_HMACPTCS
decl_stmt|;
comment|/* HMAC Negative Test Case Status */
block|}
name|tiEncryptSelfTestResult_t
typedef|;
end_typedef

begin_comment
comment|/*    Tell SPCve controller the underlying SHA algorithm, where to fetch the message,    the size of the message, where to store the digest, where to fetch the secret key and the size of the key. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptHMACTestDescriptor_s
block|{
name|bit32
name|Tlen_SHAAlgo
decl_stmt|;
name|bit32
name|MsgAddrLo
decl_stmt|;
name|bit32
name|MsgAddrHi
decl_stmt|;
name|bit32
name|MsgLen
decl_stmt|;
name|bit32
name|DigestAddrLo
decl_stmt|;
name|bit32
name|DigestAddrHi
decl_stmt|;
name|bit32
name|KeyAddrLo
decl_stmt|;
name|bit32
name|KeyAddrHi
decl_stmt|;
name|bit32
name|KeyLen
decl_stmt|;
block|}
name|tiEncryptHMACTestDescriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptHMACTestResult_s
block|{
name|bit32
name|Tlen_SHAAlgo
decl_stmt|;
name|bit32
name|Reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|tiEncryptHMACTestResult_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptSHATestDescriptor_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|MsgAddrLo
decl_stmt|;
name|bit32
name|MsgAddrHi
decl_stmt|;
name|bit32
name|MsgLen
decl_stmt|;
name|bit32
name|DigestAddrLo
decl_stmt|;
name|bit32
name|DigestAddrHi
decl_stmt|;
block|}
name|tiEncryptSHATestDescriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tiEncryptSHATestResult_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword
index|[
literal|12
index|]
decl_stmt|;
block|}
name|tiEncryptSHATestResult_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TITYPES_H */
end_comment

end_unit

