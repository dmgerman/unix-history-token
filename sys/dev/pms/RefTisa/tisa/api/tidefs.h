begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************** ** ** Version Control Information: ** ** *******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************** **     *   tidefs.h  * *   Abstract:   This module contains enum and #define definition used *               by Transport Independent API (TIAPI) Layer. *      ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIDEFS_H
end_ifndef

begin_define
define|#
directive|define
name|TIDEFS_H
end_define

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osenv.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/ostypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osdebug.h>
end_include

begin_comment
comment|/*****************************************************************************  *  INITIATOR/TARGET SHARED DEFINES AND ENUMS  *****************************************************************************/
end_comment

begin_comment
comment|/*  *  Option mask parameter for tiCOMPortStart()   */
end_comment

begin_define
define|#
directive|define
name|PORTAL_ADD_MASK
value|0x00000001
end_define

begin_comment
comment|/*   * Maximum memory descriptor for Low-Level layer.  */
end_comment

begin_define
define|#
directive|define
name|MAX_LL_LAYER_MEM_DESCRIPTORS
value|64
end_define

begin_comment
comment|/*   * TI API function return types   */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiSuccess
block|,
name|tiError
block|,
name|tiBusy
block|,
name|tiIONoDevice
block|,
name|tiMemoryTooLarge
block|,
name|tiMemoryNotAvail
block|,
name|tiInvalidHandle
block|,
name|tiNotSupported
block|,
name|tiReject
block|,
name|tiIncorrectLun
block|,
name|tiDeviceBusy
block|, }
name|tiStatus_t
typedef|;
end_typedef

begin_comment
comment|/*  * Type of memory, OR-ed the bit fields.  */
end_comment

begin_comment
comment|/* Bit 0-1, cached or dma-uncached dma-cached */
end_comment

begin_define
define|#
directive|define
name|TI_DMA_MEM
value|0x00000000
end_define

begin_comment
comment|/* uncached DMA capable memory   */
end_comment

begin_define
define|#
directive|define
name|TI_CACHED_MEM
value|0x00000001
end_define

begin_comment
comment|/* cached non-DMA capable memory */
end_comment

begin_define
define|#
directive|define
name|TI_CACHED_DMA_MEM
value|0x00000002
end_define

begin_comment
comment|/* cached DMA capable memory */
end_comment

begin_define
define|#
directive|define
name|TI_DMA_MEM_CHIP
value|0x00000003
end_define

begin_comment
comment|/* Internal HW/chip memory  */
end_comment

begin_comment
comment|/* Bit2-3: location of memory */
end_comment

begin_define
define|#
directive|define
name|TI_LOC_HOST
value|0x00000000
end_define

begin_comment
comment|/* default, allocated from host */
end_comment

begin_define
define|#
directive|define
name|TI_LOC_ON_CHIP
value|0x00000004
end_define

begin_comment
comment|/* memory is from on-chip RAM   */
end_comment

begin_define
define|#
directive|define
name|TI_LOC_ON_CARD
value|0x00000008
end_define

begin_comment
comment|/* memory is from on-card RAM   */
end_comment

begin_comment
comment|/* Type of SGL list  *  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiSgl
init|=
literal|0
block|,
name|tiSglList
init|=
literal|0x80000000
block|,
name|tiExtHdr
block|}
name|tiSglType_t
typedef|;
end_typedef

begin_comment
comment|/*   * Type of mutex semaphoring/synchronization  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiSingleMutexLockPerPort
block|,
name|tiOneMutexLockPerQueue
block|}
name|tiMutexType_t
typedef|;
end_typedef

begin_comment
comment|/*   * Context (interrupt or non-interrupt)  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiInterruptContext
block|,
name|tiNonInterruptContext
block|}
name|tiIntContextType_t
typedef|;
end_typedef

begin_comment
comment|/*  * Port Event type.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiPortPanic
block|,
name|tiPortResetComplete
block|,
name|tiPortNameServerDown
block|,
name|tiPortLinkDown
block|,
name|tiPortLinkUp
block|,
name|tiPortStarted
block|,
name|tiPortStopped
block|,
name|tiPortShutdown
block|,
name|tiPortDiscoveryReady
block|,
name|tiPortResetNeeded
block|,
name|tiEncryptOperation
block|,
name|tiModePageOperation
block|}
name|tiPortEvent_t
typedef|;
end_typedef

begin_comment
comment|/*  * tiEncryptOperation Event types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiEncryptGetInfo
block|,
name|tiEncryptSetMode
block|,
name|tiEncryptKekAdd
block|,
name|tiEncryptDekInvalidate
block|,
name|tiEncryptKekStore
block|,
name|tiEncryptKekLoad
block|,
name|tiEncryptAttribRegUpdate
block|,
name|tiEncryptDekAdd
block|,
comment|/* new */
name|tiEncryptOperatorManagement
block|,
name|tiEncryptSelfTest
block|,
name|tiEncryptSetOperator
block|,
name|tiEncryptGetOperator
block|}
name|tiEncryptOp_t
typedef|;
end_typedef

begin_comment
comment|/*   * ostiPortEvent() status values for tiCOMOperatorManagement()  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiOMNotSupported
block|,
name|tiOMIllegalParam
block|,
name|tiOMKENUnwrapFail
block|,
name|tiOMNvramOpFailure
block|, }
name|tiOperatorManagementStatus_t
typedef|;
end_typedef

begin_comment
comment|/*   * ostiInitiatorIOCompleted() and ostiTargetIOError() status values   */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiIOSuccess
block|,
name|tiIOOverRun
block|,
name|tiIOUnderRun
block|,
name|tiIOFailed
block|,
name|tiIODifError
block|,
name|tiIOEncryptError
block|, }
name|tiIOStatus_t
typedef|;
end_typedef

begin_comment
comment|/*   * ostiInitiatorIOCompleted() and ostiTargetIOError() statusDetail values   */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiSMPSuccess
block|,
name|tiSMPAborted
block|,
name|tiSMPFailed
block|, }
name|tiSMPStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiDetailBusy
block|,
name|tiDetailNotValid
block|,
name|tiDetailNoLogin
block|,
name|tiDetailAbortLogin
block|,
name|tiDetailAbortReset
block|,
name|tiDetailAborted
block|,
name|tiDetailDifMismatch
block|,
name|tiDetailDifAppTagMismatch
block|,
name|tiDetailDifRefTagMismatch
block|,
name|tiDetailDifCrcMismatch
block|,
name|tiDetailDekKeyCacheMiss
block|,
name|tiDetailCipherModeInvalid
block|,
name|tiDetailDekIVMismatch
block|,
name|tiDetailDekRamInterfaceError
block|,
name|tiDetailDekIndexOutofBounds
block|,
name|tiDetailOtherError
block|,
name|tiDetailOtherErrorNoRetry
block|, }
name|tiIOStatusDetail_t
typedef|;
end_typedef

begin_comment
comment|/*   * IOCTL Status Codes  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ERR_STATUS_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|IOCTL_ERR_STATUS_MORE_DATA
value|0x01
end_define

begin_define
define|#
directive|define
name|IOCTL_ERR_STATUS_NO_MORE_DATA
value|0x02
end_define

begin_define
define|#
directive|define
name|IOCTL_ERR_STATUS_INVALID_CODE
value|0x03
end_define

begin_define
define|#
directive|define
name|IOCTL_ERR_STATUS_INVALID_DEVICE
value|0x04
end_define

begin_define
define|#
directive|define
name|IOCTL_ERR_STATUS_NOT_RESPONDING
value|0x05
end_define

begin_define
define|#
directive|define
name|IOCTL_ERR_STATUS_INTERNAL_ERROR
value|0x06
end_define

begin_define
define|#
directive|define
name|IOCTL_ERR_STATUS_NOT_SUPPORTED
value|0x07
end_define

begin_define
define|#
directive|define
name|IOCTL_ERR_FW_EVENTLOG_DISABLED
value|0x08
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FATAL_ERROR_SOFT_RESET_TRIG
value|0x72
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FATAL_ERR_CHK_SEND_TRUE
value|0x77
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FATAL_ERR_CHK_SEND_FALSE
value|0x76
end_define

begin_define
define|#
directive|define
name|IOCTL_ERROR_NO_FATAL_ERROR
value|0x77
end_define

begin_define
define|#
directive|define
name|ADAPTER_WWN_START_OFFSET
value|0x804
end_define

begin_define
define|#
directive|define
name|ADAPTER_WWN_END_OFFSET
value|0x80b
end_define

begin_define
define|#
directive|define
name|ADAPTER_WWN_SPC_START_OFFSET
value|0x704
end_define

begin_define
define|#
directive|define
name|ADAPTER_WWN_SPC_END_OFFSET
value|0x70b
end_define

begin_comment
comment|/*  * IOCTL Return Codes   */
end_comment

begin_define
define|#
directive|define
name|IOCTL_CALL_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|IOCTL_CALL_FAIL
value|0x01
end_define

begin_define
define|#
directive|define
name|IOCTL_CALL_PENDING
value|0x02
end_define

begin_define
define|#
directive|define
name|IOCTL_CALL_INVALID_CODE
value|0x03
end_define

begin_define
define|#
directive|define
name|IOCTL_CALL_INVALID_DEVICE
value|0x04
end_define

begin_define
define|#
directive|define
name|IOCTL_CALL_TIMEOUT
value|0x08
end_define

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
name|DIF_UDT_SIZE
value|6
end_define

begin_comment
comment|/*  * Login state in tiDeviceInfo_t  */
end_comment

begin_define
define|#
directive|define
name|INI_LGN_STATE_FREE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|INI_LGN_STATE_LOGIN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INI_LGN_STATE_FAIL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|INI_LGN_STATE_OTHERS
value|0x0000000F
end_define

begin_comment
comment|/*  * SecurityCipherMode in tiEncryptInfo_t and tiCOMEncryptSetMode()  */
end_comment

begin_define
define|#
directive|define
name|TI_ENCRYPT_SEC_MODE_FACT_INIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_SEC_MODE_A
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_SEC_MODE_B
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_ATTRIB_ALLOW_SMF
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_ATTRIB_AUTH_REQ
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_ATTRIB_CIPHER_XTS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_ATTRIB_CIPHER_ECB
value|0x00000001
end_define

begin_comment
comment|/*  * Status in tiEncryptInfo_t   */
end_comment

begin_define
define|#
directive|define
name|TI_ENCRYPT_STATUS_NO_NVRAM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_STATUS_NVRAM_ERROR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_STATUS_ENGINE_ERROR
value|0x00000004
end_define

begin_comment
comment|/*  * EncryptMode in tiEncrypt_t  */
end_comment

begin_define
define|#
directive|define
name|TI_ENCRYPT_MODE_XTS_AES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPT_MODE_ECB_AES
value|0x00000000
end_define

begin_comment
comment|/*  * Encrypt blob types  */
end_comment

begin_define
define|#
directive|define
name|TI_PLAINTEXT
value|0
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPTED_KEK_PMCA
value|1
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPTED_KEK_PMCB
value|2
end_define

begin_comment
comment|/*  * Encrypt DEK table key entry sizes  */
end_comment

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE16
value|0
end_define

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE24
value|1
end_define

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE32
value|2
end_define

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE40
value|3
end_define

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE48
value|4
end_define

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE56
value|5
end_define

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE64
value|6
end_define

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE72
value|7
end_define

begin_define
define|#
directive|define
name|TI_DEK_TABLE_KEY_SIZE80
value|8
end_define

begin_comment
comment|/* KEK blob size and DEK blob size and host DEK table entry number */
end_comment

begin_define
define|#
directive|define
name|TI_KEK_BLOB_SIZE
value|48
end_define

begin_define
define|#
directive|define
name|TI_KEK_MAX_TABLE_ENTRIES
value|8
end_define

begin_define
define|#
directive|define
name|TI_DEK_MAX_TABLES
value|2
end_define

begin_define
define|#
directive|define
name|TI_DEK_MAX_TABLE_ENTRIES
value|(1024*4)
end_define

begin_define
define|#
directive|define
name|TI_DEK_BLOB_SIZE
value|80
end_define

begin_comment
comment|/************************************************************ *  tiHWEventMode_t page operation definitions ************************************************************/
end_comment

begin_define
define|#
directive|define
name|tiModePageGet
value|1
end_define

begin_define
define|#
directive|define
name|tiModePageSet
value|2
end_define

begin_comment
comment|/* controller configuration page code */
end_comment

begin_define
define|#
directive|define
name|TI_SAS_PROTOCOL_TIMER_CONFIG_PAGE
value|0x04
end_define

begin_define
define|#
directive|define
name|TI_INTERRUPT_CONFIGURATION_PAGE
value|0x05
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPTION_GENERAL_CONFIG_PAGE
value|0x20
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPTION_DEK_CONFIG_PAGE
value|0x21
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPTION_CONTROL_PARM_PAGE
value|0x22
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPTION_HMAC_CONFIG_PAGE
value|0x23
end_define

begin_comment
comment|/* encryption self test type */
end_comment

begin_define
define|#
directive|define
name|TI_ENCRYPTION_TEST_TYPE_BIST
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_ENCRYPTION_TEST_TYPE_HMAC
value|0x02
end_define

begin_comment
comment|/* SHA algorithm type */
end_comment

begin_define
define|#
directive|define
name|TI_SHA_ALG_1
value|0x04
end_define

begin_define
define|#
directive|define
name|TI_SHA_ALG_256
value|0x08
end_define

begin_define
define|#
directive|define
name|TI_SHA_ALG_224
value|0x10
end_define

begin_define
define|#
directive|define
name|TI_SHA_ALG_512
value|0x20
end_define

begin_define
define|#
directive|define
name|TI_SHA_ALG_384
value|0x40
end_define

begin_define
define|#
directive|define
name|TI_SHA_1_DIGEST_SIZE
value|20
end_define

begin_define
define|#
directive|define
name|TI_SHA_256_DIGEST_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|TI_SHA_224_DIGEST_SIZE
value|28
end_define

begin_define
define|#
directive|define
name|TI_SHA_512_DIGEST_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|TI_SHA_384_DIGEST_SIZE
value|48
end_define

begin_comment
comment|/*****************************************************************************  *  INITIATOR SPECIFIC DEFINES AND ENUMS  *****************************************************************************/
end_comment

begin_comment
comment|/*   * ostiInitiatorIOCompleted() statusDetail contains SCSI status,  * when status passed in ostiInitiatorIOCompleted() is tiIOSuccess.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_GOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_CHECK_CONDITION
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_CONDITION_MET
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_INTERMEDIATE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_INTER_CONDIT_MET
value|0x14
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_RESV_CONFLICT
value|0x18
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_COMMANDTERMINATED
value|0x22
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_TASK_SET_FULL
value|0x28
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_ACA_ACTIVE
value|0x30
end_define

begin_define
define|#
directive|define
name|SCSI_STAT_TASK_ABORTED
value|0x40
end_define

begin_comment
comment|/* 01: soft error  02: not ready  03: medium error  04: hardware error  05: illegal request  06: unit attention  0b: abort command  */
end_comment

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_NO_SENSE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_RECOVERED_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_NOT_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_MEDIUM_ERROR
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_HARDWARE_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_ILLEGAL_REQUEST
value|0x05
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_UNIT_ATTENTION
value|0x06
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_DATA_PROTECT
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_BLANK_CHECK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_UNIQUE
value|0x09
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_COPY_ABORTED
value|0x0A
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_ABORTED_COMMAND
value|0x0B
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_EQUAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_VOL_OVERFLOW
value|0x0D
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_MISCOMPARE
value|0x0E
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_KEY_RESERVED
value|0x0F
end_define

begin_comment
comment|/*   * Reset option in tiCOMReset()   */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiSoftReset
block|,
name|tiHardReset
block|,
name|tiAutoReset
block|}
name|tiReset_t
typedef|;
end_typedef

begin_comment
comment|/*   * Bit 0 Mask for the persistent option in tiINIDiscoverTargets()   */
end_comment

begin_define
define|#
directive|define
name|NORMAL_ASSIGN_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FORCE_PERSISTENT_ASSIGN_MASK
value|0x00000001
end_define

begin_comment
comment|/*   * Bit 1 Mask for the auto login option in tiINIDiscoverTargets()   */
end_comment

begin_define
define|#
directive|define
name|AUTO_LOGIN_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NO_AUTO_LOGIN_MASK
value|0x00000002
end_define

begin_comment
comment|/*   * Task Management task used in tiINITaskManagement()  *  * 1 AG_ABORT TASK - aborts the task identified by the Referenced  Task Tag field.  * 2 AG_ABORT TASK SET - aborts all Tasks issued by this initiator on the Logical Unit   * 3 AG_CLEAR ACA - clears the Auto Contingent Allegiance condition.  * 4 AG_CLEAR TASK SET - Aborts all Tasks (from all initiators) for the Logical Unit.  * 5 AG_LOGICAL UNIT RESET   * 6 AG_TARGET WARM RESET  - iSCSI only  * 7 AG_TARGET_COLD_RESET  - iSCSI only  * 8 AG_TASK_REASSIGN      - iSCSI only  * 9 AG_QUERY_TASK         - SAS only  */
end_comment

begin_define
define|#
directive|define
name|AG_ABORT_TASK
value|1
end_define

begin_define
define|#
directive|define
name|AG_ABORT_TASK_SET
value|2
end_define

begin_define
define|#
directive|define
name|AG_CLEAR_ACA
value|3
end_define

begin_define
define|#
directive|define
name|AG_CLEAR_TASK_SET
value|4
end_define

begin_define
define|#
directive|define
name|AG_LOGICAL_UNIT_RESET
value|5
end_define

begin_define
define|#
directive|define
name|AG_TARGET_WARM_RESET
value|6
end_define

begin_comment
comment|/* iSCSI only */
end_comment

begin_define
define|#
directive|define
name|AG_TARGET_COLD_RESET
value|7
end_define

begin_comment
comment|/* iSCSI only */
end_comment

begin_define
define|#
directive|define
name|AG_TASK_REASSIGN
value|8
end_define

begin_comment
comment|/* iSCSI only */
end_comment

begin_define
define|#
directive|define
name|AG_QUERY_TASK
value|9
end_define

begin_comment
comment|/* SAS only   */
end_comment

begin_comment
comment|/*  * Event types for ostiInitiatorEvent()  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiIntrEventTypeCnxError
block|,
name|tiIntrEventTypeDiscovery
block|,
name|tiIntrEventTypeTransportRecovery
block|,
name|tiIntrEventTypeTaskManagement
block|,
name|tiIntrEventTypeDeviceChange
block|,
name|tiIntrEventTypeLogin
block|,
name|tiIntrEventTypeLocalAbort
block|}
name|tiIntrEventType_t
typedef|;
end_typedef

begin_comment
comment|/*  * Event status for ostiInitiatorEvent()  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiCnxUp
block|,
name|tiCnxDown
block|}
name|tiCnxEventStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiDiscOK
block|,
name|tiDiscFailed
block|}
name|tiDiscEventStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiLoginOK
block|,
name|tiLoginFailed
block|,
name|tiLogoutOK
block|,
name|tiLogoutFailed
block|}
name|tiLoginEventStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiRecOK
block|,
name|tiRecFailed
block|,
name|tiRecStarted
block|}
name|tiRecEventStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiTMOK
block|,
name|tiTMFailed
block|}
name|tiTMEventStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiDeviceRemoval
block|,
name|tiDeviceArrival
block|,
name|tiDeviceLoginReceived
block|}
name|tiDevEventStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiAbortOK
block|,
name|tiAbortFailed
block|,
name|tiAbortDelayed
block|,
name|tiAbortInProgress
block|}
name|tiAbortEventStatus_t
typedef|;
end_typedef

begin_comment
comment|/*   * SCSI SAM-2 Task Attribute  */
end_comment

begin_define
define|#
directive|define
name|TASK_UNTAGGED
value|0
end_define

begin_comment
comment|/* Untagged      */
end_comment

begin_define
define|#
directive|define
name|TASK_SIMPLE
value|1
end_define

begin_comment
comment|/* Simple        */
end_comment

begin_define
define|#
directive|define
name|TASK_ORDERED
value|2
end_define

begin_comment
comment|/* Ordered       */
end_comment

begin_define
define|#
directive|define
name|TASK_HEAD_OF_QUEUE
value|3
end_define

begin_comment
comment|/* Head of Queue */
end_comment

begin_define
define|#
directive|define
name|TASK_ACA
value|4
end_define

begin_comment
comment|/* ACA           */
end_comment

begin_comment
comment|/*  * Data direction for I/O request  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiDirectionIn
init|=
literal|0x0000
block|,
name|tiDirectionOut
init|=
literal|0x0001
block|}
name|tiDataDirection_t
typedef|;
end_typedef

begin_comment
comment|/*  * NVRAM error subEvents for encryption   */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiNVRAMSuccess
init|=
literal|0x0000
block|,
name|tiNVRAMWriteFail
init|=
literal|0x0001
block|,
name|tiNVRAMReadFail
init|=
literal|0x0002
block|,
name|tiNVRAMNotFound
init|=
literal|0x0003
block|,
name|tiNVRAMAccessTimeout
init|=
literal|0x0004
block|}
name|tiEncryptSubEvent_t
typedef|;
end_typedef

begin_comment
comment|/* Event Logging */
end_comment

begin_comment
comment|/* Event Severity Codes */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVT_SEV_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SEV_ALWAYS_ON
value|0x01
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SEV_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SEV_WARNING
value|0x03
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SEV_INFORMATIONAL
value|0x04
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SEV_DEBUG_L1
value|0x05
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SEV_DEBUG_L2
value|0x06
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SEV_DEBUG_L3
value|0x07
end_define

begin_comment
comment|/* Event Source */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_HW
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_ITSDK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_FW
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_TD_LAYER
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_TARGET
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_OSLAYER
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_RESERVED
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_RESERVED1
value|0x0000000F
end_define

begin_comment
comment|/* Event Shifter */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_HW_SHIFTER
value|28
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_ITSDK_SHIFTER
value|24
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_FW_SHIFTER
value|20
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_COMMON_LAYER_SHIFTER
value|16
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_TARGET_SHIFTER
value|12
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_OSLAYER_SHIFTER
value|8
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_RESERVED_SHIFTER
value|4
end_define

begin_define
define|#
directive|define
name|IOCTL_EVT_SRC_RESERVED1_SHIFTER
value|0
end_define

begin_define
define|#
directive|define
name|EVENTLOG_MAX_MSG_LEN
value|110
end_define

begin_define
define|#
directive|define
name|EVENT_ID_MAX
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|DISCOVERY_IN_PROGRESS
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|TI_SSP_INDIRECT_CDB_SIZE
value|64
end_define

begin_comment
comment|/*  * Flags in tiSuperScsiInitiatorRequest_t  */
end_comment

begin_define
define|#
directive|define
name|TI_SCSI_INITIATOR_DIF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_SCSI_INITIATOR_ENCRYPT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_SCSI_INITIATOR_INDIRECT_CDB
value|0x00000004
end_define

begin_comment
comment|/*****************************************************************************  *  TARGET SPECIFIC DEFINES AND ENUMS  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Event types for ostiTargetEvent()  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|tiTgtEventTypeCnxError
block|,
name|tiTgtEventTypeDeviceChange
block|}
name|tiTgtEventType_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags in tiSuperScsiTargetRequest_t  */
end_comment

begin_define
define|#
directive|define
name|TI_SCSI_TARGET_DIF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_SCSI_TARGET_MIRROR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_SCSI_TARGET_ENCRYPT
value|0x00000004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIDEFS_H */
end_comment

end_unit

