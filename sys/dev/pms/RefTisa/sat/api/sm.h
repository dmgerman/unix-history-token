begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************** **     *   sm.h  * *   Abstract:   This module defines the contants, enum and #define definition used *               by SAT Moduled (SM). *      ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_H
end_ifndef

begin_define
define|#
directive|define
name|SM_H
end_define

begin_comment
comment|/*************************************************  *   constants for type field in smMem_t  *************************************************/
end_comment

begin_define
define|#
directive|define
name|SM_CACHED_MEM
value|0x00
end_define

begin_comment
comment|/**< CACHED memory type */
end_comment

begin_define
define|#
directive|define
name|SM_DMA_MEM
value|0x01
end_define

begin_comment
comment|/**< DMA memory type */
end_comment

begin_define
define|#
directive|define
name|SM_CACHED_DMA_MEM
value|0x02
end_define

begin_comment
comment|/**< CACHED DMA memory type */
end_comment

begin_comment
comment|/*************************************************  *   constants for API return values  *************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SM_RC_SUCCESS
block|,
name|SM_RC_FAILURE
block|,
name|SM_RC_BUSY
block|,
name|SM_RC_NODEVICE
block|,
name|SM_RC_VERSION_INCOMPATIBLE
block|,
name|SM_RC_VERSION_UNTESTED
block|,
name|SM_RC_RSV1
block|,
name|SM_RC_RSV2
block|,
name|SM_RC_RSV3
block|,
name|SM_RC_RSV4
block|,
name|SM_RC_DEVICE_BUSY
block|,
comment|/* must be the same as tiDeviceBusy */
block|}
name|smStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|smIOSuccess
block|,
name|smIOOverRun
block|,
name|smIOUnderRun
block|,
name|smIOFailed
block|,
name|smIODifError
block|,
name|smIOEncryptError
block|,
name|smIORetry
block|,
comment|/* open retry timeout */
name|smIOSTPResourceBusy
block|,
comment|/* stp resource busy */
block|}
name|smIOStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|smDetailBusy
block|,
name|smDetailNotValid
block|,
name|smDetailNoLogin
block|,
name|smDetailAbortLogin
block|,
name|smDetailAbortReset
block|,
name|smDetailAborted
block|,
name|smDetailDifMismatch
block|,
name|smDetailDifAppTagMismatch
block|,
name|smDetailDifRefTagMismatch
block|,
name|smDetailDifCrcMismatch
block|,
name|smDetailDekKeyCacheMiss
block|,
name|smDetailCipherModeInvalid
block|,
name|smDetailDekIVMismatch
block|,
name|smDetailDekRamInterfaceError
block|,
name|smDetailDekIndexOutofBounds
block|,
name|smDetailOtherError
block|}
name|smIOStatusDetail_t
typedef|;
end_typedef

begin_comment
comment|/*  * Data direction for I/O request  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|smDirectionIn
init|=
literal|0x0000
block|,
name|smDirectionOut
init|=
literal|0x0001
block|}
name|smDataDirection_t
typedef|;
end_typedef

begin_comment
comment|/*  * Event types for tdsmEventCB()  * do not change: Needs to be in sync with TISA API  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|smIntrEventTypeCnxError
block|,
name|smIntrEventTypeDiscovery
block|,
name|smIntrEventTypeTransportRecovery
block|,
name|smIntrEventTypeTaskManagement
block|,
name|smIntrEventTypeDeviceChange
block|,
name|smIntrEventTypeLogin
block|,
name|smIntrEventTypeLocalAbort
block|}
name|smIntrEventType_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|smTMOK
block|,
name|smTMFailed
block|}
name|smTMEventStatus_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags in smSuperScsiInitiatorRequest_t  */
end_comment

begin_define
define|#
directive|define
name|SM_SCSI_INITIATOR_DIF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SM_SCSI_INITIATOR_ENCRYPT
value|0x00000002
end_define

begin_comment
comment|/*  * Flags in smSuperScsiInitiatorRequest_t  */
end_comment

begin_define
define|#
directive|define
name|SM_SCSI_TARGET_DIF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SM_SCSI_TARGET_MIRROR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SM_SCSI_TARGET_ENCRYPT
value|0x00000004
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|tdData
decl_stmt|;
name|void
modifier|*
name|smData
decl_stmt|;
block|}
name|smContext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|smContext_t
name|smDeviceHandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|smContext_t
name|smIORequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|smContext_t
name|smRoot_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit8
name|lun
index|[
literal|8
index|]
decl_stmt|;
comment|/* logical unit number  */
block|}
name|smLUN_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|smLUN_t
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
name|smIniScsiCmnd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
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
name|smMem_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SM_NUM_MEM_CHUNKS
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit32
name|count
decl_stmt|;
name|smMem_t
name|smMemory
index|[
name|SM_NUM_MEM_CHUNKS
index|]
decl_stmt|;
block|}
name|smMemoryRequirement_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
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
name|smSgl_t
typedef|;
end_typedef

begin_comment
comment|/*  * DIF operation  */
end_comment

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
name|DIF_UDT_SIZE
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
name|smDif
block|{
name|agBOOLEAN
name|enableDIFPerLA
decl_stmt|;
name|bit32
name|flag
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
name|udrtArray
index|[
name|DIF_UDT_SIZE
index|]
decl_stmt|;
block|}
name|smDif_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smEncryptDek
block|{
name|bit32
name|dekTable
decl_stmt|;
name|bit32
name|dekIndex
decl_stmt|;
block|}
name|smEncryptDek_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smEncrypt
block|{
name|smEncryptDek_t
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
name|smEncrypt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smScsiInitiatorRequest
block|{
name|void
modifier|*
name|sglVirtualAddr
decl_stmt|;
name|smIniScsiCmnd_t
name|scsiCmnd
decl_stmt|;
name|smSgl_t
name|smSgl1
decl_stmt|;
name|smDataDirection_t
name|dataDirection
decl_stmt|;
block|}
name|smScsiInitiatorRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smSuperScsiInitiatorRequest
block|{
name|void
modifier|*
name|sglVirtualAddr
decl_stmt|;
name|smIniScsiCmnd_t
name|scsiCmnd
decl_stmt|;
name|smSgl_t
name|smSgl1
decl_stmt|;
name|smDataDirection_t
name|dataDirection
decl_stmt|;
name|bit32
name|flags
decl_stmt|;
comment|/*                                 bit 0-1: reserved                                bit 2: enable encryption                                bit 3: enable dif                                bit 4-7: reserved                                bit 8-23: DIF SKIP Bytes                                bit 24-31: Reserved                              */
name|smDif_t
name|Dif
decl_stmt|;
name|smEncrypt_t
name|Encrypt
decl_stmt|;
block|}
name|smSuperScsiInitiatorRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|senseData
decl_stmt|;
name|bit8
name|senseLen
decl_stmt|;
block|}
name|smSenseData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit32
name|maxActiveIOs
decl_stmt|;
name|bit32
name|numDevHandles
decl_stmt|;
ifdef|#
directive|ifdef
name|SM_DEBUG
name|bit32
name|SMDebugLevel
decl_stmt|;
endif|#
directive|endif
block|}
name|smSwConfig_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|smBOOLEAN
value|bit32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_H */
end_comment

end_unit

