begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   TPM2.0 Specification data structures   (Trusted Platform Module Library Specification, Family "2.0", Level 00, Revision 00.96,   @http://www.trustedcomputinggroup.org/resources/tpm_library_specification)    Check http://trustedcomputinggroup.org for latest specification updates.  Copyright (c) 2013 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TPM20_H_
end_ifndef

begin_define
define|#
directive|define
name|_TPM20_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Tpm12.h>
end_include

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|// Annex A Algorithm Constants
end_comment

begin_comment
comment|// Table 205 - Defines for SHA1 Hash Values
end_comment

begin_define
define|#
directive|define
name|SHA1_DIGEST_SIZE
value|20
end_define

begin_define
define|#
directive|define
name|SHA1_BLOCK_SIZE
value|64
end_define

begin_comment
comment|// Table 206 - Defines for SHA256 Hash Values
end_comment

begin_define
define|#
directive|define
name|SHA256_DIGEST_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|SHA256_BLOCK_SIZE
value|64
end_define

begin_comment
comment|// Table 207 - Defines for SHA384 Hash Values
end_comment

begin_define
define|#
directive|define
name|SHA384_DIGEST_SIZE
value|48
end_define

begin_define
define|#
directive|define
name|SHA384_BLOCK_SIZE
value|128
end_define

begin_comment
comment|// Table 208 - Defines for SHA512 Hash Values
end_comment

begin_define
define|#
directive|define
name|SHA512_DIGEST_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|SHA512_BLOCK_SIZE
value|128
end_define

begin_comment
comment|// Table 209 - Defines for SM3_256 Hash Values
end_comment

begin_define
define|#
directive|define
name|SM3_256_DIGEST_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|SM3_256_BLOCK_SIZE
value|64
end_define

begin_comment
comment|// Table 210 - Defines for Architectural Limits Values
end_comment

begin_define
define|#
directive|define
name|MAX_SESSION_NUMBER
value|3
end_define

begin_comment
comment|// Annex B Implementation Definitions
end_comment

begin_comment
comment|// Table 211 - Defines for Logic Values
end_comment

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_define
define|#
directive|define
name|SET
value|1
end_define

begin_define
define|#
directive|define
name|CLEAR
value|0
end_define

begin_comment
comment|// Table 215 - Defines for RSA Algorithm Constants
end_comment

begin_define
define|#
directive|define
name|MAX_RSA_KEY_BITS
value|2048
end_define

begin_define
define|#
directive|define
name|MAX_RSA_KEY_BYTES
value|((MAX_RSA_KEY_BITS + 7) / 8)
end_define

begin_comment
comment|// Table 216 - Defines for ECC Algorithm Constants
end_comment

begin_define
define|#
directive|define
name|MAX_ECC_KEY_BITS
value|256
end_define

begin_define
define|#
directive|define
name|MAX_ECC_KEY_BYTES
value|((MAX_ECC_KEY_BITS + 7) / 8)
end_define

begin_comment
comment|// Table 217 - Defines for AES Algorithm Constants
end_comment

begin_define
define|#
directive|define
name|MAX_AES_KEY_BITS
value|128
end_define

begin_define
define|#
directive|define
name|MAX_AES_BLOCK_SIZE_BYTES
value|16
end_define

begin_define
define|#
directive|define
name|MAX_AES_KEY_BYTES
value|((MAX_AES_KEY_BITS + 7) / 8)
end_define

begin_comment
comment|// Table 218 - Defines for SM4 Algorithm Constants
end_comment

begin_define
define|#
directive|define
name|MAX_SM4_KEY_BITS
value|128
end_define

begin_define
define|#
directive|define
name|MAX_SM4_BLOCK_SIZE_BYTES
value|16
end_define

begin_define
define|#
directive|define
name|MAX_SM4_KEY_BYTES
value|((MAX_SM4_KEY_BITS + 7) / 8)
end_define

begin_comment
comment|// Table 219 - Defines for Symmetric Algorithm Constants
end_comment

begin_define
define|#
directive|define
name|MAX_SYM_KEY_BITS
value|MAX_AES_KEY_BITS
end_define

begin_define
define|#
directive|define
name|MAX_SYM_KEY_BYTES
value|MAX_AES_KEY_BYTES
end_define

begin_define
define|#
directive|define
name|MAX_SYM_BLOCK_SIZE
value|MAX_AES_BLOCK_SIZE_BYTES
end_define

begin_comment
comment|// Table 220 - Defines for Implementation Values
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|BSIZE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUFFER_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|IMPLEMENTATION_PCR
value|24
end_define

begin_define
define|#
directive|define
name|PLATFORM_PCR
value|24
end_define

begin_define
define|#
directive|define
name|DRTM_PCR
value|17
end_define

begin_define
define|#
directive|define
name|NUM_LOCALITIES
value|5
end_define

begin_define
define|#
directive|define
name|MAX_HANDLE_NUM
value|3
end_define

begin_define
define|#
directive|define
name|MAX_ACTIVE_SESSIONS
value|64
end_define

begin_typedef
typedef|typedef
name|UINT16
name|CONTEXT_SLOT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|CONTEXT_COUNTER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_LOADED_SESSIONS
value|3
end_define

begin_define
define|#
directive|define
name|MAX_SESSION_NUM
value|3
end_define

begin_define
define|#
directive|define
name|MAX_LOADED_OBJECTS
value|3
end_define

begin_define
define|#
directive|define
name|MIN_EVICT_OBJECTS
value|2
end_define

begin_define
define|#
directive|define
name|PCR_SELECT_MIN
value|((PLATFORM_PCR + 7) / 8)
end_define

begin_define
define|#
directive|define
name|PCR_SELECT_MAX
value|((IMPLEMENTATION_PCR + 7) / 8)
end_define

begin_define
define|#
directive|define
name|NUM_POLICY_PCR_GROUP
value|1
end_define

begin_define
define|#
directive|define
name|NUM_AUTHVALUE_PCR_GROUP
value|1
end_define

begin_define
define|#
directive|define
name|MAX_CONTEXT_SIZE
value|4000
end_define

begin_define
define|#
directive|define
name|MAX_DIGEST_BUFFER
value|1024
end_define

begin_define
define|#
directive|define
name|MAX_NV_INDEX_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|MAX_CAP_BUFFER
value|1024
end_define

begin_define
define|#
directive|define
name|NV_MEMORY_SIZE
value|16384
end_define

begin_define
define|#
directive|define
name|NUM_STATIC_PCR
value|16
end_define

begin_define
define|#
directive|define
name|MAX_ALG_LIST_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|TIMER_PRESCALE
value|100000
end_define

begin_define
define|#
directive|define
name|PRIMARY_SEED_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|CONTEXT_ENCRYPT_ALG
value|TPM_ALG_AES
end_define

begin_define
define|#
directive|define
name|CONTEXT_ENCRYPT_KEY_BITS
value|MAX_SYM_KEY_BITS
end_define

begin_define
define|#
directive|define
name|CONTEXT_ENCRYPT_KEY_BYTES
value|((CONTEXT_ENCRYPT_KEY_BITS + 7) / 8)
end_define

begin_define
define|#
directive|define
name|CONTEXT_INTEGRITY_HASH_ALG
value|TPM_ALG_SHA256
end_define

begin_define
define|#
directive|define
name|CONTEXT_INTEGRITY_HASH_SIZE
value|SHA256_DIGEST_SIZE
end_define

begin_define
define|#
directive|define
name|PROOF_SIZE
value|CONTEXT_INTEGRITY_HASH_SIZE
end_define

begin_define
define|#
directive|define
name|NV_CLOCK_UPDATE_INTERVAL
value|12
end_define

begin_define
define|#
directive|define
name|NUM_POLICY_PCR
value|1
end_define

begin_define
define|#
directive|define
name|MAX_COMMAND_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|MAX_RESPONSE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|ORDERLY_BITS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_ORDERLY_COUNT
value|((1<< ORDERLY_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|ALG_ID_FIRST
value|TPM_ALG_FIRST
end_define

begin_define
define|#
directive|define
name|ALG_ID_LAST
value|TPM_ALG_LAST
end_define

begin_define
define|#
directive|define
name|MAX_SYM_DATA
value|128
end_define

begin_define
define|#
directive|define
name|MAX_RNG_ENTROPY_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|RAM_INDEX_SPACE
value|512
end_define

begin_define
define|#
directive|define
name|RSA_DEFAULT_PUBLIC_EXPONENT
value|0x00010001
end_define

begin_define
define|#
directive|define
name|CRT_FORMAT_RSA
value|YES
end_define

begin_define
define|#
directive|define
name|PRIVATE_VENDOR_SPECIFIC_BYTES
value|((MAX_RSA_KEY_BYTES / 2) * ( 3 + CRT_FORMAT_RSA * 2))
end_define

begin_comment
comment|// Capability related MAX_ value
end_comment

begin_define
define|#
directive|define
name|MAX_CAP_DATA
value|(MAX_CAP_BUFFER - sizeof(TPM_CAP) - sizeof(UINT32))
end_define

begin_define
define|#
directive|define
name|MAX_CAP_ALGS
value|(MAX_CAP_DATA / sizeof(TPMS_ALG_PROPERTY))
end_define

begin_define
define|#
directive|define
name|MAX_CAP_HANDLES
value|(MAX_CAP_DATA / sizeof(TPM_HANDLE))
end_define

begin_define
define|#
directive|define
name|MAX_CAP_CC
value|(MAX_CAP_DATA / sizeof(TPM_CC))
end_define

begin_define
define|#
directive|define
name|MAX_TPM_PROPERTIES
value|(MAX_CAP_DATA / sizeof(TPMS_TAGGED_PROPERTY))
end_define

begin_define
define|#
directive|define
name|MAX_PCR_PROPERTIES
value|(MAX_CAP_DATA / sizeof(TPMS_TAGGED_PCR_SELECT))
end_define

begin_define
define|#
directive|define
name|MAX_ECC_CURVES
value|(MAX_CAP_DATA / sizeof(TPM_ECC_CURVE))
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Always set 5 here, because we want to support all hash algo in BIOS.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HASH_COUNT
value|5
end_define

begin_comment
comment|// 5 Base Types
end_comment

begin_comment
comment|// Table 3 - Definition of Base Types
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|BYTE
typedef|;
end_typedef

begin_comment
comment|// Table 4 - Definition of Types for Documentation Clarity
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: Comment because it has same name as TPM1.2 (value is same, so not runtime issue)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//typedef UINT32 TPM_ALGORITHM_ID;
end_comment

begin_comment
comment|//typedef UINT32 TPM_MODIFIER_INDICATOR;
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_AUTHORIZATION_SIZE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|TPM_PARAMETER_SIZE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|TPM_KEY_SIZE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|TPM_KEY_BITS
typedef|;
end_typedef

begin_comment
comment|// 6 Constants
end_comment

begin_comment
comment|// Table 6 - TPM_GENERATED Constants
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_GENERATED
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_GENERATED_VALUE
value|(TPM_GENERATED)(0xff544347)
end_define

begin_comment
comment|// Table 7 - TPM_ALG_ID Constants
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_ALG_ID
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: Comment some algo which has same name as TPM1.2 (value is same, so not runtime issue)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_ERROR
value|(TPM_ALG_ID)(0x0000)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_FIRST
value|(TPM_ALG_ID)(0x0001)
end_define

begin_comment
comment|//#define TPM_ALG_RSA            (TPM_ALG_ID)(0x0001)
end_comment

begin_comment
comment|//#define TPM_ALG_SHA            (TPM_ALG_ID)(0x0004)
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_SHA1
value|(TPM_ALG_ID)(0x0004)
end_define

begin_comment
comment|//#define TPM_ALG_HMAC           (TPM_ALG_ID)(0x0005)
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_AES
value|(TPM_ALG_ID)(0x0006)
end_define

begin_comment
comment|//#define TPM_ALG_MGF1           (TPM_ALG_ID)(0x0007)
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_KEYEDHASH
value|(TPM_ALG_ID)(0x0008)
end_define

begin_comment
comment|//#define TPM_ALG_XOR            (TPM_ALG_ID)(0x000A)
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_SHA256
value|(TPM_ALG_ID)(0x000B)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_SHA384
value|(TPM_ALG_ID)(0x000C)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_SHA512
value|(TPM_ALG_ID)(0x000D)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_NULL
value|(TPM_ALG_ID)(0x0010)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_SM3_256
value|(TPM_ALG_ID)(0x0012)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_SM4
value|(TPM_ALG_ID)(0x0013)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_RSASSA
value|(TPM_ALG_ID)(0x0014)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_RSAES
value|(TPM_ALG_ID)(0x0015)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_RSAPSS
value|(TPM_ALG_ID)(0x0016)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_OAEP
value|(TPM_ALG_ID)(0x0017)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_ECDSA
value|(TPM_ALG_ID)(0x0018)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_ECDH
value|(TPM_ALG_ID)(0x0019)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_ECDAA
value|(TPM_ALG_ID)(0x001A)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_SM2
value|(TPM_ALG_ID)(0x001B)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_ECSCHNORR
value|(TPM_ALG_ID)(0x001C)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_ECMQV
value|(TPM_ALG_ID)(0x001D)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_KDF1_SP800_56a
value|(TPM_ALG_ID)(0x0020)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_KDF2
value|(TPM_ALG_ID)(0x0021)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_KDF1_SP800_108
value|(TPM_ALG_ID)(0x0022)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_ECC
value|(TPM_ALG_ID)(0x0023)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_SYMCIPHER
value|(TPM_ALG_ID)(0x0025)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_CTR
value|(TPM_ALG_ID)(0x0040)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_OFB
value|(TPM_ALG_ID)(0x0041)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_CBC
value|(TPM_ALG_ID)(0x0042)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_CFB
value|(TPM_ALG_ID)(0x0043)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_ECB
value|(TPM_ALG_ID)(0x0044)
end_define

begin_define
define|#
directive|define
name|TPM_ALG_LAST
value|(TPM_ALG_ID)(0x0044)
end_define

begin_comment
comment|// Table 8 - TPM_ECC_CURVE Constants
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_ECC_CURVE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_ECC_NONE
value|(TPM_ECC_CURVE)(0x0000)
end_define

begin_define
define|#
directive|define
name|TPM_ECC_NIST_P192
value|(TPM_ECC_CURVE)(0x0001)
end_define

begin_define
define|#
directive|define
name|TPM_ECC_NIST_P224
value|(TPM_ECC_CURVE)(0x0002)
end_define

begin_define
define|#
directive|define
name|TPM_ECC_NIST_P256
value|(TPM_ECC_CURVE)(0x0003)
end_define

begin_define
define|#
directive|define
name|TPM_ECC_NIST_P384
value|(TPM_ECC_CURVE)(0x0004)
end_define

begin_define
define|#
directive|define
name|TPM_ECC_NIST_P521
value|(TPM_ECC_CURVE)(0x0005)
end_define

begin_define
define|#
directive|define
name|TPM_ECC_BN_P256
value|(TPM_ECC_CURVE)(0x0010)
end_define

begin_define
define|#
directive|define
name|TPM_ECC_BN_P638
value|(TPM_ECC_CURVE)(0x0011)
end_define

begin_define
define|#
directive|define
name|TPM_ECC_SM2_P256
value|(TPM_ECC_CURVE)(0x0020)
end_define

begin_comment
comment|// Table 11 - TPM_CC Constants (Numeric Order)
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_CC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_CC_FIRST
value|(TPM_CC)(0x0000011F)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PP_FIRST
value|(TPM_CC)(0x0000011F)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_UndefineSpaceSpecial
value|(TPM_CC)(0x0000011F)
end_define

begin_define
define|#
directive|define
name|TPM_CC_EvictControl
value|(TPM_CC)(0x00000120)
end_define

begin_define
define|#
directive|define
name|TPM_CC_HierarchyControl
value|(TPM_CC)(0x00000121)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_UndefineSpace
value|(TPM_CC)(0x00000122)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ChangeEPS
value|(TPM_CC)(0x00000124)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ChangePPS
value|(TPM_CC)(0x00000125)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Clear
value|(TPM_CC)(0x00000126)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ClearControl
value|(TPM_CC)(0x00000127)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ClockSet
value|(TPM_CC)(0x00000128)
end_define

begin_define
define|#
directive|define
name|TPM_CC_HierarchyChangeAuth
value|(TPM_CC)(0x00000129)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_DefineSpace
value|(TPM_CC)(0x0000012A)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PCR_Allocate
value|(TPM_CC)(0x0000012B)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PCR_SetAuthPolicy
value|(TPM_CC)(0x0000012C)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PP_Commands
value|(TPM_CC)(0x0000012D)
end_define

begin_define
define|#
directive|define
name|TPM_CC_SetPrimaryPolicy
value|(TPM_CC)(0x0000012E)
end_define

begin_define
define|#
directive|define
name|TPM_CC_FieldUpgradeStart
value|(TPM_CC)(0x0000012F)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ClockRateAdjust
value|(TPM_CC)(0x00000130)
end_define

begin_define
define|#
directive|define
name|TPM_CC_CreatePrimary
value|(TPM_CC)(0x00000131)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_GlobalWriteLock
value|(TPM_CC)(0x00000132)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PP_LAST
value|(TPM_CC)(0x00000132)
end_define

begin_define
define|#
directive|define
name|TPM_CC_GetCommandAuditDigest
value|(TPM_CC)(0x00000133)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_Increment
value|(TPM_CC)(0x00000134)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_SetBits
value|(TPM_CC)(0x00000135)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_Extend
value|(TPM_CC)(0x00000136)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_Write
value|(TPM_CC)(0x00000137)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_WriteLock
value|(TPM_CC)(0x00000138)
end_define

begin_define
define|#
directive|define
name|TPM_CC_DictionaryAttackLockReset
value|(TPM_CC)(0x00000139)
end_define

begin_define
define|#
directive|define
name|TPM_CC_DictionaryAttackParameters
value|(TPM_CC)(0x0000013A)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_ChangeAuth
value|(TPM_CC)(0x0000013B)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PCR_Event
value|(TPM_CC)(0x0000013C)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PCR_Reset
value|(TPM_CC)(0x0000013D)
end_define

begin_define
define|#
directive|define
name|TPM_CC_SequenceComplete
value|(TPM_CC)(0x0000013E)
end_define

begin_define
define|#
directive|define
name|TPM_CC_SetAlgorithmSet
value|(TPM_CC)(0x0000013F)
end_define

begin_define
define|#
directive|define
name|TPM_CC_SetCommandCodeAuditStatus
value|(TPM_CC)(0x00000140)
end_define

begin_define
define|#
directive|define
name|TPM_CC_FieldUpgradeData
value|(TPM_CC)(0x00000141)
end_define

begin_define
define|#
directive|define
name|TPM_CC_IncrementalSelfTest
value|(TPM_CC)(0x00000142)
end_define

begin_define
define|#
directive|define
name|TPM_CC_SelfTest
value|(TPM_CC)(0x00000143)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Startup
value|(TPM_CC)(0x00000144)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Shutdown
value|(TPM_CC)(0x00000145)
end_define

begin_define
define|#
directive|define
name|TPM_CC_StirRandom
value|(TPM_CC)(0x00000146)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ActivateCredential
value|(TPM_CC)(0x00000147)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Certify
value|(TPM_CC)(0x00000148)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyNV
value|(TPM_CC)(0x00000149)
end_define

begin_define
define|#
directive|define
name|TPM_CC_CertifyCreation
value|(TPM_CC)(0x0000014A)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Duplicate
value|(TPM_CC)(0x0000014B)
end_define

begin_define
define|#
directive|define
name|TPM_CC_GetTime
value|(TPM_CC)(0x0000014C)
end_define

begin_define
define|#
directive|define
name|TPM_CC_GetSessionAuditDigest
value|(TPM_CC)(0x0000014D)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_Read
value|(TPM_CC)(0x0000014E)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_ReadLock
value|(TPM_CC)(0x0000014F)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ObjectChangeAuth
value|(TPM_CC)(0x00000150)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicySecret
value|(TPM_CC)(0x00000151)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Rewrap
value|(TPM_CC)(0x00000152)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Create
value|(TPM_CC)(0x00000153)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ECDH_ZGen
value|(TPM_CC)(0x00000154)
end_define

begin_define
define|#
directive|define
name|TPM_CC_HMAC
value|(TPM_CC)(0x00000155)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Import
value|(TPM_CC)(0x00000156)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Load
value|(TPM_CC)(0x00000157)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Quote
value|(TPM_CC)(0x00000158)
end_define

begin_define
define|#
directive|define
name|TPM_CC_RSA_Decrypt
value|(TPM_CC)(0x00000159)
end_define

begin_define
define|#
directive|define
name|TPM_CC_HMAC_Start
value|(TPM_CC)(0x0000015B)
end_define

begin_define
define|#
directive|define
name|TPM_CC_SequenceUpdate
value|(TPM_CC)(0x0000015C)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Sign
value|(TPM_CC)(0x0000015D)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Unseal
value|(TPM_CC)(0x0000015E)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicySigned
value|(TPM_CC)(0x00000160)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ContextLoad
value|(TPM_CC)(0x00000161)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ContextSave
value|(TPM_CC)(0x00000162)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ECDH_KeyGen
value|(TPM_CC)(0x00000163)
end_define

begin_define
define|#
directive|define
name|TPM_CC_EncryptDecrypt
value|(TPM_CC)(0x00000164)
end_define

begin_define
define|#
directive|define
name|TPM_CC_FlushContext
value|(TPM_CC)(0x00000165)
end_define

begin_define
define|#
directive|define
name|TPM_CC_LoadExternal
value|(TPM_CC)(0x00000167)
end_define

begin_define
define|#
directive|define
name|TPM_CC_MakeCredential
value|(TPM_CC)(0x00000168)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_ReadPublic
value|(TPM_CC)(0x00000169)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyAuthorize
value|(TPM_CC)(0x0000016A)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyAuthValue
value|(TPM_CC)(0x0000016B)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyCommandCode
value|(TPM_CC)(0x0000016C)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyCounterTimer
value|(TPM_CC)(0x0000016D)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyCpHash
value|(TPM_CC)(0x0000016E)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyLocality
value|(TPM_CC)(0x0000016F)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyNameHash
value|(TPM_CC)(0x00000170)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyOR
value|(TPM_CC)(0x00000171)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyTicket
value|(TPM_CC)(0x00000172)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ReadPublic
value|(TPM_CC)(0x00000173)
end_define

begin_define
define|#
directive|define
name|TPM_CC_RSA_Encrypt
value|(TPM_CC)(0x00000174)
end_define

begin_define
define|#
directive|define
name|TPM_CC_StartAuthSession
value|(TPM_CC)(0x00000176)
end_define

begin_define
define|#
directive|define
name|TPM_CC_VerifySignature
value|(TPM_CC)(0x00000177)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ECC_Parameters
value|(TPM_CC)(0x00000178)
end_define

begin_define
define|#
directive|define
name|TPM_CC_FirmwareRead
value|(TPM_CC)(0x00000179)
end_define

begin_define
define|#
directive|define
name|TPM_CC_GetCapability
value|(TPM_CC)(0x0000017A)
end_define

begin_define
define|#
directive|define
name|TPM_CC_GetRandom
value|(TPM_CC)(0x0000017B)
end_define

begin_define
define|#
directive|define
name|TPM_CC_GetTestResult
value|(TPM_CC)(0x0000017C)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Hash
value|(TPM_CC)(0x0000017D)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PCR_Read
value|(TPM_CC)(0x0000017E)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyPCR
value|(TPM_CC)(0x0000017F)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyRestart
value|(TPM_CC)(0x00000180)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ReadClock
value|(TPM_CC)(0x00000181)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PCR_Extend
value|(TPM_CC)(0x00000182)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PCR_SetAuthValue
value|(TPM_CC)(0x00000183)
end_define

begin_define
define|#
directive|define
name|TPM_CC_NV_Certify
value|(TPM_CC)(0x00000184)
end_define

begin_define
define|#
directive|define
name|TPM_CC_EventSequenceComplete
value|(TPM_CC)(0x00000185)
end_define

begin_define
define|#
directive|define
name|TPM_CC_HashSequenceStart
value|(TPM_CC)(0x00000186)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyPhysicalPresence
value|(TPM_CC)(0x00000187)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyDuplicationSelect
value|(TPM_CC)(0x00000188)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyGetDigest
value|(TPM_CC)(0x00000189)
end_define

begin_define
define|#
directive|define
name|TPM_CC_TestParms
value|(TPM_CC)(0x0000018A)
end_define

begin_define
define|#
directive|define
name|TPM_CC_Commit
value|(TPM_CC)(0x0000018B)
end_define

begin_define
define|#
directive|define
name|TPM_CC_PolicyPassword
value|(TPM_CC)(0x0000018C)
end_define

begin_define
define|#
directive|define
name|TPM_CC_ZGen_2Phase
value|(TPM_CC)(0x0000018D)
end_define

begin_define
define|#
directive|define
name|TPM_CC_EC_Ephemeral
value|(TPM_CC)(0x0000018E)
end_define

begin_define
define|#
directive|define
name|TPM_CC_LAST
value|(TPM_CC)(0x0000018E)
end_define

begin_comment
comment|// Table 15 - TPM_RC Constants (Actions)
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_RC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_RC_SUCCESS
value|(TPM_RC)(0x000)
end_define

begin_define
define|#
directive|define
name|TPM_RC_BAD_TAG
value|(TPM_RC)(0x030)
end_define

begin_define
define|#
directive|define
name|RC_VER1
value|(TPM_RC)(0x100)
end_define

begin_define
define|#
directive|define
name|TPM_RC_INITIALIZE
value|(TPM_RC)(RC_VER1 + 0x000)
end_define

begin_define
define|#
directive|define
name|TPM_RC_FAILURE
value|(TPM_RC)(RC_VER1 + 0x001)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SEQUENCE
value|(TPM_RC)(RC_VER1 + 0x003)
end_define

begin_define
define|#
directive|define
name|TPM_RC_PRIVATE
value|(TPM_RC)(RC_VER1 + 0x00B)
end_define

begin_define
define|#
directive|define
name|TPM_RC_HMAC
value|(TPM_RC)(RC_VER1 + 0x019)
end_define

begin_define
define|#
directive|define
name|TPM_RC_DISABLED
value|(TPM_RC)(RC_VER1 + 0x020)
end_define

begin_define
define|#
directive|define
name|TPM_RC_EXCLUSIVE
value|(TPM_RC)(RC_VER1 + 0x021)
end_define

begin_define
define|#
directive|define
name|TPM_RC_AUTH_TYPE
value|(TPM_RC)(RC_VER1 + 0x024)
end_define

begin_define
define|#
directive|define
name|TPM_RC_AUTH_MISSING
value|(TPM_RC)(RC_VER1 + 0x025)
end_define

begin_define
define|#
directive|define
name|TPM_RC_POLICY
value|(TPM_RC)(RC_VER1 + 0x026)
end_define

begin_define
define|#
directive|define
name|TPM_RC_PCR
value|(TPM_RC)(RC_VER1 + 0x027)
end_define

begin_define
define|#
directive|define
name|TPM_RC_PCR_CHANGED
value|(TPM_RC)(RC_VER1 + 0x028)
end_define

begin_define
define|#
directive|define
name|TPM_RC_UPGRADE
value|(TPM_RC)(RC_VER1 + 0x02D)
end_define

begin_define
define|#
directive|define
name|TPM_RC_TOO_MANY_CONTEXTS
value|(TPM_RC)(RC_VER1 + 0x02E)
end_define

begin_define
define|#
directive|define
name|TPM_RC_AUTH_UNAVAILABLE
value|(TPM_RC)(RC_VER1 + 0x02F)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REBOOT
value|(TPM_RC)(RC_VER1 + 0x030)
end_define

begin_define
define|#
directive|define
name|TPM_RC_UNBALANCED
value|(TPM_RC)(RC_VER1 + 0x031)
end_define

begin_define
define|#
directive|define
name|TPM_RC_COMMAND_SIZE
value|(TPM_RC)(RC_VER1 + 0x042)
end_define

begin_define
define|#
directive|define
name|TPM_RC_COMMAND_CODE
value|(TPM_RC)(RC_VER1 + 0x043)
end_define

begin_define
define|#
directive|define
name|TPM_RC_AUTHSIZE
value|(TPM_RC)(RC_VER1 + 0x044)
end_define

begin_define
define|#
directive|define
name|TPM_RC_AUTH_CONTEXT
value|(TPM_RC)(RC_VER1 + 0x045)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_RANGE
value|(TPM_RC)(RC_VER1 + 0x046)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_SIZE
value|(TPM_RC)(RC_VER1 + 0x047)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_LOCKED
value|(TPM_RC)(RC_VER1 + 0x048)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_AUTHORIZATION
value|(TPM_RC)(RC_VER1 + 0x049)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_UNINITIALIZED
value|(TPM_RC)(RC_VER1 + 0x04A)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_SPACE
value|(TPM_RC)(RC_VER1 + 0x04B)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_DEFINED
value|(TPM_RC)(RC_VER1 + 0x04C)
end_define

begin_define
define|#
directive|define
name|TPM_RC_BAD_CONTEXT
value|(TPM_RC)(RC_VER1 + 0x050)
end_define

begin_define
define|#
directive|define
name|TPM_RC_CPHASH
value|(TPM_RC)(RC_VER1 + 0x051)
end_define

begin_define
define|#
directive|define
name|TPM_RC_PARENT
value|(TPM_RC)(RC_VER1 + 0x052)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NEEDS_TEST
value|(TPM_RC)(RC_VER1 + 0x053)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NO_RESULT
value|(TPM_RC)(RC_VER1 + 0x054)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SENSITIVE
value|(TPM_RC)(RC_VER1 + 0x055)
end_define

begin_define
define|#
directive|define
name|RC_MAX_FM0
value|(TPM_RC)(RC_VER1 + 0x07F)
end_define

begin_define
define|#
directive|define
name|RC_FMT1
value|(TPM_RC)(0x080)
end_define

begin_define
define|#
directive|define
name|TPM_RC_ASYMMETRIC
value|(TPM_RC)(RC_FMT1 + 0x001)
end_define

begin_define
define|#
directive|define
name|TPM_RC_ATTRIBUTES
value|(TPM_RC)(RC_FMT1 + 0x002)
end_define

begin_define
define|#
directive|define
name|TPM_RC_HASH
value|(TPM_RC)(RC_FMT1 + 0x003)
end_define

begin_define
define|#
directive|define
name|TPM_RC_VALUE
value|(TPM_RC)(RC_FMT1 + 0x004)
end_define

begin_define
define|#
directive|define
name|TPM_RC_HIERARCHY
value|(TPM_RC)(RC_FMT1 + 0x005)
end_define

begin_define
define|#
directive|define
name|TPM_RC_KEY_SIZE
value|(TPM_RC)(RC_FMT1 + 0x007)
end_define

begin_define
define|#
directive|define
name|TPM_RC_MGF
value|(TPM_RC)(RC_FMT1 + 0x008)
end_define

begin_define
define|#
directive|define
name|TPM_RC_MODE
value|(TPM_RC)(RC_FMT1 + 0x009)
end_define

begin_define
define|#
directive|define
name|TPM_RC_TYPE
value|(TPM_RC)(RC_FMT1 + 0x00A)
end_define

begin_define
define|#
directive|define
name|TPM_RC_HANDLE
value|(TPM_RC)(RC_FMT1 + 0x00B)
end_define

begin_define
define|#
directive|define
name|TPM_RC_KDF
value|(TPM_RC)(RC_FMT1 + 0x00C)
end_define

begin_define
define|#
directive|define
name|TPM_RC_RANGE
value|(TPM_RC)(RC_FMT1 + 0x00D)
end_define

begin_define
define|#
directive|define
name|TPM_RC_AUTH_FAIL
value|(TPM_RC)(RC_FMT1 + 0x00E)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NONCE
value|(TPM_RC)(RC_FMT1 + 0x00F)
end_define

begin_define
define|#
directive|define
name|TPM_RC_PP
value|(TPM_RC)(RC_FMT1 + 0x010)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SCHEME
value|(TPM_RC)(RC_FMT1 + 0x012)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SIZE
value|(TPM_RC)(RC_FMT1 + 0x015)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SYMMETRIC
value|(TPM_RC)(RC_FMT1 + 0x016)
end_define

begin_define
define|#
directive|define
name|TPM_RC_TAG
value|(TPM_RC)(RC_FMT1 + 0x017)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SELECTOR
value|(TPM_RC)(RC_FMT1 + 0x018)
end_define

begin_define
define|#
directive|define
name|TPM_RC_INSUFFICIENT
value|(TPM_RC)(RC_FMT1 + 0x01A)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SIGNATURE
value|(TPM_RC)(RC_FMT1 + 0x01B)
end_define

begin_define
define|#
directive|define
name|TPM_RC_KEY
value|(TPM_RC)(RC_FMT1 + 0x01C)
end_define

begin_define
define|#
directive|define
name|TPM_RC_POLICY_FAIL
value|(TPM_RC)(RC_FMT1 + 0x01D)
end_define

begin_define
define|#
directive|define
name|TPM_RC_INTEGRITY
value|(TPM_RC)(RC_FMT1 + 0x01F)
end_define

begin_define
define|#
directive|define
name|TPM_RC_TICKET
value|(TPM_RC)(RC_FMT1 + 0x020)
end_define

begin_define
define|#
directive|define
name|TPM_RC_RESERVED_BITS
value|(TPM_RC)(RC_FMT1 + 0x021)
end_define

begin_define
define|#
directive|define
name|TPM_RC_BAD_AUTH
value|(TPM_RC)(RC_FMT1 + 0x022)
end_define

begin_define
define|#
directive|define
name|TPM_RC_EXPIRED
value|(TPM_RC)(RC_FMT1 + 0x023)
end_define

begin_define
define|#
directive|define
name|TPM_RC_POLICY_CC
value|(TPM_RC)(RC_FMT1 + 0x024 )
end_define

begin_define
define|#
directive|define
name|TPM_RC_BINDING
value|(TPM_RC)(RC_FMT1 + 0x025)
end_define

begin_define
define|#
directive|define
name|TPM_RC_CURVE
value|(TPM_RC)(RC_FMT1 + 0x026)
end_define

begin_define
define|#
directive|define
name|TPM_RC_ECC_POINT
value|(TPM_RC)(RC_FMT1 + 0x027)
end_define

begin_define
define|#
directive|define
name|RC_WARN
value|(TPM_RC)(0x900)
end_define

begin_define
define|#
directive|define
name|TPM_RC_CONTEXT_GAP
value|(TPM_RC)(RC_WARN + 0x001)
end_define

begin_define
define|#
directive|define
name|TPM_RC_OBJECT_MEMORY
value|(TPM_RC)(RC_WARN + 0x002)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SESSION_MEMORY
value|(TPM_RC)(RC_WARN + 0x003)
end_define

begin_define
define|#
directive|define
name|TPM_RC_MEMORY
value|(TPM_RC)(RC_WARN + 0x004)
end_define

begin_define
define|#
directive|define
name|TPM_RC_SESSION_HANDLES
value|(TPM_RC)(RC_WARN + 0x005)
end_define

begin_define
define|#
directive|define
name|TPM_RC_OBJECT_HANDLES
value|(TPM_RC)(RC_WARN + 0x006)
end_define

begin_define
define|#
directive|define
name|TPM_RC_LOCALITY
value|(TPM_RC)(RC_WARN + 0x007)
end_define

begin_define
define|#
directive|define
name|TPM_RC_YIELDED
value|(TPM_RC)(RC_WARN + 0x008)
end_define

begin_define
define|#
directive|define
name|TPM_RC_CANCELED
value|(TPM_RC)(RC_WARN + 0x009)
end_define

begin_define
define|#
directive|define
name|TPM_RC_TESTING
value|(TPM_RC)(RC_WARN + 0x00A)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_H0
value|(TPM_RC)(RC_WARN + 0x010)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_H1
value|(TPM_RC)(RC_WARN + 0x011)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_H2
value|(TPM_RC)(RC_WARN + 0x012)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_H3
value|(TPM_RC)(RC_WARN + 0x013)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_H4
value|(TPM_RC)(RC_WARN + 0x014)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_H5
value|(TPM_RC)(RC_WARN + 0x015)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_H6
value|(TPM_RC)(RC_WARN + 0x016)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_S0
value|(TPM_RC)(RC_WARN + 0x018)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_S1
value|(TPM_RC)(RC_WARN + 0x019)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_S2
value|(TPM_RC)(RC_WARN + 0x01A)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_S3
value|(TPM_RC)(RC_WARN + 0x01B)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_S4
value|(TPM_RC)(RC_WARN + 0x01C)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_S5
value|(TPM_RC)(RC_WARN + 0x01D)
end_define

begin_define
define|#
directive|define
name|TPM_RC_REFERENCE_S6
value|(TPM_RC)(RC_WARN + 0x01E)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_RATE
value|(TPM_RC)(RC_WARN + 0x020)
end_define

begin_define
define|#
directive|define
name|TPM_RC_LOCKOUT
value|(TPM_RC)(RC_WARN + 0x021)
end_define

begin_define
define|#
directive|define
name|TPM_RC_RETRY
value|(TPM_RC)(RC_WARN + 0x022)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NV_UNAVAILABLE
value|(TPM_RC)(RC_WARN + 0x023)
end_define

begin_define
define|#
directive|define
name|TPM_RC_NOT_USED
value|(TPM_RC)(RC_WARN + 0x7F)
end_define

begin_define
define|#
directive|define
name|TPM_RC_H
value|(TPM_RC)(0x000)
end_define

begin_define
define|#
directive|define
name|TPM_RC_P
value|(TPM_RC)(0x040)
end_define

begin_define
define|#
directive|define
name|TPM_RC_S
value|(TPM_RC)(0x800)
end_define

begin_define
define|#
directive|define
name|TPM_RC_1
value|(TPM_RC)(0x100)
end_define

begin_define
define|#
directive|define
name|TPM_RC_2
value|(TPM_RC)(0x200)
end_define

begin_define
define|#
directive|define
name|TPM_RC_3
value|(TPM_RC)(0x300)
end_define

begin_define
define|#
directive|define
name|TPM_RC_4
value|(TPM_RC)(0x400)
end_define

begin_define
define|#
directive|define
name|TPM_RC_5
value|(TPM_RC)(0x500)
end_define

begin_define
define|#
directive|define
name|TPM_RC_6
value|(TPM_RC)(0x600)
end_define

begin_define
define|#
directive|define
name|TPM_RC_7
value|(TPM_RC)(0x700)
end_define

begin_define
define|#
directive|define
name|TPM_RC_8
value|(TPM_RC)(0x800)
end_define

begin_define
define|#
directive|define
name|TPM_RC_9
value|(TPM_RC)(0x900)
end_define

begin_define
define|#
directive|define
name|TPM_RC_A
value|(TPM_RC)(0xA00)
end_define

begin_define
define|#
directive|define
name|TPM_RC_B
value|(TPM_RC)(0xB00)
end_define

begin_define
define|#
directive|define
name|TPM_RC_C
value|(TPM_RC)(0xC00)
end_define

begin_define
define|#
directive|define
name|TPM_RC_D
value|(TPM_RC)(0xD00)
end_define

begin_define
define|#
directive|define
name|TPM_RC_E
value|(TPM_RC)(0xE00)
end_define

begin_define
define|#
directive|define
name|TPM_RC_F
value|(TPM_RC)(0xF00)
end_define

begin_define
define|#
directive|define
name|TPM_RC_N_MASK
value|(TPM_RC)(0xF00)
end_define

begin_comment
comment|// Table 16 - TPM_CLOCK_ADJUST Constants
end_comment

begin_typedef
typedef|typedef
name|INT8
name|TPM_CLOCK_ADJUST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_CLOCK_COARSE_SLOWER
value|(TPM_CLOCK_ADJUST)(-3)
end_define

begin_define
define|#
directive|define
name|TPM_CLOCK_MEDIUM_SLOWER
value|(TPM_CLOCK_ADJUST)(-2)
end_define

begin_define
define|#
directive|define
name|TPM_CLOCK_FINE_SLOWER
value|(TPM_CLOCK_ADJUST)(-1)
end_define

begin_define
define|#
directive|define
name|TPM_CLOCK_NO_CHANGE
value|(TPM_CLOCK_ADJUST)(0)
end_define

begin_define
define|#
directive|define
name|TPM_CLOCK_FINE_FASTER
value|(TPM_CLOCK_ADJUST)(1)
end_define

begin_define
define|#
directive|define
name|TPM_CLOCK_MEDIUM_FASTER
value|(TPM_CLOCK_ADJUST)(2)
end_define

begin_define
define|#
directive|define
name|TPM_CLOCK_COARSE_FASTER
value|(TPM_CLOCK_ADJUST)(3)
end_define

begin_comment
comment|// Table 17 - TPM_EO Constants
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_EO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_EO_EQ
value|(TPM_EO)(0x0000)
end_define

begin_define
define|#
directive|define
name|TPM_EO_NEQ
value|(TPM_EO)(0x0001)
end_define

begin_define
define|#
directive|define
name|TPM_EO_SIGNED_GT
value|(TPM_EO)(0x0002)
end_define

begin_define
define|#
directive|define
name|TPM_EO_UNSIGNED_GT
value|(TPM_EO)(0x0003)
end_define

begin_define
define|#
directive|define
name|TPM_EO_SIGNED_LT
value|(TPM_EO)(0x0004)
end_define

begin_define
define|#
directive|define
name|TPM_EO_UNSIGNED_LT
value|(TPM_EO)(0x0005)
end_define

begin_define
define|#
directive|define
name|TPM_EO_SIGNED_GE
value|(TPM_EO)(0x0006)
end_define

begin_define
define|#
directive|define
name|TPM_EO_UNSIGNED_GE
value|(TPM_EO)(0x0007)
end_define

begin_define
define|#
directive|define
name|TPM_EO_SIGNED_LE
value|(TPM_EO)(0x0008)
end_define

begin_define
define|#
directive|define
name|TPM_EO_UNSIGNED_LE
value|(TPM_EO)(0x0009)
end_define

begin_define
define|#
directive|define
name|TPM_EO_BITSET
value|(TPM_EO)(0x000A)
end_define

begin_define
define|#
directive|define
name|TPM_EO_BITCLEAR
value|(TPM_EO)(0x000B)
end_define

begin_comment
comment|// Table 18 - TPM_ST Constants
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_ST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_ST_RSP_COMMAND
value|(TPM_ST)(0x00C4)
end_define

begin_define
define|#
directive|define
name|TPM_ST_NULL
value|(TPM_ST)(0X8000)
end_define

begin_define
define|#
directive|define
name|TPM_ST_NO_SESSIONS
value|(TPM_ST)(0x8001)
end_define

begin_define
define|#
directive|define
name|TPM_ST_SESSIONS
value|(TPM_ST)(0x8002)
end_define

begin_define
define|#
directive|define
name|TPM_ST_ATTEST_NV
value|(TPM_ST)(0x8014)
end_define

begin_define
define|#
directive|define
name|TPM_ST_ATTEST_COMMAND_AUDIT
value|(TPM_ST)(0x8015)
end_define

begin_define
define|#
directive|define
name|TPM_ST_ATTEST_SESSION_AUDIT
value|(TPM_ST)(0x8016)
end_define

begin_define
define|#
directive|define
name|TPM_ST_ATTEST_CERTIFY
value|(TPM_ST)(0x8017)
end_define

begin_define
define|#
directive|define
name|TPM_ST_ATTEST_QUOTE
value|(TPM_ST)(0x8018)
end_define

begin_define
define|#
directive|define
name|TPM_ST_ATTEST_TIME
value|(TPM_ST)(0x8019)
end_define

begin_define
define|#
directive|define
name|TPM_ST_ATTEST_CREATION
value|(TPM_ST)(0x801A)
end_define

begin_define
define|#
directive|define
name|TPM_ST_CREATION
value|(TPM_ST)(0x8021)
end_define

begin_define
define|#
directive|define
name|TPM_ST_VERIFIED
value|(TPM_ST)(0x8022)
end_define

begin_define
define|#
directive|define
name|TPM_ST_AUTH_SECRET
value|(TPM_ST)(0x8023)
end_define

begin_define
define|#
directive|define
name|TPM_ST_HASHCHECK
value|(TPM_ST)(0x8024)
end_define

begin_define
define|#
directive|define
name|TPM_ST_AUTH_SIGNED
value|(TPM_ST)(0x8025)
end_define

begin_define
define|#
directive|define
name|TPM_ST_FU_MANIFEST
value|(TPM_ST)(0x8029)
end_define

begin_comment
comment|// Table 19 - TPM_SU Constants
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_SU
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_SU_CLEAR
value|(TPM_SU)(0x0000)
end_define

begin_define
define|#
directive|define
name|TPM_SU_STATE
value|(TPM_SU)(0x0001)
end_define

begin_comment
comment|// Table 20 - TPM_SE Constants
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|TPM_SE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_SE_HMAC
value|(TPM_SE)(0x00)
end_define

begin_define
define|#
directive|define
name|TPM_SE_POLICY
value|(TPM_SE)(0x01)
end_define

begin_define
define|#
directive|define
name|TPM_SE_TRIAL
value|(TPM_SE)(0x03)
end_define

begin_comment
comment|// Table 21 - TPM_CAP Constants
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_CAP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_CAP_FIRST
value|(TPM_CAP)(0x00000000)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_ALGS
value|(TPM_CAP)(0x00000000)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_HANDLES
value|(TPM_CAP)(0x00000001)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_COMMANDS
value|(TPM_CAP)(0x00000002)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PP_COMMANDS
value|(TPM_CAP)(0x00000003)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_AUDIT_COMMANDS
value|(TPM_CAP)(0x00000004)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PCRS
value|(TPM_CAP)(0x00000005)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_TPM_PROPERTIES
value|(TPM_CAP)(0x00000006)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PCR_PROPERTIES
value|(TPM_CAP)(0x00000007)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_ECC_CURVES
value|(TPM_CAP)(0x00000008)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_LAST
value|(TPM_CAP)(0x00000008)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_VENDOR_PROPERTY
value|(TPM_CAP)(0x00000100)
end_define

begin_comment
comment|// Table 22 - TPM_PT Constants
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_PT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_PT_NONE
value|(TPM_PT)(0x00000000)
end_define

begin_define
define|#
directive|define
name|PT_GROUP
value|(TPM_PT)(0x00000100)
end_define

begin_define
define|#
directive|define
name|PT_FIXED
value|(TPM_PT)(PT_GROUP * 1)
end_define

begin_define
define|#
directive|define
name|TPM_PT_FAMILY_INDICATOR
value|(TPM_PT)(PT_FIXED + 0)
end_define

begin_define
define|#
directive|define
name|TPM_PT_LEVEL
value|(TPM_PT)(PT_FIXED + 1)
end_define

begin_define
define|#
directive|define
name|TPM_PT_REVISION
value|(TPM_PT)(PT_FIXED + 2)
end_define

begin_define
define|#
directive|define
name|TPM_PT_DAY_OF_YEAR
value|(TPM_PT)(PT_FIXED + 3)
end_define

begin_define
define|#
directive|define
name|TPM_PT_YEAR
value|(TPM_PT)(PT_FIXED + 4)
end_define

begin_define
define|#
directive|define
name|TPM_PT_MANUFACTURER
value|(TPM_PT)(PT_FIXED + 5)
end_define

begin_define
define|#
directive|define
name|TPM_PT_VENDOR_STRING_1
value|(TPM_PT)(PT_FIXED + 6)
end_define

begin_define
define|#
directive|define
name|TPM_PT_VENDOR_STRING_2
value|(TPM_PT)(PT_FIXED + 7)
end_define

begin_define
define|#
directive|define
name|TPM_PT_VENDOR_STRING_3
value|(TPM_PT)(PT_FIXED + 8)
end_define

begin_define
define|#
directive|define
name|TPM_PT_VENDOR_STRING_4
value|(TPM_PT)(PT_FIXED + 9)
end_define

begin_define
define|#
directive|define
name|TPM_PT_VENDOR_TPM_TYPE
value|(TPM_PT)(PT_FIXED + 10)
end_define

begin_define
define|#
directive|define
name|TPM_PT_FIRMWARE_VERSION_1
value|(TPM_PT)(PT_FIXED + 11)
end_define

begin_define
define|#
directive|define
name|TPM_PT_FIRMWARE_VERSION_2
value|(TPM_PT)(PT_FIXED + 12)
end_define

begin_define
define|#
directive|define
name|TPM_PT_INPUT_BUFFER
value|(TPM_PT)(PT_FIXED + 13)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_TRANSIENT_MIN
value|(TPM_PT)(PT_FIXED + 14)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_PERSISTENT_MIN
value|(TPM_PT)(PT_FIXED + 15)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_LOADED_MIN
value|(TPM_PT)(PT_FIXED + 16)
end_define

begin_define
define|#
directive|define
name|TPM_PT_ACTIVE_SESSIONS_MAX
value|(TPM_PT)(PT_FIXED + 17)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_COUNT
value|(TPM_PT)(PT_FIXED + 18)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_SELECT_MIN
value|(TPM_PT)(PT_FIXED + 19)
end_define

begin_define
define|#
directive|define
name|TPM_PT_CONTEXT_GAP_MAX
value|(TPM_PT)(PT_FIXED + 20)
end_define

begin_define
define|#
directive|define
name|TPM_PT_NV_COUNTERS_MAX
value|(TPM_PT)(PT_FIXED + 22)
end_define

begin_define
define|#
directive|define
name|TPM_PT_NV_INDEX_MAX
value|(TPM_PT)(PT_FIXED + 23)
end_define

begin_define
define|#
directive|define
name|TPM_PT_MEMORY
value|(TPM_PT)(PT_FIXED + 24)
end_define

begin_define
define|#
directive|define
name|TPM_PT_CLOCK_UPDATE
value|(TPM_PT)(PT_FIXED + 25)
end_define

begin_define
define|#
directive|define
name|TPM_PT_CONTEXT_HASH
value|(TPM_PT)(PT_FIXED + 26)
end_define

begin_define
define|#
directive|define
name|TPM_PT_CONTEXT_SYM
value|(TPM_PT)(PT_FIXED + 27)
end_define

begin_define
define|#
directive|define
name|TPM_PT_CONTEXT_SYM_SIZE
value|(TPM_PT)(PT_FIXED + 28)
end_define

begin_define
define|#
directive|define
name|TPM_PT_ORDERLY_COUNT
value|(TPM_PT)(PT_FIXED + 29)
end_define

begin_define
define|#
directive|define
name|TPM_PT_MAX_COMMAND_SIZE
value|(TPM_PT)(PT_FIXED + 30)
end_define

begin_define
define|#
directive|define
name|TPM_PT_MAX_RESPONSE_SIZE
value|(TPM_PT)(PT_FIXED + 31)
end_define

begin_define
define|#
directive|define
name|TPM_PT_MAX_DIGEST
value|(TPM_PT)(PT_FIXED + 32)
end_define

begin_define
define|#
directive|define
name|TPM_PT_MAX_OBJECT_CONTEXT
value|(TPM_PT)(PT_FIXED + 33)
end_define

begin_define
define|#
directive|define
name|TPM_PT_MAX_SESSION_CONTEXT
value|(TPM_PT)(PT_FIXED + 34)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PS_FAMILY_INDICATOR
value|(TPM_PT)(PT_FIXED + 35)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PS_LEVEL
value|(TPM_PT)(PT_FIXED + 36)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PS_REVISION
value|(TPM_PT)(PT_FIXED + 37)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PS_DAY_OF_YEAR
value|(TPM_PT)(PT_FIXED + 38)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PS_YEAR
value|(TPM_PT)(PT_FIXED + 39)
end_define

begin_define
define|#
directive|define
name|TPM_PT_SPLIT_MAX
value|(TPM_PT)(PT_FIXED + 40)
end_define

begin_define
define|#
directive|define
name|TPM_PT_TOTAL_COMMANDS
value|(TPM_PT)(PT_FIXED + 41)
end_define

begin_define
define|#
directive|define
name|TPM_PT_LIBRARY_COMMANDS
value|(TPM_PT)(PT_FIXED + 42)
end_define

begin_define
define|#
directive|define
name|TPM_PT_VENDOR_COMMANDS
value|(TPM_PT)(PT_FIXED + 43)
end_define

begin_define
define|#
directive|define
name|PT_VAR
value|(TPM_PT)(PT_GROUP * 2)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PERMANENT
value|(TPM_PT)(PT_VAR + 0)
end_define

begin_define
define|#
directive|define
name|TPM_PT_STARTUP_CLEAR
value|(TPM_PT)(PT_VAR + 1)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_NV_INDEX
value|(TPM_PT)(PT_VAR + 2)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_LOADED
value|(TPM_PT)(PT_VAR + 3)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_LOADED_AVAIL
value|(TPM_PT)(PT_VAR + 4)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_ACTIVE
value|(TPM_PT)(PT_VAR + 5)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_ACTIVE_AVAIL
value|(TPM_PT)(PT_VAR + 6)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_TRANSIENT_AVAIL
value|(TPM_PT)(PT_VAR + 7)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_PERSISTENT
value|(TPM_PT)(PT_VAR + 8)
end_define

begin_define
define|#
directive|define
name|TPM_PT_HR_PERSISTENT_AVAIL
value|(TPM_PT)(PT_VAR + 9)
end_define

begin_define
define|#
directive|define
name|TPM_PT_NV_COUNTERS
value|(TPM_PT)(PT_VAR + 10)
end_define

begin_define
define|#
directive|define
name|TPM_PT_NV_COUNTERS_AVAIL
value|(TPM_PT)(PT_VAR + 11)
end_define

begin_define
define|#
directive|define
name|TPM_PT_ALGORITHM_SET
value|(TPM_PT)(PT_VAR + 12)
end_define

begin_define
define|#
directive|define
name|TPM_PT_LOADED_CURVES
value|(TPM_PT)(PT_VAR + 13)
end_define

begin_define
define|#
directive|define
name|TPM_PT_LOCKOUT_COUNTER
value|(TPM_PT)(PT_VAR + 14)
end_define

begin_define
define|#
directive|define
name|TPM_PT_MAX_AUTH_FAIL
value|(TPM_PT)(PT_VAR + 15)
end_define

begin_define
define|#
directive|define
name|TPM_PT_LOCKOUT_INTERVAL
value|(TPM_PT)(PT_VAR + 16)
end_define

begin_define
define|#
directive|define
name|TPM_PT_LOCKOUT_RECOVERY
value|(TPM_PT)(PT_VAR + 17)
end_define

begin_define
define|#
directive|define
name|TPM_PT_NV_WRITE_RECOVERY
value|(TPM_PT)(PT_VAR + 18)
end_define

begin_define
define|#
directive|define
name|TPM_PT_AUDIT_COUNTER_0
value|(TPM_PT)(PT_VAR + 19)
end_define

begin_define
define|#
directive|define
name|TPM_PT_AUDIT_COUNTER_1
value|(TPM_PT)(PT_VAR + 20)
end_define

begin_comment
comment|// Table 23 - TPM_PT_PCR Constants
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_PT_PCR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_PT_PCR_FIRST
value|(TPM_PT_PCR)(0x00000000)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_SAVE
value|(TPM_PT_PCR)(0x00000000)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_EXTEND_L0
value|(TPM_PT_PCR)(0x00000001)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_RESET_L0
value|(TPM_PT_PCR)(0x00000002)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_EXTEND_L1
value|(TPM_PT_PCR)(0x00000003)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_RESET_L1
value|(TPM_PT_PCR)(0x00000004)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_EXTEND_L2
value|(TPM_PT_PCR)(0x00000005)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_RESET_L2
value|(TPM_PT_PCR)(0x00000006)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_EXTEND_L3
value|(TPM_PT_PCR)(0x00000007)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_RESET_L3
value|(TPM_PT_PCR)(0x00000008)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_EXTEND_L4
value|(TPM_PT_PCR)(0x00000009)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_RESET_L4
value|(TPM_PT_PCR)(0x0000000A)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_NO_INCREMENT
value|(TPM_PT_PCR)(0x00000011)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_DRTM_RESET
value|(TPM_PT_PCR)(0x00000012)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_POLICY
value|(TPM_PT_PCR)(0x00000013)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_AUTH
value|(TPM_PT_PCR)(0x00000014)
end_define

begin_define
define|#
directive|define
name|TPM_PT_PCR_LAST
value|(TPM_PT_PCR)(0x00000014)
end_define

begin_comment
comment|// Table 24 - TPM_PS Constants
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_PS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_PS_MAIN
value|(TPM_PS)(0x00000000)
end_define

begin_define
define|#
directive|define
name|TPM_PS_PC
value|(TPM_PS)(0x00000001)
end_define

begin_define
define|#
directive|define
name|TPM_PS_PDA
value|(TPM_PS)(0x00000002)
end_define

begin_define
define|#
directive|define
name|TPM_PS_CELL_PHONE
value|(TPM_PS)(0x00000003)
end_define

begin_define
define|#
directive|define
name|TPM_PS_SERVER
value|(TPM_PS)(0x00000004)
end_define

begin_define
define|#
directive|define
name|TPM_PS_PERIPHERAL
value|(TPM_PS)(0x00000005)
end_define

begin_define
define|#
directive|define
name|TPM_PS_TSS
value|(TPM_PS)(0x00000006)
end_define

begin_define
define|#
directive|define
name|TPM_PS_STORAGE
value|(TPM_PS)(0x00000007)
end_define

begin_define
define|#
directive|define
name|TPM_PS_AUTHENTICATION
value|(TPM_PS)(0x00000008)
end_define

begin_define
define|#
directive|define
name|TPM_PS_EMBEDDED
value|(TPM_PS)(0x00000009)
end_define

begin_define
define|#
directive|define
name|TPM_PS_HARDCOPY
value|(TPM_PS)(0x0000000A)
end_define

begin_define
define|#
directive|define
name|TPM_PS_INFRASTRUCTURE
value|(TPM_PS)(0x0000000B)
end_define

begin_define
define|#
directive|define
name|TPM_PS_VIRTUALIZATION
value|(TPM_PS)(0x0000000C)
end_define

begin_define
define|#
directive|define
name|TPM_PS_TNC
value|(TPM_PS)(0x0000000D)
end_define

begin_define
define|#
directive|define
name|TPM_PS_MULTI_TENANT
value|(TPM_PS)(0x0000000E)
end_define

begin_define
define|#
directive|define
name|TPM_PS_TC
value|(TPM_PS)(0x0000000F)
end_define

begin_comment
comment|// 7 Handles
end_comment

begin_comment
comment|// Table 25 - Handles Types
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: Comment because it has same name as TPM1.2 (value is same, so not runtime issue)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//typedef UINT32    TPM_HANDLE;
end_comment

begin_comment
comment|// Table 26 - TPM_HT Constants
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|TPM_HT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_HT_PCR
value|(TPM_HT)(0x00)
end_define

begin_define
define|#
directive|define
name|TPM_HT_NV_INDEX
value|(TPM_HT)(0x01)
end_define

begin_define
define|#
directive|define
name|TPM_HT_HMAC_SESSION
value|(TPM_HT)(0x02)
end_define

begin_define
define|#
directive|define
name|TPM_HT_LOADED_SESSION
value|(TPM_HT)(0x02)
end_define

begin_define
define|#
directive|define
name|TPM_HT_POLICY_SESSION
value|(TPM_HT)(0x03)
end_define

begin_define
define|#
directive|define
name|TPM_HT_ACTIVE_SESSION
value|(TPM_HT)(0x03)
end_define

begin_define
define|#
directive|define
name|TPM_HT_PERMANENT
value|(TPM_HT)(0x40)
end_define

begin_define
define|#
directive|define
name|TPM_HT_TRANSIENT
value|(TPM_HT)(0x80)
end_define

begin_define
define|#
directive|define
name|TPM_HT_PERSISTENT
value|(TPM_HT)(0x81)
end_define

begin_comment
comment|// Table 27 - TPM_RH Constants
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_RH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_RH_FIRST
value|(TPM_RH)(0x40000000)
end_define

begin_define
define|#
directive|define
name|TPM_RH_SRK
value|(TPM_RH)(0x40000000)
end_define

begin_define
define|#
directive|define
name|TPM_RH_OWNER
value|(TPM_RH)(0x40000001)
end_define

begin_define
define|#
directive|define
name|TPM_RH_REVOKE
value|(TPM_RH)(0x40000002)
end_define

begin_define
define|#
directive|define
name|TPM_RH_TRANSPORT
value|(TPM_RH)(0x40000003)
end_define

begin_define
define|#
directive|define
name|TPM_RH_OPERATOR
value|(TPM_RH)(0x40000004)
end_define

begin_define
define|#
directive|define
name|TPM_RH_ADMIN
value|(TPM_RH)(0x40000005)
end_define

begin_define
define|#
directive|define
name|TPM_RH_EK
value|(TPM_RH)(0x40000006)
end_define

begin_define
define|#
directive|define
name|TPM_RH_NULL
value|(TPM_RH)(0x40000007)
end_define

begin_define
define|#
directive|define
name|TPM_RH_UNASSIGNED
value|(TPM_RH)(0x40000008)
end_define

begin_define
define|#
directive|define
name|TPM_RS_PW
value|(TPM_RH)(0x40000009)
end_define

begin_define
define|#
directive|define
name|TPM_RH_LOCKOUT
value|(TPM_RH)(0x4000000A)
end_define

begin_define
define|#
directive|define
name|TPM_RH_ENDORSEMENT
value|(TPM_RH)(0x4000000B)
end_define

begin_define
define|#
directive|define
name|TPM_RH_PLATFORM
value|(TPM_RH)(0x4000000C)
end_define

begin_define
define|#
directive|define
name|TPM_RH_PLATFORM_NV
value|(TPM_RH)(0x4000000D)
end_define

begin_define
define|#
directive|define
name|TPM_RH_AUTH_00
value|(TPM_RH)(0x40000010)
end_define

begin_define
define|#
directive|define
name|TPM_RH_AUTH_FF
value|(TPM_RH)(0x4000010F)
end_define

begin_define
define|#
directive|define
name|TPM_RH_LAST
value|(TPM_RH)(0x4000010F)
end_define

begin_comment
comment|// Table 28 - TPM_HC Constants
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPM_HC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HR_HANDLE_MASK
value|(TPM_HC)(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|HR_RANGE_MASK
value|(TPM_HC)(0xFF000000)
end_define

begin_define
define|#
directive|define
name|HR_SHIFT
value|(TPM_HC)(24)
end_define

begin_define
define|#
directive|define
name|HR_PCR
value|(TPM_HC)((TPM_HC)TPM_HT_PCR<< HR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HR_HMAC_SESSION
value|(TPM_HC)((TPM_HC)TPM_HT_HMAC_SESSION<< HR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HR_POLICY_SESSION
value|(TPM_HC)((TPM_HC)TPM_HT_POLICY_SESSION<< HR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HR_TRANSIENT
value|(TPM_HC)((TPM_HC)TPM_HT_TRANSIENT<< HR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HR_PERSISTENT
value|(TPM_HC)((TPM_HC)TPM_HT_PERSISTENT<< HR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HR_NV_INDEX
value|(TPM_HC)((TPM_HC)TPM_HT_NV_INDEX<< HR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HR_PERMANENT
value|(TPM_HC)((TPM_HC)TPM_HT_PERMANENT<< HR_SHIFT)
end_define

begin_define
define|#
directive|define
name|PCR_FIRST
value|(TPM_HC)(HR_PCR + 0)
end_define

begin_define
define|#
directive|define
name|PCR_LAST
value|(TPM_HC)(PCR_FIRST + IMPLEMENTATION_PCR - 1)
end_define

begin_define
define|#
directive|define
name|HMAC_SESSION_FIRST
value|(TPM_HC)(HR_HMAC_SESSION + 0)
end_define

begin_define
define|#
directive|define
name|HMAC_SESSION_LAST
value|(TPM_HC)(HMAC_SESSION_FIRST + MAX_ACTIVE_SESSIONS - 1)
end_define

begin_define
define|#
directive|define
name|LOADED_SESSION_FIRST
value|(TPM_HC)(HMAC_SESSION_FIRST)
end_define

begin_define
define|#
directive|define
name|LOADED_SESSION_LAST
value|(TPM_HC)(HMAC_SESSION_LAST)
end_define

begin_define
define|#
directive|define
name|POLICY_SESSION_FIRST
value|(TPM_HC)(HR_POLICY_SESSION + 0)
end_define

begin_define
define|#
directive|define
name|POLICY_SESSION_LAST
value|(TPM_HC)(POLICY_SESSION_FIRST + MAX_ACTIVE_SESSIONS - 1)
end_define

begin_define
define|#
directive|define
name|TRANSIENT_FIRST
value|(TPM_HC)(HR_TRANSIENT + 0)
end_define

begin_define
define|#
directive|define
name|ACTIVE_SESSION_FIRST
value|(TPM_HC)(POLICY_SESSION_FIRST)
end_define

begin_define
define|#
directive|define
name|ACTIVE_SESSION_LAST
value|(TPM_HC)(POLICY_SESSION_LAST)
end_define

begin_define
define|#
directive|define
name|TRANSIENT_LAST
value|(TPM_HC)(TRANSIENT_FIRST+MAX_LOADED_OBJECTS - 1)
end_define

begin_define
define|#
directive|define
name|PERSISTENT_FIRST
value|(TPM_HC)(HR_PERSISTENT + 0)
end_define

begin_define
define|#
directive|define
name|PERSISTENT_LAST
value|(TPM_HC)(PERSISTENT_FIRST + 0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|PLATFORM_PERSISTENT
value|(TPM_HC)(PERSISTENT_FIRST + 0x00800000)
end_define

begin_define
define|#
directive|define
name|NV_INDEX_FIRST
value|(TPM_HC)(HR_NV_INDEX + 0)
end_define

begin_define
define|#
directive|define
name|NV_INDEX_LAST
value|(TPM_HC)(NV_INDEX_FIRST + 0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|PERMANENT_FIRST
value|(TPM_HC)(TPM_RH_FIRST)
end_define

begin_define
define|#
directive|define
name|PERMANENT_LAST
value|(TPM_HC)(TPM_RH_LAST)
end_define

begin_comment
comment|// 8 Attribute Structures
end_comment

begin_comment
comment|// Table 29 - TPMA_ALGORITHM Bits
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|asymmetric
range|:
literal|1
decl_stmt|;
name|UINT32
name|symmetric
range|:
literal|1
decl_stmt|;
name|UINT32
name|hash
range|:
literal|1
decl_stmt|;
name|UINT32
name|object
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved4_7
range|:
literal|4
decl_stmt|;
name|UINT32
name|signing
range|:
literal|1
decl_stmt|;
name|UINT32
name|encrypting
range|:
literal|1
decl_stmt|;
name|UINT32
name|method
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved11_31
range|:
literal|21
decl_stmt|;
block|}
name|TPMA_ALGORITHM
typedef|;
end_typedef

begin_comment
comment|// Table 30 - TPMA_OBJECT Bits
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|reserved1
range|:
literal|1
decl_stmt|;
name|UINT32
name|fixedTPM
range|:
literal|1
decl_stmt|;
name|UINT32
name|stClear
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved4
range|:
literal|1
decl_stmt|;
name|UINT32
name|fixedParent
range|:
literal|1
decl_stmt|;
name|UINT32
name|sensitiveDataOrigin
range|:
literal|1
decl_stmt|;
name|UINT32
name|userWithAuth
range|:
literal|1
decl_stmt|;
name|UINT32
name|adminWithPolicy
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved8_9
range|:
literal|2
decl_stmt|;
name|UINT32
name|noDA
range|:
literal|1
decl_stmt|;
name|UINT32
name|encryptedDuplication
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved12_15
range|:
literal|4
decl_stmt|;
name|UINT32
name|restricted
range|:
literal|1
decl_stmt|;
name|UINT32
name|decrypt
range|:
literal|1
decl_stmt|;
name|UINT32
name|sign
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved19_31
range|:
literal|13
decl_stmt|;
block|}
name|TPMA_OBJECT
typedef|;
end_typedef

begin_comment
comment|// Table 31 - TPMA_SESSION Bits
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|continueSession
range|:
literal|1
decl_stmt|;
name|UINT8
name|auditExclusive
range|:
literal|1
decl_stmt|;
name|UINT8
name|auditReset
range|:
literal|1
decl_stmt|;
name|UINT8
name|reserved3_4
range|:
literal|2
decl_stmt|;
name|UINT8
name|decrypt
range|:
literal|1
decl_stmt|;
name|UINT8
name|encrypt
range|:
literal|1
decl_stmt|;
name|UINT8
name|audit
range|:
literal|1
decl_stmt|;
block|}
name|TPMA_SESSION
typedef|;
end_typedef

begin_comment
comment|// Table 32 - TPMA_LOCALITY Bits
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: Use low case here to resolve conflict
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|locZero
range|:
literal|1
decl_stmt|;
name|UINT8
name|locOne
range|:
literal|1
decl_stmt|;
name|UINT8
name|locTwo
range|:
literal|1
decl_stmt|;
name|UINT8
name|locThree
range|:
literal|1
decl_stmt|;
name|UINT8
name|locFour
range|:
literal|1
decl_stmt|;
name|UINT8
name|Extended
range|:
literal|3
decl_stmt|;
block|}
name|TPMA_LOCALITY
typedef|;
end_typedef

begin_comment
comment|// Table 33 - TPMA_PERMANENT Bits
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ownerAuthSet
range|:
literal|1
decl_stmt|;
name|UINT32
name|endorsementAuthSet
range|:
literal|1
decl_stmt|;
name|UINT32
name|lockoutAuthSet
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved3_7
range|:
literal|5
decl_stmt|;
name|UINT32
name|disableClear
range|:
literal|1
decl_stmt|;
name|UINT32
name|inLockout
range|:
literal|1
decl_stmt|;
name|UINT32
name|tpmGeneratedEPS
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved11_31
range|:
literal|21
decl_stmt|;
block|}
name|TPMA_PERMANENT
typedef|;
end_typedef

begin_comment
comment|// Table 34 - TPMA_STARTUP_CLEAR Bits
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|phEnable
range|:
literal|1
decl_stmt|;
name|UINT32
name|shEnable
range|:
literal|1
decl_stmt|;
name|UINT32
name|ehEnable
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved3_30
range|:
literal|28
decl_stmt|;
name|UINT32
name|orderly
range|:
literal|1
decl_stmt|;
block|}
name|TPMA_STARTUP_CLEAR
typedef|;
end_typedef

begin_comment
comment|// Table 35 - TPMA_MEMORY Bits
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|sharedRAM
range|:
literal|1
decl_stmt|;
name|UINT32
name|sharedNV
range|:
literal|1
decl_stmt|;
name|UINT32
name|objectCopiedToRam
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved3_31
range|:
literal|29
decl_stmt|;
block|}
name|TPMA_MEMORY
typedef|;
end_typedef

begin_comment
comment|// Table 36 - TPMA_CC Bits
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|commandIndex
range|:
literal|16
decl_stmt|;
name|UINT32
name|reserved16_21
range|:
literal|6
decl_stmt|;
name|UINT32
name|nv
range|:
literal|1
decl_stmt|;
name|UINT32
name|extensive
range|:
literal|1
decl_stmt|;
name|UINT32
name|flushed
range|:
literal|1
decl_stmt|;
name|UINT32
name|cHandles
range|:
literal|3
decl_stmt|;
name|UINT32
name|rHandle
range|:
literal|1
decl_stmt|;
name|UINT32
name|V
range|:
literal|1
decl_stmt|;
name|UINT32
name|Res
range|:
literal|2
decl_stmt|;
block|}
name|TPMA_CC
typedef|;
end_typedef

begin_comment
comment|// 9 Interface Types
end_comment

begin_comment
comment|// Table 37 - TPMI_YES_NO Type
end_comment

begin_typedef
typedef|typedef
name|BYTE
name|TPMI_YES_NO
typedef|;
end_typedef

begin_comment
comment|// Table 38 - TPMI_DH_OBJECT Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_DH_OBJECT
typedef|;
end_typedef

begin_comment
comment|// Table 39 - TPMI_DH_PERSISTENT Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_DH_PERSISTENT
typedef|;
end_typedef

begin_comment
comment|// Table 40 - TPMI_DH_ENTITY Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_DH_ENTITY
typedef|;
end_typedef

begin_comment
comment|// Table 41 - TPMI_DH_PCR Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_DH_PCR
typedef|;
end_typedef

begin_comment
comment|// Table 42 - TPMI_SH_AUTH_SESSION Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_SH_AUTH_SESSION
typedef|;
end_typedef

begin_comment
comment|// Table 43 - TPMI_SH_HMAC Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_SH_HMAC
typedef|;
end_typedef

begin_comment
comment|// Table 44 - TPMI_SH_POLICY Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_SH_POLICY
typedef|;
end_typedef

begin_comment
comment|// Table 45 - TPMI_DH_CONTEXT Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_DH_CONTEXT
typedef|;
end_typedef

begin_comment
comment|// Table 46 - TPMI_RH_HIERARCHY Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_HIERARCHY
typedef|;
end_typedef

begin_comment
comment|// Table 47 - TPMI_RH_HIERARCHY_AUTH Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_HIERARCHY_AUTH
typedef|;
end_typedef

begin_comment
comment|// Table 48 - TPMI_RH_PLATFORM Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_PLATFORM
typedef|;
end_typedef

begin_comment
comment|// Table 49 - TPMI_RH_OWNER Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_OWNER
typedef|;
end_typedef

begin_comment
comment|// Table 50 - TPMI_RH_ENDORSEMENT Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_ENDORSEMENT
typedef|;
end_typedef

begin_comment
comment|// Table 51 - TPMI_RH_PROVISION Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_PROVISION
typedef|;
end_typedef

begin_comment
comment|// Table 52 - TPMI_RH_CLEAR Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_CLEAR
typedef|;
end_typedef

begin_comment
comment|// Table 53 - TPMI_RH_NV_AUTH Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_NV_AUTH
typedef|;
end_typedef

begin_comment
comment|// Table 54 - TPMI_RH_LOCKOUT Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_LOCKOUT
typedef|;
end_typedef

begin_comment
comment|// Table 55 - TPMI_RH_NV_INDEX Type
end_comment

begin_typedef
typedef|typedef
name|TPM_HANDLE
name|TPMI_RH_NV_INDEX
typedef|;
end_typedef

begin_comment
comment|// Table 56 - TPMI_ALG_HASH Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_HASH
typedef|;
end_typedef

begin_comment
comment|// Table 57 - TPMI_ALG_ASYM Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_ASYM
typedef|;
end_typedef

begin_comment
comment|// Table 58 - TPMI_ALG_SYM Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_SYM
typedef|;
end_typedef

begin_comment
comment|// Table 59 - TPMI_ALG_SYM_OBJECT Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_SYM_OBJECT
typedef|;
end_typedef

begin_comment
comment|// Table 60 - TPMI_ALG_SYM_MODE Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_SYM_MODE
typedef|;
end_typedef

begin_comment
comment|// Table 61 - TPMI_ALG_KDF Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_KDF
typedef|;
end_typedef

begin_comment
comment|// Table 62 - TPMI_ALG_SIG_SCHEME Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_SIG_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 63 - TPMI_ECC_KEY_EXCHANGE Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ECC_KEY_EXCHANGE
typedef|;
end_typedef

begin_comment
comment|// Table 64 - TPMI_ST_COMMAND_TAG Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ST
name|TPMI_ST_COMMAND_TAG
typedef|;
end_typedef

begin_comment
comment|// 10 Structure Definitions
end_comment

begin_comment
comment|// Table 65 - TPMS_ALGORITHM_DESCRIPTION Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ALG_ID
name|alg
decl_stmt|;
name|TPMA_ALGORITHM
name|attributes
decl_stmt|;
block|}
name|TPMS_ALGORITHM_DESCRIPTION
typedef|;
end_typedef

begin_comment
comment|// Table 66 - TPMU_HA Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|BYTE
name|sha1
index|[
name|SHA1_DIGEST_SIZE
index|]
decl_stmt|;
name|BYTE
name|sha256
index|[
name|SHA256_DIGEST_SIZE
index|]
decl_stmt|;
name|BYTE
name|sm3_256
index|[
name|SM3_256_DIGEST_SIZE
index|]
decl_stmt|;
name|BYTE
name|sha384
index|[
name|SHA384_DIGEST_SIZE
index|]
decl_stmt|;
name|BYTE
name|sha512
index|[
name|SHA512_DIGEST_SIZE
index|]
decl_stmt|;
block|}
name|TPMU_HA
typedef|;
end_typedef

begin_comment
comment|// Table 67 - TPMT_HA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
name|TPMU_HA
name|digest
decl_stmt|;
block|}
name|TPMT_HA
typedef|;
end_typedef

begin_comment
comment|// Table 68 - TPM2B_DIGEST Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
sizeof|sizeof
argument_list|(
name|TPMU_HA
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_DIGEST
typedef|;
end_typedef

begin_comment
comment|// Table 69 - TPM2B_DATA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
sizeof|sizeof
argument_list|(
name|TPMT_HA
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_DATA
typedef|;
end_typedef

begin_comment
comment|// Table 70 - TPM2B_NONCE Types
end_comment

begin_typedef
typedef|typedef
name|TPM2B_DIGEST
name|TPM2B_NONCE
typedef|;
end_typedef

begin_comment
comment|// Table 71 - TPM2B_AUTH Types
end_comment

begin_typedef
typedef|typedef
name|TPM2B_DIGEST
name|TPM2B_AUTH
typedef|;
end_typedef

begin_comment
comment|// Table 72 - TPM2B_OPERAND Types
end_comment

begin_typedef
typedef|typedef
name|TPM2B_DIGEST
name|TPM2B_OPERAND
typedef|;
end_typedef

begin_comment
comment|// Table 73 - TPM2B_EVENT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|TPM2B_EVENT
typedef|;
end_typedef

begin_comment
comment|// Table 74 - TPM2B_MAX_BUFFER Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_DIGEST_BUFFER
index|]
decl_stmt|;
block|}
name|TPM2B_MAX_BUFFER
typedef|;
end_typedef

begin_comment
comment|// Table 75 - TPM2B_MAX_NV_BUFFER Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_NV_INDEX_SIZE
index|]
decl_stmt|;
block|}
name|TPM2B_MAX_NV_BUFFER
typedef|;
end_typedef

begin_comment
comment|// Table 76 - TPM2B_TIMEOUT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
sizeof|sizeof
argument_list|(
name|UINT64
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_TIMEOUT
typedef|;
end_typedef

begin_comment
comment|// Table 77 -- TPM2B_IV Structure<I/O>
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_SYM_BLOCK_SIZE
index|]
decl_stmt|;
block|}
name|TPM2B_IV
typedef|;
end_typedef

begin_comment
comment|// Table 78 - TPMU_NAME Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMT_HA
name|digest
decl_stmt|;
name|TPM_HANDLE
name|handle
decl_stmt|;
block|}
name|TPMU_NAME
typedef|;
end_typedef

begin_comment
comment|// Table 79 - TPM2B_NAME Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|name
index|[
sizeof|sizeof
argument_list|(
name|TPMU_NAME
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_NAME
typedef|;
end_typedef

begin_comment
comment|// Table 80 - TPMS_PCR_SELECT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|sizeofSelect
decl_stmt|;
name|BYTE
name|pcrSelect
index|[
name|PCR_SELECT_MAX
index|]
decl_stmt|;
block|}
name|TPMS_PCR_SELECT
typedef|;
end_typedef

begin_comment
comment|// Table 81 - TPMS_PCR_SELECTION Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hash
decl_stmt|;
name|UINT8
name|sizeofSelect
decl_stmt|;
name|BYTE
name|pcrSelect
index|[
name|PCR_SELECT_MAX
index|]
decl_stmt|;
block|}
name|TPMS_PCR_SELECTION
typedef|;
end_typedef

begin_comment
comment|// Table 84 - TPMT_TK_CREATION Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ST
name|tag
decl_stmt|;
name|TPMI_RH_HIERARCHY
name|hierarchy
decl_stmt|;
name|TPM2B_DIGEST
name|digest
decl_stmt|;
block|}
name|TPMT_TK_CREATION
typedef|;
end_typedef

begin_comment
comment|// Table 85 - TPMT_TK_VERIFIED Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ST
name|tag
decl_stmt|;
name|TPMI_RH_HIERARCHY
name|hierarchy
decl_stmt|;
name|TPM2B_DIGEST
name|digest
decl_stmt|;
block|}
name|TPMT_TK_VERIFIED
typedef|;
end_typedef

begin_comment
comment|// Table 86 - TPMT_TK_AUTH Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ST
name|tag
decl_stmt|;
name|TPMI_RH_HIERARCHY
name|hierarchy
decl_stmt|;
name|TPM2B_DIGEST
name|digest
decl_stmt|;
block|}
name|TPMT_TK_AUTH
typedef|;
end_typedef

begin_comment
comment|// Table 87 - TPMT_TK_HASHCHECK Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ST
name|tag
decl_stmt|;
name|TPMI_RH_HIERARCHY
name|hierarchy
decl_stmt|;
name|TPM2B_DIGEST
name|digest
decl_stmt|;
block|}
name|TPMT_TK_HASHCHECK
typedef|;
end_typedef

begin_comment
comment|// Table 88 - TPMS_ALG_PROPERTY Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ALG_ID
name|alg
decl_stmt|;
name|TPMA_ALGORITHM
name|algProperties
decl_stmt|;
block|}
name|TPMS_ALG_PROPERTY
typedef|;
end_typedef

begin_comment
comment|// Table 89 - TPMS_TAGGED_PROPERTY Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_PT
name|property
decl_stmt|;
name|UINT32
name|value
decl_stmt|;
block|}
name|TPMS_TAGGED_PROPERTY
typedef|;
end_typedef

begin_comment
comment|// Table 90 - TPMS_TAGGED_PCR_SELECT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_PT
name|tag
decl_stmt|;
name|UINT8
name|sizeofSelect
decl_stmt|;
name|BYTE
name|pcrSelect
index|[
name|PCR_SELECT_MAX
index|]
decl_stmt|;
block|}
name|TPMS_TAGGED_PCR_SELECT
typedef|;
end_typedef

begin_comment
comment|// Table 91 - TPML_CC Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPM_CC
name|commandCodes
index|[
name|MAX_CAP_CC
index|]
decl_stmt|;
block|}
name|TPML_CC
typedef|;
end_typedef

begin_comment
comment|// Table 92 - TPML_CCA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPMA_CC
name|commandAttributes
index|[
name|MAX_CAP_CC
index|]
decl_stmt|;
block|}
name|TPML_CCA
typedef|;
end_typedef

begin_comment
comment|// Table 93 - TPML_ALG Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPM_ALG_ID
name|algorithms
index|[
name|MAX_ALG_LIST_SIZE
index|]
decl_stmt|;
block|}
name|TPML_ALG
typedef|;
end_typedef

begin_comment
comment|// Table 94 - TPML_HANDLE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPM_HANDLE
name|handle
index|[
name|MAX_CAP_HANDLES
index|]
decl_stmt|;
block|}
name|TPML_HANDLE
typedef|;
end_typedef

begin_comment
comment|// Table 95 - TPML_DIGEST Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPM2B_DIGEST
name|digests
index|[
literal|8
index|]
decl_stmt|;
block|}
name|TPML_DIGEST
typedef|;
end_typedef

begin_comment
comment|// Table 96 -- TPML_DIGEST_VALUES Structure<I/O>
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPMT_HA
name|digests
index|[
name|HASH_COUNT
index|]
decl_stmt|;
block|}
name|TPML_DIGEST_VALUES
typedef|;
end_typedef

begin_comment
comment|// Table 97 - TPM2B_DIGEST_VALUES Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
sizeof|sizeof
argument_list|(
name|TPML_DIGEST_VALUES
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_DIGEST_VALUES
typedef|;
end_typedef

begin_comment
comment|// Table 98 - TPML_PCR_SELECTION Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPMS_PCR_SELECTION
name|pcrSelections
index|[
name|HASH_COUNT
index|]
decl_stmt|;
block|}
name|TPML_PCR_SELECTION
typedef|;
end_typedef

begin_comment
comment|// Table 99 - TPML_ALG_PROPERTY Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPMS_ALG_PROPERTY
name|algProperties
index|[
name|MAX_CAP_ALGS
index|]
decl_stmt|;
block|}
name|TPML_ALG_PROPERTY
typedef|;
end_typedef

begin_comment
comment|// Table 100 - TPML_TAGGED_TPM_PROPERTY Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPMS_TAGGED_PROPERTY
name|tpmProperty
index|[
name|MAX_TPM_PROPERTIES
index|]
decl_stmt|;
block|}
name|TPML_TAGGED_TPM_PROPERTY
typedef|;
end_typedef

begin_comment
comment|// Table 101 - TPML_TAGGED_PCR_PROPERTY Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPMS_TAGGED_PCR_SELECT
name|pcrProperty
index|[
name|MAX_PCR_PROPERTIES
index|]
decl_stmt|;
block|}
name|TPML_TAGGED_PCR_PROPERTY
typedef|;
end_typedef

begin_comment
comment|// Table 102 - TPML_ECC_CURVE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|count
decl_stmt|;
name|TPM_ECC_CURVE
name|eccCurves
index|[
name|MAX_ECC_CURVES
index|]
decl_stmt|;
block|}
name|TPML_ECC_CURVE
typedef|;
end_typedef

begin_comment
comment|// Table 103 - TPMU_CAPABILITIES Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPML_ALG_PROPERTY
name|algorithms
decl_stmt|;
name|TPML_HANDLE
name|handles
decl_stmt|;
name|TPML_CCA
name|command
decl_stmt|;
name|TPML_CC
name|ppCommands
decl_stmt|;
name|TPML_CC
name|auditCommands
decl_stmt|;
name|TPML_PCR_SELECTION
name|assignedPCR
decl_stmt|;
name|TPML_TAGGED_TPM_PROPERTY
name|tpmProperties
decl_stmt|;
name|TPML_TAGGED_PCR_PROPERTY
name|pcrProperties
decl_stmt|;
name|TPML_ECC_CURVE
name|eccCurves
decl_stmt|;
block|}
name|TPMU_CAPABILITIES
typedef|;
end_typedef

begin_comment
comment|// Table 104 - TPMS_CAPABILITY_DATA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_CAP
name|capability
decl_stmt|;
name|TPMU_CAPABILITIES
name|data
decl_stmt|;
block|}
name|TPMS_CAPABILITY_DATA
typedef|;
end_typedef

begin_comment
comment|// Table 105 - TPMS_CLOCK_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|clock
decl_stmt|;
name|UINT32
name|resetCount
decl_stmt|;
name|UINT32
name|restartCount
decl_stmt|;
name|TPMI_YES_NO
name|safe
decl_stmt|;
block|}
name|TPMS_CLOCK_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 106 - TPMS_TIME_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|time
decl_stmt|;
name|TPMS_CLOCK_INFO
name|clockInfo
decl_stmt|;
block|}
name|TPMS_TIME_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 107 - TPMS_TIME_ATTEST_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMS_TIME_INFO
name|time
decl_stmt|;
name|UINT64
name|firmwareVersion
decl_stmt|;
block|}
name|TPMS_TIME_ATTEST_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 108 - TPMS_CERTIFY_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_NAME
name|name
decl_stmt|;
name|TPM2B_NAME
name|qualifiedName
decl_stmt|;
block|}
name|TPMS_CERTIFY_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 109 - TPMS_QUOTE_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPML_PCR_SELECTION
name|pcrSelect
decl_stmt|;
name|TPM2B_DIGEST
name|pcrDigest
decl_stmt|;
block|}
name|TPMS_QUOTE_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 110 - TPMS_COMMAND_AUDIT_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|auditCounter
decl_stmt|;
name|TPM_ALG_ID
name|digestAlg
decl_stmt|;
name|TPM2B_DIGEST
name|auditDigest
decl_stmt|;
name|TPM2B_DIGEST
name|commandDigest
decl_stmt|;
block|}
name|TPMS_COMMAND_AUDIT_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 111 - TPMS_SESSION_AUDIT_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_YES_NO
name|exclusiveSession
decl_stmt|;
name|TPM2B_DIGEST
name|sessionDigest
decl_stmt|;
block|}
name|TPMS_SESSION_AUDIT_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 112 - TPMS_CREATION_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_NAME
name|objectName
decl_stmt|;
name|TPM2B_DIGEST
name|creationHash
decl_stmt|;
block|}
name|TPMS_CREATION_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 113 - TPMS_NV_CERTIFY_INFO Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_NAME
name|indexName
decl_stmt|;
name|UINT16
name|offset
decl_stmt|;
name|TPM2B_MAX_NV_BUFFER
name|nvContents
decl_stmt|;
block|}
name|TPMS_NV_CERTIFY_INFO
typedef|;
end_typedef

begin_comment
comment|// Table 114 - TPMI_ST_ATTEST Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ST
name|TPMI_ST_ATTEST
typedef|;
end_typedef

begin_comment
comment|// Table 115 - TPMU_ATTEST Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMS_CERTIFY_INFO
name|certify
decl_stmt|;
name|TPMS_CREATION_INFO
name|creation
decl_stmt|;
name|TPMS_QUOTE_INFO
name|quote
decl_stmt|;
name|TPMS_COMMAND_AUDIT_INFO
name|commandAudit
decl_stmt|;
name|TPMS_SESSION_AUDIT_INFO
name|sessionAudit
decl_stmt|;
name|TPMS_TIME_ATTEST_INFO
name|time
decl_stmt|;
name|TPMS_NV_CERTIFY_INFO
name|nv
decl_stmt|;
block|}
name|TPMU_ATTEST
typedef|;
end_typedef

begin_comment
comment|// Table 116 - TPMS_ATTEST Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_GENERATED
name|magic
decl_stmt|;
name|TPMI_ST_ATTEST
name|type
decl_stmt|;
name|TPM2B_NAME
name|qualifiedSigner
decl_stmt|;
name|TPM2B_DATA
name|extraData
decl_stmt|;
name|TPMS_CLOCK_INFO
name|clockInfo
decl_stmt|;
name|UINT64
name|firmwareVersion
decl_stmt|;
name|TPMU_ATTEST
name|attested
decl_stmt|;
block|}
name|TPMS_ATTEST
typedef|;
end_typedef

begin_comment
comment|// Table 117 - TPM2B_ATTEST Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|attestationData
index|[
sizeof|sizeof
argument_list|(
name|TPMS_ATTEST
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_ATTEST
typedef|;
end_typedef

begin_comment
comment|// Table 118 - TPMS_AUTH_COMMAND Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_SH_AUTH_SESSION
name|sessionHandle
decl_stmt|;
name|TPM2B_NONCE
name|nonce
decl_stmt|;
name|TPMA_SESSION
name|sessionAttributes
decl_stmt|;
name|TPM2B_AUTH
name|hmac
decl_stmt|;
block|}
name|TPMS_AUTH_COMMAND
typedef|;
end_typedef

begin_comment
comment|// Table 119 - TPMS_AUTH_RESPONSE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_NONCE
name|nonce
decl_stmt|;
name|TPMA_SESSION
name|sessionAttributes
decl_stmt|;
name|TPM2B_AUTH
name|hmac
decl_stmt|;
block|}
name|TPMS_AUTH_RESPONSE
typedef|;
end_typedef

begin_comment
comment|// 11 Algorithm Parameters and Structures
end_comment

begin_comment
comment|// Table 120 - TPMI_AES_KEY_BITS Type
end_comment

begin_typedef
typedef|typedef
name|TPM_KEY_BITS
name|TPMI_AES_KEY_BITS
typedef|;
end_typedef

begin_comment
comment|// Table 121 - TPMI_SM4_KEY_BITS Type
end_comment

begin_typedef
typedef|typedef
name|TPM_KEY_BITS
name|TPMI_SM4_KEY_BITS
typedef|;
end_typedef

begin_comment
comment|// Table 122 - TPMU_SYM_KEY_BITS Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMI_AES_KEY_BITS
name|aes
decl_stmt|;
name|TPMI_SM4_KEY_BITS
name|SM4
decl_stmt|;
name|TPM_KEY_BITS
name|sym
decl_stmt|;
name|TPMI_ALG_HASH
name|xor
decl_stmt|;
block|}
name|TPMU_SYM_KEY_BITS
typedef|;
end_typedef

begin_comment
comment|// Table 123 - TPMU_SYM_MODE Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMI_ALG_SYM_MODE
name|aes
decl_stmt|;
name|TPMI_ALG_SYM_MODE
name|SM4
decl_stmt|;
name|TPMI_ALG_SYM_MODE
name|sym
decl_stmt|;
block|}
name|TPMU_SYM_MODE
typedef|;
end_typedef

begin_comment
comment|// Table 125 - TPMT_SYM_DEF Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_SYM
name|algorithm
decl_stmt|;
name|TPMU_SYM_KEY_BITS
name|keyBits
decl_stmt|;
name|TPMU_SYM_MODE
name|mode
decl_stmt|;
block|}
name|TPMT_SYM_DEF
typedef|;
end_typedef

begin_comment
comment|// Table 126 - TPMT_SYM_DEF_OBJECT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_SYM_OBJECT
name|algorithm
decl_stmt|;
name|TPMU_SYM_KEY_BITS
name|keyBits
decl_stmt|;
name|TPMU_SYM_MODE
name|mode
decl_stmt|;
block|}
name|TPMT_SYM_DEF_OBJECT
typedef|;
end_typedef

begin_comment
comment|// Table 127 - TPM2B_SYM_KEY Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_SYM_KEY_BYTES
index|]
decl_stmt|;
block|}
name|TPM2B_SYM_KEY
typedef|;
end_typedef

begin_comment
comment|// Table 128 - TPMS_SYMCIPHER_PARMS Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMT_SYM_DEF_OBJECT
name|sym
decl_stmt|;
block|}
name|TPMS_SYMCIPHER_PARMS
typedef|;
end_typedef

begin_comment
comment|// Table 129 - TPM2B_SENSITIVE_DATA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_SYM_DATA
index|]
decl_stmt|;
block|}
name|TPM2B_SENSITIVE_DATA
typedef|;
end_typedef

begin_comment
comment|// Table 130 - TPMS_SENSITIVE_CREATE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_AUTH
name|userAuth
decl_stmt|;
name|TPM2B_SENSITIVE_DATA
name|data
decl_stmt|;
block|}
name|TPMS_SENSITIVE_CREATE
typedef|;
end_typedef

begin_comment
comment|// Table 131 - TPM2B_SENSITIVE_CREATE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|TPMS_SENSITIVE_CREATE
name|sensitive
decl_stmt|;
block|}
name|TPM2B_SENSITIVE_CREATE
typedef|;
end_typedef

begin_comment
comment|// Table 132 - TPMS_SCHEME_SIGHASH Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
block|}
name|TPMS_SCHEME_SIGHASH
typedef|;
end_typedef

begin_comment
comment|// Table 133 - TPMI_ALG_KEYEDHASH_SCHEME Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_KEYEDHASH_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 134 - HMAC_SIG_SCHEME Types
end_comment

begin_typedef
typedef|typedef
name|TPMS_SCHEME_SIGHASH
name|TPMS_SCHEME_HMAC
typedef|;
end_typedef

begin_comment
comment|// Table 135 - TPMS_SCHEME_XOR Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
name|TPMI_ALG_KDF
name|kdf
decl_stmt|;
block|}
name|TPMS_SCHEME_XOR
typedef|;
end_typedef

begin_comment
comment|// Table 136 - TPMU_SCHEME_KEYEDHASH Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMS_SCHEME_HMAC
name|hmac
decl_stmt|;
name|TPMS_SCHEME_XOR
name|xor
decl_stmt|;
block|}
name|TPMU_SCHEME_KEYEDHASH
typedef|;
end_typedef

begin_comment
comment|// Table 137 - TPMT_KEYEDHASH_SCHEME Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_KEYEDHASH_SCHEME
name|scheme
decl_stmt|;
name|TPMU_SCHEME_KEYEDHASH
name|details
decl_stmt|;
block|}
name|TPMT_KEYEDHASH_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 138 - RSA_SIG_SCHEMES Types
end_comment

begin_typedef
typedef|typedef
name|TPMS_SCHEME_SIGHASH
name|TPMS_SCHEME_RSASSA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TPMS_SCHEME_SIGHASH
name|TPMS_SCHEME_RSAPSS
typedef|;
end_typedef

begin_comment
comment|// Table 139 - ECC_SIG_SCHEMES Types
end_comment

begin_typedef
typedef|typedef
name|TPMS_SCHEME_SIGHASH
name|TPMS_SCHEME_ECDSA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TPMS_SCHEME_SIGHASH
name|TPMS_SCHEME_SM2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TPMS_SCHEME_SIGHASH
name|TPMS_SCHEME_ECSCHNORR
typedef|;
end_typedef

begin_comment
comment|// Table 140 - TPMS_SCHEME_ECDAA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
name|UINT16
name|count
decl_stmt|;
block|}
name|TPMS_SCHEME_ECDAA
typedef|;
end_typedef

begin_comment
comment|// Table 141 - TPMU_SIG_SCHEME Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMS_SCHEME_RSASSA
name|rsassa
decl_stmt|;
name|TPMS_SCHEME_RSAPSS
name|rsapss
decl_stmt|;
name|TPMS_SCHEME_ECDSA
name|ecdsa
decl_stmt|;
name|TPMS_SCHEME_ECDAA
name|ecdaa
decl_stmt|;
name|TPMS_SCHEME_ECSCHNORR
name|ecSchnorr
decl_stmt|;
name|TPMS_SCHEME_HMAC
name|hmac
decl_stmt|;
name|TPMS_SCHEME_SIGHASH
name|any
decl_stmt|;
block|}
name|TPMU_SIG_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 142 - TPMT_SIG_SCHEME Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_SIG_SCHEME
name|scheme
decl_stmt|;
name|TPMU_SIG_SCHEME
name|details
decl_stmt|;
block|}
name|TPMT_SIG_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 143 - TPMS_SCHEME_OAEP Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
block|}
name|TPMS_SCHEME_OAEP
typedef|;
end_typedef

begin_comment
comment|// Table 144 - TPMS_SCHEME_ECDH Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
block|}
name|TPMS_SCHEME_ECDH
typedef|;
end_typedef

begin_comment
comment|// Table 145 - TPMS_SCHEME_MGF1 Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
block|}
name|TPMS_SCHEME_MGF1
typedef|;
end_typedef

begin_comment
comment|// Table 146 - TPMS_SCHEME_KDF1_SP800_56a Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
block|}
name|TPMS_SCHEME_KDF1_SP800_56a
typedef|;
end_typedef

begin_comment
comment|// Table 147 - TPMS_SCHEME_KDF2 Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
block|}
name|TPMS_SCHEME_KDF2
typedef|;
end_typedef

begin_comment
comment|// Table 148 - TPMS_SCHEME_KDF1_SP800_108 Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hashAlg
decl_stmt|;
block|}
name|TPMS_SCHEME_KDF1_SP800_108
typedef|;
end_typedef

begin_comment
comment|// Table 149 - TPMU_KDF_SCHEME Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMS_SCHEME_MGF1
name|mgf1
decl_stmt|;
name|TPMS_SCHEME_KDF1_SP800_56a
name|kdf1_SP800_56a
decl_stmt|;
name|TPMS_SCHEME_KDF2
name|kdf2
decl_stmt|;
name|TPMS_SCHEME_KDF1_SP800_108
name|kdf1_sp800_108
decl_stmt|;
block|}
name|TPMU_KDF_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 150 - TPMT_KDF_SCHEME Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_KDF
name|scheme
decl_stmt|;
name|TPMU_KDF_SCHEME
name|details
decl_stmt|;
block|}
name|TPMT_KDF_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 151 - TPMI_ALG_ASYM_SCHEME Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_ASYM_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 152 - TPMU_ASYM_SCHEME Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMS_SCHEME_RSASSA
name|rsassa
decl_stmt|;
name|TPMS_SCHEME_RSAPSS
name|rsapss
decl_stmt|;
name|TPMS_SCHEME_OAEP
name|oaep
decl_stmt|;
name|TPMS_SCHEME_ECDSA
name|ecdsa
decl_stmt|;
name|TPMS_SCHEME_ECDAA
name|ecdaa
decl_stmt|;
name|TPMS_SCHEME_ECSCHNORR
name|ecSchnorr
decl_stmt|;
name|TPMS_SCHEME_SIGHASH
name|anySig
decl_stmt|;
block|}
name|TPMU_ASYM_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 153 - TPMT_ASYM_SCHEME Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_ASYM_SCHEME
name|scheme
decl_stmt|;
name|TPMU_ASYM_SCHEME
name|details
decl_stmt|;
block|}
name|TPMT_ASYM_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 154 - TPMI_ALG_RSA_SCHEME Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_RSA_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 155 - TPMT_RSA_SCHEME Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_RSA_SCHEME
name|scheme
decl_stmt|;
name|TPMU_ASYM_SCHEME
name|details
decl_stmt|;
block|}
name|TPMT_RSA_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 156 - TPMI_ALG_RSA_DECRYPT Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_RSA_DECRYPT
typedef|;
end_typedef

begin_comment
comment|// Table 157 - TPMT_RSA_DECRYPT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_RSA_DECRYPT
name|scheme
decl_stmt|;
name|TPMU_ASYM_SCHEME
name|details
decl_stmt|;
block|}
name|TPMT_RSA_DECRYPT
typedef|;
end_typedef

begin_comment
comment|// Table 158 - TPM2B_PUBLIC_KEY_RSA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_RSA_KEY_BYTES
index|]
decl_stmt|;
block|}
name|TPM2B_PUBLIC_KEY_RSA
typedef|;
end_typedef

begin_comment
comment|// Table 159 - TPMI_RSA_KEY_BITS Type
end_comment

begin_typedef
typedef|typedef
name|TPM_KEY_BITS
name|TPMI_RSA_KEY_BITS
typedef|;
end_typedef

begin_comment
comment|// Table 160 - TPM2B_PRIVATE_KEY_RSA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_RSA_KEY_BYTES
operator|/
literal|2
index|]
decl_stmt|;
block|}
name|TPM2B_PRIVATE_KEY_RSA
typedef|;
end_typedef

begin_comment
comment|// Table 161 - TPM2B_ECC_PARAMETER Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_ECC_KEY_BYTES
index|]
decl_stmt|;
block|}
name|TPM2B_ECC_PARAMETER
typedef|;
end_typedef

begin_comment
comment|// Table 162 - TPMS_ECC_POINT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_ECC_PARAMETER
name|x
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|y
decl_stmt|;
block|}
name|TPMS_ECC_POINT
typedef|;
end_typedef

begin_comment
comment|// Table 163 -- TPM2B_ECC_POINT Structure<I/O>
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|TPMS_ECC_POINT
name|point
decl_stmt|;
block|}
name|TPM2B_ECC_POINT
typedef|;
end_typedef

begin_comment
comment|// Table 164 - TPMI_ALG_ECC_SCHEME Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_ECC_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 165 - TPMI_ECC_CURVE Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ECC_CURVE
name|TPMI_ECC_CURVE
typedef|;
end_typedef

begin_comment
comment|// Table 166 - TPMT_ECC_SCHEME Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_ECC_SCHEME
name|scheme
decl_stmt|;
name|TPMU_SIG_SCHEME
name|details
decl_stmt|;
block|}
name|TPMT_ECC_SCHEME
typedef|;
end_typedef

begin_comment
comment|// Table 167 - TPMS_ALGORITHM_DETAIL_ECC Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ECC_CURVE
name|curveID
decl_stmt|;
name|UINT16
name|keySize
decl_stmt|;
name|TPMT_KDF_SCHEME
name|kdf
decl_stmt|;
name|TPMT_ECC_SCHEME
name|sign
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|p
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|a
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|b
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|gX
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|gY
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|n
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|h
decl_stmt|;
block|}
name|TPMS_ALGORITHM_DETAIL_ECC
typedef|;
end_typedef

begin_comment
comment|// Table 168 - TPMS_SIGNATURE_RSASSA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hash
decl_stmt|;
name|TPM2B_PUBLIC_KEY_RSA
name|sig
decl_stmt|;
block|}
name|TPMS_SIGNATURE_RSASSA
typedef|;
end_typedef

begin_comment
comment|// Table 169 - TPMS_SIGNATURE_RSAPSS Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hash
decl_stmt|;
name|TPM2B_PUBLIC_KEY_RSA
name|sig
decl_stmt|;
block|}
name|TPMS_SIGNATURE_RSAPSS
typedef|;
end_typedef

begin_comment
comment|// Table 170 - TPMS_SIGNATURE_ECDSA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_HASH
name|hash
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|signatureR
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|signatureS
decl_stmt|;
block|}
name|TPMS_SIGNATURE_ECDSA
typedef|;
end_typedef

begin_comment
comment|// Table 171 - TPMU_SIGNATURE Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMS_SIGNATURE_RSASSA
name|rsassa
decl_stmt|;
name|TPMS_SIGNATURE_RSAPSS
name|rsapss
decl_stmt|;
name|TPMS_SIGNATURE_ECDSA
name|ecdsa
decl_stmt|;
name|TPMS_SIGNATURE_ECDSA
name|sm2
decl_stmt|;
name|TPMS_SIGNATURE_ECDSA
name|ecdaa
decl_stmt|;
name|TPMS_SIGNATURE_ECDSA
name|ecschnorr
decl_stmt|;
name|TPMT_HA
name|hmac
decl_stmt|;
name|TPMS_SCHEME_SIGHASH
name|any
decl_stmt|;
block|}
name|TPMU_SIGNATURE
typedef|;
end_typedef

begin_comment
comment|// Table 172 - TPMT_SIGNATURE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_SIG_SCHEME
name|sigAlg
decl_stmt|;
name|TPMU_SIGNATURE
name|signature
decl_stmt|;
block|}
name|TPMT_SIGNATURE
typedef|;
end_typedef

begin_comment
comment|// Table 173 - TPMU_ENCRYPTED_SECRET Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|BYTE
name|ecc
index|[
sizeof|sizeof
argument_list|(
name|TPMS_ECC_POINT
argument_list|)
index|]
decl_stmt|;
name|BYTE
name|rsa
index|[
name|MAX_RSA_KEY_BYTES
index|]
decl_stmt|;
name|BYTE
name|symmetric
index|[
sizeof|sizeof
argument_list|(
name|TPM2B_DIGEST
argument_list|)
index|]
decl_stmt|;
name|BYTE
name|keyedHash
index|[
sizeof|sizeof
argument_list|(
name|TPM2B_DIGEST
argument_list|)
index|]
decl_stmt|;
block|}
name|TPMU_ENCRYPTED_SECRET
typedef|;
end_typedef

begin_comment
comment|// Table 174 - TPM2B_ENCRYPTED_SECRET Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|secret
index|[
sizeof|sizeof
argument_list|(
name|TPMU_ENCRYPTED_SECRET
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_ENCRYPTED_SECRET
typedef|;
end_typedef

begin_comment
comment|// 12 Key/Object Complex
end_comment

begin_comment
comment|// Table 175 - TPMI_ALG_PUBLIC Type
end_comment

begin_typedef
typedef|typedef
name|TPM_ALG_ID
name|TPMI_ALG_PUBLIC
typedef|;
end_typedef

begin_comment
comment|// Table 176 - TPMU_PUBLIC_ID Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPM2B_DIGEST
name|keyedHash
decl_stmt|;
name|TPM2B_DIGEST
name|sym
decl_stmt|;
name|TPM2B_PUBLIC_KEY_RSA
name|rsa
decl_stmt|;
name|TPMS_ECC_POINT
name|ecc
decl_stmt|;
block|}
name|TPMU_PUBLIC_ID
typedef|;
end_typedef

begin_comment
comment|// Table 177 - TPMS_KEYEDHASH_PARMS Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMT_KEYEDHASH_SCHEME
name|scheme
decl_stmt|;
block|}
name|TPMS_KEYEDHASH_PARMS
typedef|;
end_typedef

begin_comment
comment|// Table 178 - TPMS_ASYM_PARMS Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMT_SYM_DEF_OBJECT
name|symmetric
decl_stmt|;
name|TPMT_ASYM_SCHEME
name|scheme
decl_stmt|;
block|}
name|TPMS_ASYM_PARMS
typedef|;
end_typedef

begin_comment
comment|// Table 179 - TPMS_RSA_PARMS Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMT_SYM_DEF_OBJECT
name|symmetric
decl_stmt|;
name|TPMT_RSA_SCHEME
name|scheme
decl_stmt|;
name|TPMI_RSA_KEY_BITS
name|keyBits
decl_stmt|;
name|UINT32
name|exponent
decl_stmt|;
block|}
name|TPMS_RSA_PARMS
typedef|;
end_typedef

begin_comment
comment|// Table 180 - TPMS_ECC_PARMS Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMT_SYM_DEF_OBJECT
name|symmetric
decl_stmt|;
name|TPMT_ECC_SCHEME
name|scheme
decl_stmt|;
name|TPMI_ECC_CURVE
name|curveID
decl_stmt|;
name|TPMT_KDF_SCHEME
name|kdf
decl_stmt|;
block|}
name|TPMS_ECC_PARMS
typedef|;
end_typedef

begin_comment
comment|// Table 181 - TPMU_PUBLIC_PARMS Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPMS_KEYEDHASH_PARMS
name|keyedHashDetail
decl_stmt|;
name|TPMT_SYM_DEF_OBJECT
name|symDetail
decl_stmt|;
name|TPMS_RSA_PARMS
name|rsaDetail
decl_stmt|;
name|TPMS_ECC_PARMS
name|eccDetail
decl_stmt|;
name|TPMS_ASYM_PARMS
name|asymDetail
decl_stmt|;
block|}
name|TPMU_PUBLIC_PARMS
typedef|;
end_typedef

begin_comment
comment|// Table 182 - TPMT_PUBLIC_PARMS Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_PUBLIC
name|type
decl_stmt|;
name|TPMU_PUBLIC_PARMS
name|parameters
decl_stmt|;
block|}
name|TPMT_PUBLIC_PARMS
typedef|;
end_typedef

begin_comment
comment|// Table 183 - TPMT_PUBLIC Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_PUBLIC
name|type
decl_stmt|;
name|TPMI_ALG_HASH
name|nameAlg
decl_stmt|;
name|TPMA_OBJECT
name|objectAttributes
decl_stmt|;
name|TPM2B_DIGEST
name|authPolicy
decl_stmt|;
name|TPMU_PUBLIC_PARMS
name|parameters
decl_stmt|;
name|TPMU_PUBLIC_ID
name|unique
decl_stmt|;
block|}
name|TPMT_PUBLIC
typedef|;
end_typedef

begin_comment
comment|// Table 184 - TPM2B_PUBLIC Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|TPMT_PUBLIC
name|publicArea
decl_stmt|;
block|}
name|TPM2B_PUBLIC
typedef|;
end_typedef

begin_comment
comment|// Table 185 - TPM2B_PRIVATE_VENDOR_SPECIFIC Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|PRIVATE_VENDOR_SPECIFIC_BYTES
index|]
decl_stmt|;
block|}
name|TPM2B_PRIVATE_VENDOR_SPECIFIC
typedef|;
end_typedef

begin_comment
comment|// Table 186 - TPMU_SENSITIVE_COMPOSITE Union
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TPM2B_PRIVATE_KEY_RSA
name|rsa
decl_stmt|;
name|TPM2B_ECC_PARAMETER
name|ecc
decl_stmt|;
name|TPM2B_SENSITIVE_DATA
name|bits
decl_stmt|;
name|TPM2B_SYM_KEY
name|sym
decl_stmt|;
name|TPM2B_PRIVATE_VENDOR_SPECIFIC
name|any
decl_stmt|;
block|}
name|TPMU_SENSITIVE_COMPOSITE
typedef|;
end_typedef

begin_comment
comment|// Table 187 - TPMT_SENSITIVE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_ALG_PUBLIC
name|sensitiveType
decl_stmt|;
name|TPM2B_AUTH
name|authValue
decl_stmt|;
name|TPM2B_DIGEST
name|seedValue
decl_stmt|;
name|TPMU_SENSITIVE_COMPOSITE
name|sensitive
decl_stmt|;
block|}
name|TPMT_SENSITIVE
typedef|;
end_typedef

begin_comment
comment|// Table 188 - TPM2B_SENSITIVE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|TPMT_SENSITIVE
name|sensitiveArea
decl_stmt|;
block|}
name|TPM2B_SENSITIVE
typedef|;
end_typedef

begin_comment
comment|// Table 189 - _PRIVATE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_DIGEST
name|integrityOuter
decl_stmt|;
name|TPM2B_DIGEST
name|integrityInner
decl_stmt|;
name|TPMT_SENSITIVE
name|sensitive
decl_stmt|;
block|}
name|_PRIVATE
typedef|;
end_typedef

begin_comment
comment|// Table 190 - TPM2B_PRIVATE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
sizeof|sizeof
argument_list|(
name|_PRIVATE
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_PRIVATE
typedef|;
end_typedef

begin_comment
comment|// Table 191 - _ID_OBJECT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_DIGEST
name|integrityHMAC
decl_stmt|;
name|TPM2B_DIGEST
name|encIdentity
decl_stmt|;
block|}
name|_ID_OBJECT
typedef|;
end_typedef

begin_comment
comment|// Table 192 - TPM2B_ID_OBJECT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|credential
index|[
sizeof|sizeof
argument_list|(
name|_ID_OBJECT
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_ID_OBJECT
typedef|;
end_typedef

begin_comment
comment|// 13 NV Storage Structures
end_comment

begin_comment
comment|// Table 193 - TPM_NV_INDEX Bits
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: Comment here to resolve conflict
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//typedef struct {
end_comment

begin_comment
comment|//  UINT32 index : 22;
end_comment

begin_comment
comment|//  UINT32 space : 2;
end_comment

begin_comment
comment|//  UINT32 RH_NV : 8;
end_comment

begin_comment
comment|//} TPM_NV_INDEX;
end_comment

begin_comment
comment|// Table 195 - TPMA_NV Bits
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|TPMA_NV_PPWRITE
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_OWNERWRITE
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_AUTHWRITE
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_POLICYWRITE
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_COUNTER
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_BITS
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_EXTEND
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved7_9
range|:
literal|3
decl_stmt|;
name|UINT32
name|TPMA_NV_POLICY_DELETE
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_WRITELOCKED
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_WRITEALL
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_WRITEDEFINE
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_WRITE_STCLEAR
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_GLOBALLOCK
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_PPREAD
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_OWNERREAD
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_AUTHREAD
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_POLICYREAD
range|:
literal|1
decl_stmt|;
name|UINT32
name|reserved20_24
range|:
literal|5
decl_stmt|;
name|UINT32
name|TPMA_NV_NO_DA
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_ORDERLY
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_CLEAR_STCLEAR
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_READLOCKED
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_WRITTEN
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_PLATFORMCREATE
range|:
literal|1
decl_stmt|;
name|UINT32
name|TPMA_NV_READ_STCLEAR
range|:
literal|1
decl_stmt|;
block|}
name|TPMA_NV
typedef|;
end_typedef

begin_comment
comment|// Table 196 - TPMS_NV_PUBLIC Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPMI_RH_NV_INDEX
name|nvIndex
decl_stmt|;
name|TPMI_ALG_HASH
name|nameAlg
decl_stmt|;
name|TPMA_NV
name|attributes
decl_stmt|;
name|TPM2B_DIGEST
name|authPolicy
decl_stmt|;
name|UINT16
name|dataSize
decl_stmt|;
block|}
name|TPMS_NV_PUBLIC
typedef|;
end_typedef

begin_comment
comment|// Table 197 - TPM2B_NV_PUBLIC Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|TPMS_NV_PUBLIC
name|nvPublic
decl_stmt|;
block|}
name|TPM2B_NV_PUBLIC
typedef|;
end_typedef

begin_comment
comment|// 14 Context Data
end_comment

begin_comment
comment|// Table 198 - TPM2B_CONTEXT_SENSITIVE Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
name|MAX_CONTEXT_SIZE
index|]
decl_stmt|;
block|}
name|TPM2B_CONTEXT_SENSITIVE
typedef|;
end_typedef

begin_comment
comment|// Table 199 - TPMS_CONTEXT_DATA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM2B_DIGEST
name|integrity
decl_stmt|;
name|TPM2B_CONTEXT_SENSITIVE
name|encrypted
decl_stmt|;
block|}
name|TPMS_CONTEXT_DATA
typedef|;
end_typedef

begin_comment
comment|// Table 200 - TPM2B_CONTEXT_DATA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|BYTE
name|buffer
index|[
sizeof|sizeof
argument_list|(
name|TPMS_CONTEXT_DATA
argument_list|)
index|]
decl_stmt|;
block|}
name|TPM2B_CONTEXT_DATA
typedef|;
end_typedef

begin_comment
comment|// Table 201 - TPMS_CONTEXT Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|sequence
decl_stmt|;
name|TPMI_DH_CONTEXT
name|savedHandle
decl_stmt|;
name|TPMI_RH_HIERARCHY
name|hierarchy
decl_stmt|;
name|TPM2B_CONTEXT_DATA
name|contextBlob
decl_stmt|;
block|}
name|TPMS_CONTEXT
typedef|;
end_typedef

begin_comment
comment|// 15 Creation Data
end_comment

begin_comment
comment|// Table 203 - TPMS_CREATION_DATA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPML_PCR_SELECTION
name|pcrSelect
decl_stmt|;
name|TPM2B_DIGEST
name|pcrDigest
decl_stmt|;
name|TPMA_LOCALITY
name|locality
decl_stmt|;
name|TPM_ALG_ID
name|parentNameAlg
decl_stmt|;
name|TPM2B_NAME
name|parentName
decl_stmt|;
name|TPM2B_NAME
name|parentQualifiedName
decl_stmt|;
name|TPM2B_DATA
name|outsideInfo
decl_stmt|;
block|}
name|TPMS_CREATION_DATA
typedef|;
end_typedef

begin_comment
comment|// Table 204 - TPM2B_CREATION_DATA Structure
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|size
decl_stmt|;
name|TPMS_CREATION_DATA
name|creationData
decl_stmt|;
block|}
name|TPM2B_CREATION_DATA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Command Header
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ST
name|tag
decl_stmt|;
name|UINT32
name|paramSize
decl_stmt|;
name|TPM_CC
name|commandCode
decl_stmt|;
block|}
name|TPM2_COMMAND_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|TPM_ST
name|tag
decl_stmt|;
name|UINT32
name|paramSize
decl_stmt|;
name|TPM_RC
name|responseCode
decl_stmt|;
block|}
name|TPM2_RESPONSE_HEADER
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG Algorithm Registry
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HASH_ALG_SHA1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HASH_ALG_SHA256
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HASH_ALG_SHA384
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HASH_ALG_SHA512
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HASH_ALG_SM3_256
value|0x00000010
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

