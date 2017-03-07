begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      TPM Specification data structures (TCG TPM Specification Version 1.2 Revision 103)   See http://trustedcomputinggroup.org for latest specification updates    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TPM12_H_
end_ifndef

begin_define
define|#
directive|define
name|_TPM12_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The start of TPM return codes
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_BASE
value|0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// All structures MUST be packed on a byte boundary.
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 2.2.3: Helper redefinitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates the conditions where it is required that authorization be presented
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|TPM_AUTH_DATA_USAGE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information as to what the payload is in an encrypted structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|TPM_PAYLOAD_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The version info breakdown
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|TPM_VERSION_BYTE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The state of the dictionary attack mitigation logic
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|TPM_DA_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The request or response authorization type
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_TAG
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The protocol in use
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_PROTOCOL_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates the start state
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_STARTUP_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The definition of the encryption scheme
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_ENC_SCHEME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The definition of the signature scheme
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_SIG_SCHEME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The definition of the migration scheme
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_MIGRATE_SCHEME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sets the state of the physical presence mechanism
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_PHYSICAL_PRESENCE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates the types of entity that are supported by the TPM
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_ENTITY_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates the permitted usage of the key
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_KEY_USAGE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type of asymmetric encrypted structure in use by the endorsement key
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_EK_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The tag for the structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_STRUCTURE_TAG
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The platform specific spec to which the information relates to
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|TPM_PLATFORM_SPECIFIC
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The command ordinal
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_COMMAND_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Identifies a TPM capability area
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_CAPABILITY_AREA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates information regarding a key
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_KEY_FLAGS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates the type of algorithm
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_ALGORITHM_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The locality modifier
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_MODIFIER_INDICATOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The actual number of a counter
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_ACTUAL_COUNT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Attributes that define what options are in use for a transport session
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_TRANSPORT_ATTRIBUTES
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Handle to an authorization session
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_AUTHHANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Index to a DIR register
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_DIRINDEX
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The area where a key is held assigned by the TPM
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_KEY_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Index to a PCR register
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_PCRINDEX
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The return code from a function
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_RESULT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The types of resources that a TPM may have using internal resources
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_RESOURCE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Allows for controlling of the key when loaded and how to handle TPM_Startup issues
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_KEY_CONTROL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The index into the NV storage area
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_NV_INDEX
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The family ID. Family IDs are automatically assigned a sequence number by the TPM.
end_comment

begin_comment
comment|/// A trusted process can set the FamilyID value in an individual row to NULL, which
end_comment

begin_comment
comment|/// invalidates that row. The family ID resets to NULL on each change of TPM Owner.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_FAMILY_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA value used as a label for the most recent verification of this family. Set to zero when not in use.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_FAMILY_VERIFICATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// How the TPM handles var
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_STARTUP_EFFECTS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The mode of a symmetric encryption
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_SYM_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The family flags
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_FAMILY_FLAGS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The index value for the delegate NV table
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_DELEGATE_INDEX
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The restrictions placed on delegation of CMK commands
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_CMK_DELEGATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The ID value of a monotonic counter
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_COUNT_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A command to execute
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_REDIT_COMMAND
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A transport session handle
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_TRANSHANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A generic handle could be key, transport etc
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// What operation is happening
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|TPM_FAMILY_OPERATION
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 2.2.4: Vendor specific
end_comment

begin_comment
comment|// The following defines allow for the quick specification of a
end_comment

begin_comment
comment|// vendor specific item.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_Vendor_Specific32
value|((UINT32) 0x00000400)
end_define

begin_define
define|#
directive|define
name|TPM_Vendor_Specific8
value|((UINT8) 0x80)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 3.1: TPM_STRUCTURE_TAG
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_TAG_CONTEXTBLOB
value|((TPM_STRUCTURE_TAG) 0x0001)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CONTEXT_SENSITIVE
value|((TPM_STRUCTURE_TAG) 0x0002)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CONTEXTPOINTER
value|((TPM_STRUCTURE_TAG) 0x0003)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CONTEXTLIST
value|((TPM_STRUCTURE_TAG) 0x0004)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_SIGNINFO
value|((TPM_STRUCTURE_TAG) 0x0005)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_PCR_INFO_LONG
value|((TPM_STRUCTURE_TAG) 0x0006)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_PERSISTENT_FLAGS
value|((TPM_STRUCTURE_TAG) 0x0007)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_VOLATILE_FLAGS
value|((TPM_STRUCTURE_TAG) 0x0008)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_PERSISTENT_DATA
value|((TPM_STRUCTURE_TAG) 0x0009)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_VOLATILE_DATA
value|((TPM_STRUCTURE_TAG) 0x000A)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_SV_DATA
value|((TPM_STRUCTURE_TAG) 0x000B)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_EK_BLOB
value|((TPM_STRUCTURE_TAG) 0x000C)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_EK_BLOB_AUTH
value|((TPM_STRUCTURE_TAG) 0x000D)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_COUNTER_VALUE
value|((TPM_STRUCTURE_TAG) 0x000E)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_TRANSPORT_INTERNAL
value|((TPM_STRUCTURE_TAG) 0x000F)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_TRANSPORT_LOG_IN
value|((TPM_STRUCTURE_TAG) 0x0010)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_TRANSPORT_LOG_OUT
value|((TPM_STRUCTURE_TAG) 0x0011)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_AUDIT_EVENT_IN
value|((TPM_STRUCTURE_TAG) 0x0012)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_AUDIT_EVENT_OUT
value|((TPM_STRUCTURE_TAG) 0x0013)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CURRENT_TICKS
value|((TPM_STRUCTURE_TAG) 0x0014)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_KEY
value|((TPM_STRUCTURE_TAG) 0x0015)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_STORED_DATA12
value|((TPM_STRUCTURE_TAG) 0x0016)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_NV_ATTRIBUTES
value|((TPM_STRUCTURE_TAG) 0x0017)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_NV_DATA_PUBLIC
value|((TPM_STRUCTURE_TAG) 0x0018)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_NV_DATA_SENSITIVE
value|((TPM_STRUCTURE_TAG) 0x0019)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DELEGATIONS
value|((TPM_STRUCTURE_TAG) 0x001A)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DELEGATE_PUBLIC
value|((TPM_STRUCTURE_TAG) 0x001B)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DELEGATE_TABLE_ROW
value|((TPM_STRUCTURE_TAG) 0x001C)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_TRANSPORT_AUTH
value|((TPM_STRUCTURE_TAG) 0x001D)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_TRANSPORT_PUBLIC
value|((TPM_STRUCTURE_TAG) 0x001E)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_PERMANENT_FLAGS
value|((TPM_STRUCTURE_TAG) 0x001F)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_STCLEAR_FLAGS
value|((TPM_STRUCTURE_TAG) 0x0020)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_STANY_FLAGS
value|((TPM_STRUCTURE_TAG) 0x0021)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_PERMANENT_DATA
value|((TPM_STRUCTURE_TAG) 0x0022)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_STCLEAR_DATA
value|((TPM_STRUCTURE_TAG) 0x0023)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_STANY_DATA
value|((TPM_STRUCTURE_TAG) 0x0024)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_FAMILY_TABLE_ENTRY
value|((TPM_STRUCTURE_TAG) 0x0025)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DELEGATE_SENSITIVE
value|((TPM_STRUCTURE_TAG) 0x0026)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DELG_KEY_BLOB
value|((TPM_STRUCTURE_TAG) 0x0027)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_KEY12
value|((TPM_STRUCTURE_TAG) 0x0028)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CERTIFY_INFO2
value|((TPM_STRUCTURE_TAG) 0x0029)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DELEGATE_OWNER_BLOB
value|((TPM_STRUCTURE_TAG) 0x002A)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_EK_BLOB_ACTIVATE
value|((TPM_STRUCTURE_TAG) 0x002B)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DAA_BLOB
value|((TPM_STRUCTURE_TAG) 0x002C)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DAA_CONTEXT
value|((TPM_STRUCTURE_TAG) 0x002D)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DAA_ENFORCE
value|((TPM_STRUCTURE_TAG) 0x002E)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DAA_ISSUER
value|((TPM_STRUCTURE_TAG) 0x002F)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CAP_VERSION_INFO
value|((TPM_STRUCTURE_TAG) 0x0030)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DAA_SENSITIVE
value|((TPM_STRUCTURE_TAG) 0x0031)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DAA_TPM
value|((TPM_STRUCTURE_TAG) 0x0032)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CMK_MIGAUTH
value|((TPM_STRUCTURE_TAG) 0x0033)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CMK_SIGTICKET
value|((TPM_STRUCTURE_TAG) 0x0034)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_CMK_MA_APPROVAL
value|((TPM_STRUCTURE_TAG) 0x0035)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_QUOTE_INFO2
value|((TPM_STRUCTURE_TAG) 0x0036)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DA_INFO
value|((TPM_STRUCTURE_TAG) 0x0037)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DA_LIMITED
value|((TPM_STRUCTURE_TAG) 0x0038)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_DA_ACTION_TYPE
value|((TPM_STRUCTURE_TAG) 0x0039)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4: TPM Types
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.1: TPM_RESOURCE_TYPE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_RT_KEY
value|((TPM_RESOURCE_TYPE) 0x00000001)
end_define

begin_comment
comment|///< The handle is a key handle and is the result of a LoadKey type operation
end_comment

begin_define
define|#
directive|define
name|TPM_RT_AUTH
value|((TPM_RESOURCE_TYPE) 0x00000002)
end_define

begin_comment
comment|///< The handle is an authorization handle. Auth handles come from TPM_OIAP, TPM_OSAP and TPM_DSAP
end_comment

begin_define
define|#
directive|define
name|TPM_RT_HASH
value|((TPM_RESOURCE_TYPE) 0x00000003)
end_define

begin_comment
comment|///< Reserved for hashes
end_comment

begin_define
define|#
directive|define
name|TPM_RT_TRANS
value|((TPM_RESOURCE_TYPE) 0x00000004)
end_define

begin_comment
comment|///< The handle is for a transport session. Transport handles come from TPM_EstablishTransport
end_comment

begin_define
define|#
directive|define
name|TPM_RT_CONTEXT
value|((TPM_RESOURCE_TYPE) 0x00000005)
end_define

begin_comment
comment|///< Resource wrapped and held outside the TPM using the context save/restore commands
end_comment

begin_define
define|#
directive|define
name|TPM_RT_COUNTER
value|((TPM_RESOURCE_TYPE) 0x00000006)
end_define

begin_comment
comment|///< Reserved for counters
end_comment

begin_define
define|#
directive|define
name|TPM_RT_DELEGATE
value|((TPM_RESOURCE_TYPE) 0x00000007)
end_define

begin_comment
comment|///< The handle is for a delegate row. These are the internal rows held in NV storage by the TPM
end_comment

begin_define
define|#
directive|define
name|TPM_RT_DAA_TPM
value|((TPM_RESOURCE_TYPE) 0x00000008)
end_define

begin_comment
comment|///< The value is a DAA TPM specific blob
end_comment

begin_define
define|#
directive|define
name|TPM_RT_DAA_V0
value|((TPM_RESOURCE_TYPE) 0x00000009)
end_define

begin_comment
comment|///< The value is a DAA V0 parameter
end_comment

begin_define
define|#
directive|define
name|TPM_RT_DAA_V1
value|((TPM_RESOURCE_TYPE) 0x0000000A)
end_define

begin_comment
comment|///< The value is a DAA V1 parameter
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.2: TPM_PAYLOAD_TYPE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_PT_ASYM
value|((TPM_PAYLOAD_TYPE) 0x01)
end_define

begin_comment
comment|///< The entity is an asymmetric key
end_comment

begin_define
define|#
directive|define
name|TPM_PT_BIND
value|((TPM_PAYLOAD_TYPE) 0x02)
end_define

begin_comment
comment|///< The entity is bound data
end_comment

begin_define
define|#
directive|define
name|TPM_PT_MIGRATE
value|((TPM_PAYLOAD_TYPE) 0x03)
end_define

begin_comment
comment|///< The entity is a migration blob
end_comment

begin_define
define|#
directive|define
name|TPM_PT_MAINT
value|((TPM_PAYLOAD_TYPE) 0x04)
end_define

begin_comment
comment|///< The entity is a maintenance blob
end_comment

begin_define
define|#
directive|define
name|TPM_PT_SEAL
value|((TPM_PAYLOAD_TYPE) 0x05)
end_define

begin_comment
comment|///< The entity is sealed data
end_comment

begin_define
define|#
directive|define
name|TPM_PT_MIGRATE_RESTRICTED
value|((TPM_PAYLOAD_TYPE) 0x06)
end_define

begin_comment
comment|///< The entity is a restricted-migration asymmetric key
end_comment

begin_define
define|#
directive|define
name|TPM_PT_MIGRATE_EXTERNAL
value|((TPM_PAYLOAD_TYPE) 0x07)
end_define

begin_comment
comment|///< The entity is a external migratable key
end_comment

begin_define
define|#
directive|define
name|TPM_PT_CMK_MIGRATE
value|((TPM_PAYLOAD_TYPE) 0x08)
end_define

begin_comment
comment|///< The entity is a CMK migratable blob
end_comment

begin_define
define|#
directive|define
name|TPM_PT_VENDOR_SPECIFIC
value|((TPM_PAYLOAD_TYPE) 0x80)
end_define

begin_comment
comment|///< 0x80 - 0xFF Vendor specific payloads
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.3: TPM_ENTITY_TYPE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_ET_KEYHANDLE
value|((UINT16) 0x0001)
end_define

begin_comment
comment|///< The entity is a keyHandle or key
end_comment

begin_define
define|#
directive|define
name|TPM_ET_OWNER
value|((UINT16) 0x0002)
end_define

begin_comment
comment|///< The entity is the TPM Owner
end_comment

begin_define
define|#
directive|define
name|TPM_ET_DATA
value|((UINT16) 0x0003)
end_define

begin_comment
comment|///< The entity is some data
end_comment

begin_define
define|#
directive|define
name|TPM_ET_SRK
value|((UINT16) 0x0004)
end_define

begin_comment
comment|///< The entity is the SRK
end_comment

begin_define
define|#
directive|define
name|TPM_ET_KEY
value|((UINT16) 0x0005)
end_define

begin_comment
comment|///< The entity is a key or keyHandle
end_comment

begin_define
define|#
directive|define
name|TPM_ET_REVOKE
value|((UINT16) 0x0006)
end_define

begin_comment
comment|///< The entity is the RevokeTrust value
end_comment

begin_define
define|#
directive|define
name|TPM_ET_DEL_OWNER_BLOB
value|((UINT16) 0x0007)
end_define

begin_comment
comment|///< The entity is a delegate owner blob
end_comment

begin_define
define|#
directive|define
name|TPM_ET_DEL_ROW
value|((UINT16) 0x0008)
end_define

begin_comment
comment|///< The entity is a delegate row
end_comment

begin_define
define|#
directive|define
name|TPM_ET_DEL_KEY_BLOB
value|((UINT16) 0x0009)
end_define

begin_comment
comment|///< The entity is a delegate key blob
end_comment

begin_define
define|#
directive|define
name|TPM_ET_COUNTER
value|((UINT16) 0x000A)
end_define

begin_comment
comment|///< The entity is a counter
end_comment

begin_define
define|#
directive|define
name|TPM_ET_NV
value|((UINT16) 0x000B)
end_define

begin_comment
comment|///< The entity is a NV index
end_comment

begin_define
define|#
directive|define
name|TPM_ET_OPERATOR
value|((UINT16) 0x000C)
end_define

begin_comment
comment|///< The entity is the operator
end_comment

begin_define
define|#
directive|define
name|TPM_ET_RESERVED_HANDLE
value|((UINT16) 0x0040)
end_define

begin_comment
comment|///< Reserved. This value avoids collisions with the handle MSB setting.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TPM_ENTITY_TYPE MSB Values: The MSB is used to indicate the ADIP encryption sheme when applicable
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_ET_XOR
value|((UINT16) 0x0000)
end_define

begin_comment
comment|///< ADIP encryption scheme: XOR
end_comment

begin_define
define|#
directive|define
name|TPM_ET_AES128
value|((UINT16) 0x0006)
end_define

begin_comment
comment|///< ADIP encryption scheme: AES 128 bits
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.4.1: Reserved Key Handles
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_KH_SRK
value|((TPM_KEY_HANDLE) 0x40000000)
end_define

begin_comment
comment|///< The handle points to the SRK
end_comment

begin_define
define|#
directive|define
name|TPM_KH_OWNER
value|((TPM_KEY_HANDLE) 0x40000001)
end_define

begin_comment
comment|///< The handle points to the TPM Owner
end_comment

begin_define
define|#
directive|define
name|TPM_KH_REVOKE
value|((TPM_KEY_HANDLE) 0x40000002)
end_define

begin_comment
comment|///< The handle points to the RevokeTrust value
end_comment

begin_define
define|#
directive|define
name|TPM_KH_TRANSPORT
value|((TPM_KEY_HANDLE) 0x40000003)
end_define

begin_comment
comment|///< The handle points to the EstablishTransport static authorization
end_comment

begin_define
define|#
directive|define
name|TPM_KH_OPERATOR
value|((TPM_KEY_HANDLE) 0x40000004)
end_define

begin_comment
comment|///< The handle points to the Operator auth
end_comment

begin_define
define|#
directive|define
name|TPM_KH_ADMIN
value|((TPM_KEY_HANDLE) 0x40000005)
end_define

begin_comment
comment|///< The handle points to the delegation administration auth
end_comment

begin_define
define|#
directive|define
name|TPM_KH_EK
value|((TPM_KEY_HANDLE) 0x40000006)
end_define

begin_comment
comment|///< The handle points to the PUBEK, only usable with TPM_OwnerReadInternalPub
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.5: TPM_STARTUP_TYPE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_ST_CLEAR
value|((TPM_STARTUP_TYPE) 0x0001)
end_define

begin_comment
comment|///< The TPM is starting up from a clean state
end_comment

begin_define
define|#
directive|define
name|TPM_ST_STATE
value|((TPM_STARTUP_TYPE) 0x0002)
end_define

begin_comment
comment|///< The TPM is starting up from a saved state
end_comment

begin_define
define|#
directive|define
name|TPM_ST_DEACTIVATED
value|((TPM_STARTUP_TYPE) 0x0003)
end_define

begin_comment
comment|///< The TPM is to startup and set the deactivated flag to TRUE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.6: TPM_STATUP_EFFECTS
end_comment

begin_comment
comment|// The table makeup is still an open issue.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.7: TPM_PROTOCOL_ID
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_PID_OIAP
value|((TPM_PROTOCOL_ID) 0x0001)
end_define

begin_comment
comment|///< The OIAP protocol.
end_comment

begin_define
define|#
directive|define
name|TPM_PID_OSAP
value|((TPM_PROTOCOL_ID) 0x0002)
end_define

begin_comment
comment|///< The OSAP protocol.
end_comment

begin_define
define|#
directive|define
name|TPM_PID_ADIP
value|((TPM_PROTOCOL_ID) 0x0003)
end_define

begin_comment
comment|///< The ADIP protocol.
end_comment

begin_define
define|#
directive|define
name|TPM_PID_ADCP
value|((TPM_PROTOCOL_ID) 0x0004)
end_define

begin_comment
comment|///< The ADCP protocol.
end_comment

begin_define
define|#
directive|define
name|TPM_PID_OWNER
value|((TPM_PROTOCOL_ID) 0x0005)
end_define

begin_comment
comment|///< The protocol for taking ownership of a TPM.
end_comment

begin_define
define|#
directive|define
name|TPM_PID_DSAP
value|((TPM_PROTOCOL_ID) 0x0006)
end_define

begin_comment
comment|///< The DSAP protocol
end_comment

begin_define
define|#
directive|define
name|TPM_PID_TRANSPORT
value|((TPM_PROTOCOL_ID) 0x0007)
end_define

begin_comment
comment|///< The transport protocol
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.8: TPM_ALGORITHM_ID
end_comment

begin_comment
comment|//   The TPM MUST support the algorithms TPM_ALG_RSA, TPM_ALG_SHA, TPM_ALG_HMAC,
end_comment

begin_comment
comment|//   TPM_ALG_MGF1
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_RSA
value|((TPM_ALGORITHM_ID) 0x00000001)
end_define

begin_comment
comment|///< The RSA algorithm.
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_DES
value|((TPM_ALGORITHM_ID) 0x00000002)
end_define

begin_comment
comment|///< The DES algorithm
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_3DES
value|((TPM_ALGORITHM_ID) 0x00000003)
end_define

begin_comment
comment|///< The 3DES algorithm in EDE mode
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_SHA
value|((TPM_ALGORITHM_ID) 0x00000004)
end_define

begin_comment
comment|///< The SHA1 algorithm
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_HMAC
value|((TPM_ALGORITHM_ID) 0x00000005)
end_define

begin_comment
comment|///< The RFC 2104 HMAC algorithm
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_AES128
value|((TPM_ALGORITHM_ID) 0x00000006)
end_define

begin_comment
comment|///< The AES algorithm, key size 128
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_MGF1
value|((TPM_ALGORITHM_ID) 0x00000007)
end_define

begin_comment
comment|///< The XOR algorithm using MGF1 to create a string the size of the encrypted block
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_AES192
value|((TPM_ALGORITHM_ID) 0x00000008)
end_define

begin_comment
comment|///< AES, key size 192
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_AES256
value|((TPM_ALGORITHM_ID) 0x00000009)
end_define

begin_comment
comment|///< AES, key size 256
end_comment

begin_define
define|#
directive|define
name|TPM_ALG_XOR
value|((TPM_ALGORITHM_ID) 0x0000000A)
end_define

begin_comment
comment|///< XOR using the rolling nonces
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.9: TPM_PHYSICAL_PRESENCE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_PHYSICAL_PRESENCE_HW_DISABLE
value|((TPM_PHYSICAL_PRESENCE) 0x0200)
end_define

begin_comment
comment|///< Sets the physicalPresenceHWEnable to FALSE
end_comment

begin_define
define|#
directive|define
name|TPM_PHYSICAL_PRESENCE_CMD_DISABLE
value|((TPM_PHYSICAL_PRESENCE) 0x0100)
end_define

begin_comment
comment|///< Sets the physicalPresenceCMDEnable to FALSE
end_comment

begin_define
define|#
directive|define
name|TPM_PHYSICAL_PRESENCE_LIFETIME_LOCK
value|((TPM_PHYSICAL_PRESENCE) 0x0080)
end_define

begin_comment
comment|///< Sets the physicalPresenceLifetimeLock to TRUE
end_comment

begin_define
define|#
directive|define
name|TPM_PHYSICAL_PRESENCE_HW_ENABLE
value|((TPM_PHYSICAL_PRESENCE) 0x0040)
end_define

begin_comment
comment|///< Sets the physicalPresenceHWEnable to TRUE
end_comment

begin_define
define|#
directive|define
name|TPM_PHYSICAL_PRESENCE_CMD_ENABLE
value|((TPM_PHYSICAL_PRESENCE) 0x0020)
end_define

begin_comment
comment|///< Sets the physicalPresenceCMDEnable to TRUE
end_comment

begin_define
define|#
directive|define
name|TPM_PHYSICAL_PRESENCE_NOTPRESENT
value|((TPM_PHYSICAL_PRESENCE) 0x0010)
end_define

begin_comment
comment|///< Sets PhysicalPresence = FALSE
end_comment

begin_define
define|#
directive|define
name|TPM_PHYSICAL_PRESENCE_PRESENT
value|((TPM_PHYSICAL_PRESENCE) 0x0008)
end_define

begin_comment
comment|///< Sets PhysicalPresence = TRUE
end_comment

begin_define
define|#
directive|define
name|TPM_PHYSICAL_PRESENCE_LOCK
value|((TPM_PHYSICAL_PRESENCE) 0x0004)
end_define

begin_comment
comment|///< Sets PhysicalPresenceLock = TRUE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.10: TPM_MIGRATE_SCHEME
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_MS_MIGRATE
value|((TPM_MIGRATE_SCHEME) 0x0001)
end_define

begin_comment
comment|///< A public key that can be used with all TPM migration commands other than 'ReWrap' mode.
end_comment

begin_define
define|#
directive|define
name|TPM_MS_REWRAP
value|((TPM_MIGRATE_SCHEME) 0x0002)
end_define

begin_comment
comment|///< A public key that can be used for the ReWrap mode of TPM_CreateMigrationBlob.
end_comment

begin_define
define|#
directive|define
name|TPM_MS_MAINT
value|((TPM_MIGRATE_SCHEME) 0x0003)
end_define

begin_comment
comment|///< A public key that can be used for the Maintenance commands
end_comment

begin_define
define|#
directive|define
name|TPM_MS_RESTRICT_MIGRATE
value|((TPM_MIGRATE_SCHEME) 0x0004)
end_define

begin_comment
comment|///< The key is to be migrated to a Migration Authority.
end_comment

begin_define
define|#
directive|define
name|TPM_MS_RESTRICT_APPROVE_DOUBLE
value|((TPM_MIGRATE_SCHEME) 0x0005)
end_define

begin_comment
comment|///< The key is to be migrated to an entity approved by a Migration Authority using double wrapping
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.11: TPM_EK_TYPE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_EK_TYPE_ACTIVATE
value|((TPM_EK_TYPE) 0x0001)
end_define

begin_comment
comment|///< The blob MUST be TPM_EK_BLOB_ACTIVATE
end_comment

begin_define
define|#
directive|define
name|TPM_EK_TYPE_AUTH
value|((TPM_EK_TYPE) 0x0002)
end_define

begin_comment
comment|///< The blob MUST be TPM_EK_BLOB_AUTH
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 4.12: TPM_PLATFORM_SPECIFIC
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_PS_PC_11
value|((TPM_PLATFORM_SPECIFIC) 0x0001)
end_define

begin_comment
comment|///< PC Specific version 1.1
end_comment

begin_define
define|#
directive|define
name|TPM_PS_PC_12
value|((TPM_PLATFORM_SPECIFIC) 0x0002)
end_define

begin_comment
comment|///< PC Specific version 1.2
end_comment

begin_define
define|#
directive|define
name|TPM_PS_PDA_12
value|((TPM_PLATFORM_SPECIFIC) 0x0003)
end_define

begin_comment
comment|///< PDA Specific version 1.2
end_comment

begin_define
define|#
directive|define
name|TPM_PS_Server_12
value|((TPM_PLATFORM_SPECIFIC) 0x0004)
end_define

begin_comment
comment|///< Server Specific version 1.2
end_comment

begin_define
define|#
directive|define
name|TPM_PS_Mobile_12
value|((TPM_PLATFORM_SPECIFIC) 0x0005)
end_define

begin_comment
comment|///< Mobil Specific version 1.2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 5: Basic Structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.1: TPM_STRUCT_VER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STRUCT_VER
block|{
name|UINT8
name|major
decl_stmt|;
name|UINT8
name|minor
decl_stmt|;
name|UINT8
name|revMajor
decl_stmt|;
name|UINT8
name|revMinor
decl_stmt|;
block|}
name|TPM_STRUCT_VER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.3: TPM_VERSION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_VERSION
block|{
name|TPM_VERSION_BYTE
name|major
decl_stmt|;
name|TPM_VERSION_BYTE
name|minor
decl_stmt|;
name|UINT8
name|revMajor
decl_stmt|;
name|UINT8
name|revMinor
decl_stmt|;
block|}
name|TPM_VERSION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_SHA1_160_HASH_LEN
value|0x14
end_define

begin_define
define|#
directive|define
name|TPM_SHA1BASED_NONCE_LEN
value|TPM_SHA1_160_HASH_LEN
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.4: TPM_DIGEST
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DIGEST
block|{
name|UINT8
name|digest
index|[
name|TPM_SHA1_160_HASH_LEN
index|]
decl_stmt|;
block|}
name|TPM_DIGEST
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This SHALL be the digest of the chosen identityLabel and privacyCA for a new TPM identity
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_DIGEST
name|TPM_CHOSENID_HASH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This SHALL be the hash of a list of PCR indexes and PCR values that a key or data is bound to
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_DIGEST
name|TPM_COMPOSITE_HASH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This SHALL be the value of a DIR register
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_DIGEST
name|TPM_DIRVALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TPM_DIGEST
name|TPM_HMAC
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The value inside of the PCR
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_DIGEST
name|TPM_PCRVALUE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This SHALL be the value of the current internal audit state
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_DIGEST
name|TPM_AUDITDIGEST
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.5: TPM_NONCE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_NONCE
block|{
name|UINT8
name|nonce
index|[
literal|20
index|]
decl_stmt|;
block|}
name|TPM_NONCE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This SHALL be a random value generated by a TPM immediately after the EK is installed
end_comment

begin_comment
comment|/// in that TPM, whenever an EK is installed in that TPM
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_NONCE
name|TPM_DAA_TPM_SEED
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This SHALL be a random value
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_NONCE
name|TPM_DAA_CONTEXT_SEED
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 5.6: TPM_AUTHDATA
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The AuthData data is the information that is saved or passed to provide proof of ownership
end_comment

begin_comment
comment|/// 296 of an entity
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|tdTPM_AUTHDATA
index|[
literal|20
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|tdTPM_AUTHDATA
name|TPM_AUTHDATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A secret plaintext value used in the authorization process
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_AUTHDATA
name|TPM_SECRET
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A ciphertext (encrypted) version of AuthData data. The encryption mechanism depends on the context
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|TPM_AUTHDATA
name|TPM_ENCAUTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.7: TPM_KEY_HANDLE_LIST
end_comment

begin_comment
comment|/// Size of handle is loaded * sizeof(TPM_KEY_HANDLE)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_KEY_HANDLE_LIST
block|{
name|UINT16
name|loaded
decl_stmt|;
name|TPM_KEY_HANDLE
name|handle
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TPM_KEY_HANDLE_LIST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 5.8: TPM_KEY_USAGE values
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM_KEY_SIGNING SHALL indicate a signing key. The [private] key SHALL be
end_comment

begin_comment
comment|/// used for signing operations, only. This means that it MUST be a leaf of the
end_comment

begin_comment
comment|/// Protected Storage key hierarchy.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_SIGNING
value|((UINT16) 0x0010)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM_KEY_STORAGE SHALL indicate a storage key. The key SHALL be used to wrap
end_comment

begin_comment
comment|/// and unwrap other keys in the Protected Storage hierarchy
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_STORAGE
value|((UINT16) 0x0011)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM_KEY_IDENTITY SHALL indicate an identity key. The key SHALL be used for
end_comment

begin_comment
comment|/// operations that require a TPM identity, only.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_IDENTITY
value|((UINT16) 0x0012)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM_KEY_AUTHCHANGE SHALL indicate an ephemeral key that is in use during
end_comment

begin_comment
comment|/// the ChangeAuthAsym process, only.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_AUTHCHANGE
value|((UINT16) 0x0013)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM_KEY_BIND SHALL indicate a key that can be used for TPM_Bind and
end_comment

begin_comment
comment|/// TPM_Unbind operations only.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_BIND
value|((UINT16) 0x0014)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM_KEY_LEGACY SHALL indicate a key that can perform signing and binding
end_comment

begin_comment
comment|/// operations. The key MAY be used for both signing and binding operations.
end_comment

begin_comment
comment|/// The TPM_KEY_LEGACY key type is to allow for use by applications where both
end_comment

begin_comment
comment|/// signing and encryption operations occur with the same key. The use of this
end_comment

begin_comment
comment|/// key type is not recommended TPM_KEY_MIGRATE 0x0016 This SHALL indicate a
end_comment

begin_comment
comment|/// key in use for TPM_MigrateKey
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_LEGACY
value|((UINT16) 0x0015)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM_KEY_MIGRAGE SHALL indicate a key in use for TPM_MigrateKey
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_MIGRATE
value|((UINT16) 0x0016)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 5.8.1: Mandatory Key Usage Schemes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_ES_NONE
value|((TPM_ENC_SCHEME) 0x0001)
end_define

begin_define
define|#
directive|define
name|TPM_ES_RSAESPKCSv15
value|((TPM_ENC_SCHEME) 0x0002)
end_define

begin_define
define|#
directive|define
name|TPM_ES_RSAESOAEP_SHA1_MGF1
value|((TPM_ENC_SCHEME) 0x0003)
end_define

begin_define
define|#
directive|define
name|TPM_ES_SYM_CNT
value|((TPM_ENC_SCHEME) 0x0004)
end_define

begin_comment
comment|///< rev94 defined
end_comment

begin_define
define|#
directive|define
name|TPM_ES_SYM_CTR
value|((TPM_ENC_SCHEME) 0x0004)
end_define

begin_define
define|#
directive|define
name|TPM_ES_SYM_OFB
value|((TPM_ENC_SCHEME) 0x0005)
end_define

begin_define
define|#
directive|define
name|TPM_SS_NONE
value|((TPM_SIG_SCHEME) 0x0001)
end_define

begin_define
define|#
directive|define
name|TPM_SS_RSASSAPKCS1v15_SHA1
value|((TPM_SIG_SCHEME) 0x0002)
end_define

begin_define
define|#
directive|define
name|TPM_SS_RSASSAPKCS1v15_DER
value|((TPM_SIG_SCHEME) 0x0003)
end_define

begin_define
define|#
directive|define
name|TPM_SS_RSASSAPKCS1v15_INFO
value|((TPM_SIG_SCHEME) 0x0004)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 5.9: TPM_AUTH_DATA_USAGE values
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_AUTH_NEVER
value|((TPM_AUTH_DATA_USAGE) 0x00)
end_define

begin_define
define|#
directive|define
name|TPM_AUTH_ALWAYS
value|((TPM_AUTH_DATA_USAGE) 0x01)
end_define

begin_define
define|#
directive|define
name|TPM_AUTH_PRIV_USE_ONLY
value|((TPM_AUTH_DATA_USAGE) 0x03)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.10: TPM_KEY_FLAGS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
name|tdTPM_KEY_FLAGS
block|{
name|redirection
init|=
literal|0x00000001
block|,
name|migratable
init|=
literal|0x00000002
block|,
name|isVolatile
init|=
literal|0x00000004
block|,
name|pcrIgnoredOnRead
init|=
literal|0x00000008
block|,
name|migrateAuthority
init|=
literal|0x00000010
block|}
name|TPM_KEY_FLAGS_BITS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.11: TPM_CHANGEAUTH_VALIDATE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CHANGEAUTH_VALIDATE
block|{
name|TPM_SECRET
name|newAuthSecret
decl_stmt|;
name|TPM_NONCE
name|n1
decl_stmt|;
block|}
name|TPM_CHANGEAUTH_VALIDATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.12: TPM_MIGRATIONKEYAUTH
end_comment

begin_comment
comment|///   decalared after section 10 to catch declaration of TPM_PUBKEY
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2 section 10.1: TPM_KEY_PARMS
end_comment

begin_comment
comment|///   [size_is(parmSize)] BYTE* parms;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_KEY_PARMS
block|{
name|TPM_ALGORITHM_ID
name|algorithmID
decl_stmt|;
name|TPM_ENC_SCHEME
name|encScheme
decl_stmt|;
name|TPM_SIG_SCHEME
name|sigScheme
decl_stmt|;
name|UINT32
name|parmSize
decl_stmt|;
name|UINT8
modifier|*
name|parms
decl_stmt|;
block|}
name|TPM_KEY_PARMS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 10.4: TPM_STORE_PUBKEY
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STORE_PUBKEY
block|{
name|UINT32
name|keyLength
decl_stmt|;
name|UINT8
name|key
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TPM_STORE_PUBKEY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 10.5: TPM_PUBKEY
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_PUBKEY
block|{
name|TPM_KEY_PARMS
name|algorithmParms
decl_stmt|;
name|TPM_STORE_PUBKEY
name|pubKey
decl_stmt|;
block|}
name|TPM_PUBKEY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.12: TPM_MIGRATIONKEYAUTH
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_MIGRATIONKEYAUTH
block|{
name|TPM_PUBKEY
name|migrationKey
decl_stmt|;
name|TPM_MIGRATE_SCHEME
name|migrationScheme
decl_stmt|;
name|TPM_DIGEST
name|digest
decl_stmt|;
block|}
name|TPM_MIGRATIONKEYAUTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.13: TPM_COUNTER_VALUE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_COUNTER_VALUE
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT8
name|label
index|[
literal|4
index|]
decl_stmt|;
name|TPM_ACTUAL_COUNT
name|counter
decl_stmt|;
block|}
name|TPM_COUNTER_VALUE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.14: TPM_SIGN_INFO
end_comment

begin_comment
comment|///   Size of data indicated by dataLen
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_SIGN_INFO
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT8
name|fixed
index|[
literal|4
index|]
decl_stmt|;
name|TPM_NONCE
name|replay
decl_stmt|;
name|UINT32
name|dataLen
decl_stmt|;
name|UINT8
modifier|*
name|data
decl_stmt|;
block|}
name|TPM_SIGN_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.15: TPM_MSA_COMPOSITE
end_comment

begin_comment
comment|///   Number of migAuthDigest indicated by MSAlist
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_MSA_COMPOSITE
block|{
name|UINT32
name|MSAlist
decl_stmt|;
name|TPM_DIGEST
name|migAuthDigest
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TPM_MSA_COMPOSITE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.16: TPM_CMK_AUTH
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CMK_AUTH
block|{
name|TPM_DIGEST
name|migrationAuthorityDigest
decl_stmt|;
name|TPM_DIGEST
name|destinationKeyDigest
decl_stmt|;
name|TPM_DIGEST
name|sourceKeyDigest
decl_stmt|;
block|}
name|TPM_CMK_AUTH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 5.17: TPM_CMK_DELEGATE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_CMK_DELEGATE_SIGNING
value|((TPM_CMK_DELEGATE) BIT31)
end_define

begin_define
define|#
directive|define
name|TPM_CMK_DELEGATE_STORAGE
value|((TPM_CMK_DELEGATE) BIT30)
end_define

begin_define
define|#
directive|define
name|TPM_CMK_DELEGATE_BIND
value|((TPM_CMK_DELEGATE) BIT29)
end_define

begin_define
define|#
directive|define
name|TPM_CMK_DELEGATE_LEGACY
value|((TPM_CMK_DELEGATE) BIT28)
end_define

begin_define
define|#
directive|define
name|TPM_CMK_DELEGATE_MIGRATE
value|((TPM_CMK_DELEGATE) BIT27)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.18: TPM_SELECT_SIZE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_SELECT_SIZE
block|{
name|UINT8
name|major
decl_stmt|;
name|UINT8
name|minor
decl_stmt|;
name|UINT16
name|reqSize
decl_stmt|;
block|}
name|TPM_SELECT_SIZE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5,19: TPM_CMK_MIGAUTH
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CMK_MIGAUTH
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DIGEST
name|msaDigest
decl_stmt|;
name|TPM_DIGEST
name|pubKeyDigest
decl_stmt|;
block|}
name|TPM_CMK_MIGAUTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.20: TPM_CMK_SIGTICKET
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CMK_SIGTICKET
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DIGEST
name|verKeyDigest
decl_stmt|;
name|TPM_DIGEST
name|signedData
decl_stmt|;
block|}
name|TPM_CMK_SIGTICKET
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 5.21: TPM_CMK_MA_APPROVAL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CMK_MA_APPROVAL
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DIGEST
name|migrationAuthorityDigest
decl_stmt|;
block|}
name|TPM_CMK_MA_APPROVAL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 6: Command Tags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_TAG_RQU_COMMAND
value|((TPM_STRUCTURE_TAG) 0x00C1)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_RQU_AUTH1_COMMAND
value|((TPM_STRUCTURE_TAG) 0x00C2)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_RQU_AUTH2_COMMAND
value|((TPM_STRUCTURE_TAG) 0x00C3)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_RSP_COMMAND
value|((TPM_STRUCTURE_TAG) 0x00C4)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_RSP_AUTH1_COMMAND
value|((TPM_STRUCTURE_TAG) 0x00C5)
end_define

begin_define
define|#
directive|define
name|TPM_TAG_RSP_AUTH2_COMMAND
value|((TPM_STRUCTURE_TAG) 0x00C6)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 7.1: TPM_PERMANENT_FLAGS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_PERMANENT_FLAGS
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|BOOLEAN
name|disable
decl_stmt|;
name|BOOLEAN
name|ownership
decl_stmt|;
name|BOOLEAN
name|deactivated
decl_stmt|;
name|BOOLEAN
name|readPubek
decl_stmt|;
name|BOOLEAN
name|disableOwnerClear
decl_stmt|;
name|BOOLEAN
name|allowMaintenance
decl_stmt|;
name|BOOLEAN
name|physicalPresenceLifetimeLock
decl_stmt|;
name|BOOLEAN
name|physicalPresenceHWEnable
decl_stmt|;
name|BOOLEAN
name|physicalPresenceCMDEnable
decl_stmt|;
name|BOOLEAN
name|CEKPUsed
decl_stmt|;
name|BOOLEAN
name|TPMpost
decl_stmt|;
name|BOOLEAN
name|TPMpostLock
decl_stmt|;
name|BOOLEAN
name|FIPS
decl_stmt|;
name|BOOLEAN
name|operator
decl_stmt|;
name|BOOLEAN
name|enableRevokeEK
decl_stmt|;
name|BOOLEAN
name|nvLocked
decl_stmt|;
name|BOOLEAN
name|readSRKPub
decl_stmt|;
name|BOOLEAN
name|tpmEstablished
decl_stmt|;
name|BOOLEAN
name|maintenanceDone
decl_stmt|;
name|BOOLEAN
name|disableFullDALogicInfo
decl_stmt|;
block|}
name|TPM_PERMANENT_FLAGS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 7.1.1: Flag Restrictions (of TPM_PERMANENT_FLAGS)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_PF_DISABLE
value|((TPM_CAPABILITY_AREA) 1)
end_define

begin_define
define|#
directive|define
name|TPM_PF_OWNERSHIP
value|((TPM_CAPABILITY_AREA) 2)
end_define

begin_define
define|#
directive|define
name|TPM_PF_DEACTIVATED
value|((TPM_CAPABILITY_AREA) 3)
end_define

begin_define
define|#
directive|define
name|TPM_PF_READPUBEK
value|((TPM_CAPABILITY_AREA) 4)
end_define

begin_define
define|#
directive|define
name|TPM_PF_DISABLEOWNERCLEAR
value|((TPM_CAPABILITY_AREA) 5)
end_define

begin_define
define|#
directive|define
name|TPM_PF_ALLOWMAINTENANCE
value|((TPM_CAPABILITY_AREA) 6)
end_define

begin_define
define|#
directive|define
name|TPM_PF_PHYSICALPRESENCELIFETIMELOCK
value|((TPM_CAPABILITY_AREA) 7)
end_define

begin_define
define|#
directive|define
name|TPM_PF_PHYSICALPRESENCEHWENABLE
value|((TPM_CAPABILITY_AREA) 8)
end_define

begin_define
define|#
directive|define
name|TPM_PF_PHYSICALPRESENCECMDENABLE
value|((TPM_CAPABILITY_AREA) 9)
end_define

begin_define
define|#
directive|define
name|TPM_PF_CEKPUSED
value|((TPM_CAPABILITY_AREA) 10)
end_define

begin_define
define|#
directive|define
name|TPM_PF_TPMPOST
value|((TPM_CAPABILITY_AREA) 11)
end_define

begin_define
define|#
directive|define
name|TPM_PF_TPMPOSTLOCK
value|((TPM_CAPABILITY_AREA) 12)
end_define

begin_define
define|#
directive|define
name|TPM_PF_FIPS
value|((TPM_CAPABILITY_AREA) 13)
end_define

begin_define
define|#
directive|define
name|TPM_PF_OPERATOR
value|((TPM_CAPABILITY_AREA) 14)
end_define

begin_define
define|#
directive|define
name|TPM_PF_ENABLEREVOKEEK
value|((TPM_CAPABILITY_AREA) 15)
end_define

begin_define
define|#
directive|define
name|TPM_PF_NV_LOCKED
value|((TPM_CAPABILITY_AREA) 16)
end_define

begin_define
define|#
directive|define
name|TPM_PF_READSRKPUB
value|((TPM_CAPABILITY_AREA) 17)
end_define

begin_define
define|#
directive|define
name|TPM_PF_TPMESTABLISHED
value|((TPM_CAPABILITY_AREA) 18)
end_define

begin_define
define|#
directive|define
name|TPM_PF_MAINTENANCEDONE
value|((TPM_CAPABILITY_AREA) 19)
end_define

begin_define
define|#
directive|define
name|TPM_PF_DISABLEFULLDALOGICINFO
value|((TPM_CAPABILITY_AREA) 20)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 7.2: TPM_STCLEAR_FLAGS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STCLEAR_FLAGS
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|BOOLEAN
name|deactivated
decl_stmt|;
name|BOOLEAN
name|disableForceClear
decl_stmt|;
name|BOOLEAN
name|physicalPresence
decl_stmt|;
name|BOOLEAN
name|physicalPresenceLock
decl_stmt|;
name|BOOLEAN
name|bGlobalLock
decl_stmt|;
block|}
name|TPM_STCLEAR_FLAGS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 7.2.1: Flag Restrictions (of TPM_STCLEAR_FLAGS)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_SF_DEACTIVATED
value|((TPM_CAPABILITY_AREA) 1)
end_define

begin_define
define|#
directive|define
name|TPM_SF_DISABLEFORCECLEAR
value|((TPM_CAPABILITY_AREA) 2)
end_define

begin_define
define|#
directive|define
name|TPM_SF_PHYSICALPRESENCE
value|((TPM_CAPABILITY_AREA) 3)
end_define

begin_define
define|#
directive|define
name|TPM_SF_PHYSICALPRESENCELOCK
value|((TPM_CAPABILITY_AREA) 4)
end_define

begin_define
define|#
directive|define
name|TPM_SF_BGLOBALLOCK
value|((TPM_CAPABILITY_AREA) 5)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 7.3: TPM_STANY_FLAGS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STANY_FLAGS
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|BOOLEAN
name|postInitialise
decl_stmt|;
name|TPM_MODIFIER_INDICATOR
name|localityModifier
decl_stmt|;
name|BOOLEAN
name|transportExclusive
decl_stmt|;
name|BOOLEAN
name|TOSPresent
decl_stmt|;
block|}
name|TPM_STANY_FLAGS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 7.3.1: Flag Restrictions (of TPM_STANY_FLAGS)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_AF_POSTINITIALISE
value|((TPM_CAPABILITY_AREA) 1)
end_define

begin_define
define|#
directive|define
name|TPM_AF_LOCALITYMODIFIER
value|((TPM_CAPABILITY_AREA) 2)
end_define

begin_define
define|#
directive|define
name|TPM_AF_TRANSPORTEXCLUSIVE
value|((TPM_CAPABILITY_AREA) 3)
end_define

begin_define
define|#
directive|define
name|TPM_AF_TOSPRESENT
value|((TPM_CAPABILITY_AREA) 4)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// All those structures defined in section 7.4, 7.5, 7.6 are not normative and
end_comment

begin_comment
comment|// thus no definitions here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 7.4: TPM_PERMANENT_DATA
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_MIN_COUNTERS
value|4
end_define

begin_comment
comment|///< the minimum number of counters is 4
end_comment

begin_define
define|#
directive|define
name|TPM_DELEGATE_KEY
value|TPM_KEY
end_define

begin_define
define|#
directive|define
name|TPM_NUM_PCR
value|16
end_define

begin_define
define|#
directive|define
name|TPM_MAX_NV_WRITE_NOOWNER
value|64
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 7.4.1: PERMANENT_DATA Subcap for SetCapability
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_PD_REVMAJOR
value|((TPM_CAPABILITY_AREA) 1)
end_define

begin_define
define|#
directive|define
name|TPM_PD_REVMINOR
value|((TPM_CAPABILITY_AREA) 2)
end_define

begin_define
define|#
directive|define
name|TPM_PD_TPMPROOF
value|((TPM_CAPABILITY_AREA) 3)
end_define

begin_define
define|#
directive|define
name|TPM_PD_OWNERAUTH
value|((TPM_CAPABILITY_AREA) 4)
end_define

begin_define
define|#
directive|define
name|TPM_PD_OPERATORAUTH
value|((TPM_CAPABILITY_AREA) 5)
end_define

begin_define
define|#
directive|define
name|TPM_PD_MANUMAINTPUB
value|((TPM_CAPABILITY_AREA) 6)
end_define

begin_define
define|#
directive|define
name|TPM_PD_ENDORSEMENTKEY
value|((TPM_CAPABILITY_AREA) 7)
end_define

begin_define
define|#
directive|define
name|TPM_PD_SRK
value|((TPM_CAPABILITY_AREA) 8)
end_define

begin_define
define|#
directive|define
name|TPM_PD_DELEGATEKEY
value|((TPM_CAPABILITY_AREA) 9)
end_define

begin_define
define|#
directive|define
name|TPM_PD_CONTEXTKEY
value|((TPM_CAPABILITY_AREA) 10)
end_define

begin_define
define|#
directive|define
name|TPM_PD_AUDITMONOTONICCOUNTER
value|((TPM_CAPABILITY_AREA) 11)
end_define

begin_define
define|#
directive|define
name|TPM_PD_MONOTONICCOUNTER
value|((TPM_CAPABILITY_AREA) 12)
end_define

begin_define
define|#
directive|define
name|TPM_PD_PCRATTRIB
value|((TPM_CAPABILITY_AREA) 13)
end_define

begin_define
define|#
directive|define
name|TPM_PD_ORDINALAUDITSTATUS
value|((TPM_CAPABILITY_AREA) 14)
end_define

begin_define
define|#
directive|define
name|TPM_PD_AUTHDIR
value|((TPM_CAPABILITY_AREA) 15)
end_define

begin_define
define|#
directive|define
name|TPM_PD_RNGSTATE
value|((TPM_CAPABILITY_AREA) 16)
end_define

begin_define
define|#
directive|define
name|TPM_PD_FAMILYTABLE
value|((TPM_CAPABILITY_AREA) 17)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATETABLE
value|((TPM_CAPABILITY_AREA) 18)
end_define

begin_define
define|#
directive|define
name|TPM_PD_EKRESET
value|((TPM_CAPABILITY_AREA) 19)
end_define

begin_define
define|#
directive|define
name|TPM_PD_MAXNVBUFSIZE
value|((TPM_CAPABILITY_AREA) 20)
end_define

begin_define
define|#
directive|define
name|TPM_PD_LASTFAMILYID
value|((TPM_CAPABILITY_AREA) 21)
end_define

begin_define
define|#
directive|define
name|TPM_PD_NOOWNERNVWRITE
value|((TPM_CAPABILITY_AREA) 22)
end_define

begin_define
define|#
directive|define
name|TPM_PD_RESTRICTDELEGATE
value|((TPM_CAPABILITY_AREA) 23)
end_define

begin_define
define|#
directive|define
name|TPM_PD_TPMDAASEED
value|((TPM_CAPABILITY_AREA) 24)
end_define

begin_define
define|#
directive|define
name|TPM_PD_DAAPROOF
value|((TPM_CAPABILITY_AREA) 25)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 7.5: TPM_STCLEAR_DATA
end_comment

begin_comment
comment|///   available inside TPM only
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STCLEAR_DATA
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_NONCE
name|contextNonceKey
decl_stmt|;
name|TPM_COUNT_ID
name|countID
decl_stmt|;
name|UINT32
name|ownerReference
decl_stmt|;
name|BOOLEAN
name|disableResetLock
decl_stmt|;
name|TPM_PCRVALUE
name|PCR
index|[
name|TPM_NUM_PCR
index|]
decl_stmt|;
name|UINT32
name|deferredPhysicalPresence
decl_stmt|;
block|}
name|TPM_STCLEAR_DATA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 7.5.1: STCLEAR_DATA Subcap for SetCapability
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_SD_CONTEXTNONCEKEY
value|((TPM_CAPABILITY_AREA)0x00000001)
end_define

begin_define
define|#
directive|define
name|TPM_SD_COUNTID
value|((TPM_CAPABILITY_AREA)0x00000002)
end_define

begin_define
define|#
directive|define
name|TPM_SD_OWNERREFERENCE
value|((TPM_CAPABILITY_AREA)0x00000003)
end_define

begin_define
define|#
directive|define
name|TPM_SD_DISABLERESETLOCK
value|((TPM_CAPABILITY_AREA)0x00000004)
end_define

begin_define
define|#
directive|define
name|TPM_SD_PCR
value|((TPM_CAPABILITY_AREA)0x00000005)
end_define

begin_define
define|#
directive|define
name|TPM_SD_DEFERREDPHYSICALPRESENCE
value|((TPM_CAPABILITY_AREA)0x00000006)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 7.6.1: STANY_DATA Subcap for SetCapability
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_AD_CONTEXTNONCESESSION
value|((TPM_CAPABILITY_AREA) 1)
end_define

begin_define
define|#
directive|define
name|TPM_AD_AUDITDIGEST
value|((TPM_CAPABILITY_AREA) 2)
end_define

begin_define
define|#
directive|define
name|TPM_AD_CURRENTTICKS
value|((TPM_CAPABILITY_AREA) 3)
end_define

begin_define
define|#
directive|define
name|TPM_AD_CONTEXTCOUNT
value|((TPM_CAPABILITY_AREA) 4)
end_define

begin_define
define|#
directive|define
name|TPM_AD_CONTEXTLIST
value|((TPM_CAPABILITY_AREA) 5)
end_define

begin_define
define|#
directive|define
name|TPM_AD_SESSIONS
value|((TPM_CAPABILITY_AREA) 6)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 8: PCR Structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 8.1: TPM_PCR_SELECTION
end_comment

begin_comment
comment|///   Size of pcrSelect[] indicated by sizeOfSelect
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_PCR_SELECTION
block|{
name|UINT16
name|sizeOfSelect
decl_stmt|;
name|UINT8
name|pcrSelect
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TPM_PCR_SELECTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 8.2: TPM_PCR_COMPOSITE
end_comment

begin_comment
comment|///   Size of pcrValue[] indicated by valueSize
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_PCR_COMPOSITE
block|{
name|TPM_PCR_SELECTION
name|select
decl_stmt|;
name|UINT32
name|valueSize
decl_stmt|;
name|TPM_PCRVALUE
name|pcrValue
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TPM_PCR_COMPOSITE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 8.3: TPM_PCR_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_PCR_INFO
block|{
name|TPM_PCR_SELECTION
name|pcrSelection
decl_stmt|;
name|TPM_COMPOSITE_HASH
name|digestAtRelease
decl_stmt|;
name|TPM_COMPOSITE_HASH
name|digestAtCreation
decl_stmt|;
block|}
name|TPM_PCR_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 8.6: TPM_LOCALITY_SELECTION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|TPM_LOCALITY_SELECTION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_LOC_FOUR
value|((UINT8) 0x10)
end_define

begin_define
define|#
directive|define
name|TPM_LOC_THREE
value|((UINT8) 0x08)
end_define

begin_define
define|#
directive|define
name|TPM_LOC_TWO
value|((UINT8) 0x04)
end_define

begin_define
define|#
directive|define
name|TPM_LOC_ONE
value|((UINT8) 0x02)
end_define

begin_define
define|#
directive|define
name|TPM_LOC_ZERO
value|((UINT8) 0x01)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 8.4: TPM_PCR_INFO_LONG
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_PCR_INFO_LONG
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_LOCALITY_SELECTION
name|localityAtCreation
decl_stmt|;
name|TPM_LOCALITY_SELECTION
name|localityAtRelease
decl_stmt|;
name|TPM_PCR_SELECTION
name|creationPCRSelection
decl_stmt|;
name|TPM_PCR_SELECTION
name|releasePCRSelection
decl_stmt|;
name|TPM_COMPOSITE_HASH
name|digestAtCreation
decl_stmt|;
name|TPM_COMPOSITE_HASH
name|digestAtRelease
decl_stmt|;
block|}
name|TPM_PCR_INFO_LONG
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 8.5: TPM_PCR_INFO_SHORT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_PCR_INFO_SHORT
block|{
name|TPM_PCR_SELECTION
name|pcrSelection
decl_stmt|;
name|TPM_LOCALITY_SELECTION
name|localityAtRelease
decl_stmt|;
name|TPM_COMPOSITE_HASH
name|digestAtRelease
decl_stmt|;
block|}
name|TPM_PCR_INFO_SHORT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 8.8: TPM_PCR_ATTRIBUTES
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_PCR_ATTRIBUTES
block|{
name|BOOLEAN
name|pcrReset
decl_stmt|;
name|TPM_LOCALITY_SELECTION
name|pcrExtendLocal
decl_stmt|;
name|TPM_LOCALITY_SELECTION
name|pcrResetLocal
decl_stmt|;
block|}
name|TPM_PCR_ATTRIBUTES
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 9: Storage Structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 9.1: TPM_STORED_DATA
end_comment

begin_comment
comment|///   [size_is(sealInfoSize)] BYTE* sealInfo;
end_comment

begin_comment
comment|///   [size_is(encDataSize)] BYTE* encData;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STORED_DATA
block|{
name|TPM_STRUCT_VER
name|ver
decl_stmt|;
name|UINT32
name|sealInfoSize
decl_stmt|;
name|UINT8
modifier|*
name|sealInfo
decl_stmt|;
name|UINT32
name|encDataSize
decl_stmt|;
name|UINT8
modifier|*
name|encData
decl_stmt|;
block|}
name|TPM_STORED_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 9.2: TPM_STORED_DATA12
end_comment

begin_comment
comment|///   [size_is(sealInfoSize)] BYTE* sealInfo;
end_comment

begin_comment
comment|///   [size_is(encDataSize)] BYTE* encData;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STORED_DATA12
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_ENTITY_TYPE
name|et
decl_stmt|;
name|UINT32
name|sealInfoSize
decl_stmt|;
name|UINT8
modifier|*
name|sealInfo
decl_stmt|;
name|UINT32
name|encDataSize
decl_stmt|;
name|UINT8
modifier|*
name|encData
decl_stmt|;
block|}
name|TPM_STORED_DATA12
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 9.3: TPM_SEALED_DATA
end_comment

begin_comment
comment|///   [size_is(dataSize)] BYTE* data;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_SEALED_DATA
block|{
name|TPM_PAYLOAD_TYPE
name|payload
decl_stmt|;
name|TPM_SECRET
name|authData
decl_stmt|;
name|TPM_NONCE
name|tpmProof
decl_stmt|;
name|TPM_DIGEST
name|storedDigest
decl_stmt|;
name|UINT32
name|dataSize
decl_stmt|;
name|UINT8
modifier|*
name|data
decl_stmt|;
block|}
name|TPM_SEALED_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 9.4: TPM_SYMMETRIC_KEY
end_comment

begin_comment
comment|///   [size_is(size)] BYTE* data;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_SYMMETRIC_KEY
block|{
name|TPM_ALGORITHM_ID
name|algId
decl_stmt|;
name|TPM_ENC_SCHEME
name|encScheme
decl_stmt|;
name|UINT16
name|dataSize
decl_stmt|;
name|UINT8
modifier|*
name|data
decl_stmt|;
block|}
name|TPM_SYMMETRIC_KEY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 9.5: TPM_BOUND_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_BOUND_DATA
block|{
name|TPM_STRUCT_VER
name|ver
decl_stmt|;
name|TPM_PAYLOAD_TYPE
name|payload
decl_stmt|;
name|UINT8
name|payloadData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TPM_BOUND_DATA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2 section 10: TPM_KEY complex
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Section 10.1, 10.4, and 10.5 have been defined previously
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 10.2: TPM_KEY
end_comment

begin_comment
comment|///   [size_is(encDataSize)] BYTE* encData;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_KEY
block|{
name|TPM_STRUCT_VER
name|ver
decl_stmt|;
name|TPM_KEY_USAGE
name|keyUsage
decl_stmt|;
name|TPM_KEY_FLAGS
name|keyFlags
decl_stmt|;
name|TPM_AUTH_DATA_USAGE
name|authDataUsage
decl_stmt|;
name|TPM_KEY_PARMS
name|algorithmParms
decl_stmt|;
name|UINT32
name|PCRInfoSize
decl_stmt|;
name|UINT8
modifier|*
name|PCRInfo
decl_stmt|;
name|TPM_STORE_PUBKEY
name|pubKey
decl_stmt|;
name|UINT32
name|encDataSize
decl_stmt|;
name|UINT8
modifier|*
name|encData
decl_stmt|;
block|}
name|TPM_KEY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 10.3: TPM_KEY12
end_comment

begin_comment
comment|///   [size_is(encDataSize)] BYTE* encData;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_KEY12
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT16
name|fill
decl_stmt|;
name|TPM_KEY_USAGE
name|keyUsage
decl_stmt|;
name|TPM_KEY_FLAGS
name|keyFlags
decl_stmt|;
name|TPM_AUTH_DATA_USAGE
name|authDataUsage
decl_stmt|;
name|TPM_KEY_PARMS
name|algorithmParms
decl_stmt|;
name|UINT32
name|PCRInfoSize
decl_stmt|;
name|UINT8
modifier|*
name|PCRInfo
decl_stmt|;
name|TPM_STORE_PUBKEY
name|pubKey
decl_stmt|;
name|UINT32
name|encDataSize
decl_stmt|;
name|UINT8
modifier|*
name|encData
decl_stmt|;
block|}
name|TPM_KEY12
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 10.7: TPM_STORE_PRIVKEY
end_comment

begin_comment
comment|///   [size_is(keyLength)] BYTE* key;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STORE_PRIVKEY
block|{
name|UINT32
name|keyLength
decl_stmt|;
name|UINT8
modifier|*
name|key
decl_stmt|;
block|}
name|TPM_STORE_PRIVKEY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 10.6: TPM_STORE_ASYMKEY
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_STORE_ASYMKEY
block|{
comment|// pos len total
name|TPM_PAYLOAD_TYPE
name|payload
decl_stmt|;
comment|// 0    1   1
name|TPM_SECRET
name|usageAuth
decl_stmt|;
comment|// 1    20  21
name|TPM_SECRET
name|migrationAuth
decl_stmt|;
comment|// 21   20  41
name|TPM_DIGEST
name|pubDataDigest
decl_stmt|;
comment|// 41   20  61
name|TPM_STORE_PRIVKEY
name|privKey
decl_stmt|;
comment|// 61 132-151 193-214
block|}
name|TPM_STORE_ASYMKEY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 10.8: TPM_MIGRATE_ASYMKEY
end_comment

begin_comment
comment|///   [size_is(partPrivKeyLen)] BYTE* partPrivKey;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_MIGRATE_ASYMKEY
block|{
comment|// pos  len  total
name|TPM_PAYLOAD_TYPE
name|payload
decl_stmt|;
comment|//   0    1       1
name|TPM_SECRET
name|usageAuth
decl_stmt|;
comment|//   1   20      21
name|TPM_DIGEST
name|pubDataDigest
decl_stmt|;
comment|//  21   20      41
name|UINT32
name|partPrivKeyLen
decl_stmt|;
comment|//  41    4      45
name|UINT8
modifier|*
name|partPrivKey
decl_stmt|;
comment|//  45 112-127 157-172
block|}
name|TPM_MIGRATE_ASYMKEY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 10.9: TPM_KEY_CONTROL
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_CONTROL_OWNER_EVICT
value|((UINT32) 0x00000001)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 11: Signed Structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 11.1: TPM_CERTIFY_INFO Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CERTIFY_INFO
block|{
name|TPM_STRUCT_VER
name|version
decl_stmt|;
name|TPM_KEY_USAGE
name|keyUsage
decl_stmt|;
name|TPM_KEY_FLAGS
name|keyFlags
decl_stmt|;
name|TPM_AUTH_DATA_USAGE
name|authDataUsage
decl_stmt|;
name|TPM_KEY_PARMS
name|algorithmParms
decl_stmt|;
name|TPM_DIGEST
name|pubkeyDigest
decl_stmt|;
name|TPM_NONCE
name|data
decl_stmt|;
name|BOOLEAN
name|parentPCRStatus
decl_stmt|;
name|UINT32
name|PCRInfoSize
decl_stmt|;
name|UINT8
modifier|*
name|PCRInfo
decl_stmt|;
block|}
name|TPM_CERTIFY_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 11.2: TPM_CERTIFY_INFO2 Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CERTIFY_INFO2
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT8
name|fill
decl_stmt|;
name|TPM_PAYLOAD_TYPE
name|payloadType
decl_stmt|;
name|TPM_KEY_USAGE
name|keyUsage
decl_stmt|;
name|TPM_KEY_FLAGS
name|keyFlags
decl_stmt|;
name|TPM_AUTH_DATA_USAGE
name|authDataUsage
decl_stmt|;
name|TPM_KEY_PARMS
name|algorithmParms
decl_stmt|;
name|TPM_DIGEST
name|pubkeyDigest
decl_stmt|;
name|TPM_NONCE
name|data
decl_stmt|;
name|BOOLEAN
name|parentPCRStatus
decl_stmt|;
name|UINT32
name|PCRInfoSize
decl_stmt|;
name|UINT8
modifier|*
name|PCRInfo
decl_stmt|;
name|UINT32
name|migrationAuthoritySize
decl_stmt|;
name|UINT8
modifier|*
name|migrationAuthority
decl_stmt|;
block|}
name|TPM_CERTIFY_INFO2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 11.3 TPM_QUOTE_INFO Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_QUOTE_INFO
block|{
name|TPM_STRUCT_VER
name|version
decl_stmt|;
name|UINT8
name|fixed
index|[
literal|4
index|]
decl_stmt|;
name|TPM_COMPOSITE_HASH
name|digestValue
decl_stmt|;
name|TPM_NONCE
name|externalData
decl_stmt|;
block|}
name|TPM_QUOTE_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 11.4 TPM_QUOTE_INFO2 Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_QUOTE_INFO2
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT8
name|fixed
index|[
literal|4
index|]
decl_stmt|;
name|TPM_NONCE
name|externalData
decl_stmt|;
name|TPM_PCR_INFO_SHORT
name|infoShort
decl_stmt|;
block|}
name|TPM_QUOTE_INFO2
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 12: Identity Structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 12.1 TPM_EK_BLOB
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_EK_BLOB
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_EK_TYPE
name|ekType
decl_stmt|;
name|UINT32
name|blobSize
decl_stmt|;
name|UINT8
modifier|*
name|blob
decl_stmt|;
block|}
name|TPM_EK_BLOB
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 12.2 TPM_EK_BLOB_ACTIVATE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_EK_BLOB_ACTIVATE
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_SYMMETRIC_KEY
name|sessionKey
decl_stmt|;
name|TPM_DIGEST
name|idDigest
decl_stmt|;
name|TPM_PCR_INFO_SHORT
name|pcrInfo
decl_stmt|;
block|}
name|TPM_EK_BLOB_ACTIVATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 12.3 TPM_EK_BLOB_AUTH
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_EK_BLOB_AUTH
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_SECRET
name|authValue
decl_stmt|;
block|}
name|TPM_EK_BLOB_AUTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 12.5 TPM_IDENTITY_CONTENTS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_IDENTITY_CONTENTS
block|{
name|TPM_STRUCT_VER
name|ver
decl_stmt|;
name|UINT32
name|ordinal
decl_stmt|;
name|TPM_CHOSENID_HASH
name|labelPrivCADigest
decl_stmt|;
name|TPM_PUBKEY
name|identityPubKey
decl_stmt|;
block|}
name|TPM_IDENTITY_CONTENTS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 12.6 TPM_IDENTITY_REQ
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_IDENTITY_REQ
block|{
name|UINT32
name|asymSize
decl_stmt|;
name|UINT32
name|symSize
decl_stmt|;
name|TPM_KEY_PARMS
name|asymAlgorithm
decl_stmt|;
name|TPM_KEY_PARMS
name|symAlgorithm
decl_stmt|;
name|UINT8
modifier|*
name|asymBlob
decl_stmt|;
name|UINT8
modifier|*
name|symBlob
decl_stmt|;
block|}
name|TPM_IDENTITY_REQ
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 12.7 TPM_IDENTITY_PROOF
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_IDENTITY_PROOF
block|{
name|TPM_STRUCT_VER
name|ver
decl_stmt|;
name|UINT32
name|labelSize
decl_stmt|;
name|UINT32
name|identityBindingSize
decl_stmt|;
name|UINT32
name|endorsementSize
decl_stmt|;
name|UINT32
name|platformSize
decl_stmt|;
name|UINT32
name|conformanceSize
decl_stmt|;
name|TPM_PUBKEY
name|identityKey
decl_stmt|;
name|UINT8
modifier|*
name|labelArea
decl_stmt|;
name|UINT8
modifier|*
name|identityBinding
decl_stmt|;
name|UINT8
modifier|*
name|endorsementCredential
decl_stmt|;
name|UINT8
modifier|*
name|platformCredential
decl_stmt|;
name|UINT8
modifier|*
name|conformanceCredential
decl_stmt|;
block|}
name|TPM_IDENTITY_PROOF
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 12.8 TPM_ASYM_CA_CONTENTS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_ASYM_CA_CONTENTS
block|{
name|TPM_SYMMETRIC_KEY
name|sessionKey
decl_stmt|;
name|TPM_DIGEST
name|idDigest
decl_stmt|;
block|}
name|TPM_ASYM_CA_CONTENTS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 12.9 TPM_SYM_CA_ATTESTATION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_SYM_CA_ATTESTATION
block|{
name|UINT32
name|credSize
decl_stmt|;
name|TPM_KEY_PARMS
name|algorithm
decl_stmt|;
name|UINT8
modifier|*
name|credential
decl_stmt|;
block|}
name|TPM_SYM_CA_ATTESTATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 15: Tick Structures
end_comment

begin_comment
comment|///   Placed here out of order because definitions are used in section 13.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CURRENT_TICKS
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT64
name|currentTicks
decl_stmt|;
name|UINT16
name|tickRate
decl_stmt|;
name|TPM_NONCE
name|tickNonce
decl_stmt|;
block|}
name|TPM_CURRENT_TICKS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 13: Transport structures
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 13.1: TPM _TRANSPORT_PUBLIC
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_TRANSPORT_PUBLIC
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_TRANSPORT_ATTRIBUTES
name|transAttributes
decl_stmt|;
name|TPM_ALGORITHM_ID
name|algId
decl_stmt|;
name|TPM_ENC_SCHEME
name|encScheme
decl_stmt|;
block|}
name|TPM_TRANSPORT_PUBLIC
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 13.1.1 TPM_TRANSPORT_ATTRIBUTES Definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_TRANSPORT_ENCRYPT
value|((UINT32)BIT0)
end_define

begin_define
define|#
directive|define
name|TPM_TRANSPORT_LOG
value|((UINT32)BIT1)
end_define

begin_define
define|#
directive|define
name|TPM_TRANSPORT_EXCLUSIVE
value|((UINT32)BIT2)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 13.2 TPM_TRANSPORT_INTERNAL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_TRANSPORT_INTERNAL
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_AUTHDATA
name|authData
decl_stmt|;
name|TPM_TRANSPORT_PUBLIC
name|transPublic
decl_stmt|;
name|TPM_TRANSHANDLE
name|transHandle
decl_stmt|;
name|TPM_NONCE
name|transNonceEven
decl_stmt|;
name|TPM_DIGEST
name|transDigest
decl_stmt|;
block|}
name|TPM_TRANSPORT_INTERNAL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 13.3 TPM_TRANSPORT_LOG_IN structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_TRANSPORT_LOG_IN
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DIGEST
name|parameters
decl_stmt|;
name|TPM_DIGEST
name|pubKeyHash
decl_stmt|;
block|}
name|TPM_TRANSPORT_LOG_IN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 13.4 TPM_TRANSPORT_LOG_OUT structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_TRANSPORT_LOG_OUT
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_CURRENT_TICKS
name|currentTicks
decl_stmt|;
name|TPM_DIGEST
name|parameters
decl_stmt|;
name|TPM_MODIFIER_INDICATOR
name|locality
decl_stmt|;
block|}
name|TPM_TRANSPORT_LOG_OUT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 13.5 TPM_TRANSPORT_AUTH structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_TRANSPORT_AUTH
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_AUTHDATA
name|authData
decl_stmt|;
block|}
name|TPM_TRANSPORT_AUTH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 14: Audit Structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 14.1 TPM_AUDIT_EVENT_IN structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_AUDIT_EVENT_IN
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DIGEST
name|inputParms
decl_stmt|;
name|TPM_COUNTER_VALUE
name|auditCount
decl_stmt|;
block|}
name|TPM_AUDIT_EVENT_IN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 14.2 TPM_AUDIT_EVENT_OUT structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_AUDIT_EVENT_OUT
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_COMMAND_CODE
name|ordinal
decl_stmt|;
name|TPM_DIGEST
name|outputParms
decl_stmt|;
name|TPM_COUNTER_VALUE
name|auditCount
decl_stmt|;
name|TPM_RESULT
name|returnCode
decl_stmt|;
block|}
name|TPM_AUDIT_EVENT_OUT
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 16: Return Codes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_VENDOR_ERROR
value|TPM_Vendor_Specific32
end_define

begin_define
define|#
directive|define
name|TPM_NON_FATAL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TPM_SUCCESS
value|((TPM_RESULT) TPM_BASE)
end_define

begin_define
define|#
directive|define
name|TPM_AUTHFAIL
value|((TPM_RESULT) (TPM_BASE + 1))
end_define

begin_define
define|#
directive|define
name|TPM_BADINDEX
value|((TPM_RESULT) (TPM_BASE + 2))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_PARAMETER
value|((TPM_RESULT) (TPM_BASE + 3))
end_define

begin_define
define|#
directive|define
name|TPM_AUDITFAILURE
value|((TPM_RESULT) (TPM_BASE + 4))
end_define

begin_define
define|#
directive|define
name|TPM_CLEAR_DISABLED
value|((TPM_RESULT) (TPM_BASE + 5))
end_define

begin_define
define|#
directive|define
name|TPM_DEACTIVATED
value|((TPM_RESULT) (TPM_BASE + 6))
end_define

begin_define
define|#
directive|define
name|TPM_DISABLED
value|((TPM_RESULT) (TPM_BASE + 7))
end_define

begin_define
define|#
directive|define
name|TPM_DISABLED_CMD
value|((TPM_RESULT) (TPM_BASE + 8))
end_define

begin_define
define|#
directive|define
name|TPM_FAIL
value|((TPM_RESULT) (TPM_BASE + 9))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_ORDINAL
value|((TPM_RESULT) (TPM_BASE + 10))
end_define

begin_define
define|#
directive|define
name|TPM_INSTALL_DISABLED
value|((TPM_RESULT) (TPM_BASE + 11))
end_define

begin_define
define|#
directive|define
name|TPM_INVALID_KEYHANDLE
value|((TPM_RESULT) (TPM_BASE + 12))
end_define

begin_define
define|#
directive|define
name|TPM_KEYNOTFOUND
value|((TPM_RESULT) (TPM_BASE + 13))
end_define

begin_define
define|#
directive|define
name|TPM_INAPPROPRIATE_ENC
value|((TPM_RESULT) (TPM_BASE + 14))
end_define

begin_define
define|#
directive|define
name|TPM_MIGRATEFAIL
value|((TPM_RESULT) (TPM_BASE + 15))
end_define

begin_define
define|#
directive|define
name|TPM_INVALID_PCR_INFO
value|((TPM_RESULT) (TPM_BASE + 16))
end_define

begin_define
define|#
directive|define
name|TPM_NOSPACE
value|((TPM_RESULT) (TPM_BASE + 17))
end_define

begin_define
define|#
directive|define
name|TPM_NOSRK
value|((TPM_RESULT) (TPM_BASE + 18))
end_define

begin_define
define|#
directive|define
name|TPM_NOTSEALED_BLOB
value|((TPM_RESULT) (TPM_BASE + 19))
end_define

begin_define
define|#
directive|define
name|TPM_OWNER_SET
value|((TPM_RESULT) (TPM_BASE + 20))
end_define

begin_define
define|#
directive|define
name|TPM_RESOURCES
value|((TPM_RESULT) (TPM_BASE + 21))
end_define

begin_define
define|#
directive|define
name|TPM_SHORTRANDOM
value|((TPM_RESULT) (TPM_BASE + 22))
end_define

begin_define
define|#
directive|define
name|TPM_SIZE
value|((TPM_RESULT) (TPM_BASE + 23))
end_define

begin_define
define|#
directive|define
name|TPM_WRONGPCRVAL
value|((TPM_RESULT) (TPM_BASE + 24))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_PARAM_SIZE
value|((TPM_RESULT) (TPM_BASE + 25))
end_define

begin_define
define|#
directive|define
name|TPM_SHA_THREAD
value|((TPM_RESULT) (TPM_BASE + 26))
end_define

begin_define
define|#
directive|define
name|TPM_SHA_ERROR
value|((TPM_RESULT) (TPM_BASE + 27))
end_define

begin_define
define|#
directive|define
name|TPM_FAILEDSELFTEST
value|((TPM_RESULT) (TPM_BASE + 28))
end_define

begin_define
define|#
directive|define
name|TPM_AUTH2FAIL
value|((TPM_RESULT) (TPM_BASE + 29))
end_define

begin_define
define|#
directive|define
name|TPM_BADTAG
value|((TPM_RESULT) (TPM_BASE + 30))
end_define

begin_define
define|#
directive|define
name|TPM_IOERROR
value|((TPM_RESULT) (TPM_BASE + 31))
end_define

begin_define
define|#
directive|define
name|TPM_ENCRYPT_ERROR
value|((TPM_RESULT) (TPM_BASE + 32))
end_define

begin_define
define|#
directive|define
name|TPM_DECRYPT_ERROR
value|((TPM_RESULT) (TPM_BASE + 33))
end_define

begin_define
define|#
directive|define
name|TPM_INVALID_AUTHHANDLE
value|((TPM_RESULT) (TPM_BASE + 34))
end_define

begin_define
define|#
directive|define
name|TPM_NO_ENDORSEMENT
value|((TPM_RESULT) (TPM_BASE + 35))
end_define

begin_define
define|#
directive|define
name|TPM_INVALID_KEYUSAGE
value|((TPM_RESULT) (TPM_BASE + 36))
end_define

begin_define
define|#
directive|define
name|TPM_WRONG_ENTITYTYPE
value|((TPM_RESULT) (TPM_BASE + 37))
end_define

begin_define
define|#
directive|define
name|TPM_INVALID_POSTINIT
value|((TPM_RESULT) (TPM_BASE + 38))
end_define

begin_define
define|#
directive|define
name|TPM_INAPPROPRIATE_SIG
value|((TPM_RESULT) (TPM_BASE + 39))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_KEY_PROPERTY
value|((TPM_RESULT) (TPM_BASE + 40))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_MIGRATION
value|((TPM_RESULT) (TPM_BASE + 41))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_SCHEME
value|((TPM_RESULT) (TPM_BASE + 42))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_DATASIZE
value|((TPM_RESULT) (TPM_BASE + 43))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_MODE
value|((TPM_RESULT) (TPM_BASE + 44))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_PRESENCE
value|((TPM_RESULT) (TPM_BASE + 45))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_VERSION
value|((TPM_RESULT) (TPM_BASE + 46))
end_define

begin_define
define|#
directive|define
name|TPM_NO_WRAP_TRANSPORT
value|((TPM_RESULT) (TPM_BASE + 47))
end_define

begin_define
define|#
directive|define
name|TPM_AUDITFAIL_UNSUCCESSFUL
value|((TPM_RESULT) (TPM_BASE + 48))
end_define

begin_define
define|#
directive|define
name|TPM_AUDITFAIL_SUCCESSFUL
value|((TPM_RESULT) (TPM_BASE + 49))
end_define

begin_define
define|#
directive|define
name|TPM_NOTRESETABLE
value|((TPM_RESULT) (TPM_BASE + 50))
end_define

begin_define
define|#
directive|define
name|TPM_NOTLOCAL
value|((TPM_RESULT) (TPM_BASE + 51))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_TYPE
value|((TPM_RESULT) (TPM_BASE + 52))
end_define

begin_define
define|#
directive|define
name|TPM_INVALID_RESOURCE
value|((TPM_RESULT) (TPM_BASE + 53))
end_define

begin_define
define|#
directive|define
name|TPM_NOTFIPS
value|((TPM_RESULT) (TPM_BASE + 54))
end_define

begin_define
define|#
directive|define
name|TPM_INVALID_FAMILY
value|((TPM_RESULT) (TPM_BASE + 55))
end_define

begin_define
define|#
directive|define
name|TPM_NO_NV_PERMISSION
value|((TPM_RESULT) (TPM_BASE + 56))
end_define

begin_define
define|#
directive|define
name|TPM_REQUIRES_SIGN
value|((TPM_RESULT) (TPM_BASE + 57))
end_define

begin_define
define|#
directive|define
name|TPM_KEY_NOTSUPPORTED
value|((TPM_RESULT) (TPM_BASE + 58))
end_define

begin_define
define|#
directive|define
name|TPM_AUTH_CONFLICT
value|((TPM_RESULT) (TPM_BASE + 59))
end_define

begin_define
define|#
directive|define
name|TPM_AREA_LOCKED
value|((TPM_RESULT) (TPM_BASE + 60))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_LOCALITY
value|((TPM_RESULT) (TPM_BASE + 61))
end_define

begin_define
define|#
directive|define
name|TPM_READ_ONLY
value|((TPM_RESULT) (TPM_BASE + 62))
end_define

begin_define
define|#
directive|define
name|TPM_PER_NOWRITE
value|((TPM_RESULT) (TPM_BASE + 63))
end_define

begin_define
define|#
directive|define
name|TPM_FAMILYCOUNT
value|((TPM_RESULT) (TPM_BASE + 64))
end_define

begin_define
define|#
directive|define
name|TPM_WRITE_LOCKED
value|((TPM_RESULT) (TPM_BASE + 65))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_ATTRIBUTES
value|((TPM_RESULT) (TPM_BASE + 66))
end_define

begin_define
define|#
directive|define
name|TPM_INVALID_STRUCTURE
value|((TPM_RESULT) (TPM_BASE + 67))
end_define

begin_define
define|#
directive|define
name|TPM_KEY_OWNER_CONTROL
value|((TPM_RESULT) (TPM_BASE + 68))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_COUNTER
value|((TPM_RESULT) (TPM_BASE + 69))
end_define

begin_define
define|#
directive|define
name|TPM_NOT_FULLWRITE
value|((TPM_RESULT) (TPM_BASE + 70))
end_define

begin_define
define|#
directive|define
name|TPM_CONTEXT_GAP
value|((TPM_RESULT) (TPM_BASE + 71))
end_define

begin_define
define|#
directive|define
name|TPM_MAXNVWRITES
value|((TPM_RESULT) (TPM_BASE + 72))
end_define

begin_define
define|#
directive|define
name|TPM_NOOPERATOR
value|((TPM_RESULT) (TPM_BASE + 73))
end_define

begin_define
define|#
directive|define
name|TPM_RESOURCEMISSING
value|((TPM_RESULT) (TPM_BASE + 74))
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_LOCK
value|((TPM_RESULT) (TPM_BASE + 75))
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_FAMILY
value|((TPM_RESULT) (TPM_BASE + 76))
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_ADMIN
value|((TPM_RESULT) (TPM_BASE + 77))
end_define

begin_define
define|#
directive|define
name|TPM_TRANSPORT_NOTEXCLUSIVE
value|((TPM_RESULT) (TPM_BASE + 78))
end_define

begin_define
define|#
directive|define
name|TPM_OWNER_CONTROL
value|((TPM_RESULT) (TPM_BASE + 79))
end_define

begin_define
define|#
directive|define
name|TPM_DAA_RESOURCES
value|((TPM_RESULT) (TPM_BASE + 80))
end_define

begin_define
define|#
directive|define
name|TPM_DAA_INPUT_DATA0
value|((TPM_RESULT) (TPM_BASE + 81))
end_define

begin_define
define|#
directive|define
name|TPM_DAA_INPUT_DATA1
value|((TPM_RESULT) (TPM_BASE + 82))
end_define

begin_define
define|#
directive|define
name|TPM_DAA_ISSUER_SETTINGS
value|((TPM_RESULT) (TPM_BASE + 83))
end_define

begin_define
define|#
directive|define
name|TPM_DAA_TPM_SETTINGS
value|((TPM_RESULT) (TPM_BASE + 84))
end_define

begin_define
define|#
directive|define
name|TPM_DAA_STAGE
value|((TPM_RESULT) (TPM_BASE + 85))
end_define

begin_define
define|#
directive|define
name|TPM_DAA_ISSUER_VALIDITY
value|((TPM_RESULT) (TPM_BASE + 86))
end_define

begin_define
define|#
directive|define
name|TPM_DAA_WRONG_W
value|((TPM_RESULT) (TPM_BASE + 87))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_HANDLE
value|((TPM_RESULT) (TPM_BASE + 88))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_DELEGATE
value|((TPM_RESULT) (TPM_BASE + 89))
end_define

begin_define
define|#
directive|define
name|TPM_BADCONTEXT
value|((TPM_RESULT) (TPM_BASE + 90))
end_define

begin_define
define|#
directive|define
name|TPM_TOOMANYCONTEXTS
value|((TPM_RESULT) (TPM_BASE + 91))
end_define

begin_define
define|#
directive|define
name|TPM_MA_TICKET_SIGNATURE
value|((TPM_RESULT) (TPM_BASE + 92))
end_define

begin_define
define|#
directive|define
name|TPM_MA_DESTINATION
value|((TPM_RESULT) (TPM_BASE + 93))
end_define

begin_define
define|#
directive|define
name|TPM_MA_SOURCE
value|((TPM_RESULT) (TPM_BASE + 94))
end_define

begin_define
define|#
directive|define
name|TPM_MA_AUTHORITY
value|((TPM_RESULT) (TPM_BASE + 95))
end_define

begin_define
define|#
directive|define
name|TPM_PERMANENTEK
value|((TPM_RESULT) (TPM_BASE + 97))
end_define

begin_define
define|#
directive|define
name|TPM_BAD_SIGNATURE
value|((TPM_RESULT) (TPM_BASE + 98))
end_define

begin_define
define|#
directive|define
name|TPM_NOCONTEXTSPACE
value|((TPM_RESULT) (TPM_BASE + 99))
end_define

begin_define
define|#
directive|define
name|TPM_RETRY
value|((TPM_RESULT) (TPM_BASE + TPM_NON_FATAL))
end_define

begin_define
define|#
directive|define
name|TPM_NEEDS_SELFTEST
value|((TPM_RESULT) (TPM_BASE + TPM_NON_FATAL + 1))
end_define

begin_define
define|#
directive|define
name|TPM_DOING_SELFTEST
value|((TPM_RESULT) (TPM_BASE + TPM_NON_FATAL + 2))
end_define

begin_define
define|#
directive|define
name|TPM_DEFEND_LOCK_RUNNING
value|((TPM_RESULT) (TPM_BASE + TPM_NON_FATAL + 3))
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 17: Ordinals
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ordinals are 32 bit values. The upper byte contains values that serve as
end_comment

begin_comment
comment|// flag indicators, the next byte contains values indicating what committee
end_comment

begin_comment
comment|// designated the ordinal, and the final two bytes contain the Command
end_comment

begin_comment
comment|// Ordinal Index.
end_comment

begin_comment
comment|//      3                   2                   1
end_comment

begin_comment
comment|//    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
end_comment

begin_comment
comment|//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
end_comment

begin_comment
comment|//   |P|C|V| Reserved| Purview |     Command Ordinal Index           |
end_comment

begin_comment
comment|//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Where:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * P is Protected/Unprotected command. When 0 the command is a Protected
end_comment

begin_comment
comment|//      command, when 1 the command is an Unprotected command.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * C is Non-Connection/Connection related command. When 0 this command
end_comment

begin_comment
comment|//      passes through to either the protected (TPM) or unprotected (TSS)
end_comment

begin_comment
comment|//      components.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * V is TPM/Vendor command. When 0 the command is TPM defined, when 1 the
end_comment

begin_comment
comment|//      command is vendor defined.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * All reserved area bits are set to 0.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_ORD_ActivateIdentity
value|((TPM_COMMAND_CODE) 0x0000007A)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_AuthorizeMigrationKey
value|((TPM_COMMAND_CODE) 0x0000002B)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CertifyKey
value|((TPM_COMMAND_CODE) 0x00000032)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CertifyKey2
value|((TPM_COMMAND_CODE) 0x00000033)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CertifySelfTest
value|((TPM_COMMAND_CODE) 0x00000052)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ChangeAuth
value|((TPM_COMMAND_CODE) 0x0000000C)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ChangeAuthAsymFinish
value|((TPM_COMMAND_CODE) 0x0000000F)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ChangeAuthAsymStart
value|((TPM_COMMAND_CODE) 0x0000000E)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ChangeAuthOwner
value|((TPM_COMMAND_CODE) 0x00000010)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CMK_ApproveMA
value|((TPM_COMMAND_CODE) 0x0000001D)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CMK_ConvertMigration
value|((TPM_COMMAND_CODE) 0x00000024)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CMK_CreateBlob
value|((TPM_COMMAND_CODE) 0x0000001B)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CMK_CreateKey
value|((TPM_COMMAND_CODE) 0x00000013)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CMK_CreateTicket
value|((TPM_COMMAND_CODE) 0x00000012)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CMK_SetRestrictions
value|((TPM_COMMAND_CODE) 0x0000001C)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ContinueSelfTest
value|((TPM_COMMAND_CODE) 0x00000053)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ConvertMigrationBlob
value|((TPM_COMMAND_CODE) 0x0000002A)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CreateCounter
value|((TPM_COMMAND_CODE) 0x000000DC)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CreateEndorsementKeyPair
value|((TPM_COMMAND_CODE) 0x00000078)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CreateMaintenanceArchive
value|((TPM_COMMAND_CODE) 0x0000002C)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CreateMigrationBlob
value|((TPM_COMMAND_CODE) 0x00000028)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CreateRevocableEK
value|((TPM_COMMAND_CODE) 0x0000007F)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_CreateWrapKey
value|((TPM_COMMAND_CODE) 0x0000001F)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_DAA_JOIN
value|((TPM_COMMAND_CODE) 0x00000029)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_DAA_SIGN
value|((TPM_COMMAND_CODE) 0x00000031)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Delegate_CreateKeyDelegation
value|((TPM_COMMAND_CODE) 0x000000D4)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Delegate_CreateOwnerDelegation
value|((TPM_COMMAND_CODE) 0x000000D5)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Delegate_LoadOwnerDelegation
value|((TPM_COMMAND_CODE) 0x000000D8)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Delegate_Manage
value|((TPM_COMMAND_CODE) 0x000000D2)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Delegate_ReadTable
value|((TPM_COMMAND_CODE) 0x000000DB)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Delegate_UpdateVerification
value|((TPM_COMMAND_CODE) 0x000000D1)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Delegate_VerifyDelegation
value|((TPM_COMMAND_CODE) 0x000000D6)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_DirRead
value|((TPM_COMMAND_CODE) 0x0000001A)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_DirWriteAuth
value|((TPM_COMMAND_CODE) 0x00000019)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_DisableForceClear
value|((TPM_COMMAND_CODE) 0x0000005E)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_DisableOwnerClear
value|((TPM_COMMAND_CODE) 0x0000005C)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_DisablePubekRead
value|((TPM_COMMAND_CODE) 0x0000007E)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_DSAP
value|((TPM_COMMAND_CODE) 0x00000011)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_EstablishTransport
value|((TPM_COMMAND_CODE) 0x000000E6)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_EvictKey
value|((TPM_COMMAND_CODE) 0x00000022)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ExecuteTransport
value|((TPM_COMMAND_CODE) 0x000000E7)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Extend
value|((TPM_COMMAND_CODE) 0x00000014)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_FieldUpgrade
value|((TPM_COMMAND_CODE) 0x000000AA)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_FlushSpecific
value|((TPM_COMMAND_CODE) 0x000000BA)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ForceClear
value|((TPM_COMMAND_CODE) 0x0000005D)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetAuditDigest
value|((TPM_COMMAND_CODE) 0x00000085)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetAuditDigestSigned
value|((TPM_COMMAND_CODE) 0x00000086)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetAuditEvent
value|((TPM_COMMAND_CODE) 0x00000082)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetAuditEventSigned
value|((TPM_COMMAND_CODE) 0x00000083)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetCapability
value|((TPM_COMMAND_CODE) 0x00000065)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetCapabilityOwner
value|((TPM_COMMAND_CODE) 0x00000066)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetCapabilitySigned
value|((TPM_COMMAND_CODE) 0x00000064)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetOrdinalAuditStatus
value|((TPM_COMMAND_CODE) 0x0000008C)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetPubKey
value|((TPM_COMMAND_CODE) 0x00000021)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetRandom
value|((TPM_COMMAND_CODE) 0x00000046)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetTestResult
value|((TPM_COMMAND_CODE) 0x00000054)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_GetTicks
value|((TPM_COMMAND_CODE) 0x000000F1)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_IncrementCounter
value|((TPM_COMMAND_CODE) 0x000000DD)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Init
value|((TPM_COMMAND_CODE) 0x00000097)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_KeyControlOwner
value|((TPM_COMMAND_CODE) 0x00000023)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_KillMaintenanceFeature
value|((TPM_COMMAND_CODE) 0x0000002E)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_LoadAuthContext
value|((TPM_COMMAND_CODE) 0x000000B7)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_LoadContext
value|((TPM_COMMAND_CODE) 0x000000B9)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_LoadKey
value|((TPM_COMMAND_CODE) 0x00000020)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_LoadKey2
value|((TPM_COMMAND_CODE) 0x00000041)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_LoadKeyContext
value|((TPM_COMMAND_CODE) 0x000000B5)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_LoadMaintenanceArchive
value|((TPM_COMMAND_CODE) 0x0000002D)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_LoadManuMaintPub
value|((TPM_COMMAND_CODE) 0x0000002F)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_MakeIdentity
value|((TPM_COMMAND_CODE) 0x00000079)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_MigrateKey
value|((TPM_COMMAND_CODE) 0x00000025)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_NV_DefineSpace
value|((TPM_COMMAND_CODE) 0x000000CC)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_NV_ReadValue
value|((TPM_COMMAND_CODE) 0x000000CF)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_NV_ReadValueAuth
value|((TPM_COMMAND_CODE) 0x000000D0)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_NV_WriteValue
value|((TPM_COMMAND_CODE) 0x000000CD)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_NV_WriteValueAuth
value|((TPM_COMMAND_CODE) 0x000000CE)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_OIAP
value|((TPM_COMMAND_CODE) 0x0000000A)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_OSAP
value|((TPM_COMMAND_CODE) 0x0000000B)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_OwnerClear
value|((TPM_COMMAND_CODE) 0x0000005B)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_OwnerReadInternalPub
value|((TPM_COMMAND_CODE) 0x00000081)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_OwnerReadPubek
value|((TPM_COMMAND_CODE) 0x0000007D)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_OwnerSetDisable
value|((TPM_COMMAND_CODE) 0x0000006E)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_PCR_Reset
value|((TPM_COMMAND_CODE) 0x000000C8)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_PcrRead
value|((TPM_COMMAND_CODE) 0x00000015)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_PhysicalDisable
value|((TPM_COMMAND_CODE) 0x00000070)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_PhysicalEnable
value|((TPM_COMMAND_CODE) 0x0000006F)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_PhysicalSetDeactivated
value|((TPM_COMMAND_CODE) 0x00000072)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Quote
value|((TPM_COMMAND_CODE) 0x00000016)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Quote2
value|((TPM_COMMAND_CODE) 0x0000003E)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ReadCounter
value|((TPM_COMMAND_CODE) 0x000000DE)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ReadManuMaintPub
value|((TPM_COMMAND_CODE) 0x00000030)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ReadPubek
value|((TPM_COMMAND_CODE) 0x0000007C)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ReleaseCounter
value|((TPM_COMMAND_CODE) 0x000000DF)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ReleaseCounterOwner
value|((TPM_COMMAND_CODE) 0x000000E0)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ReleaseTransportSigned
value|((TPM_COMMAND_CODE) 0x000000E8)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Reset
value|((TPM_COMMAND_CODE) 0x0000005A)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_ResetLockValue
value|((TPM_COMMAND_CODE) 0x00000040)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_RevokeTrust
value|((TPM_COMMAND_CODE) 0x00000080)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SaveAuthContext
value|((TPM_COMMAND_CODE) 0x000000B6)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SaveContext
value|((TPM_COMMAND_CODE) 0x000000B8)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SaveKeyContext
value|((TPM_COMMAND_CODE) 0x000000B4)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SaveState
value|((TPM_COMMAND_CODE) 0x00000098)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Seal
value|((TPM_COMMAND_CODE) 0x00000017)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Sealx
value|((TPM_COMMAND_CODE) 0x0000003D)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SelfTestFull
value|((TPM_COMMAND_CODE) 0x00000050)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SetCapability
value|((TPM_COMMAND_CODE) 0x0000003F)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SetOperatorAuth
value|((TPM_COMMAND_CODE) 0x00000074)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SetOrdinalAuditStatus
value|((TPM_COMMAND_CODE) 0x0000008D)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SetOwnerInstall
value|((TPM_COMMAND_CODE) 0x00000071)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SetOwnerPointer
value|((TPM_COMMAND_CODE) 0x00000075)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SetRedirection
value|((TPM_COMMAND_CODE) 0x0000009A)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SetTempDeactivated
value|((TPM_COMMAND_CODE) 0x00000073)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SHA1Complete
value|((TPM_COMMAND_CODE) 0x000000A2)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SHA1CompleteExtend
value|((TPM_COMMAND_CODE) 0x000000A3)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SHA1Start
value|((TPM_COMMAND_CODE) 0x000000A0)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_SHA1Update
value|((TPM_COMMAND_CODE) 0x000000A1)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Sign
value|((TPM_COMMAND_CODE) 0x0000003C)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Startup
value|((TPM_COMMAND_CODE) 0x00000099)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_StirRandom
value|((TPM_COMMAND_CODE) 0x00000047)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_TakeOwnership
value|((TPM_COMMAND_CODE) 0x0000000D)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Terminate_Handle
value|((TPM_COMMAND_CODE) 0x00000096)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_TickStampBlob
value|((TPM_COMMAND_CODE) 0x000000F2)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_UnBind
value|((TPM_COMMAND_CODE) 0x0000001E)
end_define

begin_define
define|#
directive|define
name|TPM_ORD_Unseal
value|((TPM_COMMAND_CODE) 0x00000018)
end_define

begin_define
define|#
directive|define
name|TSC_ORD_PhysicalPresence
value|((TPM_COMMAND_CODE) 0x4000000A)
end_define

begin_define
define|#
directive|define
name|TSC_ORD_ResetEstablishmentBit
value|((TPM_COMMAND_CODE) 0x4000000B)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 18: Context structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 18.1: TPM_CONTEXT_BLOB
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CONTEXT_BLOB
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_RESOURCE_TYPE
name|resourceType
decl_stmt|;
name|TPM_HANDLE
name|handle
decl_stmt|;
name|UINT8
name|label
index|[
literal|16
index|]
decl_stmt|;
name|UINT32
name|contextCount
decl_stmt|;
name|TPM_DIGEST
name|integrityDigest
decl_stmt|;
name|UINT32
name|additionalSize
decl_stmt|;
name|UINT8
modifier|*
name|additionalData
decl_stmt|;
name|UINT32
name|sensitiveSize
decl_stmt|;
name|UINT8
modifier|*
name|sensitiveData
decl_stmt|;
block|}
name|TPM_CONTEXT_BLOB
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 18.2 TPM_CONTEXT_SENSITIVE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CONTEXT_SENSITIVE
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_NONCE
name|contextNonce
decl_stmt|;
name|UINT32
name|internalSize
decl_stmt|;
name|UINT8
modifier|*
name|internalData
decl_stmt|;
block|}
name|TPM_CONTEXT_SENSITIVE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 19: NV Structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 19.1.1: Required TPM_NV_INDEX values
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_NV_INDEX_LOCK
value|((UINT32)0xffffffff)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX0
value|((UINT32)0x00000000)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_DIR
value|((UINT32)0x10000001)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_EKCert
value|((UINT32)0x0000f000)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_TPM_CC
value|((UINT32)0x0000f001)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_PlatformCert
value|((UINT32)0x0000f002)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_Platform_CC
value|((UINT32)0x0000f003)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 19.1.2: Reserved Index values
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_NV_INDEX_TSS_BASE
value|((UINT32)0x00011100)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_PC_BASE
value|((UINT32)0x00011200)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_SERVER_BASE
value|((UINT32)0x00011300)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_MOBILE_BASE
value|((UINT32)0x00011400)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_PERIPHERAL_BASE
value|((UINT32)0x00011500)
end_define

begin_define
define|#
directive|define
name|TPM_NV_INDEX_GROUP_RESV_BASE
value|((UINT32)0x00010000)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 19.2: TPM_NV_ATTRIBUTES
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_NV_ATTRIBUTES
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT32
name|attributes
decl_stmt|;
block|}
name|TPM_NV_ATTRIBUTES
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_NV_PER_READ_STCLEAR
value|(BIT31)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_AUTHREAD
value|(BIT18)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_OWNERREAD
value|(BIT17)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_PPREAD
value|(BIT16)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_GLOBALLOCK
value|(BIT15)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_WRITE_STCLEAR
value|(BIT14)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_WRITEDEFINE
value|(BIT13)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_WRITEALL
value|(BIT12)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_AUTHWRITE
value|(BIT2)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_OWNERWRITE
value|(BIT1)
end_define

begin_define
define|#
directive|define
name|TPM_NV_PER_PPWRITE
value|(BIT0)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 19.3: TPM_NV_DATA_PUBLIC
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_NV_DATA_PUBLIC
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_NV_INDEX
name|nvIndex
decl_stmt|;
name|TPM_PCR_INFO_SHORT
name|pcrInfoRead
decl_stmt|;
name|TPM_PCR_INFO_SHORT
name|pcrInfoWrite
decl_stmt|;
name|TPM_NV_ATTRIBUTES
name|permission
decl_stmt|;
name|BOOLEAN
name|bReadSTClear
decl_stmt|;
name|BOOLEAN
name|bWriteSTClear
decl_stmt|;
name|BOOLEAN
name|bWriteDefine
decl_stmt|;
name|UINT32
name|dataSize
decl_stmt|;
block|}
name|TPM_NV_DATA_PUBLIC
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 20: Delegate Structures
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_DEL_OWNER_BITS
value|((UINT32)0x00000001)
end_define

begin_define
define|#
directive|define
name|TPM_DEL_KEY_BITS
value|((UINT32)0x00000002)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.2: Delegate Definitions
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DELEGATIONS
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT32
name|delegateType
decl_stmt|;
name|UINT32
name|per1
decl_stmt|;
name|UINT32
name|per2
decl_stmt|;
block|}
name|TPM_DELEGATIONS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 20.2.1: Owner Permission Settings
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_DELEGATE_SetOrdinalAuditStatus
value|(BIT30)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_DirWriteAuth
value|(BIT29)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_CMK_ApproveMA
value|(BIT28)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_NV_WriteValue
value|(BIT27)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_CMK_CreateTicket
value|(BIT26)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_NV_ReadValue
value|(BIT25)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_Delegate_LoadOwnerDelegation
value|(BIT24)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_DAA_Join
value|(BIT23)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_AuthorizeMigrationKey
value|(BIT22)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_CreateMaintenanceArchive
value|(BIT21)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_LoadMaintenanceArchive
value|(BIT20)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_KillMaintenanceFeature
value|(BIT19)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_OwnerReadInteralPub
value|(BIT18)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_ResetLockValue
value|(BIT17)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_OwnerClear
value|(BIT16)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_DisableOwnerClear
value|(BIT15)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_NV_DefineSpace
value|(BIT14)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_OwnerSetDisable
value|(BIT13)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_SetCapability
value|(BIT12)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_MakeIdentity
value|(BIT11)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_ActivateIdentity
value|(BIT10)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_OwnerReadPubek
value|(BIT9)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_DisablePubekRead
value|(BIT8)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_SetRedirection
value|(BIT7)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_FieldUpgrade
value|(BIT6)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_Delegate_UpdateVerification
value|(BIT5)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_CreateCounter
value|(BIT4)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_ReleaseCounterOwner
value|(BIT3)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_DelegateManage
value|(BIT2)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_Delegate_CreateOwnerDelegation
value|(BIT1)
end_define

begin_define
define|#
directive|define
name|TPM_DELEGATE_DAA_Sign
value|(BIT0)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 20.2.3: Key Permission settings
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_CMK_ConvertMigration
value|(BIT28)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_TickStampBlob
value|(BIT27)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_ChangeAuthAsymStart
value|(BIT26)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_ChangeAuthAsymFinish
value|(BIT25)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_CMK_CreateKey
value|(BIT24)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_MigrateKey
value|(BIT23)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_LoadKey2
value|(BIT22)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_EstablishTransport
value|(BIT21)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_ReleaseTransportSigned
value|(BIT20)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_Quote2
value|(BIT19)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_Sealx
value|(BIT18)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_MakeIdentity
value|(BIT17)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_ActivateIdentity
value|(BIT16)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_GetAuditDigestSigned
value|(BIT15)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_Sign
value|(BIT14)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_CertifyKey2
value|(BIT13)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_CertifyKey
value|(BIT12)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_CreateWrapKey
value|(BIT11)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_CMK_CreateBlob
value|(BIT10)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_CreateMigrationBlob
value|(BIT9)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_ConvertMigrationBlob
value|(BIT8)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_CreateKeyDelegation
value|(BIT7)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_ChangeAuth
value|(BIT6)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_GetPubKey
value|(BIT5)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_UnBind
value|(BIT4)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_Quote
value|(BIT3)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_Unseal
value|(BIT2)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_Seal
value|(BIT1)
end_define

begin_define
define|#
directive|define
name|TPM_KEY_DELEGATE_LoadKey
value|(BIT0)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 20.3: TPM_FAMILY_FLAGS
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_DELEGATE_ADMIN_LOCK
value|(BIT1)
end_define

begin_define
define|#
directive|define
name|TPM_FAMFLAG_ENABLE
value|(BIT0)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.4: TPM_FAMILY_LABEL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_FAMILY_LABEL
block|{
name|UINT8
name|label
decl_stmt|;
block|}
name|TPM_FAMILY_LABEL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.5: TPM_FAMILY_TABLE_ENTRY
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_FAMILY_TABLE_ENTRY
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_FAMILY_LABEL
name|label
decl_stmt|;
name|TPM_FAMILY_ID
name|familyID
decl_stmt|;
name|TPM_FAMILY_VERIFICATION
name|verificationCount
decl_stmt|;
name|TPM_FAMILY_FLAGS
name|flags
decl_stmt|;
block|}
name|TPM_FAMILY_TABLE_ENTRY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 20.6: TPM_FAMILY_TABLE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_NUM_FAMILY_TABLE_ENTRY_MIN
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_FAMILY_TABLE
block|{
name|TPM_FAMILY_TABLE_ENTRY
name|famTableRow
index|[
name|TPM_NUM_FAMILY_TABLE_ENTRY_MIN
index|]
decl_stmt|;
block|}
name|TPM_FAMILY_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.7: TPM_DELEGATE_LABEL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DELEGATE_LABEL
block|{
name|UINT8
name|label
decl_stmt|;
block|}
name|TPM_DELEGATE_LABEL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.8: TPM_DELEGATE_PUBLIC
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DELEGATE_PUBLIC
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DELEGATE_LABEL
name|label
decl_stmt|;
name|TPM_PCR_INFO_SHORT
name|pcrInfo
decl_stmt|;
name|TPM_DELEGATIONS
name|permissions
decl_stmt|;
name|TPM_FAMILY_ID
name|familyID
decl_stmt|;
name|TPM_FAMILY_VERIFICATION
name|verificationCount
decl_stmt|;
block|}
name|TPM_DELEGATE_PUBLIC
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.9: TPM_DELEGATE_TABLE_ROW
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DELEGATE_TABLE_ROW
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DELEGATE_PUBLIC
name|pub
decl_stmt|;
name|TPM_SECRET
name|authValue
decl_stmt|;
block|}
name|TPM_DELEGATE_TABLE_ROW
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 20.10: TPM_DELEGATE_TABLE
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_NUM_DELEGATE_TABLE_ENTRY_MIN
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DELEGATE_TABLE
block|{
name|TPM_DELEGATE_TABLE_ROW
name|delRow
index|[
name|TPM_NUM_DELEGATE_TABLE_ENTRY_MIN
index|]
decl_stmt|;
block|}
name|TPM_DELEGATE_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.11: TPM_DELEGATE_SENSITIVE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DELEGATE_SENSITIVE
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_SECRET
name|authValue
decl_stmt|;
block|}
name|TPM_DELEGATE_SENSITIVE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.12: TPM_DELEGATE_OWNER_BLOB
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DELEGATE_OWNER_BLOB
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DELEGATE_PUBLIC
name|pub
decl_stmt|;
name|TPM_DIGEST
name|integrityDigest
decl_stmt|;
name|UINT32
name|additionalSize
decl_stmt|;
name|UINT8
modifier|*
name|additionalArea
decl_stmt|;
name|UINT32
name|sensitiveSize
decl_stmt|;
name|UINT8
modifier|*
name|sensitiveArea
decl_stmt|;
block|}
name|TPM_DELEGATE_OWNER_BLOB
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 20.13: TTPM_DELEGATE_KEY_BLOB
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DELEGATE_KEY_BLOB
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DELEGATE_PUBLIC
name|pub
decl_stmt|;
name|TPM_DIGEST
name|integrityDigest
decl_stmt|;
name|TPM_DIGEST
name|pubKeyDigest
decl_stmt|;
name|UINT32
name|additionalSize
decl_stmt|;
name|UINT8
modifier|*
name|additionalArea
decl_stmt|;
name|UINT32
name|sensitiveSize
decl_stmt|;
name|UINT8
modifier|*
name|sensitiveArea
decl_stmt|;
block|}
name|TPM_DELEGATE_KEY_BLOB
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 20.14: TPM_FAMILY_OPERATION Values
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_FAMILY_CREATE
value|((UINT32)0x00000001)
end_define

begin_define
define|#
directive|define
name|TPM_FAMILY_ENABLE
value|((UINT32)0x00000002)
end_define

begin_define
define|#
directive|define
name|TPM_FAMILY_ADMIN
value|((UINT32)0x00000003)
end_define

begin_define
define|#
directive|define
name|TPM_FAMILY_INVALIDATE
value|((UINT32)0x00000004)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 21.1: TPM_CAPABILITY_AREA for GetCapability
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_CAP_ORD
value|((TPM_CAPABILITY_AREA) 0x00000001)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_ALG
value|((TPM_CAPABILITY_AREA) 0x00000002)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PID
value|((TPM_CAPABILITY_AREA) 0x00000003)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_FLAG
value|((TPM_CAPABILITY_AREA) 0x00000004)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROPERTY
value|((TPM_CAPABILITY_AREA) 0x00000005)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_VERSION
value|((TPM_CAPABILITY_AREA) 0x00000006)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_KEY_HANDLE
value|((TPM_CAPABILITY_AREA) 0x00000007)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_CHECK_LOADED
value|((TPM_CAPABILITY_AREA) 0x00000008)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_SYM_MODE
value|((TPM_CAPABILITY_AREA) 0x00000009)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_KEY_STATUS
value|((TPM_CAPABILITY_AREA) 0x0000000C)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_NV_LIST
value|((TPM_CAPABILITY_AREA) 0x0000000D)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_MFR
value|((TPM_CAPABILITY_AREA) 0x00000010)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_NV_INDEX
value|((TPM_CAPABILITY_AREA) 0x00000011)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_TRANS_ALG
value|((TPM_CAPABILITY_AREA) 0x00000012)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_HANDLE
value|((TPM_CAPABILITY_AREA) 0x00000014)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_TRANS_ES
value|((TPM_CAPABILITY_AREA) 0x00000015)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_AUTH_ENCRYPT
value|((TPM_CAPABILITY_AREA) 0x00000017)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_SELECT_SIZE
value|((TPM_CAPABILITY_AREA) 0x00000018)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_VERSION_VAL
value|((TPM_CAPABILITY_AREA) 0x0000001A)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_FLAG_PERMANENT
value|((TPM_CAPABILITY_AREA) 0x00000108)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_FLAG_VOLATILE
value|((TPM_CAPABILITY_AREA) 0x00000109)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 21.2: CAP_PROPERTY Subcap values for GetCapability
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_CAP_PROP_PCR
value|((TPM_CAPABILITY_AREA) 0x00000101)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_DIR
value|((TPM_CAPABILITY_AREA) 0x00000102)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MANUFACTURER
value|((TPM_CAPABILITY_AREA) 0x00000103)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_KEYS
value|((TPM_CAPABILITY_AREA) 0x00000104)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MIN_COUNTER
value|((TPM_CAPABILITY_AREA) 0x00000107)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_AUTHSESS
value|((TPM_CAPABILITY_AREA) 0x0000010A)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_TRANSESS
value|((TPM_CAPABILITY_AREA) 0x0000010B)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_COUNTERS
value|((TPM_CAPABILITY_AREA) 0x0000010C)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MAX_AUTHSESS
value|((TPM_CAPABILITY_AREA) 0x0000010D)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MAX_TRANSESS
value|((TPM_CAPABILITY_AREA) 0x0000010E)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MAX_COUNTERS
value|((TPM_CAPABILITY_AREA) 0x0000010F)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MAX_KEYS
value|((TPM_CAPABILITY_AREA) 0x00000110)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_OWNER
value|((TPM_CAPABILITY_AREA) 0x00000111)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_CONTEXT
value|((TPM_CAPABILITY_AREA) 0x00000112)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MAX_CONTEXT
value|((TPM_CAPABILITY_AREA) 0x00000113)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_FAMILYROWS
value|((TPM_CAPABILITY_AREA) 0x00000114)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_TIS_TIMEOUT
value|((TPM_CAPABILITY_AREA) 0x00000115)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_STARTUP_EFFECT
value|((TPM_CAPABILITY_AREA) 0x00000116)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_DELEGATE_ROW
value|((TPM_CAPABILITY_AREA) 0x00000117)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_DAA_MAX
value|((TPM_CAPABILITY_AREA) 0x00000119)
end_define

begin_define
define|#
directive|define
name|CAP_PROP_SESSION_DAA
value|((TPM_CAPABILITY_AREA) 0x0000011A)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_CONTEXT_DIST
value|((TPM_CAPABILITY_AREA) 0x0000011B)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_DAA_INTERRUPT
value|((TPM_CAPABILITY_AREA) 0x0000011C)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_SESSIONS
value|((TPM_CAPABILITY_AREA) 0x0000011D)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MAX_SESSIONS
value|((TPM_CAPABILITY_AREA) 0x0000011E)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_CMK_RESTRICTION
value|((TPM_CAPABILITY_AREA) 0x0000011F)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_DURATION
value|((TPM_CAPABILITY_AREA) 0x00000120)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_ACTIVE_COUNTER
value|((TPM_CAPABILITY_AREA) 0x00000122)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_MAX_NV_AVAILABLE
value|((TPM_CAPABILITY_AREA) 0x00000123)
end_define

begin_define
define|#
directive|define
name|TPM_CAP_PROP_INPUT_BUFFER
value|((TPM_CAPABILITY_AREA) 0x00000124)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 21.4: TPM_CAPABILITY_AREA for SetCapability
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_SET_PERM_FLAGS
value|((TPM_CAPABILITY_AREA) 0x00000001)
end_define

begin_define
define|#
directive|define
name|TPM_SET_PERM_DATA
value|((TPM_CAPABILITY_AREA) 0x00000002)
end_define

begin_define
define|#
directive|define
name|TPM_SET_STCLEAR_FLAGS
value|((TPM_CAPABILITY_AREA) 0x00000003)
end_define

begin_define
define|#
directive|define
name|TPM_SET_STCLEAR_DATA
value|((TPM_CAPABILITY_AREA) 0x00000004)
end_define

begin_define
define|#
directive|define
name|TPM_SET_STANY_FLAGS
value|((TPM_CAPABILITY_AREA) 0x00000005)
end_define

begin_define
define|#
directive|define
name|TPM_SET_STANY_DATA
value|((TPM_CAPABILITY_AREA) 0x00000006)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 21.6: TPM_CAP_VERSION_INFO
end_comment

begin_comment
comment|///   [size_is(vendorSpecificSize)] BYTE* vendorSpecific;
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_CAP_VERSION_INFO
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_VERSION
name|version
decl_stmt|;
name|UINT16
name|specLevel
decl_stmt|;
name|UINT8
name|errataRev
decl_stmt|;
name|UINT8
name|tpmVendorID
index|[
literal|4
index|]
decl_stmt|;
name|UINT16
name|vendorSpecificSize
decl_stmt|;
name|UINT8
modifier|*
name|vendorSpecific
decl_stmt|;
block|}
name|TPM_CAP_VERSION_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 21.10: TPM_DA_ACTION_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DA_ACTION_TYPE
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT32
name|actions
decl_stmt|;
block|}
name|TPM_DA_ACTION_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPM_DA_ACTION_FAILURE_MODE
value|(((UINT32)1)<<3)
end_define

begin_define
define|#
directive|define
name|TPM_DA_ACTION_DEACTIVATE
value|(((UINT32)1)<<2)
end_define

begin_define
define|#
directive|define
name|TPM_DA_ACTION_DISABLE
value|(((UINT32)1)<<1)
end_define

begin_define
define|#
directive|define
name|TPM_DA_ACTION_TIMEOUT
value|(((UINT32)1)<<0)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 21.7: TPM_DA_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DA_INFO
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DA_STATE
name|state
decl_stmt|;
name|UINT16
name|currentCount
decl_stmt|;
name|UINT16
name|thresholdCount
decl_stmt|;
name|TPM_DA_ACTION_TYPE
name|actionAtThreshold
decl_stmt|;
name|UINT32
name|actionDependValue
decl_stmt|;
name|UINT32
name|vendorDataSize
decl_stmt|;
name|UINT8
modifier|*
name|vendorData
decl_stmt|;
block|}
name|TPM_DA_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 21.8: TPM_DA_INFO_LIMITED
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DA_INFO_LIMITED
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DA_STATE
name|state
decl_stmt|;
name|TPM_DA_ACTION_TYPE
name|actionAtThreshold
decl_stmt|;
name|UINT32
name|vendorDataSize
decl_stmt|;
name|UINT8
modifier|*
name|vendorData
decl_stmt|;
block|}
name|TPM_DA_INFO_LIMITED
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 21.9: CAP_PROPERTY Subcap values for GetCapability
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_DA_STATE_INACTIVE
value|((UINT8)0x00)
end_define

begin_define
define|#
directive|define
name|TPM_DA_STATE_ACTIVE
value|((UINT8)0x01)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 22: DAA Structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 22.1: Size definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_r0
value|(43)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_r1
value|(43)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_r2
value|(128)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_r3
value|(168)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_r4
value|(219)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_NT
value|(20)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_v0
value|(128)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_v1
value|(192)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_NE
value|(256)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_w
value|(256)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_SIZE_issuerModulus
value|(256)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 22.2: Constant definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPM_DAA_power0
value|(104)
end_define

begin_define
define|#
directive|define
name|TPM_DAA_power1
value|(1024)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 22.3: TPM_DAA_ISSUER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DAA_ISSUER
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_R0
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_R1
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_S0
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_S1
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_n
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_gamma
decl_stmt|;
name|UINT8
name|DAA_generic_q
index|[
literal|26
index|]
decl_stmt|;
block|}
name|TPM_DAA_ISSUER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 22.4: TPM_DAA_TPM
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DAA_TPM
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DIGEST
name|DAA_digestIssuer
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_v0
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_v1
decl_stmt|;
name|TPM_DIGEST
name|DAA_rekey
decl_stmt|;
name|UINT32
name|DAA_count
decl_stmt|;
block|}
name|TPM_DAA_TPM
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 22.5: TPM_DAA_CONTEXT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DAA_CONTEXT
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_DIGEST
name|DAA_digestContext
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest
decl_stmt|;
name|TPM_DAA_CONTEXT_SEED
name|DAA_contextSeed
decl_stmt|;
name|UINT8
name|DAA_scratch
index|[
literal|256
index|]
decl_stmt|;
name|UINT8
name|DAA_stage
decl_stmt|;
block|}
name|TPM_DAA_CONTEXT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 22.6: TPM_DAA_JOINDATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DAA_JOINDATA
block|{
name|UINT8
name|DAA_join_u0
index|[
literal|128
index|]
decl_stmt|;
name|UINT8
name|DAA_join_u1
index|[
literal|138
index|]
decl_stmt|;
name|TPM_DIGEST
name|DAA_digest_n0
decl_stmt|;
block|}
name|TPM_DAA_JOINDATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 22.8: TPM_DAA_BLOB
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DAA_BLOB
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|TPM_RESOURCE_TYPE
name|resourceType
decl_stmt|;
name|UINT8
name|label
index|[
literal|16
index|]
decl_stmt|;
name|TPM_DIGEST
name|blobIntegrity
decl_stmt|;
name|UINT32
name|additionalSize
decl_stmt|;
name|UINT8
modifier|*
name|additionalData
decl_stmt|;
name|UINT32
name|sensitiveSize
decl_stmt|;
name|UINT8
modifier|*
name|sensitiveData
decl_stmt|;
block|}
name|TPM_DAA_BLOB
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2, section 22.9: TPM_DAA_SENSITIVE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_DAA_SENSITIVE
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT32
name|internalSize
decl_stmt|;
name|UINT8
modifier|*
name|internalData
decl_stmt|;
block|}
name|TPM_DAA_SENSITIVE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Part 2, section 23: Redirection
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Part 2 section 23.1: TPM_REDIR_COMMAND
end_comment

begin_comment
comment|/// This section defines exactly one value but does not
end_comment

begin_comment
comment|/// give it a name. The definition of TPM_SetRedirection in Part3
end_comment

begin_comment
comment|/// refers to exactly one name but does not give its value. We join
end_comment

begin_comment
comment|/// them here.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TPM_REDIR_GPIO
value|(0x00000001)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM Command Headers defined in Part 3
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_RQU_COMMAND_HDR
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT32
name|paramSize
decl_stmt|;
name|TPM_COMMAND_CODE
name|ordinal
decl_stmt|;
block|}
name|TPM_RQU_COMMAND_HDR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM Response Headers defined in Part 3
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTPM_RSP_COMMAND_HDR
block|{
name|TPM_STRUCTURE_TAG
name|tag
decl_stmt|;
name|UINT32
name|paramSize
decl_stmt|;
name|TPM_RESULT
name|returnCode
decl_stmt|;
block|}
name|TPM_RSP_COMMAND_HDR
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

end_unit

