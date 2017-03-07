begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Opal Specification defined values and structures.  Copyright (c) 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCG_STORAGE_OPAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_TCG_STORAGE_OPAL_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/TcgStorageCore.h>
end_include

begin_define
define|#
directive|define
name|OPAL_UID_ADMIN_SP
value|TCG_TO_UID(0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x00, 0x01)
end_define

begin_define
define|#
directive|define
name|OPAL_UID_ADMIN_SP_C_PIN_MSID
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x84, 0x02)
end_define

begin_define
define|#
directive|define
name|OPAL_UID_ADMIN_SP_C_PIN_SID
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x01)
end_define

begin_define
define|#
directive|define
name|OPAL_UID_LOCKING_SP
value|TCG_TO_UID(0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x00, 0x02)
end_define

begin_comment
comment|// ADMIN_SP
end_comment

begin_comment
comment|// Authorities
end_comment

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_ANYBODY_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x01)
end_define

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_ADMINS_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x02)
end_define

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_MAKERS_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x03)
end_define

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_SID_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x06)
end_define

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_ADMIN1_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x02, 0x01)
end_define

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_PSID_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x01, 0xFF, 0x01)
end_define

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_ACTIVATE_METHOD
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x02, 0x03)
end_define

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_REVERT_METHOD
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x02, 0x02)
end_define

begin_comment
comment|// LOCKING SP
end_comment

begin_comment
comment|// Authorities
end_comment

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_ANYBODY_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x01)
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_ADMINS_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x02)
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_ADMIN1_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x01, 0x00, 0x01)
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_USERS_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x03, 0x00, 0x00)
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_USER1_AUTHORITY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x09, 0x00, 0x03, 0x00, 0x01)
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_REVERTSP_METHOD
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x11)
end_define

begin_comment
comment|// C_PIN Table Rows
end_comment

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_C_PIN_ADMIN1
value|TCG_TO_UID( 0x00, 0x00, 0x00, 0x0B, 0x00, 0x01, 0x00, 0x01 )
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_C_PIN_USER1
value|TCG_TO_UID( 0x00, 0x00, 0x00, 0x0B, 0x00, 0x03, 0x00, 0x01 )
end_define

begin_comment
comment|// Locking Table
end_comment

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_LOCKING_GLOBALRANGE
value|TCG_TO_UID( 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x00, 0x01 )
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_LOCKING_RANGE1
value|TCG_TO_UID( 0x00, 0x00, 0x08, 0x02, 0x00, 0x03, 0x00, 0x01 )
end_define

begin_comment
comment|// LOCKING SP ACE Table Preconfiguration
end_comment

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_ACE_LOCKING_GLOBALRANGE_GET_ALL
value|TCG_TO_UID( 0x00, 0x00, 0x00, 0x08, 0x00, 0x03, 0xD0, 0x00 )
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_ACE_LOCKING_GLOBALRANGE_SET_RDLOCKED
value|TCG_TO_UID( 0x00, 0x00, 0x00, 0x08, 0x00, 0x03, 0xE0, 0x00 )
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_ACE_LOCKING_GLOBALRANGE_SET_WRLOCKED
value|TCG_TO_UID( 0x00, 0x00, 0x00, 0x08, 0x00, 0x03, 0xE8, 0x00 )
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_ACE_K_AES_256_GLOBALRANGE_GENKEY
value|TCG_TO_UID( 0x00, 0x00, 0x00, 0x08, 0x00, 0x03, 0xB8, 0x00 )
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_ACE_K_AES_128_GLOBALRANGE_GENKEY
value|TCG_TO_UID( 0x00, 0x00, 0x00, 0x08, 0x00, 0x03, 0xB0, 0x00 )
end_define

begin_comment
comment|// LOCKING SP LockingInfo Table Preconfiguration
end_comment

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_LOCKING_INFO
value|TCG_TO_UID( 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x01 )
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_LOCKINGINFO_ALIGNMENTREQUIRED_COL
value|0x7
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_LOCKINGINFO_LOGICALBLOCKSIZE_COL
value|0x8
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_LOCKINGINFO_ALIGNMENTGRANULARITY_COL
value|0x9
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_LOCKINGINFO_LOWESTALIGNEDLBA_COL
value|0xA
end_define

begin_comment
comment|// K_AES_256 Table Preconfiguration
end_comment

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_K_AES_256_GLOBALRANGE_KEY
value|TCG_TO_UID( 0x00, 0x00, 0x08, 0x06, 0x00, 0x00, 0x00, 0x01 )
end_define

begin_comment
comment|// K_AES_128 Table Preconfiguration
end_comment

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_K_AES_128_GLOBALRANGE_KEY
value|TCG_TO_UID( 0x00, 0x00, 0x08, 0x05, 0x00, 0x00, 0x00, 0x01 )
end_define

begin_comment
comment|// Minimum Properties that an Opal Compliant SD Shall support
end_comment

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_COM_PACKET_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_REPONSE_COM_PACKET_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_PACKET_SIZE
value|2028
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_IND_TOKEN_SIZE
value|1992
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_PACKETS
value|1
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_SUBPACKETS
value|1
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_METHODS
value|1
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_SESSIONS
value|1
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_AUTHENTICATIONS
value|2
end_define

begin_define
define|#
directive|define
name|OPAL_MIN_MAX_TRANSACTION_LIMIT
value|1
end_define

begin_define
define|#
directive|define
name|OPAL_ADMIN_SP_PIN_COL
value|3
end_define

begin_define
define|#
directive|define
name|OPAL_LOCKING_SP_C_PIN_TRYLIMIT_COL
value|5
end_define

begin_define
define|#
directive|define
name|OPAL_RANDOM_METHOD_MAX_COUNT_SIZE
value|32
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|_OPAL_GEOMETRY_REPORTING_FEATURE
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|8
index|]
decl_stmt|;
name|UINT32
name|LogicalBlockSizeBE
decl_stmt|;
name|UINT64
name|AlignmentGranularityBE
decl_stmt|;
name|UINT64
name|LowestAlignedLBABE
decl_stmt|;
block|}
name|OPAL_GEOMETRY_REPORTING_FEATURE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_OPAL_SINGLE_USER_MODE_FEATURE
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT32
name|NumLockingObjectsSupportedBE
decl_stmt|;
name|UINT8
name|Any
range|:
literal|1
decl_stmt|;
name|UINT8
name|All
range|:
literal|1
decl_stmt|;
name|UINT8
name|Policy
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|5
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|7
index|]
decl_stmt|;
block|}
name|OPAL_SINGLE_USER_MODE_FEATURE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_OPAL_DATASTORE_TABLE_FEATURE
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT16
name|MaxNumTablesBE
decl_stmt|;
name|UINT32
name|MaxTotalSizeBE
decl_stmt|;
name|UINT32
name|SizeAlignmentBE
decl_stmt|;
block|}
name|OPAL_DATASTORE_TABLE_FEATURE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_OPAL_SSCV1_FEATURE_DESCRIPTOR
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT16
name|BaseComdIdBE
decl_stmt|;
name|UINT16
name|NumComIdsBE
decl_stmt|;
name|UINT8
name|RangeCrossing
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
name|UINT8
name|Future
index|[
literal|11
index|]
decl_stmt|;
block|}
name|OPAL_SSCV1_FEATURE_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_OPAL_SSCV2_FEATURE_DESCRIPTOR
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT16
name|BaseComdIdBE
decl_stmt|;
name|UINT16
name|NumComIdsBE
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|NumLockingSpAdminAuthoritiesSupportedBE
decl_stmt|;
name|UINT16
name|NumLockingSpUserAuthoritiesSupportedBE
decl_stmt|;
name|UINT8
name|InitialCPINSIDPIN
decl_stmt|;
name|UINT8
name|CPINSIDPINRevertBehavior
decl_stmt|;
name|UINT8
name|Future
index|[
literal|5
index|]
decl_stmt|;
block|}
name|OPAL_SSCV2_FEATURE_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_OPAL_SSCLITE_FEATURE_DESCRIPTOR
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT16
name|BaseComdIdBE
decl_stmt|;
name|UINT16
name|NumComIdsBE
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|5
index|]
decl_stmt|;
name|UINT8
name|InitialCPINSIDPIN
decl_stmt|;
name|UINT8
name|CPINSIDPINRevertBehavior
decl_stmt|;
name|UINT8
name|Future
index|[
literal|5
index|]
decl_stmt|;
block|}
name|OPAL_SSCLITE_FEATURE_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PYRITE_SSC_FEATURE_DESCRIPTOR
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT16
name|BaseComdIdBE
decl_stmt|;
name|UINT16
name|NumComIdsBE
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|5
index|]
decl_stmt|;
name|UINT8
name|InitialCPINSIDPIN
decl_stmt|;
name|UINT8
name|CPINSIDPINRevertBehavior
decl_stmt|;
name|UINT8
name|Future
index|[
literal|5
index|]
decl_stmt|;
block|}
name|PYRITE_SSC_FEATURE_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|CommonHeader
decl_stmt|;
name|TCG_TPER_FEATURE_DESCRIPTOR
name|Tper
decl_stmt|;
name|TCG_LOCKING_FEATURE_DESCRIPTOR
name|Locking
decl_stmt|;
name|OPAL_GEOMETRY_REPORTING_FEATURE
name|Geometry
decl_stmt|;
name|OPAL_SINGLE_USER_MODE_FEATURE
name|SingleUser
decl_stmt|;
name|OPAL_DATASTORE_TABLE_FEATURE
name|DataStore
decl_stmt|;
name|OPAL_SSCV1_FEATURE_DESCRIPTOR
name|OpalSscV1
decl_stmt|;
name|OPAL_SSCV2_FEATURE_DESCRIPTOR
name|OpalSscV2
decl_stmt|;
name|OPAL_SSCLITE_FEATURE_DESCRIPTOR
name|OpalSscLite
decl_stmt|;
name|PYRITE_SSC_FEATURE_DESCRIPTOR
name|PyriteSsc
decl_stmt|;
name|TCG_BLOCK_SID_FEATURE_DESCRIPTOR
name|BlockSid
decl_stmt|;
block|}
name|OPAL_LEVEL0_FEATURE_DESCRIPTOR
typedef|;
end_typedef

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

begin_comment
comment|// _OPAL_H_
end_comment

end_unit

