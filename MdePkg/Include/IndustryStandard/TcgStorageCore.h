begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   TCG defined values and structures.  Copyright (c) 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCG_STORAGE_CORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_TCG_STORAGE_CORE_H_
end_define

begin_include
include|#
directive|include
file|<Base.h>
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
comment|/// UID in host native byte order
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|TCG_UID
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCG_TO_UID
parameter_list|(
name|b0
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|,
name|b3
parameter_list|,
name|b4
parameter_list|,
name|b5
parameter_list|,
name|b6
parameter_list|,
name|b7
parameter_list|)
value|(TCG_UID)( \   (UINT64)(b0)         | \   ((UINT64)(b1)<< 8)  | \   ((UINT64)(b2)<< 16) | \   ((UINT64)(b3)<< 24) | \   ((UINT64)(b4)<< 32) | \   ((UINT64)(b5)<< 40) | \   ((UINT64)(b6)<< 48) | \   ((UINT64)(b7)<< 56))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ReservedBE
decl_stmt|;
name|UINT16
name|ComIDBE
decl_stmt|;
name|UINT16
name|ComIDExtensionBE
decl_stmt|;
name|UINT32
name|OutstandingDataBE
decl_stmt|;
name|UINT32
name|MinTransferBE
decl_stmt|;
name|UINT32
name|LengthBE
decl_stmt|;
name|UINT8
name|Payload
index|[
literal|0
index|]
decl_stmt|;
block|}
name|TCG_COM_PACKET
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|TperSessionNumberBE
decl_stmt|;
name|UINT32
name|HostSessionNumberBE
decl_stmt|;
name|UINT32
name|SequenceNumberBE
decl_stmt|;
name|UINT16
name|ReservedBE
decl_stmt|;
name|UINT16
name|AckTypeBE
decl_stmt|;
name|UINT32
name|AcknowledgementBE
decl_stmt|;
name|UINT32
name|LengthBE
decl_stmt|;
name|UINT8
name|Payload
index|[
literal|0
index|]
decl_stmt|;
block|}
name|TCG_PACKET
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCG_SUBPACKET_ALIGNMENT
value|4
end_define

begin_comment
comment|// 4-byte alignment per spec
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ReservedBE
index|[
literal|6
index|]
decl_stmt|;
name|UINT16
name|KindBE
decl_stmt|;
name|UINT32
name|LengthBE
decl_stmt|;
name|UINT8
name|Payload
index|[
literal|0
index|]
decl_stmt|;
block|}
name|TCG_SUB_PACKET
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SUBPACKET_KIND_DATA
value|0x0000
end_define

begin_define
define|#
directive|define
name|SUBPACKET_KIND_CREDIT_CONTROL
value|0x8001
end_define

begin_define
define|#
directive|define
name|TCG_ATOM_TYPE_INTEGER
value|0x0
end_define

begin_define
define|#
directive|define
name|TCG_ATOM_TYPE_BYTE
value|0x1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Data
range|:
literal|6
decl_stmt|;
name|UINT8
name|Sign
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsZero
range|:
literal|1
decl_stmt|;
block|}
name|TCG_TINY_ATOM_BITS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT8
name|Raw
decl_stmt|;
name|TCG_TINY_ATOM_BITS
name|TinyAtomBits
decl_stmt|;
block|}
name|TCG_SIMPLE_TOKEN_TINY_ATOM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Length
range|:
literal|4
decl_stmt|;
name|UINT8
name|SignOrCont
range|:
literal|1
decl_stmt|;
name|UINT8
name|ByteOrInt
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsZero
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsOne
range|:
literal|1
decl_stmt|;
block|}
name|TCG_SHORT_ATOM_BITS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT8
name|RawHeader
decl_stmt|;
name|TCG_SHORT_ATOM_BITS
name|ShortAtomBits
decl_stmt|;
block|}
name|TCG_SIMPLE_TOKEN_SHORT_ATOM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCG_MEDIUM_ATOM_LENGTH_HIGH_SHIFT
value|0x8
end_define

begin_define
define|#
directive|define
name|TCG_MEDIUM_ATOM_LENGTH_HIGH_MASK
value|0x7
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|LengthHigh
range|:
literal|3
decl_stmt|;
name|UINT8
name|SignOrCont
range|:
literal|1
decl_stmt|;
name|UINT8
name|ByteOrInt
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsZero
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsOne1
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsOne2
range|:
literal|1
decl_stmt|;
name|UINT8
name|LengthLow
decl_stmt|;
block|}
name|TCG_MEDIUM_ATOM_BITS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT16
name|RawHeader
decl_stmt|;
name|TCG_MEDIUM_ATOM_BITS
name|MediumAtomBits
decl_stmt|;
block|}
name|TCG_SIMPLE_TOKEN_MEDIUM_ATOM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCG_LONG_ATOM_LENGTH_HIGH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TCG_LONG_ATOM_LENGTH_MID_SHIFT
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|SignOrCont
range|:
literal|1
decl_stmt|;
name|UINT8
name|ByteOrInt
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|2
decl_stmt|;
name|UINT8
name|IsZero
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsOne1
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsOne2
range|:
literal|1
decl_stmt|;
name|UINT8
name|IsOne3
range|:
literal|1
decl_stmt|;
name|UINT8
name|LengthHigh
decl_stmt|;
name|UINT8
name|LengthMid
decl_stmt|;
name|UINT8
name|LengthLow
decl_stmt|;
block|}
name|TCG_LONG_ATOM_BITS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT32
name|RawHeader
decl_stmt|;
name|TCG_LONG_ATOM_BITS
name|LongAtomBits
decl_stmt|;
block|}
name|TCG_SIMPLE_TOKEN_LONG_ATOM
typedef|;
end_typedef

begin_comment
comment|// TCG Core Spec v2 - Table 04 - Token Types
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TcgTokenTypeReserved
block|,
name|TcgTokenTypeTinyAtom
block|,
name|TcgTokenTypeShortAtom
block|,
name|TcgTokenTypeMediumAtom
block|,
name|TcgTokenTypeLongAtom
block|,
name|TcgTokenTypeStartList
block|,
name|TcgTokenTypeEndList
block|,
name|TcgTokenTypeStartName
block|,
name|TcgTokenTypeEndName
block|,
name|TcgTokenTypeCall
block|,
name|TcgTokenTypeEndOfData
block|,
name|TcgTokenTypeEndOfSession
block|,
name|TcgTokenTypeStartTransaction
block|,
name|TcgTokenTypeEndTransaction
block|,
name|TcgTokenTypeEmptyAtom
block|, }
name|TCG_TOKEN_TYPE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|TCG_TOKEN_SHORTATOM_MAX_BYTE_SIZE
value|0x0F
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_MEDIUMATOM_MAX_BYTE_SIZE
value|0x7FF
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_LONGATOM_MAX_BYTE_SIZE
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_TINYATOM_UNSIGNED_MAX_VALUE
value|0x3F
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_TINYATOM_SIGNED_MAX_VALUE
value|0x1F
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_TINYATOM_SIGNED_MIN_VALUE
value|-32
end_define

begin_comment
comment|// TOKEN TYPES
end_comment

begin_define
define|#
directive|define
name|TCG_TOKEN_TINYATOM
value|0x00
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_TINYSIGNEDATOM
value|0x40
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_SHORTATOM
value|0x80
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_SHORTSIGNEDATOM
value|0x90
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_SHORTBYTESATOM
value|0xA0
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_MEDIUMATOM
value|0xC0
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_MEDIUMSIGNEDATOM
value|0xC8
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_MEDIUMBYTESATOM
value|0xD0
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_LONGATOM
value|0xE0
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_LONGSIGNEDATOM
value|0xE1
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_LONGBYTESATOM
value|0xE2
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_STARTLIST
value|0xF0
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_ENDLIST
value|0xF1
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_STARTNAME
value|0xF2
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_ENDNAME
value|0xF3
end_define

begin_comment
comment|// 0xF4 - 0xF7 TCG Reserved
end_comment

begin_define
define|#
directive|define
name|TCG_TOKEN_CALL
value|0xF8
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_ENDDATA
value|0xF9
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_ENDSESSION
value|0xFA
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_STARTTRANSACTION
value|0xFB
end_define

begin_define
define|#
directive|define
name|TCG_TOKEN_ENDTRANSACTION
value|0xFC
end_define

begin_comment
comment|// 0xFD - 0xFE TCG Reserved
end_comment

begin_define
define|#
directive|define
name|TCG_TOKEN_EMPTY
value|0xFF
end_define

begin_comment
comment|// CELLBLOCK reserved Names
end_comment

begin_define
define|#
directive|define
name|TCG_CELL_BLOCK_TABLE_NAME
value|(UINT8)0x00
end_define

begin_define
define|#
directive|define
name|TCG_CELL_BLOCK_START_ROW_NAME
value|(UINT8)0x01
end_define

begin_define
define|#
directive|define
name|TCG_CELL_BLOCK_END_ROW_NAME
value|(UINT8)0x02
end_define

begin_define
define|#
directive|define
name|TCG_CELL_BLOCK_START_COLUMN_NAME
value|(UINT8)0x03
end_define

begin_define
define|#
directive|define
name|TCG_CELL_BLOCK_END_COLUMN_NAME
value|(UINT8)0x04
end_define

begin_comment
comment|// METHOD STATUS CODES
end_comment

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_NOT_AUTHORIZED
value|0x01
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_OBSOLETE
value|0x02
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_SP_BUSY
value|0x03
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_SP_FAILED
value|0x04
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_SP_DISABLED
value|0x05
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_SP_FROZEN
value|0x06
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_NO_SESSIONS_AVAILABLE
value|0x07
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_UNIQUENESS_CONFLICT
value|0x08
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_INSUFFICIENT_SPACE
value|0x09
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_INSUFFICIENT_ROWS
value|0x0A
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_INVALID_PARAMETER
value|0x0C
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_OBSOLETE2
value|0x0D
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_OBSOLETE3
value|0x0E
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_TPER_MALFUNCTION
value|0x0F
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_TRANSACTION_FAILURE
value|0x10
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_RESPONSE_OVERFLOW
value|0x11
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_AUTHORITY_LOCKED_OUT
value|0x12
end_define

begin_define
define|#
directive|define
name|TCG_METHOD_STATUS_CODE_FAIL
value|0x3F
end_define

begin_comment
comment|// Feature Codes
end_comment

begin_define
define|#
directive|define
name|TCG_FEATURE_INVALID
value|(UINT16)0x0000
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_TPER
value|(UINT16)0x0001
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_LOCKING
value|(UINT16)0x0002
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_GEOMETRY_REPORTING
value|(UINT16)0x0003
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_SINGLE_USER_MODE
value|(UINT16)0x0201
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_DATASTORE_TABLE
value|(UINT16)0x0202
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_OPAL_SSC_V1_0_0
value|(UINT16)0x0200
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_OPAL_SSC_V2_0_0
value|(UINT16)0x0203
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_OPAL_SSC_LITE
value|(UINT16)0x0301
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_PYRITE_SSC
value|(UINT16)0x0302
end_define

begin_define
define|#
directive|define
name|TCG_FEATURE_BLOCK_SID
value|(UINT16)0x0402
end_define

begin_comment
comment|// ACE Expression values
end_comment

begin_define
define|#
directive|define
name|TCG_ACE_EXPRESSION_AND
value|0x0
end_define

begin_define
define|#
directive|define
name|TCG_ACE_EXPRESSION_OR
value|0x1
end_define

begin_comment
comment|/**************************************************************************** TRUSTED RECEIVE - supported security protocols list (SP_Specific = 0000h) ATA 8 Rev6a Table 68 7.57.6.2 ****************************************************************************/
end_comment

begin_comment
comment|// Security Protocol IDs
end_comment

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_INFO
value|0x00
end_define

begin_define
define|#
directive|define
name|TCG_OPAL_SECURITY_PROTOCOL_1
value|0x01
end_define

begin_define
define|#
directive|define
name|TCG_OPAL_SECURITY_PROTOCOL_2
value|0x02
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_TCG3
value|0x03
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_TCG4
value|0x04
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_TCG5
value|0x05
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_TCG6
value|0x06
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_CBCS
value|0x07
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_TAPE_DATA
value|0x20
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_DATA_ENCRYPT_CONFIG
value|0x21
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_SA_CREATION_CAPS
value|0x40
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_IKEV2_SCSI
value|0x41
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_JEDEC_UFS
value|0xEC
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_SDCARD_SECURITY
value|0xED
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_IEEE_1667
value|0xEE
end_define

begin_define
define|#
directive|define
name|TCG_SECURITY_PROTOCOL_ATA_DEVICE_SERVER_PASS
value|0xEF
end_define

begin_comment
comment|// Security Protocol Specific IDs
end_comment

begin_define
define|#
directive|define
name|TCG_SP_SPECIFIC_PROTOCOL_LIST
value|0x0000
end_define

begin_define
define|#
directive|define
name|TCG_SP_SPECIFIC_PROTOCOL_LEVEL0_DISCOVERY
value|0x0001
end_define

begin_define
define|#
directive|define
name|TCG_RESERVED_COMID
value|0x0000
end_define

begin_comment
comment|// Defined in TCG Storage Feature Set:Block SID Authentication spec,
end_comment

begin_comment
comment|// ComId used for BlockSid command is hardcode 0x0005.
end_comment

begin_define
define|#
directive|define
name|TCG_BLOCKSID_COMID
value|0x0005
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
block|{
name|UINT8
name|Reserved
index|[
literal|6
index|]
decl_stmt|;
name|UINT16
name|ListLength_BE
decl_stmt|;
comment|// 6 - 7
name|UINT8
name|List
index|[
literal|504
index|]
decl_stmt|;
comment|// 8...
block|}
name|TCG_SUPPORTED_SECURITY_PROTOCOLS
typedef|;
end_typedef

begin_comment
comment|// Level 0 Discovery
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|LengthBE
decl_stmt|;
comment|// number of valid bytes in discovery response, not including length field
name|UINT16
name|VerMajorBE
decl_stmt|;
name|UINT16
name|VerMinorBE
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|8
index|]
decl_stmt|;
name|UINT8
name|VendorUnique
index|[
literal|32
index|]
decl_stmt|;
block|}
name|TCG_LEVEL0_DISCOVERY_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
block|{
name|UINT16
name|FeatureCode_BE
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
name|UINT8
name|Version
range|:
literal|4
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
comment|// length of feature dependent data in bytes
block|}
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT8
name|LockingSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|LockingEnabled
range|:
literal|1
decl_stmt|;
comment|// means the locking security provider (SP) is enabled
name|UINT8
name|Locked
range|:
literal|1
decl_stmt|;
comment|// means at least 1 locking range is enabled
name|UINT8
name|MediaEncryption
range|:
literal|1
decl_stmt|;
name|UINT8
name|MbrEnabled
range|:
literal|1
decl_stmt|;
name|UINT8
name|MbrDone
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|2
decl_stmt|;
name|UINT8
name|Reserved515
index|[
literal|11
index|]
decl_stmt|;
block|}
name|TCG_LOCKING_FEATURE_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT8
name|SIDValueState
range|:
literal|1
decl_stmt|;
name|UINT8
name|SIDBlockedState
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved4
range|:
literal|6
decl_stmt|;
name|UINT8
name|HardwareReset
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved5
range|:
literal|7
decl_stmt|;
name|UINT8
name|Reserved615
index|[
literal|10
index|]
decl_stmt|;
block|}
name|TCG_BLOCK_SID_FEATURE_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|TCG_LEVEL0_FEATURE_DESCRIPTOR_HEADER
name|Header
decl_stmt|;
name|UINT8
name|SyncSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|AsyncSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|AckNakSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|BufferMgmtSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|StreamingSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved4b5
range|:
literal|1
decl_stmt|;
name|UINT8
name|ComIdMgmtSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved4b7
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved515
index|[
literal|11
index|]
decl_stmt|;
block|}
name|TCG_TPER_FEATURE_DESCRIPTOR
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
comment|// Special Purpose UIDs
end_comment

begin_define
define|#
directive|define
name|TCG_UID_NULL
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00)
end_define

begin_define
define|#
directive|define
name|TCG_UID_THIS_SP
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)
end_define

begin_define
define|#
directive|define
name|TCG_UID_SMUID
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF)
end_define

begin_comment
comment|// Session Manager Method UIDS
end_comment

begin_define
define|#
directive|define
name|TCG_UID_SM_PROPERTIES
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01)
end_define

begin_define
define|#
directive|define
name|TCG_UID_SM_START_SESSION
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x02)
end_define

begin_define
define|#
directive|define
name|TCG_UID_SM_SYNC_SESSION
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x03)
end_define

begin_define
define|#
directive|define
name|TCG_UID_SM_START_TRUSTED_SESSION
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x04)
end_define

begin_define
define|#
directive|define
name|TCG_UID_SM_SYNC_TRUSTED_SESSION
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x05)
end_define

begin_define
define|#
directive|define
name|TCG_UID_SM_CLOSE_SESSION
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x06)
end_define

begin_comment
comment|// MethodID UIDs
end_comment

begin_define
define|#
directive|define
name|TCG_UID_METHOD_DELETE_SP
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_CREATE_TABLE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_DELETE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x03)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_CREATE_ROW
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_DELETE_ROW
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x05)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_NEXT
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x08)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_GET_FREE_SPACE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x09)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_GET_FREE_ROWS
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0A)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_DELETE_METHOD
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0B)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_GET_ACL
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0D)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_ADD_ACE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0E)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_REMOVE_ACE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0F)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_GEN_KEY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x10)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_GET_PACKAGE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x12)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_SET_PACKAGE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x13)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_GET
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x16)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_SET
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x17)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_AUTHENTICATE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x1C)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_ISSUE_SP
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x02, 0x01)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_GET_CLOCK
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x01)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_RESET_CLOCK
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x02)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_SET_CLOCK_HIGH
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x03)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_SET_LAG_HIGH
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x04)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_SET_CLOCK_LOW
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x05)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_SET_LAG_LOW
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x06)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_INCREMENT_COUNTER
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x07)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_RANDOM
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x01)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_SALT
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x02)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_DECRYPT_INIT
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x03)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_DECRYPT
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x04)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_DECRYPT_FINALIZE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x05)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_ENCRYPT_INIT
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x06)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_ENCRYPT
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x07)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_ENCRYPT_FINALIZE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x08)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_HMAC_INIT
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x09)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_HMAC
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x0A)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_HMAC_FINALIZE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x0B)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_HASH_INIT
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x0C)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_HASH
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x0D)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_HASH_FINALIZE
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x0E)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_SIGN
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x0F)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_VERIFY
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x10)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_XOR
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x11)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_ADD_LOG
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x0A, 0x01)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_CREATE_LOG
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x0A, 0x02)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_CLEAR_LOG
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x0A, 0x03)
end_define

begin_define
define|#
directive|define
name|TCG_UID_METHOD_FLUSH_LOG
value|TCG_TO_UID(0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x0A, 0x04)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TCG_H_
end_comment

end_unit

